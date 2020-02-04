void ClearLorentzVectors__2()
{
	//! clear the Lorentz vectors
	higgs1__2 = TLorentzVector();
	higgs2__2 = TLorentzVector();
	H1H2__2 = TLorentzVector();

	b1__2 = TLorentzVector();
	b2__2 = TLorentzVector();
	b3__2 = TLorentzVector();
	b4__2 = TLorentzVector();

	b1b2__2 = TLorentzVector();
	b1b3__2 = TLorentzVector();
	b1b4__2 = TLorentzVector();
	b2b3__2 = TLorentzVector();
	b2b4__2 = TLorentzVector();
	b3b4__2 = TLorentzVector();
	
	bJ1__2 = TLorentzVector(); 
	bJ2__2 = TLorentzVector(); 
	bJ3__2 = TLorentzVector(); 
	bJ4__2 = TLorentzVector(); 
	bJ1bJ2__2 = TLorentzVector();
	bJ1bJ3__2 = TLorentzVector();
	bJ1bJ4__2 = TLorentzVector();
	bJ2bJ3__2 = TLorentzVector();
	bJ2bJ4__2 = TLorentzVector();
	bJ3bJ4__2 = TLorentzVector();

	RecH1H2__2 = TLorentzVector();
	return;

}
void fetch_histos__2()
{

	bLPt_2  = (TH1D*)f_2->Get("hbPt_Lpt");
	b2LPt_2 = (TH1D*)f_2->Get("hbPt_NLpt");
	b3LPt_2 = (TH1D*)f_2->Get("hbPt_NNLpt");
	b4LPt_2 = (TH1D*)f_2->Get("hbPt_NNNLpt");
	
	bCEta_2  = (TH1D*)f_2->Get("hbEta_Ceta");
	b2CEta_2 = (TH1D*)f_2->Get("hbEta_NCeta");
	b3CEta_2 = (TH1D*)f_2->Get("hbEta_NNCeta");
	b4CEta_2 = (TH1D*)f_2->Get("hbEta_NNNCeta");
	
	return;
}
void Draw_b_jetPt__2()
{
	t_2->Draw("bJetLPt>>bjetLPt_2");
	t_2->Draw("bJetNLPt>>bjet2LPt_2");
	t_2->Draw("bJetNNLPt>>bjet3LPt_2");
	t_2->Draw("bJetNNNLPt>>bjet4LPt_2");
	
	return;
}
void Draw_higgsPt__2()
{
	
	t_2->Draw("higgsLPt*1e-3>>higgsPt_2");
	t_2->Draw("higgsNLPt*1e-3>>higgsNLPt_2");
	
	return;
}
void Draw_Nparticles__2()
{
	int nbins = 6, nbins_1 = 20;
	double nmin = 0, nmax = 6, nmax_1 = 20;
	NSMhiggs_2 = new TH1D("NSMhiggs_2", "number of higgs", nbins, nmin, nmax);
	Nbquarks_2 = new TH1D("Nbquarks_2", "number of b quarks", nbins, nmin, nmax);
	Njets_2 = new TH1D("Njets_2", "number of jets", nbins_1, nmin, nmax_1);
	t_2->Draw("NSMhiggs>>NSMhiggs_2");
	t_2->Draw("Nbquarks>>Nbquarks_2");
	t_2->Draw("Njets>>Njets_2");
	NSMhiggs_2->SetLineColor(kGreen);
	Nbquarks_2->SetLineColor(kGreen);
	Njets_2->SetLineColor(kGreen);
	return;
}
void fetch_TTrees__2()
{
	t_2  = (TTree*)f_2->Get("glob_jet");
	t_2->SetBranchStatus("*",0);
	t_2->SetBranchStatus("higgsLPt",1);
	t_2->SetBranchStatus("higgsNLPt",1);
	t_2->SetBranchStatus("NSMhiggs",1);
	t_2->SetBranchStatus("Nbquarks",1);
	t_2->SetBranchStatus("Njets",1);
	t_2->SetBranchStatus("jetPt",1);
	t_2->SetBranchStatus("jetEta",1);
	t_2->SetBranchStatus("jetPhi",1);
	t_2->SetBranchStatus("jetM",1);
	t_2->SetBranchStatus("btaggedFlavor",1);
	t_2->SetBranchStatus("bJetLPt",1);
	t_2->SetBranchStatus("bJetNLPt",1);
	t_2->SetBranchStatus("bJetNNLPt",1);
	t_2->SetBranchStatus("bJetNNNLPt",1);
	t_2->SetBranchStatus("Nbtags",1);
	t_2->SetBranchStatus("v_higgsPt", 1);
	t_2->SetBranchStatus("v_higgsEta",1);
	t_2->SetBranchStatus("v_higgsPhi",1);
	t_2->SetBranchStatus("v_higgsM",  1);
	t_2->SetBranchStatus("v_bPt", 1);
	t_2->SetBranchStatus("v_bEta",1);
	t_2->SetBranchStatus("v_bPhi",1);
	t_2->SetBranchStatus("v_bM",  1);
	
	t_2->SetBranchAddress("jetPt", &v_2_jetPt);
	t_2->SetBranchAddress("jetEta", &v_2_jetEta);
	t_2->SetBranchAddress("jetPhi", &v_2_jetPhi);
	t_2->SetBranchAddress("jetM", &v_2_jetM);
	t_2->SetBranchAddress("btaggedFlavor", &v_2_tagFlavor);
	t_2->SetBranchAddress("Nbtags",&n_2_btags);
	t_2->SetBranchAddress("v_higgsPt", &v_2_higgsPt);
	t_2->SetBranchAddress("v_higgsEta",&v_2_higgsEta);
	t_2->SetBranchAddress("v_higgsPhi",&v_2_higgsPhi);
	t_2->SetBranchAddress("v_higgsM",  &v_2_higgsM);
	t_2->SetBranchAddress("v_bPt", &v_2_bPt);
	t_2->SetBranchAddress("v_bEta",&v_2_bEta);
	t_2->SetBranchAddress("v_bPhi",&v_2_bPhi);
	t_2->SetBranchAddress("v_bM",  &v_2_bM);

	return;
}
void Set_higgsPtProps__2()
{
	int nbins = 60;
	float ptmin = 0;
	float ptmax = 600;
	float Mmin = 200;
	float Mmax = 1400;
	//! truth leading and sub leading higgs Pt
	higgsPt_2  = new TH1D("higgsPt_2",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt_2->SetLineColor(kGreen);
	higgsPt_2->SetLineWidth(LINE_WIDTH);
	
	higgsNLPt_2  = new TH1D("higgsNLPt_2",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsNLPt_2->SetLineColor(kGreen);
	higgsNLPt_2->SetLineWidth(LINE_WIDTH);
	//! truth leading and sub leading higgs inv mass
	higgsL_M_2  = new TH1D("higgsL_M_2",  "Invariant higgs mass;m_{rec, leading higgs} [GeV];", nbins, ptmin, ptmax);
	higgsL_M_2->SetLineColor(kGreen);
	higgsL_M_2->SetLineWidth(LINE_WIDTH);
	
	higgsNL_M_2  = new TH1D("higgsNL_M_2",  "Invariant higgs mass;m_{rec, sub leading higgs} [GeV];", nbins, ptmin, ptmax);
	higgsNL_M_2->SetLineColor(kGreen);
	higgsNL_M_2->SetLineWidth(LINE_WIDTH);
	//! truth Inv mass of the di-higgs system
	MH1H2__2  = new TH1D("MH1H2__2",  "Invariant di-higgs mass;m_{truth, h1,h2} [GeV];", nbins, Mmin, Mmax);
	MH1H2__2->SetLineColor(kGreen);
	MH1H2__2->SetLineWidth(LINE_WIDTH);
	//! truth Pt of the di-higgs system
	PtH1H2__2  = new TH1D("PtH1H2__2",  "Transverse momentum of the di-higgs system;p_{T, truth, h1,h2} [GeV/c];", nbins, ptmin, ptmax);
	PtH1H2__2->SetLineColor(kGreen);
	PtH1H2__2->SetLineWidth(LINE_WIDTH);

	
	//! reconstructed leading and sub leading higgs pt
	Pt_Lhiggs_2  = new TH1D("Pt_Lhiggs_2",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	Pt_NLhiggs_2  = new TH1D("Pt_NLhiggs_2",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	//! reconstructed leading and sub leading inv mass
	M_Lhiggs_2  = new TH1D("M_Lhiggs_2",  "Invariant higgs mass;m_{rec, leading higgs} [GeV];", nbins, ptmin, ptmax);
	M_NLhiggs_2  = new TH1D("M_NLhiggs_2",  "Invariant higgs mass;m_{rec, sub leading higgs} [GeV];", nbins, ptmin, ptmax);
	
	//! reconstructed Inv mass of the di-higgs system
	RecMH1H2__2  = new TH1D("RecMH1H2__2",  "Invariant di-higgs mass;m_{truth, h1,h2} [GeV];", nbins, Mmin, Mmax);
	//! reconstructed Pt of the di-higgs system
	RecPtH1H2__2  = new TH1D("RecPtH1H2__2",  "Transverse momentum of the di-higgs system;p_{T, truth, h1,h2} [GeV/c];", nbins, ptmin, ptmax);

	// invariant mass of a pair of b's, ctr = -2.0
	Mb1b2__2 = new TH1D("Mb1b2__2", "#lambda = -2.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 12} [GeV];", nbins, ptmin, ptmax);
	Mb1b3__2 = new TH1D("Mb1b3__2", "#lambda = -2.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 13} [GeV];", nbins, ptmin, ptmax);
	Mb1b4__2 = new TH1D("Mb1b4__2", "#lambda = -2.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 14} [GeV];", nbins, ptmin, ptmax);
	Mb2b3__2 = new TH1D("Mb2b3__2", "#lambda = -2.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 23} [GeV];", nbins, ptmin, ptmax);
	Mb2b4__2 = new TH1D("Mb2b4__2", "#lambda = -2.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 24} [GeV];", nbins, ptmin, ptmax);
	Mb3b4__2 = new TH1D("Mb3b4__2", "#lambda = -2.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 34} [GeV];", nbins, ptmin, ptmax);
	return;
}

void Set_FinalJetPtProps__2()
{
	int nbins = 15; 
	Int_t nbinsMinus = nbins - 1; 
	Float_t pt_bins[15] = {20., 30., 40., 50., 60., 70., 80., 90., 100., 110., 120., 130., 140., 150., 500.};
	//b-jet leading Pt
	Ana_bjetLPt_2  = new TH1D("Ana_bjetLPt_2", "Jet p_{T} after analysis cuts; p_{T, leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	//b-jet 2nd leading Pt
	Ana_bjet2LPt_2  = new TH1D("Ana_bjet2LPt_2", "Jet p_{T} after analysis cuts; p_{T, sub leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	//b-jet 3rd leading Pt
	Ana_bjet3LPt_2  = new TH1D("Ana_bjet3LPt_2", "Jet p_{T} after analysis cuts; p_{T, 3rd leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	//b-jet 4th leading Pt
	Ana_bjet4LPt_2  = new TH1D("Ana_bjet4LPt_2", "Jet p_{T} after analysis cuts; p_{T, 4th leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	return;
}
void Set_jetPtProps__2()
{
	int nbins = 60;
	float ptmin = 0;
	float ptmax = 300;
	float dptmin = 0;
	float dptmax = 300;
	//b-jet leading Pt
	bjetLPt_2  = new TH1D("bjetLPt_2", "b-tagged Jet p_{t}; p_{t, leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 2nd leading Pt
	bjet2LPt_2  = new TH1D("bjet2LPt_2", "b-tagged Jet p_{t}; p_{t, sub leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 3rd leading Pt
	bjet3LPt_2  = new TH1D("bjet3LPt_2", "b-tagged Jet p_{t}; p_{t, 3rd leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 4th leading Pt
	bjet4LPt_2  = new TH1D("bjet4LPt_2", "b-tagged Jet p_{t}; p_{t, 4th leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	
	//jet leading Pt
	jetLPt_2  = new TH1D("jetLPt_2", "Jet p_{t}; p_{t, leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 2nd leading Pt
	jet2LPt_2  = new TH1D("jet2LPt_2", "Jet p_{t}; p_{t, sub leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 3rd leading Pt
	jet3LPt_2  = new TH1D("jet3LPt_2", "Jet p_{t}; p_{t, 3rd leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 4th leading Pt
	jet4LPt_2  = new TH1D("jet4LPt_2", "Jet p_{t}; p_{t, 4th leading jet} [GeV/c];", nbins, ptmin, ptmax);

	//jet leading M
	jetLM_2  = new TH1D("jetLM_2", "Jet invariant mass; m_{ leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 2nd leading M
	jet2LM_2  = new TH1D("jet2LM_2", "Jet invariant mass; m_{ sub leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 3rd leading M
	jet3LM_2  = new TH1D("jet3LM_2", "Jet invariant mass; m_{ 3rd leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 4th leading M
	jet4LM_2  = new TH1D("jet4LM_2", "Jet invariant mass; m_{ 4th leading jet} [GeV];", nbins, ptmin, ptmax);
	
	//bjet leading M
	bjetLM_2  = new TH1D("bjetLM_2", "Jet invariant mass; m_{ leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 2nd leading M
	bjet2LM_2  = new TH1D("bjet2LM_2", "Jet invariant mass; m_{ sub leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 3rd leading M
	bjet3LM_2  = new TH1D("bjet3LM_2", "Jet invariant mass; m_{ 3rd leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 4th leading M
	bjet4LM_2  = new TH1D("bjet4LM_2", "Jet invariant mass; m_{ 4th leading bjet} [GeV];", nbins, ptmin, ptmax);
	
	// invariant mass of a pair of b's, ctr = 1.0
	M_b1b2__2 = new TH1D("M_b1b2__2", "Invariant mass of the higgs candidates; m_{higgs candidate, 12} [GeV];", nbins, ptmin, ptmax);
	M_b1b3__2 = new TH1D("M_b1b3__2", "Invariant mass of the higgs candidates; m_{higgs candidate, 13} [GeV];", nbins, ptmin, ptmax);
	M_b1b4__2 = new TH1D("M_b1b4__2", "Invariant mass of the higgs candidates; m_{higgs candidate, 14} [GeV];", nbins, ptmin, ptmax);
	M_b2b3__2 = new TH1D("M_b2b3__2", "Invariant mass of the higgs candidates; m_{higgs candidate, 23} [GeV];", nbins, ptmin, ptmax);
	M_b2b4__2 = new TH1D("M_b2b4__2", "Invariant mass of the higgs candidates; m_{higgs candidate, 24} [GeV];", nbins, ptmin, ptmax);
	M_b3b4__2 = new TH1D("M_b3b4__2", "Invariant mass of the higgs candidates; m_{higgs candidate, 34} [GeV];", nbins, ptmin, ptmax);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4__2 = new TH1D("dM_b1b2_b3b4__2", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1234} [GeV];", nbins, dptmin, dptmax);
	dM_b1b3_b2b4__2 = new TH1D("dM_b1b3_b2b4__2", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1324} [GeV];", nbins, dptmin, dptmax);
	dM_b1b4_b2b3__2 = new TH1D("dM_b1b4_b2b3__2", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1423} [GeV];", nbins, dptmin, dptmax);

	combi_selected__2 = new TH1D("combi_selected__2", "Selected combination", 3, 1, 4);
	return;
}
void Draw_InvariantMass__2()
{
	//! higgs's
	if(v_2_higgsPt->size() == 2)
	{
		higgs1__2.SetPtEtaPhiM((*v_2_higgsPt)[0], (*v_2_higgsEta)[0], (*v_2_higgsPhi)[0], (*v_2_higgsM)[0]);
		higgs2__2.SetPtEtaPhiM((*v_2_higgsPt)[1], (*v_2_higgsEta)[1], (*v_2_higgsPhi)[1], (*v_2_higgsM)[1]);
		H1H2__2 = higgs1__2 + higgs2__2;
		
		MH1H2__2->Fill(H1H2__2.M()*1e-3);
		PtH1H2__2->Fill(H1H2__2.Pt()*1e-3);
	}
	//! b's
	if(v_2_bPt->size() == 4)
	{
		b1__2.SetPtEtaPhiM((*v_2_bPt)[0], (*v_2_bEta)[0], (*v_2_bPhi)[0], (*v_2_bM)[0]);
		b2__2.SetPtEtaPhiM((*v_2_bPt)[1], (*v_2_bEta)[1], (*v_2_bPhi)[1], (*v_2_bM)[1]);
		b3__2.SetPtEtaPhiM((*v_2_bPt)[2], (*v_2_bEta)[2], (*v_2_bPhi)[2], (*v_2_bM)[2]);
		b4__2.SetPtEtaPhiM((*v_2_bPt)[3], (*v_2_bEta)[3], (*v_2_bPhi)[3], (*v_2_bM)[3]);

		b1b2__2 = b1__2 + b2__2;
		b1b3__2 = b1__2 + b3__2;
		b1b4__2 = b1__2 + b4__2;
		b2b3__2 = b2__2 + b3__2;
		b2b4__2 = b2__2 + b4__2;
		b3b4__2 = b3__2 + b4__2;
		
		Mb1b2__2->Fill(b1b2__2.M()*1e-3);
		Mb1b3__2->Fill(b1b3__2.M()*1e-3);
		Mb1b4__2->Fill(b1b4__2.M()*1e-3);
		Mb2b3__2->Fill(b2b3__2.M()*1e-3);
		Mb2b4__2->Fill(b2b4__2.M()*1e-3);
		Mb3b4__2->Fill(b3b4__2.M()*1e-3);
	}

	return;
}
//void Fill_InvariantMass__2()
//{
//	Mb1b2__2->Fill(b1b2__2.M()*1e-3);
//	Mb1b3__2->Fill(b1b3__2.M()*1e-3);
//	Mb1b4__2->Fill(b1b4__2.M()*1e-3);
//	Mb2b3__2->Fill(b2b3__2.M()*1e-3);
//	Mb2b4__2->Fill(b2b4__2.M()*1e-3);
//	Mb3b4__2->Fill(b3b4__2.M()*1e-3);
//
//	MH1H2__2->Fill(H1H2__2.M()*1e-3);
//	PtH1H2__2->Fill(H1H2__2.Pt()*1e-3);
//	return;
//}
void Fill_NLeadingJetPtM__2()
{
	jetLPt_2->Fill((*v_2_jetPt)[0]*1e-3);
	jet2LPt_2->Fill((*v_2_jetPt)[1]*1e-3);
	jet3LPt_2->Fill((*v_2_jetPt)[2]*1e-3);
	jet4LPt_2->Fill((*v_2_jetPt)[3]*1e-3);
	
	jetLM_2->Fill( (*v_2_jetM)[0]*1e-3);
	jet2LM_2->Fill((*v_2_jetM)[1]*1e-3);
	jet3LM_2->Fill((*v_2_jetM)[2]*1e-3);
	jet4LM_2->Fill((*v_2_jetM)[3]*1e-3);

	return;
}
void Fill_bjetPtM__2(int &nhiggs)
{
	bjetLPt_2->Fill( bJ1__2.Pt()*1e-3);
	bjet2LPt_2->Fill(bJ2__2.Pt()*1e-3);
	bjet3LPt_2->Fill(bJ3__2.Pt()*1e-3);
	bjet4LPt_2->Fill(bJ4__2.Pt()*1e-3);

	bjetLM_2->Fill( bJ1__2.M()*1e-3);
	bjet2LM_2->Fill(bJ2__2.M()*1e-3);
	bjet3LM_2->Fill(bJ3__2.M()*1e-3);
	bjet4LM_2->Fill(bJ4__2.M()*1e-3);
	
	M_b1b2__2->Fill(bJ1bJ2__2.M()*1e-3);
	M_b1b3__2->Fill(bJ1bJ3__2.M()*1e-3);
	M_b1b4__2->Fill(bJ1bJ4__2.M()*1e-3);
	M_b2b3__2->Fill(bJ2bJ3__2.M()*1e-3);
	M_b2b4__2->Fill(bJ2bJ4__2.M()*1e-3);
	M_b3b4__2->Fill(bJ3bJ4__2.M()*1e-3);

	double dm_12_34 = 0, dm_13_24 = 0, dm_14_23 = 0;
	dm_12_34 = std::fabs(bJ1bJ2__2.M() - bJ3bJ4__2.M())*1e-3;
	dm_13_24 = std::fabs(bJ1bJ3__2.M() - bJ2bJ4__2.M())*1e-3;
	dm_14_23 = std::fabs(bJ1bJ4__2.M() - bJ2bJ3__2.M())*1e-3;
	//dM_b1b2_b3b4__2->Fill(dm_12_34*1e-3);	
	//dM_b1b3_b2b4__2->Fill(dm_13_24*1e-3);	
	//dM_b1b4_b2b3__2->Fill(dm_14_23*1e-3);

	//! Higgs Candidate
	int higgs_candidates = -1;
	int min_diffCombi = 999;
	if((std::fabs(bJ1bJ2__2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ3bJ4__2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
		if(dm_12_34 < min_diffCombi) 
		{
			min_diffCombi = dm_12_34;
			higgs_candidates = 1234;
		}
	}

	if((std::fabs(bJ1bJ3__2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ4__2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
		if(dm_13_24 < min_diffCombi) 
		{
			min_diffCombi = dm_13_24;
			higgs_candidates = 1324;
		}
	}
	if((std::fabs(bJ1bJ4__2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ3__2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
		if(dm_14_23 < min_diffCombi)
		{
			min_diffCombi = dm_14_23;
			higgs_candidates = 1423;
		}
	}

	if(higgs_candidates == 1234)
	{
		//if((std::fabs(bJ1bJ2__2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ3bJ4__2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		//{
			combi_selected__2->Fill(1);
			nhiggs++;
			//! Fill four jet pt after all selection
			Ana_bjetLPt_2->Fill( bJ1__2.Pt()*1e-3);
			Ana_bjet2LPt_2->Fill(bJ2__2.Pt()*1e-3);
			Ana_bjet3LPt_2->Fill(bJ3__2.Pt()*1e-3);
			Ana_bjet4LPt_2->Fill(bJ4__2.Pt()*1e-3);
			if(bJ1bJ2__2.M() > bJ3bJ4__2.M())
			{
				M_Lhiggs_2->Fill(bJ1bJ2__2.M()*1e-3);
				M_NLhiggs_2->Fill(bJ3bJ4__2.M()*1e-3);
				Pt_Lhiggs_2->Fill(bJ1bJ2__2.Pt()*1e-3);
				Pt_NLhiggs_2->Fill(bJ3bJ4__2.Pt()*1e-3);
			
			} 
			else
			{
				M_Lhiggs_2->Fill(bJ3bJ4__2.M()*1e-3);
				M_NLhiggs_2->Fill(bJ1bJ2__2.M()*1e-3);
				Pt_Lhiggs_2->Fill(bJ3bJ4__2.Pt()*1e-3);
				Pt_NLhiggs_2->Fill(bJ1bJ2__2.Pt()*1e-3);
				
			}
			RecH1H2__2 = bJ1bJ2__2 + bJ3bJ4__2;
			RecMH1H2__2->Fill(RecH1H2__2.M()*1e-3);
			RecPtH1H2__2->Fill(RecH1H2__2.Pt()*1e-3);
			
			dM_b1b2_b3b4__2->Fill(dm_12_34);	
		//}
	}
	else if(higgs_candidates == 1324)
	{
		//if((std::fabs(bJ1bJ3__2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ4__2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		//{
			combi_selected__2->Fill(2);
			nhiggs++;
			//! Fill four jet pt after all selection
			Ana_bjetLPt_2->Fill( bJ1__2.Pt()*1e-3);
			Ana_bjet2LPt_2->Fill(bJ2__2.Pt()*1e-3);
			Ana_bjet3LPt_2->Fill(bJ3__2.Pt()*1e-3);
			Ana_bjet4LPt_2->Fill(bJ4__2.Pt()*1e-3);
			if(bJ1bJ3__2.M() > bJ2bJ4__2.M())
			{
				M_Lhiggs_2->Fill(bJ1bJ3__2.M()*1e-3);
				M_NLhiggs_2->Fill(bJ2bJ4__2.M()*1e-3);
				Pt_Lhiggs_2->Fill(bJ1bJ3__2.Pt()*1e-3);
				Pt_NLhiggs_2->Fill(bJ2bJ4__2.Pt()*1e-3);
			
			} 
			else
			{
				M_Lhiggs_2->Fill(bJ2bJ4__2.M()*1e-3);
				M_NLhiggs_2->Fill(bJ1bJ3__2.M()*1e-3);
				Pt_Lhiggs_2->Fill(bJ2bJ4__2.Pt()*1e-3);
				Pt_NLhiggs_2->Fill(bJ1bJ3__2.Pt()*1e-3);
				
			}
			RecH1H2__2 = bJ1bJ3__2 + bJ2bJ4__2;
			RecMH1H2__2->Fill(RecH1H2__2.M()*1e-3);
			RecPtH1H2__2->Fill(RecH1H2__2.Pt()*1e-3);
			
			dM_b1b3_b2b4__2->Fill(dm_13_24);	
		//}
	
	}
	else if(higgs_candidates == 1423)
	{
		//if((std::fabs(bJ1bJ4__2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ3__2.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		//{
			combi_selected__2->Fill(3);
			nhiggs++;
			//! Fill four jet pt after all selection
			Ana_bjetLPt_2->Fill( bJ1__2.Pt()*1e-3);
			Ana_bjet2LPt_2->Fill(bJ2__2.Pt()*1e-3);
			Ana_bjet3LPt_2->Fill(bJ3__2.Pt()*1e-3);
			Ana_bjet4LPt_2->Fill(bJ4__2.Pt()*1e-3);
			if(bJ1bJ4__2.M() > bJ2bJ3__2.M())
			{
				M_Lhiggs_2->Fill(bJ1bJ4__2.M()*1e-3);
				M_NLhiggs_2->Fill(bJ2bJ3__2.M()*1e-3);
				Pt_Lhiggs_2->Fill(bJ1bJ4__2.Pt()*1e-3);
				Pt_NLhiggs_2->Fill(bJ2bJ3__2.Pt()*1e-3);
			
			} 
			else
			{
				M_Lhiggs_2->Fill(bJ2bJ3__2.M()*1e-3);
				M_NLhiggs_2->Fill(bJ1bJ4__2.M()*1e-3);
				Pt_Lhiggs_2->Fill(bJ2bJ3__2.Pt()*1e-3);
				Pt_NLhiggs_2->Fill(bJ1bJ4__2.Pt()*1e-3);
				
			}
			RecH1H2__2 = bJ1bJ4__2 + bJ2bJ3__2;
			RecMH1H2__2->Fill(RecH1H2__2.M()*1e-3);
			RecPtH1H2__2->Fill(RecH1H2__2.Pt()*1e-3);
			
			dM_b1b4_b2b3__2->Fill(dm_14_23);
		//}
	
	}

	return;
}
void Draw_DiJetInvariantMass__2(int &nb_2, int &nhiggs)
{
	v_2_bjetPt.clear();
	v_2_bjetEta.clear();
	v_2_bjetPhi.clear();
	v_2_bjetM.clear();
	for(int j = 0; j < v_2_tagFlavor->size(); j++)
	{
		if((*v_2_tagFlavor)[j] != 5) continue;
		v_2_bjetPt.push_back((*v_2_jetPt)[j]);
		v_2_bjetEta.push_back((*v_2_jetEta)[j]);
		v_2_bjetPhi.push_back((*v_2_jetPhi)[j]);
		v_2_bjetM.push_back((*v_2_jetM)[j]);

	}
	
	//! b jet's
	if(v_2_bjetPt.size() > 3)
	{
		if(v_2_bjetPt[0]*1e-3 >= minLeadingPt  && v_2_bjetPt[1]*1e-3 >= minSubLeadingPt  && v_2_bjetPt[2]*1e-3 >= third_Pt_cut && v_2_bjetPt[3]*1e-3 >= default_Pt_cut )
		{
			nb_2++;
			bJ1__2.SetPtEtaPhiM(v_2_bjetPt[0], v_2_bjetEta[0], v_2_bjetPhi[0], v_2_bjetM[0]);
			bJ2__2.SetPtEtaPhiM(v_2_bjetPt[1], v_2_bjetEta[1], v_2_bjetPhi[1], v_2_bjetM[1]);
			bJ3__2.SetPtEtaPhiM(v_2_bjetPt[2], v_2_bjetEta[2], v_2_bjetPhi[2], v_2_bjetM[2]);
			bJ4__2.SetPtEtaPhiM(v_2_bjetPt[3], v_2_bjetEta[3], v_2_bjetPhi[3], v_2_bjetM[3]);

			bJ1bJ2__2 = bJ1__2 + bJ2__2;
			bJ1bJ3__2 = bJ1__2 + bJ3__2;
			bJ1bJ4__2 = bJ1__2 + bJ4__2;
			bJ2bJ3__2 = bJ2__2 + bJ3__2;
			bJ2bJ4__2 = bJ2__2 + bJ4__2;
			bJ3bJ4__2 = bJ3__2 + bJ4__2;

			Fill_bjetPtM__2(nhiggs);
		}
	}
	return;
}

void SetLineWidth_2() 
{

	MH1H2__2->SetLineWidth(LINE_WIDTH); 
	PtH1H2__2->SetLineWidth(LINE_WIDTH); 

	Mb1b2__2->SetLineWidth(LINE_WIDTH); 
	Mb1b3__2->SetLineWidth(LINE_WIDTH);
	Mb1b4__2->SetLineWidth(LINE_WIDTH);
	Mb2b3__2->SetLineWidth(LINE_WIDTH);
	Mb2b4__2->SetLineWidth(LINE_WIDTH);
	Mb3b4__2->SetLineWidth(LINE_WIDTH);

	h_NbTags_2->SetLineWidth(LINE_WIDTH);
	NSMhiggs_2->SetLineWidth(LINE_WIDTH);
	Nbquarks_2->SetLineWidth(LINE_WIDTH);
	Njets_2->SetLineWidth(LINE_WIDTH);
	higgsPt_2->SetLineWidth(LINE_WIDTH);
	higgsNLPt_2->SetLineWidth(LINE_WIDTH);
	M_Lhiggs_2->SetLineWidth(LINE_WIDTH);
	M_NLhiggs_2->SetLineWidth(LINE_WIDTH);
	Pt_Lhiggs_2->SetLineWidth(LINE_WIDTH);
	Pt_NLhiggs_2->SetLineWidth(LINE_WIDTH);
	RecMH1H2__2->SetLineWidth(LINE_WIDTH);
	RecPtH1H2__2->SetLineWidth(LINE_WIDTH);

	// invariant mass of a pair of b's, ctr = -2.0
	M_b1b2__2->SetLineWidth(LINE_WIDTH);
	M_b1b3__2->SetLineWidth(LINE_WIDTH);
	M_b1b4__2->SetLineWidth(LINE_WIDTH);
	M_b2b3__2->SetLineWidth(LINE_WIDTH);
	M_b2b4__2->SetLineWidth(LINE_WIDTH);
	M_b3b4__2->SetLineWidth(LINE_WIDTH);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4__2->SetLineWidth(LINE_WIDTH);
	dM_b1b3_b2b4__2->SetLineWidth(LINE_WIDTH);
	dM_b1b4_b2b3__2->SetLineWidth(LINE_WIDTH);

	jetLM_2->SetLineWidth(LINE_WIDTH);
	jet2LM_2->SetLineWidth(LINE_WIDTH);
	jet3LM_2->SetLineWidth(LINE_WIDTH);
	jet4LM_2->SetLineWidth(LINE_WIDTH);

	bjetLM_2->SetLineWidth(LINE_WIDTH);
	bjet2LM_2->SetLineWidth(LINE_WIDTH);
	bjet3LM_2->SetLineWidth(LINE_WIDTH);
	bjet4LM_2->SetLineWidth(LINE_WIDTH);

	jetLPt_2->SetLineWidth(LINE_WIDTH);
	jet2LPt_2->SetLineWidth(LINE_WIDTH);
	jet3LPt_2->SetLineWidth(LINE_WIDTH);
	jet4LPt_2->SetLineWidth(LINE_WIDTH);

	bjetLPt_2->SetLineWidth(LINE_WIDTH);
	bjet2LPt_2->SetLineWidth(LINE_WIDTH);
	bjet3LPt_2->SetLineWidth(LINE_WIDTH);
	bjet4LPt_2->SetLineWidth(LINE_WIDTH);

	bLPt_2->SetLineWidth(LINE_WIDTH);
	b2LPt_2->SetLineWidth(LINE_WIDTH);
	b3LPt_2->SetLineWidth(LINE_WIDTH);
	b4LPt_2->SetLineWidth(LINE_WIDTH);

	bCEta_2->SetLineWidth(LINE_WIDTH);
	b2CEta_2->SetLineWidth(LINE_WIDTH);
	b3CEta_2->SetLineWidth(LINE_WIDTH);
	b4CEta_2->SetLineWidth(LINE_WIDTH);

	Ana_bjetLPt_2->SetLineWidth(LINE_WIDTH);
	Ana_bjet2LPt_2->SetLineWidth(LINE_WIDTH);
	Ana_bjet3LPt_2->SetLineWidth(LINE_WIDTH);
	Ana_bjet4LPt_2->SetLineWidth(LINE_WIDTH);
	return;
}
void Scale_signalHistos_2(double norm) 
{


	MH1H2__2->Scale(norm); 
	PtH1H2__2->Scale(norm); 
	Mb1b2__2->Scale(norm); 
	Mb1b3__2->Scale(norm);
	Mb1b4__2->Scale(norm);
	Mb2b3__2->Scale(norm);
	Mb2b4__2->Scale(norm);
	Mb3b4__2->Scale(norm);

	h_NbTags_2->Scale(norm);
	NSMhiggs_2->Scale(norm);
	Nbquarks_2->Scale(norm);
	Njets_2->Scale(norm);
	higgsPt_2->Scale(norm);
	higgsNLPt_2->Scale(norm);
	M_Lhiggs_2->Scale(norm);
	M_NLhiggs_2->Scale(norm);
	Pt_Lhiggs_2->Scale(norm);
	Pt_NLhiggs_2->Scale(norm);
	RecMH1H2__2->Scale(norm);
	RecPtH1H2__2->Scale(norm);

	// invariant mass of a pair of b's, ctr = -2.0
	M_b1b2__2->Scale(norm);
	M_b1b3__2->Scale(norm);
	M_b1b4__2->Scale(norm);
	M_b2b3__2->Scale(norm);
	M_b2b4__2->Scale(norm);
	M_b3b4__2->Scale(norm);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4__2->Scale(norm);
	dM_b1b3_b2b4__2->Scale(norm);
	dM_b1b4_b2b3__2->Scale(norm);

	jetLM_2->Scale(norm);
	jet2LM_2->Scale(norm);
	jet3LM_2->Scale(norm);
	jet4LM_2->Scale(norm);

	bjetLM_2->Scale(norm);
	bjet2LM_2->Scale(norm);
	bjet3LM_2->Scale(norm);
	bjet4LM_2->Scale(norm);

	jetLPt_2->Scale(norm);
	jet2LPt_2->Scale(norm);
	jet3LPt_2->Scale(norm);
	jet4LPt_2->Scale(norm);

	bjetLPt_2->Scale(norm);
	bjet2LPt_2->Scale(norm);
	bjet3LPt_2->Scale(norm);
	bjet4LPt_2->Scale(norm);

	bLPt_2->Scale(norm);
	b2LPt_2->Scale(norm);
	b3LPt_2->Scale(norm);
	b4LPt_2->Scale(norm);

	bCEta_2->Scale(norm);
	b2CEta_2->Scale(norm);
	b3CEta_2->Scale(norm);
	b4CEta_2->Scale(norm);

	return;
}
void Set_NleadingJetColors__2()
{

	bjetLM_2->SetLineColor(kOrange);
	bjet2LM_2->SetLineColor(kBlack);
	bjet3LM_2->SetLineColor(kRed);
	bjet4LM_2->SetLineColor(kGreen);
	jetLM_2->SetLineColor(kOrange);
	jet2LM_2->SetLineColor(kBlack);
	jet3LM_2->SetLineColor(kRed);
	jet4LM_2->SetLineColor(kGreen);
	bjetLPt_2->SetLineColor(kOrange);
	bjet2LPt_2->SetLineColor(kBlack);
	bjet3LPt_2->SetLineColor(kRed);
	bjet4LPt_2->SetLineColor(kGreen);
	jetLPt_2->SetLineColor(kOrange);
	jet2LPt_2->SetLineColor(kBlack);
	jet3LPt_2->SetLineColor(kRed);
	jet4LPt_2->SetLineColor(kGreen);
	return;
}
void Set_bquark_lambdaColors__2()
{
	

	M_Lhiggs_2->SetLineColor(kGreen);
	M_NLhiggs_2->SetLineColor(kGreen);
	Pt_Lhiggs_2->SetLineColor(kGreen);
	Pt_NLhiggs_2->SetLineColor(kGreen);
	RecMH1H2__2->SetLineColor(kGreen);
	RecPtH1H2__2->SetLineColor(kGreen);

	bjetLM_2->SetLineColor(kGreen);
	bjet2LM_2->SetLineColor(kGreen);
	bjet3LM_2->SetLineColor(kGreen);
	bjet4LM_2->SetLineColor(kGreen);
	jetLM_2->SetLineColor(kGreen);
	jet2LM_2->SetLineColor(kGreen);
	jet3LM_2->SetLineColor(kGreen);
	jet4LM_2->SetLineColor(kGreen);
	jetLPt_2->SetLineColor(kGreen);
	jet2LPt_2->SetLineColor(kGreen);
	jet3LPt_2->SetLineColor(kGreen);
	jet4LPt_2->SetLineColor(kGreen);
	bjetLPt_2->SetLineColor(kGreen);
	bjet2LPt_2->SetLineColor(kGreen);
	bjet3LPt_2->SetLineColor(kGreen);
	bjet4LPt_2->SetLineColor(kGreen);
	bLPt_2->SetLineColor(kGreen);
	b2LPt_2->SetLineColor(kGreen);
	b3LPt_2->SetLineColor(kGreen);
	b4LPt_2->SetLineColor(kGreen);
	bCEta_2->SetLineColor(kGreen);
	b2CEta_2->SetLineColor(kGreen);
	b3CEta_2->SetLineColor(kGreen);
	b4CEta_2->SetLineColor(kGreen);
	Ana_bjetLPt_2->SetLineColor(kGreen);
	Ana_bjet2LPt_2->SetLineColor(kGreen);
	Ana_bjet3LPt_2->SetLineColor(kGreen);
	Ana_bjet4LPt_2->SetLineColor(kGreen);
	return;
}
void Draw_Number_bTags__2()
{
	h_NbTags_2 = new TH1D("h_NbTags_2", "number of b tagged jets, #lambda =-2.0", 6, 0, 6);
	t_2->Draw("Nbtags>>h_NbTags_2");
	return;
}


