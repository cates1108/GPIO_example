#include <bcm2835.h>	//in system lib
#include <stdio.h>

#define PIN RPI_GPIO_P1_12	//GPIO18:Pin12

int main(void)
{
	if (!bcm2835_init())
	{
		printf("2835 init error\n");
		return 0;
	}

	bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);

	while(1)
	{
		printf("LED On\n");
		bcm2835_gpio_write(PIN,HIGH);
		delay(500);
		printf("LED Off\n");
		bcm2835_gpio_write(PIN,LOW);
		delay(500);
	}

	return 0;
}

