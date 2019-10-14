#include <iostream>
#include <fstream>
#include <string>
#include<math.h>

#include "TROOT.h"
#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TTree.h"

std::vector<int> count_higgs_b(std::vector<int> *p)
{

	std::vector<int> N(2, 0);
	for(int i = 0; i < p->size(); i++)
	{
		if ((*p)[i] == 25) N[0]++;
		else if (std::abs((*p)[i]) == 5) N[1]++;
	}
        return N;
}
//int count_bQuarks(std::vector<int> *p)
//{
//
//
//        return NbQuarks;
//}

int main()
{
	std::vector<int> *pdg = 0;
	std::vector<int> *status = 0;
        TChain c("CollectionTree");
        c.Add("/media/tamasi/Z/PhD/FCC/Castellated/data_files/user.tkar.pp_ggF_Ctr1.0hh_pythia82_NoGenCuts.v2_output.root/*.root");
        c.SetBranchStatus("*",0);
        c.SetBranchStatus("pdgId",1);
        c.SetBranchStatus("status",1);
        c.SetBranchAddress("pdgId", &pdg);
        c.SetBranchAddress("status", &status);
	std::cout<<"Total number of entries: " <<c.GetEntries()<<std::endl;
        for(int i = 0; i < c.GetEntries(); i++)
        //for(int i = 0; i < 10; i++)
        {
                c.GetEntry(i);
		//std::cout<<"pdg: " <<(*pdg)[i] <<std::endl;
		std::vector<int> N_ = count_higgs_b(pdg);
		int Nhiggs = N_[0];
		int Nbs = N_[1];
		int status_ = (*status)[i];
                if (Nhiggs != 2 && status_ != 22) 
		{
			std::cout<<"higgs count = " << Nhiggs << " , for event " << i << std::endl;
			c.Show(i);
		}
                if (Nbs != 4 && status_ != 23) 
		{
			std::cout<<"b quark count = " << Nbs << " , for event " << i << std::endl;
			c.Show(i);
		}

        }

        return 0;
}
