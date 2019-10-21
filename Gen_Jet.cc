#include "fastjet/ClusterSequence.hh"
#include "Constituent_info.h"
#include "TrackJetObj.h"
//#include "CaloEmu.h"
#include "Gen_output.h"
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

int Particle_Type(int pdgId)
{

	int q = 0;
	if(std::abs(pdgId) == 12 || std::abs(pdgId) == 14 || std::abs(pdgId) == 16 || std::abs(pdgId) == 18) q = -999;// neutrinos
	else if(std::abs(pdgId) < 10) q = -99;//quarks
	else if(pdgId == 22 || std::abs(pdgId) == 111 || std::abs(pdgId) == 2112 || std::abs(pdgId) == 3122 || std::abs(pdgId) == 310 || std::abs(pdgId) == 130 || std::abs(pdgId) == 3322) q = 0;// neutral particles
	else q = 1;
	//else if(std::abs(pdgId) == 2212 || std::abs(pdgId) == 211 || std::abs(pdgId) == 11 || std::abs(pdgId) == 13 || std::abs(pdgId) == 321 || std::abs(pdgId) == 3222 || std::abs (pdgId) == 3112 || std::abs(pdgId) == 3312 || std::abs(pdgId) == 3334) q = 1;//charged

	return q;
}

int main() 
{
  //bool debug = true;
  bool debug = false;
  
  /////////////////////////////
  //! bin range for eta and pt
  /////////////////////////////
  const float PT_MIN = 0., PT_MAX = 500., PTCUT_WIDTH = 5.0;// in GeV/c
  //! create an object to plot rate as a function of pt
  Gen_output genOut(PT_MIN, PT_MAX, PTCUT_WIDTH);
  genOut.init_PtHist(genOut.xbins, genOut.nbins);
  genOut.init_EtaHist();
  genOut.init_MultiplicityHist();

  /////////////////////////////////////////
  //! store results in an output root file 
  /////////////////////////////////////////
  //! branch variables
  gInterpreter->GenerateDictionary("vector<vector<double>>","vector");
  gInterpreter->GenerateDictionary("vector<vector<int>>","vector");

  //! output root file
  //TFile *f_out = new TFile("Genjet_PU0hh4b_m260_q1.2GeV_1.root","RECREATE");
  //TFile *f_out = new TFile("GenjetCharged_PU0hh4b_m1000_q1.2GeV_1.root","RECREATE");
  TFile *f_out = new TFile("./fastjet_output/Genjet_ggF_Ctr-2.0_q1.2GeV_1.root","RECREATE");
  TH1::SetDefaultSumw2(true);
  genOut.init_TTree();
  genOut.Branch_OutTree();
 
  //! open input trees 
  TChain rec("CollectionTree");
  //rec.Add("/home/tamasi/repo_tamasi/user.tkar.pp_VBF_H_260_hh_4b_pythia82_shower_nopileup.v8_output.root/*.root");
  //rec.Add("/home/tamasi/repo_tamasi/user.dferreir.pp_VBF_H_1000_hh_4b_pythia82_shower.v8_output.root/*.root");
  //rec.Add("/home/tamasi/repo_tamasi/user.tkar.pp_ggF_hh_4b_pythia82_shower.v2_output.root/*.root");
  //rec.Add("/media/tamasi/Z/PhD/FCC/Castellated/data_files/user.tkar.pp_ggF_Ctr1.0hh_pythia82_NoGenCuts.v2_output.root/*.root");
  rec.Add("/media/tamasi/Z/PhD/FCC/Castellated/data_files/user.tkar.pp_ggF_Ctr-2.0hh_pythia82_GenCuts.v3_output.root/*.root");
  
  //! Get total no. of events
  //Long64_t nevents = 10000;
  Long64_t nevents = rec.GetEntries();
  genOut.nevents = nevents;
  std::cout<<"number of Pile-up events : " << nevents <<std::endl; 
  
  //! define a local vector<double> to store the input values
  //! always initialise a pointer!!
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
  	if(debug)std::cout<<"nobj: "<<nobj<<std::endl;
	//if(nobj<1) continue;
	
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

		if(std::fabs(eta) > 17) continue;
		tjObj.flag = 1;// stable particles

		if(std::abs(pid) == 5 && status_ == 23 ) 
		{
			tjObj.flag = 0;
			if(debug)
			{
				std::cout<<"b quarks" <<std::endl;
				std::cout<<"pt, eta, phi, pid, status: " << pt << " , " << eta << " , " << phi << " , " << pid << " , " << status_ << std::endl;
			}

		}// b quark

		//else if(std::abs(pid) == 25 && barcode_ > 50)// this is true only if a heavy higgs decays to two SM higgs 
		else if(std::abs(pid) == 25 && status_ == 22) 
		{
			tjObj.flag = 2;
			if(debug)
			{
				std::cout<<"SM higgs" <<std::endl;
				std::cout<<"px, py, pz, eta, phi, pid, status: " << px << " , " << py << " , " << pz << " , " << eta << " , " << phi << " , " << pid << " , " << status_ << std::endl;
			}

		}// SM higgs
		else if(status_ != 1) continue;
		
		//! either use all particles for clustering or make a pt cut or around 1GeV on all particles	
		//q = Particle_Type(pid);// for some old files charge was not stored, hence use this
		q = (*charge)[j];
		
		//if(std::abs(q) < -100) continue; // neutrinos do not deposit any energy
		if(std::abs(pid) == 12 || std::abs(pid) == 14 || std::abs(pid) == 15) continue; // neutrinos do not deposit any energy
		//if(std::abs(q) == 0) continue; // create charged particle jets only.
		if(std::abs(q) != 0 && (std::abs(pid)!= 5 || pid != 25)) //is chrarged and is not a SM higgs or bquark
		{	
			//! get rid of charged particles that will not make it to the calorimeter
			if(std::fabs(pt) < 1.2e3) continue;// Also try 5 GeV and see the difference
		       	
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
	
	//! choose a jet definition
	double R = 0.4;
	double PTMINJET = 5.0e3;
	JetDefinition jet_def(antikt_algorithm, R);
	std::vector<PseudoJet> input_trpcle;
	std::vector<PseudoJet> input_bquarks;
	std::vector<double> input_bquarks_etaVals;
	std::vector<PseudoJet> input_SMhiggs;
	std::vector<double> input_SMhiggs_etaVals;


	//! loop over all truth particles
	for(int k = 0; k < trjVec.size(); ++k )
	{
		if(debug) std::cout<<"Create Pseudo jets \n";
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
	
	//***************** b quarks ********************//
	//! push the |eta values| of the b quarks into a vector 
	//! to sort input_bquarks(a PseudoJet) by increasing value of |eta|
	input_bquarks_etaVals.clear();
	for(int ie = 0; ie < input_bquarks.size(); ie++)
	{
		input_bquarks_etaVals.push_back(std::fabs(input_bquarks[ie].eta()));
	}	
	std::vector<PseudoJet> incl_bquarks_eta = objects_sorted_by_values(input_bquarks, input_bquarks_etaVals);
	std::vector<PseudoJet> incl_bquarks_pt = sorted_by_pt(input_bquarks);	

	genOut.bLPt.push_back(incl_bquarks_pt[0].pt());
	genOut.bNLPt.push_back(incl_bquarks_pt[1].pt());
	genOut.bNNLPt.push_back(incl_bquarks_pt[2].pt());
	genOut.bNNNLPt.push_back(incl_bquarks_pt[3].pt());
	//! Fill eta hist of b quarks sorted in eta
	genOut.FillEta_bquarks_eta(incl_bquarks_eta, genOut.NbJETS);
	//! Fill eta hist of b quarks sorted in pt
	genOut.FillEta_bquarks_pt(incl_bquarks_pt, genOut.NbJETS);
	//! Fill pt hist of b quarks sorted in eta
	genOut.FillPt_bquarks_eta(incl_bquarks_eta, genOut.NbJETS);
	//! Fill pt hist of b quarks sorted in pt
	genOut.FillPt_bquarks_pt(incl_bquarks_pt, genOut.NbJETS);

	genOut.dRb12 = incl_bquarks_pt[0].delta_R(incl_bquarks_pt[1]);
	genOut.dRb13 = incl_bquarks_pt[0].delta_R(incl_bquarks_pt[2]);
	genOut.dRb14 = incl_bquarks_pt[0].delta_R(incl_bquarks_pt[3]);
	genOut.dRb23 = incl_bquarks_pt[1].delta_R(incl_bquarks_pt[2]);
	genOut.dRb24 = incl_bquarks_pt[1].delta_R(incl_bquarks_pt[3]);
	genOut.dRb34 = incl_bquarks_pt[2].delta_R(incl_bquarks_pt[3]);
	//************************************************//
	
	//****************** SM higgs *******************//
	int n_SMhiggs = input_SMhiggs.size();

	//! Pt sorted PseudoJet of SM higgs
	std::vector<PseudoJet> incl_SMhiggs_pt = sorted_by_pt(input_SMhiggs);		
	for (int h = 0; h < n_SMhiggs; h++)
	{
		genOut.higgsPt.push_back(incl_SMhiggs_pt[h].pt());
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
	
	//***************************************************//

	
	//******************* All jets **********************//
	if(debug)std::cout<<"Do jet Clustering \n";
	//! run the jet clustering with the above definition, extract the jets
	ClusterSequence cs_trpcle(input_trpcle, jet_def);
	
	//! sort the resulting jets in descending order of pt
	//! sorted_by_pt is a method of PseudoJet which returns a vector of jets sorted into decreasing pt
	//! sorted_by_rapidity is a method of PseudoJet which returns a vector of jets sorted into increasing eta
	std::vector<PseudoJet> incl_trpclejets = sorted_by_pt(cs_trpcle.inclusive_jets(PTMINJET));
	std::vector<PseudoJet> incl_trpclejets_eta = sorted_by_rapidity(cs_trpcle.inclusive_jets(PTMINJET));
	genOut.Njets = incl_trpclejets.size();

	if(debug)
	{
		std::cout << "Clustering with " << jet_def.description() << std::endl;
		std::cout <<   "        pt y phi" << std::endl;
		std::cout<<"Number of truth jets Njets : " <<genOut.Njets << std::endl;
	}

	//////////////// FIND THE BEST MATCHED BJET /////////////////
	double dR, thisDR;
	int bestTruthJet;
	//! for each bquark sorted in eta (should be four per event)
	int n_bquarks = input_bquarks.size(); //TODO: Fill this in a histogram
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
	genOut.btaggedJets.resize(incl_trpclejets.size(), false);
	genOut.b1tagJets_dR.resize(incl_trpclejets.size(), 99.0);
	genOut.b2tagJets_dR.resize(incl_trpclejets.size(), 99.0);
	genOut.b3tagJets_dR.resize(incl_trpclejets.size(), 99.0);
	genOut.b4tagJets_dR.resize(incl_trpclejets.size(), 99.0);
	genOut.btagJets_dR.resize(incl_trpclejets.size(), 99.0);

	for(unsigned ii = 0; ii < incl_bquarks_pt.size(); ii++)
        {
		dR = 99999.0;
		bestTruthJet = -1;
		for (unsigned jj = 0; jj < incl_trpclejets.size(); jj++)
		{
			
			thisDR = incl_trpclejets[jj].delta_R(incl_bquarks_pt[ii]);
			if(ii == 0) genOut.b1tagJets_dR[jj] = thisDR;
			else if(ii == 1) genOut.b2tagJets_dR[jj] = thisDR;
			else if(ii == 2) genOut.b3tagJets_dR[jj] = thisDR;
			else if(ii == 3) genOut.b4tagJets_dR[jj] = thisDR;
			if(thisDR < dR)
			{
				dR = thisDR;
				bestTruthJet = jj;
			}
		}
		if(debug) std::cout <<"dR: " <<dR <<std::endl;
		if(dR < 0.4)
		{
			//! store result, i.e. in vectorof_bJetsPt: keep only jets matched to b quarks 
			//! Notice that incl_bquarks_pt is sorted hence vectorof_bJetsPt[ii] will also be already sorted	
			//! at this stage vectorof_bJetsPt[nth_bquark] = 0 => initialised above
			//! simple push_back should also work here
			genOut.vectorof_bJetsPt.push_back(incl_trpclejets[bestTruthJet].pt());
			genOut.v_bJetMultiplicity.push_back(incl_trpclejets[bestTruthJet].constituents().size());
			//if(incl_trpclejets[bestTruthJet].pt() > genOut.vectorof_bJetsPt[ii]) 
			//{
			//	genOut.vectorof_bJetsPt[ii] = incl_trpclejets[bestTruthJet].pt();
			//	genOut.v_bJetMultiplicity[ii] = incl_trpclejets[bestTruthJet].constituents().size();
			//}
			//if(debug) std::cout<<"contents in vectorof_jetPt["<<ii<<"] = " <<genOut.vectorof_bJetsPt[ii] <<std::endl;
			////incl_trpclejets_eta.erase(incl_trpclejets_eta.begin() + bestTruthJet);
			////
			genOut.btaggedJets[bestTruthJet] = true;
			genOut.btagJets_dR[bestTruthJet] = dR;
		}
	}// END OF LOOP OVER SORTED in Pt bquarks

	//! FILL Pt HIST OF JETS MATCHED to b quarks 
	genOut.Fill_bJetPt();
	//! FILL MULTIPLICITY HIST OF JETS MATCHED to b quarks 
	genOut.Fill_bJetMultiplicity();

	//! Fill eta histograms of n leading pt jets 
	genOut.FillPt_Jets_pt(incl_trpclejets, genOut.Njet_max);
	
	genOut.v_JetMultiplicity.resize(genOut.Njet_max,0);
	//! for each truth jet sorted in pt
	for (unsigned ii = 0; ii < incl_trpclejets.size(); ++ii) 
	{
		//! smear jet energies
		float jetE_;
		jetE_ = incl_trpclejets[ii].E();
		//! push back all the truth jet parameters here for all "ii"
		genOut.jetE.push_back(jetE_);
		genOut.jetPt.push_back(incl_trpclejets[ii].pt());
		genOut.jetPhi.push_back(incl_trpclejets[ii].phi());
		genOut.jetTheta.push_back(incl_trpclejets[ii].theta());
                genOut.jetEta.push_back(incl_trpclejets[ii].eta());
                genOut.jetEt.push_back(incl_trpclejets[ii].Et());
                genOut.jetMt2.push_back(incl_trpclejets[ii].mt2());
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
			/*if(debug){
			std::cout << "    constituent " << j << "'s pt: " << constituents[j].pt()<< std::endl;
			std::cout << "    constituent " << j << "'s pdg: " << constituents[j].user_info<Constituent_info>().pdg_id()<< std::endl;
			std::cout << "    constituent " << j << "'s Vz: " << constituents[j].user_info<Constituent_info>().Vz()<< std::endl;
			std::cout << "    constituent " << j << "'s Z0: " << constituents[j].user_info<Constituent_info>().Z0()<< std::endl;
			}*/
		}// end of loop over constituents		
		if(debug)
		{
			std::cout<<"jetPt : " << genOut.jetPt[ii]  << std::endl;
			std::cout<<"jetEta : " << genOut.jetEta[ii]  << std::endl;
		}
	}// end of for loop over jet size
	genOut.glob_jet->Fill();

	//! FILL MULTIPLICITY HIST OF JETS MATCHED to b quarks 
	genOut.Fill_JetMultiplicity();

	//! TODO: plot the multiplicity of the jets matched to b quarks
	//! How can we assume the highest pt jet is a b jet??
	//! highest pt jet can aslo be a track right?
	//! would be nice to observe the track multiplicities of the jets matched to b quarks
	//! since they will be for sure not a single track. and this is the reason probably because of which the signal efficiency gets better with the n constituent requirement.
	//! PROBLEM: these jets include the neutrals.. which bdw can be eliminated easily.
	//! TODO: Also repeat these plots for Higgs mass of 1TeV and observe the difference.
	

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
return 0;
}
