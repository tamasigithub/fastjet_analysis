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
	double	phi__ = -999;
	double	eta__ = -999;
	double	E__ = 0, Pt__ = 0;
	//! smear jet energies
	double E_reso_;
	double E_smeared = 0, Pt_smeared = 0;

	if (m_detector->GetBinContent(i, j) > 0) 
	{
                     eta__ = m_detector->GetXaxis()->GetBinCenter(i);
                     phi__ = m_detector->GetYaxis()->GetBinCenter(j);
                     E__ = m_detector->GetBinContent(i, j);
		     //! only stochastic term
		     //E_reso_ = SCALEfac_Ereso/sqrt(E__);//50% energy resolution
		     //! stochastic term, noise term, constant term
		     //E_reso_ = (SCALEfac_Ereso/sqrt(E__)) + (Noise_Term/E__) + Const_Term;//energy resolution
		     E_reso_ = (SCALEfac_Ereso/std::sqrt(E__)) + Const_Term;//energy resolution
		     E_smeared = gRandom->Gaus(E__,E_reso_*E__);
		     Pt_smeared = E_smeared/cosh(eta__);// E = sqrt(pt^2 + m^2) cosh(eta)
		     Pt__ = E__/cosh(eta__);// E = sqrt(pt^2 + m^2) cosh(eta)

	}
	EPtEtaPhi.push_back(E_smeared);
	EPtEtaPhi.push_back(Pt_smeared);
	//EPtEtaPhi.push_back(E__);
	//EPtEtaPhi.push_back(Pt__);
	EPtEtaPhi.push_back(eta__);
	EPtEtaPhi.push_back(phi__);
	return EPtEtaPhi;
}
