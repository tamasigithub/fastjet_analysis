#include "Sensitivity_lambda.h"
#include <vector>

//! initialise a 2D array containing the derivative of the 
// fit function for the ith bin evaluated at a given k_lambda
double c[nGraphPts][nlambda]   = {0};
//! sigma_square[i] = number of background events[i] + Significance_SM[i] 
double sigma_square[nGraphPts] = {0};
double Sensitivity_withPt[nGraphPts] = {0};
TObjArray funList(0);
TString fname;
TString gname;
TFile *file2 = nullptr;
void Init_sigma_square()
{

	for(int i = 0; i < nGraphPts; i++)
	{
	
		//sigma_square[i] = (nAnaB[i]*norm_bckgnd) + Significance1[i];
		sigma_square[i] = (nAnaB[i]*norm_bckgnd) + (nAna1[i]*norm_signal1);
	}
	return;
}

void Fit_graphs(const char *filename = out_root_file_name)
{
	file2 = new TFile(filename, "READ");
	for(int i = 0; i < nGraphPts; i++)
	{
	
		fname.Form("fun%d", i);
		gname.Form("g%d", (i+2)*10);
		TF1 *myFunc = new TF1(fname, "pol2");
		//TGraph *mygraph = (TGraph*)graphList[i];
		TGraph *mygraph = (TGraph*)file2->Get(gname);
		mygraph->Draw("AP");
		mygraph->Fit(fname, "S");
		funList.Add(myFunc);
		myFunc->Draw("same");
			
		//c1->Print(out_file_,"pdf");
		delete mygraph;
	}
	return;	
}
void Init_ci()
{

	for(int i = 0; i < nGraphPts; i++)
	{
		gname.Form("Ci_%d", (i+2)*10);
		TGraph *myCi = new TGraph();
		for(int k = 0; k < nlambda; k++)
		{
		
			TF1 *myfun = (TF1*)funList[i];
			c[i][k] = myfun->Derivative(lambda[k]);
			//c[i][k] = (funList*)[i]->Derivative(k);
			std::cout<<"c[" <<i <<"]["<<k <<"] = " <<c[i][k] <<std::endl;	
			myCi->SetPoint(k, lambda[k], c[i][k]);

		}
		myCi->SetName(gname);

		myCi->GetXaxis()->SetTitle("k_{#lambda}");
		myCi->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
		if(i == nGraphPts -1) myCi->GetYaxis()->SetTitle(Form("c_{i} (p_{T} #in {%d,%d})", (i+2)*10, (i+2)*50));
		else myCi->GetYaxis()->SetTitle(Form("c_{i} (p_{T} #in {%d,%d})", (i+2)*10, (i+3)*10));
		myCi->GetYaxis()->SetTitleSize(TITLE_SIZE);
		myCi->GetXaxis()->SetTitleSize(TITLE_SIZE);
		myCi->GetYaxis()->CenterTitle();
		myCi->GetXaxis()->CenterTitle();
		myCi->SetMarkerStyle(kFullCircle);//kFullCircle);
		myCi->SetLineColor(kRed);
		myCi->SetLineWidth(LINE_WIDTH);
		myCi->SetMarkerSize(MARKER_SIZE);
		myCi->SetTitle("hh #rightarrow 4b dS_{i}/dk_{#lambda} Vs k_{#lambda}");
		myCi->Draw("ACPe1");
		max_range = myCi->GetHistogram()->GetMaximum()*1.1;
		min_range = myCi->GetHistogram()->GetMinimum()*1.1;
		myCi->GetYaxis()->SetRangeUser(min_range, max_range);
					
		c1->Print(out_file_,"pdf");
		myCi->Write();
	}
	return;
}

void plot_ithBinSensitivity2_Vs_klambda()
{

	for(int i = 0; i < nGraphPts; i++)
	{
		gname.Form("Sens_%d", (i+2)*10);
		TGraph *mygraph = new TGraph();
		for(int k = 0; k < nlambda; k++)
		{
			double sens2_i = (c[i][k] * c[i][k])/sigma_square[i];	
			mygraph->SetPoint(k, lambda[k], std::sqrt(sens2_i));
		}
		mygraph->SetName(gname);

		mygraph->GetXaxis()->SetTitle("k_{#lambda}");
		mygraph->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
		if(i == nGraphPts -1) mygraph->GetYaxis()->SetTitle(Form("sens. (p_{T} #in {%d,%d})", (i+2)*10, (i+2)*50));
		else mygraph->GetYaxis()->SetTitle(Form("sens. (p_{T} #in {%d,%d})", (i+2)*10, (i+3)*10));
		mygraph->GetYaxis()->SetTitleSize(TITLE_SIZE);
		mygraph->GetXaxis()->SetTitleSize(TITLE_SIZE);
		mygraph->GetYaxis()->CenterTitle();
		mygraph->GetXaxis()->CenterTitle();
		mygraph->SetMarkerStyle(kFullCircle);//kFullCircle);
		mygraph->SetLineColor(kRed);
		mygraph->SetLineWidth(LINE_WIDTH);
		mygraph->SetMarkerSize(MARKER_SIZE);
		mygraph->SetTitle("hh #rightarrow 4b #sqrt{c_{i}^{2}/#sigma_{i}^{2}} Vs k_{#lambda}");
		mygraph->Draw("ACPe1");
		max_range = mygraph->GetHistogram()->GetMaximum()*1.1;
		min_range = mygraph->GetHistogram()->GetMinimum()*0.4;
		mygraph->GetYaxis()->SetRangeUser(min_range, max_range);
					
		c1->Print(out_file_,"pdf");
		mygraph->Write();

	}
	return;
}

void plot_total_sensitivity_Vs_klambda()
{
	TLegend *leg = new TLegend(Xl1, Yu1, Xl2, Yu2);
	leg->SetFillStyle(FILL_STYLE);
	leg->SetBorderSize(BORDER_SIZE);
	leg->SetTextAlign(TEXT_ALIGN);
	leg->SetTextFont(TEXT_FONT);
	leg->SetTextSize(TEXT_SIZE);
	
	TLegend *legR = new TLegend(Xr1, Ym1, Xr2, Ym2);
	legR->SetFillStyle(FILL_STYLE);
	legR->SetBorderSize(BORDER_SIZE);
	legR->SetTextAlign(TEXT_ALIGN);
	legR->SetTextFont(TEXT_FONT);
	legR->SetTextSize(TEXT_SIZE);

	TMultiGraph *mg1 = new TMultiGraph();
	TMultiGraph *mg2 = new TMultiGraph();
	//! Total sensitivity graph Vs k_lambda
	TGraph *myGraph = new TGraph();
	for(int k = 0; k < nlambda; k++)
	{
		//! Total sensitivity Vs Pt threshold
		TString gname1;
		if(lambda[k] < 0){gname1.Form("Sens2_ithPt_klambda__%d",(int)std::abs(lambda[k]));}
		else {gname1.Form("Sens2_ithPt_klambda_%d", (int)std::abs(lambda[k]));}
		TH1D *Sens2_i = new TH1D(gname1,"sensitivity in the i^{th} p_{T} bin", nbinsMinus, pT_threshold);
	
		double tot_sens2_i = 0;
		for(int i = 0; i < nGraphPts; i++)
		{
			double sens2_i = (c[i][k] * c[i][k])/sigma_square[i];
			Sens2_i->SetBinContent(i+1, sens2_i);
			tot_sens2_i += (c[i][k] * c[i][k])/sigma_square[i];
		}

		myGraph->SetPoint(k, lambda[k], std::sqrt(tot_sens2_i));

		if(lambda[k] < 0){gname.Form("Sens_contri_klambda__%d",(int)std::abs(lambda[k]));}
		else {gname.Form("Sens_contri_klambda_%d", (int)std::abs(lambda[k]));}
		//TGraph *ithBin_contri = new TGraph();
		TH1D *ithBin_contri = new TH1D(gname,"i^{th} bin contribution", nbinsMinus, pT_threshold);
		for(int i = 0; i < nGraphPts; i++)
		{
		
			double sens2_i = (c[i][k] * c[i][k])/sigma_square[i];
			//ithBin_contri->SetPoint(i, pT_threshold[i], sens2_i/tot_sens2_i);
			ithBin_contri->SetBinContent(i+1, sens2_i/tot_sens2_i);
			

			//! 1st integral is bin 1(contents in 20-30 GeV) to 9(contents in 100 - 500 GeV)
			//! last integral is bin 9(contents in 100-500 GeV) to 9(contents in 100 - 500 GeV)
			Sensitivity_withPt[i] = std::sqrt(Sens2_i->Integral(i+1, nGraphPts));

		}
		
		TString gname2;	
		if(lambda[k] < 0){gname2.Form("Sens_withPt_klambda__%d",(int)std::abs(lambda[k]));}
		else {gname2.Form("Sens_withPt_klambda_%d", (int)std::abs(lambda[k]));}	
		TGraph *sens_withPt = new TGraph(nGraphPts,pT_threshold, Sensitivity_withPt);
		sens_withPt->SetName(gname2);
		sens_withPt->GetXaxis()->SetTitle("p_{T, bJ4} [GeV/c]");
		sens_withPt->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
		sens_withPt->GetYaxis()->SetTitle("#sqrt{ #sum_{i}^{500} sens._{i}^{2}}");
		sens_withPt->GetYaxis()->SetTitleSize(TITLE_SIZE);
		sens_withPt->GetXaxis()->SetTitleSize(TITLE_SIZE);
		sens_withPt->GetYaxis()->CenterTitle();
		sens_withPt->GetXaxis()->CenterTitle();
		sens_withPt->SetMarkerStyle(kFullCircle);//kFullCircle);
		sens_withPt->SetLineColor(lambda_colors[k]);
		sens_withPt->SetTitle(Form("sensitivity Vs p_{T, bJ4} threshold for k_{#lambda} = %.1f", lambda[k]));
		sens_withPt->SetLineWidth(LINE_WIDTH);
		sens_withPt->SetMarkerSize(MARKER_SIZE);
		sens_withPt->Draw("ACPe1");
		max_range = sens_withPt->GetHistogram()->GetMaximum()*1.1;
		min_range = sens_withPt->GetHistogram()->GetMinimum()*0.4;
		sens_withPt->GetYaxis()->SetRangeUser(min_range, max_range);	
		c1->Print(out_file_,"pdf");
		sens_withPt->Write();
		gPad->Write(gname2);
		mg1->Add(sens_withPt);

			
		//ithBin_contri->SetName(gname);
		ithBin_contri->GetXaxis()->SetRangeUser(20.0, 100.0);
		ithBin_contri->GetXaxis()->SetTitle("p_{T, bJ4} [GeV/c]");
		ithBin_contri->GetYaxis()->SetTitleOffset(YAXISTITLE_OFFSET);
		ithBin_contri->GetYaxis()->SetTitle("sens._{i}^{2}/ sens._{tot}^{2}");
		ithBin_contri->GetYaxis()->SetTitleSize(TITLE_SIZE);
		ithBin_contri->GetXaxis()->SetTitleSize(TITLE_SIZE);
		ithBin_contri->GetYaxis()->CenterTitle();
		ithBin_contri->GetXaxis()->CenterTitle();
		ithBin_contri->SetMarkerStyle(kFullCircle);//kFullCircle);
		ithBin_contri->SetLineColor(lambda_colors[k]);
		ithBin_contri->SetLineWidth(LINE_WIDTH);
		ithBin_contri->SetMarkerSize(MARKER_SIZE);
		ithBin_contri->SetTitle(Form("Sensitivity contributions from p_{T, bJ4} bins for k_{#lambda} = %.1f",lambda[k]));
		//ithBin_contri->Draw("ACPe1");
		//ithBin_contri->Sumw2();
		max_range = ithBin_contri->GetMaximum()*1.1;
		min_range = ithBin_contri->GetMinimum()*0.4;
		ithBin_contri->GetYaxis()->SetRangeUser(min_range, max_range);
		ithBin_contri->Draw("PC");
			
		c1->Print(out_file_,"pdf");
		gPad->Write(gname);
		ithBin_contri->Write("HPL");
		
		TGraph *mg_i = new TGraph(ithBin_contri);
		//std::cout<<"number of points before removal: " <<mg_i->GetN() <<std::endl;
		mg_i->RemovePoint(nGraphPts-1);
		//std::cout<<"number of points After removal: " <<mg_i->GetN() <<std::endl;
		mg_i->Draw("ACP");
		mg2->Add(mg_i,"ACP");
		//mg2->Add((TGraph*)ithBin_contri);
		
		//delete ithBin_contri;
		delete Sens2_i;
		//delete sens_withPt;
		
		//! draw a k_lambda legend.
		if(lambda[k] < 0)
		{
			leg->AddEntry(sens_withPt,Form("k_{#lambda} = %.1f", lambda[k]),"l");
			legR->AddEntry(sens_withPt,Form("k_{#lambda} = %.1f", lambda[k]),"l");
		}
		else
		{
			leg->AddEntry(sens_withPt,Form("k_{#lambda} =  %.1f", lambda[k]),"l");
			legR->AddEntry(sens_withPt,Form("k_{#lambda} =  %.1f", lambda[k]),"l");
		}


	}
	myGraph->SetName("Sum_sens_i");
	myGraph->GetXaxis()->SetTitle("k_{#lambda}");
	myGraph->GetYaxis()->SetTitleOffset(0.9);
	myGraph->GetYaxis()->SetTitle("sens. #sqrt{ #sum_{i=20}^{500} c_{i}^{2}/#sigma_{i}^{2} }");
	myGraph->GetYaxis()->SetTitleSize(TITLE_SIZE);
	myGraph->GetXaxis()->SetTitleSize(TITLE_SIZE);
	myGraph->GetYaxis()->CenterTitle();
	myGraph->GetXaxis()->CenterTitle();
	myGraph->SetMarkerStyle(kFullCircle);//kFullCircle);
	myGraph->SetLineColor(kRed);
	myGraph->SetLineWidth(LINE_WIDTH);
	myGraph->SetMarkerSize(MARKER_SIZE);
	myGraph->SetTitle("hh #rightarrow 4b Sensitivity Vs k_{#lambda}");
	myGraph->Draw("ACPe1");
	max_range = myGraph->GetHistogram()->GetMaximum()*1.1;
	min_range = myGraph->GetHistogram()->GetMinimum()*0.4;
	myGraph->GetYaxis()->SetRangeUser(min_range, max_range);
	myGraph->Write();
	c1->Print(out_file_,"pdf");
	delete myGraph;

	
	c1->cd();
	mg1->Draw("ACP");
	mg1->GetYaxis()->SetTitle("#sqrt{ #sum_{i}^{500} sens._{i}^{2}}");
	mg1->GetXaxis()->SetTitle("p_{T, bJ4} threshold [GeV/c]");
	mg1->GetXaxis()->CenterTitle();
	mg1->GetYaxis()->CenterTitle();
cms_E->Draw();	
signal_->Draw();	
ana_txt->Draw();	
legR->Draw();
	gPad->Modified();
	gPad->Update();
	mg1->Write("Sens_pTthre");
	gPad->Write("Sens_pTthre");
	c1->Print(out_file_,"pdf");
	c1->SaveAs("./analysis_plots/tex/Sens_pTthre.tex");
	

	//gPad->Modified();
	//mg2->GetXaxis()->SetLimits(20,100);
	c1->cd();
	mg2->Draw("ACP");
	mg2->GetYaxis()->SetTitle("sens._{i}^{2}/ sens._{tot}^{2}");
	mg2->GetXaxis()->SetTitle("p_{T, bJ4} [GeV/c]");
	mg2->GetXaxis()->CenterTitle();
	mg2->GetYaxis()->CenterTitle();
	max_range = mg2->GetHistogram()->GetMaximum()*1.3;
	min_range = mg2->GetHistogram()->GetMinimum()*0.4;
	mg2->GetYaxis()->SetRangeUser(min_range, max_range);
cms_E->Draw();	
signal_->Draw();	
ana_txt->Draw();	
leg->Draw();
	gPad->Modified();
	gPad->Update();

	mg2->Write("sens_ithBincontri");
	gPad->Write("sens_ithBincontri");
	c1->Print(out_file_,"pdf");
	c1->SaveAs("./analysis_plots/tex/sens_ithBincontri.tex");
	c1->Clear();
	leg->Draw();
	gPad->Write("k_lambdaLeg");

	return;
}
