#ifndef __MPU6050__H
#define __MPU6050__H
#include <stdint.h>


uint8_t MPU6050_ReadReg(uint8_t RegAddress);
void MPU6050_WriteReg(uint8_t RegAddress, uint8_t Data);


void MPU6050_Init(void);
void MPU6050_GetData(int16_t *AccX, int16_t *AccY, int16_t *AccZ,
                        int16_t *GyroX, int16_t *GyroY, int16_t *GyroZ);
uint8_t MPU6050_GetId(void);

#endif
