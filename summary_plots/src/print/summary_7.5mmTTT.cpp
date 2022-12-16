// efficiency and rate arrays for sumpT method
Double_t e2[n] = {0};   Double_t r2[n] = {0};
Double_t e3[n] = {0};   Double_t r3[n] = {0};
Double_t e4[n] = {0};   Double_t r4[n] = {0};
Double_t e5[n] = {0};   Double_t r5[n] = {0};
// efficiency and rate arrays for maxpT method
Double_t ea2[n] = {0};   Double_t ra2[n] = {0};
Double_t ea3[n] = {0};   Double_t ra3[n] = {0};
Double_t ea4[n] = {0};   Double_t ra4[n] = {0};
Double_t ea5[n] = {0};   Double_t ra5[n] = {0};
// efficiency and rate arrays for no z-binning method
Double_t eb2[n] = {0};   Double_t rb2[n] = {0};
Double_t eb3[n] = {0};   Double_t rb3[n] = {0};
Double_t eb4[n] = {0};   Double_t rb4[n] = {0};
Double_t eb5[n] = {0};   Double_t rb5[n] = {0};

// corresponding errors
Double_t e_err2[n] = {0};   Double_t r_err2[n] = {0};
Double_t e_err3[n] = {0};   Double_t r_err3[n] = {0};
Double_t e_err4[n] = {0};   Double_t r_err4[n] = {0};
Double_t e_err5[n] = {0};   Double_t r_err5[n] = {0};
Double_t e_erra2[n] = {0};   Double_t r_erra2[n] = {0};
Double_t e_erra3[n] = {0};   Double_t r_erra3[n] = {0};
Double_t e_erra4[n] = {0};   Double_t r_erra4[n] = {0};
Double_t e_erra5[n] = {0};   Double_t r_erra5[n] = {0};
Double_t e_errb2[n] = {0};   Double_t r_errb2[n] = {0};
Double_t e_errb3[n] = {0};   Double_t r_errb3[n] = {0};
Double_t e_errb4[n] = {0};   Double_t r_errb4[n] = {0};
Double_t e_errb5[n] = {0};   Double_t r_errb5[n] = {0};

TH1F *E2 = nullptr;  
TH1F *E3 = nullptr;
TH1F *E4 = nullptr;
TH1F *E5 = nullptr;
TH1F *Ea2= nullptr;
TH1F *Ea3= nullptr;
TH1F *Ea4= nullptr;
TH1F *Ea5= nullptr;
TH1F *Eb2= nullptr;
TH1F *Eb3= nullptr;
TH1F *Eb4= nullptr;
TH1F *Eb5= nullptr;

TH1F *R2 =  nullptr;  
TH1F *R3 =  nullptr;
TH1F *R4 =  nullptr;
TH1F *R5 =  nullptr;
TH1F *Ra2=  nullptr;
TH1F *Ra3=  nullptr;
TH1F *Ra4=  nullptr;
TH1F *Ra5=  nullptr;
TH1F *Rb2=  nullptr;
TH1F *Rb3=  nullptr;
TH1F *Rb4=  nullptr;
TH1F *Rb5=  nullptr;

TGraphErrors *g1 = nullptr;
TGraphErrors *g2 = nullptr;
TGraphErrors *g3 = nullptr;
TGraphErrors *g4 = nullptr;
TGraphErrors *ga1 = nullptr;
TGraphErrors *ga2 = nullptr;
TGraphErrors *ga3 = nullptr;
TGraphErrors *ga4 = nullptr;
TGraphErrors *gb1 = nullptr;
TGraphErrors *gb2 = nullptr;
TGraphErrors *gb3 = nullptr;
TGraphErrors *gb4 = nullptr;

TGraph2DErrors *ga2d1 = nullptr;
TGraph2DErrors *ga2d2 = nullptr;
TGraph2DErrors *ga2d3 = nullptr;
TGraph2DErrors *ga2d4 = nullptr;

TGraph2DErrors *g2d1 = nullptr; 
TGraph2DErrors *g2d2 = nullptr; 
TGraph2DErrors *g2d3 = nullptr; 
TGraph2DErrors *g2d4 = nullptr; 

TGraph2DErrors *gb2d1 = nullptr;
TGraph2DErrors *gb2d2 = nullptr;
TGraph2DErrors *gb2d3 = nullptr;
TGraph2DErrors *gb2d4 = nullptr;

void fetch_7_5mmTTT()
{
	TFile *f = new TFile(signal_file_name, "READ");
	//! sumpt approach
	E2 = (TH1F*)f->Get("h_tJeff2");
	E3 = (TH1F*)f->Get("h_tJeff3");
	E4 = (TH1F*)f->Get("h_tJeff4");
	E5 = (TH1F*)f->Get("h_tJeff5");
	//! Lpt bins approach
	Ea2 = (TH1F*)f->Get("ha_tJeff2");
	Ea3 = (TH1F*)f->Get("ha_tJeff3");
	Ea4 = (TH1F*)f->Get("ha_tJeff4");
	Ea5 = (TH1F*)f->Get("ha_tJeff5");
	//! no z-vertex bin 
	Eb2 = (TH1F*)f->Get("hb_tJeff2");
	Eb3 = (TH1F*)f->Get("hb_tJeff3");
	Eb4 = (TH1F*)f->Get("hb_tJeff4");
	Eb5 = (TH1F*)f->Get("hb_tJeff5");
	Eb2->SetLineStyle(7);
	Eb3->SetLineStyle(7);
	Eb4->SetLineStyle(7);
	Eb5->SetLineStyle(7);
	Eb2->GetYaxis()->SetRangeUser(0,1.2);
	Eb3->GetYaxis()->SetRangeUser(0,1.2);
	Eb4->GetYaxis()->SetRangeUser(0,1.2);
	Eb5->GetYaxis()->SetRangeUser(0,1.2);
	
	TFile *f1 = new TFile(MinBias_file_name, "READ");
	TTree *t1 = (TTree*)f1->Get("glob_jet");
	nevents = t1->GetEntries();

	//! sumpt approach
	R2 = (TH1F*)f1->Get("h_PUNLpt");
	R3 = (TH1F*)f1->Get("h_PUNNLpt");
	R4 = (TH1F*)f1->Get("h_PUNNNLpt");
	R5 = (TH1F*)f1->Get("h_PUNNNNLpt");
	//! Lpt bins approach
	Ra2 = (TH1F*)f1->Get("ha_PUNLpt");
	Ra3 = (TH1F*)f1->Get("ha_PUNNLpt");
	Ra4 = (TH1F*)f1->Get("ha_PUNNNLpt");
	Ra5 = (TH1F*)f1->Get("ha_PUNNNNLpt");
	//! no z-vertex bin 
	Rb2 = (TH1F*)f1->Get("hb_PUNLpt");
	Rb3 = (TH1F*)f1->Get("hb_PUNNLpt");
	Rb4 = (TH1F*)f1->Get("hb_PUNNNLpt");
	Rb5 = (TH1F*)f1->Get("hb_PUNNNNLpt");
	//! no z-vertex bin 
	Rb2->SetLineStyle(7);
	Rb3->SetLineStyle(7);
	Rb4->SetLineStyle(7);
	Rb5->SetLineStyle(7);
	//Rb2->Scale(1.0e3/(25*nevents));
	//Rb3->Scale(1.0e3/(25*nevents));
	//Rb4->Scale(1.0e3/(25*nevents));
	//Rb5->Scale(1.0e3/(25*nevents));
	
	Rb2->GetYaxis()->SetTitle("trigger rate [MHz]");
	Rb3->GetYaxis()->SetTitle("trigger rate [MHz]");
	Rb4->GetYaxis()->SetTitle("trigger rate [MHz]");
	Rb5->GetYaxis()->SetTitle("trigger rate [MHz]");
	
	Rb2->GetYaxis()->SetRangeUser(1e-1,50);
	Rb3->GetYaxis()->SetRangeUser(1e-1,50);
	Rb4->GetYaxis()->SetRangeUser(1e-1,50);
	Rb5->GetYaxis()->SetRangeUser(1e-1,50);
	

	TCanvas *c = new TCanvas();	
        TH1::SetDefaultSumw2(true);

	nbinsE = E2->GetNbinsX();
	nbinsR = R2->GetNbinsX();
	nbinsEa = Ea2->GetNbinsX();
	nbinsRa = Ra2->GetNbinsX();
	nbinsEb = Eb2->GetNbinsX();
	nbinsRb = Rb2->GetNbinsX();
	if(debug) std::cout<<"nbinsE = " << nbinsE << ", nbinsR = " << nbinsR <<std::endl;
	assert(nbinsE == nbinsR);

	return;
}

void make_graphs_7_5mmTTT()
{
	//g1 = new TGraphErrors(n,r2,e2,0,0);
	g1 = new TGraphErrors(n,r2,e2,r_err2,e_err2);
	g1->GetYaxis()->SetTitle("trigger efficiency");
	auto axis = g1->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	g1->GetXaxis()->SetTitleOffset(1.2);
	g1->GetXaxis()->SetTitle("trigger rate [MHz]");
	g1->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g1->SetMarkerStyle(22);//kFullCircle);
	g1->SetMarkerColor(kBlack);
	g1->SetLineColor(kBlack);
	g1->SetMarkerSize(1.8);
	//c1->cd(4);
	g1->SetFillColor(kWhite);
	g1->SetTitle("2^{nd} leading pt track-jet, max-bin, bin_size: 7.5mm");
	//g1->Draw("ACPe1");
	g1->Draw("APe1");

	//g2 = new TGraphErrors(n,r3,e3,0,0);
	g2 = new TGraphErrors(n,r3,e3,r_err3,e_err3);
	g2->GetYaxis()->SetTitle("trigger efficiency");
	axis = g2->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	g2->GetXaxis()->SetTitleOffset(1.2);
	g2->GetXaxis()->SetTitle("trigger rate [MHz]");
	g2->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g2->SetMarkerStyle(22);//kFullTriangleUp);
	g2->SetMarkerColor(kRed);
	g2->SetLineColor(kRed);
	g2->SetMarkerSize(1.8);
	//c1->cd(4);
	g2->SetFillColor(kWhite);
	g2->SetTitle("3^{rd} leading pt track-jet, max-bin, bin_size: 7.5mm ");
	//g2->Draw("CPe1");
	g2->Draw("Pe1");

	//g3 = new TGraphErrors(n,r4,e4,0,0);
	g3 = new TGraphErrors(n,r4,e4,r_err4,e_err4);
	g3->GetYaxis()->SetTitle("trigger efficiency");
	axis = g3->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	g3->GetXaxis()->SetTitleOffset(1.2);
	g3->GetXaxis()->SetTitle("trigger rate [MHz]");
	g3->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g3->SetMarkerStyle(22);//k);
	g3->SetMarkerColor(kGreen+2);
	g3->SetLineColor(kGreen+2);
	g3->SetMarkerSize(1.8);
	//c1->cd(4);
	g3->SetFillColor(kWhite);
	g3->SetTitle("4^{th} leading pt track-jet, max-bin, bin_size: 7.5mm ");
	//g3->Draw("CPe1");
	g3->Draw("Pe1");

	//g4 = new TGraphErrors(n,r5,e5,0,0);
	g4 = new TGraphErrors(n,r5,e5,r_err5,e_err5);
	g4->GetYaxis()->SetTitle("trigger efficiency");
	axis = g4->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	g4->GetXaxis()->SetTitleOffset(1.2);
	g4->GetXaxis()->SetTitle("trigger rate [MHz]");
	g4->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	g4->SetMarkerStyle(22);//kFullStar);
	g4->SetMarkerColor(kBlue);
	g4->SetLineColor(kBlue);
	g4->SetMarkerSize(1.8);
	//c1->cd(4);
	g4->SetFillColor(kWhite);
	g4->SetTitle("5^{th} leading pt track-jet, max-bin, bin_size: 7.5mm ");
	//g4->Draw("CPe1");
	g4->Draw("Pe1");

	//ga1 = new TGraphErrors(n,ra2,ea2,0,0);
	ga1 = new TGraphErrors(n,ra2,ea2,r_erra2,e_erra2);
	ga1->GetYaxis()->SetTitle("trigger efficiency");
	axis = ga1->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	ga1->GetXaxis()->SetTitleOffset(1.2);
	ga1->GetXaxis()->SetTitle("trigger rate [MHz]");
	ga1->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga1->SetMarkerStyle(kFullTriangleDown);//kFullCircle);
	ga1->SetMarkerColor(kBlack);
	ga1->SetLineColor(kBlack);
	ga1->SetMarkerSize(1.8);
	//c1->cd(4);
	ga1->SetFillColor(kWhite);
	ga1->SetTitle("2^{nd} leading pt track-jet, multi-bin, bin_size: 7.5mm");
	//g1->Draw("ACPe1");
	ga1->Draw("APe1");

	//ga2 = new TGraphErrors(n,ra3,ea3,0,0);
	ga2 = new TGraphErrors(n,ra3,ea3,r_erra3,e_erra3);
	ga2->GetYaxis()->SetTitle("trigger efficiency");
	axis = ga2->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	ga2->GetXaxis()->SetTitleOffset(1.2);
	ga2->GetXaxis()->SetTitle("trigger rate [MHz]");
	ga2->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga2->SetMarkerStyle(kFullTriangleDown);//kFullTriangleUp);
	ga2->SetMarkerColor(kRed);
	ga2->SetLineColor(kRed);
	ga2->SetMarkerSize(1.8);
	//c1->cd(4);
	ga2->SetFillColor(kWhite);
	ga2->SetTitle("3^{rd} leading pt track-jet, multi-bin, bin_size: 7.5mm ");
	//ga2->Draw("CPe1");
	ga2->Draw("Pe1");

	//ga3 = new TGraphErrors(n,ra4,ea4,0,0);
	ga3 = new TGraphErrors(n,ra4,ea4,r_erra4,e_erra4);
	ga3->GetYaxis()->SetTitle("trigger efficiency");
	axis = ga3->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	ga3->GetXaxis()->SetTitleOffset(1.2);
	ga3->GetXaxis()->SetTitle("trigger rate [MHz]");
	ga3->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga3->SetMarkerStyle(kFullTriangleDown);//k);
	ga3->SetMarkerColor(kGreen+2);
	ga3->SetLineColor(kGreen+2);
	ga3->SetMarkerSize(1.8);
	//c1->cd(4);
	ga3->SetFillColor(kWhite);
	ga3->SetTitle("4^{th} leading pt track-jet, multi-bin, bin_size: 7.5mm ");
	//ga3->Draw("CPe1");
	ga3->Draw("Pe1");

	//ga4 = new TGraphErrors(n,ra5,ea5,0,0);
	ga4 = new TGraphErrors(n,ra5,ea5,r_erra5,e_erra5);
	ga4->GetYaxis()->SetTitle("trigger efficiency");
	axis = ga4->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	ga4->GetXaxis()->SetTitleOffset(1.2);
	ga4->GetXaxis()->SetTitle("trigger rate [MHz]");
	ga4->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	ga4->SetMarkerStyle(kFullTriangleDown);//kFullStar);
	ga4->SetMarkerColor(kBlue);
	ga4->SetLineColor(kBlue);
	ga4->SetMarkerSize(1.8);
	//c1->cd(4);
	ga4->SetFillColor(kWhite);
	ga4->SetTitle("5^{th} leading pt track-jet, max-pt, bin_size: 7.5mm ");
	//ga4->Draw("CPe1");
	ga4->Draw("Pe1");

	//gb1 = new TGraphErrors(n,rb2,eb2,0,0);
	gb1 = new TGraphErrors(n,rb2,eb2,r_errb2,e_errb2);
	gb1->Draw("AP");
	axis = gb1->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	gb1->GetXaxis()->SetTitleOffset(1.2);
	gb1->GetXaxis()->SetTitle("trigger rate [MHz]");
	gb1->GetYaxis()->SetTitle("trigger efficiency");
	gb1->GetXaxis()->CenterTitle();
	gb1->GetYaxis()->CenterTitle();
	gb1->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb1->SetMarkerStyle(kFullCircle);//kFullCircle);
	gb1->SetMarkerColor(kBlack);
	gb1->SetLineColor(kBlack);
	gb1->SetMarkerSize(1.5);
	//c1->cd(4);
	gb1->SetFillColor(kWhite);
	gb1->SetTitle("2^{nd} leading pt track-jet no binning ");
	//gb1->Draw("ACPe1");

	//gb2 = new TGraphErrors(n,rb3,eb3,0,0);
	gb2 = new TGraphErrors(n,rb3,eb3,r_errb3,e_errb3);
	gb2->Draw("AP");
	gb2->GetYaxis()->SetTitle("trigger efficiency");
	axis = gb2->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	gb2->GetXaxis()->SetTitleOffset(1.2);
	gb2->GetXaxis()->SetTitle("trigger rate [MHz]");
	gb2->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb2->SetMarkerStyle(kFullCircle);//kFullTriangleUp);
	gb2->SetMarkerColor(kRed);
	gb2->SetLineColor(kRed);
	gb2->SetMarkerSize(1.5);
	//c1->cd(4);
	gb2->SetFillColor(kWhite);
	gb2->SetTitle("3^{rd} leading pt track-jet no binning ");
	//gb2->Draw("CPe1");

	//gb3 = new TGraphErrors(n,rb4,eb4,0,0);
	gb3 = new TGraphErrors(n,rb4,eb4,r_errb4,e_errb4);
	gb3->Draw("AP");
	gb3->GetYaxis()->SetTitle("trigger efficiency");
	axis = gb3->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	gb3->GetXaxis()->SetTitleOffset(1.2);
	gb3->GetXaxis()->SetTitle("trigger rate [MHz]");
	gb3->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb3->SetMarkerStyle(kFullCircle);//k);
	gb3->SetMarkerColor(kGreen+2);
	gb3->SetLineColor(kGreen+2);
	gb3->SetMarkerSize(1.5);
	//c1->cd(4);
	gb3->SetFillColor(kWhite);
	gb3->SetTitle("4^{th} leading pt track-jet no binning ");
	//gb3->Draw("CPe1");

	//gb4 = new TGraphErrors(n,rb5,eb5,0,0);
	gb4 = new TGraphErrors(n,rb5,eb5,r_errb5,e_errb5);
	gb4->Draw("AP");
	gb4->GetYaxis()->SetTitle("trigger efficiency");
	axis = gb4->GetYaxis();
	axis->SetLimits(Xmin_range, Xmax_range);
	gb4->GetXaxis()->SetTitleOffset(1.2);
	gb4->GetXaxis()->SetTitle("trigger rate [MHz]");
	gb4->GetXaxis()->SetRangeUser(Ymin_range, Ymax_range);
	gb4->SetMarkerStyle(kFullCircle);//kFullStar);
	gb4->SetMarkerColor(kBlue);
	gb4->SetLineColor(kBlue);
	gb4->SetMarkerSize(1.5);
	//c1->cd(4);
	gb4->SetFillColor(kWhite);
	gb4->SetTitle("5^{th} leading pt track-jet no binning ");
	//gb4->Draw("CPe1");
	return;
}

void graph2D_7_5mm_multibin()
{
	//! multi-bin
	ga2d1 = new TGraph2DErrors(n,ea2,ra2,pt_threshold, e_erra2, r_erra2, 0);
	ga2d1->SetName("g2D2nd_maxpt");
	//ga2d1->GetXaxis()->SetTitle("trigger efficiency");
	//auto axis2d = ga2d1->GetXaxis();
	//axis2d->SetLimits(Xmin_range, Xmax_range);
	//ga2d1->GetYaxis()->SetTitleOffset(1.2);
	//ga2d1->GetYaxis()->SetTitle("trigger rate [MHz]");
	//auto axisy2d = ga2d1->GetYaxis();
	//axisy2d->SetRange(Ymin_range, Ymax_range);
	ga2d1->SetMarkerStyle(kFullTriangleDown);
	ga2d1->SetMarkerSize(TRIANGLEDOWN_SIZE);
	ga2d1->SetFillColor(kWhite);
	ga2d1->SetTitle("track-jet, multi-bin, 7.5mm");
	//ga2d1->SetTitle("2^{nd} leading pt track-jet, multi-bin, bin_size: 7.5mm");
	ga2d1->Draw("PCOLZ ERR");
	//TH1 *h2d = new TH2D();
	//h2d = ga2d1->Project("xy");
	//h2d->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	//c_->SetLogy();
	//h2d->Draw("colz");
	ga2d2 = new TGraph2DErrors(n,ea3,ra3,pt_threshold, e_erra3, r_erra3, 0);
	ga2d2->SetName("g2D3rd_maxpt");
	ga2d2->SetMarkerStyle(kFullTriangleDown);
	ga2d2->SetMarkerSize(TRIANGLEDOWN_SIZE);
	ga2d2->SetFillColor(kWhite);
	ga2d2->SetTitle("track-jet, multi-bin, 7.5mm");
	//ga2d2->SetTitle("3^{rd} leading pt track-jet, multi-bin, bin_size: 7.5mm");
	ga2d2->Draw("PCOLZ ERR");
	ga2d3 = new TGraph2DErrors(n,ea4,ra4,pt_threshold, e_erra4, r_erra4, 0);
	ga2d3->SetName("g2D4th_maxpt");
	ga2d3->SetMarkerStyle(kFullTriangleDown);
	ga2d3->SetMarkerSize(TRIANGLEDOWN_SIZE);
	ga2d3->SetFillColor(kWhite);
	ga2d3->SetTitle("track-jet, multi-bin, 7.5mm");
	//ga2d3->SetTitle("4^{th} leading pt track-jet, multi-bin, bin_size: 7.5mm");
	ga2d3->Draw("PCOLZ ERR");
	ga2d4 = new TGraph2DErrors(n,ea5,ra5,pt_threshold, e_erra5, r_erra5, 0);
	ga2d4->SetName("g2D5th_maxpt");
	ga2d4->SetMarkerStyle(kFullTriangleDown);
	ga2d4->SetMarkerSize(TRIANGLEDOWN_SIZE);
	ga2d4->SetFillColor(kWhite);
	ga2d4->SetTitle("track-jet, multi-bin, 7.5mm");
	//ga2d4->SetTitle("5^{th} leading pt track-jet, multi-bin, bin_size: 7.5mm");
	ga2d4->Draw("PCOLZ ERR");

	return;
}

void graph2D_7_5mm_maxbin()
{
	//! max-bin
	g2d1 = new TGraph2DErrors(n,e2,r2,pt_threshold, e_err2, r_err2, 0);
	g2d1->SetName("g2D2nd_sumpt");
	g2d1->SetMarkerStyle(kFullTriangleUp);
	g2d1->SetMarkerSize(TRIANGLEUP_SIZE);
	g2d1->SetFillColor(kWhite);
	g2d1->SetTitle("track-jet, max-bin, 7.5mm");
	//g2d1->SetTitle("2^{nd} leading pt track-jet, max-bin, bin_size: 7.5mm");
	g2d1->Draw("PCOLZ ERR");
	g2d2 = new TGraph2DErrors(n,e3,r3,pt_threshold, e_err3, r_err3, 0);
	g2d2->SetName("g2D3rd_sumpt");
	g2d2->SetMarkerStyle(kFullTriangleUp);
	g2d2->SetMarkerSize(TRIANGLEUP_SIZE);
	g2d2->SetFillColor(kWhite);
	g2d2->SetTitle("track-jet, max-bin, 7.5mm");
	//g2d2->SetTitle("3^{rd} leading pt track-jet, max-bin, bin_size: 7.5mm");
	g2d2->Draw("PCOLZ ERR");
	g2d3 = new TGraph2DErrors(n,e4,r4,pt_threshold, e_err4, r_err4, 0);
	g2d3->SetName("g2D4th_sumpt");
	g2d3->SetMarkerStyle(kFullTriangleUp);
	g2d3->SetMarkerSize(TRIANGLEUP_SIZE);
	g2d3->SetFillColor(kWhite);
	g2d3->SetTitle("track-jet, max-bin, 7.5mm");
	//g2d3->SetTitle("4^{th} leading pt track-jet, max-bin, bin_size: 7.5mm");
	g2d3->Draw("PCOLZ ERR");
	g2d4 = new TGraph2DErrors(n,e5,r5,pt_threshold, e_err5, r_err5, 0);
	g2d4->SetName("g2D5th_sumpt");
	g2d4->SetMarkerStyle(kFullTriangleUp);
	g2d4->SetMarkerSize(TRIANGLEUP_SIZE);
	g2d4->SetFillColor(kWhite);
	g2d4->SetTitle("track-jet, max-bin, 7.5mm");
	//g2d4->SetTitle("5^{th} leading pt track-jet, max-bin, bin_size: 7.5mm");
	g2d4->Draw("PCOLZ ERR");
	

	return;
}

void graph2D_nozbin()
{
	//! no binning
	gb2d1 = new TGraph2DErrors(n,eb2,rb2,pt_threshold, e_errb2, r_errb2, 0);
	gb2d1->SetName("g2D2nd_nobin");
	//gb2d1->GetXaxis()->SetTitle("trigger efficiency");
	//auto axis2d = gb2d1->GetXaxis();
	//axis2d->SetLimits(Xmin_range, Xmax_range);
	//gb2d1->GetYaxis()->SetTitleOffset(1.2);
	//gb2d1->GetYaxis()->SetTitle("trigger rate [MHz]");
	//auto axisy2d = gb2d1->GetYaxis();
	//axisy2d->SetRange(Ymin_range, Ymax_range);
	gb2d1->SetMarkerStyle(kFullCircle);
	gb2d1->SetMarkerSize(1.4);
	gb2d1->SetFillColor(kWhite);
	gb2d1->SetTitle("track-jet, no z bin");
	//gb2d1->SetTitle("2^{nd} leading pt track-jet, no z bin");
	gb2d1->Draw("PCOLZ ERR");
	//TH1 *h2d = new TH2D();
	//h2d = gb2d1->Project("xy");
	//h2d->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	//c_->SetLogy();
	//h2d->Draw("colz");
	gb2d2 = new TGraph2DErrors(n,eb3,rb3,pt_threshold, e_errb3, r_errb3, 0);
	gb2d2->SetName("g2D3rd_nobin");
	gb2d2->SetMarkerStyle(kFullCircle);
	gb2d2->SetMarkerSize(1.4);
	gb2d2->SetFillColor(kWhite);
	gb2d2->SetTitle("track-jet, no z bin");
	//gb2d2->SetTitle("3^{rd} leading pt track-jet, no z bin");
	gb2d2->Draw("PCOLZ ERR");
	gb2d3 = new TGraph2DErrors(n,eb4,rb4,pt_threshold, e_errb4, r_errb4, 0);
	gb2d3->SetName("g2D4th_nobin");
	gb2d3->SetMarkerStyle(kFullCircle);
	gb2d3->SetMarkerSize(1.4);
	gb2d3->SetFillColor(kWhite);
	gb2d3->SetTitle("track-jet, no z bin");
	//gb2d3->SetTitle("4^{th} leading pt track-jet, no z bin");
	gb2d3->Draw("PCOLZ ERR");
	gb2d4 = new TGraph2DErrors(n,eb5,rb5,pt_threshold, e_errb5, r_errb5, 0);
	gb2d4->SetName("g2D5th_nobin");
	gb2d4->SetMarkerStyle(kFullCircle);
	gb2d4->SetMarkerSize(1.4);
	gb2d4->SetFillColor(kWhite);
	gb2d4->SetTitle("track-jet, no z bin");
	//gb2d4->SetTitle("5^{th} leading pt track-jet, no z bin");
	gb2d4->Draw("PCOLZ ERR");
	

	return;
}
