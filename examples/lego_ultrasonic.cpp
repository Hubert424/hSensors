@NAME: lego_ultrasonic
@PORTS: stm32
@BOARDS: core2,core2mini

#include <hFramework.h>

#include <Lego_Ultrasonic.h>

using namespace hSensors;

void hMain(void)
{
	sys.setLogDev(&Serial);
	hLegoSensor_i2c ls(hSens1);
	Lego_Ultrasonic sensor(ls);

	for (;;)
	{
		int dist = sensor.readDist();
		LED1.toggle();
		printf("dist %d\r\n", dist);
		sys.delay_ms(10);
	}
}




@NAME: lego_ultrasonic
@PORTS: stm32
@BOARDS: robocore

#include <hFramework.h>

#include <Lego_Ultrasonic.h>

using namespace hSensors;

void hMain(void)
{
	sys.setLogDev(&Serial);
	Lego_Ultrasonic sensor(hSens1);

	for (;;)
	{
		int dist = sensor.readDist();
		LED1.toggle();
		printf("dist %d\r\n", dist);
		sys.delay_ms(10);
	}
}
