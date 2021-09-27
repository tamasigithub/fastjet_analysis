// *** newer and better version of this file: SignalEventList_1.cc ***//
#include "fastjet/ClusterSequence.hh"
#include "../Constituent_info.h"
#include "../TrackJetObj.h"
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
#define mass_piPM  139.57018f /* MeV/c^2 */
using namespace fastjet;
/** get first digit of a number */
template<typename T>
inline T first_digit(T a)
{
        return (int)(a / std::pow(10, (int)(log10(a))));
}


int main() 
{
  TRandom3 *myRNG = new TRandom3();
  gRandom = myRNG;
  
  //bool debug = true;
  bool debug = false;
 
//**************** Constants *********************//
  const double ChargedPcle_PtThreshold 	= 300;//MeV
  const double SCALEfac_Ereso 		= 0.5; //50%
  const double TrackerAcceptance 	= 1.5;

  const double R 			= 0.4;
  const double PTMINJET 		= 20.0e3;//MeV
  int MAX_NLEADINGJETS 			= 4;// number of jets to be b-tagged-> 99 for all
  const double default_Pt_cut           = 20.0e3;//MeV 
  const double third_Pt_cut             = 35.0e3;//MeV 
  const double second_Pt_cut            = 40.0e3;//MeV
  const double first_Pt_cut             = 55.0e3;//MeV
  double BASIC_pT_CUTS[4] 		= {first_Pt_cut, second_Pt_cut, third_Pt_cut, default_Pt_cut};
  bool CUTS_SATISFIED			= false;

//************************************************//

  //! vector of event numbers that have atleast 4 parton-level jets with the basic cuts
  int eventNumbers = -1;
  int N_jets = -1;
  double firstLeading_pT = 0;
  double secondLeading_pT = 0;
  double thirdLeading_pT = 0;
  double fourthLeading_pT = 0;
  double firstLeading_eta = 0;
  double secondLeading_eta = 0;
  double thirdLeading_eta = 0;
  double fourthLeading_eta = 0;
  //! store results in an output root file 
  TFile *f_out = new TFile("../fastjet_output/TriggerStudies_6/EventList_ggFhh4b_Eta1_5_BasicCuts_1.root","RECREATE");
  TTree *eventList = new TTree("eventList","event numbers of signal like events");
  eventList->Branch("eventNums", &eventNumbers);
  eventList->Branch("Njets", &N_jets);
  eventList->Branch("firstL_pT", &firstLeading_pT);
  eventList->Branch("secondL_pT", &secondLeading_pT);
  eventList->Branch("thirdL_pT", &thirdLeading_pT);
  eventList->Branch("fourthL_pT", &fourthLeading_pT);
  eventList->Branch("firstL_eta", &firstLeading_eta);
  eventList->Branch("secondL_eta", &secondLeading_eta);
  eventList->Branch("thirdL_eta", &thirdLeading_eta);
  eventList->Branch("fourthL_eta", &fourthLeading_eta);

  TH1::SetDefaultSumw2(true);
  //! open input trees 
  TChain tru("tracks");
  tru.Add("/home/tamasi/repo_tamasi/rec_files/rec_files/30mm/PU1k/ggFhh4b_SM_1/*.root");
  //tru.Add("/home/tamasi/repo_tamasi/rec_files/rec_files/30mm/PU1k/ggFhh4b_SM/tmpnokap/*.root");
  //tru.Add("/home/tamasi/repo_tamasi/rec_files/rec_files/30mm/PU1k/ggFhh4b_SM/nokap/*.root");

  //! Get total no. of events
  //Long64_t nevents = 500000;
  Long64_t nevents = tru.GetEntries();
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
  tru.SetBranchStatus("px",1);
  tru.SetBranchStatus("py",1);
  tru.SetBranchStatus("pz",1);
  tru.SetBranchStatus("vz",1);
  tru.SetBranchStatus("theta",1);
  tru.SetBranchStatus("pid",1);
  tru.SetBranchStatus("type_traj",1);
  tru.SetBranchStatus("tid",1);
  tru.SetBranchStatus("charge",1);
  tru.SetBranchAddress("px", &px_tru);
  tru.SetBranchAddress("py", &py_tru);
  tru.SetBranchAddress("pz", &pz_tru);
  tru.SetBranchAddress("vz", &vz_tru);
  tru.SetBranchAddress("theta", &theta_tru);
  tru.SetBranchAddress("charge", &charge);
  tru.SetBranchAddress("pid", &pdg);
  tru.SetBranchAddress("type_traj", &type);
  tru.SetBranchAddress("tid", &barcode);
  //! vector of reconstructed track-jet objects
  //define outside the loop and call clear inside OR 
  //define inside the loop and it will be destroyed 
  //at the end of the loop for each iteration similar to the class object
  std::vector<TrackJetObj> trjVec;
  double px, py, pz, pt, vz, theta, E, eta, phi;	
  int pid, type_, q;
  uint32_t barcode_;
//*****************************************************************************************//

//****************************** Begining of Event Loop ***********************************//

  //! for every event do the following
  for(int i = 0; i < nevents; ++i)
  {
	TrackJetObj tjObj;
	trjVec.clear();
	//! fetch the ith event
	tru.GetEntry(i);
	
	//! total number of particles from the ith event
	int nobj = px_tru->size();
  	if(debug)
	{
		std::cout<< "EVENT NUMBER: " << i <<" has nobj= "<<nobj<<std::endl;
		std::cout << "charged particle pt threshold = " << ChargedPcle_PtThreshold*1e-3 << "GeV/c" <<std::endl;
	}

	//! for all tracks in a pileup event
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
		if(q != 0) 
		{
			//! get rid of charged particles below a certain pT threshold
			if(std::fabs(pt) < ChargedPcle_PtThreshold) continue;
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
	input_trpcle.clear();

	//! loop over all truth particles
	for(int k = 0; k < trjVec.size(); ++k )
	{
		if(debug) std::cout<<"Create Pseudo jets \n";
		
		PseudoJet trpcle(trjVec[k].px, trjVec[k].py, trjVec[k].pz, trjVec[k].E);
		trpcle.set_user_info(new Constituent_info(trjVec[k].pdg, trjVec[k].Vz0, trjVec[k].zv));
		input_trpcle.push_back(trpcle);
	
		
	}// end of loop over all tracks trjVec

	//**************************** All jets *******************************//
	if(debug)std::cout<<"Do jet Clustering \n";
	//! run the jet clustering with the above definition, extract the jets
	ClusterSequence cs_trpcle(input_trpcle, jet_def);
	
	//! sort the resulting jets in descending order of pt
	//! sorted_by_pt is a method of PseudoJet which returns a vector of jets sorted into decreasing pt
	//! sorted_by_rapidity is a method of PseudoJet which returns a vector of jets sorted into increasing eta
	std::vector<PseudoJet> incl_trpclejets = sorted_by_pt(cs_trpcle.inclusive_jets(PTMINJET));
	int Njets = incl_trpclejets.size();

	int Max_NLeadingJets;	
	//!Store only leading 4 or 5 or all(use 99 for all) jets
	if (MAX_NLEADINGJETS == 99) Max_NLeadingJets = Njets;
	else if (MAX_NLEADINGJETS == 5) Max_NLeadingJets = 5;
	else if (MAX_NLEADINGJETS == 4) Max_NLeadingJets = 4;
	//std::cout<<"number of Jets in event " << i << ": "<<incl_trpclejets.size() <<std::endl;
	//std::cout<<"number of NJets: "<<genOut.Njets <<std::endl;
	//std::cout<<"default Max_NLeadingJets: " <<Max_NLeadingJets <<std::endl;
	//! check if atleast Max_NLeadingJets (mostly 4)
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
		if(ii < 5)
		{
			if(std::fabs(incl_trpclejets[ii].pt()) < BASIC_pT_CUTS[ii]) 
			{
				CUTS_SATISFIED = false;
				break;
			}
			else
			{
				CUTS_SATISFIED = true;
				continue;
			}
		}
	}
	
	if(CUTS_SATISFIED)
	{
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
		std::cout<<"event number: " << eventNumbers<< std::endl;
		std::cout<<"firstLeading_pT: " << firstLeading_pT*1e-3<< std::endl;
		std::cout<<"secondLeading_pT: " << secondLeading_pT*1e-3<< std::endl;
		std::cout<<"thirdLeading_pT: " << thirdLeading_pT*1e-3<< std::endl;
		std::cout<<"fourthLeading_pT: " << fourthLeading_pT*1e-3<< std::endl;
		eventList->Fill();	
	}

	//*********************************************************************//

  }//! loop over nentries
eventList->Write();
f_out->Close();
return 0;
}
