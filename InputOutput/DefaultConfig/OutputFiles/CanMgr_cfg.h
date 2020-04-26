/*********************************************************************************************************************** 
  *    DISCLAIMER                                                                                                        
  *    Copyright (C) 2011, 2016 Niyata Infotech Ptv. Ltd. All rights reserved.                                              
  ***********************************************************************************************************************/

/***********************************************************************************************************************
  * @author              Author : Mahendran L (mahendranl@niyatainfotech.com)                                                                         
***********************************************************************************************************************/
/***********************************************************************************************************************
  *                                                F I L E  D E S C R I P T I O N                                           
  *---------------------------------------------------------------------------------------------------------------------
*  @brief                                                                                                             
 * 
*  File name                       : CanMgr_cfg.c                                                                         
*  Version                         : V1.0.0      
*  Micros supported                : Micro Agnostic (Independant)     
*  Compilers supported             : XXXX                                                                           
*  Platforms supported             : XXXX                                                                            
*  Description            		 : This file contains functions definitions of CanMgr                                                                          
*
*
*
* @bug
  *---------------------------------------------------------------------------------------------------------------------*/
/**********************************************************************************************************************/
/* ====================================================================================================================
*                          I N C L U D E   F I L E S
* ===================================================================================================================*/
/**********************************************************************************************************************/


#ifndef CANMGR_CFG_H_
#define CANMGR_CFG_H_

#include "..\src\CanMgr_Types.h"
#include "hal_stdtypes.h"

#include "stdio.h"
/**Reception data Callback function mapping table*/

#define CANMGR_ISG_TORQUE_EST_RXCBK     NULL
#define CANMGR_ISG_STATE_RXCBK     NULL
#define CANMGR_ISG_TORQUE_MIN_SLEW_RATE_RXCBK     NULL
#define CANMGR_ISG_MIN_TORQUE_RXCBK     NULL
#define CANMGR_ISG_SPEED_SETPOINT_RXCBK     NULL
#define CANMGR_ENGINE_STATE_RXCBK     NULL
#define CANMGR_ISG_TORQUE_AVAILABLE_RXCBK     NULL
#define CANMGR_CRANK_CMD_RXCBK     NULL
#define CANMGR_ISG_TORQUE_MAX_SLEW_RATE_RXCBK     NULL
#define CANMGR_INERTIA_SWITCH_STATE_RXCBK     &Test1
#define CANMGR_AMBIENT_TEMP_RXCBK     NULL
#define CANMGR_EMERGENCY_SWITCH_STATE_RXCBK     NULL
#define CANMGR_BRAKE_PEDAL_POS_RXCBK     NULL
#define CANMGR_DRIVE_MODE_RXCBK     NULL
#define CANMGR_ENGINE_STOP_REQUESTED_RXCBK     NULL
#define CANMGR_PARK_BRAKE_STATE_RXCBK     NULL
#define CANMGR_VEHICLE_POWER_STATE_RXCBK     NULL
#define CANMGR_COOLANT_TEMP_RXCBK     NULL
#define CANMGR_REVERSE_SWITCH_STATE_RXCBK     NULL
#define CANMGR_CRANK_REQUESTED_RXCBK     NULL
#define CANMGR_VEHICLE_SHUTDOWN_REQ_RXCBK     NULL



/*Reception timeout Callback function mapping table*/
#define CANMGR_ISG_TORQUE_EST_TIMEOUT_CBK       NULL
#define CANMGR_ISG_STATE_TIMEOUT_CBK       NULL
#define CANMGR_ISG_TORQUE_MIN_SLEW_RATE_TIMEOUT_CBK       NULL
#define CANMGR_ISG_MIN_TORQUE_TIMEOUT_CBK       NULL
#define CANMGR_ISG_SPEED_SETPOINT_TIMEOUT_CBK       NULL
#define CANMGR_ENGINE_STATE_TIMEOUT_CBK       NULL
#define CANMGR_ISG_TORQUE_AVAILABLE_TIMEOUT_CBK       NULL
#define CANMGR_CRANK_CMD_TIMEOUT_CBK       NULL
#define CANMGR_ISG_TORQUE_MAX_SLEW_RATE_TIMEOUT_CBK       NULL
#define CANMGR_INERTIA_SWITCH_STATE_TIMEOUT_CBK       NULL
#define CANMGR_AMBIENT_TEMP_TIMEOUT_CBK       NULL
#define CANMGR_EMERGENCY_SWITCH_STATE_TIMEOUT_CBK       NULL
#define CANMGR_BRAKE_PEDAL_POS_TIMEOUT_CBK       NULL
#define CANMGR_DRIVE_MODE_TIMEOUT_CBK       NULL
#define CANMGR_ENGINE_STOP_REQUESTED_TIMEOUT_CBK       NULL
#define CANMGR_PARK_BRAKE_STATE_TIMEOUT_CBK       NULL
#define CANMGR_VEHICLE_POWER_STATE_TIMEOUT_CBK       NULL
#define CANMGR_COOLANT_TEMP_TIMEOUT_CBK       NULL
#define CANMGR_REVERSE_SWITCH_STATE_TIMEOUT_CBK       NULL
#define CANMGR_CRANK_REQUESTED_TIMEOUT_CBK       NULL
#define CANMGR_VEHICLE_SHUTDOWN_REQ_TIMEOUT_CBK       NULL





/*Remote wakeup callback function*/
#define APPLICATION_WAKEUP_CBK()   NULL
/*Network request confirmation callback function*/
#define APPLICATION_NETWORK_REQUEST_CBK_FUNC(NetworRequest_Result) NULL
/*Bus off indication callback function*/
#define APPLICATION_BUSOFF_INDICATION() NULL
#define INIT_DATA_VALUE    &Init_data_value[0][0]


/*CAN Manager mainfuncion periodicity*/
#define CANMGR_MAINFUNCTION_PERIOD       0x0Au 


/*Maximum number of RX signals*/
#define MAX_RX_SIGNALS        21u

/*TX messages in the network node*/
typedef enum
{
      PMU_STATUS=0u,
      BATT48_V_CELL14_PARAM=1u,
      BATT48_V_CELL13_PARAM=2u,
      BATT48_V_CELL12_PARAM=3u,
      BATT48_V_CELL11_PARAM=4u,
      BATT48_V_CELL10_PARAM=5u,
      BATT48_V_CELL9_PARAM=6u,
      BATT48_V_CELL8_PARAM=7u,
      BATT48_V_CELL7_PARAM=8u,
      BATT48_V_CELL6_PARAM=9u,
      BATT48_V_CELL5_PARAM=10u,
      BATT48_V_CELL4_PARAM=11u,
      BATT48_V_CELL3_PARAM=12u,
      BATT48_V_CELL2_PARAM=13u,
      BATT48_V_CELL1_PARAM=14u,
      BATT48_V_INFO=15u,
      BATT12_V_INFO=16u,
      BATT_LIMITS=17u,
      DCDC48_V_INFO=18u,
      DCDC12_V_INFO=19u,
      BATT12_V_CELL4_PARAM=20u,
      BATT12_V_CELL3_PARAM=21u,
      BATT12_V_CELL2_PARAM=22u,
      BATT12_V_CELL1_PARAM=23u,
      BATT48_V_TEMPS=24u,
      BATT12_V_TEMPS=25u,
       CANMGR_MAX_NO_OF_TX_MSGS =26u
}Tx_Msg_Id;

/*RX messages in the network node*/
typedef enum
{
      ISG_INFO=0u,
      EMS_INFO1=1u,
      VEHICLE_INFO=2u,
       CANMGR_MAX_NO_OF_RX_MSGS= 3u
}Rx_Msg_Id;



/*TX messages indentifier*/
typedef enum
{
      PMU_STATUS_FRAME_ID = (0x371),
      BATT48_V_CELL14_PARAM_FRAME_ID = (0x733),
      BATT48_V_CELL13_PARAM_FRAME_ID = (0x732),
      BATT48_V_CELL12_PARAM_FRAME_ID = (0x731),
      BATT48_V_CELL11_PARAM_FRAME_ID = (0x730),
      BATT48_V_CELL10_PARAM_FRAME_ID = (0x72f),
      BATT48_V_CELL9_PARAM_FRAME_ID = (0x72e),
      BATT48_V_CELL8_PARAM_FRAME_ID = (0x72d),
      BATT48_V_CELL7_PARAM_FRAME_ID = (0x72c),
      BATT48_V_CELL6_PARAM_FRAME_ID = (0x72b),
      BATT48_V_CELL5_PARAM_FRAME_ID = (0x72a),
      BATT48_V_CELL4_PARAM_FRAME_ID = (0x729),
      BATT48_V_CELL3_PARAM_FRAME_ID = (0x728),
      BATT48_V_CELL2_PARAM_FRAME_ID = (0x727),
      BATT48_V_CELL1_PARAM_FRAME_ID = (0x726),
      BATT48_V_INFO_FRAME_ID = (0x511),
      BATT12_V_INFO_FRAME_ID = (0x510),
      BATT_LIMITS_FRAME_ID = (0x737),
      DCDC48_V_INFO_FRAME_ID = (0x736),
      DCDC12_V_INFO_FRAME_ID = (0x735),
      BATT12_V_CELL4_PARAM_FRAME_ID = (0x724),
      BATT12_V_CELL3_PARAM_FRAME_ID = (0x723),
      BATT12_V_CELL2_PARAM_FRAME_ID = (0x722),
      BATT12_V_CELL1_PARAM_FRAME_ID = (0x721),
      BATT48_V_TEMPS_FRAME_ID = (0x734),
      BATT12_V_TEMPS_FRAME_ID = (0x725)
}Tx_Mxg_Frame_Id;


/*RX messages indentifier*/
typedef enum
{
      ISG_INFO_FRAME_ID = (0x320),
      EMS_INFO1_FRAME_ID = (0x310),
      VEHICLE_INFO_FRAME_ID = (0x340)
}Rx_Mxg_Frame_Id;

/* Tx Frame lengths in bytes. */


typedef enum
{
      PMU_STATUS_LENGTH = (4u),
      BATT48_V_CELL14_PARAM_LENGTH = (6u),
      BATT48_V_CELL13_PARAM_LENGTH = (6u),
      BATT48_V_CELL12_PARAM_LENGTH = (6u),
      BATT48_V_CELL11_PARAM_LENGTH = (6u),
      BATT48_V_CELL10_PARAM_LENGTH = (6u),
      BATT48_V_CELL9_PARAM_LENGTH = (6u),
      BATT48_V_CELL8_PARAM_LENGTH = (6u),
      BATT48_V_CELL7_PARAM_LENGTH = (6u),
      BATT48_V_CELL6_PARAM_LENGTH = (6u),
      BATT48_V_CELL5_PARAM_LENGTH = (6u),
      BATT48_V_CELL4_PARAM_LENGTH = (6u),
      BATT48_V_CELL3_PARAM_LENGTH = (6u),
      BATT48_V_CELL2_PARAM_LENGTH = (6u),
      BATT48_V_CELL1_PARAM_LENGTH = (6u),
      BATT48_V_INFO_LENGTH = (8u),
      BATT12_V_INFO_LENGTH = (8u),
      BATT_LIMITS_LENGTH = (8u),
      DCDC48_V_INFO_LENGTH = (5u),
      DCDC12_V_INFO_LENGTH = (5u),
      BATT12_V_CELL4_PARAM_LENGTH = (6u),
      BATT12_V_CELL3_PARAM_LENGTH = (6u),
      BATT12_V_CELL2_PARAM_LENGTH = (6u),
      BATT12_V_CELL1_PARAM_LENGTH = (6u),
      BATT48_V_TEMPS_LENGTH = (7u),
      BATT12_V_TEMPS_LENGTH = (7u)
}Tx_Mxg_Length;

/* Rx Frame lengths in bytes. */


typedef enum
{
      ISG_INFO_LENGTH = (3u),
      EMS_INFO1_LENGTH = (6u),
      VEHICLE_INFO_LENGTH = (5u)
}Rx_Mxg_Length;

/* Tx CLC Time. */


typedef enum
{
      PMU_STATUS_CLC_TIME   =(50u),
      BATT48_V_CELL14_PARAM_CLC_TIME = (100u),
      BATT48_V_CELL13_PARAM_CLC_TIME = (100u),
      BATT48_V_CELL12_PARAM_CLC_TIME = (100u),
      BATT48_V_CELL11_PARAM_CLC_TIME = (100u),
      BATT48_V_CELL10_PARAM_CLC_TIME = (100u),
      BATT48_V_CELL9_PARAM_CLC_TIME = (100u),
      BATT48_V_CELL8_PARAM_CLC_TIME = (100u),
      BATT48_V_CELL7_PARAM_CLC_TIME = (100u),
      BATT48_V_CELL6_PARAM_CLC_TIME = (100u),
      BATT48_V_CELL5_PARAM_CLC_TIME = (100u),
      BATT48_V_CELL4_PARAM_CLC_TIME = (100u),
      BATT48_V_CELL3_PARAM_CLC_TIME = (100u),
      BATT48_V_CELL2_PARAM_CLC_TIME = (100u),
      BATT48_V_CELL1_PARAM_CLC_TIME = (100u),
      BATT48_V_INFO_CLC_TIME = (100u),
      BATT12_V_INFO_CLC_TIME = (100u),
      BATT_LIMITS_CLC_TIME = (100u),
      DCDC48_V_INFO_CLC_TIME = (100u),
      DCDC12_V_INFO_CLC_TIME = (100u),
      BATT12_V_CELL4_PARAM_CLC_TIME = (100u),
      BATT12_V_CELL3_PARAM_CLC_TIME = (100u),
      BATT12_V_CELL2_PARAM_CLC_TIME = (100u),
      BATT12_V_CELL1_PARAM_CLC_TIME = (100u),
      BATT48_V_TEMPS_CLC_TIME = (500u),
      BATT12_V_TEMPS_CLC_TIME = (500u)
}Tx_Message_cycle_time;

/* Rx CLC Time. */


typedef enum
{
      ISG_INFO_CLC_TIME   =(10u),
      EMS_INFO1_CLC_TIME = (10u),
      VEHICLE_INFO_CLC_TIME = (20u)
}Rx_Message_cycle_time;

/* Extended or standard frame types.. */


typedef enum
{
      PMU_STATUS_IS_EXTENDED = 1,
      BATT48_V_CELL14_PARAM_IS_EXTENDED = 1,
      BATT48_V_CELL13_PARAM_IS_EXTENDED = 1,
      BATT48_V_CELL12_PARAM_IS_EXTENDED = 1,
      BATT48_V_CELL11_PARAM_IS_EXTENDED = 1,
      BATT48_V_CELL10_PARAM_IS_EXTENDED = 1,
      BATT48_V_CELL9_PARAM_IS_EXTENDED = 1,
      BATT48_V_CELL8_PARAM_IS_EXTENDED = 1,
      BATT48_V_CELL7_PARAM_IS_EXTENDED = 1,
      BATT48_V_CELL6_PARAM_IS_EXTENDED = 1,
      BATT48_V_CELL5_PARAM_IS_EXTENDED = 1,
      BATT48_V_CELL4_PARAM_IS_EXTENDED = 1,
      BATT48_V_CELL3_PARAM_IS_EXTENDED = 1,
      BATT48_V_CELL2_PARAM_IS_EXTENDED = 1,
      BATT48_V_CELL1_PARAM_IS_EXTENDED = 1,
      BATT48_V_INFO_IS_EXTENDED = 1,
      BATT12_V_INFO_IS_EXTENDED = 1,
      BATT_LIMITS_IS_EXTENDED = 1,
      DCDC48_V_INFO_IS_EXTENDED = 1,
      DCDC12_V_INFO_IS_EXTENDED = 1,
      BATT12_V_CELL4_PARAM_IS_EXTENDED = 1,
      BATT12_V_CELL3_PARAM_IS_EXTENDED = 1,
      BATT12_V_CELL2_PARAM_IS_EXTENDED = 1,
      BATT12_V_CELL1_PARAM_IS_EXTENDED = 1,
      BATT48_V_TEMPS_IS_EXTENDED = 1,
      BATT12_V_TEMPS_IS_EXTENDED = 1
}Tx_Msg_Identifier_Type;

typedef enum
{
      ISG_INFO_IS_EXTENDED = 1,
      EMS_INFO1_IS_EXTENDED = 1,
      VEHICLE_INFO_IS_EXTENDED = 1
}Rx_Msg_Identifier_Type;

/* Tx Methods. */


typedef enum
{
      PMU_STATUS_TX_METHOD = 0u,
      BATT48_V_CELL14_PARAM_TX_METHOD = 0u,
      BATT48_V_CELL13_PARAM_TX_METHOD = 0u,
      BATT48_V_CELL12_PARAM_TX_METHOD = 0u,
      BATT48_V_CELL11_PARAM_TX_METHOD = 0u,
      BATT48_V_CELL10_PARAM_TX_METHOD = 0u,
      BATT48_V_CELL9_PARAM_TX_METHOD = 0u,
      BATT48_V_CELL8_PARAM_TX_METHOD = 0u,
      BATT48_V_CELL7_PARAM_TX_METHOD = 0u,
      BATT48_V_CELL6_PARAM_TX_METHOD = 0u,
      BATT48_V_CELL5_PARAM_TX_METHOD = 0u,
      BATT48_V_CELL4_PARAM_TX_METHOD = 0u,
      BATT48_V_CELL3_PARAM_TX_METHOD = 0u,
      BATT48_V_CELL2_PARAM_TX_METHOD = 0u,
      BATT48_V_CELL1_PARAM_TX_METHOD = 0u,
      BATT48_V_INFO_TX_METHOD = 0u,
      BATT12_V_INFO_TX_METHOD = 0u,
      BATT_LIMITS_TX_METHOD = 0u,
      DCDC48_V_INFO_TX_METHOD = 0u,
      DCDC12_V_INFO_TX_METHOD = 0u,
      BATT12_V_CELL4_PARAM_TX_METHOD = 0u,
      BATT12_V_CELL3_PARAM_TX_METHOD = 0u,
      BATT12_V_CELL2_PARAM_TX_METHOD = 0u,
      BATT12_V_CELL1_PARAM_TX_METHOD = 0u,
      BATT48_V_TEMPS_TX_METHOD = 0u,
      BATT12_V_TEMPS_TX_METHOD = 0u
}Tx_Msg_Method;

/* Rx Methods. */


typedef enum
{
      ISG_INFO_RX_METHOD = 0u,
      EMS_INFO1_RX_METHOD = 0u,
      VEHICLE_INFO_RX_METHOD = 0u
}Rx_Msg_Method;


extern uint8_t Init_data_value[CANMGR_MAX_NO_OF_TX_MSGS][8];


typedef struct
{
   Tx_Msg_Method  frame_type;
  Tx_Message_cycle_time period;
  Tx_Mxg_Length  length;
  uint16_t counter;
}CanMgr_TxInfoTable_t;

typedef uint8_t(*CanMgr_Read)(float64* data);


typedef struct 
{
   uint8_t Message_Index;
  CanMgr_Read Message_funcptr;
}Rx_Dispatcher_t;

typedef void (*Rx_SignalIndication)(void);

typedef struct
{
  Rx_SignalIndication Rx_SignalIndication_cbkFuncPtr; 
}Rx_SignalIndication_t;


typedef struct 
{
  uint8_t  Message_Index;
  Rx_SignalIndication RxSignal_ReceptionTimeout_cbkFuncPtr;
  }ReceptionTimeout_t;


extern ReceptionTimeout_t Rx_ReceptionTimeoutCbk_Table[MAX_RX_SIGNALS];
extern Rx_SignalIndication_t RxCbk_SignalIndication_Table[MAX_RX_SIGNALS];
extern Rx_Dispatcher_t Rx_Dispatcher[MAX_RX_SIGNALS];



typedef struct
{
   Rx_Msg_Method frame_type;
   Rx_Mxg_Length length;
  uint16_t timeout;
  uint16_t timeout_counter;
}CanMgr_RxInfoTable_t;


extern CanMgr_TxInfoTable_t CanMgr_TxInfoTable[CANMGR_MAX_NO_OF_TX_MSGS];


extern CanMgr_RxInfoTable_t CanMgr_RxInfoTable[CANMGR_MAX_NO_OF_RX_MSGS];

void CanMgr_cfgInit(void);


/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt48_v_cell14_so_c(float64 data);
uint8_t CanMgr_Write_batt48_v_cell14_do_d(float64 data);
uint8_t CanMgr_Write_batt48_v_cell14_bal_status(float64 data);
uint8_t CanMgr_Write_batt48_v_cell14_so_h_cap(float64 data);
uint8_t CanMgr_Write_batt48_v_cell14_so_h_res(float64 data);
uint8_t CanMgr_Write_batt48_v_cell14_imbal(float64 data);
uint8_t CanMgr_Write_batt48_v_cell14_volt(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt48_v_cell14_so_c_cbk(void);
uint8_t CanMgr_batt48_v_cell14_do_d_cbk(void);
uint8_t CanMgr_batt48_v_cell14_bal_status_cbk(void);
uint8_t CanMgr_batt48_v_cell14_so_h_cap_cbk(void);
uint8_t CanMgr_batt48_v_cell14_so_h_res_cbk(void);
uint8_t CanMgr_batt48_v_cell14_imbal_cbk(void);
uint8_t CanMgr_batt48_v_cell14_volt_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt48_v_cell13_so_c(float64 data);
uint8_t CanMgr_Write_batt48_v_cell13_do_d(float64 data);
uint8_t CanMgr_Write_batt48_v_cell13_bal_status(float64 data);
uint8_t CanMgr_Write_batt48_v_cell13_so_h_cap(float64 data);
uint8_t CanMgr_Write_batt48_v_cell13_so_h_res(float64 data);
uint8_t CanMgr_Write_batt48_v_cell13_imbal(float64 data);
uint8_t CanMgr_Write_batt48_v_cell13_volt(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt48_v_cell13_so_c_cbk(void);
uint8_t CanMgr_batt48_v_cell13_do_d_cbk(void);
uint8_t CanMgr_batt48_v_cell13_bal_status_cbk(void);
uint8_t CanMgr_batt48_v_cell13_so_h_cap_cbk(void);
uint8_t CanMgr_batt48_v_cell13_so_h_res_cbk(void);
uint8_t CanMgr_batt48_v_cell13_imbal_cbk(void);
uint8_t CanMgr_batt48_v_cell13_volt_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt48_v_cell12_so_c(float64 data);
uint8_t CanMgr_Write_batt48_v_cell12_do_d(float64 data);
uint8_t CanMgr_Write_batt48_v_cell12_bal_status(float64 data);
uint8_t CanMgr_Write_batt48_v_cell12_so_h_cap(float64 data);
uint8_t CanMgr_Write_batt48_v_cell12_so_h_res(float64 data);
uint8_t CanMgr_Write_batt48_v_cell12_imbal(float64 data);
uint8_t CanMgr_Write_batt48_v_cell12_volt(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt48_v_cell12_so_c_cbk(void);
uint8_t CanMgr_batt48_v_cell12_do_d_cbk(void);
uint8_t CanMgr_batt48_v_cell12_bal_status_cbk(void);
uint8_t CanMgr_batt48_v_cell12_so_h_cap_cbk(void);
uint8_t CanMgr_batt48_v_cell12_so_h_res_cbk(void);
uint8_t CanMgr_batt48_v_cell12_imbal_cbk(void);
uint8_t CanMgr_batt48_v_cell12_volt_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt48_v_cell11_so_c(float64 data);
uint8_t CanMgr_Write_batt48_v_cell11_do_d(float64 data);
uint8_t CanMgr_Write_batt48_v_cell11_bal_status(float64 data);
uint8_t CanMgr_Write_batt48_v_cell11_so_h_cap(float64 data);
uint8_t CanMgr_Write_batt48_v_cell11_so_h_res(float64 data);
uint8_t CanMgr_Write_batt48_v_cell11_imbal(float64 data);
uint8_t CanMgr_Write_batt48_v_cell11_volt(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt48_v_cell11_so_c_cbk(void);
uint8_t CanMgr_batt48_v_cell11_do_d_cbk(void);
uint8_t CanMgr_batt48_v_cell11_bal_status_cbk(void);
uint8_t CanMgr_batt48_v_cell11_so_h_cap_cbk(void);
uint8_t CanMgr_batt48_v_cell11_so_h_res_cbk(void);
uint8_t CanMgr_batt48_v_cell11_imbal_cbk(void);
uint8_t CanMgr_batt48_v_cell11_volt_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt48_v_cell10_so_c(float64 data);
uint8_t CanMgr_Write_batt48_v_cell10_do_d(float64 data);
uint8_t CanMgr_Write_batt48_v_cell10_bal_status(float64 data);
uint8_t CanMgr_Write_batt48_v_cell10_so_h_cap(float64 data);
uint8_t CanMgr_Write_batt48_v_cell10_so_h_res(float64 data);
uint8_t CanMgr_Write_batt48_v_cell10_imbal(float64 data);
uint8_t CanMgr_Write_batt48_v_cell10_volt(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt48_v_cell10_so_c_cbk(void);
uint8_t CanMgr_batt48_v_cell10_do_d_cbk(void);
uint8_t CanMgr_batt48_v_cell10_bal_status_cbk(void);
uint8_t CanMgr_batt48_v_cell10_so_h_cap_cbk(void);
uint8_t CanMgr_batt48_v_cell10_so_h_res_cbk(void);
uint8_t CanMgr_batt48_v_cell10_imbal_cbk(void);
uint8_t CanMgr_batt48_v_cell10_volt_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt48_v_cell9_so_c(float64 data);
uint8_t CanMgr_Write_batt48_v_cell9_do_d(float64 data);
uint8_t CanMgr_Write_batt48_v_cell9_bal_status(float64 data);
uint8_t CanMgr_Write_batt48_v_cell9_so_h_cap(float64 data);
uint8_t CanMgr_Write_batt48_v_cell9_so_h_res(float64 data);
uint8_t CanMgr_Write_batt48_v_cell9_imbal(float64 data);
uint8_t CanMgr_Write_batt48_v_cell9_volt(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt48_v_cell9_so_c_cbk(void);
uint8_t CanMgr_batt48_v_cell9_do_d_cbk(void);
uint8_t CanMgr_batt48_v_cell9_bal_status_cbk(void);
uint8_t CanMgr_batt48_v_cell9_so_h_cap_cbk(void);
uint8_t CanMgr_batt48_v_cell9_so_h_res_cbk(void);
uint8_t CanMgr_batt48_v_cell9_imbal_cbk(void);
uint8_t CanMgr_batt48_v_cell9_volt_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt48_v_cell8_so_c(float64 data);
uint8_t CanMgr_Write_batt48_v_cell8_do_d(float64 data);
uint8_t CanMgr_Write_batt48_v_cell8_bal_status(float64 data);
uint8_t CanMgr_Write_batt48_v_cell8_so_h_cap(float64 data);
uint8_t CanMgr_Write_batt48_v_cell8_so_h_res(float64 data);
uint8_t CanMgr_Write_batt48_v_cell8_imbal(float64 data);
uint8_t CanMgr_Write_batt48_v_cell8_volt(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt48_v_cell8_so_c_cbk(void);
uint8_t CanMgr_batt48_v_cell8_do_d_cbk(void);
uint8_t CanMgr_batt48_v_cell8_bal_status_cbk(void);
uint8_t CanMgr_batt48_v_cell8_so_h_cap_cbk(void);
uint8_t CanMgr_batt48_v_cell8_so_h_res_cbk(void);
uint8_t CanMgr_batt48_v_cell8_imbal_cbk(void);
uint8_t CanMgr_batt48_v_cell8_volt_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt48_v_cell7_so_c(float64 data);
uint8_t CanMgr_Write_batt48_v_cell7_do_d(float64 data);
uint8_t CanMgr_Write_batt48_v_cell7_bal_status(float64 data);
uint8_t CanMgr_Write_batt48_v_cell7_so_h_cap(float64 data);
uint8_t CanMgr_Write_batt48_v_cell7_so_h_res(float64 data);
uint8_t CanMgr_Write_batt48_v_cell7_imbal(float64 data);
uint8_t CanMgr_Write_batt48_v_cell7_volt(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt48_v_cell7_so_c_cbk(void);
uint8_t CanMgr_batt48_v_cell7_do_d_cbk(void);
uint8_t CanMgr_batt48_v_cell7_bal_status_cbk(void);
uint8_t CanMgr_batt48_v_cell7_so_h_cap_cbk(void);
uint8_t CanMgr_batt48_v_cell7_so_h_res_cbk(void);
uint8_t CanMgr_batt48_v_cell7_imbal_cbk(void);
uint8_t CanMgr_batt48_v_cell7_volt_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt48_v_cell6_so_c(float64 data);
uint8_t CanMgr_Write_batt48_v_cell6_do_d(float64 data);
uint8_t CanMgr_Write_batt48_v_cell6_bal_status(float64 data);
uint8_t CanMgr_Write_batt48_v_cell6_so_h_cap(float64 data);
uint8_t CanMgr_Write_batt48_v_cell6_so_h_res(float64 data);
uint8_t CanMgr_Write_batt48_v_cell6_imbal(float64 data);
uint8_t CanMgr_Write_batt48_v_cell6_volt(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt48_v_cell6_so_c_cbk(void);
uint8_t CanMgr_batt48_v_cell6_do_d_cbk(void);
uint8_t CanMgr_batt48_v_cell6_bal_status_cbk(void);
uint8_t CanMgr_batt48_v_cell6_so_h_cap_cbk(void);
uint8_t CanMgr_batt48_v_cell6_so_h_res_cbk(void);
uint8_t CanMgr_batt48_v_cell6_imbal_cbk(void);
uint8_t CanMgr_batt48_v_cell6_volt_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt48_v_cell5_so_c(float64 data);
uint8_t CanMgr_Write_batt48_v_cell5_do_d(float64 data);
uint8_t CanMgr_Write_batt48_v_cell5_bal_status(float64 data);
uint8_t CanMgr_Write_batt48_v_cell5_so_h_cap(float64 data);
uint8_t CanMgr_Write_batt48_v_cell5_so_h_res(float64 data);
uint8_t CanMgr_Write_batt48_v_cell5_imbal(float64 data);
uint8_t CanMgr_Write_batt48_v_cell5_volt(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt48_v_cell5_so_c_cbk(void);
uint8_t CanMgr_batt48_v_cell5_do_d_cbk(void);
uint8_t CanMgr_batt48_v_cell5_bal_status_cbk(void);
uint8_t CanMgr_batt48_v_cell5_so_h_cap_cbk(void);
uint8_t CanMgr_batt48_v_cell5_so_h_res_cbk(void);
uint8_t CanMgr_batt48_v_cell5_imbal_cbk(void);
uint8_t CanMgr_batt48_v_cell5_volt_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt48_v_cell4_so_c(float64 data);
uint8_t CanMgr_Write_batt48_v_cell4_do_d(float64 data);
uint8_t CanMgr_Write_batt48_v_cell4_bal_status(float64 data);
uint8_t CanMgr_Write_batt48_v_cell4_so_h_cap(float64 data);
uint8_t CanMgr_Write_batt48_v_cell4_so_h_res(float64 data);
uint8_t CanMgr_Write_batt48_v_cell4_imbal(float64 data);
uint8_t CanMgr_Write_batt48_v_cell4_volt(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt48_v_cell4_so_c_cbk(void);
uint8_t CanMgr_batt48_v_cell4_do_d_cbk(void);
uint8_t CanMgr_batt48_v_cell4_bal_status_cbk(void);
uint8_t CanMgr_batt48_v_cell4_so_h_cap_cbk(void);
uint8_t CanMgr_batt48_v_cell4_so_h_res_cbk(void);
uint8_t CanMgr_batt48_v_cell4_imbal_cbk(void);
uint8_t CanMgr_batt48_v_cell4_volt_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt48_v_cell13_so_c(float64 data);
uint8_t CanMgr_Write_batt48_v_cell13_do_d(float64 data);
uint8_t CanMgr_Write_batt48_v_cell13_bal_status(float64 data);
uint8_t CanMgr_Write_batt48_v_cell13_so_h_cap(float64 data);
uint8_t CanMgr_Write_batt48_v_cell13_so_h_res(float64 data);
uint8_t CanMgr_Write_batt48_v_cell13_imbal(float64 data);
uint8_t CanMgr_Write_batt48_v_cell13_volt(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt48_v_cell13_so_c_cbk(void);
uint8_t CanMgr_batt48_v_cell13_do_d_cbk(void);
uint8_t CanMgr_batt48_v_cell13_bal_status_cbk(void);
uint8_t CanMgr_batt48_v_cell13_so_h_cap_cbk(void);
uint8_t CanMgr_batt48_v_cell13_so_h_res_cbk(void);
uint8_t CanMgr_batt48_v_cell13_imbal_cbk(void);
uint8_t CanMgr_batt48_v_cell13_volt_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt48_v_cell2_so_c(float64 data);
uint8_t CanMgr_Write_batt48_v_cell2_do_d(float64 data);
uint8_t CanMgr_Write_batt48_v_cell2_bal_status(float64 data);
uint8_t CanMgr_Write_batt48_v_cell2_so_h_cap(float64 data);
uint8_t CanMgr_Write_batt48_v_cell2_so_h_res(float64 data);
uint8_t CanMgr_Write_batt48_v_cell2_imbal(float64 data);
uint8_t CanMgr_Write_batt48_v_cell2_volt(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt48_v_cell2_so_c_cbk(void);
uint8_t CanMgr_batt48_v_cell2_do_d_cbk(void);
uint8_t CanMgr_batt48_v_cell2_bal_status_cbk(void);
uint8_t CanMgr_batt48_v_cell2_so_h_cap_cbk(void);
uint8_t CanMgr_batt48_v_cell2_so_h_res_cbk(void);
uint8_t CanMgr_batt48_v_cell2_imbal_cbk(void);
uint8_t CanMgr_batt48_v_cell2_volt_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt48_v_cell1_so_c(float64 data);
uint8_t CanMgr_Write_batt48_v_cell1_do_d(float64 data);
uint8_t CanMgr_Write_batt48_v_cell1_bal_status(float64 data);
uint8_t CanMgr_Write_batt48_v_cell1_so_h_cap(float64 data);
uint8_t CanMgr_Write_batt48_v_cell1_so_h_res(float64 data);
uint8_t CanMgr_Write_batt48_v_cell1_imbal(float64 data);
uint8_t CanMgr_Write_batt48_v_cell1_volt(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt48_v_cell1_so_c_cbk(void);
uint8_t CanMgr_batt48_v_cell1_do_d_cbk(void);
uint8_t CanMgr_batt48_v_cell1_bal_status_cbk(void);
uint8_t CanMgr_batt48_v_cell1_so_h_cap_cbk(void);
uint8_t CanMgr_batt48_v_cell1_so_h_res_cbk(void);
uint8_t CanMgr_batt48_v_cell1_imbal_cbk(void);
uint8_t CanMgr_batt48_v_cell1_volt_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt48_v_curr_meas(float64 data);
uint8_t CanMgr_Write_batt48_v_temp_avrg(float64 data);
uint8_t CanMgr_Write_batt48_v_temp_max(float64 data);
uint8_t CanMgr_Write_batt48_v_temp_min(float64 data);
uint8_t CanMgr_Write_batt48_v_estimated(float64 data);
uint8_t CanMgr_Write_batt48_v_so_c(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt48_v_curr_meas_cbk(void);
uint8_t CanMgr_batt48_v_temp_avrg_cbk(void);
uint8_t CanMgr_batt48_v_temp_max_cbk(void);
uint8_t CanMgr_batt48_v_temp_min_cbk(void);
uint8_t CanMgr_batt48_v_estimated_cbk(void);
uint8_t CanMgr_batt48_v_so_c_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt12_v_curr_meas(float64 data);
uint8_t CanMgr_Write_batt12_v_temp_avrg(float64 data);
uint8_t CanMgr_Write_batt12_v_temp_max(float64 data);
uint8_t CanMgr_Write_batt12_v_estimated(float64 data);
uint8_t CanMgr_Write_batt12_v_so_c(float64 data);
uint8_t CanMgr_Write_batt12_v_temp_min(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt12_v_curr_meas_cbk(void);
uint8_t CanMgr_batt12_v_temp_avrg_cbk(void);
uint8_t CanMgr_batt12_v_temp_max_cbk(void);
uint8_t CanMgr_batt12_v_estimated_cbk(void);
uint8_t CanMgr_batt12_v_so_c_cbk(void);
uint8_t CanMgr_batt12_v_temp_min_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_pmu_shutdown_ok(float64 data);
uint8_t CanMgr_Write_isg_volt_setpoint(float64 data);
uint8_t CanMgr_Write_pmu_crank_inhibit(float64 data);
uint8_t CanMgr_Write_isg_volt_max(float64 data);
uint8_t CanMgr_Write_isg_volt_min(float64 data);
uint8_t CanMgr_Write_pmu_state(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_pmu_shutdown_ok_cbk(void);
uint8_t CanMgr_isg_volt_setpoint_cbk(void);
uint8_t CanMgr_pmu_crank_inhibit_cbk(void);
uint8_t CanMgr_isg_volt_max_cbk(void);
uint8_t CanMgr_isg_volt_min_cbk(void);
uint8_t CanMgr_pmu_state_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt48_v_temp_meas1(float64 data);
uint8_t CanMgr_Write_batt48_v_temp_meas2(float64 data);
uint8_t CanMgr_Write_batt48_v_temp_meas3(float64 data);
uint8_t CanMgr_Write_batt48_v_temp_meas4(float64 data);
uint8_t CanMgr_Write_batt48_v_temp_meas5(float64 data);
uint8_t CanMgr_Write_batt48_v_temp_meas6(float64 data);
uint8_t CanMgr_Write_batt48_v_temp_meas7(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt48_v_temp_meas1_cbk(void);
uint8_t CanMgr_batt48_v_temp_meas2_cbk(void);
uint8_t CanMgr_batt48_v_temp_meas3_cbk(void);
uint8_t CanMgr_batt48_v_temp_meas4_cbk(void);
uint8_t CanMgr_batt48_v_temp_meas5_cbk(void);
uint8_t CanMgr_batt48_v_temp_meas6_cbk(void);
uint8_t CanMgr_batt48_v_temp_meas7_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt12_v_max(float64 data);
uint8_t CanMgr_Write_batt12_v_max_chrg_curr(float64 data);
uint8_t CanMgr_Write_batt12_v_max_dischrg_curr(float64 data);
uint8_t CanMgr_Write_batt12_v_min(float64 data);
uint8_t CanMgr_Write_batt48_v_max_chrg_curr(float64 data);
uint8_t CanMgr_Write_batt48_v_max_dischrg_curr(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt12_v_max_cbk(void);
uint8_t CanMgr_batt12_v_max_chrg_curr_cbk(void);
uint8_t CanMgr_batt12_v_max_dischrg_curr_cbk(void);
uint8_t CanMgr_batt12_v_min_cbk(void);
uint8_t CanMgr_batt48_v_max_chrg_curr_cbk(void);
uint8_t CanMgr_batt48_v_max_dischrg_curr_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_dcdc48_v_curr_meas(float64 data);
uint8_t CanMgr_Write_dcdc48_v_switch_req(float64 data);
uint8_t CanMgr_Write_dcdc48_v_switch_status(float64 data);
uint8_t CanMgr_Write_batt48_v_cont_status(float64 data);
uint8_t CanMgr_Write_dcdc48_volt_meas(float64 data);
uint8_t CanMgr_Write_dcdc48_volt_setpoint(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_dcdc48_v_curr_meas_cbk(void);
uint8_t CanMgr_dcdc48_v_switch_req_cbk(void);
uint8_t CanMgr_dcdc48_v_switch_status_cbk(void);
uint8_t CanMgr_batt48_v_cont_status_cbk(void);
uint8_t CanMgr_dcdc48_volt_meas_cbk(void);
uint8_t CanMgr_dcdc48_volt_setpoint_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_dcdc12_v_curr_meas(float64 data);
uint8_t CanMgr_Write_dcdc_status(float64 data);
uint8_t CanMgr_Write_dcdc12_v_switch_status(float64 data);
uint8_t CanMgr_Write_dcdc12_volt_meas(float64 data);
uint8_t CanMgr_Write_dcdc12_volt_setpoint(float64 data);
uint8_t CanMgr_Write_batt12_v_cont_status(float64 data);
uint8_t CanMgr_Write_dcdc12_v_switch_req(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_dcdc12_v_curr_meas_cbk(void);
uint8_t CanMgr_dcdc_status_cbk(void);
uint8_t CanMgr_dcdc12_v_switch_status_cbk(void);
uint8_t CanMgr_dcdc12_volt_meas_cbk(void);
uint8_t CanMgr_dcdc12_volt_setpoint_cbk(void);
uint8_t CanMgr_batt12_v_cont_status_cbk(void);
uint8_t CanMgr_dcdc12_v_switch_req_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt12_v_cell4_so_c(float64 data);
uint8_t CanMgr_Write_batt12_v_cell4_do_d(float64 data);
uint8_t CanMgr_Write_batt12_v_cell4_bal_status(float64 data);
uint8_t CanMgr_Write_batt12_v_cell4_so_h_cap(float64 data);
uint8_t CanMgr_Write_batt12_v_cell4_so_h_res(float64 data);
uint8_t CanMgr_Write_batt12_v_cell4_imbal(float64 data);
uint8_t CanMgr_Write_batt12_v_cell4_volt(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt12_v_cell4_so_c_cbk(void);
uint8_t CanMgr_batt12_v_cell4_do_d_cbk(void);
uint8_t CanMgr_batt12_v_cell4_bal_status_cbk(void);
uint8_t CanMgr_batt12_v_cell4_so_h_cap_cbk(void);
uint8_t CanMgr_batt12_v_cell4_so_h_res_cbk(void);
uint8_t CanMgr_batt12_v_cell4_imbal_cbk(void);
uint8_t CanMgr_batt12_v_cell4_volt_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt12_v_cell3_so_c(float64 data);
uint8_t CanMgr_Write_batt12_v_cell3_do_d(float64 data);
uint8_t CanMgr_Write_batt12_v_cell3_bal_status(float64 data);
uint8_t CanMgr_Write_batt12_v_cell3_so_h_cap(float64 data);
uint8_t CanMgr_Write_batt12_v_cell3_so_h_res(float64 data);
uint8_t CanMgr_Write_batt12_v_cell3_imbal(float64 data);
uint8_t CanMgr_Write_batt12_v_cell3_volt(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt12_v_cell3_so_c_cbk(void);
uint8_t CanMgr_batt12_v_cell3_do_d_cbk(void);
uint8_t CanMgr_batt12_v_cell3_bal_status_cbk(void);
uint8_t CanMgr_batt12_v_cell3_so_h_cap_cbk(void);
uint8_t CanMgr_batt12_v_cell3_so_h_res_cbk(void);
uint8_t CanMgr_batt12_v_cell3_imbal_cbk(void);
uint8_t CanMgr_batt12_v_cell3_volt_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt12_v_cell2_so_c(float64 data);
uint8_t CanMgr_Write_batt12_v_cell2_do_d(float64 data);
uint8_t CanMgr_Write_batt12_v_cell2_bal_status(float64 data);
uint8_t CanMgr_Write_batt12_v_cell2_so_h_cap(float64 data);
uint8_t CanMgr_Write_batt12_v_cell2_so_h_res(float64 data);
uint8_t CanMgr_Write_batt12_v_cell2_imbal(float64 data);
uint8_t CanMgr_Write_batt12_v_cell2_volt(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt12_v_cell2_so_c_cbk(void);
uint8_t CanMgr_batt12_v_cell2_do_d_cbk(void);
uint8_t CanMgr_batt12_v_cell2_bal_status_cbk(void);
uint8_t CanMgr_batt12_v_cell2_so_h_cap_cbk(void);
uint8_t CanMgr_batt12_v_cell2_so_h_res_cbk(void);
uint8_t CanMgr_batt12_v_cell2_imbal_cbk(void);
uint8_t CanMgr_batt12_v_cell2_volt_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt12_v_temp_meas1(float64 data);
uint8_t CanMgr_Write_batt12_v_temp_meas2(float64 data);
uint8_t CanMgr_Write_batt12_v_temp_meas3(float64 data);
uint8_t CanMgr_Write_batt12_v_temp_meas4(float64 data);
uint8_t CanMgr_Write_batt12_v_temp_meas5(float64 data);
uint8_t CanMgr_Write_batt12_v_temp_meas6(float64 data);
uint8_t CanMgr_Write_batt12_v_temp_meas7(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt12_v_temp_meas1_cbk(void);
uint8_t CanMgr_batt12_v_temp_meas2_cbk(void);
uint8_t CanMgr_batt12_v_temp_meas3_cbk(void);
uint8_t CanMgr_batt12_v_temp_meas4_cbk(void);
uint8_t CanMgr_batt12_v_temp_meas5_cbk(void);
uint8_t CanMgr_batt12_v_temp_meas6_cbk(void);
uint8_t CanMgr_batt12_v_temp_meas7_cbk(void);



/* 
  * @Brief  : The following functions shall be used by the application to update signal to be transmitted
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 

uint8_t CanMgr_Write_batt12_v_cell1_so_c(float64 data);
uint8_t CanMgr_Write_batt12_v_cell1_do_d(float64 data);
uint8_t CanMgr_Write_batt12_v_cell1_bal_status(float64 data);
uint8_t CanMgr_Write_batt12_v_cell1_so_h_cap(float64 data);
uint8_t CanMgr_Write_batt12_v_cell1_so_h_res(float64 data);
uint8_t CanMgr_Write_batt12_v_cell1_imbal(float64 data);
uint8_t CanMgr_Write_batt12_v_cell1_volt(float64 data);

/* 
  * @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : NONE                                                                               
  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               
*/ 

uint8_t CanMgr_batt12_v_cell1_so_c_cbk(void);
uint8_t CanMgr_batt12_v_cell1_do_d_cbk(void);
uint8_t CanMgr_batt12_v_cell1_bal_status_cbk(void);
uint8_t CanMgr_batt12_v_cell1_so_h_cap_cbk(void);
uint8_t CanMgr_batt12_v_cell1_so_h_res_cbk(void);
uint8_t CanMgr_batt12_v_cell1_imbal_cbk(void);
uint8_t CanMgr_batt12_v_cell1_volt_cbk(void);





/* 
* @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : pointer to store the data                                                                                
  * @return : Reception status (MSG_RECEIVED / MSG_MISSING /MSG_NEVER_RECEIVED)                                                                               
*/ 

uint8_t CanMgr_Read_inertia_switch_state(float64* data);
uint8_t CanMgr_Read_ambient_temp(float64* data);
uint8_t CanMgr_Read_emergency_switch_state(float64* data);
uint8_t CanMgr_Read_brake_pedal_pos(float64* data);
uint8_t CanMgr_Read_drive_mode(float64* data);
uint8_t CanMgr_Read_engine_stop_requested(float64* data);
uint8_t CanMgr_Read_park_brake_state(float64* data);
uint8_t CanMgr_Read_vehicle_power_state(float64* data);
uint8_t CanMgr_Read_coolant_temp(float64* data);
uint8_t CanMgr_Read_reverse_switch_state(float64* data);
uint8_t CanMgr_Read_crank_requested(float64* data);
uint8_t CanMgr_Read_vehicle_shutdown_req(float64* data);

/* 
* @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : pointer to store the data                                                                                
  * @return : Reception status (MSG_RECEIVED / MSG_MISSING /MSG_NEVER_RECEIVED)                                                                               
*/ 

uint8_t CanMgr_Read_isg_torque_est(float64* data);
uint8_t CanMgr_Read_isg_state(float64* data);

/* 
* @Brief  : The following functions shall be used by the application to check transmission status
  * @param  : pointer to store the data                                                                                
  * @return : Reception status (MSG_RECEIVED / MSG_MISSING /MSG_NEVER_RECEIVED)                                                                               
*/ 

uint8_t CanMgr_Read_isg_torque_min_slew_rate(float64* data);
uint8_t CanMgr_Read_isg_min_torque(float64* data);
uint8_t CanMgr_Read_isg_speed_setpoint(float64* data);
uint8_t CanMgr_Read_engine_state(float64* data);
uint8_t CanMgr_Read_isg_torque_available(float64* data);
uint8_t CanMgr_Read_crank_cmd(float64* data);
uint8_t CanMgr_Read_isg_torque_max_slew_rate(float64* data);

   /**********************************************************************************************************************
  *                                                R E V I S I O N   H I S T O R Y             
* **********************************************************************************************************************/
             /**********************************************************************************************************************
                 REVISION NUMBER      : V1.0.0                                                                                   
               REVISION DATE        : 30/01/2020                                                                               
              CREATED / REVISED BY : Mahendran L (mahendranl@niyatainfotech.com)                                        
              DESCRIPTION          : Initial Version                                                                       
       ---------------------------------------------------------------------------------------------------------------------
       * **********************************************************************************************************************/
#endif /* CANMGR_CFG_H_ */
