
Double_t eb__2[n] = {0};   Double_t rb__2[n] = {0};
Double_t eb__3[n] = {0};   Double_t rb__3[n] = {0};
Double_t eb__4[n] = {0};   Double_t rb__4[n] = {0};
Double_t eb__5[n] = {0};   Double_t rb__5[n] = {0};

Double_t e_errb__2[n] = {0};   Double_t r_errb__2[n] = {0};
Double_t e_errb__3[n] = {0};   Double_t r_errb__3[n] = {0};
Double_t e_errb__4[n] = {0};   Double_t r_errb__4[n] = {0};
Double_t e_errb__5[n] = {0};   Double_t r_errb__5[n] = {0};

TH1F *Ebcalo2 = nullptr;
TH1F *Ebcalo3 = nullptr;
TH1F *Ebcalo4 = nullptr;
TH1F *Ebcalo5 = nullptr;
TH1F *Rbcalo2 = nullptr;
TH1F *Rbcalo3 = nullptr;
TH1F *Rbcalo4 = nullptr;
TH1F *Rbcalo5 = nullptr;

TGraphErrors *gb_1_ = nullptr; 
TGraphErrors *gb_2_ = nullptr; 
TGraphErrors *gb_3_ = nullptr; 
TGraphErrors *gb_4_ = nullptr; 

TGraph2DErrors *gb_2d1_ = nullptr; 
TGraph2DErrors *gb_2d2_ = nullptr; 
TGraph2DErrors *gb_2d3_ = nullptr; 
TGraph2DErrors *gb_2d4_ = nullptr; 

void fetch_emuCalo()
{
	TFile *fcalo = new TFile(signal_file_calo, "READ");
	//! Calo Emulation
	Ebcalo2 = (TH1F*)fcalo->Get("hb_tJeff2");
	Ebcalo3 = (TH1F*)fcalo->Get("hb_tJeff3");
	Ebcalo4 = (TH1F*)fcalo->Get("hb_tJeff4");
	Ebcalo5 = (TH1F*)fcalo->Get("hb_tJeff5");
	//Ebcalo2->GetYaxis()->SetRangeUser(0,1.2);
	//Ebcalo3->GetYaxis()->SetRangeUser(0,1.2);
	//Ebcalo4->GetYaxis()->SetRangeUser(0,1.2);
	//Ebcalo5->GetYaxis()->SetRangeUser(0,1.2);
	Ebcalo2->SetLineStyle(2);
	Ebcalo3->SetLineStyle(2);
	Ebcalo4->SetLineStyle(2);
	Ebcalo5->SetLineStyle(2);
	
	TFile *f1calo = new TFile(MinBias_file_calo, "READ");
	TTree *t1calo = (TTree*)f1calo->Get("glob_jet");
	nevents = t1calo->GetEntries();
	//! sumpt approach
	Rbcalo2 = (TH1F*)f1calo->Get("hb_PUNLpt");
	Rbcalo3 = (TH1F*)f1calo->Get("hb_PUNNLpt");
	Rbcalo4 = (TH1F*)f1calo->Get("hb_PUNNNLpt");
	Rbcalo5 = (TH1F*)f1calo->Get("hb_PUNNNNLpt");
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


	return;
}

void make_graphs_emuCalo()
{
	//gb_1_ = new TGraphErrors(n,rb__2,eb__2,0,0);
	gb_1_ = new TGraphErrors(n,rb__2,eb__2,r_errb__2,e_errb__2);
	gb_1_->GetYaxis()->SetTitle("trigger efficiency");
	auto axis = gb_1_->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	gb_1_->GetXaxis()->SetTitleOffset(1.2);
	gb_1_->GetXaxis()->SetTitle("trigger rate [MHz]");
	gb_1_->GetYaxis()->SetTitle("trigger efficiency");
	gb_1_->GetXaxis()->CenterTitle();
	gb_1_->GetYaxis()->CenterTitle();
	gb_1_->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb_1_->SetMarkerStyle(kFullDiamond);//kFullCircle);
	gb_1_->SetMarkerColor(kBlack);
	gb_1_->SetLineColor(kBlack);
	gb_1_->SetMarkerSize(2.0);
	gb_1_->SetFillColor(kWhite);
	gb_1_->SetTitle("2^{nd} leading pt emulated calo-jet ");
	//gb1_->Draw("ACPe1");
	gb_1_->Draw("APe1");

	//gb_2_ = new TGraphErrors(n,rb__3,eb__3,0,0);
	gb_2_ = new TGraphErrors(n,rb__3,eb__3,r_errb__3,e_errb__3);
	gb_2_->GetYaxis()->SetTitle("trigger efficiency");
	axis = gb_2_->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	gb_2_->GetXaxis()->SetTitleOffset(1.2);
	gb_2_->GetXaxis()->SetTitle("trigger rate [MHz]");
	gb_2_->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb_2_->SetMarkerStyle(kFullDiamond);//kFullTriangleUp);
	gb_2_->SetMarkerColor(kRed);
	gb_2_->SetLineColor(kRed);
	gb_2_->SetMarkerSize(2.0);
	gb_2_->SetFillColor(kWhite);
	gb_2_->SetTitle("3^{rd} leading pt emulated calo-jet ");
	//gb2_->Draw("CPe1");
	gb_2_->Draw("Pe1");

	//gb_3_ = new TGraphErrors(n,rb__4,eb__4,0,0);
	gb_3_ = new TGraphErrors(n,rb__4,eb__4,r_errb__4,e_errb__4);
	gb_3_->GetYaxis()->SetTitle("trigger efficiency");
	axis = gb_3_->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	gb_3_->GetXaxis()->SetTitleOffset(1.2);
	gb_3_->GetXaxis()->SetTitle("trigger rate [MHz]");
	gb_3_->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb_3_->SetMarkerStyle(kFullDiamond);//k);
	gb_3_->SetMarkerColor(kGreen+2);
	gb_3_->SetLineColor(kGreen+2);
	gb_3_->SetMarkerSize(2.0);
	gb_3_->SetFillColor(kWhite);
	gb_3_->SetTitle("4^{th} leading pt emulated calo-jet ");
	//gb3_->Draw("CPe1");
	gb_3_->Draw("Pe1");

	//gb_4_ = new TGraphErrors(n,rb__5,eb__5,0,0);
	gb_4_ = new TGraphErrors(n,rb__5,eb__5,r_errb__5,e_errb__5);
	gb_4_->GetYaxis()->SetTitle("trigger efficiency");
	axis = gb_4_->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	gb_4_->GetXaxis()->SetTitleOffset(1.2);
	gb_4_->GetXaxis()->SetTitle("trigger rate [MHz]");
	gb_4_->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb_4_->SetMarkerStyle(kFullDiamond);//kFullStar);
	gb_4_->SetMarkerColor(kBlue);
	gb_4_->SetLineColor(kBlue);
	gb_4_->SetMarkerSize(2.0);
	//_c1->cd(4);
	gb_4_->SetFillColor(kWhite);
	gb_4_->SetTitle("5^{th} leading pt emulated calo-jet ");
	//gb4_->Draw("CPe1");
	gb_4_->Draw("Pe1");


	return;
}
void graph2D_emuCalo()
{
	//! emulated calo-jet
	gb_2d1_ = new TGraph2DErrors(n,eb__2,rb__2,pt_threshold, e_errb__2, r_errb__2, 0);
	gb_2d1_->SetName("g2D2nd_calo");
	gb_2d1_->SetMarkerStyle(kFullDiamond);
	gb_2d1_->SetMarkerSize(DIAMOND_SIZE);
	gb_2d1_->SetFillColor(kWhite);
	gb_2d1_->SetTitle("emulated calo-jet");
	//gb_2d1_->SetTitle("2^{nd} leading pt emulated calo-jet");
	gb_2d1_->Draw("PCOLZ ERR");
	gb_2d2_ = new TGraph2DErrors(n,eb__3,rb__3,pt_threshold, e_errb__3, r_errb__3, 0);
	gb_2d2_->SetName("g2D3rd_calo");
	gb_2d2_->SetMarkerStyle(kFullDiamond);
	gb_2d2_->SetMarkerSize(DIAMOND_SIZE);
	gb_2d2_->SetFillColor(kWhite);
	gb_2d2_->SetTitle("emulated calo-jet");
	//gb_2d2_->SetTitle("3^{rd} leading pt emulated calo-jet");
	gb_2d2_->Draw("PCOLZ ERR");
	gb_2d3_ = new TGraph2DErrors(n,eb__4,rb__4,pt_threshold, e_errb__4, r_errb__4, 0);
	gb_2d3_->SetName("g2D4th_calo");
	gb_2d3_->SetMarkerStyle(kFullDiamond);
	gb_2d3_->SetMarkerSize(DIAMOND_SIZE);
	gb_2d3_->SetFillColor(kWhite);
	gb_2d3_->SetTitle("emulated calo-jet");
	//gb_2d3_->SetTitle("4^{th} leading pt emulated calo-jet");
	gb_2d3_->Draw("PCOLZ ERR");
	gb_2d4_ = new TGraph2DErrors(n,eb__5,rb__5,pt_threshold, e_errb__5, r_errb__5, 0);
	gb_2d4_->SetName("g2D5th_calo");
	gb_2d4_->SetMarkerStyle(kFullDiamond);
	gb_2d4_->SetMarkerSize(DIAMOND_SIZE);
	gb_2d4_->SetFillColor(kWhite);
	gb_2d4_->SetTitle("emulated calo-jet");
	//gb_2d4_->SetTitle("5^{th} leading pt emulated calo-jet");
	gb_2d4_->Draw("PCOLZ ERR");

	return;
}
