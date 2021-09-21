#include "fastjet/ClusterSequence.hh"
#include "Constituent_info.h"
#include "TrackJetObj.h"
#include "Rate_sumpt.h"
#include "TrigEff.h"
#include <iostream>
#include <vector>
#include "math.h"
#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TChain.h>
#include <TInterpreter.h>
using namespace fastjet;
#define mass_piPM  139.57018f /* MeV/c^2 */
int main () 
{
  //bool debug = true;
  bool debug = false;
  ////////////////////////////////////////////////////////////////////////////////////
  //     if NZVTXBIN= 40 and ZRANGE = 200mm, ZBIN_width = 5;
  //     we now extend our zbin_width to include the neighbouring bins
  //	 i.e. each of the ith bin is now 15 mm and there is an overlap of 5 mm in 
  //	 either direction
  //	 the 20th bin [0,5) will now include contents from the 19th and the 21st bins
  //	 i.e. new bin range is [-5,10) i.e. ZBIN_width +- 3/2 * ZBIN_width
  //	NZVTXBIN= 40  => +-7.5mm about the center of the ith bin total 15mm
  //    NZVTXBIN= 80 => +-3.75mm about the center of the ith bin       7.5mm
  //    NZVTXBIN= 100 => +-3.0mm about the center of the ith bin       6mm
  //    NZVTXBIN= 120 => +-2.5mm about the center of the ith bin       5mm
  //    NZVTXBIN= 150 => +-2.0mm about the center of the ith bin       4mm
  //    NZVTXBIN= 200 => +-1.5mm about the center of the ith bin       3mm
  ////////////////////////////////////////////////////////////////////////////////////
  int NJETS, NZVTXBIN;
  float ZRANGE, ZBIN_width;
  int izbin, nthBIN_PV;
  //MIN_Constituents = 4;
  //std::vector<int> MIN_Constituents = {1,1,1,1,1};
  std::vector<int> MIN_Constituents = {3,2,2,1,1};
  //std::vector<int> MIN_Constituents = {4,4,3,3,2};
  NJETS = 20;
  NZVTXBIN = 200;
  ZRANGE = 200; // in mm
  ZBIN_width = ZRANGE/NZVTXBIN;
  double MAX_TRACKpt = 100e3;//!TODO: needs to be optimised
  double KAPPA_CUT   = 3.0;
  double ETA_CUT     = 1.5;
  double MIN_TRACKPT   = 2e3;//! all tracks must have a min pT > MIN_TRACKPT
  double MIN_TRACKPT_1 = 2e3;//! atleast MIN_Constituents in a jet must have pT > MIN_TRACKPT_1
  //double MIN_TRACKPT_2[5] = {2e3,2e3,2e3,2e3,2e3};//! atleast 1st constituents in a jet must have pT > MIN_TRACKPT_1
  double MIN_TRACKPT_2[5] = {9e3,7e3,4e3,3e3,2e3};//! atleast 1st constituents in a jet must have pT > MIN_TRACKPT_1
  //! Jet definition
  double R = 0.4;
  double PTMINJET = 5e3;// in MeV

 //! Print constants used
  std::cout<<"NZVTXBIN = " << NZVTXBIN <<std::endl;
  std::cout<<"ZRANGE = " << ZRANGE <<std::endl;
  std::cout<<"ZBIN_width = " << ZBIN_width <<std::endl;
  std::cout<<"MAX_TRACKpt = " << MAX_TRACKpt <<std::endl;
  std::cout<<"ETA_CUT = " << ETA_CUT <<std::endl;
/////////////////////////////////////////////////////  
  //! variables used to make purity plots
/////////////////////////////////////////////////////
  int etabin = 30;
  //double etamin =-1.7, etamax = 1.7;
  double etamin =-2.5, etamax = 2.5;
  // log bins //! for TTTjet puruty histos
  const int ptbins = 40;//no. of bins
  int length = ptbins + 1;
  Double_t xbins[length];//elements of this array are
  double dx, l10;
  dx = 3./ptbins;// 7 -> 10TeV //5 -> implies max until 10^5// xbins now in GeV
  l10 = TMath::Log(10);
  for (int i = 0; i<=ptbins; i++)
  {
	//std::cout<<"i,dx : " <<i << ", "<<dx <<std::endl;
	xbins[i] = TMath::Exp(l10*i*dx);
	//std::cout<<"xbin[i] : " <<xbins[i] <<std::endl;
  }

/////////////////////////////////////////////////////////
  //! binning for rate and trigger efficienceis
////////////////////////////////////////////////////////
  const float PT_MIN = 0., PT_MAX = 1000., PTCUT_WIDTH = 2.0;// in GeV/c
  //const float PT_MIN = 0., PT_MAX = 2000., PTCUT_WIDTH = 5.0;// in GeV/c
  //! create an object to plot rate as a function of pt
  Rate_sumpt r_sumpt(PT_MIN, PT_MAX, PTCUT_WIDTH);
  r_sumpt.init_Histos(r_sumpt.xbins, r_sumpt.nbins);

  //! create an object to plot trigger efficiency as a function of pt
  TrigEff trigger(PT_MIN, PT_MAX, PTCUT_WIDTH);
  trigger.init(trigger.xbins, trigger.nbins);

  //! init output vector
  std::vector<std::vector<double> > vectorof_jetpt(NZVTXBIN, std::vector<double>());
  std::vector<std::vector<int> > vectorof_jetMult(NZVTXBIN, std::vector<int>());
  std::vector<std::vector<double> > vec_constTRKpT_1L(NZVTXBIN, std::vector<double>());
  std::vector<std::vector<double> > vec_constTRKpT_2L(NZVTXBIN, std::vector<double>());
  std::vector<std::vector<double> > vec_constTRKpT_3L(NZVTXBIN, std::vector<double>());
  std::vector<std::vector<double> > vec_constTRKpT_4L(NZVTXBIN, std::vector<double>());
  std::vector<std::vector<double> > vec_constTRKpT_5L(NZVTXBIN, std::vector<double>());
////////////////////////////////////////////////////////////////
  //! fetch event list
///////////////////////////////////////////////////////////////  
  int eve_i = 0;
  double PV_i = 0;
  //TFile *f_eve = new TFile("/media/tamasi/Z/PhD/fastjet/fastjet_output/TriggerStudies_6/EventList_ggFhh4b_Eta1_5_BasicCuts_1.root","READ");
  //TFile *f_eve = new TFile("/media/tamasi/Z/PhD/fastjet/fastjet_output/TriggerStudies_4/user.tkar.EventList_allAnaCuts_000001.root","READ");
  TFile *f_eve = new TFile("/media/tamasi/Z/PhD/fastjet/fastjet_output/TriggerStudies_4/user.tkar.EventList_1_5_allAnaCuts_000004.root","READ");
  //TFile *f_eve = new TFile("/media/tamasi/Z/PhD/fastjet/fastjet_output/TriggerStudies_4/user.tkar.EventList_2_5_allAnaCuts_000001.root","READ");
  TTree *evelistTree = (TTree*)f_eve->Get("eventList");
  evelistTree->SetBranchAddress("eventNums", &eve_i);
  evelistTree->SetBranchAddress("PV", &PV_i);
  Long64_t nevents = evelistTree->GetEntries();
//////////////////////////////////////////////////  
  //! store results in an output root file 
//////////////////////////////////////////////////
  //! branch variables
  gInterpreter->GenerateDictionary("vector<vector<double>>","vector");
  gInterpreter->GenerateDictionary("vector<vector<int>>","vector");
   int eventNo;
  //! reconstructed track-jets
  int Njets;						// # of reconstructed track-jets
  std::vector<double> jetPt;				// reconstructed track-jet pt
  std::vector<std::vector<double> > constituentPt;	// it's constituents pt
  std::vector<double> jetPhi;                     	// reconstructed track-jet phi
  std::vector<std::vector<double> > constituentPhi;	// it's constituents phi
  std::vector<double> jetTheta;                   	// reconstructed track-jet theta
  std::vector<std::vector<double> > constituentTheta;	// it's constituents theta
  std::vector<double> jetEta;                     	// reconstructed track-jet eta
  std::vector<std::vector<double> > constituentEta;	// it's constituents eta
  std::vector<double> jetEt;                     	// reconstructed track-jet energy 
  std::vector<std::vector<double> > constituentEt;      // it's constituents energy
  std::vector<double> jetMt;                     	// reconstructed track-jet mass
  std::vector<std::vector<double> > constituentMt;      // it's constituents mass
  std::vector<std::vector<int> >    constituentPdg;	// pdg of track-jet constituents
  std::vector<std::vector<double> > constituentZ0;	// reconstructed z vertex track-jet constituents
  std::vector<bool>   hasConstituents;            	// flag indicating if the track-jet has constituents
  std::vector<int>   Nconstituents;	            	// number of constituents for each jet
  
  //! matched truth particle jets
  int M_Njets;						// # of matched truth particle jets
  std::vector<double> M_jetPt;				// matched truth particle jet pt
  std::vector<std::vector<double> > M_constituentPt;	// it's constituents pt
  std::vector<double> M_jetPhi;                     	// matched truth particle jet phi
  std::vector<std::vector<double> > M_constituentPhi;	// it's constituents phi
  std::vector<double> M_jetTheta;                   	// matched truth particle jet theta
  std::vector<std::vector<double> > M_constituentTheta;	// it's constituents theta
  std::vector<double> M_jetEta;                     	// matched truth particle jet eta
  std::vector<std::vector<double> > M_constituentEta;	// it's constituents eta
  std::vector<double> M_jetEt;                     	// matched truth particle jet energy 
  std::vector<std::vector<double> > M_constituentEt;    // it's constituents energy
  std::vector<double> M_jetMt;                     	// matched truth particle jet mass
  std::vector<std::vector<double> > M_constituentMt;    // it's constituents mass
  std::vector<std::vector<int> >    M_constituentPdg;	// pdg of matched truth particle jet constituents
  std::vector<std::vector<double> > M_constituentZ0;	// matched truth particle z vertex track-jet constituents
  std::vector<bool>   M_hasConstituents;            	// flag indicating if the truth particle jet has constituents
  std::vector<int>    M_Nconstituents;	            	// number of constituents for each jet

  //! output root file
  ////TFile *f_out = new TFile("./fastjet_output/TriggerStudies_5/TrkJPU1kggFhh4b1.2mm_30mm_4trk2.5_2GeV_33333GeV_5.root","RECREATE");
  ////TFile *f_out = new TFile("./fastjet_output/TriggerStudies_5/TrkJPU1kMB1.2mm_30mm_1trk2.5_2GeV_33333GeV_3.root","RECREATE");
  TFile *f_out = new TFile("./fastjet_output/TriggerStudies_6/TrkJPU1kggFhh4b1.5mm_30mm_32211trk1.5_2GeV_97432GeV_5.root","RECREATE");
  //TFile *f_out = new TFile("./fastjet_output/TriggerStudies_6/TrkJPU1kMB1.5mm_30mm_32211trk1.5_2GeV_97432GeV_3.root","RECREATE");
  TH1::SetDefaultSumw2(true);
  //! track jet purity
  TH1* h_num_vs_etaPU = new TH1F("h_num_vs_etaPU", "Numerator Count vs #eta;#eta;Numerator Count", etabin, etamin, etamax);
  TH1* h_den_vs_etaPU = new TH1F("h_den_vs_etaPU", "Denominator Count vs #eta;#eta;Denominator Count", etabin, etamin, etamax);
  TH1* h_num_vs_ptPU = new TH1F("h_num_vs_ptPU", "Numerator Count vs P_{t};P_{t} [GeV/c];Numerator Count", ptbins, xbins);
  TH1* h_den_vs_ptPU = new TH1F("h_den_vs_ptPU", "Denominator Count vs P_{t};P_{t} [GeV/c];Denominator Count", ptbins, xbins);

  TTree *glob_jet = new TTree("glob_jet","glob_jet");
  glob_jet->Branch("event",&eventNo);
  glob_jet->Branch("Njets",&Njets);
  glob_jet->Branch("jetPt",&jetPt);
  glob_jet->Branch("jetConstPt",&constituentPt);
  glob_jet->Branch("jetPhi",&jetPhi);
  glob_jet->Branch("jetConstPhi",&constituentPhi);
  glob_jet->Branch("jetTheta",&jetTheta);
  glob_jet->Branch("jetConstTheta",&constituentTheta);
  glob_jet->Branch("jetEta",&jetEta);
  glob_jet->Branch("jetConstEta",&constituentEta);
  glob_jet->Branch("jetEt",&jetEt);
  glob_jet->Branch("jetConstEt",&constituentEt);
  glob_jet->Branch("jetMt",&jetMt);
  glob_jet->Branch("jetConstMt",&constituentMt);
  glob_jet->Branch("jetConstPdg",&constituentPdg);
  glob_jet->Branch("jetConstZ0",&constituentZ0);
  glob_jet->Branch("has_constituents",&hasConstituents);
  glob_jet->Branch("Nconstituents", &Nconstituents);
  
  glob_jet->Branch("M_Njets",&M_Njets);
  glob_jet->Branch("M_jetPt",&M_jetPt);
  glob_jet->Branch("M_jetConstPt",&M_constituentPt);
  glob_jet->Branch("M_jetPhi",&M_jetPhi);
  glob_jet->Branch("M_jetConstPhi",&M_constituentPhi);
  glob_jet->Branch("M_jetTheta",&M_jetTheta);
  glob_jet->Branch("M_jetConstTheta",&M_constituentTheta);
  glob_jet->Branch("M_jetEta",&M_jetEta);
  glob_jet->Branch("M_jetConstEta",&M_constituentEta);
  glob_jet->Branch("M_jetEt",&M_jetEt);
  glob_jet->Branch("M_jetConstEt",&M_constituentEt);
  glob_jet->Branch("M_jetMt",&M_jetMt);
  glob_jet->Branch("M_jetConstMt",&M_constituentMt);
  glob_jet->Branch("M_jetConstPdg",&M_constituentPdg);
  glob_jet->Branch("M_jetConstZ0",&M_constituentZ0);
  glob_jet->Branch("M_has_constituents",&M_hasConstituents);
  glob_jet->Branch("M_Nconstituents",&M_Nconstituents);
  
  TTree *bin_Tree = new TTree("bin_Tree","bin_Tree");
  bin_Tree->Branch("M_1L", &r_sumpt.M_Lpt);
  bin_Tree->Branch("M_2L", &r_sumpt.M_NLpt);
  bin_Tree->Branch("M_3L", &r_sumpt.M_NNLpt);
  bin_Tree->Branch("M_4L", &r_sumpt.M_NNNLpt);
  bin_Tree->Branch("M_5L", &r_sumpt.M_NNNNLpt);
  bin_Tree->Branch("C_1LpT", &r_sumpt.v_constTRKpT_1Lsumpt);
  bin_Tree->Branch("C_2LpT", &r_sumpt.v_constTRKpT_2Lsumpt);
  bin_Tree->Branch("C_3LpT", &r_sumpt.v_constTRKpT_3Lsumpt);
  bin_Tree->Branch("C_4LpT", &r_sumpt.v_constTRKpT_4Lsumpt);
  bin_Tree->Branch("C_5LpT", &r_sumpt.v_constTRKpT_5Lsumpt);
  
  bin_Tree->Branch("Ma_1L", &r_sumpt.Ma_Lpt);
  bin_Tree->Branch("Ma_2L", &r_sumpt.Ma_NLpt);
  bin_Tree->Branch("Ma_3L", &r_sumpt.Ma_NNLpt);
  bin_Tree->Branch("Ma_4L", &r_sumpt.Ma_NNNLpt);
  bin_Tree->Branch("Ma_5L", &r_sumpt.Ma_NNNNLpt);
  bin_Tree->Branch("Ca_1LpT", &r_sumpt.v_constTRKpT_1Lmaxpt);
  bin_Tree->Branch("Ca_2LpT", &r_sumpt.v_constTRKpT_2Lmaxpt);
  bin_Tree->Branch("Ca_3LpT", &r_sumpt.v_constTRKpT_3Lmaxpt);
  bin_Tree->Branch("Ca_4LpT", &r_sumpt.v_constTRKpT_4Lmaxpt);
  bin_Tree->Branch("Ca_5LpT", &r_sumpt.v_constTRKpT_5Lmaxpt);

  bin_Tree->Branch("PV", &PV_i);
  bin_Tree->Branch("PB_tru", &nthBIN_PV);
  bin_Tree->Branch("PB_maxbin", &r_sumpt.prim_bin);
  bin_Tree->Branch("PB1_multibin", &r_sumpt.PB1);
  bin_Tree->Branch("PB2_multibin", &r_sumpt.PB2);
  bin_Tree->Branch("PB3_multibin", &r_sumpt.PB3);
  bin_Tree->Branch("PB4_multibin", &r_sumpt.PB4);
  bin_Tree->Branch("PB5_multibin", &r_sumpt.PB5);
  //! open input trees 
  TChain rec("m_recTree");
  //! high pt min bias sample sigma = 3
  rec.Add("./fastjet_output/ggFhh4b_SM_1/*.root");
  rec.Add("./fastjet_output/ggFhh4b_SM_2/*.root");
  //rec.Add("./fastjet_output/MB_1/*.root");
  //rec.Add("./fastjet_output/MB_2/*.root");
  ////rec.Add("/home/tamasi/repo_tamasi/rec_files/rec_files/30mm/PU1k/ggFhh4b_SM_1/*.root");
  ////rec.Add("/home/tamasi/repo_tamasi/rec_files/rec_files/30mm/PU1k/MB_1/*.root");
  //! define a local vector<double> to store the reconstructed pt values
  //! always initialise a pointer!!
  std::vector<double> *pt_rec = 0;
  std::vector<double> *z0_rec = 0;
  std::vector<double> *theta_rec = 0;
  std::vector<double> *eta_rec = 0;
  std::vector<double> *phi_rec = 0;
  std::vector<double> *kap_pull = 0;
  std::vector<int> *tid_rec = 0;
  std::vector<int> *m_pdg = 0;
  std::vector<double> *m_pt = 0;
  std::vector<double> *m_Vz = 0;
  std::vector<double> *m_theta = 0;
  std::vector<double> *m_eta = 0;
  std::vector<double> *m_phi = 0;
  std::vector<int> *type = 0;
  rec.SetBranchStatus("Pt_n",1);
  rec.SetBranchStatus("Z013",1);
  rec.SetBranchStatus("Theta13",1);
  rec.SetBranchStatus("Eta13",1);
  rec.SetBranchStatus("Phi013",1);
  rec.SetBranchStatus("Tid",1);
  rec.SetBranchStatus("M_pdg",1);
  rec.SetBranchStatus("M_pt",1);
  rec.SetBranchStatus("M_Vz",1);
  rec.SetBranchStatus("M_theta",1);
  rec.SetBranchStatus("M_eta",1);
  rec.SetBranchStatus("M_phi",1);
  rec.SetBranchStatus("mc_interaction",1);
  rec.SetBranchAddress("Pt_n", &pt_rec);
  rec.SetBranchAddress("Z013", &z0_rec);
  rec.SetBranchAddress("Theta13", &theta_rec);
  rec.SetBranchAddress("Eta13", &eta_rec);
  rec.SetBranchAddress("Phi013", &phi_rec);
  rec.SetBranchAddress("Tid", &tid_rec);
  rec.SetBranchAddress("kappa_pull", &kap_pull);
  rec.SetBranchAddress("M_pdg", &m_pdg);
  rec.SetBranchAddress("M_pt", &m_pt);
  rec.SetBranchAddress("M_Vz", &m_Vz);
  rec.SetBranchAddress("M_theta", &m_theta);
  rec.SetBranchAddress("M_eta", &m_eta);
  rec.SetBranchAddress("M_phi", &m_phi);
  rec.SetBranchAddress("mc_interaction", &type);
  //! get mc information -pdgid and z vertex  
  //! vectors containing a single pileup event
  std::vector<double> pt_recPU;
  std::vector<double> z0_recPU;
  std::vector<double> theta_recPU;
  std::vector<double> eta_recPU;
  std::vector<double> phi_recPU;
  std::vector<double> kap_pullPU;
  std::vector<int> tid_recPU;
  std::vector<int> m_pdgPU;
  std::vector<double> m_ptPU;
  std::vector<double> m_VzPU;
  std::vector<double> m_thetaPU;
  std::vector<double> m_etaPU;
  std::vector<double> m_phiPU;
  
  ////! Uncomment the lines below if there is no pileup in the input files
  ////! to add multiple events(artificially add pileup) into one
  ////! Get total no. of events
  ////Long64_t nentries = rec.GetEntries();
  //////Long64_t nentries = 300;
  ////int pileup = 160;
  ////Long64_t nevents = nentries/pileup;
  //Long64_t nevents = rec.GetEntries();
  ////nevents = 10;
  //r_sumpt.nevents = nevents;
  //trigger.nevents = nevents;
  //std::cout<<"Total number of enteries in the input directory : " << rec.GetEntries() <<std::endl;
  //std::cout<<"number of Pile-up events : " << nevents <<std::endl;
  //! vector of reconstructed track-jet objects
  std::vector<TrackJetObj> tjVec;//define outside the loop and call clear inside OR define inside the loop and it will be destroyed at the end of the loop for each iteration similar to the class object
  //! for every event do the following
  //
  double pt,z0,theta,eta,phi,tid,mpt,mVz,mtheta,meta,mphi,kap_cut;
  int pid;
  double PV = -999.0;
  //for(Long64_t i_event = 0; i_event < nevents; ++i_event)
  //nevents = 1;
  r_sumpt.nevents = nevents;
  trigger.nevents = nevents;
  std::cout<<"Total number of enteries in the input directory : " << rec.GetEntries() <<std::endl;
  std::cout<<"number of Pile-up events : " << nevents <<std::endl;

  for(Long64_t i_event = 0; i_event < nevents; ++i_event)
  {
	evelistTree->GetEntry(i_event);
  	eventNo = eve_i;
	PV = PV_i;
	if(PV < -900) continue;
  	//eventNo = i_event;
	TrackJetObj tjObj;
	jetPt.clear();
	constituentPt.clear();
	jetPhi.clear();
	constituentPhi.clear();
	jetTheta.clear();
	constituentTheta.clear();
	jetEta.clear();
	constituentEta.clear();
	jetEt.clear();
	constituentEt.clear();
	jetMt.clear();
	constituentMt.clear();
	constituentPdg.clear();
	constituentZ0.clear();
	hasConstituents.clear();
	Nconstituents.clear();
	M_jetPt.clear();
	M_constituentPt.clear();
	M_jetPhi.clear();
	M_constituentPhi.clear();
	M_jetTheta.clear();
	M_constituentTheta.clear();
	M_jetEta.clear();
	M_constituentEta.clear();
	M_jetEt.clear();
	M_constituentEt.clear();
	M_jetMt.clear();
	M_constituentMt.clear();
	M_constituentPdg.clear();
	M_constituentZ0.clear();
	M_hasConstituents.clear();
	M_Nconstituents.clear();
	tjVec.clear();
	pt_recPU.clear();
	z0_recPU.clear();
	theta_recPU.clear();
	eta_recPU.clear();
	phi_recPU.clear();
	tid_recPU.clear();
	m_pdgPU.clear();
	m_ptPU.clear();
	m_VzPU.clear();
	m_thetaPU.clear();
	m_etaPU.clear();
	m_phiPU.clear();
	

	
	//int skip = i*pileup;
	//if(debug)
	//{
	//	std::cout<<"skip:"<<skip <<"\n";
	//	std::cout<<"i:" <<i <<"\n";
	//}
	//for(int ievent = skip; ievent < skip+pileup; ++ievent)
	//{
		////rec.GetEntry(ievent);
		//rec.GetEntry(i_event);
		rec.GetEntry(eve_i);

		for(int ik = 0; ik < pt_rec->size(); ++ik)
		{
			//if(std::fabs((*m_pt)[ik]) < MIN_TRACKPT) continue; 	
			//if(std::fabs((*m_eta)[ik]) > ETA_CUT) continue; 	
			//if((*type)[ik] != 0 ) continue; 	
			if(std::fabs((*kap_pull)[ik]) > KAPPA_CUT ) continue; 	
			if(std::fabs((*pt_rec)[ik]) < MIN_TRACKPT) continue; 	
			if(std::fabs((*eta_rec)[ik]) > ETA_CUT) continue; 	
			//! veto fake and dc tracks?// fakes =-1, dc = -barcode
			//if( (*tid_rec)[ik] <= -1) continue;
			//! veto only dc tracks
			if( (*tid_rec)[ik] < -1) continue;
			pt_recPU.push_back((*pt_rec)[ik]);
			z0_recPU.push_back((*z0_rec)[ik]);
			theta_recPU.push_back((*theta_rec)[ik]);
			eta_recPU.push_back((*eta_rec)[ik]);
			phi_recPU.push_back((*phi_rec)[ik]);
			kap_pullPU.push_back((*kap_pull)[ik]);
			tid_recPU.push_back((*tid_rec)[ik]);
			m_pdgPU.push_back((*m_pdg)[ik]);
			m_ptPU.push_back((*m_pt)[ik]);
			m_VzPU.push_back((*m_Vz)[ik]);
			m_thetaPU.push_back((*m_theta)[ik]);
			m_etaPU.push_back((*m_eta)[ik]);
			m_phiPU.push_back((*m_phi)[ik]);
			
		}
		
	//}
	//! total number of tracks reconstructed in an event
	int nobj = pt_recPU.size();
  	if(debug)std::cout<<"nobj: "<<nobj<<std::endl;
	if(nobj<1) continue;
//////////////////////////////////////////////////////////////////////////////
//  Create track jet constituent objects to be fed to the Jet clustering Alg
//////////////////////////////////////////////////////////////////////////////
	//! for all tracks in a single pile-up event
	//! create objects(constituents) for feeding it to jet clustering alg.
	for (int j = 0; j < nobj; ++j)
	{
		//pt	= pt_recPU[j];
		pt	= std::min(pt_recPU[j], MAX_TRACKpt);
		z0	= z0_recPU[j];
		theta	= theta_recPU[j];
		eta	= eta_recPU[j];
		phi	= phi_recPU[j];
		tid	= tid_recPU[j];
		pid	= m_pdgPU[j];
		//mpt	= std::min(m_ptPU[j], MAX_TRACKpt);
		mpt	= m_ptPU[j];
		mVz	= m_VzPU[j];
		mtheta	= m_thetaPU[j];
		meta	= m_etaPU[j];
		mphi	= m_phiPU[j];
		kap_cut	= kap_pullPU[j];

		//if(std::fabs(kap_cut) > KAPPA_CUT)std::cout<<"kappa_pull: " <<kap_cut << std::endl;	
		//if(std::fabs(kap_cut) > KAPPA_CUT ) continue; 	
		//if(std::fabs(pt) < MIN_TRACKPT) continue; 	
		//if(std::fabs(eta) > ETA_CUT) continue; 	

		//if(std::fabs(kap_cut) > KAPPA_CUT)std::cout<<"kappa_pull after skip: " <<kap_cut << std::endl;	
		if(debug){std::cout<<"mpt, mVz, mtheta, mphi, tid: " << mpt << " , " << mVz << " , " << mtheta << " , " << mphi << " , " << tid << std::endl; }
		if(tid==-1)tjObj.flag = 0;//fakes
		else if(tid > 0)tjObj.flag = 1;//matched tracks
		else if(tid < -1)tjObj.flag = -1;//dc tracks

		////! veto fake and dc tracks?
		////if(tjObj.flag!=1) continue;
		////! veto only dc tracks
		//if(tjObj.flag < 0) continue;

		//tjObj.px = mpt*cos(mphi);
		//tjObj.py = mpt*sin(mphi);
		//tjObj.pz = mpt/tan(mtheta);
		//tjObj.E  = std::sqrt(std::pow(mpt/sin(mtheta),2) + std::pow(mass_piPM,2));
		//tjObj.eta = meta;
		//tjObj.phi = mphi;
		tjObj.px = pt*cos(phi);
		tjObj.py = pt*sin(phi);
		tjObj.pz = pt/tan(theta);
		tjObj.E  = std::sqrt(std::pow(pt/sin(theta),2) + std::pow(mass_piPM,2));
		tjObj.eta = eta;
		tjObj.phi = phi;
		//! matched truth info has been set to zero for fake tracks and this causes a crash while doing jet clustering
		//! for truth jet clustering we anyway do not need these zeroes
		if(tid==-1)
		{
		tjObj.px_m = 1.0;
		tjObj.py_m = 1.0;
		tjObj.pz_m = 1.0;
		tjObj.E_m  = 1.0;
		}
		else
		{
		tjObj.px_m = mpt*cos(mphi);
		tjObj.py_m = mpt*sin(mphi);
		tjObj.pz_m = mpt/tan(mtheta);
		tjObj.E_m  = std::sqrt(std::pow(mpt/sin(mtheta),2) + std::pow(mass_piPM,2));
		}
		tjObj.zv = z0;
		//tjObj.zv = mVz;
		tjObj.pdg = pid;
		tjObj.Vz0 = mVz;


		//! push the objects into a vector of these objects
		tjVec.push_back(tjObj);

	}// end of loop over nobj
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

	//! choose a jet definition
	JetDefinition jet_def(antikt_algorithm, R);
	std::vector<PseudoJet> input_tracks;
	std::vector<PseudoJet> input_particles;

///////////////////////////////////////////////////////////////////////////////////
//    Create PseudoJet
///////////////////////////////////////////////////////////////////////////////////
	// loop over all tracks
	for(int k = 0; k < tjVec.size(); ++k )
	{
	//	if(debug) std::cout<<"Create Pseudo jets \n";
		// an event with particles: px		py		pz   	E
		PseudoJet trk(tjVec[k].px, tjVec[k].py, tjVec[k].pz, tjVec[k].E);
		trk.set_user_info(new Constituent_info(tjVec[k].pdg, tjVec[k].Vz0, tjVec[k].zv));
		//input_tracks.push_back( PseudoJet( tjVec[k].px, tjVec[k].py, tjVec[k].pz, tjVec[k].E) );  
		input_tracks.push_back(trk);
		
		//! create a Pseudo jet for "truth particles" (don't need fakes marked as zero)
		if(tjVec[k].flag != 1) continue;// get rid of DC tracks and fakes
		PseudoJet m_particle(tjVec[k].px_m, tjVec[k].py_m, tjVec[k].pz_m, tjVec[k].E_m);
		m_particle.set_user_info(new Constituent_info(tjVec[k].pdg, tjVec[k].Vz0, tjVec[k].zv));
		input_particles.push_back(m_particle);
	}// end of loop over all tracks tjVec

///////////////////////////////////////////////////////////////////////////////////
//     Do Jet Clustering
///////////////////////////////////////////////////////////////////////////////////	
	if(debug)std::cout<<"Do jet Clustering  for reconstructed tracks\n";
	// run the jet clustering with the above definition, extract the jets
	ClusterSequence cs_trk(input_tracks, jet_def);
	if(debug)std::cout<<"Do jet clustering for input particles \n";
	ClusterSequence cs_m_pcle(input_particles, jet_def);
	// sort the resulting jets in ascending order of pt
	// sorted_by_pt is a method of PseudoJet which returns a vector of jets sorted into decreasing pt
	std::vector<PseudoJet> incl_trkjets_minNConstituents;
	std::vector<PseudoJet> incl_trkjets = sorted_by_pt(cs_trk.inclusive_jets(PTMINJET));
	std::vector<PseudoJet> incl_m_pclejets = sorted_by_pt(cs_m_pcle.inclusive_jets(PTMINJET));
	// print out some infos
	if(debug){std::cout << "Clustering with " << jet_def.description() << std::endl;

	// print the jets
	std::cout <<   "        pt y phi" << std::endl;}
	Njets = incl_trkjets.size();
	M_Njets = incl_m_pclejets.size();
	if(debug)
	{
		std::cout<<"Number of reconstructed jets Njets : " <<Njets << std::endl;
		std::cout<<"Number of truth jets M_Njets : " <<M_Njets << std::endl;
	}
	if(Njets < 1) continue;
	if(M_Njets < 1) continue;
//////////////////////////////////////////////////////////////////////////////////
	// Add jet matching scheme
/////////////////////////////////////////////////////////////////////////////////
	double dr, thisDR, dphi, deta;
	int bestTruthJet;// index of the best matched truth jet
	//! for each track jet
	for (unsigned i = 0; i < incl_trkjets.size(); i++) 
	{
		dr = 9999.0;
		bestTruthJet = -1;
		//! for each truth jet
		//! TODO: what about the truth pcle jets constructed from a single fake track or a combination of fake tracks? 
		//! they will have all track parameters zero. i.e. phi, eta for incl_m_pclejets = 0
		//! How would deltaR look like for these truthjets. 
		//! Can they cause inefficiencies in fake identification sometimes? 
		//! I think yes, and therefore such jets should be marked as fake before calculating any deltaR??
		for(size_t itruth = 0; itruth < incl_m_pclejets.size(); ++itruth)
		{
			//! TODO: for incl_m_pclejets[itruth].phi(),incl_m_pclejets[itruth].eta() = 0. Set thisDR = 9999.9?
			//! Actually it doesn't matter even if the fake jets are mis-identified as having dr < 0.4. because for them the matched parameters will be filled with zero anyway -> finally marking them as fakes jets
			dphi	= incl_m_pclejets[itruth].phi() - incl_trkjets[i].phi();
			deta	= incl_m_pclejets[itruth].eta() - incl_trkjets[i].eta();
			thisDR	= std::sqrt(deta*deta + dphi*dphi);
			if(debug) std::cout<<"thisDr, itruth, bestTruthJet = " <<thisDR <<" , " << itruth << " , " << bestTruthJet<< std::endl;
			if (thisDR < dr)
			{
				dr = thisDR;
				bestTruthJet = itruth;
				if(debug) 
				{
					std::cout<<"thisDr less than dr \n"; 
					std::cout<<"dr, bestTruthJet index : " << dr << " , " << bestTruthJet << std::endl;
				}
			}
		}// end of loop over incl_m_pclejets.size()

		if (dr < 0.4)//remove hard coding
		{
			//! matched track jet found, push_back the parameters labled as matched here  
			if(debug) std::cout<<" matched track jet found!! with dr, index , i, eventNo: " << dr << " , " << bestTruthJet <<" , " << i  <<" , " << eventNo << std::endl;
			M_jetPt.push_back(incl_m_pclejets[bestTruthJet].pt());
			M_jetPhi.push_back(incl_m_pclejets[bestTruthJet].phi());
			M_jetTheta.push_back(incl_m_pclejets[bestTruthJet].theta());
			M_jetEta.push_back(incl_m_pclejets[bestTruthJet].eta());
			M_jetEt.push_back(incl_m_pclejets[bestTruthJet].Et());
			M_jetMt.push_back(incl_m_pclejets[bestTruthJet].mt());
			M_hasConstituents.push_back(incl_m_pclejets[bestTruthJet].has_constituents());
			M_constituentPt.push_back(std::vector<double>());
			M_constituentPhi.push_back(std::vector<double>());
			M_constituentTheta.push_back(std::vector<double>());
			M_constituentEta.push_back(std::vector<double>());
			M_constituentEt.push_back(std::vector<double>());
			M_constituentMt.push_back(std::vector<double>());
			M_constituentPdg.push_back(std::vector<int>());
			M_constituentZ0.push_back(std::vector<double>());

		}
		else
		{
			//! no truth jet matched this track jet, push_back 0's for the parameters labled as matched
			if(debug) std::cout<<" no truth jet matched this track jet :( !! with dr, index : " << dr << " , " << bestTruthJet << std::endl;
			M_jetPt.push_back(0);
			M_jetPhi.push_back(0);
			M_jetTheta.push_back(0);
			M_jetEta.push_back(0);
			M_jetEt.push_back(0);
			M_jetMt.push_back(0);
			M_hasConstituents.push_back(incl_m_pclejets[bestTruthJet].has_constituents());
			M_constituentPt.push_back(std::vector<double>());
			M_constituentPhi.push_back(std::vector<double>());
			M_constituentTheta.push_back(std::vector<double>());
			M_constituentEta.push_back(std::vector<double>());
			M_constituentEt.push_back(std::vector<double>());
			M_constituentMt.push_back(std::vector<double>());
			M_constituentPdg.push_back(std::vector<int>());
			M_constituentZ0.push_back(std::vector<double>());
		}
		//! push back all the track jet parameters here for all "i"
		jetPt.push_back(incl_trkjets[i].pt());
		jetPhi.push_back(incl_trkjets[i].phi());
		jetTheta.push_back(incl_trkjets[i].theta());
                jetEta.push_back(incl_trkjets[i].eta());
                jetEt.push_back(incl_trkjets[i].Et());
                jetMt.push_back(incl_trkjets[i].mt());
		hasConstituents.push_back(incl_trkjets[i].has_constituents());
		constituentPt.push_back(std::vector<double>());
		constituentPhi.push_back(std::vector<double>());
		constituentTheta.push_back(std::vector<double>());
		constituentEta.push_back(std::vector<double>());
		constituentEt.push_back(std::vector<double>());
		constituentMt.push_back(std::vector<double>());
		constituentPdg.push_back(std::vector<int>());
		constituentZ0.push_back(std::vector<double>());
		if(debug)std::cout<<"truth jet pt  size : " << M_jetPt.size() << " , reco jet pt size : " << jetPt.size() << std::endl;
		//if(debug)std::cout << "jet " << i << ": "<< incl_trkjets[i].pt() << " " << incl_trkjets[i].rap() << " " << incl_trkjets[i].phi() << std::endl;
		std::vector<PseudoJet> constituents = sorted_by_pt(incl_trkjets[i].constituents());
		Nconstituents.push_back(constituents.size());
		std::vector<PseudoJet> pcle_constituents = sorted_by_pt(incl_m_pclejets[bestTruthJet].constituents());
		M_Nconstituents.push_back(pcle_constituents.size());
		//if(debug)std::cout<<"number of constituents in jet " << i << " = " << Nconstituents[i] << std::endl;
		for (unsigned j = 0; j < constituents.size(); j++) 
		{
			/*if(j>0)
			{	
				jetPt.push_back(0);
				jetPhi.push_back(0);
				jetTheta.push_back(0);
				jetEta.push_back(0);
				jetEt.push_back(0);
				jetMt.push_back(0);
				hasConstituents.push_back(0);
				
			}*/
			constituentPt[i].push_back(constituents[j].pt());
			constituentPhi[i].push_back(constituents[j].phi());
			constituentTheta[i].push_back(constituents[j].theta());
			constituentEta[i].push_back(constituents[j].eta());
			constituentEt[i].push_back(constituents[j].Et());
			constituentMt[i].push_back(constituents[j].mt());
			constituentPdg[i].push_back(constituents[j].user_info<Constituent_info>().pdg_id());
			constituentZ0[i].push_back(constituents[j].user_info<Constituent_info>().Z0());
			/*if(debug){
			std::cout << "    constituent " << j << "'s pt: " << constituents[j].pt()<< std::endl;
			std::cout << "    constituent " << j << "'s pdg: " << constituents[j].user_info<Constituent_info>().pdg_id()<< std::endl;
			std::cout << "    constituent " << j << "'s Vz: " << constituents[j].user_info<Constituent_info>().Vz()<< std::endl;
			std::cout << "    constituent " << j << "'s Z0: " << constituents[j].user_info<Constituent_info>().Z0()<< std::endl;
			}*/
		}// end of loop over constituents
		if(debug) std::cout<<"fill truth jet constituents : i, bestTruthJet = " << i << " , " << bestTruthJet <<std::endl;
		for (unsigned kj = 0; kj < pcle_constituents.size(); kj++) 
		{
			M_constituentPt[i].push_back(pcle_constituents[kj].pt());
			M_constituentPhi[i].push_back(pcle_constituents[kj].phi());
			M_constituentTheta[i].push_back(pcle_constituents[kj].theta());
			M_constituentEta[i].push_back(pcle_constituents[kj].eta());
			M_constituentEt[i].push_back(pcle_constituents[kj].Et());
			M_constituentMt[i].push_back(pcle_constituents[kj].mt());
			M_constituentPdg[i].push_back(pcle_constituents[kj].user_info<Constituent_info>().pdg_id());
			M_constituentZ0[i].push_back(pcle_constituents[kj].user_info<Constituent_info>().Z0());
			/*if(debug){
			std::cout << "  pcle constituent " << kj << "'s pt: " << constituents[kj].pt()<< std::endl;
			std::cout << "  pcle constituent " << kj << "'s pdg: " << constituents[kj].user_info<Constituent_info>().pdg_id()<< std::endl;
			std::cout << "  pcle constituent " << kj << "'s Vz: " << constituents[kj].user_info<Constituent_info>().Vz()<< std::endl;
			std::cout << "  pcle constituent " << kj << "'s Z0: " << constituents[kj].user_info<Constituent_info>().Z0()<< std::endl;
			}*/
		}// end of loop over pcle_constituents

		//! fill purity histograms
		h_den_vs_ptPU->Fill(jetPt[i]/1e3);
		if(M_jetPt[i]!= 0 ) h_num_vs_ptPU->Fill(jetPt[i]/1e3);
		h_den_vs_etaPU->Fill(jetEta[i]);
		if(M_jetPt[i]!= 0 ) h_num_vs_etaPU->Fill(jetEta[i]);
		//!store psedojets that have a minimum number of constituents associated to them
 		if(i < MIN_Constituents.size())
		{ 
			if(constituents.size() < MIN_Constituents[i])
			{
				continue;
			}
			else 
			{
				bool BREAK = false;
				for(int ithconsti = 0; ithconsti < MIN_Constituents.size(); ithconsti++)
				{
					if(debug) std::cout<<"ith consti = " << ithconsti << ", pT = " << constituents[ithconsti].pt() <<std::endl;
					if(constituents[ithconsti].pt() < MIN_TRACKPT_1)
					{
						BREAK = true;
						break;
					}
				

				}
				if(debug)std::cout<<"Break: "<<BREAK<<std::endl;
				if(BREAK)
				{
					continue;
				}
				
				incl_trkjets_minNConstituents.push_back(incl_trkjets[i]);
			}
		}
	}// end of for loop over jet size
	//! end of Jet Matching
	
	glob_jet->Fill();



/////////////////////////////////////////////////////////////////////////////////
  ///******************* jets per vertex bin *******************///
/////////////////////////////////////////////////////////////////////////////////
	std::vector<PseudoJet> in_tracks;
	//! init the vector of sumpt bin
	r_sumpt.v_sumpt.clear();
	r_sumpt.v_sumpt.resize(NZVTXBIN,0.0);
	
	//! loop over vertex bins
	for(int ith_bin = 0; ith_bin < NZVTXBIN; ++ith_bin)
	{
		////// PV BIN NUMBER FINDER ////////
		int iPVbin = (PV + 0.5 * ZRANGE) / ZBIN_width;
		if(std::fabs(iPVbin - ith_bin) < 1) 
		{
			nthBIN_PV = ith_bin;
			//std::cout <<"PV = " << PV << ",  nthBIN_PV = " << nthBIN_PV <<std::endl;	
		}
		///////////////////////////////////
		
		//! reset input list
		in_tracks.clear();
		//! init output list
		(vectorof_jetpt[ith_bin]).clear();
		(vectorof_jetpt[ith_bin]).resize(NJETS,0.0);
		(vectorof_jetMult[ith_bin]).clear();
		(vectorof_jetMult[ith_bin]).resize(NJETS,0);
		(vec_constTRKpT_1L[ith_bin]).clear();
		(vec_constTRKpT_2L[ith_bin]).clear();
		(vec_constTRKpT_3L[ith_bin]).clear();
		(vec_constTRKpT_4L[ith_bin]).clear();
		(vec_constTRKpT_5L[ith_bin]).clear();
		if(debug)
		{
			std::cout<<"ith bin, tjVec.size() : " << ith_bin <<", " << tjVec.size() << std::endl;
			/*std::cout<<"check if v_sumpt and vector of jet pt reset or not : " << r_sumpt.v_sumpt[ith_bin] << ", " << vectorof_jetpt[ith_bin][0] << ", " << vectorof_jetpt[ith_bin][1] << ", " << vectorof_jetpt[ith_bin][2] << ", " << vectorof_jetpt[ith_bin][3] << ", " << vectorof_jetpt[ith_bin][4] << ", " << vectorof_jetpt[ith_bin][5] << ", " << vectorof_jetpt[ith_bin][6] << ", " << vectorof_jetpt[ith_bin][7] << ", " << vectorof_jetpt[ith_bin][7] << ", " << vectorof_jetpt[ith_bin][8] << ", " << vectorof_jetpt[ith_bin][9] <<std::endl;*/
		}
		//! loop over all tracks
		for(int m = 0; m < tjVec.size(); ++m )
		{
			//! identify the bin number in which these tracks lie
			izbin = (tjVec[m].zv + 0.5 * ZRANGE) / (ZBIN_width);
			if(izbin < 0) izbin = 0;
			if(izbin > NZVTXBIN) izbin = NZVTXBIN - 1;
			if(debug) std::cout<<"looping over all tracks, m:  " << m << ", izbin: " << izbin << std::endl; 
			//! check z bin consistency
			//! i.e. collect the tracks only from immediate neighbours or the ith_bin
			if(std::fabs(izbin - ith_bin)<=1)
			{
				//! create a fastjet::PseudoJet with these components
				//and push back into in_tracks vector
				in_tracks.push_back(fastjet::PseudoJet(tjVec[m].px, tjVec[m].py, tjVec[m].pz, tjVec[m].E));
				if(debug) std::cout<<"z bin consistency passed!" <<std::endl;

			}
		}// end of loop over all tracks

		//! run jet clustering with above jet definition
		fastjet::ClusterSequence clust_seq(in_tracks, jet_def);

		//! get the resulting jets ordered in pt
		std::vector<fastjet::PseudoJet> inclusive_jets = sorted_by_pt(clust_seq.inclusive_jets(PTMINJET));


		//! store result, i.e. in vectorof_jetpt[ith_bin]: keep only highest pt jets from each bin
		//! Notice that inclusive_jets is sorted hence vectorof_jetpt[ith_bin] is also already sorted
		int tmp = 0;
		//! for NJETS in the ith_bin
		bool CUTS_SATISFIED = false;//! multiplicity cut satiffied in this bin
		if(debug)std::cout << "ith_bin: " << ith_bin <<std::endl; 
		for(int n = 0; n < NJETS; ++n)
		{
			if(debug) std::cout<<"size of inclusive_jets:" <<inclusive_jets.size()<<std::endl;
			//! skip the ckeck below if the size of inclusive_jets is smaller than n, for all the subsequent n's
			//! (inclusive_jets[n] will not exist in that case) 
			if(n >= inclusive_jets.size()) break;
			std::vector<PseudoJet> constituents_1 = sorted_by_pt(inclusive_jets[n].constituents());
			
			//! check if the first 5 jets have atleast MIN_Constituents
			//int multiplicity = inclusive_jets[n].constituents().size();
			int multiplicity = constituents_1.size();
			//int multiplicity = 1;
			if(debug) std::cout<<"nconstituents, n: " <<multiplicity  << ", " << n <<std::endl;
			//! if not continue
			//! do not check if not amongst the first five jets
			if(n < MIN_Constituents.size())
			{
				if(multiplicity < MIN_Constituents[n])
				{
					//!go to next jet. But before that fix the value of the nth index for vectorof_jetpt
					//tmp +=1;
					CUTS_SATISFIED = false;
					//continue;
					break;
				}
				//else CUTS_SATISFIED = true;
				else//! check if the minimum number of constituents have a minimum track pT
				{
					//CUTS_SATISFIED = false;
					bool BREAK = false;
					//for(int ithconsti = 0; ithconsti < MIN_Constituents[n]; ithconsti++)
					for(int ithconsti = 0; ithconsti < 1; ithconsti++)// check only for 1st constituent
					{
						if(debug) std::cout<<"ith consti = " << ithconsti << ", pT = " << constituents_1[ithconsti].pt() <<std::endl;
						if(constituents_1[ithconsti].pt() < MIN_TRACKPT_2[n])
						{
							BREAK = true;
							CUTS_SATISFIED = false;
							break;
						}
						else	CUTS_SATISFIED = true;
					

					}
					if(debug)std::cout<<"Break: "<<BREAK<<std::endl;
					if(BREAK)
					{
						//tmp +=1;
						//continue;
						break;
					}
				}	
			}
			if (debug) std::cout<<"n, cuts_satis: " << n << ", " << CUTS_SATISFIED << std::endl; 
			//! at this stage vectorof_jetpt[ith_bin][n] = 0.0 => initialised above
			if(CUTS_SATISFIED && inclusive_jets[n].perp() > vectorof_jetpt[ith_bin][n - tmp]) 
			{
				vectorof_jetpt[ith_bin][n - tmp] = inclusive_jets[n].perp();
				vectorof_jetMult[ith_bin][n - tmp] = multiplicity;
				if(n==0)
				{
					for(int cc = 0; cc < multiplicity; ++cc)
					{
						vec_constTRKpT_1L[ith_bin].push_back(constituents_1[cc].pt()*1e-3);
					}
				}
				else if(n==1)
				{
					for(int cc = 0; cc < multiplicity; ++cc)
					{
						vec_constTRKpT_2L[ith_bin].push_back(constituents_1[cc].pt()*1e-3);
					}
				}
				else if(n==2)
				{
					for(int cc = 0; cc < multiplicity; ++cc)
					{
						vec_constTRKpT_3L[ith_bin].push_back(constituents_1[cc].pt()*1e-3);
					}
				}
				else if(n==3)
				{
					for(int cc = 0; cc < multiplicity; ++cc)
					{
						vec_constTRKpT_4L[ith_bin].push_back(constituents_1[cc].pt()*1e-3);
					}
				}
				else if(n==4)
				{
					for(int cc = 0; cc < multiplicity; ++cc)
					{
						vec_constTRKpT_5L[ith_bin].push_back(constituents_1[cc].pt()*1e-3);
					}
				}
			}
			if(debug) std::cout<<"contents in vectorof_jetpt["<<ith_bin<<"][" << n - tmp<<"] = " <<vectorof_jetpt[ith_bin][n - tmp] <<std::endl;
		}
		//! calculate sum pt for each of the ith_bins
		r_sumpt.v_sumpt[ith_bin] = std::accumulate((vectorof_jetpt[ith_bin]).begin(), (vectorof_jetpt[ith_bin]).end(), 0.0);
		//r_sumpt.v_sumpt[ith_bin] = std::inner_product((vectorof_jetpt[ith_bin]).begin(), (vectorof_jetpt[ith_bin]).end(), (vectorof_jetpt[ith_bin]).begin(), 0.0);
	}// end of loop over NZVTXBIN
	
	///////////////////////////////////////
	//        Fill Histograms            //
	///////////////////////////////////////
	//!clear vectors
	r_sumpt.v_TJMult_sumpt.clear();
	r_sumpt.v_TJMult_maxpt.clear();
	r_sumpt.v_TJMult_sumpt.resize(NJETS,0);
	r_sumpt.v_TJMult_maxpt.resize(NJETS,0);
	
	r_sumpt.v_constTRKpT_1Lsumpt.clear();
	r_sumpt.v_constTRKpT_2Lsumpt.clear();
	r_sumpt.v_constTRKpT_3Lsumpt.clear();
	r_sumpt.v_constTRKpT_4Lsumpt.clear();
	r_sumpt.v_constTRKpT_5Lsumpt.clear();
	
	r_sumpt.v_constTRKpT_1Lmaxpt.clear();
	r_sumpt.v_constTRKpT_2Lmaxpt.clear();
	r_sumpt.v_constTRKpT_3Lmaxpt.clear();
	r_sumpt.v_constTRKpT_4Lmaxpt.clear();
	r_sumpt.v_constTRKpT_5Lmaxpt.clear();

	//! Andre's approach
	r_sumpt.Lpt = vectorof_jetpt[0][0];
	r_sumpt.NLpt = vectorof_jetpt[0][1];
	r_sumpt.NNLpt = vectorof_jetpt[0][2];
	r_sumpt.NNNLpt = vectorof_jetpt[0][3];
	r_sumpt.NNNNLpt = vectorof_jetpt[0][4];
	r_sumpt.PB1 = 0;
	r_sumpt.PB2 = 0;
	r_sumpt.PB3 = 0;
	r_sumpt.PB4 = 0;
	r_sumpt.PB5 = 0;
	//! TJ const pT Andre's approach
	int c_size;
	c_size = std::min((vec_constTRKpT_1L[0]).size(), MIN_Constituents.size());
	for(int cc = 0; cc < c_size; ++cc)
	{
		r_sumpt.v_constTRKpT_1Lmaxpt.push_back(vec_constTRKpT_1L[0][cc]);
		
	}
	c_size = std::min((vec_constTRKpT_2L[0]).size(), MIN_Constituents.size());
	for(int cc = 0; cc < c_size; ++cc)
	{
		r_sumpt.v_constTRKpT_2Lmaxpt.push_back(vec_constTRKpT_2L[0][cc]);
		
	}
	c_size = std::min((vec_constTRKpT_3L[0]).size(), MIN_Constituents.size());
	for(int cc = 0; cc < c_size; ++cc)
	{
		r_sumpt.v_constTRKpT_3Lmaxpt.push_back(vec_constTRKpT_3L[0][cc]);
		
	}
	c_size = std::min((vec_constTRKpT_4L[0]).size(), MIN_Constituents.size());
	for(int cc = 0; cc < c_size; ++cc)
	{
		r_sumpt.v_constTRKpT_4Lmaxpt.push_back(vec_constTRKpT_4L[0][cc]);
		
	}
	c_size = std::min((vec_constTRKpT_5L[0]).size(), MIN_Constituents.size());
	for(int cc = 0; cc < c_size; ++cc)
	{
		r_sumpt.v_constTRKpT_5Lmaxpt.push_back(vec_constTRKpT_5L[0][cc]);
		
	}
	//! sumpt approach
	r_sumpt.max_sumpt = r_sumpt.v_sumpt[0];
	r_sumpt.prim_bin  = 0;
	if(debug) std::cout<<"initial max_sumpt and prim bin: " << r_sumpt.max_sumpt << ", " << r_sumpt.prim_bin << std::endl;
	//! find the highest sum pt bin
	for(int p = 1; p < NZVTXBIN; ++p)
	{
		//! Andre's approach
		//! select largest of the 1st, 2nd, 3rd, 4th, 5th highest pt track jet from all the bins
		if(r_sumpt.Lpt < vectorof_jetpt[p][0]) 
		{
			r_sumpt.Lpt = vectorof_jetpt[p][0];
			r_sumpt.v_TJMult_maxpt[0]  = vectorof_jetMult[p][0];
			r_sumpt.v_constTRKpT_1Lmaxpt.clear();
			c_size = std::min((vec_constTRKpT_1L[p]).size(), MIN_Constituents.size());
			for(int cc = 0; cc < c_size; ++cc)
			{
				r_sumpt.v_constTRKpT_1Lmaxpt.push_back(vec_constTRKpT_1L[p][cc]);
				
			}
			r_sumpt.PB1 = p;

		}
		if(r_sumpt.NLpt < vectorof_jetpt[p][1])
		{
			r_sumpt.NLpt = vectorof_jetpt[p][1];
			r_sumpt.v_TJMult_maxpt[1]  = vectorof_jetMult[p][1];
			r_sumpt.v_constTRKpT_2Lmaxpt.clear();
			c_size = std::min((vec_constTRKpT_2L[p]).size(), MIN_Constituents.size());
			for(int cc = 0; cc < c_size; ++cc)
			{
				r_sumpt.v_constTRKpT_2Lmaxpt.push_back(vec_constTRKpT_2L[p][cc]);
				
			}
			r_sumpt.PB2 = p;
		}
		if(r_sumpt.NNLpt < vectorof_jetpt[p][2])
		{
			r_sumpt.NNLpt = vectorof_jetpt[p][2];
			r_sumpt.v_TJMult_maxpt[2]  = vectorof_jetMult[p][2];
			r_sumpt.v_constTRKpT_3Lmaxpt.clear();
			c_size = std::min((vec_constTRKpT_3L[p]).size(), MIN_Constituents.size());
			for(int cc = 0; cc < c_size; ++cc)
			{
				r_sumpt.v_constTRKpT_3Lmaxpt.push_back(vec_constTRKpT_3L[p][cc]);
				
			}
			r_sumpt.PB3 = p;
		}
		if(r_sumpt.NNNLpt < vectorof_jetpt[p][3])
		{
			r_sumpt.NNNLpt = vectorof_jetpt[p][3];
			r_sumpt.v_TJMult_maxpt[3]  = vectorof_jetMult[p][3];
			r_sumpt.v_constTRKpT_4Lmaxpt.clear();
			c_size = std::min((vec_constTRKpT_4L[p]).size(), MIN_Constituents.size());
			for(int cc = 0; cc < c_size; ++cc)
			{
				r_sumpt.v_constTRKpT_4Lmaxpt.push_back(vec_constTRKpT_4L[p][cc]);
				
			}
			r_sumpt.PB4 = p;
		}
		if(r_sumpt.NNNNLpt < vectorof_jetpt[p][4])
		{
			r_sumpt.NNNNLpt = vectorof_jetpt[p][4];
			r_sumpt.v_TJMult_maxpt[4]  = vectorof_jetMult[p][4];
			r_sumpt.v_constTRKpT_5Lmaxpt.clear();
			c_size = std::min((vec_constTRKpT_5L[p]).size(), MIN_Constituents.size());
			for(int cc = 0; cc < c_size; ++cc)
			{
				r_sumpt.v_constTRKpT_5Lmaxpt.push_back(vec_constTRKpT_5L[p][cc]);
				
			}
			r_sumpt.PB5 = p;
		}

		//! sumpt approach
		if(r_sumpt.max_sumpt < r_sumpt.v_sumpt[p])
		{
			r_sumpt.max_sumpt = r_sumpt.v_sumpt[p];
			r_sumpt.prim_bin  = p;
		}
	}

	r_sumpt.v_TJMult_sumpt[0]  = vectorof_jetMult[r_sumpt.prim_bin][0];
	r_sumpt.v_TJMult_sumpt[1]  = vectorof_jetMult[r_sumpt.prim_bin][1];
	r_sumpt.v_TJMult_sumpt[2]  = vectorof_jetMult[r_sumpt.prim_bin][2];
	r_sumpt.v_TJMult_sumpt[3]  = vectorof_jetMult[r_sumpt.prim_bin][3];
	r_sumpt.v_TJMult_sumpt[4]  = vectorof_jetMult[r_sumpt.prim_bin][4];

	c_size = std::min((vec_constTRKpT_1L[r_sumpt.prim_bin]).size(), MIN_Constituents.size());
	for(int cc = 0; cc < c_size; ++cc)
	{
		r_sumpt.v_constTRKpT_1Lsumpt.push_back(vec_constTRKpT_1L[r_sumpt.prim_bin][cc]);
		
	}
	c_size = std::min((vec_constTRKpT_2L[r_sumpt.prim_bin]).size(), MIN_Constituents.size());
	for(int cc = 0; cc < c_size; ++cc)
	{
		r_sumpt.v_constTRKpT_2Lsumpt.push_back(vec_constTRKpT_2L[r_sumpt.prim_bin][cc]);
		
	}
	c_size = std::min((vec_constTRKpT_3L[r_sumpt.prim_bin]).size(), MIN_Constituents.size());
	for(int cc = 0; cc < c_size; ++cc)
	{
		r_sumpt.v_constTRKpT_3Lsumpt.push_back(vec_constTRKpT_3L[r_sumpt.prim_bin][cc]);
		
	}
	c_size = std::min((vec_constTRKpT_4L[r_sumpt.prim_bin]).size(), MIN_Constituents.size());
	for(int cc = 0; cc < c_size; ++cc)
	{
		r_sumpt.v_constTRKpT_4Lsumpt.push_back(vec_constTRKpT_4L[r_sumpt.prim_bin][cc]);
		
	}
	c_size = std::min((vec_constTRKpT_5L[r_sumpt.prim_bin]).size(), MIN_Constituents.size());
	for(int cc = 0; cc < c_size; ++cc)
	{
		r_sumpt.v_constTRKpT_5Lsumpt.push_back(vec_constTRKpT_5L[r_sumpt.prim_bin][cc]);
		
	}

	if(debug) 
	{
		std::cout<<"highest maxsumpt and prim bin: " << r_sumpt.max_sumpt << ", " << r_sumpt.prim_bin << std::endl;
		std::cout<<"elements of vector of jet pt : " << vectorof_jetpt[r_sumpt.prim_bin][0] << ", " << vectorof_jetpt[r_sumpt.prim_bin][1] << ", " <<vectorof_jetpt[r_sumpt.prim_bin][2] << ", " << vectorof_jetpt[r_sumpt.prim_bin][3] << ", " << vectorof_jetpt[r_sumpt.prim_bin][4] <<std::endl;
	}
	//! Fill multiplicity histograms
	////! Andre's approach
	//////std::cout<<"ha_PULpt   : " <<r_sumpt.Lpt <<std::endl;
	//////std::cout<<"ha_PU1NLpt : " <<r_sumpt.NLpt <<std::endl;
	//////std::cout<<"ha_PU2NLpt : " <<r_sumpt.NNLpt <<std::endl;
	//////std::cout<<"ha_PU3NLpt : " <<r_sumpt.NNNLpt <<std::endl;
	//////std::cout<<"ha_PU4NLpt : " <<r_sumpt.NNNNLpt <<std::endl;
	r_sumpt.hMa_PULpt->Fill(r_sumpt.v_TJMult_maxpt[0]);
	r_sumpt.hMa_PUNLpt->Fill(r_sumpt.v_TJMult_maxpt[1]);
	r_sumpt.hMa_PUNNLpt->Fill(r_sumpt.v_TJMult_maxpt[2]);
	r_sumpt.hMa_PUNNNLpt->Fill(r_sumpt.v_TJMult_maxpt[3]);
	r_sumpt.hMa_PUNNNNLpt->Fill(r_sumpt.v_TJMult_maxpt[4]);
	r_sumpt.Fill_ContTRKpT_maxpt();
	
	r_sumpt.Ma_Lpt = r_sumpt.v_TJMult_maxpt[0];
	r_sumpt.Ma_NLpt = r_sumpt.v_TJMult_maxpt[1];
	r_sumpt.Ma_NNLpt = r_sumpt.v_TJMult_maxpt[2];
	r_sumpt.Ma_NNNLpt = r_sumpt.v_TJMult_maxpt[3];
	r_sumpt.Ma_NNNNLpt = r_sumpt.v_TJMult_maxpt[4];
	
	//
	//////! Sumpt approach
	//////std::cout<<"trackjet size : " <<vectorof_jetpt[r_sumpt.prim_bin].size() <<std::endl;
	//////std::cout<<"h_PULpt   : " <<vectorof_jetpt[r_sumpt.prim_bin][0] <<std::endl;
	//////std::cout<<"h_PU1NLpt : " <<vectorof_jetpt[r_sumpt.prim_bin][1] <<std::endl;
	//////std::cout<<"h_PU2NLpt : " <<vectorof_jetpt[r_sumpt.prim_bin][2] <<std::endl;
	//////std::cout<<"h_PU3NLpt : " <<vectorof_jetpt[r_sumpt.prim_bin][3] <<std::endl;
	//////std::cout<<"h_PU4NLpt : " <<vectorof_jetpt[r_sumpt.prim_bin][4] <<std::endl;
	r_sumpt.hM_PULpt->Fill(r_sumpt.v_TJMult_sumpt[0]);
	r_sumpt.hM_PUNLpt->Fill(r_sumpt.v_TJMult_sumpt[1]);
	r_sumpt.hM_PUNNLpt->Fill(r_sumpt.v_TJMult_sumpt[2]);
	r_sumpt.hM_PUNNNLpt->Fill(r_sumpt.v_TJMult_sumpt[3]);
	r_sumpt.hM_PUNNNNLpt->Fill(r_sumpt.v_TJMult_sumpt[4]);
	r_sumpt.Fill_ContTRKpT_sumpt();
	
	r_sumpt.M_Lpt = r_sumpt.v_TJMult_sumpt[0];
	r_sumpt.M_NLpt = r_sumpt.v_TJMult_sumpt[1];
	r_sumpt.M_NNLpt = r_sumpt.v_TJMult_sumpt[2];
	r_sumpt.M_NNNLpt = r_sumpt.v_TJMult_sumpt[3];
	r_sumpt.M_NNNNLpt = r_sumpt.v_TJMult_sumpt[4];

	bin_Tree->Fill();
	//////! No bin approach
	//////std::cout<<"inclusive trackjet size : " <<incl_trkjets.size() <<std::endl;
	//////std::cout<<"hb_PULpt   : " <<incl_trkjets[0].pt() <<std::endl;
	//////std::cout<<"hb_PU1NLpt : " <<incl_trkjets[1].pt() <<std::endl;
	//////std::cout<<"hb_PU2NLpt : " <<incl_trkjets[2].pt() <<std::endl;
	//////std::cout<<"hb_PU3NLpt : " <<incl_trkjets[3].pt() <<std::endl;
	//////std::cout<<"hb_PU4NLpt : " <<incl_trkjets[4].pt() <<std::endl;
	if(incl_trkjets_minNConstituents.size() > 4)
	{
		r_sumpt.hMb_PULpt->Fill(incl_trkjets_minNConstituents[0].constituents().size());
		r_sumpt.hMb_PUNLpt->Fill(incl_trkjets_minNConstituents[1].constituents().size());
		r_sumpt.hMb_PUNNLpt->Fill(incl_trkjets_minNConstituents[2].constituents().size());
		r_sumpt.hMb_PUNNNLpt->Fill(incl_trkjets_minNConstituents[3].constituents().size());
		r_sumpt.hMb_PUNNNNLpt->Fill(incl_trkjets_minNConstituents[4].constituents().size());
		
		//std::cout<<"1st leading N consti:"<<incl_trkjets_minNConstituents[0].constituents().size()<<std::endl;
		//std::cout<<"2nd leading N consti:"<<incl_trkjets_minNConstituents[1].constituents().size()<<std::endl;
		//std::cout<<"3rd leading N consti:"<<incl_trkjets_minNConstituents[2].constituents().size()<<std::endl;
		//std::cout<<"4th leading N consti:"<<incl_trkjets_minNConstituents[3].constituents().size()<<std::endl;
		//std::cout<<"5th leading N consti:"<<incl_trkjets_minNConstituents[4].constituents().size()<<std::endl;
	}
	else if(incl_trkjets_minNConstituents.size() > 3)
	{
		r_sumpt.hMb_PULpt->Fill(incl_trkjets_minNConstituents[0].constituents().size());
		r_sumpt.hMb_PUNLpt->Fill(incl_trkjets_minNConstituents[1].constituents().size());
		r_sumpt.hMb_PUNNLpt->Fill(incl_trkjets_minNConstituents[2].constituents().size());
		r_sumpt.hMb_PUNNNLpt->Fill(incl_trkjets_minNConstituents[3].constituents().size());
		r_sumpt.hMb_PUNNNNLpt->Fill(0);
	}
	else if(incl_trkjets_minNConstituents.size() > 2)
	{
		r_sumpt.hMb_PULpt->Fill(incl_trkjets_minNConstituents[0].constituents().size());
		r_sumpt.hMb_PUNLpt->Fill(incl_trkjets_minNConstituents[1].constituents().size());
		r_sumpt.hMb_PUNNLpt->Fill(incl_trkjets_minNConstituents[2].constituents().size());
		r_sumpt.hMb_PUNNNLpt->Fill(0);
		r_sumpt.hMb_PUNNNNLpt->Fill(0);
	}
	else if(incl_trkjets_minNConstituents.size() > 1)
	{
		r_sumpt.hMb_PULpt->Fill(incl_trkjets_minNConstituents[0].constituents().size());
		r_sumpt.hMb_PUNLpt->Fill(incl_trkjets_minNConstituents[1].constituents().size());
		r_sumpt.hMb_PUNNLpt->Fill(0);
		r_sumpt.hMb_PUNNNLpt->Fill(0);
		r_sumpt.hMb_PUNNNNLpt->Fill(0);
	}
	else if(incl_trkjets_minNConstituents.size() > 0)
	{
		r_sumpt.hMb_PULpt->Fill(incl_trkjets_minNConstituents[0].constituents().size());
		r_sumpt.hMb_PUNLpt->Fill(0);
		r_sumpt.hMb_PUNNLpt->Fill(0);
		r_sumpt.hMb_PUNNNLpt->Fill(0);
		r_sumpt.hMb_PUNNNNLpt->Fill(0);
	}
	else
	{ 
		r_sumpt.hMb_PULpt->Fill(0);
		r_sumpt.hMb_PUNLpt->Fill(0);
		r_sumpt.hMb_PUNNLpt->Fill(0);
		r_sumpt.hMb_PUNNNLpt->Fill(0);
		r_sumpt.hMb_PUNNNNLpt->Fill(0);
	}
///////////////////////////////////////////////////////////////////////////////
  ///******************* end of jets per vertex bin ************///
///////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
   ///**************Trigger Efficiency***************************///
/////////////////////////////////////////////////////////////////////////////
	//! for every pt bin (corresponding to a pt threshold)
	//std::cout<<"Just checking if everything is okay!" <<std::endl;
	//std::cout<<"nbins : " << trigger.nbins <<std::endl;
	//std::cout<<"Njet_max : " << trigger.Njet_max <<std::endl;
	for(int i2 = 0; i2 < trigger.nbins; i2++)
	{
		//std::cout << "xbins[" <<i2 << "]" <<trigger.xbins[i2]<<std::endl;
		//! sumpt approach
		//! increment n5_tot if there are atleast 5 jets with pt > xbins[i]
		if(vectorof_jetpt[r_sumpt.prim_bin].size() >= trigger.Njet_max)
		{
			if(vectorof_jetpt[r_sumpt.prim_bin][4]*1e-3 > trigger.xbins[i2]) trigger.n5_tot[i2] += 1;
			if(vectorof_jetpt[r_sumpt.prim_bin][3]*1e-3 > trigger.xbins[i2]) trigger.n4_tot[i2] += 1;
			if(vectorof_jetpt[r_sumpt.prim_bin][2]*1e-3 > trigger.xbins[i2]) trigger.n3_tot[i2] += 1;
			if(vectorof_jetpt[r_sumpt.prim_bin][1]*1e-3 > trigger.xbins[i2]) trigger.n2_tot[i2] += 1;
		}
		//! increment n4_tot if there are atleast 4 jets with pt > xbins[i]
		else if (vectorof_jetpt[r_sumpt.prim_bin].size() >= trigger.Njet_max-1)
		{
			if(vectorof_jetpt[r_sumpt.prim_bin][3]*1e-3 > trigger.xbins[i2]) trigger.n4_tot[i2] += 1;
			if(vectorof_jetpt[r_sumpt.prim_bin][2]*1e-3 > trigger.xbins[i2]) trigger.n3_tot[i2] += 1;
			if(vectorof_jetpt[r_sumpt.prim_bin][1]*1e-3 > trigger.xbins[i2]) trigger.n2_tot[i2] += 1;
			
		}
		//! increment n3_tot if there are atleast 3 jets with pt > xbins[i]
		else if (vectorof_jetpt[r_sumpt.prim_bin].size() >= trigger.Njet_max-2)
		{
			if(vectorof_jetpt[r_sumpt.prim_bin][2]*1e-3 > trigger.xbins[i2]) trigger.n3_tot[i2] += 1;
			if(vectorof_jetpt[r_sumpt.prim_bin][1]*1e-3 > trigger.xbins[i2]) trigger.n2_tot[i2] += 1;
			
		}
		//! increment n2_tot if there are atleast 2 jets with pt > xbins[i]
		else if (vectorof_jetpt[r_sumpt.prim_bin].size() >= trigger.Njet_max-3)
		{
			if(vectorof_jetpt[r_sumpt.prim_bin][1]*1e-3 > trigger.xbins[i2]) trigger.n2_tot[i2] += 1;
			
		}
		
		//! overlapping bin approach
		//! increment n5_tot if there are atleast 5 jets with pt > xbins[i]
		if(r_sumpt.NNNNLpt >= PTMINJET)
		{
			if(r_sumpt.NNNNLpt*1e-3 > trigger.xbins[i2]) trigger.n5a_tot[i2] += 1;
			if(r_sumpt.NNNLpt*1e-3 > trigger.xbins[i2]) trigger.n4a_tot[i2] += 1;
			if(r_sumpt.NNLpt*1e-3 > trigger.xbins[i2]) trigger.n3a_tot[i2] += 1;
			if(r_sumpt.NLpt*1e-3 > trigger.xbins[i2]) trigger.n2a_tot[i2] += 1;
		}
		//! increment n4_tot if there are atleast 4 jets with pt > xbins[i]
		else if (r_sumpt.NNNLpt >= PTMINJET)
		{
			if(r_sumpt.NNNLpt*1e-3 > trigger.xbins[i2]) trigger.n4a_tot[i2] += 1;
			if(r_sumpt.NNLpt*1e-3 > trigger.xbins[i2]) trigger.n3a_tot[i2] += 1;
			if(r_sumpt.NLpt*1e-3 > trigger.xbins[i2]) trigger.n2a_tot[i2] += 1;
			
		}
		//! increment n3_tot if there are atleast 3 jets with pt > xbins[i]
		else if (r_sumpt.NNLpt >= PTMINJET)
		{
			if(r_sumpt.NNLpt*1e-3 > trigger.xbins[i2]) trigger.n3a_tot[i2] += 1;
			if(r_sumpt.NLpt*1e-3 > trigger.xbins[i2]) trigger.n2a_tot[i2] += 1;
			
		}
		//! increment n2_tot if there are atleast 2 jets with pt > xbins[i]
		else if (r_sumpt.NLpt >= PTMINJET)
		{
			if(r_sumpt.NLpt*1e-3 > trigger.xbins[i2]) trigger.n2a_tot[i2] += 1;
			
		}
		
		//! increment n5_tot if there are atleast 5 jets with pt > xbins[i]
		//! no z vertex bin
		if(incl_trkjets_minNConstituents.size() >= trigger.Njet_max)
		{
			if(incl_trkjets_minNConstituents[4].pt()*1e-3 > trigger.xbins[i2]) trigger.n5b_tot[i2] += 1;
			if(incl_trkjets_minNConstituents[3].pt()*1e-3 > trigger.xbins[i2]) trigger.n4b_tot[i2] += 1;
			if(incl_trkjets_minNConstituents[2].pt()*1e-3 > trigger.xbins[i2]) trigger.n3b_tot[i2] += 1;
			if(incl_trkjets_minNConstituents[1].pt()*1e-3 > trigger.xbins[i2]) trigger.n2b_tot[i2] += 1;
		}
		//! increment n4_tot if there are atleast 4 jets with pt > xbins[i]
		else if (incl_trkjets_minNConstituents.size() >= trigger.Njet_max-1)
		{
			if(incl_trkjets_minNConstituents[3].pt()*1e-3 > trigger.xbins[i2]) trigger.n4b_tot[i2] += 1;
			if(incl_trkjets_minNConstituents[2].pt()*1e-3 > trigger.xbins[i2]) trigger.n3b_tot[i2] += 1;
			if(incl_trkjets_minNConstituents[1].pt()*1e-3 > trigger.xbins[i2]) trigger.n2b_tot[i2] += 1;
			
		}
		//! increment n3_tot if there are atleast 3 jets with pt > xbins[i]
		else if (incl_trkjets_minNConstituents.size() >= trigger.Njet_max-2)
		{
			if(incl_trkjets_minNConstituents[2].pt()*1e-3 > trigger.xbins[i2]) trigger.n3b_tot[i2] += 1;
			if(incl_trkjets_minNConstituents[1].pt()*1e-3 > trigger.xbins[i2]) trigger.n2b_tot[i2] += 1;
			
		}
		//! increment n2_tot if there are atleast 2 jets with pt > xbins[i]
		else if (incl_trkjets_minNConstituents.size() >= trigger.Njet_max-3)
		{
			if(incl_trkjets_minNConstituents[1].pt()*1e-3 > trigger.xbins[i2]) trigger.n2b_tot[i2] += 1;
			
		}
	}
  }// for loop over nentries
r_sumpt.n_tots.clear();  
r_sumpt.n_tots.push_back(trigger.n2_tot);	
r_sumpt.n_tots.push_back(trigger.n3_tot);	
r_sumpt.n_tots.push_back(trigger.n4_tot);	
r_sumpt.n_tots.push_back(trigger.n5_tot);
r_sumpt.n_tots.push_back(trigger.n2a_tot);	
r_sumpt.n_tots.push_back(trigger.n3a_tot);	
r_sumpt.n_tots.push_back(trigger.n4a_tot);	
r_sumpt.n_tots.push_back(trigger.n5a_tot);
r_sumpt.n_tots.push_back(trigger.n2b_tot);	
r_sumpt.n_tots.push_back(trigger.n3b_tot);	
r_sumpt.n_tots.push_back(trigger.n4b_tot);	
r_sumpt.n_tots.push_back(trigger.n5b_tot);
r_sumpt.Fill_TrigRate(r_sumpt.n_tots);
//! continuation of trigger efficiency cal.
//! we fill outside as we want count the no. of events with 'n' trackjets above a pt threshold
trigger.Fill_TrigEff();
trigger.SetHist_props();
TCanvas *C_trig = new TCanvas();
trigger.DrawSumpt();
C_trig->Write();
C_trig->Clear();
trigger.DrawOvpbin();
C_trig->Write();
C_trig->Clear();
trigger.DrawNoBin();
C_trig->Write();
trigger.WriteAll();

//! create purity histograms as a function of jet pt and jet eta
//std::cout<<"xbin entries :  " << r_sumpt.xbins[1] << ", " << r_sumpt.xbins[40]<<std::endl;
TH1* h_pur_vs_ptPU = dynamic_cast<TH1*>(h_num_vs_ptPU->Clone("h_pur_vs_ptPU"));
h_pur_vs_ptPU->SetTitle("Track Jet Purity vs P_{t};P_{t} [GeV/c];Purity");
h_pur_vs_ptPU->Divide(h_num_vs_ptPU, h_den_vs_ptPU, 1.0, 1.0, "B");
h_pur_vs_ptPU->GetYaxis()->SetRangeUser(0.75, 1.04);
h_pur_vs_ptPU->GetXaxis()->SetRangeUser(2000.0,1000000.0);
h_pur_vs_ptPU->SetMarkerSize(0.95);
h_pur_vs_ptPU->SetMarkerStyle(kOpenTriangleDown);
h_pur_vs_ptPU->SetMarkerColor(kBlack);

TH1* h_pur_vs_etaPU = dynamic_cast<TH1*>(h_num_vs_etaPU->Clone("h_pur_vs_etaPU"));
h_pur_vs_etaPU->SetTitle("Track Jet Purity vs #eta;#eta;Purity");
h_pur_vs_etaPU->Divide(h_num_vs_etaPU, h_den_vs_etaPU, 1.0, 1.0, "B");
h_pur_vs_etaPU->GetYaxis()->SetRangeUser(0.75, 1.04);
h_pur_vs_etaPU->SetMarkerSize(0.95);
h_pur_vs_etaPU->SetMarkerStyle(kOpenTriangleDown);
h_pur_vs_etaPU->SetMarkerColor(kBlack);

//! Write to output file
glob_jet->Write();
h_num_vs_ptPU->Write();
h_den_vs_ptPU->Write();
h_pur_vs_ptPU->Write();
h_num_vs_etaPU->Write();
h_den_vs_etaPU->Write();
h_pur_vs_etaPU->Write();

TCanvas *c1 = new TCanvas();
r_sumpt.DrawNoBin();
c1->SetLogy();
c1->Update();
TCanvas *c2 = new TCanvas();
r_sumpt.DrawRate();
c2->SetLogy();
TCanvas *c3 = new TCanvas();
r_sumpt.DrawSumpt();
c3->SetLogy();
r_sumpt.SetHist_props();
r_sumpt.WriteAll();
c1->Write();
c2->Write();
c3->Write();

bin_Tree->Write();
r_sumpt.SetMultiplicityHist_props();
r_sumpt.WriteMultiplicity();
TCanvas *c4 = new TCanvas();
r_sumpt.DrawMultiplicity();
c4->Write();

TCanvas *c5 = new TCanvas();
r_sumpt.DrawMultiplicitySumpt();
c5->Write();

TCanvas *c6 = new TCanvas();
r_sumpt.DrawMultiplicityMaxpt();
c6->Write();

r_sumpt.SetConstTRKpTHist_props();
r_sumpt.DrawConstTRKpTHist();
r_sumpt.WriteConstTRKpTHist();
TCanvas *c7 = new TCanvas();

f_out->Close();
return 0;
}
