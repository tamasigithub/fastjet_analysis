#include "Rate_sumpt.h"

void Rate_sumpt::SetHist_props()
{
	h_PUNNNNLpt->GetYaxis()->SetRangeUser(5.0e-2, 1.0e2);
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
	
	ha_PUNNNNLpt->GetYaxis()->SetRangeUser(5.0e-2, 1.0e2);
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
	
	hb_PUNNNNLpt->GetYaxis()->SetRangeUser(5.0e-2, 1.0e2);
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
	hb_PULpt->Write();
        hb_PUNLpt->Write();
        hb_PUNNLpt->Write();
        hb_PUNNNLpt->Write();
        hb_PUNNNNLpt->Write();
	ha_PULpt->Write();
        ha_PUNLpt->Write();
        ha_PUNNLpt->Write();
        ha_PUNNNLpt->Write();
        ha_PUNNNNLpt->Write();
	h_PULpt->Write();
        h_PUNLpt->Write();
        h_PUNNLpt->Write();
        h_PUNNNLpt->Write();
        h_PUNNNNLpt->Write();
}
