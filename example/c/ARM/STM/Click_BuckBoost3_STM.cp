#line 1 "D:/Clicks_git/B/Buck-boost_3_click/SW/example/c/ARM/STM/Click_BuckBoost3_STM.c"
#line 1 "d:/clicks_git/b/buck-boost_3_click/sw/example/c/arm/stm/click_buckboost3_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "d:/clicks_git/b/buck-boost_3_click/sw/example/c/arm/stm/click_buckboost3_config.h"
#line 1 "d:/clicks_git/b/buck-boost_3_click/sw/example/c/arm/stm/click_buckboost3_types.h"
#line 1 "d:/clicks_git/b/buck-boost_3_click/sw/library/__buckboost3_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 57 "d:/clicks_git/b/buck-boost_3_click/sw/library/__buckboost3_driver.h"
extern const uint8_t _BUCKBOOST3_DEVICE_ENABLE;
extern const uint8_t _BUCKBOOST3_DEVICE_DISABLE;
#line 79 "d:/clicks_git/b/buck-boost_3_click/sw/library/__buckboost3_driver.h"
void buckboost3_gpioDriverInit( const uint8_t*  gpioObj);
#line 86 "d:/clicks_git/b/buck-boost_3_click/sw/library/__buckboost3_driver.h"
void buckboost3_enable(uint8_t state);
#line 93 "d:/clicks_git/b/buck-boost_3_click/sw/library/__buckboost3_driver.h"
uint8_t buckboost3_getInterruptState();
#line 30 "D:/Clicks_git/B/Buck-boost_3_click/SW/example/c/ARM/STM/Click_BuckBoost3_STM.c"
void systemInit()
{
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
 mikrobus_logInit( _LOG_USBUART_A, 9600 );
 Delay_ms( 100 );
}

void applicationInit()
{
 buckboost3_gpioDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO );
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
