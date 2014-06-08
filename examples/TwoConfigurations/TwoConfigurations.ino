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

struct CRGB leds[NUM_LEDS];

/** FIRST CONFIGURATION **/
#define NB_SEGMENT   2
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

/** SECOND CONFIGURATION **/
#define NB_SEGMENT_OFF    1
T_SegmentConfig seg_config_off[NB_SEGMENT_OFF] = {
    { leds, NUM_LEDS}
};

T_EffectConfig effect_config_off[NB_SEGMENT] = {
    { CWhite, DOWN, Spark }
};

TM1809Controller800Mhz<LEDSTRIP_PIN> LED;
SegmentCollection segments;
SegmentCollection segmentsOff;

unsigned long time;

// Interval between configuration
#define CONFIG_INTERVAL 5000

void setup()
{
	Effect_Factory factory;

    // Init first config with 2 segments
    for(unsigned int i = 0; i < NB_SEGMENT; i++) {
        segments.addSegment(new Segment(seg_config[i], factory.createEffect(effect_config[i])));
    }
    segments.init();

    // Init second config with only 1 segment
    for(unsigned int i = 0; i < NB_SEGMENT_OFF; i++) {
        segmentsOff.addSegment(new Segment(seg_config_off[i], factory.createEffect(effect_config_off[i])));
    }
    segmentsOff.init();

    LED.init();
    time = millis();
}

void loop()
{
    static SegmentCollection* currentConfig = &segments;
    
    currentConfig->preStep();
    LED.showRGB((unsigned char *) leds, NUM_LEDS);
    currentConfig->postStep();
    delay(20);

    // switch between configurations
    if (millis() - time > CONFIG_INTERVAL) {
        currentConfig = (currentConfig == &segments) ? &segmentsOff : &segments;
        memset(leds, 0, NUM_LEDS * sizeof(struct CRGB));
        time = millis();
    }
}