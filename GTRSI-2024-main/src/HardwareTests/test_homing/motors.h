#ifndef MOTORS_H
#define MOTORS_H

#include "MeMegaPi.h"

MePort portSet(PORT_5);
MeMegaPiDCMotor motorA(PORT3B);
MeEncoderOnBoard Encoder_1(SLOT3);


void isr_process_encoder1(void)
{
    if(digitalRead(Encoder_1.getPortB()) == 0)
    {
        Encoder_1.pulsePosMinus();
    }
    else
    {
        Encoder_1.pulsePosPlus();;
    }
}

void setup_encoder(void) {
    attachInterrupt(Encoder_1.getIntNum(), isr_process_encoder1, RISING);
    TCCR1A = _BV(WGM10);
    TCCR1B = _BV(CS11) | _BV(WGM12);
    Encoder_1.setPulse(7);
    Encoder_1.setRatio(26.9);
    Encoder_1.setPosPid(1.8,0,1.2);
    Encoder_1.setSpeedPid(0.18,0,0);
}

#endif // MOTORS_H
