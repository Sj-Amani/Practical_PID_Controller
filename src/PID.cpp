#include "PID.h"
#include <math.h>
#include <iostream>

using namespace std;

/**
 * The PID class.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd, bool flag) {
    // Initialize PID coefficients and errors.
    PID::Kp = Kp;
    PID::Ki = Ki;
    PID::Kd = Kd;
    PID::flag = flag;

    p_error = 0;
    i_error = 0;
    d_error = 0;

    err = 0;
    best_err = 1000000.0;
    tol = 0.01;
    index = 0;
    horizon = 1;
    dp[0] = 0.5;
    dp[1] = 0.1;
    dp[2] = 0.5;

    first = 0;
    restart = false;

    p[0] = Kp;
    p[1] = Ki;
    p[2] = Kd;

}



void PID::UpdateError(double cte) {
    // Update PID errors based on cte. 


    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;

    if(restart)
    {
        d_error = 0;
        p_error = 0;
        i_error = 0;
        restart = false;
    }

    err += cte*cte;
    horizon = horizon + 1;

    if (flag and ((horizon==1500) or ((horizon>20) and fabs(cte)>2.5)))
    {
        //cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<" "<<"flag="<<flag<<", horizon="<<horizon<<", cte="<<cte<<endl;
        if (fabs(cte) > 2.5) { err = 1000000000; }
        err = err/horizon;
        
        if (dp[0] + dp[1] + dp[2] > tol)
        {
            if (first == 0)
            {
                p[index] += dp[index];
                first = 1;
                best_err = err;
            }
            else if (first == 1)
            {
                
                if (err < best_err)
                {
                    best_err = err;
                    dp[index] *= 1.1;
                    first = 0;
                    index = (index+1) % 3;
                }
                else
                {
                    p[index] -= 2*dp[index];
                    first = 2;
                }
            }
            else if (first == 2)
            {
                if (err < best_err)
                {
                    best_err = err;
                    dp[index] *= 1.1;
                }
                else
                {
                    p[index] += dp[index];
                    dp[index] *= 0.9;
                }
                first = 0;
                index = (index+1) % 3;
            }
            Kp = p[0];
            Ki = p[1];
            Kd = p[2];
            restart = true;
        }

        else
        {
            restart = false;
        }

        horizon = 1;
        err = 0;
    }
}

double PID::TotalError() {
    // Calculate and return the total error
    double steer_angle = -p_error*Kp - d_error*Kd - i_error*Ki;
    // Penalize large steer angles
    if(!restart)
        err += steer_angle*steer_angle;
    return steer_angle;
}

