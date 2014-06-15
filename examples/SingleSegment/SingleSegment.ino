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
#define NB_SEGMENT   1

struct CRGB leds[NUM_LEDS];

// Configure each segment with point to leds and segment length
T_SegmentConfig seg_config[NB_SEGMENT] = {
    { leds, NUM_LEDS, { CBlue, UP, Wave }}
};


TM1809Controller800Mhz<LEDSTRIP_PIN> LED;
SegmentCollection segments;

void setup()
{
	Effect_Factory factory;
    for(unsigned int i = 0; i < NB_SEGMENT; i++) {
        segments.addSegment(new Segment(seg_config[i]));
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