
bool debug = true;
Int_t nbinsE, nbinsR;
Int_t nbinsEa, nbinsRa;
Int_t nbinsEb, nbinsRb;
Int_t nevents;
// X-range: trigger efficiency, Y-range: trigger rate [MHz]
Float_t Xmin_range = 0.0, Xmax_range = 1.05;
Float_t Ymin_range = 3e-2, Ymax_range = 60.0;

// pT binning used during jet clustering
const int n = 500;
Double_t pt_threshold[n] = {0};

char signal_file_name[1023];
char MinBias_file_name[1023];
char signal_file_name_1[1023];
char MinBias_file_name_1[1023];
char signal_file_name_2[1023];
char MinBias_file_name_2[1023];
char signal_file_name_3[1023];
char MinBias_file_name_3[1023];
char signal_file_calo[1023];
char MinBias_file_calo[1023];

const double STAR_SIZE = 2.3;
const double DIAMOND_SIZE = 2.2;
const double TRIANGLEUP_SIZE = 1.5;
const double TRIANGLEDOWN_SIZE = 1.5;
