/*!
 *  \file
 *  \brief Class to plot rate as a function of pt using sumpt
 */
#ifndef RATE_SUMPT_H_
#define RATE_SUMPT_H_

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

class Rate_sumpt
{
public:
	int nevents;// number of pileup events
	double max_sumpt;
	int prim_bin;
	std::vector<double> v_sumpt;
	//int nbins = 40;
	//double ptmin = 0.0, ptmax = 1000;//in GeV/c 
	double Lpt, NLpt, NNLpt, NNNLpt, NNNNLpt;
	static const int nbins_plus1 = 401;//101;
	static const  int nbins = 400;//100;// = (pt_max - pt_min)/ptcut_width;
	//static const int nbins_plus1 = 116;
	//static const  int nbins = 115;// = (pt_max - pt_min)/ptcut_width;
	//const int Nlowpt_bins = 80;
	float pt_min, pt_max, ptcut_width;
    	float xbins[nbins_plus1];
	std::vector<int*> n_tots;

	std::vector<int> v_TJMult_sumpt;
	std::vector<int> v_TJMult_maxpt;
	//int nMultiplicityBins = 10;
	//double maxMultiplicity = 10;
	int nMultiplicityBins = 100;
	double maxMultiplicity = 100;
	int nMultiplicityBins_1 = 100;
	double maxMultiplicity_1 = 100;

	int nEtaBins = 100;
	double etaMin = 0.0, etaMax = 6.0;
	bool debug = true;
	

public:
	Rate_sumpt(float ptMin, float ptMax, float ptcutWidth):pt_min(ptMin), pt_max(ptMax), ptcut_width(ptcutWidth) 
	{
		for(int i = 0; i <= nbins; i++)
		{
			if(i==0) xbins[i] = pt_min;
			xbins[i] = xbins[0] + i*ptcut_width;
			//////std::cout<< "xbin[ " << i << "] : " <<xbins[i] <<std::endl; 
			//
			////if(i==0) xbins[i] = pt_min;
			////else if(i < Nlowpt_bins)
			////{
			////     xbins[i] = i*ptcut_width;
			////}
			////else
			////{
			////     int j = i - Nlowpt_bins;
			////     int highpt_min = pt_max - 4*ptcut_width * (nbins - Nlowpt_bins);
			////     xbins[i] = highpt_min + j*4*ptcut_width;
			////}

			//std::cout<< "xbin[ " << i << "] : " <<xbins[i] <<std::endl; 
		
		}
		/*dx = 5./ptbins;//5 -> implies max until 10^5
		l10 = TMath::Log(10);
		for (int i = 0; i<=ptbins; i++)
		{
			std::cout<<"i,dx : " <<i << ", "<<dx <<std::endl;
			xbins[i] = TMath::Exp(l10*i*dx);
			std::cout<<"xbin[i] : " <<xbins[i] <<std::endl;
		}*/
	}
	~Rate_sumpt(){}
	void init_Histos(float xbins[], int nbins);
	void init_EtaHist();
	void SetMultiplicityHist_props();
	void SetHist_props();
	void SetEtaHist_props();
	void DrawNoBin();
	void DrawRate();
	void DrawSumpt();
	void WriteAll();
	void WriteNoBin();
	void Fill_TrigRate(std::vector<int*> vec_ntots);
	void Fill_TrigRate_EMU(std::vector<int*> vec_ntots);
	void DrawMultiplicitySumpt();
	void DrawMultiplicityMaxpt();
	void DrawMultiplicity();
	void WriteMultiplicity();
	void WriteEta();
	void WriteEta1();
public:
	//! Book Histogram        
	//! sumpt histos
	TH1* h_PULpt = nullptr;
	TH1* h_PUNLpt = nullptr;
	TH1* h_PUNNLpt = nullptr;
	TH1* h_PUNNNLpt = nullptr;
	TH1* h_PUNNNNLpt = nullptr;
	//! overlapping bin approach
        TH1* ha_PULpt = nullptr;
	TH1* ha_PUNLpt = nullptr;
	TH1* ha_PUNNLpt = nullptr;
	TH1* ha_PUNNNLpt = nullptr;
	TH1* ha_PUNNNNLpt = nullptr;
	//! without binning
        TH1* hb_PULpt = nullptr;
	TH1* hb_PUNLpt = nullptr;
	TH1* hb_PUNNLpt = nullptr;
	TH1* hb_PUNNNLpt = nullptr;
	TH1* hb_PUNNNNLpt = nullptr;
	//! histograms for recording track multiplicity
	//! sumpt histos
	TH1* hM_PULpt = nullptr;
	TH1* hM_PUNLpt = nullptr;
	TH1* hM_PUNNLpt = nullptr;
	TH1* hM_PUNNNLpt = nullptr;
	TH1* hM_PUNNNNLpt = nullptr;
	//! overlapping bin approach
        TH1* hMa_PULpt = nullptr;
	TH1* hMa_PUNLpt = nullptr;
	TH1* hMa_PUNNLpt = nullptr;
	TH1* hMa_PUNNNLpt = nullptr;
	TH1* hMa_PUNNNNLpt = nullptr;
	//! without binning
        TH1* hMb_PULpt = nullptr;
	TH1* hMb_PUNLpt = nullptr;
	TH1* hMb_PUNNLpt = nullptr;
	TH1* hMb_PUNNNLpt = nullptr;
	TH1* hMb_PUNNNNLpt = nullptr;
	//! Histograms for recording the eta distributions of the n leading pt jets 
        TH1* hbEta_PULpt = nullptr;
	TH1* hbEta_PUNLpt = nullptr;
	TH1* hbEta_PUNNLpt = nullptr;
	TH1* hbEta_PUNNNLpt = nullptr;
	TH1* hbEta_PUNNNNLpt = nullptr;

	//! Histograms of eta distributions of jets matched to b quarks sorted into increasing eta
	//! central to forward
	TH1* hbEta_NNNCEta = nullptr;
	TH1* hbEta_NNCEta = nullptr;
	TH1* hbEta_NCEta = nullptr;
	TH1* hbEta_CEta = nullptr;

	
private:
    //! delete the default copy constructor and assignment operator
    Rate_sumpt(const Rate_sumpt&) = delete;
    Rate_sumpt& operator=(const Rate_sumpt&) = delete;

};
#endif /*RATE_SUMPT_H_*/
