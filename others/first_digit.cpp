
#include<iostream>
#include<vector>
#include"TROOT.h"


template<typename T>
inline T first_digit(T a)
{
        return (int)(a / std::pow(10, (int)(log10(a))));
}

void first_digit()
{
	//std::vector<uint32_t> *TID = nullptr;
	std::vector<int> *TID = nullptr;
	

	TChain c("tracks");
	c.Add("/media/tamasi/wdElements/PhD/FCC/data_files/rec_files/30mm/PU1k/ggFhh4b_SM_1/*.root");

	c.SetBranchAddress("tid", &TID);
	//for(int i = 0; i < c.GetEntries(); i++)
	for(int i = 0; i < 1; i++)
	{
	
		c.GetEntry(i);
		for(int ik = 0; ik < TID->size(); ik++)
		{
			if(first_digit((*TID)[ik]) == 1) std::cout<<"Tid : " << (*TID)[ik] <<" first digit : " << first_digit((*TID)[ik]) <<std::endl;
			//if(first_digit((*TID)[ik]) == 1) std::cout <<"hard event found for event:" << i << " with TID: " <<(*TID)[ik] <<std::endl; 
		}
	}
	std::cout<<"Tid size : " << TID->size() <<std::endl;

	return;
}
