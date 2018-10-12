#include "fastjet/ClusterSequence.hh"
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
  TChain rec("m_recTree");
  rec.Add("/afs/cern.ch/work/t/tkar/testarea/20.20.10.1/WorkArea/run/rec_outputs/hh4b_opt/user.tkar.tkar119995.MBRoot2_MYSTREAM/user.tkar.15403921.MYSTREAM._000002.root");
  //! define a local vector<double> to store the reconstructed pt values
  //! always initialise a pointer!!
  std::vector<double> *pt_rec = 0;
  std::vector<double> *z0_rec = 0;
  std::vector<double> *theta_rec = 0;
  std::vector<double> *phi_rec = 0;
  std::vector<double> *tid_rec = 0;
  rec.SetBranchStatus("Pt_n",1);
  rec.SetBranchStatus("Z013",1);
  rec.SetBranchStatus("Theta13",1);
  rec.SetBranchStatus("Phi013",1);
  rec.SetBranchStatus("Tid",1);
  rec.SetBranchAddress("Pt_n", &pt_rec);
  rec.SetBranchAddress("Z013", &z0_rec);
  rec.SetBranchAddress("Theta13", &theta_rec);
  rec.SetBranchAddress("Phi013", &phi_rec);
  rec.SetBranchAddress("Tid", &tid_rec);
  
  //! Get total no. of events
  //Long64_t n_entries = rec.GetEntries();
  Long64_t n_entries = 10;
  std::vector<TrackJetObj> tjVec;//define outside the loop and call clear inside OR define inside the loop and it will be destroyed at the end of the loop for each iteration similar to the class object
  //! for every event do the following
  for(Long64_t i = 0; i < n_entries; ++i)
  {
	double pt,z0,theta,phi,tid;
	TrackJetObj tjObj;
	tjVec.clear();
	rec.GetEntry(i);
	//! number of tracks reconstructed in an event
	int nobj = pt_rec->size();
  	std::cout<<"nobj: "<<nobj<<std::endl;
	if(nobj<1) continue;
	for (int j = 0; j < nobj; ++j)
	{
		pt	= (*pt_rec)[j];
		z0	= (*z0_rec)[j];
		theta	= (*theta_rec)[j];
		phi	= (*phi_rec)[j];
		tid	= (*tid_rec)[j];

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

		//! push the objects into a vector of these objects
		tjVec.push_back(tjObj);

	}
	
	// choose a jet definition
	double R = 0.4;
	JetDefinition jet_def(antikt_algorithm, R);
	std::vector<PseudoJet> input_particles;

	for(int k = 0; k < tjVec.size(); ++k )
	{
		// an event with three particles:   px    py  pz      E
		input_particles.push_back( PseudoJet( tjVec[k].px, tjVec[k].py, tjVec[k].pz, tjVec[k].E) );  
	}
	// run the clustering, extract the jets
	ClusterSequence cs(input_particles, jet_def);
	std::vector<PseudoJet> jets = sorted_by_pt(cs.inclusive_jets());

	// print out some infos
	std::cout << "Clustering with " << jet_def.description() << std::endl;

	// print the jets
	std::cout <<   "        pt y phi" << std::endl;
	for (unsigned i = 0; i < jets.size(); i++) 
	{
		std::cout << "jet " << i << ": "<< jets[i].pt() << " " << jets[i].rap() << " " << jets[i].phi() << std::endl;
		std::vector<PseudoJet> constituents = jets[i].constituents();
		for (unsigned j = 0; j < constituents.size(); j++) 
		{
			std::cout << "    constituent " << j << "'s pt: " << constituents[j].pt()<< std::endl;
		}
	}// for loop over jet size
  }// for loop over nentries
return 0;
}
