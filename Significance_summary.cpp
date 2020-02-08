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

const int nGraphPts = 7;
Double_t EvalPT[nGraphPts] = {20., 30., 40., 50., 60., 70., 80.};
Float_t EvalPTColors[nGraphPts] = {kViolet, kOrange, kBlue, kGreen, kGray+1, kRed, kBlack};

//double EvalPT = 35.0;
const int nlambda = 6;
Double_t lambda[nlambda] = {-2.0, -1.0, 0.0, 1.0, 2.0, 3.0};
Float_t lambda_colors[nlambda] = {kGreen, kGray +1, kBlack, kRed, kBlue, kViolet};

const char *root_file_name   = "./analysis_plots/root/SignificanceVs4thPt_incl4bProbMH30";
const char *root_file_name1   = "./analysis_plots/root/Sensitivity_studyVsk_lambda_corrected_incl4bProbMH30_final.root";
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
	
	//TGraph *mgSBfor_k = new TGraph(nlambda);
	//TGraph *mgZfor_k = new TGraph(nlambda);
	TMultiGraph *mgSBfor_k = new TMultiGraph();
	TMultiGraph *mgZfor_k  = new TMultiGraph();
	TMultiGraph *mgSensfor_k  = new TMultiGraph();

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

	TLegend *pTbJ4 = new TLegend(Xr1,Ym1,Xr2,Ym2);
	pTbJ4->SetHeader("p_{T, bJ4} thr. [GeV/c]","C");
	pTbJ4->AddEntry((TObject*)0, " ", "");
	TLegendEntry *header = (TLegendEntry*)pTbJ4->GetListOfPrimitives()->First();
   	header->SetTextAlign(kHAlignCenter+kVAlignTop);
	pTbJ4->SetFillStyle(FILL_STYLE);
	pTbJ4->SetBorderSize(BORDER_SIZE);
	pTbJ4->SetTextAlign(21);
	//pTbJ4->SetTextAlign(TEXT_ALIGN);
	pTbJ4->SetTextSize(TEXT_SIZE);


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
		f->Close();
		
	}
	//delete SBatPt;
	//delete ZatPt;
	//delete Zi_cont;
	//delete f;
		
	TFile *f1 = new TFile(root_file_name1, "READ");
	for(int i = 0; i < nGraphPts; ++i)
	{
		
		TString gname1;	
		//! plot total S/b vs pT of 4th b-jet	
		gname1.Form("GrSB__%d",(int)std::abs(EvalPT[i]));
		TGraph *SBat_Thi = new TGraph(nlambda);
		SBat_Thi->SetName(gname1);
		SBat_Thi->SetLineColor(EvalPTColors[i]);

		gname1.Form("GrZ__%d",(int)std::abs(EvalPT[i]));
		TGraph *Zat_Thi = new TGraph(nlambda);
		Zat_Thi->SetName(gname1);
		Zat_Thi->SetLineColor(EvalPTColors[i]);
		
		gname1.Form("GrSens__%d",(int)std::abs(EvalPT[i]));
		TGraph *Sensat_Thi = new TGraph(nlambda);
		Sensat_Thi->SetName(gname1);
		Sensat_Thi->SetLineColor(EvalPTColors[i]);
		

		SBat_Thi->SetMarkerStyle(kFullCircle);
		SBat_Thi->SetLineWidth(LINE_WIDTH);
		SBat_Thi->SetMarkerSize(MARKER_SIZE);
		
		Zat_Thi->SetMarkerStyle(kFullCircle);
		Zat_Thi->SetLineWidth(LINE_WIDTH);
		Zat_Thi->SetMarkerSize(MARKER_SIZE);
		
		Sensat_Thi->SetMarkerStyle(kFullCircle);
		Sensat_Thi->SetLineWidth(LINE_WIDTH);
		Sensat_Thi->SetMarkerSize(MARKER_SIZE);

		for(int k = 0; k < nlambda; ++k)
		{
			//! open root file
			sprintf(fname, "%s_%.1f.root", root_file_name, lambda[k]);
			f = new TFile(fname, "READ");
			
			SBatPt = (TGraphErrors*)f->Get("g1");

			ZatPt = (TGraphErrors*)f->Get("g2");
			
			TString gname2;	
			//! plot total S/b vs pT of 4th b-jet	
			if(lambda[k] < 0){gname2.Form("Sens_withPt_klambda__%d",(int)std::abs(lambda[k]));}
			else {gname2.Form("Sens_withPt_klambda_%d", (int)std::abs(lambda[k]));}	
			TGraph *sens = (TGraph*)f1->Get(gname2);	
			//! plot Significance and S/B with 4th bjet pt threshold =30GeV/c Vs k_lambda
			SBat_Thi->SetPoint(k, lambda[k], SBatPt->Eval(EvalPT[i]));
			Zat_Thi->SetPoint(k, lambda[k], ZatPt->Eval(EvalPT[i]));
			Sensat_Thi->SetPoint(k, lambda[k], sens->Eval(EvalPT[i]));
			
			f->Close();

		}
		mgSBfor_k->Add(SBat_Thi);
		mgZfor_k->Add(Zat_Thi);
		mgSensfor_k->Add(Sensat_Thi);
		
		//pTbJ4->AddEntry((TObject*)0, Form(" %.1f",EvalPT[i]), "");
		pTbJ4->AddEntry(Zat_Thi, Form("%.1f",EvalPT[i]), "l");
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
	max_range = mg1->GetHistogram()->GetMaximum()*1.5;
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
	max_range = mg2->GetHistogram()->GetMaximum()*1.5;
	min_range = mg2->GetHistogram()->GetMinimum()*0.4;
	mg2->GetYaxis()->SetRangeUser(min_range, max_range);
cms_E->Draw();	
signal_->Draw();	
ana_txt->Draw();
leg->Draw();
	c1->Print(out_file_,"pdf");
	c1->Write("mgZiZtot");
	c1->SaveAs("./analysis_plots/tex/mgZiZtot.tex");

	
	mgZfor_k->Draw("ACP");
	mgZfor_k->GetXaxis()->SetTitle("k_{#lambda}");
	mgZfor_k->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	mgZfor_k->GetYaxis()->SetTitle("Significance Z");
	mgZfor_k->GetYaxis()->SetTitleSize(TITLE_SIZE);
	mgZfor_k->GetXaxis()->SetTitleSize(TITLE_SIZE);
	mgZfor_k->GetYaxis()->CenterTitle();
	mgZfor_k->GetXaxis()->CenterTitle();
	//mgZfor_k->SetMarkerStyle(kFullCircle);
	//mgZfor_k->SetLineWidth(LINE_WIDTH);
	//mgZfor_k->SetMarkerSize(MARKER_SIZE);
	max_range = mgZfor_k->GetHistogram()->GetMaximum()*1.5;
	min_range = mgZfor_k->GetHistogram()->GetMinimum()*0.4;
	mgZfor_k->GetYaxis()->SetRangeUser(min_range, max_range);
	pTbJ4->Draw();
cms_E->Draw();	
signal_->Draw();	
ana_txt->Draw();	
	c1->Print(out_file_,"pdf");
	c1->Write("gZatpT");
	c1->SaveAs("./analysis_plots/tex/gZatpT.tex");

	mgSBfor_k->Draw("ACP");
	mgSBfor_k->GetXaxis()->SetTitle("k_{#lambda}");
	mgSBfor_k->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	mgSBfor_k->GetYaxis()->SetTitle("S/B");
	mgSBfor_k->GetYaxis()->SetTitleSize(TITLE_SIZE);
	mgSBfor_k->GetXaxis()->SetTitleSize(TITLE_SIZE);
	mgSBfor_k->GetYaxis()->CenterTitle();
	mgSBfor_k->GetXaxis()->CenterTitle();
	//mgSBfor_k->SetMarkerStyle(kFullCircle);
	//mgSBfor_k->SetLineWidth(LINE_WIDTH);
	//mgSBfor_k->SetMarkerSize(MARKER_SIZE);
	max_range = mgSBfor_k->GetHistogram()->GetMaximum()*1.5;
	min_range = mgSBfor_k->GetHistogram()->GetMinimum()*0.4;
	mgSBfor_k->GetYaxis()->SetRangeUser(min_range, max_range);
	pTbJ4->Draw();
cms_E->Draw();	
signal_->Draw();	
ana_txt->Draw();	
	c1->Print(out_file_,"pdf");
	c1->Write("gSBatpT");
	c1->SaveAs("./analysis_plots/tex/gSBatpT.tex");
	
	mgSensfor_k->Draw("ACP");
	mgSensfor_k->GetXaxis()->SetTitle("k_{#lambda}");
	mgSensfor_k->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	mgSensfor_k->GetYaxis()->SetTitle("Sensitivity");
	mgSensfor_k->GetYaxis()->SetTitleSize(TITLE_SIZE);
	mgSensfor_k->GetXaxis()->SetTitleSize(TITLE_SIZE);
	mgSensfor_k->GetYaxis()->CenterTitle();
	mgSensfor_k->GetXaxis()->CenterTitle();
	//mgSensfor_k->SetMarkerStyle(kFullCircle);
	//mgSensfor_k->SetLineWidth(LINE_WIDTH);
	//mgSensfor_k->SetMarkerSize(MARKER_SIZE);
	max_range = mgSensfor_k->GetHistogram()->GetMaximum()*1.5;
	min_range = mgSensfor_k->GetHistogram()->GetMinimum()*0.4;
	mgSensfor_k->GetYaxis()->SetRangeUser(min_range, max_range);
	pTbJ4->Draw();
cms_E->Draw();	
signal_->Draw();	
ana_txt->Draw();	
	c1->Print(out_file_,"pdf");
	c1->Write("gSensatpT");
	c1->SaveAs("./analysis_plots/tex/gSensatpT.tex");

	gStyle->SetOptStat(0);	
	TString hi_name;
	for(int k = nlambda-1; k > -1; --k)
	{
		if(lambda[k] < 0){hi_name.Form("h4_S2overBi_%d",(int)std::abs(lambda[k]));}
		else {hi_name.Form("h4_S2overBi%d", (int)std::abs(lambda[k]));}
		TH1D *h4s2b = (TH1D*)f1->Get(hi_name);
		
		if(lambda[k] == 3.0) 
		{
			max_range = h4s2b->GetMaximum() * 1.5;
			min_range = h4s2b->GetMinimum() * 0.4;
			h4s2b->GetYaxis()->SetRangeUser(min_range, max_range);
			c1->SetLogx();
			h4s2b->Draw("pe1");

		}
		else h4s2b->Draw("pe1 same");
	}
	leg->Draw();
cms_E->Draw();	
signal_->Draw();	
ana_txt->Draw();	
	c1->Print(out_file_,"pdf");
	c1->Write("hist_Zi2Z2tot");
	c1->SaveAs("./analysis_plots/tex/hist_Zi2Z2tot.tex");

	for(int k = nlambda-1; k > -1; --k)
	{
		if(lambda[k] < 0){hi_name.Form("Sens_contri_klambda__%d",(int)std::abs(lambda[k]));}
                else {hi_name.Form("Sens_contri_klambda_%d", (int)std::abs(lambda[k]));}
		TH1D *h4sens2_cont = (TH1D*)f1->Get(hi_name);
		if(lambda[k] == 3.0) 
		{
			max_range = h4sens2_cont->GetMaximum() * 1.5;
			min_range = h4sens2_cont->GetMinimum() * -1.0;
			h4sens2_cont->GetYaxis()->SetRangeUser(min_range, max_range);
			c1->SetLogx();
			h4sens2_cont->Draw("pe1");

		}
		else h4sens2_cont->Draw("pe1 same");
	}
	leg->Draw();
cms_E->Draw();	
signal_->Draw();	
ana_txt->Draw();	
	c1->Print(out_file_,"pdf");
	c1->Write("hist_sensi2sens2tot");
	c1->SaveAs("./analysis_plots/tex/hist_sensi2sens2tot.tex");
	f1->Close();
	
	c1->Clear();
	leg->Draw();
	c1->Print(out_file_close,"pdf");
	c1->Write("k_lambdaLeg");

	fout->Close();


	return;
}
