/*
    __buckboost3_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __buckboost3_driver.h
@brief    BuckBoost3 Driver
@mainpage BuckBoost3 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   BUCKBOOST3
@brief      BuckBoost3 Click Driver
@{

| Global Library Prefix | **BUCKBOOST3** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **okt 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _BUCKBOOST3_H_
#define _BUCKBOOST3_H_

/** 
 * @macro T_BUCKBOOST3_P
 * @brief Driver Abstract type 
 */
#define T_BUCKBOOST3_P    const uint8_t*

/** @defgroup BUCKBOOST3_COMPILE Compilation Config */              /** @{ */

//  #define   __BUCKBOOST3_DRV_SPI__                            /**<     @macro __BUCKBOOST3_DRV_SPI__  @brief SPI driver selector */
//  #define   __BUCKBOOST3_DRV_I2C__                            /**<     @macro __BUCKBOOST3_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __BUCKBOOST3_DRV_UART__                           /**<     @macro __BUCKBOOST3_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup BUCKBOOST3_VAR Variables */                           /** @{ */

extern const uint8_t _BUCKBOOST3_DEVICE_ENABLE;
extern const uint8_t _BUCKBOOST3_DEVICE_DISABLE;

                                                                       /** @} */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup BUCKBOOST3_INIT Driver Initialization */              /** @{ */

#ifdef   __BUCKBOOST3_DRV_SPI__
void buckboost3_spiDriverInit(T_BUCKBOOST3_P gpioObj, T_BUCKBOOST3_P spiObj);
#endif
#ifdef   __BUCKBOOST3_DRV_I2C__
void buckboost3_i2cDriverInit(T_BUCKBOOST3_P gpioObj, T_BUCKBOOST3_P i2cObj, uint8_t slave);
#endif
#ifdef   __BUCKBOOST3_DRV_UART__
void buckboost3_uartDriverInit(T_BUCKBOOST3_P gpioObj, T_BUCKBOOST3_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void buckboost3_gpioDriverInit(T_BUCKBOOST3_P gpioObj);
                                                                       /** @} */
/** @defgroup BUCKBOOST3_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Function for enable/disable device
 */
void buckboost3_enable(uint8_t state);

/**
 * @brief Function for get Intterupt pin state
 *
 * @return Interrupt state
 */
uint8_t buckboost3_getInterruptState();




                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_BuckBoost3_STM.c
    @example Click_BuckBoost3_TIVA.c
    @example Click_BuckBoost3_CEC.c
    @example Click_BuckBoost3_KINETIS.c
    @example Click_BuckBoost3_MSP.c
    @example Click_BuckBoost3_PIC.c
    @example Click_BuckBoost3_PIC32.c
    @example Click_BuckBoost3_DSPIC.c
    @example Click_BuckBoost3_AVR.c
    @example Click_BuckBoost3_FT90x.c
    @example Click_BuckBoost3_STM.mbas
    @example Click_BuckBoost3_TIVA.mbas
    @example Click_BuckBoost3_CEC.mbas
    @example Click_BuckBoost3_KINETIS.mbas
    @example Click_BuckBoost3_MSP.mbas
    @example Click_BuckBoost3_PIC.mbas
    @example Click_BuckBoost3_PIC32.mbas
    @example Click_BuckBoost3_DSPIC.mbas
    @example Click_BuckBoost3_AVR.mbas
    @example Click_BuckBoost3_FT90x.mbas
    @example Click_BuckBoost3_STM.mpas
    @example Click_BuckBoost3_TIVA.mpas
    @example Click_BuckBoost3_CEC.mpas
    @example Click_BuckBoost3_KINETIS.mpas
    @example Click_BuckBoost3_MSP.mpas
    @example Click_BuckBoost3_PIC.mpas
    @example Click_BuckBoost3_PIC32.mpas
    @example Click_BuckBoost3_DSPIC.mpas
    @example Click_BuckBoost3_AVR.mpas
    @example Click_BuckBoost3_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __buckboost3_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */