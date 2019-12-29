#include<iostream>
#include "TFile.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TH1D.h"
const char *out_tex_file_name = "./analysis_plots/tex/test_tex.tex";
const char *input_root_file = "./analysis_plots/root/GenJet4b2_2.5_allR0.4.root";
void padToTex(const char *pad_name)
{

	TFile *f = new TFile(input_root_file, "READ");
	TCanvas *c = new TCanvas("c","c",800,800);
	//Set canvas properties here e.g. set grid etc. 
	TPad *mypad = (TPad*)f->Get(pad_name);
	gStyle->SetOptStat(0);
	mypad->SetPad(0,0,1,1);
	mypad->DrawClone();
	c->SaveAs(out_tex_file_name);
	return;
}
