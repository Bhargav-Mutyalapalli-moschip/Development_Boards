#ifndef GPIO_H_
#define GPIO_H_

typedef enum GPIO_PORTS{
	GPIO_PORT_A = 0x40010800,
	GPIO_PORT_B = 0x40010c00,
	GPIO_PORT_C = 0x40011000,
	GPIO_PORT_D = 0x40011400,
	GPIO_PORT_E = 0x40011800,
	GPIO_PORT_F = 0x40011c00,
	GPIO_PORT_G = 0x40012000,
}GPIO_PORTS;

typedef enum GPIO_OFFSETS{
	GPIO_CRL  = 0x00,
	GPIO_CRH  = 0x04,
	GPIO_IDR  = 0x08,
	GPIO_ODR  = 0x0c,
	GPIO_BSRR = 0x10,
	GPIO_BRR  = 0x14,
	GPIO_LCKR = 0x18,
}GPIO_OFFSETS;

typedef enum GPIO_MODES{
	GPIO_MODE_INPUT			= 0b00,
	GPIO_MODE_OUTPUT_10MHZ	= 0b01,
	GPIO_MODE_OUTPUT_2MHZ	= 0b10,
	GPIO_MODE_OUTPUT_50MHZ	= 0b11,
}GPIO_MODES;

typedef enum GPIO_CONFIGS{
	// INPUT
	GPIO_CONFIG_INPUT_ANALOG		= 0b00,
	GPIO_CONFIG_INPUT_FLOATING		= 0b01,
	GPIO_CONFIG_INPUT_PULL_UP_DOWN	= 0b10,

	// OUTPUT
	GPIO_CONFIG_OUTPUT_GP_PUSHPULL	= 0b00,
	GPIO_CONFIG_OUTPUT_GP_OPENDRAIN	= 0b01,
	GPIO_CONFIG_OUTPUT_AF_PUSHPULL	= 0b10,
	GPIO_CONFIG_OUTPUT_AF_OPENDRAIN	= 0b11,
}GPIO_CONFIGS;

#define GPIO_PULL_UP 1
#define GPIO_PULL_DOWN 0


void GPIOEnable(GPIO_PORTS port);
void GPIOSetPinMode(GPIO_PORTS port, unsigned char pin, GPIO_MODES mode, GPIO_CONFIGS config);
void GPIOWrite(GPIO_PORTS port, unsigned char pin, bool state);
void GPIOSetPullDirection(GPIO_PORTS port, unsigned char pin, bool pull);

#endif