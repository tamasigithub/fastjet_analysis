void ClearLorentzVectors_B()
{
	//! clear the Lorentz vectors
	b1_B = TLorentzVector();
	b2_B = TLorentzVector();
	b3_B = TLorentzVector();
	b4_B = TLorentzVector();

	b1b2_B = TLorentzVector();
	b1b3_B = TLorentzVector();
	b1b4_B = TLorentzVector();
	b2b3_B = TLorentzVector();
	b2b4_B = TLorentzVector();
	b3b4_B = TLorentzVector();
	
	bJ1_B = TLorentzVector(); 
	bJ2_B = TLorentzVector(); 
	bJ3_B = TLorentzVector(); 
	bJ4_B = TLorentzVector(); 
	bJ1bJ2_B = TLorentzVector();
	bJ1bJ3_B = TLorentzVector();
	bJ1bJ4_B = TLorentzVector();
	bJ2bJ3_B = TLorentzVector();
	bJ2bJ4_B = TLorentzVector();
	bJ3bJ4_B = TLorentzVector();

	RecH1H2_B = TLorentzVector();
	return;

}
void fetch_histos_B()
{

	bLPtB->Fill((*vB_bPt)[0]*1e-3);
	b2LPtB->Fill((*vB_bPt)[1]*1e-3);
	b3LPtB->Fill((*vB_bPt)[2]*1e-3);
	b4LPtB->Fill((*vB_bPt)[3]*1e-3);
	
	bCEtaB  = (TH1D*)fB->Get("hbEta_Ceta");
	b2CEtaB = (TH1D*)fB->Get("hbEta_NCeta");
	b3CEtaB = (TH1D*)fB->Get("hbEta_NNCeta");
	b4CEtaB = (TH1D*)fB->Get("hbEta_NNNCeta");

	bCEtaB ->Add( (TH1D*)fB_1->Get("hbEta_Ceta") );
	b2CEtaB->Add( (TH1D*)fB_1->Get("hbEta_NCeta") );
	b3CEtaB->Add( (TH1D*)fB_1->Get("hbEta_NNCeta") );
	b4CEtaB->Add( (TH1D*)fB_1->Get("hbEta_NNNCeta") );
	//bCEtaB->Fill((*vB_bEta)[0]);
	//b2CEtaB->Fill((*vB_bEta)[1]);
	//b3CEtaB->Fill((*vB_bEta)[2]);
	//b4CEtaB->Fill((*vB_bEta)[3]);

	
	//bLPtB  = (TH1D*)fB->Get("hbPt_Lpt");
	//b2LPtB = (TH1D*)fB->Get("hbPt_NLpt");
	//b3LPtB = (TH1D*)fB->Get("hbPt_NNLpt");
	//b4LPtB = (TH1D*)fB->Get("hbPt_NNNLpt");

	//bCEtaB  = (TH1D*)fB->Get("hbEta_Ceta");
	//b2CEtaB = (TH1D*)fB->Get("hbEta_NCeta");
	//b3CEtaB = (TH1D*)fB->Get("hbEta_NNCeta");
	//b4CEtaB = (TH1D*)fB->Get("hbEta_NNNCeta");
	return;
}
void Draw_b_jetPt_B()
{
	tB.Draw("bJetLPt>>bjetLPtB");
	tB.Draw("bJetNLPt>>bjet2LPtB");
	tB.Draw("bJetNNLPt>>bjet3LPtB");
	tB.Draw("bJetNNNLPt>>bjet4LPtB");

	return;
}
void Draw_Nparticles_B()
{
	int nbins = 6, nbins_1 = 20;
	double nmin = 0, nmax = 6, nmax_1 = 20;
	NbquarksB  = new TH1D("NbquarksB", "number of b quarks", nbins, nmin, nmax);
	NjetsB  = new TH1D("NjetsB", "number of jets", nbins_1, nmin, nmax_1);
	tB.Draw("Nbquarks>>NbquarksB");
	tB.Draw("Njets>>NjetsB");
	NbquarksB->SetLineColor(kCyan);
	NjetsB->SetLineColor(kCyan);
	return;
}
void fetch_TTrees_B()
{
	//tB   = (TTree*)fB->Get("glob_jet");

	tB.SetBranchStatus("*",0);
	
	tB.SetBranchStatus("Nbquarks",1);
	tB.SetBranchStatus("Njets",1);
	tB.SetBranchStatus("jetPt",1);
	tB.SetBranchStatus("jetEta",1);
	tB.SetBranchStatus("jetPhi",1);
	tB.SetBranchStatus("jetM",1);
	tB.SetBranchStatus("btaggedFlavor",1);
	tB.SetBranchStatus("bJetLPt",1);
	tB.SetBranchStatus("bJetNLPt",1);
	tB.SetBranchStatus("bJetNNLPt",1);
	tB.SetBranchStatus("bJetNNNLPt",1);
	tB.SetBranchStatus("Nbtags",1);
	tB.SetBranchStatus("v_bPt", 1);
	tB.SetBranchStatus("v_bEta",1);
	tB.SetBranchStatus("v_bPhi",1);
	tB.SetBranchStatus("v_bM",  1);

	tB.SetBranchAddress("jetPt",  &vB_jetPt);;
	tB.SetBranchAddress("jetEta",  &vB_jetEta);
	tB.SetBranchAddress("jetPhi",  &vB_jetPhi);
	tB.SetBranchAddress("jetM",  &vB_jetM);
	tB.SetBranchAddress("btaggedFlavor",  &vB_tagFlavor);
	tB.SetBranchAddress("Nbtags",&nB_btags);
	tB.SetBranchAddress("v_bPt", &vB_bPt);
	tB.SetBranchAddress("v_bEta",&vB_bEta);
	tB.SetBranchAddress("v_bPhi",&vB_bPhi);
	tB.SetBranchAddress("v_bM",  &vB_bM);
	return;
}
void Set_higgsPtProps_B()
{
	int nbins = 60;
	float ptmin = 0;
	float ptmax = 600;
	float Mmin = 200;
	float Mmax = 1400;
	
	
	//! reconstructed leading and sub leading higgs pt
	Pt_LhiggsB  = new TH1D("Pt_LhiggsB",  " BackGround Reconnstructed higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	Pt_NLhiggsB  = new TH1D("Pt_NLhiggsB",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);
	M_LhiggsB  = new TH1D("M_LhiggsB",  "BackGround Reconstructed Invariant higgs mass;m_{rec, leading higgs} [GeV];", nbins, ptmin, ptmax);
	M_NLhiggsB  = new TH1D("M_NLhiggsB",  "Background Reconstructed Invariant higgs mass;m_{rec, sub leading higgs} [GeV];", nbins, ptmin, ptmax);
	
	//! reconstructed Inv mass of the di-higgs system
	RecMH1H2_B  = new TH1D("RecMH1H2_B",  "Background Invariant di-higgs mass;m_{truth, h1,h2} [GeV];", nbins, Mmin, Mmax);
	//! reconstructed Pt of the di-higgs system
	RecPtH1H2_B  = new TH1D("RecPtH1H2_B",  "Background Transverse momentum of the di-higgs system;p_{T, truth, h1,h2} [GeV/c];", nbins, ptmin, ptmax);

	// invariant mass of a pair of b's, pp->4b
	Mb1b2_B = new TH1D("Mb1b2_B", "Background, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 12} [GeV];", nbins, ptmin, ptmax);
	Mb1b3_B = new TH1D("Mb1b3_B", "Background, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 13} [GeV];", nbins, ptmin, ptmax);
	Mb1b4_B = new TH1D("Mb1b4_B", "Background, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 14} [GeV];", nbins, ptmin, ptmax);
	Mb2b3_B = new TH1D("Mb2b3_B", "Background, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 23} [GeV];", nbins, ptmin, ptmax);
	Mb2b4_B = new TH1D("Mb2b4_B", "Background, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 24} [GeV];", nbins, ptmin, ptmax);
	Mb3b4_B = new TH1D("Mb3b4_B", "Background, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 34} [GeV];", nbins, ptmin, ptmax);
	return;
}
void Set_FinalJetPtProps_B()
{
	int nbins = 15; 
	Int_t nbinsPlus1 = nbins - 1; 
	Float_t pt_bins[15] = {20., 30., 40., 50., 60., 70., 80., 90., 100., 110., 120., 130., 140., 150., 500.};
	//b-jet leading Pt
	Ana_bjetLPtB  = new TH1D("Ana_bjetLPtB", "BG Jet p_{T} after analysis cuts; p_{T, leading b-jet} [GeV/c];", nbinsPlus1, pt_bins);
	//b-jet 2nd leading Pt
	Ana_bjet2LPtB  = new TH1D("Ana_bjet2LPtB", "BG Jet p_{T} after analysis cuts; p_{T, sub leading b-jet} [GeV/c];", nbinsPlus1, pt_bins);
	//b-jet 3rd leading Pt
	Ana_bjet3LPtB  = new TH1D("Ana_bjet3LPtB", "BG Jet p_{T} after analysis cuts; p_{T, 3rd leading b-jet} [GeV/c];", nbinsPlus1, pt_bins);
	//b-jet 4th leading Pt
	Ana_bjet4LPtB  = new TH1D("Ana_bjet4LPtB", "BG Jet p_{T} after analysis cuts; p_{T, 4th leading b-jet} [GeV/c];", nbinsPlus1, pt_bins);
	return;
}
void Set_jetPtProps_B()
{
	int nbins = 60;
	//int netabins = 100;
	//float etamin = 0;
	//float etamax = 6.0;
	float ptmin = 0;
	float ptmax = 300;
	float dptmin = 0;
	float dptmax = 300;
	////b central Pt
	//bCEtaB  = new TH1D("bCEtaB", "b quark #eta_{b}; #eta_{b, central b quark} ;", netabins, etamin, etamax);
	////b 2nd central Pt
	//b2CEtaB  = new TH1D("b2CEtaB", "b quark #eta_{b}; #eta_{b, sub central b quark} ;", netabins, etamin, etamax);
	////b 3rd central Pt
	//b3CEtaB  = new TH1D("b3CEtaB", "b quark #eta_{b}; #eta_{b, 3rd central b quark} ;", netabins, etamin, etamax);
	////b 4th central Pt
	//b4CEtaB  = new TH1D("b4CEtaB", "b quark #eta_{b}; #eta_{b, 4th central b quark} ;", netabins, etamin, etamax);
	
	//b leading Pt
	bLPtB  = new TH1D("bLPtB", "b quark p_{T}; p_{T, leading b quark} [GeV/c];", nbins, ptmin, ptmax);
	//b 2nd leading Pt
	b2LPtB  = new TH1D("b2LPtB", "b quark p_{T}; p_{T, sub leading b quark} [GeV/c];", nbins, ptmin, ptmax);
	//b 3rd leading Pt
	b3LPtB  = new TH1D("b3LPtB", "b quark p_{T}; p_{T, 3rd leading b quark} [GeV/c];", nbins, ptmin, ptmax);
	//b 4th leading Pt
	b4LPtB  = new TH1D("b4LPtB", "b quark p_{T}; p_{T, 4th leading b quark} [GeV/c];", nbins, ptmin, ptmax);

	//b-jet leading Pt
	bjetLPtB  = new TH1D("bjetLPtB", "b-tagged Jet p_{T}; p_{T, leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 2nd leading Pt
	bjet2LPtB  = new TH1D("bjet2LPtB", "b-tagged Jet p_{T}; p_{T, sub leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 3rd leading Pt
	bjet3LPtB  = new TH1D("bjet3LPtB", "b-tagged Jet p_{T}; p_{T, 3rd leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 4th leading Pt
	bjet4LPtB  = new TH1D("bjet4LPtB", "b-tagged Jet p_{T}; p_{T, 4th leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	
	//jet leading Pt
	jetLPtB  = new TH1D("jetLPtB", "Jet p_{T}; p_{T, leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 2nd leading Pt
	jet2LPtB  = new TH1D("jet2LPtB", "Jet p_{T}; p_{T, sub leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 3rd leading Pt
	jet3LPtB  = new TH1D("jet3LPtB", "Jet p_{T}; p_{T, 3rd leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 4th leading Pt
	jet4LPtB  = new TH1D("jet4LPtB", "Jet p_{T}; p_{T, 4th leading jet} [GeV/c];", nbins, ptmin, ptmax);
	
	//jet leading M
	jetLMB  = new TH1D("jetLMB", "Jet invariant mass; m_{ leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 2nd leading M
	jet2LMB  = new TH1D("jet2LMB", "Jet invariant mass; m_{ sub leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 3rd leading M
	jet3LMB  = new TH1D("jet3LMB", "Jet invariant mass; m_{ 3rd leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 4th leading M
	jet4LMB  = new TH1D("jet4LMB", "Jet invariant mass; m_{ 4th leading jet} [GeV];", nbins, ptmin, ptmax);
	
	//bjet leading M
	bjetLMB  = new TH1D("bjetLMB", "Jet invariant mass; m_{ leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 2nd leading M
	bjet2LMB  = new TH1D("bjet2LMB", "Jet invariant mass; m_{ sub leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 3rd leading M
	bjet3LMB  = new TH1D("bjet3LMB", "Jet invariant mass; m_{ 3rd leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 4th leading M
	bjet4LMB  = new TH1D("bjet4LMB", "Jet invariant mass; m_{ 4th leading bjet} [GeV];", nbins, ptmin, ptmax);
	

	// invariant mass of a pair of b's, pp->4b
	M_b1b2_B = new TH1D("M_b1b2_B", "Background, Invariant mass of the higgs candidates; m_{higgs candidate, 12} [GeV];", nbins, ptmin, ptmax);
	M_b1b3_B = new TH1D("M_b1b3_B", "Background, Invariant mass of the higgs candidates; m_{higgs candidate, 13} [GeV];", nbins, ptmin, ptmax);
	M_b1b4_B = new TH1D("M_b1b4_B", "Background, Invariant mass of the higgs candidates; m_{higgs candidate, 14} [GeV];", nbins, ptmin, ptmax);
	M_b2b3_B = new TH1D("M_b2b3_B", "Background, Invariant mass of the higgs candidates; m_{higgs candidate, 23} [GeV];", nbins, ptmin, ptmax);
	M_b2b4_B = new TH1D("M_b2b4_B", "Background, Invariant mass of the higgs candidates; m_{higgs candidate, 24} [GeV];", nbins, ptmin, ptmax);
	M_b3b4_B = new TH1D("M_b3b4_B", "Background, Invariant mass of the higgs candidates; m_{higgs candidate, 34} [GeV];", nbins, ptmin, ptmax);
	//scatter plot of the jet pairs
	//only 3 combination of jet pairs possible
	b1b2_b3b4_B = new TH2D("b1b2_b3b4_B", "BG M_{H cand., 34} Vs M_{H cand., 12}; M_{H cand., 12} [GeV];M_{H cand., 34} [GeV]", nbins, ptmin, ptmax, nbins, ptmin, ptmax);
	b1b3_b2b4_B = new TH2D("b1b3_b2b4_B", "BG M_{H cand., 24} Vs M_{H cand., 13}; M_{H cand., 13} [GeV];M_{H cand., 24} [GeV]", nbins, ptmin, ptmax, nbins, ptmin, ptmax);
	b1b4_b2b3_B = new TH2D("b1b4_b2b3_B", "BG M_{H cand., 23} Vs M_{H cand., 14}; M_{H cand., 14} [GeV];M_{H cand., 23} [GeV]", nbins, ptmin, ptmax, nbins, ptmin, ptmax);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_B = new TH1D("dM_b1b2_b3b4_B", "Background, Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1234} [GeV];", nbins, dptmin, dptmax);
	dM_b1b3_b2b4_B = new TH1D("dM_b1b3_b2b4_B", "Background, Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1324} [GeV];", nbins, dptmin, dptmax);
	dM_b1b4_b2b3_B = new TH1D("dM_b1b4_b2b3_B", "Background, Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1423} [GeV];", nbins, dptmin, dptmax);
	
	combi_selected_B = new TH1D("combi_selected_B", "Selected combination", 3, 1, 4);
	return;
}
void Draw_InvariantMass_B()
{
	//! b's
	if(vB_bPt->size() == 4)
	{
		b1_B.SetPtEtaPhiM((*vB_bPt)[0], (*vB_bEta)[0], (*vB_bPhi)[0], (*vB_bM)[0]);
		b2_B.SetPtEtaPhiM((*vB_bPt)[1], (*vB_bEta)[1], (*vB_bPhi)[1], (*vB_bM)[1]);
		b3_B.SetPtEtaPhiM((*vB_bPt)[2], (*vB_bEta)[2], (*vB_bPhi)[2], (*vB_bM)[2]);
		b4_B.SetPtEtaPhiM((*vB_bPt)[3], (*vB_bEta)[3], (*vB_bPhi)[3], (*vB_bM)[3]);

		b1b2_B = b1_B + b2_B;
		b1b3_B = b1_B + b3_B;
		b1b4_B = b1_B + b4_B;
		b2b3_B = b2_B + b3_B;
		b2b4_B = b2_B + b4_B;
		b3b4_B = b3_B + b4_B;
		
		Mb1b2_B->Fill(b1b2_B.M()*1e-3);
		Mb1b3_B->Fill(b1b3_B.M()*1e-3);
		Mb1b4_B->Fill(b1b4_B.M()*1e-3);
		Mb2b3_B->Fill(b2b3_B.M()*1e-3);
		Mb2b4_B->Fill(b2b4_B.M()*1e-3);
		Mb3b4_B->Fill(b3b4_B.M()*1e-3);
	}

	return;
}

//void Fill_InvariantMass_B()
//{
//	Mb1b2_B->Fill(b1b2_B.M()*1e-3);
//	Mb1b3_B->Fill(b1b3_B.M()*1e-3);
//	Mb1b4_B->Fill(b1b4_B.M()*1e-3);
//	Mb2b3_B->Fill(b2b3_B.M()*1e-3);
//	Mb2b4_B->Fill(b2b4_B.M()*1e-3);
//	Mb3b4_B->Fill(b3b4_B.M()*1e-3);
//
//	return;
//}

void Fill_NLeadingJetPtM_B()
{
	jetLPtB->Fill((*vB_jetPt)[0]*1e-3);
	jet2LPtB->Fill((*vB_jetPt)[1]*1e-3);
	jet3LPtB->Fill((*vB_jetPt)[2]*1e-3);
	jet4LPtB->Fill((*vB_jetPt)[3]*1e-3);
	
	jetLMB->Fill( (*vB_jetM)[0]*1e-3);
	jet2LMB->Fill((*vB_jetM)[1]*1e-3);
	jet3LMB->Fill((*vB_jetM)[2]*1e-3);
	jet4LMB->Fill((*vB_jetM)[3]*1e-3);

	return;
}
void Fill_bjetPtM_B(int &nhiggs)
{
	bjetLPtB->Fill( bJ1_B.Pt()*1e-3);
	bjet2LPtB->Fill(bJ2_B.Pt()*1e-3);
	bjet3LPtB->Fill(bJ3_B.Pt()*1e-3);
	bjet4LPtB->Fill(bJ4_B.Pt()*1e-3);

	bjetLMB->Fill( bJ1_B.M()*1e-3);
	bjet2LMB->Fill(bJ2_B.M()*1e-3);
	bjet3LMB->Fill(bJ3_B.M()*1e-3);
	bjet4LMB->Fill(bJ4_B.M()*1e-3);
	
	M_b1b2_B->Fill(bJ1bJ2_B.M()*1e-3);
	M_b1b3_B->Fill(bJ1bJ3_B.M()*1e-3);
	M_b1b4_B->Fill(bJ1bJ4_B.M()*1e-3);
	M_b2b3_B->Fill(bJ2bJ3_B.M()*1e-3);
	M_b2b4_B->Fill(bJ2bJ4_B.M()*1e-3);
	M_b3b4_B->Fill(bJ3bJ4_B.M()*1e-3);

	b1b2_b3b4_B->Fill(bJ1bJ2_B.M()*1e-3,bJ3bJ4_B.M()*1e-3);	
	b1b3_b2b4_B->Fill(bJ1bJ3_B.M()*1e-3,bJ2bJ4_B.M()*1e-3);	
	b1b4_b2b3_B->Fill(bJ1bJ4_B.M()*1e-3,bJ2bJ3_B.M()*1e-3);	

	double dm_12_34 = 0, dm_13_24 = 0, dm_14_23 = 0;
	dm_12_34 = std::fabs(bJ1bJ2_B.M() - bJ3bJ4_B.M())*1e-3;
	dm_13_24 = std::fabs(bJ1bJ3_B.M() - bJ2bJ4_B.M())*1e-3;
	dm_14_23 = std::fabs(bJ1bJ4_B.M() - bJ2bJ3_B.M())*1e-3;
	//dM_b1b2_b3b4_B->Fill(dm_12_34*1e-3);	
	//dM_b1b3_b2b4_B->Fill(dm_13_24*1e-3);	
	//dM_b1b4_b2b3_B->Fill(dm_14_23*1e-3);

	//! Higgs Candidate
	int higgs_candidates = -1;
	int min_diffCombi = 999;
	if((std::fabs(bJ1bJ2_B.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ3bJ4_B.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
		if(dm_12_34 < min_diffCombi) 
		{
			min_diffCombi = dm_12_34;
			higgs_candidates = 1234;
		}
	}

	if((std::fabs(bJ1bJ3_B.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ4_B.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
		if(dm_13_24 < min_diffCombi) 
		{
			min_diffCombi = dm_13_24;
			higgs_candidates = 1324;
		}
	}

	if((std::fabs(bJ1bJ4_B.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ3_B.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
	{
		if(dm_14_23 < min_diffCombi)
		{
			min_diffCombi = dm_14_23;
			higgs_candidates = 1423;
		}
	}
	if(higgs_candidates == 1234)
	{
		//if((std::fabs(bJ1bJ2_B.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ3bJ4_B.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		//{
			combi_selected_B->Fill(1);
			nhiggs++;
			//! Fill four jet pt after all selection
			Ana_bjetLPtB->Fill( bJ1_B.Pt()*1e-3);
			Ana_bjet2LPtB->Fill(bJ2_B.Pt()*1e-3);
			Ana_bjet3LPtB->Fill(bJ3_B.Pt()*1e-3);
			Ana_bjet4LPtB->Fill(bJ4_B.Pt()*1e-3);
			if(bJ1bJ2_B.M() > bJ3bJ4_B.M())
			{
				M_LhiggsB->Fill(bJ1bJ2_B.M()*1e-3);
				M_NLhiggsB->Fill(bJ3bJ4_B.M()*1e-3);
				Pt_LhiggsB->Fill(bJ1bJ2_B.Pt()*1e-3);
				Pt_NLhiggsB->Fill(bJ3bJ4_B.Pt()*1e-3);
			
			} 
			else
			{
				M_LhiggsB->Fill(bJ3bJ4_B.M()*1e-3);
				M_NLhiggsB->Fill(bJ1bJ2_B.M()*1e-3);
				Pt_LhiggsB->Fill(bJ3bJ4_B.Pt()*1e-3);
				Pt_NLhiggsB->Fill(bJ1bJ2_B.Pt()*1e-3);
				
			}
			RecH1H2_B = bJ1bJ2_B + bJ3bJ4_B;
			RecMH1H2_B->Fill(RecH1H2_B.M()*1e-3);
			RecPtH1H2_B->Fill(RecH1H2_B.Pt()*1e-3);
			
			dM_b1b2_b3b4_B->Fill(dm_12_34);	
		//}
	}
	else if(higgs_candidates == 1324)
	{
		//if((std::fabs(bJ1bJ3_B.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ4_B.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		//{
			combi_selected_B->Fill(2);
			nhiggs++;
			//! Fill four jet pt after all selection
			Ana_bjetLPtB->Fill( bJ1_B.Pt()*1e-3);
			Ana_bjet2LPtB->Fill(bJ2_B.Pt()*1e-3);
			Ana_bjet3LPtB->Fill(bJ3_B.Pt()*1e-3);
			Ana_bjet4LPtB->Fill(bJ4_B.Pt()*1e-3);
			if(bJ1bJ3_B.M() > bJ2bJ4_B.M())
			{
				M_LhiggsB->Fill(bJ1bJ3_B.M()*1e-3);
				M_NLhiggsB->Fill(bJ2bJ4_B.M()*1e-3);
				Pt_LhiggsB->Fill(bJ1bJ3_B.Pt()*1e-3);
				Pt_NLhiggsB->Fill(bJ2bJ4_B.Pt()*1e-3);
			
			} 
			else
			{
				M_LhiggsB->Fill(bJ2bJ4_B.M()*1e-3);
				M_NLhiggsB->Fill(bJ1bJ3_B.M()*1e-3);
				Pt_LhiggsB->Fill(bJ2bJ4_B.Pt()*1e-3);
				Pt_NLhiggsB->Fill(bJ1bJ3_B.Pt()*1e-3);
				
			}
			RecH1H2_B = bJ1bJ3_B + bJ2bJ4_B;
			RecMH1H2_B->Fill(RecH1H2_B.M()*1e-3);
			RecPtH1H2_B->Fill(RecH1H2_B.Pt()*1e-3);
			
			dM_b1b3_b2b4_B->Fill(dm_13_24);	
		//}
	
	}
	else if(higgs_candidates == 1423)
	{
		//if((std::fabs(bJ1bJ4_B.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ3_B.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		//{
			combi_selected_B->Fill(3);
			nhiggs++;
			//! Fill four jet pt after all selection
			Ana_bjetLPtB->Fill( bJ1_B.Pt()*1e-3);
			Ana_bjet2LPtB->Fill(bJ2_B.Pt()*1e-3);
			Ana_bjet3LPtB->Fill(bJ3_B.Pt()*1e-3);
			Ana_bjet4LPtB->Fill(bJ4_B.Pt()*1e-3);
			if(bJ1bJ4_B.M() > bJ2bJ3_B.M())
			{
				M_LhiggsB->Fill(bJ1bJ4_B.M()*1e-3);
				M_NLhiggsB->Fill(bJ2bJ3_B.M()*1e-3);
				Pt_LhiggsB->Fill(bJ1bJ4_B.Pt()*1e-3);
				Pt_NLhiggsB->Fill(bJ2bJ3_B.Pt()*1e-3);
			
			} 
			else
			{
				M_LhiggsB->Fill(bJ2bJ3_B.M()*1e-3);
				M_NLhiggsB->Fill(bJ1bJ4_B.M()*1e-3);
				Pt_LhiggsB->Fill(bJ2bJ3_B.Pt()*1e-3);
				Pt_NLhiggsB->Fill(bJ1bJ4_B.Pt()*1e-3);
				
			}
			RecH1H2_B = bJ1bJ4_B + bJ2bJ3_B;
			RecMH1H2_B->Fill(RecH1H2_B.M()*1e-3);
			RecPtH1H2_B->Fill(RecH1H2_B.Pt()*1e-3);
			
			dM_b1b4_b2b3_B->Fill(dm_14_23);
		//}
	
	}

	return;
}

void Draw_DiJetInvariantMass_B(int &nbB, int &nhiggs)
{
	vB_bjetPt.clear();
	vB_bjetEta.clear();
	vB_bjetPhi.clear();
	vB_bjetM.clear();
	for(int j = 0; j < vB_tagFlavor->size(); j++)
	{
		if((*vB_tagFlavor)[j] != 5) continue;
		vB_bjetPt.push_back((*vB_jetPt)[j]);
		vB_bjetEta.push_back((*vB_jetEta)[j]);
		vB_bjetPhi.push_back((*vB_jetPhi)[j]);
		vB_bjetM.push_back((*vB_jetM)[j]);

	}
	
	//! b jet's
	if(vB_bjetPt.size() > 3)
	{
		if(vB_bjetPt[0]*1e-3 >= minLeadingPt  && vB_bjetPt[1]*1e-3 >= minSubLeadingPt  && vB_bjetPt[2]*1e-3 >= third_Pt_cut && vB_bjetPt[3]*1e-3 >= default_Pt_cut )
		{
			nbB++;
			bJ1_B.SetPtEtaPhiM(vB_bjetPt[0], vB_bjetEta[0], vB_bjetPhi[0], vB_bjetM[0]);
			bJ2_B.SetPtEtaPhiM(vB_bjetPt[1], vB_bjetEta[1], vB_bjetPhi[1], vB_bjetM[1]);
			bJ3_B.SetPtEtaPhiM(vB_bjetPt[2], vB_bjetEta[2], vB_bjetPhi[2], vB_bjetM[2]);
			bJ4_B.SetPtEtaPhiM(vB_bjetPt[3], vB_bjetEta[3], vB_bjetPhi[3], vB_bjetM[3]);

			bJ1bJ2_B = bJ1_B + bJ2_B;
			bJ1bJ3_B = bJ1_B + bJ3_B;
			bJ1bJ4_B = bJ1_B + bJ4_B;
			bJ2bJ3_B = bJ2_B + bJ3_B;
			bJ2bJ4_B = bJ2_B + bJ4_B;
			bJ3bJ4_B = bJ3_B + bJ4_B;

			Fill_bjetPtM_B(nhiggs);
		}
	}
	return;
}
void SetLineWidthB()
{
	Mb1b2_B->SetLineWidth(LINE_WIDTH); 
	Mb1b3_B->SetLineWidth(LINE_WIDTH);
	Mb1b4_B->SetLineWidth(LINE_WIDTH);
	Mb2b3_B->SetLineWidth(LINE_WIDTH);
	Mb2b4_B->SetLineWidth(LINE_WIDTH);
	Mb3b4_B->SetLineWidth(LINE_WIDTH);

	//Number of btags 
	h_NbTagsB->SetLineWidth(LINE_WIDTH);
	//Number of bquarks 
	NbquarksB->SetLineWidth(LINE_WIDTH);
	NjetsB->SetLineWidth(LINE_WIDTH);
	//reconstructed leading Higgs mass 
	M_LhiggsB->SetLineWidth(LINE_WIDTH);
	M_NLhiggsB->SetLineWidth(LINE_WIDTH);
	Pt_LhiggsB->SetLineWidth(LINE_WIDTH);
	Pt_NLhiggsB->SetLineWidth(LINE_WIDTH);
	RecMH1H2_B->SetLineWidth(LINE_WIDTH);
	RecPtH1H2_B->SetLineWidth(LINE_WIDTH);

	// invariant mass of a pair of b's, pp->4b
	M_b1b2_B->SetLineWidth(LINE_WIDTH);
	M_b1b3_B->SetLineWidth(LINE_WIDTH);
	M_b1b4_B->SetLineWidth(LINE_WIDTH);
	M_b2b3_B->SetLineWidth(LINE_WIDTH);
	M_b2b4_B->SetLineWidth(LINE_WIDTH);
	M_b3b4_B->SetLineWidth(LINE_WIDTH);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_B->SetLineWidth(LINE_WIDTH);
	dM_b1b3_b2b4_B->SetLineWidth(LINE_WIDTH);
	dM_b1b4_b2b3_B->SetLineWidth(LINE_WIDTH);
	
	
	
	//jet leading M
	jetLMB->SetLineWidth(LINE_WIDTH);
	//jet 2nd leading M
	jet2LMB->SetLineWidth(LINE_WIDTH);
	//jet 3rd leading M
	jet3LMB->SetLineWidth(LINE_WIDTH);
	//jet 4th leading M
	jet4LMB->SetLineWidth(LINE_WIDTH);
	//jet 5th leading M
	//jet5LMB->SetLineWidth(LINE_WIDTH);
	
	//jet leading Pt
	jetLPtB->SetLineWidth(LINE_WIDTH);
	//jet 2nd leading Pt
	jet2LPtB->SetLineWidth(LINE_WIDTH);
	//jet 3rd leading Pt
	jet3LPtB->SetLineWidth(LINE_WIDTH);
	//jet 4th leading Pt
	jet4LPtB->SetLineWidth(LINE_WIDTH);
	//jet 5th leading Pt
	//jet5LPtB->SetLineWidth(LINE_WIDTH);

	//bjet leading M
	bjetLMB->SetLineWidth(LINE_WIDTH);
	//bjet 2nd leading M
	bjet2LMB->SetLineWidth(LINE_WIDTH);
	//bjet 3rd leading M
	bjet3LMB->SetLineWidth(LINE_WIDTH);
	//bjet 4th leading M
	bjet4LMB->SetLineWidth(LINE_WIDTH);
	//bjet 5th leading M
	//bjet5LMB->SetLineWidth(LINE_WIDTH);
	
	//b-jet leading Pt
	bjetLPtB->SetLineWidth(LINE_WIDTH);
	//b-jet 2nd leading Pt
	bjet2LPtB->SetLineWidth(LINE_WIDTH);
	//b-jet 3rd leading Pt
	bjet3LPtB->SetLineWidth(LINE_WIDTH);
	//b-jet 4th leading Pt
	bjet4LPtB->SetLineWidth(LINE_WIDTH);

	//b leading Pt
	bLPtB->SetLineWidth(LINE_WIDTH);
	//b 2nd leading Pt
	b2LPtB->SetLineWidth(LINE_WIDTH);
	//b 3rd leading Pt
	b3LPtB->SetLineWidth(LINE_WIDTH);
	//b 4th leading Pt
	b4LPtB->SetLineWidth(LINE_WIDTH);

	//b central Pt
	bCEtaB->SetLineWidth(LINE_WIDTH);
	//b 2nd central Pt
	b2CEtaB->SetLineWidth(LINE_WIDTH);
	//b 3rd central Pt
	b3CEtaB->SetLineWidth(LINE_WIDTH);
	//b 4th central Pt
	b4CEtaB->SetLineWidth(LINE_WIDTH);
	Ana_bjetLPtB->SetLineWidth(LINE_WIDTH);
	Ana_bjet2LPtB->SetLineWidth(LINE_WIDTH);
	Ana_bjet3LPtB->SetLineWidth(LINE_WIDTH);
	Ana_bjet4LPtB->SetLineWidth(LINE_WIDTH);
	return;
}
void Scale_bckgndHistos(double norm)
{
	Mb1b2_B->Scale(norm); 
	Mb1b3_B->Scale(norm);
	Mb1b4_B->Scale(norm);
	Mb2b3_B->Scale(norm);
	Mb2b4_B->Scale(norm);
	Mb3b4_B->Scale(norm);

	//Number of btags 
	h_NbTagsB->Scale(norm);
	//Number of bquarks 
	NbquarksB->Scale(norm);
	NjetsB->Scale(norm);
	//reconstructed leading Higgs mass 
	M_LhiggsB->Scale(norm);
	M_NLhiggsB->Scale(norm);
	Pt_LhiggsB->Scale(norm);
	Pt_NLhiggsB->Scale(norm);
	RecMH1H2_B->Scale(norm);
	RecPtH1H2_B->Scale(norm);

	// invariant mass of a pair of b's, pp->4b
	M_b1b2_B->Scale(norm);
	M_b1b3_B->Scale(norm);
	M_b1b4_B->Scale(norm);
	M_b2b3_B->Scale(norm);
	M_b2b4_B->Scale(norm);
	M_b3b4_B->Scale(norm);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_B->Scale(norm);
	dM_b1b3_b2b4_B->Scale(norm);
	dM_b1b4_b2b3_B->Scale(norm);
	
	
	
	//jet leading M
	jetLMB->Scale(norm);
	//jet 2nd leading M
	jet2LMB->Scale(norm);
	//jet 3rd leading M
	jet3LMB->Scale(norm);
	//jet 4th leading M
	jet4LMB->Scale(norm);
	//jet 5th leading M
	//jet5LMB->Scale(norm);
	
	//jet leading Pt
	jetLPtB->Scale(norm);
	//jet 2nd leading Pt
	jet2LPtB->Scale(norm);
	//jet 3rd leading Pt
	jet3LPtB->Scale(norm);
	//jet 4th leading Pt
	jet4LPtB->Scale(norm);
	//jet 5th leading Pt
	//jet5LPtB->Scale(norm);

	//bjet leading M
	bjetLMB->Scale(norm);
	//bjet 2nd leading M
	bjet2LMB->Scale(norm);
	//bjet 3rd leading M
	bjet3LMB->Scale(norm);
	//bjet 4th leading M
	bjet4LMB->Scale(norm);
	//bjet 5th leading M
	//bjet5LMB->Scale(norm);
	
	//b-jet leading Pt
	bjetLPtB->Scale(norm);
	//b-jet 2nd leading Pt
	bjet2LPtB->Scale(norm);
	//b-jet 3rd leading Pt
	bjet3LPtB->Scale(norm);
	//b-jet 4th leading Pt
	bjet4LPtB->Scale(norm);

	//b leading Pt
	bLPtB->Scale(norm);
	//b 2nd leading Pt
	b2LPtB->Scale(norm);
	//b 3rd leading Pt
	b3LPtB->Scale(norm);
	//b 4th leading Pt
	b4LPtB->Scale(norm);

	//b central Pt
	bCEtaB->Scale(norm);
	//b 2nd central Pt
	b2CEtaB->Scale(norm);
	//b 3rd central Pt
	b3CEtaB->Scale(norm);
	//b 4th central Pt
	b4CEtaB->Scale(norm);
	return;
}
void Set_NleadingJetColors_B()
{

	bjetLMB->SetLineColor(kOrange);
	bjet2LMB->SetLineColor(kBlack);
	bjet3LMB->SetLineColor(kRed);
	bjet4LMB->SetLineColor(kGreen);
	jetLMB->SetLineColor(kOrange);
	jet2LMB->SetLineColor(kBlack);
	jet3LMB->SetLineColor(kRed);
	jet4LMB->SetLineColor(kGreen);
	bjetLPtB->SetLineColor(kOrange);
	bjet2LPtB->SetLineColor(kBlack);
	bjet3LPtB->SetLineColor(kRed);
	bjet4LPtB->SetLineColor(kGreen);
	jetLPtB->SetLineColor(kOrange);
	jet2LPtB->SetLineColor(kBlack);
	jet3LPtB->SetLineColor(kRed);
	jet4LPtB->SetLineColor(kGreen);
	bLPtB->SetLineColor(kOrange);
	b2LPtB->SetLineColor(kBlack);
	b3LPtB->SetLineColor(kRed);
	b4LPtB->SetLineColor(kGreen);
	//bCEtaB->SetLineColor(kOrange);
	//b2CEtaB->SetLineColor(kBlack);
	//b3CEtaB->SetLineColor(kRed);
	//b4CEtaB->SetLineColor(kGreen);
	return;
	
}

void Set_bquark_lambdaColors_B()
{

	M_LhiggsB->SetLineColor(kCyan);
	M_NLhiggsB->SetLineColor(kCyan);
	Pt_LhiggsB->SetLineColor(kCyan);
	Pt_NLhiggsB->SetLineColor(kCyan);
	RecMH1H2_B->SetLineColor(kCyan);
	RecPtH1H2_B->SetLineColor(kCyan);

	bjetLMB->SetLineColor(kCyan);
	bjet2LMB->SetLineColor(kCyan);
	bjet3LMB->SetLineColor(kCyan);
	bjet4LMB->SetLineColor(kCyan);
	jetLMB->SetLineColor(kCyan);
	jet2LMB->SetLineColor(kCyan);
	jet3LMB->SetLineColor(kCyan);
	jet4LMB->SetLineColor(kCyan);
	jetLPtB->SetLineColor(kCyan);
	jet2LPtB->SetLineColor(kCyan);
	jet3LPtB->SetLineColor(kCyan);
	jet4LPtB->SetLineColor(kCyan);
	bjetLPtB->SetLineColor(kCyan);
	bjet2LPtB->SetLineColor(kCyan);
	bjet3LPtB->SetLineColor(kCyan);
	bjet4LPtB->SetLineColor(kCyan);
	bLPtB->SetLineColor(kCyan);
	b2LPtB->SetLineColor(kCyan);
	b3LPtB->SetLineColor(kCyan);
	b4LPtB->SetLineColor(kCyan);
	bCEtaB->SetLineColor(kCyan);
	b2CEtaB->SetLineColor(kCyan);
	b3CEtaB->SetLineColor(kCyan);
	b4CEtaB->SetLineColor(kCyan);
	Ana_bjetLPtB->SetLineColor(kCyan);
	Ana_bjet2LPtB->SetLineColor(kCyan);
	Ana_bjet3LPtB->SetLineColor(kCyan);
	Ana_bjet4LPtB->SetLineColor(kCyan);
	return;
}

void Draw_Number_bTags_B()
{

	h_NbTagsB = new TH1D("h_NbTagsB", "number of b tagged jets, pp->4b", 6, 0, 6);
	tB.Draw("Nbtags>>h_NbTagsB");
	return;
}
