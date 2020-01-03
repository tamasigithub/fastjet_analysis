#include<iostream>
#include "TFile.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TH1D.h"
#include "TLatex.h"
const char *out_path = "./analysis_plots/tex";
const char *in_path = "./analysis_plots/root";
const char *input_root_file = "./analysis_plots/root/GenJet4b2_2.5_allR0.4.root";
//void padToTex(const char *pad_name)
void pad(const char *pad_name, int which_legend = 0, bool up = false, const char *input_file = "GenJet4b2_2.5_allR0.4.root")
{

	char input_root_file[1023];
        sprintf(input_root_file,"%s/%s",in_path,input_file);
	char out_tex_file_name[1023];
        sprintf(out_tex_file_name,"%s/%s.tex",out_path,pad_name);

	TFile *f = new TFile(input_root_file, "READ");
	TCanvas *c = new TCanvas("c","c",800,800);
	//Set canvas properties here e.g. set grid etc. 
	TPad *mypad = (TPad*)f->Get(pad_name);
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);
	gStyle->SetTitleX(0.1f);
	gStyle->SetTitleW(0.8f);
	mypad->SetPad(0,0,1,1);
	mypad->DrawClone();
	
	//!k_lambda legend
	if(which_legend == 1)
	{
		TPad *legend = (TPad*)f->Get("c2_d");
		//legend->SetPad(0.4,0.5,0.899,0.899);//dx = 0.5, dy = 0.4
		if(up) legend->SetPad(0.35,0.4,0.9,0.85);
		else legend->SetPad(0.3,0.02,0.85,0.47);
		legend->SetFillStyle(0);// make the pad transparent
		legend->DrawClone();
	}
	//! 4 leading jets legend
	if(which_legend == 2)
	{
		TPad *legend = (TPad*)f->Get("c4_d");
		//legend->SetPad(0.4,0.5,0.899,0.899);//dx = 0.5, dy = 0.4
		legend->SetPad(0.4,0.4,0.94,0.85);
		legend->SetFillStyle(0);// make the pad transparent
		legend->DrawClone();
	}
	//! cuts legend
	if(which_legend == 3)
	{
		TPad *legend = (TPad*)f->Get("c43c");
		//legend->SetPad(0.4,0.5,0.899,0.899);//dx = 0.5, dy = 0.4
		legend->SetPad(0.4,0.42,0.94,0.89);
		legend->SetFillStyle(0);// make the pad transparent
		legend->DrawClone();
	}

	TPad *newpad=new TPad("newpad","a transparent pad",0,0,1,1);
	newpad->SetFillStyle(4000);
	newpad->Draw();
	newpad->cd();

	//TLegend *cms_E = new TLegend(0.35,0.91,0.65,0.96);
	TLegend *cms_E = new TLegend(0.55,0.79,0.9,0.92);
	cms_E->SetFillStyle(0);
	cms_E->SetBorderSize(0);
	cms_E->AddEntry((TObject*)0, "#sqrt{s} = 100 TeV", "");
	cms_E->SetTextSize(0.04);
        cms_E->Draw();	
	c->Update();

	if(which_legend == 0)
	{
		TLegend *ana_txt = new TLegend(0.5,0.8,0.94,0.79);
		ana_txt->SetFillStyle(0);
		ana_txt->SetBorderSize(0);
		ana_txt->AddEntry((TObject*)0, "after analysis cuts", "");
		ana_txt->SetTextSize(0.04);
		ana_txt->Draw();	
		c->Update();
	
	}



	c->SaveAs(out_tex_file_name);
	return;
}
