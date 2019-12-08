#ifndef PID_H
#define PID_H

#include <vector>

class PID {
public:
  /*
  * PID Errors
  */
  double p_error;
  double i_error;
  double d_error;

  double err;
  double best_err;
  double tol;
  int restart;
  int horizon;
  bool flag;
  double p[3];
  double dp[3];
  int first;
  int index;
  /*
  * PID Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor
  */
  virtual ~PID();

  /*
  * Initialize PID
  * @param (Kp_, Ki_, Kd_) The initial PID coefficients
  */
  void Init(double Kp, double Ki, double Kd, bool tune_param);

  /*
  * Update the PID error variables given cross track error
  * @param cte The current cross track error
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error
  * @output The total PID error
  */
  double TotalError();
};

#endif // PID_H
