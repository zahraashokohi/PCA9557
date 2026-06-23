#ifndef _PCA9557_H
#define _PCA9557_H

#include "main.h"

#define PCA9557_ADDR_0    (0x18 << 1)//A0 -> 0, A1 -> 0, A2 -> 0
#define PCA9557_ADDR_1    (0x19 << 1)//A0 -> 1, A1 -> 0, A2 -> 0
#define PCA9557_ADDR_2    (0x1A << 1)//A0 -> 0, A1 -> 1, A2 -> 0
#define PCA9557_ADDR_3    (0x1B << 1)//A0 -> 1, A1 -> 1, A2 -> 0
#define PCA9557_ADDR_4    (0x1C << 1)//A0 -> 0, A1 -> 0, A2 -> 1
#define PCA9557_ADDR_5    (0x1D << 1)//A0 -> 1, A1 -> 0, A2 -> 1
#define PCA9557_ADDR_6    (0x1E << 1)//A0 -> 0, A1 -> 1, A2 -> 1
#define PCA9557_ADDR_7    (0x1F << 1)//A0 -> 1, A1 -> 1, A2 -> 1



typedef union
{
	struct{
	  uint8_t  IO_0 : 1;
		uint8_t  IO_1 : 1;
		uint8_t  IO_2 : 1;
		uint8_t  IO_3 : 1;
		uint8_t  IO_4 : 1;
		uint8_t  IO_5 : 1;
		uint8_t  IO_6 : 1;
		uint8_t  IO_7 : 1;
	};
	uint8_t pins;

}PCA_Pin;

void PCA9557_SetModePin (uint16_t deviceAddress , uint8_t value);
void PCA9557_SetValuePins(uint16_t deviceAddress , uint8_t pins);
void PCA9557_PolaritYInputInversion(uint16_t deviceAddress,uint8_t value);
uint8_t PCA9557_ReadRegisterData(uint16_t deviceAddress, uint8_t  registerAddress);

void I2C_Scan(void);



#endif
