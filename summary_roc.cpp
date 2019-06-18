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
	Float_t Xmin_range = 0.0, Xmax_range = 1.2;
	Float_t Ymin_range = 1e-1, Ymax_range = 50.0;
	Float_t e2[n] = {0};   Float_t r2[n] = {0};
	Float_t e3[n] = {0};   Float_t r3[n] = {0};
	Float_t e4[n] = {0};   Float_t r4[n] = {0};
	Float_t e5[n] = {0};   Float_t r5[n] = {0};
	/////////////////////////////////////////////////
	//! Fetch the histograms
	////////////////////////////////////////////////
	const char *file_path = ".";
	char signal_file_name[1023];
	//sprintf(signal_file_name, "%s/jetoutPU%shh4b_%smm_optsig5.root",file_path,pileup,gapsize);
	sprintf(signal_file_name, "%s/jetoutPU%shh4b_%smm_optsig5_nofaketracks.root",file_path,pileup,gapsize);//7.5
	//sprintf(signal_file_name, "%s/jetoutPU%shh4b_%smm_optsig5_nofaketracks3.75.root",file_path,pileup,gapsize);
	//sprintf(signal_file_name, "%s/jetoutPU%shh4b_%smm_optsig5_nofaketracks3.0.root",file_path,pileup,gapsize);
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
	
	char MinBias_file_name[1023];
	//sprintf(MinBias_file_name, "%s/jetoutPU%sMB_%smm_optsig5.root",file_path,pileup,gapsize);
	sprintf(MinBias_file_name, "%s/jetoutPU%sMB_%smm_optsig5_nofaketracks.root",file_path,pileup,gapsize);//7.5
	//sprintf(MinBias_file_name, "%s/jetoutPU%sMB_%smm_optsig5_nofaketracks3.75.root",file_path,pileup,gapsize);
	//sprintf(MinBias_file_name, "%s/jetoutPU%sMB_%smm_optsig5_nofaketracks3.0.root",file_path,pileup,gapsize);
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
	
	TCanvas *c = new TCanvas();	
        TH1::SetDefaultSumw2(true);

	nbinsE = E2->GetNbinsX();
	nbinsR = R2->GetNbinsX();
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

		
		//! Fill into arrays and plot graph
		e2[i-1] = E2->GetBinContent(i);
		r2[i-1] = R2->GetBinContent(i);
		e3[i-1] = E3->GetBinContent(i);
		r3[i-1] = R3->GetBinContent(i);
		e4[i-1] = E4->GetBinContent(i);
		r4[i-1] = R4->GetBinContent(i);
		e5[i-1] = E5->GetBinContent(i);
		r5[i-1] = R5->GetBinContent(i);
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

//////////////////////////////////////////////////////////////
	
	Double_t x1= 0.91,y1= 0.12, x2 = 0.99, y2 = 0.3;
	c1->SetGridx();
	c1->SetGridy();
	TMultiGraph *g = new TMultiGraph();
	g->Add(g1);
	g->Add(g2);
	g->Add(g3);
	g->Add(g4);
	g->Draw("AP");
	//g->SetTitle(plot_title);
	g->GetXaxis()->SetTitle("#epsilon_{Ntrack-jets}");
	g->GetYaxis()->SetTitle("trigger rate [MHz]");
	g->GetXaxis()->SetTitleSize(0.04);
	g->GetYaxis()->SetTitleSize(0.04);
	//g->GetXaxis()->SetRangeUser(0,100);
	//g->GetYaxis()->SetTitleOffset(1.5);
	g->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	c1->BuildLegend(x1,y1,x2,y2,"");

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
	SaveCanvas(c1,"summary_ROChh4b_MB_nofaketracks7.5");
/////////////////////////////////////////////////////////////
}


