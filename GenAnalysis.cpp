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

void Set_higgsPtProps()
{
	int nbins = 100;
	float ptmin = 0;
	float ptmax = 800;
	higgsPt1  = new TH1D("higgsPt1",  "higgs p_{t};p_{t, higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt0  = new TH1D("higgsPt0",  "higgs p_{t};p_{t, higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt_1 = new TH1D("higgsPt_1", "higgs p_{t};p_{t, higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt_2 = new TH1D("higgsPt_2", "higgs p_{t};p_{t, higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt2  = new TH1D("higgsPt2",  "higgs p_{t};p_{t, higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt2_5= new TH1D("higgsPt2_5","higgs p_{t};p_{t, higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt3  = new TH1D("higgsPt3",  "higgs p_{t};p_{t, higgs} [GeV/c];", nbins, ptmin, ptmax);

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
	
	t1->SetBranchStatus("higgsPt",1);
	t0->SetBranchStatus("higgsPt",1);
	t_1->SetBranchStatus("higgsPt",1);
	t_2->SetBranchStatus("higgsPt",1);
	t2->SetBranchStatus("higgsPt",1);
	t2_5->SetBranchStatus("higgsPt",1);
	t3->SetBranchStatus("higgsPt",1);

	return;
}
void Draw_higgsPt()
{
	
	t1->Draw("higgsPt*1e-3>>higgsPt1");
	t0->Draw("higgsPt*1e-3>>higgsPt0");
	t_1->Draw("higgsPt*1e-3>>higgsPt_1");
	t_2->Draw("higgsPt*1e-3>>higgsPt_2");
	t2->Draw("higgsPt*1e-3>>higgsPt2");
	t2_5->Draw("higgsPt*1e-3>>higgsPt2_5");
	t3->Draw("higgsPt*1e-3>>higgsPt3");
	return;
}

void fetch_histos()
{
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
	return;
}
//void Set_histProps()
//{
//	return;
//}
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

	C->Print(out_file_close,"pdf");
	return 0;
}
