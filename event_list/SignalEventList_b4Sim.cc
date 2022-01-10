// ************************************************************************************************ //
// Creates an event list that satisfy the generator level ana cuts from pythia output as input files 
// ************************************************************************************************ //
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
const int maxEventsinFile = 50;
//const char *out_path = "./out_test";
const char *out_path = "/user/tkar/work/data/gen/user.tkar.pp_4bQCD_selectedBGEvents_0/";
TFile *f_out = nullptr;
TTree *t_out = nullptr;
//! define a local vector<double> to store the input values
std::vector<float> px_;
std::vector<float> py_;
std::vector<float> pz_;
std::vector<float> vx_;
std::vector<float> vy_;
std::vector<float> vz_;
std::vector<float> e_;
std::vector<float> charge_;
std::vector<float> m_;
std::vector<int> pdgId_;
std::vector<int> status_;
std::vector<int> barcode_;
std::vector<int> pp_;
Float_t Npileup1_   = 0;
Float_t Npileup2_   = 0;

void Clear_Branch_Vars()
{
	px_.clear();
	py_.clear();
	pz_.clear();
	vx_.clear();
	vy_.clear();
	vz_.clear();
	e_.clear();
	charge_.clear();
	m_.clear();
	pdgId_.clear();
	status_.clear();
	barcode_.clear();
	pp_.clear();
	Npileup1_   = 0;
	Npileup2_   = 0;
	return;
}
void Branch_t_out()
{
	t_out->Branch("px",&px_);
	t_out->Branch("py",&py_);
	t_out->Branch("pz",&pz_);
	t_out->Branch("e",&e_);
	t_out->Branch("m",&m_);
	t_out->Branch("vx",&vx_);
	t_out->Branch("vy",&vy_);
	t_out->Branch("vz",&vz_);
	t_out->Branch("charge",&charge_);
	t_out->Branch("pdgId",&pdgId_);
	t_out->Branch("status",&status_);
	t_out->Branch("barcode",&barcode_);
	t_out->Branch("pp",&pp_);
	t_out->Branch("Npileup1",&Npileup1_);
	t_out->Branch("Npileup2",&Npileup2_);

	return;
}
//*****************************create output root file*************************************//
  void createNewOutput(char *filename)
{
	char Fname[1023];
	sprintf(Fname, "%s/%s", out_path, filename);
	f_out = new TFile(Fname,"RECREATE");
	t_out = new TTree("CollectionTree","CollectionTree");
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

//************************************************//

  //! open input trees 
  TChain rec("CollectionTree");
  rec.Add("/user/tkar/work/data/gen/user.tkar.pp_4bQCD_pythia82_nopileup.v5_output.root/*.root");

  //! Get total no. of events
  //Long64_t nevents = 500000;
  Long64_t nevents = rec.GetEntries();
  //nevents = 1000;
  std::cout<<"number of Pile-up events : " << nevents <<std::endl; 
  
  //! define a local vector<double> to store the input values
  std::vector<float> *px_tru = 0;
  std::vector<float> *py_tru = 0;
  std::vector<float> *pz_tru = 0;
  std::vector<float> *vx_tru = 0;
  std::vector<float> *vy_tru = 0;
  std::vector<float> *vz_tru = 0;
  std::vector<float> *energy = 0;
  std::vector<float> *charge = 0;
  std::vector<float> *mass   = 0;
  std::vector<int> *pdg      = 0;
  std::vector<int> *status   = 0;
  std::vector<int> *barcode  = 0;
  std::vector<int> *pp       = 0;
  Float_t Npileup1	     = 0;
  Float_t Npileup2	     = 0;

  rec.SetBranchStatus("px",1);
  rec.SetBranchStatus("py",1);
  rec.SetBranchStatus("pz",1);
  rec.SetBranchStatus("vx",1);
  rec.SetBranchStatus("vy",1);
  rec.SetBranchStatus("vz",1);
  rec.SetBranchStatus("e",1);
  rec.SetBranchStatus("charge",1);
  rec.SetBranchStatus("m",1);
  rec.SetBranchStatus("pdgId",1);
  rec.SetBranchStatus("status",1);
  rec.SetBranchStatus("barcode",1);
  rec.SetBranchStatus("pp",1);
  rec.SetBranchStatus("Npileup1",1);
  rec.SetBranchStatus("Npileup2",1);
  
  rec.SetBranchAddress("px", &px_tru);
  rec.SetBranchAddress("py", &py_tru);
  rec.SetBranchAddress("pz", &pz_tru);
  rec.SetBranchAddress("vx", &vx_tru);
  rec.SetBranchAddress("vy", &vy_tru);
  rec.SetBranchAddress("vz", &vz_tru);
  rec.SetBranchAddress("e", &energy);
  rec.SetBranchAddress("charge", &charge);
  rec.SetBranchAddress("m", &mass);
  rec.SetBranchAddress("pdgId", &pdg);
  rec.SetBranchAddress("status", &status);
  rec.SetBranchAddress("barcode", &barcode);
  rec.SetBranchAddress("pp", &pp);
  rec.SetBranchAddress("Npileup1", &Npileup1);
  rec.SetBranchAddress("Npileup2", &Npileup2);

  //! vector of reconstructed track-jet objects
  //define outside the loop and call clear inside OR 
  //define inside the loop and it will be destroyed 
  //at the end of the loop for each iteration similar to the class object
  std::vector<TrackJetObj> trjVec;
  double px, py, pz, pt, vz, E, m, eta, phi;	
  int pid, stat_, bar_, q;
//*****************************************************************************************//

//****************************** Begining of Event Loop ***********************************//

  //! for every event do the following
  int file_number = 1;
  int out_Nentries = -1;
  for(int i = 0; i < nevents; ++i)
  {
	TrackJetObj tjObj;
	trjVec.clear();

	rec.GetEntry(i);
	
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
		px	= (*px_tru)[j];
		py	= (*py_tru)[j];
		pz	= (*pz_tru)[j];
		vz	= (*vz_tru)[j];
		E	= (*energy)[j];
		m	= (*mass)[j];
		pid	= (*pdg)[j];
		stat_   = (*status)[j];
		bar_    = (*barcode)[j];

		eta	= asinh(pz/std::sqrt(px*px + py*py));
		phi	= atan2(py,px);
		pt	= hypotf(px,py);

		if(std::fabs(eta) > TrackerAcceptance) continue;
		tjObj.flag = 1;// stable particles
		
		//**** Identify light quarks, chram, bottom and Higgs *****//
		if(std::abs(pid) == 5 && stat_ == 23 ) 
		{
			tjObj.flag = 5;

		}// b quark
		else if(std::abs(pid) == 25 && stat_ == 62) 
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
		else if(stat_ != 1) continue;
		//*******************************************************//
		
		q = (*charge)[j];
		
		//! neutrinos do not deposit energy
		if(std::abs(pid) == 12 || std::abs(pid) == 14 || std::abs(pid) == 15) continue;
		//! is chrarged and is not a SM higgs or bquark or charm or any of the light quarks
		if(std::abs(q) != 0 && (std::abs(pid) > 5 || pid != 25))
		{	
			//! get rid of charged particles that will not make it to the calorimeter
			if(std::fabs(pt) < ChargedPcle_PtThreshold) continue;
		}


		if(debug && stat_ != 1)
		{
			std::cout<<"px, py, pz, eta, phi, pid, status: " << px << " , " << py << " , " << pz << " , " << eta << " , " << phi << " , " << pid << " , " << stat_ << std::endl;
		
		}

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
		//if matched to a b quark with pt > 15GeV/c, tag the jet as b-tagged with probability 0.8
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

	//if(incl_trpclejets[0].pt() < BASIC_pT_CUTS[0]) continue;
	//if(incl_trpclejets[1].pt() < BASIC_pT_CUTS[1]) continue;
	//if(incl_trpclejets[2].pt() < BASIC_pT_CUTS[2]) continue;
	//if(incl_trpclejets[3].pt() < BASIC_pT_CUTS[3]) continue;
	//! check if there are atleast 4 b-tagged jets
	if(debug) std::cout<<"number of b-jets: "<<bJet_pT.size() <<std::endl;
	if(bJet_pT.size() < 4) continue;

	if(bJet_pT[0] < BASIC_pT_CUTS[0]) continue;
	if(bJet_pT[1] < BASIC_pT_CUTS[1]) continue;
	if(bJet_pT[2] < BASIC_pT_CUTS[2]) continue;
	if(bJet_pT[3] < BASIC_pT_CUTS[3]) continue;

	//TLorentzVector bJ1, bJ2, bJ3, bJ4;
	//TLorentzVector bJ1bJ2, bJ1bJ3, bJ1bJ4, bJ2bJ3, bJ2bJ4, bJ3bJ4;
	////bJ1 = TLorentzVector(); 
	////bJ2 = TLorentzVector(); 
	////bJ3 = TLorentzVector(); 
	////bJ4 = TLorentzVector(); 
	////bJ1bJ2 = TLorentzVector();
	////bJ1bJ3 = TLorentzVector();
	////bJ1bJ4 = TLorentzVector();
	////bJ2bJ3 = TLorentzVector();
	////bJ2bJ4 = TLorentzVector();
	////bJ3bJ4 = TLorentzVector();

	//bJ1.SetPtEtaPhiM(bJet_pT[0], bJet_eta[0], bJet_phi[0], bJet_m[0]);
	//bJ2.SetPtEtaPhiM(bJet_pT[1], bJet_eta[1], bJet_phi[1], bJet_m[1]);
	//bJ3.SetPtEtaPhiM(bJet_pT[2], bJet_eta[2], bJet_phi[2], bJet_m[2]);
	//bJ4.SetPtEtaPhiM(bJet_pT[3], bJet_eta[3], bJet_phi[3], bJet_m[3]);
	//
	//bJ1bJ2 = bJ1 + bJ2;
	//bJ1bJ3 = bJ1 + bJ3;
	//bJ1bJ4 = bJ1 + bJ4;
	//bJ2bJ3 = bJ2 + bJ3;
	//bJ2bJ4 = bJ2 + bJ4;
	//bJ3bJ4 = bJ3 + bJ4;

	//double dm_12_34 = 0, dm_13_24 = 0, dm_14_23 = 0;
	//dm_12_34 = std::fabs(bJ1bJ2.M() - bJ3bJ4.M())*1e-3;
	//dm_13_24 = std::fabs(bJ1bJ3.M() - bJ2bJ4.M())*1e-3;
	//dm_14_23 = std::fabs(bJ1bJ4.M() - bJ2bJ3.M())*1e-3;

	////! Higgs Candidate
	//int higgs_candidates = -1;
	//int min_diffCombi = 999;

	//if((std::fabs(bJ1bJ2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ3bJ4.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	//{
	//
	//	if(dm_12_34 < min_diffCombi)
        //	{
        //        	min_diffCombi = dm_12_34;
        //        	higgs_candidates = 1234;
        //	}
	//}

	//if((std::fabs(bJ1bJ3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ4.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	//{
	//	if(dm_13_24 < min_diffCombi) 
	//	{
	//		min_diffCombi = dm_13_24;
	//		higgs_candidates = 1324;
	//	}
	//}

	//if((std::fabs(bJ1bJ4.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	//{
	//	if(dm_14_23 < min_diffCombi)
	//	{
	//		min_diffCombi = dm_14_23;
	//		higgs_candidates = 1423;
	//	}
	//}

	//if(higgs_candidates == -1) continue;


	//! if all cuts satisfied
	out_Nentries++;
	if(debug) std::cout<<"out_entries = " <<out_Nentries <<std::endl;
	if(debug) std::cout<<"out_entriesmod25 = " <<out_Nentries%25 <<std::endl;
	if(out_Nentries%maxEventsinFile == 0)
	{
		//! close any already open output file
		if(f_out) 
		{
			t_out->Write();
			f_out->Close();
			file_number++;
		}
		//! open a new output file with the following name
		char newFilename[1023];
		//sprintf(newFilename,"user.tkar.pp_ggF_Ctr1.0_selectedSignalEvents_%06i.root",file_number);
		sprintf(newFilename,"user.tkar.pp_4bQCD_selectedBGEvents_%06i.root",file_number);
		std::cout<<"New File Name: " << newFilename <<std::endl;
		createNewOutput(newFilename);

	}
	Clear_Branch_Vars();
	Npileup1_   = Npileup1;
	Npileup2_   = Npileup2;
	for(int jj = 0; jj < px_tru->size(); ++jj)
	{
		px_.push_back((*px_tru)[jj]);
		py_.push_back((*py_tru)[jj]);
		pz_.push_back((*pz_tru)[jj]);
		vx_.push_back((*vx_tru)[jj]);
		vy_.push_back((*vy_tru)[jj]);
		vz_.push_back((*vz_tru)[jj]);
		e_.push_back((*energy)[jj]);
		charge_.push_back((*charge)[jj]);
		m_.push_back((*mass)[jj]);
		pdgId_.push_back((*pdg)[jj]);
		status_.push_back((*status)[jj]);
		barcode_.push_back((*barcode)[jj]);
		pp_.push_back((*pp)[jj]);
	}
	t_out->Fill();

  }// end of loop over number of events

  if(f_out) 
  {
	t_out->Write();
	f_out->Close();
  }


  return 0;
}
