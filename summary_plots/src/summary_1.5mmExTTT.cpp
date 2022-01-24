
Double_t Exe2_[n] = {0};    Double_t Exr2_[n] = {0};
Double_t Exe3_[n] = {0};    Double_t Exr3_[n] = {0};
Double_t Exe4_[n] = {0};    Double_t Exr4_[n] = {0};
Double_t Exe5_[n] = {0};    Double_t Exr5_[n] = {0};
Double_t Exea_2[n] = {0};   Double_t Exra_2[n] = {0};
Double_t Exea_3[n] = {0};   Double_t Exra_3[n] = {0};
Double_t Exea_4[n] = {0};   Double_t Exra_4[n] = {0};
Double_t Exea_5[n] = {0};   Double_t Exra_5[n] = {0};
Double_t Exeb_2[n] = {0};   Double_t Exrb_2[n] = {0};
Double_t Exeb_3[n] = {0};   Double_t Exrb_3[n] = {0};
Double_t Exeb_4[n] = {0};   Double_t Exrb_4[n] = {0};
Double_t Exeb_5[n] = {0};   Double_t Exrb_5[n] = {0};

Double_t Exe_err2_[n] = {0};    Double_t Exr_err2_[n] = {0};
Double_t Exe_err3_[n] = {0};    Double_t Exr_err3_[n] = {0};
Double_t Exe_err4_[n] = {0};    Double_t Exr_err4_[n] = {0};
Double_t Exe_err5_[n] = {0};    Double_t Exr_err5_[n] = {0};
Double_t Exe_erra_2[n] = {0};   Double_t Exr_erra_2[n] = {0};
Double_t Exe_erra_3[n] = {0};   Double_t Exr_erra_3[n] = {0};
Double_t Exe_erra_4[n] = {0};   Double_t Exr_erra_4[n] = {0};
Double_t Exe_erra_5[n] = {0};   Double_t Exr_erra_5[n] = {0};
Double_t Exe_errb_2[n] = {0};   Double_t Exr_errb_2[n] = {0};
Double_t Exe_errb_3[n] = {0};   Double_t Exr_errb_3[n] = {0};
Double_t Exe_errb_4[n] = {0};   Double_t Exr_errb_4[n] = {0};
Double_t Exe_errb_5[n] = {0};   Double_t Exr_errb_5[n] = {0};

TH1F *ExE2_ = nullptr;  
TH1F *ExE3_ = nullptr;
TH1F *ExE4_ = nullptr;
TH1F *ExE5_ = nullptr;
TH1F *ExEa_2= nullptr;
TH1F *ExEa_3= nullptr;
TH1F *ExEa_4= nullptr;
TH1F *ExEa_5= nullptr;
TH1F *ExEb_2= nullptr;
TH1F *ExEb_3= nullptr;
TH1F *ExEb_4= nullptr;
TH1F *ExEb_5= nullptr;

TH1F *ExR2_ =  nullptr;  
TH1F *ExR3_ =  nullptr;
TH1F *ExR4_ =  nullptr;
TH1F *ExR5_ =  nullptr;
TH1F *ExRa_2=  nullptr;
TH1F *ExRa_3=  nullptr;
TH1F *ExRa_4=  nullptr;
TH1F *ExRa_5=  nullptr;
TH1F *ExRb_2=  nullptr;
TH1F *ExRb_3=  nullptr;
TH1F *ExRb_4=  nullptr;
TH1F *ExRb_5=  nullptr;

TGraphErrors *Exg1_ = nullptr;
TGraphErrors *Exg2_ = nullptr;
TGraphErrors *Exg3_ = nullptr;
TGraphErrors *Exg4_ = nullptr;
TGraphErrors *Exga1_ = nullptr;
TGraphErrors *Exga2_ = nullptr;
TGraphErrors *Exga3_ = nullptr;
TGraphErrors *Exga4_ = nullptr;
TGraphErrors *Exgb1_ = nullptr;
TGraphErrors *Exgb2_ = nullptr;
TGraphErrors *Exgb3_ = nullptr;
TGraphErrors *Exgb4_ = nullptr;

TGraph2DErrors *Exga2d_1 = nullptr;
TGraph2DErrors *Exga2d_2 = nullptr;
TGraph2DErrors *Exga2d_3 = nullptr;
TGraph2DErrors *Exga2d_4 = nullptr;

TGraph2DErrors *Exg2d_1 = nullptr; 
TGraph2DErrors *Exg2d_2 = nullptr; 
TGraph2DErrors *Exg2d_3 = nullptr; 
TGraph2DErrors *Exg2d_4 = nullptr; 

void fetch_1_5mmExTTT()
{
	TFile *Exf_ = new TFile(signal_file_name_3, "READ");
	//! sumpt approach
	ExE2_ = (TH1F*)Exf_->Get("h_tJeff2");
	ExE3_ = (TH1F*)Exf_->Get("h_tJeff3");
	ExE4_ = (TH1F*)Exf_->Get("h_tJeff4");
	ExE5_ = (TH1F*)Exf_->Get("h_tJeff5");
	//! Lpt _bins approach
	ExEa_2 = (TH1F*)Exf_->Get("ha_tJeff2");
	ExEa_3 = (TH1F*)Exf_->Get("ha_tJeff3");
	ExEa_4 = (TH1F*)Exf_->Get("ha_tJeff4");
	ExEa_5 = (TH1F*)Exf_->Get("ha_tJeff5");
	//! no z_-vertex bin 
	ExEb_2 = (TH1F*)Exf_->Get("hb_tJeff2");
	ExEb_3 = (TH1F*)Exf_->Get("hb_tJeff3");
	ExEb_4 = (TH1F*)Exf_->Get("hb_tJeff4");
	ExEb_5 = (TH1F*)Exf_->Get("hb_tJeff5");
	ExEb_2->SetLineStyle(7);
	ExEb_3->SetLineStyle(7);
	ExEb_4->SetLineStyle(7);
	ExEb_5->SetLineStyle(7);
	ExEb_2->GetYaxis()->SetRangeUser(0,1.2);
	ExEb_3->GetYaxis()->SetRangeUser(0,1.2);
	ExEb_4->GetYaxis()->SetRangeUser(0,1.2);
	ExEb_5->GetYaxis()->SetRangeUser(0,1.2);
	
	TFile *Exf_1 = new TFile(MinBias_file_name_3, "READ");
	TTree *Ext_1 = (TTree*)Exf_1->Get("glob_jet");
	nevents = Ext_1->GetEntries();
	//! sumpt approach
	ExR2_ = (TH1F*)Exf_1->Get("h_PUNLpt");
	ExR3_ = (TH1F*)Exf_1->Get("h_PUNNLpt");
	ExR4_ = (TH1F*)Exf_1->Get("h_PUNNNLpt");
	ExR5_ = (TH1F*)Exf_1->Get("h_PUNNNNLpt");
	//! Lpt _bins approach
	ExRa_2 = (TH1F*)Exf_1->Get("ha_PUNLpt");
	ExRa_3 = (TH1F*)Exf_1->Get("ha_PUNNLpt");
	ExRa_4 = (TH1F*)Exf_1->Get("ha_PUNNNLpt");
	ExRa_5 = (TH1F*)Exf_1->Get("ha_PUNNNNLpt");
	//! no z_-vertex bin 
	ExRb_2 = (TH1F*)Exf_1->Get("hb_PUNLpt");
	ExRb_3 = (TH1F*)Exf_1->Get("hb_PUNNLpt");
	ExRb_4 = (TH1F*)Exf_1->Get("hb_PUNNNLpt");
	ExRb_5 = (TH1F*)Exf_1->Get("hb_PUNNNNLpt");
	ExRb_2->SetLineStyle(7);
	ExRb_3->SetLineStyle(7);
	ExRb_4->SetLineStyle(7);
	ExRb_5->SetLineStyle(7);
	//Rb_2->Scale(1.0e3/(25*nevents));
	//Rb_3->Scale(1.0e3/(25*nevents));
	//Rb_4->Scale(1.0e3/(25*nevents));
	//Rb_5->Scale(1.0e3/(25*nevents));
	
	ExRb_2->GetYaxis()->SetTitle("trigger rate [MHz]");
	ExRb_3->GetYaxis()->SetTitle("trigger rate [MHz]");
	ExRb_4->GetYaxis()->SetTitle("trigger rate [MHz]");
	ExRb_5->GetYaxis()->SetTitle("trigger rate [MHz]");

	ExRb_2->GetYaxis()->SetRangeUser(1e-1,50);
	ExRb_3->GetYaxis()->SetRangeUser(1e-1,50);
	ExRb_4->GetYaxis()->SetRangeUser(1e-1,50);
	ExRb_5->GetYaxis()->SetRangeUser(1e-1,50);
	
	nbinsE =  ExE2_->GetNbinsX();
	nbinsR =  ExR2_->GetNbinsX();
	nbinsEa = ExEa_2->GetNbinsX();
	nbinsRa = ExRa_2->GetNbinsX();
	nbinsEb = ExEb_2->GetNbinsX();
	nbinsRb = ExRb_2->GetNbinsX();
	if(debug) std::cout<<"nbinsE = " << nbinsE << ", nbinsR = " << nbinsR <<std::endl;
	assert(nbinsE == nbinsR);
	
	return;
}

void make_graphs_1_5mmExTTT()
{
	Exg1_ = new TGraphErrors(n,Exe2_,Exr2_,Exe_err2_,Exr_err2_);
	Exg1_->GetXaxis()->SetTitle("trigger efficiency");
	auto axis = Exg1_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exg1_->GetYaxis()->SetTitleOffset(1.2);
	Exg1_->GetYaxis()->SetTitle("trigger rate [MHz]");
	Exg1_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exg1_->SetMarkerStyle(kOpenTriangleUp);//kFullCircle);
	Exg1_->SetMarkerColor(kBlack);
	Exg1_->SetLineColor(kBlack);
	Exg1_->SetMarkerSize(1.5);
	//c1->cd(4);
	Exg1_->SetFillColor(kWhite);
	Exg1_->SetTitle("2^{nd} leading pt track-jet, max-bin, bin_size: +-1.5mm ");
	//Exg1_->Draw("ACPe1");
	Exg1_->Draw("APe1");

	Exg2_ = new TGraphErrors(n,Exe3_,Exr3_,Exe_err3_,Exr_err3_);
	Exg2_->GetXaxis()->SetTitle("trigger efficiency");
	axis = Exg2_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exg2_->GetYaxis()->SetTitleOffset(1.2);
	Exg2_->GetYaxis()->SetTitle("trigger rate [MHz]");
	Exg2_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exg2_->SetMarkerStyle(kOpenTriangleUp);//kFullTriangleUp);
	Exg2_->SetMarkerColor(kRed);
	Exg2_->SetLineColor(kRed);
	Exg2_->SetMarkerSize(1.5);
	//c1->cd(4);
	Exg2_->SetFillColor(kWhite);
	Exg2_->SetTitle("3^{rd} leading pt track-jet, max-bin, bin_size: +-1.5mm ");
	//Exg2_->Draw("CPe1");
	Exg2_->Draw("Pe1");

	Exg3_ = new TGraphErrors(n,Exe4_,Exr4_,Exe_err4_,Exr_err4_);
	Exg3_->GetXaxis()->SetTitle("trigger efficiency");
	axis = Exg3_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exg3_->GetYaxis()->SetTitleOffset(1.2);
	Exg3_->GetYaxis()->SetTitle("trigger rate [MHz]");
	Exg3_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exg3_->SetMarkerStyle(kOpenTriangleUp);//k);
	Exg3_->SetMarkerColor(kGreen+2);
	Exg3_->SetLineColor(kGreen+2);
	Exg3_->SetMarkerSize(1.5);
	//c1->cd(4);
	Exg3_->SetFillColor(kWhite);
	Exg3_->SetTitle("4^{th} leading pt track-jet, max-bin, bin_size: +-1.5mm ");
	//Exg3_->Draw("CPe1");
	Exg3_->Draw("Pe1");

	Exg4_ = new TGraphErrors(n,Exe5_,Exr5_,Exe_err5_,Exr_err5_);
	Exg4_->GetXaxis()->SetTitle("trigger efficiency");
	axis = Exg4_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exg4_->GetYaxis()->SetTitleOffset(1.2);
	Exg4_->GetYaxis()->SetTitle("trigger rate [MHz]");
	Exg4_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exg4_->SetMarkerStyle(kOpenTriangleUp);//kFullStar);
	Exg4_->SetMarkerColor(kBlue);
	Exg4_->SetLineColor(kBlue);
	Exg4_->SetMarkerSize(1.5);
	//c1->cd(4);
	Exg4_->SetFillColor(kWhite);
	Exg4_->SetTitle("5^{th} leading pt track-jet, max-bin, bin_size: +-1.5mm ");
	//Exg4_->Draw("CPe1");
	Exg4_->Draw("Pe1");

	Exga1_ = new TGraphErrors(n,Exea_2,Exra_2,Exe_erra_2,Exr_erra_2);
	Exga1_->GetXaxis()->SetTitle("trigger efficiency");
	axis = Exga1_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exga1_->GetYaxis()->SetTitleOffset(1.2);
	Exga1_->GetYaxis()->SetTitle("trigger rate [MHz]");
	Exga1_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exga1_->SetMarkerStyle(kOpenTriangleDown);//kFullCircle);
	Exga1_->SetMarkerColor(kBlack);
	Exga1_->SetLineColor(kBlack);
	Exga1_->SetMarkerSize(1.5);
	//c1->cd(4);
	Exga1_->SetFillColor(kWhite);
	Exga1_->SetTitle("2^{nd} leading pt track-jet, multi-bin, bin_size: +-1.5mm ");
	Exga1_->Draw("APe1");

	Exga2_ = new TGraphErrors(n,Exea_3,Exra_3,Exe_erra_3,Exr_erra_3);
	Exga2_->GetXaxis()->SetTitle("trigger efficiency");
	axis = Exga2_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exga2_->GetYaxis()->SetTitleOffset(1.2);
	Exga2_->GetYaxis()->SetTitle("trigger rate [MHz]");
	Exga2_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exga2_->SetMarkerStyle(kOpenTriangleDown);//kFullTriangleDown);
	Exga2_->SetMarkerColor(kRed);
	Exga2_->SetLineColor(kRed);
	Exga2_->SetMarkerSize(1.5);
	//c1->cd(4);
	Exga2_->SetFillColor(kWhite);
	Exga2_->SetTitle("3^{rd} leading pt track-jet, multi-bin, bin_size: +-1.5mm ");
	//Exga2_->Draw("CPe1");
	Exga2_->Draw("Pe1");

	Exga3_ = new TGraphErrors(n,Exea_4,Exra_4,Exe_erra_4,Exr_erra_4);
	Exga3_->GetXaxis()->SetTitle("trigger efficiency");
	axis = Exga3_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exga3_->GetYaxis()->SetTitleOffset(1.2);
	Exga3_->GetYaxis()->SetTitle("trigger rate [MHz]");
	Exga3_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exga3_->SetMarkerStyle(kOpenTriangleDown);//k);
	Exga3_->SetMarkerColor(kGreen+2);
	Exga3_->SetLineColor(kGreen+2);
	Exga3_->SetMarkerSize(1.5);
	//c1->cd(4);
	Exga3_->SetFillColor(kWhite);
	Exga3_->SetTitle("4^{th} leading pt track-jet, multi-bin, bin_size: +-1.5mm ");
	//Exga3_->Draw("CPe1");
	Exga3_->Draw("Pe1");

	Exga4_ = new TGraphErrors(n,Exea_5,Exra_5,Exe_erra_5,Exr_erra_5);
	Exga4_->GetXaxis()->SetTitle("trigger efficiency");
	axis = Exga4_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exga4_->GetYaxis()->SetTitleOffset(1.2);
	Exga4_->GetYaxis()->SetTitle("trigger rate [MHz]");
	Exga4_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exga4_->SetMarkerStyle(kOpenTriangleDown);//kFullStar);
	Exga4_->SetMarkerColor(kBlue);
	Exga4_->SetLineColor(kBlue);
	Exga4_->SetMarkerSize(1.5);
	//c1->cd(4);
	Exga4_->SetFillColor(kWhite);
	Exga4_->SetTitle("5^{th} leading pt track-jet, multi-bin, bin_size: +-1.5mm ");
	//Exga4_->Draw("CPe1");
	Exga4_->Draw("Pe1");

	Exgb1_ = new TGraphErrors(n,Exeb_2,Exrb_2,Exe_errb_2,Exr_errb_2);
	Exgb1_->GetXaxis()->SetTitle("trigger efficiency");
	axis = Exgb1_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exgb1_->GetYaxis()->SetTitleOffset(1.2);
	Exgb1_->GetYaxis()->SetTitle("trigger rate [MHz]");
	Exgb1_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exgb1_->SetMarkerStyle(kFullCircle);//kFullCircle);
	Exgb1_->SetMarkerColor(kBlack);
	Exgb1_->SetLineColor(kBlack);
	Exgb1_->SetMarkerSize(1.5);
	//c1->cd(4);
	Exgb1_->SetFillColor(kWhite);
	Exgb1_->SetTitle("2^{nd} leading pt track-jet no binning ");
	//Exgb1_->Draw("ACPe1");
	Exgb1_->Draw("APe1");

	Exgb2_ = new TGraphErrors(n,Exeb_3,Exrb_3,Exe_errb_3,Exr_errb_3);
	Exgb2_->GetXaxis()->SetTitle("trigger efficiency");
	axis = Exgb2_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exgb2_->GetYaxis()->SetTitleOffset(1.2);
	Exgb2_->GetYaxis()->SetTitle("trigger rate [MHz]");
	Exgb2_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exgb2_->SetMarkerStyle(kFullCircle);//kFullTriangleUp);
	Exgb2_->SetMarkerColor(kRed);
	Exgb2_->SetLineColor(kRed);
	Exgb2_->SetMarkerSize(1.5);
	//c1->cd(4);
	Exgb2_->SetFillColor(kWhite);
	Exgb2_->SetTitle("3^{rd} leading pt track-jet no binning ");
	//Exgb2_->Draw("CPe1");
	Exgb2_->Draw("Pe1");

	Exgb3_ = new TGraphErrors(n,Exeb_4,Exrb_4,Exe_errb_4,Exr_errb_4);
	Exgb3_->GetXaxis()->SetTitle("trigger efficiency");
	axis = Exgb3_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exgb3_->GetYaxis()->SetTitleOffset(1.2);
	Exgb3_->GetYaxis()->SetTitle("trigger rate [MHz]");
	Exgb3_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exgb3_->SetMarkerStyle(kFullCircle);//k);
	Exgb3_->SetMarkerColor(kGreen+2);
	Exgb3_->SetLineColor(kGreen+2);
	Exgb3_->SetMarkerSize(1.5);
	//c1->cd(4);
	Exgb3_->SetFillColor(kWhite);
	Exgb3_->SetTitle("4^{th} leading pt track-jet no binning ");
	//Exgb3_->Draw("CPe1");
	Exgb3_->Draw("Pe1");

	Exgb4_ = new TGraphErrors(n,Exeb_5,Exrb_5,Exe_errb_5,Exr_errb_5);
	Exgb4_->GetXaxis()->SetTitle("trigger efficiency");
	axis = Exgb4_->GetXaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exgb4_->GetYaxis()->SetTitleOffset(1.2);
	Exgb4_->GetYaxis()->SetTitle("trigger rate [MHz]");
	Exgb4_->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exgb4_->SetMarkerStyle(kFullCircle);//kFullStar);
	Exgb4_->SetMarkerColor(kBlue);
	Exgb4_->SetLineColor(kBlue);
	Exgb4_->SetMarkerSize(1.5);
	//c1->cd(4);
	Exgb4_->SetFillColor(kWhite);
	Exgb4_->SetTitle("5^{th} leading pt track-jet no binning ");
	//Exgb4_->Draw("CPe1");
	Exgb4_->Draw("Pe1");


	return;
}
void graph2D_1_5mm_Exmultibin()
{
	//! multi-bin +-1.5mm
	Exga2d_1 = new TGraph2DErrors(n,Exea_2,Exra_2,pt_threshold, Exe_erra_2, Exr_erra_2, 0);
	Exga2d_1->SetName("g2D_2nd_Exmaxpt");
	Exga2d_1->SetMarkerStyle(kFullDiamond);
	Exga2d_1->SetMarkerSize(STAR_SIZE);
	Exga2d_1->SetFillColor(kWhite);
	Exga2d_1->SetTitle("track-jet, multi-bin, 1.5mm");
	//Exga2d_1->SetTitle("2^{nd} leading pt track-jet, multi-bin, bin_size: 1.5mm");
	Exga2d_1->Draw("PCOLZ ERR");
	Exga2d_2 = new TGraph2DErrors(n,Exea_3,Exra_3,pt_threshold, Exe_erra_3, Exr_erra_3, 0);
	Exga2d_2->SetName("g2D_3rd_Exmaxpt");
	Exga2d_2->SetMarkerStyle(kFullDiamond);
	Exga2d_2->SetMarkerSize(STAR_SIZE);
	Exga2d_2->SetFillColor(kWhite);
	Exga2d_2->SetTitle("track-jet, multi-bin, 1.5mm");
	//Exga2d_2->SetTitle("3^{rd} leading pt track-jet, multi-bin, bin_size: 1.5mm");
	Exga2d_2->Draw("PCOLZ ERR");
	Exga2d_3 = new TGraph2DErrors(n,Exea_4,Exra_4,pt_threshold, Exe_erra_4, Exr_erra_4, 0);
	Exga2d_3->SetName("g2D_4th_Exmaxpt");
	Exga2d_3->SetMarkerStyle(kFullDiamond);
	Exga2d_3->SetMarkerSize(STAR_SIZE);
	Exga2d_3->SetFillColor(kWhite);
	Exga2d_3->SetTitle("track-jet, multi-bin, 1.5mm");
	//Exga2d_3->SetTitle("4^{th} leading pt track-jet, multi-bin, bin_size: 1.5mm");
	Exga2d_3->Draw("PCOLZ ERR");
	Exga2d_4 = new TGraph2DErrors(n,Exea_5,Exra_5,pt_threshold, Exe_erra_5, Exr_erra_5, 0);
	Exga2d_4->SetName("g2D_5th_Exmaxpt");
	Exga2d_4->SetMarkerStyle(kFullDiamond);
	Exga2d_4->SetMarkerSize(STAR_SIZE);
	Exga2d_4->SetFillColor(kWhite);
	Exga2d_4->SetTitle("track-jet, multi-bin, 1.5mm");
	//Exga2d_4->SetTitle("5^{th} leading pt track-jet, multi-bin, bin_size: 1.5mm");
	Exga2d_4->Draw("PCOLZ ERR");
	
	return;
	
}
void graph2D_1_5mm_Exmaxbin()
{
	//! max-bin +-1.5mm
	Exg2d_1 = new TGraph2DErrors(n,Exe2_,Exr2_,pt_threshold, Exe_err2_, Exr_err2_, 0);
	Exg2d_1->SetName("g2D_2nd_Exsumpt");
	Exg2d_1->SetMarkerStyle(kFullDiamond);
	Exg2d_1->SetMarkerSize(STAR_SIZE);
	Exg2d_1->SetFillColor(kWhite);
	Exg2d_1->SetTitle("track-jet, max-bin, +-1.5mm");
	//Exg2d_1->SetTitle("2^{nd} leading pt track-jet, max-bin, bin_size: +-1.5mm");
	Exg2d_1->Draw("PCOLZ ERR");
	Exg2d_2 = new TGraph2DErrors(n,Exe3_,Exr3_,pt_threshold, Exe_err3_, Exr_err3_, 0);
	Exg2d_2->SetName("g2D_3rd_Exsumpt");
	Exg2d_2->SetMarkerStyle(kFullDiamond);
	Exg2d_2->SetMarkerSize(STAR_SIZE);
	Exg2d_2->SetFillColor(kWhite);
	Exg2d_2->SetTitle("track-jet, max-bin, +-1.5mm");
	//Exg2d_2->SetTitle("3^{rd} leading pt track-jet, max-bin, bin_size: +-1.5mm");
	Exg2d_2->Draw("PCOLZ ERR");
	Exg2d_3 = new TGraph2DErrors(n,Exe4_,Exr4_,pt_threshold, Exe_err4_, Exr_err4_, 0);
	Exg2d_3->SetName("g2D_4th_Exsumpt");
	Exg2d_3->SetMarkerStyle(kFullDiamond);
	Exg2d_3->SetMarkerSize(STAR_SIZE);
	Exg2d_3->SetFillColor(kWhite);
	Exg2d_3->SetTitle("track-jet, max-bin, +-1.5mm");
	//Exg2d_3->SetTitle("4^{th} leading pt track-jet, max-bin, bin_size: +-1.5mm");
	Exg2d_3->Draw("PCOLZ ERR");
	Exg2d_4 = new TGraph2DErrors(n,Exe5_,Exr5_,pt_threshold, Exe_err5_, Exr_err5_, 0);
	Exg2d_4->SetName("g2D_5th_Exsumpt");
	Exg2d_4->SetMarkerStyle(kFullDiamond);
	Exg2d_4->SetMarkerSize(STAR_SIZE);
	Exg2d_4->SetFillColor(kWhite);
	Exg2d_4->SetTitle("track-jet, max-bin, +-1.5mm");
	//Exg2d_4->SetTitle("5^{th} leading pt track-jet, max-bin, bin_size: +-1.5mm");
	Exg2d_4->Draw("PCOLZ ERR");


	return;
}
