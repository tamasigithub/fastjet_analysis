///**********open all files and save it in a single pdf **************///
//low pt min bias files sigma =3,5 and no kappa cut
//hight pt min bias files sigma =3,5 and no kappa cut
//hh4b files sigma =3,5 and no kappa
#include <iostream>
#include "TROOT.h"
#include "TFile.h"
#include "TH1D.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TLegend.h"
#include "TGraphErrors.h"
#include "TPostScript.h"
#include <fstream>
#include <string>
#include <math.h>
const char* out_path = "/eos/user/t/tkar/www/TTT/plots/trackJet";
int writeEff_to_pdf(const char* output_file_name = "tJefficiency_LptMB")
{

	char out_file_open[1023];
        sprintf(out_file_open,"%s/%s.pdf(",out_path,output_file_name);
        char out_file_[1023];
        sprintf(out_file_,"%s/%s.pdf",out_path,output_file_name);
        char out_file_close[1023];
        sprintf(out_file_close,"%s/%s.pdf)",out_path,output_file_name);
	
	TFile* f1 = TFile::Open("jetEff_LptMB1_3rec.root");
	TH1F* hep1	= (TH1F*)f1->Get("h_eff_vs_ptPU");
	TH1F* hee1	= (TH1F*)f1->Get("h_eff_vs_etaPU");

	TFile* f2 = TFile::Open("jetEff_LptMB1_5rec.root");
	TH1F* hep2	= (TH1F*)f2->Get("h_eff_vs_ptPU");
	TH1F* hee2	= (TH1F*)f2->Get("h_eff_vs_etaPU");
	
	TFile* f3 = TFile::Open("jetEff_LptMB1_noKaprec.root");
	TH1F* hep3	= (TH1F*)f3->Get("h_eff_vs_ptPU");
	TH1F* hee3	= (TH1F*)f3->Get("h_eff_vs_etaPU");
	
	TFile* f4= TFile::Open("jetEff_LptMB1_looserec.root");
	TH1F* hep4	= (TH1F*)f4->Get("h_eff_vs_ptPU");
	TH1F* hee4	= (TH1F*)f4->Get("h_eff_vs_etaPU");

	hep1->SetMarkerColor(kRed);
	hep2->SetMarkerColor(kBlue);
	hep3->SetMarkerColor(kBlack);
	hep4->SetMarkerColor(kGreen);
	hee1->SetMarkerColor(kRed);
	hee2->SetMarkerColor(kBlue);
	hee3->SetMarkerColor(kBlack);
	hee4->SetMarkerColor(kGreen);

	hep1->SetMarkerSize(1.2);
	hep2->SetMarkerSize(1.2);
	hep3->SetMarkerSize(1.2);
	hep4->SetMarkerSize(1.2);
	hee1->SetMarkerSize(1.2);
	hee2->SetMarkerSize(1.2);
	hee3->SetMarkerSize(1.2);
	hee4->SetMarkerSize(1.2);
	
	std::cout<<"Writing to pdf... \n";
	Double_t x1= 0.77,y1= 0.75, x2 = 0.99, y2 = 0.99, yy1 = 0.6, yy2 = 0.91;
	TCanvas * S = new TCanvas();
	S->Divide(2,2);
	gStyle->SetOptStat(0);
	S->SetGridx();
        S->SetGridy();
	TPad *p1 = (TPad*)(S->cd(1));
	p1->SetLogx();
	hep1->Draw();
	TLegend *l1=new TLegend(x1,y1,x2,y2,"");
	l1->SetBorderSize(0);
        l1->SetTextAlign(32);
        l1->SetTextSize(0.035);
	l1->AddEntry(hep1,"#sigma_{#kappa} = 3");
	l1->Draw();
	
	TPad *p2 = (TPad*)(S->cd(2));
	p2->SetLogx();
	hep2->Draw();
	TLegend *l2=new TLegend(x1,y1,x2,y2,"");
	l2->SetBorderSize(0);
        l2->SetTextAlign(32);
        l2->SetTextSize(0.035);
	l2->AddEntry(hep2,"#sigma_{#kappa} = 5");
	l2->Draw();

	TPad *p3 = (TPad*)(S->cd(3));
	p3->SetLogx();
	hep3->Draw();
	TLegend *l3=new TLegend(x1,y1,x2,y2,"");
	l3->SetBorderSize(0);
        l3->SetTextAlign(32);
        l3->SetTextSize(0.035);
	l3->AddEntry(hep3,"No #kappa cut");
	l3->Draw();
	
	TPad *p4 = (TPad*)(S->cd(4));
	p4->SetLogx();
	hep4->Draw();
	TLegend *l4=new TLegend(x1,y1,x2,y2,"");
	l4->SetBorderSize(0);
        l4->SetTextAlign(32);
        l4->SetTextSize(0.035);
	l4->AddEntry(hep4,"loose cuts");
	l4->Draw();
	S->Print(out_file_open, "pdf");
	p1->SetLogx(0);
	p2->SetLogx(0);
	p3->SetLogx(0);
	p4->SetLogx(0);

	S->cd(1);
	hee1->Draw();
	TLegend *m1=new TLegend(x1,y1,x2,y2,"");
	m1->SetBorderSize(0);
        m1->SetTextAlign(32);
        m1->SetTextSize(0.035);
	m1->AddEntry(hee1,"#sigma_{#kappa} = 3");
	m1->Draw();
	
	S->cd(2);
	hee2->Draw();
	TLegend *m2=new TLegend(x1,y1,x2,y2,"");
	m2->SetBorderSize(0);
        m2->SetTextAlign(32);
        m2->SetTextSize(0.035);
	m2->AddEntry(hee2,"#sigma_{#kappa} = 5");
	m2->Draw();

	S->cd(3);
	hee3->Draw();
	TLegend *m3=new TLegend(x1,y1,x2,y2,"");
	m3->SetBorderSize(0);
        m3->SetTextAlign(32);
        m3->SetTextSize(0.035);
	m3->AddEntry(hee3,"No #kappa cut");
	m3->Draw();
	
	S->cd(4);
	hee4->Draw();
	TLegend *m4=new TLegend(x1,y1,x2,y2,"");
	m4->SetBorderSize(0);
        m4->SetTextAlign(32);
        m4->SetTextSize(0.035);
	m4->AddEntry(hee4,"loose cuts");
	m4->Draw();
	S->Print(out_file_,"pdf");

	S->Clear();
	hep1->Draw();
	hep2->Draw("same");
	hep3->Draw("same");
	hep4->Draw("same");
	S->SetLogx();
	TLegend *n1=new TLegend(x1,y1,x2,y2,"");
	n1->SetBorderSize(0);
        n1->SetTextAlign(32);
        n1->SetTextSize(0.035);
	n1->AddEntry(hep1,"#sigma_{#kappa} = 3");
	n1->AddEntry(hep2,"#sigma_{#kappa} = 5");
	n1->AddEntry(hep3,"no #kappa cut");
	n1->AddEntry(hep4,"loose cuts");
	n1->Draw();
	S->Print(out_file_,"pdf");
	
	S->SetLogx(0);	
	hee1->Draw();
	hee2->Draw("same");
	hee3->Draw("same");
	hee4->Draw("same");
	TLegend *n2=new TLegend(x1,y1,x2,y2,"");
	n2->SetBorderSize(0);
        n2->SetTextAlign(32);
        n2->SetTextSize(0.035);
	n2->AddEntry(hee1,"#sigma_{#kappa} = 3");
	n2->AddEntry(hee2,"#sigma_{#kappa} = 5");
	n2->AddEntry(hee3,"no #kappa cut");
	n2->AddEntry(hee4,"loose cuts");
	n2->Draw();
	S->Print(out_file_close,"pdf");

return 0;
}
