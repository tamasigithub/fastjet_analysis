#include <iostream>
#include <fstream>
#include <string>
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TH1.h"
#include "TGraphErrors.h"

Float_t YAXISTITLE_OFFSET = 1.2;
Float_t TITLE_SIZE = 0.04;
Float_t LINE_WIDTH = 2.5;
Float_t MARKER_SIZE = 1.2;

const char *inp100TeV_DS1  = "user.tkar.pp_ggF_Ctr1.0hh_pythia82_GenCuts.v5_output.root/*.root";
const char *inp100TeV_DS0  = "user.tkar.pp_ggF_Ctr0.0hh_pythia82_GenCuts.v5_output.root/*.root";
const char *inp100TeV_DS_1 = "user.tkar.pp_ggF_Ctr-1.0hh_pythia82_GenCuts.v5_output.root/*.root";
const char *inp100TeV_DS_2 = "user.tkar.pp_ggF_Ctr-2.0hh_pythia82_GenCuts.v5_output.root/*.root";
const char *inp100TeV_DS2  = "user.tkar.pp_ggF_Ctr2.0hh_pythia82_GenCuts.v5_output.root/*.root";
const char *inp100TeV_DS2_5= "user.tkar.pp_ggF_Ctr2.5hh_pythia82_GenCuts.v5_output.root/*.root";
const char *inp100TeV_DS3  = "user.tkar.pp_ggF_Ctr3.0hh_pythia82_GenCuts.v5_output.root/*.root";

const char *inp14TeV_DS1  = "~/cernbox2/user.tkar.pp14TeV_ggF_Ctr1.0hh_pythia82_GenCuts.v1_output.root/*.root";
const char *inp14TeV_DS0  = "~/cernbox2/user.tkar.pp14TeV_ggF_Ctr0.0hh_pythia82_GenCuts.v1_output.root/*.root";
const char *inp14TeV_DS_1 = "~/cernbox2/user.tkar.pp14TeV_ggF_Ctr-1.0hh_pythia82_GenCuts.v1_output.root/*.root";
const char *inp14TeV_DS_2 = "~/cernbox2/user.tkar.pp14TeV_ggF_Ctr-2.0hh_pythia82_GenCuts.v1_output.root/*.root";
const char *inp14TeV_DS2  = "~/cernbox2/user.tkar.pp14TeV_ggF_Ctr2.0hh_pythia82_GenCuts.v1_output.root/*.root";
const char *inp14TeV_DS2_5= "~/cernbox2/user.tkar.pp14TeV_ggF_Ctr2.5hh_pythia82_GenCuts.v1_output.root/*.root";
const char *inp14TeV_DS3  = "~/cernbox2/user.tkar.pp14TeV_ggF_Ctr3.0hh_pythia82_GenCuts.v1_output.root/*.root";
const int N_files = 7;
double k_lambda[N_files] = {-2.0, -1.0, 0.0, 1.0, 2.0, 2.5, 3.0};
double Xsec100[N_files] = {0};
double Xsec14[N_files] = {0};

double NNLO_gFhhXsec100 = 1224, NNLO_gFhhXsec14 = 36.69;//fb
double k_factor100, k_factor14;

void cross_section_100TeV()
{
	TChain c1("Metadata");
	TChain c0("Metadata");
	TChain c_1("Metadata");
	TChain c_2("Metadata");
	TChain c2("Metadata");
	TChain c2_5("Metadata");
	TChain c3("Metadata");

	c1.Add(inp100TeV_DS1);
	c0.Add(inp100TeV_DS0);
	c_1.Add(inp100TeV_DS_1);
	c_2.Add(inp100TeV_DS_2);
	c2.Add(inp100TeV_DS2);
	c2_5.Add(inp100TeV_DS2_5);
	c3.Add(inp100TeV_DS3);

	TH1 *h_temp = nullptr;

	c1.Draw("crossSectionInPb");
	h_temp = (TH1*)gPad->GetPrimitive("htemp"); 
	k_factor100 = NNLO_gFhhXsec100/(h_temp->GetMean() * 1e3);
	std::cout<<"k factor for 100TeV: " <<k_factor100 <<std::endl;
	Xsec100[3] = NNLO_gFhhXsec100;
	//delete h_temp;
	c_2.Draw("crossSectionInPb");
	h_temp = (TH1*)gPad->GetPrimitive("htemp"); 
	Xsec100[0] = h_temp->GetMean() * 1e3 * k_factor100;
	//delete h_temp;
	c_1.Draw("crossSectionInPb");
	h_temp = (TH1*)gPad->GetPrimitive("htemp"); 
	Xsec100[1] = h_temp->GetMean() * 1e3 * k_factor100;
	//delete h_temp;
	c0.Draw("crossSectionInPb");
	h_temp = (TH1*)gPad->GetPrimitive("htemp"); 
	Xsec100[2] = h_temp->GetMean() * 1e3 * k_factor100;
	//delete h_temp;
	c2.Draw("crossSectionInPb");
	h_temp = (TH1*)gPad->GetPrimitive("htemp"); 
	Xsec100[4] = h_temp->GetMean() * 1e3 * k_factor100;
	//delete h_temp;
	c2_5.Draw("crossSectionInPb");
	h_temp = (TH1*)gPad->GetPrimitive("htemp"); 
	Xsec100[5] = h_temp->GetMean() * 1e3 * k_factor100;
	//delete h_temp;
	c3.Draw("crossSectionInPb");
	h_temp = (TH1*)gPad->GetPrimitive("htemp"); 
	Xsec100[6] = h_temp->GetMean() * 1e3 * k_factor100;
	//delete h_temp;

	TCanvas *c = new TCanvas();
        TGraphErrors *g3 = new TGraphErrors(N_files, k_lambda,Xsec100,0,0);
        g3->GetXaxis()->SetTitle("k_{#lambda}");
        g3->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
        g3->GetYaxis()->SetTitle("#sigma [fb]");
        g3->GetYaxis()->SetTitleSize(TITLE_SIZE);
        g3->GetXaxis()->SetTitleSize(TITLE_SIZE);
        g3->GetYaxis()->CenterTitle();
        g3->GetXaxis()->CenterTitle();
        g3->SetMarkerStyle(kFullCircle);//kFullCircle);
        g3->SetMarkerColor(kGreen);
        g3->SetLineColor(kGreen);
        g3->SetLineWidth(LINE_WIDTH);
        g3->SetMarkerSize(MARKER_SIZE);
        //g3->SetFillStyle(0);  //   Y 
        g3->SetTitle("NNLO cross-section Vs k_{#lambda} for Higgs pair production via gF");
        g3->Draw("ACPe1");
	gPad->Modified();
	//TAxis *axis = gr1->GetXaxis();
	//axis->SetLimits(0.,5.);                 // along X
	g3->SetMaximum(8000.);   // along          
	g3->SetMinimum(500.);
	g3->Draw("ACPe1");
	c->Update();
	
        //! write to a text file
	std::cout<<"Writing to txt file...." <<std::endl;
        const char* txt_path = ".";
        char txt_file[1023];
        sprintf(txt_file,"%s/Xsec_NNLOgFhh_100TeV.txt",txt_path);
        std::ofstream ofs;
        ofs.open (txt_file, std::ofstream::out | std::ofstream::app);
	for(int i = 0; i < N_files; i++)
	{
        	ofs<<k_lambda[i]<<" "<<Xsec100[i]<<"\n";

	}
	
	ofs<<"\n" <<"NNLO k factor used for 100TeV: " <<k_factor100 <<"\n";
	TFile *f_out = new TFile("Xsec_NNLOgFhh_100TeV.root", "RECREATE");
	g3->Write("NNLOXsec_100TeV");
	c->Write("C_NNLOXsec_100TeV");
	f_out->Close();
	return;
}
void cross_section_14TeV()
{
	TChain c1("Metadata");
	TChain c0("Metadata");
	TChain c_1("Metadata");
	TChain c_2("Metadata");
	TChain c2("Metadata");
	TChain c2_5("Metadata");
	TChain c3("Metadata");

	c1.Add(inp14TeV_DS1);
	c0.Add(inp14TeV_DS0);
	c_1.Add(inp14TeV_DS_1);
	c_2.Add(inp14TeV_DS_2);
	c2.Add(inp14TeV_DS2);
	c2_5.Add(inp14TeV_DS2_5);
	c3.Add(inp14TeV_DS3);

	TH1 *h_temp = nullptr;

	c1.Draw("crossSectionInPb");
	h_temp = (TH1*)gPad->GetPrimitive("htemp"); 
	k_factor14 = NNLO_gFhhXsec14/(h_temp->GetMean() * 1e3);
	std::cout<<"k factor for 14TeV: " <<k_factor14 <<std::endl;
	Xsec14[3] = NNLO_gFhhXsec14;
	//delete h_temp;
	c_2.Draw("crossSectionInPb");
	h_temp = (TH1*)gPad->GetPrimitive("htemp"); 
	Xsec14[0] = h_temp->GetMean() * 1e3 * k_factor14;
	//delete h_temp;
	c_1.Draw("crossSectionInPb");
	h_temp = (TH1*)gPad->GetPrimitive("htemp"); 
	Xsec14[1] = h_temp->GetMean() * 1e3 * k_factor14;
	//delete h_temp;
	c0.Draw("crossSectionInPb");
	h_temp = (TH1*)gPad->GetPrimitive("htemp"); 
	Xsec14[2] = h_temp->GetMean() * 1e3 * k_factor14;
	//delete h_temp;
	c2.Draw("crossSectionInPb");
	h_temp = (TH1*)gPad->GetPrimitive("htemp"); 
	Xsec14[4] = h_temp->GetMean() * 1e3 * k_factor14;
	//delete h_temp;
	c2_5.Draw("crossSectionInPb");
	h_temp = (TH1*)gPad->GetPrimitive("htemp"); 
	Xsec14[5] = h_temp->GetMean() * 1e3 * k_factor14;
	//delete h_temp;
	c3.Draw("crossSectionInPb");
	h_temp = (TH1*)gPad->GetPrimitive("htemp"); 
	Xsec14[6] = h_temp->GetMean() * 1e3 * k_factor14;
	//delete h_temp;

        TGraphErrors *g3 = new TGraphErrors(N_files, k_lambda,Xsec14,0,0);
        g3->GetXaxis()->SetTitle("k_{#lambda}");
        g3->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
        g3->GetYaxis()->SetTitle("#sigma [fb]");
        g3->GetYaxis()->SetTitleSize(TITLE_SIZE);
        g3->GetXaxis()->SetTitleSize(TITLE_SIZE);
        g3->GetYaxis()->CenterTitle();
        g3->GetXaxis()->CenterTitle();
        //g3->GetYaxis()->SetRangeUser(0, 400);
	//TAxis *axis = gr1->GetXaxis();
	//axis->SetLimits(0.,5.);                 // along X
	g3->SetMaximum(400.);   // along          
	g3->SetMinimum(0.);
	g3->Draw("ACPe1");
        g3->SetMarkerStyle(kFullCircle);//kFullCircle);
        g3->SetMarkerColor(kBlue);
        g3->SetLineColor(kBlue);
        g3->SetLineWidth(LINE_WIDTH);
        g3->SetMarkerSize(MARKER_SIZE);
        g3->SetFillStyle(0);
        g3->SetTitle("NNLO cross-section Vs k_{#lambda} for Higgs pair production via gF");
	TCanvas *c = new TCanvas();
        g3->Draw("ACPe1");
	
        //! write to a text file
	std::cout<<"Writing to txt file...." <<std::endl;
        const char* txt_path = ".";
        char txt_file[1023];
        sprintf(txt_file,"%s/Xsec_NNLOgFhh_14TeV.txt",txt_path);
        std::ofstream ofs;
        ofs.open (txt_file, std::ofstream::out | std::ofstream::app);
	for(int i = 0; i < N_files; i++)
	{
        	ofs<<k_lambda[i]<<" "<<Xsec14[i]<<"\n";

	}

	ofs<<"\n" <<"NNLO k factor used for 14TeV: " <<k_factor14 <<"\n";
	
	TFile *f_out = new TFile("Xsec_NNLOgFhh_14TeV.root", "RECREATE");
	g3->Write("NNLOXsec_14TeV");
	c->Write("C_NNLOXsec_14TeV");
	f_out->Close();
	return;
}

void plot()
{

	TFile *f1 = new TFile("Xsec_NNLOgFhh_100TeV.root", "READ");
	TFile *f2 = new TFile("Xsec_NNLOgFhh_14TeV.root", "READ");

	TGraphErrors *g1 = (TGraphErrors*)f1->Get("NNLOXsec_100TeV");
	g1->SetMinimum(0.);
	g1->SetMaximum(8000.);
	TGraphErrors *g2 = (TGraphErrors*)f2->Get("NNLOXsec_14TeV");

	TLegend *leg = new TLegend(0.65, 0.8, 0.9, 0.9);
	leg->SetBorderSize(0);
	leg->SetTextSize(0.035);
	leg->SetFillStyle(0);
	leg->AddEntry(g1, "#sqrt{s} = 100 TeV", "l");
	leg->AddEntry(g2, "#sqrt{s} = 14 TeV", "l");
	//TCanvas *C = new TCanvas();
	TCanvas *C = new TCanvas("C", "C", 800, 800);
	C->SetLogy();
	gStyle->SetOptTitle(0);
	g1->Draw("ACPe1");
        g1->GetXaxis()->SetTitle("k_{#lambda}");
        g1->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
        g1->GetYaxis()->SetTitle("#sigma [fb]");
        g1->GetYaxis()->SetTitleSize(TITLE_SIZE);
        g1->GetXaxis()->SetTitleSize(TITLE_SIZE);
        g1->GetYaxis()->CenterTitle();
        g1->GetXaxis()->CenterTitle();
	g2->Draw("CPe1");
	leg->Draw();
	C->Update();
	C->SaveAs("./analysis_plots/tex/Xsec_NNLOhhgF_14_100TeV.tex");

	return;
}
