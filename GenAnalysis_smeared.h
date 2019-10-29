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

const char *out_path = "./analysis_plots/pdf"; 
const char *output_file_name = "ggFhh4b_2.5_1_smeared";

const char *inp_file1  = "./fastjet_output/Genjet_ggF_Ctr1.0_q1.2GeV_2.5_2.root"; 
const char *inp_file0  = "./fastjet_output/Genjet_ggF_Ctr0.0_q1.2GeV_2.5_2.root"; 
const char *inp_file_1 = "./fastjet_output/Genjet_ggF_Ctr-1.0_q1.2GeV_2.5_2.root"; 
const char *inp_file_2 = "./fastjet_output/Genjet_ggF_Ctr-2.0_q1.2GeV_2.5_2.root"; 
const char *inp_file2  = "./fastjet_output/Genjet_ggF_Ctr2.0_q1.2GeV_2.5_2.root"; 
const char *inp_file2_5= "./fastjet_output/Genjet_ggF_Ctr2.5_q1.2GeV_2.5_2.root"; 
const char *inp_file3  = "./fastjet_output/Genjet_ggF_Ctr3.0_q1.2GeV_2.5_2.root"; 

TFile *f1  = nullptr;
TFile *f0  = nullptr;
TFile *f_1 = nullptr;
TFile *f_2 = nullptr;
TFile *f2  = nullptr;
TFile *f2_5= nullptr;
TFile *f3  = nullptr;

//TTree
TTree *t1  = nullptr;
TTree *t0  = nullptr;
TTree *t_1 = nullptr;
TTree *t_2 = nullptr;
TTree *t2  = nullptr;
TTree *t2_5= nullptr;
TTree *t3  = nullptr;

//! Draw Legends
TLegend *leg_higgs = nullptr;
TLegend *leg1 = nullptr;
TLegend *leg2 = nullptr;
TLegend *leg3 = nullptr;
TLegend *leg4 = nullptr;

int n_entries1;
int n_entries2;
int n_entries3;
int n_entries4;
int n_entries5;
int n_entries6;
int n_entries7;
//! Get jetPt in locally defined std::vector
std::vector<double> *v1_jetPt = nullptr;
std::vector<double> *v0_jetPt = nullptr;
std::vector<double> *v_1_jetPt = nullptr;
std::vector<double> *v_2_jetPt = nullptr;
std::vector<double> *v2_jetPt = nullptr;
std::vector<double> *v2_5_jetPt = nullptr;
std::vector<double> *v3_jetPt = nullptr;

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

//jet leading Pt
TH1D *jetLPt1  = nullptr;
TH1D *jetLPt0  = nullptr;
TH1D *jetLPt_1 = nullptr;
TH1D *jetLPt_2 = nullptr;
TH1D *jetLPt2  = nullptr;
TH1D *jetLPt2_5= nullptr;
TH1D *jetLPt3  = nullptr;
//jet 2nd leading Pt
TH1D *jet2LPt1  = nullptr;
TH1D *jet2LPt0  = nullptr;
TH1D *jet2LPt_1 = nullptr;
TH1D *jet2LPt_2 = nullptr;
TH1D *jet2LPt2  = nullptr;
TH1D *jet2LPt2_5= nullptr;
TH1D *jet2LPt3  = nullptr;
//jet 3rd leading Pt
TH1D *jet3LPt1  = nullptr;
TH1D *jet3LPt0  = nullptr;
TH1D *jet3LPt_1 = nullptr;
TH1D *jet3LPt_2 = nullptr;
TH1D *jet3LPt2  = nullptr;
TH1D *jet3LPt2_5= nullptr;
TH1D *jet3LPt3  = nullptr;
//jet 4th leading Pt
TH1D *jet4LPt1  = nullptr;
TH1D *jet4LPt0  = nullptr;
TH1D *jet4LPt_1 = nullptr;
TH1D *jet4LPt_2 = nullptr;
TH1D *jet4LPt2  = nullptr;
TH1D *jet4LPt2_5= nullptr;
TH1D *jet4LPt3  = nullptr;
//jet 5th leading Pt
TH1D *jet5LPt1  = nullptr;
TH1D *jet5LPt0  = nullptr;
TH1D *jet5LPt_1 = nullptr;
TH1D *jet5LPt_2 = nullptr;
TH1D *jet5LPt2  = nullptr;
TH1D *jet5LPt2_5= nullptr;
TH1D *jet5LPt3  = nullptr;

//b-jet leading Pt
TH1D *bjetLPt1  = nullptr;
TH1D *bjetLPt0  = nullptr;
TH1D *bjetLPt_1 = nullptr;
TH1D *bjetLPt_2 = nullptr;
TH1D *bjetLPt2  = nullptr;
TH1D *bjetLPt2_5= nullptr;
TH1D *bjetLPt3  = nullptr;
//b-jet 2nd leading Pt
TH1D *bjet2LPt1  = nullptr;
TH1D *bjet2LPt0  = nullptr;
TH1D *bjet2LPt_1 = nullptr;
TH1D *bjet2LPt_2 = nullptr;
TH1D *bjet2LPt2  = nullptr;
TH1D *bjet2LPt2_5= nullptr;
TH1D *bjet2LPt3  = nullptr;
//b-jet 3rd leading Pt
TH1D *bjet3LPt1  = nullptr;
TH1D *bjet3LPt0  = nullptr;
TH1D *bjet3LPt_1 = nullptr;
TH1D *bjet3LPt_2 = nullptr;
TH1D *bjet3LPt2  = nullptr;
TH1D *bjet3LPt2_5= nullptr;
TH1D *bjet3LPt3  = nullptr;
//b-jet 4th leading Pt
TH1D *bjet4LPt1  = nullptr;
TH1D *bjet4LPt0  = nullptr;
TH1D *bjet4LPt_1 = nullptr;
TH1D *bjet4LPt_2 = nullptr;
TH1D *bjet4LPt2  = nullptr;
TH1D *bjet4LPt2_5= nullptr;
TH1D *bjet4LPt3  = nullptr;

//b leading Pt
TH1D *bLPt1  = nullptr;
TH1D *bLPt0  = nullptr;
TH1D *bLPt_1 = nullptr;
TH1D *bLPt_2 = nullptr;
TH1D *bLPt2  = nullptr;
TH1D *bLPt2_5= nullptr;
TH1D *bLPt3  = nullptr;
//b 2nd leading Pt
TH1D *b2LPt1  = nullptr;
TH1D *b2LPt0  = nullptr;
TH1D *b2LPt_1 = nullptr;
TH1D *b2LPt_2 = nullptr;
TH1D *b2LPt2  = nullptr;
TH1D *b2LPt2_5= nullptr;
TH1D *b2LPt3  = nullptr;
//b 3rd leading Pt
TH1D *b3LPt1  = nullptr;
TH1D *b3LPt0  = nullptr;
TH1D *b3LPt_1 = nullptr;
TH1D *b3LPt_2 = nullptr;
TH1D *b3LPt2  = nullptr;
TH1D *b3LPt2_5= nullptr;
TH1D *b3LPt3  = nullptr;
//b 4th leading Pt
TH1D *b4LPt1  = nullptr;
TH1D *b4LPt0  = nullptr;
TH1D *b4LPt_1 = nullptr;
TH1D *b4LPt_2 = nullptr;
TH1D *b4LPt2  = nullptr;
TH1D *b4LPt2_5= nullptr;
TH1D *b4LPt3  = nullptr;

//b central Pt
TH1D *bCEta1  = nullptr;
TH1D *bCEta0  = nullptr;
TH1D *bCEta_1 = nullptr;
TH1D *bCEta_2 = nullptr;
TH1D *bCEta2  = nullptr;
TH1D *bCEta2_5= nullptr;
TH1D *bCEta3  = nullptr;
//b 2nd central Pt
TH1D *b2CEta1  = nullptr;
TH1D *b2CEta0  = nullptr;
TH1D *b2CEta_1 = nullptr;
TH1D *b2CEta_2 = nullptr;
TH1D *b2CEta2  = nullptr;
TH1D *b2CEta2_5= nullptr;
TH1D *b2CEta3  = nullptr;
//b 3rd central Pt
TH1D *b3CEta1  = nullptr;
TH1D *b3CEta0  = nullptr;
TH1D *b3CEta_1 = nullptr;
TH1D *b3CEta_2 = nullptr;
TH1D *b3CEta2  = nullptr;
TH1D *b3CEta2_5= nullptr;
TH1D *b3CEta3  = nullptr;
//b 4th central Pt
TH1D *b4CEta1  = nullptr;
TH1D *b4CEta0  = nullptr;
TH1D *b4CEta_1 = nullptr;
TH1D *b4CEta_2 = nullptr;
TH1D *b4CEta2  = nullptr;
TH1D *b4CEta2_5= nullptr;
TH1D *b4CEta3  = nullptr;
