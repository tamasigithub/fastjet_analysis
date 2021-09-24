
TLegend *ana_txt = nullptr;
TLegend *cms_E   = nullptr;
TLegend *signal_  = nullptr;

void Legends()
{
	ana_txt = new TLegend(0.5,0.77,0.94,0.79);
	ana_txt->SetFillStyle(0);
	ana_txt->SetBorderSize(0);
	ana_txt->AddEntry((TObject*)0, "after analysis cuts", "");
	ana_txt->SetTextSize(0.04);

	cms_E = new TLegend(0.4,0.79,0.9,0.92);
	cms_E->SetFillStyle(0);
	cms_E->SetBorderSize(0);
	cms_E->AddEntry((TObject*)0, "#sqrt{s} = 100 TeV, #mathcal{L} = 30 ab^{-1}", "");
	cms_E->SetTextSize(0.04);

	signal_ = new TLegend(0.58,0.72,0.9,0.92);
	signal_->SetFillStyle(0);
	signal_->SetBorderSize(0);
	signal_->AddEntry((TObject*)0, "HH #rightarrow b#bar{b}b#bar{b}", "");
	signal_->SetTextSize(0.04);
	return;
}
