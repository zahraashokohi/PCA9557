#include "PCA9557.h"


extern I2C_HandleTypeDef hi2c1;
/*
 * set pins for input or output
 * */
/*
 *  0×03 Configuration
 *  value = 00 -> all IO 0~7 output
 *  value = ff -> all IO 0~7 input
 */
void PCA9557_SetModePin (uint16_t deviceAddress , uint8_t value)
{
  HAL_I2C_Mem_Write(&hi2c1,deviceAddress,0x03,I2C_MEMADD_SIZE_8BIT,&value,sizeof(value), HAL_MAX_DELAY);
}
/*
 * set value for data outputting
 *  0×01 Output Port
 *  0 - > Output pin is 0 or GND
 *  1 - > Output pin is vcc  (2.5 ~ 5)
 */
void PCA9557_SetValuePins(uint16_t deviceAddress , uint8_t pins)
{
    HAL_I2C_Mem_Write(&hi2c1, deviceAddress, 0x01,I2C_MEMADD_SIZE_8BIT,&pins, sizeof(pins), HAL_MAX_DELAY);
}
/*
 *  0×02 Polarity Inversion Read/write byte
 *  The Polarity Inversion Register allows the logical state of input pins to be inverted, making active-low
 *  signals appear as active-high when read through the Input Port Register.
 */
void PCA9557_PolaritYInputInversion(uint16_t deviceAddress,uint8_t value)
{
	 HAL_I2C_Mem_Write(&hi2c1,deviceAddress,0x02,I2C_MEMADD_SIZE_8BIT,&value,sizeof(value), HAL_MAX_DELAY);
}

uint8_t PCA9557_ReadRegisterData(uint16_t deviceAddress, uint8_t  registerAddress)
{
	 uint8_t value = 0;
	 HAL_I2C_Mem_Write(&hi2c1,deviceAddress,registerAddress,I2C_MEMADD_SIZE_8BIT,&value,sizeof(value), HAL_MAX_DELAY);
	 return value;
}
void I2C_Scan(void)
{
    for(uint8_t addr = 1; addr < 128; addr++)
    {
        if(HAL_I2C_IsDeviceReady(&hi2c1, addr << 1, 2, 100) == HAL_OK)
        {
            /*
             * FOUND Device
             */
        }
    }
}
