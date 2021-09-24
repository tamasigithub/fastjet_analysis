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
	Norms_Signal[0] = norm_signal_2;
	Norms_Signal[1] = norm_signal_1;
	Norms_Signal[2] = norm_signal0;
	Norms_Signal[3] = norm_signal1;
	Norms_Signal[4] = norm_signal2;
	Norms_Signal[5] = norm_signal3;

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

void Fill_Arrays_histos()
{

	h4_bg->Scale(norm_bckgnd);
	h4_sig1->Scale(norm_signal1);
	h4_sig0->Scale(norm_signal0);
	h4_sig_1->Scale(norm_signal_1);
	h4_sig_2->Scale(norm_signal_2);
	h4_sig2->Scale(norm_signal2);
	h4_sig3->Scale(norm_signal3);	
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

		nAnaErrB[i-1]        = h4_bg->GetBinError(i);

		nAnaErr1[i-1]        = h4_sig1->GetBinError(i);
		nAnaErr0[i-1]        = h4_sig0->GetBinError(i);
		nAnaErr_1[i-1]       = h4_sig_1->GetBinError(i);
		nAnaErr_2[i-1]       = h4_sig_2->GetBinError(i);
		nAnaErr2[i-1]        = h4_sig2->GetBinError(i);
		nAnaErr3[i-1]        = h4_sig3->GetBinError(i);
		
		nAna[i-1][0]       = h4_sig_2->GetBinContent(i);
		nAna[i-1][1]       = h4_sig_1->GetBinContent(i);
		nAna[i-1][2]       = h4_sig0->GetBinContent(i);
		nAna[i-1][3]       = h4_sig1->GetBinContent(i);
		nAna[i-1][4]       = h4_sig2->GetBinContent(i);
		nAna[i-1][5]       = h4_sig3->GetBinContent(i);

		nAnaErr[i-1][0]    = h4_sig_2->GetBinError(i);
		nAnaErr[i-1][1]    = h4_sig_1->GetBinError(i);
		nAnaErr[i-1][2]    = h4_sig0->GetBinError(i);
		nAnaErr[i-1][3]    = h4_sig1->GetBinError(i);
		nAnaErr[i-1][4]    = h4_sig2->GetBinError(i);
		nAnaErr[i-1][5]    = h4_sig3->GetBinError(i);
	
	}	
	return;
}

void Fill_sigI_lambdaI_graphs()
{
	c1->Clear();
	for(int i = 0; i < nGraphPts; i++)
	{
		TString graph_name;
		graph_name.Form("g%.0f", pt_bins[i]);
		TGraphErrors *mygraph = new TGraphErrors(nlambda, lambda, nAna[i], 0, nAnaErr[i]);
		mygraph->SetName(graph_name);
		//graphList.Add(mygraph);	
		//for(int k = 0; k < nlambda; ++k)
		//{
		//	mygraph->SetPoint(k, lambda[k], nAna[i][k], 0, nAnaErr[i][k]);
		//}
		mygraph->GetXaxis()->SetTitle("k_{#lambda}");
		mygraph->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
		TString yaxis_name;
		yaxis_name.Form("S_{i} (p_{T} #in {%.0f,%.0f})",pt_bins[i], pt_bins[i+1]);
		mygraph->GetYaxis()->SetTitle(yaxis_name);
		mygraph->GetYaxis()->SetTitleSize(TITLE_SIZE);
		mygraph->GetXaxis()->SetTitleSize(TITLE_SIZE);
		mygraph->GetYaxis()->CenterTitle();
		mygraph->GetXaxis()->CenterTitle();
		mygraph->SetMarkerStyle(kFullCircle);//kFullCircle);
		mygraph->SetLineColor(kRed);
		mygraph->SetLineWidth(LINE_WIDTH);
		mygraph->SetMarkerSize(MARKER_SIZE);
		mygraph->SetTitle("hh #rightarrow 4b S_{i} Vs k_{#lambda}");
		mygraph->Draw("APe1");
		mygraph->Fit("pol2");
		max_range = mygraph->GetHistogram()->GetMaximum()*1.1;
		min_range = mygraph->GetHistogram()->GetMinimum()*0.4;
		mygraph->GetYaxis()->SetRangeUser(min_range, max_range);
		c1->Update();
		mygraph->Write();
		//gPad->Write("c80");
		c1->Print(out_file_,"pdf");
	}
	
	return;
}
void histVsPT()
{

	h4_bg->Scale(norm_bckgnd);
	h4_bg->Write("h4_bg");
	c1->Clear();
	c1->Divide(1,3);
	for(int k = 0; k < nlambda; ++k)
	{	
		TString gnamehist;
		if(lambda[k] < 0){gnamehist.Form("Ana_bjet4LPt_%d",(int)std::abs(lambda[k]));}
		else {gnamehist.Form("Ana_bjet4LPt%d", (int)std::abs(lambda[k]));}
		TH1D *hSOG = (TH1D*)f->Get(gnamehist);

		if(lambda[k] < 0){gnamehist.Form("h4_sig_%d",(int)std::abs(lambda[k]));}
		else {gnamehist.Form("h4_sig%d", (int)std::abs(lambda[k]));}
        	TH1 *h4_sigk = hSOG->Rebin(nbinsMinus, gnamehist, pt_bins);
		h4_sigk->Scale(Norms_Signal[k]);
		h4_sigk->GetXaxis()->SetTitle("p_{T, bJ4} [GeV/c]");
		h4_sigk->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
		h4_sigk->GetYaxis()->SetTitle("S");
		h4_sigk->GetYaxis()->SetTitleSize(TITLE_SIZE);
		h4_sigk->GetXaxis()->SetTitleSize(TITLE_SIZE);
		h4_sigk->GetYaxis()->CenterTitle();
		h4_sigk->GetXaxis()->CenterTitle();
		h4_sigk->SetMarkerStyle(kFullCircle);//kFullCircle);
		h4_sigk->SetLineColor(lambda_colors[k]);
		h4_sigk->SetLineWidth(LINE_WIDTH);
		h4_sigk->SetMarkerSize(MARKER_SIZE);
		h4_sigk->SetTitle(Form("S Vs p_{T, bJ4} bins for k_{#lambda} = %.1f",lambda[k]));
		max_range = h4_sigk->GetMaximum()*1.1;
		min_range = h4_sigk->GetMinimum()*0.4;
		h4_sigk->GetYaxis()->SetRangeUser(min_range, max_range);
		//h4_sigk->Draw("PC");
		c1->cd(1);
		h4_sigk->Draw("PLe1");
		gPad->SetLogx();
		h4_sigk->Write(gnamehist);
	
		if(lambda[k] < 0){gnamehist.Form("h4_SoverB_%d",(int)std::abs(lambda[k]));}
		else {gnamehist.Form("h4_SoverB%d", (int)std::abs(lambda[k]));}	
		TH1 *h4_SoverB = dynamic_cast<TH1*>(h4_sigk->Clone(gnamehist));
		h4_SoverB->Divide(h4_sigk, h4_bg, 1.0, 1.0);
		h4_SoverB->GetXaxis()->SetTitle("p_{T, bJ4} [GeV/c]");
		h4_SoverB->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
		h4_SoverB->GetYaxis()->SetTitle("S/B");
		h4_SoverB->GetYaxis()->SetTitleSize(TITLE_SIZE);
		h4_SoverB->GetXaxis()->SetTitleSize(TITLE_SIZE);
		h4_SoverB->GetYaxis()->CenterTitle();
		h4_SoverB->GetXaxis()->CenterTitle();
		h4_SoverB->SetMarkerStyle(kFullCircle);//kFullCircle);
		h4_SoverB->SetLineColor(lambda_colors[k]);
		h4_SoverB->SetLineWidth(LINE_WIDTH);
		h4_SoverB->SetMarkerSize(MARKER_SIZE);
		h4_SoverB->SetTitle(Form("S/B Vs p_{T, bJ4} bins for k_{#lambda} = %.1f",lambda[k]));
		max_range = h4_SoverB->GetMaximum()*1.1;
		min_range = h4_SoverB->GetMinimum()*0.4;
		h4_SoverB->GetYaxis()->SetRangeUser(min_range, max_range);
		//h4_SoverB->Draw("PC");
		c1->cd(2);
		h4_SoverB->Draw("PLe1");
		gPad->SetLogx();
		h4_SoverB->Write(gnamehist);
	
		if(lambda[k] < 0){gnamehist.Form("h4_S2overB_%d",(int)std::abs(lambda[k]));}
		else {gnamehist.Form("h4_S2overB%d", (int)std::abs(lambda[k]));}		

		TH1 *h4_S2 = dynamic_cast<TH1*>(h4_sigk->Clone("h4_S2"));
		h4_S2->Multiply(h4_sigk);
		
		TH1 *h4_S2overB = dynamic_cast<TH1*>(h4_S2->Clone(gnamehist));
		h4_S2overB->Divide(h4_S2, h4_bg, 1.0, 1.0);
		h4_S2overB->GetXaxis()->SetTitle("p_{T, bJ4} [GeV/c]");
		h4_S2overB->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
		h4_S2overB->GetYaxis()->SetTitle("S^{2}/B");
		h4_S2overB->GetYaxis()->SetTitleSize(TITLE_SIZE);
		h4_S2overB->GetXaxis()->SetTitleSize(TITLE_SIZE);
		h4_S2overB->GetYaxis()->CenterTitle();
		h4_S2overB->GetXaxis()->CenterTitle();
		h4_S2overB->SetMarkerStyle(kFullCircle);//kFullCircle);
		h4_S2overB->SetLineColor(lambda_colors[k]);
		h4_S2overB->SetLineWidth(LINE_WIDTH);
		h4_S2overB->SetMarkerSize(MARKER_SIZE);
		h4_S2overB->SetTitle(Form("S^{2}/B Vs p_{T, bJ4} bins for k_{#lambda} = %.1f",lambda[k]));
		max_range = h4_S2overB->GetMaximum()*1.1;
		min_range = h4_S2overB->GetMinimum()*0.4;
		h4_S2overB->GetYaxis()->SetRangeUser(min_range, max_range);
		//h4_S2overB->Draw("PC");
		c1->cd(3);
		h4_S2overB->Draw("PLe1");
		gPad->SetLogx();
		c1->Print(out_file_open,"pdf");
		h4_S2overB->Write(gnamehist);
		c1->SetLogx(0);
		
	}
	return;
}

void hist_Sig_ithBinContri()
{
	TString hi_name;
	c1->Clear();
	for(int k = nlambda-1; k >-1; --k)
	{
		if(lambda[k] < 0){hi_name.Form("h4_S2overB_%d",(int)std::abs(lambda[k]));}
		else {hi_name.Form("h4_S2overB%d", (int)std::abs(lambda[k]));}
		
		TH1D *hi = (TH1D*)file2->Get(hi_name);
		double integralK = hi->Integral();
		
		hi->Scale(1/integralK);
		hi->GetXaxis()->SetTitle("p_{T, bJ4} [GeV/c]");
		hi->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
		hi->GetYaxis()->SetTitle("Z_{i}^{2}/Z_{tot}^{2}");
		hi->GetYaxis()->SetTitleSize(TITLE_SIZE);
		hi->GetXaxis()->SetTitleSize(TITLE_SIZE);
		hi->GetYaxis()->CenterTitle();
		hi->GetXaxis()->CenterTitle();
		hi->SetMarkerStyle(kFullCircle);//kFullCircle);
		hi->SetLineColor(lambda_colors[k]);
		hi->SetLineWidth(LINE_WIDTH);
		hi->SetMarkerSize(MARKER_SIZE);
		hi->SetTitle(Form("i^{th} p_{T, bJ4} bin contribution to Significance for k_{#lambda} = %.1f",lambda[k]));
		max_range = hi->GetMaximum()*1.1;
		min_range = hi->GetMinimum()*0.4;
		hi->GetYaxis()->SetRangeUser(min_range, max_range);
		//hi->Draw("PC");
		if(lambda[k]==3.0)hi->Draw("PLe1");
		else hi->Draw("PLe1 same");
		c1->SetLogx();
		if(lambda[k] < 0){hi_name.Form("h4_S2overBi_%d",(int)std::abs(lambda[k]));}
		else {hi_name.Form("h4_S2overBi%d", (int)std::abs(lambda[k]));}
		hi->Write(hi_name);
	}
	c1->Print(out_file_,"pdf");
	c1->SetLogx(0);
	return;
}

void final_plot()
{

	TH1::SetDefaultSumw2(true);
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
	//! scale all the histos with the correct normalization
	Fill_Arrays_histos();	

        sprintf(out_root_file_name,"%s/../root/%s.root",out_path,output_file_name);
	TFile *fout = new TFile(out_root_file_name,"RECREATE");
	
        sprintf(out_file_open,"%s/%s.pdf(",out_path,output_file_name);
        sprintf(out_file_,"%s/%s.pdf",out_path,output_file_name);
        sprintf(out_file_close,"%s/%s.pdf)",out_path,output_file_name);
	c1 = new TCanvas("c1","c1",800,800);
        c1->SetLeftMargin(0.13);


	gStyle->SetOptStat(0);
	//! for Significance
	histVsPT();
	//! for Sensitivity
	Fill_sigI_lambdaI_graphs();
	
	fout->Close();
	
	//! open the first o/p root file as file2
	Fit_graphs();

        sprintf(out_root_file_name,"%s/../root/%s_final.root",out_path,output_file_name);
        TFile *finalout = new TFile(out_root_file_name,"RECREATE");

	//! for Significance
	hist_Sig_ithBinContri();

	//! for Sensitivity
	Init_ci();
	Init_sigma_square();

	plot_ithBinSensitivity2_Vs_klambda();

	plot_total_sensitivity_Vs_klambda();
	
	finalout->Close();
	c1->Print(out_file_close,"pdf");


	return;
}
