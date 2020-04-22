void ClearLorentzVectors__1()
{
	//! clear the Lorentz vectors
	higgs1__1 = TLorentzVector();
	higgs2__1 = TLorentzVector();
	H1H2__1 = TLorentzVector();

	b1__1 = TLorentzVector();
	b2__1 = TLorentzVector();
	b3__1 = TLorentzVector();
	b4__1 = TLorentzVector();

	b1b2__1 = TLorentzVector();
	b1b3__1 = TLorentzVector();
	b1b4__1 = TLorentzVector();
	b2b3__1 = TLorentzVector();
	b2b4__1 = TLorentzVector();
	b3b4__1 = TLorentzVector();
	
	bJ1__1 = TLorentzVector(); 
	bJ2__1 = TLorentzVector(); 
	bJ3__1 = TLorentzVector(); 
	bJ4__1 = TLorentzVector(); 
	bJ1bJ2__1 = TLorentzVector();
	bJ1bJ3__1 = TLorentzVector();
	bJ1bJ4__1 = TLorentzVector();
	bJ2bJ3__1 = TLorentzVector();
	bJ2bJ4__1 = TLorentzVector();
	bJ3bJ4__1 = TLorentzVector();

	RecH1H2__1 = TLorentzVector();
	return;

}
void fetch_histos__1()
{

	bLPt_1  = (TH1D*)f_1->Get("hbPt_Lpt");
	b2LPt_1 = (TH1D*)f_1->Get("hbPt_NLpt");
	b3LPt_1 = (TH1D*)f_1->Get("hbPt_NNLpt");
	b4LPt_1 = (TH1D*)f_1->Get("hbPt_NNNLpt");
	
	bCEta_1  = (TH1D*)f_1->Get("hbEta_Ceta");
	b2CEta_1 = (TH1D*)f_1->Get("hbEta_NCeta");
	b3CEta_1 = (TH1D*)f_1->Get("hbEta_NNCeta");
	b4CEta_1 = (TH1D*)f_1->Get("hbEta_NNNCeta");
	return;
}
void Draw_b_jetPt__1()
{

	t_1->Draw("bJetLPt>>bjetLPt_1");
	t_1->Draw("bJetNLPt>>bjet2LPt_1");
	t_1->Draw("bJetNNLPt>>bjet3LPt_1");
	t_1->Draw("bJetNNNLPt>>bjet4LPt_1");

	return;
}
void Draw_higgsPt__1()
{
	
	t_1->Draw("higgsLPt*1e-3>>higgsPt_1");
	t_1->Draw("higgsNLPt*1e-3>>higgsNLPt_1");
	
	return;
}
void Draw_Nparticles__1()
{
	int nbins = 6, nbins_1 = 20;
	double nmin = 0, nmax = 6, nmax_1 = 20;
	NSMhiggs_1 = new TH1D("NSMhiggs_1", "number of higgs", nbins, nmin, nmax);
	Nbquarks_1 = new TH1D("Nbquarks_1", "number of b quarks", nbins, nmin, nmax);
	Njets_1 = new TH1D("Njets_1", "number of jets", nbins_1, nmin, nmax_1);
	t_1->Draw("NSMhiggs>>NSMhiggs_1");
	t_1->Draw("Nbquarks>>Nbquarks_1");
	t_1->Draw("Njets>>Njets_1");
	NSMhiggs_1->SetLineColor(kGray +1);
	Nbquarks_1->SetLineColor(kGray +1);
	Njets_1->SetLineColor(kGray +1);
	return;
}
void fetch_TTrees__1()
{
	t_1  = (TTree*)f_1->Get("glob_jet");
	t_1->SetBranchStatus("*",0);
	t_1->SetBranchStatus("higgsLPt",1);
	t_1->SetBranchStatus("higgsNLPt",1);
	t_1->SetBranchStatus("NSMhiggs",1);
	t_1->SetBranchStatus("Nbquarks",1);
	t_1->SetBranchStatus("Njets",1);
	t_1->SetBranchStatus("jetPt",1);
	t_1->SetBranchStatus("jetEta",1);;
	t_1->SetBranchStatus("jetPhi",1);
	t_1->SetBranchStatus("jetM",1);
	t_1->SetBranchStatus("btaggedFlavor",1);
	t_1->SetBranchStatus("bJetLPt",1);
	t_1->SetBranchStatus("bJetNLPt",1);
	t_1->SetBranchStatus("bJetNNLPt",1);
	t_1->SetBranchStatus("bJetNNNLPt",1);
	t_1->SetBranchStatus("Nbtags",1);
	t_1->SetBranchStatus("v_higgsPt", 1);
	t_1->SetBranchStatus("v_higgsEta",1);
	t_1->SetBranchStatus("v_higgsPhi",1);
	t_1->SetBranchStatus("v_higgsM",  1);
	t_1->SetBranchStatus("v_bPt", 1);
	t_1->SetBranchStatus("v_bEta",1);
	t_1->SetBranchStatus("v_bPhi",1);
	t_1->SetBranchStatus("v_bM",  1);
	
	
	t_1->SetBranchAddress("jetPt", &v_1_jetPt);
	t_1->SetBranchAddress("jetEta", &v_1_jetEta);
	t_1->SetBranchAddress("jetPhi", &v_1_jetPhi);
	t_1->SetBranchAddress("jetM", &v_1_jetM);
	t_1->SetBranchAddress("btaggedFlavor", &v_1_tagFlavor);
	t_1->SetBranchAddress("Nbtags",&n_1_btags);
	t_1->SetBranchAddress("v_higgsPt", &v_1_higgsPt);
	t_1->SetBranchAddress("v_higgsEta",&v_1_higgsEta);
	t_1->SetBranchAddress("v_higgsPhi",&v_1_higgsPhi);
	t_1->SetBranchAddress("v_higgsM",  &v_1_higgsM);
	t_1->SetBranchAddress("v_bPt", &v_1_bPt);
	t_1->SetBranchAddress("v_bEta",&v_1_bEta);
	t_1->SetBranchAddress("v_bPhi",&v_1_bPhi);
	t_1->SetBranchAddress("v_bM",  &v_1_bM);
	return;
}
void Set_higgsPtProps__1()
{
	int nbins = 60;
	float ptmin = 0;
	float ptmax = 600;
	float Mmin = 200;
	float Mmax = 1400;
	//! truth leading and sub leading higgs Pt
	higgsPt_1  = new TH1D("higgsPt_1",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt_1->SetLineColor(kGray +1);
	higgsPt_1->SetLineWidth(LINE_WIDTH);
	
	higgsNLPt_1  = new TH1D("higgsNLPt_1",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsNLPt_1->SetLineColor(kGray +1);
	higgsNLPt_1->SetLineWidth(LINE_WIDTH);
	//! truth leading and sub leading higgs inv mass
	higgsL_M_1  = new TH1D("higgsL_M_1",  "Invariant higgs mass;m_{rec, leading higgs} [GeV];", nbins, ptmin, ptmax);
	higgsL_M_1->SetLineColor(kGray +1);
	higgsL_M_1->SetLineWidth(LINE_WIDTH);
	
	higgsNL_M_1  = new TH1D("higgsNL_M_1",  "Invariant higgs mass;m_{rec, sub leading higgs} [GeV];", nbins, ptmin, ptmax);
	higgsNL_M_1->SetLineColor(kGray +1);
	higgsNL_M_1->SetLineWidth(LINE_WIDTH);
	//! truth Inv mass of the di-higgs system
	MH1H2__1  = new TH1D("MH1H2__1",  "Invariant di-higgs mass;m_{truth, h1,h2} [GeV];", nbins, Mmin, Mmax);
	MH1H2__1->SetLineColor(kGray +1);
	MH1H2__1->SetLineWidth(LINE_WIDTH);
	//! truth Pt of the di-higgs system
	PtH1H2__1  = new TH1D("PtH1H2__1",  "Transverse momentum of the di-higgs system;p_{T, truth, h1,h2} [GeV/c];", nbins, ptmin, ptmax);
	PtH1H2__1->SetLineColor(kGray +1);
	PtH1H2__1->SetLineWidth(LINE_WIDTH);

	
	//! reconstructed leading and sub leading higgs pt
	Pt_Lhiggs_1  = new TH1D("Pt_Lhiggs_1",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	Pt_NLhiggs_1  = new TH1D("Pt_NLhiggs_1",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	//! reconstructed leading and sub leading inv mass
	M_Lhiggs_1  = new TH1D("M_Lhiggs_1",  "Invariant higgs mass;m_{rec, leading higgs} [GeV];", nbins, MLHmin, MLHmax);
	M_NLhiggs_1  = new TH1D("M_NLhiggs_1",  "Invariant higgs mass;m_{rec, sub leading higgs} [GeV];", nbins, MLHmin, MLHmax);
	
	//! reconstructed Inv mass of the di-higgs system
	RecMH1H2__1  = new TH1D("RecMH1H2__1",  "Invariant di-higgs mass;m_{truth, h1,h2} [GeV];", nbins, Mmin1, Mmax);
	//! reconstructed Pt of the di-higgs system
	RecPtH1H2__1  = new TH1D("RecPtH1H2__1",  "Transverse momentum of the di-higgs system;p_{T, truth, h1,h2} [GeV/c];", nbins, ptmin, ptmax);

	// invariant mass of a pair of b's, ctr = -1.0
	Mb1b2__1 = new TH1D("Mb1b2__1", "#lambda = -1.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 12} [GeV];", nbins, ptmin, ptmax);
	Mb1b3__1 = new TH1D("Mb1b3__1", "#lambda = -1.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 13} [GeV];", nbins, ptmin, ptmax);
	Mb1b4__1 = new TH1D("Mb1b4__1", "#lambda = -1.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 14} [GeV];", nbins, ptmin, ptmax);
	Mb2b3__1 = new TH1D("Mb2b3__1", "#lambda = -1.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 23} [GeV];", nbins, ptmin, ptmax);
	Mb2b4__1 = new TH1D("Mb2b4__1", "#lambda = -1.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 24} [GeV];", nbins, ptmin, ptmax);
	Mb3b4__1 = new TH1D("Mb3b4__1", "#lambda = -1.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 34} [GeV];", nbins, ptmin, ptmax);
	return;
}
void Set_FinalJetPtProps__1()
{
	int nbins = 15; 
	Int_t nbinsMinus = nbins - 1; 
	Float_t pt_bins[15] = {20., 30., 40., 50., 60., 70., 80., 90., 100., 110., 120., 130., 140., 150., 500.};
	//b-jet leading Pt
	Ana_bjetLPt_1  = new TH1D("Ana_bjetLPt_1", "Jet p_{T} after analysis cuts; p_{T, leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	//b-jet 2nd leading Pt
	Ana_bjet2LPt_1  = new TH1D("Ana_bjet2LPt_1", "Jet p_{T} after analysis cuts; p_{T, sub leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	//b-jet 3rd leading Pt
	Ana_bjet3LPt_1  = new TH1D("Ana_bjet3LPt_1", "Jet p_{T} after analysis cuts; p_{T, 3rd leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	//b-jet 4th leading Pt
	Ana_bjet4LPt_1  = new TH1D("Ana_bjet4LPt_1", "Jet p_{T} after analysis cuts; p_{T, 4th leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	return;
}
void Set_jetPtProps__1()
{
	int nbins = 60;
	float ptmin = 0;
	float ptmax = 300;
	float dptmin = 0;
	float dptmax = 300;
	//b-jet leading Pt
	bjetLPt_1  = new TH1D("bjetLPt_1", "b-tagged Jet p_{t}; p_{t, leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 2nd leading Pt
	bjet2LPt_1  = new TH1D("bjet2LPt_1", "b-tagged Jet p_{t}; p_{t, sub leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 3rd leading Pt
	bjet3LPt_1  = new TH1D("bjet3LPt_1", "b-tagged Jet p_{t}; p_{t, 3rd leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 4th leading Pt
	bjet4LPt_1  = new TH1D("bjet4LPt_1", "b-tagged Jet p_{t}; p_{t, 4th leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	
	//jet leading Pt
	jetLPt_1  = new TH1D("jetLPt_1", "Jet p_{t}; p_{t, leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 2nd leading Pt
	jet2LPt_1  = new TH1D("jet2LPt_1", "Jet p_{t}; p_{t, sub leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 3rd leading Pt
	jet3LPt_1  = new TH1D("jet3LPt_1", "Jet p_{t}; p_{t, 3rd leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 4th leading Pt
	jet4LPt_1  = new TH1D("jet4LPt_1", "Jet p_{t}; p_{t, 4th leading jet} [GeV/c];", nbins, ptmin, ptmax);

	//jet leading M
	jetLM_1  = new TH1D("jetLM_1", "Jet invariant mass; m_{ leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 2nd leading M
	jet2LM_1  = new TH1D("jet2LM_1", "Jet invariant mass; m_{ sub leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 3rd leading M
	jet3LM_1  = new TH1D("jet3LM_1", "Jet invariant mass; m_{ 3rd leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 4th leading M
	jet4LM_1  = new TH1D("jet4LM_1", "Jet invariant mass; m_{ 4th leading jet} [GeV];", nbins, ptmin, ptmax);
	
	//bjet leading M
	bjetLM_1  = new TH1D("bjetLM_1", "Jet invariant mass; m_{ leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 2nd leading M
	bjet2LM_1  = new TH1D("bjet2LM_1", "Jet invariant mass; m_{ sub leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 3rd leading M
	bjet3LM_1  = new TH1D("bjet3LM_1", "Jet invariant mass; m_{ 3rd leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 4th leading M
	bjet4LM_1  = new TH1D("bjet4LM_1", "Jet invariant mass; m_{ 4th leading bjet} [GeV];", nbins, ptmin, ptmax);
	
	// invariant mass of a pair of b's, ctr = 1.0
	M_b1b2__1 = new TH1D("M_b1b2__1", "Invariant mass of the higgs candidates; m_{higgs candidate, 12} [GeV];", nbins, ptmin, ptmax);
	M_b1b3__1 = new TH1D("M_b1b3__1", "Invariant mass of the higgs candidates; m_{higgs candidate, 13} [GeV];", nbins, ptmin, ptmax);
	M_b1b4__1 = new TH1D("M_b1b4__1", "Invariant mass of the higgs candidates; m_{higgs candidate, 14} [GeV];", nbins, ptmin, ptmax);
	M_b2b3__1 = new TH1D("M_b2b3__1", "Invariant mass of the higgs candidates; m_{higgs candidate, 23} [GeV];", nbins, ptmin, ptmax);
	M_b2b4__1 = new TH1D("M_b2b4__1", "Invariant mass of the higgs candidates; m_{higgs candidate, 24} [GeV];", nbins, ptmin, ptmax);
	M_b3b4__1 = new TH1D("M_b3b4__1", "Invariant mass of the higgs candidates; m_{higgs candidate, 34} [GeV];", nbins, ptmin, ptmax);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4__1 = new TH1D("dM_b1b2_b3b4__1", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1234} [GeV];", nbins, dptmin, dptmax);
	dM_b1b3_b2b4__1 = new TH1D("dM_b1b3_b2b4__1", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1324} [GeV];", nbins, dptmin, dptmax);
	dM_b1b4_b2b3__1 = new TH1D("dM_b1b4_b2b3__1", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1423} [GeV];", nbins, dptmin, dptmax);

	combi_selected__1 = new TH1D("combi_selected__1", "Selected combination", 3, 1, 4);
	return;
}
void Draw_InvariantMass__1()
{
	//! higgs's
	if(v_1_higgsPt->size() == 2)
	{
		higgs1__1.SetPtEtaPhiM((*v_1_higgsPt)[0], (*v_1_higgsEta)[0], (*v_1_higgsPhi)[0], (*v_1_higgsM)[0]);
		higgs2__1.SetPtEtaPhiM((*v_1_higgsPt)[1], (*v_1_higgsEta)[1], (*v_1_higgsPhi)[1], (*v_1_higgsM)[1]);
		H1H2__1 = higgs1__1 + higgs2__1;
		
		MH1H2__1->Fill(H1H2__1.M()*1e-3);
		PtH1H2__1->Fill(H1H2__1.Pt()*1e-3);
	}
	//! b's
	if(v_1_bPt->size() == 4)
	{
		b1__1.SetPtEtaPhiM((*v_1_bPt)[0], (*v_1_bEta)[0], (*v_1_bPhi)[0], (*v_1_bM)[0]);
		b2__1.SetPtEtaPhiM((*v_1_bPt)[1], (*v_1_bEta)[1], (*v_1_bPhi)[1], (*v_1_bM)[1]);
		b3__1.SetPtEtaPhiM((*v_1_bPt)[2], (*v_1_bEta)[2], (*v_1_bPhi)[2], (*v_1_bM)[2]);
		b4__1.SetPtEtaPhiM((*v_1_bPt)[3], (*v_1_bEta)[3], (*v_1_bPhi)[3], (*v_1_bM)[3]);

		b1b2__1 = b1__1 + b2__1;
		b1b3__1 = b1__1 + b3__1;
		b1b4__1 = b1__1 + b4__1;
		b2b3__1 = b2__1 + b3__1;
		b2b4__1 = b2__1 + b4__1;
		b3b4__1 = b3__1 + b4__1;
		
		Mb1b2__1->Fill(b1b2__1.M()*1e-3);
		Mb1b3__1->Fill(b1b3__1.M()*1e-3);
		Mb1b4__1->Fill(b1b4__1.M()*1e-3);
		Mb2b3__1->Fill(b2b3__1.M()*1e-3);
		Mb2b4__1->Fill(b2b4__1.M()*1e-3);
		Mb3b4__1->Fill(b3b4__1.M()*1e-3);
	}

	return;
}
//void Fill_InvariantMass__1()
//{
//	Mb1b2__1->Fill(b1b2__1.M()*1e-3);
//	Mb1b3__1->Fill(b1b3__1.M()*1e-3);
//	Mb1b4__1->Fill(b1b4__1.M()*1e-3);
//	Mb2b3__1->Fill(b2b3__1.M()*1e-3);
//	Mb2b4__1->Fill(b2b4__1.M()*1e-3);
//	Mb3b4__1->Fill(b3b4__1.M()*1e-3);
//
//	MH1H2__1->Fill(H1H2__1.M()*1e-3);
//	PtH1H2__1->Fill(H1H2__1.Pt()*1e-3);
//	return;
//}
void Fill_NLeadingJetPtM__1()
{
	jetLPt_1->Fill((*v_1_jetPt)[0]*1e-3);
	jet2LPt_1->Fill((*v_1_jetPt)[1]*1e-3);
	jet3LPt_1->Fill((*v_1_jetPt)[2]*1e-3);
	jet4LPt_1->Fill((*v_1_jetPt)[3]*1e-3);
	
	jetLM_1->Fill( (*v_1_jetM)[0]*1e-3);
	jet2LM_1->Fill((*v_1_jetM)[1]*1e-3);
	jet3LM_1->Fill((*v_1_jetM)[2]*1e-3);
	jet4LM_1->Fill((*v_1_jetM)[3]*1e-3);

	return;
}
void Fill_bjetPtM__1(int &nhiggs)
{
	bjetLPt_1->Fill( bJ1__1.Pt()*1e-3);
	bjet2LPt_1->Fill(bJ2__1.Pt()*1e-3);
	bjet3LPt_1->Fill(bJ3__1.Pt()*1e-3);
	bjet4LPt_1->Fill(bJ4__1.Pt()*1e-3);

	bjetLM_1->Fill( bJ1__1.M()*1e-3);
	bjet2LM_1->Fill(bJ2__1.M()*1e-3);
	bjet3LM_1->Fill(bJ3__1.M()*1e-3);
	bjet4LM_1->Fill(bJ4__1.M()*1e-3);
	
	M_b1b2__1->Fill(bJ1bJ2__1.M()*1e-3);
	M_b1b3__1->Fill(bJ1bJ3__1.M()*1e-3);
	M_b1b4__1->Fill(bJ1bJ4__1.M()*1e-3);
	M_b2b3__1->Fill(bJ2bJ3__1.M()*1e-3);
	M_b2b4__1->Fill(bJ2bJ4__1.M()*1e-3);
	M_b3b4__1->Fill(bJ3bJ4__1.M()*1e-3);

	double dm_12_34 = 0, dm_13_24 = 0, dm_14_23 = 0;
	dm_12_34 = std::fabs(bJ1bJ2__1.M() - bJ3bJ4__1.M())*1e-3;
	dm_13_24 = std::fabs(bJ1bJ3__1.M() - bJ2bJ4__1.M())*1e-3;
	dm_14_23 = std::fabs(bJ1bJ4__1.M() - bJ2bJ3__1.M())*1e-3;
	//dM_b1b2_b3b4__1->Fill(dm_12_34*1e-3);	
	//dM_b1b3_b2b4__1->Fill(dm_13_24*1e-3);	
	//dM_b1b4_b2b3__1->Fill(dm_14_23*1e-3);

	//! Higgs Candidate
	int higgs_candidates = -1;
	int min_diffCombi = 999;
	
	if((std::fabs(bJ1bJ2__1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ3bJ4__1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
		if(dm_12_34 < min_diffCombi) 
		{
			min_diffCombi = dm_12_34;
			higgs_candidates = 1234;
		}
	}

	if((std::fabs(bJ1bJ3__1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ4__1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
		if(dm_13_24 < min_diffCombi)
		{
			min_diffCombi = dm_13_24;
			higgs_candidates = 1324;
		}
	}

	if((std::fabs(bJ1bJ4__1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ3__1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
		if(dm_14_23 < min_diffCombi)
		{
			min_diffCombi = dm_14_23;
			higgs_candidates = 1423;
		}
	}

	if(higgs_candidates == 1234)
	{
		//if((std::fabs(bJ1bJ2__1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ3bJ4__1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		//{
			combi_selected__1->Fill(1);
			nhiggs++;
			//! Fill four jet pt after all selection
			Ana_bjetLPt_1->Fill( bJ1__1.Pt()*1e-3);
			Ana_bjet2LPt_1->Fill(bJ2__1.Pt()*1e-3);
			Ana_bjet3LPt_1->Fill(bJ3__1.Pt()*1e-3);
			Ana_bjet4LPt_1->Fill(bJ4__1.Pt()*1e-3);
			if(bJ1bJ2__1.M() > bJ3bJ4__1.M())
			{
				M_Lhiggs_1->Fill(bJ1bJ2__1.M()*1e-3);
				M_NLhiggs_1->Fill(bJ3bJ4__1.M()*1e-3);
				Pt_Lhiggs_1->Fill(bJ1bJ2__1.Pt()*1e-3);
				Pt_NLhiggs_1->Fill(bJ3bJ4__1.Pt()*1e-3);
			
			} 
			else
			{
				M_Lhiggs_1->Fill(bJ3bJ4__1.M()*1e-3);
				M_NLhiggs_1->Fill(bJ1bJ2__1.M()*1e-3);
				Pt_Lhiggs_1->Fill(bJ3bJ4__1.Pt()*1e-3);
				Pt_NLhiggs_1->Fill(bJ1bJ2__1.Pt()*1e-3);
				
			}
			RecH1H2__1 = bJ1bJ2__1 + bJ3bJ4__1;
			RecMH1H2__1->Fill(RecH1H2__1.M()*1e-3);
			RecPtH1H2__1->Fill(RecH1H2__1.Pt()*1e-3);
			
			dM_b1b2_b3b4__1->Fill(dm_12_34);	
		//}
	}
	else if(higgs_candidates == 1324)
	{
		//if((std::fabs(bJ1bJ3__1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ4__1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		//{
			combi_selected__1->Fill(2);
			nhiggs++;
			//! Fill four jet pt after all selection
			Ana_bjetLPt_1->Fill( bJ1__1.Pt()*1e-3);
			Ana_bjet2LPt_1->Fill(bJ2__1.Pt()*1e-3);
			Ana_bjet3LPt_1->Fill(bJ3__1.Pt()*1e-3);
			Ana_bjet4LPt_1->Fill(bJ4__1.Pt()*1e-3);
			if(bJ1bJ3__1.M() > bJ2bJ4__1.M())
			{
				M_Lhiggs_1->Fill(bJ1bJ3__1.M()*1e-3);
				M_NLhiggs_1->Fill(bJ2bJ4__1.M()*1e-3);
				Pt_Lhiggs_1->Fill(bJ1bJ3__1.Pt()*1e-3);
				Pt_NLhiggs_1->Fill(bJ2bJ4__1.Pt()*1e-3);
			
			} 
			else
			{
				M_Lhiggs_1->Fill(bJ2bJ4__1.M()*1e-3);
				M_NLhiggs_1->Fill(bJ1bJ3__1.M()*1e-3);
				Pt_Lhiggs_1->Fill(bJ2bJ4__1.Pt()*1e-3);
				Pt_NLhiggs_1->Fill(bJ1bJ3__1.Pt()*1e-3);
				
			}
			RecH1H2__1 = bJ1bJ3__1 + bJ2bJ4__1;
			RecMH1H2__1->Fill(RecH1H2__1.M()*1e-3);
			RecPtH1H2__1->Fill(RecH1H2__1.Pt()*1e-3);
			
			dM_b1b3_b2b4__1->Fill(dm_13_24);	
		//}
	
	}
	else if(higgs_candidates == 1423)
	{
		//if((std::fabs(bJ1bJ4__1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ3__1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		//{
			combi_selected__1->Fill(3);
			nhiggs++;
			//! Fill four jet pt after all selection
			Ana_bjetLPt_1->Fill( bJ1__1.Pt()*1e-3);
			Ana_bjet2LPt_1->Fill(bJ2__1.Pt()*1e-3);
			Ana_bjet3LPt_1->Fill(bJ3__1.Pt()*1e-3);
			Ana_bjet4LPt_1->Fill(bJ4__1.Pt()*1e-3);
			if(bJ1bJ4__1.M() > bJ2bJ3__1.M())
			{
				M_Lhiggs_1->Fill(bJ1bJ4__1.M()*1e-3);
				M_NLhiggs_1->Fill(bJ2bJ3__1.M()*1e-3);
				Pt_Lhiggs_1->Fill(bJ1bJ4__1.Pt()*1e-3);
				Pt_NLhiggs_1->Fill(bJ2bJ3__1.Pt()*1e-3);
			
			} 
			else
			{
				M_Lhiggs_1->Fill(bJ2bJ3__1.M()*1e-3);
				M_NLhiggs_1->Fill(bJ1bJ4__1.M()*1e-3);
				Pt_Lhiggs_1->Fill(bJ2bJ3__1.Pt()*1e-3);
				Pt_NLhiggs_1->Fill(bJ1bJ4__1.Pt()*1e-3);
				
			}
			RecH1H2__1 = bJ1bJ4__1 + bJ2bJ3__1;
			RecMH1H2__1->Fill(RecH1H2__1.M()*1e-3);
			RecPtH1H2__1->Fill(RecH1H2__1.Pt()*1e-3);
			
			dM_b1b4_b2b3__1->Fill(dm_14_23);
		//}
	
	}

	return;
}
void Draw_DiJetInvariantMass__1(int &nb_1, int &nhiggs)
{
	v_1_bjetPt.clear();
	v_1_bjetEta.clear();
	v_1_bjetPhi.clear();
	v_1_bjetM.clear();
	for(int j = 0; j < v_1_tagFlavor->size(); j++)
	{
		if((*v_1_tagFlavor)[j] != 5) continue;
		v_1_bjetPt.push_back((*v_1_jetPt)[j]);
		v_1_bjetEta.push_back((*v_1_jetEta)[j]);
		v_1_bjetPhi.push_back((*v_1_jetPhi)[j]);
		v_1_bjetM.push_back((*v_1_jetM)[j]);

	}
	
	//! b jet's
	if(v_1_bjetPt.size() > 3)
	{
		if(v_1_bjetPt[0]*1e-3 >= minLeadingPt  && v_1_bjetPt[1]*1e-3 >= minSubLeadingPt  && v_1_bjetPt[2]*1e-3 >= third_Pt_cut && v_1_bjetPt[3]*1e-3 >= default_Pt_cut )
		{
			nb_1++;
			bJ1__1.SetPtEtaPhiM(v_1_bjetPt[0], v_1_bjetEta[0], v_1_bjetPhi[0], v_1_bjetM[0]);
			bJ2__1.SetPtEtaPhiM(v_1_bjetPt[1], v_1_bjetEta[1], v_1_bjetPhi[1], v_1_bjetM[1]);
			bJ3__1.SetPtEtaPhiM(v_1_bjetPt[2], v_1_bjetEta[2], v_1_bjetPhi[2], v_1_bjetM[2]);
			bJ4__1.SetPtEtaPhiM(v_1_bjetPt[3], v_1_bjetEta[3], v_1_bjetPhi[3], v_1_bjetM[3]);

			bJ1bJ2__1 = bJ1__1 + bJ2__1;
			bJ1bJ3__1 = bJ1__1 + bJ3__1;
			bJ1bJ4__1 = bJ1__1 + bJ4__1;
			bJ2bJ3__1 = bJ2__1 + bJ3__1;
			bJ2bJ4__1 = bJ2__1 + bJ4__1;
			bJ3bJ4__1 = bJ3__1 + bJ4__1;

			Fill_bjetPtM__1(nhiggs);
		}
	}
	return;
}

void SetLineWidth_1()
{
        MH1H2__1->SetLineWidth(LINE_WIDTH);
        PtH1H2__1->SetLineWidth(LINE_WIDTH);

	Mb1b2__1->SetLineWidth(LINE_WIDTH); 
	Mb1b3__1->SetLineWidth(LINE_WIDTH);
	Mb1b4__1->SetLineWidth(LINE_WIDTH);
	Mb2b3__1->SetLineWidth(LINE_WIDTH);
	Mb2b4__1->SetLineWidth(LINE_WIDTH);
	Mb3b4__1->SetLineWidth(LINE_WIDTH);
	
	h_NbTags_1->SetLineWidth(LINE_WIDTH);
	NSMhiggs_1->SetLineWidth(LINE_WIDTH);
	Nbquarks_1->SetLineWidth(LINE_WIDTH);
	Njets_1->SetLineWidth(LINE_WIDTH);
	higgsPt_1->SetLineWidth(LINE_WIDTH);
	higgsNLPt_1->SetLineWidth(LINE_WIDTH);
	M_Lhiggs_1->SetLineWidth(LINE_WIDTH);
	M_NLhiggs_1->SetLineWidth(LINE_WIDTH);
	Pt_Lhiggs_1->SetLineWidth(LINE_WIDTH);
	Pt_NLhiggs_1->SetLineWidth(LINE_WIDTH);
	RecMH1H2__1->SetLineWidth(LINE_WIDTH);
	RecPtH1H2__1->SetLineWidth(LINE_WIDTH);

	// invariant mass of a pair of b's, ctr = -1.0
	M_b1b2__1->SetLineWidth(LINE_WIDTH);
	M_b1b3__1->SetLineWidth(LINE_WIDTH);
	M_b1b4__1->SetLineWidth(LINE_WIDTH);
	M_b2b3__1->SetLineWidth(LINE_WIDTH);
	M_b2b4__1->SetLineWidth(LINE_WIDTH);
	M_b3b4__1->SetLineWidth(LINE_WIDTH);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4__1->SetLineWidth(LINE_WIDTH);
	dM_b1b3_b2b4__1->SetLineWidth(LINE_WIDTH);
	dM_b1b4_b2b3__1->SetLineWidth(LINE_WIDTH);

	jetLM_1->SetLineWidth(LINE_WIDTH);
	jet2LM_1->SetLineWidth(LINE_WIDTH);
	jet3LM_1->SetLineWidth(LINE_WIDTH);
	jet4LM_1->SetLineWidth(LINE_WIDTH);

	bjetLM_1->SetLineWidth(LINE_WIDTH);
	bjet2LM_1->SetLineWidth(LINE_WIDTH);
	bjet3LM_1->SetLineWidth(LINE_WIDTH);
	bjet4LM_1->SetLineWidth(LINE_WIDTH);

	jetLPt_1->SetLineWidth(LINE_WIDTH);
	jet2LPt_1->SetLineWidth(LINE_WIDTH);
	jet3LPt_1->SetLineWidth(LINE_WIDTH);
	jet4LPt_1->SetLineWidth(LINE_WIDTH);

	bjetLPt_1->SetLineWidth(LINE_WIDTH);
	bjet2LPt_1->SetLineWidth(LINE_WIDTH);
	bjet3LPt_1->SetLineWidth(LINE_WIDTH);
	bjet4LPt_1->SetLineWidth(LINE_WIDTH);

	bLPt_1->SetLineWidth(LINE_WIDTH);
	b2LPt_1->SetLineWidth(LINE_WIDTH);
	b3LPt_1->SetLineWidth(LINE_WIDTH);
	b4LPt_1->SetLineWidth(LINE_WIDTH);

	bCEta_1->SetLineWidth(LINE_WIDTH);
	b2CEta_1->SetLineWidth(LINE_WIDTH);
	b3CEta_1->SetLineWidth(LINE_WIDTH);
	b4CEta_1->SetLineWidth(LINE_WIDTH);

	Ana_bjetLPt_1->SetLineWidth(LINE_WIDTH);
	Ana_bjet2LPt_1->SetLineWidth(LINE_WIDTH);
	Ana_bjet3LPt_1->SetLineWidth(LINE_WIDTH);
	Ana_bjet4LPt_1->SetLineWidth(LINE_WIDTH);
	return;
}
void Scale_signalHistos_1(double norm)
{
        MH1H2__1->Scale(norm);
        PtH1H2__1->Scale(norm);

	Mb1b2__1->Scale(norm); 
	Mb1b3__1->Scale(norm);
	Mb1b4__1->Scale(norm);
	Mb2b3__1->Scale(norm);
	Mb2b4__1->Scale(norm);
	Mb3b4__1->Scale(norm);
	
	h_NbTags_1->Scale(norm);
	NSMhiggs_1->Scale(norm);
	Nbquarks_1->Scale(norm);
	Njets_1->Scale(norm);
	higgsPt_1->Scale(norm);
	higgsNLPt_1->Scale(norm);
	M_Lhiggs_1->Scale(norm);
	M_NLhiggs_1->Scale(norm);
	Pt_Lhiggs_1->Scale(norm);
	Pt_NLhiggs_1->Scale(norm);
	RecMH1H2__1->Scale(norm);
	RecPtH1H2__1->Scale(norm);

	// invariant mass of a pair of b's, ctr = -1.0
	M_b1b2__1->Scale(norm);
	M_b1b3__1->Scale(norm);
	M_b1b4__1->Scale(norm);
	M_b2b3__1->Scale(norm);
	M_b2b4__1->Scale(norm);
	M_b3b4__1->Scale(norm);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4__1->Scale(norm);
	dM_b1b3_b2b4__1->Scale(norm);
	dM_b1b4_b2b3__1->Scale(norm);

	jetLM_1->Scale(norm);
	jet2LM_1->Scale(norm);
	jet3LM_1->Scale(norm);
	jet4LM_1->Scale(norm);

	bjetLM_1->Scale(norm);
	bjet2LM_1->Scale(norm);
	bjet3LM_1->Scale(norm);
	bjet4LM_1->Scale(norm);

	jetLPt_1->Scale(norm);
	jet2LPt_1->Scale(norm);
	jet3LPt_1->Scale(norm);
	jet4LPt_1->Scale(norm);

	bjetLPt_1->Scale(norm);
	bjet2LPt_1->Scale(norm);
	bjet3LPt_1->Scale(norm);
	bjet4LPt_1->Scale(norm);

	bLPt_1->Scale(norm);
	b2LPt_1->Scale(norm);
	b3LPt_1->Scale(norm);
	b4LPt_1->Scale(norm);

	bCEta_1->Scale(norm);
	b2CEta_1->Scale(norm);
	b3CEta_1->Scale(norm);
	b4CEta_1->Scale(norm);

	return;
}
void Set_NleadingJetColors__1()
{

	bjetLM_1->SetLineColor(kOrange);
	bjet2LM_1->SetLineColor(kBlack);
	bjet3LM_1->SetLineColor(kRed);
	bjet4LM_1->SetLineColor(kGreen);
	jetLM_1->SetLineColor(kOrange);
	jet2LM_1->SetLineColor(kBlack);
	jet3LM_1->SetLineColor(kRed);
	jet4LM_1->SetLineColor(kGreen);
	bjetLPt_1->SetLineColor(kOrange);
	bjet2LPt_1->SetLineColor(kBlack);
	bjet3LPt_1->SetLineColor(kRed);
	bjet4LPt_1->SetLineColor(kGreen);
	jetLPt_1->SetLineColor(kOrange);
	jet2LPt_1->SetLineColor(kBlack);
	jet3LPt_1->SetLineColor(kRed);
	jet4LPt_1->SetLineColor(kGreen);
	return;
}
void Set_bquark_lambdaColors__1()
{

	M_Lhiggs_1->SetLineColor(kGray +1);
	M_NLhiggs_1->SetLineColor(kGray +1);
	Pt_Lhiggs_1->SetLineColor(kGray +1);
	Pt_NLhiggs_1->SetLineColor(kGray +1);
	RecMH1H2__1->SetLineColor(kGray +1);
	RecPtH1H2__1->SetLineColor(kGray +1);
	
	bjetLM_1->SetLineColor(kGray +1);
	bjet2LM_1->SetLineColor(kGray +1);
	bjet3LM_1->SetLineColor(kGray +1);
	bjet4LM_1->SetLineColor(kGray +1);
	jetLM_1->SetLineColor(kGray +1);
	jet2LM_1->SetLineColor(kGray +1);
	jet3LM_1->SetLineColor(kGray +1);
	jet4LM_1->SetLineColor(kGray +1);
	jetLPt_1->SetLineColor(kGray +1);
	jet2LPt_1->SetLineColor(kGray +1);
	jet3LPt_1->SetLineColor(kGray +1);
	jet4LPt_1->SetLineColor(kGray +1);
	bjetLPt_1->SetLineColor(kGray +1);
	bjet2LPt_1->SetLineColor(kGray +1);
	bjet3LPt_1->SetLineColor(kGray +1);
	bjet4LPt_1->SetLineColor(kGray +1);
	bLPt_1->SetLineColor(kGray +1);
	b2LPt_1->SetLineColor(kGray +1);
	b3LPt_1->SetLineColor(kGray +1);
	b4LPt_1->SetLineColor(kGray +1);
	bCEta_1->SetLineColor(kGray +1);
	b2CEta_1->SetLineColor(kGray +1);
	b3CEta_1->SetLineColor(kGray +1);
	b4CEta_1->SetLineColor(kGray +1);
	Ana_bjetLPt_1->SetLineColor(kGray +1);
	Ana_bjet2LPt_1->SetLineColor(kGray +1);
	Ana_bjet3LPt_1->SetLineColor(kGray +1);
	Ana_bjet4LPt_1->SetLineColor(kGray +1);
	return;
}
void Draw_Number_bTags__1()
{

	h_NbTags_1 = new TH1D("h_NbTags_1", "number of b tagged jets, #lambda =-1.0", 6, 0, 6);
	t_1->Draw("Nbtags>>h_NbTags_1");
	return;
}


