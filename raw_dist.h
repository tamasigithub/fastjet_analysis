
const char* out_path = "./summary_plots/pdf"; 
const char* output_file_name = "rawDist_30mm_Eta1.5";
TChain t1("tracks");
TChain t2("tracks");
TChain r1("m_recTree");
TChain r2("m_recTree");

int eve_i = 0;
double PV_i = 0;

std::vector<double> *pt1 = nullptr;
std::vector<double> *eta1 = nullptr;
std::vector<double> *theta1 = nullptr;
std::vector<double> *vz1 = nullptr;
std::vector<double> *vx1 = nullptr;
std::vector<double> *vy1 = nullptr;
std::vector<int>    *pid1 = nullptr;
std::vector<int>    *type_traj1 = nullptr;
std::vector<int>    *charge1 = nullptr;

std::vector<double> *pt2 = nullptr;
std::vector<double> *eta2 = nullptr;
std::vector<double> *theta2 = nullptr;
std::vector<double> *vz2 = nullptr;
std::vector<double> *vx2 = nullptr;
std::vector<double> *vy2 = nullptr;
std::vector<int>    *pid2 = nullptr;
std::vector<int>    *type_traj2 = nullptr;
std::vector<int>    *charge2 = nullptr;

std::vector<double> *Pt_n1 = nullptr;
std::vector<double> *M_pt1 = nullptr;
std::vector<double> *Eta1 = nullptr;
std::vector<double> *Theta1 = nullptr;
std::vector<double> *M_eta1 = nullptr;
std::vector<double> *M_theta1 = nullptr;
std::vector<double> *Z01 = nullptr;
std::vector<double> *M_Vz1 = nullptr;
std::vector<int> *Tid1 = nullptr;
std::vector<int> *M_pdg1 = nullptr;
std::vector<int> *type1 = nullptr;
std::vector<double> *kappa_pull1 = nullptr;

std::vector<double> *Pt_n2 = nullptr;
std::vector<double> *M_pt2 = nullptr;
std::vector<double> *Eta2 = nullptr;
std::vector<double> *Theta2 = nullptr;
std::vector<double> *M_eta2 = nullptr;
std::vector<double> *M_theta2 = nullptr;
std::vector<double> *Z02 = nullptr;
std::vector<double> *M_Vz2 = nullptr;
std::vector<int> *Tid2 = nullptr;
std::vector<int> *M_pdg2 = nullptr;
std::vector<int> *type2 = nullptr;
std::vector<double> *kappa_pull2 = nullptr;

TH1D *ht_pT_1 = nullptr;//pT dist of signal gen particles
TH1D *ht_pT_2 = nullptr;//pT dist of pileup gen particles
TH1D *hr_pT_1 = nullptr;//pT dist of signal rec tracks
TH1D *hr_pT_2 = nullptr;//pT dist of pileup rec tracks
TH1D *hmr_pT_1 = nullptr;//matched pT dist of signal rec tracks
TH1D *hmr_pT_2 = nullptr;//matched pT dist of pileup rec tracks

TH1D *ht_eta_1 = nullptr;//eta dist of signal gen particles
TH1D *ht_eta_2 = nullptr;//eta dist of pileup gen particles
TH1D *hr_eta_1 = nullptr;//eta dist of signal rec tracks
TH1D *hr_eta_2 = nullptr;//eta dist of pileup rec tracks

TH1D *ht_pdg_1 = nullptr;//pdg dist of signal gen particles
TH1D *ht_pdg_2 = nullptr;//pdg dist of pileup gen particles
TH1D *hr_pdg_1 = nullptr;//pdg dist of signal rec tracks
TH1D *hr_pdg_2 = nullptr;//pdg dist of pileup rec tracks

TH1D *ht_type_1 = nullptr;//type dist of signal gen particles
TH1D *ht_type_2 = nullptr;//type dist of pileup gen particles
TH1D *hr_type_1 = nullptr;//type dist of signal rec tracks
TH1D *hr_type_2 = nullptr;//type dist of pileup rec tracks

TH1D *ht_z0_1 = nullptr;//z0 dist of signal gen particles
TH1D *ht_z0_2 = nullptr;//z0 dist of pileup gen particles
TH1D *hr_z0_1 = nullptr;//z0 dist of signal rec tracks
TH1D *hr_z0_2 = nullptr;//z0 dist of pileup rec tracks
TH1D *hmr_z0_1 = nullptr;//z0 dist of signal rec tracks
TH1D *hmr_z0_2 = nullptr;//z0 dist of pileup rec tracks
TH1D *hr_z0reso_1 = nullptr;//z0reso dist of signal rec tracks
TH1D *hr_z0reso_2 = nullptr;//z0reso dist of pileup rec tracks

TH1D *ht_theta_1 = nullptr;//theta dist of signal gen particles
TH1D *ht_theta_2 = nullptr;//theta dist of pileup gen particles
TH1D *hr_theta_1 = nullptr;//theta dist of signal rec tracks
TH1D *hr_theta_2 = nullptr;//theta dist of pileup rec tracks
TH1D *hmr_theta_1 = nullptr;//theta dist of signal rec tracks
TH1D *hmr_theta_2 = nullptr;//theta dist of pileup rec tracks
TH1D *hr_thetareso_1 = nullptr;//thetareso dist of signal rec tracks
TH1D *hr_thetareso_2 = nullptr;//thetareso dist of pileup rec tracks

TH2D *h2d_1 = nullptr;
TH2D *h2d_2 = nullptr;

Int_t Nbins = 100;
Double_t MaxpT = 100, MinpT = 2;
Int_t NbinsETA = 50;
Double_t Maxeta = -2.5, Mineta = 2.5;
Int_t NbinsTHETA = 50;
Double_t Maxtheta = 3.1, Mintheta = 0;
Double_t Maxthetareso = 0.02, Minthetareso = -0.02;
Int_t NbinsPDG = 2250;
Int_t Maxpdg = 2250, Minpdg = -50;
Int_t NbinsTYPE = 8;
Int_t Maxtype = 8, Mintype = 0;
Int_t NZbins = 500;
Double_t Maxz0 = 500, Minz0 = -500;
Int_t NZresobins = 100;
Double_t Maxz0reso = 10, Minz0reso = -10;

void INIT_gen_1()
{
	t1.SetBranchAddress("pt", &pt1);
	t1.SetBranchAddress("eta", &eta1);
	t1.SetBranchAddress("theta", &theta1);
	t1.SetBranchAddress("vz", &vz1);
	t1.SetBranchAddress("vx", &vx1);
	t1.SetBranchAddress("vy", &vy1);
	t1.SetBranchAddress("pid", &pid1);
	t1.SetBranchAddress("type_traj", &type_traj1);
	t1.SetBranchAddress("charge", &charge1);
	return;
}
void INIT_gen_2()
{
	t2.SetBranchAddress("pt", &pt2);
	t2.SetBranchAddress("eta", &eta2);
	t2.SetBranchAddress("theta", &theta2);
	t2.SetBranchAddress("vz", &vz2);
	t2.SetBranchAddress("vx", &vx2);
	t2.SetBranchAddress("vy", &vy2);
	t2.SetBranchAddress("pid", &pid2);
	t2.SetBranchAddress("type_traj", &type_traj2);
	t2.SetBranchAddress("charge", &charge2);
	return;
}
void INIT_rec_1()
{
	r1.SetBranchAddress("Pt_n",&Pt_n1);
	r1.SetBranchAddress("M_pt",&M_pt1);
	r1.SetBranchAddress("Eta13",&Eta1);
	r1.SetBranchAddress("M_eta",&M_eta1);
	r1.SetBranchAddress("Theta13",&Theta1);
	r1.SetBranchAddress("M_theta",&M_theta1);
	r1.SetBranchAddress("Z013",&Z01);
	r1.SetBranchAddress("M_Vz",&M_Vz1);
	r1.SetBranchAddress("Tid",&Tid1);
	r1.SetBranchAddress("M_pdg",&M_pdg1);
	r1.SetBranchAddress("kappa_pull",&kappa_pull1);
	r1.SetBranchAddress("mc_interaction",&type1);
	return;
}
void INIT_rec_2()
{
	r2.SetBranchAddress("Pt_n",&Pt_n2);
	r2.SetBranchAddress("M_pt",&M_pt2);
	r2.SetBranchAddress("Eta13",&Eta2);
	r2.SetBranchAddress("M_eta",&M_eta2);
	r2.SetBranchAddress("Theta13",&Theta2);
	r2.SetBranchAddress("M_theta",&M_theta2);
	r2.SetBranchAddress("Z013",&Z02);
	r2.SetBranchAddress("M_Vz",&M_Vz2);
	r2.SetBranchAddress("Tid",&Tid2);
	r2.SetBranchAddress("M_pdg",&M_pdg2);
	r2.SetBranchAddress("kappa_pull",&kappa_pull2);
	r2.SetBranchAddress("mc_interaction",&type2);
	return;
}
void INIT_HISTOS()
{
	ht_pT_1 = new TH1D("ht_pT_1","signal gen; p_{T} [GeV/c]", Nbins, MinpT, MaxpT);
	ht_pT_2 = new TH1D("ht_pT_2","pileup gen; p_{T} [GeV/c]", Nbins, MinpT, MaxpT);
	hr_pT_1 = new TH1D("hr_pT_1","signal rec; p_{T} [GeV/c]", Nbins, MinpT, MaxpT);
	hr_pT_2 = new TH1D("hr_pT_2","pileup rec; p_{T} [GeV/c]", Nbins, MinpT, MaxpT);
	hmr_pT_1 = new TH1D("hmr_pT_1","signal rec; matched p_{T} [GeV/c]", Nbins, MinpT, MaxpT);
	hmr_pT_2 = new TH1D("hmr_pT_2","pileup rec; matched p_{T} [GeV/c]", Nbins, MinpT, MaxpT);

	ht_eta_1 = new TH1D("ht_eta_1","signal gen; #eta", NbinsETA, Mineta, Maxeta);
	ht_eta_2 = new TH1D("ht_eta_2","pileup gen; #eta", NbinsETA, Mineta, Maxeta);
	hr_eta_1 = new TH1D("hr_eta_1","signal rec; #eta", NbinsETA, Mineta, Maxeta);
	hr_eta_2 = new TH1D("hr_eta_2","pileup rec; #eta", NbinsETA, Mineta, Maxeta);

	ht_theta_1 = new TH1D("ht_theta_1","signal gen; #theta", NbinsTHETA, Mintheta, Maxtheta);
	ht_theta_2 = new TH1D("ht_theta_2","pileup gen; #theta", NbinsTHETA, Mintheta, Maxtheta);
	hr_theta_1 = new TH1D("hr_theta_1","signal rec; #theta", NbinsTHETA, Mintheta, Maxtheta);
	hr_theta_2 = new TH1D("hr_theta_2","pileup rec; #theta", NbinsTHETA, Mintheta, Maxtheta);
	hmr_theta_1 = new TH1D("hmr_theta_1","signal rec; matched #theta", NbinsTHETA, Mintheta, Maxtheta);
	hmr_theta_2 = new TH1D("hmr_theta_2","pileup rec; matched #theta", NbinsTHETA, Mintheta, Maxtheta);
	hr_thetareso_1 = new TH1D("hr_thetareso_1","signal rec; #theta reso", NbinsTHETA, Minthetareso, Maxthetareso);
	hr_thetareso_2 = new TH1D("hr_thetareso_2","pileup rec; #theta reso", NbinsTHETA, Minthetareso, Maxthetareso);
	
	ht_pdg_1 = new TH1D("ht_pdg_1","signal gen; pdg", NbinsPDG, Minpdg, Maxpdg);
	ht_pdg_2 = new TH1D("ht_pdg_2","pileup gen; pdg", NbinsPDG, Minpdg, Maxpdg);
	hr_pdg_1 = new TH1D("hr_pdg_1","signal rec; pdg", NbinsPDG, Minpdg, Maxpdg);
	hr_pdg_2 = new TH1D("hr_pdg_2","pileup rec; pdg", NbinsPDG, Minpdg, Maxpdg);
	
	ht_type_1 = new TH1D("ht_type_1","signal gen; type", NbinsTYPE, Mintype, Maxtype);
	ht_type_2 = new TH1D("ht_type_2","pileup gen; type", NbinsTYPE, Mintype, Maxtype);
	hr_type_1 = new TH1D("hr_type_1","signal rec; type", NbinsTYPE, Mintype, Maxtype);
	hr_type_2 = new TH1D("hr_type_2","pileup rec; type", NbinsTYPE, Mintype, Maxtype);
	
	h2d_1 = new TH2D("h2d_1","signal gen; pdg; type", 400, 0, 3500,  NbinsTYPE, Mintype, Maxtype);
	h2d_2 = new TH2D("h2d_2","pileup gen; pdg; type", 400, 0, 3500,  NbinsTYPE, Mintype, Maxtype);

	ht_z0_1 = new TH1D("ht_z0_1","signal gen; z0 [mm]", NZbins, Minz0, Maxz0);
	ht_z0_2 = new TH1D("ht_z0_2","pileup gen; z0 [mm]", NZbins, Minz0, Maxz0);
	hr_z0_1 = new TH1D("hr_z0_1","signal rec; z0 [mm]", NZbins, Minz0, Maxz0);
	hr_z0_2 = new TH1D("hr_z0_2","pileup rec; z0 [mm]", NZbins, Minz0, Maxz0);
	hmr_z0_1 = new TH1D("hmr_z0_1","signal rec; matched z0 [mm]", NZbins, Minz0, Maxz0);
	hmr_z0_2 = new TH1D("hmr_z0_2","pileup rec; matched z0 [mm]", NZbins, Minz0, Maxz0);
	hr_z0reso_1 = new TH1D("hr_z0reso_1","signal rec;z0reso [mm]", NZresobins, Minz0reso, Maxz0reso);
	hr_z0reso_2 = new TH1D("hr_z0reso_2","pileup rec;z0reso [mm]", NZresobins, Minz0reso, Maxz0reso);
	return;
}

