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
const char* out_path = "./summary_plots/pdf"; 
const char* output_file_name = "withfakes100GeV2_7.5_3.75_1";
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
	bool debug = true;
	const int n = 20;
	Int_t nbinsE, nbinsR;
	Int_t nbinsEa, nbinsRa;
	Int_t nbinsEb, nbinsRb;
	Float_t Xmin_range = 0.0, Xmax_range = 1.2;
	Float_t Ymin_range = 1e-1, Ymax_range = 50.0;
	Float_t e2[n] = {0};   Float_t r2[n] = {0};
	Float_t e3[n] = {0};   Float_t r3[n] = {0};
	Float_t e4[n] = {0};   Float_t r4[n] = {0};
	Float_t e5[n] = {0};   Float_t r5[n] = {0};
	Float_t ea2[n] = {0};   Float_t ra2[n] = {0};
	Float_t ea3[n] = {0};   Float_t ra3[n] = {0};
	Float_t ea4[n] = {0};   Float_t ra4[n] = {0};
	Float_t ea5[n] = {0};   Float_t ra5[n] = {0};
	Float_t eb2[n] = {0};   Float_t rb2[n] = {0};
	Float_t eb3[n] = {0};   Float_t rb3[n] = {0};
	Float_t eb4[n] = {0};   Float_t rb4[n] = {0};
	Float_t eb5[n] = {0};   Float_t rb5[n] = {0};
	/////////////////////////////////////////////////
	//! Fetch the histograms
	////////////////////////////////////////////////
	const char *file_path = ".";
	char signal_file_name[1023];
	//sprintf(signal_file_name, "%s/jetoutPU%shh4b_%smm_optsig5.root",file_path,pileup,gapsize);
	sprintf(signal_file_name, "%s/jetoutPU%shh4b_%smm_optsig5_2tracks7.5_.root",file_path,pileup,gapsize);//7.5
	//sprintf(signal_file_name, "%s/jetoutPU%shh4b_%smm_optsig5_nofake3tracks3.75.root",file_path,pileup,gapsize);
	//sprintf(signal_file_name, "%s/jetoutPU%shh4b_%smm_optsig5_nofake3tracks3.0.root",file_path,pileup,gapsize);
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
	//sprintf(MinBias_file_name, "%s/jetoutPU%sMB_%smm_optsig5.root",file_path,pileup,gapsize);
	sprintf(MinBias_file_name, "%s/jetoutPU%sMB_%smm_optsig5_2tracks7.5_.root",file_path,pileup,gapsize);//7.5
	//sprintf(MinBias_file_name, "%s/jetoutPU%sMB_%smm_optsig5_nofake3tracks3.75.root",file_path,pileup,gapsize);
	//sprintf(MinBias_file_name, "%s/jetoutPU%sMB_%smm_optsig5_nofake3tracks3.0.root",file_path,pileup,gapsize);
	TFile *f1 = new TFile(MinBias_file_name, "READ");
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
        sprintf(txt_file,"%s/summary_trackJetROC_PU%s_%smm_nofaketracks7.5.txt",txt_path, pileup,gapsize);
        std::ofstream ofs;
        ofs.open (txt_file, std::ofstream::out | std::ofstream::app);
	//for(int i = 1; i < nbinsE + 1; i++)
	for(int i = 1; i < n + 1; i++)
	{
        	ofs<<E2->GetBinLowEdge(i)<<" "<<E2->GetBinContent(i)<<" " <<R2->GetBinContent(i)<<" "<<E3->GetBinContent(i)<<" "<<R3->GetBinContent(i)<<" "<<E4->GetBinContent(i)<<" "<<R4->GetBinContent(i)<<" "<<E5->GetBinContent(i)<<" "<<R5->GetBinContent(i)<<"\n";

		//std::cout<<"i" << i <<std::endl;
		//! Fill into arrays and plot graph
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
	}
        ofs.close();

	TCanvas *c1 = new TCanvas();
	TGraphErrors *g1 = new TGraphErrors(n,e2,r2,0,0);
	g1->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	g1->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	g1->GetYaxis()->SetTitleOffset(1.2);
	g1->GetYaxis()->SetTitle("trigger rate [MHz]");
	g1->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g1->SetMarkerStyle(22);//kFullCircle);
	g1->SetMarkerColor(kBlack);
	g1->SetLineColor(kBlack);
	g1->SetMarkerSize(1.9);
	//c1->cd(4);
	g1->SetFillStyle(0);
	g1->SetTitle("2^{nd} ");
	//g1->Draw("ACPe1");
	g1->Draw("APe1");

	TGraphErrors *g2 = new TGraphErrors(n,e3,r3,0,0);
	g2->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	g2->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	g2->GetYaxis()->SetTitleOffset(1.2);
	g2->GetYaxis()->SetTitle("trigger rate [MHz]");
	g2->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g2->SetMarkerStyle(22);//kFullTriangleUp);
	g2->SetMarkerColor(kRed);
	g2->SetLineColor(kRed);
	g2->SetMarkerSize(1.9);
	//c1->cd(4);
	g2->SetFillStyle(0);
	g2->SetTitle("3^{rd} ");
	//g2->Draw("CPe1");
	g2->Draw("Pe1");

	TGraphErrors *g3 = new TGraphErrors(n,e4,r4,0,0);
	g3->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	g3->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	g3->GetYaxis()->SetTitleOffset(1.2);
	g3->GetYaxis()->SetTitle("trigger rate [MHz]");
	g3->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g3->SetMarkerStyle(22);//k);
	g3->SetMarkerColor(kGreen);
	g3->SetLineColor(kGreen);
	g3->SetMarkerSize(1.9);
	//c1->cd(4);
	g3->SetFillStyle(0);
	g3->SetTitle("4^{th} ");
	//g3->Draw("CPe1");
	g3->Draw("Pe1");

	TGraphErrors *g4 = new TGraphErrors(n,e5,r5,0,0);
	g4->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	g4->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	g4->GetYaxis()->SetTitleOffset(1.2);
	g4->GetYaxis()->SetTitle("trigger rate [MHz]");
	g4->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g4->SetMarkerStyle(22);//kFullStar);
	g4->SetMarkerColor(kBlue);
	g4->SetLineColor(kBlue);
	g4->SetMarkerSize(1.9);
	//c1->cd(4);
	g4->SetFillStyle(0);
	g4->SetTitle("5^{th} ");
	//g4->Draw("CPe1");
	g4->Draw("Pe1");

	TGraphErrors *ga1 = new TGraphErrors(n,ea2,ra2,0,0);
	ga1->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	ga1->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	ga1->GetYaxis()->SetTitleOffset(1.2);
	ga1->GetYaxis()->SetTitle("trigger rate [MHz]");
	ga1->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga1->SetMarkerStyle(22);//kFullCircle);
	ga1->SetMarkerColor(kBlack);
	ga1->SetLineColor(kBlack);
	ga1->SetMarkerSize(1.9);
	//c1->cd(4);
	ga1->SetFillStyle(0);
	ga1->SetTitle("2^{nd} a");
	//g1->Draw("ACPe1");
	ga1->Draw("APe1");

	TGraphErrors *ga2 = new TGraphErrors(n,ea3,ra3,0,0);
	ga2->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	ga2->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	ga2->GetYaxis()->SetTitleOffset(1.2);
	ga2->GetYaxis()->SetTitle("trigger rate [MHz]");
	ga2->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga2->SetMarkerStyle(22);//kFullTriangleUp);
	ga2->SetMarkerColor(kRed);
	ga2->SetLineColor(kRed);
	ga2->SetMarkerSize(1.9);
	//c1->cd(4);
	ga2->SetFillStyle(0);
	ga2->SetTitle("3^{rd} a");
	//ga2->Draw("CPe1");
	ga2->Draw("Pe1");

	TGraphErrors *ga3 = new TGraphErrors(n,ea4,ra4,0,0);
	ga3->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	ga3->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	ga3->GetYaxis()->SetTitleOffset(1.2);
	ga3->GetYaxis()->SetTitle("trigger rate [MHz]");
	ga3->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga3->SetMarkerStyle(22);//k);
	ga3->SetMarkerColor(kGreen);
	ga3->SetLineColor(kGreen);
	ga3->SetMarkerSize(1.9);
	//c1->cd(4);
	ga3->SetFillStyle(0);
	ga3->SetTitle("4^{th} a");
	//ga3->Draw("CPe1");
	ga3->Draw("Pe1");

	TGraphErrors *ga4 = new TGraphErrors(n,ea5,ra5,0,0);
	ga4->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	ga4->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	ga4->GetYaxis()->SetTitleOffset(1.2);
	ga4->GetYaxis()->SetTitle("trigger rate [MHz]");
	ga4->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga4->SetMarkerStyle(22);//kFullStar);
	ga4->SetMarkerColor(kBlue);
	ga4->SetLineColor(kBlue);
	ga4->SetMarkerSize(1.9);
	//c1->cd(4);
	ga4->SetFillStyle(0);
	ga4->SetTitle("5^{th} a");
	//ga4->Draw("CPe1");
	ga4->Draw("Pe1");

	TGraphErrors *gb1 = new TGraphErrors(n,eb2,rb2,0,0);
	gb1->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	gb1->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	gb1->GetYaxis()->SetTitleOffset(1.2);
	gb1->GetYaxis()->SetTitle("trigger rate [MHz]");
	gb1->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb1->SetMarkerStyle(kFullCircle);//kFullCircle);
	gb1->SetMarkerColor(kBlack);
	gb1->SetLineColor(kBlack);
	gb1->SetMarkerSize(1.9);
	//c1->cd(4);
	gb1->SetFillStyle(0);
	gb1->SetTitle("2^{nd} b");
	//gb1->Draw("ACPe1");
	gb1->Draw("APe1");

	TGraphErrors *gb2 = new TGraphErrors(n,eb3,rb3,0,0);
	gb2->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	gb2->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	gb2->GetYaxis()->SetTitleOffset(1.2);
	gb2->GetYaxis()->SetTitle("trigger rate [MHz]");
	gb2->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb2->SetMarkerStyle(kFullCircle);//kFullTriangleUp);
	gb2->SetMarkerColor(kRed);
	gb2->SetLineColor(kRed);
	gb2->SetMarkerSize(1.9);
	//c1->cd(4);
	gb2->SetFillStyle(0);
	gb2->SetTitle("3^{rd} b");
	//gb2->Draw("CPe1");
	gb2->Draw("Pe1");

	TGraphErrors *gb3 = new TGraphErrors(n,eb4,rb4,0,0);
	gb3->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	gb3->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	gb3->GetYaxis()->SetTitleOffset(1.2);
	gb3->GetYaxis()->SetTitle("trigger rate [MHz]");
	gb3->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb3->SetMarkerStyle(kFullCircle);//k);
	gb3->SetMarkerColor(kGreen);
	gb3->SetLineColor(kGreen);
	gb3->SetMarkerSize(1.9);
	//c1->cd(4);
	gb3->SetFillStyle(0);
	gb3->SetTitle("4^{th} b");
	//gb3->Draw("CPe1");
	gb3->Draw("Pe1");

	TGraphErrors *gb4 = new TGraphErrors(n,eb5,rb5,0,0);
	gb4->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	gb4->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	gb4->GetYaxis()->SetTitleOffset(1.2);
	gb4->GetYaxis()->SetTitle("trigger rate [MHz]");
	gb4->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb4->SetMarkerStyle(kFullCircle);//kFullStar);
	gb4->SetMarkerColor(kBlue);
	gb4->SetLineColor(kBlue);
	gb4->SetMarkerSize(1.9);
	//c1->cd(4);
	gb4->SetFillStyle(0);
	gb4->SetTitle("5^{th} b");
	//gb4->Draw("CPe1");
	gb4->Draw("Pe1");
//////////////////////////////////////////////////////////////
/////////////// for a different z vertex bin  ////////////////
//////////////////////////////////////////////////////////////

	Float_t e2_[n] = {0};    Float_t r2_[n] = {0};
	Float_t e3_[n] = {0};    Float_t r3_[n] = {0};
	Float_t e4_[n] = {0};    Float_t r4_[n] = {0};
	Float_t e5_[n] = {0};    Float_t r5_[n] = {0};
	Float_t ea_2[n] = {0};   Float_t ra_2[n] = {0};
	Float_t ea_3[n] = {0};   Float_t ra_3[n] = {0};
	Float_t ea_4[n] = {0};   Float_t ra_4[n] = {0};
	Float_t ea_5[n] = {0};   Float_t ra_5[n] = {0};
	Float_t eb_2[n] = {0};   Float_t rb_2[n] = {0};
	Float_t eb_3[n] = {0};   Float_t rb_3[n] = {0};
	Float_t eb_4[n] = {0};   Float_t rb_4[n] = {0};
	Float_t eb_5[n] = {0};   Float_t rb_5[n] = {0};
	/////////////////////////////////////////////////
	//! Fetch the histograms
	////////////////////////////////////////////////
	char signal_file_name_1[1023];
	sprintf(signal_file_name_1, "%s/jetoutPU%shh4b_%smm_optsig5_2tracks3.75_.root",file_path,pileup,gapsize);
	//sprintf(signal_file_name_1, "%s/jetoutPU%shh4b_%smm_optsig5_nofake3tracks3.0.root",file_path,pileup,gapsize);
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
	sprintf(MinBias_file_name_1, "%s/jetoutPU%sMB_%smm_optsig5_2tracks3.75_.root",file_path,pileup,gapsize);
	//sprintf(MinBias_file_name_1, "%s/jetoutPU%sMB_%smm_optsig5_nofake3tracks3.0.root",file_path,pileup,gapsize);
	TFile *f_1 = new TFile(MinBias_file_name_1, "READ");
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
	}

	TGraphErrors *g1_ = new TGraphErrors(n,e2_,r2_,0,0);
	g1_->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	g1_->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	g1_->GetYaxis()->SetTitleOffset(1.2);
	g1_->GetYaxis()->SetTitle("trigger rate [MHz]");
	g1_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g1_->SetMarkerStyle(kOpenTriangleUp);//kFullCircle);
	g1_->SetMarkerColor(kBlack);
	g1_->SetLineColor(kBlack);
	g1_->SetMarkerSize(1.9);
	//c1->cd(4);
	g1_->SetFillStyle(0);
	g1_->SetTitle("2^{nd} ");
	//g1_->Draw("ACPe1");
	g1_->Draw("APe1");

	TGraphErrors *g2_ = new TGraphErrors(n,e3_,r3_,0,0);
	g2_->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	g2_->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	g2_->GetYaxis()->SetTitleOffset(1.2);
	g2_->GetYaxis()->SetTitle("trigger rate [MHz]");
	g2_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g2_->SetMarkerStyle(kOpenTriangleUp);//kFullTriangleUp);
	g2_->SetMarkerColor(kRed);
	g2_->SetLineColor(kRed);
	g2_->SetMarkerSize(1.9);
	//c1->cd(4);
	g2_->SetFillStyle(0);
	g2_->SetTitle("3^{rd} ");
	//g2_->Draw("CPe1");
	g2_->Draw("Pe1");

	TGraphErrors *g3_ = new TGraphErrors(n,e4_,r4_,0,0);
	g3_->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	g3_->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	g3_->GetYaxis()->SetTitleOffset(1.2);
	g3_->GetYaxis()->SetTitle("trigger rate [MHz]");
	g3_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g3_->SetMarkerStyle(kOpenTriangleUp);//k);
	g3_->SetMarkerColor(kGreen);
	g3_->SetLineColor(kGreen);
	g3_->SetMarkerSize(1.9);
	//c1->cd(4);
	g3_->SetFillStyle(0);
	g3_->SetTitle("4^{th} ");
	//g3_->Draw("CPe1");
	g3_->Draw("Pe1");

	TGraphErrors *g4_ = new TGraphErrors(n,e5_,r5_,0,0);
	g4_->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	g4_->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	g4_->GetYaxis()->SetTitleOffset(1.2);
	g4_->GetYaxis()->SetTitle("trigger rate [MHz]");
	g4_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g4_->SetMarkerStyle(kOpenTriangleUp);//kFullStar);
	g4_->SetMarkerColor(kBlue);
	g4_->SetLineColor(kBlue);
	g4_->SetMarkerSize(1.9);
	//c1->cd(4);
	g4_->SetFillStyle(0);
	g4_->SetTitle("5^{th} ");
	//g4_->Draw("CPe1");
	g4_->Draw("Pe1");

	TGraphErrors *ga1_ = new TGraphErrors(n,ea_2,ra_2,0,0);
	ga1_->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	ga1_->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	ga1_->GetYaxis()->SetTitleOffset(1.2);
	ga1_->GetYaxis()->SetTitle("trigger rate [MHz]");
	ga1_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga1_->SetMarkerStyle(kOpenTriangleUp);//kFullCircle);
	ga1_->SetMarkerColor(kBlack);
	ga1_->SetLineColor(kBlack);
	ga1_->SetMarkerSize(1.9);
	//c1->cd(4);
	ga1_->SetFillStyle(0);
	ga1_->SetTitle("2^{nd} a");
	//g1->Draw("ACPe1");
	ga1_->Draw("APe1");

	TGraphErrors *ga2_ = new TGraphErrors(n,ea_3,ra_3,0,0);
	ga2_->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	ga2_->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	ga2_->GetYaxis()->SetTitleOffset(1.2);
	ga2_->GetYaxis()->SetTitle("trigger rate [MHz]");
	ga2_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga2_->SetMarkerStyle(kOpenTriangleUp);//kFullTriangleUp);
	ga2_->SetMarkerColor(kRed);
	ga2_->SetLineColor(kRed);
	ga2_->SetMarkerSize(1.9);
	//c1->cd(4);
	ga2_->SetFillStyle(0);
	ga2_->SetTitle("3^{rd} a");
	//ga2_->Draw("CPe1");
	ga2_->Draw("Pe1");

	TGraphErrors *ga3_ = new TGraphErrors(n,ea_4,ra_4,0,0);
	ga3_->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	ga3_->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	ga3_->GetYaxis()->SetTitleOffset(1.2);
	ga3_->GetYaxis()->SetTitle("trigger rate [MHz]");
	ga3_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga3_->SetMarkerStyle(kOpenTriangleUp);//k);
	ga3_->SetMarkerColor(kGreen);
	ga3_->SetLineColor(kGreen);
	ga3_->SetMarkerSize(1.9);
	//c1->cd(4);
	ga3_->SetFillStyle(0);
	ga3_->SetTitle("4^{th} a");
	//ga3_->Draw("CPe1");
	ga3_->Draw("Pe1");

	TGraphErrors *ga4_ = new TGraphErrors(n,ea_5,ra_5,0,0);
	ga4_->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	ga4_->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	ga4_->GetYaxis()->SetTitleOffset(1.2);
	ga4_->GetYaxis()->SetTitle("trigger rate [MHz]");
	ga4_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga4_->SetMarkerStyle(kOpenTriangleUp);//kFullStar);
	ga4_->SetMarkerColor(kBlue);
	ga4_->SetLineColor(kBlue);
	ga4_->SetMarkerSize(1.9);
	//c1->cd(4);
	ga4_->SetFillStyle(0);
	ga4_->SetTitle("5^{th} a");
	//ga4_->Draw("CPe1");
	ga4_->Draw("Pe1");

	TGraphErrors *gb1_ = new TGraphErrors(n,eb_2,rb_2,0,0);
	gb1_->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	gb1_->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	gb1_->GetYaxis()->SetTitleOffset(1.2);
	gb1_->GetYaxis()->SetTitle("trigger rate [MHz]");
	gb1_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb1_->SetMarkerStyle(kFullCircle);//kFullCircle);
	gb1_->SetMarkerColor(kBlack);
	gb1_->SetLineColor(kBlack);
	gb1_->SetMarkerSize(1.9);
	//c1->cd(4);
	gb1_->SetFillStyle(0);
	gb1_->SetTitle("2^{nd} b");
	//gb1_->Draw("ACPe1");
	gb1_->Draw("APe1");

	TGraphErrors *gb2_ = new TGraphErrors(n,eb_3,rb_3,0,0);
	gb2_->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	gb2_->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	gb2_->GetYaxis()->SetTitleOffset(1.2);
	gb2_->GetYaxis()->SetTitle("trigger rate [MHz]");
	gb2_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb2_->SetMarkerStyle(kFullCircle);//kFullTriangleUp);
	gb2_->SetMarkerColor(kRed);
	gb2_->SetLineColor(kRed);
	gb2_->SetMarkerSize(1.9);
	//c1->cd(4);
	gb2_->SetFillStyle(0);
	gb2_->SetTitle("3^{rd} b");
	//gb2_->Draw("CPe1");
	gb2_->Draw("Pe1");

	TGraphErrors *gb3_ = new TGraphErrors(n,eb_4,rb_4,0,0);
	gb3_->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	gb3_->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	gb3_->GetYaxis()->SetTitleOffset(1.2);
	gb3_->GetYaxis()->SetTitle("trigger rate [MHz]");
	gb3_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb3_->SetMarkerStyle(kFullCircle);//k);
	gb3_->SetMarkerColor(kGreen);
	gb3_->SetLineColor(kGreen);
	gb3_->SetMarkerSize(1.9);
	//c1->cd(4);
	gb3_->SetFillStyle(0);
	gb3_->SetTitle("4^{th} b");
	//gb3_->Draw("CPe1");
	gb3_->Draw("Pe1");

	TGraphErrors *gb4_ = new TGraphErrors(n,eb_5,rb_5,0,0);
	gb4_->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	gb4_->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	gb4_->GetYaxis()->SetTitleOffset(1.2);
	gb4_->GetYaxis()->SetTitle("trigger rate [MHz]");
	gb4_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb4_->SetMarkerStyle(kFullCircle);//kFullStar);
	gb4_->SetMarkerColor(kBlue);
	gb4_->SetLineColor(kBlue);
	gb4_->SetMarkerSize(1.9);
	//c1->cd(4);
	gb4_->SetFillStyle(0);
	gb4_->SetTitle("5^{th} b");
	//gb4_->Draw("CPe1");
	gb4_->Draw("Pe1");
//////////////////////////////////////////////////////////////
////// here starts multi graph ///////////////////////////////
//////////////////////////////////////////////////////////////
	
	Double_t x1= 0.91,y1= 0.12, x2 = 0.99, y2 = 0.3;
	c1->SetGridx();
	c1->SetGridy();
	TMultiGraph *mg = new TMultiGraph();
	mg->Add(g1);
	mg->Add(g2);
	mg->Add(g3);
	mg->Add(g4);
	mg->Draw("AP");
	//g->SetTitle(plot_title);
	mg->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	mg->GetYaxis()->SetTitle("trigger rate [MHz]");
	mg->GetXaxis()->SetTitleSize(0.04);
	mg->GetYaxis()->SetTitleSize(0.04);
	//g->GetXaxis()->SetRangeUser(0,100);
	//g->GetYaxis()->SetTitleOffset(1.5);
	mg->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	c1->BuildLegend(x1,y1,x2,y2,"sum_pt");

	//! draw a second Y axis
	// scale rightmax to pad co-o
	//Float_t rightmax = 1.0*g->GetHistogram()->GetMaximum();
	//std::cout<< "rightmax: " << rightmax << std::endl;
	//std::cout<< "Uxmax: " << gPad->GetUxmax() << std::endl;
	//std::cout<< "Uymin: " << gPad->GetUymin() << std::endl;
	//std::cout<< "Uymax: " << gPad->GetUymax() << std::endl;
	//Float_t scale = 32.0/25.0;
	//TGaxis *A1 = new TGaxis(gPad->GetUxmax(), gPad->GetUymin(), gPad->GetUxmax(), rightmax, 0, Ymax_range*scale, 510, "+");
	//A1->Draw();
	c1->SetLogy();
	c1->Update();
	SaveCanvas(c1,"summary_ROChh4b_atleast3tracks3.0");
/////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//////////////// writing to pdf ///////////////////////////////////////
///////////////////////////////////////////////////////////////////////
	char out_file_open[1023];
        sprintf(out_file_open,"%s/%s.pdf(",out_path,output_file_name);
        char out_file_[1023];
        sprintf(out_file_,"%s/%s.pdf",out_path,output_file_name);
        char out_file_close[1023];
        sprintf(out_file_close,"%s/%s.pdf)",out_path,output_file_name);
	TCanvas * C = new TCanvas();
	//TCanvas * C = new TCanvas("C","C",800,800);
	gStyle->SetOptStat(0);
	//TGaxis::SetMaxDigits(2);
	C->SetGridx();
	C->SetGridy();
	C->SetTickx();
	C->SetTicky();
	C->SetLogy();
	g1->Draw("APe1");
	C->Print(out_file_open,"pdf");
	g2->Draw("APe1");
	C->Print(out_file_, "pdf");
	g3->Draw("APe1");
	C->Print(out_file_, "pdf");
	g4->Draw("APe1");
	C->Print(out_file_, "pdf");
	
	ga1->Draw("AAPe1");
	C->Print(out_file_, "pdf");
	ga2->Draw("APe1");
	C->Print(out_file_, "pdf");
	ga3->Draw("APe1");
	C->Print(out_file_, "pdf");
	ga4->Draw("APe1");
	C->Print(out_file_, "pdf");

	gb1->Draw("APe1");
	C->Print(out_file_, "pdf");
	gb2->Draw("APe1");
	C->Print(out_file_, "pdf");
	gb3->Draw("APe1");
	C->Print(out_file_, "pdf");
	gb4->Draw("APe1");
	C->Print(out_file_, "pdf");
	
	g1->Draw("APe1");
	g1->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	g2->Draw("Pe1");
	g3->Draw("Pe1");
	g4->Draw("Pe1");
	C->Print(out_file_, "pdf");
	
	ga1->Draw("APe1");
	ga1->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	ga2->Draw("Pe1");
	ga3->Draw("Pe1");
	ga4->Draw("Pe1");
	C->Print(out_file_, "pdf");

	gb1->Draw("APe1");
	gb1->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	gb2->Draw("Pe1");
	gb3->Draw("Pe1");
	gb4->Draw("Pe1");
	C->Print(out_file_, "pdf");

	g1->Draw("APe1");
	g2->Draw("Pe1");
	g3->Draw("Pe1");
	g4->Draw("Pe1");
	gb1->Draw("Pe1");
	gb2->Draw("Pe1");
	gb3->Draw("Pe1");
	gb4->Draw("Pe1");

	C->Print(out_file_, "pdf");
	ga1->Draw("APe1");
	ga2->Draw("Pe1");
	ga3->Draw("Pe1");
	ga4->Draw("Pe1");
	gb1->Draw("Pe1");
	gb2->Draw("Pe1");
	gb3->Draw("Pe1");
	gb4->Draw("Pe1");
	C->Print(out_file_, "pdf");

///////////////////////////////////////////////////
///////////from a different vertex bin ///////////
//////////////////////////////////////////////////
	g2_->Draw("APe1");
	C->Print(out_file_, "pdf");
	g3_->Draw("APe1");
	C->Print(out_file_, "pdf");
	g4_->Draw("APe1");
	C->Print(out_file_, "pdf");
	
	ga1_->Draw("AAPe1");
	C->Print(out_file_, "pdf");
	ga2_->Draw("APe1");
	C->Print(out_file_, "pdf");
	ga3_->Draw("APe1");
	C->Print(out_file_, "pdf");
	ga4_->Draw("APe1");
	C->Print(out_file_, "pdf");

	gb1_->Draw("APe1");
	C->Print(out_file_, "pdf");
	gb2_->Draw("APe1");
	C->Print(out_file_, "pdf");
	gb3_->Draw("APe1");
	C->Print(out_file_, "pdf");
	gb4_->Draw("APe1");
	C->Print(out_file_, "pdf");
	
	g1_->Draw("APe1");
	g2_->Draw("Pe1");
	g3_->Draw("Pe1");
	g4_->Draw("Pe1");
	C->Print(out_file_, "pdf");
	
	ga1_->Draw("APe1");
	ga2_->Draw("Pe1");
	ga3_->Draw("Pe1");
	ga4_->Draw("Pe1");
	C->Print(out_file_, "pdf");

	gb1_->Draw("APe1");
	gb2_->Draw("Pe1");
	gb3_->Draw("Pe1");
	gb4_->Draw("Pe1");
	C->Print(out_file_, "pdf");

	g1_->Draw("APe1");
	g2_->Draw("Pe1");
	g3_->Draw("Pe1");
	g4_->Draw("Pe1");
	gb1_->Draw("Pe1");
	gb2_->Draw("Pe1");
	gb3_->Draw("Pe1");
	gb4_->Draw("Pe1");

	C->Print(out_file_, "pdf");
	ga1_->Draw("APe1");
	ga2_->Draw("Pe1");
	ga3_->Draw("Pe1");
	ga4_->Draw("Pe1");
	gb1_->Draw("Pe1");
	gb2_->Draw("Pe1");
	gb3_->Draw("Pe1");
	gb4_->Draw("Pe1");
	C->Print(out_file_, "pdf");
/////////////////////////////////////////////////////////////////////
/////////////// graphs from 2 different bins together ///////////////
/////////////////////////////////////////////////////////////////////
	
	g1->Draw("APe1");
	g1->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	g2->Draw("Pe1");
	g3->Draw("Pe1");
	g4->Draw("Pe1");
	g1_->Draw("Pe1");
	g1_->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	g2_->Draw("Pe1");
	g3_->Draw("Pe1");
	g4_->Draw("Pe1");
	C->Print(out_file_, "pdf");
	
	ga1->Draw("APe1");
	ga1->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	ga2->Draw("Pe1");
	ga3->Draw("Pe1");
	ga4->Draw("Pe1");
	ga1_->Draw("Pe1");
	ga1_->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	ga2_->Draw("Pe1");
	ga3_->Draw("Pe1");
	ga4_->Draw("Pe1");
	C->Print(out_file_, "pdf");

	gb1->Draw("APe1");
	gb1->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	gb2->Draw("Pe1");
	gb3->Draw("Pe1");
	gb4->Draw("Pe1");
	gb1_->Draw("Pe1");
	gb1_->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	gb2_->Draw("Pe1");
	gb3_->Draw("Pe1");
	gb4_->Draw("Pe1");
	C->Print(out_file_, "pdf");
	C->SetLogy(0);
	
	Eb2->SetTitle("sum-pt,+-7.5 binning ");	
	Eb2->Draw("hist ");
	Eb3->Draw("hist same");
	Eb4->Draw("hist same");
	Eb5->Draw("hist same");
	E2->Draw("hist same");
	E3->Draw("hist same");
	E4->Draw("hist same");
	E5->Draw("hist same");
	C->Print(out_file_, "pdf");
	
	Eb_2->SetTitle("sum-pt,+-3.75 binning ");	
	Eb_2->Draw("hist ");
	Eb_3->Draw("hist same");
	Eb_4->Draw("hist same");
	Eb_5->Draw("hist same");
	E2_->Draw("hist same");
	E3_->Draw("hist same");
	E4_->Draw("hist same");
	E5_->Draw("hist same");
	C->Print(out_file_, "pdf");

	Eb2->SetTitle("max pt TJ from each bin,+-7.5 binning ");	
	Eb2->Draw("hist ");
	Eb3->Draw("hist same");
	Eb4->Draw("hist same");
	Eb5->Draw("hist same");
	Ea2->Draw("hist same");
	Ea3->Draw("hist same");
	Ea4->Draw("hist same");
	Ea5->Draw("hist same");
	C->Print(out_file_, "pdf");
	Eb_2->SetTitle("max pt TJ from each bin,+-3.75 binning ");	
	Eb_2->Draw("hist ");
	Eb_3->Draw("hist same");
	Eb_4->Draw("hist same");
	Eb_5->Draw("hist same");
	Ea_2->Draw("hist same");
	Ea_3->Draw("hist same");
	Ea_4->Draw("hist same");
	Ea_5->Draw("hist same");
	C->Print(out_file_, "pdf");

	C->SetLogy();
	Rb2->SetTitle("sum-pt,+-7.5 binning ");	
	Rb2->Draw("hist ");
	Rb3->Draw("hist same");
	Rb4->Draw("hist same");
	Rb5->Draw("hist same");
	R2->Draw("hist same");
	R3->Draw("hist same");
	R4->Draw("hist same");
	R5->Draw("hist same");
	C->Print(out_file_, "pdf");
	
	Rb_2->SetTitle("sum-pt,+-3.75 binning ");	
	Rb_2->Draw("hist ");
	Rb_3->Draw("hist same");
	Rb_4->Draw("hist same");
	Rb_5->Draw("hist same");
	R2_->Draw("hist same");
	R3_->Draw("hist same");
	R4_->Draw("hist same");
	R5_->Draw("hist same");
	C->Print(out_file_, "pdf");

	Rb2->SetTitle("max pt TJ from each bin,+-7.5 binning ");	
	Rb2->Draw("hist ");
	Rb3->Draw("hist same");
	Rb4->Draw("hist same");
	Rb5->Draw("hist same");
	Ra2->Draw("hist same");
	Ra3->Draw("hist same");
	Ra4->Draw("hist same");
	Ra5->Draw("hist same");
	C->Print(out_file_, "pdf");
	Rb_2->SetTitle("max pt TJ from each bin,+-3.75 binning ");	
	Rb_2->Draw("hist ");
	Rb_3->Draw("hist same");
	Rb_4->Draw("hist same");
	Rb_5->Draw("hist same");
	Ra_2->Draw("hist same");
	Ra_3->Draw("hist same");
	Ra_4->Draw("hist same");
	Ra_5->Draw("hist same");
	C->Print(out_file_close,"pdf");
}
