
void INIT_2()
{
	f2 = TFile::Open(filename2);
	t2 = (TTree*)f2->Get("bin_Tree");

	t2->SetBranchAddress("M_1L", &MBG_1L);
	t2->SetBranchAddress("M_2L", &MBG_2L);
	t2->SetBranchAddress("M_3L", &MBG_3L);
	t2->SetBranchAddress("M_4L", &MBG_4L);
	t2->SetBranchAddress("M_5L", &MBG_5L);
	t2->SetBranchAddress("Ma_1L", &MBGa_1L);
	t2->SetBranchAddress("Ma_2L", &MBGa_2L);
	t2->SetBranchAddress("Ma_3L", &MBGa_3L);
	t2->SetBranchAddress("Ma_4L", &MBGa_4L);
	t2->SetBranchAddress("Ma_5L", &MBGa_5L);
	t2->SetBranchAddress("C_1LpT", &CBG_1LpT);
	t2->SetBranchAddress("C_2LpT", &CBG_2LpT);
	t2->SetBranchAddress("C_3LpT", &CBG_3LpT);
	t2->SetBranchAddress("C_4LpT", &CBG_4LpT);
	t2->SetBranchAddress("C_5LpT", &CBG_5LpT);
	t2->SetBranchAddress("Ca_1LpT", &CBGa_1LpT);
	t2->SetBranchAddress("Ca_2LpT", &CBGa_2LpT);
	t2->SetBranchAddress("Ca_3LpT", &CBGa_3LpT);
	t2->SetBranchAddress("Ca_4LpT", &CBGa_4LpT);
	t2->SetBranchAddress("Ca_5LpT", &CBGa_5LpT);

	hBG_1L1C = new TH2D("hBG_1L1C","leading, BG;multiplicity;1^{st} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBG_1L2C = new TH2D("hBG_1L2C","leading, BG;multiplicity;2^{nd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBG_1L3C = new TH2D("hBG_1L3C","leading, BG;multiplicity;3^{rd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBG_1L4C = new TH2D("hBG_1L4C","leading, BG;multiplicity;4^{th} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	
	hBG_2L1C = new TH2D("hBG_2L1C","2^{nd} leading, BG;multiplicity;1^{st} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBG_2L2C = new TH2D("hBG_2L2C","2^{nd} leading, BG;multiplicity;2^{nd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBG_2L3C = new TH2D("hBG_2L3C","2^{nd} leading, BG;multiplicity;3^{rd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBG_2L4C = new TH2D("hBG_2L4C","2^{nd} leading, BG;multiplicity;4^{th} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	
	hBG_3L1C = new TH2D("hBG_3L1C","3^{rd} leading, BG;multiplicity;1^{st} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBG_3L2C = new TH2D("hBG_3L2C","3^{rd} leading, BG;multiplicity;2^{nd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBG_3L3C = new TH2D("hBG_3L3C","3^{rd} leading, BG;multiplicity;3^{rd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBG_3L4C = new TH2D("hBG_3L4C","3^{rd} leading, BG;multiplicity;4^{th} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	
	hBG_4L1C = new TH2D("hBG_4L1C","4^{th} leading, BG;multiplicity;1^{st} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBG_4L2C = new TH2D("hBG_4L2C","4^{th} leading, BG;multiplicity;2^{nd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBG_4L3C = new TH2D("hBG_4L3C","4^{th} leading, BG;multiplicity;3^{rd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBG_4L4C = new TH2D("hBG_4L4C","4^{th} leading, BG;multiplicity;4^{th} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	
	hBG_5L1C = new TH2D("hBG_5L1C","5^{th} leading, BG;multiplicity;1^{st} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBG_5L2C = new TH2D("hBG_5L2C","5^{th} leading, BG;multiplicity;2^{nd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBG_5L3C = new TH2D("hBG_5L3C","5^{th} leading, BG;multiplicity;3^{rd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBG_5L4C = new TH2D("hBG_5L4C","5^{th} leading, BG;multiplicity;4^{th} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	
	
	hBGa_1L1C = new TH2D("hBGa_1L1C","leading, BG;multiplicity;1^{st} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBGa_1L2C = new TH2D("hBGa_1L2C","leading, BG;multiplicity;2^{nd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBGa_1L3C = new TH2D("hBGa_1L3C","leading, BG;multiplicity;3^{rd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBGa_1L4C = new TH2D("hBGa_1L4C","leading, BG;multiplicity;4^{th} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	
	hBGa_2L1C = new TH2D("hBGa_2L1C","2^{nd} leading, BG;multiplicity;1^{st} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBGa_2L2C = new TH2D("hBGa_2L2C","2^{nd} leading, BG;multiplicity;2^{nd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBGa_2L3C = new TH2D("hBGa_2L3C","2^{nd} leading, BG;multiplicity;3^{rd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBGa_2L4C = new TH2D("hBGa_2L4C","2^{nd} leading, BG;multiplicity;4^{th} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	
	hBGa_3L1C = new TH2D("hBGa_3L1C","3^{rd} leading, BG;multiplicity;1^{st} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBGa_3L2C = new TH2D("hBGa_3L2C","3^{rd} leading, BG;multiplicity;2^{nd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBGa_3L3C = new TH2D("hBGa_3L3C","3^{rd} leading, BG;multiplicity;3^{rd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBGa_3L4C = new TH2D("hBGa_3L4C","3^{rd} leading, BG;multiplicity;4^{th} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	
	hBGa_4L1C = new TH2D("hBGa_4L1C","4^{th} leading, BG;multiplicity;1^{st} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBGa_4L2C = new TH2D("hBGa_4L2C","4^{th} leading, BG;multiplicity;2^{nd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBGa_4L3C = new TH2D("hBGa_4L3C","4^{th} leading, BG;multiplicity;3^{rd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBGa_4L4C = new TH2D("hBGa_4L4C","4^{th} leading, BG;multiplicity;4^{th} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	
	hBGa_5L1C = new TH2D("hBGa_5L1C","5^{th} leading, BG;multiplicity;1^{st} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBGa_5L2C = new TH2D("hBGa_5L2C","5^{th} leading, BG;multiplicity;2^{nd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBGa_5L3C = new TH2D("hBGa_5L3C","5^{th} leading, BG;multiplicity;3^{rd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	hBGa_5L4C = new TH2D("hBGa_5L4C","5^{th} leading, BG;multiplicity;4^{th} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);

	return;
}
