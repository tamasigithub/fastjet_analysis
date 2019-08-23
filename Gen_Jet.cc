#include "fastjet/ClusterSequence.hh"
#include "Constituent_info.h"
#include "TrackJetObj.h"
#include "Rate_sumpt.h"
#include "TrigEff.h"
//#include "CaloEmu.h"
#include <iostream>
#include <vector>
#include "math.h"
#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TChain.h>
#include <TMath.h>
#include <TRandom.h>
#include <TInterpreter.h>
using namespace fastjet;
#define mass_piPM  139.57018f /* MeV/c^2 */
int main () 
{
  //bool debug = true;
  bool debug = false;
  
/////////////////////////////////////////////////////////
  //! binning for rate and trigger efficienceis
////////////////////////////////////////////////////////
  const float PT_MIN = 0., PT_MAX = 500., PTCUT_WIDTH = 5.0;// in GeV/c
  //! create an object to plot rate as a function of pt
  Rate_sumpt r_sumpt(PT_MIN, PT_MAX, PTCUT_WIDTH);
  r_sumpt.init_Histos(r_sumpt.xbins, r_sumpt.nbins);
  r_sumpt.init_EtaHist();

  //! create an object to plot trigger efficiency as a function of pt
  TrigEff trigger(PT_MIN, PT_MAX, PTCUT_WIDTH);
//////////////////////////////////////////////////////////////////////// 
  //! store results in an output root file 
////////////////////////////////////////////////////////////////////////
  //! branch variables
  gInterpreter->GenerateDictionary("vector<vector<double>>","vector");
  gInterpreter->GenerateDictionary("vector<vector<int>>","vector");
  int eventNo;
  //! truth-jets
  int Njets;						// # of truth-jets
  //std::vector<double> jetE_sm;				// truth-jet energy smeared 
  //std::vector<double> jetPt_sm;				// truth-jet pt smeared
  std::vector<double> jetE;				// truth-jet energy 
  //std::vector<double> jetE_reso;			// x% of truth-jet energy resolution e.g. 50%/sqrt(E)
  std::vector<double> jetPt;				// truth-jet pt
  std::vector<std::vector<double> > constituentPt;	// it's constituents pt
  std::vector<double> jetPhi;                     	//  truth-jet phi
  std::vector<std::vector<double> > constituentPhi;	// it's constituents phi
  std::vector<double> jetTheta;                   	//  truth-jet theta
  std::vector<std::vector<double> > constituentTheta;	// it's constituents theta
  std::vector<double> jetEta;                     	//  truth-jet eta
  std::vector<std::vector<double> > constituentEta;	// it's constituents eta
  std::vector<double> jetEt;                     	//  truth-jet energy 
  std::vector<std::vector<double> > constituentEt;      // it's constituents energy
  std::vector<double> jetMt;                     	//  truth-jet mass
  std::vector<std::vector<double> > constituentMt;      // it's constituents mass
  std::vector<std::vector<int> >    constituentPdg;	// pdg of truth-jet constituents
  std::vector<std::vector<double> > constituentZ0;	//  z vertex truth-jet constituents
  std::vector<bool>  hasConstituents;            	// flag indicating if the truth-jet has constituents
  std::vector<int>   Nconstituents;	            	// number of constituents for each jet

  //! open input trees 
  TChain rec("CollectionTree");
  //! use a sample w/o any pileup for these studies
  rec.Add("/home/tamasi/repo_tamasi/user.tkar.pp_VBF_H_260_hh_4b_pythia82_shower_nopileup.v8_output.root/*.root");
  //! Get total no. of events
  //Long64_t nevents = 10;
  Long64_t nevents = rec.GetEntries();
  r_sumpt.nevents = nevents;
  std::cout<<"number of Pile-up events : " << nevents <<std::endl;

  //! output root file
  TFile *f_out = new TFile("Genjet_PU0hh4b_m260_q1.2GeV_1.root","RECREATE");
  TH1::SetDefaultSumw2(true);
  TTree *glob_jet = new TTree("glob_jet","glob_jet");
  glob_jet->Branch("event",&eventNo);
  glob_jet->Branch("Njets",&Njets);
  //glob_jet->Branch("jetE_sm",&jetE_sm);
  //glob_jet->Branch("jetPt_sm",&jetPt_sm);
  glob_jet->Branch("jetE",&jetE);
  //glob_jet->Branch("jetE_reso",&jetE_reso);
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
  
  //! define a local vector<double> to store the input values
  //! always initialise a pointer!!
  std::vector<float> *px_tru = 0;
  std::vector<float> *py_tru = 0;
  std::vector<float> *pz_tru = 0;
  std::vector<float> *vz_tru = 0;
  std::vector<float> *energy = 0;
  //std::vector<float> *charge = 0;
  std::vector<float> *mass = 0;
  std::vector<int> *pdg = 0;
  std::vector<int> *status = 0;
  std::vector<int> *barcode = 0;
  rec.SetBranchStatus("px",1);
  rec.SetBranchStatus("py",1);
  rec.SetBranchStatus("pz",1);
  rec.SetBranchStatus("vz",1);
  rec.SetBranchStatus("e",1);
  rec.SetBranchStatus("m",1);
  rec.SetBranchStatus("pdgId",1);
  rec.SetBranchStatus("status",1);
  rec.SetBranchStatus("barcode",1);
  rec.SetBranchAddress("px", &px_tru);
  rec.SetBranchAddress("py", &py_tru);
  rec.SetBranchAddress("pz", &pz_tru);
  rec.SetBranchAddress("vz", &vz_tru);
  rec.SetBranchAddress("e", &energy);
  //rec.SetBranchAddress("e", &charge);
  rec.SetBranchAddress("m", &mass);
  rec.SetBranchAddress("pdgId", &pdg);
  rec.SetBranchAddress("status", &status);
  rec.SetBranchAddress("barcode", &barcode);
  
  //! vector of reconstructed track-jet objects
  std::vector<TrackJetObj> trjVec;//define outside the loop and call clear inside OR define inside the loop and it will be destroyed at the end of the loop for each iteration similar to the class object
  double px, py, pz, pt, vz, E, m, eta, phi;	
  int pid, status_, barcode_, q;

  //! for every event do the following
  for(Long64_t i = 0; i < nevents; ++i)
  {
  	eventNo=i;
	TrackJetObj tjObj;
	//jetE_sm.clear();
	//jetPt_sm.clear();
	jetE.clear();
	//jetE_reso.clear();
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
	trjVec.clear();

	rec.GetEntry(i);
	
	//! total number of tracks reconstructed in an event
	int nobj = px_tru->size();
  	if(debug)std::cout<<"nobj: "<<nobj<<std::endl;
	if(nobj<1) continue;
	//! for all tracks in a pileup event
	for (int j = 0; j < nobj; ++j)
	{
		px	= (*px_tru)[j];
		py	= (*py_tru)[j];
		pz	= (*pz_tru)[j];
		vz	= (*vz_tru)[j];
		E	= (*energy)[j];
		m	= (*mass)[j];
		pid	= (*pdg)[j];
		status_ = (*status)[j];
		barcode_= (*barcode)[j];

		eta	= asinh(pz/std::sqrt(px*px + py*py));
		phi	= atan2(py,px);
		pt	= hypotf(px,py);

		if(std::fabs(eta) > 7) continue;
		tjObj.flag = 1;// stable particles
		if(std::abs(pid) == 5 && barcode_ > 50) 
		{
			tjObj.flag = 0;
			if(debug)
			{
				std::cout<<"b quarks" <<std::endl;
				std::cout<<"pt, eta, phi, pid, status: " << pt << " , " << eta << " , " << phi << " , " << pid << " , " << status_ << std::endl;
			
			}

		} // b quark
		else if(std::abs(pid) == 25 && barcode_ > 50) 
		{
			tjObj.flag = 2;
			if(debug)
			{
				std::cout<<"SM higgs" <<std::endl;
				std::cout<<"px, py, pz, eta, phi, pid, status: " << px << " , " << py << " , " << pz << " , " << eta << " , " << phi << " , " << pid << " , " << status_ << std::endl;
			
			}

		}	// SM higgs
		else if(status_ != 1) continue;
		
		//! charge right now unavailable at the generator level. 
		//! either use all particles for clustering or make a pt cut or around 1GeV on all particles	
		if(std::abs(pid) == 12 || std::abs(pid) == 14 || std::abs(pid) == 16 || std::abs(pid) == 18) q = -999;// neutrinos
		else if(std::abs(pid) < 10) q = -99;//quarks
		else if(pid == 22 || std::abs(pid) == 111 || std::abs(pid) == 2112 || std::abs(pid) == 3122 || std::abs(pid) == 310 || std::abs(pid) == 130 || std::abs(pid) == 3322) q = 0;// neutral particles
		else q = 1;
		//else if(std::abs(pid) == 2212 || std::abs(pid) == 211 || std::abs(pid) == 11 || std::abs(pid) == 13 || std::abs(pid) == 321 || std::abs(pid) == 3222 || std::abs (pid) == 3112 || std::abs(pid) == 3312 || std::abs(pid) == 3334) q = 1;//charged
		
		if(std::abs(q) < -100) continue; // neutrinos do not deposit any energy
		if(std::abs(q) != 0) //is chrarged
		{	
			//! get rid of charged particles that will not make it to the calorimeter
			if(std::fabs(pt) < 1e3) continue;
		       	
		}	


		if(debug && status_ != 1)
		{
			std::cout<<"px, py, pz, eta, phi, pid, status: " << px << " , " << py << " , " << pz << " , " << eta << " , " << phi << " , " << pid << " , " << status_ << std::endl;
		
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

	}// end of loop over nobj
	
	// choose a jet definition
	double R = 0.4;
	double PTMINJET = 5.0e3;
	JetDefinition jet_def(antikt_algorithm, R);
	std::vector<PseudoJet> input_trpcle;
	std::vector<PseudoJet> input_bquarks;
	std::vector<double> input_bquarks_etaVals;
	std::vector<PseudoJet> input_SMhiggs;


	// loop over all truth particles
	for(int k = 0; k < trjVec.size(); ++k )
	{
		//if(debug) std::cout<<"Create Pseudo jets \n";
		// an event with particles: px		py		pz   	E
		if(trjVec[k].flag == 0)
		{ 
			PseudoJet bquarks(trjVec[k].px, trjVec[k].py, trjVec[k].pz, trjVec[k].E);
			bquarks.set_user_info(new Constituent_info(trjVec[k].pdg, trjVec[k].Vz0, trjVec[k].zv));
			input_bquarks.push_back(bquarks);
		}

		else if(trjVec[k].flag == 2)
		{	
			PseudoJet SMhiggs(trjVec[k].px, trjVec[k].py, trjVec[k].pz, trjVec[k].E);
			SMhiggs.set_user_info(new Constituent_info(trjVec[k].pdg, trjVec[k].Vz0, trjVec[k].zv));
			input_SMhiggs.push_back(SMhiggs);
		}
		else 
		{
			PseudoJet trpcle(trjVec[k].px, trjVec[k].py, trjVec[k].pz, trjVec[k].E);
			trpcle.set_user_info(new Constituent_info(trjVec[k].pdg, trjVec[k].Vz0, trjVec[k].zv));
			input_trpcle.push_back(trpcle);
		}
		
	}// end of loop over all tracks trjVec
	
	if(debug)std::cout<<"Do jet Clustering \n";
	// run the jet clustering with the above definition, extract the jets
	ClusterSequence cs_trpcle(input_trpcle, jet_def);
	// sort the resulting jets in ascending order of pt
	// sorted_by_pt is a method of PseudoJet which returns a vector of jets sorted into decreasing pt
	std::vector<PseudoJet> incl_trpclejets = sorted_by_pt(cs_trpcle.inclusive_jets(PTMINJET));
	// sorted_by_rapidity is a method of PseudoJet which returns a vector of jets sorted into increasing eta
	std::vector<PseudoJet> incl_trpclejets_eta = sorted_by_rapidity(cs_trpcle.inclusive_jets(PTMINJET));
	//std::vector<PseudoJet> incl_bquarks_eta = sorted_by_rapidity(input_bquarks);
	input_bquarks_etaVals.clear();
	for(int ie = 0; ie < input_bquarks.size(); ie++)
	{
		input_bquarks_etaVals.push_back(std::fabs(input_bquarks[ie].eta()));
	}	
	std::vector<PseudoJet> incl_bquarks_eta = objects_sorted_by_values(input_bquarks, input_bquarks_etaVals);	
	// print out some infos
	if(debug)
	{
		std::cout << "Clustering with " << jet_def.description() << std::endl;
		std::cout <<   "        pt y phi" << std::endl;
	}
	Njets = incl_trpclejets.size();
	if(debug)
	{
		std::cout<<"Number of truth jets Njets : " <<Njets << std::endl;

	}

	//////////////// FIND THE BEST MATCHED BJET /////////////////
	double dR, thisDR;//, dphi, deta;
	int bestTruthJet;
	//! for each bquark sorted in eta (should be four per event)
	int n_bquarks = input_bquarks.size(); //Fill this in a histogram
	int NbJETS = 4;
	//! init vector to a high eta value
	std::vector<double>vectorof_bJetsEta(NbJETS,99.0);
	//vectorof_bJetsEta.clear();
	int n_SMhiggs = input_SMhiggs.size();
	for(unsigned ii = 0; ii < incl_bquarks_eta.size(); ii++)
        {
		dR = 99999.0;
		bestTruthJet = -1;
		for (unsigned jj = 0; jj < incl_trpclejets_eta.size(); jj++)
		{
			
			//dphi	= incl_trpclejets_eta[jj].phi() - incl_bquarks_eta[iii].phi();
			//deta	= incl_trpclejets_eta[jj].eta() - incl_bquarks_eta[ii].eta();
			//thisDR	= std::sqrt(deta*deta + dphi*dphi);
			thisDR = incl_trpclejets_eta[jj].delta_R(incl_bquarks_eta[ii]);
			if(thisDR < dR)
			{
				dR = thisDR;
				bestTruthJet = jj;
			}
		}
		if(debug) std::cout <<"dR: " <<dR <<std::endl;
		if(dR < 0.4)
		{
			//! store result, i.e. in vectorof_jetEta: keep only jets matched to b quarks 
			//! Notice that incl_bquarks_eta is sorted hence vectorof_jetEta[ii] will also be already sorted	
			//! at this stage vectorof_jetEta[nth_bquark] = 99 => initialised above
			//! simple push_back should also work here
			if(debug)
			{ 
			std::cout<<"\neta, phi, dR of b quarks " << incl_bquarks_eta[ii].eta() << ", " << incl_bquarks_eta[ii].phi() << ", " << dR <<std::endl;
			std::cout<<"eta, phi, dR of jets " << incl_trpclejets_eta[bestTruthJet].eta() << ", " << incl_trpclejets_eta[bestTruthJet].phi() << ", " << dR <<std::endl;
			}
			//vectorof_bJetsEta.push_back(incl_trpclejets_eta[bestTruthJet].eta());
			if(incl_trpclejets_eta[bestTruthJet].eta() < vectorof_bJetsEta[ii]) 
			{
				vectorof_bJetsEta[ii] = incl_trpclejets_eta[bestTruthJet].eta();
			}
			if(debug) std::cout<<"contents in vectorof_jetEta["<<ii<<"] = " <<vectorof_bJetsEta[ii] <<std::endl;
			//incl_trpclejets_eta.erase(incl_trpclejets_eta.begin() + bestTruthJet);
		}
	}// END OF LOOP OVER SORTED in ETA bquarks
	
	////////// FILL ETA HIST OF JETS MATCHED to b quarks ////////////////
	if(vectorof_bJetsEta.size() >= NbJETS)
	{
		r_sumpt.hbEta_NNNCEta->Fill(std::fabs(vectorof_bJetsEta[3]));	
		r_sumpt.hbEta_NNCEta->Fill(std::fabs(vectorof_bJetsEta[2]));	
		r_sumpt.hbEta_NCEta->Fill(std::fabs(vectorof_bJetsEta[1]));	
		r_sumpt.hbEta_CEta->Fill(std::fabs(vectorof_bJetsEta[0]));	
	}
	else if (vectorof_bJetsEta.size() >= NbJETS - 1)
	{
		r_sumpt.hbEta_NNCEta->Fill(std::fabs(vectorof_bJetsEta[2]));	
		r_sumpt.hbEta_NCEta->Fill(std::fabs(vectorof_bJetsEta[1]));	
		r_sumpt.hbEta_CEta->Fill(std::fabs(vectorof_bJetsEta[0]));	
	}
	else if (vectorof_bJetsEta.size() >= NbJETS - 2)
	{
		r_sumpt.hbEta_NCEta->Fill(std::fabs(vectorof_bJetsEta[1]));	
		r_sumpt.hbEta_CEta->Fill(std::fabs(vectorof_bJetsEta[0]));	
	}
	else if (vectorof_bJetsEta.size() >= NbJETS - 3)
	{
		r_sumpt.hbEta_CEta->Fill(std::fabs(vectorof_bJetsEta[0]));	
	}

	//! for each truth jet sorted in pt
	for (unsigned ii = 0; ii < incl_trpclejets.size(); ii++) 
	{
		//! smear jet energies
		float jetE_;
		jetE_ = incl_trpclejets[ii].E();
		//! push back all the truth jet parameters here for all "ii"
		jetE.push_back(jetE_);
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
		if(debug)std::cout<<"truth jet pt  size : " << jetPt.size() << std::endl;
		if(debug)
		{
			std::cout << "truth pcle jet " << ii << ": "<< incl_trpclejets[ii].pt() << " " << incl_trpclejets[ii].rap() << " " << incl_trpclejets[ii].phi() << std::endl;
		}
		
		std::vector<PseudoJet> constituents = incl_trpclejets[ii].constituents();
		int const_size = constituents.size();
		Nconstituents.push_back(const_size);
		for (unsigned j = 0; j < constituents.size(); j++) 
		{
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
		if(debug)
		{
			std::cout<<"jetPt : " << jetPt[ii]  << std::endl;
			std::cout<<"jetEta : " << jetEta[ii]  << std::endl;
		}
	}// end of for loop over jet size
	glob_jet->Fill();
	
	//! loop over jet pt thresholds
	for(int i2 = 0; i2 < trigger.nbins; i2++)
	{
		//! increment n5_tot if there are atleast 5 jets with pt > xbins[i]
		//! no z vertex bin
		if(debug)
		{
			std::cout<<"size jetPt_sm: " << jetPt_sm.size() <<std::endl;
			std::cout<<"size incl_trpclejets: " << incl_trpclejets.size() <<std::endl;
			std::cout<< "n5b_tot[ " << i2 << "] : " <<trigger.n5b_tot[i2] << ",   " <<  "n4b_tot[ " << i2 << "] : " <<trigger.n4b_tot[i2] << ",   " << "n3b_tot[ " << i2 << "] : " <<trigger.n3b_tot[i2] << ",   " << "n2b_tot[ " << i2 << "] : " <<trigger.n2b_tot[i2] <<std::endl;	
			
		}

		trigger.n5_tot[i2] = 1;
		trigger.n4_tot[i2] = 1;
		trigger.n3_tot[i2] = 1;
		trigger.n2_tot[i2] = 1;
		trigger.n5a_tot[i2] = 1;
		trigger.n4a_tot[i2] = 1;
		trigger.n3a_tot[i2] = 1;
		trigger.n2a_tot[i2] = 1;

	/*	if(jetPt_sm.size() >= trigger.Njet_max)
		{
			if(jetPt_sm[4]*1e-3 > trigger.xbins[i2]) trigger.n5b_tot[i2] += 1;
			if(jetPt_sm[3]*1e-3 > trigger.xbins[i2]) trigger.n4b_tot[i2] += 1;
			if(jetPt_sm[2]*1e-3 > trigger.xbins[i2]) trigger.n3b_tot[i2] += 1;
			if(jetPt_sm[1]*1e-3 > trigger.xbins[i2]) trigger.n2b_tot[i2] += 1;
		}
		//! increment n4_tot if there are atleast 4 jets with pt > xbins[i]
		else if (jetPt_sm.size() >= trigger.Njet_max-1)
		{
			if(jetPt_sm[3]*1e-3 > trigger.xbins[i2]) trigger.n4b_tot[i2] += 1;
			if(jetPt_sm[2]*1e-3 > trigger.xbins[i2]) trigger.n3b_tot[i2] += 1;
			if(jetPt_sm[1]*1e-3 > trigger.xbins[i2]) trigger.n2b_tot[i2] += 1;
			
		}
		//! increment n3_tot if there are atleast 3 jets with pt > xbins[i]
		else if (jetPt_sm.size() >= trigger.Njet_max-2)
		{
			if(jetPt_sm[2]*1e-3 > trigger.xbins[i2]) trigger.n3b_tot[i2] += 1;
			if(jetPt_sm[1]*1e-3 > trigger.xbins[i2]) trigger.n2b_tot[i2] += 1;
			
		}
		//! increment n2_tot if there are atleast 2 jets with pt > xbins[i]
		else if (jetPt_sm.size() >= trigger.Njet_max-3)
		{
			if(jetPt_sm[1]*1e-3 > trigger.xbins[i2]) trigger.n2b_tot[i2] += 1;
			
		}
	*/	/*if(incl_CaloEmuJets.size() >= trigger.Njet_max)
		{
			if(incl_CaloEmuJets[4].pt()*1e-3 > trigger.xbins[i2]) trigger.n5b_tot[i2] += 1;
			if(incl_CaloEmuJets[3].pt()*1e-3 > trigger.xbins[i2]) trigger.n4b_tot[i2] += 1;
			if(incl_CaloEmuJets[2].pt()*1e-3 > trigger.xbins[i2]) trigger.n3b_tot[i2] += 1;
			if(incl_CaloEmuJets[1].pt()*1e-3 > trigger.xbins[i2]) trigger.n2b_tot[i2] += 1;
		}
		//! increment n4_tot if there are atleast 4 jets with pt > xbins[i]
		else if (incl_CaloEmuJets.size() >= trigger.Njet_max-1)
		{
			if(incl_CaloEmuJets[3].pt()*1e-3 > trigger.xbins[i2]) trigger.n4b_tot[i2] += 1;
			if(incl_CaloEmuJets[2].pt()*1e-3 > trigger.xbins[i2]) trigger.n3b_tot[i2] += 1;
			if(incl_CaloEmuJets[1].pt()*1e-3 > trigger.xbins[i2]) trigger.n2b_tot[i2] += 1;
			
		}
		//! increment n3_tot if there are atleast 3 jets with pt > xbins[i]
		else if (incl_CaloEmuJets.size() >= trigger.Njet_max-2)
		{
			if(incl_CaloEmuJets[2].pt()*1e-3 > trigger.xbins[i2]) trigger.n3b_tot[i2] += 1;
			if(incl_CaloEmuJets[1].pt()*1e-3 > trigger.xbins[i2]) trigger.n2b_tot[i2] += 1;
			
		}
		//! increment n2_tot if there are atleast 2 jets with pt > xbins[i]
		else if (incl_CaloEmuJets.size() >= trigger.Njet_max-3)
		{
			if(incl_CaloEmuJets[1].pt()*1e-3 > trigger.xbins[i2]) trigger.n2b_tot[i2] += 1;
			
		}*/
	}//! end of loop over pt thresholds
	
	////// Fill eta histograms of n leading pt jets /////
	//if (incl_trpclejets.size() >= trigger.Njet_max) std::cout<<"leading pt jet eta: " << incl_CaloEmuJets[4].eta() <<std::endl;
	if(incl_trpclejets.size() >= trigger.Njet_max)
	{
		r_sumpt.hbEta_PUNNNNLpt->Fill(std::fabs(incl_trpclejets[4].eta()));	
		r_sumpt.hbEta_PUNNNLpt->Fill(std::fabs(incl_trpclejets[3].eta()));	
		r_sumpt.hbEta_PUNNLpt->Fill(std::fabs(incl_trpclejets[2].eta()));	
		r_sumpt.hbEta_PUNLpt->Fill(std::fabs(incl_trpclejets[1].eta()));	
		r_sumpt.hbEta_PULpt->Fill(std::fabs(incl_trpclejets[0].eta()));	
	}
	else if (incl_trpclejets.size() >= trigger.Njet_max-1)
	{
		r_sumpt.hbEta_PUNNNLpt->Fill(std::fabs(incl_trpclejets[3].eta()));	
		r_sumpt.hbEta_PUNNLpt->Fill(std::fabs(incl_trpclejets[2].eta()));	
		r_sumpt.hbEta_PUNLpt->Fill(std::fabs(incl_trpclejets[1].eta()));	
		r_sumpt.hbEta_PULpt->Fill(std::fabs(incl_trpclejets[0].eta()));	
	}
	else if (incl_trpclejets.size() >= trigger.Njet_max-2)
	{
		r_sumpt.hbEta_PUNNLpt->Fill(std::fabs(incl_trpclejets[2].eta()));	
		r_sumpt.hbEta_PUNLpt->Fill(std::fabs(incl_trpclejets[1].eta()));	
		r_sumpt.hbEta_PULpt->Fill(std::fabs(incl_trpclejets[0].eta()));	
	}
	else if (incl_trpclejets.size() >= trigger.Njet_max-3)
	{
		r_sumpt.hbEta_PUNLpt->Fill(std::fabs(incl_trpclejets[1].eta()));	
		r_sumpt.hbEta_PULpt->Fill(std::fabs(incl_trpclejets[0].eta()));	
	}
	else if (incl_trpclejets.size() >= trigger.Njet_max-4)
	{
		r_sumpt.hbEta_PULpt->Fill(std::fabs(incl_trpclejets[0].eta()));	
	}

 }// for loop over nentries
  std::cout <<"total number of events used " <<r_sumpt.nevents <<std::endl;
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
//r_sumpt.Fill_TrigRate_EMU(r_sumpt.n_tots);
//r_sumpt.SetHist_props();
////! continuation of trigger efficiency cal.
////! we fill outside as we want count the no. of events with 'n' trackjets above a pt threshold
//trigger.init(trigger.xbins, trigger.nbins);
//trigger.SetHist_props();
//trigger.Fill_TrigEff();
//TCanvas *C_trig = new TCanvas();
//trigger.DrawNoBin();
//C_trig->Write();
//trigger.WriteAll();
//TCanvas *c1 = new TCanvas();
//r_sumpt.DrawNoBin();
//c1->SetLogy();
//c1->Update();
//r_sumpt.WriteAll();
//c1->Write();
////! Write to output file
//glob_jet->Write();
r_sumpt.SetEtaHist_props();
r_sumpt.WriteEta1();

f_out->Close();
return 0;
}
