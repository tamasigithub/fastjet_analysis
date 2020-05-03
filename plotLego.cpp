#include <iostream>
#include "TROOT.h"
#include "plot_props.h"

const char *in_path = "/media/tamasi/Z/PhD/fastjet/fastjet_output/TriggerStudies_7";
const char *fName1 = "CELL1_a50c3_ALL_PU1kMB_ETA2.5_30mm_R0.4_2.root";
const char *fName2 = "CELL1_a50c3_TRK_PU1kMB_ETA2.5_30mm_R0.4_2.root";
const char *fName3 = "CELL1_a50c3_ALL_PU1kggF_ETA2.5_30mm_R0.4_2.root";
const char *fName4 = "CELL1_a50c3_TRK_PU1kggF_ETA2.5_30mm_R0.4_2.root";

TFile *f1 = nullptr;
TFile *f2 = nullptr;
TFile *f3 = nullptr;
TFile *f4 = nullptr;

TH2D *h1 = nullptr;
TH2D *h2 = nullptr;
TH2D *h3 = nullptr;
TH2D *h4 = nullptr;

double PHI = 15.0;
double Z_MAX = 90;
double Z_MIN = 0.5;

void open_files()
{
	char infile[1023];
	sprintf(infile,"%s/%s", in_path, fName1);
	f1 = TFile::Open(infile);
	
	sprintf(infile,"%s/%s", in_path, fName2);
	f2 = TFile::Open(infile);
	
	sprintf(infile,"%s/%s", in_path, fName3);
	f3 = TFile::Open(infile);
	
	sprintf(infile,"%s/%s", in_path, fName4);
	f4 = TFile::Open(infile);
	return;
}

void GetHistos()
{
	h1 = (TH2D*)f1->Get("h2d");
	h2 = (TH2D*)f2->Get("h2d");
	h3 = (TH2D*)f3->Get("h2d");
	h4 = (TH2D*)f4->Get("h2d");
	
	//h1 = (TH2D*)f1->Get("h2dpt");
	//h2 = (TH2D*)f2->Get("h2dpt");
	//h3 = (TH2D*)f3->Get("h2dpt");
	//h4 = (TH2D*)f4->Get("h2dpt");
	return;
}
void SetProps()
{
	h1->GetZaxis()->SetTitle("Energy [GeV]");
	h1->GetYaxis()->SetTitle("#phi [rad]");
	h1->GetXaxis()->SetTitle("#eta");
	h2->GetZaxis()->SetTitle("Energy [GeV]");
	h2->GetYaxis()->SetTitle("#phi [rad]");
	h2->GetXaxis()->SetTitle("#eta");
	h3->GetZaxis()->SetTitle("Energy [GeV]");
	h3->GetYaxis()->SetTitle("#phi [rad]");
	h3->GetXaxis()->SetTitle("#eta");
	h4->GetZaxis()->SetTitle("Energy [GeV]");
	h4->GetYaxis()->SetTitle("#phi [rad]");
	h4->GetXaxis()->SetTitle("#eta");
	
	h1->GetZaxis()->CenterTitle();
	h1->GetYaxis()->CenterTitle();
	h1->GetXaxis()->CenterTitle();
	h2->GetZaxis()->CenterTitle();
	h2->GetYaxis()->CenterTitle();
	h2->GetXaxis()->CenterTitle();
	h3->GetZaxis()->CenterTitle();
	h3->GetYaxis()->CenterTitle();
	h3->GetXaxis()->CenterTitle();
	h4->GetZaxis()->CenterTitle();
	h4->GetYaxis()->CenterTitle();
	h4->GetXaxis()->CenterTitle();

	h1->GetZaxis()->SetTitleSize(TITLE_SIZE);
	h1->GetYaxis()->SetTitleSize(TITLE_SIZE);
	h1->GetXaxis()->SetTitleSize(TITLE_SIZE);
	h2->GetZaxis()->SetTitleSize(TITLE_SIZE);
	h2->GetYaxis()->SetTitleSize(TITLE_SIZE);
	h2->GetXaxis()->SetTitleSize(TITLE_SIZE);
	h3->GetZaxis()->SetTitleSize(TITLE_SIZE);
	h3->GetYaxis()->SetTitleSize(TITLE_SIZE);
	h3->GetXaxis()->SetTitleSize(TITLE_SIZE);
	h4->GetZaxis()->SetTitleSize(TITLE_SIZE);
	h4->GetYaxis()->SetTitleSize(TITLE_SIZE);
	h4->GetXaxis()->SetTitleSize(TITLE_SIZE);

	h1->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET_1);
	h2->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET_1);
	h3->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET_1);
	h4->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET_1);

	h1->GetXaxis()->SetTitleOffset(YAXISTITLE_OFFSET_1);
	h2->GetXaxis()->SetTitleOffset(YAXISTITLE_OFFSET_1);
	h3->GetXaxis()->SetTitleOffset(YAXISTITLE_OFFSET_1);
	h4->GetXaxis()->SetTitleOffset(YAXISTITLE_OFFSET_1);

	h1->Scale(1e-3);
	h2->Scale(1e-3);
	h3->Scale(1e-3);
	h4->Scale(1e-3);

	h1->GetZaxis()->SetRangeUser(Z_MIN,Z_MAX);
	h2->GetZaxis()->SetRangeUser(Z_MIN,Z_MAX);
	h3->GetZaxis()->SetRangeUser(Z_MIN,Z_MAX);
	h4->GetZaxis()->SetRangeUser(Z_MIN,Z_MAX);

	h1->SetTitle("All particles, <#mu> = 1k");
	h2->SetTitle("Charged particles, <#mu> = 1k");
	h3->SetTitle("All particles, signal + <#mu> = 1k");
	h4->SetTitle("Charged particles, signal + <#mu> = 1k");

	
	
	return;
}
void plot()
{
	gStyle->SetOptStat(0);
	open_files();
	GetHistos();
	SetProps();
	Legends();
	TCanvas *c = new TCanvas("c", "c", 1000, 600);
	//TCanvas *c = new TCanvas();
		//gStyle->SetPalette(kCMYK);
		//gStyle->SetPalette(kNeon);
		//gStyle->SetPalette(kPastel);
		//gStyle->SetPalette(kCherry);
		TColor::InvertPalette();
	c->Divide(2,2);
	c->cd(1);
	//gPad->SetLogz();
	h1->Draw("LEGO2 0 FB");
	gPad->SetPhi(PHI);
	//leg1->Draw();
	//leg5->Draw();
	gPad->Update();
	
	c->cd(2);
	//gPad->SetLogz();
	h2->Draw("LEGO2 0 FB");
	gPad->SetPhi(PHI);
	gPad->Update();
	
	c->cd(3);
	//gPad->SetLogz();
	h3->Draw("LEGO2 0 FB");
	gPad->SetPhi(PHI);
	gPad->Update();
	
	c->cd(4);
	//gPad->SetLogz();
	//h4->Draw("LEGO2 0 FB BB");
	h4->Draw("LEGO2 0 FB");
	gPad->SetPhi(PHI);
	gPad->Update();
	return;
}
