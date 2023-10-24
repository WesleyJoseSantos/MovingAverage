/**
 * @file MovingAverage.h
 * @author Wesley José Santos (binary-quantum.com)
 * @brief Classe para cálculo de média móvel
 * @version 0.3
 * @date 2020-12-31
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __MOVINGAVERAGE__H__
#define __MOVINGAVERAGE__H__

#include <stdint.h>

/**
 * @brief Classe para calcular médias móveis com interpolação
 * 
 */
class MovingAverage
{
private:
    uint32_t averageSum;
    int lastValue;
    int interpolation;
    int samplesCount;
    int averageCount;
    int bufIdx;
    int average;
    int *averageBuffer;
    int enableInterpolation;
public:
    MovingAverage(int *buffer, int samplesCount);
    void setSamplesCount(int samplesCount);
    int getAverage(int currentValue);
    void setInterpolation(int state);
    void reset();
};

#endif  //!__MOVINGAVERAGE__H__