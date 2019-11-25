void fetch_TTrees_B()
{
	tB   = (TTree*)fB->Get("glob_jet");

	tB->SetBranchStatus("*",0);
	
	tB->SetBranchStatus("Nbquarks",1);
	tB->SetBranchStatus("Njets",1);
	tB->SetBranchStatus("jetPt",1);
	tB->SetBranchStatus("jetEta",1);
	tB->SetBranchStatus("jetPhi",1);
	tB->SetBranchStatus("jetM",1);
	tB->SetBranchStatus("btaggedFlavor",1);
	tB->SetBranchStatus("bJetLPt",1);
	tB->SetBranchStatus("bJetNLPt",1);
	tB->SetBranchStatus("bJetNNLPt",1);
	tB->SetBranchStatus("bJetNNNLPt",1);
	tB->SetBranchStatus("Nbtags",1);
	tB->SetBranchStatus("v_bPt", 1);
	tB->SetBranchStatus("v_bEta",1);
	tB->SetBranchStatus("v_bPhi",1);
	tB->SetBranchStatus("v_bM",  1);

	tB->SetBranchAddress("jetPt",  &vB_jetPt);;
	tB->SetBranchAddress("jetEta",  &vB_jetEta);
	tB->SetBranchAddress("jetPhi",  &vB_jetPhi);
	tB->SetBranchAddress("jetM",  &vB_jetM);
	tB->SetBranchAddress("btaggedFlavor",  &vB_tagFlavor);
	tB->SetBranchAddress("Nbtags",&nB_btags);
	tB->SetBranchAddress("v_bPt", &vB_bPt);
	tB->SetBranchAddress("v_bEta",&vB_bEta);
	tB->SetBranchAddress("v_bPhi",&vB_bPhi);
	tB->SetBranchAddress("v_bM",  &vB_bM);
	return;
}
void Set_higgsPtProps_B()
{
	int nbins = 50;
	float ptmin = 0;
	float ptmax = 500;
	float Mmin = 200;
	float Mmax = 800;
	M_LhiggsB  = new TH1D("M_LhiggsB",  "BackGround Invariant higgs mass;m_{rec, leading higgs} [GeV];", nbins, ptmin, ptmax);

	M_LhiggsB->SetLineColor(kCyan);
	
	M_LhiggsB->SetLineWidth(2);
	
	M_NLhiggsB  = new TH1D("M_NLhiggsB",  "Background Invariant higgs mass;m_{rec, sub leading higgs} [GeV];", nbins, ptmin, ptmax);

	M_NLhiggsB->SetLineColor(kViolet);
	
	M_NLhiggsB->SetLineWidth(2);
	

	// invariant mass of a pair of b's, pp->4b
	Mb1b2_B = new TH1D("Mb1b2_B", "Background, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 12} [GeV];", nbins, ptmin, ptmax);
	Mb1b3_B = new TH1D("Mb1b3_B", "Background, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 13} [GeV];", nbins, ptmin, ptmax);
	Mb1b4_B = new TH1D("Mb1b4_B", "Background, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 14} [GeV];", nbins, ptmin, ptmax);
	Mb2b3_B = new TH1D("Mb2b3_B", "Background, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 23} [GeV];", nbins, ptmin, ptmax);
	Mb2b4_B = new TH1D("Mb2b4_B", "Background, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 24} [GeV];", nbins, ptmin, ptmax);
	Mb3b4_B = new TH1D("Mb3b4_B", "Background, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 34} [GeV];", nbins, ptmin, ptmax);
	return;
}
void Set_jetPtProps_B()
{
	int nbins = 50;
	float ptmin = 0;
	float ptmax = 300;
	float dptmin = 0;
	float dptmax = 300;
	//b-jet leading Pt
	bjetLPtB  = new TH1D("bjetLPtB", "b-tagged Jet p_{t}; p_{t, leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 2nd leading Pt
	bjet2LPtB  = new TH1D("bjet2LPtB", "b-tagged Jet p_{t}; p_{t, sub leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 3rd leading Pt
	bjet3LPtB  = new TH1D("bjet3LPtB", "b-tagged Jet p_{t}; p_{t, 3rd leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 4th leading Pt
	bjet4LPtB  = new TH1D("bjet4LPtB", "b-tagged Jet p_{t}; p_{t, 4th leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	
	//jet leading Pt
	jetLPtB  = new TH1D("jetLPtB", "Jet p_{t}; p_{t, leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 2nd leading Pt
	jet2LPtB  = new TH1D("jet2LPtB", "Jet p_{t}; p_{t, sub leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 3rd leading Pt
	jet3LPtB  = new TH1D("jet3LPtB", "Jet p_{t}; p_{t, 3rd leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 4th leading Pt
	jet4LPtB  = new TH1D("jet4LPtB", "Jet p_{t}; p_{t, 4th leading jet} [GeV/c];", nbins, ptmin, ptmax);
	
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
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_B = new TH1D("dM_b1b2_b3b4_B", "Background, Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1234} [GeV];", nbins, dptmin, dptmax);
	dM_b1b3_b2b4_B = new TH1D("dM_b1b3_b2b4_B", "Background, Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1324} [GeV];", nbins, dptmin, dptmax);
	dM_b1b4_b2b3_B = new TH1D("dM_b1b4_b2b3_B", "Background, Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1423} [GeV];", nbins, dptmin, dptmax);
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
	}

	return;
}

void Fill_InvariantMass_B()
{
	Mb1b2_B->Fill(b1b2_B.M()*1e-3);
	Mb1b3_B->Fill(b1b3_B.M()*1e-3);
	Mb1b4_B->Fill(b1b4_B.M()*1e-3);
	Mb2b3_B->Fill(b2b3_B.M()*1e-3);
	Mb2b4_B->Fill(b2b4_B.M()*1e-3);
	Mb3b4_B->Fill(b3b4_B.M()*1e-3);

	return;
}

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
void Draw_DiJetInvariantMass_B()
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
	}
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

	double dm_12_34 = 0, dm_13_24 = 0, dm_14_23 = 0;
	dm_12_34 = std::fabs(bJ1bJ2_B.M() - bJ3bJ4_B.M());
	dm_13_24 = std::fabs(bJ1bJ3_B.M() - bJ2bJ4_B.M());
	dm_14_23 = std::fabs(bJ1bJ4_B.M() - bJ2bJ3_B.M());
	dM_b1b2_b3b4_B->Fill(dm_12_34*1e-3);	
	dM_b1b3_b2b4_B->Fill(dm_13_24*1e-3);	
	dM_b1b4_b2b3_B->Fill(dm_14_23*1e-3);

	//! Higgs Candidate
	int higgs_candidates = 1234;
	int min_diffCombi = dm_12_34;
	if(dm_13_24 < min_diffCombi) 
	{
		min_diffCombi = dm_13_24;
		higgs_candidates = 1324;
	}
	if(dm_14_23 < min_diffCombi)
	{
		min_diffCombi = dm_14_23;
		higgs_candidates = 1423;
	}

	if(higgs_candidates == 1234)
	{
		if((std::fabs(bJ1bJ2_B.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ3bJ4_B.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		{
			nhiggs++;
			if(bJ1bJ2_B.M() > bJ3bJ4_B.M())
			{
				M_LhiggsB->Fill(bJ1bJ2_B.M()*1e-3);
				M_NLhiggsB->Fill(bJ3bJ4_B.M()*1e-3);
			
			} 
			else
			{
				M_LhiggsB->Fill(bJ3bJ4_B.M()*1e-3);
				M_NLhiggsB->Fill(bJ1bJ2_B.M()*1e-3);
				
			}
		}
	}
	else if(higgs_candidates == 1324)
	{
		if((std::fabs(bJ1bJ3_B.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ4_B.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		{
			nhiggs++;
			if(bJ1bJ3_B.M() > bJ2bJ4_B.M())
			{
				M_LhiggsB->Fill(bJ1bJ3_B.M()*1e-3);
				M_NLhiggsB->Fill(bJ2bJ4_B.M()*1e-3);
			
			} 
			else
			{
				M_LhiggsB->Fill(bJ2bJ4_B.M()*1e-3);
				M_NLhiggsB->Fill(bJ1bJ3_B.M()*1e-3);
				
			}
		}
	
	}
	else if(higgs_candidates == 1423)
	{
		if((std::fabs(bJ1bJ4_B.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ3_B.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		{
			nhiggs++;
			if(bJ1bJ4_B.M() > bJ2bJ3_B.M())
			{
				M_LhiggsB->Fill(bJ1bJ4_B.M()*1e-3);
				M_NLhiggsB->Fill(bJ2bJ3_B.M()*1e-3);
			
			} 
			else
			{
				M_LhiggsB->Fill(bJ2bJ3_B.M()*1e-3);
				M_NLhiggsB->Fill(bJ1bJ4_B.M()*1e-3);
				
			}
		}
	
	}

	return;
}

void SetLineWidthB()
{
	Mb1b2_B->SetLineWidth(2); 
	Mb1b3_B->SetLineWidth(2);
	Mb1b4_B->SetLineWidth(2);
	Mb2b3_B->SetLineWidth(2);
	Mb2b4_B->SetLineWidth(2);
	Mb3b4_B->SetLineWidth(2);

	//Number of btags 
	h_NbTagsB->SetLineWidth(2);
	//Number of bquarks 
	NbquarksB->SetLineWidth(2);
	//reconstructed leading Higgs mass 
	M_LhiggsB->SetLineWidth(2);
	//reconstructed sub-leading Higgs mass 
	M_NLhiggsB->SetLineWidth(2);

	// invariant mass of a pair of b's, pp->4b
	M_b1b2_B->SetLineWidth(2);
	M_b1b3_B->SetLineWidth(2);
	M_b1b4_B->SetLineWidth(2);
	M_b2b3_B->SetLineWidth(2);
	M_b2b4_B->SetLineWidth(2);
	M_b3b4_B->SetLineWidth(2);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_B->SetLineWidth(2);
	dM_b1b3_b2b4_B->SetLineWidth(2);
	dM_b1b4_b2b3_B->SetLineWidth(2);
	
	
	
	//jet leading M
	jetLMB->SetLineWidth(2);
	//jet 2nd leading M
	jet2LMB->SetLineWidth(2);
	//jet 3rd leading M
	jet3LMB->SetLineWidth(2);
	//jet 4th leading M
	jet4LMB->SetLineWidth(2);
	//jet 5th leading M
	//jet5LMB->SetLineWidth(2);
	
	//jet leading Pt
	jetLPtB->SetLineWidth(2);
	//jet 2nd leading Pt
	jet2LPtB->SetLineWidth(2);
	//jet 3rd leading Pt
	jet3LPtB->SetLineWidth(2);
	//jet 4th leading Pt
	jet4LPtB->SetLineWidth(2);
	//jet 5th leading Pt
	//jet5LPtB->SetLineWidth(2);

	//bjet leading M
	bjetLMB->SetLineWidth(2);
	//bjet 2nd leading M
	bjet2LMB->SetLineWidth(2);
	//bjet 3rd leading M
	bjet3LMB->SetLineWidth(2);
	//bjet 4th leading M
	bjet4LMB->SetLineWidth(2);
	//bjet 5th leading M
	//bjet5LMB->SetLineWidth(2);
	
	//b-jet leading Pt
	bjetLPtB->SetLineWidth(2);
	//b-jet 2nd leading Pt
	bjet2LPtB->SetLineWidth(2);
	//b-jet 3rd leading Pt
	bjet3LPtB->SetLineWidth(2);
	//b-jet 4th leading Pt
	bjet4LPtB->SetLineWidth(2);

	//b leading Pt
	bLPtB->SetLineWidth(2);
	//b 2nd leading Pt
	b2LPtB->SetLineWidth(2);
	//b 3rd leading Pt
	b3LPtB->SetLineWidth(2);
	//b 4th leading Pt
	b4LPtB->SetLineWidth(2);

	//b central Pt
	bCEtaB->SetLineWidth(2);
	//b 2nd central Pt
	b2CEtaB->SetLineWidth(2);
	//b 3rd central Pt
	b3CEtaB->SetLineWidth(2);
	//b 4th central Pt
	b4CEtaB->SetLineWidth(2);
	return;
}
