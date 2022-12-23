
double pT_threshold = 0;// Trigger threshold for pileup rate of 4MHz
const double TTT_for3L = 32e3;
const double CaloT_for3L = 752e3;

const double IntLumi     = 3e4;
const double pp4bXsec    = 23.283e6;
const double ggFhhXsec1  = 12.24e2;
const double four_b_Prob = std::pow(0.58,2);
const int tot_MCevents = 5e5;
const int tot_MCevents_B = 1e6;

const char *in_files[] = {
//! Generator level info
"../event_list/out_test/user.tkar.EventList_2_5_allAnaCuts_000005.root", /* ggF signal events */
"../event_list/out_test/user.tkar.EventListpp4bQCD_2_5_allAnaCuts_000005_.root",  /* pp4b BG events */
//! Triggered jet info
"../fastjet_output/TTT_data/08_12_22/ggF1.0/TrkJPU1k1.5mm_Br30mmEC80mm_11111trk2.5_22222GeV_1.root", /*ggF signal TTT +-1.5 */
"../fastjet_output/TTT_data/08_12_22/pp_4bQCD/TrkJPU1k1.5mm_Br30mmEC80mm_11111trk2.5_22222GeV_1.root", /*pp4b BG TTT +-1.5 */
"../fastjet_output/calo_data/08_12_22/CELL_a50c3_ALL_PU1kggF_ETA2.5_30mm_R0.4_2.root", /*ggF signal calo */
"../fastjet_output/calo_data/08_12_22/CELL_a50c3_ALL_PU1kpp_4bQCD_ETA2.5_30mm_R0.4_2.root"  /*pp4b BG calo */
};

const char *pheno_file = "../analysis_plots/root/GenJet4b2_2.5_allR0.4_0.8_incl4bProbMH30.root";

const char *out_file = "./summary_significance_.root";
const int N_files = 6;
//std::vector<TFile *> root_files = {S_eve, B_eve, S_TTT, B_TTT, S_Cal, B_Cal};
std::vector<TFile *> root_files;
std::vector<TTree *> trees;// first two trees are 'eventList' and the rest are 'bin_Tree'

//! 6 local variables for the branches in 6 trees
//! first two are generator level 'b'-jets (for S and BG)
//! Next two are TTT-jets from the PB selected using sumpt(max-bin) method(for S and BG)
//! Next two are emu-calo-jets (for S and BG)
std::vector<int> eve_nums = {0,0,0,0,0,0}; 
std::vector<double> L3_JpT = {0,0,0,0,0,0};
std::vector<double> L4_JpT = {0,0,0,0,0,0};

//! 2(for S and BG) unordered_maps with key as event Id and value as 4th b-jet pT 
std::unordered_map<int, double> gen_4th_bJpT [2];

//! variables of output ttree
//! size of the following vectors is four(2TTT and 2Calo)
std::array<std::vector<double>, 4> triggered_4L_bJpT;
std::vector<TH1F *> h_trig_4L_bJpT;
std::vector<TH1F *> h_4L_bJpT; //gen bJpT for the sub-set of events used in the trigger studies 
std::vector<TH1F *> h_4L_bJpT_ratio; //ratio of triggered events / total events fed to the triggered (h_trig_4L_bJpT/h_4L_bJpT) 
std::vector<TH1F *> h_4L_bJpT_pheno_frac; //fraction of the pheno ana events = tot pheno ana events * h_4L_bJpT_ratio
//(size: 2, one for signal and one for BG)
std::vector<TH1F *> h_4L_bJpT_pheno; // tot pheno ana events 
//copy
std::vector<TH1F *> h_trig_4L_bJpT_copy;
std::vector<TH1F *> h_4L_bJpT_copy; //gen bJpT for the sub-set of events used in the trigger studies 
//std::vector<TH1F *> h_4L_bJpT_ratio_copy; //ratio of triggered events / total events fed to the triggered (h_trig_4L_bJpT/h_4L_bJpT) 
std::vector<TH1F *> h_4L_bJpT_pheno_frac_copy; //fraction of the pheno ana events = tot pheno ana events * h_4L_bJpT_ratio
//(size: 2, one for signal and one for BG)
std::vector<TH1F *> h_4L_bJpT_pheno_copy; // tot pheno ana events  
TH1F *h_TTT_Z = nullptr;
TH1F *h_Cal_Z = nullptr;
TH1F *h_pheno_Z = nullptr;
const int n = 7;
int nbinsMinus = n - 1;
double pt_bins[n] = {20., 30., 40., 50., 60., 70., 500.};
//double pt_bins[n] = {20., 30., 40., 50., 60., 90., 500.};

TLegend *leg = 0;
TLegend *leg1 = 0;
TLegend *leg2 = 0;

float offset = 0;
float offset_div = 84.0;
TGraphAsymmErrors *gr_TTT = nullptr;
TGraphAsymmErrors *gr_Cal = nullptr;
TGraphAsymmErrors *gr_pheno = nullptr;

std::vector<TGraphAsymmErrors *> gr_bJ_ratio;
