void ClearLorentzVectors_2()
{
	//! clear the Lorentz vectors
	higgs1_2 = TLorentzVector();
	higgs2_2 = TLorentzVector();
	H1H2_2 = TLorentzVector();

	b1_2 = TLorentzVector();
	b2_2 = TLorentzVector();
	b3_2 = TLorentzVector();
	b4_2 = TLorentzVector();

	b1b2_2 = TLorentzVector();
	b1b3_2 = TLorentzVector();
	b1b4_2 = TLorentzVector();
	b2b3_2 = TLorentzVector();
	b2b4_2 = TLorentzVector();
	b3b4_2 = TLorentzVector();
	
	bJ1_2 = TLorentzVector(); 
	bJ2_2 = TLorentzVector(); 
	bJ3_2 = TLorentzVector(); 
	bJ4_2 = TLorentzVector(); 
	bJ1bJ2_2 = TLorentzVector();
	bJ1bJ3_2 = TLorentzVector();
	bJ1bJ4_2 = TLorentzVector();
	bJ2bJ3_2 = TLorentzVector();
	bJ2bJ4_2 = TLorentzVector();
	bJ3bJ4_2 = TLorentzVector();

	RecH1H2_2 = TLorentzVector();
	return;

}
void fetch_histos_2()
{

	bLPt2  = (TH1D*)f2->Get("hbPt_Lpt");
	b2LPt2 = (TH1D*)f2->Get("hbPt_NLpt");
	b3LPt2 = (TH1D*)f2->Get("hbPt_NNLpt");
	b4LPt2 = (TH1D*)f2->Get("hbPt_NNNLpt");
	
	bCEta2  = (TH1D*)f2->Get("hbEta_Ceta");
	b2CEta2 = (TH1D*)f2->Get("hbEta_NCeta");
	b3CEta2 = (TH1D*)f2->Get("hbEta_NNCeta");
	b4CEta2 = (TH1D*)f2->Get("hbEta_NNNCeta");
	
	return;
}
void Draw_b_jetPt_2()
{

	t2->Draw("bJetLPt>>bjetLPt2");
	t2->Draw("bJetNLPt>>bjet2LPt2");
	t2->Draw("bJetNNLPt>>bjet3LPt2");
	t2->Draw("bJetNNNLPt>>bjet4LPt2");
	
	return;
}
void Draw_higgsPt_2()
{
	
	t2->Draw("higgsLPt*1e-3>>higgsPt2");
	t2->Draw("higgsNLPt*1e-3>>higgsNLPt2");
	
	return;
}
void Draw_Nparticles_2()
{
	int nbins = 6, nbins_1 = 20;
	double nmin = 0, nmax = 6, nmax_1 = 20;
	NSMhiggs2  = new TH1D("NSMhiggs2", "number of higgs", nbins, nmin, nmax);
	Nbquarks2  = new TH1D("Nbquarks2", "number of b quarks", nbins, nmin, nmax);
	Njets2  = new TH1D("Njets2", "number of jets", nbins_1, nmin, nmax_1);
	t2->Draw("NSMhiggs>>NSMhiggs2");
	t2->Draw("Nbquarks>>Nbquarks2");
	t2->Draw("Njets>>Njets2");
	NSMhiggs2->SetLineColor(kBlue);
	Nbquarks2->SetLineColor(kBlue);
	Njets2->SetLineColor(kBlue);
	return;
}
void fetch_TTrees_2()
{
	t2   = (TTree*)f2->Get("glob_jet");
	t2->SetBranchStatus("*",0);
	t2->SetBranchStatus("higgsLPt",1);
	t2->SetBranchStatus("higgsNLPt",1);
	t2->SetBranchStatus("NSMhiggs",1);
	t2->SetBranchStatus("Nbquarks",1);
	t2->SetBranchStatus("Njets",1);
	t2->SetBranchStatus("jetPt",1);
	t2->SetBranchStatus("jetEta",1);
	t2->SetBranchStatus("jetPhi",1);
	t2->SetBranchStatus("jetM",1);
	t2->SetBranchStatus("btaggedFlavor",1);
	t2->SetBranchStatus("bJetLPt",1);
	t2->SetBranchStatus("bJetNLPt",1);
	t2->SetBranchStatus("bJetNNLPt",1);
	t2->SetBranchStatus("bJetNNNLPt",1);
	t2->SetBranchStatus("Nbtags",1);
	t2->SetBranchStatus("v_higgsPt", 1);
	t2->SetBranchStatus("v_higgsEta",1);
	t2->SetBranchStatus("v_higgsPhi",1);
	t2->SetBranchStatus("v_higgsM",  1);
	t2->SetBranchStatus("v_bPt", 1);
	t2->SetBranchStatus("v_bEta",1);
	t2->SetBranchStatus("v_bPhi",1);
	t2->SetBranchStatus("v_bM",  1);
	
	t2->SetBranchAddress("jetPt",  &v2_jetPt);
	t2->SetBranchAddress("jetEta",  &v2_jetEta);
	t2->SetBranchAddress("jetPhi",  &v2_jetPhi);
	t2->SetBranchAddress("jetM",  &v2_jetM);
	t2->SetBranchAddress("btaggedFlavor",  &v2_tagFlavor);
	t2->SetBranchAddress("Nbtags",&n2_btags);
	t2->SetBranchAddress("v_higgsPt", &v2_higgsPt);
	t2->SetBranchAddress("v_higgsEta",&v2_higgsEta);
	t2->SetBranchAddress("v_higgsPhi",&v2_higgsPhi);
	t2->SetBranchAddress("v_higgsM",  &v2_higgsM);
	t2->SetBranchAddress("v_bPt", &v2_bPt);
	t2->SetBranchAddress("v_bEta",&v2_bEta);
	t2->SetBranchAddress("v_bPhi",&v2_bPhi);
	t2->SetBranchAddress("v_bM",  &v2_bM);

	return;
}
void Set_higgsPtProps_2()
{
	int nbins = 60;
	float ptmin = 0;
	float ptmax = 600;
	float Mmin = 200;
	float Mmax = 1400;
	//! truth leading and sub leading higgs Pt
	higgsPt2  = new TH1D("higgsPt2",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt2->SetLineColor(kBlue);
	higgsPt2->SetLineWidth(LINE_WIDTH);
	
	higgsNLPt2  = new TH1D("higgsNLPt2",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsNLPt2->SetLineColor(kBlue);
	higgsNLPt2->SetLineWidth(LINE_WIDTH);
	//! truth leading and sub leading higgs inv mass
	higgsL_M2  = new TH1D("higgsL_M2",  "Invariant higgs mass;m_{rec, leading higgs} [GeV];", nbins, ptmin, ptmax);
	higgsL_M2->SetLineColor(kBlue);
	higgsL_M2->SetLineWidth(LINE_WIDTH);
	
	higgsNL_M2  = new TH1D("higgsNL_M2",  "Invariant higgs mass;m_{rec, sub leading higgs} [GeV];", nbins, ptmin, ptmax);
	higgsNL_M2->SetLineColor(kBlue);
	higgsNL_M2->SetLineWidth(LINE_WIDTH);
	//! truth Inv mass of the di-higgs system
	MH1H2_2  = new TH1D("MH1H2_2",  "Invariant di-higgs mass;m_{truth, h1,h2} [GeV];", nbins, Mmin, Mmax);
	MH1H2_2->SetLineColor(kBlue);
	MH1H2_2->SetLineWidth(LINE_WIDTH);
	//! truth Pt of the di-higgs system
	PtH1H2_2  = new TH1D("PtH1H2_2",  "Transverse momentum of the di-higgs system;p_{T, truth, h1,h2} [GeV/c];", nbins, ptmin, ptmax);
	PtH1H2_2->SetLineColor(kBlue);
	PtH1H2_2->SetLineWidth(LINE_WIDTH);

	
	//! reconstructed leading and sub leading higgs pt
	Pt_Lhiggs2  = new TH1D("Pt_Lhiggs2",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	Pt_NLhiggs2  = new TH1D("Pt_NLhiggs2",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	//! reconstructed leading and sub leading inv mass
	M_Lhiggs2  = new TH1D("M_Lhiggs2",  "Invariant higgs mass;m_{rec, leading higgs} [GeV];", nbins, MLHmin, MLHmax);
	M_NLhiggs2  = new TH1D("M_NLhiggs2",  "Invariant higgs mass;m_{rec, sub leading higgs} [GeV];", nbins, MLHmin, MLHmax);
	
	//! reconstructed Inv mass of the di-higgs system
	RecMH1H2_2  = new TH1D("RecMH1H2_2",  "Invariant di-higgs mass;m_{truth, h1,h2} [GeV];", nbins, Mmin1, Mmax);
	//! reconstructed Pt of the di-higgs system
	RecPtH1H2_2  = new TH1D("RecPtH1H2_2",  "Transverse momentum of the di-higgs system;p_{T, truth, h1,h2} [GeV/c];", nbins, ptmin, ptmax);

	// invariant mass of a pair of b's, ctr = 2.0
	Mb1b2_2 = new TH1D("Mb1b2_2", "#lambda = 2.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 12} [GeV];", nbins, ptmin, ptmax);
	Mb1b3_2 = new TH1D("Mb1b3_2", "#lambda = 2.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 13} [GeV];", nbins, ptmin, ptmax);
	Mb1b4_2 = new TH1D("Mb1b4_2", "#lambda = 2.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 14} [GeV];", nbins, ptmin, ptmax);
	Mb2b3_2 = new TH1D("Mb2b3_2", "#lambda = 2.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 23} [GeV];", nbins, ptmin, ptmax);
	Mb2b4_2 = new TH1D("Mb2b4_2", "#lambda = 2.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 24} [GeV];", nbins, ptmin, ptmax);
	Mb3b4_2 = new TH1D("Mb3b4_2", "#lambda = 2.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 34} [GeV];", nbins, ptmin, ptmax);
	return;
}
void Set_FinalJetPtProps_2()
{
	int nbins = 15; 
	Int_t nbinsMinus = nbins - 1; 
	Float_t pt_bins[15] = {20., 30., 40., 50., 60., 70., 80., 90., 100., 110., 120., 130., 140., 150., 500.};
	//b-jet leading Pt
	Ana_bjetLPt2  = new TH1D("Ana_bjetLPt2", "Jet p_{T} after analysis cuts; p_{T, leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	//b-jet 2nd leading Pt
	Ana_bjet2LPt2  = new TH1D("Ana_bjet2LPt2", "Jet p_{T} after analysis cuts; p_{T, sub leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	//b-jet 3rd leading Pt
	Ana_bjet3LPt2  = new TH1D("Ana_bjet3LPt2", "Jet p_{T} after analysis cuts; p_{T, 3rd leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	//b-jet 4th leading Pt
	Ana_bjet4LPt2  = new TH1D("Ana_bjet4LPt2", "Jet p_{T} after analysis cuts; p_{T, 4th leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	return;
}
void Set_jetPtProps_2()
{
	int nbins = 60;
	float ptmin = 0;
	float ptmax = 300;
	float dptmin = 0;
	float dptmax = 300;
	//b-jet leading Pt
	bjetLPt2  = new TH1D("bjetLPt2", "b-tagged Jet p_{t}; p_{t, leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 2nd leading Pt
	bjet2LPt2  = new TH1D("bjet2LPt2", "b-tagged Jet p_{t}; p_{t, sub leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 3rd leading Pt
	bjet3LPt2  = new TH1D("bjet3LPt2", "b-tagged Jet p_{t}; p_{t, 3rd leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 4th leading Pt
	bjet4LPt2  = new TH1D("bjet4LPt2", "b-tagged Jet p_{t}; p_{t, 4th leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	
	//jet leading Pt
	jetLPt2  = new TH1D("jetLPt2", "Jet p_{t}; p_{t, leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 2nd leading Pt
	jet2LPt2  = new TH1D("jet2LPt2", "Jet p_{t}; p_{t, sub leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 3rd leading Pt
	jet3LPt2  = new TH1D("jet3LPt2", "Jet p_{t}; p_{t, 3rd leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 4th leading Pt
	jet4LPt2  = new TH1D("jet4LPt2", "Jet p_{t}; p_{t, 4th leading jet} [GeV/c];", nbins, ptmin, ptmax);

	//jet leading M
	jetLM2  = new TH1D("jetLM2", "Jet invariant mass; m_{ leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 2nd leading M
	jet2LM2  = new TH1D("jet2LM2", "Jet invariant mass; m_{ sub leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 3rd leading M
	jet3LM2  = new TH1D("jet3LM2", "Jet invariant mass; m_{ 3rd leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 4th leading M
	jet4LM2  = new TH1D("jet4LM2", "Jet invariant mass; m_{ 4th leading jet} [GeV];", nbins, ptmin, ptmax);
	
	//bjet leading M
	bjetLM2  = new TH1D("bjetLM2", "Jet invariant mass; m_{ leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 2nd leading M
	bjet2LM2  = new TH1D("bjet2LM2", "Jet invariant mass; m_{ sub leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 3rd leading M
	bjet3LM2  = new TH1D("bjet3LM2", "Jet invariant mass; m_{ 3rd leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 4th leading M
	bjet4LM2  = new TH1D("bjet4LM2", "Jet invariant mass; m_{ 4th leading bjet} [GeV];", nbins, ptmin, ptmax);
	
	// invariant mass of a pair of b's, ctr = 1.0
	M_b1b2_2 = new TH1D("M_b1b2_2", "Invariant mass of the higgs candidates; m_{higgs candidate, 12} [GeV];", nbins, ptmin, ptmax);
	M_b1b3_2 = new TH1D("M_b1b3_2", "Invariant mass of the higgs candidates; m_{higgs candidate, 13} [GeV];", nbins, ptmin, ptmax);
	M_b1b4_2 = new TH1D("M_b1b4_2", "Invariant mass of the higgs candidates; m_{higgs candidate, 14} [GeV];", nbins, ptmin, ptmax);
	M_b2b3_2 = new TH1D("M_b2b3_2", "Invariant mass of the higgs candidates; m_{higgs candidate, 23} [GeV];", nbins, ptmin, ptmax);
	M_b2b4_2 = new TH1D("M_b2b4_2", "Invariant mass of the higgs candidates; m_{higgs candidate, 24} [GeV];", nbins, ptmin, ptmax);
	M_b3b4_2 = new TH1D("M_b3b4_2", "Invariant mass of the higgs candidates; m_{higgs candidate, 34} [GeV];", nbins, ptmin, ptmax);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_2 = new TH1D("dM_b1b2_b3b4_2", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1234} [GeV];", nbins, dptmin, dptmax);
	dM_b1b3_b2b4_2 = new TH1D("dM_b1b3_b2b4_2", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1324} [GeV];", nbins, dptmin, dptmax);
	dM_b1b4_b2b3_2 = new TH1D("dM_b1b4_b2b3_2", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1423} [GeV];", nbins, dptmin, dptmax);

	combi_selected_2 = new TH1D("combi_selected_2", "Selected combination", 3, 1, 4);
	return;
}
void Draw_InvariantMass_2()
{
	//! higgs's
	if(v2_higgsPt->size() == 2)
	{
		higgs1_2.SetPtEtaPhiM((*v2_higgsPt)[0], (*v2_higgsEta)[0], (*v2_higgsPhi)[0], (*v2_higgsM)[0]);
		higgs2_2.SetPtEtaPhiM((*v2_higgsPt)[1], (*v2_higgsEta)[1], (*v2_higgsPhi)[1], (*v2_higgsM)[1]);
		H1H2_2 = higgs1_2 + higgs2_2;
		
		MH1H2_2->Fill(H1H2_2.M()*1e-3);
		PtH1H2_2->Fill(H1H2_2.Pt()*1e-3);
	}
	//! b's
	if(v2_bPt->size() == 4)
	{
		b1_2.SetPtEtaPhiM((*v2_bPt)[0], (*v2_bEta)[0], (*v2_bPhi)[0], (*v2_bM)[0]);
		b2_2.SetPtEtaPhiM((*v2_bPt)[1], (*v2_bEta)[1], (*v2_bPhi)[1], (*v2_bM)[1]);
		b3_2.SetPtEtaPhiM((*v2_bPt)[2], (*v2_bEta)[2], (*v2_bPhi)[2], (*v2_bM)[2]);
		b4_2.SetPtEtaPhiM((*v2_bPt)[3], (*v2_bEta)[3], (*v2_bPhi)[3], (*v2_bM)[3]);

		b1b2_2 = b1_2 + b2_2;
		b1b3_2 = b1_2 + b3_2;
		b1b4_2 = b1_2 + b4_2;
		b2b3_2 = b2_2 + b3_2;
		b2b4_2 = b2_2 + b4_2;
		b3b4_2 = b3_2 + b4_2;
		
		Mb1b2_2->Fill(b1b2_2.M()*1e-3);
		Mb1b3_2->Fill(b1b3_2.M()*1e-3);
		Mb1b4_2->Fill(b1b4_2.M()*1e-3);
		Mb2b3_2->Fill(b2b3_2.M()*1e-3);
		Mb2b4_2->Fill(b2b4_2.M()*1e-3);
		Mb3b4_2->Fill(b3b4_2.M()*1e-3);
	}
	
	return;
}
//void Fill_InvariantMass_2()
//{
//	Mb1b2_2->Fill(b1b2_2.M()*1e-3);
//	Mb1b3_2->Fill(b1b3_2.M()*1e-3);
//	Mb1b4_2->Fill(b1b4_2.M()*1e-3);
//	Mb2b3_2->Fill(b2b3_2.M()*1e-3);
//	Mb2b4_2->Fill(b2b4_2.M()*1e-3);
//	Mb3b4_2->Fill(b3b4_2.M()*1e-3);
//
//	MH1H2_2->Fill(H1H2_2.M()*1e-3);
//	PtH1H2_2->Fill(H1H2_2.Pt()*1e-3);
//	return;
//}
void Fill_NLeadingJetPtM_2()
{
	jetLPt2->Fill((*v2_jetPt)[0]*1e-3);
	jet2LPt2->Fill((*v2_jetPt)[1]*1e-3);
	jet3LPt2->Fill((*v2_jetPt)[2]*1e-3);
	jet4LPt2->Fill((*v2_jetPt)[3]*1e-3);
	
	jetLM2->Fill( (*v2_jetM)[0]*1e-3);
	jet2LM2->Fill((*v2_jetM)[1]*1e-3);
	jet3LM2->Fill((*v2_jetM)[2]*1e-3);
	jet4LM2->Fill((*v2_jetM)[3]*1e-3);

	return;
}
void Fill_bjetPtM_2(int &nhiggs)
{
	bjetLPt2->Fill( bJ1_2.Pt()*1e-3);
	bjet2LPt2->Fill(bJ2_2.Pt()*1e-3);
	bjet3LPt2->Fill(bJ3_2.Pt()*1e-3);
	bjet4LPt2->Fill(bJ4_2.Pt()*1e-3);

	bjetLM2->Fill( bJ1_2.M()*1e-3);
	bjet2LM2->Fill(bJ2_2.M()*1e-3);
	bjet3LM2->Fill(bJ3_2.M()*1e-3);
	bjet4LM2->Fill(bJ4_2.M()*1e-3);
	
	M_b1b2_2->Fill(bJ1bJ2_2.M()*1e-3);
	M_b1b3_2->Fill(bJ1bJ3_2.M()*1e-3);
	M_b1b4_2->Fill(bJ1bJ4_2.M()*1e-3);
	M_b2b3_2->Fill(bJ2bJ3_2.M()*1e-3);
	M_b2b4_2->Fill(bJ2bJ4_2.M()*1e-3);
	M_b3b4_2->Fill(bJ3bJ4_2.M()*1e-3);

	double dm_12_34 = 0, dm_13_24 = 0, dm_14_23 = 0;
	dm_12_34 = std::fabs(bJ1bJ2_2.M() - bJ3bJ4_2.M())*1e-3;
	dm_13_24 = std::fabs(bJ1bJ3_2.M() - bJ2bJ4_2.M())*1e-3;
	dm_14_23 = std::fabs(bJ1bJ4_2.M() - bJ2bJ3_2.M())*1e-3;
	//dM_b1b2_b3b4_2->Fill(dm_12_34*1e-3);	
	//dM_b1b3_b2b4_2->Fill(dm_13_24*1e-3);	
	//dM_b1b4_b2b3_2->Fill(dm_14_23*1e-3);

	//! Higgs Candidate
	int higgs_candidates = -1;
	int min_diffCombi = 999;
	
	if((std::fabs(bJ1bJ2_2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ3bJ4_2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
		if(dm_12_34 < min_diffCombi) 
		{
			min_diffCombi = dm_12_34;
			higgs_candidates = 1234;
		}
	}

	if((std::fabs(bJ1bJ3_2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ4_2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
		if(dm_13_24 < min_diffCombi) 
		{
			min_diffCombi = dm_13_24;
			higgs_candidates = 1324;
		}
	}

	if((std::fabs(bJ1bJ4_2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ3_2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
		if(dm_14_23 < min_diffCombi)
		{
			min_diffCombi = dm_14_23;
			higgs_candidates = 1423;
		}
	}

	if(higgs_candidates == 1234)
	{
		//if((std::fabs(bJ1bJ2_2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ3bJ4_2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		//{
			combi_selected_2->Fill(1);
			nhiggs++;
			//! Fill four jet pt after all selection
			Ana_bjetLPt2->Fill( bJ1_2.Pt()*1e-3);
			Ana_bjet2LPt2->Fill(bJ2_2.Pt()*1e-3);
			Ana_bjet3LPt2->Fill(bJ3_2.Pt()*1e-3);
			Ana_bjet4LPt2->Fill(bJ4_2.Pt()*1e-3);
			if(bJ1bJ2_2.M() > bJ3bJ4_2.M())
			{
				M_Lhiggs2->Fill(bJ1bJ2_2.M()*1e-3);
				M_NLhiggs2->Fill(bJ3bJ4_2.M()*1e-3);
				Pt_Lhiggs2->Fill(bJ1bJ2_2.Pt()*1e-3);
				Pt_NLhiggs2->Fill(bJ3bJ4_2.Pt()*1e-3);
			
			} 
			else
			{
				M_Lhiggs2->Fill(bJ3bJ4_2.M()*1e-3);
				M_NLhiggs2->Fill(bJ1bJ2_2.M()*1e-3);
				Pt_Lhiggs2->Fill(bJ3bJ4_2.Pt()*1e-3);
				Pt_NLhiggs2->Fill(bJ1bJ2_2.Pt()*1e-3);
				
			}
			RecH1H2_2 = bJ1bJ2_2 + bJ3bJ4_2;
			RecMH1H2_2->Fill(RecH1H2_2.M()*1e-3);
			RecPtH1H2_2->Fill(RecH1H2_2.Pt()*1e-3);
			
			dM_b1b2_b3b4_2->Fill(dm_12_34);	
		//}
	}
	else if(higgs_candidates == 1324)
	{
		//if((std::fabs(bJ1bJ3_2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ4_2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		//{
			combi_selected_2->Fill(2);
			nhiggs++;
			//! Fill four jet pt after all selection
			Ana_bjetLPt2->Fill( bJ1_2.Pt()*1e-3);
			Ana_bjet2LPt2->Fill(bJ2_2.Pt()*1e-3);
			Ana_bjet3LPt2->Fill(bJ3_2.Pt()*1e-3);
			Ana_bjet4LPt2->Fill(bJ4_2.Pt()*1e-3);
			if(bJ1bJ3_2.M() > bJ2bJ4_2.M())
			{
				M_Lhiggs2->Fill(bJ1bJ3_2.M()*1e-3);
				M_NLhiggs2->Fill(bJ2bJ4_2.M()*1e-3);
				Pt_Lhiggs2->Fill(bJ1bJ3_2.Pt()*1e-3);
				Pt_NLhiggs2->Fill(bJ2bJ4_2.Pt()*1e-3);
			
			} 
			else
			{
				M_Lhiggs2->Fill(bJ2bJ4_2.M()*1e-3);
				M_NLhiggs2->Fill(bJ1bJ3_2.M()*1e-3);
				Pt_Lhiggs2->Fill(bJ2bJ4_2.Pt()*1e-3);
				Pt_NLhiggs2->Fill(bJ1bJ3_2.Pt()*1e-3);
				
			}
			RecH1H2_2 = bJ1bJ3_2 + bJ2bJ4_2;
			RecMH1H2_2->Fill(RecH1H2_2.M()*1e-3);
			RecPtH1H2_2->Fill(RecH1H2_2.Pt()*1e-3);
			
			dM_b1b3_b2b4_2->Fill(dm_13_24);	
		//}
	
	}
	else if(higgs_candidates == 1423)
	{
		//if((std::fabs(bJ1bJ4_2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ3_2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		//{
			combi_selected_2->Fill(3);
			nhiggs++;
			//! Fill four jet pt after all selection
			Ana_bjetLPt2->Fill( bJ1_2.Pt()*1e-3);
			Ana_bjet2LPt2->Fill(bJ2_2.Pt()*1e-3);
			Ana_bjet3LPt2->Fill(bJ3_2.Pt()*1e-3);
			Ana_bjet4LPt2->Fill(bJ4_2.Pt()*1e-3);
			if(bJ1bJ4_2.M() > bJ2bJ3_2.M())
			{
				M_Lhiggs2->Fill(bJ1bJ4_2.M()*1e-3);
				M_NLhiggs2->Fill(bJ2bJ3_2.M()*1e-3);
				Pt_Lhiggs2->Fill(bJ1bJ4_2.Pt()*1e-3);
				Pt_NLhiggs2->Fill(bJ2bJ3_2.Pt()*1e-3);
			
			} 
			else
			{
				M_Lhiggs2->Fill(bJ2bJ3_2.M()*1e-3);
				M_NLhiggs2->Fill(bJ1bJ4_2.M()*1e-3);
				Pt_Lhiggs2->Fill(bJ2bJ3_2.Pt()*1e-3);
				Pt_NLhiggs2->Fill(bJ1bJ4_2.Pt()*1e-3);
				
			}
			RecH1H2_2 = bJ1bJ4_2 + bJ2bJ3_2;
			RecMH1H2_2->Fill(RecH1H2_2.M()*1e-3);
			RecPtH1H2_2->Fill(RecH1H2_2.Pt()*1e-3);
			
			dM_b1b4_b2b3_2->Fill(dm_14_23);
		//}
	
	}

	return;
}
void Draw_DiJetInvariantMass_2(int &nb2, int &nhiggs)
{
	v2_bjetPt.clear();
	v2_bjetEta.clear();
	v2_bjetPhi.clear();
	v2_bjetM.clear();
	for(int j = 0; j < v2_tagFlavor->size(); j++)
	{
		if((*v2_tagFlavor)[j] != 5) continue;
		v2_bjetPt.push_back((*v2_jetPt)[j]);
		v2_bjetEta.push_back((*v2_jetEta)[j]);
		v2_bjetPhi.push_back((*v2_jetPhi)[j]);
		v2_bjetM.push_back((*v2_jetM)[j]);

	}
	
	//! b jet's
	if(v2_bjetPt.size() > 3)
	{
		if(v2_bjetPt[0]*1e-3 >= minLeadingPt  && v2_bjetPt[1]*1e-3 >= minSubLeadingPt  && v2_bjetPt[2]*1e-3 >= third_Pt_cut && v2_bjetPt[3]*1e-3 >= default_Pt_cut )
		{
			nb2++;
			bJ1_2.SetPtEtaPhiM(v2_bjetPt[0], v2_bjetEta[0], v2_bjetPhi[0], v2_bjetM[0]);
			bJ2_2.SetPtEtaPhiM(v2_bjetPt[1], v2_bjetEta[1], v2_bjetPhi[1], v2_bjetM[1]);
			bJ3_2.SetPtEtaPhiM(v2_bjetPt[2], v2_bjetEta[2], v2_bjetPhi[2], v2_bjetM[2]);
			bJ4_2.SetPtEtaPhiM(v2_bjetPt[3], v2_bjetEta[3], v2_bjetPhi[3], v2_bjetM[3]);

			bJ1bJ2_2 = bJ1_2 + bJ2_2;
			bJ1bJ3_2 = bJ1_2 + bJ3_2;
			bJ1bJ4_2 = bJ1_2 + bJ4_2;
			bJ2bJ3_2 = bJ2_2 + bJ3_2;
			bJ2bJ4_2 = bJ2_2 + bJ4_2;
			bJ3bJ4_2 = bJ3_2 + bJ4_2;

			Fill_bjetPtM_2(nhiggs);
		}
	}
	return;
}
 
void SetLineWidth2()
{
        MH1H2_2->SetLineWidth(LINE_WIDTH);
        PtH1H2_2->SetLineWidth(LINE_WIDTH);

	Mb1b2_2->SetLineWidth(LINE_WIDTH); 
	Mb1b3_2->SetLineWidth(LINE_WIDTH);
	Mb1b4_2->SetLineWidth(LINE_WIDTH);
	Mb2b3_2->SetLineWidth(LINE_WIDTH);
	Mb2b4_2->SetLineWidth(LINE_WIDTH);
	Mb3b4_2->SetLineWidth(LINE_WIDTH);

	h_NbTags2->SetLineWidth(LINE_WIDTH);
	NSMhiggs2->SetLineWidth(LINE_WIDTH);
	Nbquarks2->SetLineWidth(LINE_WIDTH);
	Njets2->SetLineWidth(LINE_WIDTH);
	higgsPt2->SetLineWidth(LINE_WIDTH);
	higgsNLPt2->SetLineWidth(LINE_WIDTH);
	M_Lhiggs2->SetLineWidth(LINE_WIDTH);
	M_NLhiggs2->SetLineWidth(LINE_WIDTH);
	Pt_Lhiggs2->SetLineWidth(LINE_WIDTH);
	Pt_NLhiggs2->SetLineWidth(LINE_WIDTH);
	RecMH1H2_2->SetLineWidth(LINE_WIDTH);
	RecPtH1H2_2->SetLineWidth(LINE_WIDTH);

	// invariant mass of a pair of b's, ctr = 2.0
	M_b1b2_2->SetLineWidth(LINE_WIDTH);
	M_b1b3_2->SetLineWidth(LINE_WIDTH);
	M_b1b4_2->SetLineWidth(LINE_WIDTH);
	M_b2b3_2->SetLineWidth(LINE_WIDTH);
	M_b2b4_2->SetLineWidth(LINE_WIDTH);
	M_b3b4_2->SetLineWidth(LINE_WIDTH);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_2->SetLineWidth(LINE_WIDTH);
	dM_b1b3_b2b4_2->SetLineWidth(LINE_WIDTH);
	dM_b1b4_b2b3_2->SetLineWidth(LINE_WIDTH);

	jetLM2->SetLineWidth(LINE_WIDTH);
	jet2LM2->SetLineWidth(LINE_WIDTH);
	jet3LM2->SetLineWidth(LINE_WIDTH);
	jet4LM2->SetLineWidth(LINE_WIDTH);

	bjetLM2->SetLineWidth(LINE_WIDTH);
	bjet2LM2->SetLineWidth(LINE_WIDTH);
	bjet3LM2->SetLineWidth(LINE_WIDTH);
	bjet4LM2->SetLineWidth(LINE_WIDTH);

	jetLPt2->SetLineWidth(LINE_WIDTH);
	jet2LPt2->SetLineWidth(LINE_WIDTH);
	jet3LPt2->SetLineWidth(LINE_WIDTH);
	jet4LPt2->SetLineWidth(LINE_WIDTH);

	bjetLPt2->SetLineWidth(LINE_WIDTH);
	bjet2LPt2->SetLineWidth(LINE_WIDTH);
	bjet3LPt2->SetLineWidth(LINE_WIDTH);
	bjet4LPt2->SetLineWidth(LINE_WIDTH);

	bLPt2->SetLineWidth(LINE_WIDTH);
	b2LPt2->SetLineWidth(LINE_WIDTH);
	b3LPt2->SetLineWidth(LINE_WIDTH);
	b4LPt2->SetLineWidth(LINE_WIDTH);

	bCEta2->SetLineWidth(LINE_WIDTH);
	b2CEta2->SetLineWidth(LINE_WIDTH);
	b3CEta2->SetLineWidth(LINE_WIDTH);
	b4CEta2->SetLineWidth(LINE_WIDTH);

	Ana_bjetLPt2->SetLineWidth(LINE_WIDTH);
	Ana_bjet2LPt2->SetLineWidth(LINE_WIDTH);
	Ana_bjet3LPt2->SetLineWidth(LINE_WIDTH);
	Ana_bjet4LPt2->SetLineWidth(LINE_WIDTH);
	return;
}
void Scale_signalHistos2(double norm)
{
        MH1H2_2->Scale(norm);
        PtH1H2_2->Scale(norm);

	Mb1b2_2->Scale(norm); 
	Mb1b3_2->Scale(norm);
	Mb1b4_2->Scale(norm);
	Mb2b3_2->Scale(norm);
	Mb2b4_2->Scale(norm);
	Mb3b4_2->Scale(norm);

	h_NbTags2->Scale(norm);
	NSMhiggs2->Scale(norm);
	Nbquarks2->Scale(norm);
	Njets2->Scale(norm);
	higgsPt2->Scale(norm);
	higgsNLPt2->Scale(norm);
	M_Lhiggs2->Scale(norm);
	M_NLhiggs2->Scale(norm);
	Pt_Lhiggs2->Scale(norm);
	Pt_NLhiggs2->Scale(norm);
	RecMH1H2_2->Scale(norm);
	RecPtH1H2_2->Scale(norm);

	// invariant mass of a pair of b's, ctr = 2.0
	M_b1b2_2->Scale(norm);
	M_b1b3_2->Scale(norm);
	M_b1b4_2->Scale(norm);
	M_b2b3_2->Scale(norm);
	M_b2b4_2->Scale(norm);
	M_b3b4_2->Scale(norm);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_2->Scale(norm);
	dM_b1b3_b2b4_2->Scale(norm);
	dM_b1b4_b2b3_2->Scale(norm);

	jetLM2->Scale(norm);
	jet2LM2->Scale(norm);
	jet3LM2->Scale(norm);
	jet4LM2->Scale(norm);

	bjetLM2->Scale(norm);
	bjet2LM2->Scale(norm);
	bjet3LM2->Scale(norm);
	bjet4LM2->Scale(norm);

	jetLPt2->Scale(norm);
	jet2LPt2->Scale(norm);
	jet3LPt2->Scale(norm);
	jet4LPt2->Scale(norm);

	bjetLPt2->Scale(norm);
	bjet2LPt2->Scale(norm);
	bjet3LPt2->Scale(norm);
	bjet4LPt2->Scale(norm);

	bLPt2->Scale(norm);
	b2LPt2->Scale(norm);
	b3LPt2->Scale(norm);
	b4LPt2->Scale(norm);

	bCEta2->Scale(norm);
	b2CEta2->Scale(norm);
	b3CEta2->Scale(norm);
	b4CEta2->Scale(norm);

	return;
}
void Set_NleadingJetColors_2()
{

	bjetLM2->SetLineColor(kOrange);
	bjet2LM2->SetLineColor(kBlack);
	bjet3LM2->SetLineColor(kRed);
	bjet4LM2->SetLineColor(kGreen);
	jetLM2->SetLineColor(kOrange);
	jet2LM2->SetLineColor(kBlack);
	jet3LM2->SetLineColor(kRed);
	jet4LM2->SetLineColor(kGreen);
	bjetLPt2->SetLineColor(kOrange);
	bjet2LPt2->SetLineColor(kBlack);
	bjet3LPt2->SetLineColor(kRed);
	bjet4LPt2->SetLineColor(kGreen);
	jetLPt2->SetLineColor(kOrange);
	jet2LPt2->SetLineColor(kBlack);
	jet3LPt2->SetLineColor(kRed);
	jet4LPt2->SetLineColor(kGreen);
	return;
}
void Set_bquark_lambdaColors_2()
{

	M_Lhiggs2->SetLineColor(kBlue);
	M_NLhiggs2->SetLineColor(kBlue);
	Pt_Lhiggs2->SetLineColor(kBlue);
	Pt_NLhiggs2->SetLineColor(kBlue);
	RecMH1H2_2->SetLineColor(kBlue);
	RecPtH1H2_2->SetLineColor(kBlue);
	
	bjetLM2->SetLineColor(kBlue);
	bjet2LM2->SetLineColor(kBlue);
	bjet3LM2->SetLineColor(kBlue);
	bjet4LM2->SetLineColor(kBlue);
	jetLM2->SetLineColor(kBlue);
	jet2LM2->SetLineColor(kBlue);
	jet3LM2->SetLineColor(kBlue);
	jet4LM2->SetLineColor(kBlue);
	jetLPt2->SetLineColor(kBlue);
	jet2LPt2->SetLineColor(kBlue);
	jet3LPt2->SetLineColor(kBlue);
	jet4LPt2->SetLineColor(kBlue);
	bjetLPt2->SetLineColor(kBlue);
	bjet2LPt2->SetLineColor(kBlue);
	bjet3LPt2->SetLineColor(kBlue);
	bjet4LPt2->SetLineColor(kBlue);
	bLPt2->SetLineColor(kBlue);
	b2LPt2->SetLineColor(kBlue);
	b3LPt2->SetLineColor(kBlue);
	b4LPt2->SetLineColor(kBlue);
	bCEta2->SetLineColor(kBlue);
	b2CEta2->SetLineColor(kBlue);
	b3CEta2->SetLineColor(kBlue);
	b4CEta2->SetLineColor(kBlue);
	Ana_bjetLPt2->SetLineColor(kBlue);
	Ana_bjet2LPt2->SetLineColor(kBlue);
	Ana_bjet3LPt2->SetLineColor(kBlue);
	Ana_bjet4LPt2->SetLineColor(kBlue);
	return;
}
void Draw_Number_bTags_2()
{
	h_NbTags2 = new TH1D("h_NbTags2", "number of b tagged jets, #lambda =2.0", 6, 0, 6);
	t2->Draw("Nbtags>>h_NbTags2");
	return;
}


