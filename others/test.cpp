#include<iostream>
#include "TFile.h"
#include "TTree.h"

int main()
{

	TFile *f = new TFile("output.root", "READ");
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
	for(int i = 0; i < 1; i++)
	{
		t->GetEntry(i);
		for(int j = 0; j < bar->size(); j++)
		{
			if(j != (*bar)[j])std::cout<<"j " << j << ", barcode: " << (*bar)[j]<< std::endl;
		}
	}
return 0;
}
int test()
{

	TFile *f = new TFile("MomChild.root", "READ");
	TTree *t = (TTree*)f->Get("CollectionTree");

	const char *out_path = "../analysis_plots/pdf"; 
	const char *output_file_name = "testMomChild";
	const char *root_file_name = "../root_files/testMomChild.root";
	//////////////////////////////////////////////////
	//////////////// writing to pdf //////////////////
	//////////////////////////////////////////////////
	char out_file_open[1023];
        sprintf(out_file_open,"%s/%s.pdf(",out_path,output_file_name);
        char out_file_[1023];
        sprintf(out_file_,"%s/%s.pdf",out_path,output_file_name);
        char out_file_close[1023];
        sprintf(out_file_close,"%s/%s.pdf)",out_path,output_file_name);


	TFile *f_out = new TFile(root_file_name, "RECREATE");
	TCanvas *c1 = new TCanvas();
	TCanvas *c = new TCanvas();
	c->Divide(2,2);
	c->cd(1);
	TPad *mypad = (TPad*)gPad;
	t->Draw("FS_mother1PdgId","F_hTag && abs(FS_mother1PdgId)<10","hist");
	c->cd(2);
	t->Draw("FS_mother2PdgId","F_hTag && abs(FS_mother2PdgId)<10","hist");
	c->cd(3);
	t->Draw("FS_mother1PdgId","F_hTag==0 && abs(FS_mother1PdgId)<10","hist");
	c->cd(4);
	t->Draw("FS_mother2PdgId","F_hTag==0 && abs(FS_mother2PdgId)<10","hist");
	c->Print(out_file_open,"pdf");
	mypad->SetPad(0,0,1,1);
	c1->cd();
	mypad->DrawClone();
	c1->Write("c1");
	

	c->cd(1);
	t->Draw("FS_mother1PdgId","F_hTag && abs(FS_mother1PdgId)>10","hist");
	c->cd(2);
	t->Draw("FS_mother2PdgId","F_hTag && abs(FS_mother2PdgId)>10","hist");
	c->cd(3);
	t->Draw("FS_mother1PdgId","F_hTag==0 && abs(FS_mother1PdgId)>10","hist");
	c->cd(4);
	t->Draw("FS_mother2PdgId","F_hTag==0 && abs(FS_mother2PdgId)>10","hist");
	c->Print(out_file_,"pdf");
	mypad->SetPad(0,0,1,1);
	c1->cd();
	mypad->DrawClone();
	c1->Write("c2");
	
	c->cd(1);	
	t->Draw("FS_mother1Status","F_hTag && abs(FS_mother1PdgId)<10","hist");
	c->cd(2);
	t->Draw("FS_mother2Status","F_hTag && abs(FS_mother2PdgId)<10","hist");
	c->cd(3);
	t->Draw("FS_mother1Status","F_hTag==0 && abs(FS_mother1PdgId)<10","hist");
	c->cd(4);
	t->Draw("FS_mother2Status","F_hTag==0 && abs(FS_mother2PdgId)<10","hist");
	c->Print(out_file_,"pdf");
	mypad->SetPad(0,0,1,1);
	c1->cd();
	mypad->DrawClone();
	c1->Write("c3");
	
	c->cd(1);
	t->Draw("FS_mother1Status","F_hTag && abs(FS_mother1PdgId)>10","hist");
	c->cd(2);
	t->Draw("FS_mother2Status","F_hTag && abs(FS_mother2PdgId)>10","hist");
	c->cd(3);
	t->Draw("FS_mother1Status","F_hTag==0 && abs(FS_mother1PdgId)>10","hist");
	c->cd(4);
	t->Draw("FS_mother2Status","F_hTag==0 && abs(FS_mother2PdgId)>10","hist");
	c->Print(out_file_,"pdf");
	mypad->SetPad(0,0,1,1);
	c1->cd();
	mypad->DrawClone();
	c1->Write("c4");

	c->cd(1);
	t->Draw("F_PdgId","F_hTag && abs(F_PdgId)<10","hist");
	c->cd(2);
	t->Draw("F_PdgId","F_hTag==0 && abs(F_PdgId)<10","hist");
	c->cd(3);
	t->Draw("F_PdgId","F_hTag && abs(F_PdgId)>10","hist");
	c->cd(4);
	t->Draw("F_PdgId","F_hTag==0 && abs(F_PdgId)>10","hist");
	c->Print(out_file_,"pdf");
	
	c->cd(1);	
	t->Draw("F_Status","F_hTag && abs(F_PdgId)<10","hist");
	c->cd(2);
	t->Draw("F_Status","F_hTag==0 && abs(F_PdgId)<10","hist");
	c->cd(3);
	t->Draw("F_Status","F_hTag && abs(F_PdgId)>10","hist");
	c->cd(4);
	t->Draw("F_Status","F_hTag==0 && abs(F_PdgId)>10","hist");
	c->Print(out_file_close,"pdf");
	f_out->Close();

return 0;
}
