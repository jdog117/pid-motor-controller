/*
 * pid.h
 *
 *  Created on: Oct 9, 2023
 *      Author: jspca
 */

#ifndef INC_PID_H_
#define INC_PID_H_

/*
 * PID struct and initialization
 *
 * Parameters
 * uPID : Pointer to pid struct
 * Input : The variable we're trying to control (double)
 * Output : The variable that will be adjusted by the pid (double)
 * Setpoint : The value we want to Input to maintain (double)
 * Kp,Ki,Kd : Tuning Parameters. these affect how the pid will change the output (double>=0)
 * POn : Either P_ON_E (Default) or P_ON_M. Allows Proportional on Measurement to be specified.
 * ControllerDirection : Either DIRECT or REVERSE. determines which direction the output will move when faced with a given error. DIRECT is most common
 *
 */
PID(PID_TypeDef *uPID, double *Input, double *Output, double *Setpoint, double Kp, double Ki, double Kd, PIDPON_TypeDef POn, PIDCD_TypeDef ControllerDirection);


PID_TypeDef APID;

double Acc, PIDOut, AccSetpoint;

PID(&APID, &Acc, &PIDOut, &AccSetpoint, 2, 5, 1, _PID_P_ON_E, _PID_CD_DIRECT);

#endif /* INC_PID_H_ */
