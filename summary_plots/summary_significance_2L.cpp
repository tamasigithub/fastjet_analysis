//! Final summary plot of signal significance (S/sqrt(B)) using the 4th leading Jet pT (Generated jet pT)
//! Using two different methods: one bin and differential sum (with binning as in the pheno analysis)
//! for events triggered using the 3rd leading jet (recontructed jet pT: +-1.5mm TTT-jets and emulated calo jets)
//! Trigger thresholds for the 3rd leading jet at 4MHz: TTT-jet: 32 GeV Calo: 753 GeV
//! Normalization of the signal and background events are:
//
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include <unordered_map>

#include "TROOT.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TLegend.h"
#include "TGraphErrors.h"
#include "TPostScript.h"

#include "TAxis.h"
#include "TGaxis.h"
#include "TF1.h"
//CHANGE
#include "init_2L.h"
void init_eve(int &i)
{
	/* event_id
	 * 4th leading b-jet with correct binning
	 * */
	trees[i]->SetBranchAddress("eventNums", &eve_nums[i]);
	trees[i]->SetBranchAddress("secondL_bJpT", &L2_JpT[i]);
	trees[i]->SetBranchAddress("thirdL_bJpT", &L3_JpT[i]);
	for(int j = 0; j < trees[i]->GetEntries(); j++)
	{
		trees[i]->GetEntry(j);
		//! fill unordered_map for signal and BG events
		gen_4th_bJpT[i][eve_nums[i]] = L2_JpT[i];//CHANGE
		//std::cout<<"event_number : " << eve_nums[i] << std::endl;
	}
	return;
}
void init_binTree(int &i)
{	
	/* event_id
	 * 3rd leading jet
	 * */
	trees[i]->SetBranchAddress("event", &eve_nums[i]);
	trees[i]->SetBranchAddress("3L", &L3_JpT[i]);
	trees[i]->SetBranchAddress("2L", &L2_JpT[i]);
	char h_name[1024];
	if(i < 4)// 2 or 3 (TTT)
	{
		pT_threshold = TTT_for3L;//32e3;//MeV
		sprintf(h_name,"TTT_4LbJpT_%d",i%2);
		h_trig_4L_bJpT.push_back(new TH1F(h_name, "2^{nd} b-jet p_{T} of the 3L- TTT triggered jet;p_{T, bJ2} [GeV/c];",nbinsMinus, pt_bins));
		sprintf(h_name,"GenTTT_4LbJpT_%d",i%2);
		h_4L_bJpT.push_back(new TH1F(h_name, "2^{nd} b-jet p_{T};p_{T, bJ2} [GeV/c];",nbinsMinus, pt_bins));
		sprintf(h_name,"RatioTTT_4LbJpT_%d",i%2);
		h_4L_bJpT_ratio.push_back(new TH1F(h_name, "fraction of TTT triggered events vs 2^{nd} b-jet p_{T};p_{T, bJ2} [GeV/c];#frac{TTT triggered events}{total events}",nbinsMinus, pt_bins));
		sprintf(h_name,"PhenoFracTTT_4LbJpT_%d",i%2);
		h_4L_bJpT_pheno_frac.push_back(new TH1F(h_name, "fraction of pheno ana events vs 2^{nd} b-jet p_{T} for TTT;p_{T, bJ2} [GeV/c];tot pheno ana events #times fraction of TTT triggered events",nbinsMinus, pt_bins));
	}
	else if (i < 6) // 4 or 5 (Calo)
	{
		pT_threshold = CaloT_for3L;//753e3;//MeV
		sprintf(h_name,"Calo_4LbJpT_%d",i%2);
		h_trig_4L_bJpT.push_back(new TH1F(h_name, "2^{nd} b-jet p_{T} of the 3L- Calo triggered jet;p_{T, bJ2} [GeV/c];",nbinsMinus, pt_bins));
		sprintf(h_name,"GenCal_4LbJpT_%d",i%2);
		h_4L_bJpT.push_back(new TH1F(h_name, "2^{nd} b-jet p_{T};p_{T, bJ2} [GeV/c];",nbinsMinus, pt_bins));
		sprintf(h_name,"RatioCal_4LbJpT_%d",i%2);
		h_4L_bJpT_ratio.push_back(new TH1F(h_name, "fraction of Calo triggered events vs 2^{nd} b-jet p_{T};p_{T, bJ2} [GeV/c];#frac{Calo triggered events}{total events}",nbinsMinus, pt_bins));
		sprintf(h_name,"PhenoFracCal_4LbJpT_%d",i%2);
		h_4L_bJpT_pheno_frac.push_back(new TH1F(h_name, "fraction of pheno ana events vs 2^{nd} b-jet p_{T} for Calo;p_{T, bJ2} [GeV/c];tot pheno ana events #times fraction of Calo triggered events",nbinsMinus, pt_bins));
	}
	triggered_4L_bJpT[i-2].clear();

	for(int j = 0; j < trees[i]->GetEntries(); j++)
	{
		trees[i]->GetEntry(j);
		//std::cout<<"event_number : " << eve_nums[i] << std::endl;
		if(L3_JpT[i] >= pT_threshold)
		{
			if(i%2 == 0) //'Signal': TTT, Calo
			{
				if(gen_4th_bJpT[0].count(eve_nums[i]))
				{
					triggered_4L_bJpT[i-2].push_back(gen_4th_bJpT[0].at(eve_nums[i]));
					h_trig_4L_bJpT[i-2]->Fill(gen_4th_bJpT[0].at(eve_nums[i])*1e-3);
				}
				else std::cout<<" event id: " << eve_nums[i] << " was not found in file " << i <<std::endl;
			
			}
			else // 'Background': TTT, Calo
			{
				if(gen_4th_bJpT[1].count(eve_nums[i]))
				{
					triggered_4L_bJpT[i-2].push_back(gen_4th_bJpT[1].at(eve_nums[i]));
					h_trig_4L_bJpT[i-2]->Fill(gen_4th_bJpT[1].at(eve_nums[i])*1e-3);
				
				}
				else std::cout<<" event id: " << eve_nums[i] << " was not found in file " << i <<std::endl;
			
			}
		}// 4MHz pileup rate
		//fill all otherwise into a gen histogram
		if(i%2 == 0)//signal
		{
			h_4L_bJpT[i-2]->Fill(gen_4th_bJpT[0].at(eve_nums[i])*1e-3);
		}
		else//background
		{
			h_4L_bJpT[i-2]->Fill(gen_4th_bJpT[1].at(eve_nums[i])*1e-3);
		}

	}

	return;
}
double cal_norm(bool sig, int tot_events)
{
	double Xsec = 0.;
	if(sig)
	{
		Xsec = ggFhhXsec1*four_b_Prob;
	}
	else Xsec = pp4bXsec;

	return (IntLumi*Xsec)/tot_events;

}
//TTT_Significance()
void Fill_Hist()
{
	//double sig_norm = cal_norm(true, trees[2]->GetEntries());
	//double bkg_norm = cal_norm(false, trees[3]->GetEntries());
	
	// TTT
	h_4L_bJpT_ratio[0] = (TH1F*)h_trig_4L_bJpT[0]->Clone("RatioTTT_4LbJpT_0");
	h_4L_bJpT_ratio[0]->Divide(h_trig_4L_bJpT[0],h_4L_bJpT[0],1.0,1.0);
	h_4L_bJpT_ratio[1] = (TH1F*)h_trig_4L_bJpT[1]->Clone("RatioTTT_4LbJpT_1");
	h_4L_bJpT_ratio[1]->Divide(h_trig_4L_bJpT[1],h_4L_bJpT[1],1.0,1.0);
	
	h_4L_bJpT_pheno_frac[0] = (TH1F*)h_4L_bJpT_pheno[0]->Clone("PhenoFracTTT_4LbJpT_0");
	h_4L_bJpT_pheno_frac[0]->Multiply(h_4L_bJpT_ratio[0]);
	h_4L_bJpT_pheno_frac[1] = (TH1F*)h_4L_bJpT_pheno[1]->Clone("PhenoFracTTT_4LbJpT_1");
	h_4L_bJpT_pheno_frac[1]->Multiply(h_4L_bJpT_ratio[1]);

	// Calo
	h_4L_bJpT_ratio[2] = (TH1F*)h_trig_4L_bJpT[2]->Clone("RatioCal_4LbJpT_0");
	h_4L_bJpT_ratio[2]->Divide(h_trig_4L_bJpT[2],h_4L_bJpT[2],1.0,1.0);
	h_4L_bJpT_ratio[3] = (TH1F*)h_trig_4L_bJpT[3]->Clone("RatioCal_4LbJpT_1");
	h_4L_bJpT_ratio[3]->Divide(h_trig_4L_bJpT[3],h_4L_bJpT[3],1.0,1.0);
	
	h_4L_bJpT_pheno_frac[2] = (TH1F*)h_4L_bJpT_pheno[0]->Clone("PhenoFracCal_4LbJpT_0");
	h_4L_bJpT_pheno_frac[2]->Multiply(h_4L_bJpT_ratio[2]);
	h_4L_bJpT_pheno_frac[3] = (TH1F*)h_4L_bJpT_pheno[1]->Clone("PhenoFracCal_4LbJpT_1");
	h_4L_bJpT_pheno_frac[3]->Multiply(h_4L_bJpT_ratio[3]);

	//float S = triggered_4L_bJpT[2].size()*sig_norm;
	//float B = triggered_4L_bJpT[3].size()*bkg_norm;
	//return S/std::sqrt(B);

	//float S = triggered_4L_bJpT[0].size()*sig_norm;
	//float B = triggered_4L_bJpT[1].size()*bkg_norm;
	//return S/std::sqrt(B);
	return;
}
void Scale_with_BinWidth()
{
	double sig_norm = cal_norm(true, tot_MCevents);
	double bkg_norm = cal_norm(false, tot_MCevents_B);

	h_trig_4L_bJpT[0]->Scale(sig_norm,"width");
	h_trig_4L_bJpT[1]->Scale(bkg_norm,"width");
	h_trig_4L_bJpT[2]->Scale(sig_norm,"width");
	h_trig_4L_bJpT[3]->Scale(bkg_norm,"width");
	
	h_4L_bJpT[0]->Scale(sig_norm,"width");
	h_4L_bJpT[1]->Scale(bkg_norm,"width");
	h_4L_bJpT[2]->Scale(sig_norm,"width");
	h_4L_bJpT[3]->Scale(bkg_norm,"width");

	h_4L_bJpT_pheno[0]->Scale(sig_norm,"width");
	h_4L_bJpT_pheno[1]->Scale(bkg_norm,"width");

	h_4L_bJpT_pheno_frac[0]->Scale(sig_norm,"width");
	h_4L_bJpT_pheno_frac[1]->Scale(bkg_norm,"width");
	h_4L_bJpT_pheno_frac[2]->Scale(sig_norm,"width");
	h_4L_bJpT_pheno_frac[3]->Scale(bkg_norm,"width");
	
	return;
}

void Make_hist_Copy()
{
	for(int i = 0; i < 4; i++)
	{
		h_trig_4L_bJpT_copy.push_back((TH1F*)h_trig_4L_bJpT[i]->Clone());	
		h_4L_bJpT_copy.push_back((TH1F*)h_4L_bJpT[i]->Clone());
		h_4L_bJpT_ratio_copy.push_back((TH1F*)h_4L_bJpT_ratio[i]->Clone());
		h_4L_bJpT_pheno_frac_copy.push_back((TH1F*)h_4L_bJpT_pheno_frac[i]->Clone());
		if(i<2)h_4L_bJpT_pheno_copy.push_back((TH1F*)h_4L_bJpT_pheno[i]->Clone());

		if(i%2 ==0) 
		{
			h_trig_4L_bJpT_copy[i]->Scale(cal_norm(true,tot_MCevents));
			h_4L_bJpT_copy[i]->Scale(cal_norm(true,tot_MCevents));
			//h_4L_bJpT_ratio_copy[i]->Scale(cal_norm(true,tot_MCevents));
			h_4L_bJpT_pheno_frac_copy[i]->Scale(cal_norm(true,tot_MCevents));
		}
		else
		{
			h_trig_4L_bJpT_copy[i]->Scale(cal_norm(false,tot_MCevents_B));
			h_4L_bJpT_copy[i]->Scale(cal_norm(false,tot_MCevents_B));
			//h_4L_bJpT_ratio_copy[i]->Scale(cal_norm(false,tot_MCevents_B));
			h_4L_bJpT_pheno_frac_copy[i]->Scale(cal_norm(false,tot_MCevents_B));
		}
	}
	
	h_4L_bJpT_pheno_copy[0]->Scale(cal_norm(true,tot_MCevents));
	h_4L_bJpT_pheno_copy[1]->Scale(cal_norm(false,tot_MCevents_B));

	return;
}
	
void open_files()
{
	root_files.clear();
	trees.clear();

	for(int i = 0; i < N_files; i++)
	{
		root_files.push_back( new TFile(in_files[i],"READ"));
		//root_files[i]->ls();
		TString tree_name = "bin_Tree";
		if(i < 2) tree_name = "eventList";
		
		trees.push_back( (TTree*)root_files[i]->Get(tree_name));
		
		if (i < 2) init_eve(i);
		else 
		{
			init_binTree(i);
		}
		
		std::cout<<"Number of entries in tree: " << i << " = " << trees[i]->GetEntries() <<std::endl;
		if(i>1)
		{
			float efficiency = (float)triggered_4L_bJpT[i-2].size()/trees[i]->GetEntries();
			std::cout << "Trigger Efficiency at pT_threshold of :  " << pT_threshold*1e-3 << " GeV is " << efficiency << std::endl;
		}
	}
	
	return;
}
void apply_cosmetics()
{
	int width = 2;
	int style = 7;
	int color_pheno = 1;//kBlack
	int color_TTT = 600;// kBlue
	int color_Calo= 801;//kOrgange + 1
	h_4L_bJpT_pheno[0]->SetLineColor(color_pheno);
	h_4L_bJpT_pheno[1]->SetLineColor(color_pheno);
	h_4L_bJpT_pheno[1]->SetLineStyle(style);
	
	h_TTT_Z->SetLineColor(color_TTT);
	h_Cal_Z->SetLineColor(color_Calo);
	h_pheno_Z->SetLineColor(color_pheno);
	
	h_4L_bJpT_pheno[0]->SetLineWidth(width);
	h_4L_bJpT_pheno[1]->SetLineWidth(width);
	
	h_TTT_Z->SetLineWidth(width);
	h_Cal_Z->SetLineWidth(width);
	h_pheno_Z->SetLineWidth(width);

	for(int k = 0; k < 4; k++)
	{
		int color;
		if(k < 2) color = color_TTT;
		else if(k < 4) color = color_Calo;

		h_trig_4L_bJpT[k]->SetLineColor(color);
		h_4L_bJpT[k]->SetLineColor(color);
		h_4L_bJpT_ratio[k]->SetLineColor(color);
		h_4L_bJpT_pheno_frac[k]->SetLineColor(color);
	
		h_trig_4L_bJpT[k]->SetLineWidth(width);
		h_4L_bJpT[k]->SetLineWidth(width);
		h_4L_bJpT_ratio[k]->SetLineWidth(width);
		h_4L_bJpT_pheno_frac[k]->SetLineWidth(width);
		
		if(k%2==1)
		{
			h_trig_4L_bJpT[k]->SetLineStyle(style);
			h_4L_bJpT[k]->SetLineStyle(style);
			h_4L_bJpT_ratio[k]->SetLineStyle(style);
			h_4L_bJpT_pheno_frac[k]->SetLineStyle(style);
		}


	}
	return;
}

void draw_legends()
{
	leg =  new TLegend(0.1,0.1,0.49,0.55);
	leg->SetFillStyle(0);
	leg->SetBorderSize(0);
	leg->SetHeader("","C");
	leg->AddEntry(h_4L_bJpT[0],"TTT signal","l");
	leg->AddEntry(h_4L_bJpT[1],"TTT background","l");
	leg->AddEntry(h_4L_bJpT[2],"Calo signal","l");
	leg->AddEntry(h_4L_bJpT[3],"Calo background","l");
	leg->AddEntry(h_4L_bJpT_pheno[0],"Reference signal","l");
	leg->AddEntry(h_4L_bJpT_pheno[1],"Reference background","l");
	leg->Draw();
	
	leg1 =  new TLegend(0.5,0.1,0.9,0.29);
	leg1->SetFillStyle(0);
	leg1->SetBorderSize(0);
	leg1->SetHeader("2L b-jet p_{T}","C");//CHANGE
	leg1->AddEntry(h_4L_bJpT_pheno[0],"Reference signal","l");
	leg1->AddEntry(h_4L_bJpT_pheno[1],"Reference background","l");
	leg1->Draw();

	leg2 =  new TLegend(0.1,0.6,0.29,0.85);
	leg2->SetFillStyle(0);
	leg2->SetBorderSize(0);
	leg2->SetHeader("S/#sqrt{B}","");
	leg2->AddEntry(h_TTT_Z,"TTT","l");
	leg2->AddEntry(h_Cal_Z,"Calo","l");
	leg2->AddEntry(h_pheno_Z,"Reference","l");
	leg2->Draw();
	
	return;
}
void make_pdf()
{
	const char *out_path = ".";
	const char *output_file_name = "summary_significance_2L";//CHANGE
	char out_file_open[1024];
	char out_file_[1024];
	char out_file_close[1024];
        sprintf(out_file_open,"%s/%s.pdf(",out_path,output_file_name);
        sprintf(out_file_,"%s/%s.pdf",out_path,output_file_name);
        sprintf(out_file_close,"%s/%s.pdf)",out_path,output_file_name);
	
	TCanvas *c = new TCanvas();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	float max = h_trig_4L_bJpT[1]->GetMaximum() + 0.5*h_trig_4L_bJpT[1]->GetMaximum();
	float min = h_trig_4L_bJpT[2]->GetMinimum() - 0.5*h_trig_4L_bJpT[2]->GetMinimum();

	//! page1
	for(int i = 0; i < 4; i++)
	{
		h_trig_4L_bJpT[i]->GetYaxis()->SetRangeUser(min, max);
		h_trig_4L_bJpT[i]->GetYaxis()->SetTitle("# (triggered events) [GeV/c]^{-1}");
		h_trig_4L_bJpT[i]->Draw("same");
	}
	c->SetLogx();
	c->SetLogy();
	c->Write();
	c->Print(out_file_open,"pdf");	
	
	//! page2
	c->Clear();
	max = h_4L_bJpT[1]->GetMaximum() + 0.5*h_4L_bJpT[1]->GetMaximum();
	min = h_4L_bJpT[2]->GetMinimum() - 0.5*h_4L_bJpT[2]->GetMinimum();
	h_4L_bJpT[0]->GetYaxis()->SetRangeUser(min, max);
	h_4L_bJpT[0]->GetYaxis()->SetTitle("#(events fed to the trigger) [GeV/c]^{-1}");
	h_4L_bJpT[0]->Draw();
	for(int i = 1; i < 4; i++)
	{
		h_4L_bJpT[i]->Draw("same");
	}
	c->SetLogx();
	c->SetLogy();
	c->Write();
	c->Print(out_file_,"pdf");
	
	//! page3
	c->Clear();
	max = h_4L_bJpT_ratio[1]->GetMaximum() + 0.5*h_4L_bJpT_ratio[1]->GetMaximum();
	min = h_4L_bJpT_ratio[3]->GetMinimum() - 0.5*h_4L_bJpT_ratio[3]->GetMinimum();
	h_4L_bJpT_ratio[0]->GetYaxis()->SetRangeUser(min, max);
	h_4L_bJpT_ratio[0]->GetYaxis()->SetTitle("#frac{events~ triggered}{total~ events}");
	h_4L_bJpT_ratio[0]->Draw();
	for(int i = 1; i < 4; i++)
	{
		h_4L_bJpT_ratio[i]->Draw("same");
	}
	c->SetLogx();
	c->SetLogy(0);
	c->Write();
	c->Print(out_file_,"pdf");

	//! page4
	c->Clear();
	max = h_4L_bJpT_pheno[1]->GetMaximum() + 0.5*h_4L_bJpT_pheno[1]->GetMaximum();
	min = h_4L_bJpT_pheno_frac[2]->GetMinimum() - 0.5*h_4L_bJpT_pheno_frac[2]->GetMinimum();
	h_4L_bJpT_pheno_frac[0]->GetYaxis()->SetRangeUser(min, max);
	h_4L_bJpT_pheno_frac[0]->GetYaxis()->SetTitle("#events [GeV/c]^{-1}");
	h_4L_bJpT_pheno_frac[0]->Draw();
	h_4L_bJpT_pheno[0]->Draw("same");
	h_4L_bJpT_pheno[1]->Draw("same");
	for(int i = 1; i < 4; i++)
	{
		h_4L_bJpT_pheno_frac[i]->Draw("same");
	}
	c->SetLogx();
	c->SetLogy();
	c->Write();
	c->Print(out_file_,"pdf");
	
	//! page5
	//c->Clear();
	max = h_4L_bJpT_pheno[1]->GetMaximum() + 0.5*h_4L_bJpT_pheno[1]->GetMaximum();
	min = h_4L_bJpT_pheno[0]->GetMinimum() - 0.5*h_4L_bJpT_pheno[0]->GetMinimum();
	h_4L_bJpT_pheno[0]->GetYaxis()->SetRangeUser(min, max);
	h_4L_bJpT_pheno[0]->GetYaxis()->SetTitle("#events [GeV/c]^{-1}");
	h_4L_bJpT_pheno[0]->Draw();
	h_4L_bJpT_pheno[1]->Draw("same");
	c->SetLogx();
	c->SetLogy();
	c->Write();
	c->Print(out_file_,"pdf");

	//! page 6
	c->Clear();
	max = h_TTT_Z->GetMaximum() + 0.3*h_TTT_Z->GetMaximum();
	min = h_Cal_Z->GetMinimum() - 1.9*h_Cal_Z->GetMinimum();
	h_TTT_Z->GetYaxis()->SetRangeUser(min, max);
	h_TTT_Z->GetYaxis()->CenterTitle();
	h_TTT_Z->GetXaxis()->CenterTitle();
	h_TTT_Z->Draw();
	h_Cal_Z->Draw("same");
	h_pheno_Z->Draw("same");
	c->SetLogx();
	c->SetLogy(0);
	c->Write();
	c->Print(out_file_,"pdf");
	
	c->Clear();
	draw_legends();
	c->Write();
	c->Print(out_file_close,"pdf");
	return;
}

void summary_significance()
{
	//! Open output file
	TFile *f_out = new TFile(out_file,"RECREATE");
	TTree *t_out = new TTree("t_out","summary");
	t_out->Branch("TTT_S_4LbJpT", &triggered_4L_bJpT[0]);
	t_out->Branch("TTT_B_4LbJpT", &triggered_4L_bJpT[1]);
	t_out->Branch("Cal_S_4LbJpT", &triggered_4L_bJpT[2]);
	t_out->Branch("Cal_B_4LbJpT", &triggered_4L_bJpT[3]);

	//! Open pheno ana file
	TFile *f_pheno = new TFile(pheno_file, "READ");
	//h_4L_bJpT_pheno.push_back((TH1F*)((TH1F*)f_pheno->Get("Ana_bjet4LPt1"))->Rebin(nbinsMinus, "h4bJL_pheno_sig", pt_bins));
	//h_4L_bJpT_pheno.push_back((TH1F*)((TH1F*)f_pheno->Get("Ana_bjet4LPtB"))->Rebin(nbinsMinus, "h4bJL_pheno_bkg", pt_bins));
	//CHANGE
	h_4L_bJpT_pheno.push_back((TH1F*)((TH1F*)f_pheno->Get("Ana_bjet2LPt1"))->Rebin(nbinsMinus, "h4bJL_pheno_sig", pt_bins));
	h_4L_bJpT_pheno.push_back((TH1F*)((TH1F*)f_pheno->Get("Ana_bjet2LPtB"))->Rebin(nbinsMinus, "h4bJL_pheno_bkg", pt_bins));
	
	TH1::SetDefaultSumw2(true);
	//! open selected event and trigger study files
	open_files();
	f_out->cd();
	t_out->Fill();
	t_out->Write();

	Fill_Hist();
	Make_hist_Copy();


	TCanvas *C = new TCanvas();
	h_4L_bJpT_pheno_copy[0]->Draw();



	h_TTT_Z = new TH1F("h_TTT_Z","Z_{i} vs 2^{nd} b-jet p_{T} for TTT; p_{T, bJ2}[GeV/c];Z_i",nbinsMinus, pt_bins); 
	h_Cal_Z = new TH1F("h_Cal_Z","Z_{i} vs 2^{nd} b-jet p_{T} for Calo; p_{T, bJ2}[GeV/c];Z_i",nbinsMinus, pt_bins);
	h_pheno_Z = new TH1F("h_pheno_Z","Z_{i} vs 2^{nd} b-jet p_{T} for generator level analysis; p_{T, bJ2}[GeV/c];Z_i",nbinsMinus, pt_bins);
	
	float sum2_TTT = 0.;
	float sum2_Cal = 0.;
	float sum2_pheno = 0.;
	for(int i = 1; i <= h_TTT_Z->GetNbinsX(); i++)
	{
		float Si = h_4L_bJpT_pheno_frac_copy[0]->GetBinContent(i);
		float del_Si = h_4L_bJpT_pheno_frac_copy[0]->GetBinError(i);
		float Bi = h_4L_bJpT_pheno_frac_copy[1]->GetBinContent(i);
		float sqrtBi = std::sqrt(Bi);
		float del_Bi = h_4L_bJpT_pheno_frac_copy[1]->GetBinError(i);

		h_TTT_Z->SetBinContent(i, Si/sqrtBi);
		h_TTT_Z->SetBinError(i, Si/sqrtBi*std::sqrt(std::pow(del_Si/Si,2) + std::pow(0.5*del_Bi/Bi,2)));
		sum2_TTT += std::pow(Si,2)/Bi;
		
		Si = h_4L_bJpT_pheno_frac_copy[2]->GetBinContent(i);
		del_Si = h_4L_bJpT_pheno_frac_copy[2]->GetBinError(i);
		Bi = h_4L_bJpT_pheno_frac_copy[3]->GetBinContent(i);
		sqrtBi = std::sqrt(Bi);
		del_Bi = h_4L_bJpT_pheno_frac_copy[3]->GetBinError(i);

		h_Cal_Z->SetBinContent(i, Si/sqrtBi);
		h_Cal_Z->SetBinError(i, Si/sqrtBi*std::sqrt(std::pow(del_Si/Si,2) + std::pow(0.5*del_Bi/Bi,2)));
		sum2_Cal += std::pow(Si/sqrtBi,2);
		
		Si = h_4L_bJpT_pheno_copy[0]->GetBinContent(i);
		del_Si = h_4L_bJpT_pheno_copy[0]->GetBinError(i);
		Bi = h_4L_bJpT_pheno_copy[1]->GetBinContent(i);
		sqrtBi = std::sqrt(Bi);
		del_Bi = h_4L_bJpT_pheno_copy[1]->GetBinError(i);

		h_pheno_Z->SetBinContent(i, Si/sqrtBi);
		h_pheno_Z->SetBinError(i, Si/sqrtBi*std::sqrt(std::pow(del_Si/Si,2) + std::pow(0.5*del_Bi/Bi,2)));
		sum2_pheno += std::pow(Si/sqrtBi,2);
	}

	std::cout << "Single bin Significance with TTT: " << h_4L_bJpT_pheno_frac_copy[0]->Integral(1,n)/std::sqrt(h_4L_bJpT_pheno_frac_copy[1]->Integral(1,n)) <<std::endl;
	std::cout << "Single bin Significance with Cal0: " << h_4L_bJpT_pheno_frac_copy[2]->Integral(1,n)/std::sqrt(h_4L_bJpT_pheno_frac_copy[3]->Integral(1,n)) <<std::endl;
	std::cout << "Single bin Significance with Reference: " << h_4L_bJpT_pheno_copy[0]->Integral(1,n)/std::sqrt(h_4L_bJpT_pheno_copy[1]->Integral(1,n)) <<std::endl;
	
	std::cout << "Differential sum Significance with TTT: " << std::sqrt(sum2_TTT) <<std::endl;
	std::cout << "Differential sum Significance with Calo: " << std::sqrt(sum2_Cal) <<std::endl;
	std::cout << "Differential sum Significance with Reference: " << std::sqrt(sum2_pheno) <<std::endl;

	Scale_with_BinWidth();
	apply_cosmetics();

	for(int i = 0; i < h_trig_4L_bJpT.size(); i++)
	{
		h_trig_4L_bJpT[i]->Write();
		h_4L_bJpT[i]->Write();
		h_4L_bJpT_ratio[i]->Write();
		h_4L_bJpT_pheno_frac[i]->Write();
	}
	h_4L_bJpT_pheno[0]->Write();	
	h_4L_bJpT_pheno[1]->Write();
	h_TTT_Z->Write();
	h_Cal_Z->Write();

	make_pdf();

	f_out->Close();
	
	return;
}
