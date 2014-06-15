/*
 * Segment.h
 *
 *  Created on: 3 avr. 2014
 *      Author: jeckel
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_

#include <Color.h>
#include "Types.h"
#include "Effect_Generic.h"

class Effect_Generic;

class Segment {
        /* properties */
    public:
        Effect_Generic*  effect;
    protected:
        T_SegmentConfig  config;
        uint16_t         step_loop    = 0;
        uint16_t         step_index   = 0;
        boolean          has_effect = false;

        /* methods */
    public:
        Segment() { /* remove warnings */ effect = (Effect_Generic*) malloc(0); };
        Segment(T_SegmentConfig config);
        Segment(T_SegmentConfig config, Effect_Generic* effect);
        void setEffect(Effect_Generic* eff);
        void preStep();
        void postStep();
        void init();
        CRGB* leds() { return config.leds; };
        uint16_t length() { return config.length; };
        virtual ~Segment() {};
};

class SegmentCollection {
        /* properties */
    protected:
        unsigned int size = 0;
        Segment** collection;

        /* methods */
    public:
        SegmentCollection();
        void addSegment(Segment* seg);
        Segment* getSegment(unsigned int i);
        void preStep();
        void postStep();
        void init();
        void setSegmentColor(unsigned int index, CRGB color);
        virtual ~SegmentCollection() {};
};

#endif /* SEGMENT_H_ */
