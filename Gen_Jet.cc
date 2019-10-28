#include "fastjet/ClusterSequence.hh"
#include "Constituent_info.h"
#include "TrackJetObj.h"
#include "CaloEmu.h"
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
#include <TRandom3.h>
#include <TInterpreter.h>
using namespace fastjet;
#define mass_piPM  139.57018f /* MeV/c^2 */
#define SCALEfac_Ereso 0.5//50% 

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
  
  TRandom3 *myRNG = new TRandom3();
  gRandom = myRNG;

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
  TFile *f_out = new TFile("./fastjet_output/Genjet_ggF_Ctr1.0_q1.2GeV_2.5_2.root","RECREATE");
  TH1::SetDefaultSumw2(true);
  genOut.init_TTree();
  genOut.Branch_OutTree();
 
  //! open input trees 
  TChain rec("CollectionTree");
  //rec.Add("/home/tamasi/repo_tamasi/user.tkar.pp_VBF_H_260_hh_4b_pythia82_shower_nopileup.v8_output.root/*.root");
  //rec.Add("/home/tamasi/repo_tamasi/user.dferreir.pp_VBF_H_1000_hh_4b_pythia82_shower.v8_output.root/*.root");
  //rec.Add("/home/tamasi/repo_tamasi/user.tkar.pp_ggF_hh_4b_pythia82_shower.v2_output.root/*.root");
  rec.Add("/media/tamasi/Z/PhD/FCC/Castellated/data_files/user.tkar.pp_ggF_Ctr1.0hh_pythia82_NoGenCuts.v2_output.root/*.root");
  
  //! Get total no. of events
  Long64_t nevents = 10000;
  //Long64_t nevents = rec.GetEntries();
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
  	if(debug)std::cout<< "EVENT NUMBER: " << i <<" has nobj= "<<nobj<<std::endl;
	//if(nobj<1) continue;
	
	//! initialise a calo object
	//! in principle one should not create objects for every event
	//! TODO: call the block below just once and reset the detector for every event
	//! right now this is not working for some reason.
	CaloEmu caloObj;	
	double phi_Rcalo = 0.0, Rad_calo = 0.0, Rad_pcle = 0.0, ChargedPcle_PtThreshold = 0.0;
	Rad_calo = caloObj.GetCaloRadius();//in mm since pt is in MeV
	//ChargedPcle_PtThreshold = 1.0;
	ChargedPcle_PtThreshold = caloObj.GetChargedPcle_PtThreshold();
	if(debug) std::cout << "charged particle pt threshold = " << ChargedPcle_PtThreshold*1e-3 << "GeV/c" <<std::endl;


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

		if(std::fabs(eta) > 2.5) continue;
		tjObj.flag = 1;// stable particles

		if(std::abs(pid) == 5 && status_ == 23 ) 
		{
			tjObj.flag = 5;
			if(debug)
			{
				std::cout<<"b quarks" <<std::endl;
				std::cout<<"pt, eta, phi, pid, status: " << pt << " , " << eta << " , " << phi << " , " << pid << " , " << status_ << std::endl;
			}

		}// b quark

		//else if(std::abs(pid) == 25 && barcode_ > 50)// this is true only if a heavy higgs decays to two SM higgs 
		else if(std::abs(pid) == 25 && status_ == 22) 
		{
			tjObj.flag = 25;
			if(debug)
			{
				std::cout<<"SM higgs" <<std::endl;
				std::cout<<"px, py, pz, eta, phi, pid, status: " << px << " , " << py << " , " << pz << " , " << eta << " , " << phi << " , " << pid << " , " << status_ << std::endl;
			}

		}// SM higgs
		else if(std::abs(pid) == 4)
		{
			tjObj.flag = 4;
			if(debug)
			{
				std::cout<<"c quarks" <<std::endl;
				std::cout<<"pt, eta, phi, pid, status: " << pt << " , " << eta << " , " << phi << " , " << pid << " , " << status_ << std::endl;
			}
			
		}// charm quark
		else if(std::abs(pid) < 4)
		{
			tjObj.flag = 3;
			if(debug)
			{
				std::cout<<"light quarks" <<std::endl;
				std::cout<<"pt, eta, phi, pid, status: " << pt << " , " << eta << " , " << phi << " , " << pid << " , " << status_ << std::endl;
			}
			
		}// light quark
		else if(status_ != 1) continue;
		
		q = (*charge)[j];
		
		if(std::abs(pid) == 12 || std::abs(pid) == 14 || std::abs(pid) == 15) continue; // neutrinos do not deposit any energy
		//! calculate modified phi for particles
		Rad_pcle  = pt/(caloObj.CONSTANT * q * caloObj.B_field); 
		phi_Rcalo = phi;
		if(std::abs(q) != 0 && (std::abs(pid) > 5 || pid != 25)) //is chrarged and is not a SM higgs or bquark or charm or any of the light quarks
		{	
			//! get rid of charged particles that will not make it to the calorimeter
			if(std::fabs(pt) < ChargedPcle_PtThreshold) continue;
			phi_Rcalo = phi + acos(0.5 * Rad_calo/Rad_pcle) - (M_PI/2);
			if(phi_Rcalo > 2 * M_PI) phi_Rcalo -= 2*M_PI;
			if(phi_Rcalo < 0) phi_Rcalo += 2*M_PI;
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
		//! add the modified eta and phi values here
		//! i.e. eta and phi due to bending of charged particles in magnetic field
		//! (eta unchanged as track is almost straight line in s-z plane)
		tjObj.phi = phi_Rcalo;
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
	std::vector<PseudoJet> input_cquarks;
	std::vector<PseudoJet> input_lightquarks;
	std::vector<double> input_bquarks_etaVals;
	std::vector<PseudoJet> input_SMhiggs;
	std::vector<double> input_SMhiggs_etaVals;


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
		}
		
	}// end of loop over all tracks trjVec

	//********** Calo detector construction using a 2D histogram *****************//	
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
			std::vector<double> Eptetaphi = caloObj.GetCellEnergy(i, j);// this is where smearing is done
			if(Eptetaphi[0] > caloObj.GetCellEnergyThreshold())
			{
				PseudoJet p(0., 0., 0., 0.);
				// And treat 'clusters' as massless.
				if(debug) std::cout<<"Cell energy[ " << i << ", " << j << "]: " << Eptetaphi[0] <<std::endl;
	                     	p.reset_PtYPhiM(Eptetaphi[1], Eptetaphi[2], Eptetaphi[3], 0.);
				p.set_user_info(new Constituent_info(0,0,0));
				CellEnergy_forEmuCaloJets.push_back(p);

			}	
		}//phibins
	}//etabins

	//********************************************************************************************//

		
	//***************** b quarks ********************//
	//! push the |eta values| of the b quarks into a vector 
	//! to sort input_bquarks(a PseudoJet) by increasing value of |eta|
	input_bquarks_etaVals.clear();
	std::vector<PseudoJet> incl_bquarks_eta;
	std::vector<PseudoJet> incl_bquarks_pt;	
	int n_bquarks = input_bquarks.size(); //TODO: Fill this in a histogram
	if(input_bquarks.size()!=0)
	{
		for(int ie = 0; ie < input_bquarks.size(); ie++)
		{
			input_bquarks_etaVals.push_back(std::fabs(input_bquarks[ie].eta()));
		}	
		incl_bquarks_eta = objects_sorted_by_values(input_bquarks, input_bquarks_etaVals);
		incl_bquarks_pt = sorted_by_pt(input_bquarks);	
		
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
	//************************************************//
	
	//****************** SM higgs *******************//
	int n_SMhiggs = input_SMhiggs.size();
	if(n_SMhiggs > 1)
	{
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
	}
	//***************************************************//

	
	//******************* All jets **********************//
	if(debug)std::cout<<"Do jet Clustering \n";
	//! run the jet clustering with the above definition, extract the jets
	//ClusterSequence cs_trpcle(input_trpcle, jet_def);
	ClusterSequence cs_trpcle(CellEnergy_forEmuCaloJets, jet_def);
	//ClusterSequence cs_CaloEmuJet(CellEnergy_forEmuCaloJets, jet_def);
	//std::vector<PseudoJet>  incl_CaloEmuJets = sorted_by_pt(cs_CaloEmuJet.inclusive_jets(PTMINJET));
	
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


	//! Fill eta histograms of n leading pt jets 
	genOut.FillPt_Jets_pt(incl_trpclejets, genOut.Njet_max);
	
	genOut.v_JetMultiplicity.resize(genOut.Njet_max,0);
	genOut.Ncquarks = input_cquarks.size();
	genOut.Nlightquarks = input_lightquarks.size();

	double dR, thisDR;
	int bestTruthJet;
	//! for each truth jet sorted in pt
	for (unsigned ii = 0; ii < incl_trpclejets.size(); ++ii) 
	{
		//! smear jet energies
		float jetE_;
		//	, jetE_reso_;
		//float jetE_smeared, jetPt_smeared;
		jetE_ = incl_trpclejets[ii].E();
		//jetE_reso_ = SCALEfac_Ereso/sqrt(jetE_);//50% energy resolution
		//jetE_smeared = gRandom->Gaus(jetE_,jetE_reso_*jetE_);
		//jetPt_smeared = sqrt(jetE_smeared*jetE_smeared - incl_trpclejets[ii].m2() - incl_trpclejets[ii].pz()*incl_trpclejets[ii].pz());
		//
		////! push back all the truth jet parameters here for all "ii"
		//genOut.jetPt_sm.push_back(jetPt_smeared);
		//genOut.jetE_sm.push_back(jetE_smeared);
		//genOut.jetE_reso.push_back(jetE_reso_);
		
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
		
		//********* tag Jets with the following probabilities: ***********//
		//if matched to a b quark with pt > 15GeV/c, tag the jet as b-tagged with probability 0.8
		//if matched to a c quark with pt > 15GeV/c, tag the jet as b-tagged with probability 0.1
		//if matched to a light quark with pt > 15GeV/c, tag the jet as b-tagged with probability 0.01
		const double MinQuarkPt = 15e3;
		double fb = 0.8, fc= 0.1, fl = 0.01;
		dR = 99999.0;
		bestTruthJet = -1;
		int btagged_flavor = 0;
		double matchFound = 99;
		//if(debug) std::cout<<"number of b quarks: " << 
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
			if(dR < 0.4)
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
			if(dR < 0.4) 
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
			if(dR < 0.4)
			{
				matchFound = gRandom->Uniform(0,1);
				if(matchFound <= fl) btagged_flavor = 3;
			}
		}
		genOut.btaggedFlavor.push_back(btagged_flavor);
		genOut.btagProb.push_back(matchFound);


	}// end of for loop over jet size
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
		if(dR < 0.4)
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
return 0;
}
