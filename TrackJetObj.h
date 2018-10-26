/*!
 *  \file
 *  \brief The Track Jet Object class
 */
#ifndef TRACKJETOBJ_H_
#define TRACKJETOBJ_H_

#include <iostream>

class TrackJetObj
{
public:
	double px;
	double py;
	double pz;
	double E;
	double zv;
	int flag;
	double pdg;
	double Vz0;
public:
	TrackJetObj() = default;
	~TrackJetObj() = default;
//delete the default copy constructor and assignment operator
/*private:
  TrackJetObj(const TrackJetObj&) = delete;
  TrackJetObj& operator=(const TrackJetObj&) = delete;*/
};

#endif /*TRACKJETOBJ_H_*/
