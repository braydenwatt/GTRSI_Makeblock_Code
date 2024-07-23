#ifndef MOTORS_H
#define MOTORS_H

#include "MeMegaPi.h"

MePort portSet(PORT_5);
MeMegaPiDCMotor motorR(PORT1B);
MeMegaPiDCMotor motorL(PORT2B);
MeMegaPiDCMotor motorA(PORT3B);
MeMegaPiDCMotor motorG(PORT4B);
MeEncoderOnBoard encoderA(SLOT3);


int get_arm_position(void) {
    encoderA.updateCurPos();
    return encoderA.getCurPos();
}

void isr_process_encoder1(void)
{
    if(digitalRead(encoderA.getPortB()) == 0)
    {
        encoderA.pulsePosMinus();
    }
    else
    {
        encoderA.pulsePosPlus();;
    }
}

void setup_encoder(void) {
    attachInterrupt(encoderA.getIntNum(), isr_process_encoder1, RISING);
    TCCR1A = _BV(WGM10);
    TCCR1B = _BV(CS11) | _BV(WGM12);
    encoderA.setPulse(7);
    encoderA.setRatio(26.9);
    encoderA.setPosPid(1.8,0,1.2);
    encoderA.setSpeedPid(0.18,0,0);
}

#endif // MOTORS_H
