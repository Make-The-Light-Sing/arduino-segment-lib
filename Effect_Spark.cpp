/*
 * Spark.cpp
 *
 *  Created on: 4 avr. 2014
 *      Author: jeckel
 */

#include "Effect_Spark.h"

/**
 * Constructor
 */
Effect_Spark::Effect_Spark(T_EffectConfig config)
    : Effect_Generic(config)
{
}

/**
 * Step for spark effect
 */
void Effect_Spark::_preStep()
{
    position = random(segment->length());
    last_color = segment->leds()[position];
    segment->leds()[position] = config.color;
}   // _preStep

void Effect_Spark::_postStep()
{
    segment->leds()[position] = last_color;
}   // _postStep
