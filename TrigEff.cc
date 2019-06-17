#include "TrigEff.h"

void TrigEff::init(float xbins[], int nbins)
{

	h_tJeff2 = new TH1F("h_tJeff2"," Track Jet efficiency, prim_bin = Lsumpt", nbins, xbins);
	h_tJeff3 = new TH1F("h_tJeff3"," Track Jet efficiency, prim_bin = Lsumpt", nbins, xbins);
	h_tJeff4 = new TH1F("h_tJeff4"," Track Jet efficiency, prim_bin = Lsumpt", nbins, xbins);
	h_tJeff5 = new TH1F("h_tJeff5"," Track Jet efficiency, prim_bin = Lsumpt", nbins, xbins);
	
	ha_tJeff2 = new TH1F("ha_tJeff2"," Track Jet efficiency, prim_bins = Lpt", nbins, xbins);
	ha_tJeff3 = new TH1F("ha_tJeff3"," Track Jet efficiency, prim_bins = Lpt", nbins, xbins);
	ha_tJeff4 = new TH1F("ha_tJeff4"," Track Jet efficiency, prim_bins = Lpt", nbins, xbins);
	ha_tJeff5 = new TH1F("ha_tJeff5"," Track Jet efficiency, prim_bins = Lpt", nbins, xbins);
	
	hb_tJeff2 = new TH1F("hb_tJeff2"," Track Jet efficiency, No vertex bin", nbins, xbins);
	hb_tJeff3 = new TH1F("hb_tJeff3"," Track Jet efficiency, No vertex bin", nbins, xbins);
	hb_tJeff4 = new TH1F("hb_tJeff4"," Track Jet efficiency, No vertex bin", nbins, xbins);
	hb_tJeff5 = new TH1F("hb_tJeff5"," Track Jet efficiency, No vertex bin", nbins, xbins);
}
void TrigEff::SetHist_props()
{
	h_tJeff5->Sumw2(1);
	h_tJeff4->Sumw2(1);
	h_tJeff3->Sumw2(1);
	h_tJeff2->Sumw2(1);

	h_tJeff5->SetLineColor(kBlue);
	h_tJeff4->SetLineColor(kGreen);
	h_tJeff3->SetLineColor(kRed);
	h_tJeff2->SetLineColor(kBlack);

	h_tJeff5->SetLineWidth(3);
	h_tJeff4->SetLineWidth(3);
	h_tJeff3->SetLineWidth(3);
	h_tJeff2->SetLineWidth(3);

	h_tJeff5->GetYaxis()->SetTitle("#epsilon_{Njets}");
	h_tJeff4->GetYaxis()->SetTitle("#epsilon_{Njets}");
	h_tJeff3->GetYaxis()->SetTitle("#epsilon_{Njets}");
	h_tJeff2->GetYaxis()->SetTitle("#epsilon_{Njets}");

	h_tJeff5->GetXaxis()->SetTitle("P_{t} [GeV/c]");
	h_tJeff4->GetXaxis()->SetTitle("P_{t} [GeV/c]");
	h_tJeff3->GetXaxis()->SetTitle("P_{t} [GeV/c]");
	h_tJeff2->GetXaxis()->SetTitle("P_{t} [GeV/c]");
	
	ha_tJeff5->Sumw2(1);
	ha_tJeff4->Sumw2(1);
	ha_tJeff3->Sumw2(1);
	ha_tJeff2->Sumw2(1);

	ha_tJeff5->SetLineColor(kBlue);
	ha_tJeff4->SetLineColor(kGreen);
	ha_tJeff3->SetLineColor(kRed);
	ha_tJeff2->SetLineColor(kBlack);

	ha_tJeff5->SetLineWidth(3);
	ha_tJeff4->SetLineWidth(3);
	ha_tJeff3->SetLineWidth(3);
	ha_tJeff2->SetLineWidth(3);

	ha_tJeff5->GetYaxis()->SetTitle("#epsilon_{Njets}");
	ha_tJeff4->GetYaxis()->SetTitle("#epsilon_{Njets}");
	ha_tJeff3->GetYaxis()->SetTitle("#epsilon_{Njets}");
	ha_tJeff2->GetYaxis()->SetTitle("#epsilon_{Njets}");

	ha_tJeff5->GetXaxis()->SetTitle("P_{t} [GeV/c]");
	ha_tJeff4->GetXaxis()->SetTitle("P_{t} [GeV/c]");
	ha_tJeff3->GetXaxis()->SetTitle("P_{t} [GeV/c]");
	ha_tJeff2->GetXaxis()->SetTitle("P_{t} [GeV/c]");
	
	hb_tJeff5->Sumw2(1);
	hb_tJeff4->Sumw2(1);
	hb_tJeff3->Sumw2(1);
	hb_tJeff2->Sumw2(1);

	hb_tJeff5->SetLineColor(kBlue);
	hb_tJeff4->SetLineColor(kGreen);
	hb_tJeff3->SetLineColor(kRed);
	hb_tJeff2->SetLineColor(kBlack);

	hb_tJeff5->SetLineWidth(3);
	hb_tJeff4->SetLineWidth(3);
	hb_tJeff3->SetLineWidth(3);
	hb_tJeff2->SetLineWidth(3);

	hb_tJeff5->GetYaxis()->SetTitle("#epsilon_{Njets}");
	hb_tJeff4->GetYaxis()->SetTitle("#epsilon_{Njets}");
	hb_tJeff3->GetYaxis()->SetTitle("#epsilon_{Njets}");
	hb_tJeff2->GetYaxis()->SetTitle("#epsilon_{Njets}");

	hb_tJeff5->GetXaxis()->SetTitle("P_{t} [GeV/c]");
	hb_tJeff4->GetXaxis()->SetTitle("P_{t} [GeV/c]");
	hb_tJeff3->GetXaxis()->SetTitle("P_{t} [GeV/c]");
	hb_tJeff2->GetXaxis()->SetTitle("P_{t} [GeV/c]");

	//h_tJeff5->Scale(1e3/25);
	//h_tJeff4->Scale(1e3/25);
	//h_tJeff3->Scale(1e3/25);
	//h_tJeff2->Scale(1e3/25);
	//ha_tJeff5->Scale(1e3/25);
	//ha_tJeff4->Scale(1e3/25);
	//ha_tJeff3->Scale(1e3/25);
	//ha_tJeff2->Scale(1e3/25);
	//hb_tJeff5->Scale(1e3/25);
	//hb_tJeff4->Scale(1e3/25);
	//hb_tJeff3->Scale(1e3/25);
	//hb_tJeff2->Scale(1e3/25);
}
void TrigEff::Fill_TrigEff()
{
	//! Fill the jth bin of the respective histograms with the corresponding weight 
	for(int j = 0; j < nbins; ++j)
	{
		if(debug)
		{
			std::cout<< "n5_tot[ " << j << "] : " <<n5_tot[j] << ",   " <<  "n4_tot[ " << j << "] : " <<n4_tot[j] << ",   " << "n3_tot[ " << j << "] : " <<n3_tot[j] << ",   " << "n2_tot[ " << j << "] : " <<n2_tot[j] <<std::endl;
		}
	
		h_tJeff5->Fill(xbins[j], (1.0*n5_tot[j])/n5_tot[0]);
		h_tJeff4->Fill(xbins[j], (1.0*n4_tot[j])/n4_tot[0]);
		h_tJeff3->Fill(xbins[j], (1.0*n3_tot[j])/n3_tot[0]);
		h_tJeff2->Fill(xbins[j], (1.0*n2_tot[j])/n2_tot[0]);
		
		ha_tJeff5->Fill(xbins[j], (1.0*n5a_tot[j])/n5a_tot[0]);
		ha_tJeff4->Fill(xbins[j], (1.0*n4a_tot[j])/n4a_tot[0]);
		ha_tJeff3->Fill(xbins[j], (1.0*n3a_tot[j])/n3a_tot[0]);
		ha_tJeff2->Fill(xbins[j], (1.0*n2a_tot[j])/n2a_tot[0]);

		hb_tJeff5->Fill(xbins[j], (1.0*n5b_tot[j])/n5b_tot[0]);
		hb_tJeff4->Fill(xbins[j], (1.0*n4b_tot[j])/n4b_tot[0]);
		hb_tJeff3->Fill(xbins[j], (1.0*n3b_tot[j])/n3b_tot[0]);
		hb_tJeff2->Fill(xbins[j], (1.0*n2b_tot[j])/n2b_tot[0]);
	
		/*h_tJeff5->Fill(xbins[j], (1.0*n5_tot[j])/n_entries);
		h_tJeff4->Fill(xbins[j], (1.0*n4_tot[j])/n_entries);
		h_tJeff3->Fill(xbins[j], (1.0*n3_tot[j])/n_entries);
		h_tJeff2->Fill(xbins[j], (1.0*n2_tot[j])/n_entries);*/
	}
}
void TrigEff::DrawSumpt()
{

	h_tJeff5->Draw("HIST same");
	h_tJeff4->Draw("HIST same");
	h_tJeff3->Draw("HIST same");
	h_tJeff2->Draw("HIST same");
}
void TrigEff::DrawOvpbin()
{

	ha_tJeff5->Draw("HIST same");
	ha_tJeff4->Draw("HIST same");
	ha_tJeff3->Draw("HIST same");
	ha_tJeff2->Draw("HIST same");
}
void TrigEff::DrawNoBin()
{

	hb_tJeff5->Draw("HIST same");
	hb_tJeff4->Draw("HIST same");
	hb_tJeff3->Draw("HIST same");
	hb_tJeff2->Draw("HIST same");
}
void TrigEff::WriteAll()
{

	h_tJeff5->Write();
	h_tJeff4->Write();
	h_tJeff3->Write();
	h_tJeff2->Write();
	ha_tJeff5->Write();
	ha_tJeff4->Write();
	ha_tJeff3->Write();
	ha_tJeff2->Write();
	hb_tJeff5->Write();
	hb_tJeff4->Write();
	hb_tJeff3->Write();
	hb_tJeff2->Write();
}
