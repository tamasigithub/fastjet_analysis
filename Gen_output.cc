#include "Gen_output.h"

//double Gen_output::match_jets(std::vector<PseudoJet> Jet1, std::vector<PseudoJet> Jet2)
//{
//
//	double dR, thisDR;
//	int bestTruthJet;
//
//	return dR;
//}
void Gen_output::init_MultiplicityHist()
{
	//! track multiplicities of jets matched to b quarks sorted in pt
        hMult_bJetLpt = new TH1D("hMult_bJetLpt","Multiplicity of leading b-jet", nMultiplicityBins, 0, maxMultiplicity);
	hMult_bJetNLpt = new TH1D("hMult_bJetNLpt","Multiplicity of 2nd leading b-jet", nMultiplicityBins, 0, maxMultiplicity);
	hMult_bJetNNLpt = new TH1D("hMult_bJetNNLpt","Multiplicity of 3rd leading b-jet", nMultiplicityBins, 0, maxMultiplicity);
	hMult_bJetNNNLpt = new TH1D("hMult_bJetNNNLpt","Multiplicity of 4th leading b-jet", nMultiplicityBins, 0, maxMultiplicity);

	//! track multiplicities of jets matched to b quarks sorted in pt
        hMult_JetLpt = new TH1D("hMult_JetLpt","Multiplicity of leading jet", nMultiplicityBins, 0, maxMultiplicity);
	hMult_JetNLpt = new TH1D("hMult_JetNLpt","Multiplicity of 2nd leading jet", nMultiplicityBins, 0, maxMultiplicity);
	hMult_JetNNLpt = new TH1D("hMult_JetNNLpt","Multiplicity of 3rd leading jet", nMultiplicityBins, 0, maxMultiplicity);
	hMult_JetNNNLpt = new TH1D("hMult_JetNNNLpt","Multiplicity of 4th leading jet", nMultiplicityBins, 0, maxMultiplicity);
	hMult_JetNNNNLpt = new TH1D("hMult_JetNNNNLpt","Multiplicity of 5th leading jet", nMultiplicityBins, 0, maxMultiplicity);
}
void Gen_output::init_PtHist(float xbins[], int nbins)
{

	//! Pt distributions of b quarks sorted in eta
        hbPt_Ceta = new TH1D("hbPt_Ceta","Pt of most central b quark", nbins, xbins);
	hbPt_NCeta = new TH1D("hbPt_NCeta","Pt of 2nd most central b quark", nbins, xbins);
	hbPt_NNCeta = new TH1D("hbPt_NNCeta","Pt of 3rd most central b quark", nbins, xbins);
	hbPt_NNNCeta = new TH1D("hbPt_NNNCeta","Pt of 4th most central b quark", nbins, xbins);
	//! Pt distributions of b quarks sorted in pt
        hbPt_Lpt = new TH1D("hbPt_Lpt","Pt of leading b quark", nbins, xbins);
	hbPt_NLpt = new TH1D("hbPt_NLpt","Pt of 2nd leading b quark", nbins, xbins);
	hbPt_NNLpt = new TH1D("hbPt_NNLpt","Pt of 3rd leading b quark", nbins, xbins);
	hbPt_NNNLpt = new TH1D("hbPt_NNNLpt","Pt of 4th leading b quark", nbins, xbins);
	//! Pt distributions of jets matched to b quarks sorted in pt
        hbJetPt_Lpt = new TH1D("hbJetPt_Lpt","Pt of leading b-jet", nbins, xbins);
	hbJetPt_NLpt = new TH1D("hbJetPt_NLpt","Pt of 2nd leading b-jet", nbins, xbins);
	hbJetPt_NNLpt = new TH1D("hbJetPt_NNLpt","Pt of 3rd leading b-jet", nbins, xbins);
	hbJetPt_NNNLpt = new TH1D("hbJetPt_NNNLpt","Pt of 4th leading b-jet", nbins, xbins);
	//! pt distributions of 5 leading pt jets
        hJetPt_PULpt = new TH1D("hJetPt_PULpt","Pt of 1st highest Pt jet", nbins, xbins);
	hJetPt_PUNLpt = new TH1D("hJetPt_PUNLpt","Pt of 2nd highest Pt jet", nbins, xbins);
	hJetPt_PUNNLpt = new TH1D("hJetPt_PUNNLpt","Pt of 3rd highest Pt jet", nbins, xbins);
	hJetPt_PUNNNLpt = new TH1D("hJetPt_PUNNNLpt","Pt of 4th highest Pt jet", nbins, xbins);
	hJetPt_PUNNNNLpt = new TH1D("hJetPt_PUNNNNLpt","Pt of 5th highest Pt jet", nbins, xbins);
}
void Gen_output::init_EtaHist()
{

	//! eta distributions of b quarks sorted in eta
        hbEta_Ceta = new TH1D("hbEta_Ceta","Eta of most central b quark", nEtaBins, etaMin, etaMax);
	hbEta_NCeta = new TH1D("hbEta_NCeta","Eta of 2nd most central b quark", nEtaBins, etaMin, etaMax);
	hbEta_NNCeta = new TH1D("hbEta_NNCeta","Eta of 3rd most central b quark", nEtaBins, etaMin, etaMax);
	hbEta_NNNCeta = new TH1D("hbEta_NNNCeta","Eta of 4th most central b quark", nEtaBins, etaMin, etaMax);
	//! eta distributions of b quarks sorted in pt
        hbEta_Lpt = new TH1D("hbEta_Lpt","Eta of leading b quark", nEtaBins, etaMin, etaMax);
	hbEta_NLpt = new TH1D("hbEta_NLpt","Eta of 2nd leading b quark", nEtaBins, etaMin, etaMax);
	hbEta_NNLpt = new TH1D("hbEta_NNLpt","Eta of 3rd leading b quark", nEtaBins, etaMin, etaMax);
	hbEta_NNNLpt = new TH1D("hbEta_NNNLpt","Eta of 4th leading b quark", nEtaBins, etaMin, etaMax);
	//! eta distributions of jets matched to b quarks sorted in eta
        hbJetEta_Ceta = new TH1D("hbJetEta_Ceta","Eta of most central b-jet", nEtaBins, etaMin, etaMax);
	hbJetEta_NCeta = new TH1D("hbJetEta_NCeta","Eta of 2nd most central b-jet", nEtaBins, etaMin, etaMax);
	hbJetEta_NNCeta = new TH1D("hbJetEta_NNCeta","Eta of 3rd most central b-jet", nEtaBins, etaMin, etaMax);
	hbJetEta_NNNCeta = new TH1D("hbJetEta_NNNCeta","Eta of 4th most central b-jet", nEtaBins, etaMin, etaMax);
}
void Gen_output::SetPtHist_props()
{
	hbPt_NNNCeta->SetLineColor(kGreen);
	hbPt_NNCeta->SetLineColor(kRed);
	hbPt_NCeta->SetLineColor(kBlack);
	hbPt_Ceta->SetLineColor(kOrange);

	hbPt_NNNCeta->SetLineWidth(2);
	hbPt_NNCeta->SetLineWidth(2);
	hbPt_NCeta->SetLineWidth(2);
	hbPt_Ceta->SetLineWidth(2);

        hbPt_Ceta->GetXaxis()->SetTitle("b quark p_{t} [GeV/c]");
        hbPt_NCeta->GetXaxis()->SetTitle("b quark p_{t} [GeV/c]");
        hbPt_NNCeta->GetXaxis()->SetTitle("b quark p_{t} [GeV/c]");
        hbPt_NNNCeta->GetXaxis()->SetTitle("b quark p_{t} [GeV/c]");
	
	hbPt_NNNLpt->SetLineColor(kGreen);
	hbPt_NNLpt->SetLineColor(kRed);
	hbPt_NLpt->SetLineColor(kBlack);
	hbPt_Lpt->SetLineColor(kOrange);

	hbPt_NNNLpt->SetLineWidth(2);
	hbPt_NNLpt->SetLineWidth(2);
	hbPt_NLpt->SetLineWidth(2);
	hbPt_Lpt->SetLineWidth(2);

        hbPt_Lpt->GetXaxis()->SetTitle("b quark p_{t} [GeV/c]");
        hbPt_NLpt->GetXaxis()->SetTitle("b quark p_{t} [GeV/c]");
        hbPt_NNLpt->GetXaxis()->SetTitle("b quark p_{t} [GeV/c]");
        hbPt_NNNLpt->GetXaxis()->SetTitle("b quark p_{t} [GeV/c]");
	
	hbJetPt_NNNLpt->SetLineColor(kGreen);
	hbJetPt_NNLpt->SetLineColor(kRed);
	hbJetPt_NLpt->SetLineColor(kBlack);
	hbJetPt_Lpt->SetLineColor(kOrange);

	hbJetPt_NNNLpt->SetLineWidth(2);
	hbJetPt_NNLpt->SetLineWidth(2);
	hbJetPt_NLpt->SetLineWidth(2);
	hbJetPt_Lpt->SetLineWidth(2);

        hbJetPt_Lpt->GetXaxis()->SetTitle("b-jet p_{t} [GeV/c]");
        hbJetPt_NLpt->GetXaxis()->SetTitle("b-jet p_{t} [GeV/c]");
        hbJetPt_NNLpt->GetXaxis()->SetTitle("b-jet p_{t} [GeV/c]");
        hbJetPt_NNNLpt->GetXaxis()->SetTitle("b-jet p_{t} [GeV/c]");
	
	hJetPt_PUNNNNLpt->SetLineColor(kBlue);
	hJetPt_PUNNNLpt->SetLineColor(kGreen);
	hJetPt_PUNNLpt->SetLineColor(kRed);
	hJetPt_PUNLpt->SetLineColor(kBlack);
	hJetPt_PULpt->SetLineColor(kOrange);

	hJetPt_PUNNNNLpt->SetLineWidth(2);
	hJetPt_PUNNNLpt->SetLineWidth(2);
	hJetPt_PUNNLpt->SetLineWidth(2);
	hJetPt_PUNLpt->SetLineWidth(2);
	hJetPt_PULpt->SetLineWidth(2);

        hJetPt_PULpt->GetXaxis()->SetTitle("Track-jet p_{t} [GeV/c]");
        hJetPt_PUNLpt->GetXaxis()->SetTitle("Track-jet p_{t} [GeV/c]");
        hJetPt_PUNNLpt->GetXaxis()->SetTitle("Track-jet p_{t} [GeV/c]");
        hJetPt_PUNNNLpt->GetXaxis()->SetTitle("Track-jet p_{t} [GeV/c]");
        hJetPt_PUNNNNLpt->GetXaxis()->SetTitle("Track-jet p_{t} [GeV/c]");

}
void Gen_output::SetEtaHist_props()
{
	
	hbJetEta_NNNCeta->SetLineColor(kGreen);
	hbJetEta_NNCeta->SetLineColor(kRed);
	hbJetEta_NCeta->SetLineColor(kBlack);
	hbJetEta_Ceta->SetLineColor(kOrange);

	hbJetEta_NNNCeta->SetLineWidth(2);
	hbJetEta_NNCeta->SetLineWidth(2);
	hbJetEta_NCeta->SetLineWidth(2);
	hbJetEta_Ceta->SetLineWidth(2);

        hbJetEta_Ceta->GetXaxis()->SetTitle("b-jet #eta");
        hbJetEta_NCeta->GetXaxis()->SetTitle("b-jet #eta");
        hbJetEta_NNCeta->GetXaxis()->SetTitle("b-jet #eta");
        hbJetEta_NNNCeta->GetXaxis()->SetTitle("b-jet #eta");
	
	hbEta_NNNCeta->SetLineColor(kGreen);
	hbEta_NNCeta->SetLineColor(kRed);
	hbEta_NCeta->SetLineColor(kBlack);
	hbEta_Ceta->SetLineColor(kOrange);

	hbEta_NNNCeta->SetLineWidth(2);
	hbEta_NNCeta->SetLineWidth(2);
	hbEta_NCeta->SetLineWidth(2);
	hbEta_Ceta->SetLineWidth(2);

        hbEta_Ceta->GetXaxis()->SetTitle("b quark #eta");
        hbEta_NCeta->GetXaxis()->SetTitle("b quark #eta");
        hbEta_NNCeta->GetXaxis()->SetTitle("b quark #eta");
        hbEta_NNNCeta->GetXaxis()->SetTitle("b quark #eta");
	
	hbEta_NNNLpt->SetLineColor(kGreen);
	hbEta_NNLpt->SetLineColor(kRed);
	hbEta_NLpt->SetLineColor(kBlack);
	hbEta_Lpt->SetLineColor(kOrange);

	hbEta_NNNLpt->SetLineWidth(2);
	hbEta_NNLpt->SetLineWidth(2);
	hbEta_NLpt->SetLineWidth(2);
	hbEta_Lpt->SetLineWidth(2);

        hbEta_Lpt->GetXaxis()->SetTitle("b quark #eta");
        hbEta_NLpt->GetXaxis()->SetTitle("b quark #eta");
        hbEta_NNLpt->GetXaxis()->SetTitle("b quark #eta");
        hbEta_NNNLpt->GetXaxis()->SetTitle("b quark #eta");
	


}
void Gen_output::SetMultiplicityHist_props()
{

	hMult_JetNNNLpt->SetLineColor(kGreen);
	hMult_JetNNLpt->SetLineColor(kRed);
	hMult_JetNLpt->SetLineColor(kBlack);
	hMult_JetLpt->SetLineColor(kOrange);

	hMult_JetNNNLpt->SetLineWidth(2);
	hMult_JetNNLpt->SetLineWidth(2);
	hMult_JetNLpt->SetLineWidth(2);
	hMult_JetLpt->SetLineWidth(2);

        hMult_JetLpt->GetXaxis()->SetTitle("# jet constituents");
        hMult_JetNLpt->GetXaxis()->SetTitle("# jet constituents");
        hMult_JetNNLpt->GetXaxis()->SetTitle("# jet constituents");
        hMult_JetNNNLpt->GetXaxis()->SetTitle("# jet constituents");
	
	hMult_bJetNNNLpt->SetLineColor(kGreen);
	hMult_bJetNNLpt->SetLineColor(kRed);
	hMult_bJetNLpt->SetLineColor(kBlack);
	hMult_bJetLpt->SetLineColor(kOrange);

	hMult_bJetNNNLpt->SetLineWidth(2);
	hMult_bJetNNLpt->SetLineWidth(2);
	hMult_bJetNLpt->SetLineWidth(2);
	hMult_bJetLpt->SetLineWidth(2);

        hMult_bJetLpt->GetXaxis()->SetTitle("# b-jet constituents");
        hMult_bJetNLpt->GetXaxis()->SetTitle("# b-jet constituents");
        hMult_bJetNNLpt->GetXaxis()->SetTitle("# b-jet constituents");
        hMult_bJetNNNLpt->GetXaxis()->SetTitle("# b-jet constituents");
}
void Gen_output::Fill_bJetEta()
{

	if(vectorof_bJetsEta.size() >= NbJETS)
	{
		hbJetEta_NNNCeta->Fill(std::fabs(vectorof_bJetsEta[3]));	
		hbJetEta_NNCeta->Fill(std::fabs(vectorof_bJetsEta[2]));	
		hbJetEta_NCeta->Fill(std::fabs(vectorof_bJetsEta[1]));	
		hbJetEta_Ceta->Fill(std::fabs(vectorof_bJetsEta[0]));	
	}
	else if (vectorof_bJetsEta.size() >= NbJETS - 1)
	{
		hbJetEta_NNCeta->Fill(std::fabs(vectorof_bJetsEta[2]));	
		hbJetEta_NCeta->Fill(std::fabs(vectorof_bJetsEta[1]));	
		hbJetEta_Ceta->Fill(std::fabs(vectorof_bJetsEta[0]));	
	}
	else if (vectorof_bJetsEta.size() >= NbJETS - 2)
	{
		hbJetEta_NCeta->Fill(std::fabs(vectorof_bJetsEta[1]));	
		hbJetEta_Ceta->Fill(std::fabs(vectorof_bJetsEta[0]));	
	}
	else if (vectorof_bJetsEta.size() >= NbJETS - 3)
	{
		hbJetEta_Ceta->Fill(std::fabs(vectorof_bJetsEta[0]));	
	}
}
void Gen_output::Fill_bJetMultiplicity()
{

	if(v_bJetMultiplicity.size() >= NbJETS)
	{
		hMult_bJetNNNLpt->Fill(v_bJetMultiplicity[3]);	
		hMult_bJetNNLpt->Fill(v_bJetMultiplicity[2]);	
		hMult_bJetNLpt->Fill(v_bJetMultiplicity[1]);	
		hMult_bJetLpt->Fill(v_bJetMultiplicity[0]);	
	}
	else if (v_bJetMultiplicity.size() >= NbJETS - 1)
	{
		hMult_bJetNNLpt->Fill(v_bJetMultiplicity[2]);	
		hMult_bJetNLpt->Fill(v_bJetMultiplicity[1]);	
		hMult_bJetLpt->Fill(v_bJetMultiplicity[0]);	
	}
	else if (v_bJetMultiplicity.size() >= NbJETS - 2)
	{
		hMult_bJetNLpt->Fill(v_bJetMultiplicity[1]);	
		hMult_bJetLpt->Fill(v_bJetMultiplicity[0]);	
	}
	else if (v_bJetMultiplicity.size() >= NbJETS - 3)
	{
		hMult_bJetLpt->Fill(v_bJetMultiplicity[0]);	
	}
}
void Gen_output::Fill_JetMultiplicity()
{

	if(v_JetMultiplicity.size() >= Njet_max)
	{
		hMult_JetNNNNLpt->Fill(v_JetMultiplicity[4]);	
		hMult_JetNNNLpt->Fill(v_JetMultiplicity[3]);	
		hMult_JetNNLpt->Fill(v_JetMultiplicity[2]);	
		hMult_JetNLpt->Fill(v_JetMultiplicity[1]);	
		hMult_JetLpt->Fill(v_JetMultiplicity[0]);	
	}
	else if (v_JetMultiplicity.size() >= Njet_max - 1)
	{
		hMult_JetNNNLpt->Fill(v_JetMultiplicity[3]);	
		hMult_JetNNLpt->Fill(v_JetMultiplicity[2]);	
		hMult_JetNLpt->Fill(v_JetMultiplicity[1]);	
		hMult_JetLpt->Fill(v_JetMultiplicity[0]);	
	}
	else if (v_JetMultiplicity.size() >= Njet_max - 2)
	{
		hMult_JetNNLpt->Fill(v_JetMultiplicity[2]);	
		hMult_JetNLpt->Fill(v_JetMultiplicity[1]);	
		hMult_JetLpt->Fill(v_JetMultiplicity[0]);	
	}
	else if (v_JetMultiplicity.size() >= Njet_max - 3)
	{
		hMult_JetNLpt->Fill(v_JetMultiplicity[1]);	
		hMult_JetLpt->Fill(v_JetMultiplicity[0]);	
	}
	else if (v_JetMultiplicity.size() >= Njet_max - 4)
	{
		hMult_JetLpt->Fill(v_JetMultiplicity[0]);	
	}
}
void Gen_output::Fill_bJetPt()
{

	if(vectorof_bJetsPt.size() >= NbJETS)
	{
		hbJetPt_NNNLpt->Fill(vectorof_bJetsPt[3]*1e-3);	
		hbJetPt_NNLpt->Fill(vectorof_bJetsPt[2]*1e-3);	
		hbJetPt_NLpt->Fill(vectorof_bJetsPt[1]*1e-3);	
		hbJetPt_Lpt->Fill(vectorof_bJetsPt[0]*1e-3);	
	}
	else if (vectorof_bJetsPt.size() >= NbJETS - 1)
	{
		hbJetPt_NNLpt->Fill(vectorof_bJetsPt[2]*1e-3);	
		hbJetPt_NLpt->Fill(vectorof_bJetsPt[1]*1e-3);	
		hbJetPt_Lpt->Fill(vectorof_bJetsPt[0]*1e-3);	
	}
	else if (vectorof_bJetsPt.size() >= NbJETS - 2)
	{
		hbJetPt_NLpt->Fill(vectorof_bJetsPt[1]*1e-3);	
		hbJetPt_Lpt->Fill(vectorof_bJetsPt[0]*1e-3);	
	}
	else if (vectorof_bJetsPt.size() >= NbJETS - 3)
	{
		hbJetPt_Lpt->Fill(vectorof_bJetsPt[0]*1e-3);	
	}
}
void Gen_output::FillEta_bquarks_eta(std::vector<PseudoJet> Obj, int NObj)
{

	if(Obj.size() >= NObj)
	{
		hbEta_NNNCeta->Fill(std::fabs(Obj[3].eta()));	
		hbEta_NNCeta->Fill(std::fabs(Obj[2].eta()));	
		hbEta_NCeta->Fill(std::fabs(Obj[1].eta()));	
		hbEta_Ceta->Fill(std::fabs(Obj[0].eta()));	
	}
	else if (Obj.size() >= NObj - 1)
	{
		hbEta_NNCeta->Fill(std::fabs(Obj[2].eta()));	
		hbEta_NCeta->Fill(std::fabs(Obj[1].eta()));	
		hbEta_Ceta->Fill(std::fabs(Obj[0].eta()));	
	}
	else if (Obj.size() >= NObj - 2)
	{
		hbEta_NCeta->Fill(std::fabs(Obj[1].eta()));	
		hbEta_Ceta->Fill(std::fabs(Obj[0].eta()));	
	}
	else if (Obj.size() >= NObj - 3)
	{
		hbEta_Ceta->Fill(std::fabs(Obj[0].eta()));	
	}
}
void Gen_output::FillEta_bquarks_pt(std::vector<PseudoJet> Obj, int NObj)
{

	if(Obj.size() >= NObj)
	{
		hbEta_NNNLpt->Fill(std::fabs(Obj[3].eta()));	
		hbEta_NNLpt->Fill(std::fabs(Obj[2].eta()));	
		hbEta_NLpt->Fill(std::fabs(Obj[1].eta()));	
		hbEta_Lpt->Fill(std::fabs(Obj[0].eta()));	
	}
	else if (Obj.size() >= NObj - 1)
	{
		hbEta_NNLpt->Fill(std::fabs(Obj[2].eta()));	
		hbEta_NLpt->Fill(std::fabs(Obj[1].eta()));	
		hbEta_Lpt->Fill(std::fabs(Obj[0].eta()));	
	}
	else if (Obj.size() >= NObj - 2)
	{
		hbEta_NLpt->Fill(std::fabs(Obj[1].eta()));	
		hbEta_Lpt->Fill(std::fabs(Obj[0].eta()));	
	}
	else if (Obj.size() >= NObj - 3)
	{
		hbEta_Lpt->Fill(std::fabs(Obj[0].eta()));	
	}
}
void Gen_output::FillPt_bquarks_eta(std::vector<PseudoJet> Obj, int NObj)
{

	if(Obj.size() >= NObj)
	{
		hbPt_NNNCeta->Fill(Obj[3].pt()*1e-3);	
		hbPt_NNCeta->Fill(Obj[2].pt()*1e-3);	
		hbPt_NCeta->Fill(Obj[1].pt()*1e-3);	
		hbPt_Ceta->Fill(Obj[0].pt()*1e-3);	
	}
	else if (Obj.size() >= NObj - 1)
	{
		hbPt_NNCeta->Fill(Obj[2].pt()*1e-3);	
		hbPt_NCeta->Fill(Obj[1].pt()*1e-3);	
		hbPt_Ceta->Fill(Obj[0].pt()*1e-3);	
	}
	else if (Obj.size() >= NObj - 2)
	{
		hbPt_NCeta->Fill(Obj[1].pt()*1e-3);	
		hbPt_Ceta->Fill(Obj[0].pt()*1e-3);	
	}
	else if (Obj.size() >= NObj - 3)
	{
		hbPt_Ceta->Fill(Obj[0].pt()*1e-3);	
	}
}
void Gen_output::FillPt_bquarks_pt(std::vector<PseudoJet> Obj, int NObj)
{

	if(Obj.size() >= NObj)
	{
		hbPt_NNNLpt->Fill(Obj[3].pt()*1e-3);	
		hbPt_NNLpt->Fill(Obj[2].pt()*1e-3);	
		hbPt_NLpt->Fill(Obj[1].pt()*1e-3);	
		hbPt_Lpt->Fill(Obj[0].pt()*1e-3);	
	}
	else if (Obj.size() >= NObj - 1)
	{
		hbPt_NNLpt->Fill(Obj[2].pt()*1e-3);	
		hbPt_NLpt->Fill(Obj[1].pt()*1e-3);	
		hbPt_Lpt->Fill(Obj[0].pt()*1e-3);	
	}
	else if (Obj.size() >= NObj - 2)
	{
		hbPt_NLpt->Fill(Obj[1].pt()*1e-3);	
		hbPt_Lpt->Fill(Obj[0].pt()*1e-3);	
	}
	else if (Obj.size() >= NObj - 3)
	{
		hbPt_Lpt->Fill(Obj[0].pt()*1e-3);	
	}
}
void Gen_output::FillPt_Jets_pt(std::vector<PseudoJet> Obj, int NObj)
{

	if(Obj.size() >= NObj)
	{
		hJetPt_PUNNNNLpt->Fill(std::fabs(Obj[4].pt()*1e-3));	
		hJetPt_PUNNNLpt->Fill(std::fabs(Obj[3].pt()*1e-3));	
		hJetPt_PUNNLpt->Fill(std::fabs(Obj[2].pt()*1e-3));	
		hJetPt_PUNLpt->Fill(std::fabs(Obj[1].pt()*1e-3));	
		hJetPt_PULpt->Fill(std::fabs(Obj[0].pt()*1e-3));	
	}
	else if (Obj.size() >= NObj-1)
	{
		hJetPt_PUNNNLpt->Fill(std::fabs(Obj[3].pt()*1e-3));	
		hJetPt_PUNNLpt->Fill(std::fabs(Obj[2].pt()*1e-3));	
		hJetPt_PUNLpt->Fill(std::fabs(Obj[1].pt()*1e-3));	
		hJetPt_PULpt->Fill(std::fabs(Obj[0].pt()*1e-3));	
	}
	else if (Obj.size() >= NObj-2)
	{
		hJetPt_PUNNLpt->Fill(std::fabs(Obj[2].pt()*1e-3));	
		hJetPt_PUNLpt->Fill(std::fabs(Obj[1].pt()*1e-3));	
		hJetPt_PULpt->Fill(std::fabs(Obj[0].pt()*1e-3));	
	}
	else if (Obj.size() >= NObj-3)
	{
		hJetPt_PUNLpt->Fill(std::fabs(Obj[1].pt()*1e-3));	
		hJetPt_PULpt->Fill(std::fabs(Obj[0].pt()*1e-3));	
	}
	else if (Obj.size() >= NObj-4)
	{
		hJetPt_PULpt->Fill(std::fabs(Obj[0].pt()*1e-3));	
	}
}
void Gen_output::WriteEta()
{
	hbJetEta_Ceta->Write();
        hbJetEta_NCeta->Write();
        hbJetEta_NNCeta->Write();
        hbJetEta_NNNCeta->Write();
	
	hbEta_Ceta->Write();
        hbEta_NCeta->Write();
        hbEta_NNCeta->Write();
        hbEta_NNNCeta->Write();
	
	hbEta_Lpt->Write();
        hbEta_NLpt->Write();
        hbEta_NNLpt->Write();
        hbEta_NNNLpt->Write();
	

}
void Gen_output::WritePt()
{
	hbJetPt_Lpt->Write();
        hbJetPt_NLpt->Write();
        hbJetPt_NNLpt->Write();
        hbJetPt_NNNLpt->Write();
	
	hbPt_Ceta->Write();
        hbPt_NCeta->Write();
        hbPt_NNCeta->Write();
        hbPt_NNNCeta->Write();
	
	hbPt_Lpt->Write();
        hbPt_NLpt->Write();
        hbPt_NNLpt->Write();
        hbPt_NNNLpt->Write();

	hJetPt_PULpt->Write();
        hJetPt_PUNLpt->Write();
        hJetPt_PUNNLpt->Write();
        hJetPt_PUNNNLpt->Write();
        hJetPt_PUNNNNLpt->Write();
}
void Gen_output::WriteMultiplicity()
{
	hMult_bJetLpt->Write();
        hMult_bJetNLpt->Write();
        hMult_bJetNNLpt->Write();
        hMult_bJetNNNLpt->Write();
	
	hMult_JetLpt->Write();
        hMult_JetNLpt->Write();
        hMult_JetNNLpt->Write();
        hMult_JetNNNLpt->Write();
        hMult_JetNNNNLpt->Write();

}
void Gen_output::Clear_OutVars()
{
	eventNo = 0;
	Njets = 0;
	Nbquarks = 0;
	NSMhiggs = 0;
	//jetE_sm.clear();
	//jetPt_sm.clear();
	jetE.clear();
	//jetE_reso.clear();
	jetPt.clear();
	constituentPt.clear();
	jetPhi.clear();
	constituentPhi.clear();
	jetTheta.clear();
	constituentTheta.clear();
	jetEta.clear();
	constituentEta.clear();
	jetEt.clear();
	constituentEt.clear();
	jetMt2.clear();
	constituentMt.clear();
	constituentPdg.clear();
	constituentZ0.clear();
	hasConstituents.clear();
	Nconstituents.clear();

	btaggedJets.clear();		
	btagJets_dR.clear();
	b1tagJets_dR.clear();
	b2tagJets_dR.clear();
	b3tagJets_dR.clear();
	b4tagJets_dR.clear();

	vectorof_bJetsEta.clear();	
	vectorof_bJetsPt.clear();	
	v_bJetMultiplicity.clear();	
	v_JetMultiplicity.clear();	

	higgsPt.clear();
	higgsLPt.clear();
	higgsNLPt.clear();
	
	bLPt.clear();
	bNLPt.clear();
	bNNLPt.clear();
	bNNNLPt.clear();

	higgsCEta.clear();
	higgsNCEta.clear();

	dRhiggs = 0;
	dRb12 = 0;
	dRb13 = 0;
	dRb14 = 0;
	dRb23 = 0;
	dRb24 = 0;
	dRb34 = 0;
}
void Gen_output::init_TTree()
{
	glob_jet = new TTree("glob_jet","tree of glob_jet");
}
void Gen_output::Branch_OutTree()
{
	glob_jet->Branch("event",&eventNo);
	glob_jet->Branch("Njets",&Njets);
	glob_jet->Branch("Nbquarks",&Nbquarks);
	glob_jet->Branch("NSMhiggs",&NSMhiggs);
	//glob_jet->Branch("jetE_sm",&jetE_sm);
	//glob_jet->Branch("jetPt_sm",&jetPt_sm);
	glob_jet->Branch("jetE",&jetE);
	//glob_jet->Branch("jetE_reso",&jetE_reso);
	glob_jet->Branch("jetPt",&jetPt);
	glob_jet->Branch("jetConstPt",&constituentPt);
	glob_jet->Branch("jetPhi",&jetPhi);
	glob_jet->Branch("jetConstPhi",&constituentPhi);
	glob_jet->Branch("jetTheta",&jetTheta);
	glob_jet->Branch("jetConstTheta",&constituentTheta);
	glob_jet->Branch("jetEta",&jetEta);
	glob_jet->Branch("jetConstEta",&constituentEta);
	glob_jet->Branch("jetEt",&jetEt);
	glob_jet->Branch("jetConstEt",&constituentEt);
	glob_jet->Branch("jetMt2",&jetMt2);
	glob_jet->Branch("jetConstMt",&constituentMt);
	glob_jet->Branch("jetConstPdg",&constituentPdg);
	glob_jet->Branch("jetConstZ0",&constituentZ0);
	glob_jet->Branch("has_constituents",&hasConstituents);
	glob_jet->Branch("Nconstituents", &Nconstituents);
	
	glob_jet->Branch("btaggedJets", &btaggedJets);
	glob_jet->Branch("btagJets_dR", &btagJets_dR);
	glob_jet->Branch("b1tagJets_dR", &b1tagJets_dR);
	glob_jet->Branch("b2tagJets_dR", &b2tagJets_dR);
	glob_jet->Branch("b3tagJets_dR", &b3tagJets_dR);
	glob_jet->Branch("b4tagJets_dR", &b4tagJets_dR);
	
	glob_jet->Branch("v_bJetsPt", &vectorof_bJetsPt);
	glob_jet->Branch("v_bJetsEta", &vectorof_bJetsEta);
	glob_jet->Branch("v_bJetMult", &v_bJetMultiplicity);
	glob_jet->Branch("v_JetMult", &v_JetMultiplicity);
	
	glob_jet->Branch("higgsPt", &higgsPt);
	glob_jet->Branch("higgsLPt", &higgsLPt);
	glob_jet->Branch("higgsNLPt", &higgsNLPt);
	
	glob_jet->Branch("bLPt", &bLPt);
	glob_jet->Branch("bNLPt", &bNLPt);
	glob_jet->Branch("bNNLPt", &bNNLPt);
	glob_jet->Branch("bNNNLPt", &bNNNLPt);

	glob_jet->Branch("higgsCEta", &higgsCEta);
	glob_jet->Branch("higgsNCEta", &higgsNCEta);

	glob_jet->Branch("dRhiggs", &dRhiggs);
	
	glob_jet->Branch("dRb12", &dRb12);
	glob_jet->Branch("dRb13", &dRb13);
	glob_jet->Branch("dRb14", &dRb14);
	glob_jet->Branch("dRb23", &dRb23);
	glob_jet->Branch("dRb24", &dRb24);
	glob_jet->Branch("dRb34", &dRb34);

}
