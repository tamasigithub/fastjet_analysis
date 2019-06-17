/*!
 *  \file
 *  \brief Class to plot trigger efficiency as a function of the TTT track-jet pt threshold
 *  //! for n leading jets passing the pt threshold defined by the pt bins
 */
#ifndef TRIGEFF_H_
#define TRIGEFF_H_

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

class TrigEff
{
public:
	const int Njet_max = 5;
	const float eta_cut = 1.6; 
	static const int nbins_plus1 = 31;
	static const  int nbins = 30;// = (pt_max - pt_min)/ptcut_width;
	float pt_min, pt_max, ptcut_width;
    	float xbins[nbins_plus1];
	bool debug = true;

public:
	TrigEff(float ptMin, float ptMax, float ptcutWidth):pt_min(ptMin), pt_max(ptMax), ptcut_width(ptcutWidth) 
	{
		for(int i = 0; i <= nbins; i++)
		{
			xbins[i] = pt_min + i*ptcut_width;
			//std::cout<< "xbin[ " << i << "] : " <<xbins[i] <<std::endl; 
		}
		
	}
	~TrigEff(){}
	//constexpr int nBins()
	//{
    	//	return (pt_max - pt_min)/ptcut_width +1;
	//	//return nbins;
	//}

	void init(float xbins[], int nbins);
		
	void SetHist_props();
	void Fill_TrigEff();
	void DrawNoBin();
	//void DrawRate();
	//void DrawSumpt();
	void WriteAll();
public:
	////! Book Histogram        
	//TH1::SetDefaultSumw2(true);
	//TH1* h_tJeff2 = new TH1F("h_tJeff2"," Track Jet efficiency", nbins, pt_min, pt_max);
	//TH1* h_tJeff3 = new TH1F("h_tJeff3"," Track Jet efficiency", nbins, pt_min, pt_max);
	//TH1* h_tJeff4 = new TH1F("h_tJeff4"," Track Jet efficiency", nbins, pt_min, pt_max);
	//TH1* h_tJeff5 = new TH1F("h_tJeff5"," Track Jet efficiency", nbins, pt_min, pt_max);
	TH1* h_tJeff2 = nullptr;
	TH1* h_tJeff3 = nullptr;
	TH1* h_tJeff4 = nullptr;
	TH1* h_tJeff5 = nullptr;

	//! define local parameters to fill the histograms
	//! total number of events with atleast n trackjets having pt greater than the threshold defined by the pt bins(xbins)
	int n2_tot[nbins] = {0};
	int n3_tot[nbins] = {0};
	int n4_tot[nbins] = {0};
	int n5_tot[nbins] = {0};
	////! sumpt histos
	//TH1* h_PULpt = new TH1D("h_PULpt","Rate of highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	//TH1* h_PUNLpt = new TH1D("h_PUNLpt","Rate of 2nd highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	//TH1* h_PUNNLpt = new TH1D("h_PUNNLpt","Rate of 3rd highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	//TH1* h_PUNNNLpt = new TH1D("h_PUNNNLpt","Rate of 4th highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	//TH1* h_PUNNNNLpt = new TH1D("h_PUNNNNLpt","Rate Vs track jet P_{t} in <#mu> 960 , PB finding using sum pt",nbins,ptmin,ptmax);
	////! overlapping bin approach
        //TH1* ha_PULpt = new TH1D("ha_PULpt","Rate of highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	//TH1* ha_PUNLpt = new TH1D("ha_PUNLpt","Rate of 2nd highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	//TH1* ha_PUNNLpt = new TH1D("ha_PUNNLpt","Rate of 3rd highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	//TH1* ha_PUNNNLpt = new TH1D("ha_PUNNNLpt","Rate of 4th highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	//TH1* ha_PUNNNNLpt = new TH1D("ha_PUNNNNLpt","Rate Vs track jet P_{t} in <#mu> 960 ",nbins,ptmin,ptmax);
	////! without binning
        //TH1* hb_PULpt = new TH1D("hb_PULpt","Rate of highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	//TH1* hb_PUNLpt = new TH1D("hb_PUNLpt","Rate of 2nd highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	//TH1* hb_PUNNLpt = new TH1D("hb_PUNNLpt","Rate of 3rd highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	//TH1* hb_PUNNNLpt = new TH1D("hb_PUNNNLpt","Rate of 4th highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	//TH1* hb_PUNNNNLpt = new TH1D("hb_PUNNNNLpt","Rate Vs track jet P_{t} in <#mu> 960 , without binning along beam axis",nbins,ptmin,ptmax);
	
private:

    //! delete the default copy constructor and assignment operator
    TrigEff(const TrigEff&) = delete;
    TrigEff& operator=(const TrigEff&) = delete;

};
#endif /*TRIGEFF_H_*/
