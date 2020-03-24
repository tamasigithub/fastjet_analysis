#include "TROOT.h"

const int nevents = 3350;

const char* out_path = "./summary_plots/pdf"; 
//const char* output_file_name = "multiplicity_1tracks1.5_5GeVPU0";
const char* output_file_name = "pTdist_7.5mm_30mm_123trk2.5_2GeV_5GeV_1";
const char *file1name = "./fastjet_output/TriggerStudies_2/TrkJPU1kggFhh4b7.5mm_30mm_1trk2.5_2GeV_5GeV_1.root";
const char *file2name = "./fastjet_output/TriggerStudies_2/TrkJPU1kggFhh4b7.5mm_30mm_2trk2.5_2GeV_5GeV_1.root";
const char *file3name = "./fastjet_output/TriggerStudies_2/TrkJPU1kggFhh4b7.5mm_30mm_3trk2.5_2GeV_5GeV_1.root";
//const char *file1name_ = "./fastjet_output/TriggerStudies_2/TrkJPU1kggFhh4b7.5mm_30mm_1trk2.5_5GeV_5GeV_1.root";
//const char *file2name_ = "./fastjet_output/TriggerStudies_2/TrkJPU1kggFhh4b7.5mm_30mm_2trk2.5_5GeV_5GeV_1.root";
//const char *file3name_ = "./fastjet_output/TriggerStudies_2/TrkJPU1kggFhh4b7.5mm_30mm_3trk2.5_5GeV_5GeV_1.root";
const char *file1name_ = "./fastjet_output/TriggerStudies_2/TrkJPU1kMB7.5mm_30mm_1trk2.5_2GeV_5GeV_1.root";
const char *file2name_ = "./fastjet_output/TriggerStudies_2/TrkJPU1kMB7.5mm_30mm_2trk2.5_2GeV_5GeV_1.root";
const char *file3name_ = "./fastjet_output/TriggerStudies_2/TrkJPU1kMB7.5mm_30mm_3trk2.5_2GeV_5GeV_1.root";
//!ggF
//! sumpt approach
TH1D *R2_1 = nullptr;
TH1D *R3_1 = nullptr;
TH1D *R4_1 = nullptr;
TH1D *R5_1 = nullptr;
//! Lpt bins approach
TH1D *Ra2_1 = nullptr;
TH1D *Ra3_1 = nullptr;
TH1D *Ra4_1 = nullptr;
TH1D *Ra5_1 = nullptr;
//! sumpt approach
TH1D *R2_2 = nullptr;
TH1D *R3_2 = nullptr;
TH1D *R4_2 = nullptr;
TH1D *R5_2 = nullptr;
//! Lpt bins approach
TH1D *Ra2_2 = nullptr;
TH1D *Ra3_2 = nullptr;
TH1D *Ra4_2 = nullptr;
TH1D *Ra5_2 = nullptr;
//! sumpt approach
TH1D *R2_3 = nullptr;
TH1D *R3_3 = nullptr;
TH1D *R4_3 = nullptr;
TH1D *R5_3 = nullptr;
//! Lpt bins approach
TH1D *Ra2_3 = nullptr;
TH1D *Ra3_3 = nullptr;
TH1D *Ra4_3 = nullptr;
TH1D *Ra5_3 = nullptr;
//! Minbias
//! sumpt approach
TH1D *r2_1 = nullptr;
TH1D *r3_1 = nullptr;
TH1D *r4_1 = nullptr;
TH1D *r5_1 = nullptr;
//! Lpt bins approach
TH1D *ra2_1 = nullptr;
TH1D *ra3_1 = nullptr;
TH1D *ra4_1 = nullptr;
TH1D *ra5_1 = nullptr;
//! sumpt approach
TH1D *r2_2 = nullptr;
TH1D *r3_2 = nullptr;
TH1D *r4_2 = nullptr;
TH1D *r5_2 = nullptr;
//! Lpt bins approach
TH1D *ra2_2 = nullptr;
TH1D *ra3_2 = nullptr;
TH1D *ra4_2 = nullptr;
TH1D *ra5_2 = nullptr;
//! sumpt approach
TH1D *r2_3 = nullptr;
TH1D *r3_3 = nullptr;
TH1D *r4_3 = nullptr;
TH1D *r5_3 = nullptr;
//! Lpt bins approach
TH1D *ra2_3 = nullptr;
TH1D *ra3_3 = nullptr;
TH1D *ra4_3 = nullptr;
TH1D *ra5_3 = nullptr;

TLegend *l = nullptr;
TLegend *l1 = nullptr; TLegend *l2 = nullptr; TLegend *l3 = nullptr; TLegend *l4 = nullptr;
TLegend *l_1 = nullptr; TLegend *l_2 = nullptr; TLegend *l_3 = nullptr; TLegend *l_4 = nullptr;

void Set_legProps()
{

	l->SetBorderSize(0);
	l1->SetBorderSize(0);
	l2->SetBorderSize(0);
	l3->SetBorderSize(0);
	l4->SetBorderSize(0);
	l_1->SetBorderSize(0);
	l_2->SetBorderSize(0);
	l_3->SetBorderSize(0);
	l_4->SetBorderSize(0);
}

void fetch_histos(TFile *f1, TFile *f2, TFile *f3)
{

	std::cout<<"Fetching histograms"<<std::endl;

	//! sumpt approach
	R2_1 = (TH1D*)f1->Get("h_PUNLpt");
	R3_1 = (TH1D*)f1->Get("h_PUNNLpt");
	R4_1 = (TH1D*)f1->Get("h_PUNNNLpt");
	R5_1 = (TH1D*)f1->Get("h_PUNNNNLpt");
	//! Lpt bins approach
	Ra2_1 = (TH1D*)f1->Get("ha_PUNLpt");
	Ra3_1 = (TH1D*)f1->Get("ha_PUNNLpt");
	Ra4_1 = (TH1D*)f1->Get("ha_PUNNNLpt");
	Ra5_1 = (TH1D*)f1->Get("ha_PUNNNNLpt");
	//! sumpt approach
	R2_2 = (TH1D*)f2->Get("h_PUNLpt");
	R3_2 = (TH1D*)f2->Get("h_PUNNLpt");
	R4_2 = (TH1D*)f2->Get("h_PUNNNLpt");
	R5_2 = (TH1D*)f2->Get("h_PUNNNNLpt");
	//! Lpt bins approach
	Ra2_2 = (TH1D*)f2->Get("ha_PUNLpt");
	Ra3_2 = (TH1D*)f2->Get("ha_PUNNLpt");
	Ra4_2 = (TH1D*)f2->Get("ha_PUNNNLpt");
	Ra5_2 = (TH1D*)f2->Get("ha_PUNNNNLpt");
	//! sumpt approach
	R2_3 = (TH1D*)f3->Get("h_PUNLpt");
	R3_3 = (TH1D*)f3->Get("h_PUNNLpt");
	R4_3 = (TH1D*)f3->Get("h_PUNNNLpt");
	R5_3 = (TH1D*)f3->Get("h_PUNNNNLpt");
	//! Lpt bins approach
	Ra2_3 = (TH1D*)f3->Get("ha_PUNLpt");
	Ra3_3 = (TH1D*)f3->Get("ha_PUNNLpt");
	Ra4_3 = (TH1D*)f3->Get("ha_PUNNNLpt");
	Ra5_3 = (TH1D*)f3->Get("ha_PUNNNNLpt");
}
void fetch_histosBG(TFile *f1, TFile *f2, TFile *f3)
{

	std::cout<<"Fetching histograms"<<std::endl;

	//! sumpt approach
	r2_1 = (TH1D*)f1->Get("h_PUNLpt");
	r3_1 = (TH1D*)f1->Get("h_PUNNLpt");
	r4_1 = (TH1D*)f1->Get("h_PUNNNLpt");
	r5_1 = (TH1D*)f1->Get("h_PUNNNNLpt");
	//! Lpt bins approach
	ra2_1 = (TH1D*)f1->Get("ha_PUNLpt");
	ra3_1 = (TH1D*)f1->Get("ha_PUNNLpt");
	ra4_1 = (TH1D*)f1->Get("ha_PUNNNLpt");
	ra5_1 = (TH1D*)f1->Get("ha_PUNNNNLpt");
	//! sumpt approach
	r2_2 = (TH1D*)f2->Get("h_PUNLpt");
	r3_2 = (TH1D*)f2->Get("h_PUNNLpt");
	r4_2 = (TH1D*)f2->Get("h_PUNNNLpt");
	r5_2 = (TH1D*)f2->Get("h_PUNNNNLpt");
	//! Lpt bins approach
	ra2_2 = (TH1D*)f2->Get("ha_PUNLpt");
	ra3_2 = (TH1D*)f2->Get("ha_PUNNLpt");
	ra4_2 = (TH1D*)f2->Get("ha_PUNNNLpt");
	ra5_2 = (TH1D*)f2->Get("ha_PUNNNNLpt");
	//! sumpt approach
	r2_3 = (TH1D*)f3->Get("h_PUNLpt");
	r3_3 = (TH1D*)f3->Get("h_PUNNLpt");
	r4_3 = (TH1D*)f3->Get("h_PUNNNLpt");
	r5_3 = (TH1D*)f3->Get("h_PUNNNNLpt");
	//! Lpt bins approach
	ra2_3 = (TH1D*)f3->Get("ha_PUNLpt");
	ra3_3 = (TH1D*)f3->Get("ha_PUNNLpt");
	ra4_3 = (TH1D*)f3->Get("ha_PUNNNLpt");
	ra5_3 = (TH1D*)f3->Get("ha_PUNNNNLpt");
}


void SetXaxis_Range()
{

	//! sumpt approach
	R2_1->GetXaxis()->SetRangeUser(0,300);
	R3_1->GetXaxis()->SetRangeUser(0,300);
	R4_1->GetXaxis()->SetRangeUser(0,300);
	R5_1->GetXaxis()->SetRangeUser(0,300);
	//! Lpt bins approach
	Ra2_1->GetXaxis()->SetRangeUser(0,300);
	Ra3_1->GetXaxis()->SetRangeUser(0,300);
	Ra4_1->GetXaxis()->SetRangeUser(0,300);
	Ra5_1->GetXaxis()->SetRangeUser(0,300);
}
void SetYaxis_Title()
{

	//! sumpt approach
	R2_1->GetYaxis()->SetTitle("");
	R3_1->GetYaxis()->SetTitle("");
	R4_1->GetYaxis()->SetTitle("");
	R5_1->GetYaxis()->SetTitle("");
	//! Lpt bins approach
	Ra2_1->GetYaxis()->SetTitle("");
	Ra3_1->GetYaxis()->SetTitle("");
	Ra4_1->GetYaxis()->SetTitle("");
	Ra5_1->GetYaxis()->SetTitle("");
	//! sumpt approach
	R2_2->GetYaxis()->SetTitle("");
	R3_2->GetYaxis()->SetTitle("");
	R4_2->GetYaxis()->SetTitle("");
	R5_2->GetYaxis()->SetTitle("");
	//! Lpt bins approach
	Ra2_2->GetYaxis()->SetTitle("");
	Ra3_2->GetYaxis()->SetTitle("");
	Ra4_2->GetYaxis()->SetTitle("");
	Ra5_2->GetYaxis()->SetTitle("");
	//! sumpt approach
	R2_3->GetYaxis()->SetTitle("");
	R3_3->GetYaxis()->SetTitle("");
	R4_3->GetYaxis()->SetTitle("");
	R5_3->GetYaxis()->SetTitle("");
	//! Lpt bins approach
	Ra2_3->GetYaxis()->SetTitle("");
	Ra3_3->GetYaxis()->SetTitle("");
	Ra4_3->GetYaxis()->SetTitle("");
	Ra5_3->GetYaxis()->SetTitle("");
}
void SetYaxis_TitleBG()
{

	//! sumpt approach
	r2_1->GetYaxis()->SetTitle("");
	r3_1->GetYaxis()->SetTitle("");
	r4_1->GetYaxis()->SetTitle("");
	r5_1->GetYaxis()->SetTitle("");
	//! Lpt bins approach
	ra2_1->GetYaxis()->SetTitle("");
	ra3_1->GetYaxis()->SetTitle("");
	ra4_1->GetYaxis()->SetTitle("");
	ra5_1->GetYaxis()->SetTitle("");
	//! sumpt approach
	r2_2->GetYaxis()->SetTitle("");
	r3_2->GetYaxis()->SetTitle("");
	r4_2->GetYaxis()->SetTitle("");
	r5_2->GetYaxis()->SetTitle("");
	//! Lpt bins approach
	ra2_2->GetYaxis()->SetTitle("");
	ra3_2->GetYaxis()->SetTitle("");
	ra4_2->GetYaxis()->SetTitle("");
	ra5_2->GetYaxis()->SetTitle("");
	//! sumpt approach
	r2_3->GetYaxis()->SetTitle("");
	r3_3->GetYaxis()->SetTitle("");
	r4_3->GetYaxis()->SetTitle("");
	r5_3->GetYaxis()->SetTitle("");
	//! Lpt bins approach
	ra2_3->GetYaxis()->SetTitle("");
	ra3_3->GetYaxis()->SetTitle("");
	ra4_3->GetYaxis()->SetTitle("");
	ra5_3->GetYaxis()->SetTitle("");
}
void Set_Colors()
{

	//! sumpt approach
	R2_1->SetLineColor(kRed);
	R3_1->SetLineColor(kRed);
	R4_1->SetLineColor(kRed);
	R5_1->SetLineColor(kRed);
	//! Lpt bins approach
	Ra2_1->SetLineColor(kRed);
	Ra3_1->SetLineColor(kRed);
	Ra4_1->SetLineColor(kRed);
	Ra5_1->SetLineColor(kRed);
	//! sumpt approach
	R2_2->SetLineColor(kGreen+2);
	R3_2->SetLineColor(kGreen+2);
	R4_2->SetLineColor(kGreen+2);
	R5_2->SetLineColor(kGreen+2);
	//! Lpt bins approach
	Ra2_2->SetLineColor(kGreen+2);
	Ra3_2->SetLineColor(kGreen+2);
	Ra4_2->SetLineColor(kGreen+2);
	Ra5_2->SetLineColor(kGreen+2);
	//! sumpt approach
	R2_3->SetLineColor(kBlack);
	R3_3->SetLineColor(kBlack);
	R4_3->SetLineColor(kBlack);
	R5_3->SetLineColor(kBlack);
	//! Lpt bins approach
	Ra2_3->SetLineColor(kBlack);
	Ra3_3->SetLineColor(kBlack);
	Ra4_3->SetLineColor(kBlack);
	Ra5_3->SetLineColor(kBlack);
}
void Set_ColorsBG()
{

	//! sumpt approach
	r2_1->SetLineColor(kRed);
	r3_1->SetLineColor(kRed);
	r4_1->SetLineColor(kRed);
	r5_1->SetLineColor(kRed);
	//! Lpt bins approach
	ra2_1->SetLineColor(kRed);
	ra3_1->SetLineColor(kRed);
	ra4_1->SetLineColor(kRed);
	ra5_1->SetLineColor(kRed);
	//! sumpt approach
	r2_2->SetLineColor(kGreen+2);
	r3_2->SetLineColor(kGreen+2);
	r4_2->SetLineColor(kGreen+2);
	r5_2->SetLineColor(kGreen+2);
	//! Lpt bins approach
	ra2_2->SetLineColor(kGreen+2);
	ra3_2->SetLineColor(kGreen+2);
	ra4_2->SetLineColor(kGreen+2);
	ra5_2->SetLineColor(kGreen+2);
	//! sumpt approach
	r2_3->SetLineColor(kBlack);
	r3_3->SetLineColor(kBlack);
	r4_3->SetLineColor(kBlack);
	r5_3->SetLineColor(kBlack);
	//! Lpt bins approach
	ra2_3->SetLineColor(kBlack);
	ra3_3->SetLineColor(kBlack);
	ra4_3->SetLineColor(kBlack);
	ra5_3->SetLineColor(kBlack);
	//! sumpt approach
	r2_1->SetLineStyle(2);
	r3_1->SetLineStyle(2);
	r4_1->SetLineStyle(2);
	r5_1->SetLineStyle(2);
	//! Lpt bins approach
	ra2_1->SetLineStyle(2);
	ra3_1->SetLineStyle(2);
	ra4_1->SetLineStyle(2);
	ra5_1->SetLineStyle(2);
	//! sumpt approach
	r2_2->SetLineStyle(2);
	r3_2->SetLineStyle(2);
	r4_2->SetLineStyle(2);
	r5_2->SetLineStyle(2);
	//! Lpt bins approach
	ra2_2->SetLineStyle(2);
	ra3_2->SetLineStyle(2);
	ra4_2->SetLineStyle(2);
	ra5_2->SetLineStyle(2);
	//! sumpt approach
	r2_3->SetLineStyle(2);
	r3_3->SetLineStyle(2);
	r4_3->SetLineStyle(2);
	r5_3->SetLineStyle(2);
	//! Lpt bins approach
	ra2_3->SetLineStyle(2);
	ra3_3->SetLineStyle(2);
	ra4_3->SetLineStyle(2);
	ra5_3->SetLineStyle(2);
}
void Scale()
{

	//! sumpt approach
	R2_1->Scale(1.0e-3*(25*nevents));
	R3_1->Scale(1.0e-3*(25*nevents));
	R4_1->Scale(1.0e-3*(25*nevents));
	R5_1->Scale(1.0e-3*(25*nevents));
	//! Lpt bins approach
	Ra2_1->Scale(1.0e-3*(25*nevents));
	Ra3_1->Scale(1.0e-3*(25*nevents));
	Ra4_1->Scale(1.0e-3*(25*nevents));
	Ra5_1->Scale(1.0e-3*(25*nevents));
	//! sumpt approach
	R2_2->Scale(1.0e-3*(25*nevents));
	R3_2->Scale(1.0e-3*(25*nevents));
	R4_2->Scale(1.0e-3*(25*nevents));
	R5_2->Scale(1.0e-3*(25*nevents));
	//! Lpt bins approach
	Ra2_2->Scale(1.0e-3*(25*nevents));
	Ra3_2->Scale(1.0e-3*(25*nevents));
	Ra4_2->Scale(1.0e-3*(25*nevents));
	Ra5_2->Scale(1.0e-3*(25*nevents));
	//! sumpt approach
	R2_3->Scale(1.0e-3*(25*nevents));
	R3_3->Scale(1.0e-3*(25*nevents));
	R4_3->Scale(1.0e-3*(25*nevents));
	R5_3->Scale(1.0e-3*(25*nevents));
	//! Lpt bins approach
	Ra2_3->Scale(1.0e-3*(25*nevents));
	Ra3_3->Scale(1.0e-3*(25*nevents));
	Ra4_3->Scale(1.0e-3*(25*nevents));
	Ra5_3->Scale(1.0e-3*(25*nevents));
}
void ScaleBG()
{

	//! sumpt approach
	r2_1->Scale(1.0e-3*(25*nevents));
	r3_1->Scale(1.0e-3*(25*nevents));
	r4_1->Scale(1.0e-3*(25*nevents));
	r5_1->Scale(1.0e-3*(25*nevents));
	//! Lpt bins approach
	ra2_1->Scale(1.0e-3*(25*nevents));
	ra3_1->Scale(1.0e-3*(25*nevents));
	ra4_1->Scale(1.0e-3*(25*nevents));
	ra5_1->Scale(1.0e-3*(25*nevents));
	//! sumpt approach
	r2_2->Scale(1.0e-3*(25*nevents));
	r3_2->Scale(1.0e-3*(25*nevents));
	r4_2->Scale(1.0e-3*(25*nevents));
	r5_2->Scale(1.0e-3*(25*nevents));
	//! Lpt bins approach
	ra2_2->Scale(1.0e-3*(25*nevents));
	ra3_2->Scale(1.0e-3*(25*nevents));
	ra4_2->Scale(1.0e-3*(25*nevents));
	ra5_2->Scale(1.0e-3*(25*nevents));
	//! sumpt approach
	r2_3->Scale(1.0e-3*(25*nevents));
	r3_3->Scale(1.0e-3*(25*nevents));
	r4_3->Scale(1.0e-3*(25*nevents));
	r5_3->Scale(1.0e-3*(25*nevents));
	//! Lpt bins approach
	ra2_3->Scale(1.0e-3*(25*nevents));
	ra3_3->Scale(1.0e-3*(25*nevents));
	ra4_3->Scale(1.0e-3*(25*nevents));
	ra5_3->Scale(1.0e-3*(25*nevents));
}


void plot()
{

	TFile *f1 = new TFile(file1name, "READ");
	TFile *f2 = new TFile(file2name, "READ");
	TFile *f3 = new TFile(file3name, "READ");
	TFile *f1_ = new TFile(file1name_, "READ");
	TFile *f2_ = new TFile(file2name_, "READ");
	TFile *f3_ = new TFile(file3name_, "READ");
	
	fetch_histos(f1, f2, f3);
	fetch_histosBG(f1_, f2_, f3_);
	Scale();
	ScaleBG();
	SetYaxis_Title();
	SetYaxis_TitleBG();
	Set_Colors();
	Set_ColorsBG();
	SetXaxis_Range();

	//////////////////////////////////////////////////
	//////////////// writing to pdf //////////////////
	//////////////////////////////////////////////////
	char out_file_open[1023];
        sprintf(out_file_open,"%s/%s.pdf(",out_path,output_file_name);
        char out_file_[1023];
        sprintf(out_file_,"%s/%s.pdf",out_path,output_file_name);
        char out_file_close[1023];
        sprintf(out_file_close,"%s/%s.pdf)",out_path,output_file_name);

	l1 = new TLegend(0.5,0.6,0.89,0.7);
	l1->AddEntry((TObject*)0,"2^{nd} leading track-jet","");
	l1->AddEntry((TObject*)0,"max-bin: #pm 7.5mm ","");
	l2 = new TLegend(0.5,0.6,0.89,0.7);
	l2->AddEntry((TObject*)0,"3^{rd} leading track-jet","");
	l2->AddEntry((TObject*)0,"max-bin: #pm 7.5mm ","");
	l3 = new TLegend(0.5,0.6,0.89,0.7);
	l3->AddEntry((TObject*)0,"4^{th} leading track-jet","");
	l3->AddEntry((TObject*)0,"max-bin: #pm 7.5mm ","");
	l4 = new TLegend(0.5,0.6,0.89,0.7);
	l4->AddEntry((TObject*)0,"5^{th} leading track-jet","");
	l4->AddEntry((TObject*)0,"max-bin: #pm 7.5mm ","");
	
	l_1 = new TLegend(0.5,0.6,0.89,0.7);
	l_1->AddEntry((TObject*)0,"2^{nd} leading track-jet","");
	l_1->AddEntry((TObject*)0,"multi-bin: #pm 7.5mm ","");
	l_2 = new TLegend(0.5,0.6,0.89,0.7);
	l_2->AddEntry((TObject*)0,"3^{rd} leading track-jet","");
	l_2->AddEntry((TObject*)0,"multi-bin: #pm 7.5mm ","");
	l_3 = new TLegend(0.5,0.6,0.89,0.7);
	l_3->AddEntry((TObject*)0,"4^{th} leading track-jet","");
	l_3->AddEntry((TObject*)0,"multi-bin: #pm 7.5mm ","");
	l_4 = new TLegend(0.5,0.6,0.89,0.7);
	l_4->AddEntry((TObject*)0,"5^{th} leading track-jet","");
	l_4->AddEntry((TObject*)0,"multi-bin: #pm 7.5mm ","");

	l = new TLegend(0.5, 0.5, 0.89, 0.6);
	l->AddEntry(R3_3, "signal, <#mu> = 1k, 2,5GeV", "l");
	l->AddEntry(r3_3, "BG(min-bias), <#mu> = 1k", "l");
	//l->AddEntry(r3_3, "signal, <#mu> = 1k, 5,5GeV", "l");
	//TCanvas *C = new TCanvas("C","C",800,800);
	TCanvas *C = new TCanvas();
	Set_legProps();
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);
	//TGaxis::SetMaxDigits(2);
	C->SetGridx();
	C->SetGridy();
	C->SetTickx();
	C->SetTicky();
	C->SetLogy();
	C->Divide(2,2);
	
	
	//! max-bin (called sum-pt earlier)
	C->cd(1);
	gPad->SetGrid();
	gPad->SetLogy();
	R2_1->Draw("hist");
	R2_2->Draw("hist same");
	R2_3->Draw("hist same");
	r2_1->Draw("hist same");
	r2_2->Draw("hist same");
	r2_3->Draw("hist same");
	l->Draw();
	l1->Draw();

	C->cd(2);
	gPad->SetGrid();
	gPad->SetLogy();
	R3_1->Draw("hist");
	R3_2->Draw("hist same");
	R3_3->Draw("hist same");
	r3_1->Draw("hist same");
	r3_2->Draw("hist same");
	r3_3->Draw("hist same");
	l->Draw();
	l2->Draw();

	C->cd(3);
	gPad->SetGrid();
	gPad->SetLogy();
	R4_1->Draw("hist");
	R4_2->Draw("hist same");
	R4_3->Draw("hist same");
	r4_1->Draw("hist same");
	r4_2->Draw("hist same");
	r4_3->Draw("hist same");
	l->Draw();
	l3->Draw();

	C->cd(4);
	gPad->SetGrid();
	gPad->SetLogy();
	R5_1->Draw("hist");
	R5_2->Draw("hist same");
	R5_3->Draw("hist same");
	r5_1->Draw("hist same");
	r5_2->Draw("hist same");
	r5_3->Draw("hist same");
	l->Draw();
	l4->Draw();
	C->Update();
	C->Print(out_file_open,"pdf");

	C->cd(1);
	gPad->SetGrid();
	gPad->SetLogy();
	Ra2_1->Draw("hist");
	Ra2_2->Draw("hist same");
	Ra2_3->Draw("hist same");
	ra2_1->Draw("hist same");
	ra2_2->Draw("hist same");
	ra2_3->Draw("hist same");
	l->Draw();
	l_1->Draw();

	C->cd(2);
	gPad->SetGrid();
	gPad->SetLogy();
	Ra3_1->Draw("hist");
	Ra3_2->Draw("hist same");
	Ra3_3->Draw("hist same");
	ra3_1->Draw("hist same");
	ra3_2->Draw("hist same");
	ra3_3->Draw("hist same");
	l->Draw();
	l_2->Draw();

	C->cd(3);
	gPad->SetGrid();
	gPad->SetLogy();
	Ra4_1->Draw("hist");
	Ra4_2->Draw("hist same");
	Ra4_3->Draw("hist same");
	ra4_1->Draw("hist same");
	ra4_2->Draw("hist same");
	ra4_3->Draw("hist same");
	l->Draw();
	l_3->Draw();

	C->cd(4);
	gPad->SetGrid();
	gPad->SetLogy();
	Ra5_1->Draw("hist");
	Ra5_2->Draw("hist same");
	Ra5_3->Draw("hist same");
	ra5_1->Draw("hist same");
	ra5_2->Draw("hist same");
	ra5_3->Draw("hist same");
	l->Draw();
	l_4->Draw();
	C->Print(out_file_close,"pdf");

	return;
}

