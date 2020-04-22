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

void SignalEvent_PU() 
{
  
  //bool debug = true;
  bool debug = false;
 
//**************** Constants *********************//
  const double NPU1plusNPU2	= 962;
  //bool CUTS_SATISFIED		= false;

//************************************************//

  //! vector of event numbers that have atleast 4 parton-level jets with the basic cuts
  int eventNumbers = -1;
  double Npileup1 = 0;
  double Npileup2 = 0;
  //! store results in an output root file 
  TFile *f_out = new TFile("./fastjet_output/TriggerStudies_4/EventList_ggFhh4b_PU.root","RECREATE");
  TTree *eventList = new TTree("eventList","event numbers of signal like events");
  eventList->Branch("eventNums", &eventNumbers);
  eventList->Branch("Npileup1", &Npileup1);
  eventList->Branch("Npileup2", &Npileup2);

  TH1::SetDefaultSumw2(true);
  //! open input trees 
  TChain tru("mu3e");
  tru.Add("/media/tamasi/wdElements/PhD/FCC/data_files/sim_files/user.tkar.ggF1.0hh4b_SIMPU1k_30mm_Selected_merged_0/*.root");
  tru.Add("/media/tamasi/wdElements/PhD/FCC/data_files/sim_files/user.tkar.ggF1.0hh4b_SIMPU1k_30mm_Selected_merged_1/*.root");

  //! Get total no. of events
  //Long64_t nevents = 500000;
  Long64_t nevents = tru.GetEntries();
  std::cout<<"number of Pile-up events : " << nevents <<std::endl; 
  
  //! define a local vector<double> to store the input values
  Float_t NPU1 = 0;
  Float_t NPU2 = 0;
  tru.SetBranchStatus("Npileup1",1);
  tru.SetBranchStatus("Npileup2",1);
  tru.SetBranchAddress("Npileup1", &NPU1);
  tru.SetBranchAddress("Npileup2", &NPU2);
//*****************************************************************************************//

//****************************** Begining of Event Loop ***********************************//

  //! for every event do the following
  for(int i = 0; i < nevents; ++i)
  {
	//! fetch the ith event
	tru.GetEntry(i);
	
	//! total number of particles from the ith event
  	if(debug)
	{
		std::cout<< "EVENT NUMBER: " << i <<std::endl;
	}
	if(NPU1+NPU2 >= NPU1plusNPU2) continue;	
	else
	{
		eventNumbers = i;
		Npileup1 = NPU1;
		Npileup2 = NPU2;
		eventList->Fill();	
	}

	//*********************************************************************//

  }//! loop over nentries
eventList->Write();
f_out->Close();
}
