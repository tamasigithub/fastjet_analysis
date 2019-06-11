#include "fastjet/ClusterSequence.hh"
#include "Constituent_info.h"
#include "TrackJetObj.h"
#include <iostream>
#include <vector>
#include "math.h"
#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TChain.h>
#include <TMath.h>
#include <TInterpreter.h>
using namespace fastjet;
#define mass_piPM  139.57018f /* MeV/c^2 */
int main () 
{
  //bool debug = true;
  bool debug = false;
  
  //! variables used to make efficiency plots
  int etabin = 19;
  double etamin =-1.4, etamax = 1.4;
  // log bins
  const int ptbins = 40;//no. of bins
  int length = ptbins + 1;
  Double_t xbins[length];//elements of this array are
  double dx, l10;
  dx = 5./ptbins;//5 -> implies max until 10^5
  l10 = TMath::Log(10);
  for (int i = 0; i<=ptbins; i++)
  {
	//std::cout<<"i,dx : " <<i << ", "<<dx <<std::endl;
	xbins[i] = TMath::Exp(l10*i*dx);
	//std::cout<<"xbin[i] : " <<xbins[i] <<std::endl;
  }
  
  //! store results in an output root file 
  //! branch variables
  gInterpreter->GenerateDictionary("vector<vector<double> >","vector");
  gInterpreter->GenerateDictionary("vector<vector<int> >","vector");
   int eventNo;
  //! truth-jets
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
  //! matched to truth reco track-jets
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
  //TFile *f_out = new TFile("jetEff_LptMB1_3rec.root","RECREATE");
  //TFile *f_out = new TFile("jetEff_LptMB1_5rec.root","RECREATE");
  //TFile *f_out = new TFile("jetEff_LptMB1_noKaprec.root","RECREATE");
  TFile *f_out = new TFile("jetEff_LptMB1_looserec.root","RECREATE");
  TH1::SetDefaultSumw2(true);
  //! track jet efficiency
  TH1* h_num_vs_etaPU = new TH1F("h_num_vs_etaPU", "Numerator Count vs #eta;#eta;Numerator Count", etabin, etamin, etamax);
  TH1* h_den_vs_etaPU = new TH1F("h_den_vs_etaPU", "Denominator Count vs #eta;#eta;Denominator Count", etabin, etamin, etamax);
  TH1* h_num_vs_ptPU = new TH1F("h_num_vs_ptPU", "Numerator Count vs P_{t};P_{t} [MeV/c];Numerator Count", ptbins, xbins);
  TH1* h_den_vs_ptPU = new TH1F("h_den_vs_ptPU", "Denominator Count vs P_{t};P_{t} [MeV/c];Denominator Count", ptbins, xbins);

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
  
  //! open input trees 
  TChain rec("m_truthTree");
  //! high pt min bias sample sigma = 3
  //rec.Add("/eos/user/t/tkar/grid_files/user.tkar.tkar119996.MBRootOpt3_1_MYSTREAM/user.tkar.16621546.MYSTREAM/*.root");
  //!low pt min bias sample sigma=3
  //rec.Add("/eos/user/t/tkar/grid_files/user.tkar.tkar119995.MBRootOpt3_1_MYSTREAM/*.root");
  //!low pt min bias sample sigma=5
  //rec.Add("/eos/user/t/tkar/grid_files/user.tkar.tkar119995.MBRootOpt5_1_MYSTREAM/*.root");
  //!low pt min bias sample without kappa cut
  //rec.Add("/eos/user/t/tkar/grid_files/user.tkar.tkar119995.MBRootOptnoKap_1_MYSTREAM/*.root");
  //!low pt min bias sample without kappa, dphi2 and dz2 cuts
  rec.Add("/eos/user/t/tkar/grid_files/user.tkar.tkar119995.MBRootOptloose_1_MYSTREAM/*.root");
  //rec.Add("/afs/cern.ch/work/t/tkar/testarea/20.20.10.1/WorkArea/run/rec_outputs/hh4b_opt/user.tkar.309527VBF_2HDM_H_m1000_hh4bRoot2_MYSTREAM/*.root");
  //! define a local vector<double> to store the reconstructed pt values
  //! always initialise a pointer!!
  std::vector<double> *pt_tru = 0;
  std::vector<double> *z0_tru = 0;
  std::vector<double> *theta_tru = 0;
  std::vector<double> *eta_tru = 0;
  std::vector<double> *phi_tru = 0;
  std::vector<double> *tid_tru = 0;
  std::vector<int> *pdg = 0;
  std::vector<double> *m_pt = 0;
  std::vector<double> *m_Vz = 0;
  std::vector<double> *m_theta = 0;
  std::vector<double> *m_phi = 0;
  rec.SetBranchStatus("pt",1);
  rec.SetBranchStatus("Vz",1);
  rec.SetBranchStatus("theta",1);
  rec.SetBranchStatus("eta",1);
  rec.SetBranchStatus("phi",1);
  rec.SetBranchStatus("r_tid",1);
  rec.SetBranchStatus("pdg",1);
  rec.SetBranchStatus("r_Pt_n",1);
  rec.SetBranchStatus("r_Z013",1);
  rec.SetBranchStatus("r_Theta13",1);
  rec.SetBranchStatus("r_Phi013",1);
  rec.SetBranchAddress("pt", &pt_tru);
  rec.SetBranchAddress("Vz", &z0_tru);
  rec.SetBranchAddress("theta", &theta_tru);
  rec.SetBranchAddress("eta", &eta_tru);
  rec.SetBranchAddress("phi", &phi_tru);
  rec.SetBranchAddress("r_tid", &tid_tru);
  rec.SetBranchAddress("pdg", &pdg);
  rec.SetBranchAddress("r_Pt_n", &m_pt);
  rec.SetBranchAddress("r_Z013", &m_Vz);
  rec.SetBranchAddress("r_Theta13", &m_theta);
  rec.SetBranchAddress("r_Phi013", &m_phi);
  //! get mc information -pdgid and z vertex  
  //! vectors containing a single pileup event
  std::vector<double> pt_truPU;
  std::vector<double> z0_truPU;
  std::vector<double> theta_truPU;
  std::vector<double> eta_truPU;
  std::vector<double> phi_truPU;
  std::vector<double> tid_truPU;
  std::vector<int> pdgPU;
  std::vector<double> m_ptPU;
  std::vector<double> m_VzPU;
  std::vector<double> m_thetaPU;
  std::vector<double> m_phiPU;
  
  //! Get total no. of events
  Long64_t nentries = rec.GetEntries();
  //Long64_t nentries = 1000;
  int pileup = 160;
  Long64_t nevents = nentries/pileup;
  std::cout<<"Total number of enteries : " << nentries <<std::endl;
  std::cout<<"number of Pile-up events : " << nevents <<std::endl;
  //! vector of reconstructed track-jet objects
  std::vector<TrackJetObj> trjVec;//define outside the loop and call clear inside OR define inside the loop and it will be destroyed at the end of the loop for each iteration similar to the class object
  //! for every event do the following
  //
  double pt,z0,theta,eta,phi,tid,mpt,mVz,mtheta,mphi;
  int pid;
  for(Long64_t i = 0; i < nevents; ++i)
  {
  	eventNo=i;
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
	trjVec.clear();
	pt_truPU.clear();
	z0_truPU.clear();
	theta_truPU.clear();
	eta_truPU.clear();
	phi_truPU.clear();
	tid_truPU.clear();
	pdgPU.clear();
	m_ptPU.clear();
	m_VzPU.clear();
	m_thetaPU.clear();
	m_phiPU.clear();
	

	
	int skip = i*pileup;
	if(debug)
	{
		std::cout<<"skip:"<<skip <<"\n";
		std::cout<<"i:" <<i <<"\n";
	}
	for(int ievent = skip; ievent < skip+pileup; ++ievent)
	{
		rec.GetEntry(ievent);
		for(int ik = 0; ik < pt_tru->size(); ++ik)
		{
			pt_truPU.push_back((*pt_tru)[ik]);
			z0_truPU.push_back((*z0_tru)[ik]);
			theta_truPU.push_back((*theta_tru)[ik]);
			eta_truPU.push_back((*eta_tru)[ik]);
			phi_truPU.push_back((*phi_tru)[ik]);
			tid_truPU.push_back((*tid_tru)[ik]);
			pdgPU.push_back((*pdg)[ik]);
			m_ptPU.push_back((*m_pt)[ik]);
			m_VzPU.push_back((*m_Vz)[ik]);
			m_thetaPU.push_back((*m_theta)[ik]);
			m_phiPU.push_back((*m_phi)[ik]);
			
		}
		
	}
	//! total number of tracks reconstructed in an event
	int nobj = pt_truPU.size();
  	if(debug)std::cout<<"nobj: "<<nobj<<std::endl;
	if(nobj<1) continue;
	for (int j = 0; j < nobj; ++j)
	{
		pt	= pt_truPU[j];
		z0	= z0_truPU[j];
		theta	= theta_truPU[j];
		eta	= eta_truPU[j];
		phi	= phi_truPU[j];
		tid	= tid_truPU[j];
		pid	= pdgPU[j];
		mpt	= m_ptPU[j];
		mVz	= m_VzPU[j];
		mtheta	= m_thetaPU[j];
		mphi	= m_phiPU[j];
		
		if(pt < 2000 || abs(z0)>100 || abs(eta)>1.5) tjObj.flag = -2; //! need to get rid of them for efficiency calculation.
		else if(tid==0)tjObj.flag = 0;//inefficiency
		else if(tid > 0)tjObj.flag = 1;//matched tracks
		else if(tid < -1)tjObj.flag = -1;//dc truth particles

		//! veto fake and dc tracks?
		//if(tjObj.flag!=1) continue;
		//! veto only dc tracks and those which do not satisfy the above selection cuts?

		if(tjObj.flag < 0) continue;

		if(debug)
		{
			std::cout<<"flag : " << tjObj.flag <<std::endl;
			std::cout<<"pt, z0, theta, phi, pid: " << pt << " , " << z0 << " , " << theta << " , " << phi << " , " << pid << std::endl;
			std::cout<<"mpt, mVz, mtheta, mphi, tid: " << mpt << " , " << mVz << " , " << mtheta << " , " << mphi << " , " << tid << std::endl;
		
		}
		tjObj.px = pt*cos(phi);
		tjObj.py = pt*sin(phi);
		tjObj.pz = pt/tan(theta);
		tjObj.E  = std::sqrt(std::pow(pt/sin(theta),2) + std::pow(mass_piPM,2));
		//! matched to truth, reco info has been set to zero for inefficinecy and this causes a crash while doing jet clustering
		//! for rec jet clustering we anyway do not need these zeroes
		if(tid==0/*-1*/){
		tjObj.px_m = 1.0;
		tjObj.py_m = 1.0;
		tjObj.pz_m = 1.0;
		tjObj.E_m  = 1.0;}
		else{
		tjObj.px_m = mpt*cos(mphi);
		tjObj.py_m = mpt*sin(mphi);
		tjObj.pz_m = mpt/tan(mtheta);
		tjObj.E_m  = std::sqrt(std::pow(mpt/sin(mtheta),2) + std::pow(mass_piPM,2));}
		tjObj.zv = z0;
		tjObj.pdg = pid;
		tjObj.Vz0 = mVz;


		//! push the objects into a vector of these objects
		trjVec.push_back(tjObj);

	}// end of loop over nobj
	
	// choose a jet definition
	double R = 0.4;
	double PTMINJET = 5.0;
	JetDefinition jet_def(antikt_algorithm, R);
	std::vector<PseudoJet> input_trpcle;
	std::vector<PseudoJet> input_tracks;


	// loop over all truth particles
	for(int k = 0; k < trjVec.size(); ++k )
	{
		//if(debug) std::cout<<"Create Pseudo jets \n";
		// an event with particles: px		py		pz   	E
		PseudoJet trpcle(trjVec[k].px, trjVec[k].py, trjVec[k].pz, trjVec[k].E);
		trpcle.set_user_info(new Constituent_info(trjVec[k].pdg, trjVec[k].Vz0, trjVec[k].zv));
		//input_trpcle.push_back( PseudoJet( trjVec[k].px, trjVec[k].py, trjVec[k].pz, trjVec[k].E) );  
		input_trpcle.push_back(trpcle);
		
		//! create a Pseudo jet for matched to truth, reco tracks
		if(trjVec[k].flag != 1) continue;// get rid of DC tracks and fakes
		//if(trjVec[k].flag == -1) continue;// get rid of DC tracks only
		PseudoJet m_trk(trjVec[k].px_m, trjVec[k].py_m, trjVec[k].pz_m, trjVec[k].E_m);
		m_trk.set_user_info(new Constituent_info(trjVec[k].pdg, trjVec[k].Vz0, trjVec[k].zv));
		input_tracks.push_back(m_trk);
	}// end of loop over all tracks trjVec
	
	if(debug)std::cout<<"Do jet Clustering \n";
	// run the jet clustering with the above definition, extract the jets
	ClusterSequence cs_trpcle(input_trpcle, jet_def);
	if(debug)std::cout<<"Do jet clustering for input tracks \n";
	ClusterSequence cs_m_trk(input_tracks, jet_def);
	// sort the resulting jets in ascending order of pt
	// sorted_by_pt is a method of PseudoJet which returns a vector of jets sorted into decreasing pt
	std::vector<PseudoJet> incl_trpclejets = sorted_by_pt(cs_trpcle.inclusive_jets(PTMINJET));
	std::vector<PseudoJet> incl_m_trkjets = sorted_by_pt(cs_m_trk.inclusive_jets(PTMINJET));
	// print out some infos
	if(debug){std::cout << "Clustering with " << jet_def.description() << std::endl;

	// print the jets
	std::cout <<   "        pt y phi" << std::endl;}
	Njets = incl_trpclejets.size();
	M_Njets = incl_m_trkjets.size();
	if(debug)
	{
		std::cout<<"Number of truth jets Njets : " <<Njets << std::endl;
		std::cout<<"Number of reconstructed jets M_Njets : " <<M_Njets << std::endl;

	}
	// Add jet matching scheme
	double dr, thisDR, dphi, deta;
	int bestRecJet;// index of the best matched reco jet
	//! for each truth jet
	for (unsigned ii = 0; ii < incl_trpclejets.size(); ii++) 
	{
		dr = 9999.0;
		bestRecJet = -1;
		//! for each track jet
		//! TODO: what about the truth pcle jets constructed from a single fake track or a combination of fake tracks? 
		//! they will have all track parameters zero. i.e. phi, eta for incl_m_trkjets = 0
		//! How would deltaR look like for these truthjets. 
		//! Can they cause inefficiencies in fake identification sometimes? 
		//! I think yes, and therefore such jets should be marked as fake before calculating any deltaR??
		for(size_t irec = 0; irec < incl_m_trkjets.size(); ++irec)
		{
			//! TODO: for incl_m_trkjets[irec].phi(),incl_m_trkjets[irec].eta() = 0. Set thisDR = 9999.9?
			//! Actually it doesn't matter even if the fake jets are mis-identified as having dr < 0.4. because for them the matched parameters will be filled with zero anyway -> finally marking them as fakes jets
			dphi	= incl_m_trkjets[irec].phi() - incl_trpclejets[ii].phi();
			deta	= incl_m_trkjets[irec].eta() - incl_trpclejets[ii].eta();
			thisDR	= std::sqrt(deta*deta + dphi*dphi);
			if(debug) std::cout<<"thisDr, irec, bestRecJet = " <<thisDR <<" , " << irec << " , " << bestRecJet<< std::endl;
			if (thisDR < dr)
			{
				dr = thisDR;
				bestRecJet = irec;
				if(debug) 
				{
					std::cout<<"thisDr less than dr \n"; 
					std::cout<<"dr, bestRecJet index : " << dr << " , " << bestRecJet << std::endl;
				}
			}
		}// end of loop over incl_m_trkjets.size()
		if (dr < 0.4)
		{
			//! matched track jet found, push_back the parameters labled as matched here  
			if(debug) std::cout<<" matched track jet found!! with dr, index , i, eventNo: " << dr << " , " << bestRecJet <<" , " << ii  <<" , " << eventNo << std::endl;
			M_jetPt.push_back(incl_m_trkjets[bestRecJet].pt());
			M_jetPhi.push_back(incl_m_trkjets[bestRecJet].phi());
			M_jetTheta.push_back(incl_m_trkjets[bestRecJet].theta());
			M_jetEta.push_back(incl_m_trkjets[bestRecJet].eta());
			M_jetEt.push_back(incl_m_trkjets[bestRecJet].Et());
			M_jetMt.push_back(incl_m_trkjets[bestRecJet].mt());
			M_hasConstituents.push_back(incl_m_trkjets[bestRecJet].has_constituents());
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
			//! no track jet matched this truth jet, push_back 0's for the parameters labled as matched
			if(debug) std::cout<<" no track jet matched this truth jet :( !! with dr, index : " << dr << " , " << bestRecJet << std::endl;
			M_jetPt.push_back(0);
			M_jetPhi.push_back(0);
			M_jetTheta.push_back(0);
			M_jetEta.push_back(0);
			M_jetEt.push_back(0);
			M_jetMt.push_back(0);
			M_hasConstituents.push_back(incl_m_trkjets[bestRecJet].has_constituents());
			M_constituentPt.push_back(std::vector<double>());
			M_constituentPhi.push_back(std::vector<double>());
			M_constituentTheta.push_back(std::vector<double>());
			M_constituentEta.push_back(std::vector<double>());
			M_constituentEt.push_back(std::vector<double>());
			M_constituentMt.push_back(std::vector<double>());
			M_constituentPdg.push_back(std::vector<int>());
			M_constituentZ0.push_back(std::vector<double>());
		}
		//! push back all the truth jet parameters here for all "ii"
		jetPt.push_back(incl_trpclejets[ii].pt());
		jetPhi.push_back(incl_trpclejets[ii].phi());
		jetTheta.push_back(incl_trpclejets[ii].theta());
                jetEta.push_back(incl_trpclejets[ii].eta());
                jetEt.push_back(incl_trpclejets[ii].Et());
                jetMt.push_back(incl_trpclejets[ii].mt());
		hasConstituents.push_back(incl_trpclejets[ii].has_constituents());
		constituentPt.push_back(std::vector<double>());
		constituentPhi.push_back(std::vector<double>());
		constituentTheta.push_back(std::vector<double>());
		constituentEta.push_back(std::vector<double>());
		constituentEt.push_back(std::vector<double>());
		constituentMt.push_back(std::vector<double>());
		constituentPdg.push_back(std::vector<int>());
		constituentZ0.push_back(std::vector<double>());
		if(debug)std::cout<<"truth jet pt  size : " << jetPt.size() << " , reco jet pt size : " << M_jetPt.size() << std::endl;
		if(debug)
		{
			std::cout << "truth pcle jet " << ii << ": "<< incl_trpclejets[ii].pt() << " " << incl_trpclejets[ii].rap() << " " << incl_trpclejets[ii].phi() << std::endl;
			std::cout << "matched track jet " << ii << ": "<< incl_m_trkjets[bestRecJet].pt() << " " << incl_m_trkjets[bestRecJet].rap() << " " << incl_m_trkjets[bestRecJet].phi() << std::endl;
		}
		std::vector<PseudoJet> constituents = incl_trpclejets[ii].constituents();
		Nconstituents.push_back(constituents.size());
		std::vector<PseudoJet> trk_constituents = incl_m_trkjets[bestRecJet].constituents();
		M_Nconstituents.push_back(trk_constituents.size());
		if(debug)std::cout<<"number of constituents in jet " << ii << " = " << Nconstituents[ii] << std::endl;
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
			constituentPt[ii].push_back(constituents[j].pt());
			constituentPhi[ii].push_back(constituents[j].phi());
			constituentTheta[ii].push_back(constituents[j].theta());
			constituentEta[ii].push_back(constituents[j].eta());
			constituentEt[ii].push_back(constituents[j].Et());
			constituentMt[ii].push_back(constituents[j].mt());
			constituentPdg[ii].push_back(constituents[j].user_info<Constituent_info>().pdg_id());
			constituentZ0[ii].push_back(constituents[j].user_info<Constituent_info>().Z0());
			/*if(debug){
			std::cout << "    constituent " << j << "'s pt: " << constituents[j].pt()<< std::endl;
			std::cout << "    constituent " << j << "'s pdg: " << constituents[j].user_info<Constituent_info>().pdg_id()<< std::endl;
			std::cout << "    constituent " << j << "'s Vz: " << constituents[j].user_info<Constituent_info>().Vz()<< std::endl;
			std::cout << "    constituent " << j << "'s Z0: " << constituents[j].user_info<Constituent_info>().Z0()<< std::endl;
			}*/
		}// end of loop over constituents
		if(debug) std::cout<<"fill track jet constituents : ii, bestRecJet = " << ii << " , " << bestRecJet <<std::endl;
		for (unsigned kj = 0; kj < trk_constituents.size(); kj++) 
		{
			M_constituentPt[ii].push_back(trk_constituents[kj].pt());
			M_constituentPhi[ii].push_back(trk_constituents[kj].phi());
			M_constituentTheta[ii].push_back(trk_constituents[kj].theta());
			M_constituentEta[ii].push_back(trk_constituents[kj].eta());
			M_constituentEt[ii].push_back(trk_constituents[kj].Et());
			M_constituentMt[ii].push_back(trk_constituents[kj].mt());
			M_constituentPdg[ii].push_back(trk_constituents[kj].user_info<Constituent_info>().pdg_id());
			M_constituentZ0[ii].push_back(trk_constituents[kj].user_info<Constituent_info>().Z0());
			/*if(debug){
			std::cout << "  trk constituent " << kj << "'s pt: " << constituents[kj].pt()<< std::endl;
			std::cout << "  trk constituent " << kj << "'s pdg: " << constituents[kj].user_info<Constituent_info>().pdg_id()<< std::endl;
			std::cout << "  trk constituent " << kj << "'s Vz: " << constituents[kj].user_info<Constituent_info>().Vz()<< std::endl;
			std::cout << "  trk constituent " << kj << "'s Z0: " << constituents[kj].user_info<Constituent_info>().Z0()<< std::endl;
			}*/
		}// end of loop over trk_constituents

		//! fill efficiency histograms
		if(debug)
		{
			std::cout<<"filling histograms \n";
			std::cout<<"jetPt, M_jetPt : " << jetPt[ii] << ", " << M_jetPt[ii] << std::endl;
			std::cout<<"jetEta, M_jetEta : " << jetEta[ii] << ", " << M_jetEta[ii] << std::endl;
		}
		h_den_vs_ptPU->Fill(jetPt[ii]);
		if(M_jetPt[ii]!= 0 ) h_num_vs_ptPU->Fill(jetPt[ii]);
		h_den_vs_etaPU->Fill(jetEta[ii]);
		if(M_jetPt[ii]!= 0 ) h_num_vs_etaPU->Fill(jetEta[ii]);
	}// end of for loop over jet size
	glob_jet->Fill();

 }// for loop over nentries

//! create efficiency histograms as a function of jet pt and jet eta
TH1* h_eff_vs_ptPU = dynamic_cast<TH1*>(h_num_vs_ptPU->Clone("h_eff_vs_ptPU"));
h_eff_vs_ptPU->SetTitle("Track Jet Effeciency vs P_{t};P_{t} [MeV/c];Effeciency");
h_eff_vs_ptPU->Divide(h_num_vs_ptPU, h_den_vs_ptPU, 1.0, 1.0, "B");
h_eff_vs_ptPU->GetYaxis()->SetRangeUser(0.85, 1.04);
h_eff_vs_ptPU->GetXaxis()->SetRangeUser(2000.0,1000000.0);
h_eff_vs_ptPU->SetMarkerSize(0.95);
h_eff_vs_ptPU->SetMarkerStyle(kOpenTriangleDown);
h_eff_vs_ptPU->SetMarkerColor(kBlack);

TH1* h_eff_vs_etaPU = dynamic_cast<TH1*>(h_num_vs_etaPU->Clone("h_eff_vs_etaPU"));
h_eff_vs_etaPU->SetTitle("Track Jet Effeciency vs #eta;#eta;Effeciency");
h_eff_vs_etaPU->Divide(h_num_vs_etaPU, h_den_vs_etaPU, 1.0, 1.0, "B");
h_eff_vs_etaPU->GetYaxis()->SetRangeUser(0.85, 1.04);
h_eff_vs_etaPU->SetMarkerSize(0.95);
h_eff_vs_etaPU->SetMarkerStyle(kOpenTriangleDown);
h_eff_vs_etaPU->SetMarkerColor(kBlack);

//! Write to output file
glob_jet->Write();
h_num_vs_ptPU->Write();
h_den_vs_ptPU->Write();
h_eff_vs_ptPU->Write();
h_num_vs_etaPU->Write();
h_den_vs_etaPU->Write();
h_eff_vs_etaPU->Write();

f_out->Close();
return 0;
}
