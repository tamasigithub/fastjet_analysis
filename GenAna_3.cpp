void ClearLorentzVectors_3()
{
	//! clear the Lorentz vectors
	higgs1_3 = TLorentzVector();
	higgs2_3 = TLorentzVector();
	H1H2_3 = TLorentzVector();

	b1_3 = TLorentzVector();
	b2_3 = TLorentzVector();
	b3_3 = TLorentzVector();
	b4_3 = TLorentzVector();

	b1b2_3 = TLorentzVector();
	b1b3_3 = TLorentzVector();
	b1b4_3 = TLorentzVector();
	b2b3_3 = TLorentzVector();
	b2b4_3 = TLorentzVector();
	b3b4_3 = TLorentzVector();
	
	bJ1_3 = TLorentzVector(); 
	bJ2_3 = TLorentzVector(); 
	bJ3_3 = TLorentzVector(); 
	bJ4_3 = TLorentzVector(); 
	bJ1bJ2_3 = TLorentzVector();
	bJ1bJ3_3 = TLorentzVector();
	bJ1bJ4_3 = TLorentzVector();
	bJ2bJ3_3 = TLorentzVector();
	bJ2bJ4_3 = TLorentzVector();
	bJ3bJ4_3 = TLorentzVector();

	RecH1H2_3 = TLorentzVector();
	return;

}
void fetch_histos_3()
{

	bLPt3  = (TH1D*)f3->Get("hbPt_Lpt");
	b2LPt3 = (TH1D*)f3->Get("hbPt_NLpt");
	b3LPt3 = (TH1D*)f3->Get("hbPt_NNLpt");
	b4LPt3 = (TH1D*)f3->Get("hbPt_NNNLpt");
	
	bCEta3  = (TH1D*)f3->Get("hbEta_Ceta");
	b2CEta3 = (TH1D*)f3->Get("hbEta_NCeta");
	b3CEta3 = (TH1D*)f3->Get("hbEta_NNCeta");
	b4CEta3 = (TH1D*)f3->Get("hbEta_NNNCeta");
	
	return;
}
void Draw_b_jetPt_3()
{

	t3->Draw("bJetLPt>>bjetLPt3");
	t3->Draw("bJetNLPt>>bjet2LPt3");
	t3->Draw("bJetNNLPt>>bjet3LPt3");
	t3->Draw("bJetNNNLPt>>bjet4LPt3");
	return;
}
void Draw_higgsPt_3()
{
	
	t3->Draw("higgsLPt*1e-3>>higgsPt3");
	t3->Draw("higgsNLPt*1e-3>>higgsNLPt3");
	
	return;
}
void Draw_Nparticles_3()
{
	int nbins = 6, nbins_1 = 20;
	double nmin = 0, nmax = 6, nmax_1 = 20;
	NSMhiggs3  = new TH1D("NSMhiggs3", "number of higgs", nbins, nmin, nmax);
	Nbquarks3  = new TH1D("Nbquarks3", "number of b quarks", nbins, nmin, nmax);
	Njets3  = new TH1D("Njets3", "number of jets", nbins_1, nmin, nmax_1);
	t3->Draw("NSMhiggs>>NSMhiggs3");
	t3->Draw("Nbquarks>>Nbquarks3");
	t3->Draw("Njets>>Njets3");
	NSMhiggs3->SetLineColor(kViolet);
	Nbquarks3->SetLineColor(kViolet);
	Njets3->SetLineColor(kViolet);
	return;
}
void fetch_TTrees_3()
{
	t3   = (TTree*)f3->Get("glob_jet");

	t3->SetBranchStatus("*",0);
	
	t3->SetBranchStatus("higgsLPt",1);
	t3->SetBranchStatus("higgsNLPt",1);
	t3->SetBranchStatus("NSMhiggs",1);
	t3->SetBranchStatus("Nbquarks",1);
	t3->SetBranchStatus("Njets",1);
	t3->SetBranchStatus("jetPt",1);
	t3->SetBranchStatus("jetEta",1);
	t3->SetBranchStatus("jetPhi",1);
	t3->SetBranchStatus("jetM",1);
	t3->SetBranchStatus("btaggedFlavor",1);
	t3->SetBranchStatus("bJetLPt",1);
	t3->SetBranchStatus("bJetNLPt",1);
	t3->SetBranchStatus("bJetNNLPt",1);
	t3->SetBranchStatus("bJetNNNLPt",1);
	t3->SetBranchStatus("Nbtags",1);
	t3->SetBranchStatus("v_higgsPt", 1);
	t3->SetBranchStatus("v_higgsEta",1);
	t3->SetBranchStatus("v_higgsPhi",1);
	t3->SetBranchStatus("v_higgsM",  1);
	t3->SetBranchStatus("v_bPt", 1);
	t3->SetBranchStatus("v_bEta",1);
	t3->SetBranchStatus("v_bPhi",1);
	t3->SetBranchStatus("v_bM",  1);
	
	t3->SetBranchAddress("jetPt",  &v3_jetPt);
	t3->SetBranchAddress("jetEta",  &v3_jetEta);
	t3->SetBranchAddress("jetPhi",  &v3_jetPhi);
	t3->SetBranchAddress("jetM",  &v3_jetM);
	t3->SetBranchAddress("btaggedFlavor",  &v3_tagFlavor);
	t3->SetBranchAddress("Nbtags",&n3_btags);
	t3->SetBranchAddress("v_higgsPt", &v3_higgsPt);
	t3->SetBranchAddress("v_higgsEta",&v3_higgsEta);
	t3->SetBranchAddress("v_higgsPhi",&v3_higgsPhi);
	t3->SetBranchAddress("v_higgsM",  &v3_higgsM);
	t3->SetBranchAddress("v_bPt", &v3_bPt);
	t3->SetBranchAddress("v_bEta",&v3_bEta);
	t3->SetBranchAddress("v_bPhi",&v3_bPhi);
	t3->SetBranchAddress("v_bM",  &v3_bM);

	return;
}
void Set_higgsPtProps_3()
{
	int nbins = 50;
	float ptmin = 0;
	float ptmax = 500;
	float Mmin = 200;
	float Mmax = 800;
	//! truth leading and sub leading higgs Pt
	higgsPt3  = new TH1D("higgsPt3",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt3->SetLineColor(kViolet);
	higgsPt3->SetLineWidth(LINE_WIDTH);
	
	higgsNLPt3  = new TH1D("higgsNLPt3",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsNLPt3->SetLineColor(kViolet);
	higgsNLPt3->SetLineWidth(LINE_WIDTH);
	//! truth leading and sub leading higgs inv mass
	higgsL_M3  = new TH1D("higgsL_M3",  "Invariant higgs mass;m_{rec, leading higgs} [GeV];", nbins, ptmin, ptmax);
	higgsL_M3->SetLineColor(kViolet);
	higgsL_M3->SetLineWidth(LINE_WIDTH);
	
	higgsNL_M3  = new TH1D("higgsNL_M3",  "Invariant higgs mass;m_{rec, sub leading higgs} [GeV];", nbins, ptmin, ptmax);
	higgsNL_M3->SetLineColor(kViolet);
	higgsNL_M3->SetLineWidth(LINE_WIDTH);
	//! truth Inv mass of the di-higgs system
	MH1H2_3  = new TH1D("MH1H2_3",  "Invariant di-higgs mass;m_{truth, h1,h2} [GeV];", nbins, Mmin, Mmax);
	MH1H2_3->SetLineColor(kViolet);
	MH1H2_3->SetLineWidth(LINE_WIDTH);
	//! truth Pt of the di-higgs system
	PtH1H2_3  = new TH1D("PtH1H2_3",  "Transverse momentum of the di-higgs system;p_{T, truth, h1,h2} [GeV/c];", nbins, ptmin, ptmax);
	PtH1H2_3->SetLineColor(kViolet);
	PtH1H2_3->SetLineWidth(LINE_WIDTH);

	
	//! reconstructed leading and sub leading higgs pt
	Pt_Lhiggs3  = new TH1D("Pt_Lhiggs3",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	Pt_NLhiggs3  = new TH1D("Pt_NLhiggs3",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	//! reconstructed leading and sub leading inv mass
	M_Lhiggs3  = new TH1D("M_Lhiggs3",  "Invariant higgs mass;m_{rec, leading higgs} [GeV];", nbins, ptmin, ptmax);
	M_NLhiggs3  = new TH1D("M_NLhiggs3",  "Invariant higgs mass;m_{rec, sub leading higgs} [GeV];", nbins, ptmin, ptmax);
	
	//! reconstructed Inv mass of the di-higgs system
	RecMH1H2_3  = new TH1D("RecMH1H2_3",  "Invariant di-higgs mass;m_{truth, h1,h2} [GeV];", nbins, Mmin, Mmax);
	//! reconstructed Pt of the di-higgs system
	RecPtH1H2_3  = new TH1D("RecPtH1H2_3",  "Transverse momentum of the di-higgs system;p_{T, truth, h1,h2} [GeV/c];", nbins, ptmin, ptmax);

	// invariant mass of a pair of b's, ctr = 3.0
	Mb1b2_3 = new TH1D("Mb1b2_3", "#lambda = 3.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 12} [GeV];", nbins, ptmin, ptmax);
	Mb1b3_3 = new TH1D("Mb1b3_3", "#lambda = 3.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 13} [GeV];", nbins, ptmin, ptmax);
	Mb1b4_3 = new TH1D("Mb1b4_3", "#lambda = 3.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 14} [GeV];", nbins, ptmin, ptmax);
	Mb2b3_3 = new TH1D("Mb2b3_3", "#lambda = 3.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 23} [GeV];", nbins, ptmin, ptmax);
	Mb2b4_3 = new TH1D("Mb2b4_3", "#lambda = 3.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 24} [GeV];", nbins, ptmin, ptmax);
	Mb3b4_3 = new TH1D("Mb3b4_3", "#lambda = 3.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 34} [GeV];", nbins, ptmin, ptmax);
	return;
}

void Set_FinalJetPtProps_3()
{
	int nbins = 15; 
	Int_t nbinsMinus = nbins - 1; 
	Float_t pt_bins[15] = {20., 30., 40., 50., 60., 70., 80., 90., 100., 110., 120., 130., 140., 150., 500.};
	//b-jet leading Pt
	Ana_bjetLPt3  = new TH1D("Ana_bjetLPt3", "Jet p_{T} after analysis cuts; p_{T, leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	//b-jet 2nd leading Pt
	Ana_bjet2LPt3  = new TH1D("Ana_bjet2LPt3", "Jet p_{T} after analysis cuts; p_{T, sub leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	//b-jet 3rd leading Pt
	Ana_bjet3LPt3  = new TH1D("Ana_bjet3LPt3", "Jet p_{T} after analysis cuts; p_{T, 3rd leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	//b-jet 4th leading Pt
	Ana_bjet4LPt3  = new TH1D("Ana_bjet4LPt3", "Jet p_{T} after analysis cuts; p_{T, 4th leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	return;
}

void Set_jetPtProps_3()
{
	int nbins = 50;
	float ptmin = 0;
	float ptmax = 300;
	float dptmin = 0;
	float dptmax = 300;
	//b-jet leading Pt
	bjetLPt3  = new TH1D("bjetLPt3", "b-tagged Jet p_{t}; p_{t, leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 2nd leading Pt
	bjet2LPt3  = new TH1D("bjet2LPt3", "b-tagged Jet p_{t}; p_{t, sub leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 3rd leading Pt
	bjet3LPt3  = new TH1D("bjet3LPt3", "b-tagged Jet p_{t}; p_{t, 3rd leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 4th leading Pt
	bjet4LPt3  = new TH1D("bjet4LPt3", "b-tagged Jet p_{t}; p_{t, 4th leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	
	//jet leading Pt
	jetLPt3  = new TH1D("jetLPt3", "Jet p_{t}; p_{t, leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 2nd leading Pt
	jet2LPt3  = new TH1D("jet2LPt3", "Jet p_{t}; p_{t, sub leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 3rd leading Pt
	jet3LPt3  = new TH1D("jet3LPt3", "Jet p_{t}; p_{t, 3rd leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 4th leading Pt
	jet4LPt3  = new TH1D("jet4LPt3", "Jet p_{t}; p_{t, 4th leading jet} [GeV/c];", nbins, ptmin, ptmax);

	//jet leading M
	jetLM3  = new TH1D("jetLM3", "Jet invariant mass; m_{ leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 2nd leading M
	jet2LM3  = new TH1D("jet2LM3", "Jet invariant mass; m_{ sub leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 3rd leading M
	jet3LM3  = new TH1D("jet3LM3", "Jet invariant mass; m_{ 3rd leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 4th leading M
	jet4LM3  = new TH1D("jet4LM3", "Jet invariant mass; m_{ 4th leading jet} [GeV];", nbins, ptmin, ptmax);
	
	//bjet leading M
	bjetLM3  = new TH1D("bjetLM3", "Jet invariant mass; m_{ leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 2nd leading M
	bjet2LM3  = new TH1D("bjet2LM3", "Jet invariant mass; m_{ sub leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 3rd leading M
	bjet3LM3  = new TH1D("bjet3LM3", "Jet invariant mass; m_{ 3rd leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 4th leading M
	bjet4LM3  = new TH1D("bjet4LM3", "Jet invariant mass; m_{ 4th leading bjet} [GeV];", nbins, ptmin, ptmax);
	
	// invariant mass of a pair of b's, ctr = 1.0
	M_b1b2_3 = new TH1D("M_b1b2_3", "Invariant mass of the higgs candidates; m_{higgs candidate, 12} [GeV];", nbins, ptmin, ptmax);
	M_b1b3_3 = new TH1D("M_b1b3_3", "Invariant mass of the higgs candidates; m_{higgs candidate, 13} [GeV];", nbins, ptmin, ptmax);
	M_b1b4_3 = new TH1D("M_b1b4_3", "Invariant mass of the higgs candidates; m_{higgs candidate, 14} [GeV];", nbins, ptmin, ptmax);
	M_b2b3_3 = new TH1D("M_b2b3_3", "Invariant mass of the higgs candidates; m_{higgs candidate, 23} [GeV];", nbins, ptmin, ptmax);
	M_b2b4_3 = new TH1D("M_b2b4_3", "Invariant mass of the higgs candidates; m_{higgs candidate, 24} [GeV];", nbins, ptmin, ptmax);
	M_b3b4_3 = new TH1D("M_b3b4_3", "Invariant mass of the higgs candidates; m_{higgs candidate, 34} [GeV];", nbins, ptmin, ptmax);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_3 = new TH1D("dM_b1b2_b3b4_3", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1234} [GeV];", nbins, dptmin, dptmax);
	dM_b1b3_b2b4_3 = new TH1D("dM_b1b3_b2b4_3", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1324} [GeV];", nbins, dptmin, dptmax);
	dM_b1b4_b2b3_3 = new TH1D("dM_b1b4_b2b3_3", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1423} [GeV];", nbins, dptmin, dptmax);

	combi_selected_3 = new TH1D("combi_selected_3", "Selected combination", 3, 1, 4);
	return;
}
	
void Draw_InvariantMass_3()
{
	//! higgs's
	if(v3_higgsPt->size() == 2)
	{
		higgs1_3.SetPtEtaPhiM((*v3_higgsPt)[0], (*v3_higgsEta)[0], (*v3_higgsPhi)[0], (*v3_higgsM)[0]);
		higgs2_3.SetPtEtaPhiM((*v3_higgsPt)[1], (*v3_higgsEta)[1], (*v3_higgsPhi)[1], (*v3_higgsM)[1]);
		H1H2_3 = higgs1_3 + higgs2_3;
		
		MH1H2_3->Fill(H1H2_3.M()*1e-3);
		PtH1H2_3->Fill(H1H2_3.Pt()*1e-3);
	}
	//! b's
	if(v3_bPt->size() == 4)
	{
		b1_3.SetPtEtaPhiM((*v3_bPt)[0], (*v3_bEta)[0], (*v3_bPhi)[0], (*v3_bM)[0]);
		b2_3.SetPtEtaPhiM((*v3_bPt)[1], (*v3_bEta)[1], (*v3_bPhi)[1], (*v3_bM)[1]);
		b3_3.SetPtEtaPhiM((*v3_bPt)[2], (*v3_bEta)[2], (*v3_bPhi)[2], (*v3_bM)[2]);
		b4_3.SetPtEtaPhiM((*v3_bPt)[3], (*v3_bEta)[3], (*v3_bPhi)[3], (*v3_bM)[3]);

		b1b2_3 = b1_3 + b2_3;
		b1b3_3 = b1_3 + b3_3;
		b1b4_3 = b1_3 + b4_3;
		b2b3_3 = b2_3 + b3_3;
		b2b4_3 = b2_3 + b4_3;
		b3b4_3 = b3_3 + b4_3;
		
		Mb1b2_3->Fill(b1b2_3.M()*1e-3);
		Mb1b3_3->Fill(b1b3_3.M()*1e-3);
		Mb1b4_3->Fill(b1b4_3.M()*1e-3);
		Mb2b3_3->Fill(b2b3_3.M()*1e-3);
		Mb2b4_3->Fill(b2b4_3.M()*1e-3);
		Mb3b4_3->Fill(b3b4_3.M()*1e-3);
	}

	return;
}
//void Fill_InvariantMass_3()
//{
//	Mb1b2_3->Fill(b1b2_3.M()*1e-3);
//	Mb1b3_3->Fill(b1b3_3.M()*1e-3);
//	Mb1b4_3->Fill(b1b4_3.M()*1e-3);
//	Mb2b3_3->Fill(b2b3_3.M()*1e-3);
//	Mb2b4_3->Fill(b2b4_3.M()*1e-3);
//	Mb3b4_3->Fill(b3b4_3.M()*1e-3);
//
//	MH1H2_3->Fill(H1H2_3.M()*1e-3);
//	PtH1H2_3->Fill(H1H2_3.Pt()*1e-3);
//	return;
//}
void Fill_NLeadingJetPtM_3()
{
	jetLPt3->Fill((*v3_jetPt)[0]*1e-3);
	jet2LPt3->Fill((*v3_jetPt)[1]*1e-3);
	jet3LPt3->Fill((*v3_jetPt)[2]*1e-3);
	jet4LPt3->Fill((*v3_jetPt)[3]*1e-3);
	
	jetLM3->Fill( (*v3_jetM)[0]*1e-3);
	jet2LM3->Fill((*v3_jetM)[1]*1e-3);
	jet3LM3->Fill((*v3_jetM)[2]*1e-3);
	jet4LM3->Fill((*v3_jetM)[3]*1e-3);

	return;
}
void Fill_bjetPtM_3(int &nhiggs)
{
	bjetLPt3->Fill( bJ1_3.Pt()*1e-3);
	bjet2LPt3->Fill(bJ2_3.Pt()*1e-3);
	bjet3LPt3->Fill(bJ3_3.Pt()*1e-3);
	bjet4LPt3->Fill(bJ4_3.Pt()*1e-3);

	bjetLM3->Fill( bJ1_3.M()*1e-3);
	bjet2LM3->Fill(bJ2_3.M()*1e-3);
	bjet3LM3->Fill(bJ3_3.M()*1e-3);
	bjet4LM3->Fill(bJ4_3.M()*1e-3);
	
	M_b1b2_3->Fill(bJ1bJ2_3.M()*1e-3);
	M_b1b3_3->Fill(bJ1bJ3_3.M()*1e-3);
	M_b1b4_3->Fill(bJ1bJ4_3.M()*1e-3);
	M_b2b3_3->Fill(bJ2bJ3_3.M()*1e-3);
	M_b2b4_3->Fill(bJ2bJ4_3.M()*1e-3);
	M_b3b4_3->Fill(bJ3bJ4_3.M()*1e-3);

	double dm_12_34 = 0, dm_13_24 = 0, dm_14_23 = 0;
	dm_12_34 = std::fabs(bJ1bJ2_3.M() - bJ3bJ4_3.M())*1e-3;
	dm_13_24 = std::fabs(bJ1bJ3_3.M() - bJ2bJ4_3.M())*1e-3;
	dm_14_23 = std::fabs(bJ1bJ4_3.M() - bJ2bJ3_3.M())*1e-3;
	//dM_b1b2_b3b4_3->Fill(dm_12_34*1e-3);	
	//dM_b1b3_b2b4_3->Fill(dm_13_24*1e-3);	
	//dM_b1b4_b2b3_3->Fill(dm_14_23*1e-3);

	//! Higgs Candidate
	int higgs_candidates = -1;
	int min_diffCombi = 999;

	if((std::fabs(bJ1bJ2_3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ3bJ4_3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
	if(dm_12_34 < min_diffCombi) 
	{
		min_diffCombi = dm_12_34;
		higgs_candidates = 1234;
	}
	}
	if((std::fabs(bJ1bJ3_3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ4_3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
	if(dm_13_24 < min_diffCombi) 
	{
		min_diffCombi = dm_13_24;
		higgs_candidates = 1324;
	}
	}

	if((std::fabs(bJ1bJ4_3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ3_3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
	if(dm_14_23 < min_diffCombi)
	{
		min_diffCombi = dm_14_23;
		higgs_candidates = 1423;
	}
	}

	if(higgs_candidates == 1234)
	{
		//if((std::fabs(bJ1bJ2_3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ3bJ4_3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		//{
			combi_selected_3->Fill(1);
			nhiggs++;
			//! Fill four jet pt after all selection
			Ana_bjetLPt3->Fill( bJ1_3.Pt()*1e-3);
			Ana_bjet2LPt3->Fill(bJ2_3.Pt()*1e-3);
			Ana_bjet3LPt3->Fill(bJ3_3.Pt()*1e-3);
			Ana_bjet4LPt3->Fill(bJ4_3.Pt()*1e-3);
			if(bJ1bJ2_3.M() > bJ3bJ4_3.M())
			{
				M_Lhiggs3->Fill(bJ1bJ2_3.M()*1e-3);
				M_NLhiggs3->Fill(bJ3bJ4_3.M()*1e-3);
				Pt_Lhiggs3->Fill(bJ1bJ2_3.Pt()*1e-3);
				Pt_NLhiggs3->Fill(bJ3bJ4_3.Pt()*1e-3);
			
			} 
			else
			{
				M_Lhiggs3->Fill(bJ3bJ4_3.M()*1e-3);
				M_NLhiggs3->Fill(bJ1bJ2_3.M()*1e-3);
				Pt_Lhiggs3->Fill(bJ3bJ4_3.Pt()*1e-3);
				Pt_NLhiggs3->Fill(bJ1bJ2_3.Pt()*1e-3);
				
			}
			RecH1H2_3 = bJ1bJ2_3 + bJ3bJ4_3;
			RecMH1H2_3->Fill(RecH1H2_3.M()*1e-3);
			RecPtH1H2_3->Fill(RecH1H2_3.Pt()*1e-3);
			
			dM_b1b2_b3b4_3->Fill(dm_12_34);	
		//}
	}
	else if(higgs_candidates == 1324)
	{
		//if((std::fabs(bJ1bJ3_3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ4_3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		//{
			combi_selected_3->Fill(2);
			nhiggs++;
			//! Fill four jet pt after all selection
			Ana_bjetLPt3->Fill( bJ1_3.Pt()*1e-3);
			Ana_bjet2LPt3->Fill(bJ2_3.Pt()*1e-3);
			Ana_bjet3LPt3->Fill(bJ3_3.Pt()*1e-3);
			Ana_bjet4LPt3->Fill(bJ4_3.Pt()*1e-3);
			if(bJ1bJ3_3.M() > bJ2bJ4_3.M())
			{
				M_Lhiggs3->Fill(bJ1bJ3_3.M()*1e-3);
				M_NLhiggs3->Fill(bJ2bJ4_3.M()*1e-3);
				Pt_Lhiggs3->Fill(bJ1bJ3_3.Pt()*1e-3);
				Pt_NLhiggs3->Fill(bJ2bJ4_3.Pt()*1e-3);
			
			} 
			else
			{
				M_Lhiggs3->Fill(bJ2bJ4_3.M()*1e-3);
				M_NLhiggs3->Fill(bJ1bJ3_3.M()*1e-3);
				Pt_Lhiggs3->Fill(bJ2bJ4_3.Pt()*1e-3);
				Pt_NLhiggs3->Fill(bJ1bJ3_3.Pt()*1e-3);
				
			}
			RecH1H2_3 = bJ1bJ3_3 + bJ2bJ4_3;
			RecMH1H2_3->Fill(RecH1H2_3.M()*1e-3);
			RecPtH1H2_3->Fill(RecH1H2_3.Pt()*1e-3);
			
			dM_b1b3_b2b4_3->Fill(dm_13_24);	
		//}
	
	}
	else if(higgs_candidates == 1423)
	{
		//if((std::fabs(bJ1bJ4_3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ3_3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		//{
			combi_selected_3->Fill(3);
			nhiggs++;
			//! Fill four jet pt after all selection
			Ana_bjetLPt3->Fill( bJ1_3.Pt()*1e-3);
			Ana_bjet2LPt3->Fill(bJ2_3.Pt()*1e-3);
			Ana_bjet3LPt3->Fill(bJ3_3.Pt()*1e-3);
			Ana_bjet4LPt3->Fill(bJ4_3.Pt()*1e-3);
			if(bJ1bJ4_3.M() > bJ2bJ3_3.M())
			{
				M_Lhiggs3->Fill(bJ1bJ4_3.M()*1e-3);
				M_NLhiggs3->Fill(bJ2bJ3_3.M()*1e-3);
				Pt_Lhiggs3->Fill(bJ1bJ4_3.Pt()*1e-3);
				Pt_NLhiggs3->Fill(bJ2bJ3_3.Pt()*1e-3);
			
			} 
			else
			{
				M_Lhiggs3->Fill(bJ2bJ3_3.M()*1e-3);
				M_NLhiggs3->Fill(bJ1bJ4_3.M()*1e-3);
				Pt_Lhiggs3->Fill(bJ2bJ3_3.Pt()*1e-3);
				Pt_NLhiggs3->Fill(bJ1bJ4_3.Pt()*1e-3);
				
			}
			RecH1H2_3 = bJ1bJ4_3 + bJ2bJ3_3;
			RecMH1H2_3->Fill(RecH1H2_3.M()*1e-3);
			RecPtH1H2_3->Fill(RecH1H2_3.Pt()*1e-3);
			
			dM_b1b4_b2b3_3->Fill(dm_14_23);
		//}
	
	}

	return;
}
void Draw_DiJetInvariantMass_3(int &nhiggs)
{
	v3_bjetPt.clear();
	v3_bjetEta.clear();
	v3_bjetPhi.clear();
	v3_bjetM.clear();
	for(int j = 0; j < v3_tagFlavor->size(); j++)
	{
		if((*v3_tagFlavor)[j] != 5) continue;
		v3_bjetPt.push_back((*v3_jetPt)[j]);
		v3_bjetEta.push_back((*v3_jetEta)[j]);
		v3_bjetPhi.push_back((*v3_jetPhi)[j]);
		v3_bjetM.push_back((*v3_jetM)[j]);

	}
	
	//! b jet's
	if(v3_bjetPt.size() > 3)
	{
		bJ1_3.SetPtEtaPhiM(v3_bjetPt[0], v3_bjetEta[0], v3_bjetPhi[0], v3_bjetM[0]);
		bJ2_3.SetPtEtaPhiM(v3_bjetPt[1], v3_bjetEta[1], v3_bjetPhi[1], v3_bjetM[1]);
		bJ3_3.SetPtEtaPhiM(v3_bjetPt[2], v3_bjetEta[2], v3_bjetPhi[2], v3_bjetM[2]);
		bJ4_3.SetPtEtaPhiM(v3_bjetPt[3], v3_bjetEta[3], v3_bjetPhi[3], v3_bjetM[3]);

		bJ1bJ2_3 = bJ1_3 + bJ2_3;
		bJ1bJ3_3 = bJ1_3 + bJ3_3;
		bJ1bJ4_3 = bJ1_3 + bJ4_3;
		bJ2bJ3_3 = bJ2_3 + bJ3_3;
		bJ2bJ4_3 = bJ2_3 + bJ4_3;
		bJ3bJ4_3 = bJ3_3 + bJ4_3;

		Fill_bjetPtM_3(nhiggs);
	}
	return;
}
void SetLineWidth3()
{

	MH1H2_3->SetLineWidth(LINE_WIDTH); 
	PtH1H2_3->SetLineWidth(LINE_WIDTH); 

	Mb1b2_3->SetLineWidth(LINE_WIDTH); 
	Mb1b3_3->SetLineWidth(LINE_WIDTH);
	Mb1b4_3->SetLineWidth(LINE_WIDTH);
	Mb2b3_3->SetLineWidth(LINE_WIDTH);
	Mb2b4_3->SetLineWidth(LINE_WIDTH);
	Mb3b4_3->SetLineWidth(LINE_WIDTH);

	//Number of btags 
	h_NbTags3->SetLineWidth(LINE_WIDTH);
	//Number of SMhiggs 
	NSMhiggs3->SetLineWidth(LINE_WIDTH);
	//Number of bquarks 
	Nbquarks3->SetLineWidth(LINE_WIDTH);
	Njets3->SetLineWidth(LINE_WIDTH);
	//! Book histograms:
	//Higgs Pt
	higgsPt3->SetLineWidth(LINE_WIDTH);
	//Higgs sub leading Pt
	higgsNLPt3->SetLineWidth(LINE_WIDTH);
	//reconstructed leading Higgs M
	M_Lhiggs3->SetLineWidth(LINE_WIDTH);
	M_NLhiggs3->SetLineWidth(LINE_WIDTH);
	Pt_Lhiggs3->SetLineWidth(LINE_WIDTH);
	Pt_NLhiggs3->SetLineWidth(LINE_WIDTH);
	RecMH1H2_3->SetLineWidth(LINE_WIDTH);
	RecPtH1H2_3->SetLineWidth(LINE_WIDTH);

	// invariant mass of a pair of b's, ctr = 3.0
	M_b1b2_3->SetLineWidth(LINE_WIDTH);
	M_b1b3_3->SetLineWidth(LINE_WIDTH);
	M_b1b4_3->SetLineWidth(LINE_WIDTH);
	M_b2b3_3->SetLineWidth(LINE_WIDTH);
	M_b2b4_3->SetLineWidth(LINE_WIDTH);
	M_b3b4_3->SetLineWidth(LINE_WIDTH);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_3->SetLineWidth(LINE_WIDTH);
	dM_b1b3_b2b4_3->SetLineWidth(LINE_WIDTH);
	dM_b1b4_b2b3_3->SetLineWidth(LINE_WIDTH);
	
	jetLM3->SetLineWidth(LINE_WIDTH);
	//jet 2nd leading M
	jet2LM3->SetLineWidth(LINE_WIDTH);
	//jet 3rd leading M
	jet3LM3->SetLineWidth(LINE_WIDTH);
	//jet 4th leading M
	jet4LM3->SetLineWidth(LINE_WIDTH);
	
	bjetLM3->SetLineWidth(LINE_WIDTH);
	//bjet 2nd leading M
	bjet2LM3->SetLineWidth(LINE_WIDTH);
	//bjet 3rd leading M
	bjet3LM3->SetLineWidth(LINE_WIDTH);
	//bjet 4th leading M
	bjet4LM3->SetLineWidth(LINE_WIDTH);
	
	jetLPt3->SetLineWidth(LINE_WIDTH);
	//jet 2nd leading Pt
	jet2LPt3->SetLineWidth(LINE_WIDTH);
	//jet 3rd leading Pt
	jet3LPt3->SetLineWidth(LINE_WIDTH);
	//jet 4th leading Pt
	jet4LPt3->SetLineWidth(LINE_WIDTH);

	bjetLPt3->SetLineWidth(LINE_WIDTH);
	//b-jet 2nd leading Pt
	bjet2LPt3->SetLineWidth(LINE_WIDTH);
	//b-jet 3rd leading Pt
	bjet3LPt3->SetLineWidth(LINE_WIDTH);
	//b-jet 4th leading Pt
	bjet4LPt3->SetLineWidth(LINE_WIDTH);

	bLPt3->SetLineWidth(LINE_WIDTH);
	//b 2nd leading Pt
	b2LPt3->SetLineWidth(LINE_WIDTH);
	//b 3rd leading Pt
	b3LPt3->SetLineWidth(LINE_WIDTH);
	//b 4th leading Pt
	b4LPt3->SetLineWidth(LINE_WIDTH);

	bCEta3->SetLineWidth(LINE_WIDTH);
	//b 2nd central Pt
	b2CEta3->SetLineWidth(LINE_WIDTH);
	//b 3rd central Pt
	b3CEta3->SetLineWidth(LINE_WIDTH);
	//b 4th central Pt
	b4CEta3->SetLineWidth(LINE_WIDTH);
	return;

}
void Scale_signalHistos3(double norm)
{

	MH1H2_3->Scale(norm); 
	PtH1H2_3->Scale(norm); 

	Mb1b2_3->Scale(norm); 
	Mb1b3_3->Scale(norm);
	Mb1b4_3->Scale(norm);
	Mb2b3_3->Scale(norm);
	Mb2b4_3->Scale(norm);
	Mb3b4_3->Scale(norm);

	//Number of btags 
	h_NbTags3->Scale(norm);
	//Number of SMhiggs 
	NSMhiggs3->Scale(norm);
	//Number of bquarks 
	Nbquarks3->Scale(norm);
	Njets3->Scale(norm);
	//! Book histograms:
	//Higgs Pt
	higgsPt3->Scale(norm);
	//Higgs sub leading Pt
	higgsNLPt3->Scale(norm);
	//reconstructed leading Higgs M
	M_Lhiggs3->Scale(norm);
	M_NLhiggs3->Scale(norm);
	Pt_Lhiggs3->Scale(norm);
	Pt_NLhiggs3->Scale(norm);
	RecMH1H2_3->Scale(norm);
	RecPtH1H2_3->Scale(norm);

	// invariant mass of a pair of b's, ctr = 3.0
	M_b1b2_3->Scale(norm);
	M_b1b3_3->Scale(norm);
	M_b1b4_3->Scale(norm);
	M_b2b3_3->Scale(norm);
	M_b2b4_3->Scale(norm);
	M_b3b4_3->Scale(norm);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_3->Scale(norm);
	dM_b1b3_b2b4_3->Scale(norm);
	dM_b1b4_b2b3_3->Scale(norm);
	
	jetLM3->Scale(norm);
	//jet 2nd leading M
	jet2LM3->Scale(norm);
	//jet 3rd leading M
	jet3LM3->Scale(norm);
	//jet 4th leading M
	jet4LM3->Scale(norm);
	
	bjetLM3->Scale(norm);
	//bjet 2nd leading M
	bjet2LM3->Scale(norm);
	//bjet 3rd leading M
	bjet3LM3->Scale(norm);
	//bjet 4th leading M
	bjet4LM3->Scale(norm);
	
	jetLPt3->Scale(norm);
	//jet 2nd leading Pt
	jet2LPt3->Scale(norm);
	//jet 3rd leading Pt
	jet3LPt3->Scale(norm);
	//jet 4th leading Pt
	jet4LPt3->Scale(norm);

	bjetLPt3->Scale(norm);
	//b-jet 2nd leading Pt
	bjet2LPt3->Scale(norm);
	//b-jet 3rd leading Pt
	bjet3LPt3->Scale(norm);
	//b-jet 4th leading Pt
	bjet4LPt3->Scale(norm);

	bLPt3->Scale(norm);
	//b 2nd leading Pt
	b2LPt3->Scale(norm);
	//b 3rd leading Pt
	b3LPt3->Scale(norm);
	//b 4th leading Pt
	b4LPt3->Scale(norm);

	bCEta3->Scale(norm);
	//b 2nd central Pt
	b2CEta3->Scale(norm);
	//b 3rd central Pt
	b3CEta3->Scale(norm);
	//b 4th central Pt
	b4CEta3->Scale(norm);
	return;

}
void Set_NleadingJetColors_3()
{
	
	bjetLM3->SetLineColor(kOrange);
	bjet2LM3->SetLineColor(kBlack);
	bjet3LM3->SetLineColor(kRed);
	bjet4LM3->SetLineColor(kGreen);
	jetLM3->SetLineColor(kOrange);
	jet2LM3->SetLineColor(kBlack);
	jet3LM3->SetLineColor(kRed);
	jet4LM3->SetLineColor(kGreen);
	bjetLPt3->SetLineColor(kOrange);
	bjet2LPt3->SetLineColor(kBlack);
	bjet3LPt3->SetLineColor(kRed);
	bjet4LPt3->SetLineColor(kGreen);
	jetLPt3->SetLineColor(kOrange);
	jet2LPt3->SetLineColor(kBlack);
	jet3LPt3->SetLineColor(kRed);
	jet4LPt3->SetLineColor(kGreen);
	return;	
}
void Set_bquark_lambdaColors_3()
{

	M_Lhiggs3->SetLineColor(kViolet);
	M_NLhiggs3->SetLineColor(kViolet);
	Pt_Lhiggs3->SetLineColor(kViolet);
	Pt_NLhiggs3->SetLineColor(kViolet);
	RecMH1H2_3->SetLineColor(kViolet);
	RecPtH1H2_3->SetLineColor(kViolet);
	
	bjetLM3->SetLineColor(kViolet);
	bjet2LM3->SetLineColor(kViolet);
	bjet3LM3->SetLineColor(kViolet);
	bjet4LM3->SetLineColor(kViolet);
	jetLM3->SetLineColor(kViolet);
	jet2LM3->SetLineColor(kViolet);
	jet3LM3->SetLineColor(kViolet);
	jet4LM3->SetLineColor(kViolet);
	jetLPt3->SetLineColor(kViolet);
	jet2LPt3->SetLineColor(kViolet);
	jet3LPt3->SetLineColor(kViolet);
	jet4LPt3->SetLineColor(kViolet);
	bjetLPt3->SetLineColor(kViolet);
	bjet2LPt3->SetLineColor(kViolet);
	bjet3LPt3->SetLineColor(kViolet);
	bjet4LPt3->SetLineColor(kViolet);
	bLPt3->SetLineColor(kViolet);
	b2LPt3->SetLineColor(kViolet);
	b3LPt3->SetLineColor(kViolet);
	b4LPt3->SetLineColor(kViolet);
	bCEta3->SetLineColor(kViolet);
	b2CEta3->SetLineColor(kViolet);
	b3CEta3->SetLineColor(kViolet);
	b4CEta3->SetLineColor(kViolet);
	return;
}
void Draw_Number_bTags_3()
{
	h_NbTags3 = new TH1D("h_NbTags3", "number of b tagged jets, #lambda =3.0", 6, 0, 6);
	t3->Draw("Nbtags>>h_NbTags3");
	return;
}


