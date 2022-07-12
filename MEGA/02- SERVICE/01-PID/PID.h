#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

typedef struct {
	/* Controller gains */
	float Kp;
	float Ki;
	float Kd;

	/* Derivative low-pass filter time constant */
	float DerivativeLowPassFilterTime;

	/* Output limits */
	float limOutputMin;
	float limOutputMax;
	
	/* Integrator limits */
	float limIntegratorMin;
	float limIntegratorMax;

	/* Sample time (in seconds) */
	float SamplingTime;

	/* Controller "memory" */
	float integrator;
	float prevError;			/* Required for integrator */
	float differentiator;
	float prevMeasurement;		/* Required for differentiator */

	/* Controller output */
	float out;

} PIDController;

void PIDController_Init(void);
float PIDController_Update(float setpoint, float measurement);

#endif
