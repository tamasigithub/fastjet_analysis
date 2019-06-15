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
        //double Z0_cut = 1.5;//3;//1.5; //in mm
	//double tmppt , tmpz0;
	int nzvtxbin;
	double max_sumpt;
	int prim_bin;
	std::vector<double> v_sumpt;
	int nbins = 40;
	double ptmin = 0.0, ptmax = 1000;//in GeV/c 
	double Lpt, NLpt, NNLpt, NNNLpt, NNNNLpt;

public:
	Rate_sumpt(int bin):/*ptbins*/nzvtxbin(bin) 
	{
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
	void SetHist_props();
	void DrawNoBin();
	void DrawRate();
	void DrawSumpt();
	void WriteAll();
public:
	//! Book Histogram        
	//! sumpt histos
	TH1* h_PULpt = new TH1D("h_PULpt","Rate of highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	TH1* h_PUNLpt = new TH1D("h_PUNLpt","Rate of 2nd highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	TH1* h_PUNNLpt = new TH1D("h_PUNNLpt","Rate of 3rd highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	TH1* h_PUNNNLpt = new TH1D("h_PUNNNLpt","Rate of 4th highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	TH1* h_PUNNNNLpt = new TH1D("h_PUNNNNLpt","Rate Vs track jet P_{t} in <#mu> 960 , PB finding using sum pt",nbins,ptmin,ptmax);
	//! overlapping bin approach
        TH1* ha_PULpt = new TH1D("ha_PULpt","Rate of highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	TH1* ha_PUNLpt = new TH1D("ha_PUNLpt","Rate of 2nd highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	TH1* ha_PUNNLpt = new TH1D("ha_PUNNLpt","Rate of 3rd highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	TH1* ha_PUNNNLpt = new TH1D("ha_PUNNNLpt","Rate of 4th highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	TH1* ha_PUNNNNLpt = new TH1D("ha_PUNNNNLpt","Rate Vs track jet P_{t} in <#mu> 960 ",nbins,ptmin,ptmax);
	//! without binning
        TH1* hb_PULpt = new TH1D("hb_PULpt","Rate of highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	TH1* hb_PUNLpt = new TH1D("hb_PUNLpt","Rate of 2nd highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	TH1* hb_PUNNLpt = new TH1D("hb_PUNNLpt","Rate of 3rd highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	TH1* hb_PUNNNLpt = new TH1D("hb_PUNNNLpt","Rate of 4th highest Pt track jet in <#mu> 960 ",nbins,ptmin,ptmax);
	TH1* hb_PUNNNNLpt = new TH1D("hb_PUNNNNLpt","Rate Vs track jet P_{t} in <#mu> 960 , without binning along beam axis",nbins,ptmin,ptmax);
	
private:
    //! delete the default copy constructor and assignment operator
    Rate_sumpt(const Rate_sumpt&) = delete;
    Rate_sumpt& operator=(const Rate_sumpt&) = delete;

};
#endif /*RATE_SUMPT_H_*/
