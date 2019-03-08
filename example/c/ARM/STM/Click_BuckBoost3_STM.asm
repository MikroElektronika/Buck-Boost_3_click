_systemInit:
;Click_BuckBoost3_STM.c,30 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_BuckBoost3_STM.c,32 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
MOVS	R2, #1
MOVS	R1, #7
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_BuckBoost3_STM.c,33 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #2
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_BuckBoost3_STM.c,34 :: 		mikrobus_logInit( _LOG_USBUART_A, 9600 );
MOVW	R1, #9600
MOVS	R0, #32
BL	_mikrobus_logInit+0
;Click_BuckBoost3_STM.c,35 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_BuckBoost3_STM.c,36 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_BuckBoost3_STM.c,38 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_BuckBoost3_STM.c,40 :: 		buckboost3_gpioDriverInit( (T_BUCKBOOST3_P)&_MIKROBUS1_GPIO );
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_buckboost3_gpioDriverInit+0
;Click_BuckBoost3_STM.c,41 :: 		buckboost3_enable(_BUCKBOOST3_DEVICE_ENABLE);
MOVS	R0, __BUCKBOOST3_DEVICE_ENABLE
BL	_buckboost3_enable+0
;Click_BuckBoost3_STM.c,42 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_BuckBoost3_STM.c,44 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_BuckBoost3_STM.c,48 :: 		PGOOD_state = buckboost3_getInterruptState();
BL	_buckboost3_getInterruptState+0
;Click_BuckBoost3_STM.c,49 :: 		if (PGOOD_state == 0)
CMP	R0, #0
IT	NE
BNE	L_applicationTask2
;Click_BuckBoost3_STM.c,51 :: 		mikrobus_logWrite(" Low input voltage !!!", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr1_Click_BuckBoost3_STM+0)
MOVT	R0, #hi_addr(?lstr1_Click_BuckBoost3_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_BuckBoost3_STM.c,52 :: 		}
L_applicationTask2:
;Click_BuckBoost3_STM.c,53 :: 		Delay_ms( 1000 );
MOVW	R7, #6911
MOVT	R7, #183
NOP
NOP
L_applicationTask3:
SUBS	R7, R7, #1
BNE	L_applicationTask3
NOP
NOP
NOP
;Click_BuckBoost3_STM.c,54 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_BuckBoost3_STM.c,56 :: 		void main()
;Click_BuckBoost3_STM.c,58 :: 		systemInit();
BL	_systemInit+0
;Click_BuckBoost3_STM.c,59 :: 		applicationInit();
BL	_applicationInit+0
;Click_BuckBoost3_STM.c,61 :: 		while (1)
L_main5:
;Click_BuckBoost3_STM.c,63 :: 		applicationTask();
BL	_applicationTask+0
;Click_BuckBoost3_STM.c,64 :: 		}
IT	AL
BAL	L_main5
;Click_BuckBoost3_STM.c,65 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
