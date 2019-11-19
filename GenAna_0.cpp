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
	int nbins = 50;
	float ptmin = 0;
	float ptmax = 500;
	float Mmin = 200;
	float Mmax = 800;
	higgsPt0  = new TH1D("higgsPt0",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);

	higgsPt0->SetLineColor(kBlack);
	
	higgsPt0->SetLineWidth(2);
	
	higgsNLPt0  = new TH1D("higgsNLPt0",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);

	higgsNLPt0->SetLineColor(kBlack);
	
	higgsNLPt0->SetLineWidth(2);
	
	M_Lhiggs0  = new TH1D("M_Lhiggs0",  "Invariant higgs mass;m_{rec, leading higgs} [GeV];", nbins, ptmin, ptmax);

	M_Lhiggs0->SetLineColor(kBlack);
	
	M_Lhiggs0->SetLineWidth(2);
	
	M_NLhiggs0  = new TH1D("M_NLhiggs0",  "Invariant higgs mass;m_{rec, sub leading higgs} [GeV];", nbins, ptmin, ptmax);

	M_NLhiggs0->SetLineColor(kBlack);
	
	M_NLhiggs0->SetLineWidth(2);
	
	MH1H2_0  = new TH1D("MH1H2_0",  "Invariant higgs mass;m_{rec, sub leading higgs} [GeV];", nbins, Mmin, Mmax);

	MH1H2_0->SetLineColor(kBlack);
	
	MH1H2_0->SetLineWidth(2);

	// invariant mass of a pair of b's, ctr = 0.0
	Mb1b2_0 = new TH1D("Mb1b2_0", "#lambda = 0.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 12} [GeV];", nbins, ptmin, ptmax);
	Mb1b3_0 = new TH1D("Mb1b3_0", "#lambda = 0.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 13} [GeV];", nbins, ptmin, ptmax);
	Mb1b4_0 = new TH1D("Mb1b4_0", "#lambda = 0.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 14} [GeV];", nbins, ptmin, ptmax);
	Mb2b3_0 = new TH1D("Mb2b3_0", "#lambda = 0.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 23} [GeV];", nbins, ptmin, ptmax);
	Mb2b4_0 = new TH1D("Mb2b4_0", "#lambda = 0.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 24} [GeV];", nbins, ptmin, ptmax);
	Mb3b4_0 = new TH1D("Mb3b4_0", "#lambda = 0.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 34} [GeV];", nbins, ptmin, ptmax);
	return;
}
void Set_jetPtProps_0()
{
	int nbins = 50;
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
	}

	return;
}
void Fill_InvariantMass_0()
{
	Mb1b2_0->Fill(b1b2_0.M()*1e-3);
	Mb1b3_0->Fill(b1b3_0.M()*1e-3);
	Mb1b4_0->Fill(b1b4_0.M()*1e-3);
	Mb2b3_0->Fill(b2b3_0.M()*1e-3);
	Mb2b4_0->Fill(b2b4_0.M()*1e-3);
	Mb3b4_0->Fill(b3b4_0.M()*1e-3);

	MH1H2_0->Fill(H1H2_0.M()*1e-3);
	return;
}
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
void Draw_DiJetInvariantMass_0()
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
	}
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
	dm_12_34 = std::fabs(bJ1bJ2_0.M() - bJ3bJ4_0.M());
	dm_13_24 = std::fabs(bJ1bJ3_0.M() - bJ2bJ4_0.M());
	dm_14_23 = std::fabs(bJ1bJ4_0.M() - bJ2bJ3_0.M());
	dM_b1b2_b3b4_0->Fill(dm_12_34*1e-3);	
	dM_b1b3_b2b4_0->Fill(dm_13_24*1e-3);	
	dM_b1b4_b2b3_0->Fill(dm_14_23*1e-3);

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
		if((std::fabs(bJ1bJ2_0.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ3bJ4_0.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		{
			nhiggs++;
			if(bJ1bJ2_0.M() > bJ3bJ4_0.M())
			{
				M_Lhiggs0->Fill(bJ1bJ2_0.M()*1e-3);
				M_NLhiggs0->Fill(bJ3bJ4_0.M()*1e-3);
			
			} 
			else
			{
				M_Lhiggs0->Fill(bJ3bJ4_0.M()*1e-3);
				M_NLhiggs0->Fill(bJ1bJ2_0.M()*1e-3);
				
			}
		}
	}
	else if(higgs_candidates == 1324)
	{
		if((std::fabs(bJ1bJ3_0.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ4_0.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		{
			nhiggs++;
			if(bJ1bJ3_0.M() > bJ2bJ4_0.M())
			{
				M_Lhiggs0->Fill(bJ1bJ3_0.M()*1e-3);
				M_NLhiggs0->Fill(bJ2bJ4_0.M()*1e-3);
			
			} 
			else
			{
				M_Lhiggs0->Fill(bJ2bJ4_0.M()*1e-3);
				M_NLhiggs0->Fill(bJ1bJ3_0.M()*1e-3);
				
			}
		}
	
	}
	else if(higgs_candidates == 1423)
	{
		if((std::fabs(bJ1bJ4_0.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ3_0.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		{
			nhiggs++;
			if(bJ1bJ4_0.M() > bJ2bJ3_0.M())
			{
				M_Lhiggs0->Fill(bJ1bJ4_0.M()*1e-3);
				M_NLhiggs0->Fill(bJ2bJ3_0.M()*1e-3);
			
			} 
			else
			{
				M_Lhiggs0->Fill(bJ2bJ3_0.M()*1e-3);
				M_NLhiggs0->Fill(bJ1bJ4_0.M()*1e-3);
				
			}
		}
	
	}

	return;
}

void Scale_signalHistos0(double norm) 
{
	MH1H2_0->Scale(norm); 

	Mb1b2_0->Scale(norm); 
	Mb1b3_0->Scale(norm);
	Mb1b4_0->Scale(norm);
	Mb2b3_0->Scale(norm);
	Mb2b4_0->Scale(norm);
	Mb3b4_0->Scale(norm);

	h_NbTags0->Scale(norm);
	NSMhiggs0->Scale(norm);
	Nbquarks0->Scale(norm);
	higgsPt0->Scale(norm);
	higgsNLPt0->Scale(norm);
	M_Lhiggs0->Scale(norm);
	M_NLhiggs0->Scale(norm);
	
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
