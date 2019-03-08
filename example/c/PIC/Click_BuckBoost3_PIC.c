/*
Example for BuckBoost3 Click

    Date          : okt 2018.
    Author        : Katarina Perendic

Test configuration PIC :
    
    MCU             : P18F87K22
    Dev. Board      : EasyPIC PRO v7
    PIC Compiler ver : v7.2.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Sets INT pin as INPUT and CS pin as OUTPUT
- Application Initialization - Initialization driver init and enable device
- Application Task - (code snippet) - It checks if the input voltage is below the operating voltage.

*/

#include "Click_BuckBoost3_types.h"
#include "Click_BuckBoost3_config.h"

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_logInit( _LOG_USBUART, 9600 );
    Delay_ms( 100 );
}

void applicationInit()
{
    buckboost3_gpioDriverInit( (T_BUCKBOOST3_P)&_MIKROBUS1_GPIO );
    buckboost3_enable(_BUCKBOOST3_DEVICE_ENABLE);
}

void applicationTask()
{
    uint8_t PGOOD_state;
    
    PGOOD_state = buckboost3_getInterruptState();
    if (PGOOD_state == 0)
    {
        mikrobus_logWrite(" Low input voltage !!!", _LOG_LINE);
    }
    Delay_ms( 1000 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}