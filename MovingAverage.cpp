/**
 * @file MovingAverage.cpp
 * @author Wesley José Santos (binary-quantum.com)
 * @brief Classe para cálculo de média móvel
 * @version 0.4
 * @date 2020-12-31
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "MovingAverage.h"

/**
 * @brief Constrói um objeto do tipo MovingAverage
 * 
 * @param buffer Buffer as ser utilizado para o cálculo da média móvel
 * @param samplesCount Quantidade de amostras a ser utilizada para o cálculo da média móvel
 */
MovingAverage::MovingAverage(int *buffer, int samplseCount){
    this->averageBuffer = buffer;
    this->samplesCount = samplesCount;
}

/**
 * @brief Define a quantidade de amostras usadas no filtro
 * 
 * @param samplesCount 
 */
void MovingAverage::setSamplesCount(int samplesCount){
    this->reset();
    this->samplesCount = samplesCount;
}

/**
 * @brief Obtém o valor da média móvel
 * 
 * @param currentValue Valor atual da variável da qual deseja se obter a média móvel
 * @return int O valor atual da média móvel
 */
int MovingAverage::getAverage(int currentValue){
    if(samplesCount == 0){
        return currentValue;
    }

    if(enableInterpolation && (lastValue != currentValue)){
        interpolation = (currentValue + lastValue) / 2;
        lastValue = currentValue;
        currentValue = interpolation;
    }

    if(averageCount >= samplesCount){
        averageSum -= averageBuffer[bufIdx];
        averageBuffer[bufIdx] = currentValue;
        averageSum += averageBuffer[bufIdx];

        bufIdx++;

        if(bufIdx == samplesCount){
            bufIdx = 0;
        }
        average = averageSum / averageCount;
    }else{
        averageBuffer[averageCount] = currentValue;
        averageCount++;
        if(averageCount >= samplesCount){
            for (int i = 0; i < averageCount; i++)
            {
                averageSum += averageBuffer[i];
            }
        }
        return currentValue;
    }

    return average;
}

/**
 * @brief Habilita a interpolação no filtro da média móvel
 * 
 * @param state
 */
void MovingAverage::setInterpolation(int state){
    this->enableInterpolation = state;
}

/**
 * @brief Reinicia o cálculo da média móvel
 * 
 */
void MovingAverage::reset(){
    this->averageSum = 0;
    this->averageCount = 0;
    this->bufIdx = 0;

    for (int i = 0; i < this->samplesCount; i++)
    {
        this->averageBuffer[i] = 0;
    }
}