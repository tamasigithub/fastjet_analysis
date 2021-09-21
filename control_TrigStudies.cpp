#include "control_TrigStudies.h"
#include "plot_props.h"
#include "control_INIT1.cpp"
#include "control_INIT2.cpp"
#include "control_ConstpT.cpp"
#include "control_Fill_1.cpp"
#include "control_Fill_2.cpp"
#include "control_Mult.cpp"
TH2F *htemp = nullptr;
void LegEFF()
{
	Leff->SetBorderSize(0);
	Leff->SetTextSize(0.05);
	Leff->SetFillStyle(0);
	return;
}
void HtempProps()
{
	htemp->GetXaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	htemp->GetXaxis()->SetTitleSize(TEXT_SIZE);
	htemp->GetYaxis()->SetTitleSize(TEXT_SIZE);
	htemp->GetXaxis()->SetLabelSize(0.04);
	htemp->GetYaxis()->SetLabelSize(0.04);
	htemp->GetXaxis()->SetTitle("PB^{truth}");
	htemp->GetXaxis()->CenterTitle();
	htemp->GetYaxis()->CenterTitle();
	return;
}
void SetPadProps()
{
	gPad->SetLeftMargin(LEFTMARGIN);
	gPad->SetBottomMargin(BOTTOMMARGIN);
	gPad->SetTopMargin(TOPMARGIN);
	gPad->SetRightMargin(RIGHTMARGIN);
	gPad->SetFillColor(0);
	gPad->SetBorderMode(1);
	return;
}

void plot()
{
	bool debug = false;
	//bool debug = true;
	INIT_1();
	INIT_2();
	int nentries1 = t1->GetEntries();
	int nentries2 = t2->GetEntries();
	std::cout<<"File1 opened with " << nentries1 << " entries." <<std::endl;
	std::cout<<"File2 opened with " << nentries2 << " entries." <<std::endl;
	if(debug) 
	{
		nentries1 = 10; 
		nentries2 = 10; 
	}
	assert(nentries1 = nentries2);
	TEXT_SIZE = 0.06;
	INIT_MULT();
	MULT_LINEprops();
	TEXT_SIZE = 0.05;
	INIT_CONSTpT();
	CONSTpT_LINEprops();

	for(int i = 0; i < nentries1; ++i)
	{
		t1->GetEntry(i);
		FILL_2D_1L_1();
		FILL_2D_2L_1();
		FILL_2D_3L_1();
		FILL_2D_4L_1();
		FILL_2D_5L_1();
		FILL_2D_1La_1();
		FILL_2D_2La_1();
		FILL_2D_3La_1();
		FILL_2D_4La_1();
		FILL_2D_5La_1();
		
		t2->GetEntry(i);
		FILL_2D_1L_2();
		FILL_2D_2L_2();
		FILL_2D_3L_2();
		FILL_2D_4L_2();
		FILL_2D_5L_2();
		FILL_2D_1La_2();
		FILL_2D_2La_2();
		FILL_2D_3La_2();
		FILL_2D_4La_2();
		FILL_2D_5La_2();
		

	}
	CONSTpT_SETYrange();

///////////////////////////////////////////////////////////////////////
//////////////// writing to pdf ///////////////////////////////////////
///////////////////////////////////////////////////////////////////////
	char out_file_open[1023];
        sprintf(out_file_open,"%s/%s.pdf(",out_path,output_file_name);
        char out_file_[1023];
        sprintf(out_file_,"%s/%s.pdf",out_path,output_file_name);
        char out_file_close[1023];
        sprintf(out_file_close,"%s/%s.pdf)",out_path,output_file_name);
	
	char out_root_file[1023];
	sprintf(out_root_file, "%s/%s.root",out_path,output_file_name);
	
	
	TLegend *rank = new TLegend(0.6, 0.87, 0.97, 0.97);
	rank->SetFillStyle(0);
	rank->SetBorderSize(0);
	rank->SetTextSize(0.05);
	rank->AddEntry((TObject*)0,"max-bin, leading jet","");
	
	TLegend *SGBG_1 = new TLegend (0.75, 0.77, 0.97, 0.87);
	SGBG_1->SetFillStyle(0);
	SGBG_1->SetBorderSize(0);
	SGBG_1->SetTextSize(0.05);
	SGBG_1->AddEntry(BG_2L1C,"Min Bias");
	SGBG_1->AddEntry(SG_2L1C,"HH #rightarrow 4b");

	//TCanvas *c = new TCanvas("c","c",595,842);//A4 size
	//TCanvas *c = new TCanvas("c","c",600,842);
	TCanvas *c = new TCanvas("c","c",800,800);
	//TCanvas *c = new TCanvas();
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);
	TGaxis::SetMaxDigits(3);
	BOTTOMMARGIN = 0.15;
	RIGHTMARGIN = 0.03;
	LEFTMARGIN = 0.1;
	c->Clear();
	c->SetRightMargin(0.);
	c->SetLeftMargin(0.);
	c->SetTopMargin(0.);
	c->SetBottomMargin(0.);
	c->SetTicks(1,1);
	c->SetFillColor(0);
	c->SetHighLightColor(0);
	c->Divide(2,5,0,0);
	//!page1
	c->cd(1);
	SetPadProps();
	M_BG1->GetXaxis()->SetRangeUser(0,25);
	t1->Draw("M_1L>>M_SG1");
	t2->Draw("M_1L>>M_BG1");
	M_BG1->Draw("");
	M_SG1->Draw("same");
	SGBG_1->Draw();
	rank->Draw();

	c->cd(3);
	SetPadProps();
	t1->Draw("M_2L>>M_SG2");
	t2->Draw("M_2L>>M_BG2");
	M_BG2->GetXaxis()->SetRangeUser(0,20);
	M_BG2->Draw();
	M_SG2->Draw("same");
	SGBG_1->Draw();
	rank = new TLegend(0.6, 0.87, 0.97, 0.97);
	rank->SetFillStyle(0);
	rank->SetBorderSize(0);
	rank->SetTextSize(0.05);
	rank->AddEntry((TObject*)0,"max-bin, 2^{nd} leading jet", "");
	rank->Draw();
	
	c->cd(5);
	SetPadProps();
	t1->Draw("M_3L>>M_SG3");
	t2->Draw("M_3L>>M_BG3");
	M_BG3->GetXaxis()->SetRangeUser(0,15);
	M_BG3->Draw();
	M_SG3->Draw("same");
	SGBG_1->Draw();
	rank = new TLegend(0.6, 0.87, 0.97, 0.97);
	rank->SetFillStyle(0);
	rank->SetBorderSize(0);
	rank->SetTextSize(0.05);
	rank->AddEntry((TObject*)0,"max-bin, 3^{rd} leading jet", "");
	rank->Draw();

	c->cd(7);
	SetPadProps();
	t1->Draw("M_4L>>M_SG4");
	t2->Draw("M_4L>>M_BG4");
	M_BG4->GetXaxis()->SetRangeUser(0,15);
	M_BG4->Draw();
	M_SG4->Draw("same");
	SGBG_1->Draw();
	rank = new TLegend(0.6, 0.87, 0.97, 0.97);
	rank->SetFillStyle(0);
	rank->SetBorderSize(0);
	rank->SetTextSize(0.05);
	rank->AddEntry((TObject*)0,"max-bin, 4^{th} leading jet", "");
	rank->Draw();

	c->cd(9);
	SetPadProps();
	t1->Draw("M_5L>>M_SG5");
	t2->Draw("M_5L>>M_BG5");
	M_BG5->GetXaxis()->SetRangeUser(0,10);
	M_BG5->Draw();
	M_SG5->Draw("same");
	SGBG_1->Draw();
	rank = new TLegend(0.6, 0.87, 0.97, 0.97);
	rank->SetFillStyle(0);
	rank->SetBorderSize(0);
	rank->SetTextSize(0.05);
	rank->AddEntry((TObject*)0,"max-bin, 5^{th} leading jet", "");
	rank->Draw();
	
	c->cd(2);
	SetPadProps();
	t1->Draw("Ma_1L>>M_SGa1");
	t2->Draw("Ma_1L>>M_BGa1");
	M_BGa1->GetXaxis()->SetRangeUser(0,25);
	M_BGa1->Draw();
	M_SGa1->Draw("same");
	SGBG_1->Draw();
	rank = new TLegend(0.6, 0.87, 0.97, 0.97);
	rank->SetFillStyle(0);
	rank->SetBorderSize(0);
	rank->SetTextSize(0.05);
	rank->AddEntry((TObject*)0,"multi-bin, leading jet", "");
	rank->Draw();

	c->cd(4);
	SetPadProps();
	t1->Draw("Ma_2L>>M_SGa2");
	t2->Draw("Ma_2L>>M_BGa2");
	M_BGa2->GetXaxis()->SetRangeUser(0,20);
	M_BGa2->Draw();
	M_SGa2->Draw("same");
	SGBG_1->Draw();
	rank = new TLegend(0.6, 0.87, 0.97, 0.97);
	rank->SetFillStyle(0);
	rank->SetBorderSize(0);
	rank->SetTextSize(0.05);
	rank->AddEntry((TObject*)0,"multi-bin, 2^{nd} leading jet", "");
	rank->Draw();
	
	c->cd(6);
	SetPadProps();
	t1->Draw("Ma_3L>>M_SGa3");
	t2->Draw("Ma_3L>>M_BGa3");
	M_BGa3->GetXaxis()->SetRangeUser(0,15);
	M_BGa3->Draw();
	M_SGa3->Draw("same");
	SGBG_1->Draw();
	rank = new TLegend(0.6, 0.87, 0.97, 0.97);
	rank->SetFillStyle(0);
	rank->SetBorderSize(0);
	rank->SetTextSize(0.05);
	rank->AddEntry((TObject*)0,"multi-bin, 3^{rd} leading jet", "");
	rank->Draw();

	c->cd(8);
	SetPadProps();
	t1->Draw("Ma_4L>>M_SGa4");
	t2->Draw("Ma_4L>>M_BGa4");
	M_BGa4->GetXaxis()->SetRangeUser(0,15);
	M_BGa4->Draw();
	M_SGa4->Draw("same");
	SGBG_1->Draw();
	rank = new TLegend(0.6, 0.87, 0.97, 0.97);
	rank->SetFillStyle(0);
	rank->SetBorderSize(0);
	rank->SetTextSize(0.05);
	rank->AddEntry((TObject*)0,"multi-bin, 4^{th} leading jet", "");
	rank->Draw();

	c->cd(10);
	SetPadProps();
	t1->Draw("Ma_5L>>M_SGa5");
	t2->Draw("Ma_5L>>M_BGa5");
	M_BGa5->GetXaxis()->SetRangeUser(0,10);
	M_BGa5->Draw();
	M_SGa5->Draw("same");
	SGBG_1->Draw();
	rank = new TLegend(0.6, 0.87, 0.97, 0.97);
	rank->SetFillStyle(0);
	rank->SetBorderSize(0);
	rank->SetTextSize(0.05);
	rank->AddEntry((TObject*)0,"multi-bin, 5^{th} leading jet", "");
	rank->Draw();
	c->Print(out_file_open, "pdf");
	c->SaveAs("./summary_plots/tex/control1.tex");
	
	//!page2
	c->Clear();
	c->Divide(2,5);
	c->cd(1);
	M_BG1->Draw("");
	M_SG1->Draw("same");
	gPad->SetLogy();

	c->cd(3);
	gPad->SetLogy();
	M_BG2->Draw();
	M_SG2->Draw("same");
	
	c->cd(5);
	gPad->SetLogy();
	M_BG3->Draw();
	M_SG3->Draw("same");

	c->cd(7);
	gPad->SetLogy();
	M_BG4->Draw();
	M_SG4->Draw("same");

	c->cd(9);
	gPad->SetLogy();
	M_BG5->Draw();
	M_SG5->Draw("same");
	
	c->cd(2);
	gPad->SetLogy();
	M_BGa1->Draw();
	M_SGa1->Draw("same");

	c->cd(4);
	gPad->SetLogy();
	M_BGa2->Draw();
	M_SGa2->Draw("same");
	
	c->cd(6);
	gPad->SetLogy();
	M_BGa3->Draw();
	M_SGa3->Draw("same");

	c->cd(8);
	gPad->SetLogy();
	M_BGa4->Draw();
	M_SGa4->Draw("same");

	c->cd(10);
	gPad->SetLogy();
	M_BGa5->Draw();
	M_SGa5->Draw("same");
	c->Print(out_file_, "pdf");

	//!page3
	c->Clear();
	c->Divide(2,4);
	c->cd(1);
	BG_1L1C->Draw("");
	SG_1L1C->Draw("same");
	gPad->SetLogy();

	c->cd(3);
	gPad->SetLogy();
	BG_1L2C->Draw();
	SG_1L2C->Draw("same");
	
	c->cd(5);
	gPad->SetLogy();
	BG_1L3C->Draw();
	SG_1L3C->Draw("same");

	c->cd(7);
	gPad->SetLogy();
	BG_1L4C->Draw();
	SG_1L4C->Draw("same");

	c->cd(2);
	gPad->SetLogy();
	BGa_1L1C->Draw();
	SGa_1L1C->Draw("same");

	c->cd(4);
	gPad->SetLogy();
	BGa_1L2C->Draw();
	SGa_1L2C->Draw("same");
	
	c->cd(6);
	gPad->SetLogy();
	BGa_1L3C->Draw();
	SGa_1L3C->Draw("same");

	c->cd(8);
	gPad->SetLogy();
	BGa_1L4C->Draw();
	SGa_1L4C->Draw("same");

	c->Print(out_file_, "pdf");
	
	//!page4
	c->Clear();
	c->Divide(2,4);
	c->cd(1);
	BG_2L1C->Draw("");
	SG_2L1C->Draw("same");
	gPad->SetLogy();

	c->cd(3);
	gPad->SetLogy();
	BG_2L2C->Draw();
	SG_2L2C->Draw("same");
	
	c->cd(5);
	gPad->SetLogy();
	BG_2L3C->Draw();
	SG_2L3C->Draw("same");

	c->cd(7);
	gPad->SetLogy();
	BG_2L4C->Draw();
	SG_2L4C->Draw("same");

	c->cd(2);
	gPad->SetLogy();
	BGa_2L1C->Draw();
	SGa_2L1C->Draw("same");

	c->cd(4);
	gPad->SetLogy();
	BGa_2L2C->Draw();
	SGa_2L2C->Draw("same");
	
	c->cd(6);
	gPad->SetLogy();
	BGa_2L3C->Draw();
	SGa_2L3C->Draw("same");

	c->cd(8);
	gPad->SetLogy();
	BGa_2L4C->Draw();
	SGa_2L4C->Draw("same");

	c->Print(out_file_, "pdf");

	//!page5
	c->Clear();
	c->Divide(2,4);
	c->cd(1);
	BG_3L1C->Draw("");
	SG_3L1C->Draw("same");
	gPad->SetLogy();

	c->cd(3);
	gPad->SetLogy();
	BG_3L2C->Draw();
	SG_3L2C->Draw("same");
	
	c->cd(5);
	gPad->SetLogy();
	BG_3L3C->Draw();
	SG_3L3C->Draw("same");

	c->cd(7);
	gPad->SetLogy();
	BG_3L4C->Draw();
	SG_3L4C->Draw("same");

	c->cd(2);
	gPad->SetLogy();
	BGa_3L1C->Draw();
	SGa_3L1C->Draw("same");

	c->cd(4);
	gPad->SetLogy();
	BGa_3L2C->Draw();
	SGa_3L2C->Draw("same");
	
	c->cd(6);
	gPad->SetLogy();
	BGa_3L3C->Draw();
	SGa_3L3C->Draw("same");

	c->cd(8);
	gPad->SetLogy();
	BGa_3L4C->Draw();
	SGa_3L4C->Draw("same");

	c->Print(out_file_, "pdf");

	//!page6
	c->Clear();
	c->Divide(2,4);
	c->cd(1);
	BG_4L1C->Draw("");
	SG_4L1C->Draw("same");
	gPad->SetLogy();

	c->cd(3);
	gPad->SetLogy();
	BG_4L2C->Draw();
	SG_4L2C->Draw("same");
	
	c->cd(5);
	gPad->SetLogy();
	BG_4L3C->Draw();
	SG_4L3C->Draw("same");

	c->cd(7);
	gPad->SetLogy();
	BG_4L4C->Draw();
	SG_4L4C->Draw("same");

	c->cd(2);
	gPad->SetLogy();
	BGa_4L1C->Draw();
	SGa_4L1C->Draw("same");

	c->cd(4);
	gPad->SetLogy();
	BGa_4L2C->Draw();
	SGa_4L2C->Draw("same");
	
	c->cd(6);
	gPad->SetLogy();
	BGa_4L3C->Draw();
	SGa_4L3C->Draw("same");

	c->cd(8);
	gPad->SetLogy();
	BGa_4L4C->Draw();
	SGa_4L4C->Draw("same");

	c->Print(out_file_, "pdf");

	//!page7
	c->Clear();
	c->Divide(2,4);
	c->cd(1);
	BG_5L1C->Draw("");
	SG_5L1C->Draw("same");
	gPad->SetLogy();

	c->cd(3);
	gPad->SetLogy();
	BG_5L2C->Draw();
	SG_5L2C->Draw("same");
	
	c->cd(5);
	gPad->SetLogy();
	BG_5L3C->Draw();
	SG_5L3C->Draw("same");

	c->cd(7);
	gPad->SetLogy();
	BG_5L4C->Draw();
	SG_5L4C->Draw("same");

	c->cd(2);
	gPad->SetLogy();
	BGa_5L1C->Draw();
	SGa_5L1C->Draw("same");

	c->cd(4);
	gPad->SetLogy();
	BGa_5L2C->Draw();
	SGa_5L2C->Draw("same");
	
	c->cd(6);
	gPad->SetLogy();
	BGa_5L3C->Draw();
	SGa_5L3C->Draw("same");

	c->cd(8);
	gPad->SetLogy();
	BGa_5L4C->Draw();
	SGa_5L4C->Draw("same");

	c->Print(out_file_, "pdf");
	
	BG_1L1C->GetXaxis()->SetRangeUser(2,20);
	BG_1L2C->GetXaxis()->SetRangeUser(2,20);
	BG_1L3C->GetXaxis()->SetRangeUser(2,20);
	BG_1L4C->GetXaxis()->SetRangeUser(2,20);

	BG_2L1C->GetXaxis()->SetRangeUser(2,20);
	BG_2L2C->GetXaxis()->SetRangeUser(2,20);
	BG_2L3C->GetXaxis()->SetRangeUser(2,20);
	BG_2L4C->GetXaxis()->SetRangeUser(2,20);

	BG_3L1C->GetXaxis()->SetRangeUser(2,20);
	BG_3L2C->GetXaxis()->SetRangeUser(2,20);
	BG_3L3C->GetXaxis()->SetRangeUser(2,20);
	BG_3L4C->GetXaxis()->SetRangeUser(2,20);

	BG_4L1C->GetXaxis()->SetRangeUser(2,20);
	BG_4L2C->GetXaxis()->SetRangeUser(2,20);
	BG_4L3C->GetXaxis()->SetRangeUser(2,20);
	BG_4L4C->GetXaxis()->SetRangeUser(2,20);

	BG_5L1C->GetXaxis()->SetRangeUser(2,20);
	BG_5L2C->GetXaxis()->SetRangeUser(2,20);
	BG_5L3C->GetXaxis()->SetRangeUser(2,20);
	BG_5L4C->GetXaxis()->SetRangeUser(2,20);
	
	BGa_1L1C->GetXaxis()->SetRangeUser(2,20);
	BGa_1L2C->GetXaxis()->SetRangeUser(2,20);
	BGa_1L3C->GetXaxis()->SetRangeUser(2,20);
	BGa_1L4C->GetXaxis()->SetRangeUser(2,20);

	BGa_2L1C->GetXaxis()->SetRangeUser(2,20);
	BGa_2L2C->GetXaxis()->SetRangeUser(2,20);
	BGa_2L3C->GetXaxis()->SetRangeUser(2,20);
	BGa_2L4C->GetXaxis()->SetRangeUser(2,20);

	BGa_3L1C->GetXaxis()->SetRangeUser(2,20);
	BGa_3L2C->GetXaxis()->SetRangeUser(2,20);
	BGa_3L3C->GetXaxis()->SetRangeUser(2,20);
	BGa_3L4C->GetXaxis()->SetRangeUser(2,20);

	BGa_4L1C->GetXaxis()->SetRangeUser(2,20);
	BGa_4L2C->GetXaxis()->SetRangeUser(2,20);
	BGa_4L3C->GetXaxis()->SetRangeUser(2,20);
	BGa_4L4C->GetXaxis()->SetRangeUser(2,20);

	BGa_5L1C->GetXaxis()->SetRangeUser(2,20);
	BGa_5L2C->GetXaxis()->SetRangeUser(2,20);
	BGa_5L3C->GetXaxis()->SetRangeUser(2,20);
	BGa_5L4C->GetXaxis()->SetRangeUser(2,20);
	//!page8
	c->Clear();
	c->Divide(2,4);
	c->cd(1);
	BG_1L1C->Draw("");
	SG_1L1C->Draw("same");
	gPad->SetLogy();

	c->cd(3);
	gPad->SetLogy();
	BG_1L2C->Draw();
	SG_1L2C->Draw("same");
	
	c->cd(5);
	gPad->SetLogy();
	BG_1L3C->Draw();
	SG_1L3C->Draw("same");

	c->cd(7);
	gPad->SetLogy();
	BG_1L4C->Draw();
	SG_1L4C->Draw("same");

	c->cd(2);
	gPad->SetLogy();
	BGa_1L1C->Draw();
	SGa_1L1C->Draw("same");

	c->cd(4);
	gPad->SetLogy();
	BGa_1L2C->Draw();
	SGa_1L2C->Draw("same");
	
	c->cd(6);
	gPad->SetLogy();
	BGa_1L3C->Draw();
	SGa_1L3C->Draw("same");

	c->cd(8);
	gPad->SetLogy();
	BGa_1L4C->Draw();
	SGa_1L4C->Draw("same");

	c->Print(out_file_, "pdf");
	
	//!page9
	c->Clear();
	c->Divide(2,4);
	c->cd(1);
	BG_2L1C->Draw("");
	SG_2L1C->Draw("same");
	gPad->SetLogy();

	c->cd(3);
	gPad->SetLogy();
	BG_2L2C->Draw();
	SG_2L2C->Draw("same");
	
	c->cd(5);
	gPad->SetLogy();
	BG_2L3C->Draw();
	SG_2L3C->Draw("same");

	c->cd(7);
	gPad->SetLogy();
	BG_2L4C->Draw();
	SG_2L4C->Draw("same");

	c->cd(2);
	gPad->SetLogy();
	BGa_2L1C->Draw();
	SGa_2L1C->Draw("same");

	c->cd(4);
	gPad->SetLogy();
	BGa_2L2C->Draw();
	SGa_2L2C->Draw("same");
	
	c->cd(6);
	gPad->SetLogy();
	BGa_2L3C->Draw();
	SGa_2L3C->Draw("same");

	c->cd(8);
	gPad->SetLogy();
	BGa_2L4C->Draw();
	SGa_2L4C->Draw("same");

	c->Print(out_file_, "pdf");

	//!page10
	c->Clear();
	c->Divide(2,4);
	c->cd(1);
	BG_3L1C->Draw("");
	SG_3L1C->Draw("same");
	gPad->SetLogy();

	c->cd(3);
	gPad->SetLogy();
	BG_3L2C->Draw();
	SG_3L2C->Draw("same");
	
	c->cd(5);
	gPad->SetLogy();
	BG_3L3C->Draw();
	SG_3L3C->Draw("same");

	c->cd(7);
	gPad->SetLogy();
	BG_3L4C->Draw();
	SG_3L4C->Draw("same");

	c->cd(2);
	gPad->SetLogy();
	BGa_3L1C->Draw();
	SGa_3L1C->Draw("same");

	c->cd(4);
	gPad->SetLogy();
	BGa_3L2C->Draw();
	SGa_3L2C->Draw("same");
	
	c->cd(6);
	gPad->SetLogy();
	BGa_3L3C->Draw();
	SGa_3L3C->Draw("same");

	c->cd(8);
	gPad->SetLogy();
	BGa_3L4C->Draw();
	SGa_3L4C->Draw("same");

	c->Print(out_file_, "pdf");

	//!page11
	c->Clear();
	c->Divide(2,4);
	c->cd(1);
	BG_4L1C->Draw("");
	SG_4L1C->Draw("same");
	gPad->SetLogy();

	c->cd(3);
	gPad->SetLogy();
	BG_4L2C->Draw();
	SG_4L2C->Draw("same");
	
	c->cd(5);
	gPad->SetLogy();
	BG_4L3C->Draw();
	SG_4L3C->Draw("same");

	c->cd(7);
	gPad->SetLogy();
	BG_4L4C->Draw();
	SG_4L4C->Draw("same");

	c->cd(2);
	gPad->SetLogy();
	BGa_4L1C->Draw();
	SGa_4L1C->Draw("same");

	c->cd(4);
	gPad->SetLogy();
	BGa_4L2C->Draw();
	SGa_4L2C->Draw("same");
	
	c->cd(6);
	gPad->SetLogy();
	BGa_4L3C->Draw();
	SGa_4L3C->Draw("same");

	c->cd(8);
	gPad->SetLogy();
	BGa_4L4C->Draw();
	SGa_4L4C->Draw("same");

	c->Print(out_file_, "pdf");

	//!page12
	c->Clear();
	c->Divide(2,4);
	c->cd(1);
	BG_5L1C->Draw("");
	SG_5L1C->Draw("same");
	gPad->SetLogy();

	c->cd(3);
	gPad->SetLogy();
	BG_5L2C->Draw();
	SG_5L2C->Draw("same");
	
	c->cd(5);
	gPad->SetLogy();
	BG_5L3C->Draw();
	SG_5L3C->Draw("same");

	c->cd(7);
	gPad->SetLogy();
	BG_5L4C->Draw();
	SG_5L4C->Draw("same");

	c->cd(2);
	gPad->SetLogy();
	BGa_5L1C->Draw();
	SGa_5L1C->Draw("same");

	c->cd(4);
	gPad->SetLogy();
	BGa_5L2C->Draw();
	SGa_5L2C->Draw("same");
	
	c->cd(6);
	gPad->SetLogy();
	BGa_5L3C->Draw();
	SGa_5L3C->Draw("same");

	c->cd(8);
	gPad->SetLogy();
	BGa_5L4C->Draw();
	SGa_5L4C->Draw("same");

	c->Print(out_file_, "pdf");
	
	//! page13
	c->Clear();
	c->Divide(2,2);
	c->cd(1);
	gPad->SetLogy();
	h_1L1C->Draw("colz");
	c->cd(2);
	gPad->SetLogy();
	h_1L2C->Draw("colz");
	c->cd(3);
	gPad->SetLogy();
	h_1L3C->Draw("colz");
	c->cd(4);
	gPad->SetLogy();
	h_1L4C->Draw("colz");
	c->Print(out_file_, "pdf");
	//! page14
	c->cd(1);
	hBG_1L1C->Draw("colz");
	c->cd(2);
	hBG_1L2C->Draw("colz");
	c->cd(3);
	hBG_1L3C->Draw("colz");
	c->cd(4);
	hBG_1L4C->Draw("colz");
	c->Print(out_file_, "pdf");
	//! page15
	c->cd(1);
	h_2L1C->Draw("colz");
	c->cd(2);
	h_2L2C->Draw("colz");
	c->cd(3);
	h_2L3C->Draw("colz");
	c->cd(4);
	h_2L4C->Draw("colz");
	c->Print(out_file_, "pdf");
	//! page16
	c->cd(1);
	hBG_2L1C->Draw("colz");
	c->cd(2);
	hBG_2L2C->Draw("colz");
	c->cd(3);
	hBG_2L3C->Draw("colz");
	c->cd(4);
	hBG_2L4C->Draw("colz");
	c->Print(out_file_, "pdf");
	//! page17
	c->cd(1);
	h_3L1C->Draw("colz");
	c->cd(2);
	h_3L2C->Draw("colz");
	c->cd(3);
	h_3L3C->Draw("colz");
	c->cd(4);
	h_3L4C->Draw("colz");
	c->Print(out_file_, "pdf");
	//! page18
	c->cd(1);
	hBG_3L1C->Draw("colz");
	c->cd(2);
	hBG_3L2C->Draw("colz");
	c->cd(3);
	hBG_3L3C->Draw("colz");
	c->cd(4);
	hBG_3L4C->Draw("colz");
	c->Print(out_file_, "pdf");

	//! page19
	c->cd(1);
	h_4L1C->Draw("colz");
	c->cd(2);
	h_4L2C->Draw("colz");
	c->cd(3);
	h_4L3C->Draw("colz");
	c->cd(4);
	h_4L4C->Draw("colz");
	c->Print(out_file_, "pdf");
	//! page20
	c->cd(1);
	hBG_4L1C->Draw("colz");
	c->cd(2);
	hBG_4L2C->Draw("colz");
	c->cd(3);
	hBG_4L3C->Draw("colz");
	c->cd(4);
	hBG_4L4C->Draw("colz");
	c->Print(out_file_, "pdf");

	//! page21
	c->cd(1);
	h_5L1C->Draw("colz");
	c->cd(2);
	h_5L2C->Draw("colz");
	c->cd(3);
	h_5L3C->Draw("colz");
	c->cd(4);
	h_5L4C->Draw("colz");
	c->Print(out_file_, "pdf");
	//! page22
	c->cd(1);
	hBG_5L1C->Draw("colz");
	c->cd(2);
	hBG_5L2C->Draw("colz");
	c->cd(3);
	hBG_5L3C->Draw("colz");
	c->cd(4);
	hBG_5L4C->Draw("colz");
	c->Print(out_file_, "pdf");

	LEFTMARGIN = 0.14;
	BOTTOMMARGIN = 0.13;
	RIGHTMARGIN = 0.12;
	//! page23
	c->Clear();
	c->SetRightMargin(0.);
	c->SetLeftMargin(0.);
	c->SetTopMargin(0.);
	c->SetBottomMargin(0.);
	c->SetTicks(1,1);
	c->SetFillColor(0);
	c->SetHighLightColor(0);
	c->Divide(2,3, 0, 0);
	c->cd(1);
	SetPadProps();
	Float_t num = 0, den = 0, eff = 0;
	num = t1->Draw("PB_maxbin:PB_tru",selectMax,"colz");
	den = t1->Draw("PB_maxbin:PB_tru","","colz");
	htemp = (TH2F*)gPad->GetPrimitive("htemp");
	htemp->GetYaxis()->SetTitle("PB^{max-bin}");
	HtempProps();
	eff = num/den * 100;
	Leff = new TLegend (X1, Y1, X2, Y2);
	LegEFF();
	Leff->AddEntry((TObject*)0, Form("#epsilon = %.2f %%",eff),"");
	Leff->Draw();
	std::cout<<"num, den, eff: " << num << " , " << den << " , " << eff <<std::endl; 
	
	c->cd(2);
	SetPadProps();
	num = t1->Draw("PB1_multibin:PB_tru",selectMulti1,"colz");
	den = t1->Draw("PB1_multibin:PB_tru","","colz");
	htemp = (TH2F*)gPad->GetPrimitive("htemp");
	htemp->GetYaxis()->SetTitle("PB^{multi-bin}_{j_{1}}");
	HtempProps();
	eff = num/den * 100;
	Leff = new TLegend (X1, Y1, X2, Y2);
	LegEFF();
	Leff->AddEntry((TObject*)0, Form("#epsilon = %.2f %%",eff),"");
	Leff->Draw();
	std::cout<<"num, den, eff: " << num << " , " << den << " , " << eff <<std::endl; 
	
	c->cd(3);
	SetPadProps();
	num = t1->Draw("PB2_multibin:PB_tru",selectMulti2,"colz");
	den = t1->Draw("PB2_multibin:PB_tru","","colz");
	htemp = (TH2F*)gPad->GetPrimitive("htemp");
	htemp->GetYaxis()->SetTitle("PB^{multi-bin}_{j_{2}}");
	HtempProps();
	eff = num/den * 100;
	Leff = new TLegend (X1, Y1, X2, Y2);
	LegEFF();
	Leff->AddEntry((TObject*)0, Form("#epsilon = %.2f %%",eff),"");
	Leff->Draw();
	std::cout<<"num, den, eff: " << num << " , " << den << " , " << eff <<std::endl; 
	
	c->cd(4);
	SetPadProps();
	num = t1->Draw("PB3_multibin:PB_tru",selectMulti3,"colz");
	den = t1->Draw("PB3_multibin:PB_tru","","colz");
	htemp = (TH2F*)gPad->GetPrimitive("htemp");
	htemp->GetYaxis()->SetTitle("PB^{multi-bin}_{j_{3}}");
	HtempProps();
	eff = num/den * 100;
	Leff = new TLegend (X1, Y1, X2, Y2);
	LegEFF();
	Leff->AddEntry((TObject*)0, Form("#epsilon = %.2f %%",eff),"");
	Leff->Draw();
	std::cout<<"num, den, eff: " << num << " , " << den << " , " << eff <<std::endl; 
	
	c->cd(5);
	SetPadProps();
	num = t1->Draw("PB4_multibin:PB_tru",selectMulti4,"colz");
	den = t1->Draw("PB4_multibin:PB_tru","","colz");
	htemp = (TH2F*)gPad->GetPrimitive("htemp");
	htemp->GetYaxis()->SetTitle("PB^{multi-bin}_{j_{4}}");
	HtempProps();
	eff = num/den * 100;
	Leff = new TLegend (X1, Y1, X2, Y2);
	LegEFF();
	Leff->AddEntry((TObject*)0, Form("#epsilon = %.2f %%",eff),"");
	Leff->Draw();
	gPad->Update();
	std::cout<<"num, den, eff: " << num << " , " << den << " , " << eff <<std::endl; 
	
	c->cd(6);
	SetPadProps();
	num = t1->Draw("PB5_multibin:PB_tru",selectMulti5,"colz");
	den = t1->Draw("PB5_multibin:PB_tru","","colz");
	htemp = (TH2F*)gPad->GetPrimitive("htemp");
	htemp->GetYaxis()->SetTitle("PB^{multi-bin}_{j_{5}}");
	HtempProps();
	eff = num/den * 100;
	Leff = new TLegend (X1, Y1, X2, Y2);
	LegEFF();
	Leff->AddEntry((TObject*)0, Form("#epsilon = %.2f %%",eff),"");
	Leff->Draw();
	gPad->Update();
	std::cout<<"num, den, eff: " << num << " , " << den << " , " << eff <<std::endl; 
	
	c->Print(out_file_, "pdf");
	c->SaveAs("./summary_plots/tex/control23.tex");
	//! page24
	c->Clear();
	c->SetRightMargin(0.);
	c->SetLeftMargin(0.);
	c->SetTopMargin(0.);
	c->SetBottomMargin(0.);
	c->SetTicks(1,1);
	c->SetFillColor(0);
	c->SetHighLightColor(0);
	c->Divide(2,3, 0, 0);
	c->cd(1);
	SetPadProps();
	t2->Draw("PB_maxbin:PB_tru","","colz");
	htemp = (TH2F*)gPad->GetPrimitive("htemp");
	htemp->GetYaxis()->SetTitle("PB^{max-bin}");
	HtempProps();
	c->cd(2);
	SetPadProps();
	t2->Draw("PB1_multibin:PB_tru","","colz");
	htemp = (TH2F*)gPad->GetPrimitive("htemp");
	htemp->GetYaxis()->SetTitle("PB^{multi-bin}_{j_{1}}");
	HtempProps();
	c->cd(3);
	SetPadProps();
	t2->Draw("PB2_multibin:PB_tru","","colz");
	htemp = (TH2F*)gPad->GetPrimitive("htemp");
	htemp->GetYaxis()->SetTitle("PB^{multi-bin}_{j_{2}}");
	HtempProps();
	c->cd(4);
	SetPadProps();
	t2->Draw("PB3_multibin:PB_tru","","colz");
	htemp = (TH2F*)gPad->GetPrimitive("htemp");
	htemp->GetYaxis()->SetTitle("PB^{multi-bin}_{j_{3}}");
	HtempProps();
	c->cd(5);
	SetPadProps();
	t2->Draw("PB4_multibin:PB_tru","","colz");
	htemp = (TH2F*)gPad->GetPrimitive("htemp");
	htemp->GetYaxis()->SetTitle("PB^{multi-bin}_{j_{4}}");
	HtempProps();
	c->cd(6);
	SetPadProps();
	t2->Draw("PB5_multibin:PB_tru","","colz");
	htemp = (TH2F*)gPad->GetPrimitive("htemp");
	htemp->GetYaxis()->SetTitle("PB^{multi-bin}_{j_{5}}");
	HtempProps();
	c->Print(out_file_, "pdf");
	c->SaveAs("./summary_plots/tex/control24.tex");

	//!page25
	TLegend *SGBG = new TLegend (0.15, 0.87, 0.45, 0.96);
	SGBG->SetFillStyle(0);
	SGBG->SetBorderSize(0);
	SGBG->SetTextSize(0.04);
	SGBG->AddEntry(BG_2L1C,"Min Bias");
	SGBG->AddEntry(SG_2L1C,"HH #rightarrow 4b");
	TLegend *ranks = new TLegend (0.75, 0.62, 0.97, 0.97);
	ranks->SetFillStyle(0);
	ranks->SetBorderSize(0);
	ranks->SetTextSize(0.04);
	ranks->SetHeader("max-bin","C");
	ranks->AddEntry(SG_1L1C,"leading jet", "l");
	ranks->AddEntry(SG_2L1C,"2^{nd} leading jet", "l");
	ranks->AddEntry(SG_3L1C,"3^{rd} leading jet", "l");
	ranks->AddEntry(SG_4L1C,"4^{th} leading jet", "l");
	//ranks->AddEntry(SG_5L1C,"5^{th} leading jet", "l");
	TLegend *ranks_a = new TLegend (0.75, 0.62, 0.97, 0.97);
	ranks_a->SetFillStyle(0);
	ranks_a->SetBorderSize(0);
	ranks_a->SetTextSize(0.04);
	ranks_a->SetHeader("multi-bin","C");
	ranks_a->AddEntry(SGa_1L1C,"leading jet", "l");
	ranks_a->AddEntry(SGa_2L1C,"2^{nd} leading jet", "l");
	ranks_a->AddEntry(SGa_3L1C,"3^{rd} leading jet", "l");
	ranks_a->AddEntry(SGa_4L1C,"4^{th} leading jet", "l");
	//ranks_a->AddEntry(SGa_5L1C,"5^{th} leading jet", "l");

	BOTTOMMARGIN = 0.15;
	RIGHTMARGIN = 0.03;
	c->Clear();
	c->SetRightMargin(0.);
	c->SetLeftMargin(0.);
	c->SetTopMargin(0.);
	c->SetBottomMargin(0.);
	c->SetTicks(1,1);
	c->SetFillColor(0);
	c->SetHighLightColor(0);
	c->Divide(2,2,0,0);
	c->cd(1);
	SetPadProps();
	BG_1L1C->GetXaxis()->SetRangeUser(2,100);
	BG_2L1C->GetXaxis()->SetRangeUser(2,100);
	BG_3L1C->GetXaxis()->SetRangeUser(2,100);
	BG_4L1C->GetXaxis()->SetRangeUser(2,100);
	SG_1L1C->GetXaxis()->SetRangeUser(2,100);
	SG_2L1C->GetXaxis()->SetRangeUser(2,100);
	SG_3L1C->GetXaxis()->SetRangeUser(2,100);
	SG_4L1C->GetXaxis()->SetRangeUser(2,100);
	BG_1L1C->GetXaxis()->SetTitle("1^{st} const. p_{T} [GeV/c]");
	BG_1L1C->GetXaxis()->SetTitleSize(TEXT_SIZE);
	BG_1L1C->GetXaxis()->CenterTitle();
	BG_1L1C->GetXaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	//BG_5L1C->Draw("");
	//SG_5L1C->Draw("same");
	BG_1L1C->Draw("hist");
	SG_4L1C->Draw("same");
	SG_3L1C->Draw("same");
	SG_2L1C->Draw("same");
	SG_1L1C->Draw("same");
	BG_3L1C->Draw("hist same");
	BG_2L1C->Draw("hist same");
	BG_4L1C->Draw("hist same");
	gPad->SetLogy();
	gPad->SetLogx();
	SGBG->Draw();
	ranks->Draw();

	c->cd(3);
	SetPadProps();
	SG_1L2C->GetXaxis()->SetRangeUser(2,100);
	SG_2L2C->GetXaxis()->SetRangeUser(2,100);
	SG_3L2C->GetXaxis()->SetRangeUser(2,100);
	SG_4L2C->GetXaxis()->SetRangeUser(2,100);
	BG_1L2C->GetXaxis()->SetRangeUser(2,100);
	BG_2L2C->GetXaxis()->SetRangeUser(2,100);
	BG_3L2C->GetXaxis()->SetRangeUser(2,100);
	BG_4L2C->GetXaxis()->SetRangeUser(2,100);
	BG_4L2C->GetXaxis()->SetTitle("2^{nd} const. p_{T} [GeV/c]");
	BG_4L2C->GetXaxis()->SetTitleSize(TEXT_SIZE);
	BG_4L2C->GetXaxis()->CenterTitle();
	BG_4L2C->GetXaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	//BG_5L2C->Draw("");
	//SG_5L2C->Draw("same");
	BG_4L2C->Draw("");
	SG_4L2C->Draw("same");
	SG_3L2C->Draw("same");
	SG_2L2C->Draw("same");
	SG_1L2C->Draw("same");
	BG_3L2C->Draw("same");
	BG_2L2C->Draw("same");
	BG_1L2C->Draw("same");
	gPad->SetLogy();
	gPad->SetLogx();
	SGBG->Draw();
	ranks->Draw();
	
	//c->cd(5);
	//SetPadProps();
	//BG_5L3C->GetXaxis()->SetRangeUser(2,100);
	//BG_5L3C->GetXaxis()->SetTitle("3^{rd} const. p_{T} [GeV/c]");
	//BG_5L3C->GetXaxis()->SetTitleSize(TEXT_SIZE);
	//BG_5L3C->GetXaxis()->CenterTitle();
	//BG_5L3C->GetXaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	//BG_5L3C->Draw("");
	//SG_5L3C->Draw("same");
	//SG_4L3C->Draw("same");
	//SG_3L3C->Draw("same");
	//SG_2L3C->Draw("same");
	//SG_1L3C->Draw("same");
	//BG_4L3C->Draw("same");
	//BG_3L3C->Draw("same");
	//BG_2L3C->Draw("same");
	//BG_1L3C->Draw("same");
	//gPad->SetLogy();
	//gPad->SetLogx();
	//SGBG->Draw();
	//ranks->Draw();

	//c->cd(7);
	//SetPadProps();
	//BG_5L4C->GetXaxis()->SetRangeUser(2,100);
	//BG_5L4C->GetXaxis()->SetTitle("4^{th} const. p_{T} [GeV/c]");
	//BG_5L4C->GetXaxis()->SetTitleSize(TEXT_SIZE);
	//BG_5L4C->GetXaxis()->CenterTitle();
	//BG_5L4C->GetXaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	//BG_5L4C->Draw("");
	//SG_5L4C->Draw("same");
	//SG_4L4C->Draw("same");
	//SG_3L4C->Draw("same");
	//SG_2L4C->Draw("same");
	//SG_1L4C->Draw("same");
	//BG_4L4C->Draw("same");
	//BG_3L4C->Draw("same");
	//BG_2L4C->Draw("same");
	//BG_1L4C->Draw("same");
	//gPad->SetLogy();
	//gPad->SetLogx();
	//SGBG->Draw();
	//ranks->Draw();

	c->cd(2);
	SetPadProps();
	SGa_1L1C->GetXaxis()->SetRangeUser(2,100);
	SGa_2L1C->GetXaxis()->SetRangeUser(2,100);
	SGa_3L1C->GetXaxis()->SetRangeUser(2,100);
	SGa_4L1C->GetXaxis()->SetRangeUser(2,100);
	BGa_1L1C->GetXaxis()->SetRangeUser(2,100);
	BGa_2L1C->GetXaxis()->SetRangeUser(2,100);
	BGa_3L1C->GetXaxis()->SetRangeUser(2,100);
	BGa_4L1C->GetXaxis()->SetRangeUser(2,100);
	BGa_4L1C->GetXaxis()->SetTitle("1^{st} const. p_{T} [GeV/c]");
	BGa_4L1C->GetXaxis()->SetTitleSize(TEXT_SIZE);
	BGa_4L1C->GetXaxis()->CenterTitle();
	BGa_4L1C->GetXaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	//BGa_5L1C->Draw("");
	//SGa_5L1C->Draw("same");
	BGa_4L1C->Draw("");
	SGa_4L1C->Draw("same");
	SGa_3L1C->Draw("same");
	SGa_2L1C->Draw("same");
	SGa_1L1C->Draw("same");
	BGa_3L1C->Draw("same");
	BGa_2L1C->Draw("same");
	BGa_1L1C->Draw("same");
	gPad->SetLogy();
	gPad->SetLogx();
	SGBG->Draw();
	ranks_a->Draw();

	c->cd(4);
	SetPadProps();
	SGa_1L2C->GetXaxis()->SetRangeUser(2,100);
	SGa_2L2C->GetXaxis()->SetRangeUser(2,100);
	SGa_3L2C->GetXaxis()->SetRangeUser(2,100);
	SGa_4L2C->GetXaxis()->SetRangeUser(2,100);
	BGa_1L2C->GetXaxis()->SetRangeUser(2,100);
	BGa_2L2C->GetXaxis()->SetRangeUser(2,100);
	BGa_3L2C->GetXaxis()->SetRangeUser(2,100);
	BGa_4L2C->GetXaxis()->SetRangeUser(2,100);
	BGa_4L2C->GetXaxis()->SetTitle("2^{nd} const. p_{T} [GeV/c]");
	BGa_4L2C->GetXaxis()->SetTitleSize(TEXT_SIZE);
	BGa_4L2C->GetXaxis()->CenterTitle();
	BGa_4L2C->GetXaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	//BGa_5L2C->Draw("");
	//SGa_5L2C->Draw("same");
	BGa_4L2C->Draw("");
	SGa_4L2C->Draw("same");
	SGa_3L2C->Draw("same");
	SGa_2L2C->Draw("same");
	SGa_1L2C->Draw("same");
	BGa_3L2C->Draw("same");
	BGa_2L2C->Draw("same");
	BGa_1L2C->Draw("same");
	gPad->SetLogy();
	gPad->SetLogx();
	SGBG->Draw();
	ranks_a->Draw();
	
	//c->cd(6);
	//SetPadProps();
	//BGa_5L3C->GetXaxis()->SetRangeUser(2,100);
	//BGa_5L3C->GetXaxis()->SetTitle("3^{rd} const. p_{T} [GeV/c]");
	//BGa_5L3C->GetXaxis()->SetTitleSize(TEXT_SIZE);
	//BGa_5L3C->GetXaxis()->CenterTitle();
	//BGa_5L3C->GetXaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	//BGa_5L3C->Draw("");
	//SGa_5L3C->Draw("same");
	//SGa_4L3C->Draw("same");
	//SGa_3L3C->Draw("same");
	//SGa_2L3C->Draw("same");
	//SGa_1L3C->Draw("same");
	//BGa_4L3C->Draw("same");
	//BGa_3L3C->Draw("same");
	//BGa_2L3C->Draw("same");
	//BGa_1L3C->Draw("same");
	//gPad->SetLogy();
	//gPad->SetLogx();
	//SGBG->Draw();
	//ranks_a->Draw();

	//c->cd(8);
	//SetPadProps();
	//BGa_5L4C->GetXaxis()->SetRangeUser(2,100);
	//BGa_5L4C->GetXaxis()->SetTitle("4^{th} const. p_{T} [GeV/c]");
	//BGa_5L4C->GetXaxis()->SetTitleSize(TEXT_SIZE);
	//BGa_5L4C->GetXaxis()->CenterTitle();
	//BGa_5L4C->GetXaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	//BGa_5L4C->Draw("");
	//SGa_5L4C->Draw("same");
	//SGa_4L4C->Draw("same");
	//SGa_3L4C->Draw("same");
	//SGa_2L4C->Draw("same");
	//SGa_1L4C->Draw("same");
	//BGa_4L4C->Draw("same");
	//BGa_3L4C->Draw("same");
	//BGa_2L4C->Draw("same");
	//BGa_1L4C->Draw("same");
	//gPad->SetLogy();
	//gPad->SetLogx();
	//SGBG->Draw();
	//ranks_a->Draw();

	c->Print(out_file_close, "pdf");
	c->SaveAs("./summary_plots/tex/control25.tex");

	return;
}
