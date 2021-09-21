
void INIT_1()
{
	f1 = TFile::Open(filename1);
	t1 = (TTree*)f1->Get("bin_Tree");

	t1->SetBranchAddress("M_1L", &M_1L);
	t1->SetBranchAddress("M_2L", &M_2L);
	t1->SetBranchAddress("M_3L", &M_3L);
	t1->SetBranchAddress("M_4L", &M_4L);
	t1->SetBranchAddress("M_5L", &M_5L);
	t1->SetBranchAddress("Ma_1L", &Ma_1L);
	t1->SetBranchAddress("Ma_2L", &Ma_2L);
	t1->SetBranchAddress("Ma_3L", &Ma_3L);
	t1->SetBranchAddress("Ma_4L", &Ma_4L);
	t1->SetBranchAddress("Ma_5L", &Ma_5L);
	t1->SetBranchAddress("C_1LpT", &C_1LpT);
	t1->SetBranchAddress("C_2LpT", &C_2LpT);
	t1->SetBranchAddress("C_3LpT", &C_3LpT);
	t1->SetBranchAddress("C_4LpT", &C_4LpT);
	t1->SetBranchAddress("C_5LpT", &C_5LpT);
	t1->SetBranchAddress("Ca_1LpT", &Ca_1LpT);
	t1->SetBranchAddress("Ca_2LpT", &Ca_2LpT);
	t1->SetBranchAddress("Ca_3LpT", &Ca_3LpT);
	t1->SetBranchAddress("Ca_4LpT", &Ca_4LpT);
	t1->SetBranchAddress("Ca_5LpT", &Ca_5LpT);

	h_1L1C = new TH2D("h_1L1C","leading;multiplicity;1^{st} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	h_1L2C = new TH2D("h_1L2C","leading;multiplicity;2^{nd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	h_1L3C = new TH2D("h_1L3C","leading;multiplicity;3^{rd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	h_1L4C = new TH2D("h_1L4C","leading;multiplicity;4^{th} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
                                 
	h_2L1C = new TH2D("h_2L1C","2^{nd} leading;multiplicity;1^{st} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	h_2L2C = new TH2D("h_2L2C","2^{nd} leading;multiplicity;2^{nd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	h_2L3C = new TH2D("h_2L3C","2^{nd} leading;multiplicity;3^{rd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	h_2L4C = new TH2D("h_2L4C","2^{nd} leading;multiplicity;4^{th} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
                                 
	h_3L1C = new TH2D("h_3L1C","3^{rd} leading;multiplicity;1^{st} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	h_3L2C = new TH2D("h_3L2C","3^{rd} leading;multiplicity;2^{nd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	h_3L3C = new TH2D("h_3L3C","3^{rd} leading;multiplicity;3^{rd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	h_3L4C = new TH2D("h_3L4C","3^{rd} leading;multiplicity;4^{th} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
                                 
	h_4L1C = new TH2D("h_4L1C","4^{th} leading;multiplicity;1^{st} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	h_4L2C = new TH2D("h_4L2C","4^{th} leading;multiplicity;2^{nd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	h_4L3C = new TH2D("h_4L3C","4^{th} leading;multiplicity;3^{rd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	h_4L4C = new TH2D("h_4L4C","4^{th} leading;multiplicity;4^{th} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
                                 
	h_5L1C = new TH2D("h_5L1C","5^{th} leading;multiplicity;1^{st} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	h_5L2C = new TH2D("h_5L2C","5^{th} leading;multiplicity;2^{nd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	h_5L3C = new TH2D("h_5L3C","5^{th} leading;multiplicity;3^{rd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	h_5L4C = new TH2D("h_5L4C","5^{th} leading;multiplicity;4^{th} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);


	ha_1L1C = new TH2D("ha_1L1C","leading;multiplicity;1^{st} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	ha_1L2C = new TH2D("ha_1L2C","leading;multiplicity;2^{nd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	ha_1L3C = new TH2D("ha_1L3C","leading;multiplicity;3^{rd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	ha_1L4C = new TH2D("ha_1L4C","leading;multiplicity;4^{th} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
                                 
	ha_2L1C = new TH2D("ha_2L1C","2^{nd} leading;multiplicity;1^{st} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	ha_2L2C = new TH2D("ha_2L2C","2^{nd} leading;multiplicity;2^{nd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	ha_2L3C = new TH2D("ha_2L3C","2^{nd} leading;multiplicity;3^{rd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	ha_2L4C = new TH2D("ha_2L4C","2^{nd} leading;multiplicity;4^{th} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
                                 
	ha_3L1C = new TH2D("ha_3L1C","3^{rd} leading;multiplicity;1^{st} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	ha_3L2C = new TH2D("ha_3L2C","3^{rd} leading;multiplicity;2^{nd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	ha_3L3C = new TH2D("ha_3L3C","3^{rd} leading;multiplicity;3^{rd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	ha_3L4C = new TH2D("ha_3L4C","3^{rd} leading;multiplicity;4^{th} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
                                 
	ha_4L1C = new TH2D("ha_4L1C","4^{th} leading;multiplicity;1^{st} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	ha_4L2C = new TH2D("ha_4L2C","4^{th} leading;multiplicity;2^{nd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	ha_4L3C = new TH2D("ha_4L3C","4^{th} leading;multiplicity;3^{rd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	ha_4L4C = new TH2D("ha_4L4C","4^{th} leading;multiplicity;4^{th} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
                                 
	ha_5L1C = new TH2D("ha_5L1C","5^{th} leading;multiplicity;1^{st} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	ha_5L2C = new TH2D("ha_5L2C","5^{th} leading;multiplicity;2^{nd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	ha_5L3C = new TH2D("ha_5L3C","5^{th} leading;multiplicity;3^{rd} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);
	ha_5L4C = new TH2D("ha_5L4C","5^{th} leading;multiplicity;4^{th} constituent p_{T} [GeV/c]",multBIN, MINmult, MAXmult, pTBIN, MINpT, MAXpT);

	return;
}
