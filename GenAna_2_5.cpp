void ClearLorentzVectors_2_5()
{
	//! clear the Lorentz vectors
	higgs1_2_5 = TLorentzVector();
	higgs2_2_5 = TLorentzVector();
	H1H2_2_5 = TLorentzVector();

	b1_2_5 = TLorentzVector();
	b2_2_5 = TLorentzVector();
	b3_2_5 = TLorentzVector();
	b4_2_5 = TLorentzVector();

	b1b2_2_5 = TLorentzVector();
	b1b3_2_5 = TLorentzVector();
	b1b4_2_5 = TLorentzVector();
	b2b3_2_5 = TLorentzVector();
	b2b4_2_5 = TLorentzVector();
	b3b4_2_5 = TLorentzVector();
	
	bJ1_2_5 = TLorentzVector(); 
	bJ2_2_5 = TLorentzVector(); 
	bJ3_2_5 = TLorentzVector(); 
	bJ4_2_5 = TLorentzVector(); 
	bJ1bJ2_2_5 = TLorentzVector();
	bJ1bJ3_2_5 = TLorentzVector();
	bJ1bJ4_2_5 = TLorentzVector();
	bJ2bJ3_2_5 = TLorentzVector();
	bJ2bJ4_2_5 = TLorentzVector();
	bJ3bJ4_2_5 = TLorentzVector();

	RecH1H2_2_5 = TLorentzVector();
	return;

}
void fetch_histos_2_5()
{

	bLPt2_5  = (TH1D*)f2_5->Get("hbPt_Lpt");
	b2LPt2_5 = (TH1D*)f2_5->Get("hbPt_NLpt");
	b3LPt2_5 = (TH1D*)f2_5->Get("hbPt_NNLpt");
	b4LPt2_5 = (TH1D*)f2_5->Get("hbPt_NNNLpt");
	
	bCEta2_5  = (TH1D*)f2_5->Get("hbEta_Ceta");
	b2CEta2_5 = (TH1D*)f2_5->Get("hbEta_NCeta");
	b3CEta2_5 = (TH1D*)f2_5->Get("hbEta_NNCeta");
	b4CEta2_5 = (TH1D*)f2_5->Get("hbEta_NNNCeta");
	
	return;
}
void Draw_b_jetPt_2_5()
{

	t2_5->Draw("bJetLPt>>bjetLPt2_5");
	t2_5->Draw("bJetNLPt>>bjet2LPt2_5");
	t2_5->Draw("bJetNNLPt>>bjet3LPt2_5");
	t2_5->Draw("bJetNNNLPt>>bjet4LPt2_5");
	
	return;
}
void Draw_higgsPt_2_5()
{
	
	t2_5->Draw("higgsLPt*1e-3>>higgsPt2_5");
	t2_5->Draw("higgsNLPt*1e-3>>higgsNLPt2_5");
	
	return;
}
void Draw_Nparticles_2_5()
{
	int nbins = 6, nbins_1 = 20;
	double nmin = 0, nmax = 6, nmax_1 = 20;
	NSMhiggs2_5= new TH1D("NSMhiggs2_5", "number of higgs", nbins, nmin, nmax);
	Nbquarks2_5= new TH1D("Nbquarks2_5", "number of b quarks", nbins, nmin, nmax);
	Njets2_5= new TH1D("Njets2_5", "number of jets", nbins_1, nmin, nmax_1);
	t2_5->Draw("NSMhiggs>>NSMhiggs2_5");
	t2_5->Draw("Nbquarks>>Nbquarks2_5");
	t2_5->Draw("Njets>>Njets2_5");
	NSMhiggs2_5->SetLineColor(kOrange);
	Nbquarks2_5->SetLineColor(kOrange);
	Njets2_5->SetLineColor(kOrange);
	return;
}
void fetch_TTrees_2_5()
{
	t2_5 = (TTree*)f2_5->Get("glob_jet");
	t2_5->SetBranchStatus("*",0);
	t2_5->SetBranchStatus("higgsLPt",1);
	t2_5->SetBranchStatus("higgsNLPt",1);
	t2_5->SetBranchStatus("NSMhiggs",1);
	t2_5->SetBranchStatus("Nbquarks",1);
	t2_5->SetBranchStatus("Njets",1);
	t2_5->SetBranchStatus("jetPt",1);
	t2_5->SetBranchStatus("jetEta",1);
	t2_5->SetBranchStatus("jetPhi",1);
	t2_5->SetBranchStatus("jetM",1);
	t2_5->SetBranchStatus("btaggedFlavor",1);
	t2_5->SetBranchStatus("bJetLPt",1);
	t2_5->SetBranchStatus("bJetNLPt",1);
	t2_5->SetBranchStatus("bJetNNLPt",1);
	t2_5->SetBranchStatus("bJetNNNLPt",1);
	t2_5->SetBranchStatus("Nbtags",1);
	t2_5->SetBranchStatus("v_higgsPt", 1);
	t2_5->SetBranchStatus("v_higgsEta",1);
	t2_5->SetBranchStatus("v_higgsPhi",1);
	t2_5->SetBranchStatus("v_higgsM",  1);
	t2_5->SetBranchStatus("v_bPt", 1);
	t2_5->SetBranchStatus("v_bEta",1);
	t2_5->SetBranchStatus("v_bPhi",1);
	t2_5->SetBranchStatus("v_bM",  1);
	
	t2_5->SetBranchAddress("jetPt",&v2_5_jetPt);
	t2_5->SetBranchAddress("jetEta",&v2_5_jetEta);
	t2_5->SetBranchAddress("jetPhi",&v2_5_jetPhi);
	t2_5->SetBranchAddress("jetM",&v2_5_jetM);
	t2_5->SetBranchAddress("btaggedFlavor",&v2_5_tagFlavor);
	t2_5->SetBranchAddress("Nbtags",&n2_5_btags);
	t2_5->SetBranchAddress("v_higgsPt", &v2_5_higgsPt);
	t2_5->SetBranchAddress("v_higgsEta",&v2_5_higgsEta);
	t2_5->SetBranchAddress("v_higgsPhi",&v2_5_higgsPhi);
	t2_5->SetBranchAddress("v_higgsM",  &v2_5_higgsM);
	t2_5->SetBranchAddress("v_bPt", &v2_5_bPt);
	t2_5->SetBranchAddress("v_bEta",&v2_5_bEta);
	t2_5->SetBranchAddress("v_bPhi",&v2_5_bPhi);
	t2_5->SetBranchAddress("v_bM",  &v2_5_bM);
	return;
}
void Set_higgsPtProps_2_5()
{
	int nbins = 60;
	float ptmin = 0;
	float ptmax = 600;
	float Mmin = 200;
	float Mmax = 1400;
	//! truth leading and sub leading higgs Pt
	higgsPt2_5  = new TH1D("higgsPt2_5",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsPt2_5->SetLineColor(kOrange);
	higgsPt2_5->SetLineWidth(LINE_WIDTH);
	
	higgsNLPt2_5  = new TH1D("higgsNLPt2_5",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	higgsNLPt2_5->SetLineColor(kOrange);
	higgsNLPt2_5->SetLineWidth(LINE_WIDTH);
	//! truth leading and sub leading higgs inv mass
	higgsL_M2_5  = new TH1D("higgsL_M2_5",  "Invariant higgs mass;m_{rec, leading higgs} [GeV];", nbins, ptmin, ptmax);
	higgsL_M2_5->SetLineColor(kOrange);
	higgsL_M2_5->SetLineWidth(LINE_WIDTH);
	
	higgsNL_M2_5  = new TH1D("higgsNL_M2_5",  "Invariant higgs mass;m_{rec, sub leading higgs} [GeV];", nbins, ptmin, ptmax);
	higgsNL_M2_5->SetLineColor(kOrange);
	higgsNL_M2_5->SetLineWidth(LINE_WIDTH);
	//! truth Inv mass of the di-higgs system
	MH1H2_2_5  = new TH1D("MH1H2_2_5",  "Invariant di-higgs mass;m_{truth, h1,h2} [GeV];", nbins, Mmin, Mmax);
	MH1H2_2_5->SetLineColor(kOrange);
	MH1H2_2_5->SetLineWidth(LINE_WIDTH);
	//! truth Pt of the di-higgs system
	PtH1H2_2_5  = new TH1D("PtH1H2_2_5",  "Transverse momentum of the di-higgs system;p_{T, truth, h1,h2} [GeV/c];", nbins, ptmin, ptmax);
	PtH1H2_2_5->SetLineColor(kOrange);
	PtH1H2_2_5->SetLineWidth(LINE_WIDTH);

	
	//! reconstructed leading and sub leading higgs pt
	Pt_Lhiggs2_5  = new TH1D("Pt_Lhiggs2_5",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	Pt_NLhiggs2_5  = new TH1D("Pt_NLhiggs2_5",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	//! reconstructed leading and sub leading inv mass
	M_Lhiggs2_5  = new TH1D("M_Lhiggs2_5",  "Invariant higgs mass;m_{rec, leading higgs} [GeV];", nbins, ptmin, ptmax);
	M_NLhiggs2_5  = new TH1D("M_NLhiggs2_5",  "Invariant higgs mass;m_{rec, sub leading higgs} [GeV];", nbins, ptmin, ptmax);
	
	//! reconstructed Inv mass of the di-higgs system
	RecMH1H2_2_5  = new TH1D("RecMH1H2_2_5",  "Invariant di-higgs mass;m_{truth, h1,h2} [GeV];", nbins, Mmin, Mmax);
	//! reconstructed Pt of the di-higgs system
	RecPtH1H2_2_5  = new TH1D("RecPtH1H2_2_5",  "Transverse momentum of the di-higgs system;p_{T, truth, h1,h2} [GeV/c];", nbins, ptmin, ptmax);

	// invariant mass of a pair of b's, ctr = 2.5
	Mb1b2_2_5 = new TH1D("Mb1b2_2_5", "#lambda = 2.5, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 12} [GeV];", nbins, ptmin, ptmax);
	Mb1b3_2_5 = new TH1D("Mb1b3_2_5", "#lambda = 2.5, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 13} [GeV];", nbins, ptmin, ptmax);
	Mb1b4_2_5 = new TH1D("Mb1b4_2_5", "#lambda = 2.5, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 14} [GeV];", nbins, ptmin, ptmax);
	Mb2b3_2_5 = new TH1D("Mb2b3_2_5", "#lambda = 2.5, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 23} [GeV];", nbins, ptmin, ptmax);
	Mb2b4_2_5 = new TH1D("Mb2b4_2_5", "#lambda = 2.5, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 24} [GeV];", nbins, ptmin, ptmax);
	Mb3b4_2_5 = new TH1D("Mb3b4_2_5", "#lambda = 2.5, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 34} [GeV];", nbins, ptmin, ptmax);
	return;
}
void Set_FinalJetPtProps_2_5()
{
	int nbins = 15; 
	Int_t nbinsMinus = nbins - 1; 
	Float_t pt_bins[15] = {20., 30., 40., 50., 60., 70., 80., 90., 100., 110., 120., 130., 140., 150., 500.};
	//b-jet leading Pt
	Ana_bjetLPt2_5  = new TH1D("Ana_bjetLPt2_5", "Jet p_{T} after analysis cuts; p_{T, leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	//b-jet 2nd leading Pt
	Ana_bjet2LPt2_5  = new TH1D("Ana_bjet2LPt2_5", "Jet p_{T} after analysis cuts; p_{T, sub leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	//b-jet 3rd leading Pt
	Ana_bjet3LPt2_5  = new TH1D("Ana_bjet3LPt2_5", "Jet p_{T} after analysis cuts; p_{T, 3rd leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	//b-jet 4th leading Pt
	Ana_bjet4LPt2_5  = new TH1D("Ana_bjet4LPt2_5", "Jet p_{T} after analysis cuts; p_{T, 4th leading b-jet} [GeV/c];", nbinsMinus, pt_bins);
	return;
}
void Set_jetPtProps_2_5()
{
	int nbins = 60;
	float ptmin = 0;
	float ptmax = 300;
	float dptmin = 0;
	float dptmax = 300;
	//b-jet leading Pt
	bjetLPt2_5  = new TH1D("bjetLPt2_5", "b-tagged Jet p_{t}; p_{t, leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 2nd leading Pt
	bjet2LPt2_5  = new TH1D("bjet2LPt2_5", "b-tagged Jet p_{t}; p_{t, sub leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 3rd leading Pt
	bjet3LPt2_5  = new TH1D("bjet3LPt2_5", "b-tagged Jet p_{t}; p_{t, 3rd leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 4th leading Pt
	bjet4LPt2_5  = new TH1D("bjet4LPt2_5", "b-tagged Jet p_{t}; p_{t, 4th leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	
	//jet leading Pt
	jetLPt2_5  = new TH1D("jetLPt2_5", "Jet p_{t}; p_{t, leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 2nd leading Pt
	jet2LPt2_5  = new TH1D("jet2LPt2_5", "Jet p_{t}; p_{t, sub leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 3rd leading Pt
	jet3LPt2_5  = new TH1D("jet3LPt2_5", "Jet p_{t}; p_{t, 3rd leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 4th leading Pt
	jet4LPt2_5  = new TH1D("jet4LPt2_5", "Jet p_{t}; p_{t, 4th leading jet} [GeV/c];", nbins, ptmin, ptmax);

	//jet leading M
	jetLM2_5  = new TH1D("jetLM2_5", "Jet invariant mass; m_{ leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 2nd leading M
	jet2LM2_5  = new TH1D("jet2LM2_5", "Jet invariant mass; m_{ sub leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 3rd leading M
	jet3LM2_5  = new TH1D("jet3LM2_5", "Jet invariant mass; m_{ 3rd leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 4th leading M
	jet4LM2_5  = new TH1D("jet4LM2_5", "Jet invariant mass; m_{ 4th leading jet} [GeV];", nbins, ptmin, ptmax);
	
	//bjet leading M
	bjetLM2_5  = new TH1D("bjetLM2_5", "Jet invariant mass; m_{ leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 2nd leading M
	bjet2LM2_5  = new TH1D("bjet2LM2_5", "Jet invariant mass; m_{ sub leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 3rd leading M
	bjet3LM2_5  = new TH1D("bjet3LM2_5", "Jet invariant mass; m_{ 3rd leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 4th leading M
	bjet4LM2_5  = new TH1D("bjet4LM2_5", "Jet invariant mass; m_{ 4th leading bjet} [GeV];", nbins, ptmin, ptmax);
	
	// invariant mass of a pair of b's, ctr = 1.0
	M_b1b2_2_5 = new TH1D("M_b1b2_2_5", "Invariant mass of the higgs candidates; m_{higgs candidate, 12} [GeV];", nbins, ptmin, ptmax);
	M_b1b3_2_5 = new TH1D("M_b1b3_2_5", "Invariant mass of the higgs candidates; m_{higgs candidate, 13} [GeV];", nbins, ptmin, ptmax);
	M_b1b4_2_5 = new TH1D("M_b1b4_2_5", "Invariant mass of the higgs candidates; m_{higgs candidate, 14} [GeV];", nbins, ptmin, ptmax);
	M_b2b3_2_5 = new TH1D("M_b2b3_2_5", "Invariant mass of the higgs candidates; m_{higgs candidate, 23} [GeV];", nbins, ptmin, ptmax);
	M_b2b4_2_5 = new TH1D("M_b2b4_2_5", "Invariant mass of the higgs candidates; m_{higgs candidate, 24} [GeV];", nbins, ptmin, ptmax);
	M_b3b4_2_5 = new TH1D("M_b3b4_2_5", "Invariant mass of the higgs candidates; m_{higgs candidate, 34} [GeV];", nbins, ptmin, ptmax);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_2_5 = new TH1D("dM_b1b2_b3b4_2_5", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1234} [GeV];", nbins, dptmin, dptmax);
	dM_b1b3_b2b4_2_5 = new TH1D("dM_b1b3_b2b4_2_5", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1324} [GeV];", nbins, dptmin, dptmax);
	dM_b1b4_b2b3_2_5 = new TH1D("dM_b1b4_b2b3_2_5", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1423} [GeV];", nbins, dptmin, dptmax);

	combi_selected_2_5 = new TH1D("combi_selected_2_5", "Selected combination", 3, 1, 4);
	return;
}
void Draw_InvariantMass_2_5()
{

	//! higgs's
	if(v2_5_higgsPt->size() == 2)
	{
		higgs1_2_5.SetPtEtaPhiM((*v2_5_higgsPt)[0], (*v2_5_higgsEta)[0], (*v2_5_higgsPhi)[0], (*v2_5_higgsM)[0]);
		higgs2_2_5.SetPtEtaPhiM((*v2_5_higgsPt)[1], (*v2_5_higgsEta)[1], (*v2_5_higgsPhi)[1], (*v2_5_higgsM)[1]);
		H1H2_2_5 = higgs1_2_5 + higgs2_2_5;
		
		MH1H2_2_5->Fill(H1H2_2_5.M()*1e-3);
		PtH1H2_2_5->Fill(H1H2_2_5.Pt()*1e-3);
	}
	//! b's
	if(v2_5_bPt->size() == 4)
	{
		b1_2_5.SetPtEtaPhiM((*v2_5_bPt)[0], (*v2_5_bEta)[0], (*v2_5_bPhi)[0], (*v2_5_bM)[0]);
		b2_2_5.SetPtEtaPhiM((*v2_5_bPt)[1], (*v2_5_bEta)[1], (*v2_5_bPhi)[1], (*v2_5_bM)[1]);
		b3_2_5.SetPtEtaPhiM((*v2_5_bPt)[2], (*v2_5_bEta)[2], (*v2_5_bPhi)[2], (*v2_5_bM)[2]);
		b4_2_5.SetPtEtaPhiM((*v2_5_bPt)[3], (*v2_5_bEta)[3], (*v2_5_bPhi)[3], (*v2_5_bM)[3]);

		b1b2_2_5 = b1_2_5 + b2_2_5;
		b1b3_2_5 = b1_2_5 + b3_2_5;
		b1b4_2_5 = b1_2_5 + b4_2_5;
		b2b3_2_5 = b2_2_5 + b3_2_5;
		b2b4_2_5 = b2_2_5 + b4_2_5;
		b3b4_2_5 = b3_2_5 + b4_2_5;
		
		Mb1b2_2_5->Fill(b1b2_2_5.M()*1e-3);
		Mb1b3_2_5->Fill(b1b3_2_5.M()*1e-3);
		Mb1b4_2_5->Fill(b1b4_2_5.M()*1e-3);
		Mb2b3_2_5->Fill(b2b3_2_5.M()*1e-3);
		Mb2b4_2_5->Fill(b2b4_2_5.M()*1e-3);
		Mb3b4_2_5->Fill(b3b4_2_5.M()*1e-3);
	}

	return;
}
//void Fill_InvariantMass_2_5()
//{
//	Mb1b2_2_5->Fill(b1b2_2_5.M()*1e-3);
//	Mb1b3_2_5->Fill(b1b3_2_5.M()*1e-3);
//	Mb1b4_2_5->Fill(b1b4_2_5.M()*1e-3);
//	Mb2b3_2_5->Fill(b2b3_2_5.M()*1e-3);
//	Mb2b4_2_5->Fill(b2b4_2_5.M()*1e-3);
//	Mb3b4_2_5->Fill(b3b4_2_5.M()*1e-3);
//
//	MH1H2_2_5->Fill(H1H2_2_5.M()*1e-3);
//	PtH1H2_2_5->Fill(H1H2_2_5.Pt()*1e-3);
//	return;
//}
void Fill_NLeadingJetPtM_2_5()
{
	jetLPt2_5->Fill((*v2_5_jetPt)[0]*1e-3);
	jet2LPt2_5->Fill((*v2_5_jetPt)[1]*1e-3);
	jet3LPt2_5->Fill((*v2_5_jetPt)[2]*1e-3);
	jet4LPt2_5->Fill((*v2_5_jetPt)[3]*1e-3);
	
	jetLM2_5->Fill( (*v2_5_jetM)[0]*1e-3);
	jet2LM2_5->Fill((*v2_5_jetM)[1]*1e-3);
	jet3LM2_5->Fill((*v2_5_jetM)[2]*1e-3);
	jet4LM2_5->Fill((*v2_5_jetM)[3]*1e-3);

	return;
}
void Fill_bjetPtM_2_5(int &nhiggs)
{
	bjetLPt2_5->Fill( bJ1_2_5.Pt()*1e-3);
	bjet2LPt2_5->Fill(bJ2_2_5.Pt()*1e-3);
	bjet3LPt2_5->Fill(bJ3_2_5.Pt()*1e-3);
	bjet4LPt2_5->Fill(bJ4_2_5.Pt()*1e-3);

	bjetLM2_5->Fill( bJ1_2_5.M()*1e-3);
	bjet2LM2_5->Fill(bJ2_2_5.M()*1e-3);
	bjet3LM2_5->Fill(bJ3_2_5.M()*1e-3);
	bjet4LM2_5->Fill(bJ4_2_5.M()*1e-3);
	
	M_b1b2_2_5->Fill(bJ1bJ2_2_5.M()*1e-3);
	M_b1b3_2_5->Fill(bJ1bJ3_2_5.M()*1e-3);
	M_b1b4_2_5->Fill(bJ1bJ4_2_5.M()*1e-3);
	M_b2b3_2_5->Fill(bJ2bJ3_2_5.M()*1e-3);
	M_b2b4_2_5->Fill(bJ2bJ4_2_5.M()*1e-3);
	M_b3b4_2_5->Fill(bJ3bJ4_2_5.M()*1e-3);

	double dm_12_34 = 0, dm_13_24 = 0, dm_14_23 = 0;
	dm_12_34 = std::fabs(bJ1bJ2_2_5.M() - bJ3bJ4_2_5.M())*1e-3;
	dm_13_24 = std::fabs(bJ1bJ3_2_5.M() - bJ2bJ4_2_5.M())*1e-3;
	dm_14_23 = std::fabs(bJ1bJ4_2_5.M() - bJ2bJ3_2_5.M())*1e-3;
	//dM_b1b2_b3b4_2_5->Fill(dm_12_34*1e-3);	
	//dM_b1b3_b2b4_2_5->Fill(dm_13_24*1e-3);	
	//dM_b1b4_b2b3_2_5->Fill(dm_14_23*1e-3);

	//! Higgs Candidate
	int higgs_candidates = -1;
	int min_diffCombi = 999;

	if((std::fabs(bJ1bJ2_2_5.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ3bJ4_2_5.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
		if(dm_12_34 < min_diffCombi) 
		{
			min_diffCombi = dm_12_34;
			higgs_candidates = 1234;
		}
	}

	if((std::fabs(bJ1bJ3_2_5.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ4_2_5.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
		if(dm_13_24 < min_diffCombi) 
		{
			min_diffCombi = dm_13_24;
			higgs_candidates = 1324;
		}
	}

	if((std::fabs(bJ1bJ4_2_5.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ3_2_5.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
		if(dm_14_23 < min_diffCombi)
		{
			min_diffCombi = dm_14_23;
			higgs_candidates = 1423;
		}
	}

	if(higgs_candidates == 1234)
	{
		//if((std::fabs(bJ1bJ2_2_5.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ3bJ4_2_5.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		//{
			combi_selected_2_5->Fill(1);
			nhiggs++;
			//! Fill four jet pt after all selection
			Ana_bjetLPt2_5->Fill( bJ1_2_5.Pt()*1e-3);
			Ana_bjet2LPt2_5->Fill(bJ2_2_5.Pt()*1e-3);
			Ana_bjet3LPt2_5->Fill(bJ3_2_5.Pt()*1e-3);
			Ana_bjet4LPt2_5->Fill(bJ4_2_5.Pt()*1e-3);
			if(bJ1bJ2_2_5.M() > bJ3bJ4_2_5.M())
			{
				M_Lhiggs2_5->Fill(bJ1bJ2_2_5.M()*1e-3);
				M_NLhiggs2_5->Fill(bJ3bJ4_2_5.M()*1e-3);
				Pt_Lhiggs2_5->Fill(bJ1bJ2_2_5.Pt()*1e-3);
				Pt_NLhiggs2_5->Fill(bJ3bJ4_2_5.Pt()*1e-3);
			
			} 
			else
			{
				M_Lhiggs2_5->Fill(bJ3bJ4_2_5.M()*1e-3);
				M_NLhiggs2_5->Fill(bJ1bJ2_2_5.M()*1e-3);
				Pt_Lhiggs2_5->Fill(bJ3bJ4_2_5.Pt()*1e-3);
				Pt_NLhiggs2_5->Fill(bJ1bJ2_2_5.Pt()*1e-3);
				
			}
			RecH1H2_2_5 = bJ1bJ2_2_5 + bJ3bJ4_2_5;
			RecMH1H2_2_5->Fill(RecH1H2_2_5.M()*1e-3);
			RecPtH1H2_2_5->Fill(RecH1H2_2_5.Pt()*1e-3);
		
			dM_b1b2_b3b4_2_5->Fill(dm_12_34);	
		//}
	}
	else if(higgs_candidates == 1324)
	{
		//if((std::fabs(bJ1bJ3_2_5.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ4_2_5.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		//{
			combi_selected_2_5->Fill(2);
			nhiggs++;
			//! Fill four jet pt after all selection
			Ana_bjetLPt2_5->Fill( bJ1_2_5.Pt()*1e-3);
			Ana_bjet2LPt2_5->Fill(bJ2_2_5.Pt()*1e-3);
			Ana_bjet3LPt2_5->Fill(bJ3_2_5.Pt()*1e-3);
			Ana_bjet4LPt2_5->Fill(bJ4_2_5.Pt()*1e-3);
			if(bJ1bJ3_2_5.M() > bJ2bJ4_2_5.M())
			{
				M_Lhiggs2_5->Fill(bJ1bJ3_2_5.M()*1e-3);
				M_NLhiggs2_5->Fill(bJ2bJ4_2_5.M()*1e-3);
				Pt_Lhiggs2_5->Fill(bJ1bJ3_2_5.Pt()*1e-3);
				Pt_NLhiggs2_5->Fill(bJ2bJ4_2_5.Pt()*1e-3);
			
			} 
			else
			{
				M_Lhiggs2_5->Fill(bJ2bJ4_2_5.M()*1e-3);
				M_NLhiggs2_5->Fill(bJ1bJ3_2_5.M()*1e-3);
				Pt_Lhiggs2_5->Fill(bJ2bJ4_2_5.Pt()*1e-3);
				Pt_NLhiggs2_5->Fill(bJ1bJ3_2_5.Pt()*1e-3);
				
			}
			RecH1H2_2_5 = bJ1bJ3_2_5 + bJ2bJ4_2_5;
			RecMH1H2_2_5->Fill(RecH1H2_2_5.M()*1e-3);
			RecPtH1H2_2_5->Fill(RecH1H2_2_5.Pt()*1e-3);
			
			dM_b1b3_b2b4_2_5->Fill(dm_13_24);	
		//}
	
	}
	else if(higgs_candidates == 1423)
	{
		//if((std::fabs(bJ1bJ4_2_5.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ3_2_5.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		//{
			combi_selected_2_5->Fill(3);
			nhiggs++;
			//! Fill four jet pt after all selection
			Ana_bjetLPt2_5->Fill( bJ1_2_5.Pt()*1e-3);
			Ana_bjet2LPt2_5->Fill(bJ2_2_5.Pt()*1e-3);
			Ana_bjet3LPt2_5->Fill(bJ3_2_5.Pt()*1e-3);
			Ana_bjet4LPt2_5->Fill(bJ4_2_5.Pt()*1e-3);
			if(bJ1bJ4_2_5.M() > bJ2bJ3_2_5.M())
			{
				M_Lhiggs2_5->Fill(bJ1bJ4_2_5.M()*1e-3);
				M_NLhiggs2_5->Fill(bJ2bJ3_2_5.M()*1e-3);
				Pt_Lhiggs2_5->Fill(bJ1bJ4_2_5.Pt()*1e-3);
				Pt_NLhiggs2_5->Fill(bJ2bJ3_2_5.Pt()*1e-3);
			
			} 
			else
			{
				M_Lhiggs2_5->Fill(bJ2bJ3_2_5.M()*1e-3);
				M_NLhiggs2_5->Fill(bJ1bJ4_2_5.M()*1e-3);
				Pt_Lhiggs2_5->Fill(bJ2bJ3_2_5.Pt()*1e-3);
				Pt_NLhiggs2_5->Fill(bJ1bJ4_2_5.Pt()*1e-3);
				
			}
			RecH1H2_2_5 = bJ1bJ4_2_5 + bJ2bJ3_2_5;
			RecMH1H2_2_5->Fill(RecH1H2_2_5.M()*1e-3);
			RecPtH1H2_2_5->Fill(RecH1H2_2_5.Pt()*1e-3);
			
			dM_b1b4_b2b3_2_5->Fill(dm_14_23);
		//}
	
	}

	return;
}
void Draw_DiJetInvariantMass_2_5(int &nb2_5, int &nhiggs)
{
	v2_5_bjetPt.clear();
	v2_5_bjetEta.clear();
	v2_5_bjetPhi.clear();
	v2_5_bjetM.clear();
	for(int j = 0; j < v2_5_tagFlavor->size(); j++)
	{
		if((*v2_5_tagFlavor)[j] != 5) continue;
		v2_5_bjetPt.push_back((*v2_5_jetPt)[j]);
		v2_5_bjetEta.push_back((*v2_5_jetEta)[j]);
		v2_5_bjetPhi.push_back((*v2_5_jetPhi)[j]);
		v2_5_bjetM.push_back((*v2_5_jetM)[j]);

	}
	
	//! b jet's
	if(v2_5_bjetPt.size() > 3)
	{
		if(v2_5_bjetPt[0]*1e-3 >= minLeadingPt  && v2_5_bjetPt[1]*1e-3 >= minSubLeadingPt  && v2_5_bjetPt[2]*1e-3 >= third_Pt_cut && v2_5_bjetPt[3]*1e-3 >= default_Pt_cut )
		{
			nb2_5++;
			bJ1_2_5.SetPtEtaPhiM(v2_5_bjetPt[0], v2_5_bjetEta[0], v2_5_bjetPhi[0], v2_5_bjetM[0]);
			bJ2_2_5.SetPtEtaPhiM(v2_5_bjetPt[1], v2_5_bjetEta[1], v2_5_bjetPhi[1], v2_5_bjetM[1]);
			bJ3_2_5.SetPtEtaPhiM(v2_5_bjetPt[2], v2_5_bjetEta[2], v2_5_bjetPhi[2], v2_5_bjetM[2]);
			bJ4_2_5.SetPtEtaPhiM(v2_5_bjetPt[3], v2_5_bjetEta[3], v2_5_bjetPhi[3], v2_5_bjetM[3]);

			bJ1bJ2_2_5 = bJ1_2_5 + bJ2_2_5;
			bJ1bJ3_2_5 = bJ1_2_5 + bJ3_2_5;
			bJ1bJ4_2_5 = bJ1_2_5 + bJ4_2_5;
			bJ2bJ3_2_5 = bJ2_2_5 + bJ3_2_5;
			bJ2bJ4_2_5 = bJ2_2_5 + bJ4_2_5;
			bJ3bJ4_2_5 = bJ3_2_5 + bJ4_2_5;

			Fill_bjetPtM_2_5(nhiggs);
		}
	}
	return;
}
void SetLineWidth2_5()
{

	MH1H2_2_5->SetLineWidth(LINE_WIDTH); 
	PtH1H2_2_5->SetLineWidth(LINE_WIDTH); 

	Mb1b2_2_5->SetLineWidth(LINE_WIDTH); 
	Mb1b3_2_5->SetLineWidth(LINE_WIDTH);
	Mb1b4_2_5->SetLineWidth(LINE_WIDTH);
	Mb2b3_2_5->SetLineWidth(LINE_WIDTH);
	Mb2b4_2_5->SetLineWidth(LINE_WIDTH);
	Mb3b4_2_5->SetLineWidth(LINE_WIDTH);

	h_NbTags2_5->SetLineWidth(LINE_WIDTH);
	NSMhiggs2_5->SetLineWidth(LINE_WIDTH);
	Nbquarks2_5->SetLineWidth(LINE_WIDTH);
	Njets2_5->SetLineWidth(LINE_WIDTH);
	higgsPt2_5->SetLineWidth(LINE_WIDTH);
	higgsNLPt2_5->SetLineWidth(LINE_WIDTH);
	M_Lhiggs2_5->SetLineWidth(LINE_WIDTH);
	M_NLhiggs2_5->SetLineWidth(LINE_WIDTH);
	Pt_Lhiggs2_5->SetLineWidth(LINE_WIDTH);
	Pt_NLhiggs2_5->SetLineWidth(LINE_WIDTH);
	RecMH1H2_2_5->SetLineWidth(LINE_WIDTH);
	RecPtH1H2_2_5->SetLineWidth(LINE_WIDTH);

	// invariant mass of a pair of b's, ctr = 2.5
	M_b1b2_2_5->SetLineWidth(LINE_WIDTH);
	M_b1b3_2_5->SetLineWidth(LINE_WIDTH);
	M_b1b4_2_5->SetLineWidth(LINE_WIDTH);
	M_b2b3_2_5->SetLineWidth(LINE_WIDTH);
	M_b2b4_2_5->SetLineWidth(LINE_WIDTH);
	M_b3b4_2_5->SetLineWidth(LINE_WIDTH);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_2_5->SetLineWidth(LINE_WIDTH);
	dM_b1b3_b2b4_2_5->SetLineWidth(LINE_WIDTH);
	dM_b1b4_b2b3_2_5->SetLineWidth(LINE_WIDTH);

	jetLM2_5->SetLineWidth(LINE_WIDTH);
	jet2LM2_5->SetLineWidth(LINE_WIDTH);
	jet3LM2_5->SetLineWidth(LINE_WIDTH);
	jet4LM2_5->SetLineWidth(LINE_WIDTH);

	bjetLM2_5->SetLineWidth(LINE_WIDTH);
	bjet2LM2_5->SetLineWidth(LINE_WIDTH);
	bjet3LM2_5->SetLineWidth(LINE_WIDTH);
	bjet4LM2_5->SetLineWidth(LINE_WIDTH);

	jetLPt2_5->SetLineWidth(LINE_WIDTH);
	jet2LPt2_5->SetLineWidth(LINE_WIDTH);
	jet3LPt2_5->SetLineWidth(LINE_WIDTH);
	jet4LPt2_5->SetLineWidth(LINE_WIDTH);

	bjetLPt2_5->SetLineWidth(LINE_WIDTH);
	bjet2LPt2_5->SetLineWidth(LINE_WIDTH);
	bjet3LPt2_5->SetLineWidth(LINE_WIDTH);
	bjet4LPt2_5->SetLineWidth(LINE_WIDTH);

	bLPt2_5->SetLineWidth(LINE_WIDTH);
	b2LPt2_5->SetLineWidth(LINE_WIDTH);
	b3LPt2_5->SetLineWidth(LINE_WIDTH);
	b4LPt2_5->SetLineWidth(LINE_WIDTH);

	bCEta2_5->SetLineWidth(LINE_WIDTH);
	b2CEta2_5->SetLineWidth(LINE_WIDTH);
	b3CEta2_5->SetLineWidth(LINE_WIDTH);
	b4CEta2_5->SetLineWidth(LINE_WIDTH);

	Ana_bjetLPt2_5->SetLineWidth(LINE_WIDTH);
	Ana_bjet2LPt2_5->SetLineWidth(LINE_WIDTH);
	Ana_bjet3LPt2_5->SetLineWidth(LINE_WIDTH);
	Ana_bjet4LPt2_5->SetLineWidth(LINE_WIDTH);
	return;
}
void Scale_signalHistos2_5(double norm)
{

	MH1H2_2_5->Scale(norm); 
	PtH1H2_2_5->Scale(norm); 

	Mb1b2_2_5->Scale(norm); 
	Mb1b3_2_5->Scale(norm);
	Mb1b4_2_5->Scale(norm);
	Mb2b3_2_5->Scale(norm);
	Mb2b4_2_5->Scale(norm);
	Mb3b4_2_5->Scale(norm);

	h_NbTags2_5->Scale(norm);
	NSMhiggs2_5->Scale(norm);
	Nbquarks2_5->Scale(norm);
	Njets2_5->Scale(norm);
	higgsPt2_5->Scale(norm);
	higgsNLPt2_5->Scale(norm);
	M_Lhiggs2_5->Scale(norm);
	M_NLhiggs2_5->Scale(norm);
	Pt_Lhiggs2_5->Scale(norm);
	Pt_NLhiggs2_5->Scale(norm);
	RecMH1H2_2_5->Scale(norm);
	RecPtH1H2_2_5->Scale(norm);

	// invariant mass of a pair of b's, ctr = 2.5
	M_b1b2_2_5->Scale(norm);
	M_b1b3_2_5->Scale(norm);
	M_b1b4_2_5->Scale(norm);
	M_b2b3_2_5->Scale(norm);
	M_b2b4_2_5->Scale(norm);
	M_b3b4_2_5->Scale(norm);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_2_5->Scale(norm);
	dM_b1b3_b2b4_2_5->Scale(norm);
	dM_b1b4_b2b3_2_5->Scale(norm);

	jetLM2_5->Scale(norm);
	jet2LM2_5->Scale(norm);
	jet3LM2_5->Scale(norm);
	jet4LM2_5->Scale(norm);

	bjetLM2_5->Scale(norm);
	bjet2LM2_5->Scale(norm);
	bjet3LM2_5->Scale(norm);
	bjet4LM2_5->Scale(norm);

	jetLPt2_5->Scale(norm);
	jet2LPt2_5->Scale(norm);
	jet3LPt2_5->Scale(norm);
	jet4LPt2_5->Scale(norm);

	bjetLPt2_5->Scale(norm);
	bjet2LPt2_5->Scale(norm);
	bjet3LPt2_5->Scale(norm);
	bjet4LPt2_5->Scale(norm);

	bLPt2_5->Scale(norm);
	b2LPt2_5->Scale(norm);
	b3LPt2_5->Scale(norm);
	b4LPt2_5->Scale(norm);

	bCEta2_5->Scale(norm);
	b2CEta2_5->Scale(norm);
	b3CEta2_5->Scale(norm);
	b4CEta2_5->Scale(norm);

	return;
}
void Set_NleadingJetColors_2_5()
{

	bjetLM2_5->SetLineColor(kOrange);
	bjet2LM2_5->SetLineColor(kBlack);
	bjet3LM2_5->SetLineColor(kRed);
	bjet4LM2_5->SetLineColor(kGreen);
	jetLM2_5->SetLineColor(kOrange);
	jet2LM2_5->SetLineColor(kBlack);
	jet3LM2_5->SetLineColor(kRed);
	jet4LM2_5->SetLineColor(kGreen);
	bjetLPt2_5->SetLineColor(kOrange);
	bjet2LPt2_5->SetLineColor(kBlack);
	bjet3LPt2_5->SetLineColor(kRed);
	bjet4LPt2_5->SetLineColor(kGreen);
	jetLPt2_5->SetLineColor(kOrange);
	jet2LPt2_5->SetLineColor(kBlack);
	jet3LPt2_5->SetLineColor(kRed);
	jet4LPt2_5->SetLineColor(kGreen);
	return;
}
void Set_bquark_lambdaColors_2_5()
{

	M_Lhiggs2_5->SetLineColor(kOrange);
	M_NLhiggs2_5->SetLineColor(kOrange);
	Pt_Lhiggs2_5->SetLineColor(kOrange);
	Pt_NLhiggs2_5->SetLineColor(kOrange);
	RecMH1H2_2_5->SetLineColor(kOrange);
	RecPtH1H2_2_5->SetLineColor(kOrange);
	
	bjetLM2_5->SetLineColor(kOrange);
	bjet2LM2_5->SetLineColor(kOrange);
	bjet3LM2_5->SetLineColor(kOrange);
	bjet4LM2_5->SetLineColor(kOrange);
	jetLM2_5->SetLineColor(kOrange);
	jet2LM2_5->SetLineColor(kOrange);
	jet3LM2_5->SetLineColor(kOrange);
	jet4LM2_5->SetLineColor(kOrange);
	jetLPt2_5->SetLineColor(kOrange);
	jet2LPt2_5->SetLineColor(kOrange);
	jet3LPt2_5->SetLineColor(kOrange);
	jet4LPt2_5->SetLineColor(kOrange);
	bjetLPt2_5->SetLineColor(kOrange);
	bjet2LPt2_5->SetLineColor(kOrange);
	bjet3LPt2_5->SetLineColor(kOrange);
	bjet4LPt2_5->SetLineColor(kOrange);
	bLPt2_5->SetLineColor(kOrange);
	b2LPt2_5->SetLineColor(kOrange);
	b3LPt2_5->SetLineColor(kOrange);
	b4LPt2_5->SetLineColor(kOrange);
	bCEta2_5->SetLineColor(kOrange);
	b2CEta2_5->SetLineColor(kOrange);
	b3CEta2_5->SetLineColor(kOrange);
	b4CEta2_5->SetLineColor(kOrange);
	Ana_bjetLPt2_5->SetLineColor(kOrange);
	Ana_bjet2LPt2_5->SetLineColor(kOrange);
	Ana_bjet3LPt2_5->SetLineColor(kOrange);
	Ana_bjet4LPt2_5->SetLineColor(kOrange);
	return;
}
void Draw_Number_bTags_2_5()
{
	h_NbTags2_5 = new TH1D("h_NbTags2_5", "number of b tagged jets, #lambda =2.5", 6, 0, 6);
	t2_5->Draw("Nbtags>>h_NbTags2_5");
	return;
}


