#include<iostream>
#include"TFile.h"
#include"TTree.h"
#include<vector>

int mother_daughter()
{

	bool debug = false;
	TFile *f = new TFile("../root_files/output.root","READ");
	TTree *t = (TTree*)f->Get("CollectionTree");
	std::vector<int> *d1 = nullptr;
	std::vector<int> *d2 = nullptr;
	std::vector<int> *m1 = nullptr;
	std::vector<int> *m2 = nullptr;
	std::vector<int> *bar = nullptr;
	std::vector<int> *pid = nullptr;
	std::vector<int> *stat = nullptr;

	t->SetBranchAddress("daughter1", &d1);
	t->SetBranchAddress("daughter2", &d2);
	t->SetBranchAddress("mother1", &m1);
	t->SetBranchAddress("mother2", &m2);
	t->SetBranchAddress("barcode", &bar);
	t->SetBranchAddress("pdgId", &pid);
	t->SetBranchAddress("status", &stat);
	 
	TFile *fout = new TFile("../root_files/MomChild.root","RECREATE");
 
	std::vector<int> FS_mother1; 
	std::vector<int> FS_mother2; 
	std::vector<int> FS_PdgId; 
	std::vector<int> FS_Status; 
	std::vector<int> FS_Barcode;
	std::vector<int> FS_mother1PdgId;
	std::vector<int> FS_mother2PdgId;
	std::vector<int> FS_mother1Status;
	std::vector<int> FS_mother2Status;
	std::vector<int> F_mother1; 
	std::vector<int> F_mother2; 
	std::vector<int> F_PdgId; 
	std::vector<int> F_Status; 
	std::vector<int> F_Barcode;
	std::vector<int> F_bTag; 
	std::vector<int> F_hTag;
	
	TTree *CollectionTree = new TTree("CollectionTree","Final State particle and their 1st moms");
	
	CollectionTree->Branch("FS_mother1", &FS_mother1); 
	CollectionTree->Branch("FS_mother2", &FS_mother2); 
	CollectionTree->Branch("FS_PdgId",   &FS_PdgId); 
	CollectionTree->Branch("FS_Status",  &FS_Status); 
	CollectionTree->Branch("FS_Barcode", &FS_Barcode);
	CollectionTree->Branch("FS_mother1PdgId",  &FS_mother1PdgId);
	CollectionTree->Branch("FS_mother2PdgId",  &FS_mother2PdgId);
	CollectionTree->Branch("FS_mother1Status", &FS_mother1Status);
	CollectionTree->Branch("FS_mother2Status", &FS_mother2Status); 
	CollectionTree->Branch("F_mother1",  &F_mother1); 
	CollectionTree->Branch("F_mother2",  &F_mother2);
	CollectionTree->Branch("F_PdgId",    &F_PdgId); 
	CollectionTree->Branch("F_Status",   &F_Status); 
	CollectionTree->Branch("F_Barcode",  &F_Barcode);
	CollectionTree->Branch("F_bTag",     &F_bTag); 
	CollectionTree->Branch("F_hTag",     &F_hTag);
	
	for(int i = 0; i < t->GetEntries(); i++)
	//for(int i = 0; i < 1; i++)
	{
		FS_mother1.clear(); 
		FS_mother2.clear(); 
		FS_PdgId.clear(); 
		FS_Status.clear(); 
		FS_Barcode.clear(); 
		FS_mother1PdgId.clear();
		FS_mother2PdgId.clear();
		FS_mother1Status.clear();
		FS_mother2Status.clear();
		
		F_mother1.clear(); 
		F_mother2.clear(); 
		F_PdgId.clear(); 
		F_Status.clear(); 
		F_Barcode.clear(); 
		
		F_bTag.clear(); 
		F_hTag.clear();
		

		t->GetEntry(i);
		std::cout<<"Entry Number / Event Number : " << i <<std::endl;
		for(int j = 0; j < bar->size(); j++)
		{
			if((*stat)[j] == 1)
			{
				int FS_m1 = (*m1)[j];
				int FS_m2 = (*m2)[j];

				FS_mother1.push_back(FS_m1);
				FS_mother2.push_back(FS_m2);
				FS_PdgId.push_back((*pid)[j]);
				FS_Status.push_back((*stat)[j]);
				FS_Barcode.push_back((*bar)[j]);
				FS_mother1PdgId.push_back((*pid)[FS_m1]);
				FS_mother2PdgId.push_back((*pid)[FS_m2]);
				FS_mother1Status.push_back((*stat)[FS_m1]);
				FS_mother2Status.push_back((*stat)[FS_m2]);

			}

		}
		//! For each FS particle in event i
		for(int k = 0; k < FS_Barcode.size(); k++)
		{
			int FS_m1 = FS_mother1[k];
			int FS_m2 = FS_mother2[k];
			//int FS_bar = FS_Barcode[k];

			bool Proton_found = false;
			int status_ = 0;
			int bar_, pid_ = 0;
			int b_tag = 0, h_tag = 0;
			if(debug) std::cout<<"1. FS_m1, FS_m2: " << FS_m1 << ", " << FS_m2 <<std::endl;

			//! loop over all particles in the ith event
			int j = bar->size() - 1;
			//for(int j = 0; j < bar->size(); j++)
			//while( (j < bar->size()) && (!Proton_found))
			while( (j >= 0) && (!Proton_found))
			{
				
				status_ = (*stat)[j];
				if(status_ == 1) 
				{	
					j--;
					continue;
				}

				bar_ = (*bar)[j];
				pid_ = (*pid)[j];
					

				if(FS_m1 == bar_ || FS_m2 == bar_)
				{
					FS_m1 = (*m1)[j];
					FS_m2 = (*m2)[j];
					if(debug) std::cout<<"2. FS_m1, FS_m2: " << FS_m1 << ", " << FS_m2 <<std::endl;
					
					if(status_==23 && abs(pid_)==5)
					{
						//b tag this FS particle
						b_tag = bar_;
						j--;
						continue;
						
					}
					else if(status_==62 && pid_==25)
					{
						//h tag this FS particle
						h_tag = bar_;
						j--;
						continue;
					}
					else if(FS_m2 == 0)
					{
						if(FS_m1==1 || FS_m1==2)
						{
							Proton_found = true;
							if(debug)
							{
							        std::cout<<"Yayyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy"<<std::endl;	
								std::cout<<"3. FS_m1, FS_m2: " << FS_m1 << ", " << FS_m2 <<std::endl;
							}
							break;

						}
						else
						{
							j = std::max(FS_m1, FS_m2);
							//j = bar->size() - 1;

							continue;
						}
					}
					else 
					{
						j = std::max(FS_m1, FS_m2);
						//j = bar->size() - 1;
						continue;
					}

				}
				else 
				{
					j--;
					continue;
				}
				
				
			}

			//! Fill very first mother particle
			if(Proton_found)
			{
				F_mother1.push_back(FS_m1); 
				F_mother2.push_back(FS_m2); 
				F_PdgId.push_back(pid_); 
				F_Status.push_back(status_); 
				F_Barcode.push_back(bar_); 
				
				F_bTag.push_back(b_tag); 
				F_hTag.push_back(h_tag);
			}

		}

		CollectionTree->Fill();
	}
	CollectionTree->Write();
	fout->Close();
	return 0;
}
