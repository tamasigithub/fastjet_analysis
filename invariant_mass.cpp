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

TLorentzVector b1, b2, b3, b4;
TLorentzVector b1b2, b1b3, b1b4, b2b3, b2b4, b3b4;
int nbins = 100;
double ptmin = 0;
double ptmax = 500;

TH1D *Mb1b2 = new TH1D("Mb1b2","Invariant Mass b1b2; m_{b1b2} [GeV/c];", nbins, ptmin, ptmax);
TH1D *Mb1b3 = new TH1D("Mb1b3","Invariant Mass b1b2; m_{b1b3} [GeV/c];", nbins, ptmin, ptmax);
TH1D *Mb1b4 = new TH1D("Mb1b4","Invariant Mass b1b2; m_{b1b4} [GeV/c];", nbins, ptmin, ptmax);
TH1D *Mb2b3 = new TH1D("Mb2b3","Invariant Mass b1b2; m_{b2b3} [GeV/c];", nbins, ptmin, ptmax);
TH1D *Mb2b4 = new TH1D("Mb2b4","Invariant Mass b1b2; m_{b2b4} [GeV/c];", nbins, ptmin, ptmax);
TH1D *Mb3b4 = new TH1D("Mb3b4","Invariant Mass b1b2; m_{b3b4} [GeV/c];", nbins, ptmin, ptmax);

int invariant_mass()
{

	f = new TFile("./fastjet_output/Genjet2_ggF_Ctr1.0_q1.2GeV_2.5_5.root","READ");
	t = (TTree*)f->Get("glob_jet");

	t->SetBranchAddress("v_bPt", &v_bPt);
	t->SetBranchAddress("v_bEta",&v_bEta);
	t->SetBranchAddress("v_bPhi",&v_bPhi);
	t->SetBranchAddress("v_bM",  &v_bM);
	
	TFile *fout = new TFile("test.root","RECREATE");
	for(int i = 0; i < t->GetEntries(); i++)
	{
		t->GetEntry(i);
		if(v_bPt->size() < 4) continue;
		b1.SetPtEtaPhiM((*v_bPt)[0], (*v_bEta)[0], (*v_bPhi)[0], (*v_bM)[0]);
		b2.SetPtEtaPhiM((*v_bPt)[1], (*v_bEta)[1], (*v_bPhi)[1], (*v_bM)[1]);
		b3.SetPtEtaPhiM((*v_bPt)[2], (*v_bEta)[2], (*v_bPhi)[2], (*v_bM)[2]);
		b4.SetPtEtaPhiM((*v_bPt)[3], (*v_bEta)[3], (*v_bPhi)[3], (*v_bM)[3]);

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
	}

	Mb1b2->Write();
	Mb1b3->Write();
	Mb1b4->Write();
	Mb2b3->Write();
	Mb2b4->Write();
	Mb3b4->Write();
	fout->Close();
	return 0;
}
