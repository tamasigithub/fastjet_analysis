
//! sumpt approach
TH1D *M_SG1 = nullptr;
TH1D *M_SG2 = nullptr;
TH1D *M_SG3 = nullptr;
TH1D *M_SG4 = nullptr;
TH1D *M_SG5 = nullptr;
//! Lpt bins approach
TH1D *M_SGa1 = nullptr;
TH1D *M_SGa2 = nullptr;
TH1D *M_SGa3 = nullptr;
TH1D *M_SGa4 = nullptr;
TH1D *M_SGa5 = nullptr;
//! no z-vertex bin 
TH1D *M_SGb1 = nullptr;
TH1D *M_SGb2 = nullptr;
TH1D *M_SGb3 = nullptr;
TH1D *M_SGb4 = nullptr;
TH1D *M_SGb5 = nullptr;
//! sumpt approach
TH1D *M_BG1 = nullptr; 
TH1D *M_BG2 = nullptr; 
TH1D *M_BG3 = nullptr; 
TH1D *M_BG4 = nullptr; 
TH1D *M_BG5 = nullptr; 
//! Lpt bins
TH1D *M_BGa1 = nullptr; 
TH1D *M_BGa2 = nullptr;
TH1D *M_BGa3 = nullptr;
TH1D *M_BGa4 = nullptr;
TH1D *M_BGa5 = nullptr;
//! no z-ver
TH1D *M_BGb1 = nullptr; 
TH1D *M_BGb2 = nullptr;
TH1D *M_BGb3 = nullptr;
TH1D *M_BGb4 = nullptr;
TH1D *M_BGb5 = nullptr;

void INIT_MULT()
{
	M_SG1 = new TH1D("M_SG1","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	M_SG2 = new TH1D("M_SG2","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	M_SG3 = new TH1D("M_SG3","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	M_SG4 = new TH1D("M_SG4","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	M_SG5 = new TH1D("M_SG5","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	
	M_BG1 = new TH1D("M_BG1","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	M_BG2 = new TH1D("M_BG2","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	M_BG3 = new TH1D("M_BG3","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	M_BG4 = new TH1D("M_BG4","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	M_BG5 = new TH1D("M_BG5","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	
	M_SGa1 = new TH1D("M_SGa1","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	M_SGa2 = new TH1D("M_SGa2","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	M_SGa3 = new TH1D("M_SGa3","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	M_SGa4 = new TH1D("M_SGa4","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	M_SGa5 = new TH1D("M_SGa5","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	
	M_BGa1 = new TH1D("M_BGa1","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	M_BGa2 = new TH1D("M_BGa2","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	M_BGa3 = new TH1D("M_BGa3","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	M_BGa4 = new TH1D("M_BGa4","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	M_BGa5 = new TH1D("M_BGa5","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);

	//M_SGb1 = new TH1D("M_SGb1","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	//M_SGb2 = new TH1D("M_SGb2","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	//M_SGb3 = new TH1D("M_SGb3","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	//M_SGb4 = new TH1D("M_SGb4","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	//M_SGb5 = new TH1D("M_SGb5","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	//
	//M_BGb1 = new TH1D("M_BGb1","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	//M_BGb2 = new TH1D("M_BGb2","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	//M_BGb3 = new TH1D("M_BGb3","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	//M_BGb4 = new TH1D("M_BGb4","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);
	//M_BGb5 = new TH1D("M_BGb5","constituent multiplicity/track-jet;constituent multiplicity",multBIN, MINmult, MAXmult);

	return;
}

void MULT_LINEprops()
{
	M_SG1->SetLineWidth(LINE_WIDTH);
	M_SG2->SetLineWidth(LINE_WIDTH);
	M_SG3->SetLineWidth(LINE_WIDTH);
	M_SG4->SetLineWidth(LINE_WIDTH);
	M_SG5->SetLineWidth(LINE_WIDTH);
	
	M_SGa1->SetLineWidth(LINE_WIDTH);
	M_SGa2->SetLineWidth(LINE_WIDTH);
	M_SGa3->SetLineWidth(LINE_WIDTH);
	M_SGa4->SetLineWidth(LINE_WIDTH);
	M_SGa5->SetLineWidth(LINE_WIDTH);
	
	//M_SGb1->SetLineWidth(LINE_WIDTH);
	//M_SGb2->SetLineWidth(LINE_WIDTH);
	//M_SGb3->SetLineWidth(LINE_WIDTH);
	//M_SGb4->SetLineWidth(LINE_WIDTH);
	//M_SGb5->SetLineWidth(LINE_WIDTH);
	
	
	M_BG1->SetLineWidth(LINE_WIDTH); 
	M_BG2->SetLineWidth(LINE_WIDTH); 
	M_BG3->SetLineWidth(LINE_WIDTH); 
	M_BG4->SetLineWidth(LINE_WIDTH); 
	M_BG5->SetLineWidth(LINE_WIDTH); 
	
	M_BGa1->SetLineWidth(LINE_WIDTH); 
	M_BGa2->SetLineWidth(LINE_WIDTH);
	M_BGa3->SetLineWidth(LINE_WIDTH);
	M_BGa4->SetLineWidth(LINE_WIDTH);
	M_BGa5->SetLineWidth(LINE_WIDTH);
	
	//M_BGb1->SetLineWidth(LINE_WIDTH); 
	//M_BGb2->SetLineWidth(LINE_WIDTH);
	//M_BGb3->SetLineWidth(LINE_WIDTH);
	//M_BGb4->SetLineWidth(LINE_WIDTH);
	//M_BGb5->SetLineWidth(LINE_WIDTH);
	
	M_BG1->SetLineStyle(LINE_STYLE); 
	M_BG2->SetLineStyle(LINE_STYLE); 
	M_BG3->SetLineStyle(LINE_STYLE); 
	M_BG4->SetLineStyle(LINE_STYLE); 
	M_BG5->SetLineStyle(LINE_STYLE); 
	
	M_BGa1->SetLineStyle(LINE_STYLE); 
	M_BGa2->SetLineStyle(LINE_STYLE);
	M_BGa3->SetLineStyle(LINE_STYLE);
	M_BGa4->SetLineStyle(LINE_STYLE);
	M_BGa5->SetLineStyle(LINE_STYLE);
	
	//M_BGb1->SetLineStyle(LINE_STYLE); 
	//M_BGb2->SetLineStyle(LINE_STYLE);
	//M_BGb3->SetLineStyle(LINE_STYLE);
	//M_BGb4->SetLineStyle(LINE_STYLE);
	//M_BGb5->SetLineStyle(LINE_STYLE);


	M_SG1->SetLineColor(kOrange);
	M_SG2->SetLineColor(kBlack);
	M_SG3->SetLineColor(kRed);
	M_SG4->SetLineColor(kGreen);
	M_SG5->SetLineColor(kBlue);
	
	M_SGa1->SetLineColor(kOrange);
	M_SGa2->SetLineColor(kBlack);
	M_SGa3->SetLineColor(kRed);
	M_SGa4->SetLineColor(kGreen);
	M_SGa5->SetLineColor(kBlue);
	
	//M_SGb1->SetLineColor(kOrange);
	//M_SGb2->SetLineColor(kBlack);
	//M_SGb3->SetLineColor(kRed);
	//M_SGb4->SetLineColor(kGreen);
	//M_SGb5->SetLineColor(kBlue);
	
	M_BG1->SetLineColor(kOrange);
	M_BG2->SetLineColor(kBlack);
	M_BG3->SetLineColor(kRed);
	M_BG4->SetLineColor(kGreen);
	M_BG5->SetLineColor(kBlue);
	
	M_BGa1->SetLineColor(kOrange);
	M_BGa2->SetLineColor(kBlack);
	M_BGa3->SetLineColor(kRed);
	M_BGa4->SetLineColor(kGreen);
	M_BGa5->SetLineColor(kBlue);
	
	//M_BGb1->SetLineColor(kOrange);
	//M_BGb2->SetLineColor(kBlack);
	//M_BGb3->SetLineColor(kRed);
	//M_BGb4->SetLineColor(kGreen);
	//M_BGb5->SetLineColor(kBlue);

	M_SG1->GetXaxis()->SetLabelSize(TEXT_SIZE);
	M_SG2->GetXaxis()->SetLabelSize(TEXT_SIZE);
	M_SG3->GetXaxis()->SetLabelSize(TEXT_SIZE);
	M_SG4->GetXaxis()->SetLabelSize(TEXT_SIZE);
	M_SG5->GetXaxis()->SetLabelSize(TEXT_SIZE);
	
	M_SGa1->GetXaxis()->SetLabelSize(TEXT_SIZE);
	M_SGa2->GetXaxis()->SetLabelSize(TEXT_SIZE);
	M_SGa3->GetXaxis()->SetLabelSize(TEXT_SIZE);
	M_SGa4->GetXaxis()->SetLabelSize(TEXT_SIZE);
	M_SGa5->GetXaxis()->SetLabelSize(TEXT_SIZE);
	
	//M_SGb1->GetXaxis()->SetLabelSize(TEXT_SIZE);
	//M_SGb2->GetXaxis()->SetLabelSize(TEXT_SIZE);
	//M_SGb3->GetXaxis()->SetLabelSize(TEXT_SIZE);
	//M_SGb4->GetXaxis()->SetLabelSize(TEXT_SIZE);
	//M_SGb5->GetXaxis()->SetLabelSize(TEXT_SIZE);
	
	
	M_BG1->GetXaxis()->SetLabelSize(TEXT_SIZE); 
	M_BG2->GetXaxis()->SetLabelSize(TEXT_SIZE); 
	M_BG3->GetXaxis()->SetLabelSize(TEXT_SIZE); 
	M_BG4->GetXaxis()->SetLabelSize(TEXT_SIZE); 
	M_BG5->GetXaxis()->SetLabelSize(TEXT_SIZE); 
	
	M_BGa1->GetXaxis()->SetLabelSize(TEXT_SIZE); 
	M_BGa2->GetXaxis()->SetLabelSize(TEXT_SIZE);
	M_BGa3->GetXaxis()->SetLabelSize(TEXT_SIZE);
	M_BGa4->GetXaxis()->SetLabelSize(TEXT_SIZE);
	M_BGa5->GetXaxis()->SetLabelSize(TEXT_SIZE);
	
	//M_BGb1->GetXaxis()->SetLabelSize(TEXT_SIZE); 
	//M_BGb2->GetXaxis()->SetLabelSize(TEXT_SIZE);
	//M_BGb3->GetXaxis()->SetLabelSize(TEXT_SIZE);
	//M_BGb4->GetXaxis()->SetLabelSize(TEXT_SIZE);
	//M_BGb5->GetXaxis()->SetLabelSize(TEXT_SIZE);
	
	M_SG1->GetYaxis()->SetLabelSize(TEXT_SIZE);
	M_SG2->GetYaxis()->SetLabelSize(TEXT_SIZE);
	M_SG3->GetYaxis()->SetLabelSize(TEXT_SIZE);
	M_SG4->GetYaxis()->SetLabelSize(TEXT_SIZE);
	M_SG5->GetYaxis()->SetLabelSize(TEXT_SIZE);
	
	M_SGa1->GetYaxis()->SetLabelSize(TEXT_SIZE);
	M_SGa2->GetYaxis()->SetLabelSize(TEXT_SIZE);
	M_SGa3->GetYaxis()->SetLabelSize(TEXT_SIZE);
	M_SGa4->GetYaxis()->SetLabelSize(TEXT_SIZE);
	M_SGa5->GetYaxis()->SetLabelSize(TEXT_SIZE);
	
	//M_SGb1->GetYaxis()->SetLabelSize(TEXT_SIZE);
	//M_SGb2->GetYaxis()->SetLabelSize(TEXT_SIZE);
	//M_SGb3->GetYaxis()->SetLabelSize(TEXT_SIZE);
	//M_SGb4->GetYaxis()->SetLabelSize(TEXT_SIZE);
	//M_SGb5->GetYaxis()->SetLabelSize(TEXT_SIZE);
	
	
	M_BG1->GetYaxis()->SetLabelSize(TEXT_SIZE); 
	M_BG2->GetYaxis()->SetLabelSize(TEXT_SIZE); 
	M_BG3->GetYaxis()->SetLabelSize(TEXT_SIZE); 
	M_BG4->GetYaxis()->SetLabelSize(TEXT_SIZE); 
	M_BG5->GetYaxis()->SetLabelSize(TEXT_SIZE); 
	
	M_BGa1->GetYaxis()->SetLabelSize(TEXT_SIZE); 
	M_BGa2->GetYaxis()->SetLabelSize(TEXT_SIZE);
	M_BGa3->GetYaxis()->SetLabelSize(TEXT_SIZE);
	M_BGa4->GetYaxis()->SetLabelSize(TEXT_SIZE);
	M_BGa5->GetYaxis()->SetLabelSize(TEXT_SIZE);
	
	//M_BGb1->GetYaxis()->SetLabelSize(TEXT_SIZE); 
	//M_BGb2->GetYaxis()->SetLabelSize(TEXT_SIZE);
	//M_BGb3->GetYaxis()->SetLabelSize(TEXT_SIZE);
	//M_BGb4->GetYaxis()->SetLabelSize(TEXT_SIZE);
	//M_BGb5->GetYaxis()->SetLabelSize(TEXT_SIZE);

	M_SG1->GetXaxis()->CenterTitle();
	M_SG2->GetXaxis()->CenterTitle();
	M_SG3->GetXaxis()->CenterTitle();
	M_SG4->GetXaxis()->CenterTitle();
	M_SG5->GetXaxis()->CenterTitle();
	
	M_SGa1->GetXaxis()->CenterTitle();
	M_SGa2->GetXaxis()->CenterTitle();
	M_SGa3->GetXaxis()->CenterTitle();
	M_SGa4->GetXaxis()->CenterTitle();
	M_SGa5->GetXaxis()->CenterTitle();
	
	//M_SGb1->GetXaxis()->CenterTitle();
	//M_SGb2->GetXaxis()->CenterTitle();
	//M_SGb3->GetXaxis()->CenterTitle();
	//M_SGb4->GetXaxis()->CenterTitle();
	//M_SGb5->GetXaxis()->CenterTitle();
	
	
	M_BG1->GetXaxis()->CenterTitle();
	M_BG2->GetXaxis()->CenterTitle();
	M_BG3->GetXaxis()->CenterTitle();
	M_BG4->GetXaxis()->CenterTitle();
	M_BG5->GetXaxis()->CenterTitle();
	
	M_BGa1->GetXaxis()->CenterTitle();
	M_BGa2->GetXaxis()->CenterTitle();
	M_BGa3->GetXaxis()->CenterTitle();
	M_BGa4->GetXaxis()->CenterTitle();
	M_BGa5->GetXaxis()->CenterTitle();
	
	//M_BGb1->GetXaxis()->CenterTitle();
	//M_BGb2->GetXaxis()->CenterTitle();
	//M_BGb3->GetXaxis()->CenterTitle();
	//M_BGb4->GetXaxis()->CenterTitle();
	//M_BGb5->GetXaxis()->CenterTitle();

	//TEXT_SIZE = 0.05;
	M_SG1->SetTitleSize(TEXT_SIZE);
	M_SG2->SetTitleSize(TEXT_SIZE);
	M_SG3->SetTitleSize(TEXT_SIZE);
	M_SG4->SetTitleSize(TEXT_SIZE);
	M_SG5->SetTitleSize(TEXT_SIZE);
	
	M_SGa1->SetTitleSize(TEXT_SIZE);
	M_SGa2->SetTitleSize(TEXT_SIZE);
	M_SGa3->SetTitleSize(TEXT_SIZE);
	M_SGa4->SetTitleSize(TEXT_SIZE);
	M_SGa5->SetTitleSize(TEXT_SIZE);
	
	//M_SGb1->SetTitleSize(TEXT_SIZE);
	//M_SGb2->SetTitleSize(TEXT_SIZE);
	//M_SGb3->SetTitleSize(TEXT_SIZE);
	//M_SGb4->SetTitleSize(TEXT_SIZE);
	//M_SGb5->SetTitleSize(TEXT_SIZE);
	
	
	M_BG1->SetTitleSize(TEXT_SIZE); 
	M_BG2->SetTitleSize(TEXT_SIZE); 
	M_BG3->SetTitleSize(TEXT_SIZE); 
	M_BG4->SetTitleSize(TEXT_SIZE); 
	M_BG5->SetTitleSize(TEXT_SIZE); 
	
	M_BGa1->SetTitleSize(TEXT_SIZE); 
	M_BGa2->SetTitleSize(TEXT_SIZE);
	M_BGa3->SetTitleSize(TEXT_SIZE);
	M_BGa4->SetTitleSize(TEXT_SIZE);
	M_BGa5->SetTitleSize(TEXT_SIZE);
	
	//M_BGb1->SetTitleSize(TEXT_SIZE); 
	//M_BGb2->SetTitleSize(TEXT_SIZE);
	//M_BGb3->SetTitleSize(TEXT_SIZE);
	//M_BGb4->SetTitleSize(TEXT_SIZE);
	//M_BGb5->SetTitleSize(TEXT_SIZE);
	return;
}

