//Efficiency Vs  pt plots
/// e = #reconstructed(cut + matched)/#truth(cut)
/// here cut is applied on the truth parameters both in the numerator and denominator
/// new path of reconstructed files: /media/tamasi/DriveT/tamasi/Desktop/PHD/work/rec_data

#include <iostream>
#include <limits>
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TCut.h"
#include "TCanvas.h"
#include "TChain.h"
using namespace std;
    TCut num_select_mu      = " abs(pdg)==13 && r_tid>0 && abs(Vz)<100 && abs(Vx)<15 && abs(Vy)<15 ";
    TCut den_select_mu      = " abs(pdg)==13 && r_tid>= 0 && abs(Vz)<100 && abs(Vx)<15 && abs(Vy)<15 ";

void plot_efficiency
(
     const char* output_file_name = "receff_vs_ptTChaintestsinglePclePhi13.root",
    /*const std::string& suffix = "png",
    const long num_events = std::numeric_limits<long>::max(),*/
    const bool verbose = true,
    const bool together = false
)
{
    // open the file and get the tree
    /*char in_file[1023];
    const char* pathi = "/afs/cern.ch/work/t/tkar/testarea/20.20.10.1/WorkArea/run/rec_outputs";
//    const char* pathi = "/media/tamasi/DriveT/tamasi/Desktop/PHD/work/rec_data";
    sprintf(in_file,"%s/%s",pathi,input_file_name);
    TFile* input_file = TFile::Open(in_file,"READ");
    if(input_file->IsZombie())
    {
        cout<<"[plot_efficiency] Error : " << input_file_name << " is not found or is zombie.  Exiting..." << endl;
        return;
    }
    TTree* sim = (TTree*)(input_file->Get("m_truthTree"));
*/

	TChain sim("m_truthTree");
	sim.Add("/afs/cern.ch/work/t/tkar/testarea/20.20.10.1/WorkArea/run/rec_outputs/SingleParticles_Aug162k18/*.root");
    if(verbose)
    {
        cout<< "Simulated tree opened with "<< sim.GetEntries() <<"entries."<< endl;
    }
    int ptbin = 12; //30
    //Float_t bins[]={1800, 3800, 7500, 12000, 22000, 32000,42000,52000,62000,72000,82000,92000,102000};
    Float_t bins[] = {0, 4500, 5500, 14500, 25500, 34500,45500,54500,65500,74500,85500,94500,105500};

	//double ptmin = 2000, ptmax = 100000;
    //!book Histograms
    TH1::SetDefaultSumw2(true);
    TH1* h_num_vs_pt       = new TH1F("h_num_vs_pt", "Numerator Count vs P_{t};P_{t};Numerator Count"    , ptbin,bins);
    TH1* h_den_vs_pt       = new TH1F("h_den_vs_pt", "Denominator Count vs P_{t};P_{t};Denominator Count", ptbin,bins);
    //! Fill Histograms with Tree Draw
    sim.Draw("pt>>h_num_vs_pt",   num_select_prim, "goff"/*, num_events*/);
    sim.Draw("pt>>h_den_vs_pt",   den_select_prim, "goff"/*, num_events*/);

    //!Make efficiency plot
    TH1* h_eff_vs_eta = dynamic_cast<TH1*>(h_num_vs_pt->Clone("h_eff_vs_eta"));
    h_eff_vs_eta->SetTitle("Efficiency vs P_{t};P_{t};Efficiency");
    h_eff_vs_eta->Divide(h_num_vs_pt, h_den_vs_pt, 1.0, 1.0, "B");
    h_eff_vs_eta->GetYaxis()->SetRangeUser(0.1, 1.3);
    h_eff_vs_eta->SetMarkerSize(0.75);
    h_eff_vs_eta->SetMarkerStyle(20);
    h_eff_vs_eta->SetMarkerColor(kBlack);
        // write the output
//    if (suffix == "png" or suffix == "pdf" or suffix == "eps")
//    {
        if (verbose)
        {
            cout << "[plot_efficiency] printing plots to plots directory." << endl;
        }
                TCanvas* C1 = new TCanvas();   h_num_vs_pt->Draw(); C1->Update();
                TCanvas* C2 = new TCanvas();   h_den_vs_pt->Draw(); C2->Update();
                TCanvas* C3 = new TCanvas();   h_eff_vs_eta->Draw(); C3->Update();

//        TCanvas* c1 = new TCanvas();   h_num_vs_pt->Draw(); c1->Update();
//        TCanvas* c2 = new TCanvas();   h_den_vs_pt->Draw(); c2->Update();
//        TCanvas* c3 = new TCanvas();   h_eff_vs_eta->Draw(); c3->Update();
//        TCanvas* c1 = new TCanvas();   h_num_vs_theta->Draw(); c1->Update();
//        TCanvas* c2 = new TCanvas();   h_den_vs_theta->Draw(); c2->Update();
//        TCanvas* c3 = new TCanvas();   h_eff_vs_theta->Draw(); c3->Update();





//        c1.Print(Form("plots/%s_compiled.%s", h_num_vs_pt->GetName(), suffix.c_str()));
//        c2.Print(Form("plots/%s_compiled.%s", h_den_vs_pt->GetName(), suffix.c_str()));
//        c3.Print(Form("plots/%s_compiled.%s", h_eff_vs_eta->GetName(), suffix.c_str()));
//    }
/*                if(together)
                {
                    TCanvas* C = new TCanvas();
                    h_eff_vs_eta->Scale(1.0/h_eff_vs_eta->Integral());
                    h_eff_vs_eta->Draw();

                    h_eff_vs_eta_pi->Scale(1.0/h_eff_vs_eta_pi->Integral());
                    h_eff_vs_eta_pi->SetLineColor(kRed);
                    h_eff_vs_eta_pi->Draw("same");
                    C->Update();
                }
*/
    // output the file
    if (verbose)
    {
        cout << "[plot_efficiency] writing plots to " << output_file_name << endl;
    }
               //const char* path = "/home/tamasi/repo_tamasi/mu3e/run/my_macros/new_plots/efficieny_purity";
               const char* path = "/eos/user/t/tkar/www/TTT/plots/efficiency";
                char out_file [1023];
                sprintf(out_file,"%s/%s",path,output_file_name);
                TFile output_file(out_file, "RECREATE");
		gStyle->SetOptStat(0);
                /*h_num_vs_pt->Write();
                h_den_vs_pt->Write();
                h_eff_vs_eta->Write();*/
                h_num_vs_pt_mu->Write();
                h_den_vs_pt_mu->Write();
                h_eff_vs_eta_mu->Write();
                h_num_vs_pt_e->Write();
                h_den_vs_pt_e->Write();
                h_eff_vs_eta_e->Write();
                h_num_vs_pt_pi->Write();
                h_den_vs_pt_pi->Write();
                h_eff_vs_eta_pi->Write();
		TCanvas *C = new TCanvas();
		h_eff_vs_eta_mu->Draw();
		h_eff_vs_eta_e->Draw("same");
		h_eff_vs_eta_pi->Draw("same");
		C->Write();		
//    T->Fill();
   output_file.Write();
   output_file.Close();

}
