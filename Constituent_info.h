/*!
 *  \file
 *  \brief The jet constituent info class
 */
#ifndef CONSTITUENT_INFO_H_
#define CONSTITUENT_INFO_H_

#include <iostream>
#include "fastjet/PseudoJet.hh"
using namespace fastjet;

class Constituent_info: public PseudoJet::UserInfoBase 
{
	//check PseudoJet.hh
public:
	Constituent_info(int id, double vz, double z0) : _pdg_id(id), _vz_(vz), _z0_(z0){}
	inline int pdg_id() const {return _pdg_id;}
	inline double Vz() const {return _vz_;}
	inline double Z0() const {return _z0_;}
private:
	int _pdg_id;
	double _vz_;
	double _z0_;
 };
#endif /*CONSTITUENT_INFO_H_*/
