void fetch_TTrees_3()
{
	t3   = (TTree*)f3->Get("glob_jet");

	t3->SetBranchStatus("*",0);
	
	t3->SetBranchStatus("higgsLPt",1);
	t3->SetBranchStatus("higgsNLPt",1);
	t3->SetBranchStatus("NSMhiggs",1);
	t3->SetBranchStatus("Nbquarks",1);
	t3->SetBranchStatus("Njets",1);
	t3->SetBranchStatus("jetPt",1);
	t3->SetBranchStatus("jetEta",1);
	t3->SetBranchStatus("jetPhi",1);
	t3->SetBranchStatus("jetM",1);
	t3->SetBranchStatus("btaggedFlavor",1);
	t3->SetBranchStatus("bJetLPt",1);
	t3->SetBranchStatus("bJetNLPt",1);
	t3->SetBranchStatus("bJetNNLPt",1);
	t3->SetBranchStatus("bJetNNNLPt",1);
	t3->SetBranchStatus("Nbtags",1);
	t3->SetBranchStatus("v_higgsPt", 1);
	t3->SetBranchStatus("v_higgsEta",1);
	t3->SetBranchStatus("v_higgsPhi",1);
	t3->SetBranchStatus("v_higgsM",  1);
	t3->SetBranchStatus("v_bPt", 1);
	t3->SetBranchStatus("v_bEta",1);
	t3->SetBranchStatus("v_bPhi",1);
	t3->SetBranchStatus("v_bM",  1);
	
	t3->SetBranchAddress("jetPt",  &v3_jetPt);
	t3->SetBranchAddress("jetEta",  &v3_jetEta);
	t3->SetBranchAddress("jetPhi",  &v3_jetPhi);
	t3->SetBranchAddress("jetM",  &v3_jetM);
	t3->SetBranchAddress("btaggedFlavor",  &v3_tagFlavor);
	t3->SetBranchAddress("Nbtags",&n3_btags);
	t3->SetBranchAddress("v_higgsPt", &v3_higgsPt);
	t3->SetBranchAddress("v_higgsEta",&v3_higgsEta);
	t3->SetBranchAddress("v_higgsPhi",&v3_higgsPhi);
	t3->SetBranchAddress("v_higgsM",  &v3_higgsM);
	t3->SetBranchAddress("v_bPt", &v3_bPt);
	t3->SetBranchAddress("v_bEta",&v3_bEta);
	t3->SetBranchAddress("v_bPhi",&v3_bPhi);
	t3->SetBranchAddress("v_bM",  &v3_bM);

	return;
}
void Set_higgsPtProps_3()
{
	int nbins = 50;
	float ptmin = 0;
	float ptmax = 500;
	float Mmin = 200;
	float Mmax = 800;
	higgsPt3  = new TH1D("higgsPt3",  "higgs p_{t};p_{t, leading higgs} [GeV/c];", nbins, ptmin, ptmax);

	higgsPt3->SetLineColor(kViolet);
	
	higgsPt3->SetLineWidth(2);
	
	higgsNLPt3  = new TH1D("higgsNLPt3",  "higgs p_{t};p_{t, sub leading higgs} [GeV/c];", nbins, ptmin, ptmax);

	higgsNLPt3->SetLineColor(kViolet);
	
	higgsNLPt3->SetLineWidth(2);
	
	M_Lhiggs3  = new TH1D("M_Lhiggs3",  "Invariant higgs mass;m_{rec, leading higgs} [GeV];", nbins, ptmin, ptmax);

	M_Lhiggs3->SetLineColor(kViolet);
	
	M_Lhiggs3->SetLineWidth(2);
	
	M_NLhiggs3  = new TH1D("M_NLhiggs3",  "Invariant higgs mass;m_{rec, sub leading higgs} [GeV];", nbins, ptmin, ptmax);

	M_NLhiggs3->SetLineColor(kViolet);
	
	M_NLhiggs3->SetLineWidth(2);
	
	MH1H2_3  = new TH1D("MH1H2_3",  "Invariant di-higgs mass;m_{truth, h1h2} [GeV];", nbins, Mmin, Mmax);

	MH1H2_3->SetLineColor(kViolet);
	
	MH1H2_3->SetLineWidth(2);

	// invariant mass of a pair of b's, ctr = 3.0
	Mb1b2_3 = new TH1D("Mb1b2_3", "#lambda = 3.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 12} [GeV];", nbins, ptmin, ptmax);
	Mb1b3_3 = new TH1D("Mb1b3_3", "#lambda = 3.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 13} [GeV];", nbins, ptmin, ptmax);
	Mb1b4_3 = new TH1D("Mb1b4_3", "#lambda = 3.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 14} [GeV];", nbins, ptmin, ptmax);
	Mb2b3_3 = new TH1D("Mb2b3_3", "#lambda = 3.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 23} [GeV];", nbins, ptmin, ptmax);
	Mb2b4_3 = new TH1D("Mb2b4_3", "#lambda = 3.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 24} [GeV];", nbins, ptmin, ptmax);
	Mb3b4_3 = new TH1D("Mb3b4_3", "#lambda = 3.0, Truth Invariant mass of the higgs candidates; m_{higgs candidate, 34} [GeV];", nbins, ptmin, ptmax);
	return;
}


void Set_jetPtProps_3()
{
	int nbins = 50;
	float ptmin = 0;
	float ptmax = 300;
	float dptmin = 0;
	float dptmax = 300;
	//b-jet leading Pt
	bjetLPt3  = new TH1D("bjetLPt3", "b-tagged Jet p_{t}; p_{t, leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 2nd leading Pt
	bjet2LPt3  = new TH1D("bjet2LPt3", "b-tagged Jet p_{t}; p_{t, sub leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 3rd leading Pt
	bjet3LPt3  = new TH1D("bjet3LPt3", "b-tagged Jet p_{t}; p_{t, 3rd leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	//b-jet 4th leading Pt
	bjet4LPt3  = new TH1D("bjet4LPt3", "b-tagged Jet p_{t}; p_{t, 4th leading b-jet} [GeV/c];", nbins, ptmin, ptmax);
	
	//jet leading Pt
	jetLPt3  = new TH1D("jetLPt3", "Jet p_{t}; p_{t, leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 2nd leading Pt
	jet2LPt3  = new TH1D("jet2LPt3", "Jet p_{t}; p_{t, sub leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 3rd leading Pt
	jet3LPt3  = new TH1D("jet3LPt3", "Jet p_{t}; p_{t, 3rd leading jet} [GeV/c];", nbins, ptmin, ptmax);
	//jet 4th leading Pt
	jet4LPt3  = new TH1D("jet4LPt3", "Jet p_{t}; p_{t, 4th leading jet} [GeV/c];", nbins, ptmin, ptmax);

	//jet leading M
	jetLM3  = new TH1D("jetLM3", "Jet invariant mass; m_{ leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 2nd leading M
	jet2LM3  = new TH1D("jet2LM3", "Jet invariant mass; m_{ sub leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 3rd leading M
	jet3LM3  = new TH1D("jet3LM3", "Jet invariant mass; m_{ 3rd leading jet} [GeV];", nbins, ptmin, ptmax);
	//jet 4th leading M
	jet4LM3  = new TH1D("jet4LM3", "Jet invariant mass; m_{ 4th leading jet} [GeV];", nbins, ptmin, ptmax);
	
	//bjet leading M
	bjetLM3  = new TH1D("bjetLM3", "Jet invariant mass; m_{ leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 2nd leading M
	bjet2LM3  = new TH1D("bjet2LM3", "Jet invariant mass; m_{ sub leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 3rd leading M
	bjet3LM3  = new TH1D("bjet3LM3", "Jet invariant mass; m_{ 3rd leading bjet} [GeV];", nbins, ptmin, ptmax);
	//bjet 4th leading M
	bjet4LM3  = new TH1D("bjet4LM3", "Jet invariant mass; m_{ 4th leading bjet} [GeV];", nbins, ptmin, ptmax);
	
	// invariant mass of a pair of b's, ctr = 1.0
	M_b1b2_3 = new TH1D("M_b1b2_3", "Invariant mass of the higgs candidates; m_{higgs candidate, 12} [GeV];", nbins, ptmin, ptmax);
	M_b1b3_3 = new TH1D("M_b1b3_3", "Invariant mass of the higgs candidates; m_{higgs candidate, 13} [GeV];", nbins, ptmin, ptmax);
	M_b1b4_3 = new TH1D("M_b1b4_3", "Invariant mass of the higgs candidates; m_{higgs candidate, 14} [GeV];", nbins, ptmin, ptmax);
	M_b2b3_3 = new TH1D("M_b2b3_3", "Invariant mass of the higgs candidates; m_{higgs candidate, 23} [GeV];", nbins, ptmin, ptmax);
	M_b2b4_3 = new TH1D("M_b2b4_3", "Invariant mass of the higgs candidates; m_{higgs candidate, 24} [GeV];", nbins, ptmin, ptmax);
	M_b3b4_3 = new TH1D("M_b3b4_3", "Invariant mass of the higgs candidates; m_{higgs candidate, 34} [GeV];", nbins, ptmin, ptmax);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_3 = new TH1D("dM_b1b2_b3b4_3", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1234} [GeV];", nbins, dptmin, dptmax);
	dM_b1b3_b2b4_3 = new TH1D("dM_b1b3_b2b4_3", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1324} [GeV];", nbins, dptmin, dptmax);
	dM_b1b4_b2b3_3 = new TH1D("dM_b1b4_b2b3_3", "Relative difference b/w the invariant masses of the possible higgs pair; m_{H, 1423} [GeV];", nbins, dptmin, dptmax);

	return;
}
	
void Draw_InvariantMass_3()
{
	//! higgs's
	if(v3_higgsPt->size() == 2)
	{
		higgs1_3.SetPtEtaPhiM((*v3_higgsPt)[0], (*v3_higgsEta)[0], (*v3_higgsPhi)[0], (*v3_higgsM)[0]);
		higgs2_3.SetPtEtaPhiM((*v3_higgsPt)[1], (*v3_higgsEta)[1], (*v3_higgsPhi)[1], (*v3_higgsM)[1]);
		H1H2_3 = higgs1_3 + higgs2_3;
	}
	//! b's
	if(v3_bPt->size() == 4)
	{
		b1_3.SetPtEtaPhiM((*v3_bPt)[0], (*v3_bEta)[0], (*v3_bPhi)[0], (*v3_bM)[0]);
		b2_3.SetPtEtaPhiM((*v3_bPt)[1], (*v3_bEta)[1], (*v3_bPhi)[1], (*v3_bM)[1]);
		b3_3.SetPtEtaPhiM((*v3_bPt)[2], (*v3_bEta)[2], (*v3_bPhi)[2], (*v3_bM)[2]);
		b4_3.SetPtEtaPhiM((*v3_bPt)[3], (*v3_bEta)[3], (*v3_bPhi)[3], (*v3_bM)[3]);

		b1b2_3 = b1_3 + b2_3;
		b1b3_3 = b1_3 + b3_3;
		b1b4_3 = b1_3 + b4_3;
		b2b3_3 = b2_3 + b3_3;
		b2b4_3 = b2_3 + b4_3;
		b3b4_3 = b3_3 + b4_3;
	}

	return;
}
void Fill_InvariantMass_3()
{
	Mb1b2_3->Fill(b1b2_3.M()*1e-3);
	Mb1b3_3->Fill(b1b3_3.M()*1e-3);
	Mb1b4_3->Fill(b1b4_3.M()*1e-3);
	Mb2b3_3->Fill(b2b3_3.M()*1e-3);
	Mb2b4_3->Fill(b2b4_3.M()*1e-3);
	Mb3b4_3->Fill(b3b4_3.M()*1e-3);

	MH1H2_3->Fill(H1H2_3.M()*1e-3);
	return;
}
void Fill_NLeadingJetPtM_3()
{
	jetLPt3->Fill((*v3_jetPt)[0]*1e-3);
	jet2LPt3->Fill((*v3_jetPt)[1]*1e-3);
	jet3LPt3->Fill((*v3_jetPt)[2]*1e-3);
	jet4LPt3->Fill((*v3_jetPt)[3]*1e-3);
	
	jetLM3->Fill( (*v3_jetM)[0]*1e-3);
	jet2LM3->Fill((*v3_jetM)[1]*1e-3);
	jet3LM3->Fill((*v3_jetM)[2]*1e-3);
	jet4LM3->Fill((*v3_jetM)[3]*1e-3);

	return;
}
void Draw_DiJetInvariantMass_3()
{
	v3_bjetPt.clear();
	v3_bjetEta.clear();
	v3_bjetPhi.clear();
	v3_bjetM.clear();
	for(int j = 0; j < v3_tagFlavor->size(); j++)
	{
		if((*v3_tagFlavor)[j] != 5) continue;
		v3_bjetPt.push_back((*v3_jetPt)[j]);
		v3_bjetEta.push_back((*v3_jetEta)[j]);
		v3_bjetPhi.push_back((*v3_jetPhi)[j]);
		v3_bjetM.push_back((*v3_jetM)[j]);

	}
	
	//! b jet's
	if(v3_bjetPt.size() > 3)
	{
		bJ1_3.SetPtEtaPhiM(v3_bjetPt[0], v3_bjetEta[0], v3_bjetPhi[0], v3_bjetM[0]);
		bJ2_3.SetPtEtaPhiM(v3_bjetPt[1], v3_bjetEta[1], v3_bjetPhi[1], v3_bjetM[1]);
		bJ3_3.SetPtEtaPhiM(v3_bjetPt[2], v3_bjetEta[2], v3_bjetPhi[2], v3_bjetM[2]);
		bJ4_3.SetPtEtaPhiM(v3_bjetPt[3], v3_bjetEta[3], v3_bjetPhi[3], v3_bjetM[3]);

		bJ1bJ2_3 = bJ1_3 + bJ2_3;
		bJ1bJ3_3 = bJ1_3 + bJ3_3;
		bJ1bJ4_3 = bJ1_3 + bJ4_3;
		bJ2bJ3_3 = bJ2_3 + bJ3_3;
		bJ2bJ4_3 = bJ2_3 + bJ4_3;
		bJ3bJ4_3 = bJ3_3 + bJ4_3;
	}
	return;
}
void Fill_bjetPtM_3(int &nhiggs)
{
	bjetLPt3->Fill( bJ1_3.Pt()*1e-3);
	bjet2LPt3->Fill(bJ2_3.Pt()*1e-3);
	bjet3LPt3->Fill(bJ3_3.Pt()*1e-3);
	bjet4LPt3->Fill(bJ4_3.Pt()*1e-3);

	bjetLM3->Fill( bJ1_3.M()*1e-3);
	bjet2LM3->Fill(bJ2_3.M()*1e-3);
	bjet3LM3->Fill(bJ3_3.M()*1e-3);
	bjet4LM3->Fill(bJ4_3.M()*1e-3);
	
	M_b1b2_3->Fill(bJ1bJ2_3.M()*1e-3);
	M_b1b3_3->Fill(bJ1bJ3_3.M()*1e-3);
	M_b1b4_3->Fill(bJ1bJ4_3.M()*1e-3);
	M_b2b3_3->Fill(bJ2bJ3_3.M()*1e-3);
	M_b2b4_3->Fill(bJ2bJ4_3.M()*1e-3);
	M_b3b4_3->Fill(bJ3bJ4_3.M()*1e-3);

	double dm_12_34 = 0, dm_13_24 = 0, dm_14_23 = 0;
	dm_12_34 = std::fabs(bJ1bJ2_3.M() - bJ3bJ4_3.M());
	dm_13_24 = std::fabs(bJ1bJ3_3.M() - bJ2bJ4_3.M());
	dm_14_23 = std::fabs(bJ1bJ4_3.M() - bJ2bJ3_3.M());
	dM_b1b2_b3b4_3->Fill(dm_12_34*1e-3);	
	dM_b1b3_b2b4_3->Fill(dm_13_24*1e-3);	
	dM_b1b4_b2b3_3->Fill(dm_14_23*1e-3);

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
		if((std::fabs(bJ1bJ2_3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ3bJ4_3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		{
			nhiggs++;
			if(bJ1bJ2_3.M() > bJ3bJ4_3.M())
			{
				M_Lhiggs3->Fill(bJ1bJ2_3.M()*1e-3);
				M_NLhiggs3->Fill(bJ3bJ4_3.M()*1e-3);
			
			} 
			else
			{
				M_Lhiggs3->Fill(bJ3bJ4_3.M()*1e-3);
				M_NLhiggs3->Fill(bJ1bJ2_3.M()*1e-3);
				
			}
		}
	}
	else if(higgs_candidates == 1324)
	{
		if((std::fabs(bJ1bJ3_3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ4_3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		{
			nhiggs++;
			if(bJ1bJ3_3.M() > bJ2bJ4_3.M())
			{
				M_Lhiggs3->Fill(bJ1bJ3_3.M()*1e-3);
				M_NLhiggs3->Fill(bJ2bJ4_3.M()*1e-3);
			
			} 
			else
			{
				M_Lhiggs3->Fill(bJ2bJ4_3.M()*1e-3);
				M_NLhiggs3->Fill(bJ1bJ3_3.M()*1e-3);
				
			}
		}
	
	}
	else if(higgs_candidates == 1423)
	{
		if((std::fabs(bJ1bJ4_3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth && std::fabs(bJ2bJ3_3.M()*1e-3 - HiggsMass) < 0.5 * MassWidth))
		{
			nhiggs++;
			if(bJ1bJ4_3.M() > bJ2bJ3_3.M())
			{
				M_Lhiggs3->Fill(bJ1bJ4_3.M()*1e-3);
				M_NLhiggs3->Fill(bJ2bJ3_3.M()*1e-3);
			
			} 
			else
			{
				M_Lhiggs3->Fill(bJ2bJ3_3.M()*1e-3);
				M_NLhiggs3->Fill(bJ1bJ4_3.M()*1e-3);
				
			}
		}
	
	}

	return;
}
void SetLineWidth3()
{

	MH1H2_3->SetLineWidth(2); 

	Mb1b2_3->SetLineWidth(2); 
	Mb1b3_3->SetLineWidth(2);
	Mb1b4_3->SetLineWidth(2);
	Mb2b3_3->SetLineWidth(2);
	Mb2b4_3->SetLineWidth(2);
	Mb3b4_3->SetLineWidth(2);

	//Number of btags 
	h_NbTags3->SetLineWidth(2);
	//Number of SMhiggs 
	NSMhiggs3->SetLineWidth(2);
	//Number of bquarks 
	Nbquarks3->SetLineWidth(2);
	Njets3->SetLineWidth(2);
	//! Book histograms:
	//Higgs Pt
	higgsPt3->SetLineWidth(2);
	//Higgs sub leading Pt
	higgsNLPt3->SetLineWidth(2);
	//reconstructed leading Higgs M
	M_Lhiggs3->SetLineWidth(2);
	//reconstructed sub leading Higgs M
	M_NLhiggs3->SetLineWidth(2);

	// invariant mass of a pair of b's, ctr = 3.0
	M_b1b2_3->SetLineWidth(2);
	M_b1b3_3->SetLineWidth(2);
	M_b1b4_3->SetLineWidth(2);
	M_b2b3_3->SetLineWidth(2);
	M_b2b4_3->SetLineWidth(2);
	M_b3b4_3->SetLineWidth(2);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_3->SetLineWidth(2);
	dM_b1b3_b2b4_3->SetLineWidth(2);
	dM_b1b4_b2b3_3->SetLineWidth(2);
	
	jetLM3->SetLineWidth(2);
	//jet 2nd leading M
	jet2LM3->SetLineWidth(2);
	//jet 3rd leading M
	jet3LM3->SetLineWidth(2);
	//jet 4th leading M
	jet4LM3->SetLineWidth(2);
	
	bjetLM3->SetLineWidth(2);
	//bjet 2nd leading M
	bjet2LM3->SetLineWidth(2);
	//bjet 3rd leading M
	bjet3LM3->SetLineWidth(2);
	//bjet 4th leading M
	bjet4LM3->SetLineWidth(2);
	
	jetLPt3->SetLineWidth(2);
	//jet 2nd leading Pt
	jet2LPt3->SetLineWidth(2);
	//jet 3rd leading Pt
	jet3LPt3->SetLineWidth(2);
	//jet 4th leading Pt
	jet4LPt3->SetLineWidth(2);

	bjetLPt3->SetLineWidth(2);
	//b-jet 2nd leading Pt
	bjet2LPt3->SetLineWidth(2);
	//b-jet 3rd leading Pt
	bjet3LPt3->SetLineWidth(2);
	//b-jet 4th leading Pt
	bjet4LPt3->SetLineWidth(2);

	bLPt3->SetLineWidth(2);
	//b 2nd leading Pt
	b2LPt3->SetLineWidth(2);
	//b 3rd leading Pt
	b3LPt3->SetLineWidth(2);
	//b 4th leading Pt
	b4LPt3->SetLineWidth(2);

	bCEta3->SetLineWidth(2);
	//b 2nd central Pt
	b2CEta3->SetLineWidth(2);
	//b 3rd central Pt
	b3CEta3->SetLineWidth(2);
	//b 4th central Pt
	b4CEta3->SetLineWidth(2);
	return;

}
void Scale_signalHistos3(double norm)
{

	MH1H2_3->Scale(norm); 

	Mb1b2_3->Scale(norm); 
	Mb1b3_3->Scale(norm);
	Mb1b4_3->Scale(norm);
	Mb2b3_3->Scale(norm);
	Mb2b4_3->Scale(norm);
	Mb3b4_3->Scale(norm);

	//Number of btags 
	h_NbTags3->Scale(norm);
	//Number of SMhiggs 
	NSMhiggs3->Scale(norm);
	//Number of bquarks 
	Nbquarks3->Scale(norm);
	Njets3->Scale(norm);
	//! Book histograms:
	//Higgs Pt
	higgsPt3->Scale(norm);
	//Higgs sub leading Pt
	higgsNLPt3->Scale(norm);
	//reconstructed leading Higgs M
	M_Lhiggs3->Scale(norm);
	//reconstructed sub leading Higgs M
	M_NLhiggs3->Scale(norm);

	// invariant mass of a pair of b's, ctr = 3.0
	M_b1b2_3->Scale(norm);
	M_b1b3_3->Scale(norm);
	M_b1b4_3->Scale(norm);
	M_b2b3_3->Scale(norm);
	M_b2b4_3->Scale(norm);
	M_b3b4_3->Scale(norm);
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_3->Scale(norm);
	dM_b1b3_b2b4_3->Scale(norm);
	dM_b1b4_b2b3_3->Scale(norm);
	
	jetLM3->Scale(norm);
	//jet 2nd leading M
	jet2LM3->Scale(norm);
	//jet 3rd leading M
	jet3LM3->Scale(norm);
	//jet 4th leading M
	jet4LM3->Scale(norm);
	
	bjetLM3->Scale(norm);
	//bjet 2nd leading M
	bjet2LM3->Scale(norm);
	//bjet 3rd leading M
	bjet3LM3->Scale(norm);
	//bjet 4th leading M
	bjet4LM3->Scale(norm);
	
	jetLPt3->Scale(norm);
	//jet 2nd leading Pt
	jet2LPt3->Scale(norm);
	//jet 3rd leading Pt
	jet3LPt3->Scale(norm);
	//jet 4th leading Pt
	jet4LPt3->Scale(norm);

	bjetLPt3->Scale(norm);
	//b-jet 2nd leading Pt
	bjet2LPt3->Scale(norm);
	//b-jet 3rd leading Pt
	bjet3LPt3->Scale(norm);
	//b-jet 4th leading Pt
	bjet4LPt3->Scale(norm);

	bLPt3->Scale(norm);
	//b 2nd leading Pt
	b2LPt3->Scale(norm);
	//b 3rd leading Pt
	b3LPt3->Scale(norm);
	//b 4th leading Pt
	b4LPt3->Scale(norm);

	bCEta3->Scale(norm);
	//b 2nd central Pt
	b2CEta3->Scale(norm);
	//b 3rd central Pt
	b3CEta3->Scale(norm);
	//b 4th central Pt
	b4CEta3->Scale(norm);
	return;

}
