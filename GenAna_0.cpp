void ClearLorentzVectors_0()
{
	//! clear the Lorentz vectors
	higgs1_0 = TLorentzVector();
	higgs2_0 = TLorentzVector();
	H1H2_0 = TLorentzVector();

	b1_0 = TLorentzVector();
	b2_0 = TLorentzVector();
	b3_0 = TLorentzVector();
	b4_0 = TLorentzVector();

	b1b2_0 = TLorentzVector();
	b1b3_0 = TLorentzVector();
	b1b4_0 = TLorentzVector();
	b2b3_0 = TLorentzVector();
	b2b4_0 = TLorentzVector();
	b3b4_0 = TLorentzVector();
	
	bJ1_0 = TLorentzVector(); 
	bJ2_0 = TLorentzVector(); 
	bJ3_0 = TLorentzVector(); 
	bJ4_0 = TLorentzVector(); 
	bJ1bJ2_0 = TLorentzVector();
	bJ1bJ3_0 = TLorentzVector();
	bJ1bJ4_0 = TLorentzVector();
	bJ2bJ3_0 = TLorentzVector();
	bJ2bJ4_0 = TLorentzVector();
	bJ3bJ4_0 = TLorentzVector();

	RecH1H2_0 = TLorentzVector();
	return;

}
void fetch_histos_0()
{

	bLPt0  = (TH1D*)f0->Get("hbPt_Lpt");
	b2LPt0 = (TH1D*)f0->Get("hbPt_NLpt");
	b3LPt0 = (TH1D*)f0->Get("hbPt_NNLpt");
	b4LPt0 = (TH1D*)f0->Get("hbPt_NNNLpt");
	
	bCEta0  = (TH1D*)f0->Get("hbEta_Ceta");
	b2CEta0 = (TH1D*)f0->Get("hbEta_NCeta");
	b3CEta0 = (TH1D*)f0->Get("hbEta_NNCeta");
	b4CEta0 = (TH1D*)f0->Get("hbEta_NNNCeta");
	return;
}
void Draw_b_jetPt_0()
{
	
	
	t0->Draw("bJetLPt>>bjetLPt0");
	t0->Draw("bJetNLPt>>bjet2LPt0");
	t0->Draw("bJetNNLPt>>bjet3LPt0");
	t0->Draw("bJetNNNLPt>>bjet4LPt0");
	return;
}
void Draw_higgsPt_0()
{
	
	t0->Draw("higgsLPt*1e-3>>higgsPt0");
	t0->Draw("higgsNLPt*1e-3>>higgsNLPt0");
	
	return;
}
void Draw_Nparticles_0()
{
	int nbins = 6, nbins_1 = 20;
	double nmin = 0, nmax = 6, nmax_1 = 20;
	NSMhiggs0  = new TH1D("NSMhiggs0", "number of higgs", nbins, nmin, nmax);
	Nbquarks0  = new TH1D("Nbquarks0", "number of b quarks", nbins, nmin, nmax);
	Njets0  = new TH1D("Njets0", "number of jets", nbins_1, nmin, nmax_1);
	t0->Draw("NSMhiggs>>NSMhiggs0");
	t0->Draw("Nbquarks>>Nbquarks0");
	t0->Draw("Njets>>Njets0");
	NSMhiggs0->SetLineColor(kBlack);
	Nbquarks0->SetLineColor(kBlack);
	Njets0->SetLineColor(kBlack);
	return;
}
void fetch_TTrees_0()
{
	t0   = (TTree*)f0->Get("glob_jet");
	t0->SetBranchStatus("*",0);
	t0->SetBranchStatus("higgsLPt",1);
	t0->SetBranchStatus("higgsNLPt",1);
	t0->SetBranchStatus("NSMhiggs",1);
	t0->SetBranchStatus("Nbquarks",1);
	t0->SetBranchStatus("Njets",1);
	t0->SetBranchStatus("jetPt",1);
	t0->SetBranchStatus("jetEta",1);
	t0->SetBranchStatus("jetPhi",1);
	t0->SetBranchStatus("jetM",1);
	t0->SetBranchStatus("btaggedFlavor",1);
	t0->SetBranchStatus("bJetLPt",1);
	t0->SetBranchStatus("bJetNLPt",1);
	t0->SetBranchStatus("bJetNNLPt",1);
	t0->SetBranchStatus("bJetNNNLPt",1);
	t0->SetBranchStatus("Nbtags",1);
	t0->SetBranchStatus("v_higgsPt", 1);
	t0->SetBranchStatus("v_higgsEta",1);
	t0->SetBranchStatus("v_higgsPhi",1);
	t0->SetBranchStatus("v_higgsM",  1);
	t0->SetBranchStatus("v_bPt", 1);
	t0->SetBranchStatus("v_bEta",1);
	t0->SetBranchStatus("v_bPhi",1);
	t0->SetBranchStatus("v_bM",  1);

	t0->SetBranchAddress("jetPt",  &v0_jetPt);
	t0->SetBranchAddress("jetEta",  &v0_jetEta);
	t0->SetBranchAddress("jetPhi",  &v0_jetPhi);
	t0->SetBranchAddress("jetM",  &v0_jetM);
	t0->SetBranchAddress("btaggedFlavor",  &v0_tagFlavor);
	t0->SetBranchAddress("Nbtags",&n0_btags);
	t0->SetBranchAddress("v_higgsPt", &v0_higgsPt);
	t0->SetBranchAddress("v_higgsEta",&v0_higgsEta);
	t0->SetBranchAddress("v_higgsPhi",&v0_higgsPhi);
	t0->SetBranchAddress("v_higgsM",  &v0_higgsM);
	t0->SetBranchAddress("v_bPt", &v0_bPt);
	t0->SetBranchAddress("v_bEta",&v0_bEta);
	t0->SetBranchAddress("v_bPhi",&v0_bPhi);
	t0->SetBranchAddress("v_bM",  &v0_bM);
	return;
}
void Set_higgsPtProps_0()
{
	int nbins = 60;
	float ptmin = 0;
	float ptmax = 600;
	float Mmin = 200;
	float Mmax = 1400;
	//! truth leading and sub leading higgs Pt
	higgsPt0  = new TH1D("higgsPt0",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt0->SetLineColor(kBlack);
	higgsPt0->SetLineWidth(LINE_WIDTH);
	
	higgsNLPt0  = new TH1D("higgsNLPt0",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsNLPt0->SetLineColor(kBlack);
	higgsNLPt0->SetLineWidth(LINE_WIDTH);
	//! truth leading and sub leading higgs inv mass
	higgsL_M0  = new TH1D("higgsL_M0",  "Invariant higgs mass;m_{rec, leading higgs} [GeV];", nbins, ptmin, ptmax);
	higgsL_M0->SetLineColor(kBlack);
	higgsL_M0->SetLineWidth(LINE_WIDTH);
	
	higgsNL_M0  = new TH1D("higgsNL_M0",  "Invariant higgs mass;m_{rec, sub leading higgs} [GeV];", nbins, ptmin, ptmax);
	higgsNL_M0->SetLineColor(kBlack);
	higgsNL_M0->SetLineWidth(LINE_WIDTH);
	//! truth Inv mass of the di-higgs system
	MH1H2_0  = new TH1D("MH1H2_0",  "Invariant di-higgs mass;m_{truth, h1,h2} [GeV];", nbins, Mmin, Mmax);
	MH1H2_0->SetLineColor(kBlack);
	MH1H2_0->SetLineWidth(LINE_WIDTH);
	//! truth Pt of the di-higgs system
	PtH1H2_0  = new TH1D("PtH1H2_0",  "Transverse momentum of the di-higgs system;p_{T, truth, h1,h2} [GeV/c];", nbins, ptmin, ptmax);
	PtH1H2_0->SetLineColor(kBlack);
	PtH1H2_0->SetLineWidth(LINE_WIDTH);

	
	//! reconstructed leading and sub leading higgs pt
	Pt_Lhiggs0  = new TH1D("Pt_Lhiggs0",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	Pt_NLhiggs0  = new TH1D("Pt_NLhiggs0",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	//! reconstructed leading and sub leading inv mass
	M_Lhiggs0  = new TH1D("M_Lhiggs0",  "Invariant higgs mass;m_{rec, leading higgs} [GeV];", nbins, ptmin, ptmax);
	M_NLhiggs0  = new TH1D("M_NLhiggs0",  "Invariant higgs mass;m_{rec, sub leading higgs} [GeV];", nbins, ptmin, ptmax);
	
	//! reconstructed Inv mass of the di-higgs system
	RecMH1H2_0  = new TH1D("RecMH1H2_0",  "Invariant di-higgs mass;m_{truth, h1,h2} [GeV];", nbins, Mmin, Mmax);
	//! reconstructed Pt of the di-higgs system
	RecPtH1H2_0  = new TH1D("RecPtH1H2_0",  "Transverse momentum of the di-higgs system;p_{T, truth, h1,h2} [GeV/c];", nbins, ptmin, ptmax);

	// invariant mass of a pair of b's, ctr = 0.0
	Mb1b2_0 = new TH1D("Mb1b2_0", "#lambda = 0.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 12} [GeV];", nbins, ptmin, ptmax);
	Mb1b3_0 = new TH1D("Mb1b3_0", "#lambda = 0.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 13} [GeV];", nbins, ptmin, ptmax);
	Mb1b4_0 = new TH1D("Mb1b4_0", "#lambda = 0.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 14} [GeV];", nbins, ptmin, ptmax);
	Mb2b3_0 = new TH1D("Mb2b3_0", "#lambda = 0.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 23} [GeV];", nbins, ptmin, ptmax);
	Mb2b4_0 = new TH1D("Mb2b4_0", "#lambda = 0.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 24} [GeV];", nbins, ptmin, ptmax);
	Mb3b4_0 = new TH1D("Mb3b4_0", "#lambda = 0.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 34} [GeV];", nbins, ptmin, ptmax);
	return;
}
void Set_FinalJetPtProps_0()
{
	int nbins = 15; 
	Int_t nbinsMinus = nbins - 1; 
	Float_t pt_bins[15] = {20., 30., 40., 50., 60., 70., 80., 90., 100., 110., 120., 130., 140., 150., 500.};
	//b-jet leading Pt
	Ana_bjetLPt0  = new TH1D("Ana_bjetLPt0", "Jet p_{T} after analysis cuts; p_{T, leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	//b-jet 2nd leading Pt
	Ana_bjet2LPt0  = new TH1D("Ana_bjet2LPt0", "Jet p_{T} after analysis cuts; p_{T, sub leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	//b-jet 3rd leading Pt
	Ana_bjet3LPt0  = new TH1D("Ana_bjet3LPt0", "Jet p_{T} after analysis cuts; p_{T, 3rd leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	//b-jet 4th leading Pt
	Ana_bjet4LPt0  = new TH1D("Ana_bjet4LPt0", "Jet p_{T} after analysis cuts; p_{T, 4th leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	return;
}
void Set_jetPtProps_0()
{
	int nbins = 60;
	float ptmin = 0;
	float ptmax = 300;
	float dptmin = 0;
	float dptmax = 300;
	//b-jet leading Pt
	bjetLPt0  = new TH1D("bjetLPt0", "b-tagged Jet p_{t}; p_{t, leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 2nd leading Pt
	bjet2LPt0  = new TH1D("bjet2LPt0", "b-tagged Jet p_{t}; p_{t, sub leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 3rd leading Pt
	bjet3LPt0  = new TH1D("bjet3LPt0", "b-tagged Jet p_{t}; p_{t, 3rd leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 4th leading Pt
	bjet4LPt0  = new TH1D("bjet4LPt0", "b-tagged Jet p_{t}; p_{t, 4th leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	
	//jet leading Pt
	jetLPt0  = new TH1D("jetLPt0", "Jet p_{t}; p_{t, leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 2nd leading Pt
	jet2LPt0  = new TH1D("jet2LPt0", "Jet p_{t}; p_{t, sub leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 3rd leading Pt
	jet3LPt0  = new TH1D("jet3LPt0", "Jet p_{t}; p_{t, 3rd leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 4th leading Pt
	jet4LPt0  = new TH1D("jet4LPt0", "Jet p_{t}; p_{t, 4th leading jet} [GeV/c];", nbins, ptmin, ptmax);

	//jet leading M
	jetLM0  = new TH1D("jetLM0", "Jet invariant mass; m_{ leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 2nd leading M
	jet2LM0  = new TH1D("jet2LM0", "Jet invariant mass; m_{ sub leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 3rd leading M
	jet3LM0  = new TH1D("jet3LM0", "Jet invariant mass; m_{ 3rd leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 4th leading M
	jet4LM0  = new TH1D("jet4LM0", "Jet invariant mass; m_{ 4th leading jet} [GeV];", nbins, ptmin, ptmax);
	
	//bjet leading M
	bjetLM0  = new TH1D("bjetLM0", "Jet invariant mass; m_{ leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 2nd leading M
	bjet2LM0  = new TH1D("bjet2LM0", "Jet invariant mass; m_{ sub leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 3rd leading M
	bjet3LM0  = new TH1D("bjet3LM0", "Jet invariant mass; m_{ 3rd leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 4th leading M
	bjet4LM0  = new TH1D("bjet4LM0", "Jet invariant mass; m_{ 4th leading bjet} [GeV];", nbins, ptmin, ptmax);
	
	// invariant mass of a pair of b's, ctr = 0.0
	M_b1b2_0 = new TH1D("M_b1b2_0", "Invariant mass of the higgs candidates; m_{higgs candidate, 12} [GeV];", nbins, ptmin, ptmax);
	M_b1b3_0 = new TH1D("M_b1b3_0", "Invariant mass of the higgs candidates; m_{higgs candidate, 13} [GeV];", nbins, ptmin, ptmax);
	M_b1b4_0 = new TH1D("M_b1b4_0", "Invariant mass of the higgs candidates; m_{higgs candidate, 14} [GeV];", nbins, ptmin, ptmax);
	M_b2b3_0 = new TH1D("M_b2b3_0", "Invariant mass of the higgs candidates; m_{higgs candidate, 23} [GeV];", nbins, ptmin, ptmax);
	M_b2b4_0 = new TH1D("M_b2b4_0", "Invariant mass of the higgs candidates; m_{higgs candidate, 24} [GeV];", nbins, ptmin, ptmax);
	M_b3b4_0 = new TH1D("M_b3b4_0", "Invariant mass of the higgs candidates; m_{higgs candidate, 34} [GeV];", nbins, ptmin, ptmax);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_0 = new TH1D("dM_b1b2_b3b4_0", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1234} [GeV];", nbins, dptmin, dptmax);
	dM_b1b3_b2b4_0 = new TH1D("dM_b1b3_b2b4_0", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1324} [GeV];", nbins, dptmin, dptmax);
	dM_b1b4_b2b3_0 = new TH1D("dM_b1b4_b2b3_0", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1423} [GeV];", nbins, dptmin, dptmax);

	combi_selected_0 = new TH1D("combi_selected_0", "Selected combination", 3, 1, 4);
	return;
}
void Draw_InvariantMass_0()
{

	//! higgs's	
	if(v0_higgsPt->size() == 2)
	{
		higgs1_0.SetPtEtaPhiM((*v0_higgsPt)[0], (*v0_higgsEta)[0], (*v0_higgsPhi)[0], (*v0_higgsM)[0]);
		higgs2_0.SetPtEtaPhiM((*v0_higgsPt)[1], (*v0_higgsEta)[1], (*v0_higgsPhi)[1], (*v0_higgsM)[1]);
		H1H2_0 = higgs1_0 + higgs2_0;
		
		MH1H2_0->Fill(H1H2_0.M()*1e-3);
		PtH1H2_0->Fill(H1H2_0.Pt()*1e-3);
	}
	//! b's
	if(v0_bPt->size() == 4)
	{
		b1_0.SetPtEtaPhiM((*v0_bPt)[0], (*v0_bEta)[0], (*v0_bPhi)[0], (*v0_bM)[0]);
		b2_0.SetPtEtaPhiM((*v0_bPt)[1], (*v0_bEta)[1], (*v0_bPhi)[1], (*v0_bM)[1]);
		b3_0.SetPtEtaPhiM((*v0_bPt)[2], (*v0_bEta)[2], (*v0_bPhi)[2], (*v0_bM)[2]);
		b4_0.SetPtEtaPhiM((*v0_bPt)[3], (*v0_bEta)[3], (*v0_bPhi)[3], (*v0_bM)[3]);

		b1b2_0 = b1_0 + b2_0;
		b1b3_0 = b1_0 + b3_0;
		b1b4_0 = b1_0 + b4_0;
		b2b3_0 = b2_0 + b3_0;
		b2b4_0 = b2_0 + b4_0;
		b3b4_0 = b3_0 + b4_0;
		
		Mb1b2_0->Fill(b1b2_0.M()*1e-3);
		Mb1b3_0->Fill(b1b3_0.M()*1e-3);
		Mb1b4_0->Fill(b1b4_0.M()*1e-3);
		Mb2b3_0->Fill(b2b3_0.M()*1e-3);
		Mb2b4_0->Fill(b2b4_0.M()*1e-3);
		Mb3b4_0->Fill(b3b4_0.M()*1e-3);
	}

	return;
}
//void Fill_InvariantMass_0()
//{
//	Mb1b2_0->Fill(b1b2_0.M()*1e-3);
//	Mb1b3_0->Fill(b1b3_0.M()*1e-3);
//	Mb1b4_0->Fill(b1b4_0.M()*1e-3);
//	Mb2b3_0->Fill(b2b3_0.M()*1e-3);
//	Mb2b4_0->Fill(b2b4_0.M()*1e-3);
//	Mb3b4_0->Fill(b3b4_0.M()*1e-3);
//
//	MH1H2_0->Fill(H1H2_0.M()*1e-3);
//	PtH1H2_0->Fill(H1H2_0.Pt()*1e-3);
//	return;
//}
void Fill_NLeadingJetPtM_0()
{
	jetLPt0->Fill((*v0_jetPt)[0]*1e-3);
	jet2LPt0->Fill((*v0_jetPt)[1]*1e-3);
	jet3LPt0->Fill((*v0_jetPt)[2]*1e-3);
	jet4LPt0->Fill((*v0_jetPt)[3]*1e-3);
	
	jetLM0->Fill( (*v0_jetM)[0]*1e-3);
	jet2LM0->Fill((*v0_jetM)[1]*1e-3);
	jet3LM0->Fill((*v0_jetM)[2]*1e-3);
	jet4LM0->Fill((*v0_jetM)[3]*1e-3);

	return;
}
void Fill_bjetPtM_0(int &nhiggs)
{
	bjetLPt0->Fill( bJ1_0.Pt()*1e-3);
	bjet2LPt0->Fill(bJ2_0.Pt()*1e-3);
	bjet3LPt0->Fill(bJ3_0.Pt()*1e-3);
	bjet4LPt0->Fill(bJ4_0.Pt()*1e-3);

	bjetLM0->Fill( bJ1_0.M()*1e-3);
	bjet2LM0->Fill(bJ2_0.M()*1e-3);
	bjet3LM0->Fill(bJ3_0.M()*1e-3);
	bjet4LM0->Fill(bJ4_0.M()*1e-3);
	
	M_b1b2_0->Fill(bJ1bJ2_0.M()*1e-3);
	M_b1b3_0->Fill(bJ1bJ3_0.M()*1e-3);
	M_b1b4_0->Fill(bJ1bJ4_0.M()*1e-3);
	M_b2b3_0->Fill(bJ2bJ3_0.M()*1e-3);
	M_b2b4_0->Fill(bJ2bJ4_0.M()*1e-3);
	M_b3b4_0->Fill(bJ3bJ4_0.M()*1e-3);

	double dm_12_34 = 0, dm_13_24 = 0, dm_14_23 = 0;
	dm_12_34 = std::fabs(bJ1bJ2_0.M() - bJ3bJ4_0.M())*1e-3;
	dm_13_24 = std::fabs(bJ1bJ3_0.M() - bJ2bJ4_0.M())*1e-3;
	dm_14_23 = std::fabs(bJ1bJ4_0.M() - bJ2bJ3_0.M())*1e-3;
	//dM_b1b2_b3b4_0->Fill(dm_12_34*1e-3);	
	//dM_b1b3_b2b4_0->Fill(dm_13_24*1e-3);	
	//dM_b1b4_b2b3_0->Fill(dm_14_23*1e-3);

	//! Higgs Candidate
	int higgs_candidates = -1;
	int min_diffCombi = 999;
	if((std::fabs(bJ1bJ2_0.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ3bJ4_0.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
		if(dm_12_34 < min_diffCombi) 
		{
			min_diffCombi = dm_12_34;
			higgs_candidates = 1234;
		}
	}

	if((std::fabs(bJ1bJ3_0.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ4_0.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
		if(dm_13_24 < min_diffCombi) 
		{
			min_diffCombi = dm_13_24;
			higgs_candidates = 1324;
		}
	}

	if((std::fabs(bJ1bJ4_0.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ3_0.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
		if(dm_14_23 < min_diffCombi)
		{
			min_diffCombi = dm_14_23;
			higgs_candidates = 1423;
		}
	}

	if(higgs_candidates == 1234)
	{
		//if((std::fabs(bJ1bJ2_0.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ3bJ4_0.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		//{
			combi_selected_0->Fill(1);
			nhiggs++;
			//! Fill four jet pt after all selection
			Ana_bjetLPt0->Fill( bJ1_0.Pt()*1e-3);
			Ana_bjet2LPt0->Fill(bJ2_0.Pt()*1e-3);
			Ana_bjet3LPt0->Fill(bJ3_0.Pt()*1e-3);
			Ana_bjet4LPt0->Fill(bJ4_0.Pt()*1e-3);
			if(bJ1bJ2_0.M() > bJ3bJ4_0.M())
			{
				M_Lhiggs0->Fill(bJ1bJ2_0.M()*1e-3);
				M_NLhiggs0->Fill(bJ3bJ4_0.M()*1e-3);
				Pt_Lhiggs0->Fill(bJ1bJ2_0.Pt()*1e-3);
				Pt_NLhiggs0->Fill(bJ3bJ4_0.Pt()*1e-3);
			
			} 
			else
			{
				M_Lhiggs0->Fill(bJ3bJ4_0.M()*1e-3);
				M_NLhiggs0->Fill(bJ1bJ2_0.M()*1e-3);
				Pt_Lhiggs0->Fill(bJ3bJ4_0.Pt()*1e-3);
				Pt_NLhiggs0->Fill(bJ1bJ2_0.Pt()*1e-3);
				
			}
			RecH1H2_0 = bJ1bJ2_0 + bJ3bJ4_0;
			RecMH1H2_0->Fill(RecH1H2_0.M()*1e-3);
			RecPtH1H2_0->Fill(RecH1H2_0.Pt()*1e-3);
			
			dM_b1b2_b3b4_0->Fill(dm_12_34);	

		//}
	}
	else if(higgs_candidates == 1324)
	{
		//if((std::fabs(bJ1bJ3_0.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ4_0.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		//{
			combi_selected_0->Fill(2);
			nhiggs++;
			//! Fill four jet pt after all selection
			Ana_bjetLPt0->Fill( bJ1_0.Pt()*1e-3);
			Ana_bjet2LPt0->Fill(bJ2_0.Pt()*1e-3);
			Ana_bjet3LPt0->Fill(bJ3_0.Pt()*1e-3);
			Ana_bjet4LPt0->Fill(bJ4_0.Pt()*1e-3);
			if(bJ1bJ3_0.M() > bJ2bJ4_0.M())
			{
				M_Lhiggs0->Fill(bJ1bJ3_0.M()*1e-3);
				M_NLhiggs0->Fill(bJ2bJ4_0.M()*1e-3);
				Pt_Lhiggs0->Fill(bJ1bJ3_0.Pt()*1e-3);
				Pt_NLhiggs0->Fill(bJ2bJ4_0.Pt()*1e-3);
			
			} 
			else
			{
				M_Lhiggs0->Fill(bJ2bJ4_0.M()*1e-3);
				M_NLhiggs0->Fill(bJ1bJ3_0.M()*1e-3);
				Pt_Lhiggs0->Fill(bJ2bJ4_0.Pt()*1e-3);
				Pt_NLhiggs0->Fill(bJ1bJ3_0.Pt()*1e-3);
				
			}
			RecH1H2_0 = bJ1bJ3_0 + bJ2bJ4_0;
			RecMH1H2_0->Fill(RecH1H2_0.M()*1e-3);
			RecPtH1H2_0->Fill(RecH1H2_0.Pt()*1e-3);
			
			dM_b1b3_b2b4_0->Fill(dm_13_24);	
		//}
	
	}
	else if(higgs_candidates == 1423)
	{
		//if((std::fabs(bJ1bJ4_0.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ3_0.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		//{
			combi_selected_0->Fill(3);
			nhiggs++;
			//! Fill four jet pt after all selection
			Ana_bjetLPt0->Fill( bJ1_0.Pt()*1e-3);
			Ana_bjet2LPt0->Fill(bJ2_0.Pt()*1e-3);
			Ana_bjet3LPt0->Fill(bJ3_0.Pt()*1e-3);
			Ana_bjet4LPt0->Fill(bJ4_0.Pt()*1e-3);
			if(bJ1bJ4_0.M() > bJ2bJ3_0.M())
			{
				M_Lhiggs0->Fill(bJ1bJ4_0.M()*1e-3);
				M_NLhiggs0->Fill(bJ2bJ3_0.M()*1e-3);
				Pt_Lhiggs0->Fill(bJ1bJ4_0.Pt()*1e-3);
				Pt_NLhiggs0->Fill(bJ2bJ3_0.Pt()*1e-3);
			
			} 
			else
			{
				M_Lhiggs0->Fill(bJ2bJ3_0.M()*1e-3);
				M_NLhiggs0->Fill(bJ1bJ4_0.M()*1e-3);
				Pt_Lhiggs0->Fill(bJ2bJ3_0.Pt()*1e-3);
				Pt_NLhiggs0->Fill(bJ1bJ4_0.Pt()*1e-3);
				
			}
			RecH1H2_0 = bJ1bJ4_0 + bJ2bJ3_0;
			RecMH1H2_0->Fill(RecH1H2_0.M()*1e-3);
			RecPtH1H2_0->Fill(RecH1H2_0.Pt()*1e-3);
			
			dM_b1b4_b2b3_0->Fill(dm_14_23);
		//}
	
	}

	return;
}
void Draw_DiJetInvariantMass_0(int &nb0, int &nhiggs)
{
	v0_bjetPt.clear();
	v0_bjetEta.clear();
	v0_bjetPhi.clear();
	v0_bjetM.clear();


	for(int j = 0; j < v0_tagFlavor->size(); j++)
	{
		if((*v0_tagFlavor)[j] != 5) continue;
		v0_bjetPt.push_back((*v0_jetPt)[j]);
		v0_bjetEta.push_back((*v0_jetEta)[j]);
		v0_bjetPhi.push_back((*v0_jetPhi)[j]);
		v0_bjetM.push_back((*v0_jetM)[j]);

	}
	
	//! b jet's
	if(v0_bjetPt.size() > 3)
	{
		if(v0_bjetPt[0]*1e-3 >= minLeadingPt  && v0_bjetPt[1]*1e-3 >= minSubLeadingPt  && v0_bjetPt[2]*1e-3 >= third_Pt_cut && v0_bjetPt[3]*1e-3 >= default_Pt_cut )
		{
			nb0++;
			bJ1_0.SetPtEtaPhiM(v0_bjetPt[0], v0_bjetEta[0], v0_bjetPhi[0], v0_bjetM[0]);
			bJ2_0.SetPtEtaPhiM(v0_bjetPt[1], v0_bjetEta[1], v0_bjetPhi[1], v0_bjetM[1]);
			bJ3_0.SetPtEtaPhiM(v0_bjetPt[2], v0_bjetEta[2], v0_bjetPhi[2], v0_bjetM[2]);
			bJ4_0.SetPtEtaPhiM(v0_bjetPt[3], v0_bjetEta[3], v0_bjetPhi[3], v0_bjetM[3]);

			bJ1bJ2_0 = bJ1_0 + bJ2_0;
			bJ1bJ3_0 = bJ1_0 + bJ3_0;
			bJ1bJ4_0 = bJ1_0 + bJ4_0;
			bJ2bJ3_0 = bJ2_0 + bJ3_0;
			bJ2bJ4_0 = bJ2_0 + bJ4_0;
			bJ3bJ4_0 = bJ3_0 + bJ4_0;
		
			Fill_bjetPtM_0(nhiggs);
		}
	}
	return;
}

void SetLineWidth0() 
{
	MH1H2_0->SetLineWidth(LINE_WIDTH); 
	PtH1H2_0->SetLineWidth(LINE_WIDTH); 

	Mb1b2_0->SetLineWidth(LINE_WIDTH); 
	Mb1b3_0->SetLineWidth(LINE_WIDTH);
	Mb1b4_0->SetLineWidth(LINE_WIDTH);
	Mb2b3_0->SetLineWidth(LINE_WIDTH);
	Mb2b4_0->SetLineWidth(LINE_WIDTH);
	Mb3b4_0->SetLineWidth(LINE_WIDTH);

	h_NbTags0->SetLineWidth(LINE_WIDTH);
	NSMhiggs0->SetLineWidth(LINE_WIDTH);
	Nbquarks0->SetLineWidth(LINE_WIDTH);
	Njets0->SetLineWidth(LINE_WIDTH);
	higgsPt0->SetLineWidth(LINE_WIDTH);
	higgsNLPt0->SetLineWidth(LINE_WIDTH);
	M_Lhiggs0->SetLineWidth(LINE_WIDTH);
	M_NLhiggs0->SetLineWidth(LINE_WIDTH);
	Pt_Lhiggs0->SetLineWidth(LINE_WIDTH);
	Pt_NLhiggs0->SetLineWidth(LINE_WIDTH);
	RecMH1H2_0->SetLineWidth(LINE_WIDTH);
	RecPtH1H2_0->SetLineWidth(LINE_WIDTH);
	
	// invariant mass of a pair of b's, ctr = 0.0
	M_b1b2_0->SetLineWidth(LINE_WIDTH);
	M_b1b3_0->SetLineWidth(LINE_WIDTH);
	M_b1b4_0->SetLineWidth(LINE_WIDTH);
	M_b2b3_0->SetLineWidth(LINE_WIDTH);
	M_b2b4_0->SetLineWidth(LINE_WIDTH);
	M_b3b4_0->SetLineWidth(LINE_WIDTH);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_0->SetLineWidth(LINE_WIDTH);
	dM_b1b3_b2b4_0->SetLineWidth(LINE_WIDTH);
	dM_b1b4_b2b3_0->SetLineWidth(LINE_WIDTH);

	jetLM0->SetLineWidth(LINE_WIDTH);
	jet2LM0->SetLineWidth(LINE_WIDTH);
	jet3LM0->SetLineWidth(LINE_WIDTH);
	jet4LM0->SetLineWidth(LINE_WIDTH);

	bjetLM0->SetLineWidth(LINE_WIDTH);
	bjet2LM0->SetLineWidth(LINE_WIDTH);
	bjet3LM0->SetLineWidth(LINE_WIDTH);
	bjet4LM0->SetLineWidth(LINE_WIDTH);

	jetLPt0->SetLineWidth(LINE_WIDTH);
	jet2LPt0->SetLineWidth(LINE_WIDTH);
	jet3LPt0->SetLineWidth(LINE_WIDTH);
	jet4LPt0->SetLineWidth(LINE_WIDTH);

	bjetLPt0->SetLineWidth(LINE_WIDTH);
	bjet2LPt0->SetLineWidth(LINE_WIDTH);
	bjet3LPt0->SetLineWidth(LINE_WIDTH);
	bjet4LPt0->SetLineWidth(LINE_WIDTH);

	bLPt0->SetLineWidth(LINE_WIDTH);
	b2LPt0->SetLineWidth(LINE_WIDTH);
	b3LPt0->SetLineWidth(LINE_WIDTH);
	b4LPt0->SetLineWidth(LINE_WIDTH);

	bCEta0->SetLineWidth(LINE_WIDTH);
	b2CEta0->SetLineWidth(LINE_WIDTH);
	b3CEta0->SetLineWidth(LINE_WIDTH);
	b4CEta0->SetLineWidth(LINE_WIDTH);
	return;
}
void Scale_signalHistos0(double norm) 
{
	MH1H2_0->Scale(norm); 
	PtH1H2_0->Scale(norm); 

	Mb1b2_0->Scale(norm); 
	Mb1b3_0->Scale(norm);
	Mb1b4_0->Scale(norm);
	Mb2b3_0->Scale(norm);
	Mb2b4_0->Scale(norm);
	Mb3b4_0->Scale(norm);

	h_NbTags0->Scale(norm);
	NSMhiggs0->Scale(norm);
	Nbquarks0->Scale(norm);
	Njets0->Scale(norm);
	higgsPt0->Scale(norm);
	higgsNLPt0->Scale(norm);
	M_Lhiggs0->Scale(norm);
	M_NLhiggs0->Scale(norm);
	Pt_Lhiggs0->Scale(norm);
	Pt_NLhiggs0->Scale(norm);
	RecMH1H2_0->Scale(norm);
	RecPtH1H2_0->Scale(norm);
	
	// invariant mass of a pair of b's, ctr = 0.0
	M_b1b2_0->Scale(norm);
	M_b1b3_0->Scale(norm);
	M_b1b4_0->Scale(norm);
	M_b2b3_0->Scale(norm);
	M_b2b4_0->Scale(norm);
	M_b3b4_0->Scale(norm);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_0->Scale(norm);
	dM_b1b3_b2b4_0->Scale(norm);
	dM_b1b4_b2b3_0->Scale(norm);

	jetLM0->Scale(norm);
	jet2LM0->Scale(norm);
	jet3LM0->Scale(norm);
	jet4LM0->Scale(norm);

	bjetLM0->Scale(norm);
	bjet2LM0->Scale(norm);
	bjet3LM0->Scale(norm);
	bjet4LM0->Scale(norm);

	jetLPt0->Scale(norm);
	jet2LPt0->Scale(norm);
	jet3LPt0->Scale(norm);
	jet4LPt0->Scale(norm);

	bjetLPt0->Scale(norm);
	bjet2LPt0->Scale(norm);
	bjet3LPt0->Scale(norm);
	bjet4LPt0->Scale(norm);

	bLPt0->Scale(norm);
	b2LPt0->Scale(norm);
	b3LPt0->Scale(norm);
	b4LPt0->Scale(norm);

	bCEta0->Scale(norm);
	b2CEta0->Scale(norm);
	b3CEta0->Scale(norm);
	b4CEta0->Scale(norm);
	return;
}
void Set_NleadingJetColors_0()
{
	bjetLM0->SetLineColor(kOrange);
	bjet2LM0->SetLineColor(kBlack);
	bjet3LM0->SetLineColor(kRed);
	bjet4LM0->SetLineColor(kGreen);
	jetLM0->SetLineColor(kOrange);
	jet2LM0->SetLineColor(kBlack);
	jet3LM0->SetLineColor(kRed);
	jet4LM0->SetLineColor(kGreen);
	bjetLPt0->SetLineColor(kOrange);
	bjet2LPt0->SetLineColor(kBlack);
	bjet3LPt0->SetLineColor(kRed);
	bjet4LPt0->SetLineColor(kGreen);
	jetLPt0->SetLineColor(kOrange);
	jet2LPt0->SetLineColor(kBlack);
	jet3LPt0->SetLineColor(kRed);
	jet4LPt0->SetLineColor(kGreen);
	return;	
}
void Set_bquark_lambdaColors_0()
{

	M_Lhiggs0->SetLineColor(kBlack);
	M_NLhiggs0->SetLineColor(kBlack);
	Pt_Lhiggs0->SetLineColor(kBlack);
	Pt_NLhiggs0->SetLineColor(kBlack);
	RecMH1H2_0->SetLineColor(kBlack);
	RecPtH1H2_0->SetLineColor(kBlack);

	bjetLM0->SetLineColor(kBlack);
	bjet2LM0->SetLineColor(kBlack);
	bjet3LM0->SetLineColor(kBlack);
	bjet4LM0->SetLineColor(kBlack);
	jetLM0->SetLineColor(kBlack);
	jet2LM0->SetLineColor(kBlack);
	jet3LM0->SetLineColor(kBlack);
	jet4LM0->SetLineColor(kBlack);
	jetLPt0->SetLineColor(kBlack);
	jet2LPt0->SetLineColor(kBlack);
	jet3LPt0->SetLineColor(kBlack);
	jet4LPt0->SetLineColor(kBlack);
	bjetLPt0->SetLineColor(kBlack);
	bjet2LPt0->SetLineColor(kBlack);
	bjet3LPt0->SetLineColor(kBlack);
	bjet4LPt0->SetLineColor(kBlack);
	bLPt0->SetLineColor(kBlack);
	b2LPt0->SetLineColor(kBlack);
	b3LPt0->SetLineColor(kBlack);
	b4LPt0->SetLineColor(kBlack);
	bCEta0->SetLineColor(kBlack);
	b2CEta0->SetLineColor(kBlack);
	b3CEta0->SetLineColor(kBlack);
	b4CEta0->SetLineColor(kBlack);
	return;
}
void Draw_Number_bTags_0()
{

	h_NbTags0 = new TH1D("h_NbTags0", "number of b tagged jets, #lambda =0.0", 6, 0, 6);
	t0->Draw("Nbtags>>h_NbTags0");
	return;
}


