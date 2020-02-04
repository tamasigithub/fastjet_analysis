#include "Legends.cpp"
#include "Sensitivity_fit.cpp"
void calculate_normalization()
{
	norm_signal1   = (IntLumi * four_b_Prob * ggFhhXsec1)/tot_MCevents;
	norm_signal0   = (IntLumi * four_b_Prob * ggFhhXsec0)/tot_MCevents;
	norm_signal_1  = (IntLumi * four_b_Prob * ggFhhXsec_1)/tot_MCevents;
	norm_signal_2  = (IntLumi * four_b_Prob * ggFhhXsec_2)/tot_MCevents;
	norm_signal2   = (IntLumi * four_b_Prob * ggFhhXsec2)/tot_MCevents;
	norm_signal2_5 = (IntLumi * four_b_Prob * ggFhhXsec2_5)/tot_MCevents;
	norm_signal3   = (IntLumi * four_b_Prob * ggFhhXsec3)/tot_MCevents;
	norm_bckgnd    = (IntLumi * pp4bXsec)/tot_MCevents_B;
	return;
}
void fetch_bckgnd()
{

	Ana_bjet4LPtB = (TH1D*)f->Get("Ana_bjet4LPtB");
	h4_bg   = Ana_bjet4LPtB->Rebin(nbinsMinus, "h4_bg", pt_bins);
	nbinsB = h4_bg->GetNbinsX();
	return;
}
void fetch_Ctr1()
{
	Ana_bjet4LPt1 = (TH1D*)f->Get("Ana_bjet4LPt1");
	h4_sig1 = Ana_bjet4LPt1->Rebin(nbinsMinus, "h4_sig1", pt_bins);
	nbins1 = h4_sig1->GetNbinsX();
	return;
}
void fetch_Ctr0()
{
	Ana_bjet4LPt0 = (TH1D*)f->Get("Ana_bjet4LPt0");
	h4_sig0 = Ana_bjet4LPt0->Rebin(nbinsMinus, "h4_sig0", pt_bins);
	nbins0 = h4_sig0->GetNbinsX();
	return;
}
void fetch_Ctr_1()
{
	Ana_bjet4LPt_1 = (TH1D*)f->Get("Ana_bjet4LPt_1");
	h4_sig_1 = Ana_bjet4LPt_1->Rebin(nbinsMinus, "h4_sig_1", pt_bins);
	nbins_1 = h4_sig_1->GetNbinsX();
	return;
}
void fetch_Ctr_2()
{
	Ana_bjet4LPt_2 = (TH1D*)f->Get("Ana_bjet4LPt_2");
	h4_sig_2 = Ana_bjet4LPt_2->Rebin(nbinsMinus, "h4_sig_2", pt_bins);
	nbins_2 = h4_sig_2->GetNbinsX();
	return;
}
void fetch_Ctr2()
{
	Ana_bjet4LPt2 = (TH1D*)f->Get("Ana_bjet4LPt2");
	h4_sig2 = Ana_bjet4LPt2->Rebin(nbinsMinus, "h4_sig2", pt_bins);
	nbins2 = h4_sig2->GetNbinsX();
	return;
}
void fetch_Ctr3()
{
	Ana_bjet4LPt3 = (TH1D*)f->Get("Ana_bjet4LPt3");
	h4_sig3 = Ana_bjet4LPt3->Rebin(nbinsMinus, "h4_sig3", pt_bins);
	nbins3 = h4_sig3->GetNbinsX();
	return;
}
void Init_FinalHistos()
{

	h4_SoverB1  = new TH1D("h4_SoverB1", "SoverB Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus, pt_bins);
	h4_Significance1  = new TH1D("h4_Significance1", "Significance Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus, pt_bins);
	h4_Significance2_1  = new TH1D("h4_Significance2_1", "Significance square Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus, pt_bins);
	
	h4_SoverB0  = new TH1D("h4_SoverB0", "SoverB Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus, pt_bins);
	h4_Significance0  = new TH1D("h4_Significance0", "Significance Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus, pt_bins);
	h4_Significance2_0  = new TH1D("h4_Significance2_0", "Significance square Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus, pt_bins);
	
	h4_SoverB_1  = new TH1D("h4_SoverB_1", "SoverB Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus, pt_bins);
	h4_Significance_1  = new TH1D("h4_Significance_1", "Significance Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus, pt_bins);
	h4_Significance2__1  = new TH1D("h4_Significance2__1", "Significance square Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus, pt_bins);
	
	h4_SoverB_2  = new TH1D("h4_SoverB_2", "SoverB Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus, pt_bins);
	h4_Significance_2  = new TH1D("h4_Significance_2", "Significance Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus, pt_bins);
	h4_Significance2__2  = new TH1D("h4_Significance2__2", "Significance square Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus, pt_bins);
	
	h4_SoverB2  = new TH1D("h4_SoverB2", "SoverB Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus, pt_bins);
	h4_Significance2  = new TH1D("h4_Significance2", "Significance Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus, pt_bins);
	h4_Significance2_2  = new TH1D("h4_Significance2_2", "Significance square Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus, pt_bins);
	
	h4_SoverB3  = new TH1D("h4_SoverB3", "SoverB Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus, pt_bins);
	h4_Significance3  = new TH1D("h4_Significance3", "Significance Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus, pt_bins);
	h4_Significance2_3  = new TH1D("h4_Significance2_3", "Significance square Vs 4^{th} jet p_{T} after analysis cuts; p_{T, bJ4} [GeV/c];", nbinsMinus, pt_bins);
	return;
}
void Fill_Arrays_histos()
{

	for(int i = 1; i < n + 1; i++)
	{
		pT_threshold[i-1] = h4_bg->GetBinLowEdge(i);
		nAnaB[i-1]        = h4_bg->GetBinContent(i);
		
		nAna1[i-1]        = h4_sig1->GetBinContent(i);
		nAna0[i-1]        = h4_sig0->GetBinContent(i);
		nAna_1[i-1]       = h4_sig_1->GetBinContent(i);
		nAna_2[i-1]       = h4_sig_2->GetBinContent(i);
		nAna2[i-1]        = h4_sig2->GetBinContent(i);
		nAna3[i-1]        = h4_sig3->GetBinContent(i);

		if(nAnaB[i-1] != 0)
		{
			SoverB1[i-1]      = (nAna1[i-1] * norm_signal1)/(nAnaB[i-1] * norm_bckgnd);
			Significance2_1[i-1] = std::pow(nAna1[i-1] * norm_signal1, 2)/(nAnaB[i-1] * norm_bckgnd);
			Significance1[i-1] = std::sqrt(Significance2_1[i-1]);
			
			SoverB0[i-1]      = (nAna0[i-1] * norm_signal0)/(nAnaB[i-1] * norm_bckgnd);
			Significance2_0[i-1] = std::pow(nAna0[i-1] * norm_signal0, 2)/(nAnaB[i-1] * norm_bckgnd);
			Significance0[i-1] = std::sqrt(Significance2_0[i-1]);
			
			SoverB_1[i-1]      = (nAna_1[i-1] * norm_signal_1)/(nAnaB[i-1] * norm_bckgnd);
			Significance2__1[i-1] = std::pow(nAna_1[i-1] * norm_signal_1, 2)/(nAnaB[i-1] * norm_bckgnd);
			Significance_1[i-1] = std::sqrt(Significance2__1[i-1]);
			
			SoverB_2[i-1]      = (nAna_2[i-1] * norm_signal_2)/(nAnaB[i-1] * norm_bckgnd);
			Significance2__2[i-1] = std::pow(nAna_2[i-1] * norm_signal_2, 2)/(nAnaB[i-1] * norm_bckgnd);
			Significance_2[i-1] = std::sqrt(Significance2__2[i-1]);
			
			SoverB2[i-1]      = (nAna2[i-1] * norm_signal2)/(nAnaB[i-1] * norm_bckgnd);
			Significance2_2[i-1] = std::pow(nAna2[i-1] * norm_signal2, 2)/(nAnaB[i-1] * norm_bckgnd);
			Significance2[i-1] = std::sqrt(Significance2_2[i-1]);
			
			SoverB3[i-1]      = (nAna3[i-1] * norm_signal3)/(nAnaB[i-1] * norm_bckgnd);
			Significance2_3[i-1] = std::pow(nAna3[i-1] * norm_signal3, 2)/(nAnaB[i-1] * norm_bckgnd);
			Significance3[i-1] = std::sqrt(Significance2_3[i-1]);
		
		}
		h4_SoverB1->SetBinContent(i, SoverB1[i-1]);
		h4_Significance1->SetBinContent(i, Significance1[i-1]);
		h4_Significance2_1->SetBinContent(i, Significance2_1[i-1]);
		
		h4_SoverB0->SetBinContent(i, SoverB0[i-1]);
		h4_Significance0->SetBinContent(i, Significance0[i-1]);
		h4_Significance2_0->SetBinContent(i, Significance2_0[i-1]);
		
		h4_SoverB_1->SetBinContent(i, SoverB_1[i-1]);
		h4_Significance_1->SetBinContent(i, Significance_1[i-1]);
		h4_Significance2__1->SetBinContent(i, Significance2__1[i-1]);
		
		h4_SoverB_2->SetBinContent(i, SoverB_2[i-1]);
		h4_Significance_2->SetBinContent(i, Significance_2[i-1]);
		h4_Significance2__2->SetBinContent(i, Significance2__2[i-1]);
		
		h4_SoverB2->SetBinContent(i, SoverB2[i-1]);
		h4_Significance2->SetBinContent(i, Significance2[i-1]);
		h4_Significance2_2->SetBinContent(i, Significance2_2[i-1]);
		
		h4_SoverB3->SetBinContent(i, SoverB3[i-1]);
		h4_Significance3->SetBinContent(i, Significance3[i-1]);
		h4_Significance2_3->SetBinContent(i, Significance2_3[i-1]);
	
	}
	return;
}
void Set_graphProps()
{

	g20->GetXaxis()->SetTitle("k_{#lambda}");
	g20->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	//g20->GetYaxis()->SetTitle("significance (p_{T} #in {20,30})");
	g20->GetYaxis()->SetTitle("S_{i} (p_{T} #in {20,30})");
	g20->GetYaxis()->SetTitleSize(TITLE_SIZE);
	g20->GetXaxis()->SetTitleSize(TITLE_SIZE);
	g20->GetYaxis()->CenterTitle();
	g20->GetXaxis()->CenterTitle();
	g20->SetMarkerStyle(kFullCircle);//kFullCircle);
	g20->SetLineColor(kRed);
	g20->SetLineWidth(LINE_WIDTH);
	g20->SetMarkerSize(MARKER_SIZE);
	//g20->SetTitle("hh #rightarrow 4b #sqrt{S_{i}^{2}/B_{i}} Vs k_{#lambda}");
	g20->SetTitle("hh #rightarrow 4b S_{i} Vs k_{#lambda}");
	g20->Draw("APe1");
	g20->Fit("pol2");
	max_range = g20->GetHistogram()->GetMaximum()*1.1;
	min_range = g20->GetHistogram()->GetMinimum()*0.4;
	g20->GetYaxis()->SetRangeUser(min_range, max_range);
	c1->Update();
	gPad->Write("c20");
	c1->Print(out_file_open,"pdf");

	//TCanvas *c2 = new TCanvas();
	g30->GetXaxis()->SetTitle("k_{#lambda}");
	g30->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	//g30->GetYaxis()->SetTitle("significance (p_{T} #in {30,40})");
	g30->GetYaxis()->SetTitle("S_{i} (p_{T} #in {30,40})");
	g30->GetYaxis()->SetTitleSize(TITLE_SIZE);
	g30->GetXaxis()->SetTitleSize(TITLE_SIZE);
	g30->GetYaxis()->CenterTitle();
	g30->GetXaxis()->CenterTitle();
	g30->SetMarkerStyle(kFullCircle);//kFullCircle);
	g30->SetLineColor(kRed);
	g30->SetLineWidth(LINE_WIDTH);
	g30->SetMarkerSize(MARKER_SIZE);
	//g30->SetTitle("hh #rightarrow 4b #sqrt{S_{i}^{2}/B_{i}} Vs k_{#lambda}");
	g30->SetTitle("hh #rightarrow 4b S_{i} Vs k_{#lambda}");
	g30->Draw("APe1");
	g30->Fit("pol2");
	max_range = g30->GetHistogram()->GetMaximum()*1.1;
	min_range = g30->GetHistogram()->GetMinimum()*0.4;
	g30->GetYaxis()->SetRangeUser(min_range, max_range);
	c1->Update();
	gPad->Write("c30");
	c1->Print(out_file_,"pdf");

	//TCanvas *c3 = new TCanvas();
	g40->GetXaxis()->SetTitle("k_{#lambda}");
	g40->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	//g40->GetYaxis()->SetTitle("significance (p_{T} #in {40,50})");
	g40->GetYaxis()->SetTitle("S_{i} (p_{T} #in {40,50})");
	g40->GetYaxis()->SetTitleSize(TITLE_SIZE);
	g40->GetXaxis()->SetTitleSize(TITLE_SIZE);
	g40->GetYaxis()->CenterTitle();
	g40->GetXaxis()->CenterTitle();
	g40->SetMarkerStyle(kFullCircle);//kFullCircle);
	g40->SetLineColor(kRed);
	g40->SetLineWidth(LINE_WIDTH);
	g40->SetMarkerSize(MARKER_SIZE);
	//g40->SetTitle("hh #rightarrow 4b #sqrt{S_{i}^{2}/B_{i}} Vs k_{#lambda}");
	g40->SetTitle("hh #rightarrow 4b S_{i} Vs k_{#lambda}");
	g40->Draw("APe1");
	g40->Fit("pol2");
	max_range = g40->GetHistogram()->GetMaximum()*1.1;
	min_range = g40->GetHistogram()->GetMinimum()*0.4;
	g40->GetYaxis()->SetRangeUser(min_range, max_range);
	c1->Update();
	gPad->Write("c40");
	c1->Print(out_file_,"pdf");

	//TCanvas *c4 = new TCanvas();
	g50->GetXaxis()->SetTitle("k_{#lambda}");
	g50->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	//g50->GetYaxis()->SetTitle("significance (p_{T} #in {50,60})");
	g50->GetYaxis()->SetTitle("S_{i} (p_{T} #in {50,60})");
	g50->GetYaxis()->SetTitleSize(TITLE_SIZE);
	g50->GetXaxis()->SetTitleSize(TITLE_SIZE);
	g50->GetYaxis()->CenterTitle();
	g50->GetXaxis()->CenterTitle();
	g50->SetMarkerStyle(kFullCircle);//kFullCircle);
	g50->SetLineColor(kRed);
	g50->SetLineWidth(LINE_WIDTH);
	g50->SetMarkerSize(MARKER_SIZE);
	//g50->SetTitle("hh #rightarrow 4b #sqrt{S_{i}^{2}/B_{i}} Vs k_{#lambda}");
	g50->SetTitle("hh #rightarrow 4b S_{i} Vs k_{#lambda}");
	g50->Draw("APe1");
	g50->Fit("pol2");
	max_range = g50->GetHistogram()->GetMaximum()*1.1;
	min_range = g50->GetHistogram()->GetMinimum()*0.4;
	g50->GetYaxis()->SetRangeUser(min_range, max_range);
	c1->Update();
	gPad->Write("c50");
	c1->Print(out_file_,"pdf");

	//TCanvas *c5 = new TCanvas();
	g60->GetXaxis()->SetTitle("k_{#lambda}");
	g60->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	//g60->GetYaxis()->SetTitle("significance (p_{T} #in {60,70})");
	g60->GetYaxis()->SetTitle("S_{i} (p_{T} #in {60,70})");
	g60->GetYaxis()->SetTitleSize(TITLE_SIZE);
	g60->GetXaxis()->SetTitleSize(TITLE_SIZE);
	g60->GetYaxis()->CenterTitle();
	g60->GetXaxis()->CenterTitle();
	g60->SetMarkerStyle(kFullCircle);//kFullCircle);
	g60->SetLineColor(kRed);
	g60->SetLineWidth(LINE_WIDTH);
	g60->SetMarkerSize(MARKER_SIZE);
	//g60->SetTitle("hh #rightarrow 4b #sqrt{S_{i}^{2}/B_{i}} Vs k_{#lambda}");
	g60->SetTitle("hh #rightarrow 4b S_{i} Vs k_{#lambda}");
	g60->Draw("APe1");
	g60->Fit("pol2");
	max_range = g60->GetHistogram()->GetMaximum()*1.1;
	min_range = g60->GetHistogram()->GetMinimum()*0.4;
	g60->GetYaxis()->SetRangeUser(min_range, max_range);
	c1->Update();
	gPad->Write("c60");
	c1->Print(out_file_,"pdf");

	//TCanvas *c6 = new TCanvas();
	g70->GetXaxis()->SetTitle("k_{#lambda}");
	g70->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	//g70->GetYaxis()->SetTitle("significance (p_{T} #in {70,80})");
	g70->GetYaxis()->SetTitle("S_{i} (p_{T} #in {70,80})");
	g70->GetYaxis()->SetTitleSize(TITLE_SIZE);
	g70->GetXaxis()->SetTitleSize(TITLE_SIZE);
	g70->GetYaxis()->CenterTitle();
	g70->GetXaxis()->CenterTitle();
	g70->SetMarkerStyle(kFullCircle);//kFullCircle);
	g70->SetLineColor(kRed);
	g70->SetLineWidth(LINE_WIDTH);
	g70->SetMarkerSize(MARKER_SIZE);
	//g70->SetTitle("hh #rightarrow 4b #sqrt{S_{i}^{2}/B_{i}} Vs k_{#lambda}");
	g70->SetTitle("hh #rightarrow 4b S_{i} Vs k_{#lambda}");
	g70->Draw("APe1");
	g70->Fit("pol2");
	max_range = g70->GetHistogram()->GetMaximum()*1.1;
	min_range = g70->GetHistogram()->GetMinimum()*0.4;
	g70->GetYaxis()->SetRangeUser(min_range, max_range);
	c1->Update();
	gPad->Write("c70");
	c1->Print(out_file_,"pdf");

	//TCanvas *c7 = new TCanvas();
	g80->GetXaxis()->SetTitle("k_{#lambda}");
	g80->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	//g80->GetYaxis()->SetTitle("significance (p_{T} #in {80,90})");
	g80->GetYaxis()->SetTitle("S_{i} (p_{T} #in {80,90})");
	g80->GetYaxis()->SetTitleSize(TITLE_SIZE);
	g80->GetXaxis()->SetTitleSize(TITLE_SIZE);
	g80->GetYaxis()->CenterTitle();
	g80->GetXaxis()->CenterTitle();
	g80->SetMarkerStyle(kFullCircle);//kFullCircle);
	g80->SetLineColor(kRed);
	g80->SetLineWidth(LINE_WIDTH);
	g80->SetMarkerSize(MARKER_SIZE);
	//g80->SetTitle("hh #rightarrow 4b #sqrt{S_{i}^{2}/B_{i}} Vs k_{#lambda}");
	g80->SetTitle("hh #rightarrow 4b S_{i} Vs k_{#lambda}");
	g80->Draw("APe1");
	g80->Fit("pol2");
	max_range = g80->GetHistogram()->GetMaximum()*1.1;
	min_range = g80->GetHistogram()->GetMinimum()*0.4;
	g80->GetYaxis()->SetRangeUser(min_range, max_range);
	c1->Update();
	gPad->Write("c80");
	c1->Print(out_file_,"pdf");
	
	//TCanvas *c8 = new TCanvas();
	g90->GetXaxis()->SetTitle("k_{#lambda}");
	g90->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	//g90->GetYaxis()->SetTitle("significance (p_{T} #in {90,100})");
	g90->GetYaxis()->SetTitle("S_{i} (p_{T} #in {90,100})");
	g90->GetYaxis()->SetTitleSize(TITLE_SIZE);
	g90->GetXaxis()->SetTitleSize(TITLE_SIZE);
	g90->GetYaxis()->CenterTitle();
	g90->GetXaxis()->CenterTitle();
	g90->SetMarkerStyle(kFullCircle);//kFullCircle);
	g90->SetLineColor(kRed);
	g90->SetLineWidth(LINE_WIDTH);
	g90->SetMarkerSize(MARKER_SIZE);
	//g90->SetTitle("hh #rightarrow 4b #sqrt{S_{i}^{2}/B_{i}} Vs k_{#lambda}");
	g90->SetTitle("hh #rightarrow 4b S_{i} Vs k_{#lambda}");
	g90->Draw("APe1");
	g90->Fit("pol2");
	max_range = g90->GetHistogram()->GetMaximum()*1.1;
	min_range = g90->GetHistogram()->GetMinimum()*0.4;
	g90->GetYaxis()->SetRangeUser(min_range, max_range);
	c1->Update();
	gPad->Write("c90");
	c1->Print(out_file_,"pdf");

	//TCanvas *c9 = new TCanvas();
	g100->GetXaxis()->SetTitle("k_{#lambda}");
	g100->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
	//g100->GetYaxis()->SetTitle("significance (p_{T} #in {100,500})");
	g100->GetYaxis()->SetTitle("S_{i} (p_{T} #in {100,500})");
	g100->GetYaxis()->SetTitleSize(TITLE_SIZE);
	g100->GetXaxis()->SetTitleSize(TITLE_SIZE);
	g100->GetYaxis()->CenterTitle();
	g100->GetXaxis()->CenterTitle();
	g100->SetMarkerStyle(kFullCircle);//kFullCircle);
	g100->SetLineColor(kRed);
	g100->SetLineWidth(LINE_WIDTH);
	g100->SetMarkerSize(MARKER_SIZE);
	//g100->SetTitle("hh #rightarrow 4b #sqrt{S_{i}^{2}/B_{i}} Vs k_{#lambda}");
	g100->SetTitle("hh #rightarrow 4b S_{i} Vs k_{#lambda}");
	g100->Draw("APe1");
	g100->Fit("pol2");
	max_range = g100->GetHistogram()->GetMaximum()*1.1;
	min_range = g100->GetHistogram()->GetMinimum()*0.4;
	g100->GetYaxis()->SetRangeUser(min_range, max_range);
	c1->Update();
	gPad->Write("c100");
	c1->Print(out_file_,"pdf");
	return;
}

void Fill_sigI_lambdaI_graphs()
{
	//for(int i = 0; i < nGraphPts; i++)
	//{
	//
	//	for(int k = 0; k < nlambda; k++)
	//	{
	//	
	//		(graphList*)[i]->SetPoint(k, lambda[k], vSignificance[k][i])
	//	}

	//}

	//g20->SetPoint(0, lambda[0], Significance_2[0]);
	//g20->SetPoint(1, lambda[1], Significance_1[0]);
	//g20->SetPoint(2, lambda[2], Significance0[0]);
	//g20->SetPoint(3, lambda[3], Significance1[0]);
	//g20->SetPoint(4, lambda[4], Significance2[0]);
	//g20->SetPoint(5, lambda[5], Significance3[0]);
	//
	//g30->SetPoint(0, lambda[0], Significance_2[1]);
	//g30->SetPoint(1, lambda[1], Significance_1[1]);
	//g30->SetPoint(2, lambda[2], Significance0[1]);
	//g30->SetPoint(3, lambda[3], Significance1[1]);
	//g30->SetPoint(4, lambda[4], Significance2[1]);
	//g30->SetPoint(5, lambda[5], Significance3[1]);

	//g40->SetPoint(0, lambda[0], Significance_2[2]);
	//g40->SetPoint(1, lambda[1], Significance_1[2]);
	//g40->SetPoint(2, lambda[2], Significance0[2]);
	//g40->SetPoint(3, lambda[3], Significance1[2]);
	//g40->SetPoint(4, lambda[4], Significance2[2]);
	//g40->SetPoint(5, lambda[5], Significance3[2]);
	//
	//std::cout<<"Significance_2[3] = " <<Significance_2[3] <<std::endl;
	//g50->SetPoint(0, lambda[0], Significance_2[3]);
	//g50->SetPoint(1, lambda[1], Significance_1[3]);
	//g50->SetPoint(2, lambda[2], Significance0[3]);
	//g50->SetPoint(3, lambda[3], Significance1[3]);
	//g50->SetPoint(4, lambda[4], Significance2[3]);
	//g50->SetPoint(5, lambda[5], Significance3[3]);
	//
	//g60->SetPoint(0, lambda[0], Significance_2[4]);
	//g60->SetPoint(1, lambda[1], Significance_1[4]);
	//g60->SetPoint(2, lambda[2], Significance0[4]);
	//g60->SetPoint(3, lambda[3], Significance1[4]);
	//g60->SetPoint(4, lambda[4], Significance2[4]);
	//g60->SetPoint(5, lambda[5], Significance3[4]);
	//
	//g70->SetPoint(0, lambda[0], Significance_2[5]);
	//g70->SetPoint(1, lambda[1], Significance_1[5]);
	//g70->SetPoint(2, lambda[2], Significance0[5]);
	//g70->SetPoint(3, lambda[3], Significance1[5]);
	//g70->SetPoint(4, lambda[4], Significance2[5]);
	//g70->SetPoint(5, lambda[5], Significance3[5]);
	//
	//g80->SetPoint(0, lambda[0], Significance_2[6]);
	//g80->SetPoint(1, lambda[1], Significance_1[6]);
	//g80->SetPoint(2, lambda[2], Significance0[6]);
	//g80->SetPoint(3, lambda[3], Significance1[6]);
	//g80->SetPoint(4, lambda[4], Significance2[6]);
	//g80->SetPoint(5, lambda[5], Significance3[6]);
	//
	//g90->SetPoint(0, lambda[0], Significance_2[7]);
	//g90->SetPoint(1, lambda[1], Significance_1[7]);
	//g90->SetPoint(2, lambda[2], Significance0[7]);
	//g90->SetPoint(3, lambda[3], Significance1[7]);
	//g90->SetPoint(4, lambda[4], Significance2[7]);
	//g90->SetPoint(5, lambda[5], Significance3[7]);
	//
	//g100->SetPoint(0, lambda[0], Significance_2[8]);
	//g100->SetPoint(1, lambda[1], Significance_1[8]);
	//g100->SetPoint(2, lambda[2], Significance0[8]);
	//g100->SetPoint(3, lambda[3], Significance1[8]);
	//g100->SetPoint(4, lambda[4], Significance2[8]);
	//g100->SetPoint(5, lambda[5], Significance3[8]);
	
	g20->SetPoint(0, lambda[0], nAna_2[0] * norm_signal_2);
	g20->SetPoint(1, lambda[1], nAna_1[0] * norm_signal_1);
	g20->SetPoint(2, lambda[2], nAna0[0] * norm_signal0);
	g20->SetPoint(3, lambda[3], nAna1[0] * norm_signal1);
	g20->SetPoint(4, lambda[4], nAna2[0] * norm_signal2);
	g20->SetPoint(5, lambda[5], nAna3[0] * norm_signal3);
	
	g30->SetPoint(0, lambda[0], nAna_2[1] * norm_signal_2);
	g30->SetPoint(1, lambda[1], nAna_1[1] * norm_signal_1);
	g30->SetPoint(2, lambda[2], nAna0[1] * norm_signal0);
	g30->SetPoint(3, lambda[3], nAna1[1] * norm_signal1);
	g30->SetPoint(4, lambda[4], nAna2[1] * norm_signal2);
	g30->SetPoint(5, lambda[5], nAna3[1] * norm_signal3);

	g40->SetPoint(0, lambda[0], nAna_2[2] * norm_signal_2);
	g40->SetPoint(1, lambda[1], nAna_1[2] * norm_signal_1);
	g40->SetPoint(2, lambda[2], nAna0[2] * norm_signal0);
	g40->SetPoint(3, lambda[3], nAna1[2] * norm_signal1);
	g40->SetPoint(4, lambda[4], nAna2[2] * norm_signal2);
	g40->SetPoint(5, lambda[5], nAna3[2] * norm_signal3);
	
	std::cout<<"nAna_2[3] = " <<nAna_2[3] * norm_signal_2<<std::endl;
	g50->SetPoint(0, lambda[0], nAna_2[3] * norm_signal_2);
	g50->SetPoint(1, lambda[1], nAna_1[3] * norm_signal_1);
	g50->SetPoint(2, lambda[2], nAna0[3] * norm_signal0);
	g50->SetPoint(3, lambda[3], nAna1[3] * norm_signal1);
	g50->SetPoint(4, lambda[4], nAna2[3] * norm_signal2);
	g50->SetPoint(5, lambda[5], nAna3[3] * norm_signal3);
	
	g60->SetPoint(0, lambda[0], nAna_2[4] * norm_signal_2);
	g60->SetPoint(1, lambda[1], nAna_1[4] * norm_signal_1);
	g60->SetPoint(2, lambda[2], nAna0[4] * norm_signal0);
	g60->SetPoint(3, lambda[3], nAna1[4] * norm_signal1);
	g60->SetPoint(4, lambda[4], nAna2[4] * norm_signal2);
	g60->SetPoint(5, lambda[5], nAna3[4] * norm_signal3);
	
	g70->SetPoint(0, lambda[0], nAna_2[5] * norm_signal_2);
	g70->SetPoint(1, lambda[1], nAna_1[5] * norm_signal_1);
	g70->SetPoint(2, lambda[2], nAna0[5] * norm_signal0);
	g70->SetPoint(3, lambda[3], nAna1[5] * norm_signal1);
	g70->SetPoint(4, lambda[4], nAna2[5] * norm_signal2);
	g70->SetPoint(5, lambda[5], nAna3[5] * norm_signal3);
	
	g80->SetPoint(0, lambda[0], nAna_2[6] * norm_signal_2);
	g80->SetPoint(1, lambda[1], nAna_1[6] * norm_signal_1);
	g80->SetPoint(2, lambda[2], nAna0[6] * norm_signal0);
	g80->SetPoint(3, lambda[3], nAna1[6] * norm_signal1);
	g80->SetPoint(4, lambda[4], nAna2[6] * norm_signal2);
	g80->SetPoint(5, lambda[5], nAna3[6] * norm_signal3);
	
	g90->SetPoint(0, lambda[0], nAna_2[7] * norm_signal_2);
	g90->SetPoint(1, lambda[1], nAna_1[7] * norm_signal_1);
	g90->SetPoint(2, lambda[2], nAna0[7] * norm_signal0);
	g90->SetPoint(3, lambda[3], nAna1[7] * norm_signal1);
	g90->SetPoint(4, lambda[4], nAna2[7] * norm_signal2);
	g90->SetPoint(5, lambda[5], nAna3[7] * norm_signal3);
	
	g100->SetPoint(0, lambda[0], nAna_2[8] * norm_signal_2);
	g100->SetPoint(1, lambda[1], nAna_1[8] * norm_signal_1);
	g100->SetPoint(2, lambda[2], nAna0[8] * norm_signal0);
	g100->SetPoint(3, lambda[3], nAna1[8] * norm_signal1);
	g100->SetPoint(4, lambda[4], nAna2[8] * norm_signal2);
	g100->SetPoint(5, lambda[5], nAna3[8] * norm_signal3);
	return;
}
void Delete_graphs()
{

	if(g20) delete g20;
	if(g30) delete g30;
	if(g40) delete g40;
	if(g50) delete g50;
	if(g60) delete g60;
	if(g70) delete g70;
	if(g80) delete g80;
	if(g90) delete g90;
	if(g100) delete g100;
	return;
}

void final_plot()
{

	Legends();
	calculate_normalization();

	//! open the input root file
	f = new TFile(root_file_name, "READ");

	fetch_bckgnd();
	fetch_Ctr1();
	fetch_Ctr0();
	fetch_Ctr_1();
	fetch_Ctr_2();
	fetch_Ctr2();
	fetch_Ctr3();

	assert(nbins1 == nbinsB);
	assert(nbins0 == nbinsB);
	assert(nbins_1 == nbinsB);
	assert(nbins_2 == nbinsB);
	assert(nbins2 == nbinsB);
	assert(nbins3 == nbinsB);
	std::cout<<"number of bins: " <<nbins1 <<std::endl;
	std::cout<<"number of bins: " <<nbins0 <<std::endl;
	std::cout<<"number of bins: " <<nbins_1 <<std::endl;
	std::cout<<"number of bins: " <<nbins_2 <<std::endl;
	std::cout<<"number of bins: " <<nbins2 <<std::endl;
	std::cout<<"number of bins: " <<nbins3 <<std::endl;
	std::cout<<"number of bins: " <<nbinsB <<std::endl;

	Init_FinalHistos();
	Fill_Arrays_histos();	
	
	//for(int i = 0; i < nGraphPts; i++)
	//{
	//	graph_name.Form("g%d", (i+2)*10);
	//	TGraph *mygraph = new TGraph();
	//	mygraph->SetName(graph_name);
	//	graphList.Add(mygraph);	
	//}
	g20  = new TGraph();
	g30  = new TGraph();
	g40  = new TGraph();
	g50  = new TGraph();
	g60  = new TGraph();
	g70  = new TGraph();
	g80  = new TGraph();
	g90  = new TGraph();
	g100 = new TGraph();

	//vSignificance[]

	//vSignificance[0] = {Significance_2};	
	//vSignificance[1] = {Significance_1};	
	//vSignificance[2] = {Significance0};	
	//vSignificance[3] = {Significance1};	
	//vSignificance[4] = {Significance2};	
	//vSignificance[5] = {Significance3};	
	Fill_sigI_lambdaI_graphs();
	
        sprintf(out_root_file_name,"%s/../root/%s.root",out_path,output_file_name);
	TFile *fout = new TFile(out_root_file_name,"RECREATE");
	
        sprintf(out_file_open,"%s/%s.pdf(",out_path,output_file_name);
        sprintf(out_file_,"%s/%s.pdf",out_path,output_file_name);
        sprintf(out_file_close,"%s/%s.pdf)",out_path,output_file_name);
	c1 = new TCanvas("c1","c1",800,800);
        c1->SetLeftMargin(0.13);


	gStyle->SetOptStat(0);

	Set_graphProps();
	//graphList.Write();
	g20->Write("g20");
	g30->Write("g30");
	g40->Write("g40");
	g50->Write("g50");
	g60->Write("g60");
	g70->Write("g70");
	g80->Write("g80");
	g90->Write("g90");
	g100->Write("g100");
	fout->Close();

	Delete_graphs();
	
	Fit_graphs();
        sprintf(out_root_file_name,"%s/../root/%s_final.root",out_path,output_file_name);
        TFile *finalout = new TFile(out_root_file_name,"RECREATE");
	Init_ci();
	Init_sigma_square();



	plot_ithBinSensitivity2_Vs_klambda();

	plot_total_sensitivity_Vs_klambda();
	
	finalout->Close();
	c1->Print(out_file_close,"pdf");


	return;
}
