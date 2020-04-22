//!!!*********** Track multiplicities of 2nd, 3rd, 4th and 5th leading track-jets *************!!!//
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
const char* out_path = "./summary_plots/pdf"; 
//const char* output_file_name = "multiplicity_1tracks1.5_5GeVPU0";
const char* output_file_name = "multiplicity_1.2mm_30mm_43221trk2.5_2GeV_3GeV_2";

const double yMin = 0.5, yMax = 5.0e3;
//! sumpt approach
TH1D *E2 = nullptr;
TH1D *E3 = nullptr;
TH1D *E4 = nullptr;
TH1D *E5 = nullptr;
//! Lpt bins approach
TH1D *Ea2 = nullptr;
TH1D *Ea3 = nullptr;
TH1D *Ea4 = nullptr;
TH1D *Ea5 = nullptr;
//! no z-vertex bin 
TH1D *Eb2 = nullptr;
TH1D *Eb3 = nullptr;
TH1D *Eb4 = nullptr;
TH1D *Eb5 = nullptr;
//! sumpt approach
TH1D *R2 = nullptr; 
TH1D *R3 = nullptr; 
TH1D *R4 = nullptr; 
TH1D *R5 = nullptr; 
//! Lpt bins
TH1D *Ra2 = nullptr;
TH1D *Ra3 = nullptr;
TH1D *Ra4 = nullptr;
TH1D *Ra5 = nullptr;
//! no z-ver
TH1D *Rb2 = nullptr;
TH1D *Rb3 = nullptr;
TH1D *Rb4 = nullptr;
TH1D *Rb5 = nullptr;
int integral(TH1D *hist)
{
	//return hist->Integral(2,11);//from multiplicity 1 to 10
	return hist->Integral(2,101);//from multiplicity 1 to 100

}
void fetch_histos(TFile *f, TFile *f1)
{

	std::cout<<"Fetching histograms"<<std::endl;
	//! sumpt approach
	E2 = (TH1D*)f->Get("hM_PUNLpt"); 
	E3 = (TH1D*)f->Get("hM_PUNNLpt");
	E4 = (TH1D*)f->Get("hM_PUNNNLpt");
	E5 = (TH1D*)f->Get("hM_PUNNNNLpt");
	//! Lpt bins appoach
	Ea2 = (TH1D*)f->Get("hMa_PUNLpt");   
	Ea3 = (TH1D*)f->Get("hMa_PUNNLpt");  
	Ea4 = (TH1D*)f->Get("hMa_PUNNNLpt"); 
	Ea5 = (TH1D*)f->Get("hMa_PUNNNNLpt");
	//! no z-vertex in                   
	Eb2 = (TH1D*)f->Get("hMb_PUNLpt");   
	Eb3 = (TH1D*)f->Get("hMb_PUNNLpt");  
	Eb4 = (TH1D*)f->Get("hMb_PUNNNLpt"); 
	Eb5 = (TH1D*)f->Get("hMb_PUNNNNLpt");

	//! sumpt approach
	R2 = (TH1D*)f1->Get("hM_PUNLpt");
	R3 = (TH1D*)f1->Get("hM_PUNNLpt");
	R4 = (TH1D*)f1->Get("hM_PUNNNLpt");
	R5 = (TH1D*)f1->Get("hM_PUNNNNLpt");
	//! Lpt bins approach
	Ra2 = (TH1D*)f1->Get("hMa_PUNLpt");
	Ra3 = (TH1D*)f1->Get("hMa_PUNNLpt");
	Ra4 = (TH1D*)f1->Get("hMa_PUNNNLpt");
	Ra5 = (TH1D*)f1->Get("hMa_PUNNNNLpt");
	//! no z-vertex bin 
	Rb2 = (TH1D*)f1->Get("hMb_PUNLpt");
	Rb3 = (TH1D*)f1->Get("hMb_PUNNLpt");
	Rb4 = (TH1D*)f1->Get("hMb_PUNNNLpt");
	Rb5 = (TH1D*)f1->Get("hMb_PUNNNNLpt");
}
void setRange()
{
	
	E2->GetYaxis()->SetRangeUser(yMin,yMax);
	E3->GetYaxis()->SetRangeUser(yMin,yMax);
	E4->GetYaxis()->SetRangeUser(yMin,yMax);
	E5->GetYaxis()->SetRangeUser(yMin,yMax);

	Ea2->GetYaxis()->SetRangeUser(yMin,yMax);
	Ea3->GetYaxis()->SetRangeUser(yMin,yMax);
	Ea4->GetYaxis()->SetRangeUser(yMin,yMax);
	Ea5->GetYaxis()->SetRangeUser(yMin,yMax);
	
	Eb2->GetYaxis()->SetRangeUser(yMin,yMax);
	Eb3->GetYaxis()->SetRangeUser(yMin,yMax);
	Eb4->GetYaxis()->SetRangeUser(yMin,yMax);
	Eb5->GetYaxis()->SetRangeUser(yMin,yMax);
	
	R2->GetYaxis()->SetRangeUser(yMin,yMax);
	R3->GetYaxis()->SetRangeUser(yMin,yMax);
	R4->GetYaxis()->SetRangeUser(yMin,yMax);
	R5->GetYaxis()->SetRangeUser(yMin,yMax);
	
	Ra2->GetYaxis()->SetRangeUser(yMin,yMax);
	Ra3->GetYaxis()->SetRangeUser(yMin,yMax);
	Ra4->GetYaxis()->SetRangeUser(yMin,yMax);
	Ra5->GetYaxis()->SetRangeUser(yMin,yMax);
	
	
	Rb2->GetYaxis()->SetRangeUser(yMin,yMax);
	Rb3->GetYaxis()->SetRangeUser(yMin,yMax);
	Rb4->GetYaxis()->SetRangeUser(yMin,yMax);
	Rb5->GetYaxis()->SetRangeUser(yMin,yMax);
}
void setLineWidth()
{
	
	E2->SetLineWidth(2);
	E3->SetLineWidth(2);
	E4->SetLineWidth(2);
	E5->SetLineWidth(2);

	Ea2->SetLineWidth(2);
	Ea3->SetLineWidth(2);
	Ea4->SetLineWidth(2);
	Ea5->SetLineWidth(2);
	
	Eb2->SetLineWidth(2);
	Eb3->SetLineWidth(2);
	Eb4->SetLineWidth(2);
	Eb5->SetLineWidth(2);
	
	R2->SetLineWidth(2);
	R3->SetLineWidth(2);
	R4->SetLineWidth(2);
	R5->SetLineWidth(2);
	
	Ra2->SetLineWidth(2);
	Ra3->SetLineWidth(2);
	Ra4->SetLineWidth(2);
	Ra5->SetLineWidth(2);
	
	
	Rb2->SetLineWidth(2);
	Rb3->SetLineWidth(2);
	Rb4->SetLineWidth(2);
	Rb5->SetLineWidth(2);
}
void setLineStyle()
{
	
	//E2->SetLineStyle(7);
	//E3->SetLineStyle(7);
	//E4->SetLineStyle(7);
	//E5->SetLineStyle(7)
	//	;
	//Ea2->SetLineStyle(7);
	//Ea3->SetLineStyle(7);
	//Ea4->SetLineStyle(7);
	//Ea5->SetLineStyle(7);
	//
	//Eb2->SetLineStyle(7);
	//Eb3->SetLineStyle(7);
	//Eb4->SetLineStyle(7);
	//Eb5->SetLineStyle(7);
	
	R2->SetLineStyle(2);
	R3->SetLineStyle(2);
	R4->SetLineStyle(2);
	R5->SetLineStyle(2);
	
	Ra2->SetLineStyle(2);
	Ra3->SetLineStyle(2);
	Ra4->SetLineStyle(2);
	Ra5->SetLineStyle(2);
	
	
	Rb2->SetLineStyle(2);
	Rb3->SetLineStyle(2);
	Rb4->SetLineStyle(2);
	Rb5->SetLineStyle(2);
}
int TJMultiplicity()
{
	/////////////////////////////////////////////////
	//! Fetch the histograms
	////////////////////////////////////////////////
	const char *pileup = "1k";
	const char *gapsize = "30"; 
	//const char *file_path = ".";
	const char *file_path = "./fastjet_output/TriggerStudies_6";
	char signal_file_name[1023];
	
	//sprintf(signal_file_name, "%s/NewjetoutPU%shh4b_%smm_optsig5_1tracks1.5_5GeV.root",file_path,pileup,gapsize);//7.5
	sprintf(signal_file_name, "%s/TrkJPU%sggFhh4b1.2mm_%smm_43221trk2.5_2GeV_3GeV_5.root",file_path,pileup,gapsize);//7.5
	TFile *f_ = new TFile(signal_file_name, "READ");
	
	char MinBias_file_name[1023];
	//sprintf(MinBias_file_name, "%s/NewjetoutPU%sMB_%smm_optsig5_1tracks1.5_5GeV.root",file_path,pileup,gapsize);//7.5
	sprintf(MinBias_file_name, "%s/TrkJPU%sMB1.2mm_%smm_43221trk2.5_2GeV_3GeV_3.root",file_path,pileup,gapsize);//7.5
	TFile *f1_ = new TFile(MinBias_file_name, "READ");
	
	fetch_histos(f_, f1_);
	setLineWidth();
	setLineStyle();
	setRange();
	TCanvas *c = new TCanvas();	
        TH1::SetDefaultSumw2(true);

	//////////////////////////////////////////////////
	//////////////// writing to pdf //////////////////
	//////////////////////////////////////////////////
	char out_file_open[1023];
        sprintf(out_file_open,"%s/%s.pdf(",out_path,output_file_name);
        char out_file_[1023];
        sprintf(out_file_,"%s/%s.pdf",out_path,output_file_name);
        char out_file_close[1023];
        sprintf(out_file_close,"%s/%s.pdf)",out_path,output_file_name);

	int multiplicity1 = -1;
	int multiplicity2 = -1;
	float ratio = -1.0;
	Double_t x1 = 0.64, y1 = 0.71, x2 = 0.89, y2 = 0.89;
	TLegend *leg1 = new TLegend(x1, y1, x2, y2, "Integral");
	//leg1->SetFillStyle(0);
	leg1->SetBorderSize(0);
	leg1->SetTextAlign(32);
	leg1->SetTextFont(62);
	leg1->SetTextSize(0.035);
	TLegend *leg2 = new TLegend(x1, y1, x2, y2, "Integral");
	//leg2->SetFillStyle(0);
	leg2->SetBorderSize(0);
	leg2->SetTextAlign(32);
	leg2->SetTextFont(62);
	leg2->SetTextSize(0.035);
	TLegend *leg3 = new TLegend(x1, y1, x2, y2, "Integral");
	//leg3->SetFillStyle(0);
	leg3->SetBorderSize(0);
	leg3->SetTextAlign(32);
	leg3->SetTextFont(62);
	leg3->SetTextSize(0.035);
	TLegend *leg4 = new TLegend(x1, y1, x2, y2, "Integral");
	//leg4->SetFillStyle(0);
	leg4->SetBorderSize(0);
	leg4->SetTextAlign(32);
	leg4->SetTextFont(62);
	leg4->SetTextSize(0.035);
	TCanvas * C = new TCanvas();
	//TCanvas * C = new TCanvas("C","C",800,800);
	gStyle->SetOptStat(0);
	//TGaxis::SetMaxDigits(2);
	C->SetGridx();
	C->SetGridy();
	C->SetTickx();
	C->SetTicky();
	C->SetLogy();
	C->Divide(2,2);
	
	C->cd(1);
	gPad->SetGrid();
	gPad->SetLogy();
	E2->GetXaxis()->SetRangeUser(0, 40);
	E2->Draw();
	R2->Draw("same");
	multiplicity1 = integral(E2);
	multiplicity2 = integral(R2);
	ratio = (float)multiplicity1/multiplicity2;
	leg1->AddEntry(E2,Form("signal = %d",multiplicity1));
	leg1->AddEntry(R2,Form("background = %d",multiplicity2));
	leg1->AddEntry((TObject*)0,Form("ratio = %f",ratio),"");
	leg1->Draw();
	gPad->Update();

	C->cd(2);
	gPad->SetGrid();
	gPad->SetLogy();
	E3->GetXaxis()->SetRangeUser(0, 40);
	E3->Draw();
	R3->Draw("same");
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	multiplicity1 = integral(E3);
	multiplicity2 = integral(R3);
	ratio = (float)multiplicity1/multiplicity2;
	leg2->AddEntry(E3,Form("signal = %d",multiplicity1));
	leg2->AddEntry(R3,Form("background = %d",multiplicity2));
	leg2->AddEntry((TObject*)0,Form("ratio = %f",ratio),"");
	leg2->Draw();
	gPad->Update();
	C->cd(3);
	gPad->SetGrid();
	gPad->SetLogy();
	E4->GetXaxis()->SetRangeUser(0, 40);
	E4->Draw();
	R4->Draw("same");
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	multiplicity1 = integral(E4);
	multiplicity2 = integral(R4);
	ratio = (float)multiplicity1/multiplicity2;
	leg3->AddEntry(E4,Form("signal = %d",multiplicity1));
	leg3->AddEntry(R4,Form("background = %d",multiplicity2));
	leg3->AddEntry((TObject*)0,Form("ratio = %f",ratio),"");
	leg3->Draw();
	gPad->Update();
	C->cd(4);
	gPad->SetGrid();
	gPad->SetLogy();
	E5->GetXaxis()->SetRangeUser(0, 40);
	E5->Draw();
	R5->Draw("same");
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	multiplicity1 = integral(E5);
	multiplicity2 = integral(R5);
	ratio = (float)multiplicity1/multiplicity2;
	leg4->AddEntry(E5,Form("signal = %d",multiplicity1));
	leg4->AddEntry(R5,Form("background = %d",multiplicity2));
	leg4->AddEntry((TObject*)0,Form("ratio = %f",ratio),"");
	leg4->Draw();
	gPad->Update();
	C->Update();
	C->Print(out_file_open,"pdf");
	
	C->cd(1);
	gPad->SetGrid();
	gPad->SetLogy();
	Ea2->GetXaxis()->SetRangeUser(0, 40);
	Ea2->Draw();
	Ra2->Draw("same");
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	multiplicity1 = integral(Ea2);
	multiplicity2 = integral(Ra2);
	ratio = (float)multiplicity1/multiplicity2;
	leg1->Clear();
	leg1->SetHeader("Integral");
	leg1->AddEntry(Ea2,Form("signal = %d",multiplicity1));
	leg1->AddEntry(Ra2,Form("background = %d",multiplicity2));
	leg1->AddEntry((TObject*)0,Form("ratio = %f",ratio),"");
	leg1->Draw();
	gPad->Update();
	C->cd(2);
	gPad->SetGrid();
	gPad->SetLogy();
	Ea3->GetXaxis()->SetRangeUser(0, 40);
	Ea3->Draw();
	Ra3->Draw("same");
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	multiplicity1 = integral(Ea3);
	multiplicity2 = integral(Ra3);
	ratio = (float)multiplicity1/multiplicity2;
	leg2->Clear();
	leg2->SetHeader("Integral");
	leg2->AddEntry(Ea3,Form("signal = %d",multiplicity1));
	leg2->AddEntry(Ra3,Form("background = %d",multiplicity2));
	leg2->AddEntry((TObject*)0,Form("ratio = %f",ratio),"");
	leg2->Draw();
	gPad->Update();
	C->cd(3);
	gPad->SetGrid();
	gPad->SetLogy();
	Ea4->GetXaxis()->SetRangeUser(0, 40);
	Ea4->Draw();
	Ra4->Draw("same");
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	multiplicity1 = integral(Ea4);
	multiplicity2 = integral(Ra4);
	ratio = (float)multiplicity1/multiplicity2;
	leg3->Clear();
	leg3->SetHeader("Integral");
	leg3->AddEntry(Ea4,Form("signal = %d",multiplicity1));
	leg3->AddEntry(Ra4,Form("background = %d",multiplicity2));
	leg3->AddEntry((TObject*)0,Form("ratio = %f",ratio),"");
	leg3->Draw();
	gPad->Update();
	C->cd(4);
	gPad->SetGrid();
	gPad->SetLogy();
	Ea5->Draw();
	Ra5->Draw("same");
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	multiplicity1 = integral(Ea5);
	multiplicity2 = integral(Ra5);
	ratio = (float)multiplicity1/multiplicity2;
	leg4->Clear();
	leg4->SetHeader("Integral");
	leg4->AddEntry(Ea5,Form("signal = %d",multiplicity1));
	leg4->AddEntry(Ra5,Form("background = %d",multiplicity2));
	leg4->AddEntry((TObject*)0,Form("ratio = %f",ratio),"");
	leg4->Draw();
	gPad->Update();
	C->Print(out_file_,"pdf");

	C->cd(1);
	gPad->SetGrid();
	gPad->SetLogy();
	Eb2->Draw();
	Rb2->Draw("same");
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	multiplicity1 = integral(Eb2);
	multiplicity2 = integral(Rb2);
	ratio = (float)multiplicity1/multiplicity2;
	leg1->Clear();
	leg1->SetHeader("Integral");
	leg1->AddEntry(Eb2,Form("signal = %d",multiplicity1));
	leg1->AddEntry(Rb2,Form("background = %d",multiplicity2));
	leg1->AddEntry((TObject*)0,Form("ratio = %f",ratio),"");
	leg1->Draw();
	gPad->Update();
	C->cd(2);
	gPad->SetGrid();
	gPad->SetLogy();
	Eb3->Draw();
	Rb3->Draw("same");
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	multiplicity1 = integral(Eb3);
	multiplicity2 = integral(Rb3);
	ratio = (float)multiplicity1/multiplicity2;
	leg2->Clear();
	leg2->SetHeader("Integral");
	leg2->AddEntry(Eb3,Form("signal = %d",multiplicity1));
	leg2->AddEntry(Rb3,Form("background = %d",multiplicity2));
	leg2->AddEntry((TObject*)0,Form("ratio = %f",ratio),"");
	leg2->Draw();
	gPad->Update();
	C->cd(3);
	gPad->SetGrid();
	gPad->SetLogy();
	Eb4->Draw();
	Rb4->Draw("same");
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	multiplicity1 = integral(Eb4);
	multiplicity2 = integral(Rb4);
	ratio = (float)multiplicity1/multiplicity2;
	leg3->Clear();
	leg3->SetHeader("Integral");
	leg3->AddEntry(Eb4,Form("signal = %d",multiplicity1));
	leg3->AddEntry(Rb4,Form("background = %d",multiplicity2));
	leg3->AddEntry((TObject*)0,Form("ratio = %f",ratio),"");
	leg3->Draw();
	gPad->Update();
	C->cd(4);
	gPad->SetGrid();
	gPad->SetLogy();
	Eb5->Draw();
	Rb5->Draw("same");
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	multiplicity1 = integral(Eb5);
	multiplicity2 = integral(Rb5);
	ratio = (float)multiplicity1/multiplicity2;
	leg4->Clear();
	leg4->SetHeader("Integral");
	leg4->AddEntry(Eb5,Form("signal = %d",multiplicity1));
	leg4->AddEntry(Rb5,Form("background = %d",multiplicity2));
	leg4->AddEntry((TObject*)0,Form("ratio = %f",ratio),"");
	leg4->Draw();
	gPad->Update();
	C->Print(out_file_close,"pdf");
return 0;
}
