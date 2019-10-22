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
const char *output_file_name = "ggFhh4b_1";

const char *inp_file1  = "./fastjet_output/Genjet_ggF_Ctr1.0_q1.2GeV_1.root"; 
const char *inp_file0  = "./fastjet_output/Genjet_ggF_Ctr0.0_q1.2GeV_1.root"; 
const char *inp_file_1 = "./fastjet_output/Genjet_ggF_Ctr-1.0_q1.2GeV_1.root"; 
const char *inp_file_2 = "./fastjet_output/Genjet_ggF_Ctr-2.0_q1.2GeV_1.root"; 
const char *inp_file2  = "./fastjet_output/Genjet_ggF_Ctr2.0_q1.2GeV_1.root"; 
const char *inp_file2_5= "./fastjet_output/Genjet_ggF_Ctr2.5_q1.2GeV_1.root"; 
const char *inp_file3  = "./fastjet_output/Genjet_ggF_Ctr3.0_q1.2GeV_1.root"; 

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

void Set_higgsPtProps()
{
	int nbins = 100;
	float ptmin = 0;
	float ptmax = 800;
	higgsPt1  = new TH1D("higgsPt1",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt0  = new TH1D("higgsPt0",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt_1 = new TH1D("higgsPt_1", "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt_2 = new TH1D("higgsPt_2", "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt2  = new TH1D("higgsPt2",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt2_5= new TH1D("higgsPt2_5","higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt3  = new TH1D("higgsPt3",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);

	higgsPt1->SetLineColor(kRed);
	higgsPt0->SetLineColor(kBlack);
	higgsPt_1->SetLineColor(kYellow -9);
	higgsPt_2->SetLineColor(kGreen);
	higgsPt2->SetLineColor(kBlue);
	higgsPt2_5->SetLineColor(kOrange-9);
	higgsPt3->SetLineColor(kViolet);
	
	higgsPt1->SetLineWidth(2);
	higgsPt0->SetLineWidth(2);
	higgsPt_1->SetLineWidth(2);
	higgsPt_2->SetLineWidth(2);
	higgsPt2->SetLineWidth(2);
	higgsPt2_5->SetLineWidth(2);
	higgsPt3->SetLineWidth(2);
	
	higgsNLPt1  = new TH1D("higgsNLPt1",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsNLPt0  = new TH1D("higgsNLPt0",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsNLPt_1 = new TH1D("higgsNLPt_1", "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsNLPt_2 = new TH1D("higgsNLPt_2", "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsNLPt2  = new TH1D("higgsNLPt2",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsNLPt2_5= new TH1D("higgsNLPt2_5","higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsNLPt3  = new TH1D("higgsNLPt3",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);

	higgsNLPt1->SetLineColor(kRed);
	higgsNLPt0->SetLineColor(kBlack);
	higgsNLPt_1->SetLineColor(kYellow -9);
	higgsNLPt_2->SetLineColor(kGreen);
	higgsNLPt2->SetLineColor(kBlue);
	higgsNLPt2_5->SetLineColor(kOrange-9);
	higgsNLPt3->SetLineColor(kViolet);
	
	higgsNLPt1->SetLineWidth(2);
	higgsNLPt0->SetLineWidth(2);
	higgsNLPt_1->SetLineWidth(2);
	higgsNLPt_2->SetLineWidth(2);
	higgsNLPt2->SetLineWidth(2);
	higgsNLPt2_5->SetLineWidth(2);
	higgsNLPt3->SetLineWidth(2);

	return;
}
void fetch_TTrees()
{
	t1   = (TTree*)f1->Get("glob_jet");
	t0   = (TTree*)f0->Get("glob_jet");
	t_1  = (TTree*)f_1->Get("glob_jet");
	t_2  = (TTree*)f_2->Get("glob_jet");
	t2   = (TTree*)f2->Get("glob_jet");
	t2_5 = (TTree*)f2_5->Get("glob_jet");
	t3   = (TTree*)f3->Get("glob_jet");

	t1->SetBranchStatus("*",0);
	t0->SetBranchStatus("*",0);
	t_1->SetBranchStatus("*",0);
	t_2->SetBranchStatus("*",0);
	t2->SetBranchStatus("*",0);
	t2_5->SetBranchStatus("*",0);
	t3->SetBranchStatus("*",0);
	
	t1->SetBranchStatus("higgsLPt",1);
	t0->SetBranchStatus("higgsLPt",1);
	t_1->SetBranchStatus("higgsLPt",1);
	t_2->SetBranchStatus("higgsLPt",1);
	t2->SetBranchStatus("higgsLPt",1);
	t2_5->SetBranchStatus("higgsLPt",1);
	t3->SetBranchStatus("higgsLPt",1);
	
	t1->SetBranchStatus("higgsNLPt",1);
	t0->SetBranchStatus("higgsNLPt",1);
	t_1->SetBranchStatus("higgsNLPt",1);
	t_2->SetBranchStatus("higgsNLPt",1);
	t2->SetBranchStatus("higgsNLPt",1);
	t2_5->SetBranchStatus("higgsNLPt",1);
	t3->SetBranchStatus("higgsNLPt",1);

	return;
}
void Draw_higgsPt()
{
	
	t1->Draw("higgsLPt*1e-3>>higgsPt1");
	t0->Draw("higgsLPt*1e-3>>higgsPt0");
	t_1->Draw("higgsLPt*1e-3>>higgsPt_1");
	t_2->Draw("higgsLPt*1e-3>>higgsPt_2");
	t2->Draw("higgsLPt*1e-3>>higgsPt2");
	t2_5->Draw("higgsLPt*1e-3>>higgsPt2_5");
	t3->Draw("higgsLPt*1e-3>>higgsPt3");

	t1->Draw("higgsNLPt*1e-3>>higgsNLPt1");
	t0->Draw("higgsNLPt*1e-3>>higgsNLPt0");
	t_1->Draw("higgsNLPt*1e-3>>higgsNLPt_1");
	t_2->Draw("higgsNLPt*1e-3>>higgsNLPt_2");
	t2->Draw("higgsNLPt*1e-3>>higgsNLPt2");
	t2_5->Draw("higgsNLPt*1e-3>>higgsNLPt2_5");
	t3->Draw("higgsNLPt*1e-3>>higgsNLPt3");
	return;
}

void fetch_histos()
{
	bjetLPt1  = (TH1D*)f1->Get("hbJetPt_Lpt");
	bjet2LPt1 = (TH1D*)f1->Get("hbJetPt_NLpt");
	bjet3LPt1 = (TH1D*)f1->Get("hbJetPt_NNLpt");
	bjet4LPt1 = (TH1D*)f1->Get("hbJetPt_NNNLpt");
	
	bjetLPt0  = (TH1D*)f0->Get("hbJetPt_Lpt");
	bjet2LPt0 = (TH1D*)f0->Get("hbJetPt_NLpt");
	bjet3LPt0 = (TH1D*)f0->Get("hbJetPt_NNLpt");
	bjet4LPt0 = (TH1D*)f0->Get("hbJetPt_NNNLpt");
	
	bjetLPt_1  = (TH1D*)f_1->Get("hbJetPt_Lpt");
	bjet2LPt_1 = (TH1D*)f_1->Get("hbJetPt_NLpt");
	bjet3LPt_1 = (TH1D*)f_1->Get("hbJetPt_NNLpt");
	bjet4LPt_1 = (TH1D*)f_1->Get("hbJetPt_NNNLpt");
	
	bjetLPt_2  = (TH1D*)f_2->Get("hbJetPt_Lpt");
	bjet2LPt_2 = (TH1D*)f_2->Get("hbJetPt_NLpt");
	bjet3LPt_2 = (TH1D*)f_2->Get("hbJetPt_NNLpt");
	bjet4LPt_2 = (TH1D*)f_2->Get("hbJetPt_NNNLpt");
	
	bjetLPt2  = (TH1D*)f2->Get("hbJetPt_Lpt");
	bjet2LPt2 = (TH1D*)f2->Get("hbJetPt_NLpt");
	bjet3LPt2 = (TH1D*)f2->Get("hbJetPt_NNLpt");
	bjet4LPt2 = (TH1D*)f2->Get("hbJetPt_NNNLpt");
	
	bjetLPt2_5  = (TH1D*)f2_5->Get("hbJetPt_Lpt");
	bjet2LPt2_5 = (TH1D*)f2_5->Get("hbJetPt_NLpt");
	bjet3LPt2_5 = (TH1D*)f2_5->Get("hbJetPt_NNLpt");
	bjet4LPt2_5 = (TH1D*)f2_5->Get("hbJetPt_NNNLpt");
	
	
	bjetLPt3  = (TH1D*)f3->Get("hbJetPt_Lpt");
	bjet2LPt3 = (TH1D*)f3->Get("hbJetPt_NLpt");
	bjet3LPt3 = (TH1D*)f3->Get("hbJetPt_NNLpt");
	bjet4LPt3 = (TH1D*)f3->Get("hbJetPt_NNNLpt");
	
	bLPt1  = (TH1D*)f1->Get("hbPt_Lpt");
	b2LPt1 = (TH1D*)f1->Get("hbPt_NLpt");
	b3LPt1 = (TH1D*)f1->Get("hbPt_NNLpt");
	b4LPt1 = (TH1D*)f1->Get("hbPt_NNNLpt");
	
	bLPt0  = (TH1D*)f0->Get("hbPt_Lpt");
	b2LPt0 = (TH1D*)f0->Get("hbPt_NLpt");
	b3LPt0 = (TH1D*)f0->Get("hbPt_NNLpt");
	b4LPt0 = (TH1D*)f0->Get("hbPt_NNNLpt");
	
	bLPt_1  = (TH1D*)f_1->Get("hbPt_Lpt");
	b2LPt_1 = (TH1D*)f_1->Get("hbPt_NLpt");
	b3LPt_1 = (TH1D*)f_1->Get("hbPt_NNLpt");
	b4LPt_1 = (TH1D*)f_1->Get("hbPt_NNNLpt");
	
	bLPt_2  = (TH1D*)f_2->Get("hbPt_Lpt");
	b2LPt_2 = (TH1D*)f_2->Get("hbPt_NLpt");
	b3LPt_2 = (TH1D*)f_2->Get("hbPt_NNLpt");
	b4LPt_2 = (TH1D*)f_2->Get("hbPt_NNNLpt");
	
	bLPt2  = (TH1D*)f2->Get("hbPt_Lpt");
	b2LPt2 = (TH1D*)f2->Get("hbPt_NLpt");
	b3LPt2 = (TH1D*)f2->Get("hbPt_NNLpt");
	b4LPt2 = (TH1D*)f2->Get("hbPt_NNNLpt");
	
	bLPt2_5  = (TH1D*)f2_5->Get("hbPt_Lpt");
	b2LPt2_5 = (TH1D*)f2_5->Get("hbPt_NLpt");
	b3LPt2_5 = (TH1D*)f2_5->Get("hbPt_NNLpt");
	b4LPt2_5 = (TH1D*)f2_5->Get("hbPt_NNNLpt");
	
	bLPt3  = (TH1D*)f3->Get("hbPt_Lpt");
	b2LPt3 = (TH1D*)f3->Get("hbPt_NLpt");
	b3LPt3 = (TH1D*)f3->Get("hbPt_NNLpt");
	b4LPt3 = (TH1D*)f3->Get("hbPt_NNNLpt");
	
	
	bCEta1  = (TH1D*)f1->Get("hbEta_Ceta");
	b2CEta1 = (TH1D*)f1->Get("hbEta_NCeta");
	b3CEta1 = (TH1D*)f1->Get("hbEta_NNCeta");
	b4CEta1 = (TH1D*)f1->Get("hbEta_NNNCeta");
	
	bCEta0  = (TH1D*)f0->Get("hbEta_Ceta");
	b2CEta0 = (TH1D*)f0->Get("hbEta_NCeta");
	b3CEta0 = (TH1D*)f0->Get("hbEta_NNCeta");
	b4CEta0 = (TH1D*)f0->Get("hbEta_NNNCeta");
	
	bCEta_1  = (TH1D*)f_1->Get("hbEta_Ceta");
	b2CEta_1 = (TH1D*)f_1->Get("hbEta_NCeta");
	b3CEta_1 = (TH1D*)f_1->Get("hbEta_NNCeta");
	b4CEta_1 = (TH1D*)f_1->Get("hbEta_NNNCeta");
	
	bCEta_2  = (TH1D*)f_2->Get("hbEta_Ceta");
	b2CEta_2 = (TH1D*)f_2->Get("hbEta_NCeta");
	b3CEta_2 = (TH1D*)f_2->Get("hbEta_NNCeta");
	b4CEta_2 = (TH1D*)f_2->Get("hbEta_NNNCeta");
	
	bCEta2  = (TH1D*)f2->Get("hbEta_Ceta");
	b2CEta2 = (TH1D*)f2->Get("hbEta_NCeta");
	b3CEta2 = (TH1D*)f2->Get("hbEta_NNCeta");
	b4CEta2 = (TH1D*)f2->Get("hbEta_NNNCeta");
	
	bCEta2_5  = (TH1D*)f2_5->Get("hbEta_Ceta");
	b2CEta2_5 = (TH1D*)f2_5->Get("hbEta_NCeta");
	b3CEta2_5 = (TH1D*)f2_5->Get("hbEta_NNCeta");
	b4CEta2_5 = (TH1D*)f2_5->Get("hbEta_NNNCeta");
	
	bCEta3  = (TH1D*)f3->Get("hbEta_Ceta");
	b2CEta3 = (TH1D*)f3->Get("hbEta_NCeta");
	b3CEta3 = (TH1D*)f3->Get("hbEta_NNCeta");
	b4CEta3 = (TH1D*)f3->Get("hbEta_NNNCeta");
	return;
}
void Set_bquark_lambdaColors()
{
	bjetLPt1->SetLineColor(kRed);
	bjetLPt0->SetLineColor(kBlack);
	bjetLPt_1->SetLineColor(kYellow -9);
	bjetLPt_2->SetLineColor(kGreen);
	bjetLPt2->SetLineColor(kBlue);
	bjetLPt2_5->SetLineColor(kOrange-9);
	bjetLPt3->SetLineColor(kViolet);
	
	bjet2LPt1->SetLineColor(kRed);
	bjet2LPt0->SetLineColor(kBlack);
	bjet2LPt_1->SetLineColor(kYellow -9);
	bjet2LPt_2->SetLineColor(kGreen);
	bjet2LPt2->SetLineColor(kBlue);
	bjet2LPt2_5->SetLineColor(kOrange-9);
	bjet2LPt3->SetLineColor(kViolet);
	
	bjet3LPt1->SetLineColor(kRed);
	bjet3LPt0->SetLineColor(kBlack);
	bjet3LPt_1->SetLineColor(kYellow -9);
	bjet3LPt_2->SetLineColor(kGreen);
	bjet3LPt2->SetLineColor(kBlue);
	bjet3LPt2_5->SetLineColor(kOrange-9);
	bjet3LPt3->SetLineColor(kViolet);
	
	bjet4LPt1->SetLineColor(kRed);
	bjet4LPt0->SetLineColor(kBlack);
	bjet4LPt_1->SetLineColor(kYellow -9);
	bjet4LPt_2->SetLineColor(kGreen);
	bjet4LPt2->SetLineColor(kBlue);
	bjet4LPt2_5->SetLineColor(kOrange-9);
	bjet4LPt3->SetLineColor(kViolet);

	bLPt1->SetLineColor(kRed);
	bLPt0->SetLineColor(kBlack);
	bLPt_1->SetLineColor(kYellow -9);
	bLPt_2->SetLineColor(kGreen);
	bLPt2->SetLineColor(kBlue);
	bLPt2_5->SetLineColor(kOrange-9);
	bLPt3->SetLineColor(kViolet);
	
	b2LPt1->SetLineColor(kRed);
	b2LPt0->SetLineColor(kBlack);
	b2LPt_1->SetLineColor(kYellow -9);
	b2LPt_2->SetLineColor(kGreen);
	b2LPt2->SetLineColor(kBlue);
	b2LPt2_5->SetLineColor(kOrange-9);
	b2LPt3->SetLineColor(kViolet);
	
	b3LPt1->SetLineColor(kRed);
	b3LPt0->SetLineColor(kBlack);
	b3LPt_1->SetLineColor(kYellow -9);
	b3LPt_2->SetLineColor(kGreen);
	b3LPt2->SetLineColor(kBlue);
	b3LPt2_5->SetLineColor(kOrange-9);
	b3LPt3->SetLineColor(kViolet);
	
	b4LPt1->SetLineColor(kRed);
	b4LPt0->SetLineColor(kBlack);
	b4LPt_1->SetLineColor(kYellow -9);
	b4LPt_2->SetLineColor(kGreen);
	b4LPt2->SetLineColor(kBlue);
	b4LPt2_5->SetLineColor(kOrange-9);
	b4LPt3->SetLineColor(kViolet);
	
	bCEta1->SetLineColor(kRed);
	bCEta0->SetLineColor(kBlack);
	bCEta_1->SetLineColor(kYellow -9);
	bCEta_2->SetLineColor(kGreen);
	bCEta2->SetLineColor(kBlue);
	bCEta2_5->SetLineColor(kOrange-9);
	bCEta3->SetLineColor(kViolet);
	
	b2CEta1->SetLineColor(kRed);
	b2CEta0->SetLineColor(kBlack);
	b2CEta_1->SetLineColor(kYellow -9);
	b2CEta_2->SetLineColor(kGreen);
	b2CEta2->SetLineColor(kBlue);
	b2CEta2_5->SetLineColor(kOrange-9);
	b2CEta3->SetLineColor(kViolet);
	
	b3CEta1->SetLineColor(kRed);
	b3CEta0->SetLineColor(kBlack);
	b3CEta_1->SetLineColor(kYellow -9);
	b3CEta_2->SetLineColor(kGreen);
	b3CEta2->SetLineColor(kBlue);
	b3CEta2_5->SetLineColor(kOrange-9);
	b3CEta3->SetLineColor(kViolet);
	
	b4CEta1->SetLineColor(kRed);
	b4CEta0->SetLineColor(kBlack);
	b4CEta_1->SetLineColor(kYellow -9);
	b4CEta_2->SetLineColor(kGreen);
	b4CEta2->SetLineColor(kBlue);
	b4CEta2_5->SetLineColor(kOrange-9);
	b4CEta3->SetLineColor(kViolet);
	return;
}
void Set_LegendProps()
{

	leg_higgs->SetFillStyle(0);
	leg_higgs->SetBorderSize(0);
	leg_higgs->SetTextAlign(32);
	leg_higgs->SetTextFont(62);
	leg_higgs->SetTextSize(0.035);

	leg1->SetFillStyle(0);
	leg1->SetBorderSize(0);
	leg1->SetTextAlign(32);
	leg1->SetTextFont(62);
	leg1->SetTextSize(0.035);

	leg2->SetFillStyle(0);
	leg2->SetBorderSize(0);
	leg2->SetTextAlign(32);
	leg2->SetTextFont(62);
	leg2->SetTextSize(0.035);

	leg3->SetFillStyle(0);
	leg3->SetBorderSize(0);
	leg3->SetTextAlign(32);
	leg3->SetTextFont(62);
	leg3->SetTextSize(0.035);

	leg4->SetFillStyle(0);
	leg4->SetBorderSize(0);
	leg4->SetTextAlign(32);
	leg4->SetTextFont(62);
	leg4->SetTextSize(0.035);
	return;
}


int main()
{
	f1  = new TFile(inp_file1,"READ");
	f0  = new TFile(inp_file0,"READ");
	f_1 = new TFile(inp_file_1,"READ");
	f_2 = new TFile(inp_file_2,"READ");
	f2  = new TFile(inp_file2,"READ");
	f2_5= new TFile(inp_file2_5,"READ");
	f3  = new TFile(inp_file3,"READ");
	
        TH1::SetDefaultSumw2(true);
	fetch_TTrees();
	Set_higgsPtProps();
	Draw_higgsPt();
	fetch_histos();



	//////////////////////////////////////////////////
	//////////////// writing to pdf //////////////////
	//////////////////////////////////////////////////
	char out_file_open[1023];
        sprintf(out_file_open,"%s/%s.pdf(",out_path,output_file_name);
        char out_file_[1023];
        sprintf(out_file_,"%s/%s.pdf",out_path,output_file_name);
        char out_file_close[1023];
        sprintf(out_file_close,"%s/%s.pdf)",out_path,output_file_name);

	Double_t x1 = 0.71, y1 = 0.71, x2 = 0.89, y2 = 0.89;

	leg_higgs = new TLegend(x1, y1, x2, y2, "");
	leg1 = new TLegend(x1, y1, x2, y2, "");
	leg2 = new TLegend(x1, y1, x2, y2, "");
	leg3 = new TLegend(x1, y1, x2, y2, "");
	leg4 = new TLegend(x1, y1, x2, y2, "");

	Set_LegendProps();

	TCanvas * C = new TCanvas();
	//TCanvas * C = new TCanvas("C","C",800,800);
	gStyle->SetOptStat(0);
	//TGaxis::SetMaxDigits(2);
	C->SetGridx();
	C->SetGridy();
	C->SetTickx();
	C->SetTicky();
	C->SetLogy();

	higgsPt1->Draw("hist");	
	higgsPt0->Draw("hist same");	
	higgsPt_1->Draw("hist same");	
	higgsPt_2->Draw("hist same");	
	higgsPt2->Draw("hist same");	
	higgsPt2_5->Draw("hist same");
	higgsPt3->Draw("hist same");
	leg_higgs->AddEntry(higgsPt_2, "#lambda = -2.0");
	leg_higgs->AddEntry(higgsPt_1, "#lambda = -1.0");
	leg_higgs->AddEntry(higgsPt0,  "#lambda =  0.0");
	leg_higgs->AddEntry(higgsPt1,  "#lambda =  1.0");
	leg_higgs->AddEntry(higgsPt2,  "#lambda =  2.0");
	leg_higgs->AddEntry(higgsPt2_5,"#lambda =  2.5");
	leg_higgs->AddEntry(higgsPt3,  "#lambda =  3.0");
	leg_higgs->Draw();
	C->Update();
	C->Print(out_file_open,"pdf");

	higgsNLPt1->Draw("hist");	
	higgsNLPt0->Draw("hist same");	
	higgsNLPt_1->Draw("hist same");	
	higgsNLPt_2->Draw("hist same");	
	higgsNLPt2->Draw("hist same");	
	higgsNLPt2_5->Draw("hist same");
	higgsNLPt3->Draw("hist same");
	leg_higgs->Draw();
	C->Update();
	C->Print(out_file_,"pdf");
	
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	b4LPt1->SetTitle("#lambda = 1.0");
	b4LPt1->Draw("hist");
	b3LPt1->Draw("hist same");
	b2LPt1->Draw("hist same");
	bLPt1->Draw("hist same");
	leg1->AddEntry(bLPt1, "leading");
	leg1->AddEntry(b2LPt1, "sub-leading");
	leg1->AddEntry(b3LPt1, "3^{rd} leading");
	leg1->AddEntry(b4LPt1, "4^{th} leading");
	leg1->Draw();

	C->cd(2);	
	b4LPt0->SetTitle("#lambda = 0.0");
	b4LPt0->Draw("hist");
	b3LPt0->Draw("hist same");
	b2LPt0->Draw("hist same");
	bLPt0->Draw("hist same");
	leg1->Draw();

	C->cd(3);	
	b4LPt_1->SetTitle("#lambda = -1.0");
	b4LPt_1->Draw("hist");
	b3LPt_1->Draw("hist same");
	b2LPt_1->Draw("hist same");
	bLPt_1->Draw("hist same");
	leg1->Draw();

	C->cd(4);	
	b4LPt_2->SetTitle("#lambda = -2.0");
	b4LPt_2->Draw("hist");
	b3LPt_2->Draw("hist same");
	b2LPt_2->Draw("hist same");
	bLPt_2->Draw("hist same");
	leg1->Draw();
	C->Print(out_file_,"pdf");
	
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	b4LPt1->SetTitle("#lambda = 1.0");
	b4LPt1->Draw("hist");
	b3LPt1->Draw("hist same");
	b2LPt1->Draw("hist same");
	bLPt1->Draw("hist same");
	leg1->Draw();
	
	C->cd(2);
	b4LPt2->SetTitle("#lambda = 2.0");
	b4LPt2->Draw("hist");
	b3LPt2->Draw("hist same");
	b2LPt2->Draw("hist same");
	bLPt2->Draw("hist same");
	leg1->Draw();
	
	C->cd(3);
	b4LPt2_5->SetTitle("#lambda = 2.5");
	b4LPt2_5->Draw("hist");
	b3LPt2_5->Draw("hist same");
	b2LPt2_5->Draw("hist same");
	bLPt2_5->Draw("hist same");
	leg1->Draw();
	
	C->cd(4);
	b4LPt3->SetTitle("#lambda = 3.0");
	b4LPt3->Draw("hist");
	b3LPt3->Draw("hist same");
	b2LPt3->Draw("hist same");
	bLPt3->Draw("hist same");
	leg1->Draw();
	C->Print(out_file_,"pdf");


	//! bquark leading for various lambda, 
	//! bquark sub leading for various lambda, 
	//! bquark 3rd leading for various lambda, 
	//! bquark 4th leading for various lambda,
	Set_bquark_lambdaColors(); 
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	bLPt3->Draw("hist ");
	bLPt1->Draw("hist same");
	bLPt2->Draw("hist same");
	bLPt2_5->Draw("hist same");
	bLPt_2->Draw("hist same");
	bLPt_1->Draw("hist same");
	bLPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(2);
	b2LPt3->Draw("hist");
	b2LPt1->Draw("hist same");
	b2LPt2->Draw("hist same");
	b2LPt2_5->Draw("hist same");
	b2LPt_2->Draw("hist same");
	b2LPt_1->Draw("hist same");
	b2LPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(3);
	b3LPt_2->GetXaxis()->SetRangeUser(0,250);
	b3LPt_2->Draw("hist");
	b3LPt3->Draw("hist same");
	b3LPt1->Draw("hist same");
	b3LPt2->Draw("hist same");
	b3LPt2_5->Draw("hist same");
	b3LPt_1->Draw("hist same");
	b3LPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(4);
	b4LPt_2->SetTitle("P_{t} of 4th leading b quark");
	b4LPt_2->GetXaxis()->SetRangeUser(0,150);
	
	b4LPt_2->Draw("hist");
	b4LPt1->Draw("hist same");
	b4LPt2->Draw("hist same");
	b4LPt2_5->Draw("hist same");
	b4LPt3->Draw("hist same");
	b4LPt_1->Draw("hist same");
	b4LPt0->Draw("hist same");
	leg_higgs->Draw();
	C->Print(out_file_,"pdf");

	//! b-jet leading for various lambda, 
	//! b-jet sub leading for various lambda, 
	//! b-jet 3rd leading for various lambda, 
	//! b-jet 4th leading for various lambda,
	Set_bquark_lambdaColors(); 
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	bjetLPt3->Draw("hist ");
	bjetLPt1->Draw("hist same");
	bjetLPt2->Draw("hist same");
	bjetLPt2_5->Draw("hist same");
	bjetLPt_2->Draw("hist same");
	bjetLPt_1->Draw("hist same");
	bjetLPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(2);
	bjet2LPt3->Draw("hist");
	bjet2LPt1->Draw("hist same");
	bjet2LPt2->Draw("hist same");
	bjet2LPt2_5->Draw("hist same");
	bjet2LPt_2->Draw("hist same");
	bjet2LPt_1->Draw("hist same");
	bjet2LPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(3);
	bjet3LPt_2->GetXaxis()->SetRangeUser(0,250);
	bjet3LPt_2->Draw("hist");
	bjet3LPt3->Draw("hist same");
	bjet3LPt1->Draw("hist same");
	bjet3LPt2->Draw("hist same");
	bjet3LPt2_5->Draw("hist same");
	bjet3LPt_1->Draw("hist same");
	bjet3LPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(4);
	bjet4LPt_2->SetTitle("P_{t} of 4th leading b quark");
	bjet4LPt_2->GetXaxis()->SetRangeUser(0,150);
	
	bjet4LPt_2->Draw("hist");
	bjet4LPt1->Draw("hist same");
	bjet4LPt2->Draw("hist same");
	bjet4LPt2_5->Draw("hist same");
	bjet4LPt3->Draw("hist same");
	bjet4LPt_1->Draw("hist same");
	bjet4LPt0->Draw("hist same");
	leg_higgs->Draw();
	C->Print(out_file_,"pdf");
	//! bquark central for various lambda, 
	//! bquark sub Central for various lambda, 
	//! bquark 3rd Central for various lambda, 
	//! bquark 4th Central for various lambda,
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	bCEta3->Draw("hist ");
	bCEta1->Draw("hist same");
	bCEta2->Draw("hist same");
	bCEta2_5->Draw("hist same");
	bCEta_2->Draw("hist same");
	bCEta_1->Draw("hist same");
	bCEta0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(2);
	b2CEta3->Draw("hist");
	b2CEta1->Draw("hist same");
	b2CEta2->Draw("hist same");
	b2CEta2_5->Draw("hist same");
	b2CEta_2->Draw("hist same");
	b2CEta_1->Draw("hist same");
	b2CEta0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(3);
	b3CEta_2->Draw("hist");
	b3CEta3->Draw("hist same");
	b3CEta1->Draw("hist same");
	b3CEta2->Draw("hist same");
	b3CEta2_5->Draw("hist same");
	b3CEta_1->Draw("hist same");
	b3CEta0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(4);
	b4CEta_2->Draw("hist");
	b4CEta1->Draw("hist same");
	b4CEta2->Draw("hist same");
	b4CEta2_5->Draw("hist same");
	b4CEta3->Draw("hist same");
	b4CEta_1->Draw("hist same");
	b4CEta0->Draw("hist same");
	leg_higgs->Draw();
	C->Print(out_file_close,"pdf");
	return 0;
}
