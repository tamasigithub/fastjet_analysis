#include "CaloEmu.h"
         
CaloEmu::CaloEmu(const bool debug,
                 const unsigned int neta,
                 const float etamin,
                 const float etamax,
                 const unsigned int nphi,
                 const float phimin,
                 const float phimax)
{

         if (debug)
         {
            std::cout << "Info: Initialize detector" << std::endl;
            std::cout << "      -granularity eta: "  << (etamax-etamin)/static_cast<float>(neta) << std::endl;
            std::cout << "      -granularity eta: "  << (phimax-phimin)/static_cast<float>(nphi) << std::endl;
         }
         // The detector is simply a two-dimensional histogram
         m_detector = new TH2F("", "", neta, etamin, etamax, nphi, phimin, phimax);

         // Just to be sure...
         m_detector->Reset();
}

void CaloEmu::Reset_Detector()
{
	m_detector->Reset();
}

double CaloEmu::GetCaloRadius()
{
	return Calo_radius;
}
double CaloEmu::GetChargedPcle_PtThreshold()
{
	return CONSTANT * B_field * Calo_radius/2;
}
double CaloEmu::GetCellEnergyThreshold()
{
	return CellEnergyThreshold;
}

unsigned int CaloEmu::GetNxbins()
{
	return m_detector->GetNbinsX();
}

unsigned int CaloEmu::GetNybins()
{
	return m_detector->GetNbinsY();
}

void CaloEmu::AccumulateEnergy( double eta, 
				double phi, 
				double trkenergy)
{
             // find the particles rapidity and phi, then get the detector bins
             int etabin = m_detector->GetXaxis()->FindBin(eta);
             int phibin = m_detector->GetYaxis()->FindBin(phi);
             // do bin += value in the associated detector bin
             m_detector->SetBinContent(etabin, phibin, m_detector->GetBinContent(etabin, phibin) + trkenergy);
}

std::vector<double> CaloEmu::GetCellEnergy(int i, int j)
{
	EPtEtaPhi.clear();
	double	phi = -999;
	double	eta = -999;
	double	E = 0, Pt = 0;
	//! smear jet energies
	double E_reso_;
	double E_smeared = 0, Pt_smeared = 0;

	if (m_detector->GetBinContent(i, j) > 0) 
	{
                     eta = m_detector->GetXaxis()->GetBinCenter(i);
                     phi = m_detector->GetYaxis()->GetBinCenter(j);
                     E = m_detector->GetBinContent(i, j);
		     //! only stochastic term
		     //E_reso_ = SCALEfac_Ereso/sqrt(E);//50% energy resolution
		     //! stochastic term, noise term, constant term
		     //E_reso_ = (SCALEfac_Ereso/sqrt(E)) + (Noise_Term/E) + Const_Term;//energy resolution
		     E_reso_ = (SCALEfac_Ereso/std::sqrt(E)) + Const_Term;//energy resolution
		     E_smeared = gRandom->Gaus(E,E_reso_*E);
		     Pt_smeared = E_smeared/cosh(eta);// E = sqrt(pt^2 + m^2) cosh(eta)
		     Pt = E/cosh(eta);// E = sqrt(pt^2 + m^2) cosh(eta)

	}
	EPtEtaPhi.push_back(E_smeared);
	//EPtEtaPhi.push_back(E);
	//EPtEtaPhi.push_back(Pt);
	EPtEtaPhi.push_back(Pt_smeared);
	EPtEtaPhi.push_back(eta);
	EPtEtaPhi.push_back(phi);
	return EPtEtaPhi;
}
