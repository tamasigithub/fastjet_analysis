
Double_t Exe2[n] = {0};   Double_t Exr2[n] = {0};
Double_t Exe3[n] = {0};   Double_t Exr3[n] = {0};
Double_t Exe4[n] = {0};   Double_t Exr4[n] = {0};
Double_t Exe5[n] = {0};   Double_t Exr5[n] = {0};
Double_t Exea2[n] = {0};   Double_t Exra2[n] = {0};
Double_t Exea3[n] = {0};   Double_t Exra3[n] = {0};
Double_t Exea4[n] = {0};   Double_t Exra4[n] = {0};
Double_t Exea5[n] = {0};   Double_t Exra5[n] = {0};
Double_t Exeb2[n] = {0};   Double_t Exrb2[n] = {0};
Double_t Exeb3[n] = {0};   Double_t Exrb3[n] = {0};
Double_t Exeb4[n] = {0};   Double_t Exrb4[n] = {0};
Double_t Exeb5[n] = {0};   Double_t Exrb5[n] = {0};

// corresponding errors
Double_t Exe_err2[n] = {0};   Double_t Exr_err2[n] = {0};
Double_t Exe_err3[n] = {0};   Double_t Exr_err3[n] = {0};
Double_t Exe_err4[n] = {0};   Double_t Exr_err4[n] = {0};
Double_t Exe_err5[n] = {0};   Double_t Exr_err5[n] = {0};
Double_t Exe_erra2[n] = {0};   Double_t Exr_erra2[n] = {0};
Double_t Exe_erra3[n] = {0};   Double_t Exr_erra3[n] = {0};
Double_t Exe_erra4[n] = {0};   Double_t Exr_erra4[n] = {0};
Double_t Exe_erra5[n] = {0};   Double_t Exr_erra5[n] = {0};
Double_t Exe_errb2[n] = {0};   Double_t Exr_errb2[n] = {0};
Double_t Exe_errb3[n] = {0};   Double_t Exr_errb3[n] = {0};
Double_t Exe_errb4[n] = {0};   Double_t Exr_errb4[n] = {0};
Double_t Exe_errb5[n] = {0};   Double_t Exr_errb5[n] = {0};

TH1F *ExE2 = nullptr;  
TH1F *ExE3 = nullptr;
TH1F *ExE4 = nullptr;
TH1F *ExE5 = nullptr;
TH1F *ExEa2= nullptr;
TH1F *ExEa3= nullptr;
TH1F *ExEa4= nullptr;
TH1F *ExEa5= nullptr;
TH1F *ExEb2= nullptr;
TH1F *ExEb3= nullptr;
TH1F *ExEb4= nullptr;
TH1F *ExEb5= nullptr;

TH1F *ExR2 =  nullptr;  
TH1F *ExR3 =  nullptr;
TH1F *ExR4 =  nullptr;
TH1F *ExR5 =  nullptr;
TH1F *ExRa2=  nullptr;
TH1F *ExRa3=  nullptr;
TH1F *ExRa4=  nullptr;
TH1F *ExRa5=  nullptr;
TH1F *ExRb2=  nullptr;
TH1F *ExRb3=  nullptr;
TH1F *ExRb4=  nullptr;
TH1F *ExRb5=  nullptr;

TGraphErrors *Exg1 = nullptr;
TGraphErrors *Exg2 = nullptr;
TGraphErrors *Exg3 = nullptr;
TGraphErrors *Exg4 = nullptr;
TGraphErrors *Exga1 = nullptr;
TGraphErrors *Exga2 = nullptr;
TGraphErrors *Exga3 = nullptr;
TGraphErrors *Exga4 = nullptr;
TGraphErrors *Exgb1 = nullptr;
TGraphErrors *Exgb2 = nullptr;
TGraphErrors *Exgb3 = nullptr;
TGraphErrors *Exgb4 = nullptr;

TGraph2DErrors *Exga2d1 = nullptr;
TGraph2DErrors *Exga2d2 = nullptr;
TGraph2DErrors *Exga2d3 = nullptr;
TGraph2DErrors *Exga2d4 = nullptr;

TGraph2DErrors *Exg2d1 = nullptr; 
TGraph2DErrors *Exg2d2 = nullptr; 
TGraph2DErrors *Exg2d3 = nullptr; 
TGraph2DErrors *Exg2d4 = nullptr; 

TGraph2DErrors *Exgb2d1 = nullptr;
TGraph2DErrors *Exgb2d2 = nullptr;
TGraph2DErrors *Exgb2d3 = nullptr;
TGraph2DErrors *Exgb2d4 = nullptr;

void fetch_7_5mmExTTT()
{
	TFile *Exf = new TFile(signal_file_name_2, "READ");
	//! sumpt approach
	ExE2 = (TH1F*)Exf->Get("h_tJeff2");
	ExE3 = (TH1F*)Exf->Get("h_tJeff3");
	ExE4 = (TH1F*)Exf->Get("h_tJeff4");
	ExE5 = (TH1F*)Exf->Get("h_tJeff5");
	//! Lpt bins approach
	ExEa2 = (TH1F*)Exf->Get("ha_tJeff2");
	ExEa3 = (TH1F*)Exf->Get("ha_tJeff3");
	ExEa4 = (TH1F*)Exf->Get("ha_tJeff4");
	ExEa5 = (TH1F*)Exf->Get("ha_tJeff5");
	//! no z-vertex bin 
	ExEb2 = (TH1F*)Exf->Get("hb_tJeff2");
	ExEb3 = (TH1F*)Exf->Get("hb_tJeff3");
	ExEb4 = (TH1F*)Exf->Get("hb_tJeff4");
	ExEb5 = (TH1F*)Exf->Get("hb_tJeff5");
	ExEb2->SetLineStyle(7);
	ExEb3->SetLineStyle(7);
	ExEb4->SetLineStyle(7);
	ExEb5->SetLineStyle(7);
	ExEb2->GetYaxis()->SetRangeUser(0,1.2);
	ExEb3->GetYaxis()->SetRangeUser(0,1.2);
	ExEb4->GetYaxis()->SetRangeUser(0,1.2);
	ExEb5->GetYaxis()->SetRangeUser(0,1.2);
	
	TFile *Exf1 = new TFile(MinBias_file_name_2, "READ");
	TTree *Ext1 = (TTree*)Exf1->Get("glob_jet");
	nevents = Ext1->GetEntries();

	//! sumpt approach
	ExR2 = (TH1F*)Exf1->Get("h_PUNLpt");
	ExR3 = (TH1F*)Exf1->Get("h_PUNNLpt");
	ExR4 = (TH1F*)Exf1->Get("h_PUNNNLpt");
	ExR5 = (TH1F*)Exf1->Get("h_PUNNNNLpt");
	//! Lpt bins approach
	ExRa2 = (TH1F*)Exf1->Get("ha_PUNLpt");
	ExRa3 = (TH1F*)Exf1->Get("ha_PUNNLpt");
	ExRa4 = (TH1F*)Exf1->Get("ha_PUNNNLpt");
	ExRa5 = (TH1F*)Exf1->Get("ha_PUNNNNLpt");
	//! no z-vertex bin 
	ExRb2 = (TH1F*)Exf1->Get("hb_PUNLpt");
	ExRb3 = (TH1F*)Exf1->Get("hb_PUNNLpt");
	ExRb4 = (TH1F*)Exf1->Get("hb_PUNNNLpt");
	ExRb5 = (TH1F*)Exf1->Get("hb_PUNNNNLpt");
	//! no z-vertex bin 
	ExRb2->SetLineStyle(7);
	ExRb3->SetLineStyle(7);
	ExRb4->SetLineStyle(7);
	ExRb5->SetLineStyle(7);
	//Rb2->Scale(1.0e3/(25*nevents));
	//Rb3->Scale(1.0e3/(25*nevents));
	//Rb4->Scale(1.0e3/(25*nevents));
	//Rb5->Scale(1.0e3/(25*nevents));
	
	ExRb2->GetYaxis()->SetTitle("trigger rate [MHz]");
	ExRb3->GetYaxis()->SetTitle("trigger rate [MHz]");
	ExRb4->GetYaxis()->SetTitle("trigger rate [MHz]");
	ExRb5->GetYaxis()->SetTitle("trigger rate [MHz]");
	
	ExRb2->GetYaxis()->SetRangeUser(1e-1,50);
	ExRb3->GetYaxis()->SetRangeUser(1e-1,50);
	ExRb4->GetYaxis()->SetRangeUser(1e-1,50);
	ExRb5->GetYaxis()->SetRangeUser(1e-1,50);
	

	nbinsE =  ExE2->GetNbinsX();
	nbinsR =  ExR2->GetNbinsX();
	nbinsEa = ExEa2->GetNbinsX();
	nbinsRa = ExRa2->GetNbinsX();
	nbinsEb = ExEb2->GetNbinsX();
	nbinsRb = ExRb2->GetNbinsX();
	if(debug) std::cout<<"nbinsE = " << nbinsE << ", nbinsR = " << nbinsR <<std::endl;
	assert(nbinsE == nbinsR);

	return;
}

void make_graphs_7_5mmExTTT()
{
	//g1 = new TGraphErrors(n,e2,r2,0,0);
	Exg1 = new TGraphErrors(n,Exr2,Exe2,Exr_err2,Exe_err2);
	Exg1->GetYaxis()->SetTitle("trigger efficiency");
	auto axis = Exg1->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exg1->GetXaxis()->SetTitleOffset(1.2);
	Exg1->GetXaxis()->SetTitle("trigger rate [MHz]");
	Exg1->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exg1->SetMarkerStyle(22);//kFullCircle);
	Exg1->SetMarkerColor(kBlack);
	Exg1->SetLineColor(kBlack);
	Exg1->SetMarkerSize(1.8);
	//c1->cd(4);
	Exg1->SetFillColor(kWhite);
	Exg1->SetTitle("2^{nd} leading pt track-jet, max-bin, bin_size: 7.5mm");
	//g1->Draw("ACPe1");
	Exg1->Draw("APe1");

	//g2 = new TGraphErrors(n,e3,r3,0,0);
	Exg2 = new TGraphErrors(n,Exr3,Exe3,Exr_err3,Exe_err3);
	Exg2->GetYaxis()->SetTitle("trigger efficiency");
	axis = Exg2->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exg2->GetXaxis()->SetTitleOffset(1.2);
	Exg2->GetXaxis()->SetTitle("trigger rate [MHz]");
	Exg2->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exg2->SetMarkerStyle(22);//kFullTriangleUp);
	Exg2->SetMarkerColor(kRed);
	Exg2->SetLineColor(kRed);
	Exg2->SetMarkerSize(1.8);
	//c1->cd(4);
	Exg2->SetFillColor(kWhite);
	Exg2->SetTitle("3^{rd} leading pt track-jet, max-bin, bin_size: 7.5mm ");
	//g2->Draw("CPe1");
	Exg2->Draw("Pe1");

	//g3 = new TGraphErrors(n,e4,r4,0,0);
	Exg3 = new TGraphErrors(n,Exr4,Exe4,Exr_err4,Exe_err4);
	Exg3->GetYaxis()->SetTitle("trigger efficiency");
	axis = Exg3->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exg3->GetXaxis()->SetTitleOffset(1.2);
	Exg3->GetXaxis()->SetTitle("trigger rate [MHz]");
	Exg3->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exg3->SetMarkerStyle(22);//k);
	Exg3->SetMarkerColor(kGreen+2);
	Exg3->SetLineColor(kGreen+2);
	Exg3->SetMarkerSize(1.8);
	//c1->cd(4);
	Exg3->SetFillColor(kWhite);
	Exg3->SetTitle("4^{th} leading pt track-jet, max-bin, bin_size: 7.5mm ");
	//g3->Draw("CPe1");
	Exg3->Draw("Pe1");

	//g4 = new TGraphErrors(n,e5,r5,0,0);
	Exg4 = new TGraphErrors(n,Exr5,Exe5,Exr_err5,Exe_err5);
	Exg4->GetYaxis()->SetTitle("trigger efficiency");
	axis = Exg4->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exg4->GetXaxis()->SetTitleOffset(1.2);
	Exg4->GetXaxis()->SetTitle("trigger rate [MHz]");
	Exg4->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exg4->SetMarkerStyle(22);//kFullStar);
	Exg4->SetMarkerColor(kBlue);
	Exg4->SetLineColor(kBlue);
	Exg4->SetMarkerSize(1.8);
	//c1->cd(4);
	Exg4->SetFillColor(kWhite);
	Exg4->SetTitle("5^{th} leading pt track-jet, max-bin, bin_size: 7.5mm ");
	//g4->Draw("CPe1");
	Exg4->Draw("Pe1");

	//ga1 = new TGraphErrors(n,ea2,ra2,0,0);
	Exga1 = new TGraphErrors(n,Exra2,Exea2,Exr_erra2,Exe_erra2);
	Exga1->GetYaxis()->SetTitle("trigger efficiency");
	axis = Exga1->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exga1->GetXaxis()->SetTitleOffset(1.2);
	Exga1->GetXaxis()->SetTitle("trigger rate [MHz]");
	Exga1->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exga1->SetMarkerStyle(kFullSquare);//kFullCircle);
	Exga1->SetMarkerColor(kBlack);
	Exga1->SetLineColor(kBlack);
	Exga1->SetMarkerSize(1.8);
	//c1->cd(4);
	Exga1->SetFillColor(kWhite);
	Exga1->SetTitle("2^{nd} leading pt track-jet, multi-bin, bin_size: 7.5mm");
	//g1->Draw("ACPe1");
	Exga1->Draw("APe1");

	//ga2 = new TGraphErrors(n,ea3,ra3,0,0);
	Exga2 = new TGraphErrors(n,Exra3,Exea3,Exr_erra3,Exe_erra3);
	Exga2->GetYaxis()->SetTitle("trigger efficiency");
	axis = Exga2->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exga2->GetXaxis()->SetTitleOffset(1.2);
	Exga2->GetXaxis()->SetTitle("trigger rate [MHz]");
	Exga2->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exga2->SetMarkerStyle(kFullSquare);//kFullTriangleUp);
	Exga2->SetMarkerColor(kRed);
	Exga2->SetLineColor(kRed);
	Exga2->SetMarkerSize(1.8);
	//c1->cd(4);
	Exga2->SetFillColor(kWhite);
	Exga2->SetTitle("3^{rd} leading pt track-jet, multi-bin, bin_size: 7.5mm ");
	//ga2->Draw("CPe1");
	Exga2->Draw("Pe1");

	//ga3 = new TGraphErrors(n,ea4,ra4,0,0);
	Exga3 = new TGraphErrors(n,Exra4,Exea4,Exr_erra4,Exe_erra4);
	Exga3->GetYaxis()->SetTitle("trigger efficiency");
	axis = Exga3->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exga3->GetXaxis()->SetTitleOffset(1.2);
	Exga3->GetXaxis()->SetTitle("trigger rate [MHz]");
	Exga3->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exga3->SetMarkerStyle(kFullSquare);//k);
	Exga3->SetMarkerColor(kGreen+2);
	Exga3->SetLineColor(kGreen+2);
	Exga3->SetMarkerSize(1.8);
	//c1->cd(4);
	Exga3->SetFillColor(kWhite);
	Exga3->SetTitle("4^{th} leading pt track-jet, multi-bin, bin_size: 7.5mm ");
	//ga3->Draw("CPe1");
	Exga3->Draw("Pe1");

	//ga4 = new TGraphErrors(n,ea5,ra5,0,0);
	Exga4 = new TGraphErrors(n,Exra5,Exea5,Exr_erra5,Exe_erra5);
	Exga4->GetYaxis()->SetTitle("trigger efficiency");
	axis = Exga4->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exga4->GetXaxis()->SetTitleOffset(1.2);
	Exga4->GetXaxis()->SetTitle("trigger rate [MHz]");
	Exga4->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exga4->SetMarkerStyle(kFullSquare);//kFullStar);
	Exga4->SetMarkerColor(kBlue);
	Exga4->SetLineColor(kBlue);
	Exga4->SetMarkerSize(1.8);
	//c1->cd(4);
	Exga4->SetFillColor(kWhite);
	Exga4->SetTitle("5^{th} leading pt track-jet, max-pt, bin_size: 7.5mm ");
	//ga4->Draw("CPe1");
	Exga4->Draw("Pe1");

	//gb1 = new TGraphErrors(n,eb2,rb2,0,0);
	Exgb1 = new TGraphErrors(n,Exrb2,Exeb2,Exr_errb2,Exe_errb2);
	Exgb1->Draw("AP");
	axis = Exgb1->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exgb1->GetYaxis()->SetTitleOffset(1.2);
	Exgb1->GetXaxis()->SetTitle("trigger rate [MHz]");
	Exgb1->GetYaxis()->SetTitle("trigger efficiency");
	Exgb1->GetYaxis()->CenterTitle();
	Exgb1->GetXaxis()->CenterTitle();
	Exgb1->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exgb1->SetMarkerStyle(kFullCircle);//kFullCircle);
	Exgb1->SetMarkerColor(kBlack);
	Exgb1->SetLineColor(kBlack);
	Exgb1->SetMarkerSize(1.5);
	//c1->cd(4);
	Exgb1->SetFillColor(kWhite);
	Exgb1->SetTitle("2^{nd} leading pt track-jet no binning ");
	//gb1->Draw("ACPe1");

	//gb2 = new TGraphErrors(n,eb3,rb3,0,0);
	Exgb2 = new TGraphErrors(n,Exrb3,Exeb3,Exr_errb3,Exe_errb3);
	Exgb2->Draw("AP");
	Exgb2->GetYaxis()->SetTitle("trigger efficiency");
	axis = Exgb2->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exgb2->GetXaxis()->SetTitleOffset(1.2);
	Exgb2->GetXaxis()->SetTitle("trigger rate [MHz]");
	Exgb2->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exgb2->SetMarkerStyle(kFullCircle);//kFullTriangleUp);
	Exgb2->SetMarkerColor(kRed);
	Exgb2->SetLineColor(kRed);
	Exgb2->SetMarkerSize(1.5);
	//c1->cd(4);
	Exgb2->SetFillColor(kWhite);
	Exgb2->SetTitle("3^{rd} leading pt track-jet no binning ");
	//gb2->Draw("CPe1");

	//gb3 = new TGraphErrors(n,eb4,rb4,0,0);
	Exgb3 = new TGraphErrors(n,Exrb4,Exeb4,Exr_errb4,Exe_errb4);
	Exgb3->Draw("AP");
	Exgb3->GetYaxis()->SetTitle("trigger efficiency");
	axis = Exgb3->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exgb3->GetXaxis()->SetTitleOffset(1.2);
	Exgb3->GetXaxis()->SetTitle("trigger rate [MHz]");
	Exgb3->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exgb3->SetMarkerStyle(kFullCircle);//k);
	Exgb3->SetMarkerColor(kGreen+2);
	Exgb3->SetLineColor(kGreen+2);
	Exgb3->SetMarkerSize(1.5);
	//c1->cd(4);
	Exgb3->SetFillColor(kWhite);
	Exgb3->SetTitle("4^{th} leading pt track-jet no binning ");
	//gb3->Draw("CPe1");

	//gb4 = new TGraphErrors(n,eb5,rb5,0,0);
	Exgb4 = new TGraphErrors(n,Exrb5,Exeb5,Exr_errb5,Exe_errb5);
	Exgb4->Draw("AP");
	Exgb4->GetYaxis()->SetTitle("trigger efficiency");
	axis = Exgb4->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	Exgb4->GetXaxis()->SetTitleOffset(1.2);
	Exgb4->GetXaxis()->SetTitle("trigger rate [MHz]");
	Exgb4->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Exgb4->SetMarkerStyle(kFullCircle);//kFullStar);
	Exgb4->SetMarkerColor(kBlue);
	Exgb4->SetLineColor(kBlue);
	Exgb4->SetMarkerSize(1.5);
	//c1->cd(4);
	Exgb4->SetFillColor(kWhite);
	Exgb4->SetTitle("5^{th} leading pt track-jet no binning ");
	//gb4->Draw("CPe1");
	return;
}

void graph2D_7_5mm_Exmultibin()
{
	//! multi-bin
	Exga2d1 = new TGraph2DErrors(n,Exea2,Exra2,pt_threshold, Exe_erra2, Exr_erra2, 0);
	Exga2d1->SetName("g2D2nd_Exmaxpt");
	//Exga2d1->GetXaxis()->SetTitle("trigger efficiency");
	//auto axis2d = Exga2d1->GetXaxis();
	//axis2d->SetLimits(Xmin_range, Xmax_range);
	//Exga2d1->GetYaxis()->SetTitleOffset(1.2);
	//Exga2d1->GetYaxis()->SetTitle("trigger rate [MHz]");
	//auto axisy2d = Exga2d1->GetYaxis();
	//axisy2d->SetRange(Ymin_range, Ymax_range);
	Exga2d1->SetMarkerStyle(kOpenSquare);
	Exga2d1->SetMarkerSize(TRIANGLEDOWN_SIZE);
	Exga2d1->SetFillColor(kWhite);
	Exga2d1->SetTitle("track-jet, multi-bin, 7.5mm");
	//Exga2d1->SetTitle("2^{nd} leading pt track-jet, multi-bin, bin_size: 7.5mm");
	Exga2d1->Draw("PCOLZ ERR");
	//TH1 *h2d = new TH2D();
	//h2d = Exga2d1->Project("xy");
	//h2d->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	//c_->SetLogy();
	//h2d->Draw("colz");
	Exga2d2 = new TGraph2DErrors(n,Exea3,Exra3,pt_threshold, Exe_erra3, Exr_erra3, 0);
	Exga2d2->SetName("g2D3rd_Exmaxpt");
	Exga2d2->SetMarkerStyle(kOpenSquare);
	Exga2d2->SetMarkerSize(TRIANGLEDOWN_SIZE);
	Exga2d2->SetFillColor(kWhite);
	Exga2d2->SetTitle("track-jet, multi-bin, 7.5mm");
	//Exga2d2->SetTitle("3^{rd} leading pt track-jet, multi-bin, bin_size: 7.5mm");
	Exga2d2->Draw("PCOLZ ERR");
	Exga2d3 = new TGraph2DErrors(n,Exea4,Exra4,pt_threshold, Exe_erra4, Exr_erra4, 0);
	Exga2d3->SetName("g2D4th_Exmaxpt");
	Exga2d3->SetMarkerStyle(kOpenSquare);
	Exga2d3->SetMarkerSize(TRIANGLEDOWN_SIZE);
	Exga2d3->SetFillColor(kWhite);
	Exga2d3->SetTitle("track-jet, multi-bin, 7.5mm");
	//Exga2d3->SetTitle("4^{th} leading pt track-jet, multi-bin, bin_size: 7.5mm");
	Exga2d3->Draw("PCOLZ ERR");
	Exga2d4 = new TGraph2DErrors(n,Exea5,Exra5,pt_threshold, Exe_erra5, Exr_erra5, 0);
	Exga2d4->SetName("g2D5th_Exmaxpt");
	Exga2d4->SetMarkerStyle(kOpenSquare);
	Exga2d4->SetMarkerSize(TRIANGLEDOWN_SIZE);
	Exga2d4->SetFillColor(kWhite);
	Exga2d4->SetTitle("track-jet, multi-bin, 7.5mm");
	//Exga2d4->SetTitle("5^{th} leading pt track-jet, multi-bin, bin_size: 7.5mm");
	Exga2d4->Draw("PCOLZ ERR");

	return;
}

void graph2D_7_5mm_Exmaxbin()
{
	//! max-bin
	Exg2d1 = new TGraph2DErrors(n,Exe2,Exr2,pt_threshold, Exe_err2, Exr_err2, 0);
	Exg2d1->SetName("g2D2nd_Exsumpt");
	Exg2d1->SetMarkerStyle(kOpenSquare);
	Exg2d1->SetMarkerSize(TRIANGLEUP_SIZE);
	Exg2d1->SetFillColor(kWhite);
	Exg2d1->SetTitle("track-jet, max-bin, 7.5mm");
	//Exg2d1->SetTitle("2^{nd} leading pt track-jet, max-bin, bin_size: 7.5mm");
	Exg2d1->Draw("PCOLZ ERR");
	Exg2d2 = new TGraph2DErrors(n,Exe3,Exr3,pt_threshold, Exe_err3, Exr_err3, 0);
	Exg2d2->SetName("g2D3rd_Exsumpt");
	Exg2d2->SetMarkerStyle(kOpenSquare);
	Exg2d2->SetMarkerSize(TRIANGLEUP_SIZE);
	Exg2d2->SetFillColor(kWhite);
	Exg2d2->SetTitle("track-jet, max-bin, 7.5mm");
	//Exg2d2->SetTitle("3^{rd} leading pt track-jet, max-bin, bin_size: 7.5mm");
	Exg2d2->Draw("PCOLZ ERR");
	Exg2d3 = new TGraph2DErrors(n,Exe4,Exr4,pt_threshold, Exe_err4, Exr_err4, 0);
	Exg2d3->SetName("g2D4th_Exsumpt");
	Exg2d3->SetMarkerStyle(kOpenSquare);
	Exg2d3->SetMarkerSize(TRIANGLEUP_SIZE);
	Exg2d3->SetFillColor(kWhite);
	Exg2d3->SetTitle("track-jet, max-bin, 7.5mm");
	//Exg2d3->SetTitle("4^{th} leading pt track-jet, max-bin, bin_size: 7.5mm");
	Exg2d3->Draw("PCOLZ ERR");
	Exg2d4 = new TGraph2DErrors(n,Exe5,Exr5,pt_threshold, Exe_err5, Exr_err5, 0);
	Exg2d4->SetName("g2D5th_Exsumpt");
	Exg2d4->SetMarkerStyle(kOpenSquare);
	Exg2d4->SetMarkerSize(TRIANGLEUP_SIZE);
	Exg2d4->SetFillColor(kWhite);
	Exg2d4->SetTitle("track-jet, max-bin, 7.5mm");
	//Exg2d4->SetTitle("5^{th} leading pt track-jet, max-bin, bin_size: 7.5mm");
	Exg2d4->Draw("PCOLZ ERR");
	

	return;
}

void graph2D_Exnozbin()
{
	//! no binning
	Exgb2d1 = new TGraph2DErrors(n,Exeb2,Exrb2,pt_threshold, Exe_errb2, Exr_errb2, 0);
	Exgb2d1->SetName("g2D2nd_Exnobin");
	//Exgb2d1->GetXaxis()->SetTitle("trigger efficiency");
	//auto axis2d = Exgb2d1->GetXaxis();
	//axis2d->SetLimits(Xmin_range, Xmax_range);
	//Exgb2d1->GetYaxis()->SetTitleOffset(1.2);
	//Exgb2d1->GetYaxis()->SetTitle("trigger rate [MHz]");
	//auto axisy2d = Exgb2d1->GetYaxis();
	//axisy2d->SetRange(Ymin_range, Ymax_range);
	Exgb2d1->SetMarkerStyle(kFullCircle);
	Exgb2d1->SetMarkerSize(1.4);
	Exgb2d1->SetFillColor(kWhite);
	Exgb2d1->SetTitle("track-jet, no z bin");
	//Exgb2d1->SetTitle("2^{nd} leading pt track-jet, no z bin");
	Exgb2d1->Draw("PCOLZ ERR");
	//TH1 *h2d = new TH2D();
	//h2d = Exgb2d1->Project("xy");
	//h2d->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	//c_->SetLogy();
	//h2d->Draw("colz");
	Exgb2d2 = new TGraph2DErrors(n,Exeb3,Exrb3,pt_threshold, Exe_errb3, Exr_errb3, 0);
	Exgb2d2->SetName("g2D3rd_Exnobin");
	Exgb2d2->SetMarkerStyle(kFullCircle);
	Exgb2d2->SetMarkerSize(1.4);
	Exgb2d2->SetFillColor(kWhite);
	Exgb2d2->SetTitle("track-jet, no z bin");
	//Exgb2d2->SetTitle("3^{rd} leading pt track-jet, no z bin");
	Exgb2d2->Draw("PCOLZ ERR");
	Exgb2d3 = new TGraph2DErrors(n,Exeb4,Exrb4,pt_threshold, Exe_errb4, Exr_errb4, 0);
	Exgb2d3->SetName("g2D4th_Exnobin");
	Exgb2d3->SetMarkerStyle(kFullCircle);
	Exgb2d3->SetMarkerSize(1.4);
	Exgb2d3->SetFillColor(kWhite);
	Exgb2d3->SetTitle("track-jet, no z bin");
	//Exgb2d3->SetTitle("4^{th} leading pt track-jet, no z bin");
	Exgb2d3->Draw("PCOLZ ERR");
	Exgb2d4 = new TGraph2DErrors(n,Exeb5,Exrb5,pt_threshold, Exe_errb5, Exr_errb5, 0);
	Exgb2d4->SetName("g2D5th_Exnobin");
	Exgb2d4->SetMarkerStyle(kFullCircle);
	Exgb2d4->SetMarkerSize(1.4);
	Exgb2d4->SetFillColor(kWhite);
	Exgb2d4->SetTitle("track-jet, no z bin");
	//Exgb2d4->SetTitle("5^{th} leading pt track-jet, no z bin");
	Exgb2d4->Draw("PCOLZ ERR");
	

	return;
}
