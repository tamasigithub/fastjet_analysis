#include "fastjet/ClusterSequence.hh"
#include "Constituent_info.h"
#include "TrackJetObj.h"
#include <iostream>
#include <vector>
#include "math.h"
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
using namespace fastjet;
#define mass_piPM  139.57018f /* MeV/c^2 */
int main () 
{
  bool debug = false;
  // store results in an output root file 
  // branch variables
  int eventNo;
  int Njets;
  std::vector<double> jetPt;
  std::vector<double> constituentPt;
  std::vector<double> jetPhi;
  std::vector<double> constituentPhi;
  std::vector<double> jetTheta;
  std::vector<double> constituentTheta;
  std::vector<double> jetEta;
  std::vector<double> constituentEta;
  std::vector<double> jetEt;
  std::vector<double> constituentEt;
  std::vector<double> jetMt;
  std::vector<double> constituentMt;
  std::vector<int>    constituentPdg;
  std::vector<double> constituentMvz;
  std::vector<double> constituentZ0;
  std::vector<bool>   hasConstituents;
  TFile *f_out = new TFile("test_jetout.root","RECREATE");
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
  glob_jet->Branch("jetConstMvz",&constituentMvz);
  glob_jet->Branch("jetConstZ0",&constituentZ0);
  glob_jet->Branch("has_constituents",&hasConstituents);
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
  constituentMvz.clear();
  constituentZ0.clear();
  hasConstituents.clear();
  
  TChain rec("m_recTree");
  rec.Add("/afs/cern.ch/work/t/tkar/testarea/20.20.10.1/WorkArea/run/rec_outputs/hh4b_opt/user.tkar.309527VBF_2HDM_H_m1000_hh4bRoot2_MYSTREAM/*.root");
  //! define a local vector<double> to store the reconstructed pt values
  //! always initialise a pointer!!
  std::vector<double> *pt_rec = 0;
  std::vector<double> *z0_rec = 0;
  std::vector<double> *theta_rec = 0;
  std::vector<double> *phi_rec = 0;
  std::vector<double> *tid_rec = 0;
  std::vector<int> *m_pdg = 0;
  std::vector<double> *m_Vz = 0;
  rec.SetBranchStatus("Pt_n",1);
  rec.SetBranchStatus("Z013",1);
  rec.SetBranchStatus("Theta13",1);
  rec.SetBranchStatus("Phi013",1);
  rec.SetBranchStatus("Tid",1);
  rec.SetBranchStatus("M_pdg",1);
  rec.SetBranchStatus("M_Vz",1);
  rec.SetBranchAddress("Pt_n", &pt_rec);
  rec.SetBranchAddress("Z013", &z0_rec);
  rec.SetBranchAddress("Theta13", &theta_rec);
  rec.SetBranchAddress("Phi013", &phi_rec);
  rec.SetBranchAddress("Tid", &tid_rec);
  rec.SetBranchAddress("M_pdg", &m_pdg);
  rec.SetBranchAddress("M_Vz", &m_Vz);
//get mc information -pdgid and z vertex  
  //! vectors containing a single pileup event
  std::vector<double> pt_recPU;
  std::vector<double> z0_recPU;
  std::vector<double> theta_recPU;
  std::vector<double> phi_recPU;
  std::vector<double> tid_recPU;
  std::vector<int> m_pdgPU;
  std::vector<double> m_VzPU;
  
  //! Get total no. of events
  //Long64_t nentries = rec.GetEntries();
  Long64_t n_entries = 300;
  int pileup = 140;
  Long64_t nevents = n_entries/pileup;
  std::vector<TrackJetObj> tjVec;//define outside the loop and call clear inside OR define inside the loop and it will be destroyed at the end of the loop for each iteration similar to the class object
  //! for every event do the following
  //
  double pt,z0,theta,phi,tid,vz0;
  int pid;
  for(Long64_t i = 0; i < nevents; ++i)
  {
  	eventNo=i;
	TrackJetObj tjObj;
	tjVec.clear();
	pt_recPU.clear();
	z0_recPU.clear();
	theta_recPU.clear();
	phi_recPU.clear();
	tid_recPU.clear();
	m_pdgPU.clear();
	m_VzPU.clear();
	
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
			m_VzPU.push_back((*m_Vz)[ik]);
		}
		
	}
	//! number of tracks reconstructed in an event
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
		vz0	= m_VzPU[j];

		if(tid==-1)tjObj.flag = 0;//fakes
		else if(tid > 0)tjObj.flag = 1;//matched tracks
		else if(tid < -1)tjObj.flag = -1;//dc tracks

		//! veto fake and dc tracks?
		//if(tjObj.flag!=1) continue;

		tjObj.px = pt*cos(phi);
		tjObj.py = pt*sin(phi);
		tjObj.pz = pt/tan(theta);
		tjObj.E  = std::sqrt(std::pow(pt/sin(theta),2) + std::pow(mass_piPM,2));
		tjObj.zv = z0;
		tjObj.pdg = pid;
		tjObj.Vz0 = vz0;


		//! push the objects into a vector of these objects
		tjVec.push_back(tjObj);

	}
	
	// choose a jet definition
	double R = 0.4;
	JetDefinition jet_def(antikt_algorithm, R);
	std::vector<PseudoJet> input_particles;

	for(int k = 0; k < tjVec.size(); ++k )
	{
		// an event with particles: px		py		pz   	E
		PseudoJet particle(tjVec[k].px, tjVec[k].py, tjVec[k].pz, tjVec[k].E);
		particle.set_user_info(new Constituent_info(tjVec[k].pdg, tjVec[k].Vz0, tjVec[k].zv));
		input_particles.push_back(particle);
		//input_particles.push_back( PseudoJet( tjVec[k].px, tjVec[k].py, tjVec[k].pz, tjVec[k].E) );  
	}
	// run the jet clustering with the above definition, extract the jets
	ClusterSequence cs(input_particles, jet_def);
	// sort the resulting jets in ascending order of pt
	// sorted_by_pt is a method of PseudoJet which returns a vector of jets sorted into decreasing pt
	std::vector<PseudoJet> incl_jets = sorted_by_pt(cs.inclusive_jets());

	// print out some infos
	if(debug){std::cout << "Clustering with " << jet_def.description() << std::endl;

	// print the jets
	std::cout <<   "        pt y phi" << std::endl;}
	Njets=incl_jets.size();
	for (unsigned i = 0; i < incl_jets.size(); i++) 
	{
		jetPt.push_back(incl_jets[i].pt());
		jetPhi.push_back(incl_jets[i].phi());
		jetTheta.push_back(incl_jets[i].theta());
                jetEta.push_back(incl_jets[i].eta());
                jetEt.push_back(incl_jets[i].Et());
                jetMt.push_back(incl_jets[i].mt());
		hasConstituents.push_back(incl_jets[i].has_constituents());
		if(debug)std::cout << "jet " << i << ": "<< incl_jets[i].pt() << " " << incl_jets[i].rap() << " " << incl_jets[i].phi() << std::endl;
		std::vector<PseudoJet> constituents = incl_jets[i].constituents();
		for (unsigned j = 0; j < constituents.size(); j++) 
		{
			if(j>0)
			{	
				jetPt.push_back(0);
				jetPhi.push_back(0);
				jetTheta.push_back(0);
				jetEta.push_back(0);
				jetEt.push_back(0);
				jetMt.push_back(0);
				hasConstituents.push_back(0);
				
			}
			constituentPt.push_back(constituents[j].pt());
			constituentPhi.push_back(constituents[j].phi());
			constituentTheta.push_back(constituents[j].theta());
			constituentEta.push_back(constituents[j].eta());
			constituentEt.push_back(constituents[j].Et());
			constituentMt.push_back(constituents[j].mt());
			constituentPdg.push_back(constituents[j].user_info<Constituent_info>().pdg_id());
			constituentMvz.push_back(constituents[j].user_info<Constituent_info>().Vz());
			constituentZ0.push_back(constituents[j].user_info<Constituent_info>().Z0());
			if(debug){
			std::cout << "    constituent " << j << "'s pt: " << constituents[j].pt()<< std::endl;
			std::cout << "    constituent " << j << "'s pdg: " << constituents[j].user_info<Constituent_info>().pdg_id()<< std::endl;
			std::cout << "    constituent " << j << "'s Vz: " << constituents[j].user_info<Constituent_info>().Vz()<< std::endl;
			std::cout << "    constituent " << j << "'s Z0: " << constituents[j].user_info<Constituent_info>().Z0()<< std::endl;
			}
		}
	}// for loop over jet size
	glob_jet->Fill();
  }// for loop over nentries
glob_jet->Write();
f_out->Close();
return 0;
}
