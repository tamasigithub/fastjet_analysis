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

        h_PULpt->GetYaxis()->SetTitle("rate MHz");
        h_PUNLpt->GetYaxis()->SetTitle("rate MHz");
        h_PUNNLpt->GetYaxis()->SetTitle("rate MHz");
        h_PUNNNLpt->GetYaxis()->SetTitle("rate MHz");
        h_PUNNNNLpt->GetYaxis()->SetTitle("rate MHz");

        h_PULpt->GetXaxis()->SetTitle("P_{t} [MeV/c]");
        h_PUNLpt->GetXaxis()->SetTitle("P_{t} [MeV/c]");
        h_PUNNLpt->GetXaxis()->SetTitle("P_{t} [MeV/c]");
        h_PUNNNLpt->GetXaxis()->SetTitle("P_{t} [MeV/c]");
        h_PUNNNNLpt->GetXaxis()->SetTitle("P_{t} [MeV/c]");	
}

void Rate_sumpt::DrawAll()
{
	h_PUNNNNLpt->Draw();
	h_PUNNNLpt->Draw("same");
	h_PUNNLpt->Draw("same");
	h_PUNLpt->Draw("same");
	h_PULpt->Draw("same");
}

void Rate_sumpt::WriteAll()
{
	h_PULpt->Write();
        h_PUNLpt->Write();
        h_PUNNLpt->Write();
        h_PUNNNLpt->Write();
        h_PUNNNNLpt->Write();
}
