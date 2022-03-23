
Double_t e2_[n] = {0};    Double_t r2_[n] = {0};
Double_t e3_[n] = {0};    Double_t r3_[n] = {0};
Double_t e4_[n] = {0};    Double_t r4_[n] = {0};
Double_t e5_[n] = {0};    Double_t r5_[n] = {0};
Double_t ea_2[n] = {0};   Double_t ra_2[n] = {0};
Double_t ea_3[n] = {0};   Double_t ra_3[n] = {0};
Double_t ea_4[n] = {0};   Double_t ra_4[n] = {0};
Double_t ea_5[n] = {0};   Double_t ra_5[n] = {0};
Double_t eb_2[n] = {0};   Double_t rb_2[n] = {0};
Double_t eb_3[n] = {0};   Double_t rb_3[n] = {0};
Double_t eb_4[n] = {0};   Double_t rb_4[n] = {0};
Double_t eb_5[n] = {0};   Double_t rb_5[n] = {0};

Double_t e_err2_[n] = {0};    Double_t r_err2_[n] = {0};
Double_t e_err3_[n] = {0};    Double_t r_err3_[n] = {0};
Double_t e_err4_[n] = {0};    Double_t r_err4_[n] = {0};
Double_t e_err5_[n] = {0};    Double_t r_err5_[n] = {0};
Double_t e_erra_2[n] = {0};   Double_t r_erra_2[n] = {0};
Double_t e_erra_3[n] = {0};   Double_t r_erra_3[n] = {0};
Double_t e_erra_4[n] = {0};   Double_t r_erra_4[n] = {0};
Double_t e_erra_5[n] = {0};   Double_t r_erra_5[n] = {0};
Double_t e_errb_2[n] = {0};   Double_t r_errb_2[n] = {0};
Double_t e_errb_3[n] = {0};   Double_t r_errb_3[n] = {0};
Double_t e_errb_4[n] = {0};   Double_t r_errb_4[n] = {0};
Double_t e_errb_5[n] = {0};   Double_t r_errb_5[n] = {0};

TH1F *E2_ = nullptr;  
TH1F *E3_ = nullptr;
TH1F *E4_ = nullptr;
TH1F *E5_ = nullptr;
TH1F *Ea_2= nullptr;
TH1F *Ea_3= nullptr;
TH1F *Ea_4= nullptr;
TH1F *Ea_5= nullptr;
TH1F *Eb_2= nullptr;
TH1F *Eb_3= nullptr;
TH1F *Eb_4= nullptr;
TH1F *Eb_5= nullptr;

TH1F *R2_ =  nullptr;  
TH1F *R3_ =  nullptr;
TH1F *R4_ =  nullptr;
TH1F *R5_ =  nullptr;
TH1F *Ra_2=  nullptr;
TH1F *Ra_3=  nullptr;
TH1F *Ra_4=  nullptr;
TH1F *Ra_5=  nullptr;
TH1F *Rb_2=  nullptr;
TH1F *Rb_3=  nullptr;
TH1F *Rb_4=  nullptr;
TH1F *Rb_5=  nullptr;

TGraphErrors *g1_ = nullptr;
TGraphErrors *g2_ = nullptr;
TGraphErrors *g3_ = nullptr;
TGraphErrors *g4_ = nullptr;
TGraphErrors *ga1_ = nullptr;
TGraphErrors *ga2_ = nullptr;
TGraphErrors *ga3_ = nullptr;
TGraphErrors *ga4_ = nullptr;
TGraphErrors *gb1_ = nullptr;
TGraphErrors *gb2_ = nullptr;
TGraphErrors *gb3_ = nullptr;
TGraphErrors *gb4_ = nullptr;

TGraph2DErrors *ga2d_1 = nullptr;
TGraph2DErrors *ga2d_2 = nullptr;
TGraph2DErrors *ga2d_3 = nullptr;
TGraph2DErrors *ga2d_4 = nullptr;

TGraph2DErrors *g2d_1 = nullptr; 
TGraph2DErrors *g2d_2 = nullptr; 
TGraph2DErrors *g2d_3 = nullptr; 
TGraph2DErrors *g2d_4 = nullptr; 

//TGraph2DErrors *gb2d1 = nullptr;
//TGraph2DErrors *gb2d2 = nullptr;
//TGraph2DErrors *gb2d3 = nullptr;
//TGraph2DErrors *gb2d4 = nullptr;

void fetch_1_5mmTTT()
{
	TFile *f_ = new TFile(signal_file_name_1, "READ");
	//! sumpt approach
	E2_ = (TH1F*)f_->Get("h_tJeff2");
	E3_ = (TH1F*)f_->Get("h_tJeff3");
	E4_ = (TH1F*)f_->Get("h_tJeff4");
	E5_ = (TH1F*)f_->Get("h_tJeff5");
	//! Lpt _bins approach
	Ea_2 = (TH1F*)f_->Get("ha_tJeff2");
	Ea_3 = (TH1F*)f_->Get("ha_tJeff3");
	Ea_4 = (TH1F*)f_->Get("ha_tJeff4");
	Ea_5 = (TH1F*)f_->Get("ha_tJeff5");
	//! no z_-vertex bin 
	Eb_2 = (TH1F*)f_->Get("hb_tJeff2");
	Eb_3 = (TH1F*)f_->Get("hb_tJeff3");
	Eb_4 = (TH1F*)f_->Get("hb_tJeff4");
	Eb_5 = (TH1F*)f_->Get("hb_tJeff5");
	Eb_2->SetLineStyle(7);
	Eb_3->SetLineStyle(7);
	Eb_4->SetLineStyle(7);
	Eb_5->SetLineStyle(7);
	Eb_2->GetYaxis()->SetRangeUser(0,1.2);
	Eb_3->GetYaxis()->SetRangeUser(0,1.2);
	Eb_4->GetYaxis()->SetRangeUser(0,1.2);
	Eb_5->GetYaxis()->SetRangeUser(0,1.2);
	
	TFile *f_1 = new TFile(MinBias_file_name_1, "READ");
	TTree *t_1 = (TTree*)f_1->Get("glob_jet");
	nevents = t_1->GetEntries();
	//! sumpt approach
	R2_ = (TH1F*)f_1->Get("h_PUNLpt");
	R3_ = (TH1F*)f_1->Get("h_PUNNLpt");
	R4_ = (TH1F*)f_1->Get("h_PUNNNLpt");
	R5_ = (TH1F*)f_1->Get("h_PUNNNNLpt");
	//! Lpt _bins approach
	Ra_2 = (TH1F*)f_1->Get("ha_PUNLpt");
	Ra_3 = (TH1F*)f_1->Get("ha_PUNNLpt");
	Ra_4 = (TH1F*)f_1->Get("ha_PUNNNLpt");
	Ra_5 = (TH1F*)f_1->Get("ha_PUNNNNLpt");
	//! no z_-vertex bin 
	Rb_2 = (TH1F*)f_1->Get("hb_PUNLpt");
	Rb_3 = (TH1F*)f_1->Get("hb_PUNNLpt");
	Rb_4 = (TH1F*)f_1->Get("hb_PUNNNLpt");
	Rb_5 = (TH1F*)f_1->Get("hb_PUNNNNLpt");
	Rb_2->SetLineStyle(7);
	Rb_3->SetLineStyle(7);
	Rb_4->SetLineStyle(7);
	Rb_5->SetLineStyle(7);
	//Rb_2->Scale(1.0e3/(25*nevents));
	//Rb_3->Scale(1.0e3/(25*nevents));
	//Rb_4->Scale(1.0e3/(25*nevents));
	//Rb_5->Scale(1.0e3/(25*nevents));
	
	Rb_2->GetYaxis()->SetTitle("trigger rate [MHz]");
	Rb_3->GetYaxis()->SetTitle("trigger rate [MHz]");
	Rb_4->GetYaxis()->SetTitle("trigger rate [MHz]");
	Rb_5->GetYaxis()->SetTitle("trigger rate [MHz]");

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
	
	return;
}

void make_graphs_1_5mmTTT()
{
	g1_ = new TGraphErrors(n,e2_,r2_,e_err2_,r_err2_);
	g1_->GetXaxis()->SetTitle("trigger efficiency");
	auto axis = g1_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	g1_->GetYaxis()->SetTitleOffset(1.2);
	g1_->GetYaxis()->SetTitle("trigger rate [MHz]");
	g1_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g1_->SetMarkerStyle(kOpenTriangleUp);//kFullCircle);
	g1_->SetMarkerColor(kBlack);
	g1_->SetLineColor(kBlack);
	g1_->SetMarkerSize(1.5);
	//c1->cd(4);
	g1_->SetFillColor(kWhite);
	g1_->SetTitle("2^{nd} leading pt track-jet, max-bin, bin_size: +-1.5mm ");
	//g1_->Draw("ACPe1");
	g1_->Draw("APe1");

	g2_ = new TGraphErrors(n,e3_,r3_,e_err3_,r_err3_);
	g2_->GetXaxis()->SetTitle("trigger efficiency");
	axis = g2_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	g2_->GetYaxis()->SetTitleOffset(1.2);
	g2_->GetYaxis()->SetTitle("trigger rate [MHz]");
	g2_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g2_->SetMarkerStyle(kOpenTriangleUp);//kFullTriangleUp);
	g2_->SetMarkerColor(kRed);
	g2_->SetLineColor(kRed);
	g2_->SetMarkerSize(1.5);
	//c1->cd(4);
	g2_->SetFillColor(kWhite);
	g2_->SetTitle("3^{rd} leading pt track-jet, max-bin, bin_size: +-1.5mm ");
	//g2_->Draw("CPe1");
	g2_->Draw("Pe1");

	g3_ = new TGraphErrors(n,e4_,r4_,e_err4_,r_err4_);
	g3_->GetXaxis()->SetTitle("trigger efficiency");
	axis = g3_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	g3_->GetYaxis()->SetTitleOffset(1.2);
	g3_->GetYaxis()->SetTitle("trigger rate [MHz]");
	g3_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g3_->SetMarkerStyle(kOpenTriangleUp);//k);
	g3_->SetMarkerColor(kGreen+2);
	g3_->SetLineColor(kGreen+2);
	g3_->SetMarkerSize(1.5);
	//c1->cd(4);
	g3_->SetFillColor(kWhite);
	g3_->SetTitle("4^{th} leading pt track-jet, max-bin, bin_size: +-1.5mm ");
	//g3_->Draw("CPe1");
	g3_->Draw("Pe1");

	g4_ = new TGraphErrors(n,e5_,r5_,e_err5_,r_err5_);
	g4_->GetXaxis()->SetTitle("trigger efficiency");
	axis = g4_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	g4_->GetYaxis()->SetTitleOffset(1.2);
	g4_->GetYaxis()->SetTitle("trigger rate [MHz]");
	g4_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g4_->SetMarkerStyle(kOpenTriangleUp);//kFullStar);
	g4_->SetMarkerColor(kBlue);
	g4_->SetLineColor(kBlue);
	g4_->SetMarkerSize(1.5);
	//c1->cd(4);
	g4_->SetFillColor(kWhite);
	g4_->SetTitle("5^{th} leading pt track-jet, max-bin, bin_size: +-1.5mm ");
	//g4_->Draw("CPe1");
	g4_->Draw("Pe1");

	ga1_ = new TGraphErrors(n,ea_2,ra_2,e_erra_2,r_erra_2);
	ga1_->GetXaxis()->SetTitle("trigger efficiency");
	axis = ga1_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	ga1_->GetYaxis()->SetTitleOffset(1.2);
	ga1_->GetYaxis()->SetTitle("trigger rate [MHz]");
	ga1_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga1_->SetMarkerStyle(kOpenTriangleDown);//kFullCircle);
	ga1_->SetMarkerColor(kBlack);
	ga1_->SetLineColor(kBlack);
	ga1_->SetMarkerSize(1.5);
	//c1->cd(4);
	ga1_->SetFillColor(kWhite);
	ga1_->SetTitle("2^{nd} leading pt track-jet, multi-bin, bin_size: +-1.5mm ");
	//g1->Draw("ACPe1");
	ga1_->Draw("APe1");

	ga2_ = new TGraphErrors(n,ea_3,ra_3,e_erra_3,r_erra_3);
	ga2_->GetXaxis()->SetTitle("trigger efficiency");
	axis = ga2_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	ga2_->GetYaxis()->SetTitleOffset(1.2);
	ga2_->GetYaxis()->SetTitle("trigger rate [MHz]");
	ga2_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga2_->SetMarkerStyle(kOpenTriangleDown);//kFullTriangleDown);
	ga2_->SetMarkerColor(kRed);
	ga2_->SetLineColor(kRed);
	ga2_->SetMarkerSize(1.5);
	//c1->cd(4);
	ga2_->SetFillColor(kWhite);
	ga2_->SetTitle("3^{rd} leading pt track-jet, multi-bin, bin_size: +-1.5mm ");
	//ga2_->Draw("CPe1");
	ga2_->Draw("Pe1");

	ga3_ = new TGraphErrors(n,ea_4,ra_4,e_erra_4,r_erra_4);
	ga3_->GetXaxis()->SetTitle("trigger efficiency");
	axis = ga3_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	ga3_->GetYaxis()->SetTitleOffset(1.2);
	ga3_->GetYaxis()->SetTitle("trigger rate [MHz]");
	ga3_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga3_->SetMarkerStyle(kOpenTriangleDown);//k);
	ga3_->SetMarkerColor(kGreen+2);
	ga3_->SetLineColor(kGreen+2);
	ga3_->SetMarkerSize(1.5);
	//c1->cd(4);
	ga3_->SetFillColor(kWhite);
	ga3_->SetTitle("4^{th} leading pt track-jet, multi-bin, bin_size: +-1.5mm ");
	//ga3_->Draw("CPe1");
	ga3_->Draw("Pe1");

	ga4_ = new TGraphErrors(n,ea_5,ra_5,e_erra_5,r_erra_5);
	ga4_->GetXaxis()->SetTitle("trigger efficiency");
	axis = ga4_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	ga4_->GetYaxis()->SetTitleOffset(1.2);
	ga4_->GetYaxis()->SetTitle("trigger rate [MHz]");
	ga4_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga4_->SetMarkerStyle(kOpenTriangleDown);//kFullStar);
	ga4_->SetMarkerColor(kBlue);
	ga4_->SetLineColor(kBlue);
	ga4_->SetMarkerSize(1.5);
	//c1->cd(4);
	ga4_->SetFillColor(kWhite);
	ga4_->SetTitle("5^{th} leading pt track-jet, multi-bin, bin_size: +-1.5mm ");
	//ga4_->Draw("CPe1");
	ga4_->Draw("Pe1");

	gb1_ = new TGraphErrors(n,eb_2,rb_2,e_errb_2,r_errb_2);
	gb1_->GetXaxis()->SetTitle("trigger efficiency");
	axis = gb1_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	gb1_->GetYaxis()->SetTitleOffset(1.2);
	gb1_->GetYaxis()->SetTitle("trigger rate [MHz]");
	gb1_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb1_->SetMarkerStyle(kFullCircle);//kFullCircle);
	gb1_->SetMarkerColor(kBlack);
	gb1_->SetLineColor(kBlack);
	gb1_->SetMarkerSize(1.5);
	//c1->cd(4);
	gb1_->SetFillColor(kWhite);
	gb1_->SetTitle("2^{nd} leading pt track-jet no binning ");
	//gb1_->Draw("ACPe1");
	gb1_->Draw("APe1");

	gb2_ = new TGraphErrors(n,eb_3,rb_3,e_errb_3,r_errb_3);
	gb2_->GetXaxis()->SetTitle("trigger efficiency");
	axis = gb2_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	gb2_->GetYaxis()->SetTitleOffset(1.2);
	gb2_->GetYaxis()->SetTitle("trigger rate [MHz]");
	gb2_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb2_->SetMarkerStyle(kFullCircle);//kFullTriangleUp);
	gb2_->SetMarkerColor(kRed);
	gb2_->SetLineColor(kRed);
	gb2_->SetMarkerSize(1.5);
	//c1->cd(4);
	gb2_->SetFillColor(kWhite);
	gb2_->SetTitle("3^{rd} leading pt track-jet no binning ");
	//gb2_->Draw("CPe1");
	gb2_->Draw("Pe1");

	gb3_ = new TGraphErrors(n,eb_4,rb_4,e_errb_4,r_errb_4);
	gb3_->GetXaxis()->SetTitle("trigger efficiency");
	axis = gb3_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	gb3_->GetYaxis()->SetTitleOffset(1.2);
	gb3_->GetYaxis()->SetTitle("trigger rate [MHz]");
	gb3_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb3_->SetMarkerStyle(kFullCircle);//k);
	gb3_->SetMarkerColor(kGreen+2);
	gb3_->SetLineColor(kGreen+2);
	gb3_->SetMarkerSize(1.5);
	//c1->cd(4);
	gb3_->SetFillColor(kWhite);
	gb3_->SetTitle("4^{th} leading pt track-jet no binning ");
	//gb3_->Draw("CPe1");
	gb3_->Draw("Pe1");

	gb4_ = new TGraphErrors(n,eb_5,rb_5,e_errb_5,r_errb_5);
	gb4_->GetXaxis()->SetTitle("trigger efficiency");
	axis = gb4_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	gb4_->GetYaxis()->SetTitleOffset(1.2);
	gb4_->GetYaxis()->SetTitle("trigger rate [MHz]");
	gb4_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb4_->SetMarkerStyle(kFullCircle);//kFullStar);
	gb4_->SetMarkerColor(kBlue);
	gb4_->SetLineColor(kBlue);
	gb4_->SetMarkerSize(1.5);
	//c1->cd(4);
	gb4_->SetFillColor(kWhite);
	gb4_->SetTitle("5^{th} leading pt track-jet no binning ");
	//gb4_->Draw("CPe1");
	gb4_->Draw("Pe1");


	return;
}
void graph2D_1_5mm_multibin()
{
	//! multi-bin +-1.5mm
	ga2d_1 = new TGraph2DErrors(n,ea_2,ra_2,pt_threshold, e_erra_2, r_erra_2, 0);
	ga2d_1->SetName("g2D_2nd_maxpt");
	ga2d_1->SetMarkerStyle(kFullStar);
	ga2d_1->SetMarkerSize(STAR_SIZE);
	ga2d_1->SetFillColor(kWhite);
	ga2d_1->SetTitle("track-jet, multi-bin, 1.5mm");
	//ga2d_1->SetTitle("2^{nd} leading pt track-jet, multi-bin, bin_size: 1.5mm");
	ga2d_1->Draw("PCOLZ ERR");
	ga2d_2 = new TGraph2DErrors(n,ea_3,ra_3,pt_threshold, e_erra_3, r_erra_3, 0);
	ga2d_2->SetName("g2D_3rd_maxpt");
	ga2d_2->SetMarkerStyle(kFullStar);
	ga2d_2->SetMarkerSize(STAR_SIZE);
	ga2d_2->SetFillColor(kWhite);
	ga2d_2->SetTitle("track-jet, multi-bin, 1.5mm");
	//ga2d_2->SetTitle("3^{rd} leading pt track-jet, multi-bin, bin_size: 1.5mm");
	ga2d_2->Draw("PCOLZ ERR");
	ga2d_3 = new TGraph2DErrors(n,ea_4,ra_4,pt_threshold, e_erra_4, r_erra_4, 0);
	ga2d_3->SetName("g2D_4th_maxpt");
	ga2d_3->SetMarkerStyle(kFullStar);
	ga2d_3->SetMarkerSize(STAR_SIZE);
	ga2d_3->SetFillColor(kWhite);
	ga2d_3->SetTitle("track-jet, multi-bin, 1.5mm");
	//ga2d_3->SetTitle("4^{th} leading pt track-jet, multi-bin, bin_size: 1.5mm");
	ga2d_3->Draw("PCOLZ ERR");
	ga2d_4 = new TGraph2DErrors(n,ea_5,ra_5,pt_threshold, e_erra_5, r_erra_5, 0);
	ga2d_4->SetName("g2D_5th_maxpt");
	ga2d_4->SetMarkerStyle(kFullStar);
	ga2d_4->SetMarkerSize(STAR_SIZE);
	ga2d_4->SetFillColor(kWhite);
	ga2d_4->SetTitle("track-jet, multi-bin, 1.5mm");
	//ga2d_4->SetTitle("5^{th} leading pt track-jet, multi-bin, bin_size: 1.5mm");
	ga2d_4->Draw("PCOLZ ERR");
	
	return;
	
}
void graph2D_1_5mm_maxbin()
{
	//! max-bin +-1.5mm
	g2d_1 = new TGraph2DErrors(n,e2_,r2_,pt_threshold, e_err2_, r_err2_, 0);
	g2d_1->SetName("g2D_2nd_sumpt");
	g2d_1->SetMarkerStyle(kFullStar);
	g2d_1->SetMarkerSize(STAR_SIZE);
	g2d_1->SetFillColor(kWhite);
	g2d_1->SetTitle("track-jet, max-bin, +-1.5mm");
	//g2d_1->SetTitle("2^{nd} leading pt track-jet, max-bin, bin_size: +-1.5mm");
	g2d_1->Draw("PCOLZ ERR");
	g2d_2 = new TGraph2DErrors(n,e3_,r3_,pt_threshold, e_err3_, r_err3_, 0);
	g2d_2->SetName("g2D_3rd_sumpt");
	g2d_2->SetMarkerStyle(kFullStar);
	g2d_2->SetMarkerSize(STAR_SIZE);
	g2d_2->SetFillColor(kWhite);
	g2d_2->SetTitle("track-jet, max-bin, +-1.5mm");
	//g2d_2->SetTitle("3^{rd} leading pt track-jet, max-bin, bin_size: +-1.5mm");
	g2d_2->Draw("PCOLZ ERR");
	g2d_3 = new TGraph2DErrors(n,e4_,r4_,pt_threshold, e_err4_, r_err4_, 0);
	g2d_3->SetName("g2D_4th_sumpt");
	g2d_3->SetMarkerStyle(kFullStar);
	g2d_3->SetMarkerSize(STAR_SIZE);
	g2d_3->SetFillColor(kWhite);
	g2d_3->SetTitle("track-jet, max-bin, +-1.5mm");
	//g2d_3->SetTitle("4^{th} leading pt track-jet, max-bin, bin_size: +-1.5mm");
	g2d_3->Draw("PCOLZ ERR");
	g2d_4 = new TGraph2DErrors(n,e5_,r5_,pt_threshold, e_err5_, r_err5_, 0);
	g2d_4->SetName("g2D_5th_sumpt");
	g2d_4->SetMarkerStyle(kFullStar);
	g2d_4->SetMarkerSize(STAR_SIZE);
	g2d_4->SetFillColor(kWhite);
	g2d_4->SetTitle("track-jet, max-bin, +-1.5mm");
	//g2d_4->SetTitle("5^{th} leading pt track-jet, max-bin, bin_size: +-1.5mm");
	g2d_4->Draw("PCOLZ ERR");


	return;
}
