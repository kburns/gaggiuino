#include "rtd.h"

#define RREF 430.0

RTDWrapper::RTDWrapper(int8_t CS, int8_t DI, int8_t DO, int8_t CLK) : max(Adafruit_MAX31865(CS, DI, DO, CLK)), pt100(pt100rtd()) {}

void RTDWrapper::begin(void)
{
  max.begin(MAX31865_2WIRE);
}

float RTDWrapper::readCelsius(void)
{
      uint16_t rtd, ohmsx100;
      uint32_t dummy;
      float temp;
      rtd = max.readRTD();
      // Use uint16_t (ohms * 100) since it matches data type in lookup table.
      dummy = ((uint32_t)(rtd << 1)) * 100 * ((uint32_t) floor(RREF));
      dummy >>= 16;
      ohmsx100 = (uint16_t) (dummy & 0xFFFF);
      // compare lookup table and common computational methods
      temp	= pt100.celsius(ohmsx100);
      return temp;
}