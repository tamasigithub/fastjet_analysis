#include <iostream>
#include <vector>
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"

int read_out(bool debug = false )
{
gInterpreter->GenerateDictionary("vector<vector<double> >","vector");
//gInterpreter->GenerateDictionary("vector<vector<int> >","vector");
int event,njets;
std::vector<double>* jetpt = nullptr;
std::vector<int>* Nconst = nullptr;
std::vector<std::vector<double>>* jetconstpt = nullptr;

TFile* f = new TFile("test_jetout1.root","READ");
TTree* t = (TTree*) f->Get("glob_jet");
t->SetBranchAddress("event", &event);
t->SetBranchAddress("Njets", &njets);
t->SetBranchAddress("jetPt", &jetpt);
t->SetBranchAddress("jetConstPt", &jetconstpt);
t->SetBranchAddress("Nconstituents", &Nconst);

int nentries = t->GetEntries();
std::cout<<"nentries : " << nentries <<std::endl;

for(int i = 0; i < nentries ; ++i)
{
	jetpt->clear();
	jetconstpt->clear();
	Nconst->clear();
	t->GetEntry(i);
	if(debug){
	std::cout<<"for event i " << i << ", event = " << ", number of track jets = " << njets <<std::endl;
	std::cout<<"cross check njets : " << jetpt->size() << std::endl;}

	for(size_t irec = 0; irec < jetpt->size(); ++irec)
	{
		if(debug){
		//! print information
		std::cout<<"number of constituents in jet " << irec << " is : " << (*jetconstpt)[irec].size() << std::endl;
		std::cout<<"number of constituents in jet cross check " << irec << " is : " << (*Nconst)[irec] << std::endl;}
		for(size_t jrec = 0; jrec < (*jetconstpt)[irec].size(); ++jrec)
		{
			std::cout<<"event, njets, ith_jet, jth_const, jetPt, constPt : " << event << ", " << njets << ", " << irec << " , " << jrec << " , " << (*jetpt)[irec] << ", " << (*jetconstpt)[irec][jrec] << std::endl;
		}
	}
}
return 0;
}
