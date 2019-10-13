/*!
 *  \file
 *  \brief Class to plot rate as a function of pt using sumpt
 */
#ifndef GEN_OUTPUT_H_
#define GEN_OUTPUT_H_

#include <iostream>
#include "TROOT.h"
#include "TFile.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TLegend.h"
#include "TGraphErrors.h"
#include "TPostScript.h"
#include "TLatex.h"
#include "TChain.h"
#include "TMath.h"
#include <vector>
#include <list>
#include <algorithm> 
#include <functional>
#include <fstream>
#include <string>
#include <math.h>
#include <numeric> //accumulate
#include "fastjet/ClusterSequence.hh"
using namespace fastjet;

class Gen_output
{
public:
	int nevents;// number of pileup events
	double Lpt, NLpt, NNLpt, NNNLpt, NNNNLpt;
	static const int nbins_plus1 = 101;
	static const  int nbins = 100;// = (pt_max - pt_min)/ptcut_width;
	float pt_min, pt_max, ptcut_width;
    	float xbins[nbins_plus1];
	std::vector<int*> n_tots;

	const int Njet_max = 5;
	const int NbJETS = 4;
	//! init vector to a high eta value
	std::vector<double>vectorof_bJetsEta;
	//! init vector to a low pt value
	std::vector<double>vectorof_bJetsPt;
	std::vector<int> v_bJetMultiplicity;
	std::vector<int> v_JetMultiplicity;
	int nMultiplicityBins = 40;
	double maxMultiplicity = 40;

	int nEtaBins = 100;
	double etaMin = 0.0, etaMax = 6.0;
	bool debug = true;

	

public:
	Gen_output(float ptMin, float ptMax, float ptcutWidth):pt_min(ptMin), pt_max(ptMax), ptcut_width(ptcutWidth) 
	{
		for(int i = 0; i <= nbins; i++)
		{
			if(i==0) xbins[i] = pt_min;
			xbins[i] = i*ptcut_width;
			//std::cout<< "xbin[ " << i << "] : " <<xbins[i] <<std::endl; 
		}
	}
	~Gen_output(){}

	void init_MultiplicityHist();
	void init_PtHist(float xbins[], int nbins);
	void init_EtaHist();
	void SetEtaHist_props();
	void SetPtHist_props();
	void SetMultiplicityHist_props();
	void Fill_bJetEta();
	void Fill_bJetPt();
	void Fill_bJetMultiplicity();
	void Fill_JetMultiplicity();
	void FillEta_bquarks_eta(std::vector<PseudoJet> Obj, int NObj);
	void FillEta_bquarks_pt(std::vector<PseudoJet> Obj, int NObj);
	void FillPt_bquarks_eta(std::vector<PseudoJet> Obj, int NObj);
	void FillPt_bquarks_pt(std::vector<PseudoJet> Obj, int NObj);
	void FillPt_Jets_pt(std::vector<PseudoJet> Obj, int NObj);
	void WriteEta();
	void WritePt();
	void WriteMultiplicity();
	
	void Clear_OutVars();
	void init_TTree();
	void Branch_OutTree();
	
	//void init_Histos(float xbins[], int nbins);
	//void SetHist_props();
	//void DrawNoBin();
	//void DrawRate();
	//void DrawSumpt();
	//void WriteAll();
	//void WriteNoBin();
	//void Fill_TrigRate(std::vector<int*> vec_ntots);
	//void Fill_TrigRate_EMU(std::vector<int*> vec_ntots);
	//void DrawMultiplicitySumpt();
	//void DrawMultiplicityMaxpt();
	//void DrawMultiplicity();
	//void WriteMultiplicity();
public:
	//! Output TTree
	TTree* glob_jet = nullptr;

	//! output variables 
	int eventNo;
	int Njets;						// # of truth-jets
	int Nbquarks;						// # of truth-jets
	int NSMhiggs;						// # of truth-jets
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
	std::vector<double> jetEt;                     		//  truth-jet energy 
	std::vector<std::vector<double> > constituentEt;      	// it's constituents energy
	std::vector<double> jetMt;                     		//  truth-jet mass
	std::vector<std::vector<double> > constituentMt;      	// it's constituents mass
	std::vector<std::vector<int> >    constituentPdg;	// pdg of truth-jet constituents
	std::vector<std::vector<double> > constituentZ0;	//  z vertex truth-jet constituents
	std::vector<bool>  hasConstituents;            		// flag indicating if the truth-jet has constituents
	std::vector<int>   Nconstituents;	            	// number of constituents for each jet
	
	//! Book Histogram        
	//! Histograms of eta distributions of "jets matched to b quarks" sorted into increasing eta
	//! central to forward
	TH1* hbJetEta_NNNCeta = nullptr;
	TH1* hbJetEta_NNCeta = nullptr;
	TH1* hbJetEta_NCeta = nullptr;
	TH1* hbJetEta_Ceta = nullptr;
	//! Histograms of pt distributions of "jets matched to b quarks" sorted into decreasing pt
	TH1* hbJetPt_NNNLpt = nullptr;
	TH1* hbJetPt_NNLpt = nullptr;
	TH1* hbJetPt_NLpt = nullptr;
	TH1* hbJetPt_Lpt = nullptr;
	
	//! Histograms of eta distribution of "b quarks" sorted in eta
	TH1* hbEta_NNNCeta = nullptr;
	TH1* hbEta_NNCeta = nullptr;
	TH1* hbEta_NCeta = nullptr;
	TH1* hbEta_Ceta = nullptr;
	//! Histograms of eta distribution of "b quarks" sorted in pt
	TH1* hbEta_NNNLpt = nullptr;
	TH1* hbEta_NNLpt = nullptr;
	TH1* hbEta_NLpt = nullptr;
	TH1* hbEta_Lpt = nullptr;
	//! Histograms of pt distribution of "b quarks" sorted in eta
	TH1* hbPt_NNNCeta = nullptr;
	TH1* hbPt_NNCeta = nullptr;
	TH1* hbPt_NCeta = nullptr;
	TH1* hbPt_Ceta = nullptr;
	//! Histograms of pt distribution of "b quarks" sorted in pt
	TH1* hbPt_NNNLpt = nullptr;
	TH1* hbPt_NNLpt = nullptr;
	TH1* hbPt_NLpt = nullptr;
	TH1* hbPt_Lpt = nullptr;
	
	//! Histograms for recording the pt distributions of the n leading pt "jets" 
        TH1* hJetPt_PULpt = nullptr;
	TH1* hJetPt_PUNLpt = nullptr;
	TH1* hJetPt_PUNNLpt = nullptr;
	TH1* hJetPt_PUNNNLpt = nullptr;
	TH1* hJetPt_PUNNNNLpt = nullptr;
	
	//! Histograms of multiplicity of "jets matched to b quarks" sorted in pt
        TH1* hMult_bJetLpt = nullptr;
	TH1* hMult_bJetNLpt = nullptr;
	TH1* hMult_bJetNNLpt = nullptr;
	TH1* hMult_bJetNNNLpt = nullptr;
	//! Histograms of multiplicity of n leading pt "jets"
        TH1* hMult_JetLpt = nullptr;
	TH1* hMult_JetNLpt = nullptr;
	TH1* hMult_JetNNLpt = nullptr;
	TH1* hMult_JetNNNLpt = nullptr;
	TH1* hMult_JetNNNNLpt = nullptr;

	////! sumpt histos
	//TH1* h_PULpt = nullptr;
	//TH1* h_PUNLpt = nullptr;
	//TH1* h_PUNNLpt = nullptr;
	//TH1* h_PUNNNLpt = nullptr;
	//TH1* h_PUNNNNLpt = nullptr;
	////! overlapping bin approach
        //TH1* ha_PULpt = nullptr;
	//TH1* ha_PUNLpt = nullptr;
	//TH1* ha_PUNNLpt = nullptr;
	//TH1* ha_PUNNNLpt = nullptr;
	//TH1* ha_PUNNNNLpt = nullptr;
	////! without binning
        //TH1* hb_PULpt = nullptr;
	//TH1* hb_PUNLpt = nullptr;
	//TH1* hb_PUNNLpt = nullptr;
	//TH1* hb_PUNNNLpt = nullptr;
	//TH1* hb_PUNNNNLpt = nullptr;
	////! histograms for recording track multiplicity
	////! sumpt histos
	//TH1* hM_PULpt = nullptr;
	//TH1* hM_PUNLpt = nullptr;
	//TH1* hM_PUNNLpt = nullptr;
	//TH1* hM_PUNNNLpt = nullptr;
	//TH1* hM_PUNNNNLpt = nullptr;


	
private:
    //! delete the default copy constructor and assignment operator
    Gen_output(const Gen_output&) = delete;
    Gen_output& operator=(const Gen_output&) = delete;

};
#endif /*GEN_OUTPUT_H_*/
