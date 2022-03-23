//! draws a summary plot
//! compare 
//! of trigger efficiency as a function of trigger rate in MHz  
//! for different widths of overlapping z-vertex bins, with and without the endcap discs
//! I) Input files: 
//!    1. TTT-jets with extended barrel (eta 2.5), with z-bin size +-1.5mm 
//!    1. TTT-jets with extended barrel (eta 2.5), with z-bin size +-7.5mm 
//!    1. TTT-jets with endcap discs (eta 2.5), with z-bin size +-1.5mm 
//!    1. TTT-jets with endcap discs (eta 2.5), with z-bin size +-7.5mm 
//! extract the trigger efficiency from PU1000hh4b files and trigger rate from PU1000MB files for a given z-vertex bin to arrays or vectors 
//! read these vectors to draw a graph of trigger_efficiency Vs trigger_rate vs trigger threshold for a given pileup and z-vertex bin

#include <iostream>
#include <fstream>
#include <string>
#include<math.h>

#include "TROOT.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TLegend.h"
#include "TGraphErrors.h"
#include "TPostScript.h"

#include "TAxis.h"
#include "TGaxis.h"
#include "TF1.h"

#include "../../plot_props.h"
#include "summary_common.cpp"
#include "summary_7.5mmTTT.cpp"
#include "summary_1.5mmTTT.cpp"
#include "summary_7.5mmExTTT.cpp"
#include "summary_1.5mmExTTT.cpp"
#include "summary_emuCalo.cpp"


const char* out_path = "../pdf"; 
const char* output_file_name = "TTT_TrigSummarytrk_7.5_1.5_30mm_3067mmETA2.5_11111";
//! clears the txt file
void deleteText(const char* pileup) 
{
    const char* txt_path = "./txt_files";
    char txt_file[1023];
    //sprintf(txt_file,"%s/summary10-100_rmsVspurity_PU%s.txt",txt_path, pileup);
    sprintf(txt_file,"%s/summary_rmsVspurityNo30mm_PU%s.txt",txt_path, pileup);
    std::ofstream ofs;
    ofs.open(txt_file, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}
void SaveCanvas(TCanvas *C, char *name)
{
    const char *path = "../summary_plots";
    char full_name[1023];
    sprintf(full_name,"%s/summary_%s.root", path, name);
    C->SaveAs(full_name);
    sprintf(full_name,"%s/summary_%s.pdf", path, name);
    C->SaveAs(full_name);
    sprintf(full_name,"%s/summary_%s.png", path, name);
    C->SaveAs(full_name);
    sprintf(full_name,"%s/summary_%s.C", path, name);
    C->SaveAs(full_name);

}

void roc(const char *pileup, const char *gapsize)
{
	//! Draw a pre-scalling function of the form rate = 40MHz * trigger efficiency
	TF1 *fun = new TF1("fun","[0]*x*x",0,1);
	fun->SetParameter(0,40);
	//TF2 *fun1= new TF2("fun1","[0]*x-y",0,1,3e-2,40);
	//fun1->SetParameter(0,40);
	//TF12 *fun2 = new TF12("fun2",fun1,3e-2,"x");


	/////////////////////////////////////////////////
	//! Fetch the histograms from input files
	////////////////////////////////////////////////
	const char *file_path = "../../../../from_tachyon/fastjet/fastjet_output/TriggerStudies_6";// extended barrel data
	const char *file_path_1 = "../../fastjet_output/TTT_data";//with endcap data;
	const char *file_path_2 = "../../fastjet_output/calo_data";//with endcap data;

	//sprintf(signal_file_name, "%s/pp_4bQCD/TrkJPU%s7.5mm_Br30mmEC67mm_11111trk2.5_22222GeV_1.root",file_path_1,pileup);//,gapsize);//7.5
	sprintf(signal_file_name, "%s/ggF1.0/TrkJPU%s7.5mm_Br30mmEC67mm_11111trk2.5_22222GeV_1.root",file_path_1,pileup);//,gapsize);//7.5
	std::cout<<"signal file name: " <<signal_file_name <<std::endl;

	//sprintf(MinBias_file_name, "%s/MB_pp4b/TrkJPU%s7.5mm_Br30mmEC67mm_11111trk2.5_22222GeV_1.root",file_path_1,pileup);//,gapsize);//7.5
	sprintf(MinBias_file_name, "%s/MB_1/TrkJPU%s7.5mm_Br30mmEC67mm_11111trk2.5_22222GeV_1.root",file_path_1,pileup);//,gapsize);//7.5
	
	fetch_7_5mmTTT();

        //! write to a text file
	std::cout<<"Writing to txt file...." <<std::endl;
        const char* txt_path = "../txt_files";
        char txt_file[1023];
        sprintf(txt_file,"%s/summary_trackJetROC_PU%s_Br30mmEC67mm_7.5.txt",txt_path, pileup);//,gapsize);
        std::ofstream ofs;
        ofs.open (txt_file, std::ofstream::out | std::ofstream::app);
	//for(int i = 1; i < nbinsE + 1; i++)
	for(int i = 1; i < n + 1; i++)
	{
        	ofs<<E2->GetBinLowEdge(i)<<" "<<E2->GetBinContent(i)<<" " <<R2->GetBinContent(i)<<" "<<E3->GetBinContent(i)<<" "<<R3->GetBinContent(i)<<" "<<E4->GetBinContent(i)<<" "<<R4->GetBinContent(i)<<" "<<E5->GetBinContent(i)<<" "<<R5->GetBinContent(i)<<"\n";

		//std::cout<<"i" << i <<std::endl;
		//! Fill into arrays and plot graph
		pt_threshold[i-1] = R2->GetBinLowEdge(i);
		e2[i-1] = E2->GetBinContent(i);
		r2[i-1] = R2->GetBinContent(i);
		e3[i-1] = E3->GetBinContent(i);
		r3[i-1] = R3->GetBinContent(i);
		e4[i-1] = E4->GetBinContent(i);
		r4[i-1] = R4->GetBinContent(i);
		e5[i-1] = E5->GetBinContent(i);
		r5[i-1] = R5->GetBinContent(i);
		//! Fill into arrays and plot graph
		ea2[i-1] = Ea2->GetBinContent(i);
		ra2[i-1] = Ra2->GetBinContent(i);
		ea3[i-1] = Ea3->GetBinContent(i);
		ra3[i-1] = Ra3->GetBinContent(i);
		ea4[i-1] = Ea4->GetBinContent(i);
		ra4[i-1] = Ra4->GetBinContent(i);
		ea5[i-1] = Ea5->GetBinContent(i);
		ra5[i-1] = Ra5->GetBinContent(i);
		//! Fill into arrays and plot graph
		eb2[i-1] = Eb2->GetBinContent(i);
		rb2[i-1] = Rb2->GetBinContent(i);
		eb3[i-1] = Eb3->GetBinContent(i);
		rb3[i-1] = Rb3->GetBinContent(i);
		eb4[i-1] = Eb4->GetBinContent(i);
		rb4[i-1] = Rb4->GetBinContent(i);
		eb5[i-1] = Eb5->GetBinContent(i);
		rb5[i-1] = Rb5->GetBinContent(i);
		//! bin errors
		e_err2[i-1] = E2->GetBinError(i);
		e_erra2[i-1] = Ea2->GetBinError(i);
		e_errb2[i-1] = Eb2->GetBinError(i);
		e_err3[i-1] = E3->GetBinError(i);
		e_erra3[i-1] = Ea3->GetBinError(i);
		e_errb3[i-1] = Eb3->GetBinError(i);
		e_err4[i-1] = E4->GetBinError(i);
		e_erra4[i-1] = Ea4->GetBinError(i);
		e_errb4[i-1] = Eb4->GetBinError(i);
		e_err5[i-1] = E5->GetBinError(i);
		e_erra5[i-1] = Ea5->GetBinError(i);
		e_errb5[i-1] = Eb5->GetBinError(i);
		//! Fill into arrays and plot graph
		r_err2[i-1] = R2->GetBinError(i);
		r_erra2[i-1] = Ra2->GetBinError(i);
		r_errb2[i-1] = Rb2->GetBinError(i);
		r_err3[i-1] = R3->GetBinError(i);
		r_erra3[i-1] = Ra3->GetBinError(i);
		r_errb3[i-1] = Rb3->GetBinError(i);
		r_err4[i-1] = R4->GetBinError(i);
		r_erra4[i-1] = Ra4->GetBinError(i);
		r_errb4[i-1] = Rb4->GetBinError(i);
		r_err5[i-1] = R5->GetBinError(i);
		r_erra5[i-1] = Ra5->GetBinError(i);
		r_errb5[i-1] = Rb5->GetBinError(i);
	}
        ofs.close();
	
	TCanvas *c1 = new TCanvas();
	
	make_graphs_7_5mmTTT();

//////////////////////////////////////////////////////////////
/////////////// for a different z vertex bin  ////////////////
//////////////////////////////////////////////////////////////

	
	/////////////////////////////////////////////////
	//! Fetch the histograms
	////////////////////////////////////////////////
	//sprintf(signal_file_name_1, "%s/pp_4bQCD/TrkJPU%s1.5mm_Br30mmEC67mm_11111trk2.5_22222GeV_1.root",file_path_1,pileup);//,gapsize);//1.5
	sprintf(signal_file_name_1, "%s/ggF1.0/TrkJPU%s1.5mm_Br30mmEC67mm_11111trk2.5_22222GeV_1.root",file_path_1,pileup);//,gapsize);//1.5

	//sprintf(MinBias_file_name_1, "%s/MB_pp4b/TrkJPU%s1.5mm_Br30mmEC67mm_11111trk2.5_22222GeV_1.root",file_path_1,pileup);//,gapsize);//1.5
	sprintf(MinBias_file_name_1, "%s/MB_1/TrkJPU%s1.5mm_Br30mmEC67mm_11111trk2.5_22222GeV_1.root",file_path_1,pileup);//,gapsize);//1.5
	
	fetch_1_5mmTTT();

	for(int i = 1; i < n + 1; i++)
	{
		
		//! Fill into arrays and plot graph
		e2_[i-1] = E2_->GetBinContent(i);
		r2_[i-1] = R2_->GetBinContent(i);
		e3_[i-1] = E3_->GetBinContent(i);
		r3_[i-1] = R3_->GetBinContent(i);
		e4_[i-1] = E4_->GetBinContent(i);
		r4_[i-1] = R4_->GetBinContent(i);
		e5_[i-1] = E5_->GetBinContent(i);
		r5_[i-1] = R5_->GetBinContent(i);
		//_! Fill into arrays and plot graph
		ea_2[i-1] = Ea_2->GetBinContent(i);
		ra_2[i-1] = Ra_2->GetBinContent(i);
		ea_3[i-1] = Ea_3->GetBinContent(i);
		ra_3[i-1] = Ra_3->GetBinContent(i);
		ea_4[i-1] = Ea_4->GetBinContent(i);
		ra_4[i-1] = Ra_4->GetBinContent(i);
		ea_5[i-1] = Ea_5->GetBinContent(i);
		ra_5[i-1] = Ra_5->GetBinContent(i);
		//_! Fill into_ arrays and plot graph
		eb_2[i-1] = Eb_2->GetBinContent(i);
		rb_2[i-1] = Rb_2->GetBinContent(i);
		eb_3[i-1] = Eb_3->GetBinContent(i);
		rb_3[i-1] = Rb_3->GetBinContent(i);
		eb_4[i-1] = Eb_4->GetBinContent(i);
		rb_4[i-1] = Rb_4->GetBinContent(i);
		eb_5[i-1] = Eb_5->GetBinContent(i);
		rb_5[i-1] = Rb_5->GetBinContent(i);
		
		//! bin error
		e_err2_[i-1] = E2_->GetBinError(i);
		e_erra_2[i-1] = Ea_2->GetBinError(i);
		e_errb_2[i-1] = Eb_2->GetBinError(i);
		e_err3_[i-1] = E3_->GetBinError(i);
		e_erra_3[i-1] = Ea_3->GetBinError(i);
		e_errb_3[i-1] = Eb_3->GetBinError(i);
		e_err4_[i-1] = E4_->GetBinError(i);
		e_erra_4[i-1] = Ea_4->GetBinError(i);
		e_errb_4[i-1] = Eb_4->GetBinError(i);
		e_err5_[i-1] = E5_->GetBinError(i);
		e_erra_5[i-1] = Ea_5->GetBinError(i);
		e_errb_5[i-1] = Eb_5->GetBinError(i);
		//_! Fill into arrays and plot graph
		r_err2_[i-1] = R2_->GetBinError(i);
		r_erra_2[i-1] = Ra_2->GetBinError(i);
		r_errb_2[i-1] = Rb_2->GetBinError(i);
		r_err3_[i-1] = R3_->GetBinError(i);
		r_erra_3[i-1] = Ra_3->GetBinError(i);
		r_errb_3[i-1] = Rb_3->GetBinError(i);
		r_err4_[i-1] = R4_->GetBinError(i);
		r_erra_4[i-1] = Ra_4->GetBinError(i);
		r_errb_4[i-1] = Rb_4->GetBinError(i);
		r_err5_[i-1] = R5_->GetBinError(i);
		r_erra_5[i-1] = Ra_5->GetBinError(i);
		r_errb_5[i-1] = Rb_5->GetBinError(i);
	}
	
	make_graphs_1_5mmTTT();

///////////////////////////////////////////////////////////
//      Extendend barrel
///////////////////////////////////////////////////////////     
	sprintf(signal_file_name_2, "%s/ExggF1.0/TrkJPU%sggFhh4b7.5mm_30mm_11111trk2.5_2GeV_22222GeV_5.root",file_path_1,pileup);//,gapsize);//7.5
	//sprintf(signal_file_name_2, "%s/ggF1.0/TrkJPU%s7.5mm_Br30mmEC67mm_11111trk2.5_22222GeV_1.root",file_path_1,pileup);//,gapsize);//7.5
	//sprintf(signal_file_name_2, "%s/TrkJPU%sggFhh4b7.5mm_30mm_43221trk2.5_2GeV_33333GeV_5.root",file_path,pileup);//,gapsize);//7.5
	std::cout<<"signal file name: " <<signal_file_name <<std::endl;
 
	sprintf(MinBias_file_name_2, "%s/ExMB_1/TrkJPU%sMB7.5mm_30mm_11111trk2.5_2GeV_22222GeV_3.root",file_path_1,pileup);//,gapsize);//7.5
	//sprintf(MinBias_file_name_2, "%s/MB_1/TrkJPU%s7.5mm_Br30mmEC67mm_11111trk2.5_22222GeV_1.root",file_path_1,pileup);//,gapsize);//7.5
	//sprintf(MinBias_file_name_2, "%s/TrkJPU%sMB7.5mm_30mm_43221trk2.5_2GeV_33333GeV_3.root",file_path,pileup);//,gapsize);//7.5

	fetch_7_5mmExTTT();

	for(int i = 1; i < n + 1; i++)
	{

		//! Fill into arrays and plot graph
		Exe2[i-1] = ExE2->GetBinContent(i);
		Exr2[i-1] = ExR2->GetBinContent(i);
		Exe3[i-1] = ExE3->GetBinContent(i);
		Exr3[i-1] = ExR3->GetBinContent(i);
		Exe4[i-1] = ExE4->GetBinContent(i);
		Exr4[i-1] = ExR4->GetBinContent(i);
		Exe5[i-1] = ExE5->GetBinContent(i);
		Exr5[i-1] = ExR5->GetBinContent(i);
		//! Fill into arrays and plot graph
		Exea2[i-1] = ExEa2->GetBinContent(i);
		Exra2[i-1] = ExRa2->GetBinContent(i);
		Exea3[i-1] = ExEa3->GetBinContent(i);
		Exra3[i-1] = ExRa3->GetBinContent(i);
		Exea4[i-1] = ExEa4->GetBinContent(i);
		Exra4[i-1] = ExRa4->GetBinContent(i);
		Exea5[i-1] = ExEa5->GetBinContent(i);
		Exra5[i-1] = ExRa5->GetBinContent(i);
		//! Fill into arrays and plot graph
		Exeb2[i-1] = ExEb2->GetBinContent(i);
		Exrb2[i-1] = ExRb2->GetBinContent(i);
		Exeb3[i-1] = ExEb3->GetBinContent(i);
		Exrb3[i-1] = ExRb3->GetBinContent(i);
		Exeb4[i-1] = ExEb4->GetBinContent(i);
		Exrb4[i-1] = ExRb4->GetBinContent(i);
		Exeb5[i-1] = ExEb5->GetBinContent(i);
		Exrb5[i-1] = ExRb5->GetBinContent(i);
		//! bin errors
		Exe_err2[i-1]  = ExE2->GetBinError(i);
		Exe_erra2[i-1] = ExEa2->GetBinError(i);
		Exe_errb2[i-1] = ExEb2->GetBinError(i);
		Exe_err3[i-1]  = ExE3->GetBinError(i);
		Exe_erra3[i-1] = ExEa3->GetBinError(i);
		Exe_errb3[i-1] = ExEb3->GetBinError(i);
		Exe_err4[i-1]  = ExE4->GetBinError(i);
		Exe_erra4[i-1] = ExEa4->GetBinError(i);
		Exe_errb4[i-1] = ExEb4->GetBinError(i);
		Exe_err5[i-1]  = ExE5->GetBinError(i);
		Exe_erra5[i-1] = ExEa5->GetBinError(i);
		Exe_errb5[i-1] = ExEb5->GetBinError(i);
		//! Fill into arrays and plot graph
		Exr_err2[i-1]  = ExR2->GetBinError(i);
		Exr_erra2[i-1] = ExRa2->GetBinError(i);
		Exr_errb2[i-1] = ExRb2->GetBinError(i);
		Exr_err3[i-1]  = ExR3->GetBinError(i);
		Exr_erra3[i-1] = ExRa3->GetBinError(i);
		Exr_errb3[i-1] = ExRb3->GetBinError(i);
		Exr_err4[i-1]  = ExR4->GetBinError(i);
		Exr_erra4[i-1] = ExRa4->GetBinError(i);
		Exr_errb4[i-1] = ExRb4->GetBinError(i);
		Exr_err5[i-1]  = ExR5->GetBinError(i);
		Exr_erra5[i-1] = ExRa5->GetBinError(i);
		Exr_errb5[i-1] = ExRb5->GetBinError(i);
	}
	
	make_graphs_7_5mmExTTT();

	
	//sprintf(signal_file_name_3, "%s/TrkJPU%sggFhh4b1.5mm_30mm_43221trk2.5_2GeV_33333GeV_5.root",file_path,pileup);//,gapsize);//1.5
	sprintf(signal_file_name_3, "%s/ExggF1.0/TrkJPU%sggFhh4b1.5mm_30mm_11111trk2.5_2GeV_22222GeV_5.root",file_path_1,pileup);//,gapsize);//1.5
	//sprintf(signal_file_name_3, "%s/ggF1.0/TrkJPU%s1.5mm_Br30mmEC67mm_11111trk2.5_22222GeV_1.root",file_path_1,pileup);//,gapsize);//1.5
	std::cout<<"signal file name: " <<signal_file_name <<std::endl;

	sprintf(MinBias_file_name_3, "%s/ExMB_1/TrkJPU%sMB1.5mm_30mm_11111trk2.5_2GeV_22222GeV_3.root",file_path_1,pileup);//,gapsize);//1.5
	//sprintf(MinBias_file_name_3, "%s/MB_1/TrkJPU%s1.5mm_Br30mmEC67mm_11111trk2.5_22222GeV_1.root",file_path_1,pileup);//,gapsize);//1.5
	//sprintf(MinBias_file_name_3, "%s/TrkJPU%sMB1.5mm_30mm_43221trk2.5_2GeV_33333GeV_3.root",file_path,pileup);//,gapsize);//1.5

	fetch_1_5mmExTTT();
	
	for(int i = 1; i < n + 1; i++)
	{
		
		//! Fill into arrays and plot graph
		Exe2_[i-1] =  ExE2_->GetBinContent(i);
		Exr2_[i-1] =  ExR2_->GetBinContent(i);
		Exe3_[i-1] =  ExE3_->GetBinContent(i);
		Exr3_[i-1] =  ExR3_->GetBinContent(i);
		Exe4_[i-1] =  ExE4_->GetBinContent(i);
		Exr4_[i-1] =  ExR4_->GetBinContent(i);
		Exe5_[i-1] =  ExE5_->GetBinContent(i);
		Exr5_[i-1] =  ExR5_->GetBinContent(i);
		//_! Fill into arrays and plot graph
		Exea_2[i-1] = ExEa_2->GetBinContent(i);
		Exra_2[i-1] = ExRa_2->GetBinContent(i);
		Exea_3[i-1] = ExEa_3->GetBinContent(i);
		Exra_3[i-1] = ExRa_3->GetBinContent(i);
		Exea_4[i-1] = ExEa_4->GetBinContent(i);
		Exra_4[i-1] = ExRa_4->GetBinContent(i);
		Exea_5[i-1] = ExEa_5->GetBinContent(i);
		Exra_5[i-1] = ExRa_5->GetBinContent(i);
		//_! Fill into_ arrays and plot graph
		Exeb_2[i-1] = ExEb_2->GetBinContent(i);
		Exrb_2[i-1] = ExRb_2->GetBinContent(i);
		Exeb_3[i-1] = ExEb_3->GetBinContent(i);
		Exrb_3[i-1] = ExRb_3->GetBinContent(i);
		Exeb_4[i-1] = ExEb_4->GetBinContent(i);
		Exrb_4[i-1] = ExRb_4->GetBinContent(i);
		Exeb_5[i-1] = ExEb_5->GetBinContent(i);
		Exrb_5[i-1] = ExRb_5->GetBinContent(i);
		
		//! bin error
		Exe_err2_[i-1]  = ExE2_->GetBinError(i);
		Exe_erra_2[i-1] = ExEa_2->GetBinError(i);
		Exe_errb_2[i-1] = ExEb_2->GetBinError(i);
		Exe_err3_[i-1]  = ExE3_->GetBinError(i);
		Exe_erra_3[i-1] = ExEa_3->GetBinError(i);
		Exe_errb_3[i-1] = ExEb_3->GetBinError(i);
		Exe_err4_[i-1]  = ExE4_->GetBinError(i);
		Exe_erra_4[i-1] = ExEa_4->GetBinError(i);
		Exe_errb_4[i-1] = ExEb_4->GetBinError(i);
		Exe_err5_[i-1]  = ExE5_->GetBinError(i);
		Exe_erra_5[i-1] = ExEa_5->GetBinError(i);
		Exe_errb_5[i-1] = ExEb_5->GetBinError(i);
		//_! Fill into arrays and plot graph
		Exr_err2_[i-1]  = ExR2_->GetBinError(i);
		Exr_erra_2[i-1] = ExRa_2->GetBinError(i);
		Exr_errb_2[i-1] = ExRb_2->GetBinError(i);
		Exr_err3_[i-1]  = ExR3_->GetBinError(i);
		Exr_erra_3[i-1] = ExRa_3->GetBinError(i);
		Exr_errb_3[i-1] = ExRb_3->GetBinError(i);
		Exr_err4_[i-1]  = ExR4_->GetBinError(i);
		Exr_erra_4[i-1] = ExRa_4->GetBinError(i);
		Exr_errb_4[i-1] = ExRb_4->GetBinError(i);
		Exr_err5_[i-1]  = ExR5_->GetBinError(i);
		Exr_erra_5[i-1] = ExRa_5->GetBinError(i);
		Exr_errb_5[i-1] = ExRb_5->GetBinError(i);
	}
	
	make_graphs_1_5mmExTTT();
/////////////////////////////////////////////////////////////////////////////////////////////
//                               For emulated calo jets
/////////////////////////////////////////////////////////////////////////////////////////////
	//sprintf(signal_file_calo, "%s/EMU5GeV_PrimB0ALLa50c3_PU%sggFhh4b1.0_q1.2GeVeta2.5_%smmR0.4_4_test_2.root",file_path,pileup,gapsize);
	sprintf(signal_file_calo, "%s/CELL_a50c3_ALL_PU%sggF_ETA2.5_%smm_R0.4_2.root",file_path_2,pileup,gapsize);

	//sprintf(MinBias_file_calo, "%s/EMU5GeV_PrimB0ALLa50c3_PU%sMB_q1.2GeVeta2.5_%smmR0.4_4_test_2.root",file_path,pileup,gapsize);
	sprintf(MinBias_file_calo, "%s/CELL_a50c3_ALL_PU%sMB_ETA2.5_%smm_R0.4_2.root",file_path_2,pileup,gapsize);

	fetch_emuCalo();

	for(int i = 1; i < n + 1; i++)
	{
		
		//_! Fill into_ arrays and plot graph
		eb__2[i-1] = Ebcalo2->GetBinContent(i);
		rb__2[i-1] = Rbcalo2->GetBinContent(i);
		eb__3[i-1] = Ebcalo3->GetBinContent(i);
		rb__3[i-1] = Rbcalo3->GetBinContent(i);
		eb__4[i-1] = Ebcalo4->GetBinContent(i);
		rb__4[i-1] = Rbcalo4->GetBinContent(i);
		eb__5[i-1] = Ebcalo5->GetBinContent(i);
		rb__5[i-1] = Rbcalo5->GetBinContent(i);
		//_! Fill into_ arrays and plot graph
		e_errb__2[i-1] = Ebcalo2->GetBinError(i);
		e_errb__3[i-1] = Ebcalo3->GetBinError(i);
		e_errb__4[i-1] = Ebcalo4->GetBinError(i);
		e_errb__5[i-1] = Ebcalo5->GetBinError(i);
		
		r_errb__2[i-1] = Rbcalo2->GetBinError(i);
		r_errb__3[i-1] = Rbcalo3->GetBinError(i);
		r_errb__4[i-1] = Rbcalo4->GetBinError(i);
		r_errb__5[i-1] = Rbcalo5->GetBinError(i);
	}

	make_graphs_emuCalo();
	
/////////////////////////////////////////////////////////////
///                    2D graphs
/////////////////////////////////////////////////////////////
	TCanvas *c_ = new TCanvas();
	
	graph2D_7_5mm_multibin();
	graph2D_1_5mm_multibin();
	
	graph2D_7_5mm_maxbin();
	graph2D_1_5mm_maxbin();

	graph2D_7_5mm_Exmultibin();
	graph2D_1_5mm_Exmultibin();
	
	graph2D_7_5mm_Exmaxbin();
	graph2D_1_5mm_Exmaxbin();

	graph2D_nozbin();

	graph2D_emuCalo();

///////////////////////////////////////////////////////////////////////
//////////////// writing to pdf ///////////////////////////////////////
///////////////////////////////////////////////////////////////////////
	char out_file_open[1023];
        sprintf(out_file_open,"%s/%s.pdf(",out_path,output_file_name);
        char out_file_[1023];
        sprintf(out_file_,"%s/%s.pdf",out_path,output_file_name);
        char out_file_close[1023];
        sprintf(out_file_close,"%s/%s.pdf)",out_path,output_file_name);
	
	char out_root_file[1023];
	sprintf(out_root_file, "%s/%s.root",out_path,output_file_name);


	//Double_t x1 = 0.5, y1 = 0.11, x2 = 0.89, y2 = 0.39;
	Double_t x1 = 0.49, y1 = 0.11, x2 = 0.95, y2 = 0.32;
	//Double_t x1 = 0.01, y1 = 0.8, x2 = 0.49, y2 = 0.99;
	//TCanvas * C = new TCanvas();
	Legends();
	TCanvas * C = new TCanvas("C","C",800,800);
	//TCanvas * C = new TCanvas("C","C",1000,800);
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);
	TGaxis::SetMaxDigits(3);
	gPad->SetRightMargin(0.04);
	C->SetGridx();
	C->SetGridy();
	//C->SetTickx();
	//C->SetTicky();
	C->SetLogy();
	//C->Divide(2,2,0.5, 0.5);
	//! page1
	//! +-7.5mm 	
	C->cd(1);
	//gPad->SetGrid();
	gPad->SetLogy();
	g1->GetXaxis()->CenterTitle();
	g1->GetYaxis()->CenterTitle();
	g1->GetXaxis()->SetTitleSize(0.04);
	g1->GetYaxis()->SetTitleSize(0.04);
	g1->Draw("APe1");	//max-bin track-jet
	ga1->Draw("Pe1");       //multi-bin track-jet
	gb1->Draw("Pe1");       //unbinned track-jet
	gb_1_->Draw("Pe1");     //emulated calo track-jet
	g1->SetTitle("2^{nd} leading p_{t} track-jet");
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	TLegend *l1 = new TLegend(x1, y1, x2, y2, "");
	l1->SetBorderSize(0);
	l1->SetFillColor(kWhite);
	l1->SetTextSize(0.04);
	l1->SetHeader("2^{nd} leading","C");
	l1->AddEntry(g1,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 7.5 mm", "p");
	l1->AddEntry(ga1,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 7.5 mm","p");
	l1->AddEntry(gb1,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
	l1->AddEntry(gb_1_,"#kern[-3.0]{ } emulated calo-jet","p");
	l1->SetTextAlign(12);
	l1->SetMargin(0.15);
	l1->Draw();
	leg1->Draw();
	leg5->Draw();
	fun->Draw("same");
	gPad->Update();
	//gPad->Write("c1a");
	C->Print(out_file_open,"pdf");
	C->SaveAs("../tex/C1_30mm_7515mm_2trk.tex");

	//! page2
	C->cd(2);
	//gPad->SetGrid();
	gPad->SetLogy();
	g2->GetXaxis()->CenterTitle();
	g2->GetYaxis()->CenterTitle();
	g2->GetXaxis()->SetTitleSize(0.04);
	g2->GetYaxis()->SetTitleSize(0.04);
	g2->Draw("APe1");	//max-bin track-jet
	ga2->Draw("Pe1");       //multi-bin track-jet
	gb2->Draw("Pe1");       //unbinned track-jet
	gb_2_->Draw("Pe1");     //emulated calo track-jet
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	g2->SetTitle("3^{rd} leading p_{t} track-jet");
	TLegend *l2 = new TLegend(x1, y1, x2, y2, "");
	l2->SetBorderSize(0);
	l2->SetFillColor(kWhite);
	l2->SetTextSize(0.04);
	l2->SetHeader("3^{rd} leading","C");
	l2->AddEntry(g2,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 7.5 mm","p");
	l2->AddEntry(ga2,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 7.5 mm","p");
	l2->AddEntry(gb2,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
	l2->AddEntry(gb_2_,"#kern[-3.0]{ } emulated calo-jet","p");
	l2->SetTextAlign(12);
	l2->SetMargin(0.15);
	l2->Draw();
	leg1->Draw();
	leg5->Draw();
	fun->Draw("same");
	gPad->Update();
	//gPad->Write("c1b");
	C->Print(out_file_,"pdf");
	C->SaveAs("../tex/C2_30mm_7515mm_2trk.tex");

	//! page3
	C->cd(3);
	//gPad->SetGrid();
	gPad->SetLogy();
	g3->GetXaxis()->CenterTitle();
	g3->GetYaxis()->CenterTitle();
	g3->GetXaxis()->SetTitleSize(0.04);
	g3->GetYaxis()->SetTitleSize(0.04);
	g3->Draw("APe1");	//max-bin track-jet
	ga3->Draw("Pe1");       //multi-bin track-jet
	gb3->Draw("Pe1");       //unbinned track-jet
	gb_3_->Draw("Pe1");     //emulated calo track-jet
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	g3->SetTitle("4^{th} leading p_{t} track-jet");
	TLegend *l3 = new TLegend(x1, y1, x2, y2, "");
	l3->SetBorderSize(0);
	l3->SetFillColor(kWhite);
	l3->SetTextSize(0.04);
	l3->SetHeader("4^{th} leading","C");
	l3->AddEntry(g3,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 7.5 mm","p");
	l3->AddEntry(ga3,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 7.5 mm","p");
	l3->AddEntry(gb3,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
	l3->AddEntry(gb_3_,"#kern[-3.0]{ } emulated calo-jet","p");
	l3->SetTextAlign(12);
	l3->SetMargin(0.15);
	l3->Draw();
	leg1->Draw();
	leg5->Draw();
	fun->Draw("same");
	gPad->Update();
	//gPad->Write("c1c");
	C->Print(out_file_,"pdf");
	C->SaveAs("../tex/C3_30mm_7515mm_2trk.tex");

	//! page4
	C->cd(4);
	//gPad->SetGrid();
	gPad->SetLogy();
	g4->GetXaxis()->CenterTitle();
	g4->GetYaxis()->CenterTitle();
	g4->GetXaxis()->SetTitleSize(0.04);
	g4->GetYaxis()->SetTitleSize(0.04);
	g4->Draw("APe1");	//max-bin track-jet
	ga4->Draw("Pe1");	//multi-bin track-jet
	gb4->Draw("Pe1");	//unbinned track-jet
	gb_4_->Draw("Pe1");	//emulated calo track-jet
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	g4->SetTitle("5^{th} leading p_{t} track-jet");
	TLegend *l4 = new TLegend(x1, y1, x2, y2, "");
	l4->SetBorderSize(0);
	l4->SetFillColor(kWhite);
	l4->SetTextSize(0.04);
	l4->SetHeader("5^{th} leading","C");
	l4->AddEntry(g4,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 7.5 mm","p");
	l4->AddEntry(ga4,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 7.5 mm","p");
	l4->AddEntry(gb4,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
	l4->AddEntry(gb_4_,"#kern[-3.0]{ } emulated calo-jet","p");
	l4->SetTextAlign(12);
	l4->SetMargin(0.15);
	l4->Draw();
	leg1->Draw();
	leg5->Draw();
	fun->Draw("same");
	gPad->Update();
	//gPad->Write("c1d");
	C->Print(out_file_,"pdf");
	C->SaveAs("../tex/C4_30mm_7515mm_2trk.tex");

	//! page5
	//! page2
	//! +-1.5mm 	
	C->cd(1);
	//gPad->SetGrid();
	gPad->SetLogy();
	g1_->GetXaxis()->CenterTitle();
	g1_->GetYaxis()->CenterTitle();
	g1_->GetXaxis()->SetTitleSize(0.04);
	g1_->GetYaxis()->SetTitleSize(0.04);
	g1_->Draw("APe1");	//max-bin track-jet
	ga1_->Draw("Pe1");       //multi-bin track-jet
	gb1_->Draw("Pe1");       //unbinned track-jet
	gb_1_->Draw("Pe1");     //emulated calo track-jet
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	g1_->SetTitle("2^{nd} leading p_{t} track-jet");
	TLegend *l1_ = new TLegend(x1, y1, x2, y2, "");
	l1_->SetBorderSize(0);
	l1_->SetFillColor(kWhite);
	l1_->SetTextSize(0.04);
	l1_->SetHeader("2^{nd} leading","C");
	l1_->AddEntry(g1_,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 1.5mm", "p");
	l1_->AddEntry(ga1_,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 1.5mm","p");
	l1_->AddEntry(gb1_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
	l1_->AddEntry(gb_1_,"#kern[-3.0]{ } emulated calo-jet","p");
	l1_->SetTextAlign(12);
	l1_->SetMargin(0.15);
	l1_->Draw();
	leg1->Draw();
	leg5->Draw();
	fun->Draw("same");
	gPad->Update();
	//gPad->Write("c2a");
	C->Print(out_file_,"pdf");
	C->SaveAs("../tex/C5_30mm_7515mm_2trk.tex");

	//! page6
	C->cd(2);
	//gPad->SetGrid();
	gPad->SetLogy();
	g2_->GetXaxis()->CenterTitle();
	g2_->GetYaxis()->CenterTitle();
	g2_->GetXaxis()->SetTitleSize(0.04);
	g2_->GetYaxis()->SetTitleSize(0.04);
	g2_->Draw("APe1");	//max-bin track-jet
	ga2_->Draw("Pe1");       //multi-bin track-jet
	gb2_->Draw("Pe1");       //unbinned track-jet
	gb_2_->Draw("Pe1");     //emulated calo track-jet
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	g2_->SetTitle("3^{rd} leading p_{t} track-jet");
	TLegend *l2_ = new TLegend(x1, y1, x2, y2, "");
	l2_->SetBorderSize(0);
	l2_->SetFillColor(kWhite);
	l2_->SetTextSize(0.04);
	l2_->SetHeader("3^{rd} leading","C");
	l2_->AddEntry(g2_,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 1.5mm", "p");
	l2_->AddEntry(ga2_,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 1.5mm","p");
	l2_->AddEntry(gb2_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
	l2_->AddEntry(gb_2_,"#kern[-3.0]{ } emulated calo-jet","p");
	l2_->SetTextAlign(12);
	l2_->SetMargin(0.15);
	l2_->Draw();
	leg1->Draw();
	leg5->Draw();
	fun->Draw("same");
	gPad->Update();
	//gPad->Write("c2b");
	C->Print(out_file_,"pdf");
	C->SaveAs("../tex/C6_30mm_7515mm_2trk.tex");

	//! page7
	C->cd(3);
	//gPad->SetGrid();
	gPad->SetLogy();
	g3_->GetXaxis()->CenterTitle();
	g3_->GetYaxis()->CenterTitle();
	g3_->GetXaxis()->SetTitleSize(0.04);
	g3_->GetYaxis()->SetTitleSize(0.04);
	g3_->Draw("APe1");	//max-bin track-jet
	ga3_->Draw("Pe1");       //multi-bin track-jet
	gb3_->Draw("Pe1");       //unbinned track-jet
	gb_3_->Draw("Pe1");     //emulated calo track-jet
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	g3_->SetTitle("4^{th} leading p_{t} track-jet");
	y1 = 0.49; y2 = 0.7;
	TLegend *l3_ = new TLegend(x1, y1, x2, y2, "");
	l3_->SetBorderSize(0);
	l3_->SetFillColor(kWhite);
	l3_->SetTextSize(0.04);
	l3_->SetHeader("4^{th} leading","C");
	l3_->AddEntry(g3_,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 1.5mm", "p");
	l3_->AddEntry(ga3_,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 1.5mm","p");
	l3_->AddEntry(gb3_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
	l3_->AddEntry(gb_3_,"#kern[-3.0]{ } emulated calo-jet","p");
	l3_->SetTextAlign(12);
	l3_->SetMargin(0.15);
	l3_->Draw();
	leg1->Draw();
	leg5->Draw();
	fun->Draw("same");
	gPad->Update();
	//gPad->Write("c2c");
	C->Print(out_file_,"pdf");
	C->SaveAs("../tex/C7_30mm_7515mm_2trk.tex");

	//! page8
	C->cd(4);
	//gPad->SetGrid();
	gPad->SetLogy();
	g4_->GetXaxis()->CenterTitle();
	g4_->GetYaxis()->CenterTitle();
	g4_->GetXaxis()->SetTitleSize(0.04);
	g4_->GetYaxis()->SetTitleSize(0.04);
	g4_->Draw("APe1");	//max-bin track-jet
	ga4_->Draw("Pe1");	//multi-bin track-jet
	gb4_->Draw("Pe1");	//unbinned track-jet
	gb_4_->Draw("Pe1");	//emulated calo track-jet
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	g4_->SetTitle("5^{th} leading p_{t} track-jet");
	TLegend *l4_ = new TLegend(x1, y1, x2, y2, "");
	l4_->SetBorderSize(0);
	l4_->SetFillColor(kWhite);
	l4_->SetTextSize(0.04);
	l4_->SetHeader("5^{th} leading","C");
	l4_->AddEntry(g4_,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 1.5mm", "p");
	l4_->AddEntry(ga4_,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 1.5mm","p");
	l4_->AddEntry(gb4_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
	l4_->AddEntry(gb_4_,"#kern[-3.0]{ } emulated calo-jet","p");
	l4_->SetTextAlign(12);
	l4_->SetMargin(0.15);
	l4_->Draw();
	leg1->Draw();
	leg5->Draw();
	fun->Draw("same");
	gPad->Update();
	//gPad->Write("c2d");
	C->Print(out_file_,"pdf");
	C->SaveAs("../tex/C8_30mm_7515mm_2trk.tex");


	//! page9
	//! page3
	y1 = 0.11; y2 = 0.32;
	//! +-7.5, +-1.5mm multi-bin	
	C->cd(1);
	//gPad->SetGrid();
	gPad->SetLogy();
	ga1->GetXaxis()->CenterTitle();
	ga1->GetYaxis()->CenterTitle();
	ga1->GetXaxis()->SetTitleSize(0.04);
	ga1->GetYaxis()->SetTitleSize(0.04);
	ga1->Draw("APe1");	//multi-bin 7.5  track-jet
	ga1_->Draw("Pe1");       //multi-bin 3.75 track-jet
	gb1_->Draw("Pe1");       //unbinned track-jet
	gb_1_->Draw("Pe1");     //emulated calo track-jet
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	g1_->SetTitle("2^{nd} leading p_{t} track-jet");
	TLegend *l1__ = new TLegend(x1, y1, x2, y2, "");
	l1__->SetBorderSize(0);
	l1__->SetFillColor(kWhite);
	l1__->SetTextSize(0.04);
	l1__->SetHeader("2^{nd} leading","C");
	l1__->AddEntry(ga1_,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 1.5mm","p");
	l1__->AddEntry(ga1,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 7.5 mm", "p");
	l1__->AddEntry(gb1_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
	l1__->AddEntry(gb_1_,"#kern[-3.0]{ } emulated calo-jet","p");
	l1__->SetTextAlign(12);
	l1__->SetMargin(0.15);
	l1__->Draw();
	leg1->Draw();
	leg5->Draw();
	fun->Draw("same");
	gPad->Update();
	//gPad->Write("c3a");
	C->Print(out_file_,"pdf");
	C->SaveAs("../tex/C9_30mm_7515mm_2trk.tex");

	//! page10
	C->cd(2);
	//gPad->SetGrid();
	gPad->SetLogy();
	ga2->GetXaxis()->CenterTitle();
	ga2->GetYaxis()->CenterTitle();
	ga2->GetXaxis()->SetTitleSize(0.04);
	ga2->GetYaxis()->SetTitleSize(0.04);
	ga2->Draw("APe1");	//multi-bin 7.5  track-jet
	ga2_->Draw("Pe1");       //multi-bin 3.75 track-jet
	gb2_->Draw("Pe1");       //unbinned track-jet
	gb_2_->Draw("Pe1");     //emulated calo track-jet
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	g2_->SetTitle("3^{rd} leading p_{t} track-jet");
	TLegend *l2__ = new TLegend(x1, y1, x2, y2, "");
	l2__->SetBorderSize(0);
	l2__->SetFillColor(kWhite);
	l2__->SetTextSize(0.04);
	l2__->SetHeader("3^{rd} leading","C");
	l2__->AddEntry(ga2_,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 1.5mm","p");
	l2__->AddEntry(ga2,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 7.5 mm", "p");
	l2__->AddEntry(gb2_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
	l2__->AddEntry(gb_2_,"#kern[-3.0]{ } emulated calo-jet","p");
	l2__->SetTextAlign(12);
	l2__->SetMargin(0.15);
	l2__->Draw();
	leg1->Draw();
	leg5->Draw();
	fun->Draw("same");
	gPad->Update();
	//gPad->Write("c3b");
	C->Print(out_file_,"pdf");
	C->SaveAs("../tex/C10_30mm_7515mm_2trk.tex");

	//! page11
	C->cd(3);
	//gPad->SetGrid();
	gPad->SetLogy();
	ga3->GetXaxis()->CenterTitle();
	ga3->GetYaxis()->CenterTitle();
	ga3->GetXaxis()->SetTitleSize(0.04);
	ga3->GetYaxis()->SetTitleSize(0.04);
	ga3->Draw("APe1");	//multi-bin 7.5 track-jet
	ga3_->Draw("Pe1");       //multi-bin 3.75 track-jet
	gb3_->Draw("Pe1");       //unbinned track-jet
	gb_3_->Draw("Pe1");     //emulated calo track-jet
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	g3_->SetTitle("4^{th} leading p_{t} track-jet");
	y1 = 0.45; y2 = 0.66;
	TLegend *l3__ = new TLegend(x1, y1, x2, y2, "");
	l3__->SetBorderSize(0);
	l3__->SetFillColor(kWhite);
	l3__->SetTextSize(0.04);
	l3__->SetHeader("4^{th} leading","C");
	l3__->AddEntry(ga3_,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 1.5mm","p");
	l3__->AddEntry(ga3,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 7.5 mm", "p");
	l3__->AddEntry(gb3_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
	l3__->AddEntry(gb_3_,"#kern[-3.0]{ } emulated calo-jet","p");
	l3__->SetTextAlign(12);
	l3__->SetMargin(0.15);
	l3__->Draw();
	leg1->Draw();
	leg5->Draw();
	fun->Draw("same");
	gPad->Update();
	//gPad->Write("c3c");
	C->Print(out_file_,"pdf");
	C->SaveAs("../tex/C11_30mm_7515mm_2trk.tex");

	//! page12
	C->cd(4);
	//gPad->SetGrid();
	gPad->SetLogy();
	ga4->GetXaxis()->CenterTitle();
	ga4->GetYaxis()->CenterTitle();
	ga4->GetXaxis()->SetTitleSize(0.04);
	ga4->GetYaxis()->SetTitleSize(0.04);
	ga4->Draw("APe1");	//multi-bin 7.5 track-jet
	ga4_->Draw("Pe1");	//multi-bin 3.75 track-jet
	gb4_->Draw("Pe1");	//unbinned track-jet
	gb_4_->Draw("Pe1");	//emulated calo track-jet
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	g4_->SetTitle("5^{th} leading p_{t} track-jet");
	y1 = 0.35; y2 = 0.56;
	TLegend *l4__ = new TLegend(x1, y1, x2, y2, "");
	l4__->SetBorderSize(0);
	l4__->SetFillColor(kWhite);
	l4__->SetTextSize(0.04);
	l4__->SetHeader("5^{th} leading","C");
	l4__->AddEntry(ga4_,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 1.5mm","p");
	l4__->AddEntry(ga4,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 7.5 mm", "p");
	l4__->AddEntry(gb4_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
	l4__->AddEntry(gb_4_,"#kern[-3.0]{ } emulated calo-jet","p");
	l4__->SetTextAlign(12);
	l4__->SetMargin(0.15);
	l4__->Draw();
	leg1->Draw();
	leg5->Draw();
	fun->Draw("same");
	gPad->Update();
	//gPad->Write("c3d");
	C->Print(out_file_,"pdf");
	C->SaveAs("../tex/C12_30mm_7515mm_2trk.tex");

	//! page13
	//! page4
	//! +-7.5, +-1.5mm max-bin
	C->cd(1);
	//gPad->SetGrid();
	gPad->SetLogy();
	g1->Draw("APe1");	//max-bin 7.5  track-jet
	g1_->Draw("Pe1");       //max-bin 3.75 track-jet
	gb1_->Draw("Pe1");       //unbinned track-jet
	gb_1_->Draw("Pe1");     //emulated calo track-jet
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	g1_->SetTitle("2^{nd} leading p_{t} track-jet");
	y1 = 0.11; y2 = 0.32;
	TLegend *l_1__ = new TLegend(x1, y1, x2, y2, "");
	l_1__->SetBorderSize(0);
	l_1__->SetFillColor(kWhite);
	l_1__->SetTextSize(0.04);
	l_1__->SetHeader("2^{nd} leading","C");
	l_1__->AddEntry(g1_,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 1.5mm","p");
	l_1__->AddEntry(g1,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 7.5 mm", "p");
	l_1__->AddEntry(gb1_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
	l_1__->AddEntry(gb_1_,"#kern[-3.0]{ } emulated calo-jet","p");
	l_1__->SetTextAlign(12);
	l_1__->SetMargin(0.15);
	l_1__->Draw();
	leg1->Draw();
	leg5->Draw();
	fun->Draw("same");
	gPad->Update();
	//gPad->Write("c4a");
	C->Print(out_file_,"pdf");
	C->SaveAs("../tex/C13_30mm_7515mm_2trk.tex");

	//! page14
	C->cd(2);
	//gPad->SetGrid();
	gPad->SetLogy();
	g2->Draw("APe1");	//max-bin 7.5  track-jet
	g2_->Draw("Pe1");       //max-bin 3.75 track-jet
	gb2_->Draw("Pe1");       //unbinned track-jet
	gb_2_->Draw("Pe1");     //emulated calo track-jet
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	g2_->SetTitle("3^{rd} leading p_{t} track-jet");
	TLegend *l_2__ = new TLegend(x1, y1, x2, y2, "");
	l_2__->SetBorderSize(0);
	l_2__->SetFillColor(kWhite);
	l_2__->SetTextSize(0.04);
	l_2__->SetHeader("3^{rd} leading","C");
	l_2__->AddEntry(g2_,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 1.5mm","p");
	l_2__->AddEntry(g2,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 7.5 mm", "p");
	l_2__->AddEntry(gb2_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
	l_2__->AddEntry(gb_2_,"#kern[-3.0]{ } emulated calo-jet","p");
	l_2__->SetTextAlign(12);
	l_2__->SetMargin(0.15);
	l_2__->Draw();
	leg1->Draw();
	leg5->Draw();
	fun->Draw("same");
	gPad->Update();
	//gPad->Write("c4b");
	C->Print(out_file_,"pdf");
	C->SaveAs("../tex/C14_30mm_7515mm_2trk.tex");

	//! page15
	C->cd(3);
	//gPad->SetGrid();
	gPad->SetLogy();
	g3->Draw("APe1");	//max-bin 7.5 track-jet
	g3_->Draw("Pe1");       //max-bin 3.75 track-jet
	gb3_->Draw("Pe1");       //unbinned track-jet
	gb_3_->Draw("Pe1");     //emulated calo track-jet
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	g3_->SetTitle("4^{th} leading p_{t} track-jet");
	y1 = 0.44; y2 = 0.65;
	TLegend *l_3__ = new TLegend(x1, y1, x2, y2, "");
	l_3__->SetBorderSize(0);
	l_3__->SetFillColor(kWhite);
	l_3__->SetTextSize(0.04);
	l_3__->SetHeader("4^{th} leading","C");
	l_3__->AddEntry(g3_,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 1.5mm","p");
	l_3__->AddEntry(g3,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 7.5 mm", "p");
	l_3__->AddEntry(gb3_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
	l_3__->AddEntry(gb_3_,"#kern[-3.0]{ } emulated calo-jet","p");
	l_3__->SetTextAlign(12);
	l_3__->SetMargin(0.15);
	l_3__->Draw();
	leg1->Draw();
	leg5->Draw();
	fun->Draw("same");
	gPad->Update();
	//gPad->Write("c4c");
	C->Print(out_file_,"pdf");
	C->SaveAs("../tex/C15_30mm_7515mm_2trk.tex");

	//! page16
	C->cd(4);
	//gPad->SetGrid();
	gPad->SetLogy();
	g4->Draw("APe1");	//max-bin 7.5 track-jet
	g4_->Draw("Pe1");	//max-bin 3.75 track-jet
	gb4_->Draw("Pe1");	//unbinned track-jet
	gb_4_->Draw("Pe1");	//emulated calo track-jet
	//gPad->BuildLegend(x1, y1, x2, y2, "", "PL"); // ROOT 6
	g4_->SetTitle("5^{th} leading p_{t} track-jet");
	y1 = 0.24; y2 = 0.45;
	TLegend *l_4__ = new TLegend(x1, y1, x2, y2, "");
	l_4__->SetBorderSize(0);
	l_4__->SetFillColor(kWhite);
	l_4__->SetTextSize(0.04);
	l_4__->SetHeader("5^{th} leading","C");
	l_4__->AddEntry(g4_,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 1.5mm","p");
	l_4__->AddEntry(g4,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 7.5 mm", "p");
	l_4__->AddEntry(gb4_,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
	l_4__->AddEntry(gb_4_,"#kern[-3.0]{ } emulated calo-jet","p");
	l_4__->SetTextAlign(12);
	l_4__->SetMargin(0.15);
	l_4__->Draw();
	leg1->Draw();
	leg5->Draw();
	fun->Draw("same");
	gPad->Update();
	//gPad->Write("c4d");
	C->Print(out_file_,"pdf");
	C->SaveAs("../tex/C16_30mm_7515mm_2trk.tex");

	//gPad->DrawFrame(Xmin_range, Ymin_range, Xmax_range, Ymax_range);
	//https://root-forum.cern.ch/t/tgraph2d-access-xyz-range-and-title-out-of-sync-color-bar/15722	
	TH2D *h2d1 = new TH2D("h2d1","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *h2d2 = new TH2D("h2d2","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *h2d3 = new TH2D("h2d3","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *h2d4 = new TH2D("h2d4","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *h2d_1 = new TH2D("h2d_1","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *h2d_2 = new TH2D("h2d_2","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *h2d_3 = new TH2D("h2d_3","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *h2d_4 = new TH2D("h2d_4","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *ha2d1 = new TH2D("ha2d1","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *ha2d2 = new TH2D("ha2d2","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *ha2d3 = new TH2D("ha2d3","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *ha2d4 = new TH2D("ha2d4","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *ha2d_1 = new TH2D("ha2d_1","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *ha2d_2 = new TH2D("ha2d_2","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *ha2d_3 = new TH2D("ha2d_3","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *ha2d_4 = new TH2D("ha2d_4","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *hb2d1 = new TH2D("hb2d1","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *hb2d2 = new TH2D("hb2d2","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *hb2d3 = new TH2D("hb2d3","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *hb2d4 = new TH2D("hb2d4","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *h2d1_ = new TH2D("h2d1_","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *h2d2_ = new TH2D("h2d2_","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *h2d3_ = new TH2D("h2d3_","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *h2d4_ = new TH2D("h2d4_","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *hb2d1_ = new TH2D("hb2d1_","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *hb2d2_ = new TH2D("hb2d2_","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *hb2d3_ = new TH2D("hb2d3_","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *hb2d4_ = new TH2D("hb2d4_","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *h2d1__ = new TH2D("h2d1__","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *h2d2__ = new TH2D("h2d2__","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *h2d3__ = new TH2D("h2d3__","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);
	TH2D *h2d4__ = new TH2D("h2d4__","",n, Xmin_range, Xmax_range, n, Ymin_range, Ymax_range);

	h2d1->GetXaxis()->CenterTitle();
	h2d2->GetXaxis()->CenterTitle();
	h2d3->GetXaxis()->CenterTitle();
	h2d4->GetXaxis()->CenterTitle();
	h2d_1->GetXaxis()->CenterTitle();
	h2d_2->GetXaxis()->CenterTitle();
	h2d_3->GetXaxis()->CenterTitle();
	h2d_4->GetXaxis()->CenterTitle();
	ha2d1->GetXaxis()->CenterTitle();
	ha2d2->GetXaxis()->CenterTitle();
	ha2d3->GetXaxis()->CenterTitle();
	ha2d4->GetXaxis()->CenterTitle();
	ha2d_1->GetXaxis()->CenterTitle();
	ha2d_2->GetXaxis()->CenterTitle();
	ha2d_3->GetXaxis()->CenterTitle();
	ha2d_4->GetXaxis()->CenterTitle();
	hb2d1->GetXaxis()->CenterTitle();
	hb2d2->GetXaxis()->CenterTitle();
	hb2d3->GetXaxis()->CenterTitle();
	hb2d4->GetXaxis()->CenterTitle();
	h2d1_->GetXaxis()->CenterTitle();
	h2d2_->GetXaxis()->CenterTitle();
	h2d3_->GetXaxis()->CenterTitle();
	h2d4_->GetXaxis()->CenterTitle();
	hb2d1_->GetXaxis()->CenterTitle();
	hb2d2_->GetXaxis()->CenterTitle();
	hb2d3_->GetXaxis()->CenterTitle();
	hb2d4_->GetXaxis()->CenterTitle();
	h2d1__->GetXaxis()->CenterTitle();
	h2d2__->GetXaxis()->CenterTitle();
	h2d3__->GetXaxis()->CenterTitle();
	h2d4__->GetXaxis()->CenterTitle();

	h2d1->GetYaxis()->CenterTitle();
	h2d2->GetYaxis()->CenterTitle();
	h2d3->GetYaxis()->CenterTitle();
	h2d4->GetYaxis()->CenterTitle();
	h2d_1->GetYaxis()->CenterTitle();
	h2d_2->GetYaxis()->CenterTitle();
	h2d_3->GetYaxis()->CenterTitle();
	h2d_4->GetYaxis()->CenterTitle();
	ha2d1->GetYaxis()->CenterTitle();
	ha2d2->GetYaxis()->CenterTitle();
	ha2d3->GetYaxis()->CenterTitle();
	ha2d4->GetYaxis()->CenterTitle();
	ha2d_1->GetYaxis()->CenterTitle();
	ha2d_2->GetYaxis()->CenterTitle();
	ha2d_3->GetYaxis()->CenterTitle();
	ha2d_4->GetYaxis()->CenterTitle();
	hb2d1->GetYaxis()->CenterTitle();
	hb2d2->GetYaxis()->CenterTitle();
	hb2d3->GetYaxis()->CenterTitle();
	hb2d4->GetYaxis()->CenterTitle();
	h2d1_->GetYaxis()->CenterTitle();
	h2d2_->GetYaxis()->CenterTitle();
	h2d3_->GetYaxis()->CenterTitle();
	h2d4_->GetYaxis()->CenterTitle();
	hb2d1_->GetYaxis()->CenterTitle();
	hb2d2_->GetYaxis()->CenterTitle();
	hb2d3_->GetYaxis()->CenterTitle();
	hb2d4_->GetYaxis()->CenterTitle();
	h2d1__->GetYaxis()->CenterTitle();
	h2d2__->GetYaxis()->CenterTitle();
	h2d3__->GetYaxis()->CenterTitle();
	h2d4__->GetYaxis()->CenterTitle();
	//x2 = 0.85;
	//x2 = 0.42;
	
	//gStyle->SetPalette(kColorPrintableOnGrey);
	//gStyle->SetPalette(kRainBow);
	gStyle->SetPalette(kLightTemperature);
	//! page17
	//! page5
	//! multi-bin and calo
	C->Clear();
	C->cd(1);
	ga2d1->SetHistogram(ha2d1);
	ga2d_1->SetHistogram(ha2d_1);
	Exga2d1->SetHistogram(hb2d1);
	Exga2d_1->SetHistogram(h2d1_);
	//gb2d1->SetHistogram(hb2d1);
	//gb_2d1_->SetHistogram(h2d1_);
	////ha2d1->Write();
	////ga2d1->Write();
	
	//gPad->SetFillStyle(4000);
	ha2d1->GetXaxis()->SetTitle("trigger efficiency");
	ha2d1->GetXaxis()->SetTitleOffset(1.5);
	ha2d1->GetYaxis()->SetTitle("trigger rate [MHz]");
	ha2d1->GetZaxis()->SetTitleOffset(1.3);
	ha2d1->GetZaxis()->SetTitle("p_{T} [GeV/c]");
	ga2d1->GetXaxis()->SetTitleSize(0.04);
	ga2d1->GetYaxis()->SetTitleSize(0.04);
	ga2d1->GetZaxis()->SetTitleSize(0.04);
	ga2d1->Draw("PCOLZ ERR");
	ga2d_1->Draw("PCOL ERR same");
	Exga2d1->Draw("PCOL ERR same");
	Exga2d_1->Draw("PCOL ERR same");
	//gb2d1->Draw("PCOL ERR same");
	//gb_2d1_->Draw("PCOL ERR same");
	//fun->Draw("same");
	gPad->SetTheta(90.0);
	gPad->SetPhi(0.001);
	gPad->SetRightMargin(0.15);
	gPad->SetLeftMargin(0.125);
	//gPad->BuildLegend(x1, y1, x2, y2, "2^{nd} leading p_{t}", "PL"); // ROOT 6
	x1 = 0.35, x2 = 0.75, y1 = 0.11, y2 = 0.31;
	TLegend *J1 = new TLegend(x1+0.15,y2+0.01,x2,y2+0.05);
	J1->SetFillColor(kWhite);
        J1->SetBorderSize(0);
        J1->AddEntry((TObject*)0, "2^{nd} leading", "");
        J1->SetTextSize(0.04);
	J1->Draw();
	TLegend *l1___ = new TLegend(x1, y1, x2, y2, "");
	l1___->SetBorderSize(0);
	l1___->SetFillColor(kWhite);
	l1___->SetTextSize(0.04);
	l1___->AddEntry(ga2d_1,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 1.5mm","p");
	l1___->AddEntry(ga2d1,"#kern[-3.0]{ } TTT-jet, multi-bin: #pm 7.5 mm", "p");
	l1___->AddEntry(Exga2d_1,"#kern[-3.0]{ } Ex.TTT-jet, multi-bin: #pm 1.5mm","p");
	l1___->AddEntry(Exga2d1,"#kern[-3.0]{ } Ex.TTT-jet, multi-bin: #pm 7.5 mm", "p");
	//l1___->AddEntry(gb2d1,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
	//l1___->AddEntry(gb_2d1_,"#kern[-3.0]{ } emulated calo-jet","p");
	l1___->SetTextAlign(12);
	l1___->SetMargin(0.15);
	l1___->Draw();
	leg1->Draw();
	leg5->Draw();
	gPad->Modified();
	gPad->Update();
	C->Print(out_file_,"pdf");
	C->SaveAs("../tex/C17_30mm_7515mm_2trk.tex");
	//cc->Write("c5a");
	//gPad->GetView()->TopView();
	//! page18
	C->cd(2);
	ga2d2->SetHistogram(ha2d2);
	ga2d_2->SetHistogram(ha2d_2);
	Exga2d2->SetHistogram(hb2d2);
	Exga2d_2->SetHistogram(h2d2_);
	//gb2d2->SetHistogram(hb2d2);
	//gb_2d2_->SetHistogram(h2d2_);
	////gPad->SetFillStyle(4000);
	ga2d2->Draw("PCOLZ ERR");
	ga2d_2->Draw("PCOL ERR same");
	Exga2d2->Draw("PCOL ERR same");
	Exga2d_2->Draw("PCOL ERR same");
	//gb2d2->Draw("PCOL ERR same");
	//gb_2d2_->Draw("PCOL ERR same");
	////fun->Draw("same");
	gPad->SetTheta(90.0);
	gPad->SetPhi(0.001);
	ga2d2->GetXaxis()->SetTitle("trigger efficiency");
	ga2d2->GetXaxis()->SetTitleOffset(1.5);
	ga2d2->GetYaxis()->SetTitle("trigger rate [MHz]");
	ga2d2->GetZaxis()->SetTitle("p_{T} [GeV/c]");
	ga2d2->GetZaxis()->SetTitleOffset(1.3);
	ga2d2->GetXaxis()->SetTitleSize(0.04);
	ga2d2->GetYaxis()->SetTitleSize(0.04);
	ga2d2->GetZaxis()->SetTitleSize(0.04);
	gPad->SetRightMargin(0.15);
	gPad->SetLeftMargin(0.125);
	//gPad->BuildLegend(x1, y1, x2, y2, "3^{rd} leading p_{t}", "PL"); // ROOT 6
	//l2__->Draw();
	l1___->Draw();
	TLegend *J2 = new TLegend(x1+0.15,y2+0.01,x2,y2+0.05);
	//TLegend *J2 = new TLegend(x1+0.15,y2-0.1,x2,y2-0.06);
	J2->SetFillColor(kWhite);
        J2->SetBorderSize(0);
        J2->AddEntry((TObject*)0, "3^{rd} leading", "");
        J2->SetTextSize(0.04);
	J2->Draw();
	leg1->Draw();
	leg5->Draw();
	gPad->Modified();
	gPad->Update();
	//gPad->Write("c5b");
	C->Print(out_file_,"pdf");
	C->SaveAs("../tex/C18_30mm_7515mm_2trk.tex");
	//! page19
	C->cd(3);
	ga2d3->SetHistogram(ha2d3);
	ga2d_3->SetHistogram(ha2d_3);
	Exga2d3->SetHistogram(hb2d3);
	Exga2d_3->SetHistogram(h2d3_);
	//gb2d3->SetHistogram(hb2d3);
	//gb_2d3_->SetHistogram(h2d3_);
	////gPad->SetFillStyle(4000);
	ga2d3->Draw("PCOLZ ERR");
	ga2d_3->Draw("PCOL ERR same");
	Exga2d3->Draw("PCOL ERR same");
	Exga2d_3->Draw("PCOL ERR same");
	//gb2d3->Draw("PCOL ERR same");
	//gb_2d3_->Draw("PCOL ERR same");
	////fun->Draw("same");
	gPad->SetTheta(90.0);
	gPad->SetPhi(0.001);
	ga2d3->GetXaxis()->SetTitle("trigger efficiency");
	ga2d3->GetXaxis()->SetTitleOffset(1.5);
	ga2d3->GetYaxis()->SetTitle("trigger rate [MHz]");
	ga2d3->GetZaxis()->SetTitle("p_{T} [GeV/c]");
	ga2d3->GetZaxis()->SetTitleOffset(1.3);
	ga2d3->GetXaxis()->SetTitleSize(0.04);
	ga2d3->GetYaxis()->SetTitleSize(0.04);
	ga2d3->GetZaxis()->SetTitleSize(0.04);
	gPad->SetRightMargin(0.15);
	gPad->SetLeftMargin(0.125);
	//gPad->BuildLegend(x1, y1, x2, y2, "4^{th} leading p_{t}", "PL"); // ROOT 6
	//l3__->Draw();
	l1___->Draw();
	TLegend *J3 = new TLegend(x1+0.15,y2+0.01,x2,y2+0.05);
	//TLegend *J3 = new TLegend(x1+0.15,y2-0.1,x2,y2-0.06);
	J3->SetFillColor(kWhite);
        J3->SetBorderSize(0);
        J3->AddEntry((TObject*)0, "4^{th} leading", "");
        J3->SetTextSize(0.04);
	J3->Draw();
	leg1->Draw();
	leg5->Draw();
	gPad->Modified();
	gPad->Update();
	//gPad->Write("c5c");
	C->Print(out_file_,"pdf");
	C->SaveAs("../tex/C19_30mm_7515mm_2trk.tex");
	//! page20
	C->cd(4);
	ga2d4->SetHistogram(ha2d4);
	ga2d_4->SetHistogram(ha2d_4);
	Exga2d4->SetHistogram(hb2d4);
	Exga2d_4->SetHistogram(h2d4_);
	//gb2d4->SetHistogram(hb2d4);
	//gb_2d4_->SetHistogram(h2d4_);
	////gPad->SetFillStyle(4000);
	ga2d4->Draw("PCOLZ ERR");
	ga2d_4->Draw("PCOL ERR same");
	Exga2d4->Draw("PCOL ERR same");
	Exga2d_4->Draw("PCOL ERR same");
	//gb2d4->Draw("PCOL ERR same");
	//gb_2d4_->Draw("PCOL ERR same");
	////fun->Draw("same");
	gPad->SetTheta(90.0);
	gPad->SetPhi(0.001);
	ga2d4->GetXaxis()->SetTitle("trigger efficiency");
	ga2d4->GetXaxis()->SetTitleOffset(1.5);
	ga2d4->GetYaxis()->SetTitle("trigger rate [MHz]");
	ga2d4->GetZaxis()->SetTitle("p_{T} [GeV/c]");
	ga2d4->GetZaxis()->SetTitleOffset(1.3);
	ga2d4->GetXaxis()->SetTitleSize(0.04);
	ga2d4->GetYaxis()->SetTitleSize(0.04);
	ga2d4->GetZaxis()->SetTitleSize(0.04);
	gPad->SetRightMargin(0.15);
	gPad->SetLeftMargin(0.125);
	//gPad->BuildLegend(x1, y1, x2, y2, "5^{th} leading p_{t}", "PL"); // ROOT 6
	//l4__->Draw();
	l1___->Draw();
	TLegend *J4 = new TLegend(x1+0.15,y2+0.01,x2,y2+0.05);
	//TLegend *J4 = new TLegend(x1+0.15,y2+0.01,x2,y2+0.05);
	J4->SetFillColor(kWhite);
        J4->SetBorderSize(0);
        J4->AddEntry((TObject*)0, "5^{th} leading", "");
        J4->SetTextSize(0.04);
	J4->Draw();
	leg1->Draw();
	leg5->Draw();
	gPad->Modified();
	gPad->Update();
	//gPad->Write("c5d");
	C->SaveAs("../pdf/c5.C");
	C->Print(out_file_, "pdf");
	C->SaveAs("../tex/C20_30mm_7515mm_2trk.tex");

	//! page21
	C->Clear();
	//C->Divide(2,2,0.5,0.5);
	//! page6
	//! max-bin and calo
	C->cd(1);
	gPad->SetLogy();
	g2d1->SetHistogram(h2d1);
	g2d_1->SetHistogram(h2d_1);
	Exg2d1->SetHistogram(hb2d1_);
	Exg2d_1->SetHistogram(h2d1__);
	//gPad->SetFillStyle(4000);
	g2d1->Draw("PCOLZ ERR");
	g2d_1->Draw("PCOL ERR same");
	Exg2d1->Draw("PCOL ERR same");
	Exg2d_1->Draw("PCOL ERR same");
	//gb2d1->Draw("PCOL ERR same");
	//gb_2d1_->Draw("PCOL ERR same");
	////fun->Draw("same");
	gPad->SetTheta(90.0);
	gPad->SetPhi(0.001);
	g2d1->GetXaxis()->SetTitle("trigger efficiency");
	g2d1->GetXaxis()->SetTitleOffset(1.5);
	g2d1->GetYaxis()->SetTitle("trigger rate [MHz]");
	g2d1->GetZaxis()->SetTitle("p_{T} [GeV/c]");
	g2d1->GetZaxis()->SetTitleOffset(1.3);
	g2d1->GetXaxis()->SetTitleSize(0.04);
	g2d1->GetYaxis()->SetTitleSize(0.04);
	g2d1->GetZaxis()->SetTitleSize(0.04);
	gPad->SetRightMargin(0.15);
	gPad->SetLeftMargin(0.125);
	//gPad->BuildLegend(x1, y1, x2, y2, "2^{nd} leading p_{t}", "PL"); // ROOT 6
	J1->Draw();
	leg1->Draw();
	leg5->Draw();
	TLegend *l_1___ = new TLegend(x1, y1, x2, y2, "");
	l_1___->SetBorderSize(0);
	l_1___->SetFillColor(kWhite);
	l_1___->SetTextSize(0.04);
	l_1___->AddEntry(g2d_1,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 1.5mm","p");
	l_1___->AddEntry(g2d1,"#kern[-3.0]{ } TTT-jet, max-bin: #pm 7.5 mm", "p");
	l_1___->AddEntry(Exg2d_1,"#kern[-3.0]{ } Ex.TTT-jet, max-bin: #pm 1.5mm","p");
	l_1___->AddEntry(Exg2d1,"#kern[-3.0]{ } Ex.TTT-jet, max-bin: #pm 7.5 mm", "p");
	//l_1___->AddEntry(gb2d1,"#kern[-3.0]{ } TTT-jet, no z-binning","p");
	//l_1___->AddEntry(gb_2d1_,"#kern[-3.0]{ } emulated calo-jet","p");
	l_1___->SetTextAlign(12);
	l_1___->SetMargin(0.15);
	l_1___->Draw();
	gPad->Modified();
	gPad->Update();
	//gPad->Write("c6a");
	//gPad->GetView()->TopView();
	C->Print(out_file_,"pdf");
	C->SaveAs("../tex/C21_30mm_7515mm_2trk.tex");
	//! page22
	C->cd(2);
	g2d2->SetHistogram(h2d2);
	g2d_2->SetHistogram(h2d_2);
	Exg2d2->SetHistogram(hb2d2_);
	Exg2d_2->SetHistogram(h2d2__);
	//gPad->SetFillStyle(4000);
	g2d2->Draw("PCOLZ ERR");
	g2d_2->Draw("PCOL ERR same");
	Exg2d2->Draw("PCOL ERR same");
	Exg2d_2->Draw("PCOL ERR same");
	//gb2d2->Draw("PCOL ERR same");
	//gb_2d2_->Draw("PCOL ERR same");
	gPad->SetTheta(90.0);
	gPad->SetPhi(0.001);
	g2d2->GetXaxis()->SetTitle("trigger efficiency");
	g2d2->GetXaxis()->SetTitleOffset(1.5);
	g2d2->GetYaxis()->SetTitle("trigger rate [MHz]");
	g2d2->GetZaxis()->SetTitle("p_{T} [GeV/c]");
	g2d2->GetZaxis()->SetTitleOffset(1.3);
	g2d2->GetXaxis()->SetTitleSize(0.04);
	g2d2->GetYaxis()->SetTitleSize(0.04);
	g2d2->GetZaxis()->SetTitleSize(0.04);
	gPad->SetRightMargin(0.15);
	gPad->SetLeftMargin(0.125);
	gPad->SetLogy();
	//gPad->BuildLegend(x1, y1, x2, y2, "3^{rd} leading p_{t}", "PL"); // ROOT 6
	//l_2__->Draw();
	l_1___->Draw();
	J2->Draw();
	leg1->Draw();
	leg5->Draw();
	gPad->Modified();
	gPad->Update();
	//gPad->Write("c6b");
	C->Print(out_file_,"pdf");
	C->SaveAs("../tex/C22_30mm_7515mm_2trk.tex");
	//! page23
	C->cd(3);
	gPad->SetLogy();
	g2d3->SetHistogram(h2d3);
	g2d_3->SetHistogram(h2d_3);
	Exg2d3->SetHistogram(hb2d3_);
	Exg2d_3->SetHistogram(h2d3__);
	//gPad->SetFillStyle(4000);
	g2d3->Draw("PCOLZ ERR");
	g2d_3->Draw("PCOL ERR same");
	Exg2d3->Draw("PCOL ERR same");
	Exg2d_3->Draw("PCOL ERR same");
	//gb2d3->Draw("PCOL ERR same");
	//gb_2d3_->Draw("PCOL ERR same");
	gPad->SetTheta(90.0);
	gPad->SetPhi(0.001);
	//fun2->Draw("same");
	g2d3->GetXaxis()->SetTitle("trigger efficiency");
	g2d3->GetXaxis()->SetTitleOffset(1.5);
	g2d3->GetYaxis()->SetTitle("trigger rate [MHz]");
	g2d3->GetZaxis()->SetTitle("p_{T} [GeV/c]");
	g2d3->GetZaxis()->SetTitleOffset(1.3);
	g2d3->GetXaxis()->SetTitleSize(0.04);
	g2d3->GetYaxis()->SetTitleSize(0.04);
	g2d3->GetZaxis()->SetTitleSize(0.04);
	gPad->SetRightMargin(0.15);
	gPad->SetLeftMargin(0.125);
	//gPad->BuildLegend(x1, y1, x2, y2, "4^{th} leading p_{t}", "PL"); // ROOT 6
	//l_3__->Draw();
	l_1___->Draw();
	J3->Draw();
	leg1->Draw();
	leg5->Draw();
	gPad->Modified();
	gPad->Update();
	//gPad->Write("c6c");
	C->Print(out_file_,"pdf");
	C->SaveAs("../tex/C23_30mm_7515mm_2trk.tex");

	//! page24
	C->cd(4);
	TPad *mypad1 = new TPad("mypad1","mypad1",0,0,1,1);
	mypad1->SetLogy();
	g2d4->SetHistogram(h2d4);
	g2d_4->SetHistogram(h2d_4);
	Exg2d4->SetHistogram(hb2d4_);
	Exg2d_4->SetHistogram(h2d4__);
	//mypad1->SetFillStyle(4000);
	g2d4->GetXaxis()->SetTitle("trigger efficiency");
	g2d4->GetXaxis()->SetTitleOffset(1.5);
	g2d4->GetYaxis()->SetTitle("trigger rate [MHz]");
	g2d4->GetZaxis()->SetTitle("p_{T} [GeV/c]");
	g2d4->GetZaxis()->SetTitleOffset(1.3);
	g2d4->GetXaxis()->SetTitleSize(0.04);
	g2d4->GetYaxis()->SetTitleSize(0.04);
	g2d4->GetZaxis()->SetTitleSize(0.04);
	g2d4->Draw("PCOLZ ERR");
	g2d_4->Draw("PCOL ERR same");
	Exg2d4->Draw("PCOL ERR same");
	Exg2d_4->Draw("PCOL ERR same");
	//gb2d4->Draw("PCOL ERR same");
	//gb_2d4_->Draw("PCOL ERR same");
	mypad1->SetTheta(90.0);
	mypad1->SetPhi(0.001);
	//fun1->Draw("same");
	mypad1->SetRightMargin(0.15);
	mypad1->SetLeftMargin(0.125);
	//mypad1->BuildLegend(x1, y1, x2, y2, "5^{th} leading p_{t}", "PL"); // ROOT 6
	//l_4__->Draw();
	std::cout<<"X1, X2: " <<mypad1->GetX1() <<", " <<mypad1->GetX2() <<std::endl;
	std::cout<<"Y1, Y2: " <<mypad1->GetY1() <<", " <<mypad1->GetY2() <<std::endl;
	l_1___->Draw();
	J4->Draw();
	leg1->Draw();
	leg5->Draw();
	mypad1->Modified();
	mypad1->Update();
	//mypad1->Draw();
	//gPad->Write("c6d");
	C->Print(out_file_, "pdf");
	C->SaveAs("../pdf/c6.C");
	C->SaveAs("../tex/C24_30mm_7515mm_2trk.tex");

	std::cout<<"X1, X2: " <<gPad->GetX1() <<", " <<gPad->GetX2() <<std::endl;
	std::cout<<"Y1, Y2: " <<gPad->GetY1() <<", " <<gPad->GetY2() <<std::endl;

	//! page25
	//C->cd();
	//TPad *mypad = new TPad("mypad","mypad",gPad->GetX1(),gPad->GetY1(),gPad->GetX2(),gPad->GetY2());
	TPad *mypad = new TPad("mypad","mypad",0,0,1,1);
	mypad->SetFillStyle(0);
	//fun->GetYaxis()->SetRangeUser(Ymin_range,Ymax_range);
	h2d4->Draw();
	fun->Draw("same");
	mypad->SetLogy();
	mypad->DrawClone();
	C->Print(out_file_, "pdf");
	C->SaveAs("../tex/C24a_30mm_7515mm_2trk.tex");

	//! page26
	C->Clear();
	gPad->SetRightMargin(0.07);
	gPad->SetLeftMargin(0.1);
	//! page7	
	C->cd(1);
	g1->Draw("APe1");
	g2->Draw("Pe1");
	g3->Draw("Pe1");
	g4->Draw("Pe1");
	gPad->BuildLegend(x1, y1, x2, y2, "sum p_{t}", "PL"); // ROOT 6
	gPad->Modified();
	gPad->Update();
	//gPad->Write("c7a");
	C->Print(out_file_,"pdf");

	//! page27
	C->cd(2);
	ga1->Draw("APe1");
	ga2->Draw("Pe1");
	ga3->Draw("Pe1");
	ga4->Draw("Pe1");
	gPad->BuildLegend(x1, y1, x2, y2, "max p_{t}", "PL"); // ROOT 6
	gPad->Modified();
	gPad->Update();
	//gPad->Write("c7b");
	C->Print(out_file_,"pdf");

	//! page28
	C->cd(3);
	gb1->Draw("AP");
	gb2->Draw("P");
	gb3->Draw("P");
	gb4->Draw("P");
	gPad->BuildLegend(x1, y1, x2, y2, "no z binning", "PL"); // ROOT 6
	gPad->Modified();
	gPad->Update();
	//gPad->Write("c7c");
	C->Print(out_file_,"pdf");
	
	//! page29
	C->cd(4);
	gb_1_->Draw("APe1");
	gb_2_->Draw("Pe1");
	gb_3_->Draw("Pe1");
	gb_4_->Draw("Pe1");
	//gPad->BuildLegend(x1, y1, x2, y2, "emulated calo-jets", "PL"); // ROOT 6
	x1 = 0.65, y1 = 0.11, x2 = 0.91, y2 = 0.4;
	TLegend *emu = new TLegend(x1, y1, x2, y2, "");
	emu->SetBorderSize(0);
	emu->SetFillColor(kWhite);
	emu->SetTextSize(0.04);
	emu->SetHeader("Emu. calo-jet","C");
	emu->AddEntry(gb_1_,"#kern[-1.0]{ } 2^{nd} leading","p");
	emu->AddEntry(gb_2_,"#kern[-1.0]{ } 3^{rd} leading", "p");
	emu->AddEntry(gb_3_,"#kern[-1.0]{ } 4^{th} leading","p");
	emu->AddEntry(gb_4_,"#kern[-1.0]{ } 5^{th} leading","p");
	emu->SetTextAlign(12);
	emu->SetMargin(0.15);
	emu->Draw();

	gPad->Modified();
	gPad->Update();
	//gPad->Write("c7d");
	C->Print(out_file_, "pdf");
	C->SaveAs("../tex/C29_30mm_7515mm_calo.tex");
	
///////////////////////////////////////////////////
///////////from a different vertex bin ///////////
//////////////////////////////////////////////////
	C->Clear();
/////////////////////////////////////////////////////////////////////
/////////////// graphs from 2 different bins together ///////////////
/////////////////////////////////////////////////////////////////////
	//! page30
	//! page8
	g1->Draw("APe1");
	g1->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	g2->Draw("Pe1");
	g3->Draw("Pe1");
	g4->Draw("Pe1");
	g1_->Draw("Pe1");
	g1_->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	g2_->Draw("Pe1");
	g3_->Draw("Pe1");
	g4_->Draw("Pe1");
	C->Print(out_file_, "pdf");
	
	//! page31
	//! page9
	ga1->Draw("APe1");
	ga1->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	ga2->Draw("Pe1");
	ga3->Draw("Pe1");
	ga4->Draw("Pe1");
	ga1_->Draw("Pe1");
	ga1_->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	ga2_->Draw("Pe1");
	ga3_->Draw("Pe1");
	ga4_->Draw("Pe1");
	C->Print(out_file_, "pdf");

	//! page32
	//! page10
	gb1->Draw("APe1");
	gb1->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	gb2->Draw("Pe1");
	gb3->Draw("Pe1");
	gb4->Draw("Pe1");
	gb_1_->Draw("Pe1");
	gb_1_->GetXaxis()->SetRangeUser(Xmin_range, Xmax_range);
	gb_2_->Draw("Pe1");
	gb_3_->Draw("Pe1");
	gb_4_->Draw("Pe1");
	C->Print(out_file_, "pdf");
	C->SetLogy(0);
	
	//! page33
	//! page11
	C->SetLogx();
	Eb2->SetTitle("sum-pt,+-7.5mm binning ");
	Eb2->GetXaxis()->SetTitle("p_{T} [GeV/c]");
	Eb2->GetYaxis()->SetTitle("trigger efficiency");
	Eb2->GetXaxis()->CenterTitle();
	Eb2->GetYaxis()->CenterTitle();
	Eb2->GetXaxis()->SetTitleSize(0.04);
	Eb2->GetYaxis()->SetTitleSize(0.04);
	Eb2->GetXaxis()->SetRangeUser(2.0,0.9e3);
	Eb2->Draw("hist ");
	Eb3->Draw("hist same");
	Eb4->Draw("hist same");
	Eb5->Draw("hist same");
	E2->Draw("hist same");
	E3->Draw("hist same");
	E4->Draw("hist same");
	E5->Draw("hist same");
	Ebcalo2->Draw("hist same");
	Ebcalo3->Draw("hist same");
	Ebcalo4->Draw("hist same");
	Ebcalo5->Draw("hist same");
	leg1->Draw();
	leg5->Draw();
	C->Print(out_file_, "pdf");
	//gPad->Write("c11");
	C->SaveAs("../tex/C32_30mm_7515mm_2trk.tex");
	C->SaveAs("../C/C32_30mm_7515mm_2trk.C");
	
	//! page34
	//! page12
	Eb_2->SetTitle("sum-pt,+-1.5mm binning ");
	Eb_2->GetXaxis()->SetTitle("p_{T} [GeV/c]");
	Eb_2->GetYaxis()->SetTitle("trigger efficiency");
	Eb_2->GetXaxis()->CenterTitle();
	Eb_2->GetYaxis()->CenterTitle();	
	Eb_2->GetXaxis()->SetTitleSize(0.04);
	Eb_2->GetYaxis()->SetTitleSize(0.04);
	Eb_2->GetXaxis()->SetRangeUser(2.0, 0.9e3);
	Eb_2->Draw("hist ");
	Eb_3->Draw("hist same");
	Eb_4->Draw("hist same");
	Eb_5->Draw("hist same");
	E2_->Draw("hist same");
	E3_->Draw("hist same");
	E4_->Draw("hist same");
	E5_->Draw("hist same");
	Ebcalo2->Draw("hist same");
	Ebcalo3->Draw("hist same");
	Ebcalo4->Draw("hist same");
	Ebcalo5->Draw("hist same");
	leg1->Draw();
	leg5->Draw();
	C->Print(out_file_, "pdf");
	//gPad->Write("c12");
	C->SaveAs("../tex/C33_30mm_7515mm_2trk.tex");
	C->SaveAs("../C/C33_30mm_7515mm_2trk.C");

	//! page35
	//! page13
	Eb2->SetTitle("max pt TJ from each bin,+-7.5mm binning ");	
	Eb2->Draw("hist ");
	Eb3->Draw("hist same");
	Eb4->Draw("hist same");
	Eb5->Draw("hist same");
	Ea2->Draw("hist same");
	Ea3->Draw("hist same");
	Ea4->Draw("hist same");
	Ea5->Draw("hist same");
	Ebcalo2->Draw("hist same");
	Ebcalo3->Draw("hist same");
	Ebcalo4->Draw("hist same");
	Ebcalo5->Draw("hist same");
	leg1->Draw();
	leg5->Draw();
	C->Print(out_file_, "pdf");
	//gPad->Write("c13");
	C->SaveAs("../tex/C34_30mm_7515mm_2trk.tex");
	C->SaveAs("../C/C34_30mm_7515mm_2trk.C");

	//! page36
	//! page14
	Eb_2->SetTitle("max pt TJ from each bin,+-1.5mm binning ");	
	Eb_2->Draw("hist ");
	Eb_3->Draw("hist same");
	Eb_4->Draw("hist same");
	Eb_5->Draw("hist same");
	Ea_2->Draw("hist same");
	Ea_3->Draw("hist same");
	Ea_4->Draw("hist same");
	Ea_5->Draw("hist same");
	Ebcalo2->Draw("hist same");
	Ebcalo3->Draw("hist same");
	Ebcalo4->Draw("hist same");
	Ebcalo5->Draw("hist same");
	leg1->Draw();
	leg5->Draw();
	C->Print(out_file_, "pdf");
	//gPad->Write("c14");
	C->SaveAs("../tex/C35_30mm_7515mm_2trk.tex");
	C->SaveAs("../C/C35_30mm_7515mm_2trk.C");

	//! page37
	//! page15
	C->SetLogy();
	Rb2->SetTitle("sum-pt,+-7.5mm binning ");	
	Rb2->GetXaxis()->SetTitle("p_{T} [GeV/c]");
	Rb2->GetYaxis()->SetTitle("trigger rate [MHz]");
	Rb2->GetXaxis()->CenterTitle();
	Rb2->GetYaxis()->CenterTitle();
	Rb2->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Rb2->GetXaxis()->SetRangeUser(2.0, 0.9e3);
	Rb2->GetXaxis()->SetTitleSize(0.04);
	Rb2->GetYaxis()->SetTitleSize(0.04);
	Rb2->GetYaxis()->SetTitleOffset(1.2);
	Rb2->Draw("hist ");
	Rb3->Draw("hist same");
	Rb4->Draw("hist same");
	Rb5->Draw("hist same");
	R2->Draw("hist same");
	R3->Draw("hist same");
	R4->Draw("hist same");
	R5->Draw("hist same");
	Rbcalo2->Draw("hist same");
	Rbcalo3->Draw("hist same");
	Rbcalo4->Draw("hist same");
	Rbcalo5->Draw("hist same");
	leg1->Draw();
	leg5->Draw();
	C->Print(out_file_, "pdf");
	C->SaveAs("../tex/C36_30mm_7515mm_2trk.tex");
	C->SaveAs("../C/C36_30mm_7515mm_2trk.C");
	//gPad->Write("c15");
	
	//! page38
	//! page16
	Rb_2->SetTitle("sum-pt,+-1.5mm binning ");
	Rb_2->GetXaxis()->SetTitle("p_{T} [GeV/c]");
	Rb_2->GetYaxis()->SetTitle("trigger rate [MHz]");
	Rb_2->GetXaxis()->CenterTitle();
	Rb_2->GetYaxis()->CenterTitle();	
	Rb_2->GetYaxis()->SetRangeUser(Ymin_range, Ymax_range);
	Rb_2->GetXaxis()->SetRangeUser(2.0, 0.9e3);
	////Rb_2->GetXaxis()->SetRangeUser(0, 0.07e3);
	Rb_2->GetXaxis()->SetTitleSize(0.04);
	Rb_2->GetYaxis()->SetTitleSize(0.04);
	Rb_2->GetYaxis()->SetTitleOffset(1.2);
	Rb_2->Draw("hist ");
	Rb_3->Draw("hist same");
	Rb_4->Draw("hist same");
	Rb_5->Draw("hist same");
	R2_->Draw("hist same");
	R3_->Draw("hist same");
	R4_->Draw("hist same");
	R5_->Draw("hist same");
	Rbcalo2->Draw("hist same");
	Rbcalo3->Draw("hist same");
	Rbcalo4->Draw("hist same");
	Rbcalo5->Draw("hist same");
	leg1->Draw();
	leg5->Draw();
	C->Print(out_file_, "pdf");
	C->SaveAs("../tex/C37_30mm_7515mm_2trk.tex");
	C->SaveAs("../C/C37_30mm_7515mm_2trk.C");
	//gPad->Write("c16");

	//! page39
	//! page17
	Rb2->SetTitle("max pt TJ from each bin,+-7.5mm binning ");	
	Rb2->Draw("hist ");
	Rb3->Draw("hist same");
	Rb4->Draw("hist same");
	Rb5->Draw("hist same");
	Ra2->Draw("hist same");
	Ra3->Draw("hist same");
	Ra4->Draw("hist same");
	Ra5->Draw("hist same");
	Rbcalo2->Draw("hist same");
	Rbcalo3->Draw("hist same");
	Rbcalo4->Draw("hist same");
	Rbcalo5->Draw("hist same");
	leg1->Draw();
	leg5->Draw();
	C->Print(out_file_, "pdf");
	C->SaveAs("../tex/C38_30mm_7515mm_2trk.tex");
	C->SaveAs("../C/C38_30mm_7515mm_2trk.C");
	//gPad->Write("c17");

	//! page40
	//! pagr18
	Rb_2->SetTitle("max pt TJ from each bin,+-1.5mm binning ");	
	Rb_2->Draw("hist ");
	Rb_3->Draw("hist same");
	Rb_4->Draw("hist same");
	Rb_5->Draw("hist same");
	Ra_2->Draw("hist same");
	Ra_3->Draw("hist same");
	Ra_4->Draw("hist same");
	Ra_5->Draw("hist same");
	Rbcalo2->Draw("hist same");
	Rbcalo3->Draw("hist same");
	Rbcalo4->Draw("hist same");
	Rbcalo5->Draw("hist same");
	leg1->Draw();
	leg5->Draw();
	C->Print(out_file_close,"pdf");
	C->SaveAs("../tex/C39_30mm_7515mm_2trk.tex");
	C->SaveAs("../C/C39_30mm_7515mm_2trk.C");
	//gPad->Write("c18");

	//f_out->Close();
	return;
}
