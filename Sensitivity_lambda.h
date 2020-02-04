#include <iostream>
#include <fstream>
#include <string>
#include<math.h>

#include "TROOT.h"
#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TLegend.h"
#include "TGraphErrors.h"
#include "TPostScript.h"
#include "TDirectory.h"
#include "TAxis.h"
#include "TGaxis.h"
#include "TF1.h"
#include "TLatex.h"

//! input root file
TFile *f = nullptr;
//const char *root_file_name = "./analysis_plots/root/GenJet4b2_2.5_allR0.4_0.8_incl4bProb.root";
const char *root_file_name = "./analysis_plots/root/GenJet4b2_2.5_allR0.4_0.8_incl4bProbMH30.root";

const char *txt_path = "./analysis_plots/txt_files";
const char *out_path = "./analysis_plots/pdf"; 
const char *output_file_name = "Sensitivity_studyVsk_lambda_corrected_incl4bProbMH30";
char out_root_file_name[1023];

TCanvas *c1 = nullptr;
char out_file_open[1023];
char out_file_[1023];
char out_file_close[1023];

const int nlambda = 6;
Double_t lambda[nlambda] = {-2.0, -1.0, 0.0, 1.0, 2.0, 3.0};
Float_t lambda_colors[nlambda] = {kGreen, kYellow-9, kBlack, kRed, kBlue, kViolet};
const int n = 10;
const int nGraphPts = 9;
Int_t nbinsMinus = n - 1; 
Double_t pt_bins[n] = {20., 30., 40., 50., 60., 70., 80., 90., 100., 500.};
//! 100TeV
const double IntLumi      = 3e4;//fb-1 
const double pp4bXsec     = 23.283e6;//fb 
const double ggFhhXsec1   = 12.24e2;//fb
const double ggFhhXsec0   = 2346.13;
const double ggFhhXsec_1  = 3995.26;
const double ggFhhXsec_2  = 6172.40;
const double ggFhhXsec2   = 625.59;
const double ggFhhXsec2_5 = 523.907;
const double ggFhhXsec3   = 553.485;
const double four_b_Prob  = std::pow(0.58,2);
int tot_MCevents = 5e5;

double norm_signal1, norm_signal0, norm_signal_1, norm_signal_2, norm_signal2, norm_signal2_5, norm_signal3;
double norm_bckgnd;
double nbins1, nbins0, nbins_1, nbins_2, nbins2, nbins2_5, nbins3, nbinsB;

Double_t pT_threshold[n] = {0};

Int_t   nAnaB[n]        = {0};

Int_t   nAna1[n]        = {0};
Int_t   nAna0[n]        = {0};
Int_t   nAna_1[n]       = {0};
Int_t   nAna_2[n]       = {0};
Int_t   nAna2[n]        = {0};
Int_t   nAna3[n]        = {0};


//! SoverB in the ith bin for different lambda values.
Double_t SoverB1[n]  = {0};
Double_t SoverB0[n]  = {0};
Double_t SoverB_1[n] = {0};
Double_t SoverB_2[n] = {0};
Double_t SoverB2[n]  = {0};
Double_t SoverB3[n]  = {0};

//! Significance in the ith bin for different lambda values.
double Significance1[n]  = {0};
double Significance0[n]  = {0};
double Significance_1[n] = {0};
double Significance_2[n] = {0};
double Significance2[n]  = {0};
double Significance3[n]  = {0};

//double vSignificance[nlambda][n] = {
//	Significance1,
//	Significance0,
//	Significance_1,
//	Significance_2,
//	Significance2,
//	Significance3
//
//};
//! Significance square in the ith bin for different lambda values.
Double_t Significance2_1[n]  = {0};
Double_t Significance2_0[n]  = {0};
Double_t Significance2__1[n] = {0};
Double_t Significance2__2[n] = {0};
Double_t Significance2_2[n]  = {0};
Double_t Significance2_3[n]  = {0};

//! Book histograms
TH1D *Ana_bjet4LPtB  = nullptr; 
TH1D *Ana_bjet4LPt1  = nullptr; 
TH1D *Ana_bjet4LPt0  = nullptr; 
TH1D *Ana_bjet4LPt_1 = nullptr; 
TH1D *Ana_bjet4LPt_2 = nullptr; 
TH1D *Ana_bjet4LPt2  = nullptr; 
TH1D *Ana_bjet4LPt3  = nullptr; 

TH1 *h4_bg      = nullptr;
TH1 *h4_sig1    = nullptr;
TH1 *h4_sig0    = nullptr;
TH1 *h4_sig_1   = nullptr;
TH1 *h4_sig_2   = nullptr;
TH1 *h4_sig2    = nullptr;
TH1 *h4_sig3    = nullptr;

TH1D *h4_SoverB1        = nullptr;
TH1D *h4_SoverB0        = nullptr;
TH1D *h4_SoverB_1       = nullptr;
TH1D *h4_SoverB_2       = nullptr;
TH1D *h4_SoverB2        = nullptr;
TH1D *h4_SoverB3        = nullptr;

TH1D *h4_Significance1   = nullptr;
TH1D *h4_Significance0   = nullptr;
TH1D *h4_Significance_1  = nullptr;
TH1D *h4_Significance_2  = nullptr;
TH1D *h4_Significance2   = nullptr;
TH1D *h4_Significance3   = nullptr;

TH1D *h4_Significance2_1   = nullptr;
TH1D *h4_Significance2_0   = nullptr;
TH1D *h4_Significance2__1  = nullptr;
TH1D *h4_Significance2__2  = nullptr;
TH1D *h4_Significance2_2   = nullptr;
TH1D *h4_Significance2_3   = nullptr;

//TMultiGraph *mg1 = nullptr;
//TMultiGraph *mg2 = nullptr;
//! Significance of the ith bin(pT threshold) Vs k_lambda
//TObjArray graphList(0);
//TString graph_name;
TGraph *g20  = nullptr;
TGraph *g30  = nullptr;
TGraph *g40  = nullptr;
TGraph *g50  = nullptr;
TGraph *g60  = nullptr;
TGraph *g70  = nullptr;
TGraph *g80  = nullptr;
TGraph *g90  = nullptr;
TGraph *g100 = nullptr;
////////////////////////////////////
Float_t LINE_WIDTH = 2.5;
Float_t TITLE_SIZE = 0.04;
Float_t MARKER_SIZE = 1.2;
Float_t AXISTITLE_OFFSET = 0.8;
Float_t YAXISTITLE_OFFSET = 1.2;
Float_t max_range;
Float_t min_range;
Float_t ENTRY_SEP = 0.05;
Float_t FILL_STYLE = 0;
Float_t BORDER_SIZE = 0;
Float_t TEXT_ALIGN = 32;
Float_t TEXT_ALIGN_1 = 12;
Float_t TEXT_FONT = 62;
Float_t TEXT_SIZE = 0.04;
Float_t Xl1 = 0.16, Yu1 = 0.6, Xl2 = 0.36, Yu2 = 0.89;
Float_t Xr1 = 0.65, Ym1 = 0.5, Xr2 = 0.85, Ym2 = 0.76;
