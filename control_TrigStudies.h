#include "TROOT.h"
#include <iostream>
#include <vector>

const char* out_path = "./summary_plots/pdf"; 
const char* output_file_name = "control_TRKPU1k_1.5mm_30mm_Eta1.5_11111_22222_1";
//const char *filename1 = "./fastjet_output/TriggerStudies_4/TrkJPU1kggFhh4b1.5mm_30mm_32221trk1.5_2GeV_22222GeV_5.root";
//const char *filename2 = "./fastjet_output/TriggerStudies_4/TrkJPU1kMB1.5mm_30mm_32221trk1.5_2GeV_22222GeV_3.root";
const char *filename1 = "./fastjet_output/TriggerStudies_6/TrkJPU1kggFhh4b1.5mm_30mm_11111trk1.5_2GeV_22222GeV_5.root";
const char *filename2 = "./fastjet_output/TriggerStudies_6/TrkJPU1kMB1.5mm_30mm_11111trk1.5_2GeV_22222GeV_3.root";
Double_t MINpT = 2;//GeV
Double_t MAXpT = 100;//GeV
Int_t MINmult = 0; 
Int_t MAXmult = 30;
Int_t pTBIN   = 98;
Int_t npTBIN  = 18;
Float_t xpTBIN[19] = {2.,3.,4.,5.,6.,7.,8.,9.,10.,15.,20.,30.,40.,50.,60.,70.,80.,90.,100.};
Int_t multBIN = 30;

Float_t LEFTMARGIN   = 0.13;
Float_t RIGHTMARGIN  = 0.12;
Float_t TOPMARGIN    = 0.02;
Float_t BOTTOMMARGIN = 0.13;

TCut selectMax    = "abs(PB_tru - PB_maxbin)<=1";
TCut selectMulti1 = "abs(PB_tru - PB1_multibin)<=1";
TCut selectMulti2 = "abs(PB_tru - PB2_multibin)<=1";
TCut selectMulti3 = "abs(PB_tru - PB3_multibin)<=1";
TCut selectMulti4 = "abs(PB_tru - PB4_multibin)<=1";
TCut selectMulti5 = "abs(PB_tru - PB5_multibin)<=1";

TLegend *Leff = nullptr;
Float_t X1 = 0.5, X2 = 0.89, Y1 = 0.89, Y2 = 0.97;
TFile *f1 = nullptr;
TTree *t1 = nullptr;
//! multiplicity of constituent tracks/track-jet
Double_t M_1L;
Double_t M_2L;
Double_t M_3L;
Double_t M_4L;
Double_t M_5L;

Double_t Ma_1L;
Double_t Ma_2L;
Double_t Ma_3L;
Double_t Ma_4L;
Double_t Ma_5L;

//! constituent pT
std::vector<double> *C_1LpT = nullptr;
std::vector<double> *C_2LpT = nullptr;
std::vector<double> *C_3LpT = nullptr;
std::vector<double> *C_4LpT = nullptr;
std::vector<double> *C_5LpT = nullptr;
//! multi-bin
std::vector<double> *Ca_1LpT = nullptr;
std::vector<double> *Ca_2LpT = nullptr;
std::vector<double> *Ca_3LpT = nullptr;
std::vector<double> *Ca_4LpT = nullptr;
std::vector<double> *Ca_5LpT = nullptr;


//! BOOK histograms for control plots
//! 2D hists
TH2D *h_1L1C = nullptr;
TH2D *h_1L2C = nullptr;
TH2D *h_1L3C = nullptr;
TH2D *h_1L4C = nullptr;

TH2D *h_2L1C = nullptr;
TH2D *h_2L2C = nullptr;
TH2D *h_2L3C = nullptr;
TH2D *h_2L4C = nullptr;

TH2D *h_3L1C = nullptr;
TH2D *h_3L2C = nullptr;
TH2D *h_3L3C = nullptr;
TH2D *h_3L4C = nullptr;

TH2D *h_4L1C = nullptr;
TH2D *h_4L2C = nullptr;
TH2D *h_4L3C = nullptr;
TH2D *h_4L4C = nullptr;

TH2D *h_5L1C = nullptr;
TH2D *h_5L2C = nullptr;
TH2D *h_5L3C = nullptr;
TH2D *h_5L4C = nullptr;

TH2D *ha_1L1C = nullptr;
TH2D *ha_1L2C = nullptr;
TH2D *ha_1L3C = nullptr;
TH2D *ha_1L4C = nullptr;

TH2D *ha_2L1C = nullptr;
TH2D *ha_2L2C = nullptr;
TH2D *ha_2L3C = nullptr;
TH2D *ha_2L4C = nullptr;

TH2D *ha_3L1C = nullptr;
TH2D *ha_3L2C = nullptr;
TH2D *ha_3L3C = nullptr;
TH2D *ha_3L4C = nullptr;

TH2D *ha_4L1C = nullptr;
TH2D *ha_4L2C = nullptr;
TH2D *ha_4L3C = nullptr;
TH2D *ha_4L4C = nullptr;

TH2D *ha_5L1C = nullptr;
TH2D *ha_5L2C = nullptr;
TH2D *ha_5L3C = nullptr;
TH2D *ha_5L4C = nullptr;

//! 2nd root file
TFile *f2 = nullptr;
TTree *t2 = nullptr;
//! multiplicity of constituent tracks/track-jet
Double_t MBG_1L;
Double_t MBG_2L;
Double_t MBG_3L;
Double_t MBG_4L;
Double_t MBG_5L;

Double_t MBGa_1L;
Double_t MBGa_2L;
Double_t MBGa_3L;
Double_t MBGa_4L;
Double_t MBGa_5L;

//! constituent pT
std::vector<double> *CBG_1LpT = nullptr;
std::vector<double> *CBG_2LpT = nullptr;
std::vector<double> *CBG_3LpT = nullptr;
std::vector<double> *CBG_4LpT = nullptr;
std::vector<double> *CBG_5LpT = nullptr;
//! multi-bin
std::vector<double> *CBGa_1LpT = nullptr;
std::vector<double> *CBGa_2LpT = nullptr;
std::vector<double> *CBGa_3LpT = nullptr;
std::vector<double> *CBGa_4LpT = nullptr;
std::vector<double> *CBGa_5LpT = nullptr;


//! BOOK histograms for control plots
TH2D *hBG_1L1C = nullptr;
TH2D *hBG_1L2C = nullptr;
TH2D *hBG_1L3C = nullptr;
TH2D *hBG_1L4C = nullptr;

TH2D *hBG_2L1C = nullptr;
TH2D *hBG_2L2C = nullptr;
TH2D *hBG_2L3C = nullptr;
TH2D *hBG_2L4C = nullptr;

TH2D *hBG_3L1C = nullptr;
TH2D *hBG_3L2C = nullptr;
TH2D *hBG_3L3C = nullptr;
TH2D *hBG_3L4C = nullptr;

TH2D *hBG_4L1C = nullptr;
TH2D *hBG_4L2C = nullptr;
TH2D *hBG_4L3C = nullptr;
TH2D *hBG_4L4C = nullptr;

TH2D *hBG_5L1C = nullptr;
TH2D *hBG_5L2C = nullptr;
TH2D *hBG_5L3C = nullptr;
TH2D *hBG_5L4C = nullptr;

TH2D *hBGa_1L1C = nullptr;
TH2D *hBGa_1L2C = nullptr;
TH2D *hBGa_1L3C = nullptr;
TH2D *hBGa_1L4C = nullptr;

TH2D *hBGa_2L1C = nullptr;
TH2D *hBGa_2L2C = nullptr;
TH2D *hBGa_2L3C = nullptr;
TH2D *hBGa_2L4C = nullptr;

TH2D *hBGa_3L1C = nullptr;
TH2D *hBGa_3L2C = nullptr;
TH2D *hBGa_3L3C = nullptr;
TH2D *hBGa_3L4C = nullptr;

TH2D *hBGa_4L1C = nullptr;
TH2D *hBGa_4L2C = nullptr;
TH2D *hBGa_4L3C = nullptr;
TH2D *hBGa_4L4C = nullptr;

TH2D *hBGa_5L1C = nullptr;
TH2D *hBGa_5L2C = nullptr;
TH2D *hBGa_5L3C = nullptr;
TH2D *hBGa_5L4C = nullptr;
