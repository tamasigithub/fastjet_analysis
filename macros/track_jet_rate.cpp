//////// Track Jet Rate as a function of Eta and Pt //////////
///// Create rate plot as a function of pt /////
#include <iostream>
#include "TROOT.h"
#include "TFile.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TLegend.h"
#include "TGraphErrors.h"
#include "TPostScript.h"
#include "TLatex.h"
#include "TChain.h"
#include <vector>
#include <list>
#include <algorithm> 
#include <functional>
#include <fstream>
#include <string>
#include <math.h>
#include <numeric> //accumulate
//! path for input files
const char* path = "/afs/cern.ch/work/t/tkar/testarea/20.20.10.1/WorkArea/run/rec_outputs";
//const char* out_path = "/afs/cern.ch/work/t/tkar/testarea/20.20.10.1/WorkArea/run/rec_outputs";
const char* out_path = "/eos/user/t/tkar/www/TTT/plots/rate";
//const char* path = "/media/tamasi/Z/PhD/ATHENA/rec_output";
//const char* path = "/media/munmun/Z/PhD/ATHENA/rec_output";


int plot_rate(const char* output_file_name = "JetrateVspt_3mmSumpt_Pu160optsigma3", bool debug = false)
{
	//! Input file names
	TChain rec("glob_jet");
	//rec.Add("/afs/cern.ch/work/t/tkar/testarea/20.20.10.1/WorkArea/run/rec_outputs/MB_files/*.root");
	//rec.Add("/afs/cern.ch/work/t/tkar/testarea/20.20.10.1/WorkArea/run/rec_outputs/MB_files_opt/user.tkar.tkar119995.MBRoot1_MYSTREAM/*.root");
	rec.Add("/afs/cern.ch/work/t/tkar/testarea/20.20.10.1/WorkArea/run/rec_outputs/MB_files_opt/user.tkar.tkar119995.MBRoot3_MYSTREAM/*.root");
	rec.Add("/eos/user/t/tkar/grid_files/user.tkar.tkar119996.MBRoot3_MYSTREAM/*.root");
       	std::cout<<"total entries: "<< rec.GetEntries() <<"\n";
	int nbins = 20;
	double ptmin = 0.0, ptmax = 100000.0;//0 to 100 GeV/c
	//! Book Histogram
        TH1* h_PULpt = new TH1D("h_PULpt","Rate of highest Pt track in PU 200",nbins,ptmin,ptmax);
	TH1* h_PUNLpt = new TH1D("h_PUNLpt","Rate of 2nd highest Pt track in PU 200",nbins,ptmin,ptmax);
	TH1* h_PUNNLpt = new TH1D("h_PUNNLpt","Rate of 3rd highest Pt track in PU 200",nbins,ptmin,ptmax);
	TH1* h_PUNNNLpt = new TH1D("h_PUNNNLpt","Rate of 4th highest Pt track in PU 200",nbins,ptmin,ptmax);
	TH1* h_PUNNNNLpt = new TH1D("h_PUNNNNLpt","Rate Vs track P_{t} in PU 160, PB finding using sum pt",nbins,ptmin,ptmax);

	//! define a local vector<double> to store the reconstructed pt values
	//! always initialise a pointer!!
	std::vector<double> *Pt_rec = 0;
        std::vector<double> *Z0_rec = 0;
	rec.TChain::SetBranchStatus("Pt_n",1);
        rec.TChain::SetBranchStatus("Z013",1);
        rec.TChain::SetBranchAddress("Pt_n", &Pt_rec);
        rec.TChain::SetBranchAddress("Z013", &Z0_rec);
        Long64_t n_entries = rec.GetEntries();
//        Long64_t n_entries = 20;
	std::cout<<"Reconstructed Tree has " << n_entries << " entries\n";
        int pileup = 160;
        Long64_t nevents=n_entries/pileup; // corresponds to the total no. of pileup events
        std::cout<<"total no. of pileup events processed : " << nevents <<"\n";

	double PU_Lpt, PU_NLpt, PU_NNLpt, PU_NNNLpt, PU_NNNNLpt;
	double max_sumpt;
	int prim_bin;
        double Z0_cut = 1.5;//3;//1.5; //in mm
	double tmppt , tmpz0;
        //! Create a vector to store all the tracks reconstructed in 'pileup' no. of events
        std::vector<double> Pt_recPU;
        std::vector<double> Z0_recPU;
	std::vector<double> zbincenter;
	zbincenter.clear();
	//! Fill zbincenter with bin centers along the z axis from -100 to 100 in steps of 10 
	int nzbins = 81;//41;//81;
	for (double z = -100.0; z <= 100.0; z+=(2.0*100)/(nzbins-1))
	{
		zbincenter.push_back(z);
	}
	std::cout<<"size: " <<zbincenter.size() <<"\n";// should be nzbins

	//! define a containier holding the list of overlapping zbins(basically the tracks in this bin) and 
	//! a constainer containing the list of first 5 highest pt tracks in each of the bins
	std::vector<std::vector<double>> vectorofbins(nzbins, std::vector<double>());
	//std::vector<std::vector<double>> v_highestPttracks(nzbins, std::vector<double>(5));
	std::vector<double> v_sumpt(nzbins,0.0);
	char buffer[1024];
	//! For all pileup events
        for(Long64_t i = 0; i < nevents-2; ++i)
        {
		//! clear all the vectors to erase any information from previous event
            	Pt_recPU.clear();
            	Z0_recPU.clear();
		for(int y = 0; y <nzbins; ++y)
		{
			(vectorofbins[y]).clear();
			//(v_highestPttracks[y]).clear();
		}
		int skip = i*pileup;
                if(debug)
		{
                	std::cout<<"\nskip:"<<skip <<"\n";
                	std::cout<<"i:" <<i <<"\n";
		}

		//! Create overlapping bins along the Z-axis
                for(int j = skip; j < skip+pileup; ++j)
                {
			if(debug)std::cout<<"j : " << j << ", skip : "<<skip <<"\n";	
			rec.TChain::GetEntry(j);
                    	//! fill the pileup vectors
                    	for(int k = 0; k < Pt_rec->size(); ++k)
                    	{
				tmppt = (*Pt_rec)[k];
				tmpz0 = (*Z0_rec)[k];

                        	Pt_recPU.push_back(tmppt);
                        	Z0_recPU.push_back(tmpz0);
				for(int v = 0; v<nzbins; ++v)
				{
					//! Fill the overlapping z bins depending on where tmpz0 lies along Z
					//! a bin of width 2*Z0_cut is defined about zbincenter[i] -> 
					if(abs(zbincenter[v] - tmpz0) < Z0_cut)
					{
						//! if the track pt is greater than 100 GeV make it 100GeV as it will affect the sumpt
						if(tmppt > 1.1e5) tmppt = 1e5;
						(vectorofbins[v]).push_back(tmppt);
					}
				}
                    	}

                }
		
		//! Partial sort the elemets of vectorofbins and hence fill the first 5 highest pt tracks in v_highestPttracks
		for(int u = 0; u < nzbins; ++u)
		{
			//! Calculated sumpt for each bin
			if((vectorofbins[u]).size() < 5) v_sumpt[u] = -1.0;
			else v_sumpt[u] =  std::accumulate((vectorofbins[u]).begin(),(vectorofbins[u]).end(),0.0);
			
		}
		
		max_sumpt	= v_sumpt[0];
		prim_bin	= 0;
		//! find the highest sumpt bin
		for(int t =1; t < nzbins; ++t)
		{
			if(v_sumpt[t]<0) continue;
			if(max_sumpt < v_sumpt[t])
			{
				max_sumpt = v_sumpt[t];
				prim_bin  = t;
			}
		}
		//!Partial sort track pt for the primary bin
		if(v_sumpt[prim_bin] > 0)
		{
			std::partial_sort((vectorofbins[prim_bin]).begin(),(vectorofbins[prim_bin]).begin()+5,(vectorofbins[prim_bin]).end(),std::greater<double>());
			PU_Lpt 		= vectorofbins[prim_bin][0];
			PU_NLpt 	= vectorofbins[prim_bin][1];
			PU_NNLpt 	= vectorofbins[prim_bin][2];
			PU_NNNLpt 	= vectorofbins[prim_bin][3];
			PU_NNNNLpt 	= vectorofbins[prim_bin][4];
			//! Fill Histo
			h_PULpt->Fill(PU_Lpt);
			h_PUNLpt->Fill(PU_NLpt);
			h_PUNNLpt->Fill(PU_NNLpt);
			h_PUNNNLpt->Fill(PU_NNNLpt);
			h_PUNNNNLpt->Fill(PU_NNNNLpt);

			if(debug)
			{
				std::cout<<"size : " << Pt_recPU.size() <<"\n";
				std::cout<<"Max pt of all reconstructed tracks in event "<< i <<" is: " <<PU_Lpt << "\n";
				std::cout<<"next to Max pt of all reconstructed tracks in event "<< i <<" is: " << PU_NLpt   << "\n";
				std::cout<<"next to Max pt of all reconstructed tracks in event "<< i <<" is: " << PU_NNLpt  << "\n";
				std::cout<<"next to Max pt of all reconstructed tracks in event "<< i <<" is: " << PU_NNNLpt << "\n";

			}
		
		}	
        }
        TCanvas *c1 = new TCanvas();
	h_PUNNNNLpt->GetYaxis()->SetRangeUser(5.0e-2, 1.0e2);
        c1->SetLogy();
	h_PUNNNNLpt->SetLineColor(kBlue);
	h_PUNNNLpt->SetLineColor(kGreen);
	h_PUNNLpt->SetLineColor(kRed);
	h_PUNLpt->SetLineColor(kBlack);
	h_PULpt->SetLineColor(kOrange);

	h_PUNNNNLpt->SetLineWidth(3);
	h_PUNNNLpt->SetLineWidth(3);
	h_PUNNLpt->SetLineWidth(3);
	h_PUNLpt->SetLineWidth(3);
	h_PULpt->SetLineWidth(3);

        h_PULpt->Scale(1.0e3/(25*nevents));
        h_PUNLpt->Scale(1.0e3/(25*nevents));
        h_PUNNLpt->Scale(1.0e3/(25*nevents));
        h_PUNNNLpt->Scale(1.0e3/(25*nevents));
        h_PUNNNNLpt->Scale(1.0e3/(25*nevents));

        h_PULpt->GetYaxis()->SetTitle("rate MHz");
        h_PUNLpt->GetYaxis()->SetTitle("rate MHz");
        h_PUNNLpt->GetYaxis()->SetTitle("rate MHz");
        h_PUNNNLpt->GetYaxis()->SetTitle("rate MHz");
        h_PUNNNNLpt->GetYaxis()->SetTitle("rate MHz");

        h_PULpt->GetXaxis()->SetTitle("P_{t} [MeV/c]");
        h_PUNLpt->GetXaxis()->SetTitle("P_{t} [MeV/c]");
        h_PUNNLpt->GetXaxis()->SetTitle("P_{t} [MeV/c]");
        h_PUNNNLpt->GetXaxis()->SetTitle("P_{t} [MeV/c]");
        h_PUNNNNLpt->GetXaxis()->SetTitle("P_{t} [MeV/c]");

	h_PUNNNNLpt->Draw();
	h_PUNNNLpt->Draw("same");
	h_PUNNLpt->Draw("same");
	h_PUNLpt->Draw("same");
	h_PULpt->Draw("same");

        //! Write histograms to output_file_name
        //const char* out_path = "/media/munmun/Z/PhD/ATHENA/plots";
	char out_file_root[1023];
        sprintf(out_file_root,"%s/%s.root",out_path,output_file_name);
        TFile* output_file = new TFile(out_file_root, "RECREATE");

        h_PULpt->Write();
        h_PUNLpt->Write();
        h_PUNNLpt->Write();
        h_PUNNNLpt->Write();
        h_PUNNNNLpt->Write();
        c1->Write();
        output_file->Close();

        //! Save as pdf
        char out_file_open[1023];
        sprintf(out_file_open,"%s/%s.pdf(",out_path,output_file_name);
        char out_file_[1023];
        sprintf(out_file_,"%s/%s.pdf",out_path,output_file_name);
        char out_file_close[1023];
        sprintf(out_file_close,"%s/%s.pdf)",out_path,output_file_name);

        TCanvas *C = new TCanvas();
        gStyle->SetOptStat(0);

        h_PULpt->Draw();
        C->Print(out_file_open,"pdf");
        h_PUNLpt->Draw();
        C->Print(out_file_,"pdf");
        h_PUNNLpt->Draw();
        C->Print(out_file_,"pdf");
        h_PUNNNLpt->Draw();
        C->Print(out_file_,"pdf");
	h_PUNNNNLpt->Draw();
        C->Print(out_file_,"pdf");


        //! plot same
        Double_t x1= 0.805,y1= 0.6, x2 = 0.995, y2 = 0.9;

        //PUNNNLpt->GetYaxis()->SetRangeUser(1e-2, 5 * h_PULpt->GetMaximum());
        h_PUNNNNLpt->Draw();
        h_PUNNNLpt->Draw("same");
        h_PUNNLpt->Draw("same");
        h_PUNLpt->Draw("same");
        //h_PULpt->Draw("same");
        C->SetLogy();
	C->SetGridx();
	C->SetGridy();
        TLegend *leg2=new TLegend(x1,y1,x2,y2,"P_{t}");
        //leg2->AddEntry(h_PULpt,"highest");
        leg2->AddEntry(h_PUNLpt,"2nd highest");
        leg2->AddEntry(h_PUNNLpt,"3rd highest");
        leg2->AddEntry(h_PUNNNLpt,"4th highest");
        leg2->AddEntry(h_PUNNNNLpt,"5th highest");
        leg2->Draw();
	C->Update();
        C->Print(out_file_close,"pdf");


	return 0;
}
