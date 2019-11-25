#include <iostream>
#include <vector>
#include <TFile.h>
#include <TH1.h>
#include <TTree.h>
#include <TLorentzVector.h>

TFile *f = nullptr; 
TTree *t = nullptr;
std::vector<double> *v_bPt  = nullptr;
std::vector<double> *v_bEta = nullptr;
std::vector<double> *v_bPhi = nullptr;
std::vector<double> *v_bM   = nullptr;
std::vector<double> *v_btagFlavor = nullptr;
int n1_btags = 0;

std::vector<double> v1_bPt;
std::vector<double> v1_bEta;
std::vector<double> v1_bPhi;
std::vector<double> v1_bM;

TLorentzVector b1, b2, b3, b4;
TLorentzVector b1b2, b1b3, b1b4, b2b3, b2b4, b3b4;
int nbins = 100;
double ptmin = 0;
double ptmax = 500;

TH1D *Mb1b2 = new TH1D("Mb1b2","Invariant Mass b1b2; m_{b1b2} [GeV];", nbins, ptmin, ptmax);
TH1D *Mb1b3 = new TH1D("Mb1b3","Invariant Mass b1b3; m_{b1b3} [GeV];", nbins, ptmin, ptmax);
TH1D *Mb1b4 = new TH1D("Mb1b4","Invariant Mass b1b4; m_{b1b4} [GeV];", nbins, ptmin, ptmax);
TH1D *Mb2b3 = new TH1D("Mb2b3","Invariant Mass b2b3; m_{b2b3} [GeV];", nbins, ptmin, ptmax);
TH1D *Mb2b4 = new TH1D("Mb2b4","Invariant Mass b2b4; m_{b2b4} [GeV];", nbins, ptmin, ptmax);
TH1D *Mb3b4 = new TH1D("Mb3b4","Invariant Mass b3b4; m_{b3b4} [GeV];", nbins, ptmin, ptmax);

TH1D *Ptb1b2 = new TH1D("Ptb1b2","Pt b1b2; pt_{b1b2} [GeV/c];", nbins, ptmin, ptmax);
TH1D *Ptb1b3 = new TH1D("Ptb1b3","Pt b1b3; pt_{b1b3} [GeV/c];", nbins, ptmin, ptmax);
TH1D *Ptb1b4 = new TH1D("Ptb1b4","Pt b1b4; pt_{b1b4} [GeV/c];", nbins, ptmin, ptmax);
TH1D *Ptb2b3 = new TH1D("Ptb2b3","Pt b2b3; pt_{b2b3} [GeV/c];", nbins, ptmin, ptmax);
TH1D *Ptb2b4 = new TH1D("Ptb2b4","Pt b2b4; pt_{b2b4} [GeV/c];", nbins, ptmin, ptmax);
TH1D *Ptb3b4 = new TH1D("Ptb3b4","Pt b3b4; pt_{b3b4} [GeV/c];", nbins, ptmin, ptmax);

int invariant_mass()
{

	f = new TFile("./fastjet_output/fastjet_output/Genjet2_ggF_Ctr1.0_q300MeV_2.5_5.root","READ");
	t = (TTree*)f->Get("glob_jet");

	t->SetBranchAddress("jetPt", &v_bPt);
	t->SetBranchAddress("jetEta",&v_bEta);
	t->SetBranchAddress("jetPhi",&v_bPhi);
	t->SetBranchAddress("jetM",  &v_bM);
	t->SetBranchAddress("Nbtags",  &n1_btags);
	t->SetBranchAddress("btaggedFlavor",  &v_btagFlavor);
	
	TFile *fout = new TFile("test.root","RECREATE");
	for(int i = 0; i < t->GetEntries(); i++)
	{
		v1_bPt.clear();
		v1_bEta.clear();
		v1_bPhi.clear();
		v1_bM.clear();
		t->GetEntry(i);
		if(v_bPt->size() < 4) continue;
		if((*v_bPt)[0]*1e-3 < 55.0) continue;
		if((*v_bPt)[1]*1e-3 < 40.0) continue;
		if(n1_btags < 4) continue;

		for(int j = 0; j < v_btagFlavor->size(); j++)
		{
			if((*v_btagFlavor)[j] != 5) continue;
			v1_bPt.push_back((*v_bPt)[j]);
			v1_bEta.push_back((*v_bEta)[j]);
			v1_bPhi.push_back((*v_bPhi)[j]);
			v1_bM.push_back((*v_bM)[j]);

		}
		b1.SetPtEtaPhiM(v1_bPt[0], v1_bEta[0], v1_bPhi[0], v1_bM[0]);
		b2.SetPtEtaPhiM(v1_bPt[1], v1_bEta[1], v1_bPhi[1], v1_bM[1]);
		b3.SetPtEtaPhiM(v1_bPt[2], v1_bEta[2], v1_bPhi[2], v1_bM[2]);
		b4.SetPtEtaPhiM(v1_bPt[3], v1_bEta[3], v1_bPhi[3], v1_bM[3]);

		b1b2 = b1 + b2;
		b1b3 = b1 + b3;
		b1b4 = b1 + b4;
		b2b3 = b2 + b3;
		b2b4 = b2 + b4;
		b3b4 = b3 + b4;

		Mb1b2->Fill(b1b2.M()*1e-3);
		Mb1b3->Fill(b1b3.M()*1e-3);
		Mb1b4->Fill(b1b4.M()*1e-3);
		Mb2b3->Fill(b2b3.M()*1e-3);
		Mb2b4->Fill(b2b4.M()*1e-3);
		Mb3b4->Fill(b3b4.M()*1e-3);
		
		Ptb1b2->Fill(b1b2.Pt()*1e-3);
		Ptb1b3->Fill(b1b3.Pt()*1e-3);
		Ptb1b4->Fill(b1b4.Pt()*1e-3);
		Ptb2b3->Fill(b2b3.Pt()*1e-3);
		Ptb2b4->Fill(b2b4.Pt()*1e-3);
		Ptb3b4->Fill(b3b4.Pt()*1e-3);
	}

	Mb1b2->Write();
	Mb1b3->Write();
	Mb1b4->Write();
	Mb2b3->Write();
	Mb2b4->Write();
	Mb3b4->Write();
	
	Ptb1b2->Write();
	Ptb1b3->Write();
	Ptb1b4->Write();
	Ptb2b3->Write();
	Ptb2b4->Write();
	Ptb3b4->Write();
	fout->Close();
	return 0;
}
//int invariant_mass()
//{
//
//	f = new TFile("./fastjet_output/Genjet2_ggF_Ctr1.0_q1.2GeV_2.5_5.root","READ");
//	t = (TTree*)f->Get("glob_jet");
//
//	t->SetBranchAddress("v_bPt", &v_bPt);
//	t->SetBranchAddress("v_bEta",&v_bEta);
//	t->SetBranchAddress("v_bPhi",&v_bPhi);
//	t->SetBranchAddress("v_bM",  &v_bM);
//	
//	TFile *fout = new TFile("test.root","RECREATE");
//	for(int i = 0; i < t->GetEntries(); i++)
//	{
//		t->GetEntry(i);
//		if(v_bPt->size() < 4) continue;
//		b1.SetPtEtaPhiM((*v_bPt)[0], (*v_bEta)[0], (*v_bPhi)[0], (*v_bM)[0]);
//		b2.SetPtEtaPhiM((*v_bPt)[1], (*v_bEta)[1], (*v_bPhi)[1], (*v_bM)[1]);
//		b3.SetPtEtaPhiM((*v_bPt)[2], (*v_bEta)[2], (*v_bPhi)[2], (*v_bM)[2]);
//		b4.SetPtEtaPhiM((*v_bPt)[3], (*v_bEta)[3], (*v_bPhi)[3], (*v_bM)[3]);
//
//		b1b2 = b1 + b2;
//		b1b3 = b1 + b3;
//		b1b4 = b1 + b4;
//		b2b3 = b2 + b3;
//		b2b4 = b2 + b4;
//		b3b4 = b3 + b4;
//
//		Mb1b2->Fill(b1b2.M()*1e-3);
//		Mb1b3->Fill(b1b3.M()*1e-3);
//		Mb1b4->Fill(b1b4.M()*1e-3);
//		Mb2b3->Fill(b2b3.M()*1e-3);
//		Mb2b4->Fill(b2b4.M()*1e-3);
//		Mb3b4->Fill(b3b4.M()*1e-3);
//	}
//
//	Mb1b2->Write();
//	Mb1b3->Write();
//	Mb1b4->Write();
//	Mb2b3->Write();
//	Mb2b4->Write();
//	Mb3b4->Write();
//	fout->Close();
//	return 0;
//}
