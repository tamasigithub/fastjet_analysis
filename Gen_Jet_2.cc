#include "fastjet/ClusterSequence.hh"
#include "Constituent_info.h"
#include "TrackJetObj.h"
#include "Gen_output_2.h"
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
using namespace fastjet;


int main() 
{
  
  TRandom3 *myRNG = new TRandom3();
  gRandom = myRNG;

  //bool debug = true;
  bool debug = false;
 
//**************** Constants *********************//
  const double ChargedPcle_PtThreshold 	= 300;//MeV
  const double SCALEfac_Ereso 		= 0.5; //50%
  const double TrackerAcceptance 	= 6.0;

  const double R 			= 0.4;
  const double PTMINJET 		= 20.0e3;//MeV
  int MAX_NLEADINGJETS 			= 99;// number of jets to be b-tagged-> 99 for all

  //! b-tag info
  const double MinQuarkPt = 15e3;//MeV
  const double fb = 0.8, fc= 0.1, fl = 0.01;
//************************************************//
  
//****************object and file creation and  reading of input files***************//
  //! bin range for eta and pt
  const float PT_MIN = 0., PT_MAX = 500., PTCUT_WIDTH = 5.0;// in GeV/c

  //! create an object to plot rate as a function of pt
  Gen_output genOut(PT_MIN, PT_MAX, PTCUT_WIDTH);
  genOut.init_PtHist(genOut.xbins, genOut.nbins);
  genOut.init_EtaHist();
  genOut.init_MultiplicityHist();

  gInterpreter->GenerateDictionary("vector<vector<double>>","vector");
  gInterpreter->GenerateDictionary("vector<vector<int>>","vector");

  //! store results in an output root file 
  //TFile *f_out = new TFile("./fastjet_output/test_all_b.root","RECREATE");
  TFile *f_out = new TFile("./fastjet_output/Genjet2_pp4b_q300MeV_6.0_allR0.4_0.8btag_1.root","RECREATE");
  //TFile *f_out = new TFile("./fastjet_output/Genjet2_ggF_Ctr-2.0_q300MeV_2.5_allR0.4_0.8btag.root","RECREATE");
  TH1::SetDefaultSumw2(true);
  genOut.init_TTree();
  genOut.Branch_OutTree();
 
  //! open input trees 
  TChain rec("CollectionTree");
  //rec.Add("/media/tamasi/Z/PhD/FCC/Castellated/data_files/user.tkar.pp_4bQCD_pythia82_GenCuts.v3_output.root/*.root");
  //rec.Add("/media/tamasi/Z/PhD/FCC/Castellated/data_files/user.tkar.pp_ggF_Ctr-2.0hh_pythia82_GenCuts.v3_output.root/*.root");
  
  //rec.Add("/home/tamasi/repo_tamasi/grid_files/user.tkar.pp_ggF_Ctr-2.0hh_pythia82_nopileup.v5_output.root/*.root");
  //rec.Add("/home/tamasi/repo_tamasi/grid_files/user.tkar.pp_4bQCD_pythia82_nopileup.v5_output.root/*.root");
  rec.Add("/home/tamasi/repo_tamasi/grid_files/user.tkar.pp_4bQCD_pythia82_GenCuts.v5_output.root/*.root");

  std::cout<<"Input files used from user.tkar.pp_ggF_Ctr-2.0hh_pythia82_nopileup.v5_output.root"<<std::endl;

  std::cout<<"output file name Genjet2_ggF_Ctr-2.0_q300MeV_2.5_allR0.4_0.8btag.root"<<std::endl;

  //! Get total no. of events
  //Long64_t nevents = 500000;
  Long64_t nevents = rec.GetEntries();
  genOut.nevents = nevents;
  std::cout<<"number of Pile-up events : " << nevents <<std::endl; 
  
  //! define a local vector<double> to store the input values
  std::vector<float> *px_tru = 0;
  std::vector<float> *py_tru = 0;
  std::vector<float> *pz_tru = 0;
  std::vector<float> *vz_tru = 0;
  std::vector<float> *energy = 0;
  std::vector<float> *charge = 0;
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
  rec.SetBranchStatus("charge",1);
  rec.SetBranchAddress("px", &px_tru);
  rec.SetBranchAddress("py", &py_tru);
  rec.SetBranchAddress("pz", &pz_tru);
  rec.SetBranchAddress("vz", &vz_tru);
  rec.SetBranchAddress("e", &energy);
  rec.SetBranchAddress("charge", &charge);
  rec.SetBranchAddress("m", &mass);
  rec.SetBranchAddress("pdgId", &pdg);
  rec.SetBranchAddress("status", &status);
  rec.SetBranchAddress("barcode", &barcode);
  
  //! vector of reconstructed track-jet objects
  //define outside the loop and call clear inside OR 
  //define inside the loop and it will be destroyed 
  //at the end of the loop for each iteration similar to the class object
  std::vector<TrackJetObj> trjVec;
  double px, py, pz, pt, vz, E, m, eta, phi;	
  int pid, status_, barcode_, q;
//*****************************************************************************************//

//****************************** Begining of Event Loop ***********************************//

  //! for every event do the following
  for(int i = 0; i < nevents; ++i)
  {
  	genOut.Clear_OutVars();
	genOut.eventNo = i;
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

		if(std::fabs(eta) > TrackerAcceptance) continue;
		tjObj.flag = 1;// stable particles
		
		//**** Identify light quarks, chram, bottom and Higgs *****//
		if(std::abs(pid) == 5 && status_ == 23 ) 
		{
			tjObj.flag = 5;

		}// b quark
		else if(std::abs(pid) == 25 && status_ == 62) 
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
		else if(status_ != 1) continue;
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

	}// end of loop over nobj(all tracks/particles in an event)
	
	//! choose a jet definition
	JetDefinition jet_def(antikt_algorithm, R);
	//! all stable particles in this event
	std::vector<PseudoJet> input_trpcle;
	//! all b quarks in this event
	std::vector<PseudoJet> input_bquarks;
	std::vector<double> input_bquarks_etaVals;
	//! all charm quarks in this event
	std::vector<PseudoJet> input_cquarks;
	//! all light quarks in this event
	std::vector<PseudoJet> input_lightquarks;
	//! all higgs in this event
	std::vector<PseudoJet> input_SMhiggs;


	//! loop over all truth particles
	for(int k = 0; k < trjVec.size(); ++k )
	{
		if(debug) std::cout<<"Create Pseudo jets \n";
		if(trjVec[k].flag == 5)
		{ 
			if(debug) std::cout<<"Create b quarks Pseudo jets \n";
			PseudoJet bquarks(trjVec[k].px, trjVec[k].py, trjVec[k].pz, trjVec[k].E);
			bquarks.set_user_info(new Constituent_info(trjVec[k].pdg, trjVec[k].Vz0, trjVec[k].zv));
			input_bquarks.push_back(bquarks);
		}
		else if(trjVec[k].flag == 4)
		{ 
			if(debug) std::cout<<"Create charm quarks Pseudo jets \n";
			PseudoJet cquarks(trjVec[k].px, trjVec[k].py, trjVec[k].pz, trjVec[k].E);
			cquarks.set_user_info(new Constituent_info(trjVec[k].pdg, trjVec[k].Vz0, trjVec[k].zv));
			input_cquarks.push_back(cquarks);
		}
		else if(trjVec[k].flag == 3)
		{ 
			if(debug) std::cout<<"Create light quarks Pseudo jets \n";
			PseudoJet lightquarks(trjVec[k].px, trjVec[k].py, trjVec[k].pz, trjVec[k].E);
			lightquarks.set_user_info(new Constituent_info(trjVec[k].pdg, trjVec[k].Vz0, trjVec[k].zv));
			input_lightquarks.push_back(lightquarks);
		}
		else if(trjVec[k].flag == 25)
		{	
			if(debug) std::cout<<"Create higgs Pseudo jets \n";
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


		
	//********************************* b quarks **************************************//
	//! push the |eta values| of the b quarks into a vector 
	//! to sort input_bquarks(a PseudoJet) by increasing value of |eta|
	input_bquarks_etaVals.clear();
	std::vector<PseudoJet> incl_bquarks_eta;
	std::vector<PseudoJet> incl_bquarks_pt;	
	int n_bquarks = input_bquarks.size();
	if(input_bquarks.size()!=0)
	{
		for(int ie = 0; ie < input_bquarks.size(); ie++)
		{
			input_bquarks_etaVals.push_back(std::fabs(input_bquarks[ie].eta()));
		}	
		incl_bquarks_eta = objects_sorted_by_values(input_bquarks, input_bquarks_etaVals);
		incl_bquarks_pt = sorted_by_pt(input_bquarks);
		
		//! Pt Eta Phi M of bquarks
		for(int ie = 0; ie < incl_bquarks_pt.size(); ie++)
		{
			genOut.v_bPt.push_back(incl_bquarks_pt[ie].pt());
			genOut.v_bEta.push_back(incl_bquarks_pt[ie].eta());
			genOut.v_bPhi.push_back(incl_bquarks_pt[ie].phi());
			genOut.v_bM.push_back(incl_bquarks_pt[ie].m());
		}
		
		if(incl_bquarks_pt.size() < 2)
		{
			genOut.bLPt.push_back(incl_bquarks_pt[0].pt());
			genOut.bNLPt.push_back(0);
			genOut.bNNLPt.push_back(0);
			genOut.bNNNLPt.push_back(0);
		}
		else if(incl_bquarks_pt.size() < 3)
		{
			genOut.bLPt.push_back(incl_bquarks_pt[0].pt());
			genOut.bNLPt.push_back(incl_bquarks_pt[1].pt());
			genOut.bNNLPt.push_back(0);
			genOut.bNNNLPt.push_back(0);
		}
		else if(incl_bquarks_pt.size() < 4)
		{
			genOut.bLPt.push_back(incl_bquarks_pt[0].pt());
			genOut.bNLPt.push_back(incl_bquarks_pt[1].pt());
			genOut.bNNLPt.push_back(incl_bquarks_pt[2].pt());
			genOut.bNNNLPt.push_back(0);
		}
		else
		{
			genOut.bLPt.push_back(incl_bquarks_pt[0].pt());
			genOut.bNLPt.push_back(incl_bquarks_pt[1].pt());
			genOut.bNNLPt.push_back(incl_bquarks_pt[2].pt());
			genOut.bNNNLPt.push_back(incl_bquarks_pt[3].pt());
		}
		//! Fill eta hist of b quarks sorted in eta
		genOut.FillEta_bquarks_eta(incl_bquarks_eta, genOut.NbJETS);
		//! Fill eta hist of b quarks sorted in pt
		genOut.FillEta_bquarks_pt(incl_bquarks_pt, genOut.NbJETS);
		//! Fill pt hist of b quarks sorted in eta
		genOut.FillPt_bquarks_eta(incl_bquarks_eta, genOut.NbJETS);
		//! Fill pt hist of b quarks sorted in pt
		genOut.FillPt_bquarks_pt(incl_bquarks_pt, genOut.NbJETS);

		if(incl_bquarks_pt.size() < 3)
		{
			genOut.dRb12 = incl_bquarks_pt[0].delta_R(incl_bquarks_pt[1]);
		}
		if(incl_bquarks_pt.size() < 4)
		{
			genOut.dRb13 = incl_bquarks_pt[0].delta_R(incl_bquarks_pt[2]);
			genOut.dRb23 = incl_bquarks_pt[1].delta_R(incl_bquarks_pt[2]);
		}
		if(incl_bquarks_pt.size() >3 )
		{
			genOut.dRb14 = incl_bquarks_pt[0].delta_R(incl_bquarks_pt[3]);
			genOut.dRb24 = incl_bquarks_pt[1].delta_R(incl_bquarks_pt[3]);
			genOut.dRb34 = incl_bquarks_pt[2].delta_R(incl_bquarks_pt[3]);
		}
	}
	//************************************************************************//
	
	//******************************* SM higgs *******************************//
	int n_SMhiggs = input_SMhiggs.size();
	if(n_SMhiggs > 1)
	{
		//! Pt sorted PseudoJet of SM higgs
		std::vector<PseudoJet> incl_SMhiggs_pt = sorted_by_pt(input_SMhiggs);		
		for (int h = 0; h < n_SMhiggs; h++)
		{
			genOut.v_higgsPt.push_back(incl_SMhiggs_pt[h].pt());
			genOut.v_higgsEta.push_back(incl_SMhiggs_pt[h].eta());
			genOut.v_higgsPhi.push_back(incl_SMhiggs_pt[h].phi());
			genOut.v_higgsM.push_back(incl_SMhiggs_pt[h].m());
		}
		genOut.higgsLPt.push_back(incl_SMhiggs_pt[0].pt());
		genOut.higgsNLPt.push_back(incl_SMhiggs_pt[1].pt());

		//! Eta sorted higgs
		if (std::fabs(incl_SMhiggs_pt[0].eta()) < std::fabs(incl_SMhiggs_pt[1].eta()))
		{
			genOut.higgsCEta.push_back(incl_SMhiggs_pt[0].eta());
			genOut.higgsNCEta.push_back(incl_SMhiggs_pt[1].eta());
		
		}
		else
		{
			genOut.higgsCEta.push_back(incl_SMhiggs_pt[1].eta());
			genOut.higgsNCEta.push_back(incl_SMhiggs_pt[0].eta());
		
		}

		//! delta R between the two higgs
		genOut.dRhiggs = incl_SMhiggs_pt[0].delta_R(incl_SMhiggs_pt[1]);
	}
	//*********************************************************************//

	
	//**************************** All jets *******************************//
	if(debug)std::cout<<"Do jet Clustering \n";
	//! run the jet clustering with the above definition, extract the jets
	ClusterSequence cs_trpcle(input_trpcle, jet_def);
	
	//! sort the resulting jets in descending order of pt
	//! sorted_by_pt is a method of PseudoJet which returns a vector of jets sorted into decreasing pt
	//! sorted_by_rapidity is a method of PseudoJet which returns a vector of jets sorted into increasing eta
	std::vector<PseudoJet> incl_trpclejets = sorted_by_pt(cs_trpcle.inclusive_jets(PTMINJET));
	std::vector<PseudoJet> incl_trpclejets_eta = sorted_by_rapidity(cs_trpcle.inclusive_jets(PTMINJET));
	genOut.Njets = incl_trpclejets.size();
	genOut.Ncquarks = input_cquarks.size();
	genOut.Nlightquarks = input_lightquarks.size();
	genOut.v_JetMultiplicity.resize(genOut.Njet_max,0);

	int Max_NLeadingJets;	
	//!Store only leading 4 or 5 or all(use 99 for all) jets
	if (MAX_NLEADINGJETS == 99) Max_NLeadingJets = genOut.Njets;
	else if (MAX_NLEADINGJETS == 5) Max_NLeadingJets = 5;
	else if (MAX_NLEADINGJETS == 4) Max_NLeadingJets = 4;
	//std::cout<<"number of Jets in event " << i << ": "<<incl_trpclejets.size() <<std::endl;
	//std::cout<<"number of NJets: "<<genOut.Njets <<std::endl;
	//std::cout<<"default Max_NLeadingJets: " <<Max_NLeadingJets <<std::endl;
	if (genOut.Njets < Max_NLeadingJets) 
	{
		if(genOut.Njets == 4) Max_NLeadingJets = 4;
		else continue;
	}

	if(debug)
	{
		std::cout << "Clustering with " << jet_def.description() << std::endl;
		std::cout<<"Number of truth jets Njets : " <<genOut.Njets << std::endl;
	}

	double dR, thisDR;
	int bestTruthJet;
	//! for each truth jet sorted in pt
	//std::cout<<"final Max_NLeadingJets: " <<Max_NLeadingJets <<std::endl;
	//std::cout<<std::endl;
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
	
			
		//! push back all the truth jet parameters here for all "ii"
		genOut.jetE_sm.push_back(jetE_smeared);
		genOut.jetE_reso.push_back(jetE_reso_);
		
		genOut.jetE.push_back(incl_trpclejets[ii].e());
		genOut.jetPt.push_back(incl_trpclejets[ii].pt());
                genOut.jetM.push_back(incl_trpclejets[ii].m());
		genOut.jetPhi.push_back(incl_trpclejets[ii].phi());
		genOut.jetTheta.push_back(incl_trpclejets[ii].theta());
                genOut.jetEta.push_back(incl_trpclejets[ii].eta());
		genOut.hasConstituents.push_back(incl_trpclejets[ii].has_constituents());
		genOut.constituentPt.push_back(std::vector<double>());
		genOut.constituentPhi.push_back(std::vector<double>());
		genOut.constituentTheta.push_back(std::vector<double>());
		genOut.constituentEta.push_back(std::vector<double>());
		genOut.constituentEt.push_back(std::vector<double>());
		genOut.constituentMt.push_back(std::vector<double>());
		genOut.constituentPdg.push_back(std::vector<int>());
		genOut.constituentZ0.push_back(std::vector<double>());
		if(debug)
		{
			std::cout<<"truth jet pt  size : " << genOut.jetPt.size() << std::endl;
			std::cout << "truth pcle jet " << ii << ": "<< incl_trpclejets[ii].pt() << " " << incl_trpclejets[ii].rap() << " " << incl_trpclejets[ii].phi() << std::endl;
		}
		
		std::vector<PseudoJet> constituents = incl_trpclejets[ii].constituents();
		int const_size = constituents.size();
		genOut.Nconstituents.push_back(const_size);
		if(ii < genOut.Njet_max + 1)
		{
			genOut.v_JetMultiplicity[ii] = const_size;
		}
		for (unsigned j = 0; j < constituents.size(); j++) 
		{
			genOut.constituentPt[ii].push_back(constituents[j].pt());
			genOut.constituentPhi[ii].push_back(constituents[j].phi());
			genOut.constituentTheta[ii].push_back(constituents[j].theta());
			genOut.constituentEta[ii].push_back(constituents[j].eta());
			genOut.constituentEt[ii].push_back(constituents[j].Et());
			genOut.constituentMt[ii].push_back(constituents[j].m());
			genOut.constituentPdg[ii].push_back(constituents[j].user_info<Constituent_info>().pdg_id());
			genOut.constituentZ0[ii].push_back(constituents[j].user_info<Constituent_info>().Z0());
		}// end of loop over constituents		
		if(debug)
		{
			std::cout<<"jetPt : " << genOut.jetPt[ii]  << std::endl;
			std::cout<<"jetEta : " << genOut.jetEta[ii]  << std::endl;
		}
	
		//************************* tag Jets with the following probabilities: ********************//
		//if matched to a b quark with pt > 15GeV/c, tag the jet as b-tagged with probability 0.8
		//if matched to a c quark with pt > 15GeV/c, tag the jet as b-tagged with probability 0.1
		//if matched to a light quark with pt > 15GeV/c, tag the jet as b-tagged with probability 0.01
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
		//! b-mistag of charm-jets
		if(btagged_flavor == 0 && genOut.Ncquarks != 0)
		{
			for(unsigned jj = 0; jj < genOut.Ncquarks; ++jj)
			{
				if(input_cquarks[jj].pt() < MinQuarkPt) continue;
				thisDR = incl_trpclejets[ii].delta_R(input_cquarks[jj]);
				if(thisDR < dR)
				{
					dR = thisDR;
					bestTruthJet = jj;

				}
			}
			if(dR < R) 
			{
				matchFound = gRandom->Uniform(0,1);
				if(matchFound <= fc) btagged_flavor = 4;
			}
		}
		//! b-mistag of light-jets
		if(btagged_flavor == 0 && genOut.Nlightquarks != 0)
		{
			for(unsigned jj = 0; jj < genOut.Nlightquarks; ++jj)
			{
				if(input_lightquarks[jj].pt() < MinQuarkPt) continue;
				thisDR = incl_trpclejets[ii].delta_R(input_lightquarks[jj]);
				if(thisDR < dR)
				{
					dR = thisDR;
					bestTruthJet = jj;

				}
			}
			if(dR < R)
			{
				matchFound = gRandom->Uniform(0,1);
				if(matchFound <= fl) btagged_flavor = 3;
			}
		}
		genOut.btaggedFlavor.push_back(btagged_flavor);
		genOut.btagProb.push_back(matchFound);


	}// end of for loop over jet size
	//! Fill eta histograms of n leading pt jets 
	genOut.FillPt_Jets_pt(incl_trpclejets, genOut.Njet_max);
	//! calculate the number of b-tags per event
	int Nbtags_ = 0;
	for(int ii = 0; ii < genOut.btaggedFlavor.size(); ii++)
	{
		if(genOut.btaggedFlavor[ii] == 0) continue;
		else Nbtags_++;
	}
	genOut.Nbtags = Nbtags_;
	//*******************************************************************//

	//********************** FIND THE BEST MATCHED BJET ****************//
	//! for each bquark sorted in eta (should be four per event)
	genOut.Nbquarks = n_bquarks;
	genOut.NSMhiggs = n_SMhiggs;
	genOut.vectorof_bJetsEta.resize(genOut.NbJETS,99.0);
	for(unsigned ii = 0; ii < incl_bquarks_eta.size(); ii++)
        {
		dR = 99999.0;
		bestTruthJet = -1;
		for (unsigned jj = 0; jj < incl_trpclejets_eta.size(); jj++)
		{
			
			thisDR = incl_trpclejets_eta[jj].delta_R(incl_bquarks_eta[ii]);
			if(thisDR < dR)
			{
				dR = thisDR;
				bestTruthJet = jj;
			}
		}
		if(debug) std::cout <<"dR: " <<dR <<std::endl;
		if(dR < R)
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
			//genOut.vectorof_bJetsEta.push_back(incl_trpclejets_eta[bestTruthJet].eta());
			if(incl_trpclejets_eta[bestTruthJet].eta() < genOut.vectorof_bJetsEta[ii]) 
			{
				genOut.vectorof_bJetsEta[ii] = incl_trpclejets_eta[bestTruthJet].eta();
			}
			if(debug) std::cout<<"contents in vectorof_jetEta["<<ii<<"] = " <<genOut.vectorof_bJetsEta[ii] <<std::endl;
			//incl_trpclejets_eta.erase(incl_trpclejets_eta.begin() + bestTruthJet);
		}
	}// END OF LOOP OVER SORTED in ETA bquarks
	
	//! FILL ETA HIST OF JETS MATCHED to b quarks 
	genOut.Fill_bJetEta();

	//! for each bquark sorted in pt (should be four per event)
	//genOut.vectorof_bJetsPt.resize(genOut.NbJETS,0.0);
	//genOut.v_bJetMultiplicity.resize(genOut.NbJETS,0);
	//! create a flag for jets tagged as b or not for every event and fill it in the TTree
	//genOut.btaggedJets.resize(incl_trpclejets.size(), false);
	genOut.b1tagJets_dR.resize(incl_trpclejets.size(), 99.0);
	genOut.b2tagJets_dR.resize(incl_trpclejets.size(), 99.0);
	genOut.b3tagJets_dR.resize(incl_trpclejets.size(), 99.0);
	genOut.b4tagJets_dR.resize(incl_trpclejets.size(), 99.0);
	genOut.btagJets_dR.resize(incl_trpclejets.size(), 99.0);

	for(unsigned ii = 0; ii < incl_bquarks_pt.size(); ii++)
        {
		dR = 99999.0;
		bestTruthJet = -1;
		if(incl_bquarks_pt[ii].pt() < 15e3) continue;
		for (unsigned jj = 0; jj < incl_trpclejets.size(); jj++)
		{
			thisDR = incl_trpclejets[jj].delta_R(incl_bquarks_pt[ii]);
			if(ii == 0) genOut.b1tagJets_dR[jj] = thisDR;
			else if(ii == 1) genOut.b2tagJets_dR[jj] = thisDR;
			else if(ii == 2) genOut.b3tagJets_dR[jj] = thisDR;
			else if(ii == 3) genOut.b4tagJets_dR[jj] = thisDR;
			//if(abs(incl_trpclejets[jj].pt() - incl_bquarks_pt[ii].pt()) > 10e3) continue;
			if(thisDR < dR)
			{
				dR = thisDR;
				bestTruthJet = jj;
			}
		}
		if(debug) std::cout <<"dR: " <<dR <<std::endl;
		if(dR < R)
		{
			//! store result, i.e. in vectorof_bJetsPt: keep only jets matched to b quarks 
			//! Notice that incl_bquarks_pt is sorted hence vectorof_bJetsPt[ii] will also be already sorted	
			//! at this stage vectorof_bJetsPt[nth_bquark] = 0 => initialised above
			//! simple push_back should also work here
			genOut.vectorof_bJetsPt.push_back(incl_trpclejets[bestTruthJet].pt());
			genOut.v_bJetMultiplicity.push_back(incl_trpclejets[bestTruthJet].constituents().size());
			//genOut.btaggedJets[bestTruthJet] = true;
			genOut.btagJets_dR[bestTruthJet] = dR;
		}
	}// END OF LOOP OVER SORTED in Pt bquarks


	//! FILL Pt HIST OF JETS MATCHED to b quarks 
	genOut.Fill_bJetPt();
	//! FILL MULTIPLICITY HIST OF JETS MATCHED to b quarks 
	genOut.Fill_bJetMultiplicity();
	//*******************************************************************************//
	
	genOut.glob_jet->Fill();

	//! FILL MULTIPLICITY HIST OF JETS MATCHED to b quarks 
	genOut.Fill_JetMultiplicity();
	

 }// for loop over nentries
std::cout <<"total number of events used " <<genOut.nevents <<std::endl;

genOut.SetEtaHist_props();
genOut.WriteEta();
genOut.SetPtHist_props();
genOut.WritePt();
genOut.SetMultiplicityHist_props();
genOut.WriteMultiplicity();
genOut.glob_jet->Write();
f_out->Close();
delete px_tru;
delete py_tru;
delete pz_tru;
delete vz_tru;
delete energy;
delete charge;
delete mass;
delete pdg;
delete status;
delete barcode;

return 0;
}
