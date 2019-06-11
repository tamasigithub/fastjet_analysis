#include <iostream>
#include <TMath.h>
int pt_bins()
{
// log bins
  const int ptbins = 40;//no. of bins
  int length = ptbins + 1;
  Double_t xbins[length];//elements of this array are
  double dx, l10;
  dx = 5./ptbins;//5 -> implies max until 10^5
  l10 = TMath::Log(10);
  for (int i = 0; i<=ptbins; i++)
  {
	std::cout<<"i,dx : " <<i << ", "<<dx <<std::endl;
	xbins[i] = TMath::Exp(l10*i*dx);
	std::cout<<"xbin[i] : " <<xbins[i] <<std::endl;
  }
return 0;
}
