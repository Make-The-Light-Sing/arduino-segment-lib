/*
 * Types.h
 *
 *  Created on: 4 avr. 2014
 *      Author: jeckel
 */

#ifndef TYPES_H_
#define TYPES_H_

#include <Color.h>


/**
 * Define type for effect direction
 */
typedef enum E_Direction {
    UP   = 1,
    DOWN = 2
};

/**
 * Define the type of effect enum list
 */
typedef enum E_Effect {
    Color_Chase = 1,
    Fire        = 2,
    Pulse       = 3,
    Rainbow     = 4,
    Spark       = 5,
    Wave        = 6
};

/**
 * Define the effect configuration structure
 */
typedef struct T_EffectConfig {
    CRGB        color;
    E_Direction direction;
    E_Effect    type;
};

/**
 * Define the effect configuration structure
 */
typedef struct T_SegmentConfig {
    uint16_t       start;
    uint16_t       length;
    T_EffectConfig effect;
};

/**
 * Define the Segment list configuration
 */
typedef struct T_SegmentCollectionConfig {
    uint8_t  size;
    uint16_t delay;
    T_SegmentConfig* segments;
};

#endif /* TYPES_H_ */
