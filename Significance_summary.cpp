
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
#include "TGraphErrors.h"
#include "TPostScript.h"
#include "TDirectory.h"
#include "TAxis.h"
#include "TGaxis.h"
#include "TF1.h"
#include "TLatex.h"
#include "TLegend.h"

#include "Legends.cpp"

const double EvalPT = 35.0;

const int nGraphPts = 9;
const int nlambda = 6;
Double_t lambda[nlambda] = {-2.0, -1.0, 0.0, 1.0, 2.0, 3.0};
Float_t lambda_colors[nlambda] = {kGreen, kYellow-9, kBlack, kRed, kBlue, kViolet};

const char *root_file_name   = "./analysis_plots/root/SignificanceVs4thPt_incl4bProbMH30";
//const char *root_file_name_2 = "./analysis_plots/root/SignificanceVs4thPt_incl4bProbMH30_-2.0.root";
//const char *root_file_name_1 = "./analysis_plots/root/SignificanceVs4thPt_incl4bProbMH30_-1.0.root";
//const char *root_file_name0  = "./analysis_plots/root/SignificanceVs4thPt_incl4bProbMH30_0.0.root";
//const char *root_file_name1  = "./analysis_plots/root/SignificanceVs4thPt_incl4bProbMH30_1.0.root";
//const char *root_file_name2  = "./analysis_plots/root/SignificanceVs4thPt_incl4bProbMH30_2.0.root";
//const char *root_file_name3  = "./analysis_plots/root/SignificanceVs4thPt_incl4bProbMH30_3.0.root";

const char *out_path = "./analysis_plots/pdf"; 
const char *output_file_name = "Significance_Summary_incl4bProbMH30";

Float_t max_range, min_range;
Float_t LINE_WIDTH = 2.5;
Float_t TITLE_SIZE = 0.04;
Float_t MARKER_SIZE = 1.2;
Float_t AXISTITLE_OFFSET = 0.8;
Float_t YAXISTITLE_OFFSET = 1.5;
Float_t LEFT_MARGIN = 0.15;
////////////////////////////////////
Float_t FILL_STYLE = 0;
Float_t BORDER_SIZE = 0;
Float_t TEXT_ALIGN = 32;
Float_t TEXT_FONT = 62;
Float_t TEXT_SIZE = 0.04;
Float_t Xl1 = 0.16, Yu1 = 0.6, Xl2 = 0.36, Yu2 = 0.89;
Float_t Xr1 = 0.65, Ym1 = 0.5, Xr2 = 0.85, Ym2 = 0.76;
void plot()
{
	Legends();
	TMultiGraph *mg = new TMultiGraph();
	TGraphErrors *SBatPt = nullptr;
	TMultiGraph *mg1 = new TMultiGraph();
	TGraphErrors *ZatPt = nullptr;
	TMultiGraph *mg2 = new TMultiGraph();
	TGraphErrors *Zi_cont = nullptr;
	
	TGraph *SBat30 = new TGraph(nlambda);
	TGraph *Zat30 = new TGraph(nlambda);

	TLegend *leg = new TLegend(Xl1, Yu1, Xl2, Yu2);
	leg->SetFillStyle(FILL_STYLE);
	leg->SetBorderSize(BORDER_SIZE);
	leg->SetTextAlign(TEXT_ALIGN);
	leg->SetTextFont(TEXT_FONT);
	leg->SetTextSize(TEXT_SIZE);
	
	TLegend *legR = new TLegend(Xr1, Ym1, Xr2, Ym2);
	legR->SetFillStyle(FILL_STYLE);
	legR->SetBorderSize(BORDER_SIZE);
	legR->SetTextAlign(TEXT_ALIGN);
	legR->SetTextFont(TEXT_FONT);
	legR->SetTextSize(TEXT_SIZE);
	
	char fname[1024];
	TFile *f = nullptr;
	for(int k = 0; k < nlambda; k++)
	{
		//! open root file
		sprintf(fname, "%s_%.1f.root", root_file_name, lambda[k]);
		f = new TFile(fname, "READ");
		
		TString gname2;	
		//! plot total S/b vs pT of 4th b-jet	
		if(lambda[k] < 0){gname2.Form("GrSB__%d",(int)std::abs(lambda[k]));}
		else {gname2.Form("GrSB_%d", (int)std::abs(lambda[k]));}	
		
		SBatPt = (TGraphErrors*)f->Get("g1");
		SBatPt->SetName(gname2);
		SBatPt->SetLineColor(lambda_colors[k]);
		mg->Add(SBatPt);

		//! plot total significance Vs pT of 4th b-jet
		if(lambda[k] < 0){gname2.Form("Gr__%d",(int)std::abs(lambda[k]));}
		else {gname2.Form("Gr_%d", (int)std::abs(lambda[k]));}	
		
		ZatPt = (TGraphErrors*)f->Get("g2");
		ZatPt->SetName(gname2);
		ZatPt->SetLineColor(lambda_colors[k]);
		mg1->Add(ZatPt);
		

		//! plot ith pT bin contribution to significance2 Vs pT bin of 4th b-jet
		if(lambda[k] < 0){gname2.Form("Grcont__%d",(int)std::abs(lambda[k]));}
		else {gname2.Form("Grcont_%d", (int)std::abs(lambda[k]));}	
		
		Zi_cont = (TGraphErrors*)f->Get("G3");
		//Zi_cont->RemovePoint(8);
		Zi_cont->SetName(gname2);
		Zi_cont->SetLineColor(lambda_colors[k]);
		mg2->Add(Zi_cont);

		//! plot Significance and S/B with 4th bjet pt threshold =30GeV/c Vs k_lambda
		Zat30->SetPoint(k, lambda[k], ZatPt->Eval(EvalPT));
		SBat30->SetPoint(k, lambda[k], SBatPt->Eval(EvalPT));

		//! draw a k_lambda legend.
		if(lambda[k] < 0)
		{
			leg->AddEntry(ZatPt,Form("k_{#lambda} = %.1f", lambda[k]),"l");
			legR->AddEntry(ZatPt,Form("k_{#lambda} = %.1f", lambda[k]),"l");
		}
		else
		{
			leg->AddEntry(ZatPt,Form("k_{#lambda} =  %.1f", lambda[k]),"l");
			legR->AddEntry(ZatPt,Form("k_{#lambda} =  %.1f", lambda[k]),"l");
		}

	}
	
	char out_root_file_name[1024];
        sprintf(out_root_file_name,"%s/../root/%s.root",out_path,output_file_name);
	TFile *fout = new TFile(out_root_file_name,"RECREATE");
	char out_file_open[1024];
	char out_file_[1024];
	char out_file_close[1024];
        sprintf(out_file_open,"%s/%s.pdf(",out_path,output_file_name);
        sprintf(out_file_,"%s/%s.pdf",out_path,output_file_name);
        sprintf(out_file_close,"%s/%s.pdf)",out_path,output_file_name);
	
	TCanvas *c1 = new TCanvas("c1","c1", 800, 800);
	gStyle->SetOptTitle(0);	
        c1->SetLeftMargin(LEFT_MARGIN);
	mg->Draw("ACP");
	mg->GetXaxis()->SetTitle("p_{T,bJ4} threshold [GeV/c]");
	mg->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	mg->GetYaxis()->SetTitle("#sum_{i}^{500} S_{i}/B_{i}");
	mg->GetYaxis()->SetTitleSize(TITLE_SIZE);
	mg->GetXaxis()->SetTitleSize(TITLE_SIZE);
	mg->GetYaxis()->CenterTitle();
	mg->GetXaxis()->CenterTitle();
	max_range = mg->GetHistogram()->GetMaximum()*1.3;
	min_range = mg->GetHistogram()->GetMinimum()*0.4;
	mg->GetYaxis()->SetRangeUser(min_range, max_range);
cms_E->Draw();	
signal_->Draw();	
ana_txt->Draw();	
legR->Draw();
	c1->Print(out_file_open,"pdf");
	c1->Write("mgSB");
	c1->SaveAs("./analysis_plots/tex/mgSB.tex");

	mg1->Draw("ACP");
	mg1->GetXaxis()->SetTitle("p_{T,bJ4} threshold [GeV/c]");
	mg1->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	mg1->GetYaxis()->SetTitle("#sqrt{#sum_{i}^{500} Z_{i}^{2}}");
	mg1->GetYaxis()->SetTitleSize(TITLE_SIZE);
	mg1->GetXaxis()->SetTitleSize(TITLE_SIZE);
	mg1->GetYaxis()->CenterTitle();
	mg1->GetXaxis()->CenterTitle();
	max_range = mg1->GetHistogram()->GetMaximum()*1.3;
	min_range = mg1->GetHistogram()->GetMinimum()*0.4;
	mg1->GetYaxis()->SetRangeUser(min_range, max_range);
cms_E->Draw();	
signal_->Draw();	
ana_txt->Draw();	
legR->Draw();
	c1->Print(out_file_,"pdf");
	c1->Write("mgZsum");
	c1->SaveAs("./analysis_plots/tex/mgZsum.tex");

	mg2->Draw("ACP");
	mg2->GetXaxis()->SetTitle("p_{T,bJ4} [GeV/c]");
	mg2->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	mg2->GetYaxis()->SetTitle("Z_{i}/Z_{tot}");
	mg2->GetYaxis()->SetTitleSize(TITLE_SIZE);
	mg2->GetXaxis()->SetTitleSize(TITLE_SIZE);
	mg2->GetYaxis()->CenterTitle();
	mg2->GetXaxis()->CenterTitle();
	max_range = mg2->GetHistogram()->GetMaximum()*1.3;
	min_range = mg2->GetHistogram()->GetMinimum()*0.4;
	mg2->GetYaxis()->SetRangeUser(min_range, max_range);
cms_E->Draw();	
signal_->Draw();	
ana_txt->Draw();
leg->Draw();
	c1->Print(out_file_,"pdf");
	c1->Write("mgZiZtot");
	c1->SaveAs("./analysis_plots/tex/mgZiZtot.tex");

	TLegend *pTbJ4 = new TLegend(0.12,0.14,0.3,0.23);
	pTbJ4->SetFillStyle(0);
	pTbJ4->SetBorderSize(0);
	pTbJ4->AddEntry((TObject*)0, Form("p_{T, bJ4} thr. = %.1f GeV/c",EvalPT), "");
	pTbJ4->SetTextSize(0.04);
	
	Zat30->Draw("ACP");
	Zat30->GetXaxis()->SetTitle("k_{#lambda}");
	Zat30->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	Zat30->GetYaxis()->SetTitle("Significance Z");
	Zat30->GetYaxis()->SetTitleSize(TITLE_SIZE);
	Zat30->GetXaxis()->SetTitleSize(TITLE_SIZE);
	Zat30->GetYaxis()->CenterTitle();
	Zat30->GetXaxis()->CenterTitle();
	Zat30->SetMarkerStyle(kFullCircle);
	Zat30->SetLineWidth(LINE_WIDTH);
	Zat30->SetMarkerSize(MARKER_SIZE);
	pTbJ4->Draw();
cms_E->Draw();	
signal_->Draw();	
ana_txt->Draw();	
	c1->Print(out_file_,"pdf");
	c1->Write("gZatpT");
	c1->SaveAs("./analysis_plots/tex/gZatpT.tex");

	SBat30->Draw("ACP");
	SBat30->GetXaxis()->SetTitle("k_{#lambda}");
	SBat30->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	SBat30->GetYaxis()->SetTitle("S/B");
	SBat30->GetYaxis()->SetTitleSize(TITLE_SIZE);
	SBat30->GetXaxis()->SetTitleSize(TITLE_SIZE);
	SBat30->GetYaxis()->CenterTitle();
	SBat30->GetXaxis()->CenterTitle();
	SBat30->SetMarkerStyle(kFullCircle);
	SBat30->SetLineWidth(LINE_WIDTH);
	SBat30->SetMarkerSize(MARKER_SIZE);
	pTbJ4->Draw();
cms_E->Draw();	
signal_->Draw();	
ana_txt->Draw();	
	c1->Print(out_file_,"pdf");
	c1->Write("gSBatpT");
	c1->SaveAs("./analysis_plots/tex/gSBatpT.tex");

	c1->Clear();
	leg->Draw();
	c1->Print(out_file_close,"pdf");
	c1->Write("k_lambdaLeg");

	fout->Close();


	return;
}
