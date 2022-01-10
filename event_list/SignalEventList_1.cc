// *************************************************************************************************//
// *** Create an event list that satisfies the selection cuts used for Generator level analysis ***//
// *** For this calo-jets(charged + neutrals) are created from the reco "tracks" TTree ***//
//
// input files: TTT reco output (PU1k) specified in the main()
// output file: a root output created by createNewOutput(file_name) -> called in main()
// for all "tracks"(simulated info) in an event the following checks are made:
// 1. only primary tracks (the ones shot into the simulation)
// 2. only hard scattered particles (PU included)
// 3. those within a given tracker acceptance (eta)
// 4. tracks with charge >1 are discarded
// 5. neutrinos, Higgs and other quarks do not deposit energy in the calo 
// 6. Events with b quarks with PV(same as HS vertex) outside the Luminous region are discarded
// 7. Gen_Ana cuts on the clustered jets: atleast 4 jets satisfying the basic pT cuts
// Note: invariant higgs mast cut not included
// *************************************************************************************************//
#include <iostream>
#include <vector>
#include "math.h"
#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TChain.h>
#include <TMath.h>
#include <TRandom3.h>
#include <TInterpreter.h>
#include <TLorentzVector.h>
#include "fastjet/ClusterSequence.hh"
#include "../Constituent_info.h"
#include "../TrackJetObj.h"
#define mass_piPM  139.57018f /* MeV/c^2 */
using namespace fastjet;
const char *out_path = "./out_test";
//const char *out_path = "/media/tamasi/Z/PhD/fastjet/fastjet_output/TriggerStudies_4";
const int file_number = 3;
TFile *f_out = nullptr;
TTree *eventList = nullptr;

/** get first digit of a number */
template<typename T>
inline T first_digit(T a)
{
        return (int)(a / std::pow(10, (int)(log10(a))));
}

//! event numbers that have satisfied all the analysis cuts
int eventNumbers = -1;
double PV = -999.0;
int N_jets = -1;
double firstLeading_pT = 0;
double secondLeading_pT = 0;
double thirdLeading_pT = 0;
double fourthLeading_pT = 0;
double firstLeading_eta = 0;
double secondLeading_eta = 0;
double thirdLeading_eta = 0;
double fourthLeading_eta = 0;
double firstLeading_bJpT = 0;
double secondLeading_bJpT = 0;
double thirdLeading_bJpT = 0;
double fourthLeading_bJpT = 0;
double firstLeading_bJeta = 0;
double secondLeading_bJeta = 0;
double thirdLeading_bJeta = 0;
double fourthLeading_bJeta = 0;
double invariant_H1 = 0;
double invariant_H2 = 0;
void Clear_Branch_Vars()
{
  
	eventNumbers = -1;
//	PV = -999.0;
	N_jets = -1;
	firstLeading_pT = 0;
	secondLeading_pT = 0;
	thirdLeading_pT = 0;
	fourthLeading_pT = 0;
	firstLeading_eta = 0;
	secondLeading_eta = 0;
	thirdLeading_eta = 0;
	fourthLeading_eta = 0;
	
	firstLeading_bJpT = 0;
	secondLeading_bJpT = 0;
	thirdLeading_bJpT = 0;
	fourthLeading_bJpT = 0;
	firstLeading_bJeta = 0;
	secondLeading_bJeta = 0;
	thirdLeading_bJeta = 0;
	fourthLeading_bJeta = 0;
	invariant_H1 = 0;
	invariant_H2 = 0;
	return;
}
void Branch_t_out()
{
  eventList->Branch("eventNums", &eventNumbers);
  eventList->Branch("PV", &PV);
  eventList->Branch("Njets", &N_jets);
  eventList->Branch("firstL_pT", &firstLeading_pT);
  eventList->Branch("secondL_pT", &secondLeading_pT);
  eventList->Branch("thirdL_pT", &thirdLeading_pT);
  eventList->Branch("fourthL_pT", &fourthLeading_pT);
  eventList->Branch("firstL_eta", &firstLeading_eta);
  eventList->Branch("secondL_eta", &secondLeading_eta);
  eventList->Branch("thirdL_eta", &thirdLeading_eta);
  eventList->Branch("fourthL_eta", &fourthLeading_eta);
  eventList->Branch("firstL_bJpT", &firstLeading_bJpT);
  eventList->Branch("secondL_bJpT", &secondLeading_bJpT);
  eventList->Branch("thirdL_bJpT", &thirdLeading_bJpT);
  eventList->Branch("fourthL_bJpT", &fourthLeading_bJpT);
  eventList->Branch("firstL_bJeta", &firstLeading_bJeta);
  eventList->Branch("secondL_bJeta", &secondLeading_bJeta);
  eventList->Branch("thirdL_bJeta", &thirdLeading_bJeta);
  eventList->Branch("fourthL_bJeta", &fourthLeading_bJeta);
  eventList->Branch("invariant_H1", &invariant_H1);
  eventList->Branch("invariant_H2", &invariant_H2);

	return;
}
//*****************************create output root file*************************************//
  void createNewOutput(char *filename)
{
	char Fname[1023];
	sprintf(Fname, "%s/%s", out_path, filename);
	f_out = new TFile(Fname,"RECREATE");
  	eventList = new TTree("eventList","event numbers of signal like events");
	//! clear branch variables
	Clear_Branch_Vars();
	Branch_t_out();

	return;
}
//*****************************************************************************************//
int main() 
{
  TRandom3 *myRNG = new TRandom3();
  gRandom = myRNG;
  
  //bool debug = true;
  bool debug = false;
 
//**************** Constants *********************//
  const double ChargedPcle_PtThreshold 	= 300;//MeV
  const double SCALEfac_Ereso 		= 0.5; //50%
  const double TrackerAcceptance 	= 2.5;

  const double R 			= 0.4;
  const double PTMINJET 		= 20.0e3;//MeV
  int MAX_NLEADINGJETS 			= 99;// number of jets to be b-tagged-> 99 for all
  const double default_Pt_cut           = 20.0e3;//MeV 
  const double third_Pt_cut             = 35.0e3;//MeV 
  const double second_Pt_cut            = 40.0e3;//MeV
  const double first_Pt_cut             = 55.0e3;//MeV
  double BASIC_pT_CUTS[4] 		= {first_Pt_cut, second_Pt_cut, third_Pt_cut, default_Pt_cut};
  bool CUTS_SATISFIED			= false;

  //! b-tag info
  const double MinQuarkPt = 15e3;//MeV
  const double fb = 1.0, fc= 0.1, fl = 0.01;

  const double HiggsMass       = 125.0;//GeV
  const double MassWidth       = 60.0;//GeV
  const double Max_vz	       = 100.0;//mm

//************************************************//

  //! open input trees 
  TChain rec("tracks");
  rec.Add("/user/tkar/work/data/rec/sel/Br30mmEC67mm/PU1k/pp_4bQCD/*.root");
  //rec.Add("/user/tkar/work/data/rec/sel/Br30mmEC67mm/PU1k/ggF1.0/*.root");
  //rec.Add("/media/tamasi/wdElements/PhD/FCC/data_files/rec_files/30mm/PU1k/ggFhh4b_SM_1/*.root");
  //rec.Add("/media/tamasi/wdElements/PhD/FCC/data_files/rec_files/30mm/PU1k/ggFhh4b_SM_2/*.root");
  //rec.Add("/home/tamasi/repo_tamasi/rec_files/rec_files/30mm/PU1k/ggFhh4b_SM/*.root");
  //rec.Add("/home/tamasi/repo_tamasi/rec_files/rec_files/30mm/PU1k/ggFhh4b_SM/tmpnokap/*.root");
  //rec.Add("/home/tamasi/repo_tamasi/rec_files/rec_files/30mm/PU1k/ggFhh4b_SM/nokap/*.root");

  //! Get total no. of events
  //Long64_t nevents = 500000;
  Long64_t nevents = rec.GetEntries();
  //nevents = 100;
  std::cout<<"number of Pile-up events : " << nevents <<std::endl; 
  
  //! define a local vector<double> to store the input values
  std::vector<double> *px_tru = 0;
  std::vector<double> *py_tru = 0;
  std::vector<double> *pz_tru = 0;
  std::vector<double> *vz_tru = 0;
  std::vector<double> *theta_tru = 0;
  std::vector<int> *charge = 0;
  std::vector<int> *pdg = 0;
  std::vector<int> *type = 0;
  std::vector<uint32_t> *barcode = 0;
  rec.SetBranchStatus("px",1);
  rec.SetBranchStatus("py",1);
  rec.SetBranchStatus("pz",1);
  rec.SetBranchStatus("vz",1);
  rec.SetBranchStatus("theta",1);
  rec.SetBranchStatus("pid",1);
  rec.SetBranchStatus("type_traj",1);
  rec.SetBranchStatus("tid",1);
  rec.SetBranchStatus("charge",1);
  rec.SetBranchAddress("px", &px_tru);
  rec.SetBranchAddress("py", &py_tru);
  rec.SetBranchAddress("pz", &pz_tru);
  rec.SetBranchAddress("vz", &vz_tru);
  rec.SetBranchAddress("theta", &theta_tru);
  rec.SetBranchAddress("charge", &charge);
  rec.SetBranchAddress("pid", &pdg);
  rec.SetBranchAddress("type_traj", &type);
  rec.SetBranchAddress("tid", &barcode);

  //! vector of reconstructed track-jet objects
  //define outside the loop and call clear inside OR 
  //define inside the loop and it will be destroyed 
  //at the end of the loop for each iteration similar to the class object
  std::vector<TrackJetObj> trjVec;
  double px, py, pz, pt, vz, E, theta, eta, phi;	
  int pid, type_, q;
  uint32_t barcode_;
//*****************************************************************************************//
	//! open a new output file with the following name
	char newFilename[1023];
	sprintf(newFilename,"user.tkar.EventList_2_5_allAnaCuts_%06i.root",file_number);
	//sprintf(newFilename,"user.tkar.EventListpp4bQCD_2_5_allAnaCuts_%06i.root",file_number);
	std::cout<<"New File Name: " << newFilename <<std::endl;
	createNewOutput(newFilename);
//****************************** Begining of Event Loop ***********************************//

  for(int i = 0; i < nevents; ++i)
  {
	TrackJetObj tjObj;
	trjVec.clear();

	rec.GetEntry(i);
	
	PV = -999.0;
	bool PVoutsideLumiR = false;
	//! total number of tracks reconstructed in an event
	int nobj = px_tru->size();
  	if(debug)
	{
		std::cout<< "EVENT NUMBER: " << i <<" has nobj= "<<nobj<<std::endl;
		std::cout << "charged particle pt threshold = " << ChargedPcle_PtThreshold*1e-3 << "GeV/c" <<std::endl;
	}


	//! for all tracks in an event
	for (int j = 0; j < nobj; ++j)
	{
		type_   = (*type)[j];
		if(type_ != 0) continue;//primary only!
		barcode_= (*barcode)[j];
		if (debug) std::cout <<"barcode and its first digit: "<<type_ <<", " << barcode_ << ", " << first_digit(barcode_) <<std::endl;
		if(first_digit(barcode_) != 1) continue;
		px	= (*px_tru)[j];
		py	= (*py_tru)[j];
		pz	= (*pz_tru)[j];
		vz	= (*vz_tru)[j];
		theta	= (*theta_tru)[j];
		q 	= (*charge)[j];
		pid	= (*pdg)[j];

		eta	= asinh(pz/std::sqrt(px*px + py*py));
		phi	= atan2(py,px);
		pt	= hypotf(px,py);
		E  	= std::sqrt(std::pow(pt/sin(theta),2) + std::pow(mass_piPM,2));

		if(std::fabs(eta) > TrackerAcceptance) continue;
		if(std::abs(q) > 1) continue;
		//! neutrinos do not deposit energy
		if(std::abs(pid) == 12 || std::abs(pid) == 14 || std::abs(pid) == 16) continue;
		//! is chrarged and is not a SM higgs or bquark or charm or any of the light quarks
		if(std::abs(q) != 0 && (std::abs(pid) > 5 || pid != 25))
		{	
			//! get rid of charged particles that will not make it to the calorimeter
			if(std::fabs(pt) < ChargedPcle_PtThreshold) continue;
		}

		
		tjObj.flag = 1;// stable particles
		
		//**** Identify light quarks, chram, bottom and Higgs *****//
		if(std::abs(pid) == 5 ) 
		{
			tjObj.flag = 5;
			if(std::fabs(vz) > Max_vz)
			{
				PVoutsideLumiR = true;
				break;
			}
			else PV = vz;	

		}// b quark
		else if(std::abs(pid) == 25) 
		{
			tjObj.flag = 25;

		}// SM higgs
		else if(std::abs(pid) == 4)
		{
			tjObj.flag = 4;
			
		}// charm quark
		else if(std::abs(pid) < 4)
		{
			tjObj.flag = 3;
			
		}// light quark
		//*******************************************************//
		
		
		tjObj.px = px;
		tjObj.py = py;
		tjObj.pz = pz;
		tjObj.E  = E;
		tjObj.eta = eta;
		tjObj.phi = phi;
		tjObj.zv = vz;
		tjObj.pdg = pid;
		tjObj.Vz0 = vz;

		//! push the objects into a vector of these objects
		trjVec.push_back(tjObj);

	}// end of loop over nobj(all tracks/particles in an event)

	if(PVoutsideLumiR) continue;

	//! choose a jet definition
	JetDefinition jet_def(antikt_algorithm, R);
	//! all stable particles in this event
	std::vector<PseudoJet> input_trpcle;
	//! all b quarks in this event
	std::vector<PseudoJet> input_bquarks;
	//! all higgs in this event
	//std::vector<PseudoJet> input_SMhiggs;


	//! loop over all truth particles
	for(int k = 0; k < trjVec.size(); ++k )
	{
		//if(debug) std::cout<<"Create Pseudo jets \n";
		if(trjVec[k].flag == 5)
		{ 
			if(debug) std::cout<<"Create b quarks Pseudo jets \n";
			PseudoJet bquarks(trjVec[k].px, trjVec[k].py, trjVec[k].pz, trjVec[k].E);
			bquarks.set_user_info(new Constituent_info(trjVec[k].pdg, trjVec[k].Vz0, trjVec[k].zv));
			input_bquarks.push_back(bquarks);
		}
		//else if(trjVec[k].flag == 25)
		//{	
		//	if(debug) std::cout<<"Create higgs Pseudo jets \n";
		//	PseudoJet SMhiggs(trjVec[k].px, trjVec[k].py, trjVec[k].pz, trjVec[k].E);
		//	SMhiggs.set_user_info(new Constituent_info(trjVec[k].pdg, trjVec[k].Vz0, trjVec[k].zv));
		//	input_SMhiggs.push_back(SMhiggs);
		//}
		else if (trjVec[k].flag == 1) 
		{
			PseudoJet trpcle(trjVec[k].px, trjVec[k].py, trjVec[k].pz, trjVec[k].E);
			trpcle.set_user_info(new Constituent_info(trjVec[k].pdg, trjVec[k].Vz0, trjVec[k].zv));
			input_trpcle.push_back(trpcle);
		}
		
	}// end of loop over all tracks trjVec

		
	//*************************** b quarks ********************************//
	int n_bquarks = input_bquarks.size();
	//! skip events which have less than four b quarks
	if(debug) std::cout<<"number of b quarks: "<< n_bquarks <<std::endl;
	if (n_bquarks < 4) continue;
	std::vector<PseudoJet>	incl_bquarks_pt = sorted_by_pt(input_bquarks);
	//*********************************************************************//

	
	//**************************** All jets *******************************//
	if(debug)std::cout<<"Do jet Clustering \n";
	//! run the jet clustering with the above definition, extract the jets
	ClusterSequence cs_trpcle(input_trpcle, jet_def);
	
	//! sort the resulting jets in descending order of pt
	//! sorted_by_pt is a method of PseudoJet which returns a vector of jets sorted into decreasing pt
	std::vector<PseudoJet> incl_trpclejets = sorted_by_pt(cs_trpcle.inclusive_jets(PTMINJET));
	int Njets = incl_trpclejets.size();
	if(debug) std::cout <<"Number of Jets: " << Njets <<std::endl;

	int Max_NLeadingJets;	
	//!Store only leading 4 or 5 or all(use 99 for all) jets
	if (MAX_NLEADINGJETS == 99) Max_NLeadingJets = Njets;
	else if (MAX_NLEADINGJETS == 5) Max_NLeadingJets = 5;
	else if (MAX_NLEADINGJETS == 4) Max_NLeadingJets = 4;
	//std::cout<<"number of Jets in event " << i << ": "<<incl_trpclejets.size() <<std::endl;
	//std::cout<<"number of NJets: "<<genOut.Njets <<std::endl;
	//std::cout<<"default Max_NLeadingJets: " <<Max_NLeadingJets <<std::endl;
	if (Njets < Max_NLeadingJets) 
	{
		if(Njets == 4) Max_NLeadingJets = 4;
		else continue;
	}

	if(debug)
	{
		std::cout << "Clustering with " << jet_def.description() << std::endl;
		std::cout<<"Number of truth jets Njets : " <<Njets << std::endl;
	}

	double dR, thisDR;
	int bestTruthJet;
	//! for each truth jet sorted in pt
	//std::cout<<"final Max_NLeadingJets: " <<Max_NLeadingJets <<std::endl;
	//std::cout<<std::endl;
	std::vector<double> bJet_pT;
	std::vector<double> bJet_eta;
	std::vector<double> bJet_phi;
	std::vector<double> bJet_m;
	bJet_pT.clear();
	bJet_eta.clear();
	bJet_phi.clear();
	bJet_m.clear();
	for (unsigned ii = 0; ii < Max_NLeadingJets; ++ii) 
	{
		//! smear jet energies
		double jetE_, jetPx_, jetPy_, jetPz_, jetE_reso_;
		double jetE_smeared;
		jetE_  = incl_trpclejets[ii].e();
		jetPx_ = incl_trpclejets[ii].px();
		jetPy_ = incl_trpclejets[ii].py();
		jetPz_ = incl_trpclejets[ii].pz();

		jetE_reso_ = SCALEfac_Ereso/sqrt(jetE_);//50% energy resolution
		jetE_smeared = gRandom->Gaus(jetE_,jetE_reso_*jetE_);

		incl_trpclejets[ii].reset_momentum(jetPx_, jetPy_, jetPz_, jetE_smeared);
		if(incl_trpclejets[ii].eta() > TrackerAcceptance) continue;
	
			
		if(debug)
		{
			std::cout << "truth pcle jet " << ii << ": "<< incl_trpclejets[ii].pt() << " " << incl_trpclejets[ii].rap() << " " << incl_trpclejets[ii].phi() << std::endl;
		}
		
	
		//************************* tag Jets with the following probabilities: ********************//
		//if matched to a b quark with pt > 15GeV/c, tag the jet as b-tagged with probability fb
		dR = 99999.0;
		bestTruthJet = -1;
		int btagged_flavor = 0;
		double matchFound = 99;
		//! b-jet tagging
		if(btagged_flavor == 0 && n_bquarks !=0)
		{
			for(unsigned jj = 0; jj < n_bquarks; ++jj)
			{
				if(incl_bquarks_pt[jj].pt() < MinQuarkPt) continue;
				thisDR = incl_trpclejets[ii].delta_R(incl_bquarks_pt[jj]);
				if(thisDR < dR)
				{
					dR = thisDR;
					bestTruthJet = jj;

				}
			}
			if(dR < R)
			{ 
				matchFound = gRandom->Uniform(0,1);
				if(matchFound <= fb ) btagged_flavor = 5;

			}
		
		}
		if(btagged_flavor == 5)
		{
			bJet_pT.push_back(incl_trpclejets[ii].pt());
			bJet_eta.push_back(incl_trpclejets[ii].eta());
			bJet_phi.push_back(incl_trpclejets[ii].phi());
			bJet_m.push_back(incl_trpclejets[ii].m());
		}

	}// end of for loop over jet size

	//! check if there are atleast 4 b-tagged jets
	if(debug) std::cout<<"number of b-jets: "<<bJet_pT.size() <<std::endl;
	if(bJet_pT.size() < 4) continue;

	if(bJet_pT[0] < BASIC_pT_CUTS[0]) continue;
	if(bJet_pT[1] < BASIC_pT_CUTS[1]) continue;
	if(bJet_pT[2] < BASIC_pT_CUTS[2]) continue;
	if(bJet_pT[3] < BASIC_pT_CUTS[3]) continue;

	TLorentzVector bJ1, bJ2, bJ3, bJ4;
	TLorentzVector bJ1bJ2, bJ1bJ3, bJ1bJ4, bJ2bJ3, bJ2bJ4, bJ3bJ4;

	bJ1.SetPtEtaPhiM(bJet_pT[0], bJet_eta[0], bJet_phi[0], bJet_m[0]);
	bJ2.SetPtEtaPhiM(bJet_pT[1], bJet_eta[1], bJet_phi[1], bJet_m[1]);
	bJ3.SetPtEtaPhiM(bJet_pT[2], bJet_eta[2], bJet_phi[2], bJet_m[2]);
	bJ4.SetPtEtaPhiM(bJet_pT[3], bJet_eta[3], bJet_phi[3], bJet_m[3]);
	
	bJ1bJ2 = bJ1 + bJ2;
	bJ1bJ3 = bJ1 + bJ3;
	bJ1bJ4 = bJ1 + bJ4;
	bJ2bJ3 = bJ2 + bJ3;
	bJ2bJ4 = bJ2 + bJ4;
	bJ3bJ4 = bJ3 + bJ4;

	double dm_12_34 = 0, dm_13_24 = 0, dm_14_23 = 0;
	dm_12_34 = std::fabs(bJ1bJ2.M() - bJ3bJ4.M())*1e-3;
	dm_13_24 = std::fabs(bJ1bJ3.M() - bJ2bJ4.M())*1e-3;
	dm_14_23 = std::fabs(bJ1bJ4.M() - bJ2bJ3.M())*1e-3;

	//! Higgs Candidate
	int higgs_candidates = -1;
	int min_diffCombi = 999;

	if((std::fabs(bJ1bJ2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ3bJ4.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
	
		if(dm_12_34 < min_diffCombi)
        	{
                	min_diffCombi = dm_12_34;
                	higgs_candidates = 1234;
        	}
	}

	if((std::fabs(bJ1bJ3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ4.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
		if(dm_13_24 < min_diffCombi) 
		{
			min_diffCombi = dm_13_24;
			higgs_candidates = 1324;
		}
	}

	if((std::fabs(bJ1bJ4.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
		if(dm_14_23 < min_diffCombi)
		{
			min_diffCombi = dm_14_23;
			higgs_candidates = 1423;
		}
	}

	if(higgs_candidates == -1) continue;
	double M_Lhiggs1 = 0, M_NLhiggs1 = 0;
	if(higgs_candidates == 1234)
	{
		if(bJ1bJ2.M() > bJ3bJ4.M())
		{
			M_Lhiggs1 = bJ1bJ2.M()*1e-3;
			M_NLhiggs1 = bJ3bJ4.M()*1e-3;
		
		} 
		else
		{
			M_Lhiggs1 = bJ3bJ4.M()*1e-3;
			M_NLhiggs1 = bJ1bJ2.M()*1e-3;
			
		}
	
	}
	else if(higgs_candidates == 1324)
	{
		if(bJ1bJ3.M() > bJ2bJ4.M())
		{
			M_Lhiggs1 = bJ1bJ3.M()*1e-3;
			M_NLhiggs1 = bJ2bJ4.M()*1e-3;
		
		} 
		else
		{
			M_Lhiggs1 = bJ2bJ4.M()*1e-3;
			M_NLhiggs1 = bJ1bJ3.M()*1e-3;
			
		}

	}
	else if(higgs_candidates == 1423)
	{
		if(bJ1bJ4.M() > bJ2bJ3.M())
		{
			M_Lhiggs1 = bJ1bJ4.M()*1e-3;
			M_NLhiggs1 = bJ2bJ3.M()*1e-3;
		
		} 
		else
		{
			M_Lhiggs1 = bJ2bJ3.M()*1e-3;
			M_NLhiggs1 = bJ1bJ4.M()*1e-3;
			
		}
	
	}


	//! if all cuts satisfied

	Clear_Branch_Vars();
	eventNumbers = i;
	N_jets = Njets;
	firstLeading_pT = incl_trpclejets[0].pt();
	secondLeading_pT = incl_trpclejets[1].pt();
	thirdLeading_pT = incl_trpclejets[2].pt();
	fourthLeading_pT = incl_trpclejets[3].pt();
	
	firstLeading_eta = incl_trpclejets[0].eta();
	secondLeading_eta = incl_trpclejets[1].eta();
	thirdLeading_eta = incl_trpclejets[2].eta();
	fourthLeading_eta = incl_trpclejets[3].eta();
	
	firstLeading_bJpT  = bJet_pT[0];
	secondLeading_bJpT = bJet_pT[1];
	thirdLeading_bJpT  = bJet_pT[2];
	fourthLeading_bJpT = bJet_pT[3];
	
	firstLeading_bJeta  = bJet_eta[0];
	secondLeading_bJeta = bJet_eta[1];
	thirdLeading_bJeta  = bJet_eta[2];
	fourthLeading_bJeta = bJet_eta[3];

	invariant_H1 = M_Lhiggs1;
	invariant_H2 = M_NLhiggs1;
	
	eventList->Fill();

  }// end of loop over number of events

  if(f_out) 
  {
	eventList->Write();
	f_out->Close();
  }


  return 0;
}
