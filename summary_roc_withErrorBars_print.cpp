//! draws a summary plot 
//! of trigger efficiency as a function of trigger rate in MHz  
//! for various gap size of the TTT ==========================================> TODO - Needs simulation of different configurations
//! for various pileup configurations,e.g. 0,200,1000 ==========================================> TODO - Needs simulation of different pileup configurations
//! for different widths of overlapping z-vertex bins
//! extract the trigger efficiency from PU1000hh4b files and trigger rate from PU1000MB files for a given z-vertex bin to a text file
//! pileup z0 trigger_efficiency trigger_rate
//! read this txt file to draw a graph of trigger_efficiency Vs trigger_rate for a given pileup and z-vertex bin
//! do the same for various z-vertex bins(TODO:and for different gap sizes, pileup configs) and draw a multigraph

#include <iostream>
#include <fstream>
#include <string>
#include<math.h>

#include "TROOT.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TLegend.h"
#include "TGraphErrors.h"
#include "TPostScript.h"

#include "TAxis.h"
#include "TGaxis.h"
#include "TF1.h"

#include "plot_props.h"

const double STAR_SIZE = 2.3;
const double DIAMOND_SIZE = 2.2;
const double TRIANGLEUP_SIZE = 2.1;
const double TRIANGLEDOWN_SIZE = 2.1;

const char* out_path = "./summary_plots/pdf"; 
//const char* output_file_name = "nofakes100GeV2Calo_7.5_3.75_q1.2GeV_2";
//const char* output_file_name = "TrigSummary43221trk_7.5_1.2_5GeV_PrimB0ALLa50c3Caloq1.2GeV_2GeV_33333GeV_30mm_5_2";
const char* output_file_name = "TrigSummary32211trk_7.5_1.5_97432GeV_CELL_a50c3_ALL30mmETA2.5_5_80";
//! clears the txt file
void deleteText(const char* pileup) 
{
    const char* txt_path = "./txt_files";
    char txt_file[1023];
    //sprintf(txt_file,"%s/summary10-100_rmsVspurity_PU%s.txt",txt_path, pileup);
    sprintf(txt_file,"%s/summary_rmsVspurityNo30mm_PU%s.txt",txt_path, pileup);
    std::ofstream ofs;
    ofs.open(txt_file, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}
void SaveCanvas(TCanvas *C, char *name)
{
    const char *path = "./summary_plots";
    char full_name[1023];
    sprintf(full_name,"%s/summary_%s.root", path, name);
    C->SaveAs(full_name);
    sprintf(full_name,"%s/summary_%s.pdf", path, name);
    C->SaveAs(full_name);
    sprintf(full_name,"%s/summary_%s.png", path, name);
    C->SaveAs(full_name);
    sprintf(full_name,"%s/summary_%s.C", path, name);
    C->SaveAs(full_name);

}

//! run_no - run number of the single particle file
//! first two numbers of which are identical to gap size
void roc(const char *pileup, const char *gapsize)
{
	//! Draw a pre-scalling function of the form rate = 40MHz * trigger efficiency
	TF1 *fun = new TF1("fun","[0]*x*x",0,1);
	fun->SetParameter(0,40);
	//TF2 *fun1= new TF2("fun1","[0]*x-y",0,1,3e-2,40);
	//fun1->SetParameter(0,40);
	//TF12 *fun2 = new TF12("fun2",fun1,3e-2,"x");

	bool debug = true;
	//const int n = 20;
	//const int n = 115;
	//const int n = 400;
	const int n = 500;
	//const int n = 190;
	//const int n = 100;
	Int_t nbinsE, nbinsR;
	Int_t nbinsEa, nbinsRa;
	Int_t nbinsEb, nbinsRb;
	Float_t Xmin_range = 0.0, Xmax_range = 1.05;
	Float_t Ymin_range = 3e-2, Ymax_range = 60.0;
	Double_t e2[n] = {0};   Double_t r2[n] = {0};
	Double_t e3[n] = {0};   Double_t r3[n] = {0};
	Double_t e4[n] = {0};   Double_t r4[n] = {0};
	Double_t e5[n] = {0};   Double_t r5[n] = {0};
	Double_t ea2[n] = {0};   Double_t ra2[n] = {0};
	Double_t ea3[n] = {0};   Double_t ra3[n] = {0};
	Double_t ea4[n] = {0};   Double_t ra4[n] = {0};
	Double_t ea5[n] = {0};   Double_t ra5[n] = {0};
	Double_t eb2[n] = {0};   Double_t rb2[n] = {0};
	Double_t eb3[n] = {0};   Double_t rb3[n] = {0};
	Double_t eb4[n] = {0};   Double_t rb4[n] = {0};
	Double_t eb5[n] = {0};   Double_t rb5[n] = {0};

	Double_t e_err2[n] = {0};   Double_t r_err2[n] = {0};
	Double_t e_err3[n] = {0};   Double_t r_err3[n] = {0};
	Double_t e_err4[n] = {0};   Double_t r_err4[n] = {0};
	Double_t e_err5[n] = {0};   Double_t r_err5[n] = {0};
	Double_t e_erra2[n] = {0};   Double_t r_erra2[n] = {0};
	Double_t e_erra3[n] = {0};   Double_t r_erra3[n] = {0};
	Double_t e_erra4[n] = {0};   Double_t r_erra4[n] = {0};
	Double_t e_erra5[n] = {0};   Double_t r_erra5[n] = {0};
	Double_t e_errb2[n] = {0};   Double_t r_errb2[n] = {0};
	Double_t e_errb3[n] = {0};   Double_t r_errb3[n] = {0};
	Double_t e_errb4[n] = {0};   Double_t r_errb4[n] = {0};
	Double_t e_errb5[n] = {0};   Double_t r_errb5[n] = {0};
	Double_t pt_threshold[n] = {0};
	/////////////////////////////////////////////////
	//! Fetch the histograms
	////////////////////////////////////////////////
	const char *file_path = "./fastjet_output/TriggerStudies_7";
	const char *file_path_1 = "./fastjet_output/TriggerStudies_6";
	const char *file_path_2= "./fastjet_output/TriggerStudies";
	char signal_file_name[1023];
	sprintf(signal_file_name, "%s/TrkJPU%sggFhh4b7.5mm_%smm_32211trk2.5_2GeV_97432GeV_5_80.root",file_path_1,pileup,gapsize);//7.5
	std::cout<<"signal file name: " <<signal_file_name <<std::endl;
	TFile *f = new TFile(signal_file_name, "READ");
	//! sumpt approach
	TH1F *E2 = (TH1F*)f->Get("h_tJeff2");
	TH1F *E3 = (TH1F*)f->Get("h_tJeff3");
	TH1F *E4 = (TH1F*)f->Get("h_tJeff4");
	TH1F *E5 = (TH1F*)f->Get("h_tJeff5");
	//! Lpt bins approach
	TH1F *Ea2 = (TH1F*)f->Get("ha_tJeff2");
	TH1F *Ea3 = (TH1F*)f->Get("ha_tJeff3");
	TH1F *Ea4 = (TH1F*)f->Get("ha_tJeff4");
	TH1F *Ea5 = (TH1F*)f->Get("ha_tJeff5");
	//! no z-vertex bin 
	TH1F *Eb2 = (TH1F*)f->Get("hb_tJeff2");
	TH1F *Eb3 = (TH1F*)f->Get("hb_tJeff3");
	TH1F *Eb4 = (TH1F*)f->Get("hb_tJeff4");
	TH1F *Eb5 = (TH1F*)f->Get("hb_tJeff5");
	Eb2->SetLineStyle(7);
	Eb3->SetLineStyle(7);
	Eb4->SetLineStyle(7);
	Eb5->SetLineStyle(7);
	Eb2->GetYaxis()->SetRangeUser(0,1.2);
	Eb3->GetYaxis()->SetRangeUser(0,1.2);
	Eb4->GetYaxis()->SetRangeUser(0,1.2);
	Eb5->GetYaxis()->SetRangeUser(0,1.2);
	
	char MinBias_file_name[1023];
	sprintf(MinBias_file_name, "%s/TrkJPU%sMB7.5mm_%smm_32211trk2.5_2GeV_97432GeV_3_80.root",file_path_1,pileup,gapsize);//7.5
	TFile *f1 = new TFile(MinBias_file_name, "READ");
	TTree *t1 = (TTree*)f1->Get("glob_jet");
	int nevents = t1->GetEntries();

	//! sumpt approach
	TH1F *R2 = (TH1F*)f1->Get("h_PUNLpt");
	TH1F *R3 = (TH1F*)f1->Get("h_PUNNLpt");
	TH1F *R4 = (TH1F*)f1->Get("h_PUNNNLpt");
	TH1F *R5 = (TH1F*)f1->Get("h_PUNNNNLpt");
	//! Lpt bins approach
	TH1F *Ra2 = (TH1F*)f1->Get("ha_PUNLpt");
	TH1F *Ra3 = (TH1F*)f1->Get("ha_PUNNLpt");
	TH1F *Ra4 = (TH1F*)f1->Get("ha_PUNNNLpt");
	TH1F *Ra5 = (TH1F*)f1->Get("ha_PUNNNNLpt");
	//! no z-vertex bin 
	TH1F *Rb2 = (TH1F*)f1->Get("hb_PUNLpt");
	TH1F *Rb3 = (TH1F*)f1->Get("hb_PUNNLpt");
	TH1F *Rb4 = (TH1F*)f1->Get("hb_PUNNNLpt");
	TH1F *Rb5 = (TH1F*)f1->Get("hb_PUNNNNLpt");
	//! no z-vertex bin 
	Rb2->SetLineStyle(7);
	Rb3->SetLineStyle(7);
	Rb4->SetLineStyle(7);
	Rb5->SetLineStyle(7);
	//Rb2->Scale(1.0e3/(25*nevents));
	//Rb3->Scale(1.0e3/(25*nevents));
	//Rb4->Scale(1.0e3/(25*nevents));
	//Rb5->Scale(1.0e3/(25*nevents));
	
	Rb2->GetYaxis()->SetTitle("trigger rate [MHz]");
	Rb3->GetYaxis()->SetTitle("trigger rate [MHz]");
	Rb4->GetYaxis()->SetTitle("trigger rate [MHz]");
	Rb5->GetYaxis()->SetTitle("trigger rate [MHz]");
	
	Rb2->GetYaxis()->SetRangeUser(1e-1,50);
	Rb3->GetYaxis()->SetRangeUser(1e-1,50);
	Rb4->GetYaxis()->SetRangeUser(1e-1,50);
	Rb5->GetYaxis()->SetRangeUser(1e-1,50);
	

	TCanvas *c = new TCanvas();	
        TH1::SetDefaultSumw2(true);

	nbinsE = E2->GetNbinsX();
	nbinsR = R2->GetNbinsX();
	nbinsEa = Ea2->GetNbinsX();
	nbinsRa = Ra2->GetNbinsX();
	nbinsEb = Eb2->GetNbinsX();
	nbinsRb = Rb2->GetNbinsX();
	if(debug) std::cout<<"nbinsE = " << nbinsE << ", nbinsR = " << nbinsR <<std::endl;
	assert(nbinsE == nbinsR);
	
        //! write to a text file
	std::cout<<"Writing to txt file...." <<std::endl;
        const char* txt_path = "./txt_files";
        char txt_file[1023];
        sprintf(txt_file,"%s/summary_trackJetROC_PU%s_%smm_7.5.txt",txt_path, pileup,gapsize);
        std::ofstream ofs;
        ofs.open (txt_file, std::ofstream::out | std::ofstream::app);
	//for(int i = 1; i < nbinsE + 1; i++)
	for(int i = 1; i < n + 1; i++)
	{
        	ofs<<E2->GetBinLowEdge(i)<<" "<<E2->GetBinContent(i)<<" " <<R2->GetBinContent(i)<<" "<<E3->GetBinContent(i)<<" "<<R3->GetBinContent(i)<<" "<<E4->GetBinContent(i)<<" "<<R4->GetBinContent(i)<<" "<<E5->GetBinContent(i)<<" "<<R5->GetBinContent(i)<<"\n";

		//std::cout<<"i" << i <<std::endl;
		//! Fill into arrays and plot graph
		pt_threshold[i-1] = R2->GetBinLowEdge(i);
		e2[i-1] = E2->GetBinContent(i);
		r2[i-1] = R2->GetBinContent(i);
		e3[i-1] = E3->GetBinContent(i);
		r3[i-1] = R3->GetBinContent(i);
		e4[i-1] = E4->GetBinContent(i);
		r4[i-1] = R4->GetBinContent(i);
		e5[i-1] = E5->GetBinContent(i);
		r5[i-1] = R5->GetBinContent(i);
		//! Fill into arrays and plot graph
		ea2[i-1] = Ea2->GetBinContent(i);
		ra2[i-1] = Ra2->GetBinContent(i);
		ea3[i-1] = Ea3->GetBinContent(i);
		ra3[i-1] = Ra3->GetBinContent(i);
		ea4[i-1] = Ea4->GetBinContent(i);
		ra4[i-1] = Ra4->GetBinContent(i);
		ea5[i-1] = Ea5->GetBinContent(i);
		ra5[i-1] = Ra5->GetBinContent(i);
		//! Fill into arrays and plot graph
		eb2[i-1] = Eb2->GetBinContent(i);
		rb2[i-1] = Rb2->GetBinContent(i);
		eb3[i-1] = Eb3->GetBinContent(i);
		rb3[i-1] = Rb3->GetBinContent(i);
		eb4[i-1] = Eb4->GetBinContent(i);
		rb4[i-1] = Rb4->GetBinContent(i);
		eb5[i-1] = Eb5->GetBinContent(i);
		rb5[i-1] = Rb5->GetBinContent(i);
		//! bin errors
		e_err2[i-1] = E2->GetBinError(i);
		e_erra2[i-1] = Ea2->GetBinError(i);
		e_errb2[i-1] = Eb2->GetBinError(i);
		e_err3[i-1] = E3->GetBinError(i);
		e_erra3[i-1] = Ea3->GetBinError(i);
		e_errb3[i-1] = Eb3->GetBinError(i);
		e_err4[i-1] = E4->GetBinError(i);
		e_erra4[i-1] = Ea4->GetBinError(i);
		e_errb4[i-1] = Eb4->GetBinError(i);
		e_err5[i-1] = E5->GetBinError(i);
		e_erra5[i-1] = Ea5->GetBinError(i);
		e_errb5[i-1] = Eb5->GetBinError(i);
		//! Fill into arrays and plot graph
		r_err2[i-1] = R2->GetBinError(i);
		r_erra2[i-1] = Ra2->GetBinError(i);
		r_errb2[i-1] = Rb2->GetBinError(i);
		r_err3[i-1] = R3->GetBinError(i);
		r_erra3[i-1] = Ra3->GetBinError(i);
		r_errb3[i-1] = Rb3->GetBinError(i);
		r_err4[i-1] = R4->GetBinError(i);
		r_erra4[i-1] = Ra4->GetBinError(i);
		r_errb4[i-1] = Rb4->GetBinError(i);
		r_err5[i-1] = R5->GetBinError(i);
		r_erra5[i-1] = Ra5->GetBinError(i);
		r_errb5[i-1] = Rb5->GetBinError(i);
	}
        ofs.close();


	TCanvas *c1 = new TCanvas();
	//TGraphErrors *g1 = new TGraphErrors(n,e2,r2,0,0);
	TGraphErrors *g1 = new TGraphErrors(n,r2,e2,r_err2,e_err2);
	//g1->GetXaxis()->SetTitle("trigger efficiency");
	//auto axis = g1->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//g1->GetYaxis()->SetTitleOffset(1.2);
	//g1->GetYaxis()->SetTitle("trigger rate [MHz]");
	//g1->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g1->SetMarkerStyle(22);//kFullCircle);
	g1->SetMarkerColor(kBlack);
	g1->SetLineColor(kBlack);
	g1->SetMarkerSize(1.8);
	//c1->cd(4);
	g1->SetFillColor(kWhite);
	g1->SetTitle("2^{nd} leading pt track-jet, max-bin, bin_size: 7.5mm");
	//g1->Draw("ACPe1");
	g1->Draw("APe1");

	//TGraphErrors *g2 = new TGraphErrors(n,e3,r3,0,0);
	TGraphErrors *g2 = new TGraphErrors(n,r3,e3,r_err3,e_err3);
	//g2->GetXaxis()->SetTitle("trigger efficiency");
	//axis = g2->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//g2->GetYaxis()->SetTitleOffset(1.2);
	//g2->GetYaxis()->SetTitle("trigger rate [MHz]");
	//g2->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g2->SetMarkerStyle(22);//kFullTriangleUp);
	g2->SetMarkerColor(kRed);
	g2->SetLineColor(kRed);
	g2->SetMarkerSize(1.8);
	//c1->cd(4);
	g2->SetFillColor(kWhite);
	g2->SetTitle("3^{rd} leading pt track-jet, max-bin, bin_size: 7.5mm ");
	//g2->Draw("CPe1");
	g2->Draw("Pe1");

	//TGraphErrors *g3 = new TGraphErrors(n,e4,r4,0,0);
	TGraphErrors *g3 = new TGraphErrors(n,r4,e4,r_err4,e_err4);
	//g3->GetXaxis()->SetTitle("trigger efficiency");
	//axis = g3->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//g3->GetYaxis()->SetTitleOffset(1.2);
	//g3->GetYaxis()->SetTitle("trigger rate [MHz]");
	//g3->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g3->SetMarkerStyle(22);//k);
	g3->SetMarkerColor(kGreen+2);
	g3->SetLineColor(kGreen+2);
	g3->SetMarkerSize(1.8);
	//c1->cd(4);
	g3->SetFillColor(kWhite);
	g3->SetTitle("4^{th} leading pt track-jet, max-bin, bin_size: 7.5mm ");
	//g3->Draw("CPe1");
	g3->Draw("Pe1");

	//TGraphErrors *g4 = new TGraphErrors(n,e5,r5,0,0);
	TGraphErrors *g4 = new TGraphErrors(n,r5,e5,r_err5,e_err5);
	//g4->GetXaxis()->SetTitle("trigger efficiency");
	//axis = g4->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//g4->GetYaxis()->SetTitleOffset(1.2);
	//g4->GetYaxis()->SetTitle("trigger rate [MHz]");
	//g4->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g4->SetMarkerStyle(22);//kFullStar);
	g4->SetMarkerColor(kBlue);
	g4->SetLineColor(kBlue);
	g4->SetMarkerSize(1.8);
	//c1->cd(4);
	g4->SetFillColor(kWhite);
	g4->SetTitle("5^{th} leading pt track-jet, max-bin, bin_size: 7.5mm ");
	//g4->Draw("CPe1");
	g4->Draw("Pe1");

	//TGraphErrors *ga1 = new TGraphErrors(n,ea2,ra2,0,0);
	TGraphErrors *ga1 = new TGraphErrors(n,ra2,ea2,r_erra2,e_erra2);
	//ga1->GetXaxis()->SetTitle("trigger efficiency");
	//axis = ga1->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//ga1->GetYaxis()->SetTitleOffset(1.2);
	//ga1->GetYaxis()->SetTitle("trigger rate [MHz]");
	//ga1->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga1->SetMarkerStyle(kFullTriangleDown);//kFullCircle);
	ga1->SetMarkerColor(kBlack);
	ga1->SetLineColor(kBlack);
	ga1->SetMarkerSize(1.8);
	//c1->cd(4);
	ga1->SetFillColor(kWhite);
	ga1->SetTitle("2^{nd} leading pt track-jet, multi-bin, bin_size: 7.5mm");
	//g1->Draw("ACPe1");
	ga1->Draw("APe1");

	//TGraphErrors *ga2 = new TGraphErrors(n,ea3,ra3,0,0);
	TGraphErrors *ga2 = new TGraphErrors(n,ra3,ea3,r_erra3,e_erra3);
	//ga2->GetXaxis()->SetTitle("trigger efficiency");
	//axis = ga2->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//ga2->GetYaxis()->SetTitleOffset(1.2);
	//ga2->GetYaxis()->SetTitle("trigger rate [MHz]");
	//ga2->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga2->SetMarkerStyle(kFullTriangleDown);//kFullTriangleUp);
	ga2->SetMarkerColor(kRed);
	ga2->SetLineColor(kRed);
	ga2->SetMarkerSize(1.8);
	//c1->cd(4);
	ga2->SetFillColor(kWhite);
	ga2->SetTitle("3^{rd} leading pt track-jet, multi-bin, bin_size: 7.5mm ");
	//ga2->Draw("CPe1");
	ga2->Draw("Pe1");

	//TGraphErrors *ga3 = new TGraphErrors(n,ea4,ra4,0,0);
	TGraphErrors *ga3 = new TGraphErrors(n,ra4,ea4,r_erra4,e_erra4);
	//ga3->GetXaxis()->SetTitle("trigger efficiency");
	//axis = ga3->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//ga3->GetYaxis()->SetTitleOffset(1.2);
	//ga3->GetYaxis()->SetTitle("trigger rate [MHz]");
	//ga3->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga3->SetMarkerStyle(kFullTriangleDown);//k);
	ga3->SetMarkerColor(kGreen+2);
	ga3->SetLineColor(kGreen+2);
	ga3->SetMarkerSize(1.8);
	//c1->cd(4);
	ga3->SetFillColor(kWhite);
	ga3->SetTitle("4^{th} leading pt track-jet, multi-bin, bin_size: 7.5mm ");
	//ga3->Draw("CPe1");
	ga3->Draw("Pe1");

	//TGraphErrors *ga4 = new TGraphErrors(n,ea5,ra5,0,0);
	TGraphErrors *ga4 = new TGraphErrors(n,ra5,ea5,r_erra5,e_erra5);
	//ga4->GetXaxis()->SetTitle("trigger efficiency");
	//axis = ga4->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//ga4->GetYaxis()->SetTitleOffset(1.2);
	//ga4->GetYaxis()->SetTitle("trigger rate [MHz]");
	//ga4->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga4->SetMarkerStyle(kFullTriangleDown);//kFullStar);
	ga4->SetMarkerColor(kBlue);
	ga4->SetLineColor(kBlue);
	ga4->SetMarkerSize(1.8);
	//c1->cd(4);
	ga4->SetFillColor(kWhite);
	ga4->SetTitle("5^{th} leading pt track-jet, max-pt, bin_size: 7.5mm ");
	//ga4->Draw("CPe1");
	ga4->Draw("Pe1");

	//TGraphErrors *gb1 = new TGraphErrors(n,eb2,rb2,0,0);
	TGraphErrors *gb1 = new TGraphErrors(n,rb2,eb2,r_errb2,e_errb2);
	gb1->Draw("AP");
	//axis = gb1->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//gb1->GetYaxis()->SetTitleOffset(1.2);
	//gb1->GetYaxis()->SetTitle("trigger rate [MHz]");
	//gb1->GetXaxis()->SetTitle("trigger efficiency");
	//gb1->GetYaxis()->CenterTitle();
	//gb1->GetXaxis()->CenterTitle();
	//gb1->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb1->SetMarkerStyle(kFullCircle);//kFullCircle);
	gb1->SetMarkerColor(kBlack);
	gb1->SetLineColor(kBlack);
	gb1->SetMarkerSize(1.5);
	//c1->cd(4);
	gb1->SetFillColor(kWhite);
	gb1->SetTitle("2^{nd} leading pt track-jet no binning ");
	//gb1->Draw("ACPe1");

	//TGraphErrors *gb2 = new TGraphErrors(n,eb3,rb3,0,0);
	TGraphErrors *gb2 = new TGraphErrors(n,rb3,eb3,r_errb3,e_errb3);
	gb2->Draw("AP");
	//gb2->GetXaxis()->SetTitle("trigger efficiency");
	//axis = gb2->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//gb2->GetYaxis()->SetTitleOffset(1.2);
	//gb2->GetYaxis()->SetTitle("trigger rate [MHz]");
	//gb2->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb2->SetMarkerStyle(kFullCircle);//kFullTriangleUp);
	gb2->SetMarkerColor(kRed);
	gb2->SetLineColor(kRed);
	gb2->SetMarkerSize(1.5);
	//c1->cd(4);
	gb2->SetFillColor(kWhite);
	gb2->SetTitle("3^{rd} leading pt track-jet no binning ");
	//gb2->Draw("CPe1");

	//TGraphErrors *gb3 = new TGraphErrors(n,eb4,rb4,0,0);
	TGraphErrors *gb3 = new TGraphErrors(n,rb4,eb4,r_errb4,e_errb4);
	gb3->Draw("AP");
	//gb3->GetXaxis()->SetTitle("trigger efficiency");
	//axis = gb3->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//gb3->GetYaxis()->SetTitleOffset(1.2);
	//gb3->GetYaxis()->SetTitle("trigger rate [MHz]");
	//gb3->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb3->SetMarkerStyle(kFullCircle);//k);
	gb3->SetMarkerColor(kGreen+2);
	gb3->SetLineColor(kGreen+2);
	gb3->SetMarkerSize(1.5);
	//c1->cd(4);
	gb3->SetFillColor(kWhite);
	gb3->SetTitle("4^{th} leading pt track-jet no binning ");
	//gb3->Draw("CPe1");

	//TGraphErrors *gb4 = new TGraphErrors(n,eb5,rb5,0,0);
	TGraphErrors *gb4 = new TGraphErrors(n,rb5,eb5,r_errb5,e_errb5);
	gb4->Draw("AP");
	//gb4->GetXaxis()->SetTitle("trigger efficiency");
	//axis = gb4->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//gb4->GetYaxis()->SetTitleOffset(1.2);
	//gb4->GetYaxis()->SetTitle("trigger rate [MHz]");
	//gb4->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb4->SetMarkerStyle(kFullCircle);//kFullStar);
	gb4->SetMarkerColor(kBlue);
	gb4->SetLineColor(kBlue);
	gb4->SetMarkerSize(1.5);
	//c1->cd(4);
	gb4->SetFillColor(kWhite);
	gb4->SetTitle("5^{th} leading pt track-jet no binning ");
	//gb4->Draw("CPe1");
//////////////////////////////////////////////////////////////
/////////////// for a different z vertex bin  ////////////////
//////////////////////////////////////////////////////////////

	Double_t e2_[n] = {0};    Double_t r2_[n] = {0};
	Double_t e3_[n] = {0};    Double_t r3_[n] = {0};
	Double_t e4_[n] = {0};    Double_t r4_[n] = {0};
	Double_t e5_[n] = {0};    Double_t r5_[n] = {0};
	Double_t ea_2[n] = {0};   Double_t ra_2[n] = {0};
	Double_t ea_3[n] = {0};   Double_t ra_3[n] = {0};
	Double_t ea_4[n] = {0};   Double_t ra_4[n] = {0};
	Double_t ea_5[n] = {0};   Double_t ra_5[n] = {0};
	Double_t eb_2[n] = {0};   Double_t rb_2[n] = {0};
	Double_t eb_3[n] = {0};   Double_t rb_3[n] = {0};
	Double_t eb_4[n] = {0};   Double_t rb_4[n] = {0};
	Double_t eb_5[n] = {0};   Double_t rb_5[n] = {0};
	
	Double_t e_err2_[n] = {0};    Double_t r_err2_[n] = {0};
	Double_t e_err3_[n] = {0};    Double_t r_err3_[n] = {0};
	Double_t e_err4_[n] = {0};    Double_t r_err4_[n] = {0};
	Double_t e_err5_[n] = {0};    Double_t r_err5_[n] = {0};
	Double_t e_erra_2[n] = {0};   Double_t r_erra_2[n] = {0};
	Double_t e_erra_3[n] = {0};   Double_t r_erra_3[n] = {0};
	Double_t e_erra_4[n] = {0};   Double_t r_erra_4[n] = {0};
	Double_t e_erra_5[n] = {0};   Double_t r_erra_5[n] = {0};
	Double_t e_errb_2[n] = {0};   Double_t r_errb_2[n] = {0};
	Double_t e_errb_3[n] = {0};   Double_t r_errb_3[n] = {0};
	Double_t e_errb_4[n] = {0};   Double_t r_errb_4[n] = {0};
	Double_t e_errb_5[n] = {0};   Double_t r_errb_5[n] = {0};
	/////////////////////////////////////////////////
	//! Fetch the histograms
	////////////////////////////////////////////////
	char signal_file_name_1[1023];
	sprintf(signal_file_name_1, "%s/TrkJPU%sggFhh4b1.5mm_%smm_32211trk2.5_2GeV_97432GeV_5_80.root",file_path_1,pileup,gapsize);//1.5
	TFile *f_ = new TFile(signal_file_name_1, "READ");
	//! sumpt approach
	TH1F *E2_ = (TH1F*)f_->Get("h_tJeff2");
	TH1F *E3_ = (TH1F*)f_->Get("h_tJeff3");
	TH1F *E4_ = (TH1F*)f_->Get("h_tJeff4");
	TH1F *E5_ = (TH1F*)f_->Get("h_tJeff5");
	//! Lpt _bins approach
	TH1F *Ea_2 = (TH1F*)f_->Get("ha_tJeff2");
	TH1F *Ea_3 = (TH1F*)f_->Get("ha_tJeff3");
	TH1F *Ea_4 = (TH1F*)f_->Get("ha_tJeff4");
	TH1F *Ea_5 = (TH1F*)f_->Get("ha_tJeff5");
	//! no z_-vertex bin 
	TH1F *Eb_2 = (TH1F*)f_->Get("hb_tJeff2");
	TH1F *Eb_3 = (TH1F*)f_->Get("hb_tJeff3");
	TH1F *Eb_4 = (TH1F*)f_->Get("hb_tJeff4");
	TH1F *Eb_5 = (TH1F*)f_->Get("hb_tJeff5");
	Eb_2->SetLineStyle(7);
	Eb_3->SetLineStyle(7);
	Eb_4->SetLineStyle(7);
	Eb_5->SetLineStyle(7);
	Eb_2->GetYaxis()->SetRangeUser(0,1.2);
	Eb_3->GetYaxis()->SetRangeUser(0,1.2);
	Eb_4->GetYaxis()->SetRangeUser(0,1.2);
	Eb_5->GetYaxis()->SetRangeUser(0,1.2);
	
	char MinBias_file_name_1[1023];
	sprintf(MinBias_file_name_1, "%s/TrkJPU%sMB1.5mm_%smm_32211trk2.5_2GeV_97432GeV_3_80.root",file_path_1,pileup,gapsize);//1.5
	TFile *f_1 = new TFile(MinBias_file_name_1, "READ");
	TTree *t_1 = (TTree*)f_1->Get("glob_jet");
	nevents = t_1->GetEntries();
	//! sumpt approach
	TH1F *R2_ = (TH1F*)f_1->Get("h_PUNLpt");
	TH1F *R3_ = (TH1F*)f_1->Get("h_PUNNLpt");
	TH1F *R4_ = (TH1F*)f_1->Get("h_PUNNNLpt");
	TH1F *R5_ = (TH1F*)f_1->Get("h_PUNNNNLpt");
	//! Lpt _bins approach
	TH1F *Ra_2 = (TH1F*)f_1->Get("ha_PUNLpt");
	TH1F *Ra_3 = (TH1F*)f_1->Get("ha_PUNNLpt");
	TH1F *Ra_4 = (TH1F*)f_1->Get("ha_PUNNNLpt");
	TH1F *Ra_5 = (TH1F*)f_1->Get("ha_PUNNNNLpt");
	//! no z_-vertex bin 
	TH1F *Rb_2 = (TH1F*)f_1->Get("hb_PUNLpt");
	TH1F *Rb_3 = (TH1F*)f_1->Get("hb_PUNNLpt");
	TH1F *Rb_4 = (TH1F*)f_1->Get("hb_PUNNNLpt");
	TH1F *Rb_5 = (TH1F*)f_1->Get("hb_PUNNNNLpt");
	Rb_2->SetLineStyle(7);
	Rb_3->SetLineStyle(7);
	Rb_4->SetLineStyle(7);
	Rb_5->SetLineStyle(7);
	//Rb_2->Scale(1.0e3/(25*nevents));
	//Rb_3->Scale(1.0e3/(25*nevents));
	//Rb_4->Scale(1.0e3/(25*nevents));
	//Rb_5->Scale(1.0e3/(25*nevents));
	
	Rb_2->GetYaxis()->SetTitle("trigger rate [MHz]");
	Rb_3->GetYaxis()->SetTitle("trigger rate [MHz]");
	Rb_4->GetYaxis()->SetTitle("trigger rate [MHz]");
	Rb_5->GetYaxis()->SetTitle("trigger rate [MHz]");

	Rb_2->GetYaxis()->SetRangeUser(1e-1,50);
	Rb_3->GetYaxis()->SetRangeUser(1e-1,50);
	Rb_4->GetYaxis()->SetRangeUser(1e-1,50);
	Rb_5->GetYaxis()->SetRangeUser(1e-1,50);
	
	nbinsE = E2_->GetNbinsX();
	nbinsR = R2_->GetNbinsX();
	nbinsEa = Ea_2->GetNbinsX();
	nbinsRa = Ra_2->GetNbinsX();
	nbinsEb = Eb_2->GetNbinsX();
	nbinsRb = Rb_2->GetNbinsX();
	if(debug) std::cout<<"nbinsE = " << nbinsE << ", nbinsR = " << nbinsR <<std::endl;
	assert(nbinsE == nbinsR);
	
	for(int i = 1; i < n + 1; i++)
	{
		
		//! Fill into arrays and plot graph
		e2_[i-1] = E2_->GetBinContent(i);
		r2_[i-1] = R2_->GetBinContent(i);
		e3_[i-1] = E3_->GetBinContent(i);
		r3_[i-1] = R3_->GetBinContent(i);
		e4_[i-1] = E4_->GetBinContent(i);
		r4_[i-1] = R4_->GetBinContent(i);
		e5_[i-1] = E5_->GetBinContent(i);
		r5_[i-1] = R5_->GetBinContent(i);
		//_! Fill into arrays and plot graph
		ea_2[i-1] = Ea_2->GetBinContent(i);
		ra_2[i-1] = Ra_2->GetBinContent(i);
		ea_3[i-1] = Ea_3->GetBinContent(i);
		ra_3[i-1] = Ra_3->GetBinContent(i);
		ea_4[i-1] = Ea_4->GetBinContent(i);
		ra_4[i-1] = Ra_4->GetBinContent(i);
		ea_5[i-1] = Ea_5->GetBinContent(i);
		ra_5[i-1] = Ra_5->GetBinContent(i);
		//_! Fill into_ arrays and plot graph
		eb_2[i-1] = Eb_2->GetBinContent(i);
		rb_2[i-1] = Rb_2->GetBinContent(i);
		eb_3[i-1] = Eb_3->GetBinContent(i);
		rb_3[i-1] = Rb_3->GetBinContent(i);
		eb_4[i-1] = Eb_4->GetBinContent(i);
		rb_4[i-1] = Rb_4->GetBinContent(i);
		eb_5[i-1] = Eb_5->GetBinContent(i);
		rb_5[i-1] = Rb_5->GetBinContent(i);
		
		//! bin error
		e_err2_[i-1] = E2_->GetBinError(i);
		e_erra_2[i-1] = Ea_2->GetBinError(i);
		e_errb_2[i-1] = Eb_2->GetBinError(i);
		e_err3_[i-1] = E3_->GetBinError(i);
		e_erra_3[i-1] = Ea_3->GetBinError(i);
		e_errb_3[i-1] = Eb_3->GetBinError(i);
		e_err4_[i-1] = E4_->GetBinError(i);
		e_erra_4[i-1] = Ea_4->GetBinError(i);
		e_errb_4[i-1] = Eb_4->GetBinError(i);
		e_err5_[i-1] = E5_->GetBinError(i);
		e_erra_5[i-1] = Ea_5->GetBinError(i);
		e_errb_5[i-1] = Eb_5->GetBinError(i);
		//_! Fill into arrays and plot graph
		r_err2_[i-1] = R2_->GetBinError(i);
		r_erra_2[i-1] = Ra_2->GetBinError(i);
		r_errb_2[i-1] = Rb_2->GetBinError(i);
		r_err3_[i-1] = R3_->GetBinError(i);
		r_erra_3[i-1] = Ra_3->GetBinError(i);
		r_errb_3[i-1] = Rb_3->GetBinError(i);
		r_err4_[i-1] = R4_->GetBinError(i);
		r_erra_4[i-1] = Ra_4->GetBinError(i);
		r_errb_4[i-1] = Rb_4->GetBinError(i);
		r_err5_[i-1] = R5_->GetBinError(i);
		r_erra_5[i-1] = Ra_5->GetBinError(i);
		r_errb_5[i-1] = Rb_5->GetBinError(i);
	}

	//TGraphErrors *g1_ = new TGraphErrors(n,e2_,r2_,0,0);
	TGraphErrors *g1_ = new TGraphErrors(n,r2_,e2_,r_err2_,e_err2_);
	//g1_->GetXaxis()->SetTitle("trigger efficiency");
	//axis = g1_->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//g1_->GetYaxis()->SetTitleOffset(1.2);
	//g1_->GetYaxis()->SetTitle("trigger rate [MHz]");
	//g1_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g1_->SetMarkerStyle(kOpenTriangleUp);//kFullCircle);
	g1_->SetMarkerColor(kBlack);
	g1_->SetLineColor(kBlack);
	g1_->SetMarkerSize(1.5);
	//c1->cd(4);
	g1_->SetFillColor(kWhite);
	g1_->SetTitle("2^{nd} leading pt track-jet, max-bin, bin_size: +-1.5mm ");
	//g1_->Draw("ACPe1");
	g1_->Draw("APe1");

	//TGraphErrors *g2_ = new TGraphErrors(n,e3_,r3_,0,0);
	TGraphErrors *g2_ = new TGraphErrors(n,r3_,e3_,r_err3_,e_err3_);
	//g2_->GetXaxis()->SetTitle("trigger efficiency");
	//axis = g2_->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//g2_->GetYaxis()->SetTitleOffset(1.2);
	//g2_->GetYaxis()->SetTitle("trigger rate [MHz]");
	//g2_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g2_->SetMarkerStyle(kOpenTriangleUp);//kFullTriangleUp);
	g2_->SetMarkerColor(kRed);
	g2_->SetLineColor(kRed);
	g2_->SetMarkerSize(1.5);
	//c1->cd(4);
	g2_->SetFillColor(kWhite);
	g2_->SetTitle("3^{rd} leading pt track-jet, max-bin, bin_size: +-1.5mm ");
	//g2_->Draw("CPe1");
	g2_->Draw("Pe1");

	//TGraphErrors *g3_ = new TGraphErrors(n,e4_,r4_,0,0);
	TGraphErrors *g3_ = new TGraphErrors(n,r4_,e4_,r_err4_,e_err4_);
	//g3_->GetXaxis()->SetTitle("trigger efficiency");
	//axis = g3_->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//g3_->GetYaxis()->SetTitleOffset(1.2);
	//g3_->GetYaxis()->SetTitle("trigger rate [MHz]");
	//g3_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g3_->SetMarkerStyle(kOpenTriangleUp);//k);
	g3_->SetMarkerColor(kGreen+2);
	g3_->SetLineColor(kGreen+2);
	g3_->SetMarkerSize(1.5);
	//c1->cd(4);
	g3_->SetFillColor(kWhite);
	g3_->SetTitle("4^{th} leading pt track-jet, max-bin, bin_size: +-1.5mm ");
	//g3_->Draw("CPe1");
	g3_->Draw("Pe1");

	//TGraphErrors *g4_ = new TGraphErrors(n,e5_,r5_,0,0);
	TGraphErrors *g4_ = new TGraphErrors(n,r5_,e5_,r_err5_,e_err5_);
	//g4_->GetXaxis()->SetTitle("trigger efficiency");
	//axis = g4_->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//g4_->GetYaxis()->SetTitleOffset(1.2);
	//g4_->GetYaxis()->SetTitle("trigger rate [MHz]");
	//g4_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g4_->SetMarkerStyle(kOpenTriangleUp);//kFullStar);
	g4_->SetMarkerColor(kBlue);
	g4_->SetLineColor(kBlue);
	g4_->SetMarkerSize(1.5);
	//c1->cd(4);
	g4_->SetFillColor(kWhite);
	g4_->SetTitle("5^{th} leading pt track-jet, max-bin, bin_size: +-1.5mm ");
	//g4_->Draw("CPe1");
	g4_->Draw("Pe1");

	//TGraphErrors *ga1_ = new TGraphErrors(n,ea_2,ra_2,0,0);
	TGraphErrors *ga1_ = new TGraphErrors(n,ra_2,ea_2,r_erra_2,e_erra_2);
	//ga1_->GetXaxis()->SetTitle("trigger efficiency");
	//axis = ga1_->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//ga1_->GetYaxis()->SetTitleOffset(1.2);
	//ga1_->GetYaxis()->SetTitle("trigger rate [MHz]");
	//ga1_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga1_->SetMarkerStyle(kOpenTriangleDown);//kFullCircle);
	ga1_->SetMarkerColor(kBlack);
	ga1_->SetLineColor(kBlack);
	ga1_->SetMarkerSize(1.5);
	//c1->cd(4);
	ga1_->SetFillColor(kWhite);
	ga1_->SetTitle("2^{nd} leading pt track-jet, multi-bin, bin_size: +-1.5mm ");
	//g1->Draw("ACPe1");
	ga1_->Draw("APe1");

	//TGraphErrors *ga2_ = new TGraphErrors(n,ea_3,ra_3,0,0);
	TGraphErrors *ga2_ = new TGraphErrors(n,ra_3,ea_3,r_erra_3,e_erra_3);
	//ga2_->GetXaxis()->SetTitle("trigger efficiency");
	//axis = ga2_->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//ga2_->GetYaxis()->SetTitleOffset(1.2);
	//ga2_->GetYaxis()->SetTitle("trigger rate [MHz]");
	//ga2_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga2_->SetMarkerStyle(kOpenTriangleDown);//kFullTriangleDown);
	ga2_->SetMarkerColor(kRed);
	ga2_->SetLineColor(kRed);
	ga2_->SetMarkerSize(1.5);
	//c1->cd(4);
	ga2_->SetFillColor(kWhite);
	ga2_->SetTitle("3^{rd} leading pt track-jet, multi-bin, bin_size: +-1.5mm ");
	//ga2_->Draw("CPe1");
	ga2_->Draw("Pe1");

	//TGraphErrors *ga3_ = new TGraphErrors(n,ea_4,ra_4,0,0);
	TGraphErrors *ga3_ = new TGraphErrors(n,ra_4,ea_4,r_erra_4,e_erra_4);
	//ga3_->GetXaxis()->SetTitle("trigger efficiency");
	//axis = ga3_->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//ga3_->GetYaxis()->SetTitleOffset(1.2);
	//ga3_->GetYaxis()->SetTitle("trigger rate [MHz]");
	//ga3_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga3_->SetMarkerStyle(kOpenTriangleDown);//k);
	ga3_->SetMarkerColor(kGreen+2);
	ga3_->SetLineColor(kGreen+2);
	ga3_->SetMarkerSize(1.5);
	//c1->cd(4);
	ga3_->SetFillColor(kWhite);
	ga3_->SetTitle("4^{th} leading pt track-jet, multi-bin, bin_size: +-1.5mm ");
	//ga3_->Draw("CPe1");
	ga3_->Draw("Pe1");

	//TGraphErrors *ga4_ = new TGraphErrors(n,ea_5,ra_5,0,0);
	TGraphErrors *ga4_ = new TGraphErrors(n,ra_5,ea_5,r_erra_5,e_erra_5);
	//ga4_->GetXaxis()->SetTitle("trigger efficiency");
	//axis = ga4_->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//ga4_->GetYaxis()->SetTitleOffset(1.2);
	//ga4_->GetYaxis()->SetTitle("trigger rate [MHz]");
	//ga4_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga4_->SetMarkerStyle(kOpenTriangleDown);//kFullStar);
	ga4_->SetMarkerColor(kBlue);
	ga4_->SetLineColor(kBlue);
	ga4_->SetMarkerSize(1.5);
	//c1->cd(4);
	ga4_->SetFillColor(kWhite);
	ga4_->SetTitle("5^{th} leading pt track-jet, multi-bin, bin_size: +-1.5mm ");
	//ga4_->Draw("CPe1");
	ga4_->Draw("Pe1");

	//TGraphErrors *gb1_ = new TGraphErrors(n,eb_2,rb_2,0,0);
	TGraphErrors *gb1_ = new TGraphErrors(n,rb_2,eb_2,r_errb_2,e_errb_2);
	//gb1_->GetXaxis()->SetTitle("trigger efficiency");
	//axis = gb1_->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//gb1_->GetYaxis()->SetTitleOffset(1.2);
	//gb1_->GetYaxis()->SetTitle("trigger rate [MHz]");
	//gb1_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb1_->SetMarkerStyle(kFullCircle);//kFullCircle);
	gb1_->SetMarkerColor(kBlack);
	gb1_->SetLineColor(kBlack);
	gb1_->SetMarkerSize(1.5);
	//c1->cd(4);
	gb1_->SetFillColor(kWhite);
	gb1_->SetTitle("2^{nd} leading pt track-jet no binning ");
	//gb1_->Draw("ACPe1");
	gb1_->Draw("APe1");

	//TGraphErrors *gb2_ = new TGraphErrors(n,eb_3,rb_3,0,0);
	TGraphErrors *gb2_ = new TGraphErrors(n,rb_3,eb_3,r_errb_3,e_errb_3);
	//gb2_->GetXaxis()->SetTitle("trigger efficiency");
	//axis = gb2_->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//gb2_->GetYaxis()->SetTitleOffset(1.2);
	//gb2_->GetYaxis()->SetTitle("trigger rate [MHz]");
	//gb2_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb2_->SetMarkerStyle(kFullCircle);//kFullTriangleUp);
	gb2_->SetMarkerColor(kRed);
	gb2_->SetLineColor(kRed);
	gb2_->SetMarkerSize(1.5);
	//c1->cd(4);
	gb2_->SetFillColor(kWhite);
	gb2_->SetTitle("3^{rd} leading pt track-jet no binning ");
	//gb2_->Draw("CPe1");
	gb2_->Draw("Pe1");

	//TGraphErrors *gb3_ = new TGraphErrors(n,eb_4,rb_4,0,0);
	TGraphErrors *gb3_ = new TGraphErrors(n,rb_4,eb_4,r_errb_4,e_errb_4);
	//gb3_->GetXaxis()->SetTitle("trigger efficiency");
	//axis = gb3_->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//gb3_->GetYaxis()->SetTitleOffset(1.2);
	//gb3_->GetYaxis()->SetTitle("trigger rate [MHz]");
	//gb3_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb3_->SetMarkerStyle(kFullCircle);//k);
	gb3_->SetMarkerColor(kGreen+2);
	gb3_->SetLineColor(kGreen+2);
	gb3_->SetMarkerSize(1.5);
	//c1->cd(4);
	gb3_->SetFillColor(kWhite);
	gb3_->SetTitle("4^{th} leading pt track-jet no binning ");
	//gb3_->Draw("CPe1");
	gb3_->Draw("Pe1");

	//TGraphErrors *gb4_ = new TGraphErrors(n,eb_5,rb_5,0,0);
	TGraphErrors *gb4_ = new TGraphErrors(n,rb_5,eb_5,r_errb_5,e_errb_5);
	//gb4_->GetXaxis()->SetTitle("trigger efficiency");
	//axis = gb4_->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//gb4_->GetYaxis()->SetTitleOffset(1.2);
	//gb4_->GetYaxis()->SetTitle("trigger rate [MHz]");
	//gb4_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb4_->SetMarkerStyle(kFullCircle);//kFullStar);
	gb4_->SetMarkerColor(kBlue);
	gb4_->SetLineColor(kBlue);
	gb4_->SetMarkerSize(1.5);
	//c1->cd(4);
	gb4_->SetFillColor(kWhite);
	gb4_->SetTitle("5^{th} leading pt track-jet no binning ");
	//gb4_->Draw("CPe1");
	gb4_->Draw("Pe1");

/////////////////////////////////////////////////////////////////////////////////////////////
//                               For emulated calo jets
/////////////////////////////////////////////////////////////////////////////////////////////
	Double_t eb__2[n] = {0};   Double_t rb__2[n] = {0};
	Double_t eb__3[n] = {0};   Double_t rb__3[n] = {0};
	Double_t eb__4[n] = {0};   Double_t rb__4[n] = {0};
	Double_t eb__5[n] = {0};   Double_t rb__5[n] = {0};

	Double_t e_errb__2[n] = {0};   Double_t r_errb__2[n] = {0};
	Double_t e_errb__3[n] = {0};   Double_t r_errb__3[n] = {0};
	Double_t e_errb__4[n] = {0};   Double_t r_errb__4[n] = {0};
	Double_t e_errb__5[n] = {0};   Double_t r_errb__5[n] = {0};
	char signal_file_calo[1023];
	//sprintf(signal_file_calo, "%s/EMU5GeV_PrimB0ALLa50c3_PU%sggFhh4b1.0_q1.2GeVeta2.5_%smmR0.4_4_test_2.root",file_path,pileup,gapsize);
	sprintf(signal_file_calo, "%s/CELL_a50c3_ALL_PU%sggF_ETA2.5_%smm_R0.4_3.root",file_path,pileup,gapsize);
	TFile *fcalo = new TFile(signal_file_calo, "READ");
	//! Calo Emulation
	TH1F *Ebcalo2 = (TH1F*)fcalo->Get("hb_tJeff2");
	TH1F *Ebcalo3 = (TH1F*)fcalo->Get("hb_tJeff3");
	TH1F *Ebcalo4 = (TH1F*)fcalo->Get("hb_tJeff4");
	TH1F *Ebcalo5 = (TH1F*)fcalo->Get("hb_tJeff5");
	//Ebcalo2->GetYaxis()->SetRangeUser(0,1.2);
	//Ebcalo3->GetYaxis()->SetRangeUser(0,1.2);
	//Ebcalo4->GetYaxis()->SetRangeUser(0,1.2);
	//Ebcalo5->GetYaxis()->SetRangeUser(0,1.2);
	Ebcalo2->SetLineStyle(2);
	Ebcalo3->SetLineStyle(2);
	Ebcalo4->SetLineStyle(2);
	Ebcalo5->SetLineStyle(2);
	
	char MinBias_file_calo[1023];
	//sprintf(MinBias_file_calo, "%s/EMU5GeV_PrimB0ALLa50c3_PU%sMB_q1.2GeVeta2.5_%smmR0.4_4_test_2.root",file_path,pileup,gapsize);
	sprintf(MinBias_file_calo, "%s/CELL_a50c3_ALL_PU%sMB_ETA2.5_%smm_R0.4_3.root",file_path,pileup,gapsize);
	TFile *f1calo = new TFile(MinBias_file_calo, "READ");
	TTree *t1calo = (TTree*)f1calo->Get("glob_jet");
	nevents = t1calo->GetEntries();
	//! sumpt approach
	TH1F *Rbcalo2 = (TH1F*)f1calo->Get("hb_PUNLpt");
	TH1F *Rbcalo3 = (TH1F*)f1calo->Get("hb_PUNNLpt");
	TH1F *Rbcalo4 = (TH1F*)f1calo->Get("hb_PUNNNLpt");
	TH1F *Rbcalo5 = (TH1F*)f1calo->Get("hb_PUNNNNLpt");
	//Rbcalo2->GetYaxis()->SetRangeUser(1e-1,50);
	//Rbcalo3->GetYaxis()->SetRangeUser(1e-1,50);
	//Rbcalo4->GetYaxis()->SetRangeUser(1e-1,50);
	//Rbcalo5->GetYaxis()->SetRangeUser(1e-1,50);
	Rbcalo2->SetLineStyle(2);
	Rbcalo3->SetLineStyle(2);
	Rbcalo4->SetLineStyle(2);
	Rbcalo5->SetLineStyle(2);
	//Rbcalo2->Scale(1.0e3/(25*nevents));
	//Rbcalo3->Scale(1.0e3/(25*nevents));
	//Rbcalo4->Scale(1.0e3/(25*nevents));
	//Rbcalo5->Scale(1.0e3/(25*nevents));
	
	Rbcalo2->GetYaxis()->SetTitle("trigger rate [MHz]");
	Rbcalo3->GetYaxis()->SetTitle("trigger rate [MHz]");
	Rbcalo4->GetYaxis()->SetTitle("trigger rate [MHz]");
	Rbcalo5->GetYaxis()->SetTitle("trigger rate [MHz]");
	if(debug) std::cout<<"nbinsEcalo = " << Ebcalo2->GetNbinsX() << ", nbinsRcalo = " << Rbcalo2->GetNbinsX() <<std::endl;

	for(int i = 1; i < n + 1; i++)
	{
		
		//_! Fill into_ arrays and plot graph
		eb__2[i-1] = Ebcalo2->GetBinContent(i);
		rb__2[i-1] = Rbcalo2->GetBinContent(i);
		eb__3[i-1] = Ebcalo3->GetBinContent(i);
		rb__3[i-1] = Rbcalo3->GetBinContent(i);
		eb__4[i-1] = Ebcalo4->GetBinContent(i);
		rb__4[i-1] = Rbcalo4->GetBinContent(i);
		eb__5[i-1] = Ebcalo5->GetBinContent(i);
		rb__5[i-1] = Rbcalo5->GetBinContent(i);
		//_! Fill into_ arrays and plot graph
		e_errb__2[i-1] = Ebcalo2->GetBinError(i);
		e_errb__3[i-1] = Ebcalo3->GetBinError(i);
		e_errb__4[i-1] = Ebcalo4->GetBinError(i);
		e_errb__5[i-1] = Ebcalo5->GetBinError(i);
		
		r_errb__2[i-1] = Rbcalo2->GetBinError(i);
		r_errb__3[i-1] = Rbcalo3->GetBinError(i);
		r_errb__4[i-1] = Rbcalo4->GetBinError(i);
		r_errb__5[i-1] = Rbcalo5->GetBinError(i);
	}
	//TGraphErrors *gb_1_ = new TGraphErrors(n,eb__2,rb__2,0,0);
	TGraphErrors *gb_1_ = new TGraphErrors(n,rb__2,eb__2,r_errb__2,e_errb__2);
	//gb_1_->GetXaxis()->SetTitle("trigger efficiency");
	//axis = gb_1_->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//gb_1_->GetYaxis()->SetTitleOffset(1.2);
	//gb_1_->GetYaxis()->SetTitle("trigger rate [MHz]");
	//gb_1_->GetXaxis()->SetTitle("trigger efficiency");
	//gb_1_->GetYaxis()->CenterTitle();
	//gb_1_->GetXaxis()->CenterTitle();
	//gb_1_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb_1_->SetMarkerStyle(kFullDiamond);//kFullCircle);
	gb_1_->SetMarkerColor(kBlack);
	gb_1_->SetLineColor(kBlack);
	gb_1_->SetMarkerSize(2.0);
	gb_1_->SetFillColor(kWhite);
	gb_1_->SetTitle("2^{nd} leading pt emulated calo-jet ");
	//gb1_->Draw("ACPe1");
	gb_1_->Draw("APe1");

	//TGraphErrors *gb_2_ = new TGraphErrors(n,eb__3,rb__3,0,0);
	TGraphErrors *gb_2_ = new TGraphErrors(n,rb__3,eb__3,r_errb__3,e_errb__3);
	//gb_2_->GetXaxis()->SetTitle("trigger efficiency");
	//axis = gb_2_->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//gb_2_->GetYaxis()->SetTitleOffset(1.2);
	//gb_2_->GetYaxis()->SetTitle("trigger rate [MHz]");
	//gb_2_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb_2_->SetMarkerStyle(kFullDiamond);//kFullTriangleUp);
	gb_2_->SetMarkerColor(kRed);
	gb_2_->SetLineColor(kRed);
	gb_2_->SetMarkerSize(2.0);
	gb_2_->SetFillColor(kWhite);
	gb_2_->SetTitle("3^{rd} leading pt emulated calo-jet ");
	//gb2_->Draw("CPe1");
	gb_2_->Draw("Pe1");

	//TGraphErrors *gb_3_ = new TGraphErrors(n,eb__4,rb__4,0,0);
	TGraphErrors *gb_3_ = new TGraphErrors(n,rb__4,eb__4,r_errb__4,e_errb__4);
	//gb_3_->GetXaxis()->SetTitle("trigger efficiency");
	//axis = gb_3_->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//gb_3_->GetYaxis()->SetTitleOffset(1.2);
	//gb_3_->GetYaxis()->SetTitle("trigger rate [MHz]");
	//gb_3_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb_3_->SetMarkerStyle(kFullDiamond);//k);
	gb_3_->SetMarkerColor(kGreen+2);
	gb_3_->SetLineColor(kGreen+2);
	gb_3_->SetMarkerSize(2.0);
	gb_3_->SetFillColor(kWhite);
	gb_3_->SetTitle("4^{th} leading pt emulated calo-jet ");
	//gb3_->Draw("CPe1");
	gb_3_->Draw("Pe1");

	//TGraphErrors *gb_4_ = new TGraphErrors(n,eb__5,rb__5,0,0);
	TGraphErrors *gb_4_ = new TGraphErrors(n,rb__5,eb__5,r_errb__5,e_errb__5);
	//gb_4_->GetXaxis()->SetTitle("trigger efficiency");
	//axis = gb_4_->GetXaxis();
	//axis->SetLimits(Xmin_range, Xmax_range);
	//gb_4_->GetYaxis()->SetTitleOffset(1.2);
	//gb_4_->GetYaxis()->SetTitle("trigger rate [MHz]");
	//gb_4_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb_4_->SetMarkerStyle(kFullDiamond);//kFullStar);
	gb_4_->SetMarkerColor(kBlue);
	gb_4_->SetLineColor(kBlue);
	gb_4_->SetMarkerSize(2.0);
	//_c1->cd(4);
	gb_4_->SetFillColor(kWhite);
	gb_4_->SetTitle("5^{th} leading pt emulated calo-jet ");
	//gb4_->Draw("CPe1");
	gb_4_->Draw("Pe1");


	/// print ///////////
	std::cout<<"calo-jets trigger efficiency at 1MHz: " <<std::endl;
	std::cout <<"2L: " <<gb_1_->Eval(1) << std::endl;
	std::cout <<"3L: " <<gb_2_->Eval(1) << std::endl;
	std::cout <<"4L: " <<gb_3_->Eval(1) << std::endl;
	std::cout <<"5L: " <<gb_4_->Eval(1) << std::endl;
	std::cout<<"calo-jets trigger efficiency at 4MHz: " <<std::endl;
	std::cout <<"2L: " <<gb_1_->Eval(4) << std::endl;
	std::cout <<"3L: " <<gb_2_->Eval(4) << std::endl;
	std::cout <<"4L: " <<gb_3_->Eval(4) << std::endl;
	std::cout <<"5L: " <<gb_4_->Eval(4) << std::endl << std::endl;
	std::cout<<"no z-bin-jets trigger efficiency at 1MHz: " <<std::endl;
	std::cout <<"2L: " <<gb1_->Eval(1) << std::endl;
	std::cout <<"3L: " <<gb2_->Eval(1) << std::endl;
	std::cout <<"4L: " <<gb3_->Eval(1) << std::endl;
	std::cout <<"5L: " <<gb4_->Eval(1) << std::endl;
	std::cout<<"no z-bin-jets trigger efficiency at 4MHz: " <<std::endl;
	std::cout <<"2L: " <<gb1_->Eval(4) << std::endl;
	std::cout <<"3L: " <<gb2_->Eval(4) << std::endl;
	std::cout <<"4L: " <<gb3_->Eval(4) << std::endl;
	std::cout <<"5L: " <<gb4_->Eval(4) << std::endl << std::endl;
	std::cout<<"no multi-bin(1.5mm)-jets trigger efficiency at 1MHz: " <<std::endl;
	std::cout <<"2L: " <<ga1_->Eval(1) << std::endl;
	std::cout <<"3L: " <<ga2_->Eval(1) << std::endl;
	std::cout <<"4L: " <<ga3_->Eval(1) << std::endl;
	std::cout <<"5L: " <<ga4_->Eval(1) << std::endl;
	std::cout<<"no multi-bin(1.5mm)-jets trigger efficiency at 4MHz: " <<std::endl;
	std::cout <<"2L: " <<ga1_->Eval(4) << std::endl;
	std::cout <<"3L: " <<ga2_->Eval(4) << std::endl;
	std::cout <<"4L: " <<ga3_->Eval(4) << std::endl;
	std::cout <<"5L: " <<ga4_->Eval(4) << std::endl << std::endl;
	std::cout<<"no max-bin(1.5mm)-jets trigger efficiency at 1MHz: " <<std::endl;
	std::cout <<"2L: " <<g1_->Eval(1) << std::endl;
	std::cout <<"3L: " <<g2_->Eval(1) << std::endl;
	std::cout <<"4L: " <<g3_->Eval(1) << std::endl;
	std::cout <<"5L: " <<g4_->Eval(1) << std::endl;
	std::cout<<"no max-bin(1.5mm)-jets trigger efficiency at 4MHz: " <<std::endl;
	std::cout <<"2L: " <<g1_->Eval(4) << std::endl;
	std::cout <<"3L: " <<g2_->Eval(4) << std::endl;
	std::cout <<"4L: " <<g3_->Eval(4) << std::endl;
	std::cout <<"5L: " <<g4_->Eval(4) << std::endl << std::endl;

//////////////////////////////////////////////////////////////
////// here starts multi graph ///////////////////////////////
//////////////////////////////////////////////////////////////
	
	Double_t xx1= 0.1,yy1= 0.72, xx2 = 0.19, yy2 = 0.9;
	c1->SetGridx();
	c1->SetGridy();
	TMultiGraph *mg = new TMultiGraph();
	mg->Add(gb2);
	mg->Add(gb1);
	mg->Add(gb3);
	mg->Add(gb4);
	mg->Draw("AP");
	//g->SetTitle(plot_title);
	mg->GetXaxis()->SetTitle("trigger efficiency");
	mg->GetYaxis()->SetTitle("trigger rate [MHz]");
	mg->GetXaxis()->SetTitleSize(0.04);
	mg->GetYaxis()->SetTitleSize(0.04);
//	g->GetXaxis()->SetRangeUser(0,100);
//	g->GetYaxis()->SetTitleOffset(1.5);
	mg->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	c1->BuildLegend(xx1,yy1,xx2,yy2,"max-bin");

	//! draw a second Y axis
	// scale rightmax to pad co-o
	//Float_t rightmax = 1.0*g->GetHistogram()->GetMaximum();
	//std::cout<< "rightmax: " << rightmax << std::endl;
	//std::cout<< "Uxmax: " << gPad->GetUxmax() << std::endl;
	//std::cout<< "Uymin: " << gPad->GetUymin() << std::endl;
	//std::cout<< "Uymax: " << gPad->GetUymax() << std::endl;
	//Float_t scale = 33.0/25.0;
	//TGaxis *A1 = new TGaxis(gPad->GetUxmax(), gPad->GetUymin(), gPad->GetUxmax(), rightmax, 0, Ymax_range*scale, 510, "+");
	//A1->Draw();
	c1->SetLogy();
	c1->Update();
	SaveCanvas(c1,"summary_ROChh4b_atleast1tracks3.75");
/////////////////////////////////////////////////////////////
///                    2D graphs
/////////////////////////////////////////////////////////////
	TCanvas *c_ = new TCanvas();
	//! multi-bin
	TGraph2DErrors *ga2d1 = new TGraph2DErrors(n,ea2,ra2,pt_threshold, e_erra2, r_erra2, 0);
	ga2d1->SetName("g2D2nd_maxpt");
	//ga2d1->GetXaxis()->SetTitle("trigger efficiency");
	//auto axis2d = ga2d1->GetXaxis();
	//axis2d->SetLimits(Xmin_range, Xmax_range);
	//ga2d1->GetYaxis()->SetTitleOffset(1.2);
	//ga2d1->GetYaxis()->SetTitle("trigger rate [MHz]");
	//auto axisy2d = ga2d1->GetYaxis();
	//axisy2d->SetRange(Ymin_range, Ymax_range);
	ga2d1->SetMarkerStyle(kFullTriangleDown);
	ga2d1->SetMarkerSize(TRIANGLEDOWN_SIZE);
	ga2d1->SetFillColor(kWhite);
	ga2d1->SetTitle("track-jet, multi-bin, 7.5mm");
	//ga2d1->SetTitle("2^{nd} leading pt track-jet, multi-bin, bin_size: 7.5mm");
	ga2d1->Draw("PCOLZ ERR");
	//TH1 *h2d = new TH2D();
	//h2d = ga2d1->Project("xy");
	//h2d->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	//c_->SetLogy();
	//h2d->Draw("colz");
	TGraph2DErrors *ga2d2 = new TGraph2DErrors(n,ea3,ra3,pt_threshold, e_erra3, r_erra3, 0);
	ga2d2->SetName("g2D3rd_maxpt");
	ga2d2->SetMarkerStyle(kFullTriangleDown);
	ga2d2->SetMarkerSize(TRIANGLEDOWN_SIZE);
	ga2d2->SetFillColor(kWhite);
	ga2d2->SetTitle("track-jet, multi-bin, 7.5mm");
	//ga2d2->SetTitle("3^{rd} leading pt track-jet, multi-bin, bin_size: 7.5mm");
	ga2d2->Draw("PCOLZ ERR");
	TGraph2DErrors *ga2d3 = new TGraph2DErrors(n,ea4,ra4,pt_threshold, e_erra4, r_erra4, 0);
	ga2d3->SetName("g2D4th_maxpt");
	ga2d3->SetMarkerStyle(kFullTriangleDown);
	ga2d3->SetMarkerSize(TRIANGLEDOWN_SIZE);
	ga2d3->SetFillColor(kWhite);
	ga2d3->SetTitle("track-jet, multi-bin, 7.5mm");
	//ga2d3->SetTitle("4^{th} leading pt track-jet, multi-bin, bin_size: 7.5mm");
	ga2d3->Draw("PCOLZ ERR");
	TGraph2DErrors *ga2d4 = new TGraph2DErrors(n,ea5,ra5,pt_threshold, e_erra5, r_erra5, 0);
	ga2d4->SetName("g2D5th_maxpt");
	ga2d4->SetMarkerStyle(kFullTriangleDown);
	ga2d4->SetMarkerSize(TRIANGLEDOWN_SIZE);
	ga2d4->SetFillColor(kWhite);
	ga2d4->SetTitle("track-jet, multi-bin, 7.5mm");
	//ga2d4->SetTitle("5^{th} leading pt track-jet, multi-bin, bin_size: 7.5mm");
	ga2d4->Draw("PCOLZ ERR");

	//! multi-bin +-1.5mm
	TGraph2DErrors *ga2d_1 = new TGraph2DErrors(n,ea_2,ra_2,pt_threshold, e_erra_2, r_erra_2, 0);
	ga2d_1->SetName("g2D_2nd_maxpt");
	ga2d_1->SetMarkerStyle(kFullStar);
	ga2d_1->SetMarkerSize(STAR_SIZE);
	ga2d_1->SetFillColor(kWhite);
	ga2d_1->SetTitle("track-jet, multi-bin, 1.5mm");
	//ga2d_1->SetTitle("2^{nd} leading pt track-jet, multi-bin, bin_size: 1.5mm");
	ga2d_1->Draw("PCOLZ ERR");
	TGraph2DErrors *ga2d_2 = new TGraph2DErrors(n,ea_3,ra_3,pt_threshold, e_erra_3, r_erra_3, 0);
	ga2d_2->SetName("g2D_3rd_maxpt");
	ga2d_2->SetMarkerStyle(kFullStar);
	ga2d_2->SetMarkerSize(STAR_SIZE);
	ga2d_2->SetFillColor(kWhite);
	ga2d_2->SetTitle("track-jet, multi-bin, 1.5mm");
	//ga2d_2->SetTitle("3^{rd} leading pt track-jet, multi-bin, bin_size: 1.5mm");
	ga2d_2->Draw("PCOLZ ERR");
	TGraph2DErrors *ga2d_3 = new TGraph2DErrors(n,ea_4,ra_4,pt_threshold, e_erra_4, r_erra_4, 0);
	ga2d_3->SetName("g2D_4th_maxpt");
	ga2d_3->SetMarkerStyle(kFullStar);
	ga2d_3->SetMarkerSize(STAR_SIZE);
	ga2d_3->SetFillColor(kWhite);
	ga2d_3->SetTitle("track-jet, multi-bin, 1.5mm");
	//ga2d_3->SetTitle("4^{th} leading pt track-jet, multi-bin, bin_size: 1.5mm");
	ga2d_3->Draw("PCOLZ ERR");
	TGraph2DErrors *ga2d_4 = new TGraph2DErrors(n,ea_5,ra_5,pt_threshold, e_erra_5, r_erra_5, 0);
	ga2d_4->SetName("g2D_5th_maxpt");
	ga2d_4->SetMarkerStyle(kFullStar);
	ga2d_4->SetMarkerSize(STAR_SIZE);
	ga2d_4->SetFillColor(kWhite);
	ga2d_4->SetTitle("track-jet, multi-bin, 1.5mm");
	//ga2d_4->SetTitle("5^{th} leading pt track-jet, multi-bin, bin_size: 1.5mm");
	ga2d_4->Draw("PCOLZ ERR");
	
	//! max-bin
	TGraph2DErrors *g2d1 = new TGraph2DErrors(n,e2,r2,pt_threshold, e_err2, r_err2, 0);
	g2d1->SetName("g2D2nd_sumpt");
	g2d1->SetMarkerStyle(kFullTriangleUp);
	g2d1->SetMarkerSize(TRIANGLEUP_SIZE);
	g2d1->SetFillColor(kWhite);
	g2d1->SetTitle("track-jet, max-bin, 7.5mm");
	//g2d1->SetTitle("2^{nd} leading pt track-jet, max-bin, bin_size: 7.5mm");
	g2d1->Draw("PCOLZ ERR");
	TGraph2DErrors *g2d2 = new TGraph2DErrors(n,e3,r3,pt_threshold, e_err3, r_err3, 0);
	g2d2->SetName("g2D3rd_sumpt");
	g2d2->SetMarkerStyle(kFullTriangleUp);
	g2d2->SetMarkerSize(TRIANGLEUP_SIZE);
	g2d2->SetFillColor(kWhite);
	g2d2->SetTitle("track-jet, max-bin, 7.5mm");
	//g2d2->SetTitle("3^{rd} leading pt track-jet, max-bin, bin_size: 7.5mm");
	g2d2->Draw("PCOLZ ERR");
	TGraph2DErrors *g2d3 = new TGraph2DErrors(n,e4,r4,pt_threshold, e_err4, r_err4, 0);
	g2d3->SetName("g2D4th_sumpt");
	g2d3->SetMarkerStyle(kFullTriangleUp);
	g2d3->SetMarkerSize(TRIANGLEUP_SIZE);
	g2d3->SetFillColor(kWhite);
	g2d3->SetTitle("track-jet, max-bin, 7.5mm");
	//g2d3->SetTitle("4^{th} leading pt track-jet, max-bin, bin_size: 7.5mm");
	g2d3->Draw("PCOLZ ERR");
	TGraph2DErrors *g2d4 = new TGraph2DErrors(n,e5,r5,pt_threshold, e_err5, r_err5, 0);
	g2d4->SetName("g2D5th_sumpt");
	g2d4->SetMarkerStyle(kFullTriangleUp);
	g2d4->SetMarkerSize(TRIANGLEUP_SIZE);
	g2d4->SetFillColor(kWhite);
	g2d4->SetTitle("track-jet, max-bin, 7.5mm");
	//g2d4->SetTitle("5^{th} leading pt track-jet, max-bin, bin_size: 7.5mm");
	g2d4->Draw("PCOLZ ERR");
	
	//! max-bin +-1.5mm
	TGraph2DErrors *g2d_1 = new TGraph2DErrors(n,e2_,r2_,pt_threshold, e_err2_, r_err2_, 0);
	g2d_1->SetName("g2D_2nd_sumpt");
	g2d_1->SetMarkerStyle(kFullStar);
	g2d_1->SetMarkerSize(STAR_SIZE);
	g2d_1->SetFillColor(kWhite);
	g2d_1->SetTitle("track-jet, max-bin, +-1.5mm");
	//g2d_1->SetTitle("2^{nd} leading pt track-jet, max-bin, bin_size: +-1.5mm");
	g2d_1->Draw("PCOLZ ERR");
	TGraph2DErrors *g2d_2 = new TGraph2DErrors(n,e3_,r3_,pt_threshold, e_err3_, r_err3_, 0);
	g2d_2->SetName("g2D_3rd_sumpt");
	g2d_2->SetMarkerStyle(kFullStar);
	g2d_2->SetMarkerSize(STAR_SIZE);
	g2d_2->SetFillColor(kWhite);
	g2d_2->SetTitle("track-jet, max-bin, +-1.5mm");
	//g2d_2->SetTitle("3^{rd} leading pt track-jet, max-bin, bin_size: +-1.5mm");
	g2d_2->Draw("PCOLZ ERR");
	TGraph2DErrors *g2d_3 = new TGraph2DErrors(n,e4_,r4_,pt_threshold, e_err4_, r_err4_, 0);
	g2d_3->SetName("g2D_4th_sumpt");
	g2d_3->SetMarkerStyle(kFullStar);
	g2d_3->SetMarkerSize(STAR_SIZE);
	g2d_3->SetFillColor(kWhite);
	g2d_3->SetTitle("track-jet, max-bin, +-1.5mm");
	//g2d_3->SetTitle("4^{th} leading pt track-jet, max-bin, bin_size: +-1.5mm");
	g2d_3->Draw("PCOLZ ERR");
	TGraph2DErrors *g2d_4 = new TGraph2DErrors(n,e5_,r5_,pt_threshold, e_err5_, r_err5_, 0);
	g2d_4->SetName("g2D_5th_sumpt");
	g2d_4->SetMarkerStyle(kFullStar);
	g2d_4->SetMarkerSize(STAR_SIZE);
	g2d_4->SetFillColor(kWhite);
	g2d_4->SetTitle("track-jet, max-bin, +-1.5mm");
	//g2d_4->SetTitle("5^{th} leading pt track-jet, max-bin, bin_size: +-1.5mm");
	g2d_4->Draw("PCOLZ ERR");

	//! no binning
	TGraph2DErrors *gb2d1 = new TGraph2DErrors(n,eb2,rb2,pt_threshold, e_errb2, r_errb2, 0);
	gb2d1->SetName("g2D2nd_nobin");
	//gb2d1->GetXaxis()->SetTitle("trigger efficiency");
	//auto axis2d = gb2d1->GetXaxis();
	//axis2d->SetLimits(Xmin_range, Xmax_range);
	//gb2d1->GetYaxis()->SetTitleOffset(1.2);
	//gb2d1->GetYaxis()->SetTitle("trigger rate [MHz]");
	//auto axisy2d = gb2d1->GetYaxis();
	//axisy2d->SetRange(Ymin_range, Ymax_range);
	gb2d1->SetMarkerStyle(kFullCircle);
	gb2d1->SetMarkerSize(1.4);
	gb2d1->SetFillColor(kWhite);
	gb2d1->SetTitle("track-jet, no z bin");
	//gb2d1->SetTitle("2^{nd} leading pt track-jet, no z bin");
	gb2d1->Draw("PCOLZ ERR");
	//TH1 *h2d = new TH2D();
	//h2d = gb2d1->Project("xy");
	//h2d->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	//c_->SetLogy();
	//h2d->Draw("colz");
	TGraph2DErrors *gb2d2 = new TGraph2DErrors(n,eb3,rb3,pt_threshold, e_errb3, r_errb3, 0);
	gb2d2->SetName("g2D3rd_nobin");
	gb2d2->SetMarkerStyle(kFullCircle);
	gb2d2->SetMarkerSize(1.4);
	gb2d2->SetFillColor(kWhite);
	gb2d2->SetTitle("track-jet, no z bin");
	//gb2d2->SetTitle("3^{rd} leading pt track-jet, no z bin");
	gb2d2->Draw("PCOLZ ERR");
	TGraph2DErrors *gb2d3 = new TGraph2DErrors(n,eb4,rb4,pt_threshold, e_errb4, r_errb4, 0);
	gb2d3->SetName("g2D4th_nobin");
	gb2d3->SetMarkerStyle(kFullCircle);
	gb2d3->SetMarkerSize(1.4);
	gb2d3->SetFillColor(kWhite);
	gb2d3->SetTitle("track-jet, no z bin");
	//gb2d3->SetTitle("4^{th} leading pt track-jet, no z bin");
	gb2d3->Draw("PCOLZ ERR");
	TGraph2DErrors *gb2d4 = new TGraph2DErrors(n,eb5,rb5,pt_threshold, e_errb5, r_errb5, 0);
	gb2d4->SetName("g2D5th_nobin");
	gb2d4->SetMarkerStyle(kFullCircle);
	gb2d4->SetMarkerSize(1.4);
	gb2d4->SetFillColor(kWhite);
	gb2d4->SetTitle("track-jet, no z bin");
	//gb2d4->SetTitle("5^{th} leading pt track-jet, no z bin");
	gb2d4->Draw("PCOLZ ERR");
	
	//! emulated calo-jet
	TGraph2DErrors *gb_2d1_ = new TGraph2DErrors(n,eb__2,rb__2,pt_threshold, e_errb__2, r_errb__2, 0);
	gb_2d1_->SetName("g2D2nd_calo");
	gb_2d1_->SetMarkerStyle(kFullDiamond);
	gb_2d1_->SetMarkerSize(DIAMOND_SIZE);
	gb_2d1_->SetFillColor(kWhite);
	gb_2d1_->SetTitle("emulated calo-jet");
	//gb_2d1_->SetTitle("2^{nd} leading pt emulated calo-jet");
	gb_2d1_->Draw("PCOLZ ERR");
	TGraph2DErrors *gb_2d2_ = new TGraph2DErrors(n,eb__3,rb__3,pt_threshold, e_errb__3, r_errb__3, 0);
	gb_2d2_->SetName("g2D3rd_calo");
	gb_2d2_->SetMarkerStyle(kFullDiamond);
	gb_2d2_->SetMarkerSize(DIAMOND_SIZE);
	gb_2d2_->SetFillColor(kWhite);
	gb_2d2_->SetTitle("emulated calo-jet");
	//gb_2d2_->SetTitle("3^{rd} leading pt emulated calo-jet");
	gb_2d2_->Draw("PCOLZ ERR");
	TGraph2DErrors *gb_2d3_ = new TGraph2DErrors(n,eb__4,rb__4,pt_threshold, e_errb__4, r_errb__4, 0);
	gb_2d3_->SetName("g2D4th_calo");
	gb_2d3_->SetMarkerStyle(kFullDiamond);
	gb_2d3_->SetMarkerSize(DIAMOND_SIZE);
	gb_2d3_->SetFillColor(kWhite);
	gb_2d3_->SetTitle("emulated calo-jet");
	//gb_2d3_->SetTitle("4^{th} leading pt emulated calo-jet");
	gb_2d3_->Draw("PCOLZ ERR");
	TGraph2DErrors *gb_2d4_ = new TGraph2DErrors(n,eb__5,rb__5,pt_threshold, e_errb__5, r_errb__5, 0);
	gb_2d4_->SetName("g2D5th_calo");
	gb_2d4_->SetMarkerStyle(kFullDiamond);
	gb_2d4_->SetMarkerSize(DIAMOND_SIZE);
	gb_2d4_->SetFillColor(kWhite);
	gb_2d4_->SetTitle("emulated calo-jet");
	//gb_2d4_->SetTitle("5^{th} leading pt emulated calo-jet");
	gb_2d4_->Draw("PCOLZ ERR");
///////////////////////////////////////////////////////////////////////
//////////////// writing to pdf ///////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//	char out_file_open[1023];
//        sprintf(out_file_open,"%s/%s.pdf(",out_path,output_file_name);
//        char out_file_[1023];
//        sprintf(out_file_,"%s/%s.pdf",out_path,output_file_name);
//        char out_file_close[1023];
//        sprintf(out_file_close,"%s/%s.pdf)",out_path,output_file_name);
//	
//	char out_root_file[1023];
//	sprintf(out_root_file, "%s/%s.root",out_path,output_file_name);
//
//
//	//Double_t x1 = 0.5, y1 = 0.11, x2 = 0.89, y2 = 0.39;
//	Double_t x1 = 0.49, y1 = 0.11, x2 = 0.95, y2 = 0.32;
//	//Double_t x1 = 0.01, y1 = 0.8, x2 = 0.49, y2 = 0.99;
//	//TCanvas * C = new TCanvas();
//	Legends();
//	TCanvas * C = new TCanvas("C","C",800,800);
//	//TCanvas * C = new TCanvas("C","C",1000,800);
//	gStyle->SetOptStat(0);
//	gStyle->SetOptTitle(0);
//	TGaxis::SetMaxDigits(3);
//	gPad->SetRightMargin(0.04);
//	C->SetGridx();
//	C->SetGridy();
//	//C->SetTickx();
//	//C->SetTicky();
//	C->SetLogy();
//	//C->Divide(2,2,0.5, 0.5);
//	//! page1
//	//! +-7.5mm 	
//	C->cd(1);
//	//gPad->SetGrid();
//	gPad->SetLogy();
//	g1->GetXaxis()->CenterTitle();
//	g1->GetYaxis()->CenterTitle();
//	g1->GetXaxis()->SetTitleSize(0.04);
//	g1->GetYaxis()->SetTitleSize(0.04);
//	g1->Draw("APe1");	//max-bin track-jet
//	ga1->Draw("Pe1");       //multi-bin track-jet
//	gb1->Draw("Pe1");       //unbinned track-jet
//	gb_1_->Draw("Pe1");     //emulated calo track-jet
//	g1->SetTitle("2^{nd} leading p_{t} track-jet");
//	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
//	TLegend *l1 = new TLegend(x1, y1, x2, y2, "");
//	l1->SetBorderSize(0);
//	l1->SetFillColor(kWhite);
//	l1->SetTextSize(0.04);
//	l1->SetHeader("2^{nd} leading","C");
//	l1->AddEntry(g1,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 7.5 mm", "p");
//	l1->AddEntry(ga1,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 7.5 mm","p");
//	l1->AddEntry(gb1,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
//	l1->AddEntry(gb_1_,"#kern[-3.0]{ } emulated calo-jet","p");
//	l1->SetTextAlign(12);
//	l1->SetMargin(0.15);
//	l1->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	fun->Draw("same");
//	gPad->Update();
//	//gPad->Write("c1a");
//	C->Print(out_file_open,"pdf");
//	C->SaveAs("./summary_plots/tex/C1_30mm_7515mm_2trk.tex");
//
//	//! page2
//	C->cd(2);
//	//gPad->SetGrid();
//	gPad->SetLogy();
//	g2->GetXaxis()->CenterTitle();
//	g2->GetYaxis()->CenterTitle();
//	g2->GetXaxis()->SetTitleSize(0.04);
//	g2->GetYaxis()->SetTitleSize(0.04);
//	g2->Draw("APe1");	//max-bin track-jet
//	ga2->Draw("Pe1");       //multi-bin track-jet
//	gb2->Draw("Pe1");       //unbinned track-jet
//	gb_2_->Draw("Pe1");     //emulated calo track-jet
//	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
//	g2->SetTitle("3^{rd} leading p_{t} track-jet");
//	TLegend *l2 = new TLegend(x1, y1, x2, y2, "");
//	l2->SetBorderSize(0);
//	l2->SetFillColor(kWhite);
//	l2->SetTextSize(0.04);
//	l2->SetHeader("3^{rd} leading","C");
//	l2->AddEntry(g2,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 7.5 mm","p");
//	l2->AddEntry(ga2,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 7.5 mm","p");
//	l2->AddEntry(gb2,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
//	l2->AddEntry(gb_2_,"#kern[-3.0]{ } emulated calo-jet","p");
//	l2->SetTextAlign(12);
//	l2->SetMargin(0.15);
//	l2->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	fun->Draw("same");
//	gPad->Update();
//	//gPad->Write("c1b");
//	C->Print(out_file_,"pdf");
//	C->SaveAs("./summary_plots/tex/C2_30mm_7515mm_2trk.tex");
//
//	//! page3
//	C->cd(3);
//	//gPad->SetGrid();
//	gPad->SetLogy();
//	g3->GetXaxis()->CenterTitle();
//	g3->GetYaxis()->CenterTitle();
//	g3->GetXaxis()->SetTitleSize(0.04);
//	g3->GetYaxis()->SetTitleSize(0.04);
//	g3->Draw("APe1");	//max-bin track-jet
//	ga3->Draw("Pe1");       //multi-bin track-jet
//	gb3->Draw("Pe1");       //unbinned track-jet
//	gb_3_->Draw("Pe1");     //emulated calo track-jet
//	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
//	g3->SetTitle("4^{th} leading p_{t} track-jet");
//	TLegend *l3 = new TLegend(x1, y1, x2, y2, "");
//	l3->SetBorderSize(0);
//	l3->SetFillColor(kWhite);
//	l3->SetTextSize(0.04);
//	l3->SetHeader("4^{th} leading","C");
//	l3->AddEntry(g3,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 7.5 mm","p");
//	l3->AddEntry(ga3,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 7.5 mm","p");
//	l3->AddEntry(gb3,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
//	l3->AddEntry(gb_3_,"#kern[-3.0]{ } emulated calo-jet","p");
//	l3->SetTextAlign(12);
//	l3->SetMargin(0.15);
//	l3->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	fun->Draw("same");
//	gPad->Update();
//	//gPad->Write("c1c");
//	C->Print(out_file_,"pdf");
//	C->SaveAs("./summary_plots/tex/C3_30mm_7515mm_2trk.tex");
//
//	//! page4
//	C->cd(4);
//	//gPad->SetGrid();
//	gPad->SetLogy();
//	g4->GetXaxis()->CenterTitle();
//	g4->GetYaxis()->CenterTitle();
//	g4->GetXaxis()->SetTitleSize(0.04);
//	g4->GetYaxis()->SetTitleSize(0.04);
//	g4->Draw("APe1");	//max-bin track-jet
//	ga4->Draw("Pe1");	//multi-bin track-jet
//	gb4->Draw("Pe1");	//unbinned track-jet
//	gb_4_->Draw("Pe1");	//emulated calo track-jet
//	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
//	g4->SetTitle("5^{th} leading p_{t} track-jet");
//	TLegend *l4 = new TLegend(x1, y1, x2, y2, "");
//	l4->SetBorderSize(0);
//	l4->SetFillColor(kWhite);
//	l4->SetTextSize(0.04);
//	l4->SetHeader("5^{th} leading","C");
//	l4->AddEntry(g4,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 7.5 mm","p");
//	l4->AddEntry(ga4,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 7.5 mm","p");
//	l4->AddEntry(gb4,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
//	l4->AddEntry(gb_4_,"#kern[-3.0]{ } emulated calo-jet","p");
//	l4->SetTextAlign(12);
//	l4->SetMargin(0.15);
//	l4->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	fun->Draw("same");
//	gPad->Update();
//	//gPad->Write("c1d");
//	C->Print(out_file_,"pdf");
//	C->SaveAs("./summary_plots/tex/C4_30mm_7515mm_2trk.tex");
//
//	//! page5
//	//! page2
//	//! +-1.5mm 	
//	C->cd(1);
//	//gPad->SetGrid();
//	gPad->SetLogy();
//	g1_->GetXaxis()->CenterTitle();
//	g1_->GetYaxis()->CenterTitle();
//	g1_->GetXaxis()->SetTitleSize(0.04);
//	g1_->GetYaxis()->SetTitleSize(0.04);
//	g1_->Draw("APe1");	//max-bin track-jet
//	ga1_->Draw("Pe1");       //multi-bin track-jet
//	gb1_->Draw("Pe1");       //unbinned track-jet
//	gb_1_->Draw("Pe1");     //emulated calo track-jet
//	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
//	g1_->SetTitle("2^{nd} leading p_{t} track-jet");
//	TLegend *l1_ = new TLegend(x1, y1, x2, y2, "");
//	l1_->SetBorderSize(0);
//	l1_->SetFillColor(kWhite);
//	l1_->SetTextSize(0.04);
//	l1_->SetHeader("2^{nd} leading","C");
//	l1_->AddEntry(g1_,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 1.5mm", "p");
//	l1_->AddEntry(ga1_,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 1.5mm","p");
//	l1_->AddEntry(gb1_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
//	l1_->AddEntry(gb_1_,"#kern[-3.0]{ } emulated calo-jet","p");
//	l1_->SetTextAlign(12);
//	l1_->SetMargin(0.15);
//	l1_->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	fun->Draw("same");
//	gPad->Update();
//	//gPad->Write("c2a");
//	C->Print(out_file_,"pdf");
//	C->SaveAs("./summary_plots/tex/C5_30mm_7515mm_2trk.tex");
//
//	//! page6
//	C->cd(2);
//	//gPad->SetGrid();
//	gPad->SetLogy();
//	g2_->GetXaxis()->CenterTitle();
//	g2_->GetYaxis()->CenterTitle();
//	g2_->GetXaxis()->SetTitleSize(0.04);
//	g2_->GetYaxis()->SetTitleSize(0.04);
//	g2_->Draw("APe1");	//max-bin track-jet
//	ga2_->Draw("Pe1");       //multi-bin track-jet
//	gb2_->Draw("Pe1");       //unbinned track-jet
//	gb_2_->Draw("Pe1");     //emulated calo track-jet
//	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
//	g2_->SetTitle("3^{rd} leading p_{t} track-jet");
//	TLegend *l2_ = new TLegend(x1, y1, x2, y2, "");
//	l2_->SetBorderSize(0);
//	l2_->SetFillColor(kWhite);
//	l2_->SetTextSize(0.04);
//	l2_->SetHeader("3^{rd} leading","C");
//	l2_->AddEntry(g2_,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 1.5mm", "p");
//	l2_->AddEntry(ga2_,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 1.5mm","p");
//	l2_->AddEntry(gb2_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
//	l2_->AddEntry(gb_2_,"#kern[-3.0]{ } emulated calo-jet","p");
//	l2_->SetTextAlign(12);
//	l2_->SetMargin(0.15);
//	l2_->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	fun->Draw("same");
//	gPad->Update();
//	//gPad->Write("c2b");
//	C->Print(out_file_,"pdf");
//	C->SaveAs("./summary_plots/tex/C6_30mm_7515mm_2trk.tex");
//
//	//! page7
//	C->cd(3);
//	//gPad->SetGrid();
//	gPad->SetLogy();
//	g3_->GetXaxis()->CenterTitle();
//	g3_->GetYaxis()->CenterTitle();
//	g3_->GetXaxis()->SetTitleSize(0.04);
//	g3_->GetYaxis()->SetTitleSize(0.04);
//	g3_->Draw("APe1");	//max-bin track-jet
//	ga3_->Draw("Pe1");       //multi-bin track-jet
//	gb3_->Draw("Pe1");       //unbinned track-jet
//	gb_3_->Draw("Pe1");     //emulated calo track-jet
//	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
//	g3_->SetTitle("4^{th} leading p_{t} track-jet");
//	y1 = 0.49; y2 = 0.7;
//	TLegend *l3_ = new TLegend(x1, y1, x2, y2, "");
//	l3_->SetBorderSize(0);
//	l3_->SetFillColor(kWhite);
//	l3_->SetTextSize(0.04);
//	l3_->SetHeader("4^{th} leading","C");
//	l3_->AddEntry(g3_,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 1.5mm", "p");
//	l3_->AddEntry(ga3_,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 1.5mm","p");
//	l3_->AddEntry(gb3_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
//	l3_->AddEntry(gb_3_,"#kern[-3.0]{ } emulated calo-jet","p");
//	l3_->SetTextAlign(12);
//	l3_->SetMargin(0.15);
//	l3_->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	fun->Draw("same");
//	gPad->Update();
//	//gPad->Write("c2c");
//	C->Print(out_file_,"pdf");
//	C->SaveAs("./summary_plots/tex/C7_30mm_7515mm_2trk.tex");
//
//	//! page8
//	C->cd(4);
//	//gPad->SetGrid();
//	gPad->SetLogy();
//	g4_->GetXaxis()->CenterTitle();
//	g4_->GetYaxis()->CenterTitle();
//	g4_->GetXaxis()->SetTitleSize(0.04);
//	g4_->GetYaxis()->SetTitleSize(0.04);
//	g4_->Draw("APe1");	//max-bin track-jet
//	ga4_->Draw("Pe1");	//multi-bin track-jet
//	gb4_->Draw("Pe1");	//unbinned track-jet
//	gb_4_->Draw("Pe1");	//emulated calo track-jet
//	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
//	g4_->SetTitle("5^{th} leading p_{t} track-jet");
//	TLegend *l4_ = new TLegend(x1, y1, x2, y2, "");
//	l4_->SetBorderSize(0);
//	l4_->SetFillColor(kWhite);
//	l4_->SetTextSize(0.04);
//	l4_->SetHeader("5^{th} leading","C");
//	l4_->AddEntry(g4_,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 1.5mm", "p");
//	l4_->AddEntry(ga4_,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 1.5mm","p");
//	l4_->AddEntry(gb4_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
//	l4_->AddEntry(gb_4_,"#kern[-3.0]{ } emulated calo-jet","p");
//	l4_->SetTextAlign(12);
//	l4_->SetMargin(0.15);
//	l4_->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	fun->Draw("same");
//	gPad->Update();
//	//gPad->Write("c2d");
//	C->Print(out_file_,"pdf");
//	C->SaveAs("./summary_plots/tex/C8_30mm_7515mm_2trk.tex");
//
//
//	//! page9
//	//! page3
//	y1 = 0.11; y2 = 0.32;
//	//! +-7.5, +-1.5mm multi-bin	
//	C->cd(1);
//	//gPad->SetGrid();
//	gPad->SetLogy();
//	ga1->GetXaxis()->CenterTitle();
//	ga1->GetYaxis()->CenterTitle();
//	ga1->GetXaxis()->SetTitleSize(0.04);
//	ga1->GetYaxis()->SetTitleSize(0.04);
//	ga1->Draw("APe1");	//multi-bin 7.5  track-jet
//	ga1_->Draw("Pe1");       //multi-bin 3.75 track-jet
//	gb1_->Draw("Pe1");       //unbinned track-jet
//	gb_1_->Draw("Pe1");     //emulated calo track-jet
//	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
//	g1_->SetTitle("2^{nd} leading p_{t} track-jet");
//	TLegend *l1__ = new TLegend(x1, y1, x2, y2, "");
//	l1__->SetBorderSize(0);
//	l1__->SetFillColor(kWhite);
//	l1__->SetTextSize(0.04);
//	l1__->SetHeader("2^{nd} leading","C");
//	l1__->AddEntry(ga1_,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 1.5mm","p");
//	l1__->AddEntry(ga1,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 7.5 mm", "p");
//	l1__->AddEntry(gb1_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
//	l1__->AddEntry(gb_1_,"#kern[-3.0]{ } emulated calo-jet","p");
//	l1__->SetTextAlign(12);
//	l1__->SetMargin(0.15);
//	l1__->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	fun->Draw("same");
//	gPad->Update();
//	//gPad->Write("c3a");
//	C->Print(out_file_,"pdf");
//	C->SaveAs("./summary_plots/tex/C9_30mm_7515mm_2trk.tex");
//
//	//! page10
//	C->cd(2);
//	//gPad->SetGrid();
//	gPad->SetLogy();
//	ga2->GetXaxis()->CenterTitle();
//	ga2->GetYaxis()->CenterTitle();
//	ga2->GetXaxis()->SetTitleSize(0.04);
//	ga2->GetYaxis()->SetTitleSize(0.04);
//	ga2->Draw("APe1");	//multi-bin 7.5  track-jet
//	ga2_->Draw("Pe1");       //multi-bin 3.75 track-jet
//	gb2_->Draw("Pe1");       //unbinned track-jet
//	gb_2_->Draw("Pe1");     //emulated calo track-jet
//	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
//	g2_->SetTitle("3^{rd} leading p_{t} track-jet");
//	TLegend *l2__ = new TLegend(x1, y1, x2, y2, "");
//	l2__->SetBorderSize(0);
//	l2__->SetFillColor(kWhite);
//	l2__->SetTextSize(0.04);
//	l2__->SetHeader("3^{rd} leading","C");
//	l2__->AddEntry(ga2_,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 1.5mm","p");
//	l2__->AddEntry(ga2,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 7.5 mm", "p");
//	l2__->AddEntry(gb2_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
//	l2__->AddEntry(gb_2_,"#kern[-3.0]{ } emulated calo-jet","p");
//	l2__->SetTextAlign(12);
//	l2__->SetMargin(0.15);
//	l2__->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	fun->Draw("same");
//	gPad->Update();
//	//gPad->Write("c3b");
//	C->Print(out_file_,"pdf");
//	C->SaveAs("./summary_plots/tex/C10_30mm_7515mm_2trk.tex");
//
//	//! page11
//	C->cd(3);
//	//gPad->SetGrid();
//	gPad->SetLogy();
//	ga3->GetXaxis()->CenterTitle();
//	ga3->GetYaxis()->CenterTitle();
//	ga3->GetXaxis()->SetTitleSize(0.04);
//	ga3->GetYaxis()->SetTitleSize(0.04);
//	ga3->Draw("APe1");	//multi-bin 7.5 track-jet
//	ga3_->Draw("Pe1");       //multi-bin 3.75 track-jet
//	gb3_->Draw("Pe1");       //unbinned track-jet
//	gb_3_->Draw("Pe1");     //emulated calo track-jet
//	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
//	g3_->SetTitle("4^{th} leading p_{t} track-jet");
//	y1 = 0.45; y2 = 0.66;
//	TLegend *l3__ = new TLegend(x1, y1, x2, y2, "");
//	l3__->SetBorderSize(0);
//	l3__->SetFillColor(kWhite);
//	l3__->SetTextSize(0.04);
//	l3__->SetHeader("4^{th} leading","C");
//	l3__->AddEntry(ga3_,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 1.5mm","p");
//	l3__->AddEntry(ga3,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 7.5 mm", "p");
//	l3__->AddEntry(gb3_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
//	l3__->AddEntry(gb_3_,"#kern[-3.0]{ } emulated calo-jet","p");
//	l3__->SetTextAlign(12);
//	l3__->SetMargin(0.15);
//	l3__->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	fun->Draw("same");
//	gPad->Update();
//	//gPad->Write("c3c");
//	C->Print(out_file_,"pdf");
//	C->SaveAs("./summary_plots/tex/C11_30mm_7515mm_2trk.tex");
//
//	//! page12
//	C->cd(4);
//	//gPad->SetGrid();
//	gPad->SetLogy();
//	ga4->GetXaxis()->CenterTitle();
//	ga4->GetYaxis()->CenterTitle();
//	ga4->GetXaxis()->SetTitleSize(0.04);
//	ga4->GetYaxis()->SetTitleSize(0.04);
//	ga4->Draw("APe1");	//multi-bin 7.5 track-jet
//	ga4_->Draw("Pe1");	//multi-bin 3.75 track-jet
//	gb4_->Draw("Pe1");	//unbinned track-jet
//	gb_4_->Draw("Pe1");	//emulated calo track-jet
//	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
//	g4_->SetTitle("5^{th} leading p_{t} track-jet");
//	y1 = 0.35; y2 = 0.56;
//	TLegend *l4__ = new TLegend(x1, y1, x2, y2, "");
//	l4__->SetBorderSize(0);
//	l4__->SetFillColor(kWhite);
//	l4__->SetTextSize(0.04);
//	l4__->SetHeader("5^{th} leading","C");
//	l4__->AddEntry(ga4_,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 1.5mm","p");
//	l4__->AddEntry(ga4,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 7.5 mm", "p");
//	l4__->AddEntry(gb4_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
//	l4__->AddEntry(gb_4_,"#kern[-3.0]{ } emulated calo-jet","p");
//	l4__->SetTextAlign(12);
//	l4__->SetMargin(0.15);
//	l4__->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	fun->Draw("same");
//	gPad->Update();
//	//gPad->Write("c3d");
//	C->Print(out_file_,"pdf");
//	C->SaveAs("./summary_plots/tex/C12_30mm_7515mm_2trk.tex");
//
//	//! page13
//	//! page4
//	//! +-7.5, +-1.5mm max-bin
//	C->cd(1);
//	//gPad->SetGrid();
//	gPad->SetLogy();
//	g1->Draw("APe1");	//max-bin 7.5  track-jet
//	g1_->Draw("Pe1");       //max-bin 3.75 track-jet
//	gb1_->Draw("Pe1");       //unbinned track-jet
//	gb_1_->Draw("Pe1");     //emulated calo track-jet
//	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
//	g1_->SetTitle("2^{nd} leading p_{t} track-jet");
//	y1 = 0.11; y2 = 0.32;
//	TLegend *l_1__ = new TLegend(x1, y1, x2, y2, "");
//	l_1__->SetBorderSize(0);
//	l_1__->SetFillColor(kWhite);
//	l_1__->SetTextSize(0.04);
//	l_1__->SetHeader("2^{nd} leading","C");
//	l_1__->AddEntry(g1_,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 1.5mm","p");
//	l_1__->AddEntry(g1,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 7.5 mm", "p");
//	l_1__->AddEntry(gb1_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
//	l_1__->AddEntry(gb_1_,"#kern[-3.0]{ } emulated calo-jet","p");
//	l_1__->SetTextAlign(12);
//	l_1__->SetMargin(0.15);
//	l_1__->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	fun->Draw("same");
//	gPad->Update();
//	//gPad->Write("c4a");
//	C->Print(out_file_,"pdf");
//	C->SaveAs("./summary_plots/tex/C13_30mm_7515mm_2trk.tex");
//
//	//! page14
//	C->cd(2);
//	//gPad->SetGrid();
//	gPad->SetLogy();
//	g2->Draw("APe1");	//max-bin 7.5  track-jet
//	g2_->Draw("Pe1");       //max-bin 3.75 track-jet
//	gb2_->Draw("Pe1");       //unbinned track-jet
//	gb_2_->Draw("Pe1");     //emulated calo track-jet
//	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
//	g2_->SetTitle("3^{rd} leading p_{t} track-jet");
//	TLegend *l_2__ = new TLegend(x1, y1, x2, y2, "");
//	l_2__->SetBorderSize(0);
//	l_2__->SetFillColor(kWhite);
//	l_2__->SetTextSize(0.04);
//	l_2__->SetHeader("3^{rd} leading","C");
//	l_2__->AddEntry(g2_,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 1.5mm","p");
//	l_2__->AddEntry(g2,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 7.5 mm", "p");
//	l_2__->AddEntry(gb2_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
//	l_2__->AddEntry(gb_2_,"#kern[-3.0]{ } emulated calo-jet","p");
//	l_2__->SetTextAlign(12);
//	l_2__->SetMargin(0.15);
//	l_2__->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	fun->Draw("same");
//	gPad->Update();
//	//gPad->Write("c4b");
//	C->Print(out_file_,"pdf");
//	C->SaveAs("./summary_plots/tex/C14_30mm_7515mm_2trk.tex");
//
//	//! page15
//	C->cd(3);
//	//gPad->SetGrid();
//	gPad->SetLogy();
//	g3->Draw("APe1");	//max-bin 7.5 track-jet
//	g3_->Draw("Pe1");       //max-bin 3.75 track-jet
//	gb3_->Draw("Pe1");       //unbinned track-jet
//	gb_3_->Draw("Pe1");     //emulated calo track-jet
//	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
//	g3_->SetTitle("4^{th} leading p_{t} track-jet");
//	y1 = 0.44; y2 = 0.65;
//	TLegend *l_3__ = new TLegend(x1, y1, x2, y2, "");
//	l_3__->SetBorderSize(0);
//	l_3__->SetFillColor(kWhite);
//	l_3__->SetTextSize(0.04);
//	l_3__->SetHeader("4^{th} leading","C");
//	l_3__->AddEntry(g3_,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 1.5mm","p");
//	l_3__->AddEntry(g3,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 7.5 mm", "p");
//	l_3__->AddEntry(gb3_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
//	l_3__->AddEntry(gb_3_,"#kern[-3.0]{ } emulated calo-jet","p");
//	l_3__->SetTextAlign(12);
//	l_3__->SetMargin(0.15);
//	l_3__->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	fun->Draw("same");
//	gPad->Update();
//	//gPad->Write("c4c");
//	C->Print(out_file_,"pdf");
//	C->SaveAs("./summary_plots/tex/C15_30mm_7515mm_2trk.tex");
//
//	//! page16
//	C->cd(4);
//	//gPad->SetGrid();
//	gPad->SetLogy();
//	g4->Draw("APe1");	//max-bin 7.5 track-jet
//	g4_->Draw("Pe1");	//max-bin 3.75 track-jet
//	gb4_->Draw("Pe1");	//unbinned track-jet
//	gb_4_->Draw("Pe1");	//emulated calo track-jet
//	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
//	g4_->SetTitle("5^{th} leading p_{t} track-jet");
//	y1 = 0.24; y2 = 0.45;
//	TLegend *l_4__ = new TLegend(x1, y1, x2, y2, "");
//	l_4__->SetBorderSize(0);
//	l_4__->SetFillColor(kWhite);
//	l_4__->SetTextSize(0.04);
//	l_4__->SetHeader("5^{th} leading","C");
//	l_4__->AddEntry(g4_,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 1.5mm","p");
//	l_4__->AddEntry(g4,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 7.5 mm", "p");
//	l_4__->AddEntry(gb4_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
//	l_4__->AddEntry(gb_4_,"#kern[-3.0]{ } emulated calo-jet","p");
//	l_4__->SetTextAlign(12);
//	l_4__->SetMargin(0.15);
//	l_4__->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	fun->Draw("same");
//	gPad->Update();
//	//gPad->Write("c4d");
//	C->Print(out_file_,"pdf");
//	C->SaveAs("./summary_plots/tex/C16_30mm_7515mm_2trk.tex");
//
//	//gPad->DrawFrame(Xmin_range, Ymin_range, Xmax_range, Ymax_range);
//	//https://root-forum.cern.ch/t/tgraph2d-access-xyz-range-and-title-out-of-sync-color-bar/15722	
//	TH2D *h2d1 = new TH2D("h2d1","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *h2d2 = new TH2D("h2d2","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *h2d3 = new TH2D("h2d3","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *h2d4 = new TH2D("h2d4","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *h2d_1 = new TH2D("h2d_1","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *h2d_2 = new TH2D("h2d_2","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *h2d_3 = new TH2D("h2d_3","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *h2d_4 = new TH2D("h2d_4","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *ha2d1 = new TH2D("ha2d1","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *ha2d2 = new TH2D("ha2d2","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *ha2d3 = new TH2D("ha2d3","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *ha2d4 = new TH2D("ha2d4","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *ha2d_1 = new TH2D("ha2d_1","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *ha2d_2 = new TH2D("ha2d_2","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *ha2d_3 = new TH2D("ha2d_3","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *ha2d_4 = new TH2D("ha2d_4","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *hb2d1 = new TH2D("hb2d1","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *hb2d2 = new TH2D("hb2d2","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *hb2d3 = new TH2D("hb2d3","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *hb2d4 = new TH2D("hb2d4","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *h2d1_ = new TH2D("h2d1_","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *h2d2_ = new TH2D("h2d2_","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *h2d3_ = new TH2D("h2d3_","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//	TH2D *h2d4_ = new TH2D("h2d4_","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
//
//	h2d1->GetXaxis()->CenterTitle();
//	h2d2->GetXaxis()->CenterTitle();
//	h2d3->GetXaxis()->CenterTitle();
//	h2d4->GetXaxis()->CenterTitle();
//	h2d_1->GetXaxis()->CenterTitle();
//	h2d_2->GetXaxis()->CenterTitle();
//	h2d_3->GetXaxis()->CenterTitle();
//	h2d_4->GetXaxis()->CenterTitle();
//	ha2d1->GetXaxis()->CenterTitle();
//	ha2d2->GetXaxis()->CenterTitle();
//	ha2d3->GetXaxis()->CenterTitle();
//	ha2d4->GetXaxis()->CenterTitle();
//	ha2d_1->GetXaxis()->CenterTitle();
//	ha2d_2->GetXaxis()->CenterTitle();
//	ha2d_3->GetXaxis()->CenterTitle();
//	ha2d_4->GetXaxis()->CenterTitle();
//	hb2d1->GetXaxis()->CenterTitle();
//	hb2d2->GetXaxis()->CenterTitle();
//	hb2d3->GetXaxis()->CenterTitle();
//	hb2d4->GetXaxis()->CenterTitle();
//	h2d1_->GetXaxis()->CenterTitle();
//	h2d2_->GetXaxis()->CenterTitle();
//	h2d3_->GetXaxis()->CenterTitle();
//	h2d4_->GetXaxis()->CenterTitle();
//
//	h2d1->GetYaxis()->CenterTitle();
//	h2d2->GetYaxis()->CenterTitle();
//	h2d3->GetYaxis()->CenterTitle();
//	h2d4->GetYaxis()->CenterTitle();
//	h2d_1->GetYaxis()->CenterTitle();
//	h2d_2->GetYaxis()->CenterTitle();
//	h2d_3->GetYaxis()->CenterTitle();
//	h2d_4->GetYaxis()->CenterTitle();
//	ha2d1->GetYaxis()->CenterTitle();
//	ha2d2->GetYaxis()->CenterTitle();
//	ha2d3->GetYaxis()->CenterTitle();
//	ha2d4->GetYaxis()->CenterTitle();
//	ha2d_1->GetYaxis()->CenterTitle();
//	ha2d_2->GetYaxis()->CenterTitle();
//	ha2d_3->GetYaxis()->CenterTitle();
//	ha2d_4->GetYaxis()->CenterTitle();
//	hb2d1->GetYaxis()->CenterTitle();
//	hb2d2->GetYaxis()->CenterTitle();
//	hb2d3->GetYaxis()->CenterTitle();
//	hb2d4->GetYaxis()->CenterTitle();
//	h2d1_->GetYaxis()->CenterTitle();
//	h2d2_->GetYaxis()->CenterTitle();
//	h2d3_->GetYaxis()->CenterTitle();
//	h2d4_->GetYaxis()->CenterTitle();
//	//x2 = 0.85;
//	//x2 = 0.42;
//	
//	//gStyle->SetPalette(kColorPrintableOnGrey);
//	//gStyle->SetPalette(kRainBow);
//	gStyle->SetPalette(kLightTemperature);
//	//! page17
//	//! page5
//	//! multi-bin and calo
//	C->Clear();
//	C->cd(1);
//	ga2d1->SetHistogram(ha2d1);
//	ga2d_1->SetHistogram(ha2d_1);
//	gb2d1->SetHistogram(hb2d1);
//	gb_2d1_->SetHistogram(h2d1_);
//	//ha2d1->Write();
//	//ga2d1->Write();
//	
//	//gPad->SetFillStyle(4000);
//	ha2d1->GetXaxis()->SetTitle("trigger efficiency");
//	ha2d1->GetXaxis()->SetTitleOffset(1.5);
//	ha2d1->GetYaxis()->SetTitle("trigger rate [MHz]");
//	ha2d1->GetZaxis()->SetTitleOffset(1.3);
//	ha2d1->GetZaxis()->SetTitle("p_{T} [GeV/c]");
//	ga2d1->GetXaxis()->SetTitleSize(0.04);
//	ga2d1->GetYaxis()->SetTitleSize(0.04);
//	ga2d1->GetZaxis()->SetTitleSize(0.04);
//	ga2d1->Draw("PCOLZ ERR");
//	ga2d_1->Draw("PCOL ERR same");
//	gb2d1->Draw("PCOL ERR same");
//	gb_2d1_->Draw("PCOL ERR same");
//	//fun->Draw("same");
//	gPad->SetTheta(90.0);
//	gPad->SetPhi(0.001);
//	gPad->SetRightMargin(0.15);
//	gPad->SetLeftMargin(0.125);
//	//gPad->BuildLegend(x1, y1, x2, y2, "2^{nd} leading p_{t}", "PL"); // ROOT 6
//	x1 = 0.35, x2 = 0.75, y1 = 0.11, y2 = 0.31;
//	TLegend *J1 = new TLegend(x1+0.15,y2+0.01,x2,y2+0.05);
//	J1->SetFillColor(kWhite);
//        J1->SetBorderSize(0);
//        J1->AddEntry((TObject*)0, "2^{nd} leading", "");
//        J1->SetTextSize(0.04);
//	J1->Draw();
//	TLegend *l1___ = new TLegend(x1, y1, x2, y2, "");
//	l1___->SetBorderSize(0);
//	l1___->SetFillColor(kWhite);
//	l1___->SetTextSize(0.04);
//	l1___->AddEntry(ga2d_1,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 1.5mm","p");
//	l1___->AddEntry(ga2d1,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 7.5 mm", "p");
//	l1___->AddEntry(gb2d1,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
//	l1___->AddEntry(gb_2d1_,"#kern[-3.0]{ } emulated calo-jet","p");
//	l1___->SetTextAlign(12);
//	l1___->SetMargin(0.15);
//	l1___->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	gPad->Modified();
//	gPad->Update();
//	C->Print(out_file_,"pdf");
//	C->SaveAs("./summary_plots/tex/C17_30mm_7515mm_2trk.tex");
//	//cc->Write("c5a");
//	//gPad->GetView()->TopView();
//	//! page18
//	C->cd(2);
//	ga2d2->SetHistogram(ha2d2);
//	ga2d_2->SetHistogram(ha2d_2);
//	gb2d2->SetHistogram(hb2d2);
//	gb_2d2_->SetHistogram(h2d2_);
//	//gPad->SetFillStyle(4000);
//	ga2d2->Draw("PCOLZ ERR");
//	ga2d_2->Draw("PCOL ERR same");
//	gb2d2->Draw("PCOL ERR same");
//	gb_2d2_->Draw("PCOL ERR same");
//	//fun->Draw("same");
//	gPad->SetTheta(90.0);
//	gPad->SetPhi(0.001);
//	ga2d2->GetXaxis()->SetTitle("trigger efficiency");
//	ga2d2->GetXaxis()->SetTitleOffset(1.5);
//	ga2d2->GetYaxis()->SetTitle("trigger rate [MHz]");
//	ga2d2->GetZaxis()->SetTitle("p_{T} [GeV/c]");
//	ga2d2->GetZaxis()->SetTitleOffset(1.3);
//	ga2d2->GetXaxis()->SetTitleSize(0.04);
//	ga2d2->GetYaxis()->SetTitleSize(0.04);
//	ga2d2->GetZaxis()->SetTitleSize(0.04);
//	gPad->SetRightMargin(0.15);
//	gPad->SetLeftMargin(0.125);
//	//gPad->BuildLegend(x1, y1, x2, y2, "3^{rd} leading p_{t}", "PL"); // ROOT 6
//	//l2__->Draw();
//	l1___->Draw();
//	TLegend *J2 = new TLegend(x1+0.15,y2+0.01,x2,y2+0.05);
//	//TLegend *J2 = new TLegend(x1+0.15,y2-0.1,x2,y2-0.06);
//	J2->SetFillColor(kWhite);
//        J2->SetBorderSize(0);
//        J2->AddEntry((TObject*)0, "3^{rd} leading", "");
//        J2->SetTextSize(0.04);
//	J2->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	gPad->Modified();
//	gPad->Update();
//	//gPad->Write("c5b");
//	C->Print(out_file_,"pdf");
//	C->SaveAs("./summary_plots/tex/C18_30mm_7515mm_2trk.tex");
//	//! page19
//	C->cd(3);
//	ga2d3->SetHistogram(ha2d3);
//	ga2d_3->SetHistogram(ha2d_3);
//	gb2d3->SetHistogram(hb2d3);
//	gb_2d3_->SetHistogram(h2d3_);
//	//gPad->SetFillStyle(4000);
//	ga2d3->Draw("PCOLZ ERR");
//	ga2d_3->Draw("PCOL ERR same");
//	gb2d3->Draw("PCOL ERR same");
//	gb_2d3_->Draw("PCOL ERR same");
//	//fun->Draw("same");
//	gPad->SetTheta(90.0);
//	gPad->SetPhi(0.001);
//	ga2d3->GetXaxis()->SetTitle("trigger efficiency");
//	ga2d3->GetXaxis()->SetTitleOffset(1.5);
//	ga2d3->GetYaxis()->SetTitle("trigger rate [MHz]");
//	ga2d3->GetZaxis()->SetTitle("p_{T} [GeV/c]");
//	ga2d3->GetZaxis()->SetTitleOffset(1.3);
//	ga2d3->GetXaxis()->SetTitleSize(0.04);
//	ga2d3->GetYaxis()->SetTitleSize(0.04);
//	ga2d3->GetZaxis()->SetTitleSize(0.04);
//	gPad->SetRightMargin(0.15);
//	gPad->SetLeftMargin(0.125);
//	//gPad->BuildLegend(x1, y1, x2, y2, "4^{th} leading p_{t}", "PL"); // ROOT 6
//	//l3__->Draw();
//	l1___->Draw();
//	TLegend *J3 = new TLegend(x1+0.15,y2+0.01,x2,y2+0.05);
//	//TLegend *J3 = new TLegend(x1+0.15,y2-0.1,x2,y2-0.06);
//	J3->SetFillColor(kWhite);
//        J3->SetBorderSize(0);
//        J3->AddEntry((TObject*)0, "4^{th} leading", "");
//        J3->SetTextSize(0.04);
//	J3->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	gPad->Modified();
//	gPad->Update();
//	//gPad->Write("c5c");
//	C->Print(out_file_,"pdf");
//	C->SaveAs("./summary_plots/tex/C19_30mm_7515mm_2trk.tex");
//	//! page20
//	C->cd(4);
//	ga2d4->SetHistogram(ha2d4);
//	ga2d_4->SetHistogram(ha2d_4);
//	gb2d4->SetHistogram(hb2d4);
//	gb_2d4_->SetHistogram(h2d4_);
//	//gPad->SetFillStyle(4000);
//	ga2d4->Draw("PCOLZ C ERR");
//	ga2d_4->Draw("PCOL ERR same");
//	gb2d4->Draw("PCOL ERR same");
//	gb_2d4_->Draw("PCOL ERR same");
//	//fun->Draw("same");
//	gPad->SetTheta(90.0);
//	gPad->SetPhi(0.001);
//	ga2d4->GetXaxis()->SetTitle("trigger efficiency");
//	ga2d4->GetXaxis()->SetTitleOffset(1.5);
//	ga2d4->GetYaxis()->SetTitle("trigger rate [MHz]");
//	ga2d4->GetZaxis()->SetTitle("p_{T} [GeV/c]");
//	ga2d4->GetZaxis()->SetTitleOffset(1.3);
//	ga2d4->GetXaxis()->SetTitleSize(0.04);
//	ga2d4->GetYaxis()->SetTitleSize(0.04);
//	ga2d4->GetZaxis()->SetTitleSize(0.04);
//	gPad->SetRightMargin(0.15);
//	gPad->SetLeftMargin(0.125);
//	//gPad->BuildLegend(x1, y1, x2, y2, "5^{th} leading p_{t}", "PL"); // ROOT 6
//	//l4__->Draw();
//	l1___->Draw();
//	TLegend *J4 = new TLegend(x1+0.15,y2+0.01,x2,y2+0.05);
//	//TLegend *J4 = new TLegend(x1+0.15,y2+0.01,x2,y2+0.05);
//	J4->SetFillColor(kWhite);
//        J4->SetBorderSize(0);
//        J4->AddEntry((TObject*)0, "5^{th} leading", "");
//        J4->SetTextSize(0.04);
//	J4->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	gPad->Modified();
//	gPad->Update();
//	//gPad->Write("c5d");
//	C->SaveAs("./summary_plots/pdf/c5.C");
//	C->Print(out_file_, "pdf");
//	C->SaveAs("./summary_plots/tex/C20_30mm_7515mm_2trk.tex");
//
//	//! page21
//	C->Clear();
//	//C->Divide(2,2,0.5,0.5);
//	//! page6
//	//! max-bin and calo
//	C->cd(1);
//	gPad->SetLogy();
//	g2d1->SetHistogram(h2d1);
//	g2d_1->SetHistogram(h2d_1);
//	//gPad->SetFillStyle(4000);
//	g2d1->Draw("PCOLZ ERR");
//	g2d_1->Draw("PCOL ERR same");
//	gb2d1->Draw("PCOL ERR same");
//	gb_2d1_->Draw("PCOL ERR same");
//	//fun->Draw("same");
//	gPad->SetTheta(90.0);
//	gPad->SetPhi(0.001);
//	g2d1->GetXaxis()->SetTitle("trigger efficiency");
//	g2d1->GetXaxis()->SetTitleOffset(1.5);
//	g2d1->GetYaxis()->SetTitle("trigger rate [MHz]");
//	g2d1->GetZaxis()->SetTitle("p_{T} [GeV/c]");
//	g2d1->GetZaxis()->SetTitleOffset(1.3);
//	g2d1->GetXaxis()->SetTitleSize(0.04);
//	g2d1->GetYaxis()->SetTitleSize(0.04);
//	g2d1->GetZaxis()->SetTitleSize(0.04);
//	gPad->SetRightMargin(0.15);
//	gPad->SetLeftMargin(0.125);
//	//gPad->BuildLegend(x1, y1, x2, y2, "2^{nd} leading p_{t}", "PL"); // ROOT 6
//	J1->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	TLegend *l_1___ = new TLegend(x1, y1, x2, y2, "");
//	l_1___->SetBorderSize(0);
//	l_1___->SetFillColor(kWhite);
//	l_1___->SetTextSize(0.04);
//	l_1___->AddEntry(g2d_1,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 1.5mm","p");
//	l_1___->AddEntry(g2d1,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 7.5 mm", "p");
//	l_1___->AddEntry(gb2d1,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
//	l_1___->AddEntry(gb_2d1_,"#kern[-3.0]{ } emulated calo-jet","p");
//	l_1___->SetTextAlign(12);
//	l_1___->SetMargin(0.15);
//	l_1___->Draw();
//	gPad->Modified();
//	gPad->Update();
//	//gPad->Write("c6a");
//	//gPad->GetView()->TopView();
//	C->Print(out_file_,"pdf");
//	C->SaveAs("./summary_plots/tex/C21_30mm_7515mm_2trk.tex");
//	//! page22
//	C->cd(2);
//	g2d2->SetHistogram(h2d2);
//	g2d_2->SetHistogram(h2d_2);
//	//gPad->SetFillStyle(4000);
//	g2d2->Draw("PCOLZ ERR");
//	g2d_2->Draw("PCOL ERR same");
//	gb2d2->Draw("PCOL ERR same");
//	gb_2d2_->Draw("PCOL ERR same");
//	gPad->SetTheta(90.0);
//	gPad->SetPhi(0.001);
//	g2d2->GetXaxis()->SetTitle("trigger efficiency");
//	g2d2->GetXaxis()->SetTitleOffset(1.5);
//	g2d2->GetYaxis()->SetTitle("trigger rate [MHz]");
//	g2d2->GetZaxis()->SetTitle("p_{T} [GeV/c]");
//	g2d2->GetZaxis()->SetTitleOffset(1.3);
//	g2d2->GetXaxis()->SetTitleSize(0.04);
//	g2d2->GetYaxis()->SetTitleSize(0.04);
//	g2d2->GetZaxis()->SetTitleSize(0.04);
//	gPad->SetRightMargin(0.15);
//	gPad->SetLeftMargin(0.125);
//	gPad->SetLogy();
//	//gPad->BuildLegend(x1, y1, x2, y2, "3^{rd} leading p_{t}", "PL"); // ROOT 6
//	//l_2__->Draw();
//	l_1___->Draw();
//	J2->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	gPad->Modified();
//	gPad->Update();
//	//gPad->Write("c6b");
//	C->Print(out_file_,"pdf");
//	C->SaveAs("./summary_plots/tex/C22_30mm_7515mm_2trk.tex");
//	//! page23
//	C->cd(3);
//	gPad->SetLogy();
//	g2d3->SetHistogram(h2d3);
//	g2d_3->SetHistogram(h2d_3);
//	//gPad->SetFillStyle(4000);
//	g2d3->Draw("PCOLZ ERR");
//	g2d_3->Draw("PCOL ERR same");
//	gb2d3->Draw("PCOL ERR same");
//	gb_2d3_->Draw("PCOL ERR same");
//	gPad->SetTheta(90.0);
//	gPad->SetPhi(0.001);
//	//fun2->Draw("same");
//	g2d3->GetXaxis()->SetTitle("trigger efficiency");
//	g2d3->GetXaxis()->SetTitleOffset(1.5);
//	g2d3->GetYaxis()->SetTitle("trigger rate [MHz]");
//	g2d3->GetZaxis()->SetTitle("p_{T} [GeV/c]");
//	g2d3->GetZaxis()->SetTitleOffset(1.3);
//	g2d3->GetXaxis()->SetTitleSize(0.04);
//	g2d3->GetYaxis()->SetTitleSize(0.04);
//	g2d3->GetZaxis()->SetTitleSize(0.04);
//	gPad->SetRightMargin(0.15);
//	gPad->SetLeftMargin(0.125);
//	//gPad->BuildLegend(x1, y1, x2, y2, "4^{th} leading p_{t}", "PL"); // ROOT 6
//	//l_3__->Draw();
//	l_1___->Draw();
//	J3->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	gPad->Modified();
//	gPad->Update();
//	//gPad->Write("c6c");
//	C->Print(out_file_,"pdf");
//	C->SaveAs("./summary_plots/tex/C23_30mm_7515mm_2trk.tex");
//
//	//! page24
//	C->cd(4);
//	TPad *mypad1 = new TPad("mypad1","mypad1",0,0,1,1);
//	mypad1->SetLogy();
//	g2d4->SetHistogram(h2d4);
//	g2d_4->SetHistogram(h2d_4);
//	//mypad1->SetFillStyle(4000);
//	g2d4->GetXaxis()->SetTitle("trigger efficiency");
//	g2d4->GetXaxis()->SetTitleOffset(1.5);
//	g2d4->GetYaxis()->SetTitle("trigger rate [MHz]");
//	g2d4->GetZaxis()->SetTitle("p_{T} [GeV/c]");
//	g2d4->GetZaxis()->SetTitleOffset(1.3);
//	g2d4->GetXaxis()->SetTitleSize(0.04);
//	g2d4->GetYaxis()->SetTitleSize(0.04);
//	g2d4->GetZaxis()->SetTitleSize(0.04);
//	g2d4->Draw("PCOLZ ERR");
//	g2d_4->Draw("PCOL ERR same");
//	gb2d4->Draw("PCOL ERR same");
//	gb_2d4_->Draw("PCOL ERR same");
//	mypad1->SetTheta(90.0);
//	mypad1->SetPhi(0.001);
//	//fun1->Draw("same");
//	mypad1->SetRightMargin(0.15);
//	mypad1->SetLeftMargin(0.125);
//	//mypad1->BuildLegend(x1, y1, x2, y2, "5^{th} leading p_{t}", "PL"); // ROOT 6
//	//l_4__->Draw();
//	std::cout<<"X1, X2: " <<mypad1->GetX1() <<", " <<mypad1->GetX2() <<std::endl;
//	std::cout<<"Y1, Y2: " <<mypad1->GetY1() <<", " <<mypad1->GetY2() <<std::endl;
//	l_1___->Draw();
//	J4->Draw();
//	leg1->Draw();
//	leg5->Draw();
//	mypad1->Modified();
//	mypad1->Update();
//	//mypad1->Draw();
//	//gPad->Write("c6d");
//	C->Print(out_file_, "pdf");
//	C->SaveAs("./summary_plots/pdf/c6.C");
//	C->SaveAs("./summary_plots/tex/C24_30mm_7515mm_2trk.tex");
//
//	std::cout<<"X1, X2: " <<gPad->GetX1() <<", " <<gPad->GetX2() <<std::endl;
//	std::cout<<"Y1, Y2: " <<gPad->GetY1() <<", " <<gPad->GetY2() <<std::endl;
//
//	//! page25
//	//C->cd();
//	//TPad *mypad = new TPad("mypad","mypad",gPad->GetX1(),gPad->GetY1(),gPad->GetX2(),gPad->GetY2());
//	TPad *mypad = new TPad("mypad","mypad",0,0,1,1);
//	mypad->SetFillStyle(0);
//	//fun->GetYaxis()->SetRangeUser(Ymin_range,Ymax_range);
//	h2d4->Draw();
//	fun->Draw("same");
//	mypad->SetLogy();
//	mypad->DrawClone();
//	C->Print(out_file_, "pdf");
//	C->SaveAs("./summary_plots/tex/C24a_30mm_7515mm_2trk.tex");
//
//	//! page26
//	C->Clear();
//	gPad->SetRightMargin(0.07);
//	gPad->SetLeftMargin(0.1);
//	//! page7	
//	C->cd(1);
//	g1->Draw("APe1");
//	g2->Draw("Pe1");
//	g3->Draw("Pe1");
//	g4->Draw("Pe1");
//	gPad->BuildLegend(x1, y1, x2, y2, "sum p_{t}", "PL"); // ROOT 6
//	gPad->Modified();
//	gPad->Update();
//	//gPad->Write("c7a");
//	C->Print(out_file_,"pdf");
//
//	//! page27
//	C->cd(2);
//	ga1->Draw("APe1");
//	ga2->Draw("Pe1");
//	ga3->Draw("Pe1");
//	ga4->Draw("Pe1");
//	gPad->BuildLegend(x1, y1, x2, y2, "max p_{t}", "PL"); // ROOT 6
//	gPad->Modified();
//	gPad->Update();
//	//gPad->Write("c7b");
//	C->Print(out_file_,"pdf");
//
//	//! page28
//	C->cd(3);
//	gb1->Draw("AP");
//	gb2->Draw("P");
//	gb3->Draw("P");
//	gb4->Draw("P");
//	gPad->BuildLegend(x1, y1, x2, y2, "no z binning", "PL"); // ROOT 6
//	gPad->Modified();
//	gPad->Update();
//	//gPad->Write("c7c");
//	C->Print(out_file_,"pdf");
//	
//	//! page29
//	C->cd(4);
//	gb_1_->Draw("APe1");
//	gb_2_->Draw("Pe1");
//	gb_3_->Draw("Pe1");
//	gb_4_->Draw("Pe1");
//	//gPad->BuildLegend(x1, y1, x2, y2, "emulated calo-jets", "PL"); // ROOT 6
//	x1 = 0.65, y1 = 0.11, x2 = 0.91, y2 = 0.4;
//	TLegend *emu = new TLegend(x1, y1, x2, y2, "");
//	emu->SetBorderSize(0);
//	emu->SetFillColor(kWhite);
//	emu->SetTextSize(0.04);
//	emu->SetHeader("Emu. calo-jet","C");
//	emu->AddEntry(gb_1_,"#kern[-1.0]{ } 2^{nd} leading","p");
//	emu->AddEntry(gb_2_,"#kern[-1.0]{ } 3^{rd} leading", "p");
//	emu->AddEntry(gb_3_,"#kern[-1.0]{ } 4^{th} leading","p");
//	emu->AddEntry(gb_4_,"#kern[-1.0]{ } 5^{th} leading","p");
//	emu->SetTextAlign(12);
//	emu->SetMargin(0.15);
//	emu->Draw();
//
//	gPad->Modified();
//	gPad->Update();
//	//gPad->Write("c7d");
//	C->Print(out_file_, "pdf");
//	C->SaveAs("./summary_plots/tex/C29_30mm_7515mm_calo.tex");
//	
/////////////////////////////////////////////////////
/////////////from a different vertex bin ///////////
////////////////////////////////////////////////////
//	C->Clear();
///////////////////////////////////////////////////////////////////////
///////////////// graphs from 2 different bins together ///////////////
///////////////////////////////////////////////////////////////////////
//	//! page30
//	//! page8
//	g1->Draw("APe1");
//	g1->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
//	g2->Draw("Pe1");
//	g3->Draw("Pe1");
//	g4->Draw("Pe1");
//	g1_->Draw("Pe1");
//	g1_->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
//	g2_->Draw("Pe1");
//	g3_->Draw("Pe1");
//	g4_->Draw("Pe1");
//	C->Print(out_file_, "pdf");
//	
//	//! page31
//	//! page9
//	ga1->Draw("APe1");
//	ga1->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
//	ga2->Draw("Pe1");
//	ga3->Draw("Pe1");
//	ga4->Draw("Pe1");
//	ga1_->Draw("Pe1");
//	ga1_->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
//	ga2_->Draw("Pe1");
//	ga3_->Draw("Pe1");
//	ga4_->Draw("Pe1");
//	C->Print(out_file_, "pdf");
//
//	//! page32
//	//! page10
//	gb1->Draw("APe1");
//	gb1->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
//	gb2->Draw("Pe1");
//	gb3->Draw("Pe1");
//	gb4->Draw("Pe1");
//	gb_1_->Draw("Pe1");
//	gb_1_->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
//	gb_2_->Draw("Pe1");
//	gb_3_->Draw("Pe1");
//	gb_4_->Draw("Pe1");
//	C->Print(out_file_, "pdf");
//	C->SetLogy(0);
//	
//	//! page33
//	//! page11
//	C->SetLogx();
//	Eb2->SetTitle("sum-pt,+-7.5mm binning ");
//	Eb2->GetXaxis()->SetTitle("p_{T} [GeV/c]");
//	Eb2->GetYaxis()->SetTitle("trigger efficiency");
//	Eb2->GetXaxis()->CenterTitle();
//	Eb2->GetYaxis()->CenterTitle();
//	Eb2->GetXaxis()->SetTitleSize(0.04);
//	Eb2->GetYaxis()->SetTitleSize(0.04);
//	Eb2->GetXaxis()->SetRangeUser(2.0,0.9e3);
//	Eb2->Draw("hist ");
//	Eb3->Draw("hist same");
//	Eb4->Draw("hist same");
//	Eb5->Draw("hist same");
//	E2->Draw("hist same");
//	E3->Draw("hist same");
//	E4->Draw("hist same");
//	E5->Draw("hist same");
//	Ebcalo2->Draw("hist same");
//	Ebcalo3->Draw("hist same");
//	Ebcalo4->Draw("hist same");
//	Ebcalo5->Draw("hist same");
//	leg1->Draw();
//	leg5->Draw();
//	C->Print(out_file_, "pdf");
//	//gPad->Write("c11");
//	C->SaveAs("./summary_plots/tex/C32_30mm_7515mm_2trk.tex");
//	C->SaveAs("./summary_plots/C/C32_30mm_7515mm_2trk.C");
//	
//	//! page34
//	//! page12
//	Eb_2->SetTitle("sum-pt,+-1.5mm binning ");
//	Eb_2->GetXaxis()->SetTitle("p_{T} [GeV/c]");
//	Eb_2->GetYaxis()->SetTitle("trigger efficiency");
//	Eb_2->GetXaxis()->CenterTitle();
//	Eb_2->GetYaxis()->CenterTitle();	
//	Eb_2->GetXaxis()->SetTitleSize(0.04);
//	Eb_2->GetYaxis()->SetTitleSize(0.04);
//	Eb_2->GetXaxis()->SetRangeUser(2.0, 0.9e3);
//	Eb_2->Draw("hist ");
//	Eb_3->Draw("hist same");
//	Eb_4->Draw("hist same");
//	Eb_5->Draw("hist same");
//	E2_->Draw("hist same");
//	E3_->Draw("hist same");
//	E4_->Draw("hist same");
//	E5_->Draw("hist same");
//	Ebcalo2->Draw("hist same");
//	Ebcalo3->Draw("hist same");
//	Ebcalo4->Draw("hist same");
//	Ebcalo5->Draw("hist same");
//	leg1->Draw();
//	leg5->Draw();
//	C->Print(out_file_, "pdf");
//	//gPad->Write("c12");
//	C->SaveAs("./summary_plots/tex/C33_30mm_7515mm_2trk.tex");
//	C->SaveAs("./summary_plots/C/C33_30mm_7515mm_2trk.C");
//
//	//! page35
//	//! page13
//	Eb2->SetTitle("max pt TJ from each bin,+-7.5mm binning ");	
//	Eb2->Draw("hist ");
//	Eb3->Draw("hist same");
//	Eb4->Draw("hist same");
//	Eb5->Draw("hist same");
//	Ea2->Draw("hist same");
//	Ea3->Draw("hist same");
//	Ea4->Draw("hist same");
//	Ea5->Draw("hist same");
//	Ebcalo2->Draw("hist same");
//	Ebcalo3->Draw("hist same");
//	Ebcalo4->Draw("hist same");
//	Ebcalo5->Draw("hist same");
//	leg1->Draw();
//	leg5->Draw();
//	C->Print(out_file_, "pdf");
//	//gPad->Write("c13");
//	C->SaveAs("./summary_plots/tex/C34_30mm_7515mm_2trk.tex");
//	C->SaveAs("./summary_plots/C/C34_30mm_7515mm_2trk.C");
//
//	//! page36
//	//! page14
//	Eb_2->SetTitle("max pt TJ from each bin,+-1.5mm binning ");	
//	Eb_2->Draw("hist ");
//	Eb_3->Draw("hist same");
//	Eb_4->Draw("hist same");
//	Eb_5->Draw("hist same");
//	Ea_2->Draw("hist same");
//	Ea_3->Draw("hist same");
//	Ea_4->Draw("hist same");
//	Ea_5->Draw("hist same");
//	Ebcalo2->Draw("hist same");
//	Ebcalo3->Draw("hist same");
//	Ebcalo4->Draw("hist same");
//	Ebcalo5->Draw("hist same");
//	leg1->Draw();
//	leg5->Draw();
//	C->Print(out_file_, "pdf");
//	//gPad->Write("c14");
//	C->SaveAs("./summary_plots/tex/C35_30mm_7515mm_2trk.tex");
//	C->SaveAs("./summary_plots/C/C35_30mm_7515mm_2trk.C");
//
//	//! page37
//	//! page15
//	C->SetLogy();
//	Rb2->SetTitle("sum-pt,+-7.5mm binning ");	
//	Rb2->GetXaxis()->SetTitle("p_{T} [GeV/c]");
//	Rb2->GetYaxis()->SetTitle("trigger rate [MHz]");
//	Rb2->GetXaxis()->CenterTitle();
//	Rb2->GetYaxis()->CenterTitle();
//	Rb2->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
//	Rb2->GetXaxis()->SetRangeUser(2.0, 0.9e3);
//	Rb2->GetXaxis()->SetTitleSize(0.04);
//	Rb2->GetYaxis()->SetTitleSize(0.04);
//	Rb2->GetYaxis()->SetTitleOffset(1.2);
//	Rb2->Draw("hist ");
//	Rb3->Draw("hist same");
//	Rb4->Draw("hist same");
//	Rb5->Draw("hist same");
//	R2->Draw("hist same");
//	R3->Draw("hist same");
//	R4->Draw("hist same");
//	R5->Draw("hist same");
//	Rbcalo2->Draw("hist same");
//	Rbcalo3->Draw("hist same");
//	Rbcalo4->Draw("hist same");
//	Rbcalo5->Draw("hist same");
//	leg1->Draw();
//	leg5->Draw();
//	C->Print(out_file_, "pdf");
//	C->SaveAs("./summary_plots/tex/C36_30mm_7515mm_2trk.tex");
//	C->SaveAs("./summary_plots/C/C36_30mm_7515mm_2trk.C");
//	//gPad->Write("c15");
//	
//	//! page38
//	//! page16
//	Rb_2->SetTitle("sum-pt,+-1.5mm binning ");
//	Rb_2->GetXaxis()->SetTitle("p_{T} [GeV/c]");
//	Rb_2->GetYaxis()->SetTitle("trigger rate [MHz]");
//	Rb_2->GetXaxis()->CenterTitle();
//	Rb_2->GetYaxis()->CenterTitle();	
//	Rb_2->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
//	Rb_2->GetXaxis()->SetRangeUser(2.0, 0.9e3);
//	////Rb_2->GetXaxis()->SetRangeUser(0, 0.07e3);
//	Rb_2->GetXaxis()->SetTitleSize(0.04);
//	Rb_2->GetYaxis()->SetTitleSize(0.04);
//	Rb_2->GetYaxis()->SetTitleOffset(1.2);
//	Rb_2->Draw("hist ");
//	Rb_3->Draw("hist same");
//	Rb_4->Draw("hist same");
//	Rb_5->Draw("hist same");
//	R2_->Draw("hist same");
//	R3_->Draw("hist same");
//	R4_->Draw("hist same");
//	R5_->Draw("hist same");
//	Rbcalo2->Draw("hist same");
//	Rbcalo3->Draw("hist same");
//	Rbcalo4->Draw("hist same");
//	Rbcalo5->Draw("hist same");
//	leg1->Draw();
//	leg5->Draw();
//	C->Print(out_file_, "pdf");
//	C->SaveAs("./summary_plots/tex/C37_30mm_7515mm_2trk.tex");
//	C->SaveAs("./summary_plots/C/C37_30mm_7515mm_2trk.C");
//	//gPad->Write("c16");
//
//	//! page39
//	//! page17
//	Rb2->SetTitle("max pt TJ from each bin,+-7.5mm binning ");	
//	Rb2->Draw("hist ");
//	Rb3->Draw("hist same");
//	Rb4->Draw("hist same");
//	Rb5->Draw("hist same");
//	Ra2->Draw("hist same");
//	Ra3->Draw("hist same");
//	Ra4->Draw("hist same");
//	Ra5->Draw("hist same");
//	Rbcalo2->Draw("hist same");
//	Rbcalo3->Draw("hist same");
//	Rbcalo4->Draw("hist same");
//	Rbcalo5->Draw("hist same");
//	leg1->Draw();
//	leg5->Draw();
//	C->Print(out_file_, "pdf");
//	C->SaveAs("./summary_plots/tex/C38_30mm_7515mm_2trk.tex");
//	C->SaveAs("./summary_plots/C/C38_30mm_7515mm_2trk.C");
//	//gPad->Write("c17");
//
//	//! page40
//	//! pagr18
//	Rb_2->SetTitle("max pt TJ from each bin,+-1.5mm binning ");	
//	Rb_2->Draw("hist ");
//	Rb_3->Draw("hist same");
//	Rb_4->Draw("hist same");
//	Rb_5->Draw("hist same");
//	Ra_2->Draw("hist same");
//	Ra_3->Draw("hist same");
//	Ra_4->Draw("hist same");
//	Ra_5->Draw("hist same");
//	Rbcalo2->Draw("hist same");
//	Rbcalo3->Draw("hist same");
//	Rbcalo4->Draw("hist same");
//	Rbcalo5->Draw("hist same");
//	leg1->Draw();
//	leg5->Draw();
//	C->Print(out_file_close,"pdf");
//	C->SaveAs("./summary_plots/tex/C39_30mm_7515mm_2trk.tex");
//	C->SaveAs("./summary_plots/C/C39_30mm_7515mm_2trk.C");
//	//gPad->Write("c18");

	//f_out->Close();
	return;
}
