/*
Example for BuckBoost3 Click

    Date          : okt 2018.
    Author        : Katarina Perendic

Test configuration CEC :
    
    MCU              : CEC1702
    Dev. Board       : Clicker 2 for CEC1702
    ARM Compiler ver : v6.0.0.0

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
    mikrobus_logInit( _MIKROBUS2, 9600 );
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