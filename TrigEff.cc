#include "TrigEff.h"

void TrigEff::init(float xbins[], int nbins)
{

	h_tJeff2 = new TH1F("h_tJeff2"," Track Jet efficiency", nbins, xbins);
	h_tJeff3 = new TH1F("h_tJeff3"," Track Jet efficiency", nbins, xbins);
	h_tJeff4 = new TH1F("h_tJeff4"," Track Jet efficiency", nbins, xbins);
	h_tJeff5 = new TH1F("h_tJeff5"," Track Jet efficiency", nbins, xbins);
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
	
		/*h_tJeff5->Fill(xbins[j], (1.0*n5_tot[j])/n_entries);
		h_tJeff4->Fill(xbins[j], (1.0*n4_tot[j])/n_entries);
		h_tJeff3->Fill(xbins[j], (1.0*n3_tot[j])/n_entries);
		h_tJeff2->Fill(xbins[j], (1.0*n2_tot[j])/n_entries);*/
	}
}
void TrigEff::DrawNoBin()
{

	h_tJeff5->Draw("HIST same");
	h_tJeff4->Draw("HIST same");
	h_tJeff3->Draw("HIST same");
	h_tJeff2->Draw("HIST same");
}
void TrigEff::WriteAll()
{

	h_tJeff5->Write();
	h_tJeff4->Write();
	h_tJeff3->Write();
	h_tJeff2->Write();
}

//void TrigEff::init(float xbins[], int nbins)
//{
//	//! initialise xbins which is of size nbins+1
//	for(int i = 0; i < nbins; ++i)
//	{
//	      xbins[i] = pt_min + i*ptcut_width;
//	      std::cout<< "pt_min: "<<pt_min << "ptcut_width: " << ptcut_width << ", xbins[" << i << "] : " <<xbins[i] <<std::endl; 
//	}
//}
