///// Rebinning : https://root.cern.ch/doc/master/classTH1.html#aff6520fdae026334bf34fa1800946790
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

const int n = 10;
const int nGraphPts = 9;
const float ctr = 2.5;
//const char *root_file_name = "./analysis_plots/root/GenJet4b2_2.5_allR0.4_0.8_incl4bProb.root";
const char *root_file_name = "./analysis_plots/root/GenJet4b2_2.5_allR0.4_0.8_incl4bProbMH30.root";
const char *txt_path = "./analysis_plots/txt_files";
const char *out_path = "./analysis_plots/pdf"; 
const char *output_file_name = "SignificanceVs4thPt_incl4bProbMH30";

Float_t LINE_WIDTH = 2.5;
Float_t TITLE_SIZE = 0.04;
Float_t MARKER_SIZE = 1.2;
Float_t AXISTITLE_OFFSET = 0.8;
Float_t YAXISTITLE_OFFSET = 1.2;
Float_t max_range;
Float_t min_range;

//! 100TeV
const double IntLumi      = 3e4;//fb-1 -> 10 ab-1(projected luminosity is 30 ab-1 not 10 ab-1)
const double pp4bXsec     = 23.283e6;//fb, NLO Xsection// k-factor 1.6// LO 14.552e6 +- 12.16e3
const double ggFhhXsec2_5 = 523.907;
const double four_b_Prob  = std::pow(0.58,2);
int tot_MCevents = 5e5;

double norm_signal, norm_bckgnd;

Int_t nbinsMinus = n - 1; 
Double_t pt_bins[n] = {20., 30., 40., 50., 60., 70., 80., 90., 100., 500.};
Int_t   nAna[n]        = {0};
Int_t   nAnaB[n]        = {0};

Float_t SoverB[n]      = {0};

Float_t Significance1[n]   = {0};
Float_t Significance2[n]   = {0};
Float_t Significance2_[n]  = {0};

Float_t SignificanceGain1[n]   = {0};
Float_t SignificanceGain2[n]   = {0};

Float_t pT_threshold[n] = {0};
//! Book histograms
TH1D *Ana_bjet4LPt = nullptr; 
TH1D *Ana_bjet4LPtB = nullptr; 
TH1 *h4_sig   = nullptr;
TH1 *h4_bg     = nullptr;

TH1D *h4_SoverB        = nullptr;
TH1D *h4_Significance1   = nullptr;
TH1D *h4_Significance2   = nullptr;

TGraphErrors *g1 = nullptr;
TGraphErrors *g2 = nullptr;
TGraphErrors *g3 = nullptr;
TGraphErrors *G2 = nullptr;
TGraphErrors *G2_ = nullptr;
TGraphErrors *G3 = nullptr;
void plot_VsPt2_5()
{

	TFile *f = new TFile(root_file_name, "READ");
	Ana_bjet4LPt = (TH1D*)f->Get("Ana_bjet4LPt2_5");
	Ana_bjet4LPtB = (TH1D*)f->Get("Ana_bjet4LPtB");
	h4_sig = Ana_bjet4LPt->Rebin(nbinsMinus, "h4_sig", pt_bins);
	h4_bg   = Ana_bjet4LPtB->Rebin(nbinsMinus, "h4_bg", pt_bins);
	//h4_sig = (TH1D*)f->Get("Ana_bjet4LPt2_5");
	//h4_bg   = (TH1D*)f->Get("Ana_bjet4LPtB");

	norm_signal   = (IntLumi * four_b_Prob * ggFhhXsec2_5)/tot_MCevents;
	norm_bckgnd   = (IntLumi * pp4bXsec)/tot_MCevents;
	
	int nbins = h4_sig->GetNbinsX();
	int nbinsB = h4_bg->GetNbinsX();
	assert(nbins == nbinsB);
	std::cout<<"number of bins: " <<nbins <<std::endl;

	h4_SoverB  = new TH1D("h4_SoverB", "SoverB Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus, pt_bins);
	h4_Significance1  = new TH1D("h4_Significance1", "Significance Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus, pt_bins);
	h4_Significance2  = new TH1D("h4_Significance2", "Significance square Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus, pt_bins);

        //! write to a text file
	std::cout<<"Writing to txt file...." <<std::endl;
        char txt_file[1023];
        sprintf(txt_file,"%s/Significance_%.1f_1.txt",txt_path, ctr);
        std::ofstream ofs;
 	ofs.open (txt_file, std::ofstream::out | std::ofstream::app);
	ofs<<"pT " <<"N_S " <<"N_B " <<"Nnorm_S " <<"Nnorm_B " <<"S/B " << "S/sqrt(B) "<<"S2/B\n";	
	for(int i = 1; i < n + 1; i++)
	{

		//std::cout<<"i" << i <<std::endl;
		//! Fill into arrays and plot graph
		pT_threshold[i-1] = h4_sig->GetBinLowEdge(i);
		nAna[i-1]        = h4_sig->GetBinContent(i);
		nAnaB[i-1]        = h4_bg->GetBinContent(i);

		if(nAnaB[i-1] != 0)
		{
			SoverB[i-1]      = (nAna[i-1] * norm_signal)/(nAnaB[i-1] * norm_bckgnd);
			Significance1[i-1] = (nAna[i-1] * norm_signal)/std::sqrt(nAnaB[i-1] * norm_bckgnd);
			Significance2[i-1] = std::pow(nAna[i-1] * norm_signal, 2)/(nAnaB[i-1] * norm_bckgnd);
		}
		h4_SoverB->SetBinContent(i, SoverB[i-1]);
		h4_Significance1->SetBinContent(i, Significance1[i-1]);
		h4_Significance2->SetBinContent(i, Significance2[i-1]);

        	ofs<<pT_threshold[i-1]<<" "<<nAna[i-1]<<" "<<nAnaB[i-1]<<" "<<nAna[i-1]*norm_signal<<" "<<nAnaB[i-1]*norm_bckgnd<<" "<<SoverB[i-1]<<" "<<Significance1[i-1]<<" "<<Significance2[i-1]<<"\n";
	}
	ofs.close();

	return;
}

void plot_graph()
{

	TCanvas *c = new TCanvas("c","c",800,800);
	plot_VsPt2_5();
	c->SetLeftMargin(0.13);
	TGaxis::SetMaxDigits(3);
	h4_sig->Draw("hist");	
	h4_bg->Draw("hist");	
	//! Significance square per bin
	h4_Significance2->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	h4_Significance2->GetYaxis()->SetTitle("S^{2}/B");
	h4_Significance2->GetYaxis()->SetTitleSize(TITLE_SIZE);
	h4_Significance2->GetXaxis()->SetTitleSize(TITLE_SIZE);
	h4_Significance2->GetYaxis()->CenterTitle();
	h4_Significance2->GetXaxis()->CenterTitle();
	h4_Significance2->SetLineColor(kRed);
	h4_Significance2->SetLineWidth(LINE_WIDTH);
	h4_Significance2->Draw("hist");
	//! Significance per bin
	h4_Significance1->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	h4_Significance1->GetYaxis()->SetTitle("S/#sqrt{B}");
	h4_Significance1->GetYaxis()->SetTitleSize(TITLE_SIZE);
	h4_Significance1->GetXaxis()->SetTitleSize(TITLE_SIZE);
	h4_Significance1->GetYaxis()->CenterTitle();
	h4_Significance1->GetXaxis()->CenterTitle();
	h4_Significance1->SetLineColor(kRed);
	h4_Significance1->SetLineWidth(LINE_WIDTH);
	h4_Significance1->Draw("hist");
	//! SoverB per bin
	h4_SoverB->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	h4_SoverB->GetYaxis()->SetTitle("S/B");
	h4_SoverB->GetYaxis()->SetTitleSize(TITLE_SIZE);
	h4_SoverB->GetXaxis()->SetTitleSize(TITLE_SIZE);
	h4_SoverB->GetYaxis()->CenterTitle();
	h4_SoverB->GetXaxis()->CenterTitle();
	h4_SoverB->SetLineColor(kRed);
	h4_SoverB->SetLineWidth(LINE_WIDTH);
	h4_SoverB->Draw("hist");
	
	//Significance1[nGraphPts] = Significance1[nGraphPts-1];// this will make the gain for the last pt = 1
	//Significance2[nGraphPts] = Significance2[nGraphPts-1];// this will make the gain for the last pt = 1
	for(int i = 0; i < nGraphPts; i++)
	{
		SignificanceGain1[i] = Significance1[i]/h4_Significance1->Integral(1,nGraphPts); 
		SignificanceGain2[i] = Significance2[i]/h4_Significance2->Integral(1, nGraphPts); 
	}
	for(int i = 0; i < nGraphPts; i++)
	{
		//! 1st integral is bin 1(contents in 20-30 GeV) to 9(contents in 100 - 500 GeV)
		//! last integral is bin 9(contents in 100-500 GeV) to 9(contents in 100 - 500 GeV)
		SoverB[i] = h4_SoverB->Integral(i+1, nGraphPts);
		Significance2[i] = h4_Significance2->Integral(i+1, nGraphPts);
		Significance1[i] = std::sqrt(Significance2[i]);
		//Significance1[i] = h4_Significance1->Integral(i+1, nGraphPts);
		Significance2_[i] = h4_Significance2->Integral(1, i+1);
	}
	//! SoverB Vs Pt threshold 
	g1 = new TGraphErrors(nGraphPts, pT_threshold, SoverB,0,0);
	g1->GetXaxis()->SetTitle("p_{T, bJ4} [GeV/c]");
	g1->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	g1->GetYaxis()->SetTitle("#sum_{i}^{500}S/B");
	g1->GetYaxis()->SetTitleSize(TITLE_SIZE);
	g1->GetXaxis()->SetTitleSize(TITLE_SIZE);
	g1->GetYaxis()->CenterTitle();
	g1->GetXaxis()->CenterTitle();
	g1->SetMarkerStyle(kFullCircle);//kFullCircle);
	g1->SetLineColor(kRed);
	g1->SetLineWidth(LINE_WIDTH);
	g1->SetMarkerSize(MARKER_SIZE);
	g1->SetTitle("hh #rightarrow 4b S/B Vs 4^{th} leading jet p_{T}");
	g1->Draw("ACPe1");
	max_range = g1->GetHistogram()->GetMaximum()*1.3;
	min_range = g1->GetHistogram()->GetMinimum()*0.4;
	g1->GetYaxis()->SetRangeUser(min_range, max_range);
	
	//! Significance Vs Pt threshold 
	g2 = new TGraphErrors(nGraphPts, pT_threshold, Significance1,0,0);
	g2->GetXaxis()->SetTitle("p_{T, bJ4} [GeV/c]");
	g2->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	//g2->GetYaxis()->SetTitle("#sum_{i}^{500}S_{i}/#sqrt{B}_{i}");
	g2->GetYaxis()->SetTitle("#sqrt{#sum_{i}^{500}S_{i}^{2}/B_{i}}");
	g2->GetYaxis()->SetTitleSize(TITLE_SIZE);
	g2->GetXaxis()->SetTitleSize(TITLE_SIZE);
	g2->GetYaxis()->CenterTitle();
	g2->GetXaxis()->CenterTitle();
	g2->SetMarkerStyle(kFullCircle);//kFullCircle);
	g2->SetLineColor(kRed);
	g2->SetLineWidth(LINE_WIDTH);
	g2->SetMarkerSize(MARKER_SIZE);
	g2->SetTitle("hh #rightarrow 4b Total Significance Vs 4^{th} leading jet p_{T}");
	g2->Draw("ACPe1");
	max_range = g2->GetHistogram()->GetMaximum()*1.3;
	min_range = g2->GetHistogram()->GetMinimum()*0.4;
	g2->GetYaxis()->SetRangeUser(min_range, max_range);
	
	//! Significance square Vs Pt threshold from i to 500 GeV/c
	G2 = new TGraphErrors(nGraphPts, pT_threshold, Significance2,0,0);
	G2->GetXaxis()->SetTitle("p_{T, bJ4} [GeV/c]");
	G2->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	G2->GetYaxis()->SetTitle("#sum_{i}^{500}S_{i}^{2}/B_{i}");
	G2->GetYaxis()->SetTitleSize(TITLE_SIZE);
	G2->GetXaxis()->SetTitleSize(TITLE_SIZE);
	G2->GetYaxis()->CenterTitle();
	G2->GetXaxis()->CenterTitle();
	G2->SetMarkerStyle(kFullCircle);//kFullCircle);
	G2->SetLineColor(kRed);
	G2->SetLineWidth(LINE_WIDTH);
	G2->SetMarkerSize(MARKER_SIZE);
	G2->SetTitle("hh #rightarrow 4b (Significance)^{2} Vs 4^{th} leading jet p_{T}");
	G2->Draw("ACPe1");
	max_range = G2->GetHistogram()->GetMaximum()*1.3;
	min_range = G2->GetHistogram()->GetMinimum()*0.4;
	G2->GetYaxis()->SetRangeUser(min_range, max_range);
	
	//! Significance square Vs Pt threshold from 20 to i GeV/c
	G2_ = new TGraphErrors(nGraphPts, pT_threshold, Significance2_,0,0);
	G2_->GetXaxis()->SetTitle("p_{T, bJ4} [GeV/c]");
	G2_->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	G2_->GetYaxis()->SetTitle("#sum_{20}^{i}S_{i}^{2}/B_{i}");
	G2_->GetYaxis()->SetTitleSize(TITLE_SIZE);
	G2_->GetXaxis()->SetTitleSize(TITLE_SIZE);
	G2_->GetYaxis()->CenterTitle();
	G2_->GetXaxis()->CenterTitle();
	G2_->SetMarkerStyle(kFullCircle);//kFullCircle);
	G2_->SetLineColor(kRed);
	G2_->SetLineWidth(LINE_WIDTH);
	G2_->SetMarkerSize(MARKER_SIZE);
	G2_->SetTitle("hh #rightarrow 4b (Significance)^{2} Vs 4^{th} leading jet p_{T}");
	G2_->Draw("ACPe1");
	max_range = G2_->GetHistogram()->GetMaximum()*1.3;
	min_range = G2_->GetHistogram()->GetMinimum()*0.4;
	G2_->GetYaxis()->SetRangeUser(min_range, max_range);
	
	//! Gain in Significance Vs Pt threshold 
	g3 = new TGraphErrors(nGraphPts, pT_threshold, SignificanceGain1,0,0);
	g3->GetXaxis()->SetTitle("p_{T, bJ4} [GeV/c]");
	g3->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	g3->GetYaxis()->SetTitle("Gain in S/#sqrt{B}");
	g3->GetYaxis()->SetTitleSize(TITLE_SIZE);
	g3->GetXaxis()->SetTitleSize(TITLE_SIZE);
	g3->GetYaxis()->CenterTitle();
	g3->GetXaxis()->CenterTitle();
	g3->SetMarkerStyle(kFullCircle);//kFullCircle);
	g3->SetLineColor(kRed);
	g3->SetLineWidth(LINE_WIDTH);
	g3->SetMarkerSize(MARKER_SIZE);
	g3->SetTitle("hh #rightarrow 4b Significance gain Vs 4^{th} leading jet p_{T}");
	g3->Draw("ACPe1");
	max_range = g3->GetHistogram()->GetMaximum()*1.3;
	min_range = g3->GetHistogram()->GetMinimum()*0.4;
	g3->GetYaxis()->SetRangeUser(min_range, max_range);
	
	//! Gain in (Significance)^2 Vs Pt threshold 
	Float_t pT_new[nGraphPts] = {25.0, 35.0, 45.0, 55.0, 65.0, 75.0, 85.0, 95.0, 120.0};
	G3 = new TGraphErrors(nGraphPts, pT_new, SignificanceGain2,0,0);
	G3->GetXaxis()->SetTitle("p_{T, bJ4} [GeV/c]");
	G3->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	G3->GetYaxis()->SetTitle("Gain in S^{2}/B");
	G3->GetYaxis()->SetTitleSize(TITLE_SIZE);
	G3->GetXaxis()->SetTitleSize(TITLE_SIZE);
	G3->GetYaxis()->CenterTitle();
	G3->GetXaxis()->CenterTitle();
	G3->SetMarkerStyle(kFullCircle);//kFullCircle);
	G3->SetLineColor(kRed);
	G3->SetLineWidth(LINE_WIDTH);
	G3->SetMarkerSize(MARKER_SIZE);
	G3->SetTitle("hh #rightarrow 4b (Significance)^{2} gain Vs 4^{th} leading jet p_{T}");
	G3->Draw("ACPe1");
	max_range = G3->GetHistogram()->GetMaximum()*1.3;
	min_range = G3->GetHistogram()->GetMinimum()*0.4;
	G3->GetYaxis()->SetRangeUser(min_range, max_range);

	char root_file_name[1023];
        sprintf(root_file_name,"%s/../root/%s_%.1f.root",out_path,output_file_name,ctr);

	TFile *f_out = new TFile(root_file_name,"RECREATE");
	h4_sig->Write();
	h4_bg->Write();
	h4_Significance1->Write();	
	h4_Significance2->Write();	
	h4_SoverB->Write();
	g1->Write("g1");
	g2->Write("g2");
	g3->Write("g3");
	G2->Write("G2");
	G2_->Write("G2_");
	G3->Write("G3");
	f_out->Close();

	return;
}

void pdf()
{
	plot_graph();
	char out_file_open[1023];
        sprintf(out_file_open,"%s/%s_%.1f.pdf(",out_path,output_file_name,ctr);
        char out_file_[1023];
        sprintf(out_file_,"%s/%s_%.1f.pdf",out_path,output_file_name,ctr);
        char out_file_close[1023];
        sprintf(out_file_close,"%s/%s_%.1f.pdf)",out_path,output_file_name,ctr);

	TCanvas *C = new TCanvas("C","C", 800, 800);
	C->SetLeftMargin(0.13);
	h4_SoverB->Draw("hist");
	C->Print(out_file_open,"pdf");
	C->Clear();
	h4_Significance1->Draw("hist");	
	C->Print(out_file_,"pdf");
	C->Clear();
	h4_Significance2->Draw("hist");
	C->Print(out_file_,"pdf");
	C->Clear();
	g1->Draw("ACPe1");
	C->Print(out_file_,"pdf");
	C->Clear();
	g2->Draw("ACPe1");
	C->Print(out_file_,"pdf");
	C->Clear();
	G2->Draw("ACPe1");
	C->Print(out_file_,"pdf");
	C->Clear();
	G2_->Draw("ACPe1");
	//C->Print(out_file_,"pdf");
	//C->Clear();
	//g3->Draw("ACPe1");
	//C->Print(out_file_,"pdf");
	//C->Clear();
	//G3->Draw("ACPe1");
	C->Print(out_file_close,"pdf");
        	
	return;
}
