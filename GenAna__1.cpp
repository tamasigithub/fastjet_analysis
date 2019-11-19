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
	int nbins = 50;
	float ptmin = 0;
	float ptmax = 500;
	float Mmin = 200;
	float Mmax = 800;
	higgsPt_1 = new TH1D("higgsPt_1", "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);

	higgsPt_1->SetLineColor(kYellow -9);
	
	higgsPt_1->SetLineWidth(2);
	
	higgsNLPt_1 = new TH1D("higgsNLPt_1", "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);

	higgsNLPt_1->SetLineColor(kYellow -9);
	
	higgsNLPt_1->SetLineWidth(2);
	
	M_Lhiggs_1 = new TH1D("M_Lhiggs_1", "Invariant higgs mass;m_{rec, leading higgs} [GeV];", nbins, ptmin, ptmax);

	M_Lhiggs_1->SetLineColor(kYellow -9);
	
	M_Lhiggs_1->SetLineWidth(2);
	
	M_NLhiggs_1 = new TH1D("M_NLhiggs_1", "Invariant higgs mass;m_{rec, sub leading higgs} [GeV];", nbins, ptmin, ptmax);

	M_NLhiggs_1->SetLineColor(kYellow -9);
	
	M_NLhiggs_1->SetLineWidth(2);
	
	MH1H2__1 = new TH1D("MH1H2__1", "Invariant higgs mass;m_{rec, sub leading higgs} [GeV];", nbins, Mmin, Mmax);

	MH1H2__1->SetLineColor(kYellow -9);
	
	MH1H2__1->SetLineWidth(2);

	// invariant mass of a pair of b's, ctr = -1.0
	Mb1b2__1 = new TH1D("Mb1b2__1", "#lambda = -1.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 12} [GeV];", nbins, ptmin, ptmax);
	Mb1b3__1 = new TH1D("Mb1b3__1", "#lambda = -1.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 13} [GeV];", nbins, ptmin, ptmax);
	Mb1b4__1 = new TH1D("Mb1b4__1", "#lambda = -1.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 14} [GeV];", nbins, ptmin, ptmax);
	Mb2b3__1 = new TH1D("Mb2b3__1", "#lambda = -1.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 23} [GeV];", nbins, ptmin, ptmax);
	Mb2b4__1 = new TH1D("Mb2b4__1", "#lambda = -1.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 24} [GeV];", nbins, ptmin, ptmax);
	Mb3b4__1 = new TH1D("Mb3b4__1", "#lambda = -1.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 34} [GeV];", nbins, ptmin, ptmax);
	return;
}
void Set_jetPtProps__1()
{
	int nbins = 50;
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
	}

	return;
}
void Fill_InvariantMass__1()
{
	Mb1b2__1->Fill(b1b2__1.M()*1e-3);
	Mb1b3__1->Fill(b1b3__1.M()*1e-3);
	Mb1b4__1->Fill(b1b4__1.M()*1e-3);
	Mb2b3__1->Fill(b2b3__1.M()*1e-3);
	Mb2b4__1->Fill(b2b4__1.M()*1e-3);
	Mb3b4__1->Fill(b3b4__1.M()*1e-3);

	MH1H2__1->Fill(H1H2__1.M()*1e-3);
	return;
}
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
void Draw_DiJetInvariantMass__1()
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
	}
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
	dm_12_34 = std::fabs(bJ1bJ2__1.M() - bJ3bJ4__1.M());
	dm_13_24 = std::fabs(bJ1bJ3__1.M() - bJ2bJ4__1.M());
	dm_14_23 = std::fabs(bJ1bJ4__1.M() - bJ2bJ3__1.M());
	dM_b1b2_b3b4__1->Fill(dm_12_34*1e-3);	
	dM_b1b3_b2b4__1->Fill(dm_13_24*1e-3);	
	dM_b1b4_b2b3__1->Fill(dm_14_23*1e-3);

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
		if((std::fabs(bJ1bJ2__1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ3bJ4__1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		{
			nhiggs++;
			if(bJ1bJ2__1.M() > bJ3bJ4__1.M())
			{
				M_Lhiggs_1->Fill(bJ1bJ2__1.M()*1e-3);
				M_NLhiggs_1->Fill(bJ3bJ4__1.M()*1e-3);
			
			} 
			else
			{
				M_Lhiggs_1->Fill(bJ3bJ4__1.M()*1e-3);
				M_NLhiggs_1->Fill(bJ1bJ2__1.M()*1e-3);
				
			}
		}
	}
	else if(higgs_candidates == 1324)
	{
		if((std::fabs(bJ1bJ3__1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ4__1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		{
			nhiggs++;
			if(bJ1bJ3__1.M() > bJ2bJ4__1.M())
			{
				M_Lhiggs_1->Fill(bJ1bJ3__1.M()*1e-3);
				M_NLhiggs_1->Fill(bJ2bJ4__1.M()*1e-3);
			
			} 
			else
			{
				M_Lhiggs_1->Fill(bJ2bJ4__1.M()*1e-3);
				M_NLhiggs_1->Fill(bJ1bJ3__1.M()*1e-3);
				
			}
		}
	
	}
	else if(higgs_candidates == 1423)
	{
		if((std::fabs(bJ1bJ4__1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ3__1.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		{
			nhiggs++;
			if(bJ1bJ4__1.M() > bJ2bJ3__1.M())
			{
				M_Lhiggs_1->Fill(bJ1bJ4__1.M()*1e-3);
				M_NLhiggs_1->Fill(bJ2bJ3__1.M()*1e-3);
			
			} 
			else
			{
				M_Lhiggs_1->Fill(bJ2bJ3__1.M()*1e-3);
				M_NLhiggs_1->Fill(bJ1bJ4__1.M()*1e-3);
				
			}
		}
	
	}

	return;
}

void Scale_signalHistos_1(double norm)
{
        MH1H2__1->Scale(norm);

	Mb1b2__1->Scale(norm); 
	Mb1b3__1->Scale(norm);
	Mb1b4__1->Scale(norm);
	Mb2b3__1->Scale(norm);
	Mb2b4__1->Scale(norm);
	Mb3b4__1->Scale(norm);
	
	h_NbTags_1->Scale(norm);
	NSMhiggs_1->Scale(norm);
	Nbquarks_1->Scale(norm);
	higgsPt_1->Scale(norm);
	higgsNLPt_1->Scale(norm);
	M_Lhiggs_1->Scale(norm);
	M_NLhiggs_1->Scale(norm);

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
