#ifndef UTILITIES_H
#define UTILITIES_H

// PixyCam specs (https://forum.pixycam.com/t/what-is-the-max-x-and-y-of-the-pixy2/7356)
const int X_RESOLUTION = 315;
const int Y_RESOLUTION = 207;

const int FRAME_WIDTH = 78;
const int FRAME_HEIGHT = 51;

const int MAX_ACTUATION = 255;
const int MIN_ACTUATION = -255;

/****************************** Functions ******************************/

float clampActuation(float value) {
    value = min(value, MAX_ACTUATION);
    value = max(value, MIN_ACTUATION);
    return value;
}

#endif // UTILITIES_H
