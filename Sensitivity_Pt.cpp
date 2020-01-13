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

const int n = 14;
const int nGraphPts = 9;
const float ctr = 1.0;
const char *root_file_name = "./analysis_plots/root/GenJet4b2_2.5_allR0.4_0.8_1.root";
const char *txt_path = "./analysis_plots/txt_files";
const char *out_path = "./analysis_plots/pdf"; 
const char *output_file_name = "SensitivityVs4thPt_1";

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
const double ggFhhXsec1   = 12.24e2;//fb, latest available NNLO Xsection, arXiv:1803.02463v1
const double ggFhhXsec0   = 2346.13;
const double ggFhhXsec_1  = 3995.26;
const double ggFhhXsec_2  = 6172.40;
const double ggFhhXsec2   = 625.59;
const double ggFhhXsec2_5 = 523.907;
const double ggFhhXsec3   = 553.485;
int tot_MCevents = 5e5;
double norm_signal1, norm_signal0, norm_signal_1, norm_signal_2, norm_signal2, norm_signal2_5, norm_signal3, norm_bckgnd;

Int_t nbinsMinus1 = n - 1; 
Float_t pt_bins[n] = {20., 30., 40., 50., 60., 70., 80., 90., 100., 110., 120., 130., 140., 150.};
Int_t   nAna1[n]        = {0};
Int_t   nAna0[n]        = {0};
Int_t   nAna_1[n]       = {0};
Int_t   nAna_2[n]       = {0};
Int_t   nAna2[n]        = {0};
Int_t   nAna2_5[n]      = {0};
Int_t   nAna3[n]        = {0};
Int_t   nAnaB[n]        = {0};

Float_t SoverB1[n]      = {0};
Float_t SoverB0[n]      = {0};
Float_t SoverB_1[n]     = {0};
Float_t SoverB_2[n]     = {0};
Float_t SoverB2[n]      = {0};
Float_t SoverB2_5[n]    = {0};
Float_t SoverB3[n]      = {0};

Float_t Sensitivity1[n]   = {0};
Float_t Sensitivity0[n]   = {0};
Float_t Sensitivity_1[n]  = {0};
Float_t Sensitivity_2[n]  = {0};
Float_t Sensitivity2[n]   = {0};
Float_t Sensitivity2_5[n] = {0};
Float_t Sensitivity3[n]   = {0};

Float_t SensitivityGain1[n]   = {0};
Float_t SensitivityGain0[n]   = {0};
Float_t SensitivityGain_1[n]  = {0};
Float_t SensitivityGain_2[n]  = {0};
Float_t SensitivityGain2[n]   = {0};
Float_t SensitivityGain2_5[n] = {0};
Float_t SensitivityGain3[n]   = {0};

Float_t pT_threshold[n] = {0};
//! Book histograms
TH1D *h4_sig1   = nullptr;
TH1D *h4_sig0   = nullptr;
TH1D *h4_sig_1  = nullptr;
TH1D *h4_sig_2  = nullptr;
TH1D *h4_sig2   = nullptr;
TH1D *h4_sig2_5 = nullptr;
TH1D *h4_sig3   = nullptr;
TH1D *h4_bg     = nullptr;

TH1D *h4_SoverB1        = nullptr;
TH1D *h4_SoverB0        = nullptr;
TH1D *h4_SoverB_1       = nullptr;
TH1D *h4_SoverB_2       = nullptr;
TH1D *h4_SoverB2        = nullptr;
TH1D *h4_SoverB2_5      = nullptr;
TH1D *h4_SoverB3        = nullptr;
TH1D *h4_Sensitivity1   = nullptr;
TH1D *h4_Sensitivity0   = nullptr;
TH1D *h4_Sensitivity_1  = nullptr;
TH1D *h4_Sensitivity_2  = nullptr;
TH1D *h4_Sensitivity2   = nullptr;
TH1D *h4_Sensitivity2_5 = nullptr;
TH1D *h4_Sensitivity3   = nullptr;

TGraphErrors *g1 = nullptr;
TGraphErrors *g2 = nullptr;
TGraphErrors *g3 = nullptr;
void plot_VsPt1()
{

	TFile *f = new TFile(root_file_name, "READ");
	h4_sig1 = (TH1D*)f->Get("Ana_bjet4LPt1");
	h4_bg   = (TH1D*)f->Get("Ana_bjet4LPtB");

	norm_signal1   = (IntLumi * ggFhhXsec1)/tot_MCevents;
	norm_signal0   = (IntLumi * ggFhhXsec0)/tot_MCevents;
	norm_signal_1  = (IntLumi * ggFhhXsec_1)/tot_MCevents;
	norm_signal_2  = (IntLumi * ggFhhXsec_2)/tot_MCevents;
	norm_signal2   = (IntLumi * ggFhhXsec2)/tot_MCevents;
	norm_signal2_5 = (IntLumi * ggFhhXsec2_5)/tot_MCevents;
	norm_signal3   = (IntLumi * ggFhhXsec3)/tot_MCevents;
	norm_bckgnd    = (IntLumi * pp4bXsec)/tot_MCevents;
	
	int nbins1 = h4_sig1->GetNbinsX();
	int nbinsB = h4_bg->GetNbinsX();
	assert(nbins1 == nbinsB);
	std::cout<<"number of bins: " <<nbins1 <<std::endl;

	h4_SoverB1  = new TH1D("h4_SoverB1", "SoverB Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus1, pt_bins);
	h4_Sensitivity1  = new TH1D("h4_Sensitivity1", "Sensitivity Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus1, pt_bins);

        //! write to a text file
	std::cout<<"Writing to txt file...." <<std::endl;
        char txt_file[1023];
        sprintf(txt_file,"%s/Sensitivity_%.1f_1.txt",txt_path, ctr);
        std::ofstream ofs;
 	ofs.open (txt_file, std::ofstream::out | std::ofstream::app);
	ofs<<"pT " <<"N_S " <<"N_B " <<"Nnorm_S " <<"Nnorm_B " <<"S/B " << "S/sqrt(B)\n";	
	for(int i = 1; i < n + 1; i++)
	{

		//std::cout<<"i" << i <<std::endl;
		//! Fill into arrays and plot graph
		pT_threshold[i-1] = h4_sig1->GetBinLowEdge(i);
		nAna1[i-1]        = h4_sig1->GetBinContent(i);
		nAnaB[i-1]        = h4_bg->GetBinContent(i);

		if(nAnaB[i-1] != 0)
		{
			SoverB1[i-1]      = (nAna1[i-1] * norm_signal1)/(nAnaB[i-1] * norm_bckgnd);
			Sensitivity1[i-1] = (nAna1[i-1] * norm_signal1)/std::sqrt(nAnaB[i-1] * norm_bckgnd);
		}
		h4_SoverB1->SetBinContent(i, SoverB1[i-1]);
		h4_Sensitivity1->SetBinContent(i, Sensitivity1[i-1]);

        	ofs<<pT_threshold[i-1]<<" "<<nAna1[i-1]<<" "<<nAnaB[i-1]<<" "<<nAna1[i-1]*norm_signal1<<" "<<nAnaB[i-1]*norm_bckgnd<<" "<<SoverB1[i-1]<<" "<<Sensitivity1[i-1]<<"\n";
	}
	ofs.close();

	return;
}

void plot_graph()
{

	TCanvas *c = new TCanvas("c","c",800,800);
	plot_VsPt1();
	
	//! Sensitivity per bin
	h4_Sensitivity1->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	h4_Sensitivity1->GetYaxis()->SetTitle("S/#sqrt{B}");
	h4_Sensitivity1->GetYaxis()->SetTitleSize(TITLE_SIZE);
	h4_Sensitivity1->GetXaxis()->SetTitleSize(TITLE_SIZE);
	h4_Sensitivity1->GetYaxis()->CenterTitle();
	h4_Sensitivity1->GetXaxis()->CenterTitle();
	h4_Sensitivity1->SetLineColor(kRed);
	h4_Sensitivity1->SetLineWidth(LINE_WIDTH);
	h4_Sensitivity1->Draw("hist");
	//! SoverB per bin
	h4_SoverB1->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	h4_SoverB1->GetYaxis()->SetTitle("S/#sqrt{B}");
	h4_SoverB1->GetYaxis()->SetTitleSize(TITLE_SIZE);
	h4_SoverB1->GetXaxis()->SetTitleSize(TITLE_SIZE);
	h4_SoverB1->GetYaxis()->CenterTitle();
	h4_SoverB1->GetXaxis()->CenterTitle();
	h4_SoverB1->SetLineColor(kRed);
	h4_SoverB1->SetLineWidth(LINE_WIDTH);
	h4_SoverB1->Draw("hist");
	
	for(int i = 0; i < nGraphPts; i++)
	{
		
		SoverB1[i] = h4_SoverB1->Integral(i+1, nGraphPts);
		Sensitivity1[i] = h4_Sensitivity1->Integral(i+1, nGraphPts);
	}
	Sensitivity1[nGraphPts] = Sensitivity1[nGraphPts-1];// this will make the gain for the last pt = 1
	for(int i = 0; i < nGraphPts; i++)
	{
		SensitivityGain1[i] = Sensitivity1[i]/Sensitivity1[i+1]; 
	}
	//! SoverB Vs Pt threshold 
	g1 = new TGraphErrors(nGraphPts, pT_threshold, SoverB1,0,0);
	g1->GetXaxis()->SetTitle("p_{T, bJ4} [GeV/c]");
	g1->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	g1->GetYaxis()->SetTitle("S/B");
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
	
	//! Sensitivity Vs Pt threshold 
	g2 = new TGraphErrors(nGraphPts, pT_threshold, Sensitivity1,0,0);
	g2->GetXaxis()->SetTitle("p_{T, bJ4} [GeV/c]");
	g2->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	g2->GetYaxis()->SetTitle("S/#sqrt{B}");
	g2->GetYaxis()->SetTitleSize(TITLE_SIZE);
	g2->GetXaxis()->SetTitleSize(TITLE_SIZE);
	g2->GetYaxis()->CenterTitle();
	g2->GetXaxis()->CenterTitle();
	g2->SetMarkerStyle(kFullCircle);//kFullCircle);
	g2->SetLineColor(kRed);
	g2->SetLineWidth(LINE_WIDTH);
	g2->SetMarkerSize(MARKER_SIZE);
	g2->SetTitle("hh #rightarrow 4b sensitivty Vs 4^{th} leading jet p_{T}");
	g2->Draw("ACPe1");
	max_range = g2->GetHistogram()->GetMaximum()*1.3;
	min_range = g2->GetHistogram()->GetMinimum()*0.4;
	g2->GetYaxis()->SetRangeUser(min_range, max_range);
	
	//! Gain in Sensitivity Vs Pt threshold 
	g3 = new TGraphErrors(nGraphPts, pT_threshold, SensitivityGain1,0,0);
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
	g3->SetTitle("hh #rightarrow 4b sensitivty gain Vs 4^{th} leading jet p_{T}");
	g3->Draw("ACPe1");
	max_range = g3->GetHistogram()->GetMaximum()*1.3;
	min_range = g3->GetHistogram()->GetMinimum()*0.4;
	g3->GetYaxis()->SetRangeUser(min_range, max_range);

	TFile *f_out = new TFile("./analysis_plots/root/SensitivityVs4thPt_1.root","RECREATE");
	h4_Sensitivity1->Write();	
	h4_SoverB1->Write();
	g1->Write();
	g2->Write();
	g3->Write();
	f_out->Close();

	return;
}

void Write_to_pdf()
{

	char out_file_open[1023];
        sprintf(out_file_open,"%s/%s.pdf(",out_path,output_file_name);
        char out_file_[1023];
        sprintf(out_file_,"%s/%s.pdf",out_path,output_file_name);
        char out_file_close[1023];
        sprintf(out_file_close,"%s/%s.pdf)",out_path,output_file_name);

	TCanvas *C = new TCanvas("C","C", 800, 800);
	h4_Sensitivity1->Draw("hist");	
	C->Print(out_file_open,"pdf");
	h4_SoverB1->Draw("hist");
	C->Print(out_file_,"pdf");
	g1->Draw("ACPe1");
	C->Print(out_file_,"pdf");
	g2->Draw("ACPe1");
	C->Print(out_file_,"pdf");
	g3->Draw("ACPe1");
	C->Print(out_file_close,"pdf");
        	
	return;
}
