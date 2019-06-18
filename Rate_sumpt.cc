#include "Rate_sumpt.h"

void Rate_sumpt::init_Histos(float xbins[], int nbins)
{

	//! Book Histogram        
	//! sumpt histos
	h_PULpt = new TH1D("h_PULpt","Rate of highest Pt track jet in <#mu> 960 ",nbins,xbins);
	h_PUNLpt = new TH1D("h_PUNLpt","Rate of 2nd highest Pt track jet in <#mu> 960 ",nbins,xbins);
	h_PUNNLpt = new TH1D("h_PUNNLpt","Rate of 3rd highest Pt track jet in <#mu> 960 ",nbins,xbins);
	h_PUNNNLpt = new TH1D("h_PUNNNLpt","Rate of 4th highest Pt track jet in <#mu> 960 ",nbins,xbins);
	h_PUNNNNLpt = new TH1D("h_PUNNNNLpt","Rate Vs track jet P_{t} in <#mu> 960 , PB finding using sum pt",nbins,xbins);
	//! overlapping bin approach
        ha_PULpt = new TH1D("ha_PULpt","Rate of highest Pt track jet in <#mu> 960 ",nbins,xbins);
	ha_PUNLpt = new TH1D("ha_PUNLpt","Rate of 2nd highest Pt track jet in <#mu> 960 ",nbins,xbins);
	ha_PUNNLpt = new TH1D("ha_PUNNLpt","Rate of 3rd highest Pt track jet in <#mu> 960 ",nbins,xbins);
	ha_PUNNNLpt = new TH1D("ha_PUNNNLpt","Rate of 4th highest Pt track jet in <#mu> 960 ",nbins,xbins);
	ha_PUNNNNLpt = new TH1D("ha_PUNNNNLpt","Rate Vs track jet P_{t} in <#mu> 960 ",nbins,xbins);
	//! without binning
        hb_PULpt = new TH1D("hb_PULpt","Rate of highest Pt track jet in <#mu> 960 ",nbins,xbins);
	hb_PUNLpt = new TH1D("hb_PUNLpt","Rate of 2nd highest Pt track jet in <#mu> 960 ",nbins,xbins);
	hb_PUNNLpt = new TH1D("hb_PUNNLpt","Rate of 3rd highest Pt track jet in <#mu> 960 ",nbins,xbins);
	hb_PUNNNLpt = new TH1D("hb_PUNNNLpt","Rate of 4th highest Pt track jet in <#mu> 960 ",nbins,xbins);
	hb_PUNNNNLpt = new TH1D("hb_PUNNNNLpt","Rate Vs track jet P_{t} in <#mu> 960 , without binning along beam axis",nbins,xbins);
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
