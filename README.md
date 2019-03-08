![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# BuckBoost3 Click

- **CIC Prefix**  : BUCKBOOST3
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : okt 2018.

---

### Software Support

We provide a library for the BuckBoost3 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2624/buck-boost-3-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library includes features to enable or disable devices and functions to check if the input voltage is below the operating voltage.

Key functions :

- ``` void buckboost3_enable(uint8_t state) ``` - Function for enable/disable device
- ``` uint8_t buckboost3_getInterruptState() ``` - Function for get Intterupt pin state

**Examples Description**

The application is composed of three sections :

- System Initialization - Sets INT pin as INPUT and CS pin as OUTPUT
- Application Initialization - Initialization driver init and enable device
- Application Task - (code snippet) - It checks if the input voltage is below the operating voltage.


```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2624/buck-boost-3-click) page.

Other mikroE Libraries used in the example:

- GPIO

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
