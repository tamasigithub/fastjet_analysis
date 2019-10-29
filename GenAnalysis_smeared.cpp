#include "GenAnalysis_smeared.h"

void Set_higgsPtProps()
{
	int nbins = 100;
	float ptmin = 0;
	float ptmax = 500;
	higgsPt1  = new TH1D("higgsPt1",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt0  = new TH1D("higgsPt0",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt_1 = new TH1D("higgsPt_1", "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt_2 = new TH1D("higgsPt_2", "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt2  = new TH1D("higgsPt2",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt2_5= new TH1D("higgsPt2_5","higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt3  = new TH1D("higgsPt3",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);

	higgsPt1->SetLineColor(kRed);
	higgsPt0->SetLineColor(kBlack);
	higgsPt_1->SetLineColor(kYellow -9);
	higgsPt_2->SetLineColor(kGreen);
	higgsPt2->SetLineColor(kBlue);
	higgsPt2_5->SetLineColor(kOrange-9);
	higgsPt3->SetLineColor(kViolet);
	
	higgsPt1->SetLineWidth(2);
	higgsPt0->SetLineWidth(2);
	higgsPt_1->SetLineWidth(2);
	higgsPt_2->SetLineWidth(2);
	higgsPt2->SetLineWidth(2);
	higgsPt2_5->SetLineWidth(2);
	higgsPt3->SetLineWidth(2);
	
	higgsNLPt1  = new TH1D("higgsNLPt1",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsNLPt0  = new TH1D("higgsNLPt0",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsNLPt_1 = new TH1D("higgsNLPt_1", "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsNLPt_2 = new TH1D("higgsNLPt_2", "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsNLPt2  = new TH1D("higgsNLPt2",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsNLPt2_5= new TH1D("higgsNLPt2_5","higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsNLPt3  = new TH1D("higgsNLPt3",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);

	higgsNLPt1->SetLineColor(kRed);
	higgsNLPt0->SetLineColor(kBlack);
	higgsNLPt_1->SetLineColor(kYellow -9);
	higgsNLPt_2->SetLineColor(kGreen);
	higgsNLPt2->SetLineColor(kBlue);
	higgsNLPt2_5->SetLineColor(kOrange-9);
	higgsNLPt3->SetLineColor(kViolet);
	
	higgsNLPt1->SetLineWidth(2);
	higgsNLPt0->SetLineWidth(2);
	higgsNLPt_1->SetLineWidth(2);
	higgsNLPt_2->SetLineWidth(2);
	higgsNLPt2->SetLineWidth(2);
	higgsNLPt2_5->SetLineWidth(2);
	higgsNLPt3->SetLineWidth(2);
	return;
}

void Set_jetPtProps()
{
	int nbins = 100;
	float ptmin = 0;
	float ptmax = 300;
	//b-jet leading Pt
	bjetLPt1  = new TH1D("bjetLPt1", "b-tagged Jet p_{t}; p_{t, leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjetLPt0  = new TH1D("bjetLPt0", "b-tagged Jet p_{t}; p_{t, leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjetLPt_1 = new TH1D("bjetLPt_1", "b-tagged Jet p_{t}; p_{t, leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjetLPt_2 = new TH1D("bjetLPt_2", "b-tagged Jet p_{t}; p_{t, leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjetLPt2  = new TH1D("bjetLPt2", "b-tagged Jet p_{t}; p_{t, leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjetLPt2_5= new TH1D("bjetLPt2_5", "b-tagged Jet p_{t}; p_{t, leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjetLPt3  = new TH1D("bjetLPt3", "b-tagged Jet p_{t}; p_{t, leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 2nd leading Pt
	bjet2LPt1  = new TH1D("bjet2LPt1", "b-tagged Jet p_{t}; p_{t, sub leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjet2LPt0  = new TH1D("bjet2LPt0", "b-tagged Jet p_{t}; p_{t, sub leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjet2LPt_1 = new TH1D("bjet2LPt_1", "b-tagged Jet p_{t}; p_{t, sub leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjet2LPt_2 = new TH1D("bjet2LPt_2", "b-tagged Jet p_{t}; p_{t, sub leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjet2LPt2  = new TH1D("bjet2LPt2", "b-tagged Jet p_{t}; p_{t, sub leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjet2LPt2_5= new TH1D("bjet2LPt2_5", "b-tagged Jet p_{t}; p_{t, sub leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjet2LPt3  = new TH1D("bjet2LPt3", "b-tagged Jet p_{t}; p_{t, sub leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 3rd leading Pt
	bjet3LPt1  = new TH1D("bjet3LPt1", "b-tagged Jet p_{t}; p_{t, 3rd leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjet3LPt0  = new TH1D("bjet3LPt0", "b-tagged Jet p_{t}; p_{t, 3rd leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjet3LPt_1 = new TH1D("bjet3LPt_1", "b-tagged Jet p_{t}; p_{t, 3rd leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjet3LPt_2 = new TH1D("bjet3LPt_2", "b-tagged Jet p_{t}; p_{t, 3rd leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjet3LPt2  = new TH1D("bjet3LPt2", "b-tagged Jet p_{t}; p_{t, 3rd leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjet3LPt2_5= new TH1D("bjet3LPt2_5", "b-tagged Jet p_{t}; p_{t, 3rd leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjet3LPt3  = new TH1D("bjet3LPt3", "b-tagged Jet p_{t}; p_{t, 3rd leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 4th leading Pt
	bjet4LPt1  = new TH1D("bjet4LPt1", "b-tagged Jet p_{t}; p_{t, 4th leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjet4LPt0  = new TH1D("bjet4LPt0", "b-tagged Jet p_{t}; p_{t, 4th leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjet4LPt_1 = new TH1D("bjet4LPt_1", "b-tagged Jet p_{t}; p_{t, 4th leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjet4LPt_2 = new TH1D("bjet4LPt_2", "b-tagged Jet p_{t}; p_{t, 4th leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjet4LPt2  = new TH1D("bjet4LPt2", "b-tagged Jet p_{t}; p_{t, 4th leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjet4LPt2_5= new TH1D("bjet4LPt2_5", "b-tagged Jet p_{t}; p_{t, 4th leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	bjet4LPt3  = new TH1D("bjet4LPt3", "b-tagged Jet p_{t}; p_{t, 4th leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	
	//jet leading Pt
	jetLPt1  = new TH1D("jetLPt1", "Jet p_{t}; p_{t, leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jetLPt0  = new TH1D("jetLPt0", "Jet p_{t}; p_{t, leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jetLPt_1 = new TH1D("jetLPt_1", "Jet p_{t}; p_{t, leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jetLPt_2 = new TH1D("jetLPt_2", "Jet p_{t}; p_{t, leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jetLPt2  = new TH1D("jetLPt2", "Jet p_{t}; p_{t, leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jetLPt2_5= new TH1D("jetLPt2_5", "Jet p_{t}; p_{t, leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jetLPt3  = new TH1D("jetLPt3", "Jet p_{t}; p_{t, leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 2nd leading Pt
	jet2LPt1  = new TH1D("jet2LPt1", "Jet p_{t}; p_{t, sub leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jet2LPt0  = new TH1D("jet2LPt0", "Jet p_{t}; p_{t, sub leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jet2LPt_1 = new TH1D("jet2LPt_1", "Jet p_{t}; p_{t, sub leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jet2LPt_2 = new TH1D("jet2LPt_2", "Jet p_{t}; p_{t, sub leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jet2LPt2  = new TH1D("jet2LPt2", "Jet p_{t}; p_{t, sub leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jet2LPt2_5= new TH1D("jet2LPt2_5", "Jet p_{t}; p_{t, sub leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jet2LPt3  = new TH1D("jet2LPt3", "Jet p_{t}; p_{t, sub leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 3rd leading Pt
	jet3LPt1  = new TH1D("jet3LPt1", "Jet p_{t}; p_{t, 3rd leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jet3LPt0  = new TH1D("jet3LPt0", "Jet p_{t}; p_{t, 3rd leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jet3LPt_1 = new TH1D("jet3LPt_1", "Jet p_{t}; p_{t, 3rd leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jet3LPt_2 = new TH1D("jet3LPt_2", "Jet p_{t}; p_{t, 3rd leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jet3LPt2  = new TH1D("jet3LPt2", "Jet p_{t}; p_{t, 3rd leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jet3LPt2_5= new TH1D("jet3LPt2_5", "Jet p_{t}; p_{t, 3rd leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jet3LPt3  = new TH1D("jet3LPt3", "Jet p_{t}; p_{t, 3rd leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 4th leading Pt
	jet4LPt1  = new TH1D("jet4LPt1", "Jet p_{t}; p_{t, 4th leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jet4LPt0  = new TH1D("jet4LPt0", "Jet p_{t}; p_{t, 4th leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jet4LPt_1 = new TH1D("jet4LPt_1", "Jet p_{t}; p_{t, 4th leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jet4LPt_2 = new TH1D("jet4LPt_2", "Jet p_{t}; p_{t, 4th leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jet4LPt2  = new TH1D("jet4LPt2", "Jet p_{t}; p_{t, 4th leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jet4LPt2_5= new TH1D("jet4LPt2_5", "Jet p_{t}; p_{t, 4th leading jet} [GeV/c];", nbins, ptmin, ptmax);
	jet4LPt3  = new TH1D("jet4LPt3", "Jet p_{t}; p_{t, 4th leading jet} [GeV/c];", nbins, ptmin, ptmax);
	return;
}
int get_Nentries()
{
	n_entries1 = t1->GetEntries();
	n_entries2 = t0->GetEntries();
	n_entries3 = t_1->GetEntries();
	n_entries4 = t_2->GetEntries();
	n_entries5 = t2->GetEntries();
	n_entries6 = t2_5->GetEntries();
	n_entries7 = t3->GetEntries();
	assert (n_entries1 = n_entries2);
	assert (n_entries2 = n_entries3);
	assert (n_entries3 = n_entries4);
	assert (n_entries4 = n_entries5);
	assert (n_entries5 = n_entries6);
	assert (n_entries6 = n_entries7);
	return n_entries1;
}
void fetch_TTrees()
{
	t1   = (TTree*)f1->Get("glob_jet");
	t0   = (TTree*)f0->Get("glob_jet");
	t_1  = (TTree*)f_1->Get("glob_jet");
	t_2  = (TTree*)f_2->Get("glob_jet");
	t2   = (TTree*)f2->Get("glob_jet");
	t2_5 = (TTree*)f2_5->Get("glob_jet");
	t3   = (TTree*)f3->Get("glob_jet");

	t1->SetBranchStatus("*",0);
	t0->SetBranchStatus("*",0);
	t_1->SetBranchStatus("*",0);
	t_2->SetBranchStatus("*",0);
	t2->SetBranchStatus("*",0);
	t2_5->SetBranchStatus("*",0);
	t3->SetBranchStatus("*",0);
	
	t1->SetBranchStatus("higgsLPt",1);
	t0->SetBranchStatus("higgsLPt",1);
	t_1->SetBranchStatus("higgsLPt",1);
	t_2->SetBranchStatus("higgsLPt",1);
	t2->SetBranchStatus("higgsLPt",1);
	t2_5->SetBranchStatus("higgsLPt",1);
	t3->SetBranchStatus("higgsLPt",1);
	
	t1->SetBranchStatus("higgsNLPt",1);
	t0->SetBranchStatus("higgsNLPt",1);
	t_1->SetBranchStatus("higgsNLPt",1);
	t_2->SetBranchStatus("higgsNLPt",1);
	t2->SetBranchStatus("higgsNLPt",1);
	t2_5->SetBranchStatus("higgsNLPt",1);
	t3->SetBranchStatus("higgsNLPt",1);

	t1->SetBranchStatus("NSMhiggs",1);
	t0->SetBranchStatus("NSMhiggs",1);
	t_1->SetBranchStatus("NSMhiggs",1);
	t_2->SetBranchStatus("NSMhiggs",1);
	t2->SetBranchStatus("NSMhiggs",1);
	t2_5->SetBranchStatus("NSMhiggs",1);
	t3->SetBranchStatus("NSMhiggs",1);

	t1->SetBranchStatus("Nbquarks",1);
	t0->SetBranchStatus("Nbquarks",1);
	t_1->SetBranchStatus("Nbquarks",1);
	t_2->SetBranchStatus("Nbquarks",1);
	t2->SetBranchStatus("Nbquarks",1);
	t2_5->SetBranchStatus("Nbquarks",1);
	t3->SetBranchStatus("Nbquarks",1);
	
	t1->SetBranchStatus("Njets",1);
	t0->SetBranchStatus("Njets",1);
	t_1->SetBranchStatus("Njets",1);
	t_2->SetBranchStatus("Njets",1);
	t2->SetBranchStatus("Njets",1);
	t2_5->SetBranchStatus("Njets",1);
	t3->SetBranchStatus("Njets",1);
	
	t1->SetBranchStatus("jetPt",1);
	t0->SetBranchStatus("jetPt",1);
	t_1->SetBranchStatus("jetPt",1);
	t_2->SetBranchStatus("jetPt",1);
	t2->SetBranchStatus("jetPt",1);
	t2_5->SetBranchStatus("jetPt",1);
	t3->SetBranchStatus("jetPt",1);
	t1->SetBranchAddress("jetPt",  &v1_jetPt);
	t0->SetBranchAddress("jetPt",  &v0_jetPt);
	t_1->SetBranchAddress("jetPt", &v_1_jetPt);
	t_2->SetBranchAddress("jetPt", &v_2_jetPt);
	t2->SetBranchAddress("jetPt",  &v2_jetPt);
	t2_5->SetBranchAddress("jetPt",&v2_5_jetPt);
	t3->SetBranchAddress("jetPt",  &v3_jetPt);
	
	t1->SetBranchStatus("bJetLPt",1);
	t0->SetBranchStatus("bJetLPt",1);
	t_1->SetBranchStatus("bJetLPt",1);
	t_2->SetBranchStatus("bJetLPt",1);
	t2->SetBranchStatus("bJetLPt",1);
	t2_5->SetBranchStatus("bJetLPt",1);
	t3->SetBranchStatus("bJetLPt",1);
	
	t1->SetBranchStatus("bJetNLPt",1);
	t0->SetBranchStatus("bJetNLPt",1);
	t_1->SetBranchStatus("bJetNLPt",1);
	t_2->SetBranchStatus("bJetNLPt",1);
	t2->SetBranchStatus("bJetNLPt",1);
	t2_5->SetBranchStatus("bJetNLPt",1);
	t3->SetBranchStatus("bJetNLPt",1);
	
	t1->SetBranchStatus("bJetNNLPt",1);
	t0->SetBranchStatus("bJetNNLPt",1);
	t_1->SetBranchStatus("bJetNNLPt",1);
	t_2->SetBranchStatus("bJetNNLPt",1);
	t2->SetBranchStatus("bJetNNLPt",1);
	t2_5->SetBranchStatus("bJetNNLPt",1);
	t3->SetBranchStatus("bJetNNLPt",1);
	
	t1->SetBranchStatus("bJetNNNLPt",1);
	t0->SetBranchStatus("bJetNNNLPt",1);
	t_1->SetBranchStatus("bJetNNNLPt",1);
	t_2->SetBranchStatus("bJetNNNLPt",1);
	t2->SetBranchStatus("bJetNNNLPt",1);
	t2_5->SetBranchStatus("bJetNNNLPt",1);
	t3->SetBranchStatus("bJetNNNLPt",1);
	
	return;
}
void Draw_Nparticles()
{
	int nbins = 6;
	double nmin = 0, nmax = 6;
	//Number of SMhiggs 
	NSMhiggs1  = new TH1D("NSMhiggs1", "number of higgs", nbins, nmin, nmax);
	NSMhiggs0  = new TH1D("NSMhiggs0", "number of higgs", nbins, nmin, nmax);
	NSMhiggs_1 = new TH1D("NSMhiggs_1", "number of higgs", nbins, nmin, nmax);
	NSMhiggs_2 = new TH1D("NSMhiggs_2", "number of higgs", nbins, nmin, nmax);
	NSMhiggs2  = new TH1D("NSMhiggs2", "number of higgs", nbins, nmin, nmax);
	NSMhiggs2_5= new TH1D("NSMhiggs2_5", "number of higgs", nbins, nmin, nmax);
	NSMhiggs3  = new TH1D("NSMhiggs3", "number of higgs", nbins, nmin, nmax);
	//Number of bquarks 
	Nbquarks1  = new TH1D("Nbquarks1", "number of b quarks", nbins, nmin, nmax);
	Nbquarks0  = new TH1D("Nbquarks0", "number of b quarks", nbins, nmin, nmax);
	Nbquarks_1 = new TH1D("Nbquarks_1", "number of b quarks", nbins, nmin, nmax);
	Nbquarks_2 = new TH1D("Nbquarks_2", "number of b quarks", nbins, nmin, nmax);
	Nbquarks2  = new TH1D("Nbquarks2", "number of b quarks", nbins, nmin, nmax);
	Nbquarks2_5= new TH1D("Nbquarks2_5", "number of b quarks", nbins, nmin, nmax);
	Nbquarks3  = new TH1D("Nbquarks3", "number of b quarks", nbins, nmin, nmax);
	
	t1->Draw("Nbquarks>>Nbquarks1");
	t0->Draw("Nbquarks>>Nbquarks0");
	t_1->Draw("Nbquarks>>Nbquarks_1");
	t_2->Draw("Nbquarks>>Nbquarks_2");
	t2->Draw("Nbquarks>>Nbquarks2");
	t2_5->Draw("Nbquarks>>Nbquarks2_5");
	t3->Draw("Nbquarks>>Nbquarks3");

	t1->Draw("NSMhiggs>>NSMhiggs1");
	t0->Draw("NSMhiggs>>NSMhiggs0");
	t_1->Draw("NSMhiggs>>NSMhiggs_1");
	t_2->Draw("NSMhiggs>>NSMhiggs_2");
	t2->Draw("NSMhiggs>>NSMhiggs2");
	t2_5->Draw("NSMhiggs>>NSMhiggs2_5");
	t3->Draw("NSMhiggs>>NSMhiggs3");
	
	Nbquarks1->SetLineColor(kRed);
	Nbquarks0->SetLineColor(kBlack);
	Nbquarks_1->SetLineColor(kYellow -9);
	Nbquarks_2->SetLineColor(kGreen);
	Nbquarks2->SetLineColor(kBlue);
	Nbquarks2_5->SetLineColor(kOrange-9);
	Nbquarks3->SetLineColor(kViolet);

	NSMhiggs1->SetLineColor(kRed);
	NSMhiggs0->SetLineColor(kBlack);
	NSMhiggs_1->SetLineColor(kYellow -9);
	NSMhiggs_2->SetLineColor(kGreen);
	NSMhiggs2->SetLineColor(kBlue);
	NSMhiggs2_5->SetLineColor(kOrange-9);
	NSMhiggs3->SetLineColor(kViolet);
	return;
}
void Draw_higgsPt()
{
	
	t1->Draw("higgsLPt*1e-3>>higgsPt1");
	t0->Draw("higgsLPt*1e-3>>higgsPt0");
	t_1->Draw("higgsLPt*1e-3>>higgsPt_1");
	t_2->Draw("higgsLPt*1e-3>>higgsPt_2");
	t2->Draw("higgsLPt*1e-3>>higgsPt2");
	t2_5->Draw("higgsLPt*1e-3>>higgsPt2_5");
	t3->Draw("higgsLPt*1e-3>>higgsPt3");

	t1->Draw("higgsNLPt*1e-3>>higgsNLPt1");
	t0->Draw("higgsNLPt*1e-3>>higgsNLPt0");
	t_1->Draw("higgsNLPt*1e-3>>higgsNLPt_1");
	t_2->Draw("higgsNLPt*1e-3>>higgsNLPt_2");
	t2->Draw("higgsNLPt*1e-3>>higgsNLPt2");
	t2_5->Draw("higgsNLPt*1e-3>>higgsNLPt2_5");
	t3->Draw("higgsNLPt*1e-3>>higgsNLPt3");
	
	return;
}
void Draw_b_jetPt()
{
	
	t1->Draw("bJetLPt>>bjetLPt1");
	t0->Draw("bJetLPt>>bjetLPt0");
	t_1->Draw("bJetLPt>>bjetLPt_1");
	t_2->Draw("bJetLPt>>bjetLPt_2");
	t2->Draw("bJetLPt>>bjetLPt2");
	t2_5->Draw("bJetLPt>>bjetLPt2_5");
	t3->Draw("bJetLPt>>bjetLPt3");
	
	t1->Draw("bJetNLPt>>bjet2LPt1");
	t0->Draw("bJetNLPt>>bjet2LPt0");
	t_1->Draw("bJetNLPt>>bjet2LPt_1");
	t_2->Draw("bJetNLPt>>bjet2LPt_2");
	t2->Draw("bJetNLPt>>bjet2LPt2");
	t2_5->Draw("bJetNLPt>>bjet2LPt2_5");
	t3->Draw("bJetNLPt>>bjet2LPt3");
	
	t1->Draw("bJetNNLPt>>bjet3LPt1");
	t0->Draw("bJetNNLPt>>bjet3LPt0");
	t_1->Draw("bJetNNLPt>>bjet3LPt_1");
	t_2->Draw("bJetNNLPt>>bjet3LPt_2");
	t2->Draw("bJetNNLPt>>bjet3LPt2");
	t2_5->Draw("bJetNNLPt>>bjet3LPt2_5");
	t3->Draw("bJetNNLPt>>bjet3LPt3");
	
	t1->Draw("bJetNNNLPt>>bjet4LPt1");
	t0->Draw("bJetNNNLPt>>bjet4LPt0");
	t_1->Draw("bJetNNNLPt>>bjet4LPt_1");
	t_2->Draw("bJetNNNLPt>>bjet4LPt_2");
	t2->Draw("bJetNNNLPt>>bjet4LPt2");
	t2_5->Draw("bJetNNNLPt>>bjet4LPt2_5");
	t3->Draw("bJetNNNLPt>>bjet4LPt3");

	return;
}

void fetch_histos()
{
	////bjetLPt1  = (TH1D*)f1->Get("hbJetPt_Lpt");
	////bjet2LPt1 = (TH1D*)f1->Get("hbJetPt_NLpt");
	////bjet3LPt1 = (TH1D*)f1->Get("hbJetPt_NNLpt");
	////bjet4LPt1 = (TH1D*)f1->Get("hbJetPt_NNNLpt");
	////
	////bjetLPt0  = (TH1D*)f0->Get("hbJetPt_Lpt");
	////bjet2LPt0 = (TH1D*)f0->Get("hbJetPt_NLpt");
	////bjet3LPt0 = (TH1D*)f0->Get("hbJetPt_NNLpt");
	////bjet4LPt0 = (TH1D*)f0->Get("hbJetPt_NNNLpt");
	////
	////bjetLPt_1  = (TH1D*)f_1->Get("hbJetPt_Lpt");
	////bjet2LPt_1 = (TH1D*)f_1->Get("hbJetPt_NLpt");
	////bjet3LPt_1 = (TH1D*)f_1->Get("hbJetPt_NNLpt");
	////bjet4LPt_1 = (TH1D*)f_1->Get("hbJetPt_NNNLpt");
	////
	////bjetLPt_2  = (TH1D*)f_2->Get("hbJetPt_Lpt");
	////bjet2LPt_2 = (TH1D*)f_2->Get("hbJetPt_NLpt");
	////bjet3LPt_2 = (TH1D*)f_2->Get("hbJetPt_NNLpt");
	////bjet4LPt_2 = (TH1D*)f_2->Get("hbJetPt_NNNLpt");
	////
	////bjetLPt2  = (TH1D*)f2->Get("hbJetPt_Lpt");
	////bjet2LPt2 = (TH1D*)f2->Get("hbJetPt_NLpt");
	////bjet3LPt2 = (TH1D*)f2->Get("hbJetPt_NNLpt");
	////bjet4LPt2 = (TH1D*)f2->Get("hbJetPt_NNNLpt");
	////
	////bjetLPt2_5  = (TH1D*)f2_5->Get("hbJetPt_Lpt");
	////bjet2LPt2_5 = (TH1D*)f2_5->Get("hbJetPt_NLpt");
	////bjet3LPt2_5 = (TH1D*)f2_5->Get("hbJetPt_NNLpt");
	////bjet4LPt2_5 = (TH1D*)f2_5->Get("hbJetPt_NNNLpt");
	////
	////
	////bjetLPt3  = (TH1D*)f3->Get("hbJetPt_Lpt");
	////bjet2LPt3 = (TH1D*)f3->Get("hbJetPt_NLpt");
	////bjet3LPt3 = (TH1D*)f3->Get("hbJetPt_NNLpt");
	////bjet4LPt3 = (TH1D*)f3->Get("hbJetPt_NNNLpt");
	//
	//jetLPt1  = (TH1D*)f1->Get("hJetPt_PULpt");
	//jet2LPt1 = (TH1D*)f1->Get("hJetPt_PUNLpt");
	//jet3LPt1 = (TH1D*)f1->Get("hJetPt_PUNNLpt");
	//jet4LPt1 = (TH1D*)f1->Get("hJetPt_PUNNNLpt");
	//jet5LPt1 = (TH1D*)f1->Get("hJetPt_PUNNNNLpt");
	//
	//jetLPt0  = (TH1D*)f0->Get("hJetPt_PULpt");
	//jet2LPt0 = (TH1D*)f0->Get("hJetPt_PUNLpt");
	//jet3LPt0 = (TH1D*)f0->Get("hJetPt_PUNNLpt");
	//jet4LPt0 = (TH1D*)f0->Get("hJetPt_PUNNNLpt");
	//jet5LPt0 = (TH1D*)f0->Get("hJetPt_PUNNNNLpt");
	//
	//jetLPt_1  = (TH1D*)f_1->Get("hJetPt_PULpt");
	//jet2LPt_1 = (TH1D*)f_1->Get("hJetPt_PUNLpt");
	//jet3LPt_1 = (TH1D*)f_1->Get("hJetPt_PUNNLpt");
	//jet4LPt_1 = (TH1D*)f_1->Get("hJetPt_PUNNNLpt");
	//jet5LPt_1 = (TH1D*)f_1->Get("hJetPt_PUNNNNLpt");
	//
	//jetLPt_2  = (TH1D*)f_2->Get("hJetPt_PULpt");
	//jet2LPt_2 = (TH1D*)f_2->Get("hJetPt_PUNLpt");
	//jet3LPt_2 = (TH1D*)f_2->Get("hJetPt_PUNNLpt");
	//jet4LPt_2 = (TH1D*)f_2->Get("hJetPt_PUNNNLpt");
	//jet5LPt_2 = (TH1D*)f_2->Get("hJetPt_PUNNNNLpt");
	//
	//jetLPt2  = (TH1D*)f2->Get("hJetPt_PULpt");
	//jet2LPt2 = (TH1D*)f2->Get("hJetPt_PUNLpt");
	//jet3LPt2 = (TH1D*)f2->Get("hJetPt_PUNNLpt");
	//jet4LPt2 = (TH1D*)f2->Get("hJetPt_PUNNNLpt");
	//jet5LPt2 = (TH1D*)f2->Get("hJetPt_PUNNNNLpt");
	//
	//jetLPt2_5  = (TH1D*)f2_5->Get("hJetPt_PULpt");
	//jet2LPt2_5 = (TH1D*)f2_5->Get("hJetPt_PUNLpt");
	//jet3LPt2_5 = (TH1D*)f2_5->Get("hJetPt_PUNNLpt");
	//jet4LPt2_5 = (TH1D*)f2_5->Get("hJetPt_PUNNNLpt");
	//jet5LPt2_5 = (TH1D*)f2_5->Get("hJetPt_PUNNNNLpt");
	//
	//jetLPt3  = (TH1D*)f3->Get("hJetPt_PULpt");
	//jet2LPt3 = (TH1D*)f3->Get("hJetPt_PUNLpt");
	//jet3LPt3 = (TH1D*)f3->Get("hJetPt_PUNNLpt");
	//jet4LPt3 = (TH1D*)f3->Get("hJetPt_PUNNNLpt");
	//jet5LPt3 = (TH1D*)f3->Get("hJetPt_PUNNNNLpt");
	

	bLPt1  = (TH1D*)f1->Get("hbPt_Lpt");
	b2LPt1 = (TH1D*)f1->Get("hbPt_NLpt");
	b3LPt1 = (TH1D*)f1->Get("hbPt_NNLpt");
	b4LPt1 = (TH1D*)f1->Get("hbPt_NNNLpt");
	
	bLPt0  = (TH1D*)f0->Get("hbPt_Lpt");
	b2LPt0 = (TH1D*)f0->Get("hbPt_NLpt");
	b3LPt0 = (TH1D*)f0->Get("hbPt_NNLpt");
	b4LPt0 = (TH1D*)f0->Get("hbPt_NNNLpt");
	
	bLPt_1  = (TH1D*)f_1->Get("hbPt_Lpt");
	b2LPt_1 = (TH1D*)f_1->Get("hbPt_NLpt");
	b3LPt_1 = (TH1D*)f_1->Get("hbPt_NNLpt");
	b4LPt_1 = (TH1D*)f_1->Get("hbPt_NNNLpt");
	
	bLPt_2  = (TH1D*)f_2->Get("hbPt_Lpt");
	b2LPt_2 = (TH1D*)f_2->Get("hbPt_NLpt");
	b3LPt_2 = (TH1D*)f_2->Get("hbPt_NNLpt");
	b4LPt_2 = (TH1D*)f_2->Get("hbPt_NNNLpt");
	
	bLPt2  = (TH1D*)f2->Get("hbPt_Lpt");
	b2LPt2 = (TH1D*)f2->Get("hbPt_NLpt");
	b3LPt2 = (TH1D*)f2->Get("hbPt_NNLpt");
	b4LPt2 = (TH1D*)f2->Get("hbPt_NNNLpt");
	
	bLPt2_5  = (TH1D*)f2_5->Get("hbPt_Lpt");
	b2LPt2_5 = (TH1D*)f2_5->Get("hbPt_NLpt");
	b3LPt2_5 = (TH1D*)f2_5->Get("hbPt_NNLpt");
	b4LPt2_5 = (TH1D*)f2_5->Get("hbPt_NNNLpt");
	
	bLPt3  = (TH1D*)f3->Get("hbPt_Lpt");
	b2LPt3 = (TH1D*)f3->Get("hbPt_NLpt");
	b3LPt3 = (TH1D*)f3->Get("hbPt_NNLpt");
	b4LPt3 = (TH1D*)f3->Get("hbPt_NNNLpt");
	
	
	bCEta1  = (TH1D*)f1->Get("hbEta_Ceta");
	b2CEta1 = (TH1D*)f1->Get("hbEta_NCeta");
	b3CEta1 = (TH1D*)f1->Get("hbEta_NNCeta");
	b4CEta1 = (TH1D*)f1->Get("hbEta_NNNCeta");
	
	bCEta0  = (TH1D*)f0->Get("hbEta_Ceta");
	b2CEta0 = (TH1D*)f0->Get("hbEta_NCeta");
	b3CEta0 = (TH1D*)f0->Get("hbEta_NNCeta");
	b4CEta0 = (TH1D*)f0->Get("hbEta_NNNCeta");
	
	bCEta_1  = (TH1D*)f_1->Get("hbEta_Ceta");
	b2CEta_1 = (TH1D*)f_1->Get("hbEta_NCeta");
	b3CEta_1 = (TH1D*)f_1->Get("hbEta_NNCeta");
	b4CEta_1 = (TH1D*)f_1->Get("hbEta_NNNCeta");
	
	bCEta_2  = (TH1D*)f_2->Get("hbEta_Ceta");
	b2CEta_2 = (TH1D*)f_2->Get("hbEta_NCeta");
	b3CEta_2 = (TH1D*)f_2->Get("hbEta_NNCeta");
	b4CEta_2 = (TH1D*)f_2->Get("hbEta_NNNCeta");
	
	bCEta2  = (TH1D*)f2->Get("hbEta_Ceta");
	b2CEta2 = (TH1D*)f2->Get("hbEta_NCeta");
	b3CEta2 = (TH1D*)f2->Get("hbEta_NNCeta");
	b4CEta2 = (TH1D*)f2->Get("hbEta_NNNCeta");
	
	bCEta2_5  = (TH1D*)f2_5->Get("hbEta_Ceta");
	b2CEta2_5 = (TH1D*)f2_5->Get("hbEta_NCeta");
	b3CEta2_5 = (TH1D*)f2_5->Get("hbEta_NNCeta");
	b4CEta2_5 = (TH1D*)f2_5->Get("hbEta_NNNCeta");
	
	bCEta3  = (TH1D*)f3->Get("hbEta_Ceta");
	b2CEta3 = (TH1D*)f3->Get("hbEta_NCeta");
	b3CEta3 = (TH1D*)f3->Get("hbEta_NNCeta");
	b4CEta3 = (TH1D*)f3->Get("hbEta_NNNCeta");
	return;
}
void Set_NleadingJetColors()
{
	jetLPt1->SetLineColor(kOrange);
	jetLPt0->SetLineColor(kOrange);
	jetLPt_1->SetLineColor(kOrange);
	jetLPt_2->SetLineColor(kOrange);
	jetLPt2->SetLineColor(kOrange);
	jetLPt2_5->SetLineColor(kOrange);
	jetLPt3->SetLineColor(kOrange);
	
	jet2LPt1->SetLineColor(kBlack);
	jet2LPt0->SetLineColor(kBlack);
	jet2LPt_1->SetLineColor(kBlack);
	jet2LPt_2->SetLineColor(kBlack);
	jet2LPt2->SetLineColor(kBlack);
	jet2LPt2_5->SetLineColor(kBlack);
	jet2LPt3->SetLineColor(kBlack);
	
	jet3LPt1->SetLineColor(kRed);
	jet3LPt0->SetLineColor(kRed);
	jet3LPt_1->SetLineColor(kRed);
	jet3LPt_2->SetLineColor(kRed);
	jet3LPt2->SetLineColor(kRed);
	jet3LPt2_5->SetLineColor(kRed);
	jet3LPt3->SetLineColor(kRed);
	
	jet4LPt1->SetLineColor(kGreen);
	jet4LPt0->SetLineColor(kGreen);
	jet4LPt_1->SetLineColor(kGreen);
	jet4LPt_2->SetLineColor(kGreen);
	jet4LPt2->SetLineColor(kGreen);
	jet4LPt2_5->SetLineColor(kGreen);
	jet4LPt3->SetLineColor(kGreen);
	
	bjetLPt1->SetLineColor(kOrange);
	bjetLPt0->SetLineColor(kOrange);
	bjetLPt_1->SetLineColor(kOrange);
	bjetLPt_2->SetLineColor(kOrange);
	bjetLPt2->SetLineColor(kOrange);
	bjetLPt2_5->SetLineColor(kOrange);
	bjetLPt3->SetLineColor(kOrange);
	
	bjet2LPt1->SetLineColor(kBlack);
	bjet2LPt0->SetLineColor(kBlack);
	bjet2LPt_1->SetLineColor(kBlack);
	bjet2LPt_2->SetLineColor(kBlack);
	bjet2LPt2->SetLineColor(kBlack);
	bjet2LPt2_5->SetLineColor(kBlack);
	bjet2LPt3->SetLineColor(kBlack);
	
	bjet3LPt1->SetLineColor(kRed);
	bjet3LPt0->SetLineColor(kRed);
	bjet3LPt_1->SetLineColor(kRed);
	bjet3LPt_2->SetLineColor(kRed);
	bjet3LPt2->SetLineColor(kRed);
	bjet3LPt2_5->SetLineColor(kRed);
	bjet3LPt3->SetLineColor(kRed);
	
	bjet4LPt1->SetLineColor(kGreen);
	bjet4LPt0->SetLineColor(kGreen);
	bjet4LPt_1->SetLineColor(kGreen);
	bjet4LPt_2->SetLineColor(kGreen);
	bjet4LPt2->SetLineColor(kGreen);
	bjet4LPt2_5->SetLineColor(kGreen);
	bjet4LPt3->SetLineColor(kGreen);

}
void Set_bquark_lambdaColors()
{
	
	jetLPt1->SetLineColor(kRed);
	jetLPt0->SetLineColor(kBlack);
	jetLPt_1->SetLineColor(kYellow -9);
	jetLPt_2->SetLineColor(kGreen);
	jetLPt2->SetLineColor(kBlue);
	jetLPt2_5->SetLineColor(kOrange-9);
	jetLPt3->SetLineColor(kViolet);
	
	jet2LPt1->SetLineColor(kRed);
	jet2LPt0->SetLineColor(kBlack);
	jet2LPt_1->SetLineColor(kYellow -9);
	jet2LPt_2->SetLineColor(kGreen);
	jet2LPt2->SetLineColor(kBlue);
	jet2LPt2_5->SetLineColor(kOrange-9);
	jet2LPt3->SetLineColor(kViolet);
	
	jet3LPt1->SetLineColor(kRed);
	jet3LPt0->SetLineColor(kBlack);
	jet3LPt_1->SetLineColor(kYellow -9);
	jet3LPt_2->SetLineColor(kGreen);
	jet3LPt2->SetLineColor(kBlue);
	jet3LPt2_5->SetLineColor(kOrange-9);
	jet3LPt3->SetLineColor(kViolet);
	
	jet4LPt1->SetLineColor(kRed);
	jet4LPt0->SetLineColor(kBlack);
	jet4LPt_1->SetLineColor(kYellow -9);
	jet4LPt_2->SetLineColor(kGreen);
	jet4LPt2->SetLineColor(kBlue);
	jet4LPt2_5->SetLineColor(kOrange-9);
	jet4LPt3->SetLineColor(kViolet);
	
	bjetLPt1->SetLineColor(kRed);
	bjetLPt0->SetLineColor(kBlack);
	bjetLPt_1->SetLineColor(kYellow -9);
	bjetLPt_2->SetLineColor(kGreen);
	bjetLPt2->SetLineColor(kBlue);
	bjetLPt2_5->SetLineColor(kOrange-9);
	bjetLPt3->SetLineColor(kViolet);
	
	bjet2LPt1->SetLineColor(kRed);
	bjet2LPt0->SetLineColor(kBlack);
	bjet2LPt_1->SetLineColor(kYellow -9);
	bjet2LPt_2->SetLineColor(kGreen);
	bjet2LPt2->SetLineColor(kBlue);
	bjet2LPt2_5->SetLineColor(kOrange-9);
	bjet2LPt3->SetLineColor(kViolet);
	
	bjet3LPt1->SetLineColor(kRed);
	bjet3LPt0->SetLineColor(kBlack);
	bjet3LPt_1->SetLineColor(kYellow -9);
	bjet3LPt_2->SetLineColor(kGreen);
	bjet3LPt2->SetLineColor(kBlue);
	bjet3LPt2_5->SetLineColor(kOrange-9);
	bjet3LPt3->SetLineColor(kViolet);
	
	bjet4LPt1->SetLineColor(kRed);
	bjet4LPt0->SetLineColor(kBlack);
	bjet4LPt_1->SetLineColor(kYellow -9);
	bjet4LPt_2->SetLineColor(kGreen);
	bjet4LPt2->SetLineColor(kBlue);
	bjet4LPt2_5->SetLineColor(kOrange-9);
	bjet4LPt3->SetLineColor(kViolet);

	bLPt1->SetLineColor(kRed);
	bLPt0->SetLineColor(kBlack);
	bLPt_1->SetLineColor(kYellow -9);
	bLPt_2->SetLineColor(kGreen);
	bLPt2->SetLineColor(kBlue);
	bLPt2_5->SetLineColor(kOrange-9);
	bLPt3->SetLineColor(kViolet);
	
	b2LPt1->SetLineColor(kRed);
	b2LPt0->SetLineColor(kBlack);
	b2LPt_1->SetLineColor(kYellow -9);
	b2LPt_2->SetLineColor(kGreen);
	b2LPt2->SetLineColor(kBlue);
	b2LPt2_5->SetLineColor(kOrange-9);
	b2LPt3->SetLineColor(kViolet);
	
	b3LPt1->SetLineColor(kRed);
	b3LPt0->SetLineColor(kBlack);
	b3LPt_1->SetLineColor(kYellow -9);
	b3LPt_2->SetLineColor(kGreen);
	b3LPt2->SetLineColor(kBlue);
	b3LPt2_5->SetLineColor(kOrange-9);
	b3LPt3->SetLineColor(kViolet);
	
	b4LPt1->SetLineColor(kRed);
	b4LPt0->SetLineColor(kBlack);
	b4LPt_1->SetLineColor(kYellow -9);
	b4LPt_2->SetLineColor(kGreen);
	b4LPt2->SetLineColor(kBlue);
	b4LPt2_5->SetLineColor(kOrange-9);
	b4LPt3->SetLineColor(kViolet);
	
	bCEta1->SetLineColor(kRed);
	bCEta0->SetLineColor(kBlack);
	bCEta_1->SetLineColor(kYellow -9);
	bCEta_2->SetLineColor(kGreen);
	bCEta2->SetLineColor(kBlue);
	bCEta2_5->SetLineColor(kOrange-9);
	bCEta3->SetLineColor(kViolet);
	
	b2CEta1->SetLineColor(kRed);
	b2CEta0->SetLineColor(kBlack);
	b2CEta_1->SetLineColor(kYellow -9);
	b2CEta_2->SetLineColor(kGreen);
	b2CEta2->SetLineColor(kBlue);
	b2CEta2_5->SetLineColor(kOrange-9);
	b2CEta3->SetLineColor(kViolet);
	
	b3CEta1->SetLineColor(kRed);
	b3CEta0->SetLineColor(kBlack);
	b3CEta_1->SetLineColor(kYellow -9);
	b3CEta_2->SetLineColor(kGreen);
	b3CEta2->SetLineColor(kBlue);
	b3CEta2_5->SetLineColor(kOrange-9);
	b3CEta3->SetLineColor(kViolet);
	
	b4CEta1->SetLineColor(kRed);
	b4CEta0->SetLineColor(kBlack);
	b4CEta_1->SetLineColor(kYellow -9);
	b4CEta_2->SetLineColor(kGreen);
	b4CEta2->SetLineColor(kBlue);
	b4CEta2_5->SetLineColor(kOrange-9);
	b4CEta3->SetLineColor(kViolet);
	return;
}
void Set_LegendProps()
{

	leg_higgs->SetFillStyle(0);
	leg_higgs->SetBorderSize(0);
	leg_higgs->SetTextAlign(32);
	leg_higgs->SetTextFont(62);
	leg_higgs->SetTextSize(0.035);

	leg1->SetFillStyle(0);
	leg1->SetBorderSize(0);
	leg1->SetTextAlign(32);
	leg1->SetTextFont(62);
	leg1->SetTextSize(0.035);

	leg2->SetFillStyle(0);
	leg2->SetBorderSize(0);
	leg2->SetTextAlign(32);
	leg2->SetTextFont(62);
	leg2->SetTextSize(0.035);

	leg3->SetFillStyle(0);
	leg3->SetBorderSize(0);
	leg3->SetTextAlign(32);
	leg3->SetTextFont(62);
	leg3->SetTextSize(0.035);

	leg4->SetFillStyle(0);
	leg4->SetBorderSize(0);
	leg4->SetTextAlign(32);
	leg4->SetTextFont(62);
	leg4->SetTextSize(0.035);
	return;
}

void Draw_NleadingJetPt()
{
	int n_entries = get_Nentries();
	int min_Njets = 4;
	for(int i = 0; i < n_entries; ++i)
	{
		t1->GetEntry(i);
		t0->GetEntry(i);
		t_1->GetEntry(i);
		t_2->GetEntry(i);
		t2->GetEntry(i);
		t2_5->GetEntry(i);
		t3->GetEntry(i);
		if (v1_jetPt->size() >= min_Njets)
		{
			jetLPt1->Fill((*v1_jetPt)[0]*1e-3);
			jet2LPt1->Fill((*v1_jetPt)[1]*1e-3);
			jet3LPt1->Fill((*v1_jetPt)[2]*1e-3);
			jet4LPt1->Fill((*v1_jetPt)[3]*1e-3);
		}
		if (v0_jetPt->size() >= min_Njets)
		{
			jetLPt0->Fill((*v0_jetPt)[0]*1e-3);
			jet2LPt0->Fill((*v0_jetPt)[1]*1e-3);
			jet3LPt0->Fill((*v0_jetPt)[2]*1e-3);
			jet4LPt0->Fill((*v0_jetPt)[3]*1e-3);
		}
		if (v_1_jetPt->size() >= min_Njets)
		{
			jetLPt_1->Fill((*v_1_jetPt)[0]*1e-3);
			jet2LPt_1->Fill((*v_1_jetPt)[1]*1e-3);
			jet3LPt_1->Fill((*v_1_jetPt)[2]*1e-3);
			jet4LPt_1->Fill((*v_1_jetPt)[3]*1e-3);
		}
		if (v_2_jetPt->size() >= min_Njets)
		{
			jetLPt_2->Fill((*v_2_jetPt)[0]*1e-3);
			jet2LPt_2->Fill((*v_2_jetPt)[1]*1e-3);
			jet3LPt_2->Fill((*v_2_jetPt)[2]*1e-3);
			jet4LPt_2->Fill((*v_2_jetPt)[3]*1e-3);
		}
		if (v2_jetPt->size() >= min_Njets)
		{
			jetLPt2->Fill((*v2_jetPt)[0]*1e-3);
			jet2LPt2->Fill((*v2_jetPt)[1]*1e-3);
			jet3LPt2->Fill((*v2_jetPt)[2]*1e-3);
			jet4LPt2->Fill((*v2_jetPt)[3]*1e-3);
		}
		if (v2_5_jetPt->size() >= min_Njets)
		{
			jetLPt2_5->Fill((*v2_5_jetPt)[0]*1e-3);
			jet2LPt2_5->Fill((*v2_5_jetPt)[1]*1e-3);
			jet3LPt2_5->Fill((*v2_5_jetPt)[2]*1e-3);
			jet4LPt2_5->Fill((*v2_5_jetPt)[3]*1e-3);
		}
		if (v3_jetPt->size() >= min_Njets)
		{
			jetLPt3->Fill((*v3_jetPt)[0]*1e-3);
			jet2LPt3->Fill((*v3_jetPt)[1]*1e-3);
			jet3LPt3->Fill((*v3_jetPt)[2]*1e-3);
			jet4LPt3->Fill((*v3_jetPt)[3]*1e-3);
		}

	}
	return;

}

int main()
{
	f1  = new TFile(inp_file1,"READ");
	f0  = new TFile(inp_file0,"READ");
	f_1 = new TFile(inp_file_1,"READ");
	f_2 = new TFile(inp_file_2,"READ");
	f2  = new TFile(inp_file2,"READ");
	f2_5= new TFile(inp_file2_5,"READ");
	f3  = new TFile(inp_file3,"READ");
	
        TH1::SetDefaultSumw2(true);
	fetch_TTrees();
	Set_higgsPtProps();
	Set_jetPtProps();
	Draw_higgsPt();
	Draw_b_jetPt();
	fetch_histos();
	Draw_Nparticles();
	
	Draw_NleadingJetPt();
	Set_NleadingJetColors(); 

	//////////////////////////////////////////////////
	//////////////// writing to pdf //////////////////
	//////////////////////////////////////////////////
	char out_file_open[1023];
        sprintf(out_file_open,"%s/%s.pdf(",out_path,output_file_name);
        char out_file_[1023];
        sprintf(out_file_,"%s/%s.pdf",out_path,output_file_name);
        char out_file_close[1023];
        sprintf(out_file_close,"%s/%s.pdf)",out_path,output_file_name);

	Double_t x1 = 0.71, y1 = 0.71, x2 = 0.89, y2 = 0.89;

	leg_higgs = new TLegend(x1, y1, x2, y2, "");
	leg1 = new TLegend(x1, y1, x2, y2, "");
	leg2 = new TLegend(x1, y1, x2, y2, "");
	leg3 = new TLegend(x1, y1, x2, y2, "");
	leg4 = new TLegend(x1, y1, x2, y2, "");

	Set_LegendProps();

	TCanvas * C = new TCanvas();
	//TCanvas * C = new TCanvas("C","C",800,800);
	gStyle->SetOptStat(0);
	//TGaxis::SetMaxDigits(2);
	C->SetGridx();
	C->SetGridy();
	C->SetTickx();
	C->SetTicky();
	//C->SetLogy();

	higgsPt1->Draw("hist");	
	higgsPt0->Draw("hist same");	
	higgsPt_1->Draw("hist same");	
	higgsPt_2->Draw("hist same");	
	higgsPt2->Draw("hist same");	
	higgsPt2_5->Draw("hist same");
	higgsPt3->Draw("hist same");
	leg_higgs->AddEntry(higgsPt_2, "k_{#lambda} = -2.0");
	leg_higgs->AddEntry(higgsPt_1, "k_{#lambda} = -1.0");
	leg_higgs->AddEntry(higgsPt0,  "k_{#lambda} =  0.0");
	leg_higgs->AddEntry(higgsPt1,  "k_{#lambda} =  1.0");
	leg_higgs->AddEntry(higgsPt2,  "k_{#lambda} =  2.0");
	leg_higgs->AddEntry(higgsPt2_5,"k_{#lambda} =  2.5");
	leg_higgs->AddEntry(higgsPt3,  "k_{#lambda} =  3.0");
	leg_higgs->Draw();
	C->Update();
	C->Print(out_file_open,"pdf");

	higgsNLPt1->Draw("hist");	
	higgsNLPt0->Draw("hist same");	
	higgsNLPt_1->Draw("hist same");	
	higgsNLPt_2->Draw("hist same");	
	higgsNLPt2->Draw("hist same");	
	higgsNLPt2_5->Draw("hist same");
	higgsNLPt3->Draw("hist same");
	leg_higgs->Draw();
	C->Update();
	C->Print(out_file_,"pdf");
	
	C->SetLogy(0);
	NSMhiggs1->Draw("hist");
	NSMhiggs0->Draw("hist same");
	NSMhiggs_1->Draw("hist same");
	NSMhiggs_2->Draw("hist same");
	NSMhiggs2->Draw("hist same");
	NSMhiggs2_5->Draw("hist same");
	NSMhiggs3->Draw("hist same");
	leg_higgs->Draw();
	C->Print(out_file_,"pdf");

	Nbquarks1->Draw("hist");
	Nbquarks0->Draw("hist same");
	Nbquarks_1->Draw("hist same");
	Nbquarks_2->Draw("hist same");
	Nbquarks2->Draw("hist same");
	Nbquarks2_5->Draw("hist same");
	Nbquarks3->Draw("hist same");
	leg_higgs->Draw();
	C->Update();
	C->Print(out_file_,"pdf");

	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	b4LPt1->SetTitle("k_{#lambda} = 1.0");
	b4LPt1->Draw("hist");
	b3LPt1->Draw("hist same");
	b2LPt1->Draw("hist same");
	bLPt1->Draw("hist same");
	leg1->AddEntry(bLPt1, "leading");
	leg1->AddEntry(b2LPt1, "sub-leading");
	leg1->AddEntry(b3LPt1, "3^{rd} leading");
	leg1->AddEntry(b4LPt1, "4^{th} leading");
	leg1->Draw();

	C->cd(2);	
	b4LPt0->SetTitle("k_{#lambda} = 0.0");
	b4LPt0->Draw("hist");
	b3LPt0->Draw("hist same");
	b2LPt0->Draw("hist same");
	bLPt0->Draw("hist same");
	leg1->Draw();

	C->cd(3);	
	b4LPt_1->SetTitle("k_{#lambda} = -1.0");
	b4LPt_1->Draw("hist");
	b3LPt_1->Draw("hist same");
	b2LPt_1->Draw("hist same");
	bLPt_1->Draw("hist same");
	leg1->Draw();

	C->cd(4);	
	b4LPt_2->SetTitle("k_{#lambda} = -2.0");
	b4LPt_2->Draw("hist");
	b3LPt_2->Draw("hist same");
	b2LPt_2->Draw("hist same");
	bLPt_2->Draw("hist same");
	leg1->Draw();
	C->Print(out_file_,"pdf");
	
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	b4LPt1->SetTitle("k_{#lambda} = 1.0");
	b4LPt1->Draw("hist");
	b3LPt1->Draw("hist same");
	b2LPt1->Draw("hist same");
	bLPt1->Draw("hist same");
	leg1->Draw();
	
	C->cd(2);
	b4LPt2->SetTitle("k_{#lambda} = 2.0");
	b4LPt2->Draw("hist");
	b3LPt2->Draw("hist same");
	b2LPt2->Draw("hist same");
	bLPt2->Draw("hist same");
	leg1->Draw();
	
	C->cd(3);
	b4LPt2_5->SetTitle("k_{#lambda} = 2.5");
	b4LPt2_5->Draw("hist");
	b3LPt2_5->Draw("hist same");
	b2LPt2_5->Draw("hist same");
	bLPt2_5->Draw("hist same");
	leg1->Draw();
	
	C->cd(4);
	b4LPt3->SetTitle("k_{#lambda} = 3.0");
	b4LPt3->Draw("hist");
	b3LPt3->Draw("hist same");
	b2LPt3->Draw("hist same");
	bLPt3->Draw("hist same");
	leg1->Draw();
	C->Print(out_file_,"pdf");
	
	//! 4 leading b-Jets
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	bjet4LPt1->SetTitle("k_{#lambda} = 1.0");
	bjet4LPt1->GetXaxis()->SetTitle("p_{t,b-jet} [GeV/c]");
	bjet4LPt1->Draw("hist");
	bjet3LPt1->Draw("hist same");
	bjet2LPt1->Draw("hist same");
	bjetLPt1->Draw("hist same");
	leg1->Draw();

	C->cd(2);	
	bjet4LPt0->SetTitle("k_{#lambda} = 0.0");
	bjet4LPt0->GetXaxis()->SetTitle("p_{t,b-jet} [GeV/c]");
	bjet4LPt0->Draw("hist");
	bjet3LPt0->Draw("hist same");
	bjet2LPt0->Draw("hist same");
	bjetLPt0->Draw("hist same");
	leg1->Draw();

	C->cd(3);	
	bjet4LPt_1->SetTitle("k_{#lambda} = -1.0");
	bjet4LPt_1->GetXaxis()->SetTitle("p_{t,b-jet} [GeV/c]");
	bjet4LPt_1->Draw("hist");
	bjet3LPt_1->Draw("hist same");
	bjet2LPt_1->Draw("hist same");
	bjetLPt_1->Draw("hist same");
	leg1->Draw();

	C->cd(4);	
	bjet4LPt_2->SetTitle("k_{#lambda} = -2.0");
	bjet4LPt_2->GetXaxis()->SetTitle("p_{t,b-jet} [GeV/c]");
	bjet4LPt_2->Draw("hist");
	bjet3LPt_2->Draw("hist same");
	bjet2LPt_2->Draw("hist same");
	bjetLPt_2->Draw("hist same");
	leg1->Draw();
	C->Print(out_file_,"pdf");
	
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	bjet4LPt1->SetTitle("k_{#lambda} = 1.0");
	bjet4LPt1->GetXaxis()->SetTitle("p_{t,b-jet} [GeV/c]");
	bjet4LPt1->Draw("hist same");
	bjet3LPt1->Draw("hist same");
	bjet2LPt1->Draw("hist same");
	bjetLPt1->Draw("hist same");
	leg1->Draw();
	
	C->cd(2);
	bjet4LPt2->SetTitle("k_{#lambda} = 2.0");
	bjet4LPt2->GetXaxis()->SetTitle("p_{t,b-jet} [GeV/c]");
	bjet4LPt2->Draw("hist");
	bjet3LPt2->Draw("hist same");
	bjet2LPt2->Draw("hist same");
	bjetLPt2->Draw("hist same");
	leg1->Draw();
	
	C->cd(3);
	bjet4LPt2_5->SetTitle("k_{#lambda} = 2.5");
	bjet4LPt2_5->GetXaxis()->SetTitle("p_{t,b-jet} [GeV/c]");
	bjet4LPt2_5->Draw("hist");
	bjet3LPt2_5->Draw("hist same");
	bjet2LPt2_5->Draw("hist same");
	bjetLPt2_5->Draw("hist same");
	leg1->Draw();
	
	C->cd(4);
	bjet4LPt3->SetTitle("k_{#lambda} = 3.0");
	bjet4LPt3->GetXaxis()->SetTitle("p_{t,b-jet} [GeV/c]");
	bjet4LPt3->Draw("hist");
	bjet3LPt3->Draw("hist same");
	bjet2LPt3->Draw("hist same");
	bjetLPt3->Draw("hist same");
	leg1->Draw();
	C->Print(out_file_,"pdf");
	
	//! 5 leading Jets
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	jet4LPt1->SetTitle("k_{#lambda} = 1.0");
	jet4LPt1->GetXaxis()->SetTitle("p_{t,jet} [GeV/c]");
	//jet5LPt1->Draw("hist");
	jet4LPt1->Draw("hist");
	jet3LPt1->Draw("hist same");
	jet2LPt1->Draw("hist same");
	jetLPt1->Draw("hist same");
	leg2->AddEntry(jetLPt1, "leading");
	leg2->AddEntry(jet2LPt1, "sub-leading");
	leg2->AddEntry(jet3LPt1, "3^{rd} leading");
	leg2->AddEntry(jet4LPt1, "4^{th} leading");
	//leg2->AddEntry(jet5LPt1, "5^{th} leading");
	leg2->Draw();

	C->cd(2);	
	jet4LPt0->SetTitle("k_{#lambda} = 0.0");
	jet4LPt0->GetXaxis()->SetTitle("p_{t,jet} [GeV/c]");
	//jet5LPt0->Draw("hist");
	jet4LPt0->Draw("hist");
	jet3LPt0->Draw("hist same");
	jet2LPt0->Draw("hist same");
	jetLPt0->Draw("hist same");
	leg2->Draw();

	C->cd(3);	
	jet4LPt_1->SetTitle("k_{#lambda} = -1.0");
	jet4LPt_1->GetXaxis()->SetTitle("p_{t,jet} [GeV/c]");
	//jet5LPt_1->Draw("hist");
	jet4LPt_1->Draw("hist");
	jet3LPt_1->Draw("hist same");
	jet2LPt_1->Draw("hist same");
	jetLPt_1->Draw("hist same");
	leg2->Draw();

	C->cd(4);	
	jet4LPt_2->SetTitle("k_{#lambda} = -2.0");
	jet4LPt_2->GetXaxis()->SetTitle("p_{t,jet} [GeV/c]");
	//jet5LPt_2->Draw("hist");
	jet4LPt_2->Draw("hist");
	jet3LPt_2->Draw("hist same");
	jet2LPt_2->Draw("hist same");
	jetLPt_2->Draw("hist same");
	leg2->Draw();
	C->Print(out_file_,"pdf");
	
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	jet4LPt1->SetTitle("k_{#lambda} = 1.0");
	jet4LPt1->GetXaxis()->SetTitle("p_{t,jet} [GeV/c]");
	//jet5LPt1->Draw("hist");
	jet4LPt1->Draw("hist same");
	jet3LPt1->Draw("hist same");
	jet2LPt1->Draw("hist same");
	jetLPt1->Draw("hist same");
	leg2->Draw();
	
	C->cd(2);
	jet4LPt2->SetTitle("k_{#lambda} = 2.0");
	jet4LPt2->GetXaxis()->SetTitle("p_{t,jet} [GeV/c]");
	//jet5LPt2->Draw("hist");
	jet4LPt2->Draw("hist");
	jet3LPt2->Draw("hist same");
	jet2LPt2->Draw("hist same");
	jetLPt2->Draw("hist same");
	leg2->Draw();
	
	C->cd(3);
	jet4LPt2_5->SetTitle("k_{#lambda} = 2.5");
	jet4LPt2_5->GetXaxis()->SetTitle("p_{t,jet} [GeV/c]");
	//jet5LPt2_5->Draw("hist");
	jet4LPt2_5->Draw("hist");
	jet3LPt2_5->Draw("hist same");
	jet2LPt2_5->Draw("hist same");
	jetLPt2_5->Draw("hist same");
	leg2->Draw();
	
	C->cd(4);
	jet4LPt3->SetTitle("k_{#lambda} = 3.0");
	jet4LPt3->GetXaxis()->SetTitle("p_{t,jet} [GeV/c]");
	//jet5LPt3->Draw("hist");
	jet4LPt3->Draw("hist");
	jet3LPt3->Draw("hist same");
	jet2LPt3->Draw("hist same");
	jetLPt3->Draw("hist same");
	leg2->Draw();
	C->Print(out_file_,"pdf");


	//! bquark leading for various lambda, 
	//! bquark sub leading for various lambda, 
	//! bquark 3rd leading for various lambda, 
	//! bquark 4th leading for various lambda,
	Set_bquark_lambdaColors(); 
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	bLPt3->Draw("hist ");
	bLPt1->Draw("hist same");
	bLPt2->Draw("hist same");
	bLPt2_5->Draw("hist same");
	bLPt_2->Draw("hist same");
	bLPt_1->Draw("hist same");
	bLPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(2);
	b2LPt3->Draw("hist");
	b2LPt1->Draw("hist same");
	b2LPt2->Draw("hist same");
	b2LPt2_5->Draw("hist same");
	b2LPt_2->Draw("hist same");
	b2LPt_1->Draw("hist same");
	b2LPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(3);
	b3LPt_2->GetXaxis()->SetRangeUser(0,250);
	b3LPt_2->Draw("hist");
	b3LPt3->Draw("hist same");
	b3LPt1->Draw("hist same");
	b3LPt2->Draw("hist same");
	b3LPt2_5->Draw("hist same");
	b3LPt_1->Draw("hist same");
	b3LPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(4);
	b4LPt_2->SetTitle("P_{t} of 4th leading b quark");
	b4LPt_2->GetXaxis()->SetRangeUser(0,150);
	
	b4LPt_2->Draw("hist");
	b4LPt1->Draw("hist same");
	b4LPt2->Draw("hist same");
	b4LPt2_5->Draw("hist same");
	b4LPt3->Draw("hist same");
	b4LPt_1->Draw("hist same");
	b4LPt0->Draw("hist same");
	leg_higgs->Draw();
	C->Print(out_file_,"pdf");

	//! b-jet leading for various lambda, 
	//! b-jet sub leading for various lambda, 
	//! b-jet 3rd leading for various lambda, 
	//! b-jet 4th leading for various lambda,
	//Set_bquark_lambdaColors(); 
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	bjetLPt_2->Draw("hist");
	bjetLPt2->Draw("hist same");
	bjetLPt2_5->Draw("hist same");
	bjetLPt3->Draw("hist same");
	bjetLPt_1->Draw("hist same");
	bjetLPt1->Draw("hist same");
	bjetLPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(2);
	bjet2LPt_2->Draw("hist");
	bjet2LPt2->Draw("hist same");
	bjet2LPt2_5->Draw("hist same");
	bjet2LPt3->Draw("hist same");
	bjet2LPt_1->Draw("hist same");
	bjet2LPt1->Draw("hist same");
	bjet2LPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(3);
	bjet3LPt_2->GetXaxis()->SetRangeUser(0,250);
	bjet3LPt_2->Draw("hist");
	bjet3LPt3->Draw("hist same");
	bjet3LPt2->Draw("hist same");
	bjet3LPt2_5->Draw("hist same");
	bjet3LPt_1->Draw("hist same");
	bjet3LPt1->Draw("hist same");
	bjet3LPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(4);
	bjet4LPt_2->GetXaxis()->SetRangeUser(0,150);
	
	bjet4LPt_2->Draw("hist same");
	bjet4LPt2->Draw("hist same");
	bjet4LPt2_5->Draw("hist same");
	bjet4LPt3->Draw("hist same");
	bjet4LPt_1->Draw("hist same");
	bjet4LPt1->Draw("hist same");
	bjet4LPt0->Draw("hist same");
	leg_higgs->Draw();
	C->Print(out_file_,"pdf");
	//! jet leading for various lambda, 
	//! jet sub leading for various lambda, 
	//! jet 3rd leading for various lambda, 
	//! jet 4th leading for various lambda,
	//Set_bquark_lambdaColors(); 
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	jetLPt_2->Draw("hist");
	jetLPt2->Draw("hist same");
	jetLPt2_5->Draw("hist same");
	jetLPt3->Draw("hist same");
	jetLPt_1->Draw("hist same");
	jetLPt1->Draw("hist same");
	jetLPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(2);
	jet2LPt_2->Draw("hist");
	jet2LPt2->Draw("hist same");
	jet2LPt2_5->Draw("hist same");
	jet2LPt3->Draw("hist same");
	jet2LPt_1->Draw("hist same");
	jet2LPt1->Draw("hist same");
	jet2LPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(3);
	jet3LPt_2->GetXaxis()->SetRangeUser(0,250);
	jet3LPt_2->Draw("hist");
	jet3LPt3->Draw("hist same");
	jet3LPt2->Draw("hist same");
	jet3LPt2_5->Draw("hist same");
	jet3LPt_1->Draw("hist same");
	jet3LPt1->Draw("hist same");
	jet3LPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(4);
	jet4LPt_2->GetXaxis()->SetRangeUser(0,150);
	
	jet4LPt_2->Draw("hist same");
	jet4LPt2->Draw("hist same");
	jet4LPt2_5->Draw("hist same");
	jet4LPt3->Draw("hist same");
	jet4LPt_1->Draw("hist same");
	jet4LPt1->Draw("hist same");
	jet4LPt0->Draw("hist same");
	leg_higgs->Draw();
	C->Print(out_file_,"pdf");
	//! bquark central for various lambda, 
	//! bquark sub Central for various lambda, 
	//! bquark 3rd Central for various lambda, 
	//! bquark 4th Central for various lambda,
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	bCEta3->Draw("hist ");
	bCEta1->Draw("hist same");
	bCEta2->Draw("hist same");
	bCEta2_5->Draw("hist same");
	bCEta_2->Draw("hist same");
	bCEta_1->Draw("hist same");
	bCEta0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(2);
	b2CEta3->Draw("hist");
	b2CEta1->Draw("hist same");
	b2CEta2->Draw("hist same");
	b2CEta2_5->Draw("hist same");
	b2CEta_2->Draw("hist same");
	b2CEta_1->Draw("hist same");
	b2CEta0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(3);
	b3CEta_2->Draw("hist");
	b3CEta3->Draw("hist same");
	b3CEta1->Draw("hist same");
	b3CEta2->Draw("hist same");
	b3CEta2_5->Draw("hist same");
	b3CEta_1->Draw("hist same");
	b3CEta0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(4);
	b4CEta_2->Draw("hist");
	b4CEta1->Draw("hist same");
	b4CEta2->Draw("hist same");
	b4CEta2_5->Draw("hist same");
	b4CEta3->Draw("hist same");
	b4CEta_1->Draw("hist same");
	b4CEta0->Draw("hist same");
	leg_higgs->Draw();
	C->Print(out_file_close,"pdf");
	return 0;
}
