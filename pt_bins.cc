#include <iostream>
#include <TMath.h>
int pt_bins()
{
// log bins
  const int ptbins = 60;//no. of bins
  int length = ptbins + 1;
  Double_t xbins[length];//elements of this array are
  double dx, l10;
  dx = 6./ptbins;//5 -> implies max until 10^5
  l10 = TMath::Log(10);
  for (int i = 0; i<=ptbins; i++)
  {
	std::cout<<"i,dx : " <<i << ", "<<dx <<std::endl;
	xbins[i] = TMath::Exp(l10*i*dx);
	std::cout<<"xbin[i] : " <<xbins[i] <<std::endl;
  }

  float pt_min = 1, pt_max = 1200, lowptcut_width = 10, highptcut_width = 20;//in GeV
  const int totalpt_bins = 60;
  int Nlowpt_bins = 40;// => 20 bins for high pt
  //! variable custom binning
   for(int i = 0; i <= totalpt_bins; i++)
   {
	   if(i==0) xbins[i] = pt_min;
	   else if(i < Nlowpt_bins)
	   {
	   	xbins[i] = i*lowptcut_width;
	   }
	   else
	   {
		int j = i - Nlowpt_bins;
		int highpt_min = pt_max - highptcut_width * (totalpt_bins - Nlowpt_bins);
		xbins[i] = highpt_min + j*highptcut_width;
	   }

           std::cout<< "xbin[ " << i << "] : " <<xbins[i] <<std::endl; 
   }

 
return 0;
}
