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
#include "TRandom.h"
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
	const float eta_cut = 2.5; 
	static const int nbins_plus1 = 401;//101;
	static const  int nbins = 400;//100;// = (pt_max - pt_min)/ptcut_width;
	//static const int nbins_plus1 = 116;
	//static const  int nbins = 115;// = (pt_max - pt_min)/ptcut_width;
	//const int Nlowpt_bins = 80;
	float pt_min, pt_max, ptcut_width;
    	float xbins[nbins_plus1];
	bool debug = true;

public:
	TrigEff(float ptMin, float ptMax, float ptcutWidth):pt_min(ptMin), pt_max(ptMax), ptcut_width(ptcutWidth) 
	{
		for(int i = 0; i <= nbins; i++)
		{
			if(i==0) xbins[i] = pt_min;
			xbins[i] = xbins[0] + i*ptcut_width;
			////
			//////std::cout<< "xbin[ " << i << "] : " <<xbins[i] <<std::endl;
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
	void DrawOvpbin();
	void DrawSumpt();
	void WriteAll();
	void WriteNoBin();
public:
	////! Book Histogram
	//! sumpt histos        
	TH1* h_tJeff2 = nullptr;
	TH1* h_tJeff3 = nullptr;
	TH1* h_tJeff4 = nullptr;
	TH1* h_tJeff5 = nullptr;
	//! overlapping bin approach 
	TH1* ha_tJeff2 = nullptr;
	TH1* ha_tJeff3 = nullptr;
	TH1* ha_tJeff4 = nullptr;
	TH1* ha_tJeff5 = nullptr;
	//! without binning approach 
	TH1* hb_tJeff2 = nullptr;
	TH1* hb_tJeff3 = nullptr;
	TH1* hb_tJeff4 = nullptr;
	TH1* hb_tJeff5 = nullptr;

	//! define local parameters to fill the histograms
	//! total number of events with atleast n trackjets having pt greater than the threshold defined by the pt bins(xbins)
	//! sumpt bin finding approach
	int n2_tot[nbins] = {0};
	int n3_tot[nbins] = {0};
	int n4_tot[nbins] = {0};
	int n5_tot[nbins] = {0};
	//! overlapping bin approach
	int n2a_tot[nbins] = {0};
	int n3a_tot[nbins] = {0};
	int n4a_tot[nbins] = {0};
	int n5a_tot[nbins] = {0};
	//! no binning approach
	int n2b_tot[nbins] = {0};
	int n3b_tot[nbins] = {0};
	int n4b_tot[nbins] = {0};
	int n5b_tot[nbins] = {0};
	
private:

    //! delete the default copy constructor and assignment operator
    TrigEff(const TrigEff&) = delete;
    TrigEff& operator=(const TrigEff&) = delete;

};
#endif /*TRIGEFF_H_*/
