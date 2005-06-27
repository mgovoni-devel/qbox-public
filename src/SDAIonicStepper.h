////////////////////////////////////////////////////////////////////////////////
//
// SDAIonicStepper.h:
//
////////////////////////////////////////////////////////////////////////////////
// $Id: SDAIonicStepper.h,v 1.4 2005-06-27 22:21:32 fgygi Exp $

#ifndef SDAIONICSTEPPER_H
#define SDAIONICSTEPPER_H

#include "IonicStepper.h"
#include "AndersonMixer.h"

class SDAIonicStepper : public IonicStepper
{
  private:
  
  vector<double> f_;
  vector<double> fbar_;
  double theta_;
  bool first_step_;
  AndersonMixer mixer_;
  
  public:
  
  SDAIonicStepper(Sample& s) : IonicStepper(s), first_step_(true), theta_(0),
  mixer_(ndofs_, 0)
  {
    f_.resize(ndofs_);
    fbar_.resize(ndofs_);
    rm_ = r0_;
    mixer_.set_theta_max(1.0);
    //mixer_.set_theta_nc(-0.5); // default: 0.0
  }

  void compute_r(double e0, const vector<vector< double> >& f0);
  void compute_v(double e0, const vector<vector< double> >& f0) {}
  void reset(void) { first_step_ = true; }
};

#endif
