#include "Rate_sumpt.h"

void Rate_sumpt::init_Histos(float xbins[], int nbins)
{

	//! Book Histogram        
	//! sumpt histos
	h_PULpt = new TH1D("h_PULpt","Rate of highest Pt track jet in <#mu> 1000 ",nbins,xbins);
	h_PUNLpt = new TH1D("h_PUNLpt","Rate of 2nd highest Pt track jet in <#mu> 1000 ",nbins,xbins);
	h_PUNNLpt = new TH1D("h_PUNNLpt","Rate of 3rd highest Pt track jet in <#mu> 1000 ",nbins,xbins);
	h_PUNNNLpt = new TH1D("h_PUNNNLpt","Rate of 4th highest Pt track jet in <#mu> 1000 ",nbins,xbins);
	h_PUNNNNLpt = new TH1D("h_PUNNNNLpt","Rate Vs track jet P_{t} in <#mu> 1000 , PB finding using sum pt",nbins,xbins);
	//! maxpt approach
        ha_PULpt = new TH1D("ha_PULpt","Rate of highest Pt track jet in <#mu> 1000 ",nbins,xbins);
	ha_PUNLpt = new TH1D("ha_PUNLpt","Rate of 2nd highest Pt track jet in <#mu> 1000 ",nbins,xbins);
	ha_PUNNLpt = new TH1D("ha_PUNNLpt","Rate of 3rd highest Pt track jet in <#mu> 1000 ",nbins,xbins);
	ha_PUNNNLpt = new TH1D("ha_PUNNNLpt","Rate of 4th highest Pt track jet in <#mu> 1000 ",nbins,xbins);
	ha_PUNNNNLpt = new TH1D("ha_PUNNNNLpt","Rate Vs track jet P_{t} in <#mu> 1000 ",nbins,xbins);
	//! without binning
        hb_PULpt = new TH1D("hb_PULpt","Rate of highest Pt track jet in <#mu> 1000 ",nbins,xbins);
	hb_PUNLpt = new TH1D("hb_PUNLpt","Rate of 2nd highest Pt track jet in <#mu> 1000 ",nbins,xbins);
	hb_PUNNLpt = new TH1D("hb_PUNNLpt","Rate of 3rd highest Pt track jet in <#mu> 1000 ",nbins,xbins);
	hb_PUNNNLpt = new TH1D("hb_PUNNNLpt","Rate of 4th highest Pt track jet in <#mu> 1000 ",nbins,xbins);
	hb_PUNNNNLpt = new TH1D("hb_PUNNNNLpt","Rate Vs track jet P_{t} in <#mu> 1000 , without binning along beam axis",nbins,xbins);

	/////! Multiplicity histograms
	//! sumpt histos
	hM_PULpt = new TH1D("hM_PULpt","Multiplicity of highest Pt track jet in <#mu> 1000 ",nMultiplicityBins,0,maxMultiplicity);
	hM_PUNLpt = new TH1D("hM_PUNLpt","Multiplicity of 2nd highest Pt track jet in <#mu> 1000 ",nMultiplicityBins,0,maxMultiplicity);
	hM_PUNNLpt = new TH1D("hM_PUNNLpt","Multiplicity of 3rd highest Pt track jet in <#mu> 1000 ",nMultiplicityBins,0,maxMultiplicity);
	hM_PUNNNLpt = new TH1D("hM_PUNNNLpt","Multiplicity of 4th highest Pt track jet in <#mu> 1000 ",nMultiplicityBins,0,maxMultiplicity);
	hM_PUNNNNLpt = new TH1D("hM_PUNNNNLpt","Track-jet multiplicity in <#mu> 1000, sum-pt",nMultiplicityBins,0,maxMultiplicity);
	//! maxpt approach
        hMa_PULpt = new TH1D("hMa_PULpt","Multiplicity of highest Pt track jet in <#mu> 1000 ",nMultiplicityBins,0,maxMultiplicity);
	hMa_PUNLpt = new TH1D("hMa_PUNLpt","Multiplicity of 2nd highest Pt track jet in <#mu> 1000 ",nMultiplicityBins,0,maxMultiplicity);
	hMa_PUNNLpt = new TH1D("hMa_PUNNLpt","Multiplicity of 3rd highest Pt track jet in <#mu> 1000 ",nMultiplicityBins,0,maxMultiplicity);
	hMa_PUNNNLpt = new TH1D("hMa_PUNNNLpt","Multiplicity of 4th highest Pt track jet in <#mu> 1000 ",nMultiplicityBins,0,maxMultiplicity);
	hMa_PUNNNNLpt = new TH1D("hMa_PUNNNNLpt","Track-jet multiplicity in <#mu> 1000, max-pt ",nMultiplicityBins,0,maxMultiplicity);
	//! without binning
        hMb_PULpt = new TH1D("hMb_PULpt","Multiplicity of highest Pt track jet in <#mu> 1000 ",nMultiplicityBins,0,maxMultiplicity);
	hMb_PUNLpt = new TH1D("hMb_PUNLpt","Multiplicity of 2nd highest Pt track jet in <#mu> 1000 ",nMultiplicityBins,0,maxMultiplicity);
	hMb_PUNNLpt = new TH1D("hMb_PUNNLpt","Multiplicity of 3rd highest Pt track jet in <#mu> 1000 ",nMultiplicityBins,0,maxMultiplicity);
	hMb_PUNNNLpt = new TH1D("hMb_PUNNNLpt","Multiplicity of 4th highest Pt track jet in <#mu> 1000 ",nMultiplicityBins,0,maxMultiplicity);
	hMb_PUNNNNLpt = new TH1D("hMb_PUNNNNLpt","Track-jet multiplicity in <#mu> 1000 , w/o binning along z",nMultiplicityBins,0,maxMultiplicity);

}

void Rate_sumpt::init_EtaHist()
{

	//! eta distributions of jets matched to b quarks sorted in eta
        hbEta_CEta = new TH1D("hbEta_CEta","Eta of most central bjet", nEtaBins, etaMin, etaMax);
	hbEta_NCEta = new TH1D("hbEta_NCEta","Eta of 2nd most central bjet", nEtaBins, etaMin, etaMax);
	hbEta_NNCEta = new TH1D("hbEta_NNCEta","Eta of 3rd most central bjet", nEtaBins, etaMin, etaMax);
	hbEta_NNNCEta = new TH1D("hbEta_NNNCEta","Eta of 4th most central bjet", nEtaBins, etaMin, etaMax);
	//! eta distributions of 5 leading pt jets
        hbEta_PULpt = new TH1D("hbEta_PULpt","Eta of 1st highest Pt jet", nEtaBins, etaMin, etaMax);
	hbEta_PUNLpt = new TH1D("hbEta_PUNLpt","Eta of 2nd highest Pt jet", nEtaBins, etaMin, etaMax);
	hbEta_PUNNLpt = new TH1D("hbEta_PUNNLpt","Eta of 3rd highest Pt jet", nEtaBins, etaMin, etaMax);
	hbEta_PUNNNLpt = new TH1D("hbEta_PUNNNLpt","Eta of 4th highest Pt jet", nEtaBins, etaMin, etaMax);
	hbEta_PUNNNNLpt = new TH1D("hbEta_PUNNNNLpt","Eta of 5th highest Pt jet", nEtaBins, etaMin, etaMax);
}

void Rate_sumpt::SetEtaHist_props()
{
	
	hbEta_PUNNNNLpt->SetLineColor(kBlue);
	hbEta_PUNNNLpt->SetLineColor(kGreen);
	hbEta_PUNNLpt->SetLineColor(kRed);
	hbEta_PUNLpt->SetLineColor(kBlack);
	hbEta_PULpt->SetLineColor(kOrange);

	hbEta_PUNNNNLpt->SetLineWidth(2);
	hbEta_PUNNNLpt->SetLineWidth(2);
	hbEta_PUNNLpt->SetLineWidth(2);
	hbEta_PUNLpt->SetLineWidth(2);
	hbEta_PULpt->SetLineWidth(2);

        hbEta_PULpt->GetXaxis()->SetTitle("Track-jet #eta");
        hbEta_PUNLpt->GetXaxis()->SetTitle("Track-jet #eta");
        hbEta_PUNNLpt->GetXaxis()->SetTitle("Track-jet #eta");
        hbEta_PUNNNLpt->GetXaxis()->SetTitle("Track-jet #eta");
        hbEta_PUNNNNLpt->GetXaxis()->SetTitle("Track-jet #eta");

	hbEta_NNNCEta->SetLineColor(kGreen);
	hbEta_NNCEta->SetLineColor(kRed);
	hbEta_NCEta->SetLineColor(kBlack);
	hbEta_CEta->SetLineColor(kOrange);

	hbEta_NNNCEta->SetLineWidth(2);
	hbEta_NNCEta->SetLineWidth(2);
	hbEta_NCEta->SetLineWidth(2);
	hbEta_CEta->SetLineWidth(2);

        hbEta_CEta->GetXaxis()->SetTitle("Track-jet #eta");
        hbEta_NCEta->GetXaxis()->SetTitle("Track-jet #eta");
        hbEta_NNCEta->GetXaxis()->SetTitle("Track-jet #eta");
        hbEta_NNNCEta->GetXaxis()->SetTitle("Track-jet #eta");

}
void Rate_sumpt::SetMultiplicityHist_props()
{
	hM_PUNNNNLpt->SetLineColor(kBlue);
	hM_PUNNNLpt->SetLineColor(kGreen);
	hM_PUNNLpt->SetLineColor(kRed);
	hM_PUNLpt->SetLineColor(kBlack);
	hM_PULpt->SetLineColor(kOrange);

	hM_PUNNNNLpt->SetLineWidth(3);
	hM_PUNNNLpt->SetLineWidth(3);
	hM_PUNNLpt->SetLineWidth(3);
	hM_PUNLpt->SetLineWidth(3);
	hM_PULpt->SetLineWidth(3);

        hM_PULpt->GetXaxis()->SetTitle("Track-jet Multiplicity");
        hM_PUNLpt->GetXaxis()->SetTitle("Track-jet Multiplicity");
        hM_PUNNLpt->GetXaxis()->SetTitle("Track-jet Multiplicity");
        hM_PUNNNLpt->GetXaxis()->SetTitle("Track-jet Multiplicity");
        hM_PUNNNNLpt->GetXaxis()->SetTitle("Track-jet Multiplicity");
	
	hMa_PUNNNNLpt->SetLineColor(kBlue);
	hMa_PUNNNLpt->SetLineColor(kGreen);
	hMa_PUNNLpt->SetLineColor(kRed);
	hMa_PUNLpt->SetLineColor(kBlack);
	hMa_PULpt->SetLineColor(kOrange);

	hMa_PUNNNNLpt->SetLineWidth(3);
	hMa_PUNNNLpt->SetLineWidth(3);
	hMa_PUNNLpt->SetLineWidth(3);
	hMa_PUNLpt->SetLineWidth(3);
	hMa_PULpt->SetLineWidth(3);

        hMa_PULpt->GetXaxis()->SetTitle("Track-jet Multiplicity");
        hMa_PUNLpt->GetXaxis()->SetTitle("Track-jet Multiplicity");
        hMa_PUNNLpt->GetXaxis()->SetTitle("Track-jet Multiplicity");
        hMa_PUNNNLpt->GetXaxis()->SetTitle("Track-jet Multiplicity");
        hMa_PUNNNNLpt->GetXaxis()->SetTitle("Track-jet Multiplicity");
	
	hMb_PUNNNNLpt->SetLineColor(kBlue);
	hMb_PUNNNLpt->SetLineColor(kGreen);
	hMb_PUNNLpt->SetLineColor(kRed);
	hMb_PUNLpt->SetLineColor(kBlack);
	hMb_PULpt->SetLineColor(kOrange);

	hMb_PUNNNNLpt->SetLineWidth(3);
	hMb_PUNNNLpt->SetLineWidth(3);
	hMb_PUNNLpt->SetLineWidth(3);
	hMb_PUNLpt->SetLineWidth(3);
	hMb_PULpt->SetLineWidth(3);

        hMb_PULpt->GetXaxis()->SetTitle("Track-jet Multiplicity");
        hMb_PUNLpt->GetXaxis()->SetTitle("Track-jet Multiplicity");
        hMb_PUNNLpt->GetXaxis()->SetTitle("Track-jet Multiplicity");
        hMb_PUNNNLpt->GetXaxis()->SetTitle("Track-jet Multiplicity");
        hMb_PUNNNNLpt->GetXaxis()->SetTitle("Track-jet Multiplicity");

}
void Rate_sumpt::SetHist_props()
{
	h_PUNNNNLpt->GetYaxis()->SetRangeUser(5.0e-2, 50.0);
	h_PUNNNNLpt->SetLineColor(kBlue);
	h_PUNNNLpt->SetLineColor(kGreen);
	h_PUNNLpt->SetLineColor(kRed);
	h_PUNLpt->SetLineColor(kBlack);
	h_PULpt->SetLineColor(kOrange);

	h_PUNNNNLpt->SetLineWidth(3);
	h_PUNNNLpt->SetLineWidth(3);
	h_PUNNLpt->SetLineWidth(3);
	h_PUNLpt->SetLineWidth(3);
	h_PULpt->SetLineWidth(3);

        h_PULpt->Scale(1.0e3/(25*nevents));
        h_PUNLpt->Scale(1.0e3/(25*nevents));
        h_PUNNLpt->Scale(1.0e3/(25*nevents));
        h_PUNNNLpt->Scale(1.0e3/(25*nevents));
        h_PUNNNNLpt->Scale(1.0e3/(25*nevents));

        h_PULpt->GetYaxis()->SetTitle("rate [MHz]");
        h_PUNLpt->GetYaxis()->SetTitle("rate [MHz]");
        h_PUNNLpt->GetYaxis()->SetTitle("rate [MHz]");
        h_PUNNNLpt->GetYaxis()->SetTitle("rate [MHz]");
        h_PUNNNNLpt->GetYaxis()->SetTitle("rate [MHz]");

        h_PULpt->GetXaxis()->SetTitle("P_{t} [GeV/c]");
        h_PUNLpt->GetXaxis()->SetTitle("P_{t} [GeV/c]");
        h_PUNNLpt->GetXaxis()->SetTitle("P_{t} [GeV/c]");
        h_PUNNNLpt->GetXaxis()->SetTitle("P_{t} [GeV/c]");
        h_PUNNNNLpt->GetXaxis()->SetTitle("P_{t} [GeV/c]");
	
	ha_PUNNNNLpt->GetYaxis()->SetRangeUser(5.0e-2, 50.0);
	ha_PUNNNNLpt->SetLineColor(kBlue);
	ha_PUNNNLpt->SetLineColor(kGreen);
	ha_PUNNLpt->SetLineColor(kRed);
	ha_PUNLpt->SetLineColor(kBlack);
	ha_PULpt->SetLineColor(kOrange);

	ha_PUNNNNLpt->SetLineWidth(3);
	ha_PUNNNLpt->SetLineWidth(3);
	ha_PUNNLpt->SetLineWidth(3);
	ha_PUNLpt->SetLineWidth(3);
	ha_PULpt->SetLineWidth(3);

        ha_PULpt->Scale(1.0e3/(25*nevents));
        ha_PUNLpt->Scale(1.0e3/(25*nevents));
        ha_PUNNLpt->Scale(1.0e3/(25*nevents));
        ha_PUNNNLpt->Scale(1.0e3/(25*nevents));
        ha_PUNNNNLpt->Scale(1.0e3/(25*nevents));

        ha_PULpt->GetYaxis()->SetTitle("rate [MHz]");
        ha_PUNLpt->GetYaxis()->SetTitle("rate [MHz]");
        ha_PUNNLpt->GetYaxis()->SetTitle("rate [MHz]");
        ha_PUNNNLpt->GetYaxis()->SetTitle("rate [MHz]");
        ha_PUNNNNLpt->GetYaxis()->SetTitle("rate [MHz]");

        ha_PULpt->GetXaxis()->SetTitle("P_{t} [GeV/c]");
        ha_PUNLpt->GetXaxis()->SetTitle("P_{t} [GeV/c]");
        ha_PUNNLpt->GetXaxis()->SetTitle("P_{t} [GeV/c]");
        ha_PUNNNLpt->GetXaxis()->SetTitle("P_{t} [GeV/c]");
        ha_PUNNNNLpt->GetXaxis()->SetTitle("P_{t} [GeV/c]");
	
	hb_PUNNNNLpt->GetYaxis()->SetRangeUser(5.0e-2, 50.0);
	hb_PUNNNNLpt->SetLineColor(kBlue);
	hb_PUNNNLpt->SetLineColor(kGreen);
	hb_PUNNLpt->SetLineColor(kRed);
	hb_PUNLpt->SetLineColor(kBlack);
	hb_PULpt->SetLineColor(kOrange);

	hb_PUNNNNLpt->SetLineWidth(3);
	hb_PUNNNLpt->SetLineWidth(3);
	hb_PUNNLpt->SetLineWidth(3);
	hb_PUNLpt->SetLineWidth(3);
	hb_PULpt->SetLineWidth(3);

        hb_PULpt->Scale(1.0e3/(25*nevents));
        hb_PUNLpt->Scale(1.0e3/(25*nevents));
        hb_PUNNLpt->Scale(1.0e3/(25*nevents));
        hb_PUNNNLpt->Scale(1.0e3/(25*nevents));
        hb_PUNNNNLpt->Scale(1.0e3/(25*nevents));

        hb_PULpt->GetYaxis()->SetTitle("rate [MHz]");
        hb_PUNLpt->GetYaxis()->SetTitle("rate [MHz]");
        hb_PUNNLpt->GetYaxis()->SetTitle("rate [MHz]");
        hb_PUNNNLpt->GetYaxis()->SetTitle("rate [MHz]");
        hb_PUNNNNLpt->GetYaxis()->SetTitle("rate [MHz]");

        hb_PULpt->GetXaxis()->SetTitle("P_{t} [GeV/c]");
        hb_PUNLpt->GetXaxis()->SetTitle("P_{t} [GeV/c]");
        hb_PUNNLpt->GetXaxis()->SetTitle("P_{t} [GeV/c]");
        hb_PUNNNLpt->GetXaxis()->SetTitle("P_{t} [GeV/c]");
        hb_PUNNNNLpt->GetXaxis()->SetTitle("P_{t} [GeV/c]");

}
void Rate_sumpt::Fill_TrigRate_EMU(std::vector<int*> vec_ntots)
{
	//! Fill the jth bin of the respective histograms with the corresponding weight 
        for(int j = 0; j < nbins; ++j)
        {
        	std::cout<<"n2tot[" <<j <<"] = " << vec_ntots[0][j] <<std::endl;
          	
          
          	hb_PUNLpt->Fill(xbins[j], (1.0 * vec_ntots[8][j]));
          	hb_PUNNLpt->Fill(xbins[j], (1.0 * vec_ntots[9][j]));
          	hb_PUNNNLpt->Fill(xbins[j], (1.0 * vec_ntots[10][j]));
          	hb_PUNNNNLpt->Fill(xbins[j], (1.0 * vec_ntots[11][j]));
         
	}

}
void Rate_sumpt::Fill_TrigRate(std::vector<int*> vec_ntots)
{
	//! Fill the jth bin of the respective histograms with the corresponding weight 
        for(int j = 0; j < nbins; ++j)
        {
        	//std::cout<<"n2tot[" <<j <<"] = " << vec_ntots[0][j] <<std::endl;
          	
          
          	h_PUNLpt->Fill(xbins[j], (1.0 * vec_ntots[0][j]));
          	h_PUNNLpt->Fill(xbins[j], (1.0 * vec_ntots[1][j]));
          	h_PUNNNLpt->Fill(xbins[j], (1.0 * vec_ntots[2][j]));
          	h_PUNNNNLpt->Fill(xbins[j], (1.0 * vec_ntots[3][j]));
         
	 	ha_PUNLpt->Fill(xbins[j], (1.0 * vec_ntots[4][j]));
          	ha_PUNNLpt->Fill(xbins[j], (1.0 * vec_ntots[5][j]));
          	ha_PUNNNLpt->Fill(xbins[j], (1.0 * vec_ntots[6][j]));
          	ha_PUNNNNLpt->Fill(xbins[j], (1.0 * vec_ntots[7][j]));

          	hb_PUNLpt->Fill(xbins[j], (1.0 * vec_ntots[8][j]));
          	hb_PUNNLpt->Fill(xbins[j], (1.0 * vec_ntots[9][j]));
          	hb_PUNNNLpt->Fill(xbins[j], (1.0 * vec_ntots[10][j]));
          	hb_PUNNNNLpt->Fill(xbins[j], (1.0 * vec_ntots[11][j]));
          	
          
          	/*h_tJeff5->Fill(xbins[j], (1.0*n5_tot[j])/n_entries);
          	h_tJeff4->Fill(xbins[j], (1.0*n4_tot[j])/n_entries);
          	h_tJeff3->Fill(xbins[j], (1.0*n3_tot[j])/n_entries);
          	h_tJeff2->Fill(xbins[j], (1.0*n2_tot[j])/n_entries);*/
        }

}
void Rate_sumpt::DrawMultiplicitySumpt()
{
        hM_PUNNNNLpt->Draw("hist");
        hM_PUNNNLpt->Draw("hist same");
        hM_PUNNLpt->Draw("hist same");
        hM_PUNLpt->Draw("hist same");
	//hM_PULpt->Draw("hist");
}
void Rate_sumpt::DrawMultiplicityMaxpt()
{
        hMa_PUNNNNLpt->Draw("hist");
        hMa_PUNNNLpt->Draw("hist same");
        hMa_PUNNLpt->Draw("hist same");
        hMa_PUNLpt->Draw("hist same");
	//hMa_PULpt->Draw("hist");
}
void Rate_sumpt::DrawMultiplicity()
{
        hMb_PUNNNNLpt->Draw("hist ");
        hMb_PUNNNLpt->Draw("hist same");
        hMb_PUNNLpt->Draw("hist same");
        hMb_PUNLpt->Draw("hist same");
	//hMb_PULpt->Draw("hist");
}
void Rate_sumpt::WriteMultiplicity()
{
	hMb_PULpt->Write();
        hMb_PUNLpt->Write();
        hMb_PUNNLpt->Write();
        hMb_PUNNNLpt->Write();
        hMb_PUNNNNLpt->Write();
	hMa_PULpt->Write();
        hMa_PUNLpt->Write();
        hMa_PUNNLpt->Write();
        hMa_PUNNNLpt->Write();
        hMa_PUNNNNLpt->Write();
	hM_PULpt->Write();
        hM_PUNLpt->Write();
        hM_PUNNLpt->Write();
        hM_PUNNNLpt->Write();
        hM_PUNNNNLpt->Write();
}
void Rate_sumpt::DrawNoBin()
{
	hb_PUNNNNLpt->Draw("hist");
	hb_PUNNNLpt->Draw("hist same");
	hb_PUNNLpt->Draw("hist same");
	hb_PUNLpt->Draw("hist same");
	//hb_PULpt->Draw("hist same");
}
void Rate_sumpt::DrawRate()
{
	ha_PUNNNNLpt->Draw("hist");
	ha_PUNNNLpt->Draw("hist same");
	ha_PUNNLpt->Draw("hist same");
	ha_PUNLpt->Draw("hist same");
	//ha_PULpt->Draw("hist same");
}
void Rate_sumpt::DrawSumpt()
{
	h_PUNNNNLpt->Draw("hist");
	h_PUNNNLpt->Draw("hist same");
	h_PUNNLpt->Draw("hist same");
	h_PUNLpt->Draw("hist same");
	//h_PULpt->Draw("hist same");
}

void Rate_sumpt::WriteAll()
{
	//hb_PULpt->Write();
        hb_PUNLpt->Write();
        hb_PUNNLpt->Write();
        hb_PUNNNLpt->Write();
        hb_PUNNNNLpt->Write();
	//ha_PULpt->Write();
        ha_PUNLpt->Write();
        ha_PUNNLpt->Write();
        ha_PUNNNLpt->Write();
        ha_PUNNNNLpt->Write();
	//h_PULpt->Write();
        h_PUNLpt->Write();
        h_PUNNLpt->Write();
        h_PUNNNLpt->Write();
        h_PUNNNNLpt->Write();
}
void Rate_sumpt::WriteNoBin()
{
	//hb_PULpt->Write();
        hb_PUNLpt->Write();
        hb_PUNNLpt->Write();
        hb_PUNNNLpt->Write();
        hb_PUNNNNLpt->Write();
	//ha_PULpt->Write();
        ha_PUNLpt->Write();
        ha_PUNNLpt->Write();
        ha_PUNNNLpt->Write();
        ha_PUNNNNLpt->Write();
	//h_PULpt->Write();
        h_PUNLpt->Write();
        h_PUNNLpt->Write();
        h_PUNNNLpt->Write();
        h_PUNNNNLpt->Write();
}
void Rate_sumpt::WriteEta()
{
	hbEta_PULpt->Write();
        hbEta_PUNLpt->Write();
        hbEta_PUNNLpt->Write();
        hbEta_PUNNNLpt->Write();
        hbEta_PUNNNNLpt->Write();
}
void Rate_sumpt::WriteEta1()
{
	hbEta_CEta->Write();
        hbEta_NCEta->Write();
        hbEta_NNCEta->Write();
        hbEta_NNNCEta->Write();
}
