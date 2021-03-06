@PORTS: stm32
@NAME: hitechnic_compass
#include <hFramework.h>

#include <Hitechnic_Compass.h>

using namespace hSensors;

void hMain(void)
{
	sys.setLogDev(&Serial);
	
{% if board(robocore) %}
	Hitechnic_Compass sensor(hSens1);
{% else %}
	hLegoSensor_i2c ls(hSens1);
	Hitechnic_Compass sensor(ls);
{% endif %}
	
	for (;;)
	{
		uint16_t heading;
		sensor.readHeading(heading);
		LED1.toggle();
		printf("head %d\r\n", heading);
		sys.delay_ms(10);
	}
}
