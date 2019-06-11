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
int write_to_pdf(const char* output_file_name = "tJrate_LptMB2")
{

	char out_file_open[1023];
        sprintf(out_file_open,"%s/%s.pdf(",out_path,output_file_name);
        char out_file_[1023];
        sprintf(out_file_,"%s/%s.pdf",out_path,output_file_name);
        char out_file_close[1023];
        sprintf(out_file_close,"%s/%s.pdf)",out_path,output_file_name);
	
	TFile* f1 = TFile::Open("jetout_LptMB2_3rec.root");
	TH1F* hpp1	= (TH1F*)f1->Get("h_pur_vs_ptPU");
	TH1F* hpe1	= (TH1F*)f1->Get("h_pur_vs_etaPU");
	//! no binning
	TH1D* hr_aa1	= (TH1D*)f1->Get("hb_PULpt");
	TH1D* hr_aa2	= (TH1D*)f1->Get("hb_PUNLpt");
	TH1D* hr_aa3	= (TH1D*)f1->Get("hb_PUNNLpt");
	TH1D* hr_aa4	= (TH1D*)f1->Get("hb_PUNNNLpt");
	TH1D* hr_aa5	= (TH1D*)f1->Get("hb_PUNNNNLpt");
	//! Andres approach
	TH1D* hr_ab1	= (TH1D*)f1->Get("ha_PULpt");
	TH1D* hr_ab2	= (TH1D*)f1->Get("ha_PUNLpt");
	TH1D* hr_ab3	= (TH1D*)f1->Get("ha_PUNNLpt");
	TH1D* hr_ab4	= (TH1D*)f1->Get("ha_PUNNNLpt");
	TH1D* hr_ab5	= (TH1D*)f1->Get("ha_PUNNNNLpt");
	//! sumpt approach
	TH1D* hr_ac1	= (TH1D*)f1->Get("h_PULpt");
	TH1D* hr_ac2	= (TH1D*)f1->Get("h_PUNLpt");
	TH1D* hr_ac3	= (TH1D*)f1->Get("h_PUNNLpt");
	TH1D* hr_ac4	= (TH1D*)f1->Get("h_PUNNNLpt");
	TH1D* hr_ac5	= (TH1D*)f1->Get("h_PUNNNNLpt");

	TFile* f2 = TFile::Open("jetout_LptMB2_5rec.root");
	TH1F* hpp2	= (TH1F*)f2->Get("h_pur_vs_ptPU");
	TH1F* hpe2	= (TH1F*)f2->Get("h_pur_vs_etaPU");
	//! no binning
	TH1D* hr_ba1	= (TH1D*)f2->Get("hb_PULpt");
	TH1D* hr_ba2	= (TH1D*)f2->Get("hb_PUNLpt");
	TH1D* hr_ba3	= (TH1D*)f2->Get("hb_PUNNLpt");
	TH1D* hr_ba4	= (TH1D*)f2->Get("hb_PUNNNLpt");
	TH1D* hr_ba5	= (TH1D*)f2->Get("hb_PUNNNNLpt");
	//! Andres approach
	TH1D* hr_bb1	= (TH1D*)f2->Get("ha_PULpt");
	TH1D* hr_bb2	= (TH1D*)f2->Get("ha_PUNLpt");
	TH1D* hr_bb3	= (TH1D*)f2->Get("ha_PUNNLpt");
	TH1D* hr_bb4	= (TH1D*)f2->Get("ha_PUNNNLpt");
	TH1D* hr_bb5	= (TH1D*)f2->Get("ha_PUNNNNLpt");
	//! sumpt approach
	TH1D* hr_bc1	= (TH1D*)f2->Get("h_PULpt");
	TH1D* hr_bc2	= (TH1D*)f2->Get("h_PUNLpt");
	TH1D* hr_bc3	= (TH1D*)f2->Get("h_PUNNLpt");
	TH1D* hr_bc4	= (TH1D*)f2->Get("h_PUNNNLpt");
	TH1D* hr_bc5	= (TH1D*)f2->Get("h_PUNNNNLpt");
	
	TFile* f3 = TFile::Open("jetout_LptMB2_noKaprec.root");
	TH1F* hpp3	= (TH1F*)f3->Get("h_pur_vs_ptPU");
	TH1F* hpe3	= (TH1F*)f3->Get("h_pur_vs_etaPU");
	//! no binning
	TH1D* hr_ca1	= (TH1D*)f3->Get("hb_PULpt");
	TH1D* hr_ca2	= (TH1D*)f3->Get("hb_PUNLpt");
	TH1D* hr_ca3	= (TH1D*)f3->Get("hb_PUNNLpt");
	TH1D* hr_ca4	= (TH1D*)f3->Get("hb_PUNNNLpt");
	TH1D* hr_ca5	= (TH1D*)f3->Get("hb_PUNNNNLpt");
	//! Andres approach
	TH1D* hr_cb1	= (TH1D*)f3->Get("ha_PULpt");
	TH1D* hr_cb2	= (TH1D*)f3->Get("ha_PUNLpt");
	TH1D* hr_cb3	= (TH1D*)f3->Get("ha_PUNNLpt");
	TH1D* hr_cb4	= (TH1D*)f3->Get("ha_PUNNNLpt");
	TH1D* hr_cb5	= (TH1D*)f3->Get("ha_PUNNNNLpt");
	//! sumpt approach
	TH1D* hr_cc1	= (TH1D*)f3->Get("h_PULpt");
	TH1D* hr_cc2	= (TH1D*)f3->Get("h_PUNLpt");
	TH1D* hr_cc3	= (TH1D*)f3->Get("h_PUNNLpt");
	TH1D* hr_cc4	= (TH1D*)f3->Get("h_PUNNNLpt");
	TH1D* hr_cc5	= (TH1D*)f3->Get("h_PUNNNNLpt");
	
	TFile* f4= TFile::Open("jetout_LptMB2_looserec.root");
	TH1F* hpp4	= (TH1F*)f4->Get("h_pur_vs_ptPU");
	TH1F* hpe4	= (TH1F*)f4->Get("h_pur_vs_etaPU");
	//! no binning
	TH1D* hr_da1	= (TH1D*)f4->Get("hb_PULpt");
	TH1D* hr_da2	= (TH1D*)f4->Get("hb_PUNLpt");
	TH1D* hr_da3	= (TH1D*)f4->Get("hb_PUNNLpt");
	TH1D* hr_da4	= (TH1D*)f4->Get("hb_PUNNNLpt");
	TH1D* hr_da5	= (TH1D*)f4->Get("hb_PUNNNNLpt");
	//! Andres approach
	TH1D* hr_db1	= (TH1D*)f4->Get("ha_PULpt");
	TH1D* hr_db2	= (TH1D*)f4->Get("ha_PUNLpt");
	TH1D* hr_db3	= (TH1D*)f4->Get("ha_PUNNLpt");
	TH1D* hr_db4	= (TH1D*)f4->Get("ha_PUNNNLpt");
	TH1D* hr_db5	= (TH1D*)f4->Get("ha_PUNNNNLpt");
	//! sumpt approach
	TH1D* hr_dc1	= (TH1D*)f4->Get("h_PULpt");
	TH1D* hr_dc2	= (TH1D*)f4->Get("h_PUNLpt");
	TH1D* hr_dc3	= (TH1D*)f4->Get("h_PUNNLpt");
	TH1D* hr_dc4	= (TH1D*)f4->Get("h_PUNNNLpt");
	TH1D* hr_dc5	= (TH1D*)f4->Get("h_PUNNNNLpt");

	hpp1->SetMarkerColor(kRed);
	hpp2->SetMarkerColor(kBlue);
	hpp3->SetMarkerColor(kBlack);
	hpp4->SetMarkerColor(kGreen);
	hpe1->SetMarkerColor(kRed);
	hpe2->SetMarkerColor(kBlue);
	hpe3->SetMarkerColor(kBlack);
	hpe4->SetMarkerColor(kGreen);

	hpp1->SetMarkerSize(1.2);
	hpp2->SetMarkerSize(1.2);
	hpp3->SetMarkerSize(1.2);
	hpp4->SetMarkerSize(1.2);
	hpe1->SetMarkerSize(1.2);
	hpe2->SetMarkerSize(1.2);
	hpe3->SetMarkerSize(1.2);
	hpe4->SetMarkerSize(1.2);
	
	std::cout<<"Writing to pdf... \n";
	Double_t x1= 0.77,y1= 0.75, x2 = 0.99, y2 = 0.99, yy1 = 0.6, yy2 = 0.91;
	TCanvas * S = new TCanvas();
	S->Divide(2,2);
	gStyle->SetOptStat(0);
	S->SetGridx();
        S->SetGridy();
	TPad *p1 = (TPad*)(S->cd(1));
	p1->SetLogx();
	hpp1->Draw();
	TLegend *l1=new TLegend(x1,y1,x2,y2,"");
	l1->SetBorderSize(0);
        l1->SetTextAlign(32);
        l1->SetTextSize(0.035);
	l1->AddEntry(hpp1,"#sigma_{#kappa} = 3");
	l1->Draw();
	
	TPad *p2 = (TPad*)(S->cd(2));
	p2->SetLogx();
	hpp2->Draw();
	TLegend *l2=new TLegend(x1,y1,x2,y2,"");
	l2->SetBorderSize(0);
        l2->SetTextAlign(32);
        l2->SetTextSize(0.035);
	l2->AddEntry(hpp2,"#sigma_{#kappa} = 5");
	l2->Draw();

	TPad *p3 = (TPad*)(S->cd(3));
	p3->SetLogx();
	hpp3->Draw();
	TLegend *l3=new TLegend(x1,y1,x2,y2,"");
	l3->SetBorderSize(0);
        l3->SetTextAlign(32);
        l3->SetTextSize(0.035);
	l3->AddEntry(hpp3,"No #kappa cut");
	l3->Draw();
	
	TPad *p4 = (TPad*)(S->cd(4));
	p4->SetLogx();
	hpp4->Draw();
	TLegend *l4=new TLegend(x1,y1,x2,y2,"");
	l4->SetBorderSize(0);
        l4->SetTextAlign(32);
        l4->SetTextSize(0.035);
	l4->AddEntry(hpp4,"loose cuts");
	l4->Draw();
	S->Print(out_file_open, "pdf");
	p1->SetLogx(0);
	p2->SetLogx(0);
	p3->SetLogx(0);
	p4->SetLogx(0);

	S->cd(1);
	hpe1->Draw();
	TLegend *m1=new TLegend(x1,y1,x2,y2,"");
	m1->SetBorderSize(0);
        m1->SetTextAlign(32);
        m1->SetTextSize(0.035);
	m1->AddEntry(hpe1,"#sigma_{#kappa} = 3");
	m1->Draw();
	
	S->cd(2);
	hpe2->Draw();
	TLegend *m2=new TLegend(x1,y1,x2,y2,"");
	m2->SetBorderSize(0);
        m2->SetTextAlign(32);
        m2->SetTextSize(0.035);
	m2->AddEntry(hpe2,"#sigma_{#kappa} = 5");
	m2->Draw();

	S->cd(3);
	hpe3->Draw();
	TLegend *m3=new TLegend(x1,y1,x2,y2,"");
	m3->SetBorderSize(0);
        m3->SetTextAlign(32);
        m3->SetTextSize(0.035);
	m3->AddEntry(hpe3,"No #kappa cut");
	m3->Draw();
	
	S->cd(4);
	hpe4->Draw();
	TLegend *m4=new TLegend(x1,y1,x2,y2,"");
	m4->SetBorderSize(0);
        m4->SetTextAlign(32);
        m4->SetTextSize(0.035);
	m4->AddEntry(hpe4,"loose cuts");
	m4->Draw();
	S->Print(out_file_,"pdf");

	S->Clear();
	hpp1->Draw();
	hpp2->Draw("same");
	hpp3->Draw("same");
	hpp4->Draw("same");
	S->SetLogx();
	TLegend *n1=new TLegend(x1,y1,x2,y2,"");
	n1->SetBorderSize(0);
        n1->SetTextAlign(32);
        n1->SetTextSize(0.035);
	n1->AddEntry(hpp1,"#sigma_{#kappa} = 3");
	n1->AddEntry(hpp2,"#sigma_{#kappa} = 5");
	n1->AddEntry(hpp3,"no #kappa cut");
	n1->AddEntry(hpp4,"loose cuts");
	n1->Draw();
	S->Print(out_file_,"pdf");
	
	S->SetLogx(0);	
	hpe1->Draw();
	hpe2->Draw("same");
	hpe3->Draw("same");
	hpe4->Draw("same");
	TLegend *n2=new TLegend(x1,y1,x2,y2,"");
	n2->SetBorderSize(0);
        n2->SetTextAlign(32);
        n2->SetTextSize(0.035);
	n2->AddEntry(hpe1,"#sigma_{#kappa} = 3");
	n2->AddEntry(hpe2,"#sigma_{#kappa} = 5");
	n2->AddEntry(hpe3,"no #kappa cut");
	n2->AddEntry(hpe4,"loose cuts");
	n2->Draw();
	S->Print(out_file_,"pdf");
	
	hr_da5->Draw();
	hr_da4->Draw("same");
	hr_da3->Draw("same");
	hr_da2->Draw("same");
	hr_da1->Draw("same");
	S->SetLogy();
	TLegend *n3=new TLegend(x1,yy1,x2,yy2,"#splitline{track-jet p_{t}, loose cuts}{No Binning}");
	n3->SetBorderSize(0);
        n3->SetTextAlign(32);
        n3->SetTextSize(0.035);
	n3->AddEntry(hr_da1,"highest");
	n3->AddEntry(hr_da2,"2^{nd} highest");
	n3->AddEntry(hr_da3,"3^{rd} highest");
	n3->AddEntry(hr_da4,"4^{th} highest");
	n3->AddEntry(hr_da5,"5^{th} highest");
	n3->Draw();
	S->Print(out_file_,"pdf");

	hr_db5->Draw();
	hr_db4->Draw("same");
	hr_db3->Draw("same");
	hr_db2->Draw("same");
	hr_db1->Draw("same");
	TLegend *n4=new TLegend(x1,yy1,x2,yy2,"#splitline{track-jet p_{t}, loose cuts}{overlapping bins}");
	n4->SetBorderSize(0);
        n4->SetTextAlign(32);
        n4->SetTextSize(0.035);
	n4->AddEntry(hr_db1,"highest");
	n4->AddEntry(hr_db2,"2^{nd} highest");
	n4->AddEntry(hr_db3,"3^{rd} highest");
	n4->AddEntry(hr_db4,"4^{th} highest");
	n4->AddEntry(hr_db5,"5^{th} highest");
	n4->Draw();
	S->Print(out_file_,"pdf");
	
	hr_dc5->Draw();
	hr_dc4->Draw("same");
	hr_dc3->Draw("same");
	hr_dc2->Draw("same");
	hr_dc1->Draw("same");
	TLegend *n5=new TLegend(x1,yy1,x2,yy2,"#splitline{track-jet p_{t}, loose cuts}{sum pt}");
	n5->SetBorderSize(0);
        n5->SetTextAlign(32);
        n5->SetTextSize(0.035);
	n5->AddEntry(hr_dc1,"highest");
	n5->AddEntry(hr_dc2,"2^{nd} highest");
	n5->AddEntry(hr_dc3,"3^{rd} highest");
	n5->AddEntry(hr_dc4,"4^{th} highest");
	n5->AddEntry(hr_dc5,"5^{th} highest");
	n5->Draw();
	S->Print(out_file_,"pdf");

	hr_ca5->Draw();
	hr_ca4->Draw("same");
	hr_ca3->Draw("same");
	hr_ca2->Draw("same");
	hr_ca1->Draw("same");
	TLegend *n6=new TLegend(x1,yy1,x2,yy2,"#splitline{track-jet p_{t}, no #kappa cut}{No Binning}");
	n6->SetBorderSize(0);
        n6->SetTextAlign(32);
        n6->SetTextSize(0.035);
	n6->AddEntry(hr_ca1,"highest");
	n6->AddEntry(hr_ca2,"2^{nd} highest");
	n6->AddEntry(hr_ca3,"3^{rd} highest");
	n6->AddEntry(hr_ca4,"4^{th} highest");
	n6->AddEntry(hr_ca5,"5^{th} highest");
	n6->Draw();
	S->Print(out_file_,"pdf");

	hr_cb5->Draw();
	hr_cb4->Draw("same");
	hr_cb3->Draw("same");
	hr_cb2->Draw("same");
	hr_cb1->Draw("same");
	TLegend *n7=new TLegend(x1,yy1,x2,yy2,"#splitline{track-jet p_{t}, no #kappa cut}{overlapping bins}");
	n7->SetBorderSize(0);
        n7->SetTextAlign(32);
        n7->SetTextSize(0.035);
	n7->AddEntry(hr_cb1,"highest");
	n7->AddEntry(hr_cb2,"2^{nd} highest");
	n7->AddEntry(hr_cb3,"3^{rd} highest");
	n7->AddEntry(hr_cb4,"4^{th} highest");
	n7->AddEntry(hr_cb5,"5^{th} highest");
	n7->Draw();
	S->Print(out_file_,"pdf");
	
	hr_cc5->Draw();
	hr_cc4->Draw("same");
	hr_cc3->Draw("same");
	hr_cc2->Draw("same");
	hr_cc1->Draw("same");
	TLegend *n8=new TLegend(x1,yy1,x2,yy2,"#splitline{track-jet p_{t}, no #kappa cut}{sum pt}");
	n8->SetBorderSize(0);
        n8->SetTextAlign(32);
        n8->SetTextSize(0.035);
	n8->AddEntry(hr_cc1,"highest");
	n8->AddEntry(hr_cc2,"2^{nd} highest");
	n8->AddEntry(hr_cc3,"3^{rd} highest");
	n8->AddEntry(hr_cc4,"4^{th} highest");
	n8->AddEntry(hr_cc5,"5^{th} highest");
	n8->Draw();
	S->Print(out_file_,"pdf");
	
	hr_ba5->Draw();
	hr_ba4->Draw("same");
	hr_ba3->Draw("same");
	hr_ba2->Draw("same");
	hr_ba1->Draw("same");
	TLegend *n9=new TLegend(x1,yy1,x2,yy2,"#splitline{track-jet p_{t}, #sigma_{#kappa} = 5}{No Binning}");
	n9->SetBorderSize(0);
        n9->SetTextAlign(32);
        n9->SetTextSize(0.035);
	n9->AddEntry(hr_ba1,"highest");
	n9->AddEntry(hr_ba2,"2^{nd} highest");
	n9->AddEntry(hr_ba3,"3^{rd} highest");
	n9->AddEntry(hr_ba4,"4^{th} highest");
	n9->AddEntry(hr_ba5,"5^{th} highest");
	n9->Draw();
	S->Print(out_file_,"pdf");

	hr_bb5->Draw();
	hr_bb4->Draw("same");
	hr_bb3->Draw("same");
	hr_bb2->Draw("same");
	hr_bb1->Draw("same");
	TLegend *n10=new TLegend(x1,yy1,x2,yy2,"#splitline{track-jet p_{t}, #sigma_{#kappa} = 5}{overlapping bins}");
	n10->SetBorderSize(0);
        n10->SetTextAlign(32);
        n10->SetTextSize(0.035);
	n10->AddEntry(hr_bb1,"highest");
	n10->AddEntry(hr_bb2,"2^{nd} highest");
	n10->AddEntry(hr_bb3,"3^{rd} highest");
	n10->AddEntry(hr_bb4,"4^{th} highest");
	n10->AddEntry(hr_bb5,"5^{th} highest");
	n10->Draw();
	S->Print(out_file_,"pdf");
	
	hr_bc5->Draw();
	hr_bc4->Draw("same");
	hr_bc3->Draw("same");
	hr_bc2->Draw("same");
	hr_bc1->Draw("same");
	TLegend *n11=new TLegend(x1,yy1,x2,yy2,"#splitline{track-jet p_{t}, #sigma_{#kappa} = 5}{sum pt}");
	n11->SetBorderSize(0);
        n11->SetTextAlign(32);
        n11->SetTextSize(0.035);
	n11->AddEntry(hr_bc1,"highest");
	n11->AddEntry(hr_bc2,"2^{nd} highest");
	n11->AddEntry(hr_bc3,"3^{rd} highest");
	n11->AddEntry(hr_bc4,"4^{th} highest");
	n11->AddEntry(hr_bc5,"5^{th} highest");
	n11->Draw();
	S->Print(out_file_,"pdf");
	
	hr_aa5->Draw();
	hr_aa4->Draw("same");
	hr_aa3->Draw("same");
	hr_aa2->Draw("same");
	hr_aa1->Draw("same");
	TLegend *n12=new TLegend(x1,yy1,x2,yy2,"#splitline{track-jet p_{t}, #sigma_{#kappa} = 3}{No Binning}");
	n12->SetBorderSize(0);
        n12->SetTextAlign(32);
        n12->SetTextSize(0.035);
	n12->AddEntry(hr_aa1,"highest");
	n12->AddEntry(hr_aa2,"2^{nd} highest");
	n12->AddEntry(hr_aa3,"3^{rd} highest");
	n12->AddEntry(hr_aa4,"4^{th} highest");
	n12->AddEntry(hr_aa5,"5^{th} highest");
	n12->Draw();
	S->Print(out_file_,"pdf");

	hr_ab5->Draw();
	hr_ab4->Draw("same");
	hr_ab3->Draw("same");
	hr_ab2->Draw("same");
	hr_ab1->Draw("same");
	TLegend *n13=new TLegend(x1,yy1,x2,yy2,"#splitline{track-jet p_{t}, #sigma_{#kappa} = 3}{overlapping bins}");
	n13->SetBorderSize(0);
        n13->SetTextAlign(32);
        n13->SetTextSize(0.035);
	n13->AddEntry(hr_ab1,"highest");
	n13->AddEntry(hr_ab2,"2^{nd} highest");
	n13->AddEntry(hr_ab3,"3^{rd} highest");
	n13->AddEntry(hr_ab4,"4^{th} highest");
	n13->AddEntry(hr_ab5,"5^{th} highest");
	n13->Draw();
	S->Print(out_file_,"pdf");
	
	hr_ac5->Draw();
	hr_ac4->Draw("same");
	hr_ac3->Draw("same");
	hr_ac2->Draw("same");
	hr_ac1->Draw("same");
	TLegend *n14=new TLegend(x1,yy1,x2,yy2,"#splitline{track-jet p_{t}, #sigma_{#kappa} = 3}{sum pt}");
	n14->SetBorderSize(0);
        n14->SetTextAlign(32);
        n14->SetTextSize(0.035);
	n14->AddEntry(hr_ac1,"highest");
	n14->AddEntry(hr_ac2,"2^{nd} highest");
	n14->AddEntry(hr_ac3,"3^{rd} highest");
	n14->AddEntry(hr_ac4,"4^{th} highest");
	n14->AddEntry(hr_ac5,"5^{th} highest");
	n14->Draw();
	S->Print(out_file_close,"pdf");

return 0;
}
