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

const double HiggsMass = 125.0;//GeV
const double MassWidth = 80.0;//GeV

const double IntLumi   = 1e4;//fb-1 -> 10 ab-1
const double pp4bXsec  = 23.283e6;//fb, NLO Xsection
const double ggFhhXsec = 12.24e2;//fb, latest available NNLO Xsection, arXiv:1803.02463v1

const char *out_path = "./analysis_plots/pdf"; 
const char *output_file_name = "ggFhh4b_2.5_5_1Norm_smeared";

const char *inp_file1  = "./fastjet_output/Genjet_ggF_Ctr1.0_q1.2GeV_2.5_5.root"; 
const char *inp_file0  = "./fastjet_output/Genjet_ggF_Ctr0.0_q1.2GeV_2.5_5.root"; 
const char *inp_file_1 = "./fastjet_output/Genjet_ggF_Ctr-1.0_q1.2GeV_2.5_5.root"; 
const char *inp_file_2 = "./fastjet_output/Genjet_ggF_Ctr-2.0_q1.2GeV_2.5_5.root"; 
const char *inp_file2  = "./fastjet_output/Genjet_ggF_Ctr2.0_q1.2GeV_2.5_5.root"; 
const char *inp_file2_5= "./fastjet_output/Genjet_ggF_Ctr2.5_q1.2GeV_2.5_5.root"; 
const char *inp_file3  = "./fastjet_output/Genjet_ggF_Ctr3.0_q1.2GeV_2.5_5.root"; 
const char *inp_fileB  = "./fastjet_output/Genjet_pp4b_q1.2GeV_2.5_5.root"; 

TFile *f1  = nullptr;
TFile *f0  = nullptr;
TFile *f_1 = nullptr;
TFile *f_2 = nullptr;
TFile *f2  = nullptr;
TFile *f2_5= nullptr;
TFile *f3  = nullptr;
TFile *fB  = nullptr;

//TTree
TTree *t1  = nullptr;
TTree *t0  = nullptr;
TTree *t_1 = nullptr;
TTree *t_2 = nullptr;
TTree *t2  = nullptr;
TTree *t2_5= nullptr;
TTree *t3  = nullptr;
TTree *tB  = nullptr;

//! Draw Legends
TLegend *leg_higgs = nullptr;
TLegend *leg1 = nullptr;
TLegend *leg2 = nullptr;
TLegend *leg3 = nullptr;
TLegend *leg4 = nullptr;
TLegend *leg5 = nullptr;
TLegend *leg6 = nullptr;

//! Get bjetMt2 in locally defined std::vector
std::vector<double> v1_bjetMt2;
std::vector<double> v0_bjetMt2;
std::vector<double> v_1_bjetMt2;
std::vector<double> v_2_bjetMt2;
std::vector<double> v2_bjetMt2;
std::vector<double> v2_5_bjetMt2;
std::vector<double> v3_bjetMt2;
std::vector<double> vB_bjetMt2;
//! Get bjetPt in locally defined std::vector
std::vector<double> v1_bjetPt;
std::vector<double> v0_bjetPt;
std::vector<double> v_1_bjetPt;
std::vector<double> v_2_bjetPt;
std::vector<double> v2_bjetPt;
std::vector<double> v2_5_bjetPt;
std::vector<double> v3_bjetPt;
std::vector<double> vB_bjetPt;
//! Get invariant mass of combinations of bjets  in locally defined std::vector
//! there are 4 bjets in an event => 6 combination of 2 bjets are possible
std::vector<double> v1_bibjM;
std::vector<double> v0_bibjM;
std::vector<double> v_1_bibjM;
std::vector<double> v_2_bibjM;
std::vector<double> v2_bibjM;
std::vector<double> v2_5_bibjM;
std::vector<double> v3_bibjM;
std::vector<double> vB_bibjM;
//! Get jetPt in locally defined std::vector
std::vector<double> *v1_jetMt2 = nullptr;
std::vector<double> *v0_jetMt2 = nullptr;
std::vector<double> *v_1_jetMt2 = nullptr;
std::vector<double> *v_2_jetMt2 = nullptr;
std::vector<double> *v2_jetMt2 = nullptr;
std::vector<double> *v2_5_jetMt2 = nullptr;
std::vector<double> *v3_jetMt2 = nullptr;
std::vector<double> *vB_jetMt2 = nullptr;
//! Get jetPt in locally defined std::vector
std::vector<double> *v1_jetPt = nullptr;
std::vector<double> *v0_jetPt = nullptr;
std::vector<double> *v_1_jetPt = nullptr;
std::vector<double> *v_2_jetPt = nullptr;
std::vector<double> *v2_jetPt = nullptr;
std::vector<double> *v2_5_jetPt = nullptr;
std::vector<double> *v3_jetPt = nullptr;
std::vector<double> *vB_jetPt = nullptr;
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
//! Book histograms:
//Higgs Pt
TH1 *higgsPt1  = nullptr;
TH1 *higgsPt0  = nullptr;
TH1 *higgsPt_1 = nullptr;
TH1 *higgsPt_2 = nullptr;
TH1 *higgsPt2  = nullptr;
TH1 *higgsPt2_5= nullptr;
TH1 *higgsPt3  = nullptr;
//Higgs sub leading Pt
TH1 *higgsNLPt1  = nullptr;
TH1 *higgsNLPt0  = nullptr;
TH1 *higgsNLPt_1 = nullptr;
TH1 *higgsNLPt_2 = nullptr;
TH1 *higgsNLPt2  = nullptr;
TH1 *higgsNLPt2_5= nullptr;
TH1 *higgsNLPt3  = nullptr;

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
