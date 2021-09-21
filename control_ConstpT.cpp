
TH1D *SG_1L1C = nullptr;
TH1D *SG_1L2C = nullptr;
TH1D *SG_1L3C = nullptr;
TH1D *SG_1L4C = nullptr;

TH1D *SG_2L1C = nullptr;
TH1D *SG_2L2C = nullptr;
TH1D *SG_2L3C = nullptr;
TH1D *SG_2L4C = nullptr;

TH1D *SG_3L1C = nullptr;
TH1D *SG_3L2C = nullptr;
TH1D *SG_3L3C = nullptr;
TH1D *SG_3L4C = nullptr;

TH1D *SG_4L1C = nullptr;
TH1D *SG_4L2C = nullptr;
TH1D *SG_4L3C = nullptr;
TH1D *SG_4L4C = nullptr;

TH1D *SG_5L1C = nullptr;
TH1D *SG_5L2C = nullptr;
TH1D *SG_5L3C = nullptr;
TH1D *SG_5L4C = nullptr;

TH1D *SGa_1L1C = nullptr;
TH1D *SGa_1L2C = nullptr;
TH1D *SGa_1L3C = nullptr;
TH1D *SGa_1L4C = nullptr;

TH1D *SGa_2L1C = nullptr;
TH1D *SGa_2L2C = nullptr;
TH1D *SGa_2L3C = nullptr;
TH1D *SGa_2L4C = nullptr;

TH1D *SGa_3L1C = nullptr;
TH1D *SGa_3L2C = nullptr;
TH1D *SGa_3L3C = nullptr;
TH1D *SGa_3L4C = nullptr;

TH1D *SGa_4L1C = nullptr;
TH1D *SGa_4L2C = nullptr;
TH1D *SGa_4L3C = nullptr;
TH1D *SGa_4L4C = nullptr;

TH1D *SGa_5L1C = nullptr;
TH1D *SGa_5L2C = nullptr;
TH1D *SGa_5L3C = nullptr;
TH1D *SGa_5L4C = nullptr;

TH1D *BG_1L1C = nullptr;
TH1D *BG_1L2C = nullptr;
TH1D *BG_1L3C = nullptr;
TH1D *BG_1L4C = nullptr;

TH1D *BG_2L1C = nullptr;
TH1D *BG_2L2C = nullptr;
TH1D *BG_2L3C = nullptr;
TH1D *BG_2L4C = nullptr;

TH1D *BG_3L1C = nullptr;
TH1D *BG_3L2C = nullptr;
TH1D *BG_3L3C = nullptr;
TH1D *BG_3L4C = nullptr;

TH1D *BG_4L1C = nullptr;
TH1D *BG_4L2C = nullptr;
TH1D *BG_4L3C = nullptr;
TH1D *BG_4L4C = nullptr;

TH1D *BG_5L1C = nullptr;
TH1D *BG_5L2C = nullptr;
TH1D *BG_5L3C = nullptr;
TH1D *BG_5L4C = nullptr;

TH1D *BGa_1L1C = nullptr;
TH1D *BGa_1L2C = nullptr;
TH1D *BGa_1L3C = nullptr;
TH1D *BGa_1L4C = nullptr;

TH1D *BGa_2L1C = nullptr;
TH1D *BGa_2L2C = nullptr;
TH1D *BGa_2L3C = nullptr;
TH1D *BGa_2L4C = nullptr;

TH1D *BGa_3L1C = nullptr;
TH1D *BGa_3L2C = nullptr;
TH1D *BGa_3L3C = nullptr;
TH1D *BGa_3L4C = nullptr;

TH1D *BGa_4L1C = nullptr;
TH1D *BGa_4L2C = nullptr;
TH1D *BGa_4L3C = nullptr;
TH1D *BGa_4L4C = nullptr;

TH1D *BGa_5L1C = nullptr;
TH1D *BGa_5L2C = nullptr;
TH1D *BGa_5L3C = nullptr;
TH1D *BGa_5L4C = nullptr;

void INIT_CONSTpT()
{

	SG_1L1C = new TH1D("SG_1L1C","leading 1^{st} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SG_1L2C = new TH1D("SG_1L2C","leading 2^{nd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SG_1L3C = new TH1D("SG_1L3C","leading 3^{rd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SG_1L4C = new TH1D("SG_1L4C","leading 4^{th} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
                                 
	SG_2L1C = new TH1D("SG_2L1C","2^{nd} leading 1^{st} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SG_2L2C = new TH1D("SG_2L2C","2^{nd} leading 2^{nd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SG_2L3C = new TH1D("SG_2L3C","2^{nd} leading 3^{rd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SG_2L4C = new TH1D("SG_2L4C","2^{nd} leading 4^{th} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
                                 
	SG_3L1C = new TH1D("SG_3L1C","3^{rd} leading 1^{st} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SG_3L2C = new TH1D("SG_3L2C","3^{rd} leading 2^{nd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SG_3L3C = new TH1D("SG_3L3C","3^{rd} leading 3^{rd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SG_3L4C = new TH1D("SG_3L4C","3^{rd} leading 4^{th} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
                                 
	SG_4L1C = new TH1D("SG_4L1C","4^{th} leading 1^{st} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SG_4L2C = new TH1D("SG_4L2C","4^{th} leading 2^{nd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SG_4L3C = new TH1D("SG_4L3C","4^{th} leading 3^{rd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SG_4L4C = new TH1D("SG_4L4C","4^{th} leading 4^{th} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
                                 
	SG_5L1C = new TH1D("SG_5L1C","5^{th} leading 1^{st} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SG_5L2C = new TH1D("SG_5L2C","5^{th} leading 2^{nd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SG_5L3C = new TH1D("SG_5L3C","5^{th} leading 3^{rd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SG_5L4C = new TH1D("SG_5L4C","5^{th} leading 4^{th} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	
	SGa_1L1C = new TH1D("SGa_1L1C","leading 1^{st} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SGa_1L2C = new TH1D("SGa_1L2C","leading 2^{nd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SGa_1L3C = new TH1D("SGa_1L3C","leading 3^{rd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SGa_1L4C = new TH1D("SGa_1L4C","leading 4^{th} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
                                 
	SGa_2L1C = new TH1D("SGa_2L1C","2^{nd} leading 1^{st} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SGa_2L2C = new TH1D("SGa_2L2C","2^{nd} leading 2^{nd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SGa_2L3C = new TH1D("SGa_2L3C","2^{nd} leading 3^{rd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SGa_2L4C = new TH1D("SGa_2L4C","2^{nd} leading 4^{th} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
                                 
	SGa_3L1C = new TH1D("SGa_3L1C","3^{rd} leading 1^{st} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SGa_3L2C = new TH1D("SGa_3L2C","3^{rd} leading 2^{nd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SGa_3L3C = new TH1D("SGa_3L3C","3^{rd} leading 3^{rd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SGa_3L4C = new TH1D("SGa_3L4C","3^{rd} leading 4^{th} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
                                 
	SGa_4L1C = new TH1D("SGa_4L1C","4^{th} leading 1^{st} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SGa_4L2C = new TH1D("SGa_4L2C","4^{th} leading 2^{nd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SGa_4L3C = new TH1D("SGa_4L3C","4^{th} leading 3^{rd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SGa_4L4C = new TH1D("SGa_4L4C","4^{th} leading 4^{th} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
                                 
	SGa_5L1C = new TH1D("SGa_5L1C","5^{th} leading 1^{st} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SGa_5L2C = new TH1D("SGa_5L2C","5^{th} leading 2^{nd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SGa_5L3C = new TH1D("SGa_5L3C","5^{th} leading 3^{rd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	SGa_5L4C = new TH1D("SGa_5L4C","5^{th} leading 4^{th} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	
	BG_1L1C = new TH1D("BG_1L1C","leading 1^{st} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BG_1L2C = new TH1D("BG_1L2C","leading 2^{nd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BG_1L3C = new TH1D("BG_1L3C","leading 3^{rd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BG_1L4C = new TH1D("BG_1L4C","leading 4^{th} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
                                 
	BG_2L1C = new TH1D("BG_2L1C","2^{nd} leading 1^{st} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BG_2L2C = new TH1D("BG_2L2C","2^{nd} leading 2^{nd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BG_2L3C = new TH1D("BG_2L3C","2^{nd} leading 3^{rd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BG_2L4C = new TH1D("BG_2L4C","2^{nd} leading 4^{th} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
                                 
	BG_3L1C = new TH1D("BG_3L1C","3^{rd} leading 1^{st} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BG_3L2C = new TH1D("BG_3L2C","3^{rd} leading 2^{nd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BG_3L3C = new TH1D("BG_3L3C","3^{rd} leading 3^{rd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BG_3L4C = new TH1D("BG_3L4C","3^{rd} leading 4^{th} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
                                 
	BG_4L1C = new TH1D("BG_4L1C","4^{th} leading 1^{st} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BG_4L2C = new TH1D("BG_4L2C","4^{th} leading 2^{nd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BG_4L3C = new TH1D("BG_4L3C","4^{th} leading 3^{rd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BG_4L4C = new TH1D("BG_4L4C","4^{th} leading 4^{th} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
                                 
	BG_5L1C = new TH1D("BG_5L1C","5^{th} leading 1^{st} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BG_5L2C = new TH1D("BG_5L2C","5^{th} leading 2^{nd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BG_5L3C = new TH1D("BG_5L3C","5^{th} leading 3^{rd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BG_5L4C = new TH1D("BG_5L4C","5^{th} leading 4^{th} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	
	BGa_1L1C = new TH1D("BGa_1L1C","leading 1^{st} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BGa_1L2C = new TH1D("BGa_1L2C","leading 2^{nd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BGa_1L3C = new TH1D("BGa_1L3C","leading 3^{rd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BGa_1L4C = new TH1D("BGa_1L4C","leading 4^{th} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
                                 
	BGa_2L1C = new TH1D("BGa_2L1C","2^{nd} leading 1^{st} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BGa_2L2C = new TH1D("BGa_2L2C","2^{nd} leading 2^{nd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BGa_2L3C = new TH1D("BGa_2L3C","2^{nd} leading 3^{rd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BGa_2L4C = new TH1D("BGa_2L4C","2^{nd} leading 4^{th} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
                                 
	BGa_3L1C = new TH1D("BGa_3L1C","3^{rd} leading 1^{st} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BGa_3L2C = new TH1D("BGa_3L2C","3^{rd} leading 2^{nd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BGa_3L3C = new TH1D("BGa_3L3C","3^{rd} leading 3^{rd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BGa_3L4C = new TH1D("BGa_3L4C","3^{rd} leading 4^{th} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
                                 
	BGa_4L1C = new TH1D("BGa_4L1C","4^{th} leading 1^{st} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BGa_4L2C = new TH1D("BGa_4L2C","4^{th} leading 2^{nd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BGa_4L3C = new TH1D("BGa_4L3C","4^{th} leading 3^{rd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BGa_4L4C = new TH1D("BGa_4L4C","4^{th} leading 4^{th} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
                                 
	BGa_5L1C = new TH1D("BGa_5L1C","5^{th} leading 1^{st} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BGa_5L2C = new TH1D("BGa_5L2C","5^{th} leading 2^{nd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BGa_5L3C = new TH1D("BGa_5L3C","5^{th} leading 3^{rd} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	BGa_5L4C = new TH1D("BGa_5L4C","5^{th} leading 4^{th} constituent p_{T} [GeV/c]", npTBIN, xpTBIN);
	return;
}

void CONSTpT_LINEprops()
{

	SG_1L1C->SetLineWidth(LINE_WIDTH);
	SG_1L2C->SetLineWidth(LINE_WIDTH);
	SG_1L3C->SetLineWidth(LINE_WIDTH);
	SG_1L4C->SetLineWidth(LINE_WIDTH);

	SG_2L1C->SetLineWidth(LINE_WIDTH);
	SG_2L2C->SetLineWidth(LINE_WIDTH);
	SG_2L3C->SetLineWidth(LINE_WIDTH);
	SG_2L4C->SetLineWidth(LINE_WIDTH);

	SG_3L1C->SetLineWidth(LINE_WIDTH);
	SG_3L2C->SetLineWidth(LINE_WIDTH);
	SG_3L3C->SetLineWidth(LINE_WIDTH);
	SG_3L4C->SetLineWidth(LINE_WIDTH);

	SG_4L1C->SetLineWidth(LINE_WIDTH);
	SG_4L2C->SetLineWidth(LINE_WIDTH);
	SG_4L3C->SetLineWidth(LINE_WIDTH);
	SG_4L4C->SetLineWidth(LINE_WIDTH);

	SG_5L1C->SetLineWidth(LINE_WIDTH);
	SG_5L2C->SetLineWidth(LINE_WIDTH);
	SG_5L3C->SetLineWidth(LINE_WIDTH);
	SG_5L4C->SetLineWidth(LINE_WIDTH);

	SGa_1L1C->SetLineWidth(LINE_WIDTH);
	SGa_1L2C->SetLineWidth(LINE_WIDTH);
	SGa_1L3C->SetLineWidth(LINE_WIDTH);
	SGa_1L4C->SetLineWidth(LINE_WIDTH);

	SGa_2L1C->SetLineWidth(LINE_WIDTH);
	SGa_2L2C->SetLineWidth(LINE_WIDTH);
	SGa_2L3C->SetLineWidth(LINE_WIDTH);
	SGa_2L4C->SetLineWidth(LINE_WIDTH);

	SGa_3L1C->SetLineWidth(LINE_WIDTH);
	SGa_3L2C->SetLineWidth(LINE_WIDTH);
	SGa_3L3C->SetLineWidth(LINE_WIDTH);
	SGa_3L4C->SetLineWidth(LINE_WIDTH);

	SGa_4L1C->SetLineWidth(LINE_WIDTH);
	SGa_4L2C->SetLineWidth(LINE_WIDTH);
	SGa_4L3C->SetLineWidth(LINE_WIDTH);
	SGa_4L4C->SetLineWidth(LINE_WIDTH);

	SGa_5L1C->SetLineWidth(LINE_WIDTH);
	SGa_5L2C->SetLineWidth(LINE_WIDTH);
	SGa_5L3C->SetLineWidth(LINE_WIDTH);
	SGa_5L4C->SetLineWidth(LINE_WIDTH);

	BG_1L1C->SetLineWidth(LINE_WIDTH);
	BG_1L2C->SetLineWidth(LINE_WIDTH);
	BG_1L3C->SetLineWidth(LINE_WIDTH);
	BG_1L4C->SetLineWidth(LINE_WIDTH);

	BG_2L1C->SetLineWidth(LINE_WIDTH);
	BG_2L2C->SetLineWidth(LINE_WIDTH);
	BG_2L3C->SetLineWidth(LINE_WIDTH);
	BG_2L4C->SetLineWidth(LINE_WIDTH);

	BG_3L1C->SetLineWidth(LINE_WIDTH);
	BG_3L2C->SetLineWidth(LINE_WIDTH);
	BG_3L3C->SetLineWidth(LINE_WIDTH);
	BG_3L4C->SetLineWidth(LINE_WIDTH);

	BG_4L1C->SetLineWidth(LINE_WIDTH);
	BG_4L2C->SetLineWidth(LINE_WIDTH);
	BG_4L3C->SetLineWidth(LINE_WIDTH);
	BG_4L4C->SetLineWidth(LINE_WIDTH);

	BG_5L1C->SetLineWidth(LINE_WIDTH);
	BG_5L2C->SetLineWidth(LINE_WIDTH);
	BG_5L3C->SetLineWidth(LINE_WIDTH);
	BG_5L4C->SetLineWidth(LINE_WIDTH);

	BGa_1L1C->SetLineWidth(LINE_WIDTH);
	BGa_1L2C->SetLineWidth(LINE_WIDTH);
	BGa_1L3C->SetLineWidth(LINE_WIDTH);
	BGa_1L4C->SetLineWidth(LINE_WIDTH);

	BGa_2L1C->SetLineWidth(LINE_WIDTH);
	BGa_2L2C->SetLineWidth(LINE_WIDTH);
	BGa_2L3C->SetLineWidth(LINE_WIDTH);
	BGa_2L4C->SetLineWidth(LINE_WIDTH);

	BGa_3L1C->SetLineWidth(LINE_WIDTH);
	BGa_3L2C->SetLineWidth(LINE_WIDTH);
	BGa_3L3C->SetLineWidth(LINE_WIDTH);
	BGa_3L4C->SetLineWidth(LINE_WIDTH);

	BGa_4L1C->SetLineWidth(LINE_WIDTH);
	BGa_4L2C->SetLineWidth(LINE_WIDTH);
	BGa_4L3C->SetLineWidth(LINE_WIDTH);
	BGa_4L4C->SetLineWidth(LINE_WIDTH);

	BGa_5L1C->SetLineWidth(LINE_WIDTH);
	BGa_5L2C->SetLineWidth(LINE_WIDTH);
	BGa_5L3C->SetLineWidth(LINE_WIDTH);
	BGa_5L4C->SetLineWidth(LINE_WIDTH);
	
	BG_1L1C->SetLineStyle(LINE_STYLE);
	BG_1L2C->SetLineStyle(LINE_STYLE);
	BG_1L3C->SetLineStyle(LINE_STYLE);
	BG_1L4C->SetLineStyle(LINE_STYLE);

	BG_2L1C->SetLineStyle(LINE_STYLE);
	BG_2L2C->SetLineStyle(LINE_STYLE);
	BG_2L3C->SetLineStyle(LINE_STYLE);
	BG_2L4C->SetLineStyle(LINE_STYLE);

	BG_3L1C->SetLineStyle(LINE_STYLE);
	BG_3L2C->SetLineStyle(LINE_STYLE);
	BG_3L3C->SetLineStyle(LINE_STYLE);
	BG_3L4C->SetLineStyle(LINE_STYLE);

	BG_4L1C->SetLineStyle(LINE_STYLE);
	BG_4L2C->SetLineStyle(LINE_STYLE);
	BG_4L3C->SetLineStyle(LINE_STYLE);
	BG_4L4C->SetLineStyle(LINE_STYLE);

	BG_5L1C->SetLineStyle(LINE_STYLE);
	BG_5L2C->SetLineStyle(LINE_STYLE);
	BG_5L3C->SetLineStyle(LINE_STYLE);
	BG_5L4C->SetLineStyle(LINE_STYLE);

	BGa_1L1C->SetLineStyle(LINE_STYLE);
	BGa_1L2C->SetLineStyle(LINE_STYLE);
	BGa_1L3C->SetLineStyle(LINE_STYLE);
	BGa_1L4C->SetLineStyle(LINE_STYLE);

	BGa_2L1C->SetLineStyle(LINE_STYLE);
	BGa_2L2C->SetLineStyle(LINE_STYLE);
	BGa_2L3C->SetLineStyle(LINE_STYLE);
	BGa_2L4C->SetLineStyle(LINE_STYLE);

	BGa_3L1C->SetLineStyle(LINE_STYLE);
	BGa_3L2C->SetLineStyle(LINE_STYLE);
	BGa_3L3C->SetLineStyle(LINE_STYLE);
	BGa_3L4C->SetLineStyle(LINE_STYLE);

	BGa_4L1C->SetLineStyle(LINE_STYLE);
	BGa_4L2C->SetLineStyle(LINE_STYLE);
	BGa_4L3C->SetLineStyle(LINE_STYLE);
	BGa_4L4C->SetLineStyle(LINE_STYLE);

	BGa_5L1C->SetLineStyle(LINE_STYLE);
	BGa_5L2C->SetLineStyle(LINE_STYLE);
	BGa_5L3C->SetLineStyle(LINE_STYLE);
	BGa_5L4C->SetLineStyle(LINE_STYLE);

	SG_1L1C->SetLineColor(kOrange - 3);
	SG_1L2C->SetLineColor(kOrange - 3);
	SG_1L3C->SetLineColor(kOrange - 3);
	SG_1L4C->SetLineColor(kOrange - 3);

	SG_2L1C->SetLineColor(kBlack);
	SG_2L2C->SetLineColor(kBlack);
	SG_2L3C->SetLineColor(kBlack);
	SG_2L4C->SetLineColor(kBlack);

	SG_3L1C->SetLineColor(kRed);
	SG_3L2C->SetLineColor(kRed);
	SG_3L3C->SetLineColor(kRed);
	SG_3L4C->SetLineColor(kRed);

	SG_4L1C->SetLineColor(kGreen - 3);
	SG_4L2C->SetLineColor(kGreen - 3);
	SG_4L3C->SetLineColor(kGreen - 3);
	SG_4L4C->SetLineColor(kGreen - 3);

	SG_5L1C->SetLineColor(kBlue);
	SG_5L2C->SetLineColor(kBlue);
	SG_5L3C->SetLineColor(kBlue);
	SG_5L4C->SetLineColor(kBlue);

	SGa_1L1C->SetLineColor(kOrange - 3);
	SGa_1L2C->SetLineColor(kOrange - 3);
	SGa_1L3C->SetLineColor(kOrange - 3);
	SGa_1L4C->SetLineColor(kOrange - 3);

	SGa_2L1C->SetLineColor(kBlack);
	SGa_2L2C->SetLineColor(kBlack);
	SGa_2L3C->SetLineColor(kBlack);
	SGa_2L4C->SetLineColor(kBlack);

	SGa_3L1C->SetLineColor(kRed);
	SGa_3L2C->SetLineColor(kRed);
	SGa_3L3C->SetLineColor(kRed);
	SGa_3L4C->SetLineColor(kRed);

	SGa_4L1C->SetLineColor(kGreen - 3);
	SGa_4L2C->SetLineColor(kGreen - 3);
	SGa_4L3C->SetLineColor(kGreen - 3);
	SGa_4L4C->SetLineColor(kGreen - 3);

	SGa_5L1C->SetLineColor(kBlue);
	SGa_5L2C->SetLineColor(kBlue);
	SGa_5L3C->SetLineColor(kBlue);
	SGa_5L4C->SetLineColor(kBlue);

	BG_1L1C->SetLineColor(kOrange - 3);
	BG_1L2C->SetLineColor(kOrange - 3);
	BG_1L3C->SetLineColor(kOrange - 3);
	BG_1L4C->SetLineColor(kOrange - 3);

	BG_2L1C->SetLineColor(kBlack);
	BG_2L2C->SetLineColor(kBlack);
	BG_2L3C->SetLineColor(kBlack);
	BG_2L4C->SetLineColor(kBlack);

	BG_3L1C->SetLineColor(kRed);
	BG_3L2C->SetLineColor(kRed);
	BG_3L3C->SetLineColor(kRed);
	BG_3L4C->SetLineColor(kRed);

	BG_4L1C->SetLineColor(kGreen - 3);
	BG_4L2C->SetLineColor(kGreen - 3);
	BG_4L3C->SetLineColor(kGreen - 3);
	BG_4L4C->SetLineColor(kGreen - 3);

	BG_5L1C->SetLineColor(kBlue);
	BG_5L2C->SetLineColor(kBlue);
	BG_5L3C->SetLineColor(kBlue);
	BG_5L4C->SetLineColor(kBlue);

	BGa_1L1C->SetLineColor(kOrange - 3);
	BGa_1L2C->SetLineColor(kOrange - 3);
	BGa_1L3C->SetLineColor(kOrange - 3);
	BGa_1L4C->SetLineColor(kOrange - 3);

	BGa_2L1C->SetLineColor(kBlack);
	BGa_2L2C->SetLineColor(kBlack);
	BGa_2L3C->SetLineColor(kBlack);
	BGa_2L4C->SetLineColor(kBlack);

	BGa_3L1C->SetLineColor(kRed);
	BGa_3L2C->SetLineColor(kRed);
	BGa_3L3C->SetLineColor(kRed);
	BGa_3L4C->SetLineColor(kRed);

	BGa_4L1C->SetLineColor(kGreen - 3);
	BGa_4L2C->SetLineColor(kGreen - 3);
	BGa_4L3C->SetLineColor(kGreen - 3);
	BGa_4L4C->SetLineColor(kGreen - 3);

	BGa_5L1C->SetLineColor(kBlue);
	BGa_5L2C->SetLineColor(kBlue);
	BGa_5L3C->SetLineColor(kBlue);
	BGa_5L4C->SetLineColor(kBlue);

	SG_1L1C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SG_1L2C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SG_1L3C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SG_1L4C->GetYaxis()->SetLabelSize(TEXT_SIZE);

	SG_2L1C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SG_2L2C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SG_2L3C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SG_2L4C->GetYaxis()->SetLabelSize(TEXT_SIZE);

	SG_3L1C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SG_3L2C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SG_3L3C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SG_3L4C->GetYaxis()->SetLabelSize(TEXT_SIZE);

	SG_4L1C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SG_4L2C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SG_4L3C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SG_4L4C->GetYaxis()->SetLabelSize(TEXT_SIZE);

	SG_5L1C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SG_5L2C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SG_5L3C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SG_5L4C->GetYaxis()->SetLabelSize(TEXT_SIZE);

	SGa_1L1C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SGa_1L2C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SGa_1L3C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SGa_1L4C->GetYaxis()->SetLabelSize(TEXT_SIZE);

	SGa_2L1C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SGa_2L2C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SGa_2L3C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SGa_2L4C->GetYaxis()->SetLabelSize(TEXT_SIZE);

	SGa_3L1C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SGa_3L2C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SGa_3L3C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SGa_3L4C->GetYaxis()->SetLabelSize(TEXT_SIZE);

	SGa_4L1C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SGa_4L2C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SGa_4L3C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SGa_4L4C->GetYaxis()->SetLabelSize(TEXT_SIZE);

	SGa_5L1C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SGa_5L2C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SGa_5L3C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	SGa_5L4C->GetYaxis()->SetLabelSize(TEXT_SIZE);

	BG_1L1C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BG_1L2C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BG_1L3C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BG_1L4C->GetYaxis()->SetLabelSize(TEXT_SIZE);

	BG_2L1C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BG_2L2C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BG_2L3C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BG_2L4C->GetYaxis()->SetLabelSize(TEXT_SIZE);

	BG_3L1C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BG_3L2C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BG_3L3C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BG_3L4C->GetYaxis()->SetLabelSize(TEXT_SIZE);

	BG_4L1C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BG_4L2C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BG_4L3C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BG_4L4C->GetYaxis()->SetLabelSize(TEXT_SIZE);

	BG_5L1C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BG_5L2C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BG_5L3C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BG_5L4C->GetYaxis()->SetLabelSize(TEXT_SIZE);

	BGa_1L1C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BGa_1L2C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BGa_1L3C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BGa_1L4C->GetYaxis()->SetLabelSize(TEXT_SIZE);

	BGa_2L1C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BGa_2L2C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BGa_2L3C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BGa_2L4C->GetYaxis()->SetLabelSize(TEXT_SIZE);

	BGa_3L1C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BGa_3L2C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BGa_3L3C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BGa_3L4C->GetYaxis()->SetLabelSize(TEXT_SIZE);

	BGa_4L1C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BGa_4L2C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BGa_4L3C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BGa_4L4C->GetYaxis()->SetLabelSize(TEXT_SIZE);

	BGa_5L1C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BGa_5L2C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BGa_5L3C->GetYaxis()->SetLabelSize(TEXT_SIZE);
	BGa_5L4C->GetYaxis()->SetLabelSize(TEXT_SIZE);

	SG_1L1C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SG_1L2C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SG_1L3C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SG_1L4C->GetXaxis()->SetLabelSize(TEXT_SIZE);

	SG_2L1C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SG_2L2C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SG_2L3C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SG_2L4C->GetXaxis()->SetLabelSize(TEXT_SIZE);

	SG_3L1C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SG_3L2C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SG_3L3C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SG_3L4C->GetXaxis()->SetLabelSize(TEXT_SIZE);

	SG_4L1C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SG_4L2C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SG_4L3C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SG_4L4C->GetXaxis()->SetLabelSize(TEXT_SIZE);

	SG_5L1C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SG_5L2C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SG_5L3C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SG_5L4C->GetXaxis()->SetLabelSize(TEXT_SIZE);

	SGa_1L1C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SGa_1L2C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SGa_1L3C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SGa_1L4C->GetXaxis()->SetLabelSize(TEXT_SIZE);

	SGa_2L1C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SGa_2L2C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SGa_2L3C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SGa_2L4C->GetXaxis()->SetLabelSize(TEXT_SIZE);

	SGa_3L1C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SGa_3L2C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SGa_3L3C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SGa_3L4C->GetXaxis()->SetLabelSize(TEXT_SIZE);

	SGa_4L1C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SGa_4L2C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SGa_4L3C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SGa_4L4C->GetXaxis()->SetLabelSize(TEXT_SIZE);

	SGa_5L1C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SGa_5L2C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SGa_5L3C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	SGa_5L4C->GetXaxis()->SetLabelSize(TEXT_SIZE);

	BG_1L1C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BG_1L2C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BG_1L3C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BG_1L4C->GetXaxis()->SetLabelSize(TEXT_SIZE);

	BG_2L1C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BG_2L2C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BG_2L3C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BG_2L4C->GetXaxis()->SetLabelSize(TEXT_SIZE);

	BG_3L1C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BG_3L2C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BG_3L3C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BG_3L4C->GetXaxis()->SetLabelSize(TEXT_SIZE);

	BG_4L1C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BG_4L2C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BG_4L3C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BG_4L4C->GetXaxis()->SetLabelSize(TEXT_SIZE);

	BG_5L1C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BG_5L2C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BG_5L3C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BG_5L4C->GetXaxis()->SetLabelSize(TEXT_SIZE);

	BGa_1L1C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BGa_1L2C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BGa_1L3C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BGa_1L4C->GetXaxis()->SetLabelSize(TEXT_SIZE);

	BGa_2L1C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BGa_2L2C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BGa_2L3C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BGa_2L4C->GetXaxis()->SetLabelSize(TEXT_SIZE);

	BGa_3L1C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BGa_3L2C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BGa_3L3C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BGa_3L4C->GetXaxis()->SetLabelSize(TEXT_SIZE);

	BGa_4L1C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BGa_4L2C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BGa_4L3C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BGa_4L4C->GetXaxis()->SetLabelSize(TEXT_SIZE);

	BGa_5L1C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BGa_5L2C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BGa_5L3C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	BGa_5L4C->GetXaxis()->SetLabelSize(TEXT_SIZE);
	return;
}

void CONSTpT_SETYrange()
{
	float MaxY = 1e3;
	float MAXy = 1e4;
	MaxY = BG_1L1C->GetMaximum()*5;
	BG_1L1C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BG_1L2C->GetMaximum()*5;
	BG_1L2C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BG_1L3C->GetMaximum()*5;
	BG_1L3C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BG_1L4C->GetMaximum()*5;
	BG_1L4C->GetYaxis()->SetRangeUser(1,MAXy);

	MaxY = BG_2L1C->GetMaximum()*5;
	BG_2L1C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BG_2L2C->GetMaximum()*5;
	BG_2L2C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BG_2L3C->GetMaximum()*5;
	BG_2L3C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BG_2L4C->GetMaximum()*5;
	BG_2L4C->GetYaxis()->SetRangeUser(1,MAXy);

	MaxY = BG_3L1C->GetMaximum()*5;
	BG_3L1C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BG_3L2C->GetMaximum()*5;
	BG_3L2C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BG_3L3C->GetMaximum()*5;
	BG_3L3C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BG_3L4C->GetMaximum()*5;
	BG_3L4C->GetYaxis()->SetRangeUser(1,MAXy);

	MaxY = BG_4L1C->GetMaximum()*5;
	BG_4L1C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BG_4L2C->GetMaximum()*5;
	BG_4L2C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BG_4L3C->GetMaximum()*5;
	BG_4L3C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BG_4L4C->GetMaximum()*5;
	BG_4L4C->GetYaxis()->SetRangeUser(1,MAXy);

	MaxY = BG_5L1C->GetMaximum()*5;
	BG_5L1C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BG_5L2C->GetMaximum()*5;
	BG_5L2C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BG_5L3C->GetMaximum()*5;
	BG_5L3C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BG_5L4C->GetMaximum()*5;
	BG_5L4C->GetYaxis()->SetRangeUser(1,MAXy);
	
	MaxY = BGa_1L1C->GetMaximum()*5;
	BGa_1L1C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BGa_1L2C->GetMaximum()*5;
	BGa_1L2C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BGa_1L3C->GetMaximum()*5;
	BGa_1L3C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BGa_1L4C->GetMaximum()*5;
	BGa_1L4C->GetYaxis()->SetRangeUser(1,MAXy);

	MaxY = BGa_2L1C->GetMaximum()*5;
	BGa_2L1C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BGa_2L2C->GetMaximum()*5;
	BGa_2L2C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BGa_2L3C->GetMaximum()*5;
	BGa_2L3C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BGa_2L4C->GetMaximum()*5;
	BGa_2L4C->GetYaxis()->SetRangeUser(1,MAXy);

	MaxY = BGa_3L1C->GetMaximum()*5;
	BGa_3L1C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BGa_3L2C->GetMaximum()*5;
	BGa_3L2C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BGa_3L3C->GetMaximum()*5;
	BGa_3L3C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BGa_3L4C->GetMaximum()*5;
	BGa_3L4C->GetYaxis()->SetRangeUser(1,MAXy);

	MaxY = BGa_4L1C->GetMaximum()*5;
	BGa_4L1C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BGa_4L2C->GetMaximum()*5;
	BGa_4L2C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BGa_4L3C->GetMaximum()*5;
	BGa_4L3C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BGa_4L4C->GetMaximum()*5;
	BGa_4L4C->GetYaxis()->SetRangeUser(1,MAXy);

	MaxY = BGa_5L1C->GetMaximum()*5;
	BGa_5L1C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BGa_5L2C->GetMaximum()*5;
	BGa_5L2C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BGa_5L3C->GetMaximum()*5;
	BGa_5L3C->GetYaxis()->SetRangeUser(1,MAXy);
	MaxY = BGa_5L4C->GetMaximum()*5;
	BGa_5L4C->GetYaxis()->SetRangeUser(1,MAXy);
	return;

}
