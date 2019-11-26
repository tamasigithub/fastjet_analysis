#include "GenAnalysis_smeared.h"
#include "GenAna_1.cpp"
#include "GenAna_0.cpp"
#include "GenAna__1.cpp"
#include "GenAna__2.cpp"
#include "GenAna_2.cpp"
#include "GenAna_2_5.cpp"
#include "GenAna_3.cpp"
#include "GenAna_bckgnd.cpp"


void Set_FinalbJetColors()
{
	// invariant mass of a pair of b's, ctr = 1.0
	M_b1b2_1->SetLineColor(kRed);
	M_b1b3_1->SetLineColor(kBlack);
	M_b1b4_1->SetLineColor(kGreen);
	M_b2b3_1->SetLineColor(kBlue);
	M_b2b4_1->SetLineColor(kOrange - 9);
	M_b3b4_1->SetLineColor(kViolet);    
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_1->SetLineColor(kRed);
	dM_b1b3_b2b4_1->SetLineColor(kBlack);
	dM_b1b4_b2b3_1->SetLineColor(kGreen);

	// invariant mass of a pair of b's, pp->4b
	M_b1b2_B->SetLineColor(kRed);        
	M_b1b3_B->SetLineColor(kBlack);      
	M_b1b4_B->SetLineColor(kGreen);      
	M_b2b3_B->SetLineColor(kBlue);       
	M_b2b4_B->SetLineColor(kOrange - 9); 
	M_b3b4_B->SetLineColor(kViolet);     
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	dM_b1b2_b3b4_B->SetLineColor(kRed);  
	dM_b1b3_b2b4_B->SetLineColor(kBlack);
	dM_b1b4_b2b3_B->SetLineColor(kGreen);

}

void Set_LegendProps()
{

	leg_higgs_1->SetFillStyle(0);
	leg_higgs_1->SetBorderSize(0);
	leg_higgs_1->SetTextAlign(32);
	leg_higgs_1->SetTextFont(62);
	leg_higgs_1->SetTextSize(0.055);
	
	leg_higgs->SetFillStyle(0);
	leg_higgs->SetBorderSize(0);
	leg_higgs->SetTextAlign(32);
	leg_higgs->SetTextFont(62);
	leg_higgs->SetTextSize(0.035);

	leg1->SetFillStyle(0);
	leg1->SetBorderSize(0);
	leg1->SetTextAlign(32);
	leg1->SetTextFont(62);
	leg1->SetTextSize(0.035);

	leg2->SetFillStyle(0);
	leg2->SetBorderSize(0);
	leg2->SetTextAlign(32);
	leg2->SetTextFont(62);
	leg2->SetTextSize(0.035);

	leg3->SetFillStyle(0);
	leg3->SetBorderSize(0);
	leg3->SetTextAlign(32);
	leg3->SetTextFont(62);
	leg3->SetTextSize(0.035);

	leg4->SetFillStyle(0);
	leg4->SetBorderSize(0);
	leg4->SetTextAlign(32);
	leg4->SetTextFont(62);
	leg4->SetTextSize(0.035);
	
	leg5->SetFillStyle(0);
	leg5->SetBorderSize(0);
	leg5->SetTextAlign(32);
	leg5->SetTextFont(62);
	leg5->SetTextSize(0.035);
	
	leg6->SetFillStyle(0);
	leg6->SetBorderSize(0);
	leg6->SetTextAlign(32);
	leg6->SetTextFont(62);
	leg6->SetTextSize(0.035);
	return;
}




int main()
{
	
	f1  = new TFile(inp_file1,"READ");
	f0  = new TFile(inp_file0,"READ");
	f_1 = new TFile(inp_file_1,"READ");
	f_2 = new TFile(inp_file_2,"READ");
	f2  = new TFile(inp_file2,"READ");
	f2_5= new TFile(inp_file2_5,"READ");
	f3  = new TFile(inp_file3,"READ");
	fB  = new TFile(inp_fileB,"READ");
	
        TH1::SetDefaultSumw2(true);
	fetch_TTrees_1();
	fetch_TTrees_0();
	fetch_TTrees__1();
	fetch_TTrees__2();
	fetch_TTrees_2();
	fetch_TTrees_2_5();
	fetch_TTrees_3();
	fetch_TTrees_B();
	//! get the normalization for an integrated luminosity of 10 ab-1 data
	//int tot_MCevents = get_Nentries();
	//int tot_MCevents = get_Nentries();
	int tot_MCevents = 5e5;
	double norm_signal1, norm_signal0, norm_signal_1, norm_signal_2, norm_signal2, norm_signal2_5, norm_signal3;
	norm_signal1   = (IntLumi * ggFhhXsec1)/tot_MCevents;
	norm_signal0   = (IntLumi * ggFhhXsec0)/tot_MCevents;
	norm_signal_1  = (IntLumi * ggFhhXsec_1)/tot_MCevents;
	norm_signal_2  = (IntLumi * ggFhhXsec_2)/tot_MCevents;
	norm_signal2   = (IntLumi * ggFhhXsec2)/tot_MCevents;
	norm_signal2_5 = (IntLumi * ggFhhXsec2_5)/tot_MCevents;
	norm_signal3   = (IntLumi * ggFhhXsec3)/tot_MCevents;
	double norm_bckgnd = (IntLumi * pp4bXsec)/tot_MCevents;
	std::cout<<"Number of signal and background events used =  " << tot_MCevents <<std::endl;
	std::cout<<"Total integrated luminosity  =  " << IntLumi*1e-3 << " ab-1" <<std::endl;
	std::cout<<"signal normalization used 1  =  " << norm_signal1 <<std::endl;
	std::cout<<"signal normalization used 0  =  " << norm_signal0 <<std::endl;
	std::cout<<"signal normalization used -1 =  " << norm_signal_1 <<std::endl;
	std::cout<<"signal normalization used -2 =  " << norm_signal_2 <<std::endl;
	std::cout<<"signal normalization used 2  =  " << norm_signal2 <<std::endl;
	std::cout<<"signal normalization used 2.5=  " << norm_signal2_5 <<std::endl;
	std::cout<<"signal normalization used 3  =  " << norm_signal3 <<std::endl;
	std::cout<<"background normalization used=  " << norm_bckgnd <<std::endl;

	Set_higgsPtProps_1();
	Set_higgsPtProps_0();
	Set_higgsPtProps__1();
	Set_higgsPtProps__2();
	Set_higgsPtProps_2();
	Set_higgsPtProps_2_5();
	Set_higgsPtProps_3();
	Set_higgsPtProps_B();

	Set_jetPtProps_1();
	Set_jetPtProps_0();
	Set_jetPtProps__1();
	Set_jetPtProps__2();
	Set_jetPtProps_2();
	Set_jetPtProps_2_5();
	Set_jetPtProps_3();
	Set_jetPtProps_B();
	
	Draw_higgsPt_1();
	Draw_higgsPt_0();
	Draw_higgsPt__1();
	Draw_higgsPt__2();
	Draw_higgsPt_2();
	Draw_higgsPt_2_5();
	Draw_higgsPt_3();
	//Draw_b_jetPt();
	
	fetch_histos_1();
	fetch_histos_0();
	fetch_histos__1();
	fetch_histos__2();
	fetch_histos_2();
	fetch_histos_2_5();
	fetch_histos_3();
	fetch_histos_B();
	
	Draw_Nparticles_1();
	Draw_Nparticles_0();
	Draw_Nparticles__1();
	Draw_Nparticles__2();
	Draw_Nparticles_2();
	Draw_Nparticles_2_5();
	Draw_Nparticles_3();
	Draw_Nparticles_B();
	
	Set_NleadingJetColors_1();
	Set_NleadingJetColors_0();
	Set_NleadingJetColors__1();
	Set_NleadingJetColors__2();
	Set_NleadingJetColors_2();
	Set_NleadingJetColors_2_5();
	Set_NleadingJetColors_3();
	Set_NleadingJetColors_B();

	Set_FinalbJetColors();
	//Set_FinalbJetColors_0();
	//Set_FinalbJetColors__1();
	//Set_FinalbJetColors__2();
	//Set_FinalbJetColors_2();
	//Set_FinalbJetColors_2_5();
	//Set_FinalbJetColors_3();
	//Set_FinalbJetColors_B();

	Draw_Number_bTags_1();
	Draw_Number_bTags_0();
	Draw_Number_bTags__1();
	Draw_Number_bTags__2();
	Draw_Number_bTags_2();
	Draw_Number_bTags_2_5();
	Draw_Number_bTags_3();
	Draw_Number_bTags_B();

	int n1 = 0, n0 = 0, n_1 = 0, n_2 = 0, n2 = 0, n2_5 = 0, n3 = 0, nB = 0;
	int nL1 = 0, nL0 = 0, nL_1 = 0, nL_2 = 0, nL2 = 0, nL2_5 = 0, nL3 = 0, nLB = 0;
	int nNL1 = 0, nNL0 = 0, nNL_1 = 0, nNL_2 = 0, nNL2 = 0, nNL2_5 = 0, nNL3 = 0, nNLB = 0;
	int nb1 = 0, nb0 = 0, nb_1 = 0, nb_2 = 0, nb2 = 0, nb2_5 = 0, nb3 = 0, nbB = 0;
	int nh1 = 0, nh0 = 0, nh_1 = 0, nh_2 = 0, nh2 = 0, nh2_5 = 0, nh3 = 0, nhB = 0;
	
	std::cout<<"N entries in t1: " <<t1->GetEntries() <<std::endl;
	std::cout<<"N entries in t0: " <<t0->GetEntries() <<std::endl;
	std::cout<<"N entries in t_1: " <<t_1->GetEntries() <<std::endl;
	std::cout<<"N entries in t_2: " <<t_2->GetEntries() <<std::endl;
	std::cout<<"N entries in t2: " <<t2->GetEntries() <<std::endl;
	std::cout<<"N entries in t2_5: " <<t2_5->GetEntries() <<std::endl;
	std::cout<<"N entries in t3: " <<t3->GetEntries() <<std::endl;
	std::cout<<"N entries in tB: " <<tB->GetEntries() <<std::endl;
		
	for(int i = 0; i < t1->GetEntries(); i++)
	//for(int i = 0; i < 50; i++)
	{
		t1->GetEntry(i);
		Draw_InvariantMass_1();
		Fill_InvariantMass_1();
		if (v1_jetPt->size() < min_Njets) continue;
		n1++;
		if((*v1_jetPt)[0]*1e-3 < minLeadingPt) continue;
		nL1++;
		if((*v1_jetPt)[1]*1e-3 < minSubLeadingPt) continue;
		nNL1++;
		Fill_NLeadingJetPtM_1();
		if(n1_btags < 4) continue;
		nb1++;
		Draw_DiJetInvariantMass_1();
		Fill_bjetPtM_1(nh1);

	}	
	std::cout<<"ctr = 1.0" <<std::endl;
	std::cout<<"n1 : " << n1 <<std::endl;
	std::cout<<"nL1 : " << nL1 <<std::endl;
	std::cout<<"nNL1 : " << nNL1 <<std::endl;
	std::cout<<"nb1 : " << nb1 <<std::endl;
	std::cout<<"nh1 : " << nh1 <<std::endl;

	for(int i = 0; i < t0->GetEntries(); i++)
	//for(int i = 0; i < 50; i++)
	{
		t0->GetEntry(i);
		Draw_InvariantMass_0();
		Fill_InvariantMass_0();
		if (v0_jetPt->size() < min_Njets) continue;
		n0++;
		if((*v0_jetPt)[0]*1e-3 < minLeadingPt) continue;
		nL0++;
		if((*v0_jetPt)[1]*1e-3 < minSubLeadingPt) continue;
		nNL0++;
		Fill_NLeadingJetPtM_0();
		if(n0_btags < 4) continue;
		nb0++;
		Draw_DiJetInvariantMass_0();
		Fill_bjetPtM_0(nh0);

	}
	std::cout<<"ctr = 0.0" <<std::endl;
	std::cout<<"n0 : " << n0 <<std::endl;
	std::cout<<"nL0 : " << nL0 <<std::endl;
	std::cout<<"nNL0 : " << nNL0 <<std::endl;
	std::cout<<"nb0 : " << nb0 <<std::endl;
	std::cout<<"nh0 : " << nh0 <<std::endl;
	
	for(int i = 0; i < t_1->GetEntries(); i++)
	//for(int i = 0; i < 50; i++)
	{
		t_1->GetEntry(i);
		Draw_InvariantMass__1();
		Fill_InvariantMass__1();
		if (v_1_jetPt->size() < min_Njets) continue;
		n_1++;
		if((*v_1_jetPt)[0]*1e-3 < minLeadingPt) continue;
		nL_1++;
		if((*v_1_jetPt)[1]*1e-3 < minSubLeadingPt) continue;
		nNL_1++;
		Fill_NLeadingJetPtM__1();
		if(n_1_btags < 4) continue;
		nb_1++;
		Draw_DiJetInvariantMass__1();
		Fill_bjetPtM__1(nh_1);

	}
	std::cout<<"ctr = -1.0" <<std::endl;
	std::cout<<"n_1 : " << n_1 <<std::endl;
	std::cout<<"nL_1 : " << nL_1 <<std::endl;
	std::cout<<"nNL_1 : " << nNL_1 <<std::endl;
	std::cout<<"nb_1 : " << nb_1 <<std::endl;
	std::cout<<"nh_1 : " << nh_1 <<std::endl;
	
	for(int i = 0; i < t_2->GetEntries(); i++)
	//for(int i = 0; i < 50; i++)
	{
		t_2->GetEntry(i);
		Draw_InvariantMass__2();
		Fill_InvariantMass__2();
		if (v_2_jetPt->size() < min_Njets) continue;
		n_2++;
		if((*v_2_jetPt)[0]*1e-3 < minLeadingPt) continue;
		nL_2++;
		if((*v_2_jetPt)[1]*1e-3 < minSubLeadingPt) continue;
		nNL_2++;
		Fill_NLeadingJetPtM__2();
		if(n_2_btags < 4) continue;
		nb_2++;
		Draw_DiJetInvariantMass__2();
		Fill_bjetPtM__2(nh_2);

	}
	std::cout<<"ctr = -2.0" <<std::endl;
	std::cout<<"n_2 : " << n_2 <<std::endl;
	std::cout<<"nL_2 : " << nL_2 <<std::endl;
	std::cout<<"nNL_2 : " << nNL_2 <<std::endl;
	std::cout<<"nb_2 : " << nb_2 <<std::endl;
	std::cout<<"nh_2 : " << nh_2 <<std::endl;
	
	for(int i = 0; i < t2->GetEntries(); i++)
	//for(int i = 0; i < 50; i++)
	{
		t2->GetEntry(i);
		Draw_InvariantMass_2();
		Fill_InvariantMass_2();
		if (v2_jetPt->size() < min_Njets) continue;
		n2++;
		if((*v2_jetPt)[0]*1e-3 < minLeadingPt) continue;
		nL2++;
		if((*v2_jetPt)[1]*1e-3 < minSubLeadingPt) continue;
		nNL2++;
		Fill_NLeadingJetPtM_2();
		if(n2_btags < 4) continue;
		nb2++;
		Draw_DiJetInvariantMass_2();
		Fill_bjetPtM_2(nh2);

	}
	std::cout<<"ctr = 2.0" <<std::endl;
	std::cout<<"n2 : " << n2 <<std::endl;
	std::cout<<"nL2 : " << nL2 <<std::endl;
	std::cout<<"nNL2 : " << nNL2 <<std::endl;
	std::cout<<"nb2 : " << nb2 <<std::endl;
	std::cout<<"nh2 : " << nh2 <<std::endl;
	
	for(int i = 0; i < t2_5->GetEntries(); i++)
	//for(int i = 0; i < 50; i++)
	{
		t2_5->GetEntry(i);
		Draw_InvariantMass_2_5();
		Fill_InvariantMass_2_5();
		if (v2_5_jetPt->size() < min_Njets) continue;
		n2_5++;
		if((*v2_5_jetPt)[0]*1e-3 < minLeadingPt) continue;
		nL2_5++;
		if((*v2_5_jetPt)[1]*1e-3 < minSubLeadingPt) continue;
		nNL2_5++;
		Fill_NLeadingJetPtM_2_5();
		if(n2_5_btags < 4) continue;
		nb2_5++;
		Draw_DiJetInvariantMass_2_5();
		Fill_bjetPtM_2_5(nh2_5);

	}
	std::cout<<"ctr = 2.5" <<std::endl;
	std::cout<<"n2_5 : " << n2_5 <<std::endl;
	std::cout<<"nL2_5 : " << nL2_5 <<std::endl;
	std::cout<<"nNL2_5 : " << nNL2_5 <<std::endl;
	std::cout<<"nb2_5 : " << nb2_5 <<std::endl;
	std::cout<<"nh2_5 : " << nh2_5 <<std::endl;
	
	for(int i = 0; i < t3->GetEntries(); i++)
	//for(int i = 0; i < 50; i++)
	{
		t3->GetEntry(i);
		Draw_InvariantMass_3();
		Fill_InvariantMass_3();
		if (v3_jetPt->size() < min_Njets) continue;
		n3++;
		if((*v3_jetPt)[0]*1e-3 < minLeadingPt) continue;
		nL3++;
		if((*v3_jetPt)[1]*1e-3 < minSubLeadingPt) continue;
		nNL3++;
		Fill_NLeadingJetPtM_3();
		if(n3_btags < 4) continue;
		nb3++;
		Draw_DiJetInvariantMass_3();
		Fill_bjetPtM_3(nh3);

	}
	std::cout<<"ctr = 3.0" <<std::endl;
	std::cout<<"n3 : " << n3 <<std::endl;
	std::cout<<"nL3 : " << nL3 <<std::endl;
	std::cout<<"nNL3 : " << nNL3 <<std::endl;
	std::cout<<"nb3 : " << nb3 <<std::endl;
	std::cout<<"nh3 : " << nh3 <<std::endl;
	
	for(int i = 0; i < tB->GetEntries(); i++)
	//for(int i = 0; i < 50; i++)
	{
		tB->GetEntry(i);
		Draw_InvariantMass_B();
		Fill_InvariantMass_B();
		if (vB_jetPt->size() < min_Njets) continue;
		nB++;
		if((*vB_jetPt)[0]*1e-3 < minLeadingPt) continue;
		nLB++;
		if((*vB_jetPt)[1]*1e-3 < minSubLeadingPt) continue;
		nNLB++;
		Fill_NLeadingJetPtM_B();
		if(nB_btags < 4) continue;
		nbB++;
		Draw_DiJetInvariantMass_B();
		Fill_bjetPtM_B(nhB);

	}
	std::cout<<"pp->4b" <<std::endl;
	std::cout<<"nB : " << nB <<std::endl;
	std::cout<<"nLB : " << nLB <<std::endl;
	std::cout<<"nNLB : " << nNLB <<std::endl;
	std::cout<<"nbB : " << nbB <<std::endl;
	std::cout<<"nhB : " << nhB <<std::endl;

	Scale_bckgndHistos(norm_bckgnd);	
	Scale_signalHistos1(norm_signal1);
	Scale_signalHistos0(norm_signal0);
	Scale_signalHistos_1(norm_signal_1);
	Scale_signalHistos_2(norm_signal_2);
	Scale_signalHistos2(norm_signal2);
	Scale_signalHistos2_5(norm_signal2_5);
	Scale_signalHistos3(norm_signal3);
	
	SetLineWidthB();	
	SetLineWidth1();
	SetLineWidth0();
	SetLineWidth_1();
	SetLineWidth_2();
	SetLineWidth2();
	SetLineWidth2_5();
	SetLineWidth3();
	//////////////////////////////////////////////////
	//////////////// writing to pdf //////////////////
	//////////////////////////////////////////////////
	char out_file_open[1023];
        sprintf(out_file_open,"%s/%s.pdf(",out_path,output_file_name);
        char out_file_[1023];
        sprintf(out_file_,"%s/%s.pdf",out_path,output_file_name);
        char out_file_close[1023];
        sprintf(out_file_close,"%s/%s.pdf)",out_path,output_file_name);

	Double_t x1 = 0.71, y1 = 0.71, x2 = 0.89, y2 = 0.89;

	leg_higgs_1 = new TLegend(0.5, 0.2, 0.9, 0.9, "");
	leg_higgs = new TLegend(x1, y1, x2, y2, "");
	leg1 = new TLegend(x1, y1, x2, y2, "");
	leg2 = new TLegend(x1, y1, x2, y2, "");
	leg3 = new TLegend(x1, y1, x2, y2, "");
	leg4 = new TLegend(x1, y1, x2, y2, "");
	leg5 = new TLegend(x1, y1, x2, y2, "");
	leg6 = new TLegend(x1, y1, x2, y2, "");

	Set_LegendProps();

	TCanvas * C = new TCanvas();
	//TCanvas * C = new TCanvas("C","C",800,800);
	gStyle->SetOptStat(0);
	//TGaxis::SetMaxDigits(2);
	C->SetGridx();
	C->SetGridy();
	C->SetTickx();
	C->SetTicky();
	//C->SetLogy();
	//! page1
	TLatex lat;
	lat.SetTextSize(0.03);
	lat.SetTextAlign(12);
	float Ylat, X1lat, X2lat, X3lat, X4lat, X5lat, X6lat, X7lat, X8lat, X9lat;
	float step = 0.06;
	Ylat = 0.96; 
	X1lat = 0.02;
	X2lat = X1lat + 2*0.095;
	X3lat = X2lat + 0.095;
	X4lat = X3lat + 0.095;
	X5lat = X4lat + 0.095;
	X6lat = X5lat + 0.095;
	X7lat = X6lat + 0.095;
	X8lat = X7lat + 0.095;
	X9lat = X8lat + 0.095;
	lat.DrawLatex(X1lat, Ylat, "N Events"); 
	lat.DrawLatex(X2lat, Ylat, "pp #rightarrow 4b");
	lat.DrawLatex(X3lat, Ylat, "k_{#lambda} = 1.0");
	lat.DrawLatex(X4lat, Ylat, "k_{#lambda} = 0.0");
	lat.DrawLatex(X5lat, Ylat, "k_{#lambda} = -1.0");
	lat.DrawLatex(X6lat, Ylat, "k_{#lambda} = -2.0");
	lat.DrawLatex(X7lat, Ylat, "k_{#lambda} = 2.0");
	lat.DrawLatex(X8lat, Ylat, "k_{#lambda} = 2.5");
	lat.DrawLatex(X9lat, Ylat, "k_{#lambda} = 3.0");

	Ylat -= step;
	lat.DrawLatex(X1lat, Ylat, "N_{jets} #geq 4");
	lat.DrawLatex(X2lat, Ylat, Form("%d", nB));
	lat.DrawLatex(X3lat, Ylat, Form("%d", n1));
	lat.DrawLatex(X4lat, Ylat, Form("%d", n0));
	lat.DrawLatex(X5lat, Ylat, Form("%d", n_1));
	lat.DrawLatex(X6lat, Ylat, Form("%d", n_2));
	lat.DrawLatex(X7lat, Ylat, Form("%d", n2));
	lat.DrawLatex(X8lat, Ylat, Form("%d", n2_5));
	lat.DrawLatex(X9lat, Ylat, Form("%d", n3));
	Ylat -= step;
	lat.DrawLatex(X1lat, Ylat, "S/#sqrt{B}");
	lat.DrawLatex(X2lat, Ylat, "--");
	lat.DrawLatex(X3lat, Ylat, Form("%.3f", (n1*norm_signal1)/std::sqrt(nB*norm_bckgnd)));
	lat.DrawLatex(X4lat, Ylat, Form("%.3f", (n0*norm_signal0)/std::sqrt(nB*norm_bckgnd)));
	lat.DrawLatex(X5lat, Ylat, Form("%.3f", (n_1*norm_signal_1)/std::sqrt(nB*norm_bckgnd)));
	lat.DrawLatex(X6lat, Ylat, Form("%.3f", (n_2*norm_signal_2)/std::sqrt(nB*norm_bckgnd)));
	lat.DrawLatex(X7lat, Ylat, Form("%.3f", (n2*norm_signal2)/std::sqrt(nB*norm_bckgnd)));
	lat.DrawLatex(X8lat, Ylat, Form("%.3f", (n2_5*norm_signal2_5)/std::sqrt(nB*norm_bckgnd)));
	lat.DrawLatex(X9lat, Ylat, Form("%.3f", (n3*norm_signal3)/std::sqrt(nB*norm_bckgnd)));

	Ylat -= step;
	lat.DrawLatex(X1lat, Ylat, "p_{T, L} #geq 55 GeV/c");
	lat.DrawLatex(X2lat, Ylat, Form("%d", nLB));
	lat.DrawLatex(X3lat, Ylat, Form("%d", nL1));
	lat.DrawLatex(X4lat, Ylat, Form("%d", nL0));
	lat.DrawLatex(X5lat, Ylat, Form("%d", nL_1));
	lat.DrawLatex(X6lat, Ylat, Form("%d", nL_2));
	lat.DrawLatex(X7lat, Ylat, Form("%d", nL2));
	lat.DrawLatex(X8lat, Ylat, Form("%d", nL2_5));
	lat.DrawLatex(X9lat, Ylat, Form("%d", nL3));
	Ylat -= step;
	lat.DrawLatex(X1lat, Ylat, "S/#sqrt{B}");
	lat.DrawLatex(X2lat, Ylat, "--");
	lat.DrawLatex(X3lat, Ylat, Form("%.3f", (nL1*norm_signal1)/std::sqrt(nLB*norm_bckgnd)));
	lat.DrawLatex(X4lat, Ylat, Form("%.3f", (nL0*norm_signal0)/std::sqrt(nLB*norm_bckgnd)));
	lat.DrawLatex(X5lat, Ylat, Form("%.3f", (nL_1*norm_signal_1)/std::sqrt(nLB*norm_bckgnd)));
	lat.DrawLatex(X6lat, Ylat, Form("%.3f", (nL_2*norm_signal_2)/std::sqrt(nLB*norm_bckgnd)));
	lat.DrawLatex(X7lat, Ylat, Form("%.3f", (nL2*norm_signal2)/std::sqrt(nLB*norm_bckgnd)));
	lat.DrawLatex(X8lat, Ylat, Form("%.3f", (nL2_5*norm_signal2_5)/std::sqrt(nLB*norm_bckgnd)));
	lat.DrawLatex(X9lat, Ylat, Form("%.3f", (nL3*norm_signal3)/std::sqrt(nLB*norm_bckgnd)));

	Ylat -= step;
	lat.DrawLatex(X1lat, Ylat, "p_{T, NL} #geq 40 GeV/c");
	lat.DrawLatex(X2lat, Ylat, Form("%d", nNLB));
	lat.DrawLatex(X3lat, Ylat, Form("%d", nNL1));
	lat.DrawLatex(X4lat, Ylat, Form("%d", nNL0));
	lat.DrawLatex(X5lat, Ylat, Form("%d", nNL_1));
	lat.DrawLatex(X6lat, Ylat, Form("%d", nNL_2));
	lat.DrawLatex(X7lat, Ylat, Form("%d", nNL2));
	lat.DrawLatex(X8lat, Ylat, Form("%d", nNL2_5));
	lat.DrawLatex(X9lat, Ylat, Form("%d", nNL3));
	Ylat -= step;
	lat.DrawLatex(X1lat, Ylat, "S/#sqrt{B}");
	lat.DrawLatex(X2lat, Ylat, "--");
	lat.DrawLatex(X3lat, Ylat, Form("%.3f", (nNL1*norm_signal1)/std::sqrt(nNLB*norm_bckgnd)));
	lat.DrawLatex(X4lat, Ylat, Form("%.3f", (nNL0*norm_signal0)/std::sqrt(nNLB*norm_bckgnd)));
	lat.DrawLatex(X5lat, Ylat, Form("%.3f", (nNL_1*norm_signal_1)/std::sqrt(nNLB*norm_bckgnd)));
	lat.DrawLatex(X6lat, Ylat, Form("%.3f", (nNL_2*norm_signal_2)/std::sqrt(nNLB*norm_bckgnd)));
	lat.DrawLatex(X7lat, Ylat, Form("%.3f", (nNL2*norm_signal2)/std::sqrt(nNLB*norm_bckgnd)));
	lat.DrawLatex(X8lat, Ylat, Form("%.3f", (nNL2_5*norm_signal2_5)/std::sqrt(nNLB*norm_bckgnd)));
	lat.DrawLatex(X9lat, Ylat, Form("%.3f", (nNL3*norm_signal3)/std::sqrt(nNLB*norm_bckgnd)));

	Ylat -= step;
	lat.DrawLatex(X1lat, Ylat, "N_{btags} #geq 4");
	lat.DrawLatex(X2lat, Ylat, Form("%d", nbB));
	lat.DrawLatex(X3lat, Ylat, Form("%d", nb1));
	lat.DrawLatex(X4lat, Ylat, Form("%d", nb0));
	lat.DrawLatex(X5lat, Ylat, Form("%d", nb_1));
	lat.DrawLatex(X6lat, Ylat, Form("%d", nb_2));
	lat.DrawLatex(X7lat, Ylat, Form("%d", nb2));
	lat.DrawLatex(X8lat, Ylat, Form("%d", nb2_5));
	lat.DrawLatex(X9lat, Ylat, Form("%d", nb3));
	Ylat -= step;
	lat.DrawLatex(X1lat, Ylat, "S/#sqrt{B}");
	lat.DrawLatex(X2lat, Ylat, "--");
	lat.DrawLatex(X3lat, Ylat, Form("%.3f", (nb1*norm_signal1)/std::sqrt(nbB*norm_bckgnd)));
	lat.DrawLatex(X4lat, Ylat, Form("%.3f", (nb0*norm_signal0)/std::sqrt(nbB*norm_bckgnd)));
	lat.DrawLatex(X5lat, Ylat, Form("%.3f", (nb_1*norm_signal_1)/std::sqrt(nbB*norm_bckgnd)));
	lat.DrawLatex(X6lat, Ylat, Form("%.3f", (nb_2*norm_signal_2)/std::sqrt(nbB*norm_bckgnd)));
	lat.DrawLatex(X7lat, Ylat, Form("%.3f", (nb2*norm_signal2)/std::sqrt(nbB*norm_bckgnd)));
	lat.DrawLatex(X8lat, Ylat, Form("%.3f", (nb2_5*norm_signal2_5)/std::sqrt(nbB*norm_bckgnd)));
	lat.DrawLatex(X9lat, Ylat, Form("%.3f", (nb3*norm_signal3)/std::sqrt(nbB*norm_bckgnd)));

	Ylat -= step;
	lat.DrawLatex(X1lat, Ylat, "|M_{h1,h2} - 125|  #leq 40");
	lat.DrawLatex(X2lat, Ylat, Form("%d", nhB));
	lat.DrawLatex(X3lat, Ylat, Form("%d", nh1));
	lat.DrawLatex(X4lat, Ylat, Form("%d", nh0));
	lat.DrawLatex(X5lat, Ylat, Form("%d", nh_1));
	lat.DrawLatex(X6lat, Ylat, Form("%d", nh_2));
	lat.DrawLatex(X7lat, Ylat, Form("%d", nh2));
	lat.DrawLatex(X8lat, Ylat, Form("%d", nh2_5));
	lat.DrawLatex(X9lat, Ylat, Form("%d", nh3));

	Ylat -= step;
	lat.DrawLatex(X1lat, Ylat, "S/#sqrt{B}");
	lat.DrawLatex(X2lat, Ylat, "--");
	lat.DrawLatex(X3lat, Ylat, Form("%.3f", (nh1*norm_signal1)/std::sqrt(nhB*norm_bckgnd)));
	lat.DrawLatex(X4lat, Ylat, Form("%.3f", (nh0*norm_signal0)/std::sqrt(nhB*norm_bckgnd)));
	lat.DrawLatex(X5lat, Ylat, Form("%.3f", (nh_1*norm_signal_1)/std::sqrt(nhB*norm_bckgnd)));
	lat.DrawLatex(X6lat, Ylat, Form("%.3f", (nh_2*norm_signal_2)/std::sqrt(nhB*norm_bckgnd)));
	lat.DrawLatex(X7lat, Ylat, Form("%.3f", (nh2*norm_signal2)/std::sqrt(nhB*norm_bckgnd)));
	lat.DrawLatex(X8lat, Ylat, Form("%.3f", (nh2_5*norm_signal2_5)/std::sqrt(nhB*norm_bckgnd)));
	lat.DrawLatex(X9lat, Ylat, Form("%.3f", (nh3*norm_signal3)/std::sqrt(nhB*norm_bckgnd)));
	
	Ylat -= step;
	lat.DrawLatex(X1lat, Ylat, "S/B");
	lat.DrawLatex(X2lat, Ylat, "--");
	lat.DrawLatex(X3lat, Ylat, Form("%.3e", (nh1*norm_signal1)/(nhB*norm_bckgnd)));
	lat.DrawLatex(X4lat, Ylat, Form("%.3e", (nh0*norm_signal0)/(nhB*norm_bckgnd)));
	lat.DrawLatex(X5lat, Ylat, Form("%.3e", (nh_1*norm_signal_1)/(nhB*norm_bckgnd)));
	lat.DrawLatex(X6lat, Ylat, Form("%.3e", (nh_2*norm_signal_2)/(nhB*norm_bckgnd)));
	lat.DrawLatex(X7lat, Ylat, Form("%.3e", (nh2*norm_signal2)/(nhB*norm_bckgnd)));
	lat.DrawLatex(X8lat, Ylat, Form("%.3e", (nh2_5*norm_signal2_5)/(nhB*norm_bckgnd)));
	lat.DrawLatex(X9lat, Ylat, Form("%.3e", (nh3*norm_signal3)/(nhB*norm_bckgnd)));
	C->Print(out_file_open,"pdf");
	
	//! page2
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	Nbquarks_2->Draw("hist");
	Nbquarks0->Draw("hist same");
	Nbquarks_1->Draw("hist same");
	Nbquarks1->Draw("hist same");
	Nbquarks2->Draw("hist same");
	Nbquarks2_5->Draw("hist same");
	Nbquarks3->Draw("hist same");
	leg_higgs->AddEntry(higgsPt_2, "k_{#lambda} = -2.0");
	leg_higgs->AddEntry(higgsPt_1, "k_{#lambda} = -1.0");
	leg_higgs->AddEntry(higgsPt0,  "k_{#lambda} =  0.0");
	leg_higgs->AddEntry(higgsPt1,  "k_{#lambda} =  1.0");
	leg_higgs->AddEntry(higgsPt2,  "k_{#lambda} =  2.0");
	leg_higgs->AddEntry(higgsPt2_5,"k_{#lambda} =  2.5");
	leg_higgs->AddEntry(higgsPt3,  "k_{#lambda} =  3.0");

	leg_higgs_1->AddEntry(higgsPt_2, "k_{#lambda} = -2.0");
	leg_higgs_1->AddEntry(higgsPt_1, "k_{#lambda} = -1.0");
	leg_higgs_1->AddEntry(higgsPt0,  "k_{#lambda} =  0.0");
	leg_higgs_1->AddEntry(higgsPt1,  "k_{#lambda} =  1.0");
	leg_higgs_1->AddEntry(higgsPt2,  "k_{#lambda} =  2.0");
	leg_higgs_1->AddEntry(higgsPt2_5,"k_{#lambda} =  2.5");
	leg_higgs_1->AddEntry(higgsPt3,  "k_{#lambda} =  3.0");
	leg_higgs_1->AddEntry(NbquarksB, "pp #rightarrow 4b");
	//leg_higgs->Draw();
	C->Update();
	
	C->cd(2);
	//leg_higgs->Draw();
	NbquarksB->Draw("hist");
	C->Update();

	C->cd(3);
	gPad->SetLogy();
	NjetsB->GetYaxis()->SetRangeUser(1e2,15e10);
	NjetsB->Draw("hist");
	Njets_2->Draw("hist same");
	Njets0->Draw("hist same");
	Njets_1->Draw("hist same");
	Njets1->Draw("hist same");
	Njets2->Draw("hist same");
	Njets2_5->Draw("hist same");
	Njets3->Draw("hist same");
	C->Update();

	C->cd(4);
	leg_higgs_1->Draw();
	C->Print(out_file_,"pdf");
	
	//! page3
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	// invariant mass of di-higgs system
	MH1H2__2->SetTitle("Di-higgs Invariant Mass");
	MH1H2__2->GetXaxis()->SetTitle("M_{truth,h1h2}");
	MH1H2__2->Draw("hist");
	MH1H2_0->Draw("hist same");
	MH1H2__1->Draw("hist same");
	MH1H2_3->Draw("hist same");
	MH1H2_2->Draw("hist same");
	MH1H2_2_5->Draw("hist same");
	MH1H2_1->Draw("hist same");
	C->Update();

	C->cd(2);
	gPad->SetLogy();
	MH1H2__2->SetTitle("Di-higgs Invariant Mass");
	MH1H2__2->GetXaxis()->SetTitle("M_{truth,h1h2}");
	MH1H2__2->GetYaxis()->SetRangeUser(1e2, 3.5e6);
	MH1H2__2->Draw("hist");
	MH1H2_0->Draw("hist same");
	MH1H2__1->Draw("hist same");
	MH1H2_3->Draw("hist same");
	MH1H2_2->Draw("hist same");
	MH1H2_2_5->Draw("hist same");
	MH1H2_1->Draw("hist same");
	
	C->cd(3);
	NSMhiggs_2->Draw("hist");
	NSMhiggs0->Draw("hist same");
	NSMhiggs_1->Draw("hist same");
	NSMhiggs1->Draw("hist same");
	NSMhiggs2->Draw("hist same");
	NSMhiggs2_5->Draw("hist same");
	NSMhiggs3->Draw("hist same");

	C->cd(4);
	leg_higgs_1->Draw();
	C->Print(out_file_,"pdf");
	

	//! page4
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	higgsPt_2->Draw("hist");	
	higgsPt0->Draw("hist same");	
	higgsPt_1->Draw("hist same");	
	higgsPt1->Draw("hist same");	
	higgsPt2->Draw("hist same");	
	higgsPt2_5->Draw("hist same");
	higgsPt3->Draw("hist same");
	C->Update();

	C->cd(2);
	higgsNLPt_2->Draw("hist");	
	higgsNLPt0->Draw("hist same");	
	higgsNLPt_1->Draw("hist same");	
	higgsNLPt1->Draw("hist same");	
	higgsNLPt2->Draw("hist same");	
	higgsNLPt2_5->Draw("hist same");
	higgsNLPt3->Draw("hist same");
	leg_higgs->Draw();
	C->Update();

	C->cd(3);
	gPad->SetLogy();
	higgsPt_2->Draw("hist");	
	higgsPt0->Draw("hist same");	
	higgsPt_1->Draw("hist same");	
	higgsPt1->Draw("hist same");	
	higgsPt2->Draw("hist same");	
	higgsPt2_5->Draw("hist same");
	higgsPt3->Draw("hist same");
	leg_higgs->Draw();
	C->Update();

	C->cd(4);
	gPad->SetLogy();
	higgsNLPt_2->Draw("hist");	
	higgsNLPt0->Draw("hist same");	
	higgsNLPt_1->Draw("hist same");	
	higgsNLPt1->Draw("hist same");	
	higgsNLPt2->Draw("hist same");	
	higgsNLPt2_5->Draw("hist same");
	higgsNLPt3->Draw("hist same");
	leg_higgs->Draw();
	C->Update();
	C->Print(out_file_,"pdf");

	//! page5
	//! page6
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	b4LPt1->SetTitle("k_{#lambda} = 1.0");
	b4LPt1->Draw("hist");
	b3LPt1->Draw("hist same");
	b2LPt1->Draw("hist same");
	bLPt1->Draw("hist same");
	leg1->AddEntry(bLPt1, "leading");
	leg1->AddEntry(b2LPt1, "sub-leading");
	leg1->AddEntry(b3LPt1, "3^{rd} leading");
	leg1->AddEntry(b4LPt1, "4^{th} leading");
	leg1->Draw();

	C->cd(2);	
	b4LPt0->SetTitle("k_{#lambda} = 0.0");
	b4LPt0->Draw("hist");
	b3LPt0->Draw("hist same");
	b2LPt0->Draw("hist same");
	bLPt0->Draw("hist same");
	leg1->Draw();

	C->cd(3);	
	b4LPt_1->SetTitle("k_{#lambda} = -1.0");
	b4LPt_1->Draw("hist");
	b3LPt_1->Draw("hist same");
	b2LPt_1->Draw("hist same");
	bLPt_1->Draw("hist same");
	leg1->Draw();

	C->cd(4);	
	b4LPt_2->SetTitle("k_{#lambda} = -2.0");
	b4LPt_2->Draw("hist");
	b3LPt_2->Draw("hist same");
	b2LPt_2->Draw("hist same");
	bLPt_2->Draw("hist same");
	leg1->Draw();
	C->Print(out_file_,"pdf");
	
	//! page7
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	b4LPt1->SetTitle("k_{#lambda} = 1.0");
	b4LPt1->Draw("hist");
	b3LPt1->Draw("hist same");
	b2LPt1->Draw("hist same");
	bLPt1->Draw("hist same");
	leg1->Draw();
	
	C->cd(2);
	b4LPt2->SetTitle("k_{#lambda} = 2.0");
	b4LPt2->Draw("hist");
	b3LPt2->Draw("hist same");
	b2LPt2->Draw("hist same");
	bLPt2->Draw("hist same");
	leg1->Draw();
	
	C->cd(3);
	b4LPt2_5->SetTitle("k_{#lambda} = 2.5");
	b4LPt2_5->Draw("hist");
	b3LPt2_5->Draw("hist same");
	b2LPt2_5->Draw("hist same");
	bLPt2_5->Draw("hist same");
	leg1->Draw();
	
	C->cd(4);
	b4LPt3->SetTitle("k_{#lambda} = 3.0");
	b4LPt3->Draw("hist");
	b3LPt3->Draw("hist same");
	b2LPt3->Draw("hist same");
	bLPt3->Draw("hist same");
	leg1->Draw();
	C->Print(out_file_,"pdf");
	
	//! page8
	C->Clear();
	C->Divide(1,2);
	C->cd(1);
	b4LPt1->SetTitle("k_{#lambda} = 1.0");
	b4LPt1->Draw("hist");
	b3LPt1->Draw("hist same");
	b2LPt1->Draw("hist same");
	bLPt1->Draw("hist same");
	leg1->Draw();

	C->cd(2);
	b4LPtB->SetTitle("pp->4b");
	b4LPtB->Draw("hist");
	b3LPtB->Draw("hist same");
	b2LPtB->Draw("hist same");
	bLPtB->Draw("hist same");
	leg1->Draw();
	C->Print(out_file_,"pdf");
	
	//! page9
	//! 4 leading b-Jets
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	bjet4LPt1->SetTitle("k_{#lambda} = 1.0");
	bjet4LPt1->GetXaxis()->SetTitle("p_{t,b-jet} [GeV/c]");
	bjet4LPt1->Draw("hist");
	bjet3LPt1->Draw("hist same");
	bjet2LPt1->Draw("hist same");
	bjetLPt1->Draw("hist same");
	leg1->Draw();

	C->cd(2);	
	bjet4LPt0->SetTitle("k_{#lambda} = 0.0");
	bjet4LPt0->GetXaxis()->SetTitle("p_{t,b-jet} [GeV/c]");
	bjet4LPt0->Draw("hist");
	bjet3LPt0->Draw("hist same");
	bjet2LPt0->Draw("hist same");
	bjetLPt0->Draw("hist same");
	leg1->Draw();

	C->cd(3);	
	bjet4LPt_1->SetTitle("k_{#lambda} = -1.0");
	bjet4LPt_1->GetXaxis()->SetTitle("p_{t,b-jet} [GeV/c]");
	bjet4LPt_1->Draw("hist");
	bjet3LPt_1->Draw("hist same");
	bjet2LPt_1->Draw("hist same");
	bjetLPt_1->Draw("hist same");
	leg1->Draw();

	C->cd(4);	
	bjet4LPt_2->SetTitle("k_{#lambda} = -2.0");
	bjet4LPt_2->GetXaxis()->SetTitle("p_{t,b-jet} [GeV/c]");
	bjet4LPt_2->Draw("hist");
	bjet3LPt_2->Draw("hist same");
	bjet2LPt_2->Draw("hist same");
	bjetLPt_2->Draw("hist same");
	leg1->Draw();
	C->Print(out_file_,"pdf");
	
	//! page10
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	bjet4LPt1->SetTitle("k_{#lambda} = 1.0");
	bjet4LPt1->GetXaxis()->SetTitle("p_{t,b-jet} [GeV/c]");
	bjet4LPt1->Draw("hist same");
	bjet3LPt1->Draw("hist same");
	bjet2LPt1->Draw("hist same");
	bjetLPt1->Draw("hist same");
	leg1->Draw();
	
	C->cd(2);
	bjet4LPt2->SetTitle("k_{#lambda} = 2.0");
	bjet4LPt2->GetXaxis()->SetTitle("p_{t,b-jet} [GeV/c]");
	bjet4LPt2->Draw("hist");
	bjet3LPt2->Draw("hist same");
	bjet2LPt2->Draw("hist same");
	bjetLPt2->Draw("hist same");
	leg1->Draw();
	
	C->cd(3);
	bjet4LPt2_5->SetTitle("k_{#lambda} = 2.5");
	bjet4LPt2_5->GetXaxis()->SetTitle("p_{t,b-jet} [GeV/c]");
	bjet4LPt2_5->Draw("hist");
	bjet3LPt2_5->Draw("hist same");
	bjet2LPt2_5->Draw("hist same");
	bjetLPt2_5->Draw("hist same");
	leg1->Draw();
	
	C->cd(4);
	bjet4LPt3->SetTitle("k_{#lambda} = 3.0");
	bjet4LPt3->GetXaxis()->SetTitle("p_{t,b-jet} [GeV/c]");
	bjet4LPt3->Draw("hist");
	bjet3LPt3->Draw("hist same");
	bjet2LPt3->Draw("hist same");
	bjetLPt3->Draw("hist same");
	leg1->Draw();
	C->Print(out_file_,"pdf");
	
	//! page11
	C->Clear();
	C->Divide(1,2);
	C->cd(1);
	bjet4LPt1->SetTitle("k_{#lambda} = 1.0");
	bjet4LPt1->Draw("hist");
	bjet3LPt1->Draw("hist same");
	bjet2LPt1->Draw("hist same");
	bjetLPt1->Draw("hist same");
	leg1->Draw();

	C->cd(2);
	bjet4LPtB->SetTitle("pp->4b");
	bjet4LPtB->Draw("hist");
	bjet2LPtB->Draw("hist same");
	bjetLPtB->Draw("hist same");
	bjet3LPtB->Draw("hist same");
	leg1->Draw();
	C->Print(out_file_,"pdf");
	
	//! page12
	//! 4 leading Jets
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	jet4LPt1->SetTitle("k_{#lambda} = 1.0");
	jet4LPt1->GetXaxis()->SetTitle("p_{t,jet} [GeV/c]");
	//jet5LPt1->Draw("hist");
	jet4LPt1->Draw("hist");
	jet3LPt1->Draw("hist same");
	jet2LPt1->Draw("hist same");
	jetLPt1->Draw("hist same");
	leg2->AddEntry(jetLPt1, "leading");
	leg2->AddEntry(jet2LPt1, "sub-leading");
	leg2->AddEntry(jet3LPt1, "3^{rd} leading");
	leg2->AddEntry(jet4LPt1, "4^{th} leading");
	//leg2->AddEntry(jet5LPt1, "5^{th} leading");
	leg2->Draw();

	C->cd(2);	
	jet4LPt0->SetTitle("k_{#lambda} = 0.0");
	jet4LPt0->GetXaxis()->SetTitle("p_{t,jet} [GeV/c]");
	//jet5LPt0->Draw("hist");
	jet4LPt0->Draw("hist");
	jet3LPt0->Draw("hist same");
	jet2LPt0->Draw("hist same");
	jetLPt0->Draw("hist same");
	leg2->Draw();

	C->cd(3);	
	jet4LPt_1->SetTitle("k_{#lambda} = -1.0");
	jet4LPt_1->GetXaxis()->SetTitle("p_{t,jet} [GeV/c]");
	//jet5LPt_1->Draw("hist");
	jet4LPt_1->Draw("hist");
	jet3LPt_1->Draw("hist same");
	jet2LPt_1->Draw("hist same");
	jetLPt_1->Draw("hist same");
	leg2->Draw();

	C->cd(4);	
	jet4LPt_2->SetTitle("k_{#lambda} = -2.0");
	jet4LPt_2->GetXaxis()->SetTitle("p_{t,jet} [GeV/c]");
	//jet5LPt_2->Draw("hist");
	jet4LPt_2->Draw("hist");
	jet3LPt_2->Draw("hist same");
	jet2LPt_2->Draw("hist same");
	jetLPt_2->Draw("hist same");
	leg2->Draw();
	C->Print(out_file_,"pdf");
	
	//! page13
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	jet4LPt1->SetTitle("k_{#lambda} = 1.0");
	jet4LPt1->GetXaxis()->SetTitle("p_{t,jet} [GeV/c]");
	//jet5LPt1->Draw("hist");
	jet4LPt1->Draw("hist same");
	jet3LPt1->Draw("hist same");
	jet2LPt1->Draw("hist same");
	jetLPt1->Draw("hist same");
	leg2->Draw();
	
	C->cd(2);
	jet4LPt2->SetTitle("k_{#lambda} = 2.0");
	jet4LPt2->GetXaxis()->SetTitle("p_{t,jet} [GeV/c]");
	//jet5LPt2->Draw("hist");
	jet4LPt2->Draw("hist");
	jet3LPt2->Draw("hist same");
	jet2LPt2->Draw("hist same");
	jetLPt2->Draw("hist same");
	leg2->Draw();
	
	C->cd(3);
	jet4LPt2_5->SetTitle("k_{#lambda} = 2.5");
	jet4LPt2_5->GetXaxis()->SetTitle("p_{t,jet} [GeV/c]");
	//jet5LPt2_5->Draw("hist");
	jet4LPt2_5->Draw("hist");
	jet3LPt2_5->Draw("hist same");
	jet2LPt2_5->Draw("hist same");
	jetLPt2_5->Draw("hist same");
	leg2->Draw();
	
	C->cd(4);
	jet4LPt3->SetTitle("k_{#lambda} = 3.0");
	jet4LPt3->GetXaxis()->SetTitle("p_{t,jet} [GeV/c]");
	//jet5LPt3->Draw("hist");
	jet4LPt3->Draw("hist");
	jet3LPt3->Draw("hist same");
	jet2LPt3->Draw("hist same");
	jetLPt3->Draw("hist same");
	leg2->Draw();
	C->Print(out_file_,"pdf");

	//! page14
	C->Clear();
	C->Divide(1,2);
	C->cd(1);
	jet4LPt1->SetTitle("k_{#lambda} = 1.0");
	jet4LPt1->Draw("hist");
	jet3LPt1->Draw("hist same");
	jet2LPt1->Draw("hist same");
	jetLPt1->Draw("hist same");
	leg2->Draw();

	C->cd(2);
	jet4LPtB->SetTitle("pp->4b");
	jet4LPtB->GetXaxis()->SetTitle("p_{t,jet} [GeV/c]");
	jet4LPtB->Draw("hist");
	jet3LPtB->Draw("hist same");
	jet2LPtB->Draw("hist same");
	jetLPtB->Draw("hist same");
	leg2->Draw();
	C->Print(out_file_,"pdf");
	//! page15
	//! 4 leading Jets invariant mass
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	gPad->SetLogy();
	jet4LM1->SetTitle("k_{#lambda} = 1.0");
	jet4LM1->GetXaxis()->SetTitle("m_{j} [GeV]");
	//jet5LM1->Draw("hist");
	jet4LM1->Draw("hist");
	jet3LM1->Draw("hist same");
	jet2LM1->Draw("hist same");
	jetLM1->Draw("hist same");
	leg2->Draw();

	C->cd(2);	
	gPad->SetLogy();
	jet4LM0->SetTitle("k_{#lambda} = 0.0");
	jet4LM0->GetXaxis()->SetTitle("m_{j} [GeV]");
	//jet5LM0->Draw("hist");
	jet4LM0->Draw("hist");
	jet3LM0->Draw("hist same");
	jet2LM0->Draw("hist same");
	jetLM0->Draw("hist same");
	leg2->Draw();

	C->cd(3);	
	gPad->SetLogy();
	jet4LM_1->SetTitle("k_{#lambda} = -1.0");
	jet4LM_1->GetXaxis()->SetTitle("m_{j} [GeV]");
	//jet5LM_1->Draw("hist");
	jet4LM_1->Draw("hist");
	jet3LM_1->Draw("hist same");
	jet2LM_1->Draw("hist same");
	jetLM_1->Draw("hist same");
	leg2->Draw();

	C->cd(4);	
	gPad->SetLogy();
	jet4LM_2->SetTitle("k_{#lambda} = -2.0");
	jet4LM_2->GetXaxis()->SetTitle("m_{j} [GeV]");
	//jet5LM_2->Draw("hist");
	jet4LM_2->Draw("hist");
	jet3LM_2->Draw("hist same");
	jet2LM_2->Draw("hist same");
	jetLM_2->Draw("hist same");
	leg2->Draw();
	C->Print(out_file_,"pdf");
	
	//! page16
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	gPad->SetLogy();
	jet4LM1->SetTitle("k_{#lambda} = 1.0");
	jet4LM1->GetXaxis()->SetTitle("m_{j} [GeV]");
	//jet5LM1->Draw("hist");
	jet4LM1->Draw("hist same");
	jet3LM1->Draw("hist same");
	jet2LM1->Draw("hist same");
	jetLM1->Draw("hist same");
	leg2->Draw();
	
	C->cd(2);
	gPad->SetLogy();
	jet4LM2->SetTitle("k_{#lambda} = 2.0");
	jet4LM2->GetXaxis()->SetTitle("m_{j} [GeV]");
	//jet5LM2->Draw("hist");
	jet4LM2->Draw("hist");
	jet3LM2->Draw("hist same");
	jet2LM2->Draw("hist same");
	jetLM2->Draw("hist same");
	leg2->Draw();
	
	C->cd(3);
	gPad->SetLogy();
	jet4LM2_5->SetTitle("k_{#lambda} = 2.5");
	jet4LM2_5->GetXaxis()->SetTitle("m_{j} [GeV]");
	//jet5LM2_5->Draw("hist");
	jet4LM2_5->Draw("hist");
	jet3LM2_5->Draw("hist same");
	jet2LM2_5->Draw("hist same");
	jetLM2_5->Draw("hist same");
	leg2->Draw();
	
	C->cd(4);
	gPad->SetLogy();
	jet4LM3->SetTitle("k_{#lambda} = 3.0");
	jet4LM3->GetXaxis()->SetTitle("m_{j} [GeV]");
	//jet5LM3->Draw("hist");
	jet4LM3->Draw("hist");
	jet3LM3->Draw("hist same");
	jet2LM3->Draw("hist same");
	jetLM3->Draw("hist same");
	leg2->Draw();
	C->Print(out_file_,"pdf");
	
	//! page17
	C->Clear();
	C->Divide(1,2);
	C->cd(1);
	gPad->SetLogy();
	jet4LM1->SetTitle("k_{#lambda} = 1.0");
	jet4LM1->Draw("hist");
	jet3LM1->Draw("hist same");
	jet2LM1->Draw("hist same");
	jetLM1->Draw("hist same");
	leg2->Draw();

	C->cd(2);
	gPad->SetLogy();
	jet4LMB->SetTitle("pp->4b");
	jet4LMB->GetXaxis()->SetTitle("m_{j} [GeV]");
	jet4LMB->Draw("hist");
	jet3LMB->Draw("hist same");
	jet2LMB->Draw("hist same");
	jetLMB->Draw("hist same");
	leg2->Draw();
	C->Print(out_file_,"pdf");

	//! page18
	//! 4 leading Jets invariant mass
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	gPad->SetLogy();
	bjet4LM1->SetTitle("k_{#lambda} = 1.0");
	bjet4LM1->GetXaxis()->SetTitle("m_{bjet} [GeV]");
	//bjet5LM1->Draw("hist");
	bjet4LM1->Draw("hist");
	bjet3LM1->Draw("hist same");
	bjet2LM1->Draw("hist same");
	bjetLM1->Draw("hist same");
	leg2->Draw();

	C->cd(2);	
	gPad->SetLogy();
	bjet4LM0->SetTitle("k_{#lambda} = 0.0");
	bjet4LM0->GetXaxis()->SetTitle("m_{bjet} [GeV]");
	//bjet5LM0->Draw("hist");
	bjet4LM0->Draw("hist");
	bjet3LM0->Draw("hist same");
	bjet2LM0->Draw("hist same");
	bjetLM0->Draw("hist same");
	leg2->Draw();

	C->cd(3);	
	gPad->SetLogy();
	bjet4LM_1->SetTitle("k_{#lambda} = -1.0");
	bjet4LM_1->GetXaxis()->SetTitle("m_{bjet} [GeV]");
	//bjet5LM_1->Draw("hist");
	bjet4LM_1->Draw("hist");
	bjet3LM_1->Draw("hist same");
	bjet2LM_1->Draw("hist same");
	bjetLM_1->Draw("hist same");
	leg2->Draw();

	C->cd(4);	
	gPad->SetLogy();
	bjet4LM_2->SetTitle("k_{#lambda} = -2.0");
	bjet4LM_2->GetXaxis()->SetTitle("m_{bjet} [GeV]");
	//bjet5LM_2->Draw("hist");
	bjet4LM_2->Draw("hist");
	bjet3LM_2->Draw("hist same");
	bjet2LM_2->Draw("hist same");
	bjetLM_2->Draw("hist same");
	leg2->Draw();
	C->Print(out_file_,"pdf");
	
	//! page19
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	gPad->SetLogy();
	bjet4LM1->SetTitle("k_{#lambda} = 1.0");
	bjet4LM1->GetXaxis()->SetTitle("m_{bjet} [GeV]");
	//bjet5LM1->Draw("hist");
	bjet4LM1->Draw("hist same");
	bjet3LM1->Draw("hist same");
	bjet2LM1->Draw("hist same");
	bjetLM1->Draw("hist same");
	leg2->Draw();
	
	C->cd(2);
	gPad->SetLogy();
	bjet4LM2->SetTitle("k_{#lambda} = 2.0");
	bjet4LM2->GetXaxis()->SetTitle("m_{bjet} [GeV]");
	//bjet5LM2->Draw("hist");
	bjet4LM2->Draw("hist");
	bjet3LM2->Draw("hist same");
	bjet2LM2->Draw("hist same");
	bjetLM2->Draw("hist same");
	leg2->Draw();
	
	C->cd(3);
	gPad->SetLogy();
	bjet4LM2_5->SetTitle("k_{#lambda} = 2.5");
	bjet4LM2_5->GetXaxis()->SetTitle("m_{bjet} [GeV]");
	//bjet5LM2_5->Draw("hist");
	bjet4LM2_5->Draw("hist");
	bjet3LM2_5->Draw("hist same");
	bjet2LM2_5->Draw("hist same");
	bjetLM2_5->Draw("hist same");
	leg2->Draw();
	
	C->cd(4);
	gPad->SetLogy();
	bjet4LM3->SetTitle("k_{#lambda} = 3.0");
	bjet4LM3->GetXaxis()->SetTitle("m_{bjet} [GeV]");
	//bjet5LM3->Draw("hist");
	bjet4LM3->Draw("hist");
	bjet3LM3->Draw("hist same");
	bjet2LM3->Draw("hist same");
	bjetLM3->Draw("hist same");
	leg2->Draw();
	C->Print(out_file_,"pdf");
	
	//! page20
	C->Clear();
	C->Divide(1,2);
	C->cd(1);
	gPad->SetLogy();
	bjet4LM1->SetTitle("k_{#lambda} = 1.0");
	bjet4LM1->Draw("hist");
	bjet3LM1->Draw("hist same");
	bjet2LM1->Draw("hist same");
	bjetLM1->Draw("hist same");
	leg2->Draw();

	C->cd(2);
	gPad->SetLogy();
	bjet4LMB->SetTitle("pp->4b");
	bjet4LMB->GetXaxis()->SetTitle("m_{bjet} [GeV]");
	bjet4LMB->Draw("hist");
	bjet3LMB->Draw("hist same");
	bjet2LMB->Draw("hist same");
	bjetLMB->Draw("hist same");
	leg2->Draw();
	C->Print(out_file_,"pdf");

	//! page21
	//! bquark leading for various lambda, 
	//! bquark sub leading for various lambda, 
	//! bquark 3rd leading for various lambda, 
	//! bquark 4th leading for various lambda,
	Set_bquark_lambdaColors_1(); 
	Set_bquark_lambdaColors_0(); 
	Set_bquark_lambdaColors__1(); 
	Set_bquark_lambdaColors__2(); 
	Set_bquark_lambdaColors_2(); 
	Set_bquark_lambdaColors_2_5(); 
	Set_bquark_lambdaColors_3(); 
	Set_bquark_lambdaColors_B(); 
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	gPad->SetLogy();
	bLPtB->GetYaxis()->SetRangeUser(1e2,5e10);
	bLPtB->Draw("hist ");
	bLPt3->Draw("hist same");
	bLPt1->Draw("hist same");
	bLPt2->Draw("hist same");
	bLPt2_5->Draw("hist same");
	bLPt_2->Draw("hist same");
	bLPt_1->Draw("hist same");
	bLPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(2);
	gPad->SetLogy();
	b2LPtB->GetYaxis()->SetRangeUser(1e2,5e10);
	b2LPtB->Draw("hist");
	b2LPt3->Draw("hist same");
	b2LPt1->Draw("hist same");
	b2LPt2->Draw("hist same");
	b2LPt2_5->Draw("hist same");
	b2LPt_2->Draw("hist same");
	b2LPt_1->Draw("hist same");
	b2LPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(3);
	gPad->SetLogy();
	b3LPtB->GetXaxis()->SetRangeUser(0,250);
	b3LPtB->GetYaxis()->SetRangeUser(1e2,5e10);
	b3LPtB->Draw("hist");
	b3LPt_2->Draw("hist same");
	b3LPt3->Draw("hist same");
	b3LPt1->Draw("hist same");
	b3LPt2->Draw("hist same");
	b3LPt2_5->Draw("hist same");
	b3LPt_1->Draw("hist same");
	b3LPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(4);
	gPad->SetLogy();
	b4LPtB->SetTitle("P_{t} of 4th leading b quark");
	b4LPtB->GetXaxis()->SetRangeUser(0,150);
	b4LPtB->GetYaxis()->SetRangeUser(1e2,5e10);
	
	b4LPtB->Draw("hist");
	b4LPt_2->Draw("hist same");
	b4LPt1->Draw("hist same");
	b4LPt2->Draw("hist same");
	b4LPt2_5->Draw("hist same");
	b4LPt3->Draw("hist same");
	b4LPt_1->Draw("hist same");
	b4LPt0->Draw("hist same");
	leg_higgs->Draw();
	C->Print(out_file_,"pdf");

	//! page22
	//! b-jet leading for various lambda, 
	//! b-jet sub leading for various lambda, 
	//! b-jet 3rd leading for various lambda, 
	//! b-jet 4th leading for various lambda,
	//Set_bquark_lambdaColors(); 
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	gPad->SetLogy();
	bjetLPtB->GetYaxis()->SetRangeUser(1e2,5e10);
	bjetLPtB->Draw("hist");
	bjetLPt_2->Draw("hist same");
	bjetLPt2->Draw("hist same");
	bjetLPt2_5->Draw("hist same");
	bjetLPt3->Draw("hist same");
	bjetLPt_1->Draw("hist same");
	bjetLPt1->Draw("hist same");
	bjetLPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(2);
	gPad->SetLogy();
	bjet2LPtB->GetYaxis()->SetRangeUser(1e2,5e10);
	bjet2LPtB->Draw("hist");
	bjet2LPt_2->Draw("hist same");
	bjet2LPt2->Draw("hist same");
	bjet2LPt2_5->Draw("hist same");
	bjet2LPt3->Draw("hist same");
	bjet2LPt_1->Draw("hist same");
	bjet2LPt1->Draw("hist same");
	bjet2LPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(3);
	gPad->SetLogy();
	bjet3LPtB->GetXaxis()->SetRangeUser(0,250);
	bjet3LPtB->GetYaxis()->SetRangeUser(1e2,5e10);
	bjet3LPtB->Draw("hist");
	bjet3LPt_2->Draw("hist same");
	bjet3LPt3->Draw("hist same");
	bjet3LPt2->Draw("hist same");
	bjet3LPt2_5->Draw("hist same");
	bjet3LPt_1->Draw("hist same");
	bjet3LPt1->Draw("hist same");
	bjet3LPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(4);
	gPad->SetLogy();
	bjet4LPtB->GetXaxis()->SetRangeUser(0,150);
	bjet4LPtB->GetYaxis()->SetRangeUser(1e2,5e10);
	
	bjet4LPtB->Draw("hist");
	bjet4LPt_2->Draw("hist same");
	bjet4LPt2->Draw("hist same");
	bjet4LPt2_5->Draw("hist same");
	bjet4LPt3->Draw("hist same");
	bjet4LPt_1->Draw("hist same");
	bjet4LPt1->Draw("hist same");
	bjet4LPt0->Draw("hist same");
	leg_higgs->Draw();
	C->Print(out_file_,"pdf");
	
	//! page23
	//! jet leading for various lambda, 
	//! jet sub leading for various lambda, 
	//! jet 3rd leading for various lambda, 
	//! jet 4th leading for various lambda,
	//Set_bquark_lambdaColors(); 
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	gPad->SetLogy();
	jetLPtB->GetYaxis()->SetRangeUser(1e2,5e10);
	jetLPtB->Draw("hist");
	jetLPt_2->Draw("hist same");
	jetLPt2->Draw("hist same");
	jetLPt2_5->Draw("hist same");
	jetLPt3->Draw("hist same");
	jetLPt_1->Draw("hist same");
	jetLPt1->Draw("hist same");
	jetLPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(2);
	gPad->SetLogy();
	jet2LPtB->GetYaxis()->SetRangeUser(1e2,5e10);
	jet2LPtB->Draw("hist");
	jet2LPt_2->Draw("hist same");
	jet2LPt2->Draw("hist same");
	jet2LPt2_5->Draw("hist same");
	jet2LPt3->Draw("hist same");
	jet2LPt_1->Draw("hist same");
	jet2LPt1->Draw("hist same");
	jet2LPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(3);
	gPad->SetLogy();
	jet3LPtB->GetXaxis()->SetRangeUser(0,250);
	jet3LPtB->GetYaxis()->SetRangeUser(1e2,5e10);
	jet3LPtB->Draw("hist");
	jet3LPt_2->Draw("hist same");
	jet3LPt3->Draw("hist same");
	jet3LPt2->Draw("hist same");
	jet3LPt2_5->Draw("hist same");
	jet3LPt_1->Draw("hist same");
	jet3LPt1->Draw("hist same");
	jet3LPt0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(4);
	gPad->SetLogy();
	jet4LPtB->GetXaxis()->SetRangeUser(0,150);
	jet4LPtB->GetYaxis()->SetRangeUser(1e2,5e10);
	
	jet4LPtB->Draw("hist");
	jet4LPt_2->Draw("hist same");
	jet4LPt2->Draw("hist same");
	jet4LPt2_5->Draw("hist same");
	jet4LPt3->Draw("hist same");
	jet4LPt_1->Draw("hist same");
	jet4LPt1->Draw("hist same");
	jet4LPt0->Draw("hist same");
	leg_higgs->Draw();
	C->Print(out_file_,"pdf");
	
	//! page24
	//! bquark central for various lambda, 
	//! bquark sub Central for various lambda, 
	//! bquark 3rd Central for various lambda, 
	//! bquark 4th Central for various lambda,
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	//C->SetLogy(0);
	gPad->SetLogy();
	bCEtaB->GetYaxis()->SetRangeUser(1e2,5e10);
	bCEtaB->Draw("hist ");
	bCEta3->Draw("hist same");
	bCEta1->Draw("hist same");
	bCEta2->Draw("hist same");
	bCEta2_5->Draw("hist same");
	bCEta_2->Draw("hist same");
	bCEta_1->Draw("hist same");
	bCEta0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(2);
	gPad->SetLogy();
	b2CEtaB->GetYaxis()->SetRangeUser(1e2,5e10);
	b2CEtaB->Draw("hist");
	b2CEta3->Draw("hist same");
	b2CEta1->Draw("hist same");
	b2CEta2->Draw("hist same");
	b2CEta2_5->Draw("hist same");
	b2CEta_2->Draw("hist same");
	b2CEta_1->Draw("hist same");
	b2CEta0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(3);
	gPad->SetLogy();
	b3CEtaB->GetYaxis()->SetRangeUser(1e2,5e10);
	b3CEtaB->Draw("hist");
	b3CEta_2->Draw("hist same");
	b3CEta3->Draw("hist same");
	b3CEta1->Draw("hist same");
	b3CEta2->Draw("hist same");
	b3CEta2_5->Draw("hist same");
	b3CEta_1->Draw("hist same");
	b3CEta0->Draw("hist same");
	leg_higgs->Draw();
	
	C->cd(4);
	gPad->SetLogy();
	b4CEtaB->GetYaxis()->SetRangeUser(1e2,5e10);
	b4CEtaB->Draw("hist");
	b4CEta_2->Draw("hist same");
	b4CEta1->Draw("hist same");
	b4CEta2->Draw("hist same");
	b4CEta2_5->Draw("hist same");
	b4CEta3->Draw("hist same");
	b4CEta_1->Draw("hist same");
	b4CEta0->Draw("hist same");
	leg_higgs->Draw();
	C->Print(out_file_,"pdf");

	//! page25
	//! Number of b tagged jets in an event
	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	h_NbTags1->Draw("hist");
	leg3->AddEntry((TObject*)0,Form("total = %f",h_NbTags1->Integral(1,6)),"");
	leg3->AddEntry((TObject*)0,Form("4btags = %f",h_NbTags1->Integral(0,5) - h_NbTags1->Integral(0,4)),"");
	leg3->AddEntry((TObject*)0,Form("3btags = %f",h_NbTags1->Integral(0,4) - h_NbTags1->Integral(0,3)),"");
	leg3->Draw();
	
	C->cd(2);
	h_NbTags0->Draw("hist");
	leg4->AddEntry((TObject*)0,Form("total = %f",h_NbTags0->Integral(1,6)),"");
	leg4->AddEntry((TObject*)0,Form("4btags = %f",h_NbTags0->Integral(0,5) - h_NbTags0->Integral(0,4)),"");
	leg4->AddEntry((TObject*)0,Form("3btags = %f",h_NbTags0->Integral(0,4) - h_NbTags0->Integral(0,3)),"");
	leg4->Draw();
	
	C->cd(3);
	h_NbTags_1->Draw("hist");
	leg5->AddEntry((TObject*)0,Form("total = %f",h_NbTags_1->Integral(1,6)),"");
	leg5->AddEntry((TObject*)0,Form("4btags = %f",h_NbTags_1->Integral(0,5) - h_NbTags_1->Integral(0,4)),"");
	leg5->AddEntry((TObject*)0,Form("3btags = %f",h_NbTags_1->Integral(0,4) - h_NbTags_1->Integral(0,3)),"");
	leg5->Draw();
	
	C->cd(4);
	h_NbTags_2->Draw("hist");
	leg6->AddEntry((TObject*)0,Form("total = %f",h_NbTags_2->Integral(1,6)),"");
	leg6->AddEntry((TObject*)0,Form("4btags = %f",h_NbTags_2->Integral(0,5) - h_NbTags_2->Integral(0,4)),"");
	leg6->AddEntry((TObject*)0,Form("3btags = %f",h_NbTags_2->Integral(0,4) - h_NbTags_2->Integral(0,3)),"");
	leg6->Draw();
	C->Print(out_file_,"pdf");

	//! page26
	C->Clear();
	C->Divide(2,2);
	leg3->Clear();
	leg4->Clear();
	leg5->Clear();
	leg6->Clear();
	Set_LegendProps();
	C->cd(1);
	h_NbTags2->Draw("hist");
	leg3->AddEntry((TObject*)0,Form("total = %f",h_NbTags2->Integral(1,6)),"");
	leg3->AddEntry((TObject*)0,Form("4btags = %f",h_NbTags2->Integral(0,5) - h_NbTags2->Integral(0,4)),"");
	leg3->AddEntry((TObject*)0,Form("3btags = %f",h_NbTags2->Integral(0,4) - h_NbTags2->Integral(0,3)),"");
	leg3->Draw();
	
	C->cd(2);
	h_NbTags2_5->Draw("hist");
	leg4->AddEntry((TObject*)0,Form("total = %f",h_NbTags2_5->Integral(1,6)),"");
	leg4->AddEntry((TObject*)0,Form("4btags = %f",h_NbTags2_5->Integral(0,5) - h_NbTags2_5->Integral(0,4)),"");
	leg4->AddEntry((TObject*)0,Form("3btags = %f",h_NbTags2_5->Integral(0,4) - h_NbTags2_5->Integral(0,3)),"");
	leg4->Draw();
	
	C->cd(3);
	h_NbTags3->Draw("hist");
	leg5->AddEntry((TObject*)0,Form("total = %f",h_NbTags3->Integral(1,6)),"");
	leg5->AddEntry((TObject*)0,Form("4btags = %f",h_NbTags3->Integral(0,5) - h_NbTags3->Integral(0,4)),"");
	leg5->AddEntry((TObject*)0,Form("3btags = %f",h_NbTags3->Integral(0,4) - h_NbTags3->Integral(0,3)),"");
	leg5->Draw();
	
	C->cd(4);
	h_NbTagsB->Draw("hist");
	leg6->AddEntry((TObject*)0,Form("total = %f",h_NbTagsB->Integral(1,6)),"");
	leg6->AddEntry((TObject*)0,Form("4btags = %f",h_NbTagsB->Integral(0,5) - h_NbTagsB->Integral(0,4)),"");
	leg6->AddEntry((TObject*)0,Form("3btags = %f",h_NbTagsB->Integral(0,4) - h_NbTagsB->Integral(0,3)),"");
	leg6->Draw();
	C->Print(out_file_,"pdf");

	//! page27
	C->Clear();
	C->Divide(2,3);
	C->cd(1);
	gPad->SetLogy();
	M_b1b2_1->Draw("hist");
	C->cd(2);
	gPad->SetLogy();
	M_b1b3_1->Draw("hist");
	C->cd(3);
	gPad->SetLogy();
	M_b1b4_1->Draw("hist");
	C->cd(4);
	gPad->SetLogy();
	M_b2b3_1->Draw("hist");
	C->cd(5);
	gPad->SetLogy();
	M_b2b4_1->Draw("hist");
	C->cd(6);
	gPad->SetLogy();
	M_b3b4_1->Draw("hist");
	C->Print(out_file_,"pdf");

	//! page28
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	C->Clear();
	C->Divide(1,3);
	C->cd(1);
	gPad->SetLogy();
	dM_b1b2_b3b4_1->Draw("hist");
	C->cd(2);
	gPad->SetLogy();
	dM_b1b3_b2b4_1->Draw("hist");
	C->cd(3);
	gPad->SetLogy();
	dM_b1b4_b2b3_1->Draw("hist");
	C->Print(out_file_,"pdf");

	//! page29
	// invariant mass of a pair of b's, pp->4b
	C->Clear();
	C->Divide(2,3);
	C->cd(1);
	gPad->SetLogy();
	M_b1b2_B->Draw("hist");
	C->cd(2);
	gPad->SetLogy();
	M_b1b3_B->Draw("hist");
	C->cd(3);
	gPad->SetLogy();
	M_b1b4_B->Draw("hist");
	C->cd(4);
	gPad->SetLogy();
	M_b2b3_B->Draw("hist");
	C->cd(5);
	gPad->SetLogy();
	M_b2b4_B->Draw("hist");
	C->cd(6);
	gPad->SetLogy();
	M_b3b4_B->Draw("hist");
	C->Print(out_file_,"pdf");

	//! page30
	//relative difference of the jet pairs
	//only 3 combination of jet pairs possible
	C->Clear();
	C->Divide(1,3);
	C->cd(1);
	gPad->SetLogy();
	dM_b1b2_b3b4_B->Draw("hist");
	C->cd(2);
	gPad->SetLogy();
	dM_b1b3_b2b4_B->Draw("hist");
	C->cd(3);
	gPad->SetLogy();
	dM_b1b4_b2b3_B->Draw("hist");
	C->Print(out_file_,"pdf");

	C->Clear();
	C->Divide(2,2);
	C->cd(1);
	M_Lhiggs1->Draw("hist");
	C->cd(2);
	M_NLhiggs1->Draw("hist");
	C->cd(3);
	M_LhiggsB->Draw("hist");
	C->cd(4);
	M_NLhiggsB->Draw("hist");
	C->Print(out_file_,"pdf");

	//! page31
	// invariant mass of a pair of b's, pp->4b
	C->Clear();
	C->Divide(2,3);
	C->cd(1);
	gPad->SetLogy();
	Mb1b2_B->Draw("hist");
	C->cd(2);
	gPad->SetLogy();
	Mb1b3_B->Draw("hist");
	C->cd(3);
	gPad->SetLogy();
	Mb1b4_B->Draw("hist");
	C->cd(4);
	gPad->SetLogy();
	Mb2b3_B->Draw("hist");
	C->cd(5);
	gPad->SetLogy();
	Mb2b4_B->Draw("hist");
	C->cd(6);
	gPad->SetLogy();
	Mb3b4_B->Draw("hist");
	C->Print(out_file_,"pdf");

	//! page32
	// invariant mass of a pair of b's, ctr = 1.0
	C->Clear();
	C->Divide(2,3);
	C->cd(1);
	gPad->SetLogy();
	Mb1b2_1->Draw("hist");
	C->cd(2);
	gPad->SetLogy();
	Mb1b3_1->Draw("hist");
	C->cd(3);
	gPad->SetLogy();
	Mb1b4_1->Draw("hist");
	C->cd(4);
	gPad->SetLogy();
	Mb2b3_1->Draw("hist");
	C->cd(5);
	gPad->SetLogy();
	Mb2b4_1->Draw("hist");
	C->cd(6);
	gPad->SetLogy();
	Mb3b4_1->Draw("hist");
	C->Print(out_file_,"pdf");

	//! page33
	// invariant mass of a pair of b's, ctr = 0.0
	C->Clear();
	C->Divide(2,3);
	C->cd(1);
	gPad->SetLogy();
	Mb1b2_0->Draw("hist");
	C->cd(2);
	gPad->SetLogy();
	Mb1b3_0->Draw("hist");
	C->cd(3);
	gPad->SetLogy();
	Mb1b4_0->Draw("hist");
	C->cd(4);
	gPad->SetLogy();
	Mb2b3_0->Draw("hist");
	C->cd(5);
	gPad->SetLogy();
	Mb2b4_0->Draw("hist");
	C->cd(6);
	gPad->SetLogy();
	Mb3b4_0->Draw("hist");
	C->Print(out_file_,"pdf");

	//! page34
	// invariant mass of a pair of b's, ctr = -1.0
	C->Clear();
	C->Divide(2,3);
	C->cd(1);
	gPad->SetLogy();
	Mb1b2__1->Draw("hist");
	C->cd(2);
	gPad->SetLogy();
	Mb1b3__1->Draw("hist");
	C->cd(3);
	gPad->SetLogy();
	Mb1b4__1->Draw("hist");
	C->cd(4);
	gPad->SetLogy();
	Mb2b3__1->Draw("hist");
	C->cd(5);
	gPad->SetLogy();
	Mb2b4__1->Draw("hist");
	C->cd(6);
	gPad->SetLogy();
	Mb3b4__1->Draw("hist");
	C->Print(out_file_,"pdf");

	//! page35
	// invariant mass of a pair of b's, ctr = -2.0
	C->Clear();
	C->Divide(2,3);
	C->cd(1);
	gPad->SetLogy();
	Mb1b2__2->Draw("hist");
	C->cd(2);
	gPad->SetLogy();
	Mb1b3__2->Draw("hist");
	C->cd(3);
	gPad->SetLogy();
	Mb1b4__2->Draw("hist");
	C->cd(4);
	gPad->SetLogy();
	Mb2b3__2->Draw("hist");
	C->cd(5);
	gPad->SetLogy();
	Mb2b4__2->Draw("hist");
	C->cd(6);
	gPad->SetLogy();
	Mb3b4__2->Draw("hist");
	C->Print(out_file_,"pdf");

	//! page36
	// invariant mass of a pair of b's, ctr = 2.0
	C->Clear();
	C->Divide(2,3);
	C->cd(1);
	gPad->SetLogy();
	Mb1b2_2->Draw("hist");
	C->cd(2);
	gPad->SetLogy();
	Mb1b3_2->Draw("hist");
	C->cd(3);
	gPad->SetLogy();
	Mb1b4_2->Draw("hist");
	C->cd(4);
	gPad->SetLogy();
	Mb2b3_2->Draw("hist");
	C->cd(5);
	gPad->SetLogy();
	Mb2b4_2->Draw("hist");
	C->cd(6);
	gPad->SetLogy();
	Mb3b4_2->Draw("hist");
	C->Print(out_file_,"pdf");

	//! page37
	// invariant mass of a pair of b's, ctr = 2.5
	C->Clear();
	C->Divide(2,3);
	C->cd(1);
	gPad->SetLogy();
	Mb1b2_2_5->Draw("hist");
	C->cd(2);
	gPad->SetLogy();
	Mb1b3_2_5->Draw("hist");
	C->cd(3);
	gPad->SetLogy();
	Mb1b4_2_5->Draw("hist");
	C->cd(4);
	gPad->SetLogy();
	Mb2b3_2_5->Draw("hist");
	C->cd(5);
	gPad->SetLogy();
	Mb2b4_2_5->Draw("hist");
	C->cd(6);
	gPad->SetLogy();
	Mb3b4_2_5->Draw("hist");
	C->Print(out_file_,"pdf");

	//! page38
	// invariant mass of a pair of b's, ctr = 3.0
	C->Clear();
	C->Divide(2,3);
	C->cd(1);
	gPad->SetLogy();
	Mb1b2_3->Draw("hist");
	C->cd(2);
	gPad->SetLogy();
	Mb1b3_3->Draw("hist");
	C->cd(3);
	gPad->SetLogy();
	Mb1b4_3->Draw("hist");
	C->cd(4);
	gPad->SetLogy();
	Mb2b3_3->Draw("hist");
	C->cd(5);
	gPad->SetLogy();
	Mb2b4_3->Draw("hist");
	C->cd(6);
	gPad->SetLogy();
	Mb3b4_3->Draw("hist");
//	C->Print(out_file_,"pdf");

	//! page39

	//! page40
	// invariant mass of di-higgs system
//	C->Clear();
//	C->SetLogy();
	C->Print(out_file_close,"pdf");
	return 0;
}
