#include "Sensitivity_lambda.h"
#include <vector>
//! initialise a 2D array containing the derivative of the 
// fit function for the ith bin evaluated at a given k_lambda
double c[nGraphPts][nlambda]   = {0};
//! sigma_square[i] = number of background events[i] + Significance_SM[i] 
double sigma_square[nGraphPts] = {0};

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
		mygraph->Fit(fname, "S");
		funList.Add(myFunc);	
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
			c[i][k] = myfun->Derivative(k);
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
		if(i == nGraphPts -1) mygraph->GetYaxis()->SetTitle(Form("sensitivity (p_{T} #in {%d,%d})", (i+2)*10, (i+2)*50));
		else mygraph->GetYaxis()->SetTitle(Form("sensitivity (p_{T} #in {%d,%d})", (i+2)*10, (i+3)*10));
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

	TGraph *myGraph = new TGraph();
	for(int k = 0; k < nlambda; k++)
	{
	
		double sum_sens2_i = 0;
		for(int i = 0; i < nGraphPts; i ++)
		{
		
			sum_sens2_i += (c[i][k] * c[i][k])/sigma_square[i];
		}

		myGraph->SetPoint(k, lambda[k], std::sqrt(sum_sens2_i));

	}
	myGraph->SetName("Sum_sens_i");
	myGraph->GetXaxis()->SetTitle("k_{#lambda}");
	myGraph->GetYaxis()->SetTitleOffset(0.9);
	myGraph->GetYaxis()->SetTitle("Sensitivity #sqrt{ #sum_{i=20}^{500} c_{i}^{2}/#sigma_{i}^{2} }");
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

	return;
}
