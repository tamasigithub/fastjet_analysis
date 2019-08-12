#include "fastjet/ClusterSequence.hh"
#include "Constituent_info.h"
#include "TrackJetObj.h"
#include "Rate_sumpt.h"
#include "TrigEff.h"
#include "CaloEmu.h"
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
  
  //! variables used to make efficiency plots
  int etabin = 30;
  double etamin =-1.7, etamax = 1.7;
  // log bins
  const int ptbins = 40;//no. of bins
  int length = ptbins + 1;
  Double_t xbins[length];
  double dx, l10;
  dx = 3./ptbins;//5 -> implies max until 10^5
  l10 = TMath::Log(10);
  for (int i = 0; i<=ptbins; i++)
  {
	//std::cout<<"i,dx : " <<i << ", "<<dx <<std::endl;
	xbins[i] = TMath::Exp(l10*i*dx);
	//std::cout<<"xbin[i] : " <<xbins[i] <<std::endl;
  }

  int MIN_Constituents = 2;
  float SCALEfac_Ereso = 0.5;//50% 
/////////////////////////////////////////////////////////
  //! binning for rate and trigger efficienceis
////////////////////////////////////////////////////////
  const float PT_MIN = 0., PT_MAX = 500., PTCUT_WIDTH = 5.0;// in GeV/c
  //! create an object to plot rate as a function of pt
  Rate_sumpt r_sumpt(PT_MIN, PT_MAX, PTCUT_WIDTH);
  r_sumpt.init_Histos(r_sumpt.xbins, r_sumpt.nbins);

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
  std::vector<double> jetE_sm;				// truth-jet energy smeared 
  std::vector<double> jetPt_sm;				// truth-jet pt smeared
  std::vector<double> jetE;				// truth-jet energy 
  std::vector<double> jetE_reso;			// x% of truth-jet energy resolution e.g. 50%/sqrt(E)
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

  //! output root file
  //TFile *f_out = new TFile("NewjetEMU5GeV_PU0MB_q1.2GeV_30mm.root","RECREATE");
  TFile *f_out = new TFile("NewjetEMU5GeV_PU0hh4b_m260_q1.2GeV_30mm.root","RECREATE");
  //! default 5 GeV pt cut, eta 1.6
  //TFile *f_out = new TFile("jetEMU_PU1000MB_30mm.root","RECREATE");
  //TFile *f_out = new TFile("jetEMU_PU1000hh4b_m260_30mm.root","RECREATE");
  TH1::SetDefaultSumw2(true);
  //! track jet efficiency
  TH1* h_num_vs_etaPU = new TH1F("h_num_vs_etaPU", "Numerator Count vs #eta;#eta;Numerator Count", etabin, etamin, etamax);
  TH1* h_den_vs_etaPU = new TH1F("h_den_vs_etaPU", "Denominator Count vs #eta;#eta;Denominator Count", etabin, etamin, etamax);
  TH1* h_num_vs_ptPU = new TH1F("h_num_vs_ptPU", "Numerator Count vs P_{t};P_{t} [MeV/c];Numerator Count", ptbins, xbins);
  TH1* h_den_vs_ptPU = new TH1F("h_den_vs_ptPU", "Denominator Count vs P_{t};P_{t} [MeV/c];Denominator Count", ptbins, xbins);

  TTree *glob_jet = new TTree("glob_jet","glob_jet");
  glob_jet->Branch("event",&eventNo);
  glob_jet->Branch("Njets",&Njets);
  glob_jet->Branch("jetE_sm",&jetE_sm);
  glob_jet->Branch("jetPt_sm",&jetPt_sm);
  glob_jet->Branch("jetE",&jetE);
  glob_jet->Branch("jetE_reso",&jetE_reso);
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
  
  
  //! open input trees 
  TChain rec("tracks");
  //rec.Add("/media/tamasi/Z/PhD/FCC/Castellated/rec_files/PU1000hh4b_recTree_3*.root");
  //rec.Add("/media/tamasi/Z/PhD/FCC/Castellated/rec_files/PU1000MB_recTree_3*.root");
  rec.Add("/media/tamasi/Z/PhD/FCC/Castellated/rec_files/PU0_hh4bm260_30mm_sig5/*.root");
  //rec.Add("/media/tamasi/Z/PhD/FCC/Castellated/rec_files/PU0_MB_30mm_sig5/*.root");
  //! define a local vector<double> to store the reconstructed pt values
  //! always initialise a pointer!!
  std::vector<double> *pt_tru = 0;
  std::vector<double> *z0_tru = 0;
  std::vector<double> *theta_tru = 0;
  std::vector<double> *eta_tru = 0;
  std::vector<double> *phi_tru = 0;
  std::vector<int> *pdg = 0;
  std::vector<int> *charge = 0;
  rec.SetBranchStatus("pt",1);
  rec.SetBranchStatus("vz",1);
  rec.SetBranchStatus("theta",1);
  rec.SetBranchStatus("eta",1);
  rec.SetBranchStatus("phi",1);
  rec.SetBranchStatus("pid",1);
  rec.SetBranchStatus("charge",1);
  rec.SetBranchAddress("pt", &pt_tru);
  rec.SetBranchAddress("vz", &z0_tru);
  rec.SetBranchAddress("theta", &theta_tru);
  rec.SetBranchAddress("eta", &eta_tru);
  rec.SetBranchAddress("phi", &phi_tru);
  rec.SetBranchAddress("pid", &pdg);
  rec.SetBranchAddress("charge", &charge);
  //! get mc information -pdgid and z vertex  
  //! vectors containing a single pileup event
  std::vector<double> pt_truPU;
  std::vector<double> z0_truPU;
  std::vector<double> theta_truPU;
  std::vector<double> eta_truPU;
  std::vector<double> phi_truPU;
  std::vector<int> pdgPU;
  std::vector<int> chargePU;
  
  //! Get total no. of events
  //Long64_t nentries = rec.GetEntries();
  ////Long64_t nentries = 1000;
  //int pileup = 160;
  //Long64_t nevents = nentries/pileup;
  //Long64_t nevents = 900;
  Long64_t nevents = rec.GetEntries();
  r_sumpt.nevents = nevents;
  //std::cout<<"Total number of enteries : " << nentries <<std::endl;
  std::cout<<"number of Pile-up events : " << nevents <<std::endl;
  //! vector of reconstructed track-jet objects
  std::vector<TrackJetObj> trjVec;//define outside the loop and call clear inside OR define inside the loop and it will be destroyed at the end of the loop for each iteration similar to the class object
  //
  double pt,z0,theta,eta,phi;
  int pid,q;


  //! for every event do the following
  for(Long64_t i = 0; i < nevents; ++i)
  {
  	eventNo=i;
	TrackJetObj tjObj;
	jetE_sm.clear();
	jetPt_sm.clear();
	jetE.clear();
	jetE_reso.clear();
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
	pt_truPU.clear();
	z0_truPU.clear();
	theta_truPU.clear();
	eta_truPU.clear();
	phi_truPU.clear();
	pdgPU.clear();
	chargePU.clear();

	//caloObj.Reset_Detector();	
	rec.GetEntry(i);
	for(int ik = 0; ik < pt_tru->size(); ++ik)
	{
		pt_truPU.push_back((*pt_tru)[ik]);
		z0_truPU.push_back((*z0_tru)[ik]);
		theta_truPU.push_back((*theta_tru)[ik]);
		eta_truPU.push_back((*eta_tru)[ik]);
		phi_truPU.push_back((*phi_tru)[ik]);
		pdgPU.push_back((*pdg)[ik]);
		chargePU.push_back((*charge)[ik]);
		
	}
	

	//! initialise a calo object
	//! in principle one should not create objects for every event
	//! TODO: call the block below just once and reset the detector for every event
	//! right now this is not working for some reason.

	CaloEmu caloObj;	
	double phi_Rcalo = 0, Rad_calo = 0, Rad_pcle = 0, ChargedPcle_PtThreshold = 0;
	Rad_calo = caloObj.GetCaloRadius();//in mm since pt is in MeV
	ChargedPcle_PtThreshold = caloObj.GetChargedPcle_PtThreshold();
	if(debug) std::cout << "charged particle pt threshold = " << ChargedPcle_PtThreshold*1e-3 << "GeV/c" <<std::endl;

	
	//! total number of tracks reconstructed in an event
	int nobj = pt_truPU.size();
  	if(debug)std::cout<<"nobj: "<<nobj<<std::endl;
	if(nobj<1) continue;
	//! for all tracks in a pileup event
	for (int j = 0; j < nobj; ++j)
	{
		pt	= pt_truPU[j];
		z0	= z0_truPU[j];
		theta	= theta_truPU[j];
		eta	= eta_truPU[j];
		phi	= phi_truPU[j];
		pid	= pdgPU[j];
		q	= chargePU[j];

		//////// ACCEPTANCE CUTS //////////	
		if(std::fabs(eta) > 1.7) continue; 
		if(std::abs(q) > 1) continue; // there are a=many particles with pdgs >1e9 which have weird charges
		Rad_pcle  = pt/(caloObj.CONSTANT * q * caloObj.B_field); 
		phi_Rcalo = phi;
		if(std::abs(q) != 0) //is chrarged
		{	
			//! get rid of charged particles that will not make it to the calorimeter
			if(std::fabs(pt) < ChargedPcle_PtThreshold) continue;
			phi_Rcalo = phi + acos(0.5 * Rad_calo/Rad_pcle) - (M_PI/2);
			if(phi_Rcalo > 2 * M_PI) phi_Rcalo -= 2*M_PI;
			if(phi_Rcalo < 0) phi_Rcalo += 2*M_PI;
		}	

		//! veto fake and dc tracks?
		//if(tjObj.flag!=1) continue;
		//! veto only dc tracks and those which do not satisfy the above selection cuts?
		if(tjObj.flag < 0) continue;

		if(debug)
		{
			std::cout<<"flag : " << tjObj.flag <<std::endl;
			std::cout<<"pt, z0, theta, phi, pid: " << pt << " , " << z0 << " , " << theta << " , " << phi << " , " << pid << std::endl;
		
		}
		tjObj.px = pt*cos(phi);
		tjObj.py = pt*sin(phi);
		tjObj.pz = pt/tan(theta);
		tjObj.E  = std::sqrt(std::pow(pt/sin(theta),2) + std::pow(mass_piPM,2));
		//! add the modified eta and phi values here
		//! i.e. eta and phi due to bending of charged particles in magnetic field
		//if(q!=0)double rad = pt/(0.3*4*q);
		tjObj.eta = eta;
		tjObj.phi = phi_Rcalo;
		//! matched to truth, reco info has been set to zero for inefficinecy and this causes a crash while doing jet clustering
		//! for rec jet clustering we anyway do not need these zeroes
		tjObj.zv = z0;
		tjObj.pdg = pid;
		tjObj.Vz0 = z0;

		//! push the objects into a vector of these objects
		trjVec.push_back(tjObj);

	}// end of loop over nobj
	
	// choose a jet definition
	double R = 0.4;
	double PTMINJET = 5.0e3;
	JetDefinition jet_def(antikt_algorithm, R);
	std::vector<PseudoJet> input_trpcle;


	// loop over all truth particles
	for(int k = 0; k < trjVec.size(); ++k )
	{
		//if(debug) std::cout<<"Create Pseudo jets \n";
		// an event with particles: px		py		pz   	E
		PseudoJet trpcle(trjVec[k].px, trjVec[k].py, trjVec[k].pz, trjVec[k].E);
		trpcle.set_user_info(new Constituent_info(trjVec[k].pdg, trjVec[k].Vz0, trjVec[k].zv));
		//input_trpcle.push_back( PseudoJet( trjVec[k].px, trjVec[k].py, trjVec[k].pz, trjVec[k].E) );  
		input_trpcle.push_back(trpcle);
		
		////////////////////////////////////////////////////////////////
		//           Calorimeter - realistic emulation                //
		////////////////////////////////////////////////////////////////           
		//! accumulate energy deposits in each calo cell
                //! find the particles rapidity and phi, then get the detector bins(cells) and accumulate energy in this cell
		/*std::cout<<"eta, Eta: " <<trjVec[k].eta << ", " << trpcle.eta() <<std::endl;
		std::cout<<"phi, Phi: " <<trjVec[k].phi << ", " << trpcle.phi() <<std::endl;
		std::cout<<"e, E: " <<trjVec[k].E << ", " << trpcle.e() <<std::endl;*/
		//caloObj.AccumulateEnergy(trpcle.eta(), trpcle.phi(), trpcle.e());// initial eta phi
		caloObj.AccumulateEnergy(trjVec[k].eta, trjVec[k].phi, trjVec[k].E);// modified eta phi due to bending in magnetic field
	}// end of loop over all tracks trjVec
	
	std::vector<PseudoJet> CellEnergy_forEmuCaloJets;
	unsigned int n_xbins = caloObj.GetNxbins();
	unsigned int n_ybins = caloObj.GetNybins();
	if(debug)
	{
		std::cout << "n_xbins: " << n_xbins <<std::endl;//etabins
		std::cout << "n_ybins: " << n_ybins <<std::endl;//phibins
		std::cout<<"Cell Energy threshold: " << caloObj.GetCellEnergyThreshold()*1e-3 << "GeV."<<std::endl;
	}
	for(unsigned int i = 1; i <= n_xbins; i++ )
	{
		for(unsigned int j = 1; j <= n_ybins; j++)
		{
			std::vector<double> Eptetaphi = caloObj.GetCellEnergy(i, j);
			if(Eptetaphi[0] > caloObj.GetCellEnergyThreshold())
			{
				PseudoJet p(0., 0., 0., 0.);
				// And treat 'clusters' as massless.
				if(debug) std::cout<<"Cell energy[ " << i << ", " << j << "]: " << Eptetaphi[0] <<std::endl;
	                     	p.reset_PtYPhiM(Eptetaphi[1], Eptetaphi[2], Eptetaphi[3], 0.);
				CellEnergy_forEmuCaloJets.push_back(p);

			}	
		}//phibins
	}//etabins

	ClusterSequence cs_CaloEmuJet(CellEnergy_forEmuCaloJets, jet_def);
	std::vector<PseudoJet>  incl_CaloEmuJets = sorted_by_pt(cs_CaloEmuJet.inclusive_jets(PTMINJET));
	// ********************************************************************************************//
	
	if(debug)std::cout<<"Do jet Clustering \n";
	// run the jet clustering with the above definition, extract the jets
	ClusterSequence cs_trpcle(input_trpcle, jet_def);
	// sort the resulting jets in ascending order of pt
	// sorted_by_pt is a method of PseudoJet which returns a vector of jets sorted into decreasing pt
	std::vector<PseudoJet> incl_trpclejets = sorted_by_pt(cs_trpcle.inclusive_jets(PTMINJET));
	// print out some infos
	if(debug){std::cout << "Clustering with " << jet_def.description() << std::endl;

	// print the jets
	std::cout <<   "        pt y phi" << std::endl;}
	Njets = incl_trpclejets.size();
	if(debug)
	{
		std::cout<<"Number of truth jets Njets : " <<Njets << std::endl;

	}
	//! for each truth jet
	for (unsigned ii = 0; ii < incl_trpclejets.size(); ii++) 
	{
		//! check if the nth jet has atleast MIN_Constituents
		//if(const_size < MIN_Constituents) continue;
		//! smear jet energies
		float jetE_, jetE_reso_;
		float jetE_smeared, jetPt_smeared;
		jetE_ = incl_trpclejets[ii].E();
		jetE_reso_ = SCALEfac_Ereso/sqrt(jetE_);//50% energy resolution
		jetE_smeared = gRandom->Gaus(jetE_,jetE_reso_*jetE_);
		jetPt_smeared = sqrt(jetE_smeared*jetE_smeared - incl_trpclejets[ii].m2() - incl_trpclejets[ii].pz()*incl_trpclejets[ii].pz());
		//! push back all the truth jet parameters here for all "ii"
		jetPt_sm.push_back(jetPt_smeared);
		jetE_sm.push_back(jetE_smeared);
		jetE_reso.push_back(jetE_reso_);
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
		if(debug)
		{ 
			if(const_size < MIN_Constituents) std::cout <<"not a jet" <<std::endl;
			std::cout<<"number of constituents in jet " << ii << " = " << Nconstituents[ii] << std::endl;
		}
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
	*/	if(incl_CaloEmuJets.size() >= trigger.Njet_max)
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
			
		}
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
//r_sumpt.SetHist_props();
r_sumpt.Fill_TrigRate_EMU(r_sumpt.n_tots);
r_sumpt.SetHist_props();
//! continuation of trigger efficiency cal.
//! we fill outside as we want count the no. of events with 'n' trackjets above a pt threshold
trigger.init(trigger.xbins, trigger.nbins);
trigger.SetHist_props();
trigger.Fill_TrigEff();
TCanvas *C_trig = new TCanvas();
trigger.DrawNoBin();
C_trig->Write();
trigger.WriteAll();
TCanvas *c1 = new TCanvas();
r_sumpt.DrawNoBin();
c1->SetLogy();
c1->Update();
r_sumpt.WriteAll();
c1->Write();
//! Write to output file
glob_jet->Write();

f_out->Close();
return 0;
}
