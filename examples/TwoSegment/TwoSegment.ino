/**
 * Example with a single Segment configuration
 *
 * WARNING !! This library requires two additionnal libraries :
 * - Color : https://github.com/jeckel/arduino-color-lib
 * - FastSPI : https://github.com/jeckel/arduino-fastpsi_led-lib
 *
 * @author : Jeckel
 * @link : https://github.com/jeckel/arduino-segment-lib
 */
#include <Color.h>
#include <FastSPI_LED2.h>
#include <Segment.h>

#define LEDSTRIP_PIN 6
#define NUM_LEDS     21
#define NB_SEGMENT   2

struct CRGB leds[NUM_LEDS];

// Configure each segment with point to leds and segment length
T_SegmentConfig seg_config[NB_SEGMENT] = {
    { leds, 10},
    { leds + 10, 11}
};

// Effect link to segment : color, direction (up or down), and effect
T_EffectConfig effect_config[NB_SEGMENT] = {
    { CBlue, UP, Wave },
    { CRed, DOWN, Color_Chase }
};

TM1809Controller800Mhz<LEDSTRIP_PIN> LED;
SegmentCollection segments;

void setup()
{
	Effect_Factory factory;
    for(unsigned int i = 0; i < NB_SEGMENT; i++) {
        segments.addSegment(new Segment(seg_config[i], factory.createEffect(effect_config[i])));
    }
    segments.init();
    LED.init();
}

void loop()
{
    segments.preStep();
    LED.showRGB((unsigned char *) leds, NUM_LEDS);
    segments.postStep();
    delay(20);
}