
#include <Adafruit_MAX31865.h>
#include <pt100rtd.h>

class RTDWrapper
{
  private:
    Adafruit_MAX31865 max;
    pt100rtd pt100;
  public:
    RTDWrapper(int8_t CS, int8_t DI, int8_t DO, int8_t CLK);
    void begin(void);
    float readCelsius(void);
};
