#include "PID.h"

PIDController pid;

void PIDController_Init(void) {

    pid.Kp = 0.1f;
    pid.Ki = 0.01f;
    pid.Kd = 0.0f;

    /* Derivative low-pass filter time constant */
    pid.DerivativeLowPassFilterTime = 0.0f;
    pid.SamplingTime = 0.5f;
    /* Output limits */
    pid.limOutputMin = 0.0f;
    pid.limOutputMax = 1023.0f;

    /* Integrator limits */
    pid.limIntegratorMin = 0.0f;
    pid.limIntegratorMax =  1023.0f;

	/* Clear controller variables */
	pid.integrator = 0.0f;
	pid.prevError  = 0.0f;

	pid.differentiator  = 0.0f;
	pid.prevMeasurement = 0.0f;

	pid.out = 0.0f;

}

float PIDController_Update(int setpoint, int measurement) {

	/*
	 * Error signal
	 */
    int error = setpoint - measurement;


	/*
	 * Proportional
	 */
    int  proportional = pid.Kp * error;


	/*
	 * Integral
	 */
    pid.integrator =  pid.Ki *  (error + pid.prevError);

	/* Anti-wind-up via integrator clamping */
    if (pid.integrator > pid.limIntegratorMax) {

        pid.integrator = pid.limIntegratorMax;

    } else if (pid.integrator < pid.limIntegratorMin) {

        pid.integrator = pid.limIntegratorMin;

    }

	/*
	 * Derivative (band-limited differentiator)
	 */
		
    pid.differentiator = - (2.0f * pid.Kd * (measurement - pid.prevMeasurement)	/* Note: derivative on measurement, therefore minus sign in front of equation! */
                         + (2.0f * pid.DerivativeLowPassFilterTime - pid.SamplingTime) * pid.differentiator)
                         / (2.0f * pid.DerivativeLowPassFilterTime + pid.SamplingTime);


	/*
	 * Compute output and apply limits
	 */
    pid.out = proportional + pid.integrator + pid.differentiator;

    if (pid.out > pid.limOutputMax) {

        pid.out = pid.limOutputMax;

    } else if (pid.out < pid.limOutputMin) {

        pid.out = pid.limOutputMin;
    }

	/* Store error and measurement for later use */
    pid.prevError       = error;
    pid.prevMeasurement = measurement;

	/* Return controller output */
    return pid.out;

}
