#include<iostream>
int z_bins()
{
	bool debug = false;
	int NZVTXBIN = 120;
	float ZRANGE = 200;
	float ZBIN_width = ZRANGE/NZVTXBIN;
	std::cout<<"bin width: " <<ZBIN_width <<std::endl;
	std::cout<<"3/2 x bin width: " <<1.5 * ZBIN_width <<std::endl;
	std::cout<<"new range of " << NZVTXBIN/2 << "th bin [ 0, " << ZBIN_width <<") is [" <<ZBIN_width/2 - 1.5*ZBIN_width <<", " << ZBIN_width/2 + 1.5*ZBIN_width << ")" <<std::endl;  
	//for(int i = 0; i < NZVTXBIN; i++)
	//{
	//	std::cout<<"range " << i << ": [" << -1*ZRANGE
	//}
	double tjVec[7] = {-4.99, -5.01, -5.0, 0.0, 5.0, 5.01, 4.99};
	//! loop over vertex bins
        for(int ith_bin = 0; ith_bin < NZVTXBIN; ++ith_bin)
        {
		std::cout<<std::endl;
		std::cout<<ith_bin << "th bin" << std::endl;
		for(int m = 0; m < /*tjVec.size()*/7; ++m )
                {
                        //! identify the bin number in which these tracks lie
                        int izbin = (tjVec[m] + 0.5 * ZRANGE) / (ZBIN_width);
                        if(izbin < 0) izbin = 0;
                        if(izbin > NZVTXBIN) izbin = NZVTXBIN - 1;
                        if(debug) std::cout<<"looping over all tracks: track_vz[:  " << m << "] = "<< tjVec[m]<<", and izbin: " << izbin << std::endl;
                        //! check z bin consistency
                        //! i.e. collect the tracks only from immediate neighbours or the ith_bin
                        if(abs(izbin - ith_bin)<=1)
                        {
                                //! create a fastjet::PseudoJet with these components
                                //and push back into in_tracks vector
                                if(debug) std::cout<<"z bin consistency passed!" <<std::endl;

                        }
 		}
	}
return 0;
}
