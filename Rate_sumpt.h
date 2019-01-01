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
	int nbins = 20;
	double ptmin = 0.0, ptmax = 100000.0;//0 to 100 GeV/c
	//! Book Histogram
        TH1* h_PULpt = new TH1D("h_PULpt","Rate of highest Pt track in PU 200",nbins,ptmin,ptmax);
	TH1* h_PUNLpt = new TH1D("h_PUNLpt","Rate of 2nd highest Pt track in PU 200",nbins,ptmin,ptmax);
	TH1* h_PUNNLpt = new TH1D("h_PUNNLpt","Rate of 3rd highest Pt track in PU 200",nbins,ptmin,ptmax);
	TH1* h_PUNNNLpt = new TH1D("h_PUNNNLpt","Rate of 4th highest Pt track in PU 200",nbins,ptmin,ptmax);
	TH1* h_PUNNNNLpt = new TH1D("h_PUNNNNLpt","Rate Vs track P_{t} in PU 160, PB finding using sum pt",nbins,ptmin,ptmax);

public:
	Rate_sumpt(int nzbin):nzvtxbin(nzbin)
	{
		//std::vector<double> v_sumpt(nzvtxbin,0.0);
		v_sumpt.resize(nzvtxbin,0.0);
	}
	~Rate_sumpt(){}
	void SetHist_props();
	void DrawAll();
	void WriteAll();
};
#endif /*RATE_SUMPT_H_*/
