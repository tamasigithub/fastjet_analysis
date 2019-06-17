#include <iostream>
#include "TrigEff.h"

int main()
{
	const float a = 0.;
	const float b = 1000.;
	const float  c = 5.0;
	TrigEff trigger(a, b, c);
	//const int length = trigger.nBins();
//	//trigger.nbins = length;
	//std::cout<<"nbins: " <<length <<std::endl;
	//for(int i = 0; i <= length; ++i)
	//{
	//	trigger.xbins[i] = trigger.pt_min + i*trigger.ptcut_width;
	//	std::cout <<"xbins[" <<i <<"] = " << trigger.xbins[i] <<std::endl;
	//}
return 0;
}
