#include "fastjet/ClusterSequence.hh"
#include "Constituent_info.h"
#include "TrackJetObj.h"
#include "Rate_sumpt.h"
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
  bool debug = true;
  //bool debug = false;
  
  int NJETS, NZVTXBIN, ZRANGE, ZBIN_width;
  int izbin;
  NJETS = 10;
  NZVTXBIN = 40;
  ZRANGE = 200; // in mm
  ZBIN_width = ZRANGE/NZVTXBIN;
  //! init output vector
  std::vector<std::vector<double>> vectorof_jetpt(NZVTXBIN, std::vector<double>());
  //! create an object to plot rate as a function of pt
  Rate_sumpt r_sumpt(NZVTXBIN);
  
  // store results in an output root file 
  // branch variables
  gInterpreter->GenerateDictionary("vector<vector<double> >","vector");
  gInterpreter->GenerateDictionary("vector<vector<int> >","vector");
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
  TFile *f_out = new TFile("jetout1_rec.root","RECREATE");
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
  TChain rec("m_recTree");
  rec.Add("/afs/cern.ch/work/t/tkar/testarea/20.20.10.1/WorkArea/run/rec_outputs/hh4b_opt/user.tkar.309527VBF_2HDM_H_m1000_hh4bRoot2_MYSTREAM/*.root");
  //! define a local vector<double> to store the reconstructed pt values
  //! always initialise a pointer!!
  std::vector<double> *pt_rec = 0;
  std::vector<double> *z0_rec = 0;
  std::vector<double> *theta_rec = 0;
  std::vector<double> *phi_rec = 0;
  std::vector<int> *tid_rec = 0;
  std::vector<int> *m_pdg = 0;
  std::vector<double> *m_pt = 0;
  std::vector<double> *m_Vz = 0;
  std::vector<double> *m_theta = 0;
  std::vector<double> *m_phi = 0;
  rec.SetBranchStatus("Pt_n",1);
  rec.SetBranchStatus("Z013",1);
  rec.SetBranchStatus("Theta13",1);
  rec.SetBranchStatus("Phi013",1);
  rec.SetBranchStatus("Tid",1);
  rec.SetBranchStatus("M_pdg",1);
  rec.SetBranchStatus("M_pt",1);
  rec.SetBranchStatus("M_Vz",1);
  rec.SetBranchStatus("M_theta",1);
  rec.SetBranchStatus("M_phi",1);
  rec.SetBranchAddress("Pt_n", &pt_rec);
  rec.SetBranchAddress("Z013", &z0_rec);
  rec.SetBranchAddress("Theta13", &theta_rec);
  rec.SetBranchAddress("Phi013", &phi_rec);
  rec.SetBranchAddress("Tid", &tid_rec);
  rec.SetBranchAddress("M_pdg", &m_pdg);
  rec.SetBranchAddress("M_pt", &m_pt);
  rec.SetBranchAddress("M_Vz", &m_Vz);
  rec.SetBranchAddress("M_theta", &m_theta);
  rec.SetBranchAddress("M_phi", &m_phi);
  //! get mc information -pdgid and z vertex  
  //! vectors containing a single pileup event
  std::vector<double> pt_recPU;
  std::vector<double> z0_recPU;
  std::vector<double> theta_recPU;
  std::vector<double> phi_recPU;
  std::vector<int> tid_recPU;
  std::vector<int> m_pdgPU;
  std::vector<double> m_ptPU;
  std::vector<double> m_VzPU;
  std::vector<double> m_thetaPU;
  std::vector<double> m_phiPU;
  
  //! Get total no. of events
  Long64_t nentries = rec.GetEntries();
  //Long64_t nentries = 300;
  int pileup = 140;
  Long64_t nevents = nentries/pileup;
  std::cout<<"Total number of enteries : " << nentries <<std::endl;
  std::cout<<"number of Pile-up events : " << nevents <<std::endl;
  //! vector of reconstructed track-jet objects
  std::vector<TrackJetObj> tjVec;//define outside the loop and call clear inside OR define inside the loop and it will be destroyed at the end of the loop for each iteration similar to the class object
  //! for every event do the following
  //
  double pt,z0,theta,phi,tid,mpt,mVz,mtheta,mphi;
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
	tjVec.clear();
	pt_recPU.clear();
	z0_recPU.clear();
	theta_recPU.clear();
	phi_recPU.clear();
	tid_recPU.clear();
	m_pdgPU.clear();
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
		for(int ik = 0; ik < pt_rec->size(); ++ik)
		{
			pt_recPU.push_back((*pt_rec)[ik]);
			z0_recPU.push_back((*z0_rec)[ik]);
			theta_recPU.push_back((*theta_rec)[ik]);
			phi_recPU.push_back((*phi_rec)[ik]);
			tid_recPU.push_back((*tid_rec)[ik]);
			m_pdgPU.push_back((*m_pdg)[ik]);
			m_ptPU.push_back((*m_pt)[ik]);
			m_VzPU.push_back((*m_Vz)[ik]);
			m_thetaPU.push_back((*m_theta)[ik]);
			m_phiPU.push_back((*m_phi)[ik]);
			
		}
		
	}
	//! total number of tracks reconstructed in an event
	int nobj = pt_recPU.size();
  	if(debug)std::cout<<"nobj: "<<nobj<<std::endl;
	if(nobj<1) continue;
	for (int j = 0; j < nobj; ++j)
	{
		pt	= pt_recPU[j];
		z0	= z0_recPU[j];
		theta	= theta_recPU[j];
		phi	= phi_recPU[j];
		tid	= tid_recPU[j];
		pid	= m_pdgPU[j];
		mpt	= m_ptPU[j];
		mVz	= m_VzPU[j];
		mtheta	= m_thetaPU[j];
		mphi	= m_phiPU[j];
		
		if(debug){std::cout<<"mpt, mVz, mtheta, mphi, tid: " << mpt << " , " << mVz << " , " << mtheta << " , " << mphi << " , " << tid << std::endl; }
		if(tid==-1)tjObj.flag = 0;//fakes
		else if(tid > 0)tjObj.flag = 1;//matched tracks
		else if(tid < -1)tjObj.flag = -1;//dc tracks

		//! veto fake and dc tracks?
		if(tjObj.flag!=1) continue;

		tjObj.px = pt*cos(phi);
		tjObj.py = pt*sin(phi);
		tjObj.pz = pt/tan(theta);
		tjObj.E  = std::sqrt(std::pow(pt/sin(theta),2) + std::pow(mass_piPM,2));
		//! matched truth info has been set to zero for fake tracks and this causes a crash while doing jet clustering
		//! for truth jet clustering we anyway do not need these zeroes
		if(tid==-1){
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
		tjVec.push_back(tjObj);

	}// end of loop over nobj
	
	// choose a jet definition
	double R = 0.4;
	JetDefinition jet_def(antikt_algorithm, R);
	std::vector<PseudoJet> input_tracks;
	std::vector<PseudoJet> input_particles;


	// loop over all tracks
	for(int k = 0; k < tjVec.size(); ++k )
	{
	//	if(debug) std::cout<<"Create Pseudo jets \n";
		// an event with particles: px		py		pz   	E
		PseudoJet trk(tjVec[k].px, tjVec[k].py, tjVec[k].pz, tjVec[k].E);
		trk.set_user_info(new Constituent_info(tjVec[k].pdg, tjVec[k].Vz0, tjVec[k].zv));
		//input_tracks.push_back( PseudoJet( tjVec[k].px, tjVec[k].py, tjVec[k].pz, tjVec[k].E) );  
		input_tracks.push_back(trk);
		
		//! create a Pseudo jet for truth particles
		if(tjVec[k].flag != 1) continue;// get rid of DC tracks and fakes
		PseudoJet m_particle(tjVec[k].px_m, tjVec[k].py_m, tjVec[k].pz_m, tjVec[k].E_m);
		m_particle.set_user_info(new Constituent_info(tjVec[k].pdg, tjVec[k].Vz0, tjVec[k].zv));
		input_particles.push_back(m_particle);
	}// end of loop over all tracks tjVec
	
	if(debug)std::cout<<"Do jet Clustering \n";
	// run the jet clustering with the above definition, extract the jets
	ClusterSequence cs_trk(input_tracks, jet_def);
	if(debug)std::cout<<"Do jet clustering for input particles \n";
	ClusterSequence cs_m_pcle(input_particles, jet_def);
	// sort the resulting jets in ascending order of pt
	// sorted_by_pt is a method of PseudoJet which returns a vector of jets sorted into decreasing pt
	std::vector<PseudoJet> incl_trkjets = sorted_by_pt(cs_trk.inclusive_jets());
	std::vector<PseudoJet> incl_m_pclejets = sorted_by_pt(cs_m_pcle.inclusive_jets());
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
	// Add jet matching scheme
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
		if (dr < 0.4)
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
		std::vector<PseudoJet> constituents = incl_trkjets[i].constituents();
		Nconstituents.push_back(constituents.size());
		std::vector<PseudoJet> pcle_constituents = incl_m_pclejets[bestTruthJet].constituents();
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
			/*constituentPt.back().push_back(constituents[j].pt());
			constituentPhi.back().push_back(constituents[j].phi());
			constituentTheta.back().push_back(constituents[j].theta());
			constituentEta.back().push_back(constituents[j].eta());
			constituentEt.back().push_back(constituents[j].Et());
			constituentMt.back().push_back(constituents[j].mt());
			constituentPdg.back().push_back(constituents[j].user_info<Constituent_info>().pdg_id());
			constituentMvz.back().push_back(constituents[j].user_info<Constituent_info>().Vz());
			constituentZ0.back().push_back(constituents[j].user_info<Constituent_info>().Z0());*/
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
	}// end of for loop over jet size
	glob_jet->Fill();

  ///******************* jets per vertex bin *******************///
	std::vector<PseudoJet> in_tracks;
	//! init the vector of sumpt bin
	r_sumpt.v_sumpt.clear();
	r_sumpt.v_sumpt.resize(NZVTXBIN,0.0);
	
	//! loop over vertex bins
	for(int ith_bin = 0; ith_bin < NZVTXBIN; ++ith_bin)
	{
		//! reset input list
		in_tracks.clear();
		//! init output list
		(vectorof_jetpt[ith_bin]).clear();
		(vectorof_jetpt[ith_bin]).resize(NJETS,0.0);
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
			if(abs(izbin - ith_bin)<=1)
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
		std::vector<fastjet::PseudoJet> inclusive_jets = sorted_by_pt(clust_seq.inclusive_jets());

		//! store result: keep only highest pt jets from each bin
		//! Notice that inclusive_jets is sorted hence vectorof_jetpt[ith_bin] is also already sorted
		for(int n = 0; n < NJETS; ++n)
		{
			if(n >= inclusive_jets.size()) break;
			if(inclusive_jets[n].perp() > vectorof_jetpt[ith_bin][n]) vectorof_jetpt[ith_bin][n] = inclusive_jets[n].perp();
		}
		//! calculate sum pt for each of the ith_bins
		r_sumpt.v_sumpt[ith_bin] = std::accumulate((vectorof_jetpt[ith_bin]).begin(), (vectorof_jetpt[ith_bin]).end(), 0.0);
	}// end of loop over NZVTXBIN

	r_sumpt.max_sumpt = r_sumpt.v_sumpt[0];
	r_sumpt.prim_bin  = 0;
	if(debug) std::cout<<"initial max_sumpt and prim bin: " << r_sumpt.max_sumpt << ", " << r_sumpt.prim_bin << std::endl;
	//! find the highest sum pt bin
	for(int p = 1; p < NZVTXBIN; ++p)
	{
		if(r_sumpt.max_sumpt < r_sumpt.v_sumpt[p])
		{
			r_sumpt.max_sumpt = r_sumpt.v_sumpt[p];
			r_sumpt.prim_bin  = p;
		}
	}
	if(debug) 
	{
		std::cout<<"highest maxsumpt and prim bin: " << r_sumpt.max_sumpt << ", " << r_sumpt.prim_bin << std::endl;
		std::cout<<"elements of vector of jet pt : " << vectorof_jetpt[r_sumpt.prim_bin][0] << ", " << vectorof_jetpt[r_sumpt.prim_bin][1] << ", " <<vectorof_jetpt[r_sumpt.prim_bin][2] << ", " << vectorof_jetpt[r_sumpt.prim_bin][3] << ", " << vectorof_jetpt[r_sumpt.prim_bin][4] <<std::endl;
	}
	//! Fill histograms
	r_sumpt.h_PULpt->Fill(vectorof_jetpt[r_sumpt.prim_bin][0]);
	r_sumpt.h_PUNLpt->Fill(vectorof_jetpt[r_sumpt.prim_bin][1]);
	r_sumpt.h_PUNNLpt->Fill(vectorof_jetpt[r_sumpt.prim_bin][2]);
	r_sumpt.h_PUNNNLpt->Fill(vectorof_jetpt[r_sumpt.prim_bin][3]);
	r_sumpt.h_PUNNNNLpt->Fill(vectorof_jetpt[r_sumpt.prim_bin][4]);

  ///******************* end of jets per vertex bin ************///
  }// for loop over nentries
glob_jet->Write();
TCanvas *c1 = new TCanvas();
r_sumpt.SetHist_props();
//r_sumpt.h_PULpt->Draw();
//r_sumpt.h_PULpt->Write();
r_sumpt.DrawAll();
r_sumpt.WriteAll();
c1->Write();
f_out->Close();
return 0;
}
