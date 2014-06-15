/*
 * Generic.cpp
 *
 *  Created on: 4 avr. 2014
 *      Author: jeckel
 */

#include "Effect_Generic.h"

#include "Effect_ColorChase.h"
#include "Effect_Fire.h"
#include "Effect_Pulse.h"
#include "Effect_Rainbow.h"
#include "Effect_Spark.h"
#include "Effect_Wave.h"

/**
 * Empty constructor
 */
Effect_Generic::Effect_Generic()
{
    /* remove warnings */
    segment = (Segment*) malloc(0);
}

/**
 * Main constructor
 */
Effect_Generic::Effect_Generic(T_EffectConfig config)
    : config(config)
{
    /* remove warnings */
    segment = (Segment*) malloc(0);
};

/**
 * Destructor
 */
Effect_Generic::~Effect_Generic()
{
}

/**
 * Define segment on which the effect should apply
 */
void Effect_Generic::setSegment(Segment* s)
{
    segment = s;
}

/**
 * Start of step
 */
void Effect_Generic::preStep()
{
    _preStep();
}

/**
 * End of step
 */
void Effect_Generic::postStep() {
    _postStep();
    step_index ++;
    if (step_index >= step_loop) {
        step_index = 0;
        _endLoop();
    }
}

/**
 * Redefine color
 */
void Effect_Generic::setColor(CRGB color)
{
    config.color = color;
}

/**
 * Init effect
 */
void Effect_Generic::init()
{
    step_loop = segment->length();
}   // init

/**
 * Effect factory
 */
Effect_Generic* Effect_Factory::createEffect(T_EffectConfig config)
{
    switch(config.type) {
        case Color_Chase : {
            return new Effect_ColorChase(config);
            break;
        }
        case Fire : {
            return new Effect_Fire(config);
            break;
        }
        case Pulse : {
            return new Effect_Pulse(config);
            break;
        }
        case Rainbow : {
            return new Effect_Rainbow(config);
            break;
        }
        case Spark : {
            return new Effect_Spark(config);
            break;
        }
        case Wave : {
            return new Effect_Wave(config);
            break;
        }
    }
}
