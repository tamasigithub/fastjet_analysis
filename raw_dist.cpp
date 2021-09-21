#include "TROOT.h"
#include <iostream>
#include <vector>
#include "raw_dist.h"
void plot()
{
  
	
	TFile *f_eve = new TFile("/media/tamasi/Z/PhD/fastjet/fastjet_output/TriggerStudies_4/user.tkar.EventList_1_5_allAnaCuts_000004.root","READ");
	TTree *evelistTree = (TTree*)f_eve->Get("eventList");
	evelistTree->SetBranchAddress("eventNums", &eve_i);
	evelistTree->SetBranchAddress("PV", &PV_i);
	Long64_t nevents = evelistTree->GetEntries();

	t1.Add("./fastjet_output/ggFhh4b_SM_1/*.root");
	t1.Add("./fastjet_output/ggFhh4b_SM_2/*.root");
	r1.Add("./fastjet_output/ggFhh4b_SM_1/*.root");
	r1.Add("./fastjet_output/ggFhh4b_SM_2/*.root");
	
	t2.Add("./fastjet_output/MB_1/*.root");
	t2.Add("./fastjet_output/MB_2/*.root");
	r2.Add("./fastjet_output/MB_1/*.root");
	r2.Add("./fastjet_output/MB_2/*.root");

	std::cout<<"******* NUMBER OF ENTRIES IN VARIOUS NTUPLES *********" <<std::endl;
	std::cout<<"event list: " <<nevents << " entries." <<std::endl;
	std::cout<<"ggF tracks: " <<t1.GetEntries() << " entries." <<std::endl;
	std::cout<<"ggF reco t: " <<r1.GetEntries() << " entries." <<std::endl;
	std::cout<<"MB  tracks: " <<t2.GetEntries() << " entries." <<std::endl;
	std::cout<<"MB  reco t: " <<r2.GetEntries() << " entries." <<std::endl;

	INIT_gen_1();
	INIT_gen_2();
	INIT_rec_1();
	INIT_rec_2();
	INIT_HISTOS();

	nevents = 50;
	for(int i = 0; i < nevents; i++)
	{
	
		evelistTree->GetEntry(i);
		t1.GetEntry(eve_i);
		t2.GetEntry(eve_i);
		r1.GetEntry(eve_i);
		r2.GetEntry(eve_i);
	
		for(int ik = 0; ik < pt1->size(); ik++)
		{
			if(std::fabs((*eta1)[ik]) > 1.5) continue;
			if((*pid1)[ik] == 25 || (*pid1)[ik] == 5) continue;
			if(std::fabs((*vz1)[ik]) > 100) continue;

			if((*charge1)[ik] == 0)h2d_1->Fill(std::abs((*pid1)[ik]), (*type_traj1)[ik]);
			
			if(std::fabs((*pt1)[ik]) < 2e3) continue;
			if(std::abs((*charge1)[ik]) != 1) continue;
			
			ht_type_1->Fill((*type_traj1)[ik]);
			
			if(std::fabs((*vx1)[ik]) > 5) continue;
			if(std::fabs((*vy1)[ik]) > 5) continue;
			if((*type_traj1)[ik] != 0) continue;

			ht_pT_1->Fill((*pt1)[ik]*1e-3);
			ht_z0_1->Fill((*vz1)[ik]);
			ht_eta_1->Fill((*eta1)[ik]);
			ht_theta_1->Fill((*theta1)[ik]);
			ht_pdg_1->Fill(std::abs((*pid1)[ik]));
	
		}
		for(int ik = 0; ik < pt2->size(); ik++)
		{
			if(std::fabs((*eta2)[ik]) > 1.5) continue;
			if((*pid2)[ik] == 25 || (*pid2)[ik] == 5) continue;
			if(std::fabs((*vz2)[ik]) > 100) continue;
			
			if((*charge2)[ik] == 0)h2d_2->Fill(std::abs((*pid2)[ik]), (*type_traj2)[ik]);
			
			if(std::fabs((*pt2)[ik]) < 2e3) continue;
			if(std::abs((*charge2)[ik]) != 1) continue;
			
			ht_type_2->Fill((*type_traj2)[ik]);
			
			if(std::fabs((*vx2)[ik]) > 5) continue;
			if(std::fabs((*vy2)[ik]) > 5) continue;
			if((*type_traj2)[ik] != 0) continue;
			
			ht_pT_2->Fill((*pt2)[ik]*1e-3);
			ht_z0_2->Fill((*vz2)[ik]);
			ht_eta_2->Fill((*eta2)[ik]);
			ht_theta_2->Fill((*theta2)[ik]);
			ht_pdg_2->Fill(std::abs((*pid2)[ik]));
		
		}
		for(int ik = 0; ik < Pt_n1->size(); ik++)
		{
			if(std::fabs((*kappa_pull1)[ik]) > 3.0) continue;
			if(std::fabs((*Pt_n1)[ik]) < 2e3) continue;
			if(std::fabs((*Eta1)[ik]) > 1.5) continue;
			if((*Tid1)[ik] <= -1) continue;

			hr_type_1->Fill((*type1)[ik]);

			hr_pT_1->Fill((*Pt_n1)[ik]*1e-3);
			hmr_pT_1->Fill((*M_pt1)[ik]*1e-3);
			hr_z0_1->Fill((*Z01)[ik]);
			hmr_z0_1->Fill((*M_Vz1)[ik]);
			hr_z0reso_1->Fill((*Z01)[ik] - (*M_Vz1)[ik]);
			hr_theta_1->Fill((*Theta1)[ik]);
			hmr_theta_1->Fill((*M_theta1)[ik]);
			hr_thetareso_1->Fill((*Theta1)[ik] - (*M_theta1)[ik]);
			hr_eta_1->Fill((*Eta1)[ik]);
			hr_pdg_1->Fill(std::abs((*M_pdg1)[ik]));
		}
		for(int ik = 0; ik < Pt_n2->size(); ik++)
		{
			if(std::fabs((*kappa_pull2)[ik]) > 3.0) continue;
			if(std::fabs((*Pt_n2)[ik]) < 2e3) continue;
			if(std::fabs((*Eta2)[ik]) > 1.5) continue;
			if((*Tid2)[ik] <= -1) continue;
		
			hr_type_2->Fill((*type2)[ik]);
			
			hr_pT_2->Fill((*Pt_n2)[ik]*1e-3);
			hmr_pT_2->Fill((*M_pt2)[ik]*1e-3);
			hr_z0_2->Fill((*Z02)[ik]);
			hmr_z0_2->Fill((*M_Vz2)[ik]);
			hr_z0reso_2->Fill((*Z02)[ik] - (*M_Vz2)[ik]);
			hr_theta_2->Fill((*Theta2)[ik]);
			hmr_theta_2->Fill((*M_theta2)[ik]);
			hr_thetareso_2->Fill((*Theta2)[ik] - (*M_theta2)[ik]);
			hr_eta_2->Fill((*Eta2)[ik]);
			hr_pdg_2->Fill(std::abs((*M_pdg2)[ik]));
		}
	}

///////////////////////////////////////////////////////////////////////
//////////////// writing to pdf ///////////////////////////////////////
///////////////////////////////////////////////////////////////////////
	char out_file_open[1023];
        sprintf(out_file_open,"%s/%s.pdf(",out_path,output_file_name);
        char out_file_[1023];
        sprintf(out_file_,"%s/%s.pdf",out_path,output_file_name);
        char out_file_close[1023];
        sprintf(out_file_close,"%s/%s.pdf)",out_path,output_file_name);
	
	//char out_root_file[1023];
	//sprintf(out_root_file, "%s/%s.root",out_path,output_file_name);
	TCanvas *c = new TCanvas("c","c",1000, 800);
	c->Divide(2,2);
	c->cd(1);
	gPad->SetLogy();
	gPad->SetGridx();
	gPad->SetGridy();
	//t1.Draw("type_traj>>h_sig","");
	ht_type_1->Draw("e1");
	c->cd(2);
	gPad->SetLogy();
	gPad->SetGridx();
	gPad->SetGridy();
	//t2.Draw("type_traj>>h_pileup","");
	ht_type_2->Draw("e1");
	c->cd(3);
	gPad->SetLogy();
	gPad->SetGridx();
	gPad->SetGridy();
	//r1.Draw("mc_interaction>>h_rec_sig","");
	hr_type_1->Draw("e1");
	c->cd(4);
	gPad->SetLogy();
	gPad->SetGridx();
	gPad->SetGridy();
	//r2.Draw("mc_interaction>>h_rec_pileup","");
	hr_type_2->Draw("e1");
	c->Print(out_file_open,"pdf");

	c->Clear();
	c->Divide(2,2);
	c->cd(1);
	gPad->SetLogy();
	gPad->SetLogx();
	gPad->SetGridx();
	gPad->SetGridy();
	ht_pT_1->SetLineColor(kGreen);
	ht_pT_1->SetLineWidth(2.0);
	hr_pT_1->SetLineColor(kRed);
	hr_pT_1->SetLineWidth(2.0);
	hr_pT_1->SetTitle("signal: gen-green, rec-red");
	hr_pT_1->Draw("hist");
	ht_pT_1->Draw("hist same");
	c->cd(2);
	gPad->SetGridx();
	gPad->SetGridy();
	gPad->SetLogy();
	gPad->SetLogx();
	ht_pT_2->SetLineColor(kGreen);
	ht_pT_2->SetLineWidth(2.0);
	ht_pT_2->SetLineStyle(7);
	hr_pT_2->SetLineColor(kRed);
	hr_pT_2->SetLineWidth(2.0);
	hr_pT_2->SetLineStyle(7);
	hr_pT_2->SetTitle("pile-up: gen-green, rec-red");
	hr_pT_2->Draw("hist");
	ht_pT_2->Draw("hist same");
	c->cd(3);
	gPad->SetGridx();
	gPad->SetGridy();
	gPad->SetLogy();
	gPad->SetLogx();
	ht_pT_1->SetLineColor(kGreen);
	ht_pT_1->SetLineWidth(2.0);
	hmr_pT_1->SetLineColor(kRed);
	hmr_pT_1->SetLineWidth(2.0);
	hmr_pT_1->SetTitle("signal: gen-green, matched rec-red");
	hmr_pT_1->Draw("hist");
	ht_pT_1->Draw("hist same");
	c->cd(4);
	gPad->SetGridx();
	gPad->SetGridy();
	gPad->SetLogy();
	gPad->SetLogx();
	ht_pT_2->SetLineColor(kGreen);
	ht_pT_2->SetLineWidth(2.0);
	ht_pT_2->SetLineStyle(7);
	hmr_pT_2->SetLineColor(kRed);
	hmr_pT_2->SetLineWidth(2.0);
	hmr_pT_2->SetLineStyle(7);
	hmr_pT_2->SetTitle("pile-up: gen-green, matched rec-red");
	hmr_pT_2->Draw("hist");
	ht_pT_2->Draw("hist same");
	c->Print(out_file_,"pdf");

	c->Clear();
	c->Divide(2,2);
	c->cd(1);
	gPad->SetGridx();
	gPad->SetGridy();
	//gPad->SetLogy();
	ht_z0_1->SetLineColor(kGreen);
	ht_z0_1->SetLineWidth(2.0);
	hr_z0_1->SetLineColor(kRed);
	hr_z0_1->SetLineWidth(2.0);
	ht_z0_1->GetYaxis()->SetRangeUser(0,1400);
	ht_z0_1->SetTitle("signal: gen-green, rec-red");
	ht_z0_1->Draw("hist");
	hr_z0_1->Draw("hist same");
	c->cd(2);
	gPad->SetGridx();
	gPad->SetGridy();
	//gPad->SetLogy();
	ht_z0_2->SetLineColor(kGreen);
	ht_z0_2->SetLineWidth(2.0);
	ht_z0_2->SetLineStyle(7);
	hr_z0_2->SetLineColor(kRed);
	hr_z0_2->SetLineWidth(2.0);
	hr_z0_2->SetLineStyle(7);
	ht_z0_2->GetYaxis()->SetRangeUser(0,1400);
	ht_z0_2->SetTitle("pile-up: gen-green, rec-red");
	ht_z0_2->Draw("hist");
	hr_z0_2->Draw("hist same");
	c->cd(3);
	gPad->SetGridx();
	gPad->SetGridy();
	//gPad->SetLogy();
	ht_z0_1->SetLineColor(kGreen);
	ht_z0_1->SetLineWidth(2.0);
	hmr_z0_1->SetLineColor(kRed);
	hmr_z0_1->SetLineWidth(2.0);
	hmr_z0_1->GetYaxis()->SetRangeUser(0,1400);
	hmr_z0_1->SetTitle("signal: gen-green, matched rec-red");
	hmr_z0_1->Draw("hist");
	ht_z0_1->Draw("hist same");
	c->cd(4);
	gPad->SetGridx();
	gPad->SetGridy();
	//gPad->SetLogy();
	ht_z0_2->SetLineColor(kGreen);
	ht_z0_2->SetLineWidth(2.0);
	ht_z0_2->SetLineStyle(7);
	hmr_z0_2->SetLineColor(kRed);
	hmr_z0_2->SetLineWidth(2.0);
	hmr_z0_2->SetLineStyle(7);
	hmr_z0_2->GetYaxis()->SetRangeUser(0,1400);
	hmr_z0_2->SetTitle("pile-up: gen-green, matched rec-red");
	hmr_z0_2->Draw("hist");
	ht_z0_2->Draw("hist same");
	c->Print(out_file_,"pdf");
	
	c->Clear();
	c->Divide(2,2);
	c->cd(1);
	gPad->SetGridx();
	gPad->SetGridy();
	//gPad->SetLogy();
	ht_theta_1->SetLineColor(kGreen);
	ht_theta_1->SetLineWidth(2.0);
	hr_theta_1->SetLineColor(kRed);
	hr_theta_1->SetLineWidth(2.0);
	ht_theta_1->GetYaxis()->SetRangeUser(0,3400);
	ht_theta_1->SetTitle("signal: gen-green, rec-red");
	ht_theta_1->Draw("hist");
	hr_theta_1->Draw("hist same");
	c->cd(2);
	gPad->SetGridx();
	gPad->SetGridy();
	//gPad->SetLogy();
	ht_theta_2->SetLineColor(kGreen);
	ht_theta_2->SetLineWidth(2.0);
	ht_theta_2->SetLineStyle(7);
	hr_theta_2->SetLineColor(kRed);
	hr_theta_2->SetLineStyle(7);
	hr_theta_2->SetLineWidth(2.0);
	ht_theta_2->GetYaxis()->SetRangeUser(0,3400);
	ht_theta_2->SetTitle("pile-up: gen-green, rec-red");
	ht_theta_2->Draw("hist");
	hr_theta_2->Draw("hist same");
	c->cd(3);
	gPad->SetGridx();
	gPad->SetGridy();
	//gPad->SetLogy();
	ht_theta_1->SetLineColor(kGreen);
	ht_theta_1->SetLineWidth(2.0);
	hmr_theta_1->SetLineColor(kRed);
	hmr_theta_1->SetLineWidth(2.0);
	hmr_theta_1->GetYaxis()->SetRangeUser(0,3400);
	hmr_theta_1->SetTitle("signal: gen-green, matched rec-red");
	hmr_theta_1->Draw("hist");
	ht_theta_1->Draw("hist same");
	c->cd(4);
	gPad->SetGridx();
	gPad->SetGridy();
	//gPad->SetLogy();
	ht_theta_2->SetLineColor(kGreen);
	ht_theta_2->SetLineWidth(2.0);
	ht_theta_2->SetLineStyle(7);
	hmr_theta_2->SetLineColor(kRed);
	hmr_theta_2->SetLineWidth(2.0);
	hmr_theta_2->SetLineStyle(7);
	hmr_theta_2->GetYaxis()->SetRangeUser(0,3400);
	hmr_theta_2->SetTitle("pile-up: gen-green, matched rec-red");
	hmr_theta_2->Draw("hist");
	ht_theta_2->Draw("hist same");
	c->Print(out_file_,"pdf");
	
	c->Clear();
	c->Divide(2,2);
	c->cd(1);
	hr_z0reso_1->SetLineColor(kRed);
	hr_z0reso_1->SetLineWidth(2.0);
	hr_z0reso_1->Draw("hist");
	c->cd(2);
	hr_z0reso_2->SetLineColor(kRed);
	hr_z0reso_2->SetLineWidth(2.0);
	hr_z0reso_2->SetLineStyle(7);
	hr_z0reso_2->Draw("hist");
	c->cd(3);
	hr_thetareso_1->SetLineColor(kRed);
	hr_thetareso_1->SetLineWidth(2.0);
	hr_thetareso_1->Draw("hist");
	c->cd(4);
	hr_thetareso_2->SetLineColor(kRed);
	hr_thetareso_2->SetLineWidth(2.0);
	hr_thetareso_2->SetLineStyle(7);
	hr_thetareso_2->Draw("hist");
	c->Print(out_file_,"pdf");
	
	c->Clear();
	c->Divide(2,2);
	c->cd(1);
	gPad->SetGridx();
	gPad->SetGridy();
	gPad->SetLogy();
	ht_eta_1->Draw("e1");
	c->cd(2);
	gPad->SetGridx();
	gPad->SetGridy();
	gPad->SetLogy();
	ht_eta_2->Draw("e1");
	c->cd(3);
	gPad->SetGridx();
	gPad->SetGridy();
	gPad->SetLogy();
	hr_eta_1->Draw("e1");
	c->cd(4);
	gPad->SetGridx();
	gPad->SetGridy();
	gPad->SetLogy();
	hr_eta_2->Draw("e1");
	c->Print(out_file_,"pdf");
	
	c->Clear();
	c->Divide(2,2);
	c->cd(1);
	gPad->SetGridx();
	gPad->SetGridy();
	gPad->SetLogy();
	ht_pdg_1->Draw("e1");
	c->cd(2);
	gPad->SetGridx();
	gPad->SetGridy();
	gPad->SetLogy();
	ht_pdg_2->Draw("e1");
	c->cd(3);
	gPad->SetGridx();
	gPad->SetGridy();
	gPad->SetLogy();
	hr_pdg_1->Draw("e1");
	c->cd(4);
	gPad->SetGridx();
	gPad->SetGridy();
	gPad->SetLogy();
	hr_pdg_2->Draw("e1");
	c->Print(out_file_,"pdf");
	
	gStyle->SetOptStat(0);
	c->Clear();
	c->Divide(1,2);
	c->cd(1);
	h2d_1->Draw("colz");
	c->cd(2);
	h2d_2->Draw("colz");
	c->Print(out_file_,"pdf");
	
	gStyle->SetOptStat(1);
	c->Clear();
	c->Divide(2,2);
	c->cd(1);
	r1.Draw("Pt_n*1e-3:M_pt*1e-3","abs(pt) > 2e3 && abs(Z013) < 100 && abs(Eta13)<1.5 && Tid >0","",50);
	c->cd(2);
	r2.Draw("Pt_n*1e-3:M_pt*1e-3","abs(pt) > 2e3 && abs(Z013) < 100 && abs(Eta13)<1.5 && Tid >0","",50);
	c->cd(3);
	r1.Draw("Pt_n*1e-3:M_pt*1e-3","abs(pt) > 2e3 && abs(Z013) < 100 && abs(Eta13)<1.5 && Tid >0 && abs(M_pdg)==211","",50);
	c->cd(4);
	r2.Draw("Pt_n*1e-3:M_pt*1e-3","abs(pt) > 2e3 && abs(Z013) < 100 && abs(Eta13)<1.5 && Tid >0 && abs(M_pdg)==211","",50);
	c->Print(out_file_,"pdf");

	c->Clear();
	c->Divide(2,2);
	c->cd(1);
	r1.Draw("Pt_n*1e-3:M_pt*1e-3","abs(pt) > 2e3 && abs(Z013) < 100 && abs(Eta13)<1.5 && Tid >0 && abs(M_pdg)==11","",50);
	c->cd(2);
	r2.Draw("Pt_n*1e-3:M_pt*1e-3","abs(pt) > 2e3 && abs(Z013) < 100 && abs(Eta13)<1.5 && Tid >0 && abs(M_pdg)==11","",50);
	c->cd(3);
	r1.Draw("Pt_n*1e-3:M_pt*1e-3","abs(pt) > 2e3 && abs(Z013) < 100 && abs(Eta13)<1.5 && Tid >0 && abs(M_pdg)==13","",50);
	c->cd(4);
	r2.Draw("Pt_n*1e-3:M_pt*1e-3","abs(pt) > 2e3 && abs(Z013) < 100 && abs(Eta13)<1.5 && Tid >0 && abs(M_pdg)==13","",50);
	c->Print(out_file_close,"pdf");
	return;
}
