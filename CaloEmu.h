/*!
 *  \file
 *  \brief Class to emulate a calorimeter with given eta-phi granularity 
 *  //! This involves constructing eta-phi cells with the given granularity
 *  //! accumulating the energy deposited by a particle hitting the cell for each event
 *  //! and finally use the energy deposits in these cells for each event to do jet clustering
 */
#ifndef CALOEMU_H_
#define CALOEMU_H_

#include <iostream>
#include "TROOT.h"
#include "TFile.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TLegend.h"
#include "TGraphErrors.h"
#include "TPostScript.h"
#include "TLatex.h"
#include "TChain.h"
#include "TMath.h"
#include "TRandom.h"
#include <vector>
#include <list>
#include <algorithm> 
#include <functional>
#include <fstream>
#include <string>
#include <math.h>
#include <numeric> //accumulate

class CaloEmu
{
	private:
	      // Members
	      TH2F *m_detector = nullptr; // detector (modeled by a 2dim histogram)
	      std::vector<double> EPtEtaPhi;//accumulated params for a cell
	      double CellEnergyThreshold = 0.5e3;//MeV
	      double Calo_radius = 2e3;//mm
	      double SCALEfac_Ereso = 0.5;// 50%
	public:
	          //static constexpr double B_field = 4.0; //Magnetic Field strength
		  //static constexpr double CONSTANT = 0.299760192;
	          const double B_field = 4.0; //Magnetic Field strength
		  const double CONSTANT = 0.299760192;


	public:

		/*
		    arguments:
		    neta: number of pixels in pseudorapidity
		    nphi: number of pixels in azimuthal
		    etamin: minimum pseudorapidity
		    etamax: maximum pseudorapidity
		    phimin: minimum azimuthal
		    phimax: maximum azimuthal
		*/
	        //! FCC-hh ECAL granularity deta x dphi  = 0.01 x 0.009 in |eta| < 2.5
		CaloEmu(const bool debug = false,
                        const unsigned int neta = 500,
                        const float etamin = -2.5,
                        const float etamax = 2.5,
                        const unsigned int nphi = 698,
                        const float phimin = 0,
                        const float phimax = 2*3.141);//! I have purposely not used M_PI here 
		
		~CaloEmu()
		{
			if ( m_detector )
           			delete m_detector;
		}

	public:		
		void Reset_Detector();
		double GetCaloRadius();
		double GetChargedPcle_PtThreshold();
		double GetCellEnergyThreshold();
		unsigned int GetNxbins();
		unsigned int GetNybins();
		//! Accumulate energy deposits in each cell
		void AccumulateEnergy(double eta, double phi, double trkenergy);
		//! Get the accumulated energy deposit from a given eta-phi cell
		std::vector<double> GetCellEnergy(int i, int j);
	
	private:

	    //! delete the default copy constructor and assignment operator
	    CaloEmu(const CaloEmu&) = delete;
	    CaloEmu& operator=(const CaloEmu&) = delete;

};
#endif /*CALOEMU_H_*/
