/*
 * ColorChase.cpp
 *
 *  Created on: 4 avr. 2014
 *      Author: jeckel
 */

#include "Effect_ColorChase.h"

/**
 * Constructor
 */
Effect_ColorChase::Effect_ColorChase(T_EffectConfig config)
    : Effect_Generic(config)
{
}

/**
 * Override pre-step actions
 */
void Effect_ColorChase::_preStep()
{
    if (config.direction == DOWN) {
        segment->leds()[segment->length() - step_index - 1] = config.color;
    } else {
        segment->leds()[step_index] = config.color;
    }
    //segment->config.leds[step_index] = config.color;
}

/**
 * Override post-step actions
 */
void Effect_ColorChase::_postStep()
{
    memset(segment->leds(), 0x00, segment->length() * sizeof(CRGB));
}
