void fetch_TTrees_1()
{
	t1   = (TTree*)f1->Get("glob_jet");
	t1->SetBranchStatus("*",0);
	t1->SetBranchStatus("higgsLPt",1);
	t1->SetBranchStatus("higgsNLPt",1);
	t1->SetBranchStatus("NSMhiggs",1);
	t1->SetBranchStatus("Nbquarks",1);
	t1->SetBranchStatus("Njets",1);
	t1->SetBranchStatus("jetPt",1);
	t1->SetBranchStatus("jetEta",1);
	t1->SetBranchStatus("jetPhi",1);
	t1->SetBranchStatus("jetM",1);
	t1->SetBranchStatus("btaggedFlavor",1);
	t1->SetBranchStatus("bJetLPt",1);
	t1->SetBranchStatus("bJetNLPt",1);
	t1->SetBranchStatus("bJetNNLPt",1);
	t1->SetBranchStatus("bJetNNNLPt",1);
	t1->SetBranchStatus("Nbtags",1);
	t1->SetBranchStatus("v_higgsPt", 1);
	t1->SetBranchStatus("v_higgsEta",1);
	t1->SetBranchStatus("v_higgsPhi",1);
	t1->SetBranchStatus("v_higgsM",  1);
	t1->SetBranchStatus("v_bPt", 1);
	t1->SetBranchStatus("v_bEta",1);
	t1->SetBranchStatus("v_bPhi",1);
	t1->SetBranchStatus("v_bM",  1);
	
	t1->SetBranchAddress("jetPt",  &v1_jetPt);
	t1->SetBranchAddress("jetEta",  &v1_jetEta);
	t1->SetBranchAddress("jetPhi",  &v1_jetPhi);
	t1->SetBranchAddress("jetM",  &v1_jetM);
	t1->SetBranchAddress("btaggedFlavor",  &v1_tagFlavor);
	t1->SetBranchAddress("Nbtags",&n1_btags);
	t1->SetBranchAddress("v_higgsPt", &v1_higgsPt);
	t1->SetBranchAddress("v_higgsEta",&v1_higgsEta);
	t1->SetBranchAddress("v_higgsPhi",&v1_higgsPhi);
	t1->SetBranchAddress("v_higgsM",  &v1_higgsM);
	t1->SetBranchAddress("v_bPt", &v1_bPt);
	t1->SetBranchAddress("v_bEta",&v1_bEta);
	t1->SetBranchAddress("v_bPhi",&v1_bPhi);
	t1->SetBranchAddress("v_bM",  &v1_bM);
	return;
}
void Set_higgsPtProps_1()
{
	int nbins = 50;
	float ptmin = 0;
	float ptmax = 500;
	float Mmin = 200;
	float Mmax = 800;
	higgsPt1  = new TH1D("higgsPt1",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);

	higgsPt1->SetLineColor(kRed);
	
	higgsPt1->SetLineWidth(2);
	
	higgsNLPt1  = new TH1D("higgsNLPt1",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);

	higgsNLPt1->SetLineColor(kRed);
	
	higgsNLPt1->SetLineWidth(2);
	
	M_Lhiggs1  = new TH1D("M_Lhiggs1",  "Invariant higgs mass;m_{rec, leading higgs} [GeV];", nbins, ptmin, ptmax);

	M_Lhiggs1->SetLineColor(kRed);
	
	M_Lhiggs1->SetLineWidth(2);
	
	M_NLhiggs1  = new TH1D("M_NLhiggs1",  "Invariant higgs mass;m_{rec, sub leading higgs} [GeV];", nbins, ptmin, ptmax);

	M_NLhiggs1->SetLineColor(kRed);
	
	M_NLhiggs1->SetLineWidth(2);
	
	MH1H2_1  = new TH1D("MH1H2_1",  "Invariant di-higgs mass;m_{truth, h1h2} [GeV];", nbins, Mmin, Mmax);

	MH1H2_1->SetLineColor(kRed);
	
	MH1H2_1->SetLineWidth(2);

	// invariant mass of a pair of b's, ctr = 1.0
	Mb1b2_1 = new TH1D("Mb1b2_1", "#lambda = 1.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 12} [GeV];", nbins, ptmin, ptmax);
	Mb1b3_1 = new TH1D("Mb1b3_1", "#lambda = 1.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 13} [GeV];", nbins, ptmin, ptmax);
	Mb1b4_1 = new TH1D("Mb1b4_1", "#lambda = 1.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 14} [GeV];", nbins, ptmin, ptmax);
	Mb2b3_1 = new TH1D("Mb2b3_1", "#lambda = 1.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 23} [GeV];", nbins, ptmin, ptmax);
	Mb2b4_1 = new TH1D("Mb2b4_1", "#lambda = 1.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 24} [GeV];", nbins, ptmin, ptmax);
	Mb3b4_1 = new TH1D("Mb3b4_1", "#lambda = 1.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 34} [GeV];", nbins, ptmin, ptmax);
	return;
}


void Set_jetPtProps_1()
{
	int nbins = 50;
	float ptmin = 0;
	float ptmax = 300;
	float dptmin = 0;
	float dptmax = 300;
	//b-jet leading Pt
	bjetLPt1  = new TH1D("bjetLPt1", "b-tagged Jet p_{t}; p_{t, leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 2nd leading Pt
	bjet2LPt1  = new TH1D("bjet2LPt1", "b-tagged Jet p_{t}; p_{t, sub leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 3rd leading Pt
	bjet3LPt1  = new TH1D("bjet3LPt1", "b-tagged Jet p_{t}; p_{t, 3rd leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 4th leading Pt
	bjet4LPt1  = new TH1D("bjet4LPt1", "b-tagged Jet p_{t}; p_{t, 4th leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	
	//jet leading Pt
	jetLPt1  = new TH1D("jetLPt1", "Jet p_{t}; p_{t, leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 2nd leading Pt
	jet2LPt1  = new TH1D("jet2LPt1", "Jet p_{t}; p_{t, sub leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 3rd leading Pt
	jet3LPt1  = new TH1D("jet3LPt1", "Jet p_{t}; p_{t, 3rd leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 4th leading Pt
	jet4LPt1  = new TH1D("jet4LPt1", "Jet p_{t}; p_{t, 4th leading jet} [GeV/c];", nbins, ptmin, ptmax);

	//jet leading M
	jetLM1  = new TH1D("jetLM1", "Jet invariant mass; m_{ leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 2nd leading M
	jet2LM1  = new TH1D("jet2LM1", "Jet invariant mass; m_{ sub leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 3rd leading M
	jet3LM1  = new TH1D("jet3LM1", "Jet invariant mass; m_{ 3rd leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 4th leading M
	jet4LM1  = new TH1D("jet4LM1", "Jet invariant mass; m_{ 4th leading jet} [GeV];", nbins, ptmin, ptmax);
	
	//bjet leading M
	bjetLM1  = new TH1D("bjetLM1", "Jet invariant mass; m_{ leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 2nd leading M
	bjet2LM1  = new TH1D("bjet2LM1", "Jet invariant mass; m_{ sub leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 3rd leading M
	bjet3LM1  = new TH1D("bjet3LM1", "Jet invariant mass; m_{ 3rd leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 4th leading M
	bjet4LM1  = new TH1D("bjet4LM1", "Jet invariant mass; m_{ 4th leading bjet} [GeV];", nbins, ptmin, ptmax);
	
	// invariant mass of a pair of b's, ctr = 1.0
	M_b1b2_1 = new TH1D("M_b1b2_1", "Invariant mass of the higgs candidates; m_{higgs candidate, 12} [GeV];", nbins, ptmin, ptmax);
	M_b1b3_1 = new TH1D("M_b1b3_1", "Invariant mass of the higgs candidates; m_{higgs candidate, 13} [GeV];", nbins, ptmin, ptmax);
	M_b1b4_1 = new TH1D("M_b1b4_1", "Invariant mass of the higgs candidates; m_{higgs candidate, 14} [GeV];", nbins, ptmin, ptmax);
	M_b2b3_1 = new TH1D("M_b2b3_1", "Invariant mass of the higgs candidates; m_{higgs candidate, 23} [GeV];", nbins, ptmin, ptmax);
	M_b2b4_1 = new TH1D("M_b2b4_1", "Invariant mass of the higgs candidates; m_{higgs candidate, 24} [GeV];", nbins, ptmin, ptmax);
	M_b3b4_1 = new TH1D("M_b3b4_1", "Invariant mass of the higgs candidates; m_{higgs candidate, 34} [GeV];", nbins, ptmin, ptmax);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_1 = new TH1D("dM_b1b2_b3b4_1", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1234} [GeV];", nbins, dptmin, dptmax);
	dM_b1b3_b2b4_1 = new TH1D("dM_b1b3_b2b4_1", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1324} [GeV];", nbins, dptmin, dptmax);
	dM_b1b4_b2b3_1 = new TH1D("dM_b1b4_b2b3_1", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1423} [GeV];", nbins, dptmin, dptmax);

	return;
}

void Draw_InvariantMass_1()
{

	//! higgs's
	if(v1_higgsPt->size() == 2)
	{
		higgs1_1.SetPtEtaPhiM((*v1_higgsPt)[0], (*v1_higgsEta)[0], (*v1_higgsPhi)[0], (*v1_higgsM)[0]);
		higgs2_1.SetPtEtaPhiM((*v1_higgsPt)[1], (*v1_higgsEta)[1], (*v1_higgsPhi)[1], (*v1_higgsM)[1]);
		H1H2_1 = higgs1_1 + higgs2_1;
	}
	//! b's
	if(v1_bPt->size() == 4)
	{
		b1_1.SetPtEtaPhiM((*v1_bPt)[0], (*v1_bEta)[0], (*v1_bPhi)[0], (*v1_bM)[0]);
		b2_1.SetPtEtaPhiM((*v1_bPt)[1], (*v1_bEta)[1], (*v1_bPhi)[1], (*v1_bM)[1]);
		b3_1.SetPtEtaPhiM((*v1_bPt)[2], (*v1_bEta)[2], (*v1_bPhi)[2], (*v1_bM)[2]);
		b4_1.SetPtEtaPhiM((*v1_bPt)[3], (*v1_bEta)[3], (*v1_bPhi)[3], (*v1_bM)[3]);

		b1b2_1 = b1_1 + b2_1;
		b1b3_1 = b1_1 + b3_1;
		b1b4_1 = b1_1 + b4_1;
		b2b3_1 = b2_1 + b3_1;
		b2b4_1 = b2_1 + b4_1;
		b3b4_1 = b3_1 + b4_1;
	}

	return;
}
void Fill_InvariantMass_1()
{
	Mb1b2_1->Fill(b1b2_1.M()*1e-3);
	Mb1b3_1->Fill(b1b3_1.M()*1e-3);
	Mb1b4_1->Fill(b1b4_1.M()*1e-3);
	Mb2b3_1->Fill(b2b3_1.M()*1e-3);
	Mb2b4_1->Fill(b2b4_1.M()*1e-3);
	Mb3b4_1->Fill(b3b4_1.M()*1e-3);

	MH1H2_1->Fill(H1H2_1.M()*1e-3);
	return;
}
void Fill_NLeadingJetPtM_1()
{
	jetLPt1->Fill((*v1_jetPt)[0]*1e-3);
	jet2LPt1->Fill((*v1_jetPt)[1]*1e-3);
	jet3LPt1->Fill((*v1_jetPt)[2]*1e-3);
	jet4LPt1->Fill((*v1_jetPt)[3]*1e-3);
	
	jetLM1->Fill( (*v1_jetM)[0]*1e-3);
	jet2LM1->Fill((*v1_jetM)[1]*1e-3);
	jet3LM1->Fill((*v1_jetM)[2]*1e-3);
	jet4LM1->Fill((*v1_jetM)[3]*1e-3);

	return;
}
void Draw_DiJetInvariantMass_1()
{
	v1_bjetPt.clear();
	v1_bjetEta.clear();
	v1_bjetPhi.clear();
	v1_bjetM.clear();
	for(int j = 0; j < v1_tagFlavor->size(); j++)
	{
		if((*v1_tagFlavor)[j] != 5) continue;
		v1_bjetPt.push_back((*v1_jetPt)[j]);
		v1_bjetEta.push_back((*v1_jetEta)[j]);
		v1_bjetPhi.push_back((*v1_jetPhi)[j]);
		v1_bjetM.push_back((*v1_jetM)[j]);

	}
	
	//! b jet's
	if(v1_bjetPt.size() > 3)
	{
		bJ1_1.SetPtEtaPhiM(v1_bjetPt[0], v1_bjetEta[0], v1_bjetPhi[0], v1_bjetM[0]);
		bJ2_1.SetPtEtaPhiM(v1_bjetPt[1], v1_bjetEta[1], v1_bjetPhi[1], v1_bjetM[1]);
		bJ3_1.SetPtEtaPhiM(v1_bjetPt[2], v1_bjetEta[2], v1_bjetPhi[2], v1_bjetM[2]);
		bJ4_1.SetPtEtaPhiM(v1_bjetPt[3], v1_bjetEta[3], v1_bjetPhi[3], v1_bjetM[3]);

		bJ1bJ2_1 = bJ1_1 + bJ2_1;
		bJ1bJ3_1 = bJ1_1 + bJ3_1;
		bJ1bJ4_1 = bJ1_1 + bJ4_1;
		bJ2bJ3_1 = bJ2_1 + bJ3_1;
		bJ2bJ4_1 = bJ2_1 + bJ4_1;
		bJ3bJ4_1 = bJ3_1 + bJ4_1;
	}
	return;
}
void Fill_bjetPtM_1(int &nhiggs)
{
	bjetLPt1->Fill( bJ1_1.Pt()*1e-3);
	bjet2LPt1->Fill(bJ2_1.Pt()*1e-3);
	bjet3LPt1->Fill(bJ3_1.Pt()*1e-3);
	bjet4LPt1->Fill(bJ4_1.Pt()*1e-3);

	bjetLM1->Fill( bJ1_1.M()*1e-3);
	bjet2LM1->Fill(bJ2_1.M()*1e-3);
	bjet3LM1->Fill(bJ3_1.M()*1e-3);
	bjet4LM1->Fill(bJ4_1.M()*1e-3);
	
	M_b1b2_1->Fill(bJ1bJ2_1.M()*1e-3);
	M_b1b3_1->Fill(bJ1bJ3_1.M()*1e-3);
	M_b1b4_1->Fill(bJ1bJ4_1.M()*1e-3);
	M_b2b3_1->Fill(bJ2bJ3_1.M()*1e-3);
	M_b2b4_1->Fill(bJ2bJ4_1.M()*1e-3);
	M_b3b4_1->Fill(bJ3bJ4_1.M()*1e-3);

	double dm_12_34 = 0, dm_13_24 = 0, dm_14_23 = 0;
	dm_12_34 = std::fabs(bJ1bJ2_1.M() - bJ3bJ4_1.M());
	dm_13_24 = std::fabs(bJ1bJ3_1.M() - bJ2bJ4_1.M());
	dm_14_23 = std::fabs(bJ1bJ4_1.M() - bJ2bJ3_1.M());
	dM_b1b2_b3b4_1->Fill(dm_12_34*1e-3);	
	dM_b1b3_b2b4_1->Fill(dm_13_24*1e-3);	
	dM_b1b4_b2b3_1->Fill(dm_14_23*1e-3);

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
		if((std::fabs(bJ1bJ2_1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ3bJ4_1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		{
			nhiggs++;
			if(bJ1bJ2_1.M() > bJ3bJ4_1.M())
			{
				M_Lhiggs1->Fill(bJ1bJ2_1.M()*1e-3);
				M_NLhiggs1->Fill(bJ3bJ4_1.M()*1e-3);
			
			} 
			else
			{
				M_Lhiggs1->Fill(bJ3bJ4_1.M()*1e-3);
				M_NLhiggs1->Fill(bJ1bJ2_1.M()*1e-3);
				
			}
		}
	}
	else if(higgs_candidates == 1324)
	{
		if((std::fabs(bJ1bJ3_1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ4_1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		{
			nhiggs++;
			if(bJ1bJ3_1.M() > bJ2bJ4_1.M())
			{
				M_Lhiggs1->Fill(bJ1bJ3_1.M()*1e-3);
				M_NLhiggs1->Fill(bJ2bJ4_1.M()*1e-3);
			
			} 
			else
			{
				M_Lhiggs1->Fill(bJ2bJ4_1.M()*1e-3);
				M_NLhiggs1->Fill(bJ1bJ3_1.M()*1e-3);
				
			}
		}
	
	}
	else if(higgs_candidates == 1423)
	{
		if((std::fabs(bJ1bJ4_1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ3_1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		{
			nhiggs++;
			if(bJ1bJ4_1.M() > bJ2bJ3_1.M())
			{
				M_Lhiggs1->Fill(bJ1bJ4_1.M()*1e-3);
				M_NLhiggs1->Fill(bJ2bJ3_1.M()*1e-3);
			
			} 
			else
			{
				M_Lhiggs1->Fill(bJ2bJ3_1.M()*1e-3);
				M_NLhiggs1->Fill(bJ1bJ4_1.M()*1e-3);
				
			}
		}
	
	}

	return;
}
void SetLineWidth1()
{


	MH1H2_1->SetLineWidth(2); 
	
	Mb1b2_1->SetLineWidth(2); 
	Mb1b3_1->SetLineWidth(2);
	Mb1b4_1->SetLineWidth(2);
	Mb2b3_1->SetLineWidth(2);
	Mb2b4_1->SetLineWidth(2);
	Mb3b4_1->SetLineWidth(2);

	h_NbTags1->SetLineWidth(2);

	NSMhiggs1->SetLineWidth(2);
	Nbquarks1->SetLineWidth(2);
	Njets1->SetLineWidth(2);
	
	higgsPt1->SetLineWidth(2);
	higgsNLPt1->SetLineWidth(2);
	
	M_Lhiggs1->SetLineWidth(2);
	M_NLhiggs1->SetLineWidth(2);
	// invariant mass of a pair of b's, ctr = 1.0
	M_b1b2_1->SetLineWidth(2);
	M_b1b3_1->SetLineWidth(2);
	M_b1b4_1->SetLineWidth(2);
	M_b2b3_1->SetLineWidth(2);
	M_b2b4_1->SetLineWidth(2);
	M_b3b4_1->SetLineWidth(2);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_1->SetLineWidth(2);
	dM_b1b3_b2b4_1->SetLineWidth(2);
	dM_b1b4_b2b3_1->SetLineWidth(2);
	
	//jet leading M
	jetLM1->SetLineWidth(2);
	jet2LM1->SetLineWidth(2);
	jet3LM1->SetLineWidth(2);
	jet4LM1->SetLineWidth(2);
	
	//bjet leading M
	bjetLM1->SetLineWidth(2);
	bjet2LM1->SetLineWidth(2);
	bjet3LM1->SetLineWidth(2);
	bjet4LM1->SetLineWidth(2);
	
	//jet leading Pt
	jetLPt1->SetLineWidth(2);
	jet2LPt1->SetLineWidth(2);
	jet3LPt1->SetLineWidth(2);
	jet4LPt1->SetLineWidth(2);
	
	//b-jet leading Pt
	bjetLPt1->SetLineWidth(2);
	bjet2LPt1->SetLineWidth(2);
	bjet3LPt1->SetLineWidth(2);
	bjet4LPt1->SetLineWidth(2);
	
	//b leading Pt
	bLPt1->SetLineWidth(2);
	b2LPt1->SetLineWidth(2);
	b3LPt1->SetLineWidth(2);
	b4LPt1->SetLineWidth(2);
	
	//b central Pt
	bCEta1->SetLineWidth(2);
	b2CEta1->SetLineWidth(2);
	b3CEta1->SetLineWidth(2);
	b4CEta1->SetLineWidth(2);
	return;
}
void Scale_signalHistos1(double norm)
{


	MH1H2_1->Scale(norm); 
	
	Mb1b2_1->Scale(norm); 
	Mb1b3_1->Scale(norm);
	Mb1b4_1->Scale(norm);
	Mb2b3_1->Scale(norm);
	Mb2b4_1->Scale(norm);
	Mb3b4_1->Scale(norm);

	h_NbTags1->Scale(norm);

	NSMhiggs1->Scale(norm);
	Nbquarks1->Scale(norm);
	Njets1->Scale(norm);
	
	higgsPt1->Scale(norm);
	higgsNLPt1->Scale(norm);
	
	M_Lhiggs1->Scale(norm);
	M_NLhiggs1->Scale(norm);
	// invariant mass of a pair of b's, ctr = 1.0
	M_b1b2_1->Scale(norm);
	M_b1b3_1->Scale(norm);
	M_b1b4_1->Scale(norm);
	M_b2b3_1->Scale(norm);
	M_b2b4_1->Scale(norm);
	M_b3b4_1->Scale(norm);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_1->Scale(norm);
	dM_b1b3_b2b4_1->Scale(norm);
	dM_b1b4_b2b3_1->Scale(norm);
	
	//jet leading M
	jetLM1->Scale(norm);
	jet2LM1->Scale(norm);
	jet3LM1->Scale(norm);
	jet4LM1->Scale(norm);
	
	//bjet leading M
	bjetLM1->Scale(norm);
	bjet2LM1->Scale(norm);
	bjet3LM1->Scale(norm);
	bjet4LM1->Scale(norm);
	
	//jet leading Pt
	jetLPt1->Scale(norm);
	jet2LPt1->Scale(norm);
	jet3LPt1->Scale(norm);
	jet4LPt1->Scale(norm);
	
	//b-jet leading Pt
	bjetLPt1->Scale(norm);
	bjet2LPt1->Scale(norm);
	bjet3LPt1->Scale(norm);
	bjet4LPt1->Scale(norm);
	
	//b leading Pt
	bLPt1->Scale(norm);
	b2LPt1->Scale(norm);
	b3LPt1->Scale(norm);
	b4LPt1->Scale(norm);
	
	//b central Pt
	bCEta1->Scale(norm);
	b2CEta1->Scale(norm);
	b3CEta1->Scale(norm);
	b4CEta1->Scale(norm);
	return;
}
