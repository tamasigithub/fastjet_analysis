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

double max_rangeM=0;
double max_rangePt=0;

const int min_Njets = 4;
const double default_Pt_cut  = 20.0;//GeV 
const double third_Pt_cut    = 35.0;//GeV 
const double minSubLeadingPt = 40.0;//GeV
const double minLeadingPt    = 55.0;//GeV
const double HiggsMass       = 125.0;//GeV
const double MassWidth       = 60.0;//GeV
//! 100TeV
const double IntLumi      = 3e4;//fb-1 -> 10 ab-1(projected luminosity is 30 ab-1 not 10 ab-1)
const double four_b_Prob  = std::pow(0.58,2);
const double pp4bXsec     = 23.283e6;//fb, NLO Xsection// k-factor 1.6// LO 14.552e6 +- 12.16e3 
const double ggFhhXsec1   = 12.24e2 * four_b_Prob;//fb, latest available NNLO Xsection, arXiv:1803.02463v1
const double ggFhhXsec0   = 2346.13 * four_b_Prob;
const double ggFhhXsec_1  = 3995.26 * four_b_Prob;
const double ggFhhXsec_2  = 6172.40 * four_b_Prob;
const double ggFhhXsec2   = 625.59 * four_b_Prob;
const double ggFhhXsec2_5 = 523.907 * four_b_Prob;
const double ggFhhXsec3   = 553.485 * four_b_Prob;
////! 14TeV
//const double IntLumi      = 3e3;//fb-1 -> 0.3 ab-1
//const double pp4bXsec     = 15.696e5;//fb, NLO Xsection// k-factor 1.6?// LO 9.81e5
//const double ggFhhXsec1   = 36.69 * four_b_Prob;//fb, latest available NNLO Xsection, arXiv:1803.02463v1
//const double ggFhhXsec0   = 75.867 * four_b_Prob;
//const double ggFhhXsec_1  = 135.046 * four_b_Prob;
//const double ggFhhXsec_2  = 214.181 * four_b_Prob;
//const double ggFhhXsec2   = 17.4765 * four_b_Prob;
//const double ggFhhXsec2_5 = 15.3792 * four_b_Prob;
//const double ggFhhXsec3   = 18.2744 * four_b_Prob;

double k_lambda[7] = {-2.0, -1.0, 0.0, 1.0, 2.0, 2.5, 3.0};

double Xsec_OG[7] = {ggFhhXsec_2, ggFhhXsec_1, ggFhhXsec0, ggFhhXsec1, ggFhhXsec2, ggFhhXsec2_5, ggFhhXsec3};

const char *root_out_name = "./analysis_plots/root/GenJet4b2_2.5_allR0.4_0.8_incl4bProbMH30_1.root";
const char *out_path = "./analysis_plots/pdf"; 
const char *output_file_name = "GenJet4b2_2.5_allR0.4_0.8_incl4bProbMH30_2";

//const char *inp_file1  = "./fastjet_output/80percentBtag/Genjet2_ggF_Ctr1.0_q300MeV_6.0_allR0.4.root"; 
//const char *inp_file0  = "./fastjet_output/80percentBtag/Genjet2_ggF_Ctr0.0_q300MeV_6.0_allR0.4.root"; 
//const char *inp_file_1 = "./fastjet_output/80percentBtag/Genjet2_ggF_Ctr-1.0_q300MeV_6.0_allR0.4.root"; 
//const char *inp_file_2 = "./fastjet_output/80percentBtag/Genjet2_ggF_Ctr-2.0_q300MeV_6.0_allR0.4.root"; 
//const char *inp_file2  = "./fastjet_output/80percentBtag/Genjet2_ggF_Ctr2.0_q300MeV_6.0_allR0.4.root"; 
//const char *inp_file2_5= "./fastjet_output/80percentBtag/Genjet2_ggF_Ctr2.5_q300MeV_6.0_allR0.4.root"; 
//const char *inp_file3  = "./fastjet_output/80percentBtag/Genjet2_ggF_Ctr3.0_q300MeV_6.0_allR0.4.root"; 
//const char *inp_fileB  = "./fastjet_output/80percentBtag/Genjet2_pp4b_q300MeV_6.0_allR0.4.root"; 
//const char *inp_fileB_1  = "./fastjet_output/80percentBtag/Genjet2_pp4b_q300MeV_6.0_allR0.4_0.8btag_1.root"; 

const char *inp_file1  = "./fastjet_output/Genjet2_ggF_Ctr1.0_q300MeV_2.5_allR0.4_0.8btag.root"; 
const char *inp_file0  = "./fastjet_output/Genjet2_ggF_Ctr0.0_q300MeV_2.5_allR0.4_0.8btag.root"; 
const char *inp_file_1 = "./fastjet_output/Genjet2_ggF_Ctr-1.0_q300MeV_2.5_allR0.4_0.8btag.root"; 
const char *inp_file_2 = "./fastjet_output/Genjet2_ggF_Ctr-2.0_q300MeV_2.5_allR0.4_0.8btag.root"; 
const char *inp_file2  = "./fastjet_output/Genjet2_ggF_Ctr2.0_q300MeV_2.5_allR0.4_0.8btag.root"; 
const char *inp_file2_5= "./fastjet_output/Genjet2_ggF_Ctr2.5_q300MeV_2.5_allR0.4_0.8btag.root"; 
const char *inp_file3  = "./fastjet_output/Genjet2_ggF_Ctr3.0_q300MeV_2.5_allR0.4_0.8btag.root"; 
const char *inp_fileB  = "./fastjet_output/Genjet2_pp4b_q300MeV_2.5_allR0.4_0.8btag.root"; 
const char *inp_fileB_1  = "./fastjet_output/Genjet2_pp4b_q300MeV_2.5_allR0.4_0.8btag_1.root"; 

////!14TeV
//const char *inp_file1  = "./fastjet_output/80percentBtag/Genjet2_ggF14TeV_Ctr1.0_q300MeV_2.5_allR0.4.root"; 
//const char *inp_file0  = "./fastjet_output/80percentBtag/Genjet2_ggF14TeV_Ctr0.0_q300MeV_2.5_allR0.4.root"; 
//const char *inp_file_1 = "./fastjet_output/80percentBtag/Genjet2_ggF14TeV_Ctr-1.0_q300MeV_2.5_allR0.4.root"; 
//const char *inp_file_2 = "./fastjet_output/80percentBtag/Genjet2_ggF14TeV_Ctr-2.0_q300MeV_2.5_allR0.4.root"; 
//const char *inp_file2  = "./fastjet_output/80percentBtag/Genjet2_ggF14TeV_Ctr2.0_q300MeV_2.5_allR0.4.root"; 
//const char *inp_file2_5= "./fastjet_output/80percentBtag/Genjet2_ggF14TeV_Ctr2.5_q300MeV_2.5_allR0.4.root"; 
//const char *inp_file3  = "./fastjet_output/80percentBtag/Genjet2_ggF14TeV_Ctr3.0_q300MeV_2.5_allR0.4.root"; 
//const char *inp_fileB  = "./fastjet_output/80percentBtag/Genjet2_pp4b14TeV_q300MeV_2.5_allR0.4.root"; 

TFile *f1  = nullptr;
TFile *f0  = nullptr;
TFile *f_1 = nullptr;
TFile *f_2 = nullptr;
TFile *f2  = nullptr;
TFile *f2_5= nullptr;
TFile *f3  = nullptr;
TFile *fB  = nullptr;
TFile *fB_1  = nullptr;

//TTree
TTree *t1  = nullptr;
TTree *t0  = nullptr;
TTree *t_1 = nullptr;
TTree *t_2 = nullptr;
TTree *t2  = nullptr;
TTree *t2_5= nullptr;
TTree *t3  = nullptr;
//TTree *tB  = nullptr;
TChain tB("glob_jet");


std::vector<double> *v1_higgsPt  = nullptr;
std::vector<double> *v1_higgsEta = nullptr;
std::vector<double> *v1_higgsPhi = nullptr;
std::vector<double> *v1_higgsM   = nullptr;

std::vector<double> *v0_higgsPt  = nullptr;
std::vector<double> *v0_higgsEta = nullptr;
std::vector<double> *v0_higgsPhi = nullptr;
std::vector<double> *v0_higgsM   = nullptr;

std::vector<double> *v_1_higgsPt  = nullptr;
std::vector<double> *v_1_higgsEta = nullptr;
std::vector<double> *v_1_higgsPhi = nullptr;
std::vector<double> *v_1_higgsM   = nullptr;

std::vector<double> *v_2_higgsPt  = nullptr;
std::vector<double> *v_2_higgsEta = nullptr;
std::vector<double> *v_2_higgsPhi = nullptr;
std::vector<double> *v_2_higgsM   = nullptr;

std::vector<double> *v2_higgsPt  = nullptr;
std::vector<double> *v2_higgsEta = nullptr;
std::vector<double> *v2_higgsPhi = nullptr;
std::vector<double> *v2_higgsM   = nullptr;

std::vector<double> *v2_5_higgsPt  = nullptr;
std::vector<double> *v2_5_higgsEta = nullptr;
std::vector<double> *v2_5_higgsPhi = nullptr;
std::vector<double> *v2_5_higgsM   = nullptr;

std::vector<double> *v3_higgsPt  = nullptr;
std::vector<double> *v3_higgsEta = nullptr;
std::vector<double> *v3_higgsPhi = nullptr;
std::vector<double> *v3_higgsM   = nullptr;

TLorentzVector higgs1_1, higgs2_1, H1H2_1;
TLorentzVector higgs1_0, higgs2_0, H1H2_0;
TLorentzVector higgs1__1, higgs2__1, H1H2__1;
TLorentzVector higgs1__2, higgs2__2, H1H2__2;
TLorentzVector higgs1_2, higgs2_2, H1H2_2;
TLorentzVector higgs1_2_5, higgs2_2_5, H1H2_2_5;
TLorentzVector higgs1_3, higgs2_3, H1H2_3; 

std::vector<double> *v1_bPt  = nullptr;
std::vector<double> *v1_bEta = nullptr;
std::vector<double> *v1_bPhi = nullptr;
std::vector<double> *v1_bM   = nullptr;

std::vector<double> *v0_bPt  = nullptr;
std::vector<double> *v0_bEta = nullptr;
std::vector<double> *v0_bPhi = nullptr;
std::vector<double> *v0_bM   = nullptr;

std::vector<double> *v_1_bPt  = nullptr;
std::vector<double> *v_1_bEta = nullptr;
std::vector<double> *v_1_bPhi = nullptr;
std::vector<double> *v_1_bM   = nullptr;

std::vector<double> *v_2_bPt  = nullptr;
std::vector<double> *v_2_bEta = nullptr;
std::vector<double> *v_2_bPhi = nullptr;
std::vector<double> *v_2_bM   = nullptr;

std::vector<double> *v2_bPt  = nullptr;
std::vector<double> *v2_bEta = nullptr;
std::vector<double> *v2_bPhi = nullptr;
std::vector<double> *v2_bM   = nullptr;

std::vector<double> *v2_5_bPt  = nullptr;
std::vector<double> *v2_5_bEta = nullptr;
std::vector<double> *v2_5_bPhi = nullptr;
std::vector<double> *v2_5_bM   = nullptr;

std::vector<double> *v3_bPt  = nullptr;
std::vector<double> *v3_bEta = nullptr;
std::vector<double> *v3_bPhi = nullptr;
std::vector<double> *v3_bM   = nullptr;

std::vector<double> *vB_bPt  = nullptr;
std::vector<double> *vB_bEta = nullptr;
std::vector<double> *vB_bPhi = nullptr;
std::vector<double> *vB_bM   = nullptr;

TLorentzVector b1_1, b2_1, b3_1, b4_1;
TLorentzVector b1b2_1, b1b3_1, b1b4_1, b2b3_1, b2b4_1, b3b4_1;
TLorentzVector b1_0, b2_0, b3_0, b4_0;
TLorentzVector b1b2_0, b1b3_0, b1b4_0, b2b3_0, b2b4_0, b3b4_0;
TLorentzVector b1__1, b2__1, b3__1, b4__1;
TLorentzVector b1b2__1, b1b3__1, b1b4__1, b2b3__1, b2b4__1, b3b4__1;
TLorentzVector b1__2, b2__2, b3__2, b4__2;
TLorentzVector b1b2__2, b1b3__2, b1b4__2, b2b3__2, b2b4__2, b3b4__2;
TLorentzVector b1_2, b2_2, b3_2, b4_2;
TLorentzVector b1b2_2, b1b3_2, b1b4_2, b2b3_2, b2b4_2, b3b4_2;
TLorentzVector b1_2_5, b2_2_5, b3_2_5, b4_2_5;
TLorentzVector b1b2_2_5, b1b3_2_5, b1b4_2_5, b2b3_2_5, b2b4_2_5, b3b4_2_5;
TLorentzVector b1_3, b2_3, b3_3, b4_3;
TLorentzVector b1b2_3, b1b3_3, b1b4_3, b2b3_3, b2b4_3, b3b4_3;

TLorentzVector b1_B, b2_B, b3_B, b4_B;
TLorentzVector b1b2_B, b1b3_B, b1b4_B, b2b3_B, b2b4_B, b3b4_B;

TH1D *Mb1b2_1 = nullptr; 
TH1D *Mb1b3_1 = nullptr;
TH1D *Mb1b4_1 = nullptr;
TH1D *Mb2b3_1 = nullptr;
TH1D *Mb2b4_1 = nullptr;
TH1D *Mb3b4_1 = nullptr;

TH1D *Mb1b2_0 = nullptr; 
TH1D *Mb1b3_0 = nullptr;
TH1D *Mb1b4_0 = nullptr;
TH1D *Mb2b3_0 = nullptr;
TH1D *Mb2b4_0 = nullptr;
TH1D *Mb3b4_0 = nullptr;

TH1D *Mb1b2__1 = nullptr; 
TH1D *Mb1b3__1 = nullptr;
TH1D *Mb1b4__1 = nullptr;
TH1D *Mb2b3__1 = nullptr;
TH1D *Mb2b4__1 = nullptr;
TH1D *Mb3b4__1 = nullptr;

TH1D *Mb1b2__2 = nullptr; 
TH1D *Mb1b3__2 = nullptr;
TH1D *Mb1b4__2 = nullptr;
TH1D *Mb2b3__2 = nullptr;
TH1D *Mb2b4__2 = nullptr;
TH1D *Mb3b4__2 = nullptr;

TH1D *Mb1b2_2 = nullptr; 
TH1D *Mb1b3_2 = nullptr;
TH1D *Mb1b4_2 = nullptr;
TH1D *Mb2b3_2 = nullptr;
TH1D *Mb2b4_2 = nullptr;
TH1D *Mb3b4_2 = nullptr;

TH1D *Mb1b2_2_5 = nullptr; 
TH1D *Mb1b3_2_5 = nullptr;
TH1D *Mb1b4_2_5 = nullptr;
TH1D *Mb2b3_2_5 = nullptr;
TH1D *Mb2b4_2_5 = nullptr;
TH1D *Mb3b4_2_5 = nullptr;

TH1D *Mb1b2_3 = nullptr; 
TH1D *Mb1b3_3 = nullptr;
TH1D *Mb1b4_3 = nullptr;
TH1D *Mb2b3_3 = nullptr;
TH1D *Mb2b4_3 = nullptr;
TH1D *Mb3b4_3 = nullptr;

TH1D *Mb1b2_B = nullptr; 
TH1D *Mb1b3_B = nullptr;
TH1D *Mb1b4_B = nullptr;
TH1D *Mb2b3_B = nullptr;
TH1D *Mb2b4_B = nullptr;
TH1D *Mb3b4_B = nullptr;

//! Reconstructed objects
TLorentzVector bJ1_1, bJ2_1, bJ3_1, bJ4_1;
TLorentzVector bJ1bJ2_1, bJ1bJ3_1, bJ1bJ4_1, bJ2bJ3_1, bJ2bJ4_1, bJ3bJ4_1;
TLorentzVector bJ1_0, bJ2_0, bJ3_0, bJ4_0;
TLorentzVector bJ1bJ2_0, bJ1bJ3_0, bJ1bJ4_0, bJ2bJ3_0, bJ2bJ4_0, bJ3bJ4_0;
TLorentzVector bJ1__1, bJ2__1, bJ3__1, bJ4__1;
TLorentzVector bJ1bJ2__1, bJ1bJ3__1, bJ1bJ4__1, bJ2bJ3__1, bJ2bJ4__1, bJ3bJ4__1;
TLorentzVector bJ1__2, bJ2__2, bJ3__2, bJ4__2;
TLorentzVector bJ1bJ2__2, bJ1bJ3__2, bJ1bJ4__2, bJ2bJ3__2, bJ2bJ4__2, bJ3bJ4__2;
TLorentzVector bJ1_2, bJ2_2, bJ3_2, bJ4_2;
TLorentzVector bJ1bJ2_2, bJ1bJ3_2, bJ1bJ4_2, bJ2bJ3_2, bJ2bJ4_2, bJ3bJ4_2;
TLorentzVector bJ1_2_5, bJ2_2_5, bJ3_2_5, bJ4_2_5;
TLorentzVector bJ1bJ2_2_5, bJ1bJ3_2_5, bJ1bJ4_2_5, bJ2bJ3_2_5, bJ2bJ4_2_5, bJ3bJ4_2_5;
TLorentzVector bJ1_3, bJ2_3, bJ3_3, bJ4_3;
TLorentzVector bJ1bJ2_3, bJ1bJ3_3, bJ1bJ4_3, bJ2bJ3_3, bJ2bJ4_3, bJ3bJ4_3;
TLorentzVector RecH1H2_1;
TLorentzVector RecH1H2_0;
TLorentzVector RecH1H2__1;
TLorentzVector RecH1H2__2;
TLorentzVector RecH1H2_2;
TLorentzVector RecH1H2_2_5;
TLorentzVector RecH1H2_3;

TLorentzVector bJ1_B, bJ2_B, bJ3_B, bJ4_B;
TLorentzVector bJ1bJ2_B, bJ1bJ3_B, bJ1bJ4_B, bJ2bJ3_B, bJ2bJ4_B, bJ3bJ4_B;
TLorentzVector RecH1H2_B;

//! Get bjetPt in locally defined std::vector
std::vector<double> v1_bjetPt;
std::vector<double> v0_bjetPt;
std::vector<double> v_1_bjetPt;
std::vector<double> v_2_bjetPt;
std::vector<double> v2_bjetPt;
std::vector<double> v2_5_bjetPt;
std::vector<double> v3_bjetPt;
std::vector<double> vB_bjetPt;
//! Get bjetEta in locally defined std::vector
std::vector<double> v1_bjetEta;
std::vector<double> v0_bjetEta;
std::vector<double> v_1_bjetEta;
std::vector<double> v_2_bjetEta;
std::vector<double> v2_bjetEta;
std::vector<double> v2_5_bjetEta;
std::vector<double> v3_bjetEta;
std::vector<double> vB_bjetEta;
//! Get bjetPhi in locally defined std::vector
std::vector<double> v1_bjetPhi;
std::vector<double> v0_bjetPhi;
std::vector<double> v_1_bjetPhi;
std::vector<double> v_2_bjetPhi;
std::vector<double> v2_bjetPhi;
std::vector<double> v2_5_bjetPhi;
std::vector<double> v3_bjetPhi;
std::vector<double> vB_bjetPhi;
//! Get bjetMt2 in locally defined std::vector
std::vector<double> v1_bjetM;
std::vector<double> v0_bjetM;
std::vector<double> v_1_bjetM;
std::vector<double> v_2_bjetM;
std::vector<double> v2_bjetM;
std::vector<double> v2_5_bjetM;
std::vector<double> v3_bjetM;
std::vector<double> vB_bjetM;
//! Get invariant mass of combinations of bjets  in locally defined std::vector
////! there are 4 bjets in an event => 6 combination of 2 bjets are possible
//std::vector<double> v1_bibjM;
//std::vector<double> v0_bibjM;
//std::vector<double> v_1_bibjM;
//std::vector<double> v_2_bibjM;
//std::vector<double> v2_bibjM;
//std::vector<double> v2_5_bibjM;
//std::vector<double> v3_bibjM;
//std::vector<double> vB_bibjM;
//! Get jetM in locally defined std::vector
std::vector<double> *v1_jetM = nullptr;
std::vector<double> *v0_jetM = nullptr;
std::vector<double> *v_1_jetM = nullptr;
std::vector<double> *v_2_jetM = nullptr;
std::vector<double> *v2_jetM = nullptr;
std::vector<double> *v2_5_jetM = nullptr;
std::vector<double> *v3_jetM = nullptr;
std::vector<double> *vB_jetM = nullptr;
//! Get jetPt in locally defined std::vector
std::vector<double> *v1_jetPt = nullptr;
std::vector<double> *v0_jetPt = nullptr;
std::vector<double> *v_1_jetPt = nullptr;
std::vector<double> *v_2_jetPt = nullptr;
std::vector<double> *v2_jetPt = nullptr;
std::vector<double> *v2_5_jetPt = nullptr;
std::vector<double> *v3_jetPt = nullptr;
std::vector<double> *vB_jetPt = nullptr;
//! Get jetPhi in locally defined std::vector
std::vector<double> *v1_jetPhi = nullptr;
std::vector<double> *v0_jetPhi = nullptr;
std::vector<double> *v_1_jetPhi = nullptr;
std::vector<double> *v_2_jetPhi = nullptr;
std::vector<double> *v2_jetPhi = nullptr;
std::vector<double> *v2_5_jetPhi = nullptr;
std::vector<double> *v3_jetPhi = nullptr;
std::vector<double> *vB_jetPhi = nullptr;
//! Get jetEta in locally defined std::vector
std::vector<double> *v1_jetEta = nullptr;
std::vector<double> *v0_jetEta = nullptr;
std::vector<double> *v_1_jetEta = nullptr;
std::vector<double> *v_2_jetEta = nullptr;
std::vector<double> *v2_jetEta = nullptr;
std::vector<double> *v2_5_jetEta = nullptr;
std::vector<double> *v3_jetEta = nullptr;
std::vector<double> *vB_jetEta = nullptr;
//! Get tagged flavor of the jets in locally defined std::vector
std::vector<int> *v1_tagFlavor = nullptr;
std::vector<int> *v0_tagFlavor = nullptr;
std::vector<int> *v_1_tagFlavor = nullptr;
std::vector<int> *v_2_tagFlavor = nullptr;
std::vector<int> *v2_tagFlavor = nullptr;
std::vector<int> *v2_5_tagFlavor = nullptr;
std::vector<int> *v3_tagFlavor = nullptr;
std::vector<int> *vB_tagFlavor = nullptr;
//! Get number of b-tags in an event.
int n1_btags = 0;
int n0_btags = 0;
int n_1_btags = 0;
int n_2_btags = 0;
int n2_btags = 0;
int n2_5_btags = 0;
int n3_btags = 0;
int nB_btags = 0;

//Number of b tags
TH1D *h_NbTags1  = nullptr;
TH1D *h_NbTags0  = nullptr;
TH1D *h_NbTags_1 = nullptr;
TH1D *h_NbTags_2 = nullptr;
TH1D *h_NbTags2  = nullptr;
TH1D *h_NbTags2_5= nullptr;
TH1D *h_NbTags3  = nullptr;
TH1D *h_NbTagsB  = nullptr;
//Number of SMhiggs 
TH1D *NSMhiggs1  = nullptr;
TH1D *NSMhiggs0  = nullptr;
TH1D *NSMhiggs_1 = nullptr;
TH1D *NSMhiggs_2 = nullptr;
TH1D *NSMhiggs2  = nullptr;
TH1D *NSMhiggs2_5= nullptr;
TH1D *NSMhiggs3  = nullptr;
//Number of bquarks 
TH1D *Nbquarks1  = nullptr;
TH1D *Nbquarks0  = nullptr;
TH1D *Nbquarks_1 = nullptr;
TH1D *Nbquarks_2 = nullptr;
TH1D *Nbquarks2  = nullptr;
TH1D *Nbquarks2_5= nullptr;
TH1D *Nbquarks3  = nullptr;
TH1D *NbquarksB  = nullptr;
//Number of jets 
TH1D *Njets1  = nullptr;
TH1D *Njets0  = nullptr;
TH1D *Njets_1 = nullptr;
TH1D *Njets_2 = nullptr;
TH1D *Njets2  = nullptr;
TH1D *Njets2_5= nullptr;
TH1D *Njets3  = nullptr;
TH1D *NjetsB  = nullptr;
//! Book histograms:
// truth Higgs Pt
TH1 *higgsPt1  = nullptr;
TH1 *higgsPt0  = nullptr;
TH1 *higgsPt_1 = nullptr;
TH1 *higgsPt_2 = nullptr;
TH1 *higgsPt2  = nullptr;
TH1 *higgsPt2_5= nullptr;
TH1 *higgsPt3  = nullptr;
//truth Higgs sub leading Pt
TH1 *higgsNLPt1  = nullptr;
TH1 *higgsNLPt0  = nullptr;
TH1 *higgsNLPt_1 = nullptr;
TH1 *higgsNLPt_2 = nullptr;
TH1 *higgsNLPt2  = nullptr;
TH1 *higgsNLPt2_5= nullptr;
TH1 *higgsNLPt3  = nullptr;
// truth leading Higgs mass
TH1 *higgsL_M1  = nullptr;
TH1 *higgsL_M0  = nullptr;
TH1 *higgsL_M_1 = nullptr;
TH1 *higgsL_M_2 = nullptr;
TH1 *higgsL_M2  = nullptr;
TH1 *higgsL_M2_5= nullptr;
TH1 *higgsL_M3  = nullptr;
//truth sub leading Higgs mass
TH1 *higgsNL_M1  = nullptr;
TH1 *higgsNL_M0  = nullptr;
TH1 *higgsNL_M_1 = nullptr;
TH1 *higgsNL_M_2 = nullptr;
TH1 *higgsNL_M2  = nullptr;
TH1 *higgsNL_M2_5= nullptr;
TH1 *higgsNL_M3  = nullptr;
//truth inv mass of di-higgs system
TH1D *MH1H2_1 = nullptr; 
TH1D *MH1H2_0 = nullptr; 
TH1D *MH1H2__1 = nullptr; 
TH1D *MH1H2__2 = nullptr; 
TH1D *MH1H2_2 = nullptr; 
TH1D *MH1H2_2_5 = nullptr; 
TH1D *MH1H2_3 = nullptr; 
// truth pt of di-higgs system
TH1D *PtH1H2_1 = nullptr; 
TH1D *PtH1H2_0 = nullptr; 
TH1D *PtH1H2__1 = nullptr; 
TH1D *PtH1H2__2 = nullptr; 
TH1D *PtH1H2_2 = nullptr; 
TH1D *PtH1H2_2_5 = nullptr; 
TH1D *PtH1H2_3 = nullptr;

//recconstructed pt of the leading higgs
TH1D *Pt_Lhiggs1   = nullptr;
TH1D *Pt_Lhiggs0   = nullptr;
TH1D *Pt_Lhiggs_1  = nullptr;
TH1D *Pt_Lhiggs_2  = nullptr;
TH1D *Pt_Lhiggs2   = nullptr;
TH1D *Pt_Lhiggs2_5 = nullptr;
TH1D *Pt_Lhiggs3   = nullptr;
TH1D *Pt_LhiggsB   = nullptr;
//recconstructed pt of the sub-leading higgs
TH1D *Pt_NLhiggs1   = nullptr;
TH1D *Pt_NLhiggs0   = nullptr;
TH1D *Pt_NLhiggs_1  = nullptr;
TH1D *Pt_NLhiggs_2  = nullptr;
TH1D *Pt_NLhiggs2   = nullptr;
TH1D *Pt_NLhiggs2_5 = nullptr;
TH1D *Pt_NLhiggs3   = nullptr;
TH1D *Pt_NLhiggsB   = nullptr;
//recconstructed invariant mass of the leading higgs
TH1D *M_Lhiggs1   = nullptr;
TH1D *M_Lhiggs0   = nullptr;
TH1D *M_Lhiggs_1  = nullptr;
TH1D *M_Lhiggs_2  = nullptr;
TH1D *M_Lhiggs2   = nullptr;
TH1D *M_Lhiggs2_5 = nullptr;
TH1D *M_Lhiggs3   = nullptr;
TH1D *M_LhiggsB   = nullptr;
//recconstructed invariant mass of the sub-leading higgs
TH1D *M_NLhiggs1   = nullptr;
TH1D *M_NLhiggs0   = nullptr;
TH1D *M_NLhiggs_1  = nullptr;
TH1D *M_NLhiggs_2  = nullptr;
TH1D *M_NLhiggs2   = nullptr;
TH1D *M_NLhiggs2_5 = nullptr;
TH1D *M_NLhiggs3   = nullptr;
TH1D *M_NLhiggsB   = nullptr;
//reconstructed pt of the di-higgs system
TH1D *RecPtH1H2_1 = nullptr; 
TH1D *RecPtH1H2_0 = nullptr; 
TH1D *RecPtH1H2__1 = nullptr; 
TH1D *RecPtH1H2__2 = nullptr; 
TH1D *RecPtH1H2_2 = nullptr; 
TH1D *RecPtH1H2_2_5 = nullptr; 
TH1D *RecPtH1H2_3 = nullptr;
TH1D *RecPtH1H2_B = nullptr;
//reconstructed inv mass of the di-higgs system
TH1D *RecMH1H2_1 = nullptr; 
TH1D *RecMH1H2_0 = nullptr; 
TH1D *RecMH1H2__1 = nullptr; 
TH1D *RecMH1H2__2 = nullptr; 
TH1D *RecMH1H2_2 = nullptr; 
TH1D *RecMH1H2_2_5 = nullptr; 
TH1D *RecMH1H2_3 = nullptr;
TH1D *RecMH1H2_B = nullptr;

// invariant mass of a pair of b's, ctr = 1.0
TH1D *M_b1b2_1 = nullptr;
TH1D *M_b1b3_1 = nullptr;
TH1D *M_b1b4_1 = nullptr;
TH1D *M_b2b3_1 = nullptr;
TH1D *M_b2b4_1 = nullptr;
TH1D *M_b3b4_1 = nullptr;
//relative difference of the jet pairs
//only 3 combination of jet pairs possible
TH1D *dM_b1b2_b3b4_1 = nullptr;
TH1D *dM_b1b3_b2b4_1 = nullptr;
TH1D *dM_b1b4_b2b3_1 = nullptr;

// invariant mass of a pair of b's, ctr = 0.0
TH1D *M_b1b2_0 = nullptr;
TH1D *M_b1b3_0 = nullptr;
TH1D *M_b1b4_0 = nullptr;
TH1D *M_b2b3_0 = nullptr;
TH1D *M_b2b4_0 = nullptr;
TH1D *M_b3b4_0 = nullptr;
//relative difference of the jet pairs
//only 3 combination of jet pairs possible
TH1D *dM_b1b2_b3b4_0 = nullptr;
TH1D *dM_b1b3_b2b4_0 = nullptr;
TH1D *dM_b1b4_b2b3_0 = nullptr;

// invariant mass of a pair of b's, ctr = -1.0
TH1D *M_b1b2__1 = nullptr;
TH1D *M_b1b3__1 = nullptr;
TH1D *M_b1b4__1 = nullptr;
TH1D *M_b2b3__1 = nullptr;
TH1D *M_b2b4__1 = nullptr;
TH1D *M_b3b4__1 = nullptr;
//relative difference of the jet pairs
//only 3 combination of jet pairs possible
TH1D *dM_b1b2_b3b4__1 = nullptr;
TH1D *dM_b1b3_b2b4__1 = nullptr;
TH1D *dM_b1b4_b2b3__1 = nullptr;

// invariant mass of a pair of b's, ctr = -2.0
TH1D *M_b1b2__2 = nullptr;
TH1D *M_b1b3__2 = nullptr;
TH1D *M_b1b4__2 = nullptr;
TH1D *M_b2b3__2 = nullptr;
TH1D *M_b2b4__2 = nullptr;
TH1D *M_b3b4__2 = nullptr;
//relative difference of the jet pairs
//only 3 combination of jet pairs possible
TH1D *dM_b1b2_b3b4__2 = nullptr;
TH1D *dM_b1b3_b2b4__2 = nullptr;
TH1D *dM_b1b4_b2b3__2 = nullptr;

// invariant mass of a pair of b's, ctr = 2.0
TH1D *M_b1b2_2 = nullptr;
TH1D *M_b1b3_2 = nullptr;
TH1D *M_b1b4_2 = nullptr;
TH1D *M_b2b3_2 = nullptr;
TH1D *M_b2b4_2 = nullptr;
TH1D *M_b3b4_2 = nullptr;
//relative difference of the jet pairs
//only 3 combination of jet pairs possible
TH1D *dM_b1b2_b3b4_2 = nullptr;
TH1D *dM_b1b3_b2b4_2 = nullptr;
TH1D *dM_b1b4_b2b3_2 = nullptr;

// invariant mass of a pair of b's, ctr = 2.5
TH1D *M_b1b2_2_5 = nullptr;
TH1D *M_b1b3_2_5 = nullptr;
TH1D *M_b1b4_2_5 = nullptr;
TH1D *M_b2b3_2_5 = nullptr;
TH1D *M_b2b4_2_5 = nullptr;
TH1D *M_b3b4_2_5 = nullptr;
//relative difference of the jet pairs
//only 3 combination of jet pairs possible
TH1D *dM_b1b2_b3b4_2_5 = nullptr;
TH1D *dM_b1b3_b2b4_2_5 = nullptr;
TH1D *dM_b1b4_b2b3_2_5 = nullptr;

// invariant mass of a pair of b's, ctr = 3.0
TH1D *M_b1b2_3 = nullptr;
TH1D *M_b1b3_3 = nullptr;
TH1D *M_b1b4_3 = nullptr;
TH1D *M_b2b3_3 = nullptr;
TH1D *M_b2b4_3 = nullptr;
TH1D *M_b3b4_3 = nullptr;
//relative difference of the jet pairs
//only 3 combination of jet pairs possible
TH1D *dM_b1b2_b3b4_3 = nullptr;
TH1D *dM_b1b3_b2b4_3 = nullptr;
TH1D *dM_b1b4_b2b3_3 = nullptr;

// invariant mass of a pair of b's, pp->4b
TH1D *M_b1b2_B = nullptr;
TH1D *M_b1b3_B = nullptr;
TH1D *M_b1b4_B = nullptr;
TH1D *M_b2b3_B = nullptr;
TH1D *M_b2b4_B = nullptr;
TH1D *M_b3b4_B = nullptr;
//relative difference of the jet pairs
//only 3 combination of jet pairs possible
TH1D *dM_b1b2_b3b4_B = nullptr;
TH1D *dM_b1b3_b2b4_B = nullptr;
TH1D *dM_b1b4_b2b3_B = nullptr;

//! frequency of the combination selected from amongst the 3 possible combinations
TH1D *combi_selected_1   = nullptr;
TH1D *combi_selected_0   = nullptr;
TH1D *combi_selected__1  = nullptr;
TH1D *combi_selected__2  = nullptr;
TH1D *combi_selected_2   = nullptr;
TH1D *combi_selected_2_5 = nullptr;
TH1D *combi_selected_3   = nullptr;
TH1D *combi_selected_B   = nullptr;

//jet leading M
TH1D *jetLM1  = nullptr;
TH1D *jetLM0  = nullptr;
TH1D *jetLM_1 = nullptr;
TH1D *jetLM_2 = nullptr;
TH1D *jetLM2  = nullptr;
TH1D *jetLM2_5= nullptr;
TH1D *jetLM3  = nullptr;
TH1D *jetLMB  = nullptr;
//jet 2nd leading M
TH1D *jet2LM1  = nullptr;
TH1D *jet2LM0  = nullptr;
TH1D *jet2LM_1 = nullptr;
TH1D *jet2LM_2 = nullptr;
TH1D *jet2LM2  = nullptr;
TH1D *jet2LM2_5= nullptr;
TH1D *jet2LM3  = nullptr;
TH1D *jet2LMB  = nullptr;
//jet 3rd leading M
TH1D *jet3LM1  = nullptr;
TH1D *jet3LM0  = nullptr;
TH1D *jet3LM_1 = nullptr;
TH1D *jet3LM_2 = nullptr;
TH1D *jet3LM2  = nullptr;
TH1D *jet3LM2_5= nullptr;
TH1D *jet3LM3  = nullptr;
TH1D *jet3LMB  = nullptr;
//jet 4th leading M
TH1D *jet4LM1  = nullptr;
TH1D *jet4LM0  = nullptr;
TH1D *jet4LM_1 = nullptr;
TH1D *jet4LM_2 = nullptr;
TH1D *jet4LM2  = nullptr;
TH1D *jet4LM2_5= nullptr;
TH1D *jet4LM3  = nullptr;
TH1D *jet4LMB  = nullptr;
//jet 5th leading M
TH1D *jet5LM1  = nullptr;
TH1D *jet5LM0  = nullptr;
TH1D *jet5LM_1 = nullptr;
TH1D *jet5LM_2 = nullptr;
TH1D *jet5LM2  = nullptr;
TH1D *jet5LM2_5= nullptr;
TH1D *jet5LM3  = nullptr;
TH1D *jet5LMB  = nullptr;

//bjet leading M
TH1D *bjetLM1  = nullptr;
TH1D *bjetLM0  = nullptr;
TH1D *bjetLM_1 = nullptr;
TH1D *bjetLM_2 = nullptr;
TH1D *bjetLM2  = nullptr;
TH1D *bjetLM2_5= nullptr;
TH1D *bjetLM3  = nullptr;
TH1D *bjetLMB  = nullptr;
//bjet 2nd leading M
TH1D *bjet2LM1  = nullptr;
TH1D *bjet2LM0  = nullptr;
TH1D *bjet2LM_1 = nullptr;
TH1D *bjet2LM_2 = nullptr;
TH1D *bjet2LM2  = nullptr;
TH1D *bjet2LM2_5= nullptr;
TH1D *bjet2LM3  = nullptr;
TH1D *bjet2LMB  = nullptr;
//bjet 3rd leading M
TH1D *bjet3LM1  = nullptr;
TH1D *bjet3LM0  = nullptr;
TH1D *bjet3LM_1 = nullptr;
TH1D *bjet3LM_2 = nullptr;
TH1D *bjet3LM2  = nullptr;
TH1D *bjet3LM2_5= nullptr;
TH1D *bjet3LM3  = nullptr;
TH1D *bjet3LMB  = nullptr;
//bjet 4th leading M
TH1D *bjet4LM1  = nullptr;
TH1D *bjet4LM0  = nullptr;
TH1D *bjet4LM_1 = nullptr;
TH1D *bjet4LM_2 = nullptr;
TH1D *bjet4LM2  = nullptr;
TH1D *bjet4LM2_5= nullptr;
TH1D *bjet4LM3  = nullptr;
TH1D *bjet4LMB  = nullptr;
//bjet 5th leading M
TH1D *bjet5LM1  = nullptr;
TH1D *bjet5LM0  = nullptr;
TH1D *bjet5LM_1 = nullptr;
TH1D *bjet5LM_2 = nullptr;
TH1D *bjet5LM2  = nullptr;
TH1D *bjet5LM2_5= nullptr;
TH1D *bjet5LM3  = nullptr;
TH1D *bjet5LMB  = nullptr;

//jet leading Pt
TH1D *jetLPt1  = nullptr;
TH1D *jetLPt0  = nullptr;
TH1D *jetLPt_1 = nullptr;
TH1D *jetLPt_2 = nullptr;
TH1D *jetLPt2  = nullptr;
TH1D *jetLPt2_5= nullptr;
TH1D *jetLPt3  = nullptr;
TH1D *jetLPtB  = nullptr;
//jet 2nd leading Pt
TH1D *jet2LPt1  = nullptr;
TH1D *jet2LPt0  = nullptr;
TH1D *jet2LPt_1 = nullptr;
TH1D *jet2LPt_2 = nullptr;
TH1D *jet2LPt2  = nullptr;
TH1D *jet2LPt2_5= nullptr;
TH1D *jet2LPt3  = nullptr;
TH1D *jet2LPtB  = nullptr;
//jet 3rd leading Pt
TH1D *jet3LPt1  = nullptr;
TH1D *jet3LPt0  = nullptr;
TH1D *jet3LPt_1 = nullptr;
TH1D *jet3LPt_2 = nullptr;
TH1D *jet3LPt2  = nullptr;
TH1D *jet3LPt2_5= nullptr;
TH1D *jet3LPt3  = nullptr;
TH1D *jet3LPtB  = nullptr;
//jet 4th leading Pt
TH1D *jet4LPt1  = nullptr;
TH1D *jet4LPt0  = nullptr;
TH1D *jet4LPt_1 = nullptr;
TH1D *jet4LPt_2 = nullptr;
TH1D *jet4LPt2  = nullptr;
TH1D *jet4LPt2_5= nullptr;
TH1D *jet4LPt3  = nullptr;
TH1D *jet4LPtB  = nullptr;
//jet 5th leading Pt
TH1D *jet5LPt1  = nullptr;
TH1D *jet5LPt0  = nullptr;
TH1D *jet5LPt_1 = nullptr;
TH1D *jet5LPt_2 = nullptr;
TH1D *jet5LPt2  = nullptr;
TH1D *jet5LPt2_5= nullptr;
TH1D *jet5LPt3  = nullptr;
TH1D *jet5LPtB  = nullptr;

//b-jet leading Pt
TH1D *bjetLPt1  = nullptr;
TH1D *bjetLPt0  = nullptr;
TH1D *bjetLPt_1 = nullptr;
TH1D *bjetLPt_2 = nullptr;
TH1D *bjetLPt2  = nullptr;
TH1D *bjetLPt2_5= nullptr;
TH1D *bjetLPt3  = nullptr;
TH1D *bjetLPtB  = nullptr;
//b-jet 2nd leading Pt
TH1D *bjet2LPt1  = nullptr;
TH1D *bjet2LPt0  = nullptr;
TH1D *bjet2LPt_1 = nullptr;
TH1D *bjet2LPt_2 = nullptr;
TH1D *bjet2LPt2  = nullptr;
TH1D *bjet2LPt2_5= nullptr;
TH1D *bjet2LPt3  = nullptr;
TH1D *bjet2LPtB  = nullptr;
//b-jet 3rd leading Pt
TH1D *bjet3LPt1  = nullptr;
TH1D *bjet3LPt0  = nullptr;
TH1D *bjet3LPt_1 = nullptr;
TH1D *bjet3LPt_2 = nullptr;
TH1D *bjet3LPt2  = nullptr;
TH1D *bjet3LPt2_5= nullptr;
TH1D *bjet3LPt3  = nullptr;
TH1D *bjet3LPtB  = nullptr;
//b-jet 4th leading Pt
TH1D *bjet4LPt1  = nullptr;
TH1D *bjet4LPt0  = nullptr;
TH1D *bjet4LPt_1 = nullptr;
TH1D *bjet4LPt_2 = nullptr;
TH1D *bjet4LPt2  = nullptr;
TH1D *bjet4LPt2_5= nullptr;
TH1D *bjet4LPt3  = nullptr;
TH1D *bjet4LPtB  = nullptr;

//! Four jet pt after all selection, SM
TH1D *Ana_bjetLPt1  = nullptr;
TH1D *Ana_bjet2LPt1 = nullptr;
TH1D *Ana_bjet3LPt1 = nullptr;
TH1D *Ana_bjet4LPt1 = nullptr;
//! Four jet pt after all selection, 0 
TH1D *Ana_bjetLPt0  = nullptr;
TH1D *Ana_bjet2LPt0 = nullptr;
TH1D *Ana_bjet3LPt0 = nullptr;
TH1D *Ana_bjet4LPt0 = nullptr;
//! Four jet pt after all selection, _1 
TH1D *Ana_bjetLPt_1  = nullptr;
TH1D *Ana_bjet2LPt_1 = nullptr;
TH1D *Ana_bjet3LPt_1 = nullptr;
TH1D *Ana_bjet4LPt_1 = nullptr;
//! Four jet pt after all selection, _2 
TH1D *Ana_bjetLPt_2  = nullptr;
TH1D *Ana_bjet2LPt_2 = nullptr;
TH1D *Ana_bjet3LPt_2 = nullptr;
TH1D *Ana_bjet4LPt_2 = nullptr;
//! Four jet pt after all selection, 2 
TH1D *Ana_bjetLPt2  = nullptr;
TH1D *Ana_bjet2LPt2 = nullptr;
TH1D *Ana_bjet3LPt2 = nullptr;
TH1D *Ana_bjet4LPt2 = nullptr;
//! Four jet pt after all selection, 2_5 
TH1D *Ana_bjetLPt2_5  = nullptr;
TH1D *Ana_bjet2LPt2_5 = nullptr;
TH1D *Ana_bjet3LPt2_5 = nullptr;
TH1D *Ana_bjet4LPt2_5 = nullptr;
//! Four jet pt after all selection, 3 
TH1D *Ana_bjetLPt3  = nullptr;
TH1D *Ana_bjet2LPt3 = nullptr;
TH1D *Ana_bjet3LPt3 = nullptr;
TH1D *Ana_bjet4LPt3 = nullptr;
//! Four jet pt after all selection, pp->4b
TH1D *Ana_bjetLPtB  = nullptr;
TH1D *Ana_bjet2LPtB = nullptr;
TH1D *Ana_bjet3LPtB = nullptr;
TH1D *Ana_bjet4LPtB = nullptr;

//b leading Pt
TH1D *bLPt1  = nullptr;
TH1D *bLPt0  = nullptr;
TH1D *bLPt_1 = nullptr;
TH1D *bLPt_2 = nullptr;
TH1D *bLPt2  = nullptr;
TH1D *bLPt2_5= nullptr;
TH1D *bLPt3  = nullptr;
TH1D *bLPtB  = nullptr;
//b 2nd leading Pt
TH1D *b2LPt1  = nullptr;
TH1D *b2LPt0  = nullptr;
TH1D *b2LPt_1 = nullptr;
TH1D *b2LPt_2 = nullptr;
TH1D *b2LPt2  = nullptr;
TH1D *b2LPt2_5= nullptr;
TH1D *b2LPt3  = nullptr;
TH1D *b2LPtB  = nullptr;
//b 3rd leading Pt
TH1D *b3LPt1  = nullptr;
TH1D *b3LPt0  = nullptr;
TH1D *b3LPt_1 = nullptr;
TH1D *b3LPt_2 = nullptr;
TH1D *b3LPt2  = nullptr;
TH1D *b3LPt2_5= nullptr;
TH1D *b3LPt3  = nullptr;
TH1D *b3LPtB  = nullptr;
//b 4th leading Pt
TH1D *b4LPt1  = nullptr;
TH1D *b4LPt0  = nullptr;
TH1D *b4LPt_1 = nullptr;
TH1D *b4LPt_2 = nullptr;
TH1D *b4LPt2  = nullptr;
TH1D *b4LPt2_5= nullptr;
TH1D *b4LPt3  = nullptr;
TH1D *b4LPtB  = nullptr;

//b central Pt
TH1D *bCEta1  = nullptr;
TH1D *bCEta0  = nullptr;
TH1D *bCEta_1 = nullptr;
TH1D *bCEta_2 = nullptr;
TH1D *bCEta2  = nullptr;
TH1D *bCEta2_5= nullptr;
TH1D *bCEta3  = nullptr;
TH1D *bCEtaB  = nullptr;
//b 2nd central Pt
TH1D *b2CEta1  = nullptr;
TH1D *b2CEta0  = nullptr;
TH1D *b2CEta_1 = nullptr;
TH1D *b2CEta_2 = nullptr;
TH1D *b2CEta2  = nullptr;
TH1D *b2CEta2_5= nullptr;
TH1D *b2CEta3  = nullptr;
TH1D *b2CEtaB  = nullptr;
//b 3rd central Pt
TH1D *b3CEta1  = nullptr;
TH1D *b3CEta0  = nullptr;
TH1D *b3CEta_1 = nullptr;
TH1D *b3CEta_2 = nullptr;
TH1D *b3CEta2  = nullptr;
TH1D *b3CEta2_5= nullptr;
TH1D *b3CEta3  = nullptr;
TH1D *b3CEtaB = nullptr;
//b 4th central Pt
TH1D *b4CEta1  = nullptr;
TH1D *b4CEta0  = nullptr;
TH1D *b4CEta_1 = nullptr;
TH1D *b4CEta_2 = nullptr;
TH1D *b4CEta2  = nullptr;
TH1D *b4CEta2_5= nullptr;
TH1D *b4CEta3  = nullptr;
TH1D *b4CEtaB  = nullptr;

//! scatter plot b/w rec mass of possible higgs candidates
TH2D *b1b2_b3b4_1 = nullptr;
TH2D *b1b3_b2b4_1 = nullptr;
TH2D *b1b4_b2b3_1 = nullptr;
//! scatter plot b/w rec mass of possible higgs candidates
TH2D *b1b2_b3b4_B = nullptr;
TH2D *b1b3_b2b4_B = nullptr;
TH2D *b1b4_b2b3_B = nullptr;

TH2D *J1bJ1_1 = nullptr;
TH2D *J2bJ2_1 = nullptr;
TH2D *J3bJ3_1 = nullptr;
TH2D *J4bJ4_1 = nullptr;

TH2D *MJ1bJ1_1 = nullptr;
TH2D *MJ2bJ2_1 = nullptr;
TH2D *MJ3bJ3_1 = nullptr;
TH2D *MJ4bJ4_1 = nullptr;

Float_t MLHmin = 50.0;
Float_t MLHmax = 250.0;
Float_t Mmin1 = 100.0;

Float_t LINE_WIDTH = 2.5;
Float_t TITLE_SIZE = 0.04;
Float_t MARKER_SIZE = 1.2;
Float_t AXISTITLE_OFFSET = 0.8;
Float_t YAXISTITLE_OFFSET = 1.2;

//********** Legend Properties ************//
//! Draw Legends
TLegend *leg_higgs_1 = nullptr;
TLegend *leg_higgs   = nullptr;
TLegend *leg1 = nullptr;
TLegend *leg2 = nullptr;
TLegend *leg3 = nullptr;
TLegend *leg4 = nullptr;
TLegend *leg5 = nullptr;
TLegend *leg6 = nullptr;
TLegend *l_   = nullptr;

Float_t ENTRY_SEP = 0.05;
Float_t FILL_STYLE = 0;
Float_t BORDER_SIZE = 0;
Float_t TEXT_ALIGN = 32;
Float_t TEXT_ALIGN_1 = 12;
Float_t TEXT_FONT = 62;
Float_t TEXT_SIZE = 0.03;
Float_t TEXT_SIZE_1 = 0.05;
