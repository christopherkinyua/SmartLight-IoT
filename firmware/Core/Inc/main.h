/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#include "driver/i2c.h"

#ifdef __cplusplus
extern "C"
{
#endif

    // These are the default pins for I2C: Can change them later on

#define I2C_MASTER_SCL_IO 22
#define I2C_MASTER_SDA_IO 21
#define I2C_MASTER_NUM I2C_NUM_0
#define I2C_MASTER_FREQ_HZ 100000
#define I2C_MASTER_TX_BUF_DISABLE 0
#define I2C_MASTER_RX_BUF_DISABLE 0
#define INA219_ADDRESS 0x40 // INA219 I2C address

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */