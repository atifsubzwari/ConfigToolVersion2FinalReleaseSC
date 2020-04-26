/*
* CanMgr_cfg.c
*
*  Created on:25-4-2020
*      Author: DESKTOP-TGOOAVJ
*/

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

#include "CanMgr_cfg.h"
#include "CanMgr.h"


/***********************************************************************************************************************
 *                          M A C R O D E F I N I T I O N S
***********************************************************************************************************************/


#define EINVAL 22


/***********************************************************************************************************************
 *                          V A R I A B L E S D E F I N I  T I O N S
***********************************************************************************************************************/

/**
* Signals in message VehicleInfo.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t inertia_switch_state;
uint8_t ambient_temp;
uint8_t emergency_switch_state;
uint8_t brake_pedal_pos;
uint8_t drive_mode;
uint8_t engine_stop_requested;
uint8_t park_brake_state;
uint8_t vehicle_power_state;
uint8_t coolant_temp;
uint8_t reverse_switch_state;
uint8_t crank_requested;
uint8_t vehicle_shutdown_req;
}powertraincanv04_vehicle_info_t;

static powertraincanv04_vehicle_info_t   vehicle_info;

/**
* Signals in message ISGInfo.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint16_t isg_torque_est;
uint8_t isg_state;
}powertraincanv04_isg_info_t;

static powertraincanv04_isg_info_t   isg_info;

/**
* Signals in message EMSInfo1.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint16_t isg_torque_min_slew_rate;
uint8_t isg_min_torque;
uint16_t isg_speed_setpoint;
uint8_t engine_state;
uint8_t isg_torque_available;
uint8_t crank_cmd;
uint8_t isg_torque_max_slew_rate;
}powertraincanv04_ems_info1_t;

static powertraincanv04_ems_info1_t   ems_info1;

/**
* Signals in message Batt48VCell14Param.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t batt48_v_cell14_so_c;
uint8_t batt48_v_cell14_do_d;
uint8_t batt48_v_cell14_bal_status;
uint8_t batt48_v_cell14_so_h_cap;
uint8_t batt48_v_cell14_so_h_res;
uint8_t batt48_v_cell14_imbal;
uint16_t batt48_v_cell14_volt;
}powertraincanv04_batt48_v_cell14_param_t;

static powertraincanv04_batt48_v_cell14_param_t   batt48_v_cell14_param;

/**
* Signals in message Batt48VCell13Param.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t batt48_v_cell13_so_c;
uint8_t batt48_v_cell13_do_d;
uint8_t batt48_v_cell13_bal_status;
uint8_t batt48_v_cell13_so_h_cap;
uint8_t batt48_v_cell13_so_h_res;
uint8_t batt48_v_cell13_imbal;
uint16_t batt48_v_cell13_volt;
}powertraincanv04_batt48_v_cell13_param_t;

static powertraincanv04_batt48_v_cell13_param_t   batt48_v_cell13_param;

/**
* Signals in message Batt48VCell12Param.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t batt48_v_cell12_so_c;
uint8_t batt48_v_cell12_do_d;
uint8_t batt48_v_cell12_bal_status;
uint8_t batt48_v_cell12_so_h_cap;
uint8_t batt48_v_cell12_so_h_res;
uint8_t batt48_v_cell12_imbal;
uint16_t batt48_v_cell12_volt;
}powertraincanv04_batt48_v_cell12_param_t;

static powertraincanv04_batt48_v_cell12_param_t   batt48_v_cell12_param;

/**
* Signals in message Batt48VCell11Param.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t batt48_v_cell11_so_c;
uint8_t batt48_v_cell11_do_d;
uint8_t batt48_v_cell11_bal_status;
uint8_t batt48_v_cell11_so_h_cap;
uint8_t batt48_v_cell11_so_h_res;
uint8_t batt48_v_cell11_imbal;
uint16_t batt48_v_cell11_volt;
}powertraincanv04_batt48_v_cell11_param_t;

static powertraincanv04_batt48_v_cell11_param_t   batt48_v_cell11_param;

/**
* Signals in message Batt48VCell10Param.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t batt48_v_cell10_so_c;
uint8_t batt48_v_cell10_do_d;
uint8_t batt48_v_cell10_bal_status;
uint8_t batt48_v_cell10_so_h_cap;
uint8_t batt48_v_cell10_so_h_res;
uint8_t batt48_v_cell10_imbal;
uint16_t batt48_v_cell10_volt;
}powertraincanv04_batt48_v_cell10_param_t;

static powertraincanv04_batt48_v_cell10_param_t   batt48_v_cell10_param;

/**
* Signals in message Batt48VCell9Param.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t batt48_v_cell9_so_c;
uint8_t batt48_v_cell9_do_d;
uint8_t batt48_v_cell9_bal_status;
uint8_t batt48_v_cell9_so_h_cap;
uint8_t batt48_v_cell9_so_h_res;
uint8_t batt48_v_cell9_imbal;
uint16_t batt48_v_cell9_volt;
}powertraincanv04_batt48_v_cell9_param_t;

static powertraincanv04_batt48_v_cell9_param_t   batt48_v_cell9_param;

/**
* Signals in message Batt48VCell8Param.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t batt48_v_cell8_so_c;
uint8_t batt48_v_cell8_do_d;
uint8_t batt48_v_cell8_bal_status;
uint8_t batt48_v_cell8_so_h_cap;
uint8_t batt48_v_cell8_so_h_res;
uint8_t batt48_v_cell8_imbal;
uint16_t batt48_v_cell8_volt;
}powertraincanv04_batt48_v_cell8_param_t;

static powertraincanv04_batt48_v_cell8_param_t   batt48_v_cell8_param;

/**
* Signals in message Batt48VCell7Param.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t batt48_v_cell7_so_c;
uint8_t batt48_v_cell7_do_d;
uint8_t batt48_v_cell7_bal_status;
uint8_t batt48_v_cell7_so_h_cap;
uint8_t batt48_v_cell7_so_h_res;
uint8_t batt48_v_cell7_imbal;
uint16_t batt48_v_cell7_volt;
}powertraincanv04_batt48_v_cell7_param_t;

static powertraincanv04_batt48_v_cell7_param_t   batt48_v_cell7_param;

/**
* Signals in message Batt48VCell6Param.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t batt48_v_cell6_so_c;
uint8_t batt48_v_cell6_do_d;
uint8_t batt48_v_cell6_bal_status;
uint8_t batt48_v_cell6_so_h_cap;
uint8_t batt48_v_cell6_so_h_res;
uint8_t batt48_v_cell6_imbal;
uint16_t batt48_v_cell6_volt;
}powertraincanv04_batt48_v_cell6_param_t;

static powertraincanv04_batt48_v_cell6_param_t   batt48_v_cell6_param;

/**
* Signals in message Batt48VCell5Param.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t batt48_v_cell5_so_c;
uint8_t batt48_v_cell5_do_d;
uint8_t batt48_v_cell5_bal_status;
uint8_t batt48_v_cell5_so_h_cap;
uint8_t batt48_v_cell5_so_h_res;
uint8_t batt48_v_cell5_imbal;
uint16_t batt48_v_cell5_volt;
}powertraincanv04_batt48_v_cell5_param_t;

static powertraincanv04_batt48_v_cell5_param_t   batt48_v_cell5_param;

/**
* Signals in message Batt48VCell4Param.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t batt48_v_cell4_so_c;
uint8_t batt48_v_cell4_do_d;
uint8_t batt48_v_cell4_bal_status;
uint8_t batt48_v_cell4_so_h_cap;
uint8_t batt48_v_cell4_so_h_res;
uint8_t batt48_v_cell4_imbal;
uint16_t batt48_v_cell4_volt;
}powertraincanv04_batt48_v_cell4_param_t;

static powertraincanv04_batt48_v_cell4_param_t   batt48_v_cell4_param;

/**
* Signals in message Batt48VCell3Param.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t batt48_v_cell13_so_c;
uint8_t batt48_v_cell13_do_d;
uint8_t batt48_v_cell13_bal_status;
uint8_t batt48_v_cell13_so_h_cap;
uint8_t batt48_v_cell13_so_h_res;
uint8_t batt48_v_cell13_imbal;
uint16_t batt48_v_cell13_volt;
}powertraincanv04_batt48_v_cell3_param_t;

static powertraincanv04_batt48_v_cell3_param_t   batt48_v_cell3_param;

/**
* Signals in message Batt48VCell2Param.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t batt48_v_cell2_so_c;
uint8_t batt48_v_cell2_do_d;
uint8_t batt48_v_cell2_bal_status;
uint8_t batt48_v_cell2_so_h_cap;
uint8_t batt48_v_cell2_so_h_res;
uint8_t batt48_v_cell2_imbal;
uint16_t batt48_v_cell2_volt;
}powertraincanv04_batt48_v_cell2_param_t;

static powertraincanv04_batt48_v_cell2_param_t   batt48_v_cell2_param;

/**
* Signals in message Batt48VCell1Param.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t batt48_v_cell1_so_c;
uint8_t batt48_v_cell1_do_d;
uint8_t batt48_v_cell1_bal_status;
uint8_t batt48_v_cell1_so_h_cap;
uint8_t batt48_v_cell1_so_h_res;
uint8_t batt48_v_cell1_imbal;
uint16_t batt48_v_cell1_volt;
}powertraincanv04_batt48_v_cell1_param_t;

static powertraincanv04_batt48_v_cell1_param_t   batt48_v_cell1_param;

/**
* Signals in message Batt48VInfo.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint16_t batt48_v_curr_meas;
uint8_t batt48_v_temp_avrg;
uint8_t batt48_v_temp_max;
uint8_t batt48_v_temp_min;
uint16_t batt48_v_estimated;
uint8_t batt48_v_so_c;
}powertraincanv04_batt48_v_info_t;

static powertraincanv04_batt48_v_info_t   batt48_v_info;

/**
* Signals in message Batt12VInfo.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint16_t batt12_v_curr_meas;
uint8_t batt12_v_temp_avrg;
uint8_t batt12_v_temp_max;
uint16_t batt12_v_estimated;
uint8_t batt12_v_so_c;
uint8_t batt12_v_temp_min;
}powertraincanv04_batt12_v_info_t;

static powertraincanv04_batt12_v_info_t   batt12_v_info;

/**
* Signals in message PMUStatus.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t pmu_shutdown_ok;
uint8_t isg_volt_setpoint;
uint8_t pmu_crank_inhibit;
uint8_t isg_volt_max;
uint8_t isg_volt_min;
uint8_t pmu_state;
}powertraincanv04_pmu_status_t;

static powertraincanv04_pmu_status_t   pmu_status;

/**
* Signals in message Batt48VTemps.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t batt48_v_temp_meas1;
uint8_t batt48_v_temp_meas2;
uint8_t batt48_v_temp_meas3;
uint8_t batt48_v_temp_meas4;
uint8_t batt48_v_temp_meas5;
uint8_t batt48_v_temp_meas6;
uint8_t batt48_v_temp_meas7;
}powertraincanv04_batt48_v_temps_t;

static powertraincanv04_batt48_v_temps_t   batt48_v_temps;

/**
* Signals in message BattLimits.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t batt12_v_max;
uint8_t batt12_v_max_chrg_curr;
uint8_t batt12_v_max_dischrg_curr;
uint8_t batt12_v_min;
uint8_t batt48_v_max_chrg_curr;
uint16_t batt48_v_max_dischrg_curr;
}powertraincanv04_batt_limits_t;

static powertraincanv04_batt_limits_t   batt_limits;

/**
* Signals in message DCDC48VInfo.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint16_t dcdc48_v_curr_meas;
uint8_t dcdc48_v_switch_req;
uint8_t dcdc48_v_switch_status;
uint8_t batt48_v_cont_status;
uint16_t dcdc48_volt_meas;
uint8_t dcdc48_volt_setpoint;
}powertraincanv04_dcdc48_v_info_t;

static powertraincanv04_dcdc48_v_info_t   dcdc48_v_info;

/**
* Signals in message DCDC12VInfo.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint16_t dcdc12_v_curr_meas;
uint8_t dcdc_status;
uint8_t dcdc12_v_switch_status;
uint16_t dcdc12_volt_meas;
uint8_t dcdc12_volt_setpoint;
uint8_t batt12_v_cont_status;
uint8_t dcdc12_v_switch_req;
}powertraincanv04_dcdc12_v_info_t;

static powertraincanv04_dcdc12_v_info_t   dcdc12_v_info;

/**
* Signals in message Batt12VCell4Param.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t batt12_v_cell4_so_c;
uint8_t batt12_v_cell4_do_d;
uint8_t batt12_v_cell4_bal_status;
uint8_t batt12_v_cell4_so_h_cap;
uint8_t batt12_v_cell4_so_h_res;
uint8_t batt12_v_cell4_imbal;
uint16_t batt12_v_cell4_volt;
}powertraincanv04_batt12_v_cell4_param_t;

static powertraincanv04_batt12_v_cell4_param_t   batt12_v_cell4_param;

/**
* Signals in message Batt12VCell3Param.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t batt12_v_cell3_so_c;
uint8_t batt12_v_cell3_do_d;
uint8_t batt12_v_cell3_bal_status;
uint8_t batt12_v_cell3_so_h_cap;
uint8_t batt12_v_cell3_so_h_res;
uint8_t batt12_v_cell3_imbal;
uint16_t batt12_v_cell3_volt;
}powertraincanv04_batt12_v_cell3_param_t;

static powertraincanv04_batt12_v_cell3_param_t   batt12_v_cell3_param;

/**
* Signals in message Batt12VCell2Param.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t batt12_v_cell2_so_c;
uint8_t batt12_v_cell2_do_d;
uint8_t batt12_v_cell2_bal_status;
uint8_t batt12_v_cell2_so_h_cap;
uint8_t batt12_v_cell2_so_h_res;
uint8_t batt12_v_cell2_imbal;
uint16_t batt12_v_cell2_volt;
}powertraincanv04_batt12_v_cell2_param_t;

static powertraincanv04_batt12_v_cell2_param_t   batt12_v_cell2_param;

/**
* Signals in message Batt12VTemps.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t batt12_v_temp_meas1;
uint8_t batt12_v_temp_meas2;
uint8_t batt12_v_temp_meas3;
uint8_t batt12_v_temp_meas4;
uint8_t batt12_v_temp_meas5;
uint8_t batt12_v_temp_meas6;
uint8_t batt12_v_temp_meas7;
}powertraincanv04_batt12_v_temps_t;

static powertraincanv04_batt12_v_temps_t   batt12_v_temps;

/**
* Signals in message Batt12VCell1Param.
*
* All signal values are as on the CAN bus.
*/


typedef struct {
uint8_t batt12_v_cell1_so_c;
uint8_t batt12_v_cell1_do_d;
uint8_t batt12_v_cell1_bal_status;
uint8_t batt12_v_cell1_so_h_cap;
uint8_t batt12_v_cell1_so_h_res;
uint8_t batt12_v_cell1_imbal;
uint16_t batt12_v_cell1_volt;
}powertraincanv04_batt12_v_cell1_param_t;

static powertraincanv04_batt12_v_cell1_param_t   batt12_v_cell1_param;







static const powertraincanv04_batt48_v_cell14_param_t default_batt48_v_cell14_param ={0,0,0,65,90,0,2};
static const powertraincanv04_batt48_v_cell13_param_t default_batt48_v_cell13_param ={0,0,0,65,90,0,2};
static const powertraincanv04_batt48_v_cell12_param_t default_batt48_v_cell12_param ={0,0,0,65,90,0,2};
static const powertraincanv04_batt48_v_cell11_param_t default_batt48_v_cell11_param ={0,0,0,65,90,0,2};
static const powertraincanv04_batt48_v_cell10_param_t default_batt48_v_cell10_param ={0,0,0,65,90,0,2};
static const powertraincanv04_batt48_v_cell9_param_t default_batt48_v_cell9_param ={0,0,0,65,90,0,2};
static const powertraincanv04_batt48_v_cell8_param_t default_batt48_v_cell8_param ={0,0,0,65,90,0,2};
static const powertraincanv04_batt48_v_cell7_param_t default_batt48_v_cell7_param ={0,0,0,65,90,0,2};
static const powertraincanv04_batt48_v_cell6_param_t default_batt48_v_cell6_param ={0,0,0,65,90,0,2};
static const powertraincanv04_batt48_v_cell5_param_t default_batt48_v_cell5_param ={0,0,0,65,90,0,2};
static const powertraincanv04_batt48_v_cell4_param_t default_batt48_v_cell4_param ={0,0,0,65,90,0,2};
static const powertraincanv04_batt48_v_cell3_param_t default_batt48_v_cell3_param ={0,0,0,65,90,0,2};
static const powertraincanv04_batt48_v_cell2_param_t default_batt48_v_cell2_param ={0,0,0,65,90,0,2};
static const powertraincanv04_batt48_v_cell1_param_t default_batt48_v_cell1_param ={0,0,0,65,90,0,2};
static const powertraincanv04_batt48_v_info_t default_batt48_v_info ={0,-40,-40,-40,22,0};
static const powertraincanv04_batt12_v_info_t default_batt12_v_info ={0,-40,-40,6,0,-40};
static const powertraincanv04_pmu_status_t default_pmu_status ={0,40,0,40,28,0};
static const powertraincanv04_batt48_v_temps_t default_batt48_v_temps ={-40,-40,-40,-40,-40,-40,-40};
static const powertraincanv04_batt_limits_t default_batt_limits ={6,0,0,6,0,0};
static const powertraincanv04_dcdc48_v_info_t default_dcdc48_v_info ={0,0,0,0,22,40};
static const powertraincanv04_dcdc12_v_info_t default_dcdc12_v_info ={0,0,0,6,8,0,0};
static const powertraincanv04_batt12_v_cell4_param_t default_batt12_v_cell4_param ={0,0,0,65,90,0,2};
static const powertraincanv04_batt12_v_cell3_param_t default_batt12_v_cell3_param ={0,0,0,65,90,0,2};
static const powertraincanv04_batt12_v_cell2_param_t default_batt12_v_cell2_param ={0,0,0,65,90,0,2};
static const powertraincanv04_batt12_v_temps_t default_batt12_v_temps ={-40,-40,-40,-40,-40,-40,-40};
static const powertraincanv04_batt12_v_cell1_param_t default_batt12_v_cell1_param ={0,0,0,65,90,0,2};


uint8_t Init_data_value[CANMGR_MAX_NO_OF_TX_MSGS][8];


Rx_Dispatcher_t Rx_Dispatcher[MAX_RX_SIGNALS] = {
       {0,&CanMgr_Read_isg_torque_est},
       {0,&CanMgr_Read_isg_state},
       {1,&CanMgr_Read_isg_torque_min_slew_rate},
       {1,&CanMgr_Read_isg_min_torque},
       {1,&CanMgr_Read_isg_speed_setpoint},
       {1,&CanMgr_Read_engine_state},
       {1,&CanMgr_Read_isg_torque_available},
       {1,&CanMgr_Read_crank_cmd},
       {1,&CanMgr_Read_isg_torque_max_slew_rate},
       {2,&CanMgr_Read_inertia_switch_state},
       {2,&CanMgr_Read_ambient_temp},
       {2,&CanMgr_Read_emergency_switch_state},
       {2,&CanMgr_Read_brake_pedal_pos},
       {2,&CanMgr_Read_drive_mode},
       {2,&CanMgr_Read_engine_stop_requested},
       {2,&CanMgr_Read_park_brake_state},
       {2,&CanMgr_Read_vehicle_power_state},
       {2,&CanMgr_Read_coolant_temp},
       {2,&CanMgr_Read_reverse_switch_state},
       {2,&CanMgr_Read_crank_requested},
       {2,&CanMgr_Read_vehicle_shutdown_req}
};



Rx_SignalIndication_t RxCbk_SignalIndication_Table[MAX_RX_SIGNALS] ={
       { CANMGR_ISG_TORQUE_EST_RXCBK },
       { CANMGR_ISG_STATE_RXCBK },
       { CANMGR_ISG_TORQUE_MIN_SLEW_RATE_RXCBK },
       { CANMGR_ISG_MIN_TORQUE_RXCBK },
       { CANMGR_ISG_SPEED_SETPOINT_RXCBK },
       { CANMGR_ENGINE_STATE_RXCBK },
       { CANMGR_ISG_TORQUE_AVAILABLE_RXCBK },
       { CANMGR_CRANK_CMD_RXCBK },
       { CANMGR_ISG_TORQUE_MAX_SLEW_RATE_RXCBK },
       { CANMGR_INERTIA_SWITCH_STATE_RXCBK },
       { CANMGR_AMBIENT_TEMP_RXCBK },
       { CANMGR_EMERGENCY_SWITCH_STATE_RXCBK },
       { CANMGR_BRAKE_PEDAL_POS_RXCBK },
       { CANMGR_DRIVE_MODE_RXCBK },
       { CANMGR_ENGINE_STOP_REQUESTED_RXCBK },
       { CANMGR_PARK_BRAKE_STATE_RXCBK },
       { CANMGR_VEHICLE_POWER_STATE_RXCBK },
       { CANMGR_COOLANT_TEMP_RXCBK },
       { CANMGR_REVERSE_SWITCH_STATE_RXCBK },
       { CANMGR_CRANK_REQUESTED_RXCBK },
       { CANMGR_VEHICLE_SHUTDOWN_REQ_RXCBK }
};


ReceptionTimeout_t Rx_ReceptionTimeoutCbk_Table[MAX_RX_SIGNALS]={
       {0,CANMGR_ISG_TORQUE_EST_TIMEOUT_CBK},
       {0,CANMGR_ISG_STATE_TIMEOUT_CBK},
       {1,CANMGR_ISG_TORQUE_MIN_SLEW_RATE_TIMEOUT_CBK},
       {1,CANMGR_ISG_MIN_TORQUE_TIMEOUT_CBK},
       {1,CANMGR_ISG_SPEED_SETPOINT_TIMEOUT_CBK},
       {1,CANMGR_ENGINE_STATE_TIMEOUT_CBK},
       {1,CANMGR_ISG_TORQUE_AVAILABLE_TIMEOUT_CBK},
       {1,CANMGR_CRANK_CMD_TIMEOUT_CBK},
       {1,CANMGR_ISG_TORQUE_MAX_SLEW_RATE_TIMEOUT_CBK},
       {2,CANMGR_INERTIA_SWITCH_STATE_TIMEOUT_CBK},
       {2,CANMGR_AMBIENT_TEMP_TIMEOUT_CBK},
       {2,CANMGR_EMERGENCY_SWITCH_STATE_TIMEOUT_CBK},
       {2,CANMGR_BRAKE_PEDAL_POS_TIMEOUT_CBK},
       {2,CANMGR_DRIVE_MODE_TIMEOUT_CBK},
       {2,CANMGR_ENGINE_STOP_REQUESTED_TIMEOUT_CBK},
       {2,CANMGR_PARK_BRAKE_STATE_TIMEOUT_CBK},
       {2,CANMGR_VEHICLE_POWER_STATE_TIMEOUT_CBK},
       {2,CANMGR_COOLANT_TEMP_TIMEOUT_CBK},
       {2,CANMGR_REVERSE_SWITCH_STATE_TIMEOUT_CBK},
       {2,CANMGR_CRANK_REQUESTED_TIMEOUT_CBK},
       {2,CANMGR_VEHICLE_SHUTDOWN_REQ_TIMEOUT_CBK}
};



CanMgr_TxInfoTable_t CanMgr_TxInfoTable[CANMGR_MAX_NO_OF_TX_MSGS] = {
      {
          PMU_STATUS_TX_METHOD , 
          PMU_STATUS_CLC_TIME,
          PMU_STATUS_LENGTH,
          0
      }
      ,
      {
          BATT48_V_CELL14_PARAM_TX_METHOD , 
          BATT48_V_CELL14_PARAM_CLC_TIME,
          BATT48_V_CELL14_PARAM_LENGTH,
          0
          }
      ,
      {
          BATT48_V_CELL13_PARAM_TX_METHOD , 
          BATT48_V_CELL13_PARAM_CLC_TIME,
          BATT48_V_CELL13_PARAM_LENGTH,
          0
          }
      ,
      {
          BATT48_V_CELL12_PARAM_TX_METHOD , 
          BATT48_V_CELL12_PARAM_CLC_TIME,
          BATT48_V_CELL12_PARAM_LENGTH,
          0
          }
      ,
      {
          BATT48_V_CELL11_PARAM_TX_METHOD , 
          BATT48_V_CELL11_PARAM_CLC_TIME,
          BATT48_V_CELL11_PARAM_LENGTH,
          0
          }
      ,
      {
          BATT48_V_CELL10_PARAM_TX_METHOD , 
          BATT48_V_CELL10_PARAM_CLC_TIME,
          BATT48_V_CELL10_PARAM_LENGTH,
          0
          }
      ,
      {
          BATT48_V_CELL9_PARAM_TX_METHOD , 
          BATT48_V_CELL9_PARAM_CLC_TIME,
          BATT48_V_CELL9_PARAM_LENGTH,
          0
          }
      ,
      {
          BATT48_V_CELL8_PARAM_TX_METHOD , 
          BATT48_V_CELL8_PARAM_CLC_TIME,
          BATT48_V_CELL8_PARAM_LENGTH,
          0
          }
      ,
      {
          BATT48_V_CELL7_PARAM_TX_METHOD , 
          BATT48_V_CELL7_PARAM_CLC_TIME,
          BATT48_V_CELL7_PARAM_LENGTH,
          0
          }
      ,
      {
          BATT48_V_CELL6_PARAM_TX_METHOD , 
          BATT48_V_CELL6_PARAM_CLC_TIME,
          BATT48_V_CELL6_PARAM_LENGTH,
          0
          }
      ,
      {
          BATT48_V_CELL5_PARAM_TX_METHOD , 
          BATT48_V_CELL5_PARAM_CLC_TIME,
          BATT48_V_CELL5_PARAM_LENGTH,
          0
          }
      ,
      {
          BATT48_V_CELL4_PARAM_TX_METHOD , 
          BATT48_V_CELL4_PARAM_CLC_TIME,
          BATT48_V_CELL4_PARAM_LENGTH,
          0
          }
      ,
      {
          BATT48_V_CELL3_PARAM_TX_METHOD , 
          BATT48_V_CELL3_PARAM_CLC_TIME,
          BATT48_V_CELL3_PARAM_LENGTH,
          0
          }
      ,
      {
          BATT48_V_CELL2_PARAM_TX_METHOD , 
          BATT48_V_CELL2_PARAM_CLC_TIME,
          BATT48_V_CELL2_PARAM_LENGTH,
          0
          }
      ,
      {
          BATT48_V_CELL1_PARAM_TX_METHOD , 
          BATT48_V_CELL1_PARAM_CLC_TIME,
          BATT48_V_CELL1_PARAM_LENGTH,
          0
          }
      ,
      {
          BATT48_V_INFO_TX_METHOD , 
          BATT48_V_INFO_CLC_TIME,
          BATT48_V_INFO_LENGTH,
          0
          }
      ,
      {
          BATT12_V_INFO_TX_METHOD , 
          BATT12_V_INFO_CLC_TIME,
          BATT12_V_INFO_LENGTH,
          0
          }
      ,
      {
          BATT_LIMITS_TX_METHOD , 
          BATT_LIMITS_CLC_TIME,
          BATT_LIMITS_LENGTH,
          0
          }
      ,
      {
          DCDC48_V_INFO_TX_METHOD , 
          DCDC48_V_INFO_CLC_TIME,
          DCDC48_V_INFO_LENGTH,
          0
          }
      ,
      {
          DCDC12_V_INFO_TX_METHOD , 
          DCDC12_V_INFO_CLC_TIME,
          DCDC12_V_INFO_LENGTH,
          0
          }
      ,
      {
          BATT12_V_CELL4_PARAM_TX_METHOD , 
          BATT12_V_CELL4_PARAM_CLC_TIME,
          BATT12_V_CELL4_PARAM_LENGTH,
          0
          }
      ,
      {
          BATT12_V_CELL3_PARAM_TX_METHOD , 
          BATT12_V_CELL3_PARAM_CLC_TIME,
          BATT12_V_CELL3_PARAM_LENGTH,
          0
          }
      ,
      {
          BATT12_V_CELL2_PARAM_TX_METHOD , 
          BATT12_V_CELL2_PARAM_CLC_TIME,
          BATT12_V_CELL2_PARAM_LENGTH,
          0
          }
      ,
      {
          BATT12_V_CELL1_PARAM_TX_METHOD , 
          BATT12_V_CELL1_PARAM_CLC_TIME,
          BATT12_V_CELL1_PARAM_LENGTH,
          0
          }
      ,
      {
          BATT48_V_TEMPS_TX_METHOD , 
          BATT48_V_TEMPS_CLC_TIME,
          BATT48_V_TEMPS_LENGTH,
          0
          }
      ,
      {
          BATT12_V_TEMPS_TX_METHOD , 
          BATT12_V_TEMPS_CLC_TIME,
          BATT12_V_TEMPS_LENGTH,
          0
          }
};

CanMgr_RxInfoTable_t CanMgr_RxInfoTable[CANMGR_MAX_NO_OF_RX_MSGS] = {
      {
          ISG_INFO_RX_METHOD , 
          ISG_INFO_LENGTH,
          0,
          0
          }
      ,
      {
          EMS_INFO1_RX_METHOD , 
          EMS_INFO1_LENGTH,
          0,
          0
          }
      ,
      {
          VEHICLE_INFO_RX_METHOD , 
          VEHICLE_INFO_LENGTH,
          10,
          0
          }
};




/**********************************************************************************************************************
                                  F U N C T I O N S    D E C L A R A T I O N                        
* *********************************************************************************************************************/

/**
* Pack message Batt48VCell14Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt48_v_cell14_param_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt48_v_cell14_param_t *src_p,
      size_t size);



/**
* Pack message Batt48VCell13Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt48_v_cell13_param_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt48_v_cell13_param_t *src_p,
      size_t size);



/**
* Pack message Batt48VCell12Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt48_v_cell12_param_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt48_v_cell12_param_t *src_p,
      size_t size);



/**
* Pack message Batt48VCell11Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt48_v_cell11_param_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt48_v_cell11_param_t *src_p,
      size_t size);



/**
* Pack message Batt48VCell10Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt48_v_cell10_param_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt48_v_cell10_param_t *src_p,
      size_t size);



/**
* Pack message Batt48VCell9Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt48_v_cell9_param_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt48_v_cell9_param_t *src_p,
      size_t size);



/**
* Pack message Batt48VCell8Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt48_v_cell8_param_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt48_v_cell8_param_t *src_p,
      size_t size);



/**
* Pack message Batt48VCell7Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt48_v_cell7_param_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt48_v_cell7_param_t *src_p,
      size_t size);



/**
* Pack message Batt48VCell6Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt48_v_cell6_param_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt48_v_cell6_param_t *src_p,
      size_t size);



/**
* Pack message Batt48VCell5Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt48_v_cell5_param_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt48_v_cell5_param_t *src_p,
      size_t size);



/**
* Pack message Batt48VCell4Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt48_v_cell4_param_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt48_v_cell4_param_t *src_p,
      size_t size);



/**
* Pack message Batt48VCell3Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt48_v_cell3_param_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt48_v_cell3_param_t *src_p,
      size_t size);



/**
* Pack message Batt48VCell2Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt48_v_cell2_param_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt48_v_cell2_param_t *src_p,
      size_t size);



/**
* Pack message Batt48VCell1Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt48_v_cell1_param_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt48_v_cell1_param_t *src_p,
      size_t size);



/**
* Pack message Batt48VInfo.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt48_v_info_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt48_v_info_t *src_p,
      size_t size);



/**
* Pack message Batt12VInfo.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt12_v_info_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt12_v_info_t *src_p,
      size_t size);



/**
* Pack message PMUStatus.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_pmu_status_pack(
      uint8_t *dst_p,
      const  powertraincanv04_pmu_status_t *src_p,
      size_t size);



/**
* Pack message Batt48VTemps.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt48_v_temps_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt48_v_temps_t *src_p,
      size_t size);



/**
* Pack message BattLimits.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt_limits_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt_limits_t *src_p,
      size_t size);



/**
* Pack message DCDC48VInfo.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_dcdc48_v_info_pack(
      uint8_t *dst_p,
      const  powertraincanv04_dcdc48_v_info_t *src_p,
      size_t size);



/**
* Pack message DCDC12VInfo.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_dcdc12_v_info_pack(
      uint8_t *dst_p,
      const  powertraincanv04_dcdc12_v_info_t *src_p,
      size_t size);



/**
* Pack message Batt12VCell4Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt12_v_cell4_param_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt12_v_cell4_param_t *src_p,
      size_t size);



/**
* Pack message Batt12VCell3Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt12_v_cell3_param_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt12_v_cell3_param_t *src_p,
      size_t size);



/**
* Pack message Batt12VCell2Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt12_v_cell2_param_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt12_v_cell2_param_t *src_p,
      size_t size);



/**
* Pack message Batt12VTemps.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt12_v_temps_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt12_v_temps_t *src_p,
      size_t size);



/**
* Pack message Batt12VCell1Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32 powertraincanv04_batt12_v_cell1_param_pack(
      uint8_t *dst_p,
      const  powertraincanv04_batt12_v_cell1_param_t *src_p,
      size_t size);



/**
* Unpack message ISGInfo.
*
* @param[out] dst_p Object to unpack the message into.
* @param[in] src_p Message to unpack.
* @param[in] size Size of src_p.
*
* @return zero(0) or negative error code.
*/
static sint32 powertraincanv04_isg_info_unpack(
      powertraincanv04_isg_info_t *dst_p,
      const uint8_t *src_p,
      size_t size);



/**
* Unpack message EMSInfo1.
*
* @param[out] dst_p Object to unpack the message into.
* @param[in] src_p Message to unpack.
* @param[in] size Size of src_p.
*
* @return zero(0) or negative error code.
*/
static sint32 powertraincanv04_ems_info1_unpack(
      powertraincanv04_ems_info1_t *dst_p,
      const uint8_t *src_p,
      size_t size);



/**
* Unpack message VehicleInfo.
*
* @param[out] dst_p Object to unpack the message into.
* @param[in] src_p Message to unpack.
* @param[in] size Size of src_p.
*
* @return zero(0) or negative error code.
*/
static sint32 powertraincanv04_vehicle_info_unpack(
      powertraincanv04_vehicle_info_t *dst_p,
      const uint8_t *src_p,
      size_t size);



/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_pmu_status_pmu_shutdown_ok_encode(float64 value); 
static uint8_t powertraincanv04_pmu_status_isg_volt_setpoint_encode(float64 value); 
static uint8_t powertraincanv04_pmu_status_pmu_crank_inhibit_encode(float64 value); 
static uint8_t powertraincanv04_pmu_status_isg_volt_max_encode(float64 value); 
static uint8_t powertraincanv04_pmu_status_isg_volt_min_encode(float64 value); 
static uint8_t powertraincanv04_pmu_status_pmu_state_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_so_c_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_do_d_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_bal_status_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_so_h_cap_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_so_h_res_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_imbal_encode(float64 value); 
static uint16_t powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_volt_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_so_c_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_do_d_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_bal_status_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_so_h_cap_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_so_h_res_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_imbal_encode(float64 value); 
static uint16_t powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_volt_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_so_c_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_do_d_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_bal_status_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_so_h_cap_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_so_h_res_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_imbal_encode(float64 value); 
static uint16_t powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_volt_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_so_c_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_do_d_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_bal_status_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_so_h_cap_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_so_h_res_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_imbal_encode(float64 value); 
static uint16_t powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_volt_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_so_c_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_do_d_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_bal_status_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_so_h_cap_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_so_h_res_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_imbal_encode(float64 value); 
static uint16_t powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_volt_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_so_c_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_do_d_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_bal_status_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_so_h_cap_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_so_h_res_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_imbal_encode(float64 value); 
static uint16_t powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_volt_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_so_c_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_do_d_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_bal_status_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_so_h_cap_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_so_h_res_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_imbal_encode(float64 value); 
static uint16_t powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_volt_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_so_c_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_do_d_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_bal_status_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_so_h_cap_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_so_h_res_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_imbal_encode(float64 value); 
static uint16_t powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_volt_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_so_c_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_do_d_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_bal_status_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_so_h_cap_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_so_h_res_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_imbal_encode(float64 value); 
static uint16_t powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_volt_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_so_c_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_do_d_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_bal_status_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_so_h_cap_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_so_h_res_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_imbal_encode(float64 value); 
static uint16_t powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_volt_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_so_c_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_do_d_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_bal_status_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_so_h_cap_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_so_h_res_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_imbal_encode(float64 value); 
static uint16_t powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_volt_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_so_c_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_do_d_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_bal_status_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_so_h_cap_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_so_h_res_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_imbal_encode(float64 value); 
static uint16_t powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_volt_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_so_c_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_do_d_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_bal_status_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_so_h_cap_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_so_h_res_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_imbal_encode(float64 value); 
static uint16_t powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_volt_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_so_c_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_do_d_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_bal_status_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_so_h_cap_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_so_h_res_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_imbal_encode(float64 value); 
static uint16_t powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_volt_encode(float64 value); 
static uint16_t powertraincanv04_batt48_v_info_batt48_v_curr_meas_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_info_batt48_v_temp_avrg_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_info_batt48_v_temp_max_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_info_batt48_v_temp_min_encode(float64 value); 
static uint16_t powertraincanv04_batt48_v_info_batt48_v_estimated_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_info_batt48_v_so_c_encode(float64 value); 
static uint16_t powertraincanv04_batt12_v_info_batt12_v_curr_meas_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_info_batt12_v_temp_avrg_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_info_batt12_v_temp_max_encode(float64 value); 
static uint16_t powertraincanv04_batt12_v_info_batt12_v_estimated_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_info_batt12_v_so_c_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_info_batt12_v_temp_min_encode(float64 value); 
static uint8_t powertraincanv04_batt_limits_batt12_v_max_encode(float64 value); 
static uint8_t powertraincanv04_batt_limits_batt12_v_max_chrg_curr_encode(float64 value); 
static uint8_t powertraincanv04_batt_limits_batt12_v_max_dischrg_curr_encode(float64 value); 
static uint8_t powertraincanv04_batt_limits_batt12_v_min_encode(float64 value); 
static uint8_t powertraincanv04_batt_limits_batt48_v_max_chrg_curr_encode(float64 value); 
static uint16_t powertraincanv04_batt_limits_batt48_v_max_dischrg_curr_encode(float64 value); 
static uint16_t powertraincanv04_dcdc48_v_info_dcdc48_v_curr_meas_encode(float64 value); 
static uint8_t powertraincanv04_dcdc48_v_info_dcdc48_v_switch_req_encode(float64 value); 
static uint8_t powertraincanv04_dcdc48_v_info_dcdc48_v_switch_status_encode(float64 value); 
static uint8_t powertraincanv04_dcdc48_v_info_batt48_v_cont_status_encode(float64 value); 
static uint16_t powertraincanv04_dcdc48_v_info_dcdc48_volt_meas_encode(float64 value); 
static uint8_t powertraincanv04_dcdc48_v_info_dcdc48_volt_setpoint_encode(float64 value); 
static uint16_t powertraincanv04_dcdc12_v_info_dcdc12_v_curr_meas_encode(float64 value); 
static uint8_t powertraincanv04_dcdc12_v_info_dcdc_status_encode(float64 value); 
static uint8_t powertraincanv04_dcdc12_v_info_dcdc12_v_switch_status_encode(float64 value); 
static uint16_t powertraincanv04_dcdc12_v_info_dcdc12_volt_meas_encode(float64 value); 
static uint8_t powertraincanv04_dcdc12_v_info_dcdc12_volt_setpoint_encode(float64 value); 
static uint8_t powertraincanv04_dcdc12_v_info_batt12_v_cont_status_encode(float64 value); 
static uint8_t powertraincanv04_dcdc12_v_info_dcdc12_v_switch_req_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_so_c_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_do_d_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_bal_status_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_so_h_cap_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_so_h_res_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_imbal_encode(float64 value); 
static uint16_t powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_volt_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_so_c_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_do_d_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_bal_status_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_so_h_cap_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_so_h_res_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_imbal_encode(float64 value); 
static uint16_t powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_volt_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_so_c_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_do_d_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_bal_status_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_so_h_cap_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_so_h_res_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_imbal_encode(float64 value); 
static uint16_t powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_volt_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_so_c_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_do_d_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_bal_status_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_so_h_cap_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_so_h_res_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_imbal_encode(float64 value); 
static uint16_t powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_volt_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_temps_batt48_v_temp_meas1_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_temps_batt48_v_temp_meas2_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_temps_batt48_v_temp_meas3_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_temps_batt48_v_temp_meas4_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_temps_batt48_v_temp_meas5_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_temps_batt48_v_temp_meas6_encode(float64 value); 
static uint8_t powertraincanv04_batt48_v_temps_batt48_v_temp_meas7_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_temps_batt12_v_temp_meas1_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_temps_batt12_v_temp_meas2_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_temps_batt12_v_temp_meas3_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_temps_batt12_v_temp_meas4_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_temps_batt12_v_temp_meas5_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_temps_batt12_v_temp_meas6_encode(float64 value); 
static uint8_t powertraincanv04_batt12_v_temps_batt12_v_temp_meas7_encode(float64 value); 



/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64 powertraincanv04_vehicle_info_inertia_switch_state_decode(uint8_t value);
static float64 powertraincanv04_vehicle_info_ambient_temp_decode(uint8_t value);
static float64 powertraincanv04_vehicle_info_emergency_switch_state_decode(uint8_t value);
static float64 powertraincanv04_vehicle_info_brake_pedal_pos_decode(uint8_t value);
static float64 powertraincanv04_vehicle_info_drive_mode_decode(uint8_t value);
static float64 powertraincanv04_vehicle_info_engine_stop_requested_decode(uint8_t value);
static float64 powertraincanv04_vehicle_info_park_brake_state_decode(uint8_t value);
static float64 powertraincanv04_vehicle_info_vehicle_power_state_decode(uint8_t value);
static float64 powertraincanv04_vehicle_info_coolant_temp_decode(uint8_t value);
static float64 powertraincanv04_vehicle_info_reverse_switch_state_decode(uint8_t value);
static float64 powertraincanv04_vehicle_info_crank_requested_decode(uint8_t value);
static float64 powertraincanv04_vehicle_info_vehicle_shutdown_req_decode(uint8_t value);
static float64 powertraincanv04_isg_info_isg_torque_est_decode(uint16_t value);
static float64 powertraincanv04_isg_info_isg_state_decode(uint8_t value);
static float64 powertraincanv04_ems_info1_isg_torque_min_slew_rate_decode(uint16_t value);
static float64 powertraincanv04_ems_info1_isg_min_torque_decode(uint8_t value);
static float64 powertraincanv04_ems_info1_isg_speed_setpoint_decode(uint16_t value);
static float64 powertraincanv04_ems_info1_engine_state_decode(uint8_t value);
static float64 powertraincanv04_ems_info1_isg_torque_available_decode(uint8_t value);
static float64 powertraincanv04_ems_info1_crank_cmd_decode(uint8_t value);
static float64 powertraincanv04_ems_info1_isg_torque_max_slew_rate_decode(uint8_t value);



/**
* Check that given signal is in allowed range.
*
* @param[in] value Signal to check.
*
@return true if in range, false otherwise.
*/
static boolean powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_so_c_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_do_d_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_bal_status_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_so_h_cap_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_so_h_res_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_imbal_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_volt_is_in_range(uint16_t value);
static boolean powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_so_c_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_do_d_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_bal_status_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_so_h_cap_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_so_h_res_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_imbal_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_volt_is_in_range(uint16_t value);
static boolean powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_so_c_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_do_d_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_bal_status_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_so_h_cap_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_so_h_res_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_imbal_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_volt_is_in_range(uint16_t value);
static boolean powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_so_c_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_do_d_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_bal_status_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_so_h_cap_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_so_h_res_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_imbal_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_volt_is_in_range(uint16_t value);
static boolean powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_so_c_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_do_d_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_bal_status_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_so_h_cap_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_so_h_res_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_imbal_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_volt_is_in_range(uint16_t value);
static boolean powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_so_c_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_do_d_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_bal_status_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_so_h_cap_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_so_h_res_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_imbal_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_volt_is_in_range(uint16_t value);
static boolean powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_so_c_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_do_d_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_bal_status_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_so_h_cap_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_so_h_res_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_imbal_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_volt_is_in_range(uint16_t value);
static boolean powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_so_c_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_do_d_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_bal_status_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_so_h_cap_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_so_h_res_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_imbal_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_volt_is_in_range(uint16_t value);
static boolean powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_so_c_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_do_d_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_bal_status_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_so_h_cap_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_so_h_res_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_imbal_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_volt_is_in_range(uint16_t value);
static boolean powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_so_c_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_do_d_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_bal_status_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_so_h_cap_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_so_h_res_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_imbal_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_volt_is_in_range(uint16_t value);
static boolean powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_so_c_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_do_d_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_bal_status_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_so_h_cap_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_so_h_res_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_imbal_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_volt_is_in_range(uint16_t value);
static boolean powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_so_c_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_do_d_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_bal_status_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_so_h_cap_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_so_h_res_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_imbal_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_volt_is_in_range(uint16_t value);
static boolean powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_so_c_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_do_d_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_bal_status_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_so_h_cap_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_so_h_res_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_imbal_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_volt_is_in_range(uint16_t value);
static boolean powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_so_c_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_do_d_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_bal_status_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_so_h_cap_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_so_h_res_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_imbal_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_volt_is_in_range(uint16_t value);
static boolean powertraincanv04_batt48_v_info_batt48_v_curr_meas_is_in_range(uint16_t value);
static boolean powertraincanv04_batt48_v_info_batt48_v_temp_avrg_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_info_batt48_v_temp_max_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_info_batt48_v_temp_min_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_info_batt48_v_estimated_is_in_range(uint16_t value);
static boolean powertraincanv04_batt48_v_info_batt48_v_so_c_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_info_batt12_v_curr_meas_is_in_range(uint16_t value);
static boolean powertraincanv04_batt12_v_info_batt12_v_temp_avrg_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_info_batt12_v_temp_max_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_info_batt12_v_estimated_is_in_range(uint16_t value);
static boolean powertraincanv04_batt12_v_info_batt12_v_so_c_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_info_batt12_v_temp_min_is_in_range(uint8_t value);
static boolean powertraincanv04_pmu_status_pmu_shutdown_ok_is_in_range(uint8_t value);
static boolean powertraincanv04_pmu_status_isg_volt_setpoint_is_in_range(uint8_t value);
static boolean powertraincanv04_pmu_status_pmu_crank_inhibit_is_in_range(uint8_t value);
static boolean powertraincanv04_pmu_status_isg_volt_max_is_in_range(uint8_t value);
static boolean powertraincanv04_pmu_status_isg_volt_min_is_in_range(uint8_t value);
static boolean powertraincanv04_pmu_status_pmu_state_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_temps_batt48_v_temp_meas1_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_temps_batt48_v_temp_meas2_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_temps_batt48_v_temp_meas3_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_temps_batt48_v_temp_meas4_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_temps_batt48_v_temp_meas5_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_temps_batt48_v_temp_meas6_is_in_range(uint8_t value);
static boolean powertraincanv04_batt48_v_temps_batt48_v_temp_meas7_is_in_range(uint8_t value);
static boolean powertraincanv04_batt_limits_batt12_v_max_is_in_range(uint8_t value);
static boolean powertraincanv04_batt_limits_batt12_v_max_chrg_curr_is_in_range(uint8_t value);
static boolean powertraincanv04_batt_limits_batt12_v_max_dischrg_curr_is_in_range(uint8_t value);
static boolean powertraincanv04_batt_limits_batt12_v_min_is_in_range(uint8_t value);
static boolean powertraincanv04_batt_limits_batt48_v_max_chrg_curr_is_in_range(uint8_t value);
static boolean powertraincanv04_batt_limits_batt48_v_max_dischrg_curr_is_in_range(uint16_t value);
static boolean powertraincanv04_dcdc48_v_info_dcdc48_v_curr_meas_is_in_range(uint16_t value);
static boolean powertraincanv04_dcdc48_v_info_dcdc48_v_switch_req_is_in_range(uint8_t value);
static boolean powertraincanv04_dcdc48_v_info_dcdc48_v_switch_status_is_in_range(uint8_t value);
static boolean powertraincanv04_dcdc48_v_info_batt48_v_cont_status_is_in_range(uint8_t value);
static boolean powertraincanv04_dcdc48_v_info_dcdc48_volt_meas_is_in_range(uint16_t value);
static boolean powertraincanv04_dcdc48_v_info_dcdc48_volt_setpoint_is_in_range(uint8_t value);
static boolean powertraincanv04_dcdc12_v_info_dcdc12_v_curr_meas_is_in_range(uint16_t value);
static boolean powertraincanv04_dcdc12_v_info_dcdc_status_is_in_range(uint8_t value);
static boolean powertraincanv04_dcdc12_v_info_dcdc12_v_switch_status_is_in_range(uint8_t value);
static boolean powertraincanv04_dcdc12_v_info_dcdc12_volt_meas_is_in_range(uint16_t value);
static boolean powertraincanv04_dcdc12_v_info_dcdc12_volt_setpoint_is_in_range(uint8_t value);
static boolean powertraincanv04_dcdc12_v_info_batt12_v_cont_status_is_in_range(uint8_t value);
static boolean powertraincanv04_dcdc12_v_info_dcdc12_v_switch_req_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_so_c_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_do_d_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_bal_status_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_so_h_cap_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_so_h_res_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_imbal_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_volt_is_in_range(uint16_t value);
static boolean powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_so_c_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_do_d_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_bal_status_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_so_h_cap_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_so_h_res_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_imbal_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_volt_is_in_range(uint16_t value);
static boolean powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_so_c_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_do_d_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_bal_status_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_so_h_cap_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_so_h_res_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_imbal_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_volt_is_in_range(uint16_t value);
static boolean powertraincanv04_batt12_v_temps_batt12_v_temp_meas1_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_temps_batt12_v_temp_meas2_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_temps_batt12_v_temp_meas3_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_temps_batt12_v_temp_meas4_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_temps_batt12_v_temp_meas5_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_temps_batt12_v_temp_meas6_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_temps_batt12_v_temp_meas7_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_so_c_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_do_d_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_bal_status_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_so_h_cap_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_so_h_res_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_imbal_is_in_range(uint8_t value);
static boolean powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_volt_is_in_range(uint16_t value);

static inline uint8_t pack_left_shift_u8(    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value << shift) & mask);
}

static inline uint8_t pack_left_shift_u16(
    uint16_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value << shift) & mask);
}

static inline uint8_t pack_right_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value >> shift) & mask);
}

static inline uint8_t pack_right_shift_u16(
    uint16_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value >> shift) & mask);
}

static inline uint8_t unpack_left_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value & mask) << shift);
}

static inline uint16_t unpack_left_shift_u16(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint16_t)((uint16_t)(value & mask) << shift);
}

static inline uint8_t unpack_right_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value & mask) >> shift);
}

static inline uint16_t unpack_right_shift_u16(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint16_t)((uint16_t)(value & mask) >> shift);
}



/**********************************************************************************************************************
                                    F U N C T I O N S    D E F  I N A T I O N S                        
**********************************************************************************************************************/

/**
* Pack message Batt48VCell14Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt48_v_cell14_param_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt48_v_cell14_param_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6u);

    dst_p[0] |= pack_left_shift_u8(src_p->batt48_v_cell14_so_c, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt48_v_cell14_do_d, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell14_bal_status, 6u, 0xc0u);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell14_so_h_cap, 0u, 0x3fu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt48_v_cell14_so_h_res, 2u, 0xfcu);
    dst_p[3] |= pack_right_shift_u8(src_p->batt48_v_cell14_imbal, 5u, 0x03u);
    dst_p[4] |= pack_left_shift_u8(src_p->batt48_v_cell14_imbal, 3u, 0xf8u);
    dst_p[4] |= pack_right_shift_u16(src_p->batt48_v_cell14_volt, 8u, 0x07u);
    dst_p[5] |= pack_left_shift_u16(src_p->batt48_v_cell14_volt, 0u, 0xffu);

    return (6);
}
/**
* Pack message Batt48VCell13Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt48_v_cell13_param_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt48_v_cell13_param_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6u);

    dst_p[0] |= pack_left_shift_u8(src_p->batt48_v_cell13_so_c, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt48_v_cell13_do_d, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell13_bal_status, 6u, 0xc0u);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell13_so_h_cap, 0u, 0x3fu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt48_v_cell13_so_h_res, 2u, 0xfcu);
    dst_p[3] |= pack_right_shift_u8(src_p->batt48_v_cell13_imbal, 5u, 0x03u);
    dst_p[4] |= pack_left_shift_u8(src_p->batt48_v_cell13_imbal, 3u, 0xf8u);
    dst_p[4] |= pack_right_shift_u16(src_p->batt48_v_cell13_volt, 8u, 0x07u);
    dst_p[5] |= pack_left_shift_u16(src_p->batt48_v_cell13_volt, 0u, 0xffu);

    return (6);
}
/**
* Pack message Batt48VCell12Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt48_v_cell12_param_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt48_v_cell12_param_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6u);

    dst_p[0] |= pack_left_shift_u8(src_p->batt48_v_cell12_so_c, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt48_v_cell12_do_d, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell12_bal_status, 6u, 0xc0u);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell12_so_h_cap, 0u, 0x3fu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt48_v_cell12_so_h_res, 2u, 0xfcu);
    dst_p[3] |= pack_right_shift_u8(src_p->batt48_v_cell12_imbal, 5u, 0x03u);
    dst_p[4] |= pack_left_shift_u8(src_p->batt48_v_cell12_imbal, 3u, 0xf8u);
    dst_p[4] |= pack_right_shift_u16(src_p->batt48_v_cell12_volt, 8u, 0x07u);
    dst_p[5] |= pack_left_shift_u16(src_p->batt48_v_cell12_volt, 0u, 0xffu);

    return (6);
}
/**
* Pack message Batt48VCell11Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt48_v_cell11_param_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt48_v_cell11_param_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6u);

    dst_p[0] |= pack_left_shift_u8(src_p->batt48_v_cell11_so_c, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt48_v_cell11_do_d, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell11_bal_status, 6u, 0xc0u);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell11_so_h_cap, 0u, 0x3fu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt48_v_cell11_so_h_res, 2u, 0xfcu);
    dst_p[3] |= pack_right_shift_u8(src_p->batt48_v_cell11_imbal, 5u, 0x03u);
    dst_p[4] |= pack_left_shift_u8(src_p->batt48_v_cell11_imbal, 3u, 0xf8u);
    dst_p[4] |= pack_right_shift_u16(src_p->batt48_v_cell11_volt, 8u, 0x07u);
    dst_p[5] |= pack_left_shift_u16(src_p->batt48_v_cell11_volt, 0u, 0xffu);

    return (6);
}
/**
* Pack message Batt48VCell10Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt48_v_cell10_param_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt48_v_cell10_param_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6u);

    dst_p[0] |= pack_left_shift_u8(src_p->batt48_v_cell10_so_c, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt48_v_cell10_do_d, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell10_bal_status, 6u, 0xc0u);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell10_so_h_cap, 0u, 0x3fu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt48_v_cell10_so_h_res, 2u, 0xfcu);
    dst_p[3] |= pack_right_shift_u8(src_p->batt48_v_cell10_imbal, 5u, 0x03u);
    dst_p[4] |= pack_left_shift_u8(src_p->batt48_v_cell10_imbal, 3u, 0xf8u);
    dst_p[4] |= pack_right_shift_u16(src_p->batt48_v_cell10_volt, 8u, 0x07u);
    dst_p[5] |= pack_left_shift_u16(src_p->batt48_v_cell10_volt, 0u, 0xffu);

    return (6);
}
/**
* Pack message Batt48VCell9Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt48_v_cell9_param_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt48_v_cell9_param_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6u);

    dst_p[0] |= pack_left_shift_u8(src_p->batt48_v_cell9_so_c, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt48_v_cell9_do_d, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell9_bal_status, 6u, 0xc0u);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell9_so_h_cap, 0u, 0x3fu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt48_v_cell9_so_h_res, 2u, 0xfcu);
    dst_p[3] |= pack_right_shift_u8(src_p->batt48_v_cell9_imbal, 5u, 0x03u);
    dst_p[4] |= pack_left_shift_u8(src_p->batt48_v_cell9_imbal, 3u, 0xf8u);
    dst_p[4] |= pack_right_shift_u16(src_p->batt48_v_cell9_volt, 8u, 0x07u);
    dst_p[5] |= pack_left_shift_u16(src_p->batt48_v_cell9_volt, 0u, 0xffu);

    return (6);
}
/**
* Pack message Batt48VCell8Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt48_v_cell8_param_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt48_v_cell8_param_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6u);

    dst_p[0] |= pack_left_shift_u8(src_p->batt48_v_cell8_so_c, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt48_v_cell8_do_d, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell8_bal_status, 6u, 0xc0u);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell8_so_h_cap, 0u, 0x3fu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt48_v_cell8_so_h_res, 2u, 0xfcu);
    dst_p[3] |= pack_right_shift_u8(src_p->batt48_v_cell8_imbal, 5u, 0x03u);
    dst_p[4] |= pack_left_shift_u8(src_p->batt48_v_cell8_imbal, 3u, 0xf8u);
    dst_p[4] |= pack_right_shift_u16(src_p->batt48_v_cell8_volt, 8u, 0x07u);
    dst_p[5] |= pack_left_shift_u16(src_p->batt48_v_cell8_volt, 0u, 0xffu);

    return (6);
}
/**
* Pack message Batt48VCell7Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt48_v_cell7_param_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt48_v_cell7_param_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6u);

    dst_p[0] |= pack_left_shift_u8(src_p->batt48_v_cell7_so_c, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt48_v_cell7_do_d, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell7_bal_status, 6u, 0xc0u);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell7_so_h_cap, 0u, 0x3fu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt48_v_cell7_so_h_res, 2u, 0xfcu);
    dst_p[3] |= pack_right_shift_u8(src_p->batt48_v_cell7_imbal, 5u, 0x03u);
    dst_p[4] |= pack_left_shift_u8(src_p->batt48_v_cell7_imbal, 3u, 0xf8u);
    dst_p[4] |= pack_right_shift_u16(src_p->batt48_v_cell7_volt, 8u, 0x07u);
    dst_p[5] |= pack_left_shift_u16(src_p->batt48_v_cell7_volt, 0u, 0xffu);

    return (6);
}
/**
* Pack message Batt48VCell6Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt48_v_cell6_param_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt48_v_cell6_param_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6u);

    dst_p[0] |= pack_left_shift_u8(src_p->batt48_v_cell6_so_c, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt48_v_cell6_do_d, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell6_bal_status, 6u, 0xc0u);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell6_so_h_cap, 0u, 0x3fu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt48_v_cell6_so_h_res, 2u, 0xfcu);
    dst_p[3] |= pack_right_shift_u8(src_p->batt48_v_cell6_imbal, 5u, 0x03u);
    dst_p[4] |= pack_left_shift_u8(src_p->batt48_v_cell6_imbal, 3u, 0xf8u);
    dst_p[4] |= pack_right_shift_u16(src_p->batt48_v_cell6_volt, 8u, 0x07u);
    dst_p[5] |= pack_left_shift_u16(src_p->batt48_v_cell6_volt, 0u, 0xffu);

    return (6);
}
/**
* Pack message Batt48VCell5Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt48_v_cell5_param_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt48_v_cell5_param_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6u);

    dst_p[0] |= pack_left_shift_u8(src_p->batt48_v_cell5_so_c, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt48_v_cell5_do_d, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell5_bal_status, 6u, 0xc0u);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell5_so_h_cap, 0u, 0x3fu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt48_v_cell5_so_h_res, 2u, 0xfcu);
    dst_p[3] |= pack_right_shift_u8(src_p->batt48_v_cell5_imbal, 5u, 0x03u);
    dst_p[4] |= pack_left_shift_u8(src_p->batt48_v_cell5_imbal, 3u, 0xf8u);
    dst_p[4] |= pack_right_shift_u16(src_p->batt48_v_cell5_volt, 8u, 0x07u);
    dst_p[5] |= pack_left_shift_u16(src_p->batt48_v_cell5_volt, 0u, 0xffu);

    return (6);
}
/**
* Pack message Batt48VCell4Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt48_v_cell4_param_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt48_v_cell4_param_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6u);

    dst_p[0] |= pack_left_shift_u8(src_p->batt48_v_cell4_so_c, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt48_v_cell4_do_d, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell4_bal_status, 6u, 0xc0u);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell4_so_h_cap, 0u, 0x3fu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt48_v_cell4_so_h_res, 2u, 0xfcu);
    dst_p[3] |= pack_right_shift_u8(src_p->batt48_v_cell4_imbal, 5u, 0x03u);
    dst_p[4] |= pack_left_shift_u8(src_p->batt48_v_cell4_imbal, 3u, 0xf8u);
    dst_p[4] |= pack_right_shift_u16(src_p->batt48_v_cell4_volt, 8u, 0x07u);
    dst_p[5] |= pack_left_shift_u16(src_p->batt48_v_cell4_volt, 0u, 0xffu);

    return (6);
}
/**
* Pack message Batt48VCell3Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt48_v_cell3_param_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt48_v_cell3_param_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6u);

    dst_p[0] |= pack_left_shift_u8(src_p->batt48_v_cell13_so_c, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt48_v_cell13_do_d, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell13_bal_status, 6u, 0xc0u);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell13_so_h_cap, 0u, 0x3fu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt48_v_cell13_so_h_res, 2u, 0xfcu);
    dst_p[3] |= pack_right_shift_u8(src_p->batt48_v_cell13_imbal, 5u, 0x03u);
    dst_p[4] |= pack_left_shift_u8(src_p->batt48_v_cell13_imbal, 3u, 0xf8u);
    dst_p[4] |= pack_right_shift_u16(src_p->batt48_v_cell13_volt, 8u, 0x07u);
    dst_p[5] |= pack_left_shift_u16(src_p->batt48_v_cell13_volt, 0u, 0xffu);

    return (6);
}
/**
* Pack message Batt48VCell2Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt48_v_cell2_param_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt48_v_cell2_param_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6u);

    dst_p[0] |= pack_left_shift_u8(src_p->batt48_v_cell2_so_c, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt48_v_cell2_do_d, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell2_bal_status, 6u, 0xc0u);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell2_so_h_cap, 0u, 0x3fu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt48_v_cell2_so_h_res, 2u, 0xfcu);
    dst_p[3] |= pack_right_shift_u8(src_p->batt48_v_cell2_imbal, 5u, 0x03u);
    dst_p[4] |= pack_left_shift_u8(src_p->batt48_v_cell2_imbal, 3u, 0xf8u);
    dst_p[4] |= pack_right_shift_u16(src_p->batt48_v_cell2_volt, 8u, 0x07u);
    dst_p[5] |= pack_left_shift_u16(src_p->batt48_v_cell2_volt, 0u, 0xffu);

    return (6);
}
/**
* Pack message Batt48VCell1Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt48_v_cell1_param_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt48_v_cell1_param_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6u);

    dst_p[0] |= pack_left_shift_u8(src_p->batt48_v_cell1_so_c, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt48_v_cell1_do_d, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell1_bal_status, 6u, 0xc0u);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_cell1_so_h_cap, 0u, 0x3fu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt48_v_cell1_so_h_res, 2u, 0xfcu);
    dst_p[3] |= pack_right_shift_u8(src_p->batt48_v_cell1_imbal, 5u, 0x03u);
    dst_p[4] |= pack_left_shift_u8(src_p->batt48_v_cell1_imbal, 3u, 0xf8u);
    dst_p[4] |= pack_right_shift_u16(src_p->batt48_v_cell1_volt, 8u, 0x07u);
    dst_p[5] |= pack_left_shift_u16(src_p->batt48_v_cell1_volt, 0u, 0xffu);

    return (6);
}
/**
* Pack message Batt48VInfo.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt48_v_info_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt48_v_info_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8u);

    dst_p[0] |= pack_right_shift_u16(src_p->batt48_v_curr_meas, 3u, 0xffu);
    dst_p[1] |= pack_left_shift_u16(src_p->batt48_v_curr_meas, 5u, 0xe0u);
    dst_p[1] |= pack_right_shift_u8(src_p->batt48_v_temp_avrg, 2u, 0x1fu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_temp_avrg, 6u, 0xc0u);
    dst_p[2] |= pack_right_shift_u8(src_p->batt48_v_temp_max, 1u, 0x3fu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt48_v_temp_max, 7u, 0x80u);
    dst_p[3] |= pack_left_shift_u8(src_p->batt48_v_temp_min, 0u, 0x7fu);
    dst_p[4] |= pack_right_shift_u16(src_p->batt48_v_estimated, 4u, 0xffu);
    dst_p[5] |= pack_left_shift_u16(src_p->batt48_v_estimated, 4u, 0xf0u);
    dst_p[6] |= pack_left_shift_u8(src_p->batt48_v_so_c, 0u, 0xffu);

    return (8);
}
/**
* Pack message Batt12VInfo.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt12_v_info_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt12_v_info_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8u);

    dst_p[0] |= pack_right_shift_u16(src_p->batt12_v_curr_meas, 2u, 0xffu);
    dst_p[1] |= pack_left_shift_u16(src_p->batt12_v_curr_meas, 6u, 0xc0u);
    dst_p[1] |= pack_right_shift_u8(src_p->batt12_v_temp_avrg, 1u, 0x3fu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt12_v_temp_avrg, 7u, 0x80u);
    dst_p[2] |= pack_left_shift_u8(src_p->batt12_v_temp_max, 0u, 0x7fu);
    dst_p[3] |= pack_right_shift_u16(src_p->batt12_v_estimated, 2u, 0xffu);
    dst_p[4] |= pack_left_shift_u16(src_p->batt12_v_estimated, 6u, 0xc0u);
    dst_p[5] |= pack_left_shift_u8(src_p->batt12_v_so_c, 0u, 0xffu);
    dst_p[6] |= pack_left_shift_u8(src_p->batt12_v_temp_min, 0u, 0x7fu);

    return (8);
}
/**
* Pack message PMUStatus.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_pmu_status_pack(
    uint8_t *dst_p,
    const  powertraincanv04_pmu_status_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 4u);

    dst_p[0] |= pack_left_shift_u8(src_p->pmu_shutdown_ok, 7u, 0x80u);
    dst_p[0] |= pack_left_shift_u8(src_p->isg_volt_setpoint, 0u, 0x7fu);
    dst_p[1] |= pack_left_shift_u8(src_p->pmu_crank_inhibit, 7u, 0x80u);
    dst_p[1] |= pack_left_shift_u8(src_p->isg_volt_max, 0u, 0x7fu);
    dst_p[2] |= pack_left_shift_u8(src_p->isg_volt_min, 0u, 0xffu);
    dst_p[3] |= pack_left_shift_u8(src_p->pmu_state, 0u, 0x07u);

    return (4);
}
/**
* Pack message Batt48VTemps.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt48_v_temps_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt48_v_temps_t *src_p,
    size_t size)
{
    if (size < 7u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 7u);

    dst_p[0] |= pack_left_shift_u8(src_p->batt48_v_temp_meas1, 0u, 0x7fu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt48_v_temp_meas2, 0u, 0x7fu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt48_v_temp_meas3, 0u, 0x7fu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt48_v_temp_meas4, 0u, 0x7fu);
    dst_p[4] |= pack_left_shift_u8(src_p->batt48_v_temp_meas5, 0u, 0x7fu);
    dst_p[5] |= pack_left_shift_u8(src_p->batt48_v_temp_meas6, 0u, 0x7fu);
    dst_p[6] |= pack_left_shift_u8(src_p->batt48_v_temp_meas7, 0u, 0x7fu);

    return (7);
}
/**
* Pack message BattLimits.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt_limits_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt_limits_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8u);

    dst_p[0] |= pack_left_shift_u8(src_p->batt12_v_max, 1u, 0xfeu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt12_v_max_chrg_curr, 3u, 0xf8u);
    dst_p[2] |= pack_left_shift_u8(src_p->batt12_v_max_dischrg_curr, 0u, 0xffu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt12_v_min, 1u, 0xfeu);
    dst_p[4] |= pack_left_shift_u8(src_p->batt48_v_max_chrg_curr, 2u, 0xfcu);
    dst_p[4] |= pack_right_shift_u16(src_p->batt48_v_max_dischrg_curr, 8u, 0x03u);
    dst_p[5] |= pack_left_shift_u16(src_p->batt48_v_max_dischrg_curr, 0u, 0xffu);

    return (8);
}
/**
* Pack message DCDC48VInfo.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_dcdc48_v_info_pack(
    uint8_t *dst_p,
    const  powertraincanv04_dcdc48_v_info_t *src_p,
    size_t size)
{
    if (size < 5u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 5u);

    dst_p[0] |= pack_right_shift_u16(src_p->dcdc48_v_curr_meas, 2u, 0xffu);
    dst_p[1] |= pack_left_shift_u16(src_p->dcdc48_v_curr_meas, 6u, 0xc0u);
    dst_p[1] |= pack_left_shift_u8(src_p->dcdc48_v_switch_req, 4u, 0x30u);
    dst_p[1] |= pack_left_shift_u8(src_p->dcdc48_v_switch_status, 2u, 0x0cu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt48_v_cont_status, 0u, 0x03u);
    dst_p[2] |= pack_right_shift_u16(src_p->dcdc48_volt_meas, 4u, 0xffu);
    dst_p[3] |= pack_left_shift_u16(src_p->dcdc48_volt_meas, 4u, 0xf0u);
    dst_p[4] |= pack_left_shift_u8(src_p->dcdc48_volt_setpoint, 1u, 0xfeu);

    return (5);
}
/**
* Pack message DCDC12VInfo.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_dcdc12_v_info_pack(
    uint8_t *dst_p,
    const  powertraincanv04_dcdc12_v_info_t *src_p,
    size_t size)
{
    if (size < 5u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 5u);

    dst_p[0] |= pack_right_shift_u16(src_p->dcdc12_v_curr_meas, 3u, 0xffu);
    dst_p[1] |= pack_left_shift_u16(src_p->dcdc12_v_curr_meas, 5u, 0xe0u);
    dst_p[1] |= pack_left_shift_u8(src_p->dcdc_status, 2u, 0x1cu);
    dst_p[1] |= pack_left_shift_u8(src_p->dcdc12_v_switch_status, 0u, 0x03u);
    dst_p[2] |= pack_right_shift_u16(src_p->dcdc12_volt_meas, 2u, 0xffu);
    dst_p[3] |= pack_left_shift_u16(src_p->dcdc12_volt_meas, 6u, 0xc0u);
    dst_p[3] |= pack_left_shift_u8(src_p->dcdc12_volt_setpoint, 0u, 0x3fu);
    dst_p[4] |= pack_left_shift_u8(src_p->batt12_v_cont_status, 2u, 0x0cu);
    dst_p[4] |= pack_left_shift_u8(src_p->dcdc12_v_switch_req, 0u, 0x03u);

    return (5);
}
/**
* Pack message Batt12VCell4Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt12_v_cell4_param_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt12_v_cell4_param_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6u);

    dst_p[0] |= pack_left_shift_u8(src_p->batt12_v_cell4_so_c, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt12_v_cell4_do_d, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt12_v_cell4_bal_status, 6u, 0xc0u);
    dst_p[2] |= pack_left_shift_u8(src_p->batt12_v_cell4_so_h_cap, 0u, 0x3fu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt12_v_cell4_so_h_res, 2u, 0xfcu);
    dst_p[3] |= pack_right_shift_u8(src_p->batt12_v_cell4_imbal, 5u, 0x03u);
    dst_p[4] |= pack_left_shift_u8(src_p->batt12_v_cell4_imbal, 3u, 0xf8u);
    dst_p[4] |= pack_right_shift_u16(src_p->batt12_v_cell4_volt, 8u, 0x07u);
    dst_p[5] |= pack_left_shift_u16(src_p->batt12_v_cell4_volt, 0u, 0xffu);

    return (6);
}
/**
* Pack message Batt12VCell3Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt12_v_cell3_param_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt12_v_cell3_param_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6u);

    dst_p[0] |= pack_left_shift_u8(src_p->batt12_v_cell3_so_c, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt12_v_cell3_do_d, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt12_v_cell3_bal_status, 6u, 0xc0u);
    dst_p[2] |= pack_left_shift_u8(src_p->batt12_v_cell3_so_h_cap, 0u, 0x3fu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt12_v_cell3_so_h_res, 2u, 0xfcu);
    dst_p[3] |= pack_right_shift_u8(src_p->batt12_v_cell3_imbal, 5u, 0x03u);
    dst_p[4] |= pack_left_shift_u8(src_p->batt12_v_cell3_imbal, 3u, 0xf8u);
    dst_p[4] |= pack_right_shift_u16(src_p->batt12_v_cell3_volt, 8u, 0x07u);
    dst_p[5] |= pack_left_shift_u16(src_p->batt12_v_cell3_volt, 0u, 0xffu);

    return (6);
}
/**
* Pack message Batt12VCell2Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt12_v_cell2_param_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt12_v_cell2_param_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6u);

    dst_p[0] |= pack_left_shift_u8(src_p->batt12_v_cell2_so_c, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt12_v_cell2_do_d, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt12_v_cell2_bal_status, 6u, 0xc0u);
    dst_p[2] |= pack_left_shift_u8(src_p->batt12_v_cell2_so_h_cap, 0u, 0x3fu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt12_v_cell2_so_h_res, 2u, 0xfcu);
    dst_p[3] |= pack_right_shift_u8(src_p->batt12_v_cell2_imbal, 5u, 0x03u);
    dst_p[4] |= pack_left_shift_u8(src_p->batt12_v_cell2_imbal, 3u, 0xf8u);
    dst_p[4] |= pack_right_shift_u16(src_p->batt12_v_cell2_volt, 8u, 0x07u);
    dst_p[5] |= pack_left_shift_u16(src_p->batt12_v_cell2_volt, 0u, 0xffu);

    return (6);
}
/**
* Pack message Batt12VTemps.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt12_v_temps_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt12_v_temps_t *src_p,
    size_t size)
{
    if (size < 7u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 7u);

    dst_p[0] |= pack_left_shift_u8(src_p->batt12_v_temp_meas1, 0u, 0x7fu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt12_v_temp_meas2, 0u, 0x7fu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt12_v_temp_meas3, 0u, 0x7fu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt12_v_temp_meas4, 0u, 0x7fu);
    dst_p[4] |= pack_left_shift_u8(src_p->batt12_v_temp_meas5, 0u, 0x7fu);
    dst_p[5] |= pack_left_shift_u8(src_p->batt12_v_temp_meas6, 0u, 0x7fu);
    dst_p[6] |= pack_left_shift_u8(src_p->batt12_v_temp_meas7, 0u, 0x7fu);

    return (7);
}
/**
* Pack message Batt12VCell1Param.
*
* @param[out] dst_p Buffer to pack the message into.
* @param[in] src_p Data to pack.
* @param[in] size Size of dst_p.
*
* @return Size of packed data, or negative error code.
*/
static sint32  powertraincanv04_batt12_v_cell1_param_pack(
    uint8_t *dst_p,
    const  powertraincanv04_batt12_v_cell1_param_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6u);

    dst_p[0] |= pack_left_shift_u8(src_p->batt12_v_cell1_so_c, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->batt12_v_cell1_do_d, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->batt12_v_cell1_bal_status, 6u, 0xc0u);
    dst_p[2] |= pack_left_shift_u8(src_p->batt12_v_cell1_so_h_cap, 0u, 0x3fu);
    dst_p[3] |= pack_left_shift_u8(src_p->batt12_v_cell1_so_h_res, 2u, 0xfcu);
    dst_p[3] |= pack_right_shift_u8(src_p->batt12_v_cell1_imbal, 5u, 0x03u);
    dst_p[4] |= pack_left_shift_u8(src_p->batt12_v_cell1_imbal, 3u, 0xf8u);
    dst_p[4] |= pack_right_shift_u16(src_p->batt12_v_cell1_volt, 8u, 0x07u);
    dst_p[5] |= pack_left_shift_u16(src_p->batt12_v_cell1_volt, 0u, 0xffu);

    return (6);
}
/**
* Unpack message VehicleInfo.
*
*@param[out] dst_p Object to unpack the message into.
* @param[in] src_p Message to unpack.
* @param[in] size Size of src_p.
*
* @return zero(0) or negative error code.
*/ 
static sint32 powertraincanv04_vehicle_info_unpack(
     powertraincanv04_vehicle_info_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 5u) {
        return (-EINVAL);
    }

    memset(dst_p, 0, sizeof(*dst_p));

    dst_p->inertia_switch_state |= unpack_right_shift_u8(src_p[0], 7u, 0x80u);
    dst_p->ambient_temp |= unpack_right_shift_u8(src_p[0], 0u, 0x7fu);
    dst_p->emergency_switch_state |= unpack_right_shift_u8(src_p[1], 7u, 0x80u);
    dst_p->brake_pedal_pos |= unpack_right_shift_u8(src_p[1], 0u, 0x7fu);
    dst_p->drive_mode |= unpack_right_shift_u8(src_p[2], 7u, 0x80u);
    dst_p->engine_stop_requested |= unpack_right_shift_u8(src_p[2], 6u, 0x40u);
    dst_p->park_brake_state |= unpack_right_shift_u8(src_p[2], 4u, 0x30u);
    dst_p->vehicle_power_state |= unpack_right_shift_u8(src_p[2], 0u, 0x0fu);
    dst_p->coolant_temp |= unpack_right_shift_u8(src_p[3], 0u, 0xffu);
    dst_p->reverse_switch_state |= unpack_right_shift_u8(src_p[4], 2u, 0x04u);
    dst_p->crank_requested |= unpack_right_shift_u8(src_p[4], 1u, 0x02u);
    dst_p->vehicle_shutdown_req |= unpack_right_shift_u8(src_p[4], 0u, 0x01u);

    return (0);
}
/**
* Unpack message ISGInfo.
*
*@param[out] dst_p Object to unpack the message into.
* @param[in] src_p Message to unpack.
* @param[in] size Size of src_p.
*
* @return zero(0) or negative error code.
*/ 
static sint32 powertraincanv04_isg_info_unpack(
     powertraincanv04_isg_info_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 3u) {
        return (-EINVAL);
    }

    memset(dst_p, 0, sizeof(*dst_p));

    dst_p->isg_torque_est |= unpack_left_shift_u16(src_p[0], 3u, 0xffu);
    dst_p->isg_torque_est |= unpack_right_shift_u16(src_p[1], 5u, 0xe0u);
    dst_p->isg_state |= unpack_right_shift_u8(src_p[1], 0u, 0x07u);

    return (0);
}
/**
* Unpack message EMSInfo1.
*
*@param[out] dst_p Object to unpack the message into.
* @param[in] src_p Message to unpack.
* @param[in] size Size of src_p.
*
* @return zero(0) or negative error code.
*/ 
static sint32 powertraincanv04_ems_info1_unpack(
     powertraincanv04_ems_info1_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 6u) {
        return (-EINVAL);
    }

    memset(dst_p, 0, sizeof(*dst_p));

    dst_p->isg_torque_min_slew_rate |= unpack_left_shift_u16(src_p[0], 1u, 0xffu);
    dst_p->isg_torque_min_slew_rate |= unpack_right_shift_u16(src_p[1], 7u, 0x80u);
    dst_p->isg_min_torque |= unpack_right_shift_u8(src_p[1], 0u, 0x7fu);
    dst_p->isg_speed_setpoint |= unpack_left_shift_u16(src_p[2], 3u, 0xffu);
    dst_p->isg_speed_setpoint |= unpack_right_shift_u16(src_p[3], 5u, 0xe0u);
    dst_p->engine_state |= unpack_right_shift_u8(src_p[3], 2u, 0x1cu);
    dst_p->isg_torque_available |= unpack_right_shift_u8(src_p[4], 1u, 0xfeu);
    dst_p->crank_cmd |= unpack_right_shift_u8(src_p[4], 0u, 0x01u);
    dst_p->isg_torque_max_slew_rate |= unpack_right_shift_u8(src_p[5], 0u, 0xffu);

    return (0);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_so_c_encode(float64 value)
{
    return (uint8_t)(value / 0.5);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_do_d_encode(float64 value)
{
    return (uint8_t)(value / 0.02);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_bal_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_so_h_cap_encode(float64 value)
{
    return (uint8_t)(value - 65.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_so_h_res_encode(float64 value)
{
    return (uint8_t)(value - 90.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_imbal_encode(float64 value)
{
    return (uint8_t)(value / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_volt_encode(float64 value)
{
    return (uint16_t)((value - 1.8) / 0.001);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_so_c_is_in_range(uint8_t value)
{
    return (value <= 200u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_do_d_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_bal_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_so_h_cap_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_so_h_res_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_imbal_is_in_range(uint8_t value)
{
    return (value <= 120u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_volt_is_in_range(uint16_t value)
{
    return (value <= 2000u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_so_c_encode(float64 value)
{
    return (uint8_t)(value / 0.5);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_do_d_encode(float64 value)
{
    return (uint8_t)(value / 0.02);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_bal_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_so_h_cap_encode(float64 value)
{
    return (uint8_t)(value - 65.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_so_h_res_encode(float64 value)
{
    return (uint8_t)(value - 90.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_imbal_encode(float64 value)
{
    return (uint8_t)(value / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_volt_encode(float64 value)
{
    return (uint16_t)((value - 1.8) / 0.001);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_so_c_is_in_range(uint8_t value)
{
    return (value <= 200u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_do_d_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_bal_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_so_h_cap_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_so_h_res_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_imbal_is_in_range(uint8_t value)
{
    return (value <= 120u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_volt_is_in_range(uint16_t value)
{
    return (value <= 2000u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_so_c_encode(float64 value)
{
    return (uint8_t)(value / 0.5);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_do_d_encode(float64 value)
{
    return (uint8_t)(value / 0.02);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_bal_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_so_h_cap_encode(float64 value)
{
    return (uint8_t)(value - 65.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_so_h_res_encode(float64 value)
{
    return (uint8_t)(value - 90.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_imbal_encode(float64 value)
{
    return (uint8_t)(value / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_volt_encode(float64 value)
{
    return (uint16_t)((value - 1.8) / 0.001);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_so_c_is_in_range(uint8_t value)
{
    return (value <= 200u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_do_d_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_bal_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_so_h_cap_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_so_h_res_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_imbal_is_in_range(uint8_t value)
{
    return (value <= 120u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_volt_is_in_range(uint16_t value)
{
    return (value <= 2000u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_so_c_encode(float64 value)
{
    return (uint8_t)(value / 0.5);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_do_d_encode(float64 value)
{
    return (uint8_t)(value / 0.02);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_bal_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_so_h_cap_encode(float64 value)
{
    return (uint8_t)(value - 65.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_so_h_res_encode(float64 value)
{
    return (uint8_t)(value - 90.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_imbal_encode(float64 value)
{
    return (uint8_t)(value / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_volt_encode(float64 value)
{
    return (uint16_t)((value - 1.8) / 0.001);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_so_c_is_in_range(uint8_t value)
{
    return (value <= 200u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_do_d_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_bal_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_so_h_cap_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_so_h_res_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_imbal_is_in_range(uint8_t value)
{
    return (value <= 120u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_volt_is_in_range(uint16_t value)
{
    return (value <= 2000u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_so_c_encode(float64 value)
{
    return (uint8_t)(value / 0.5);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_do_d_encode(float64 value)
{
    return (uint8_t)(value / 0.02);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_bal_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_so_h_cap_encode(float64 value)
{
    return (uint8_t)(value - 65.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_so_h_res_encode(float64 value)
{
    return (uint8_t)(value - 90.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_imbal_encode(float64 value)
{
    return (uint8_t)(value / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_volt_encode(float64 value)
{
    return (uint16_t)((value - 1.8) / 0.001);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_so_c_is_in_range(uint8_t value)
{
    return (value <= 200u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_do_d_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_bal_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_so_h_cap_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_so_h_res_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_imbal_is_in_range(uint8_t value)
{
    return (value <= 120u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_volt_is_in_range(uint16_t value)
{
    return (value <= 2000u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_so_c_encode(float64 value)
{
    return (uint8_t)(value / 0.5);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_do_d_encode(float64 value)
{
    return (uint8_t)(value / 0.02);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_bal_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_so_h_cap_encode(float64 value)
{
    return (uint8_t)(value - 65.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_so_h_res_encode(float64 value)
{
    return (uint8_t)(value - 90.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_imbal_encode(float64 value)
{
    return (uint8_t)(value / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_volt_encode(float64 value)
{
    return (uint16_t)((value - 1.8) / 0.001);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_so_c_is_in_range(uint8_t value)
{
    return (value <= 200u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_do_d_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_bal_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_so_h_cap_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_so_h_res_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_imbal_is_in_range(uint8_t value)
{
    return (value <= 120u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_volt_is_in_range(uint16_t value)
{
    return (value <= 2000u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_so_c_encode(float64 value)
{
    return (uint8_t)(value / 0.5);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_do_d_encode(float64 value)
{
    return (uint8_t)(value / 0.02);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_bal_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_so_h_cap_encode(float64 value)
{
    return (uint8_t)(value - 65.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_so_h_res_encode(float64 value)
{
    return (uint8_t)(value - 90.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_imbal_encode(float64 value)
{
    return (uint8_t)(value / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_volt_encode(float64 value)
{
    return (uint16_t)((value - 1.8) / 0.001);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_so_c_is_in_range(uint8_t value)
{
    return (value <= 200u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_do_d_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_bal_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_so_h_cap_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_so_h_res_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_imbal_is_in_range(uint8_t value)
{
    return (value <= 120u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_volt_is_in_range(uint16_t value)
{
    return (value <= 2000u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_so_c_encode(float64 value)
{
    return (uint8_t)(value / 0.5);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_do_d_encode(float64 value)
{
    return (uint8_t)(value / 0.02);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_bal_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_so_h_cap_encode(float64 value)
{
    return (uint8_t)(value - 65.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_so_h_res_encode(float64 value)
{
    return (uint8_t)(value - 90.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_imbal_encode(float64 value)
{
    return (uint8_t)(value / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_volt_encode(float64 value)
{
    return (uint16_t)((value - 1.8) / 0.001);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_so_c_is_in_range(uint8_t value)
{
    return (value <= 200u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_do_d_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_bal_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_so_h_cap_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_so_h_res_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_imbal_is_in_range(uint8_t value)
{
    return (value <= 120u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_volt_is_in_range(uint16_t value)
{
    return (value <= 2000u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_so_c_encode(float64 value)
{
    return (uint8_t)(value / 0.5);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_do_d_encode(float64 value)
{
    return (uint8_t)(value / 0.02);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_bal_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_so_h_cap_encode(float64 value)
{
    return (uint8_t)(value - 65.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_so_h_res_encode(float64 value)
{
    return (uint8_t)(value - 90.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_imbal_encode(float64 value)
{
    return (uint8_t)(value / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_volt_encode(float64 value)
{
    return (uint16_t)((value - 1.8) / 0.001);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_so_c_is_in_range(uint8_t value)
{
    return (value <= 200u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_do_d_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_bal_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_so_h_cap_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_so_h_res_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_imbal_is_in_range(uint8_t value)
{
    return (value <= 120u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_volt_is_in_range(uint16_t value)
{
    return (value <= 2000u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_so_c_encode(float64 value)
{
    return (uint8_t)(value / 0.5);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_do_d_encode(float64 value)
{
    return (uint8_t)(value / 0.02);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_bal_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_so_h_cap_encode(float64 value)
{
    return (uint8_t)(value - 65.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_so_h_res_encode(float64 value)
{
    return (uint8_t)(value - 90.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_imbal_encode(float64 value)
{
    return (uint8_t)(value / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_volt_encode(float64 value)
{
    return (uint16_t)((value - 1.8) / 0.001);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_so_c_is_in_range(uint8_t value)
{
    return (value <= 200u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_do_d_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_bal_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_so_h_cap_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_so_h_res_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_imbal_is_in_range(uint8_t value)
{
    return (value <= 120u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_volt_is_in_range(uint16_t value)
{
    return (value <= 2000u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_so_c_encode(float64 value)
{
    return (uint8_t)(value / 0.5);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_do_d_encode(float64 value)
{
    return (uint8_t)(value / 0.02);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_bal_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_so_h_cap_encode(float64 value)
{
    return (uint8_t)(value - 65.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_so_h_res_encode(float64 value)
{
    return (uint8_t)(value - 90.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_imbal_encode(float64 value)
{
    return (uint8_t)(value / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_volt_encode(float64 value)
{
    return (uint16_t)((value - 1.8) / 0.001);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_so_c_is_in_range(uint8_t value)
{
    return (value <= 200u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_do_d_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_bal_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_so_h_cap_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_so_h_res_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_imbal_is_in_range(uint8_t value)
{
    return (value <= 120u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_volt_is_in_range(uint16_t value)
{
    return (value <= 2000u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_so_c_encode(float64 value)
{
    return (uint8_t)(value / 0.5);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_do_d_encode(float64 value)
{
    return (uint8_t)(value / 0.02);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_bal_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_so_h_cap_encode(float64 value)
{
    return (uint8_t)(value - 65.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_so_h_res_encode(float64 value)
{
    return (uint8_t)(value - 90.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_imbal_encode(float64 value)
{
    return (uint8_t)(value / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_volt_encode(float64 value)
{
    return (uint16_t)((value - 1.8) / 0.001);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_so_c_is_in_range(uint8_t value)
{
    return (value <= 200u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_do_d_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_bal_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_so_h_cap_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_so_h_res_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_imbal_is_in_range(uint8_t value)
{
    return (value <= 120u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_volt_is_in_range(uint16_t value)
{
    return (value <= 2000u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_so_c_encode(float64 value)
{
    return (uint8_t)(value / 0.5);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_do_d_encode(float64 value)
{
    return (uint8_t)(value / 0.02);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_bal_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_so_h_cap_encode(float64 value)
{
    return (uint8_t)(value - 65.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_so_h_res_encode(float64 value)
{
    return (uint8_t)(value - 90.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_imbal_encode(float64 value)
{
    return (uint8_t)(value / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_volt_encode(float64 value)
{
    return (uint16_t)((value - 1.8) / 0.001);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_so_c_is_in_range(uint8_t value)
{
    return (value <= 200u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_do_d_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_bal_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_so_h_cap_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_so_h_res_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_imbal_is_in_range(uint8_t value)
{
    return (value <= 120u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_volt_is_in_range(uint16_t value)
{
    return (value <= 2000u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_so_c_encode(float64 value)
{
    return (uint8_t)(value / 0.5);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_do_d_encode(float64 value)
{
    return (uint8_t)(value / 0.02);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_bal_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_so_h_cap_encode(float64 value)
{
    return (uint8_t)(value - 65.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_so_h_res_encode(float64 value)
{
    return (uint8_t)(value - 90.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_imbal_encode(float64 value)
{
    return (uint8_t)(value / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_volt_encode(float64 value)
{
    return (uint16_t)((value - 1.8) / 0.001);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_so_c_is_in_range(uint8_t value)
{
    return (value <= 200u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_do_d_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_bal_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_so_h_cap_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_so_h_res_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_imbal_is_in_range(uint8_t value)
{
    return (value <= 120u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_volt_is_in_range(uint16_t value)
{
    return (value <= 2000u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt48_v_info_batt48_v_curr_meas_encode(float64 value)
{
    return (uint16_t)(value / 0.5);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_info_batt48_v_temp_avrg_encode(float64 value)
{
    return (uint8_t)(value - -40.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_info_batt48_v_temp_max_encode(float64 value)
{
    return (uint8_t)(value - -40.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_info_batt48_v_temp_min_encode(float64 value)
{
    return (uint8_t)(value - -40.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt48_v_info_batt48_v_estimated_encode(float64 value)
{
    return (uint16_t)((value - 22.4) / 0.01);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_info_batt48_v_so_c_encode(float64 value)
{
    return (uint8_t)(value / 0.5);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_info_batt48_v_curr_meas_is_in_range(uint16_t value)
{
    return (value <= 1200u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_info_batt48_v_temp_avrg_is_in_range(uint8_t value)
{
    return (value <= 125u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_info_batt48_v_temp_max_is_in_range(uint8_t value)
{
    return (value <= 125u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_info_batt48_v_temp_min_is_in_range(uint8_t value)
{
    return (value <= 125u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_info_batt48_v_estimated_is_in_range(uint16_t value)
{
    return (value <= 3080u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_info_batt48_v_so_c_is_in_range(uint8_t value)
{
    return (value <= 200u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt12_v_info_batt12_v_curr_meas_encode(float64 value)
{
    return (uint16_t)(value / 0.2);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_info_batt12_v_temp_avrg_encode(float64 value)
{
    return (uint8_t)(value - -40.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_info_batt12_v_temp_max_encode(float64 value)
{
    return (uint8_t)(value - -40.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt12_v_info_batt12_v_estimated_encode(float64 value)
{
    return (uint16_t)((value - 6.4) / 0.01);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_info_batt12_v_so_c_encode(float64 value)
{
    return (uint8_t)(value / 0.5);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_info_batt12_v_temp_min_encode(float64 value)
{
    return (uint8_t)(value - -40.0);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_info_batt12_v_curr_meas_is_in_range(uint16_t value)
{
    return (value <= 1000u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_info_batt12_v_temp_avrg_is_in_range(uint8_t value)
{
    return (value <= 125u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_info_batt12_v_temp_max_is_in_range(uint8_t value)
{
    return (value <= 125u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_info_batt12_v_estimated_is_in_range(uint16_t value)
{
    return (value <= 880u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_info_batt12_v_so_c_is_in_range(uint8_t value)
{
    return (value <= 200u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_info_batt12_v_temp_min_is_in_range(uint8_t value)
{
    return (value <= 125u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_pmu_status_pmu_shutdown_ok_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_pmu_status_isg_volt_setpoint_encode(float64 value)
{
    return (uint8_t)((value - 40.4) / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_pmu_status_pmu_crank_inhibit_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_pmu_status_isg_volt_max_encode(float64 value)
{
    return (uint8_t)((value - 40.4) / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_pmu_status_isg_volt_min_encode(float64 value)
{
    return (uint8_t)((value - 28.0) / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_pmu_status_pmu_state_encode(float64 value)
{
    return (uint8_t)(value);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_pmu_status_pmu_shutdown_ok_is_in_range(uint8_t value)
{
    return (value <= 1u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_pmu_status_isg_volt_setpoint_is_in_range(uint8_t value)
{
    return (value <= 100u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_pmu_status_pmu_crank_inhibit_is_in_range(uint8_t value)
{
    return (value <= 1u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_pmu_status_isg_volt_max_is_in_range(uint8_t value)
{
    return (value <= 100u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_pmu_status_isg_volt_min_is_in_range(uint8_t value)
{
    return (value <= 224u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_pmu_status_pmu_state_is_in_range(uint8_t value)
{
    return (value <= 7u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_temps_batt48_v_temp_meas1_encode(float64 value)
{
    return (uint8_t)(value - -40.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_temps_batt48_v_temp_meas2_encode(float64 value)
{
    return (uint8_t)(value - -40.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_temps_batt48_v_temp_meas3_encode(float64 value)
{
    return (uint8_t)(value - -40.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_temps_batt48_v_temp_meas4_encode(float64 value)
{
    return (uint8_t)(value - -40.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_temps_batt48_v_temp_meas5_encode(float64 value)
{
    return (uint8_t)(value - -40.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_temps_batt48_v_temp_meas6_encode(float64 value)
{
    return (uint8_t)(value - -40.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt48_v_temps_batt48_v_temp_meas7_encode(float64 value)
{
    return (uint8_t)(value - -40.0);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_temps_batt48_v_temp_meas1_is_in_range(uint8_t value)
{
    return (value <= 125u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_temps_batt48_v_temp_meas2_is_in_range(uint8_t value)
{
    return (value <= 125u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_temps_batt48_v_temp_meas3_is_in_range(uint8_t value)
{
    return (value <= 125u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_temps_batt48_v_temp_meas4_is_in_range(uint8_t value)
{
    return (value <= 125u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_temps_batt48_v_temp_meas5_is_in_range(uint8_t value)
{
    return (value <= 125u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_temps_batt48_v_temp_meas6_is_in_range(uint8_t value)
{
    return (value <= 125u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt48_v_temps_batt48_v_temp_meas7_is_in_range(uint8_t value)
{
    return (value <= 125u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt_limits_batt12_v_max_encode(float64 value)
{
    return (uint8_t)((value - 6.4) / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt_limits_batt12_v_max_chrg_curr_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt_limits_batt12_v_max_dischrg_curr_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt_limits_batt12_v_min_encode(float64 value)
{
    return (uint8_t)((value - 6.4) / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt_limits_batt48_v_max_chrg_curr_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt_limits_batt48_v_max_dischrg_curr_encode(float64 value)
{
    return (uint16_t)(value);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt_limits_batt12_v_max_is_in_range(uint8_t value)
{
    return (value <= 88u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt_limits_batt12_v_max_chrg_curr_is_in_range(uint8_t value)
{
    return (value <= 30u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt_limits_batt12_v_max_dischrg_curr_is_in_range(uint8_t value)
{
    return (value <= 150u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt_limits_batt12_v_min_is_in_range(uint8_t value)
{
    return (value <= 88u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt_limits_batt48_v_max_chrg_curr_is_in_range(uint8_t value)
{
    return (value <= 50u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt_limits_batt48_v_max_dischrg_curr_is_in_range(uint16_t value)
{
    return (value <= 600u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_dcdc48_v_info_dcdc48_v_curr_meas_encode(float64 value)
{
    return (uint16_t)(value / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_dcdc48_v_info_dcdc48_v_switch_req_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_dcdc48_v_info_dcdc48_v_switch_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_dcdc48_v_info_batt48_v_cont_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_dcdc48_v_info_dcdc48_volt_meas_encode(float64 value)
{
    return (uint16_t)((value - 22.4) / 0.01);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_dcdc48_v_info_dcdc48_volt_setpoint_encode(float64 value)
{
    return (uint8_t)((value - 40.0) / 0.1);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_dcdc48_v_info_dcdc48_v_curr_meas_is_in_range(uint16_t value)
{
    return (value <= 900u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_dcdc48_v_info_dcdc48_v_switch_req_is_in_range(uint8_t value)
{
    return (value <= 2u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_dcdc48_v_info_dcdc48_v_switch_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_dcdc48_v_info_batt48_v_cont_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_dcdc48_v_info_dcdc48_volt_meas_is_in_range(uint16_t value)
{
    return (value <= 3080u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_dcdc48_v_info_dcdc48_volt_setpoint_is_in_range(uint8_t value)
{
    return (value <= 104u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_dcdc12_v_info_dcdc12_v_curr_meas_encode(float64 value)
{
    return (uint16_t)(value / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_dcdc12_v_info_dcdc_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_dcdc12_v_info_dcdc12_v_switch_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_dcdc12_v_info_dcdc12_volt_meas_encode(float64 value)
{
    return (uint16_t)((value - 6.4) / 0.01);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_dcdc12_v_info_dcdc12_volt_setpoint_encode(float64 value)
{
    return (uint8_t)((value - 8.0) / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_dcdc12_v_info_batt12_v_cont_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_dcdc12_v_info_dcdc12_v_switch_req_encode(float64 value)
{
    return (uint8_t)(value);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_dcdc12_v_info_dcdc12_v_curr_meas_is_in_range(uint16_t value)
{
    return (value <= 2000u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_dcdc12_v_info_dcdc_status_is_in_range(uint8_t value)
{
    return (value <= 4u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_dcdc12_v_info_dcdc12_v_switch_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_dcdc12_v_info_dcdc12_volt_meas_is_in_range(uint16_t value)
{
    return (value <= 880u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_dcdc12_v_info_dcdc12_volt_setpoint_is_in_range(uint8_t value)
{
    return (value <= 63u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_dcdc12_v_info_batt12_v_cont_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_dcdc12_v_info_dcdc12_v_switch_req_is_in_range(uint8_t value)
{
    return (value <= 2u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_so_c_encode(float64 value)
{
    return (uint8_t)(value / 0.5);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_do_d_encode(float64 value)
{
    return (uint8_t)(value / 0.02);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_bal_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_so_h_cap_encode(float64 value)
{
    return (uint8_t)(value - 65.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_so_h_res_encode(float64 value)
{
    return (uint8_t)(value - 90.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_imbal_encode(float64 value)
{
    return (uint8_t)(value / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_volt_encode(float64 value)
{
    return (uint16_t)((value - 1.8) / 0.001);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_so_c_is_in_range(uint8_t value)
{
    return (value <= 200u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_do_d_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_bal_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_so_h_cap_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_so_h_res_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_imbal_is_in_range(uint8_t value)
{
    return (value <= 120u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_volt_is_in_range(uint16_t value)
{
    return (value <= 2000u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_so_c_encode(float64 value)
{
    return (uint8_t)(value / 0.5);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_do_d_encode(float64 value)
{
    return (uint8_t)(value / 0.02);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_bal_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_so_h_cap_encode(float64 value)
{
    return (uint8_t)(value - 65.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_so_h_res_encode(float64 value)
{
    return (uint8_t)(value - 90.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_imbal_encode(float64 value)
{
    return (uint8_t)(value / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_volt_encode(float64 value)
{
    return (uint16_t)((value - 1.8) / 0.001);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_so_c_is_in_range(uint8_t value)
{
    return (value <= 200u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_do_d_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_bal_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_so_h_cap_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_so_h_res_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_imbal_is_in_range(uint8_t value)
{
    return (value <= 120u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_volt_is_in_range(uint16_t value)
{
    return (value <= 2000u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_so_c_encode(float64 value)
{
    return (uint8_t)(value / 0.5);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_do_d_encode(float64 value)
{
    return (uint8_t)(value / 0.02);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_bal_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_so_h_cap_encode(float64 value)
{
    return (uint8_t)(value - 65.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_so_h_res_encode(float64 value)
{
    return (uint8_t)(value - 90.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_imbal_encode(float64 value)
{
    return (uint8_t)(value / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_volt_encode(float64 value)
{
    return (uint16_t)((value - 1.8) / 0.001);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_so_c_is_in_range(uint8_t value)
{
    return (value <= 200u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_do_d_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_bal_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_so_h_cap_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_so_h_res_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_imbal_is_in_range(uint8_t value)
{
    return (value <= 120u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_volt_is_in_range(uint16_t value)
{
    return (value <= 2000u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_temps_batt12_v_temp_meas1_encode(float64 value)
{
    return (uint8_t)(value - -40.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_temps_batt12_v_temp_meas2_encode(float64 value)
{
    return (uint8_t)(value - -40.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_temps_batt12_v_temp_meas3_encode(float64 value)
{
    return (uint8_t)(value - -40.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_temps_batt12_v_temp_meas4_encode(float64 value)
{
    return (uint8_t)(value - -40.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_temps_batt12_v_temp_meas5_encode(float64 value)
{
    return (uint8_t)(value - -40.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_temps_batt12_v_temp_meas6_encode(float64 value)
{
    return (uint8_t)(value - -40.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_temps_batt12_v_temp_meas7_encode(float64 value)
{
    return (uint8_t)(value - -40.0);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_temps_batt12_v_temp_meas1_is_in_range(uint8_t value)
{
    return (value <= 125u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_temps_batt12_v_temp_meas2_is_in_range(uint8_t value)
{
    return (value <= 125u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_temps_batt12_v_temp_meas3_is_in_range(uint8_t value)
{
    return (value <= 125u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_temps_batt12_v_temp_meas4_is_in_range(uint8_t value)
{
    return (value <= 125u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_temps_batt12_v_temp_meas5_is_in_range(uint8_t value)
{
    return (value <= 125u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_temps_batt12_v_temp_meas6_is_in_range(uint8_t value)
{
    return (value <= 125u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_temps_batt12_v_temp_meas7_is_in_range(uint8_t value)
{
    return (value <= 125u);
}


/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_so_c_encode(float64 value)
{
    return (uint8_t)(value / 0.5);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_do_d_encode(float64 value)
{
    return (uint8_t)(value / 0.02);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_bal_status_encode(float64 value)
{
    return (uint8_t)(value);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_so_h_cap_encode(float64 value)
{
    return (uint8_t)(value - 65.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_so_h_res_encode(float64 value)
{
    return (uint8_t)(value - 90.0);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint8_t powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_imbal_encode(float64 value)
{
    return (uint8_t)(value / 0.1);
}
/**
  * Encode given signal by applying scaling and offset
  * @param[in] value Signal to encode.
  * @return Encoded signal.
*/ 
static uint16_t powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_volt_encode(float64 value)
{
    return (uint16_t)((value - 1.8) / 0.001);
}

/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_so_c_is_in_range(uint8_t value)
{
    return (value <= 200u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_do_d_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_bal_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_so_h_cap_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_so_h_res_is_in_range(uint8_t value)
{
    return (value <= 60u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_imbal_is_in_range(uint8_t value)
{
    return (value <= 120u);
}


/* 
  * Check that given signal is in allowed range.                                                                          
  * @param[in] value Signal to check.                                                                            
  * @return true if in range, false otherwise                                                                          
*/ 
static boolean  powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_volt_is_in_range(uint16_t value)
{
    return (value <= 2000u);
}



/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64  powertraincanv04_vehicle_info_inertia_switch_state_decode(uint8_t value)
{
    return ((float64)value);
}
/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64  powertraincanv04_vehicle_info_ambient_temp_decode(uint8_t value)
{
    return ((float64)value + -40.0);
}
/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64  powertraincanv04_vehicle_info_emergency_switch_state_decode(uint8_t value)
{
    return ((float64)value);
}
/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64  powertraincanv04_vehicle_info_brake_pedal_pos_decode(uint8_t value)
{
    return ((float64)value);
}
/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64  powertraincanv04_vehicle_info_drive_mode_decode(uint8_t value)
{
    return ((float64)value);
}
/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64  powertraincanv04_vehicle_info_engine_stop_requested_decode(uint8_t value)
{
    return ((float64)value);
}
/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64  powertraincanv04_vehicle_info_park_brake_state_decode(uint8_t value)
{
    return ((float64)value);
}
/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64  powertraincanv04_vehicle_info_vehicle_power_state_decode(uint8_t value)
{
    return ((float64)value);
}
/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64  powertraincanv04_vehicle_info_coolant_temp_decode(uint8_t value)
{
    return ((float64)value + -40.0);
}
/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64  powertraincanv04_vehicle_info_reverse_switch_state_decode(uint8_t value)
{
    return ((float64)value);
}
/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64  powertraincanv04_vehicle_info_crank_requested_decode(uint8_t value)
{
    return ((float64)value);
}
/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64  powertraincanv04_vehicle_info_vehicle_shutdown_req_decode(uint8_t value)
{
    return ((float64)value);
}

/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64  powertraincanv04_isg_info_isg_torque_est_decode(uint16_t value)
{
    return (((float64)value * 0.1) + -85.0);
}
/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64  powertraincanv04_isg_info_isg_state_decode(uint8_t value)
{
    return ((float64)value);
}

/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64  powertraincanv04_ems_info1_isg_torque_min_slew_rate_decode(uint16_t value)
{
    return ((float64)value);
}
/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64  powertraincanv04_ems_info1_isg_min_torque_decode(uint8_t value)
{
    return ((float64)value);
}
/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64  powertraincanv04_ems_info1_isg_speed_setpoint_decode(uint16_t value)
{
    return ((float64)value);
}
/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64  powertraincanv04_ems_info1_engine_state_decode(uint8_t value)
{
    return ((float64)value);
}
/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64  powertraincanv04_ems_info1_isg_torque_available_decode(uint8_t value)
{
    return ((float64)value);
}
/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64  powertraincanv04_ems_info1_crank_cmd_decode(uint8_t value)
{
    return ((float64)value);
}
/**
  * Decode given signal by applying scaling and offset
  * @param[in] value Signal to decode.
  * @return Decoded signal.
*/ 
static float64  powertraincanv04_ems_info1_isg_torque_max_slew_rate_decode(uint8_t value)
{
    return ((float64)value);
}


/* 
  * @Brief  : Updates signal Batt48VCell14SoC                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell14_so_c(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL14_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_so_c_encode(data);
		 if(powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_so_c_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell14_param.batt48_v_cell14_so_c = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell14_param_pack(fl_data,&batt48_v_cell14_param,(size_t)BATT48_V_CELL14_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL14_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell14DoD                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell14_do_d(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL14_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_do_d_encode(data);
		 if(powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_do_d_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell14_param.batt48_v_cell14_do_d = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell14_param_pack(fl_data,&batt48_v_cell14_param,(size_t)BATT48_V_CELL14_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL14_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell14BalStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell14_bal_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL14_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_bal_status_encode(data);
		 if(powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_bal_status_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell14_param.batt48_v_cell14_bal_status = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell14_param_pack(fl_data,&batt48_v_cell14_param,(size_t)BATT48_V_CELL14_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL14_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell14SoHCap                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell14_so_h_cap(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL14_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_so_h_cap_encode(data);
		 if(powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_so_h_cap_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell14_param.batt48_v_cell14_so_h_cap = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell14_param_pack(fl_data,&batt48_v_cell14_param,(size_t)BATT48_V_CELL14_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL14_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell14SoHRes                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell14_so_h_res(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL14_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_so_h_res_encode(data);
		 if(powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_so_h_res_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell14_param.batt48_v_cell14_so_h_res = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell14_param_pack(fl_data,&batt48_v_cell14_param,(size_t)BATT48_V_CELL14_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL14_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell14Imbal                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell14_imbal(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL14_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_imbal_encode(data);
		 if(powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_imbal_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell14_param.batt48_v_cell14_imbal = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell14_param_pack(fl_data,&batt48_v_cell14_param,(size_t)BATT48_V_CELL14_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL14_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell14Volt                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell14_volt(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL14_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_volt_encode(data);
		 if(powertraincanv04_batt48_v_cell14_param_batt48_v_cell14_volt_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell14_param.batt48_v_cell14_volt = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell14_param_pack(fl_data,&batt48_v_cell14_param,(size_t)BATT48_V_CELL14_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL14_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt48VCell14SoC                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell14_so_c_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL14_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell14DoD                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell14_do_d_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL14_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell14BalStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell14_bal_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL14_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell14SoHCap                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell14_so_h_cap_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL14_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell14SoHRes                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell14_so_h_res_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL14_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell14Imbal                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell14_imbal_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL14_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell14Volt                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell14_volt_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL14_PARAM));
}

/* 
  * @Brief  : Updates signal Batt48VCell13SoC                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell13_so_c(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL13_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_so_c_encode(data);
		 if(powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_so_c_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell13_param.batt48_v_cell13_so_c = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell13_param_pack(fl_data,&batt48_v_cell13_param,(size_t)BATT48_V_CELL13_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL13_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell13DoD                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell13_do_d(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL13_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_do_d_encode(data);
		 if(powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_do_d_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell13_param.batt48_v_cell13_do_d = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell13_param_pack(fl_data,&batt48_v_cell13_param,(size_t)BATT48_V_CELL13_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL13_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell13BalStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell13_bal_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL13_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_bal_status_encode(data);
		 if(powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_bal_status_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell13_param.batt48_v_cell13_bal_status = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell13_param_pack(fl_data,&batt48_v_cell13_param,(size_t)BATT48_V_CELL13_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL13_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell13SoHCap                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell13_so_h_cap(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL13_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_so_h_cap_encode(data);
		 if(powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_so_h_cap_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell13_param.batt48_v_cell13_so_h_cap = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell13_param_pack(fl_data,&batt48_v_cell13_param,(size_t)BATT48_V_CELL13_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL13_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell13SoHRes                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell13_so_h_res(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL13_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_so_h_res_encode(data);
		 if(powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_so_h_res_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell13_param.batt48_v_cell13_so_h_res = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell13_param_pack(fl_data,&batt48_v_cell13_param,(size_t)BATT48_V_CELL13_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL13_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell13Imbal                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell13_imbal(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL13_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_imbal_encode(data);
		 if(powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_imbal_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell13_param.batt48_v_cell13_imbal = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell13_param_pack(fl_data,&batt48_v_cell13_param,(size_t)BATT48_V_CELL13_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL13_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell13Volt                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell13_volt(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL13_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_volt_encode(data);
		 if(powertraincanv04_batt48_v_cell13_param_batt48_v_cell13_volt_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell13_param.batt48_v_cell13_volt = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell13_param_pack(fl_data,&batt48_v_cell13_param,(size_t)BATT48_V_CELL13_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL13_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt48VCell13SoC                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell13_so_c_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL13_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell13DoD                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell13_do_d_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL13_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell13BalStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell13_bal_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL13_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell13SoHCap                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell13_so_h_cap_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL13_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell13SoHRes                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell13_so_h_res_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL13_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell13Imbal                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell13_imbal_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL13_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell13Volt                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell13_volt_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL13_PARAM));
}

/* 
  * @Brief  : Updates signal Batt48VCell12SoC                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell12_so_c(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL12_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_so_c_encode(data);
		 if(powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_so_c_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell12_param.batt48_v_cell12_so_c = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell12_param_pack(fl_data,&batt48_v_cell12_param,(size_t)BATT48_V_CELL12_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL12_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell12DoD                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell12_do_d(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL12_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_do_d_encode(data);
		 if(powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_do_d_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell12_param.batt48_v_cell12_do_d = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell12_param_pack(fl_data,&batt48_v_cell12_param,(size_t)BATT48_V_CELL12_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL12_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell12BalStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell12_bal_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL12_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_bal_status_encode(data);
		 if(powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_bal_status_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell12_param.batt48_v_cell12_bal_status = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell12_param_pack(fl_data,&batt48_v_cell12_param,(size_t)BATT48_V_CELL12_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL12_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell12SoHCap                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell12_so_h_cap(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL12_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_so_h_cap_encode(data);
		 if(powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_so_h_cap_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell12_param.batt48_v_cell12_so_h_cap = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell12_param_pack(fl_data,&batt48_v_cell12_param,(size_t)BATT48_V_CELL12_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL12_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell12SoHRes                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell12_so_h_res(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL12_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_so_h_res_encode(data);
		 if(powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_so_h_res_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell12_param.batt48_v_cell12_so_h_res = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell12_param_pack(fl_data,&batt48_v_cell12_param,(size_t)BATT48_V_CELL12_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL12_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell12Imbal                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell12_imbal(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL12_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_imbal_encode(data);
		 if(powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_imbal_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell12_param.batt48_v_cell12_imbal = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell12_param_pack(fl_data,&batt48_v_cell12_param,(size_t)BATT48_V_CELL12_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL12_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell12Volt                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell12_volt(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL12_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_volt_encode(data);
		 if(powertraincanv04_batt48_v_cell12_param_batt48_v_cell12_volt_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell12_param.batt48_v_cell12_volt = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell12_param_pack(fl_data,&batt48_v_cell12_param,(size_t)BATT48_V_CELL12_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL12_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt48VCell12SoC                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell12_so_c_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL12_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell12DoD                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell12_do_d_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL12_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell12BalStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell12_bal_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL12_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell12SoHCap                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell12_so_h_cap_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL12_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell12SoHRes                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell12_so_h_res_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL12_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell12Imbal                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell12_imbal_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL12_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell12Volt                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell12_volt_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL12_PARAM));
}

/* 
  * @Brief  : Updates signal Batt48VCell11SoC                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell11_so_c(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL11_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_so_c_encode(data);
		 if(powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_so_c_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell11_param.batt48_v_cell11_so_c = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell11_param_pack(fl_data,&batt48_v_cell11_param,(size_t)BATT48_V_CELL11_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL11_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell11DoD                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell11_do_d(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL11_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_do_d_encode(data);
		 if(powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_do_d_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell11_param.batt48_v_cell11_do_d = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell11_param_pack(fl_data,&batt48_v_cell11_param,(size_t)BATT48_V_CELL11_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL11_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell11BalStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell11_bal_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL11_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_bal_status_encode(data);
		 if(powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_bal_status_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell11_param.batt48_v_cell11_bal_status = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell11_param_pack(fl_data,&batt48_v_cell11_param,(size_t)BATT48_V_CELL11_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL11_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell11SoHCap                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell11_so_h_cap(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL11_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_so_h_cap_encode(data);
		 if(powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_so_h_cap_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell11_param.batt48_v_cell11_so_h_cap = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell11_param_pack(fl_data,&batt48_v_cell11_param,(size_t)BATT48_V_CELL11_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL11_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell11SoHRes                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell11_so_h_res(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL11_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_so_h_res_encode(data);
		 if(powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_so_h_res_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell11_param.batt48_v_cell11_so_h_res = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell11_param_pack(fl_data,&batt48_v_cell11_param,(size_t)BATT48_V_CELL11_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL11_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell11Imbal                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell11_imbal(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL11_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_imbal_encode(data);
		 if(powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_imbal_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell11_param.batt48_v_cell11_imbal = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell11_param_pack(fl_data,&batt48_v_cell11_param,(size_t)BATT48_V_CELL11_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL11_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell11Volt                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell11_volt(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL11_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_volt_encode(data);
		 if(powertraincanv04_batt48_v_cell11_param_batt48_v_cell11_volt_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell11_param.batt48_v_cell11_volt = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell11_param_pack(fl_data,&batt48_v_cell11_param,(size_t)BATT48_V_CELL11_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL11_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt48VCell11SoC                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell11_so_c_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL11_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell11DoD                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell11_do_d_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL11_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell11BalStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell11_bal_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL11_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell11SoHCap                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell11_so_h_cap_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL11_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell11SoHRes                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell11_so_h_res_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL11_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell11Imbal                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell11_imbal_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL11_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell11Volt                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell11_volt_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL11_PARAM));
}

/* 
  * @Brief  : Updates signal Batt48VCell10SoC                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell10_so_c(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL10_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_so_c_encode(data);
		 if(powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_so_c_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell10_param.batt48_v_cell10_so_c = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell10_param_pack(fl_data,&batt48_v_cell10_param,(size_t)BATT48_V_CELL10_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL10_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell10DoD                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell10_do_d(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL10_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_do_d_encode(data);
		 if(powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_do_d_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell10_param.batt48_v_cell10_do_d = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell10_param_pack(fl_data,&batt48_v_cell10_param,(size_t)BATT48_V_CELL10_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL10_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell10BalStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell10_bal_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL10_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_bal_status_encode(data);
		 if(powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_bal_status_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell10_param.batt48_v_cell10_bal_status = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell10_param_pack(fl_data,&batt48_v_cell10_param,(size_t)BATT48_V_CELL10_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL10_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell10SoHCap                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell10_so_h_cap(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL10_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_so_h_cap_encode(data);
		 if(powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_so_h_cap_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell10_param.batt48_v_cell10_so_h_cap = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell10_param_pack(fl_data,&batt48_v_cell10_param,(size_t)BATT48_V_CELL10_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL10_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell10SoHRes                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell10_so_h_res(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL10_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_so_h_res_encode(data);
		 if(powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_so_h_res_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell10_param.batt48_v_cell10_so_h_res = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell10_param_pack(fl_data,&batt48_v_cell10_param,(size_t)BATT48_V_CELL10_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL10_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell10Imbal                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell10_imbal(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL10_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_imbal_encode(data);
		 if(powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_imbal_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell10_param.batt48_v_cell10_imbal = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell10_param_pack(fl_data,&batt48_v_cell10_param,(size_t)BATT48_V_CELL10_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL10_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell10Volt                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell10_volt(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL10_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_volt_encode(data);
		 if(powertraincanv04_batt48_v_cell10_param_batt48_v_cell10_volt_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell10_param.batt48_v_cell10_volt = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell10_param_pack(fl_data,&batt48_v_cell10_param,(size_t)BATT48_V_CELL10_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL10_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt48VCell10SoC                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell10_so_c_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL10_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell10DoD                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell10_do_d_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL10_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell10BalStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell10_bal_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL10_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell10SoHCap                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell10_so_h_cap_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL10_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell10SoHRes                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell10_so_h_res_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL10_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell10Imbal                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell10_imbal_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL10_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell10Volt                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell10_volt_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL10_PARAM));
}

/* 
  * @Brief  : Updates signal Batt48VCell9SoC                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell9_so_c(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL9_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_so_c_encode(data);
		 if(powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_so_c_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell9_param.batt48_v_cell9_so_c = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell9_param_pack(fl_data,&batt48_v_cell9_param,(size_t)BATT48_V_CELL9_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL9_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell9DoD                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell9_do_d(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL9_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_do_d_encode(data);
		 if(powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_do_d_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell9_param.batt48_v_cell9_do_d = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell9_param_pack(fl_data,&batt48_v_cell9_param,(size_t)BATT48_V_CELL9_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL9_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell9BalStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell9_bal_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL9_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_bal_status_encode(data);
		 if(powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_bal_status_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell9_param.batt48_v_cell9_bal_status = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell9_param_pack(fl_data,&batt48_v_cell9_param,(size_t)BATT48_V_CELL9_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL9_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell9SoHCap                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell9_so_h_cap(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL9_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_so_h_cap_encode(data);
		 if(powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_so_h_cap_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell9_param.batt48_v_cell9_so_h_cap = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell9_param_pack(fl_data,&batt48_v_cell9_param,(size_t)BATT48_V_CELL9_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL9_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell9SoHRes                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell9_so_h_res(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL9_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_so_h_res_encode(data);
		 if(powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_so_h_res_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell9_param.batt48_v_cell9_so_h_res = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell9_param_pack(fl_data,&batt48_v_cell9_param,(size_t)BATT48_V_CELL9_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL9_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell9Imbal                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell9_imbal(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL9_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_imbal_encode(data);
		 if(powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_imbal_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell9_param.batt48_v_cell9_imbal = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell9_param_pack(fl_data,&batt48_v_cell9_param,(size_t)BATT48_V_CELL9_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL9_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell9Volt                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell9_volt(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL9_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_volt_encode(data);
		 if(powertraincanv04_batt48_v_cell9_param_batt48_v_cell9_volt_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell9_param.batt48_v_cell9_volt = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell9_param_pack(fl_data,&batt48_v_cell9_param,(size_t)BATT48_V_CELL9_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL9_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt48VCell9SoC                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell9_so_c_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL9_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell9DoD                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell9_do_d_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL9_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell9BalStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell9_bal_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL9_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell9SoHCap                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell9_so_h_cap_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL9_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell9SoHRes                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell9_so_h_res_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL9_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell9Imbal                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell9_imbal_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL9_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell9Volt                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell9_volt_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL9_PARAM));
}

/* 
  * @Brief  : Updates signal Batt48VCell8SoC                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell8_so_c(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL8_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_so_c_encode(data);
		 if(powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_so_c_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell8_param.batt48_v_cell8_so_c = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell8_param_pack(fl_data,&batt48_v_cell8_param,(size_t)BATT48_V_CELL8_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL8_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell8DoD                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell8_do_d(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL8_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_do_d_encode(data);
		 if(powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_do_d_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell8_param.batt48_v_cell8_do_d = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell8_param_pack(fl_data,&batt48_v_cell8_param,(size_t)BATT48_V_CELL8_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL8_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell8BalStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell8_bal_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL8_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_bal_status_encode(data);
		 if(powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_bal_status_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell8_param.batt48_v_cell8_bal_status = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell8_param_pack(fl_data,&batt48_v_cell8_param,(size_t)BATT48_V_CELL8_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL8_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell8SoHCap                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell8_so_h_cap(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL8_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_so_h_cap_encode(data);
		 if(powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_so_h_cap_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell8_param.batt48_v_cell8_so_h_cap = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell8_param_pack(fl_data,&batt48_v_cell8_param,(size_t)BATT48_V_CELL8_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL8_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell8SoHRes                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell8_so_h_res(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL8_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_so_h_res_encode(data);
		 if(powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_so_h_res_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell8_param.batt48_v_cell8_so_h_res = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell8_param_pack(fl_data,&batt48_v_cell8_param,(size_t)BATT48_V_CELL8_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL8_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell8Imbal                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell8_imbal(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL8_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_imbal_encode(data);
		 if(powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_imbal_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell8_param.batt48_v_cell8_imbal = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell8_param_pack(fl_data,&batt48_v_cell8_param,(size_t)BATT48_V_CELL8_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL8_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell8Volt                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell8_volt(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL8_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_volt_encode(data);
		 if(powertraincanv04_batt48_v_cell8_param_batt48_v_cell8_volt_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell8_param.batt48_v_cell8_volt = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell8_param_pack(fl_data,&batt48_v_cell8_param,(size_t)BATT48_V_CELL8_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL8_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt48VCell8SoC                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell8_so_c_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL8_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell8DoD                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell8_do_d_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL8_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell8BalStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell8_bal_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL8_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell8SoHCap                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell8_so_h_cap_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL8_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell8SoHRes                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell8_so_h_res_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL8_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell8Imbal                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell8_imbal_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL8_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell8Volt                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell8_volt_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL8_PARAM));
}

/* 
  * @Brief  : Updates signal Batt48VCell7SoC                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell7_so_c(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL7_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_so_c_encode(data);
		 if(powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_so_c_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell7_param.batt48_v_cell7_so_c = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell7_param_pack(fl_data,&batt48_v_cell7_param,(size_t)BATT48_V_CELL7_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL7_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell7DoD                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell7_do_d(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL7_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_do_d_encode(data);
		 if(powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_do_d_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell7_param.batt48_v_cell7_do_d = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell7_param_pack(fl_data,&batt48_v_cell7_param,(size_t)BATT48_V_CELL7_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL7_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell7BalStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell7_bal_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL7_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_bal_status_encode(data);
		 if(powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_bal_status_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell7_param.batt48_v_cell7_bal_status = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell7_param_pack(fl_data,&batt48_v_cell7_param,(size_t)BATT48_V_CELL7_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL7_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell7SoHCap                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell7_so_h_cap(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL7_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_so_h_cap_encode(data);
		 if(powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_so_h_cap_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell7_param.batt48_v_cell7_so_h_cap = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell7_param_pack(fl_data,&batt48_v_cell7_param,(size_t)BATT48_V_CELL7_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL7_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell7SoHRes                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell7_so_h_res(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL7_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_so_h_res_encode(data);
		 if(powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_so_h_res_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell7_param.batt48_v_cell7_so_h_res = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell7_param_pack(fl_data,&batt48_v_cell7_param,(size_t)BATT48_V_CELL7_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL7_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell7Imbal                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell7_imbal(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL7_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_imbal_encode(data);
		 if(powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_imbal_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell7_param.batt48_v_cell7_imbal = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell7_param_pack(fl_data,&batt48_v_cell7_param,(size_t)BATT48_V_CELL7_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL7_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell7Volt                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell7_volt(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL7_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_volt_encode(data);
		 if(powertraincanv04_batt48_v_cell7_param_batt48_v_cell7_volt_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell7_param.batt48_v_cell7_volt = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell7_param_pack(fl_data,&batt48_v_cell7_param,(size_t)BATT48_V_CELL7_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL7_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt48VCell7SoC                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell7_so_c_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL7_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell7DoD                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell7_do_d_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL7_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell7BalStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell7_bal_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL7_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell7SoHCap                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell7_so_h_cap_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL7_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell7SoHRes                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell7_so_h_res_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL7_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell7Imbal                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell7_imbal_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL7_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell7Volt                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell7_volt_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL7_PARAM));
}

/* 
  * @Brief  : Updates signal Batt48VCell6SoC                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell6_so_c(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL6_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_so_c_encode(data);
		 if(powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_so_c_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell6_param.batt48_v_cell6_so_c = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell6_param_pack(fl_data,&batt48_v_cell6_param,(size_t)BATT48_V_CELL6_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL6_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell6DoD                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell6_do_d(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL6_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_do_d_encode(data);
		 if(powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_do_d_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell6_param.batt48_v_cell6_do_d = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell6_param_pack(fl_data,&batt48_v_cell6_param,(size_t)BATT48_V_CELL6_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL6_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell6BalStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell6_bal_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL6_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_bal_status_encode(data);
		 if(powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_bal_status_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell6_param.batt48_v_cell6_bal_status = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell6_param_pack(fl_data,&batt48_v_cell6_param,(size_t)BATT48_V_CELL6_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL6_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell6SoHCap                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell6_so_h_cap(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL6_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_so_h_cap_encode(data);
		 if(powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_so_h_cap_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell6_param.batt48_v_cell6_so_h_cap = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell6_param_pack(fl_data,&batt48_v_cell6_param,(size_t)BATT48_V_CELL6_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL6_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell6SoHRes                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell6_so_h_res(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL6_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_so_h_res_encode(data);
		 if(powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_so_h_res_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell6_param.batt48_v_cell6_so_h_res = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell6_param_pack(fl_data,&batt48_v_cell6_param,(size_t)BATT48_V_CELL6_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL6_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell6Imbal                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell6_imbal(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL6_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_imbal_encode(data);
		 if(powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_imbal_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell6_param.batt48_v_cell6_imbal = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell6_param_pack(fl_data,&batt48_v_cell6_param,(size_t)BATT48_V_CELL6_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL6_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell6Volt                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell6_volt(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL6_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_volt_encode(data);
		 if(powertraincanv04_batt48_v_cell6_param_batt48_v_cell6_volt_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell6_param.batt48_v_cell6_volt = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell6_param_pack(fl_data,&batt48_v_cell6_param,(size_t)BATT48_V_CELL6_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL6_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt48VCell6SoC                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell6_so_c_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL6_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell6DoD                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell6_do_d_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL6_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell6BalStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell6_bal_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL6_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell6SoHCap                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell6_so_h_cap_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL6_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell6SoHRes                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell6_so_h_res_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL6_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell6Imbal                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell6_imbal_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL6_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell6Volt                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell6_volt_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL6_PARAM));
}

/* 
  * @Brief  : Updates signal Batt48VCell5SoC                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell5_so_c(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL5_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_so_c_encode(data);
		 if(powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_so_c_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell5_param.batt48_v_cell5_so_c = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell5_param_pack(fl_data,&batt48_v_cell5_param,(size_t)BATT48_V_CELL5_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL5_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell5DoD                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell5_do_d(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL5_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_do_d_encode(data);
		 if(powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_do_d_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell5_param.batt48_v_cell5_do_d = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell5_param_pack(fl_data,&batt48_v_cell5_param,(size_t)BATT48_V_CELL5_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL5_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell5BalStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell5_bal_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL5_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_bal_status_encode(data);
		 if(powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_bal_status_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell5_param.batt48_v_cell5_bal_status = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell5_param_pack(fl_data,&batt48_v_cell5_param,(size_t)BATT48_V_CELL5_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL5_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell5SoHCap                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell5_so_h_cap(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL5_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_so_h_cap_encode(data);
		 if(powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_so_h_cap_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell5_param.batt48_v_cell5_so_h_cap = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell5_param_pack(fl_data,&batt48_v_cell5_param,(size_t)BATT48_V_CELL5_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL5_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell5SoHRes                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell5_so_h_res(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL5_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_so_h_res_encode(data);
		 if(powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_so_h_res_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell5_param.batt48_v_cell5_so_h_res = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell5_param_pack(fl_data,&batt48_v_cell5_param,(size_t)BATT48_V_CELL5_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL5_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell5Imbal                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell5_imbal(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL5_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_imbal_encode(data);
		 if(powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_imbal_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell5_param.batt48_v_cell5_imbal = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell5_param_pack(fl_data,&batt48_v_cell5_param,(size_t)BATT48_V_CELL5_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL5_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell5Volt                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell5_volt(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL5_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_volt_encode(data);
		 if(powertraincanv04_batt48_v_cell5_param_batt48_v_cell5_volt_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell5_param.batt48_v_cell5_volt = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell5_param_pack(fl_data,&batt48_v_cell5_param,(size_t)BATT48_V_CELL5_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL5_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt48VCell5SoC                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell5_so_c_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL5_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell5DoD                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell5_do_d_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL5_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell5BalStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell5_bal_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL5_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell5SoHCap                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell5_so_h_cap_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL5_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell5SoHRes                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell5_so_h_res_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL5_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell5Imbal                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell5_imbal_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL5_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell5Volt                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell5_volt_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL5_PARAM));
}

/* 
  * @Brief  : Updates signal Batt48VCell4SoC                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell4_so_c(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL4_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_so_c_encode(data);
		 if(powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_so_c_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell4_param.batt48_v_cell4_so_c = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell4_param_pack(fl_data,&batt48_v_cell4_param,(size_t)BATT48_V_CELL4_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL4_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell4DoD                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell4_do_d(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL4_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_do_d_encode(data);
		 if(powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_do_d_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell4_param.batt48_v_cell4_do_d = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell4_param_pack(fl_data,&batt48_v_cell4_param,(size_t)BATT48_V_CELL4_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL4_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell4BalStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell4_bal_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL4_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_bal_status_encode(data);
		 if(powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_bal_status_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell4_param.batt48_v_cell4_bal_status = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell4_param_pack(fl_data,&batt48_v_cell4_param,(size_t)BATT48_V_CELL4_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL4_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell4SoHCap                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell4_so_h_cap(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL4_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_so_h_cap_encode(data);
		 if(powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_so_h_cap_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell4_param.batt48_v_cell4_so_h_cap = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell4_param_pack(fl_data,&batt48_v_cell4_param,(size_t)BATT48_V_CELL4_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL4_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell4SoHRes                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell4_so_h_res(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL4_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_so_h_res_encode(data);
		 if(powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_so_h_res_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell4_param.batt48_v_cell4_so_h_res = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell4_param_pack(fl_data,&batt48_v_cell4_param,(size_t)BATT48_V_CELL4_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL4_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell4Imbal                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell4_imbal(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL4_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_imbal_encode(data);
		 if(powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_imbal_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell4_param.batt48_v_cell4_imbal = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell4_param_pack(fl_data,&batt48_v_cell4_param,(size_t)BATT48_V_CELL4_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL4_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell4Volt                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell4_volt(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL4_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_volt_encode(data);
		 if(powertraincanv04_batt48_v_cell4_param_batt48_v_cell4_volt_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell4_param.batt48_v_cell4_volt = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell4_param_pack(fl_data,&batt48_v_cell4_param,(size_t)BATT48_V_CELL4_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL4_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt48VCell4SoC                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell4_so_c_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL4_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell4DoD                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell4_do_d_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL4_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell4BalStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell4_bal_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL4_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell4SoHCap                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell4_so_h_cap_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL4_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell4SoHRes                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell4_so_h_res_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL4_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell4Imbal                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell4_imbal_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL4_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell4Volt                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell4_volt_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL4_PARAM));
}

/* 
  * @Brief  : Updates signal Batt48VCell13SoC                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell13_so_c(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL3_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_so_c_encode(data);
		 if(powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_so_c_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell3_param.batt48_v_cell13_so_c = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell3_param_pack(fl_data,&batt48_v_cell3_param,(size_t)BATT48_V_CELL3_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL3_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell13DoD                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell13_do_d(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL3_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_do_d_encode(data);
		 if(powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_do_d_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell3_param.batt48_v_cell13_do_d = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell3_param_pack(fl_data,&batt48_v_cell3_param,(size_t)BATT48_V_CELL3_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL3_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell13BalStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell13_bal_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL3_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_bal_status_encode(data);
		 if(powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_bal_status_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell3_param.batt48_v_cell13_bal_status = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell3_param_pack(fl_data,&batt48_v_cell3_param,(size_t)BATT48_V_CELL3_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL3_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell13SoHCap                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell13_so_h_cap(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL3_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_so_h_cap_encode(data);
		 if(powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_so_h_cap_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell3_param.batt48_v_cell13_so_h_cap = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell3_param_pack(fl_data,&batt48_v_cell3_param,(size_t)BATT48_V_CELL3_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL3_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell13SoHRes                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell13_so_h_res(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL3_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_so_h_res_encode(data);
		 if(powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_so_h_res_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell3_param.batt48_v_cell13_so_h_res = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell3_param_pack(fl_data,&batt48_v_cell3_param,(size_t)BATT48_V_CELL3_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL3_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell13Imbal                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell13_imbal(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL3_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_imbal_encode(data);
		 if(powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_imbal_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell3_param.batt48_v_cell13_imbal = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell3_param_pack(fl_data,&batt48_v_cell3_param,(size_t)BATT48_V_CELL3_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL3_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell13Volt                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell13_volt(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL3_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_volt_encode(data);
		 if(powertraincanv04_batt48_v_cell3_param_batt48_v_cell13_volt_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell3_param.batt48_v_cell13_volt = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell3_param_pack(fl_data,&batt48_v_cell3_param,(size_t)BATT48_V_CELL3_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL3_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt48VCell13SoC                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell13_so_c_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL3_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell13DoD                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell13_do_d_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL3_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell13BalStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell13_bal_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL3_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell13SoHCap                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell13_so_h_cap_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL3_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell13SoHRes                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell13_so_h_res_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL3_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell13Imbal                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell13_imbal_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL3_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell13Volt                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell13_volt_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL3_PARAM));
}

/* 
  * @Brief  : Updates signal Batt48VCell2SoC                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell2_so_c(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL2_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_so_c_encode(data);
		 if(powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_so_c_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell2_param.batt48_v_cell2_so_c = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell2_param_pack(fl_data,&batt48_v_cell2_param,(size_t)BATT48_V_CELL2_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL2_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell2DoD                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell2_do_d(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL2_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_do_d_encode(data);
		 if(powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_do_d_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell2_param.batt48_v_cell2_do_d = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell2_param_pack(fl_data,&batt48_v_cell2_param,(size_t)BATT48_V_CELL2_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL2_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell2BalStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell2_bal_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL2_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_bal_status_encode(data);
		 if(powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_bal_status_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell2_param.batt48_v_cell2_bal_status = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell2_param_pack(fl_data,&batt48_v_cell2_param,(size_t)BATT48_V_CELL2_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL2_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell2SoHCap                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell2_so_h_cap(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL2_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_so_h_cap_encode(data);
		 if(powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_so_h_cap_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell2_param.batt48_v_cell2_so_h_cap = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell2_param_pack(fl_data,&batt48_v_cell2_param,(size_t)BATT48_V_CELL2_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL2_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell2SoHRes                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell2_so_h_res(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL2_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_so_h_res_encode(data);
		 if(powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_so_h_res_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell2_param.batt48_v_cell2_so_h_res = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell2_param_pack(fl_data,&batt48_v_cell2_param,(size_t)BATT48_V_CELL2_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL2_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell2Imbal                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell2_imbal(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL2_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_imbal_encode(data);
		 if(powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_imbal_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell2_param.batt48_v_cell2_imbal = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell2_param_pack(fl_data,&batt48_v_cell2_param,(size_t)BATT48_V_CELL2_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL2_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell2Volt                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell2_volt(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL2_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_volt_encode(data);
		 if(powertraincanv04_batt48_v_cell2_param_batt48_v_cell2_volt_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell2_param.batt48_v_cell2_volt = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell2_param_pack(fl_data,&batt48_v_cell2_param,(size_t)BATT48_V_CELL2_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL2_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt48VCell2SoC                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell2_so_c_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL2_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell2DoD                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell2_do_d_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL2_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell2BalStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell2_bal_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL2_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell2SoHCap                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell2_so_h_cap_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL2_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell2SoHRes                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell2_so_h_res_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL2_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell2Imbal                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell2_imbal_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL2_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell2Volt                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell2_volt_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL2_PARAM));
}

/* 
  * @Brief  : Updates signal Batt48VCell1SoC                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell1_so_c(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL1_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_so_c_encode(data);
		 if(powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_so_c_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell1_param.batt48_v_cell1_so_c = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell1_param_pack(fl_data,&batt48_v_cell1_param,(size_t)BATT48_V_CELL1_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL1_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell1DoD                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell1_do_d(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL1_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_do_d_encode(data);
		 if(powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_do_d_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell1_param.batt48_v_cell1_do_d = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell1_param_pack(fl_data,&batt48_v_cell1_param,(size_t)BATT48_V_CELL1_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL1_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell1BalStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell1_bal_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL1_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_bal_status_encode(data);
		 if(powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_bal_status_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell1_param.batt48_v_cell1_bal_status = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell1_param_pack(fl_data,&batt48_v_cell1_param,(size_t)BATT48_V_CELL1_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL1_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell1SoHCap                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell1_so_h_cap(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL1_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_so_h_cap_encode(data);
		 if(powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_so_h_cap_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell1_param.batt48_v_cell1_so_h_cap = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell1_param_pack(fl_data,&batt48_v_cell1_param,(size_t)BATT48_V_CELL1_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL1_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell1SoHRes                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell1_so_h_res(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL1_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_so_h_res_encode(data);
		 if(powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_so_h_res_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell1_param.batt48_v_cell1_so_h_res = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell1_param_pack(fl_data,&batt48_v_cell1_param,(size_t)BATT48_V_CELL1_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL1_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell1Imbal                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell1_imbal(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL1_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_imbal_encode(data);
		 if(powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_imbal_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell1_param.batt48_v_cell1_imbal = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell1_param_pack(fl_data,&batt48_v_cell1_param,(size_t)BATT48_V_CELL1_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL1_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VCell1Volt                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cell1_volt(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_CELL1_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_volt_encode(data);
		 if(powertraincanv04_batt48_v_cell1_param_batt48_v_cell1_volt_is_in_range(fl_encoded_data))
		 {
				 batt48_v_cell1_param.batt48_v_cell1_volt = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_cell1_param_pack(fl_data,&batt48_v_cell1_param,(size_t)BATT48_V_CELL1_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_CELL1_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt48VCell1SoC                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell1_so_c_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL1_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell1DoD                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell1_do_d_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL1_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell1BalStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell1_bal_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL1_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell1SoHCap                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell1_so_h_cap_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL1_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell1SoHRes                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell1_so_h_res_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL1_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell1Imbal                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell1_imbal_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL1_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VCell1Volt                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cell1_volt_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_CELL1_PARAM));
}

/* 
  * @Brief  : Updates signal Batt48VCurrMeas                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_curr_meas(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_info_batt48_v_curr_meas_encode(data);
		 if(powertraincanv04_batt48_v_info_batt48_v_curr_meas_is_in_range(fl_encoded_data))
		 {
				 batt48_v_info.batt48_v_curr_meas = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_info_pack(fl_data,&batt48_v_info,(size_t)BATT48_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VTempAvrg                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_temp_avrg(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_info_batt48_v_temp_avrg_encode(data);
		 if(powertraincanv04_batt48_v_info_batt48_v_temp_avrg_is_in_range(fl_encoded_data))
		 {
				 batt48_v_info.batt48_v_temp_avrg = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_info_pack(fl_data,&batt48_v_info,(size_t)BATT48_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VTempMax                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_temp_max(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_info_batt48_v_temp_max_encode(data);
		 if(powertraincanv04_batt48_v_info_batt48_v_temp_max_is_in_range(fl_encoded_data))
		 {
				 batt48_v_info.batt48_v_temp_max = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_info_pack(fl_data,&batt48_v_info,(size_t)BATT48_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VTempMin                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_temp_min(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_info_batt48_v_temp_min_encode(data);
		 if(powertraincanv04_batt48_v_info_batt48_v_temp_min_is_in_range(fl_encoded_data))
		 {
				 batt48_v_info.batt48_v_temp_min = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_info_pack(fl_data,&batt48_v_info,(size_t)BATT48_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VEstimated                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_estimated(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_info_batt48_v_estimated_encode(data);
		 if(powertraincanv04_batt48_v_info_batt48_v_estimated_is_in_range(fl_encoded_data))
		 {
				 batt48_v_info.batt48_v_estimated = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_info_pack(fl_data,&batt48_v_info,(size_t)BATT48_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VSoC                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_so_c(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_info_batt48_v_so_c_encode(data);
		 if(powertraincanv04_batt48_v_info_batt48_v_so_c_is_in_range(fl_encoded_data))
		 {
				 batt48_v_info.batt48_v_so_c = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_info_pack(fl_data,&batt48_v_info,(size_t)BATT48_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt48VCurrMeas                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_curr_meas_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_INFO));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VTempAvrg                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_temp_avrg_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_INFO));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VTempMax                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_temp_max_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_INFO));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VTempMin                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_temp_min_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_INFO));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VEstimated                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_estimated_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_INFO));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VSoC                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_so_c_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_INFO));
}

/* 
  * @Brief  : Updates signal Batt12VCurrMeas                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_curr_meas(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_info_batt12_v_curr_meas_encode(data);
		 if(powertraincanv04_batt12_v_info_batt12_v_curr_meas_is_in_range(fl_encoded_data))
		 {
				 batt12_v_info.batt12_v_curr_meas = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_info_pack(fl_data,&batt12_v_info,(size_t)BATT12_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VTempAvrg                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_temp_avrg(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_info_batt12_v_temp_avrg_encode(data);
		 if(powertraincanv04_batt12_v_info_batt12_v_temp_avrg_is_in_range(fl_encoded_data))
		 {
				 batt12_v_info.batt12_v_temp_avrg = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_info_pack(fl_data,&batt12_v_info,(size_t)BATT12_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VTempMax                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_temp_max(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_info_batt12_v_temp_max_encode(data);
		 if(powertraincanv04_batt12_v_info_batt12_v_temp_max_is_in_range(fl_encoded_data))
		 {
				 batt12_v_info.batt12_v_temp_max = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_info_pack(fl_data,&batt12_v_info,(size_t)BATT12_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VEstimated                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_estimated(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_info_batt12_v_estimated_encode(data);
		 if(powertraincanv04_batt12_v_info_batt12_v_estimated_is_in_range(fl_encoded_data))
		 {
				 batt12_v_info.batt12_v_estimated = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_info_pack(fl_data,&batt12_v_info,(size_t)BATT12_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VSoC                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_so_c(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_info_batt12_v_so_c_encode(data);
		 if(powertraincanv04_batt12_v_info_batt12_v_so_c_is_in_range(fl_encoded_data))
		 {
				 batt12_v_info.batt12_v_so_c = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_info_pack(fl_data,&batt12_v_info,(size_t)BATT12_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VTempMin                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_temp_min(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_info_batt12_v_temp_min_encode(data);
		 if(powertraincanv04_batt12_v_info_batt12_v_temp_min_is_in_range(fl_encoded_data))
		 {
				 batt12_v_info.batt12_v_temp_min = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_info_pack(fl_data,&batt12_v_info,(size_t)BATT12_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt12VCurrMeas                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_curr_meas_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_INFO));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VTempAvrg                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_temp_avrg_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_INFO));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VTempMax                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_temp_max_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_INFO));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VEstimated                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_estimated_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_INFO));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VSoC                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_so_c_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_INFO));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VTempMin                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_temp_min_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_INFO));
}

/* 
  * @Brief  : Updates signal PMUShutdownOK                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_pmu_shutdown_ok(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[PMU_STATUS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_pmu_status_pmu_shutdown_ok_encode(data);
		 if(powertraincanv04_pmu_status_pmu_shutdown_ok_is_in_range(fl_encoded_data))
		 {
				 pmu_status.pmu_shutdown_ok = fl_encoded_data;
				 (void)powertraincanv04_pmu_status_pack(fl_data,&pmu_status,(size_t)PMU_STATUS_LENGTH);
				 ret = CanMgr_SendSignal( PMU_STATUS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal ISGVoltSetpoint                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_isg_volt_setpoint(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[PMU_STATUS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_pmu_status_isg_volt_setpoint_encode(data);
		 if(powertraincanv04_pmu_status_isg_volt_setpoint_is_in_range(fl_encoded_data))
		 {
				 pmu_status.isg_volt_setpoint = fl_encoded_data;
				 (void)powertraincanv04_pmu_status_pack(fl_data,&pmu_status,(size_t)PMU_STATUS_LENGTH);
				 ret = CanMgr_SendSignal( PMU_STATUS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal PMUCrankInhibit                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_pmu_crank_inhibit(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[PMU_STATUS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_pmu_status_pmu_crank_inhibit_encode(data);
		 if(powertraincanv04_pmu_status_pmu_crank_inhibit_is_in_range(fl_encoded_data))
		 {
				 pmu_status.pmu_crank_inhibit = fl_encoded_data;
				 (void)powertraincanv04_pmu_status_pack(fl_data,&pmu_status,(size_t)PMU_STATUS_LENGTH);
				 ret = CanMgr_SendSignal( PMU_STATUS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal ISGVoltMax                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_isg_volt_max(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[PMU_STATUS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_pmu_status_isg_volt_max_encode(data);
		 if(powertraincanv04_pmu_status_isg_volt_max_is_in_range(fl_encoded_data))
		 {
				 pmu_status.isg_volt_max = fl_encoded_data;
				 (void)powertraincanv04_pmu_status_pack(fl_data,&pmu_status,(size_t)PMU_STATUS_LENGTH);
				 ret = CanMgr_SendSignal( PMU_STATUS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal ISGVoltMin                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_isg_volt_min(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[PMU_STATUS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_pmu_status_isg_volt_min_encode(data);
		 if(powertraincanv04_pmu_status_isg_volt_min_is_in_range(fl_encoded_data))
		 {
				 pmu_status.isg_volt_min = fl_encoded_data;
				 (void)powertraincanv04_pmu_status_pack(fl_data,&pmu_status,(size_t)PMU_STATUS_LENGTH);
				 ret = CanMgr_SendSignal( PMU_STATUS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal PMUState                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_pmu_state(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[PMU_STATUS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_pmu_status_pmu_state_encode(data);
		 if(powertraincanv04_pmu_status_pmu_state_is_in_range(fl_encoded_data))
		 {
				 pmu_status.pmu_state = fl_encoded_data;
				 (void)powertraincanv04_pmu_status_pack(fl_data,&pmu_status,(size_t)PMU_STATUS_LENGTH);
				 ret = CanMgr_SendSignal( PMU_STATUS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of PMUShutdownOK                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_pmu_shutdown_ok_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(PMU_STATUS));
}

/* 
  * @Brief  : Returns the transmission status of ISGVoltSetpoint                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_isg_volt_setpoint_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(PMU_STATUS));
}

/* 
  * @Brief  : Returns the transmission status of PMUCrankInhibit                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_pmu_crank_inhibit_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(PMU_STATUS));
}

/* 
  * @Brief  : Returns the transmission status of ISGVoltMax                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_isg_volt_max_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(PMU_STATUS));
}

/* 
  * @Brief  : Returns the transmission status of ISGVoltMin                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_isg_volt_min_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(PMU_STATUS));
}

/* 
  * @Brief  : Returns the transmission status of PMUState                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_pmu_state_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(PMU_STATUS));
}

/* 
  * @Brief  : Updates signal Batt48VTempMeas1                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_temp_meas1(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_TEMPS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_temps_batt48_v_temp_meas1_encode(data);
		 if(powertraincanv04_batt48_v_temps_batt48_v_temp_meas1_is_in_range(fl_encoded_data))
		 {
				 batt48_v_temps.batt48_v_temp_meas1 = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_temps_pack(fl_data,&batt48_v_temps,(size_t)BATT48_V_TEMPS_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_TEMPS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VTempMeas2                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_temp_meas2(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_TEMPS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_temps_batt48_v_temp_meas2_encode(data);
		 if(powertraincanv04_batt48_v_temps_batt48_v_temp_meas2_is_in_range(fl_encoded_data))
		 {
				 batt48_v_temps.batt48_v_temp_meas2 = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_temps_pack(fl_data,&batt48_v_temps,(size_t)BATT48_V_TEMPS_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_TEMPS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VTempMeas3                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_temp_meas3(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_TEMPS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_temps_batt48_v_temp_meas3_encode(data);
		 if(powertraincanv04_batt48_v_temps_batt48_v_temp_meas3_is_in_range(fl_encoded_data))
		 {
				 batt48_v_temps.batt48_v_temp_meas3 = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_temps_pack(fl_data,&batt48_v_temps,(size_t)BATT48_V_TEMPS_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_TEMPS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VTempMeas4                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_temp_meas4(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_TEMPS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_temps_batt48_v_temp_meas4_encode(data);
		 if(powertraincanv04_batt48_v_temps_batt48_v_temp_meas4_is_in_range(fl_encoded_data))
		 {
				 batt48_v_temps.batt48_v_temp_meas4 = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_temps_pack(fl_data,&batt48_v_temps,(size_t)BATT48_V_TEMPS_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_TEMPS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VTempMeas5                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_temp_meas5(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_TEMPS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_temps_batt48_v_temp_meas5_encode(data);
		 if(powertraincanv04_batt48_v_temps_batt48_v_temp_meas5_is_in_range(fl_encoded_data))
		 {
				 batt48_v_temps.batt48_v_temp_meas5 = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_temps_pack(fl_data,&batt48_v_temps,(size_t)BATT48_V_TEMPS_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_TEMPS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VTempMeas6                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_temp_meas6(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_TEMPS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_temps_batt48_v_temp_meas6_encode(data);
		 if(powertraincanv04_batt48_v_temps_batt48_v_temp_meas6_is_in_range(fl_encoded_data))
		 {
				 batt48_v_temps.batt48_v_temp_meas6 = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_temps_pack(fl_data,&batt48_v_temps,(size_t)BATT48_V_TEMPS_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_TEMPS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VTempMeas7                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_temp_meas7(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT48_V_TEMPS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt48_v_temps_batt48_v_temp_meas7_encode(data);
		 if(powertraincanv04_batt48_v_temps_batt48_v_temp_meas7_is_in_range(fl_encoded_data))
		 {
				 batt48_v_temps.batt48_v_temp_meas7 = fl_encoded_data;
				 (void)powertraincanv04_batt48_v_temps_pack(fl_data,&batt48_v_temps,(size_t)BATT48_V_TEMPS_LENGTH);
				 ret = CanMgr_SendSignal( BATT48_V_TEMPS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt48VTempMeas1                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_temp_meas1_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_TEMPS));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VTempMeas2                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_temp_meas2_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_TEMPS));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VTempMeas3                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_temp_meas3_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_TEMPS));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VTempMeas4                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_temp_meas4_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_TEMPS));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VTempMeas5                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_temp_meas5_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_TEMPS));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VTempMeas6                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_temp_meas6_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_TEMPS));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VTempMeas7                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_temp_meas7_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT48_V_TEMPS));
}

/* 
  * @Brief  : Updates signal Batt12VMax                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_max(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT_LIMITS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt_limits_batt12_v_max_encode(data);
		 if(powertraincanv04_batt_limits_batt12_v_max_is_in_range(fl_encoded_data))
		 {
				 batt_limits.batt12_v_max = fl_encoded_data;
				 (void)powertraincanv04_batt_limits_pack(fl_data,&batt_limits,(size_t)BATT_LIMITS_LENGTH);
				 ret = CanMgr_SendSignal( BATT_LIMITS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VMaxChrgCurr                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_max_chrg_curr(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT_LIMITS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt_limits_batt12_v_max_chrg_curr_encode(data);
		 if(powertraincanv04_batt_limits_batt12_v_max_chrg_curr_is_in_range(fl_encoded_data))
		 {
				 batt_limits.batt12_v_max_chrg_curr = fl_encoded_data;
				 (void)powertraincanv04_batt_limits_pack(fl_data,&batt_limits,(size_t)BATT_LIMITS_LENGTH);
				 ret = CanMgr_SendSignal( BATT_LIMITS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VMaxDischrgCurr                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_max_dischrg_curr(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT_LIMITS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt_limits_batt12_v_max_dischrg_curr_encode(data);
		 if(powertraincanv04_batt_limits_batt12_v_max_dischrg_curr_is_in_range(fl_encoded_data))
		 {
				 batt_limits.batt12_v_max_dischrg_curr = fl_encoded_data;
				 (void)powertraincanv04_batt_limits_pack(fl_data,&batt_limits,(size_t)BATT_LIMITS_LENGTH);
				 ret = CanMgr_SendSignal( BATT_LIMITS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VMin                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_min(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT_LIMITS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt_limits_batt12_v_min_encode(data);
		 if(powertraincanv04_batt_limits_batt12_v_min_is_in_range(fl_encoded_data))
		 {
				 batt_limits.batt12_v_min = fl_encoded_data;
				 (void)powertraincanv04_batt_limits_pack(fl_data,&batt_limits,(size_t)BATT_LIMITS_LENGTH);
				 ret = CanMgr_SendSignal( BATT_LIMITS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VMaxChrgCurr                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_max_chrg_curr(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT_LIMITS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt_limits_batt48_v_max_chrg_curr_encode(data);
		 if(powertraincanv04_batt_limits_batt48_v_max_chrg_curr_is_in_range(fl_encoded_data))
		 {
				 batt_limits.batt48_v_max_chrg_curr = fl_encoded_data;
				 (void)powertraincanv04_batt_limits_pack(fl_data,&batt_limits,(size_t)BATT_LIMITS_LENGTH);
				 ret = CanMgr_SendSignal( BATT_LIMITS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VMaxDischrgCurr                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_max_dischrg_curr(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT_LIMITS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt_limits_batt48_v_max_dischrg_curr_encode(data);
		 if(powertraincanv04_batt_limits_batt48_v_max_dischrg_curr_is_in_range(fl_encoded_data))
		 {
				 batt_limits.batt48_v_max_dischrg_curr = fl_encoded_data;
				 (void)powertraincanv04_batt_limits_pack(fl_data,&batt_limits,(size_t)BATT_LIMITS_LENGTH);
				 ret = CanMgr_SendSignal( BATT_LIMITS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt12VMax                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_max_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT_LIMITS));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VMaxChrgCurr                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_max_chrg_curr_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT_LIMITS));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VMaxDischrgCurr                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_max_dischrg_curr_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT_LIMITS));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VMin                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_min_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT_LIMITS));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VMaxChrgCurr                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_max_chrg_curr_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT_LIMITS));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VMaxDischrgCurr                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_max_dischrg_curr_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT_LIMITS));
}

/* 
  * @Brief  : Updates signal DCDC48VCurrMeas                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_dcdc48_v_curr_meas(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[DCDC48_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_dcdc48_v_info_dcdc48_v_curr_meas_encode(data);
		 if(powertraincanv04_dcdc48_v_info_dcdc48_v_curr_meas_is_in_range(fl_encoded_data))
		 {
				 dcdc48_v_info.dcdc48_v_curr_meas = fl_encoded_data;
				 (void)powertraincanv04_dcdc48_v_info_pack(fl_data,&dcdc48_v_info,(size_t)DCDC48_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( DCDC48_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal DCDC48VSwitchReq                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_dcdc48_v_switch_req(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[DCDC48_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_dcdc48_v_info_dcdc48_v_switch_req_encode(data);
		 if(powertraincanv04_dcdc48_v_info_dcdc48_v_switch_req_is_in_range(fl_encoded_data))
		 {
				 dcdc48_v_info.dcdc48_v_switch_req = fl_encoded_data;
				 (void)powertraincanv04_dcdc48_v_info_pack(fl_data,&dcdc48_v_info,(size_t)DCDC48_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( DCDC48_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal DCDC48VSwitchStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_dcdc48_v_switch_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[DCDC48_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_dcdc48_v_info_dcdc48_v_switch_status_encode(data);
		 if(powertraincanv04_dcdc48_v_info_dcdc48_v_switch_status_is_in_range(fl_encoded_data))
		 {
				 dcdc48_v_info.dcdc48_v_switch_status = fl_encoded_data;
				 (void)powertraincanv04_dcdc48_v_info_pack(fl_data,&dcdc48_v_info,(size_t)DCDC48_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( DCDC48_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt48VContStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt48_v_cont_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[DCDC48_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_dcdc48_v_info_batt48_v_cont_status_encode(data);
		 if(powertraincanv04_dcdc48_v_info_batt48_v_cont_status_is_in_range(fl_encoded_data))
		 {
				 dcdc48_v_info.batt48_v_cont_status = fl_encoded_data;
				 (void)powertraincanv04_dcdc48_v_info_pack(fl_data,&dcdc48_v_info,(size_t)DCDC48_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( DCDC48_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal DCDC48VoltMeas                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_dcdc48_volt_meas(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[DCDC48_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_dcdc48_v_info_dcdc48_volt_meas_encode(data);
		 if(powertraincanv04_dcdc48_v_info_dcdc48_volt_meas_is_in_range(fl_encoded_data))
		 {
				 dcdc48_v_info.dcdc48_volt_meas = fl_encoded_data;
				 (void)powertraincanv04_dcdc48_v_info_pack(fl_data,&dcdc48_v_info,(size_t)DCDC48_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( DCDC48_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal DCDC48VoltSetpoint                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_dcdc48_volt_setpoint(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[DCDC48_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_dcdc48_v_info_dcdc48_volt_setpoint_encode(data);
		 if(powertraincanv04_dcdc48_v_info_dcdc48_volt_setpoint_is_in_range(fl_encoded_data))
		 {
				 dcdc48_v_info.dcdc48_volt_setpoint = fl_encoded_data;
				 (void)powertraincanv04_dcdc48_v_info_pack(fl_data,&dcdc48_v_info,(size_t)DCDC48_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( DCDC48_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of DCDC48VCurrMeas                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_dcdc48_v_curr_meas_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(DCDC48_V_INFO));
}

/* 
  * @Brief  : Returns the transmission status of DCDC48VSwitchReq                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_dcdc48_v_switch_req_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(DCDC48_V_INFO));
}

/* 
  * @Brief  : Returns the transmission status of DCDC48VSwitchStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_dcdc48_v_switch_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(DCDC48_V_INFO));
}

/* 
  * @Brief  : Returns the transmission status of Batt48VContStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt48_v_cont_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(DCDC48_V_INFO));
}

/* 
  * @Brief  : Returns the transmission status of DCDC48VoltMeas                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_dcdc48_volt_meas_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(DCDC48_V_INFO));
}

/* 
  * @Brief  : Returns the transmission status of DCDC48VoltSetpoint                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_dcdc48_volt_setpoint_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(DCDC48_V_INFO));
}

/* 
  * @Brief  : Updates signal DCDC12VCurrMeas                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_dcdc12_v_curr_meas(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[DCDC12_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_dcdc12_v_info_dcdc12_v_curr_meas_encode(data);
		 if(powertraincanv04_dcdc12_v_info_dcdc12_v_curr_meas_is_in_range(fl_encoded_data))
		 {
				 dcdc12_v_info.dcdc12_v_curr_meas = fl_encoded_data;
				 (void)powertraincanv04_dcdc12_v_info_pack(fl_data,&dcdc12_v_info,(size_t)DCDC12_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( DCDC12_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal DCDCStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_dcdc_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[DCDC12_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_dcdc12_v_info_dcdc_status_encode(data);
		 if(powertraincanv04_dcdc12_v_info_dcdc_status_is_in_range(fl_encoded_data))
		 {
				 dcdc12_v_info.dcdc_status = fl_encoded_data;
				 (void)powertraincanv04_dcdc12_v_info_pack(fl_data,&dcdc12_v_info,(size_t)DCDC12_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( DCDC12_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal DCDC12VSwitchStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_dcdc12_v_switch_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[DCDC12_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_dcdc12_v_info_dcdc12_v_switch_status_encode(data);
		 if(powertraincanv04_dcdc12_v_info_dcdc12_v_switch_status_is_in_range(fl_encoded_data))
		 {
				 dcdc12_v_info.dcdc12_v_switch_status = fl_encoded_data;
				 (void)powertraincanv04_dcdc12_v_info_pack(fl_data,&dcdc12_v_info,(size_t)DCDC12_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( DCDC12_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal DCDC12VoltMeas                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_dcdc12_volt_meas(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[DCDC12_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_dcdc12_v_info_dcdc12_volt_meas_encode(data);
		 if(powertraincanv04_dcdc12_v_info_dcdc12_volt_meas_is_in_range(fl_encoded_data))
		 {
				 dcdc12_v_info.dcdc12_volt_meas = fl_encoded_data;
				 (void)powertraincanv04_dcdc12_v_info_pack(fl_data,&dcdc12_v_info,(size_t)DCDC12_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( DCDC12_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal DCDC12VoltSetpoint                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_dcdc12_volt_setpoint(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[DCDC12_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_dcdc12_v_info_dcdc12_volt_setpoint_encode(data);
		 if(powertraincanv04_dcdc12_v_info_dcdc12_volt_setpoint_is_in_range(fl_encoded_data))
		 {
				 dcdc12_v_info.dcdc12_volt_setpoint = fl_encoded_data;
				 (void)powertraincanv04_dcdc12_v_info_pack(fl_data,&dcdc12_v_info,(size_t)DCDC12_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( DCDC12_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VContStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cont_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[DCDC12_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_dcdc12_v_info_batt12_v_cont_status_encode(data);
		 if(powertraincanv04_dcdc12_v_info_batt12_v_cont_status_is_in_range(fl_encoded_data))
		 {
				 dcdc12_v_info.batt12_v_cont_status = fl_encoded_data;
				 (void)powertraincanv04_dcdc12_v_info_pack(fl_data,&dcdc12_v_info,(size_t)DCDC12_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( DCDC12_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal DCDC12VSwitchReq                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_dcdc12_v_switch_req(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[DCDC12_V_INFO_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_dcdc12_v_info_dcdc12_v_switch_req_encode(data);
		 if(powertraincanv04_dcdc12_v_info_dcdc12_v_switch_req_is_in_range(fl_encoded_data))
		 {
				 dcdc12_v_info.dcdc12_v_switch_req = fl_encoded_data;
				 (void)powertraincanv04_dcdc12_v_info_pack(fl_data,&dcdc12_v_info,(size_t)DCDC12_V_INFO_LENGTH);
				 ret = CanMgr_SendSignal( DCDC12_V_INFO,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of DCDC12VCurrMeas                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_dcdc12_v_curr_meas_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(DCDC12_V_INFO));
}

/* 
  * @Brief  : Returns the transmission status of DCDCStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_dcdc_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(DCDC12_V_INFO));
}

/* 
  * @Brief  : Returns the transmission status of DCDC12VSwitchStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_dcdc12_v_switch_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(DCDC12_V_INFO));
}

/* 
  * @Brief  : Returns the transmission status of DCDC12VoltMeas                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_dcdc12_volt_meas_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(DCDC12_V_INFO));
}

/* 
  * @Brief  : Returns the transmission status of DCDC12VoltSetpoint                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_dcdc12_volt_setpoint_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(DCDC12_V_INFO));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VContStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cont_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(DCDC12_V_INFO));
}

/* 
  * @Brief  : Returns the transmission status of DCDC12VSwitchReq                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_dcdc12_v_switch_req_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(DCDC12_V_INFO));
}

/* 
  * @Brief  : Updates signal Batt12VCell4SoC                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell4_so_c(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL4_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_so_c_encode(data);
		 if(powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_so_c_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell4_param.batt12_v_cell4_so_c = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell4_param_pack(fl_data,&batt12_v_cell4_param,(size_t)BATT12_V_CELL4_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL4_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell4DoD                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell4_do_d(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL4_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_do_d_encode(data);
		 if(powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_do_d_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell4_param.batt12_v_cell4_do_d = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell4_param_pack(fl_data,&batt12_v_cell4_param,(size_t)BATT12_V_CELL4_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL4_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell4BalStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell4_bal_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL4_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_bal_status_encode(data);
		 if(powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_bal_status_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell4_param.batt12_v_cell4_bal_status = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell4_param_pack(fl_data,&batt12_v_cell4_param,(size_t)BATT12_V_CELL4_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL4_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell4SoHCap                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell4_so_h_cap(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL4_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_so_h_cap_encode(data);
		 if(powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_so_h_cap_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell4_param.batt12_v_cell4_so_h_cap = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell4_param_pack(fl_data,&batt12_v_cell4_param,(size_t)BATT12_V_CELL4_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL4_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell4SoHRes                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell4_so_h_res(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL4_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_so_h_res_encode(data);
		 if(powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_so_h_res_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell4_param.batt12_v_cell4_so_h_res = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell4_param_pack(fl_data,&batt12_v_cell4_param,(size_t)BATT12_V_CELL4_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL4_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell4Imbal                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell4_imbal(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL4_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_imbal_encode(data);
		 if(powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_imbal_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell4_param.batt12_v_cell4_imbal = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell4_param_pack(fl_data,&batt12_v_cell4_param,(size_t)BATT12_V_CELL4_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL4_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell4Volt                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell4_volt(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL4_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_volt_encode(data);
		 if(powertraincanv04_batt12_v_cell4_param_batt12_v_cell4_volt_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell4_param.batt12_v_cell4_volt = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell4_param_pack(fl_data,&batt12_v_cell4_param,(size_t)BATT12_V_CELL4_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL4_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt12VCell4SoC                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell4_so_c_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL4_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell4DoD                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell4_do_d_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL4_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell4BalStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell4_bal_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL4_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell4SoHCap                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell4_so_h_cap_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL4_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell4SoHRes                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell4_so_h_res_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL4_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell4Imbal                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell4_imbal_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL4_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell4Volt                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell4_volt_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL4_PARAM));
}

/* 
  * @Brief  : Updates signal Batt12VCell3SoC                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell3_so_c(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL3_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_so_c_encode(data);
		 if(powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_so_c_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell3_param.batt12_v_cell3_so_c = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell3_param_pack(fl_data,&batt12_v_cell3_param,(size_t)BATT12_V_CELL3_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL3_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell3DoD                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell3_do_d(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL3_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_do_d_encode(data);
		 if(powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_do_d_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell3_param.batt12_v_cell3_do_d = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell3_param_pack(fl_data,&batt12_v_cell3_param,(size_t)BATT12_V_CELL3_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL3_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell3BalStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell3_bal_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL3_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_bal_status_encode(data);
		 if(powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_bal_status_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell3_param.batt12_v_cell3_bal_status = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell3_param_pack(fl_data,&batt12_v_cell3_param,(size_t)BATT12_V_CELL3_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL3_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell3SoHCap                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell3_so_h_cap(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL3_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_so_h_cap_encode(data);
		 if(powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_so_h_cap_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell3_param.batt12_v_cell3_so_h_cap = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell3_param_pack(fl_data,&batt12_v_cell3_param,(size_t)BATT12_V_CELL3_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL3_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell3SoHRes                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell3_so_h_res(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL3_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_so_h_res_encode(data);
		 if(powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_so_h_res_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell3_param.batt12_v_cell3_so_h_res = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell3_param_pack(fl_data,&batt12_v_cell3_param,(size_t)BATT12_V_CELL3_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL3_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell3Imbal                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell3_imbal(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL3_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_imbal_encode(data);
		 if(powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_imbal_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell3_param.batt12_v_cell3_imbal = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell3_param_pack(fl_data,&batt12_v_cell3_param,(size_t)BATT12_V_CELL3_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL3_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell3Volt                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell3_volt(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL3_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_volt_encode(data);
		 if(powertraincanv04_batt12_v_cell3_param_batt12_v_cell3_volt_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell3_param.batt12_v_cell3_volt = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell3_param_pack(fl_data,&batt12_v_cell3_param,(size_t)BATT12_V_CELL3_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL3_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt12VCell3SoC                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell3_so_c_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL3_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell3DoD                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell3_do_d_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL3_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell3BalStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell3_bal_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL3_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell3SoHCap                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell3_so_h_cap_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL3_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell3SoHRes                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell3_so_h_res_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL3_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell3Imbal                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell3_imbal_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL3_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell3Volt                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell3_volt_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL3_PARAM));
}

/* 
  * @Brief  : Updates signal Batt12VCell2SoC                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell2_so_c(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL2_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_so_c_encode(data);
		 if(powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_so_c_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell2_param.batt12_v_cell2_so_c = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell2_param_pack(fl_data,&batt12_v_cell2_param,(size_t)BATT12_V_CELL2_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL2_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell2DoD                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell2_do_d(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL2_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_do_d_encode(data);
		 if(powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_do_d_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell2_param.batt12_v_cell2_do_d = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell2_param_pack(fl_data,&batt12_v_cell2_param,(size_t)BATT12_V_CELL2_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL2_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell2BalStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell2_bal_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL2_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_bal_status_encode(data);
		 if(powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_bal_status_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell2_param.batt12_v_cell2_bal_status = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell2_param_pack(fl_data,&batt12_v_cell2_param,(size_t)BATT12_V_CELL2_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL2_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell2SoHCap                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell2_so_h_cap(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL2_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_so_h_cap_encode(data);
		 if(powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_so_h_cap_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell2_param.batt12_v_cell2_so_h_cap = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell2_param_pack(fl_data,&batt12_v_cell2_param,(size_t)BATT12_V_CELL2_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL2_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell2SoHRes                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell2_so_h_res(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL2_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_so_h_res_encode(data);
		 if(powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_so_h_res_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell2_param.batt12_v_cell2_so_h_res = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell2_param_pack(fl_data,&batt12_v_cell2_param,(size_t)BATT12_V_CELL2_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL2_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell2Imbal                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell2_imbal(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL2_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_imbal_encode(data);
		 if(powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_imbal_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell2_param.batt12_v_cell2_imbal = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell2_param_pack(fl_data,&batt12_v_cell2_param,(size_t)BATT12_V_CELL2_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL2_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell2Volt                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell2_volt(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL2_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_volt_encode(data);
		 if(powertraincanv04_batt12_v_cell2_param_batt12_v_cell2_volt_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell2_param.batt12_v_cell2_volt = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell2_param_pack(fl_data,&batt12_v_cell2_param,(size_t)BATT12_V_CELL2_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL2_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt12VCell2SoC                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell2_so_c_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL2_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell2DoD                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell2_do_d_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL2_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell2BalStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell2_bal_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL2_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell2SoHCap                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell2_so_h_cap_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL2_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell2SoHRes                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell2_so_h_res_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL2_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell2Imbal                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell2_imbal_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL2_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell2Volt                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell2_volt_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL2_PARAM));
}

/* 
  * @Brief  : Updates signal Batt12VTempMeas1                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_temp_meas1(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_TEMPS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_temps_batt12_v_temp_meas1_encode(data);
		 if(powertraincanv04_batt12_v_temps_batt12_v_temp_meas1_is_in_range(fl_encoded_data))
		 {
				 batt12_v_temps.batt12_v_temp_meas1 = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_temps_pack(fl_data,&batt12_v_temps,(size_t)BATT12_V_TEMPS_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_TEMPS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VTempMeas2                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_temp_meas2(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_TEMPS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_temps_batt12_v_temp_meas2_encode(data);
		 if(powertraincanv04_batt12_v_temps_batt12_v_temp_meas2_is_in_range(fl_encoded_data))
		 {
				 batt12_v_temps.batt12_v_temp_meas2 = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_temps_pack(fl_data,&batt12_v_temps,(size_t)BATT12_V_TEMPS_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_TEMPS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VTempMeas3                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_temp_meas3(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_TEMPS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_temps_batt12_v_temp_meas3_encode(data);
		 if(powertraincanv04_batt12_v_temps_batt12_v_temp_meas3_is_in_range(fl_encoded_data))
		 {
				 batt12_v_temps.batt12_v_temp_meas3 = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_temps_pack(fl_data,&batt12_v_temps,(size_t)BATT12_V_TEMPS_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_TEMPS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VTempMeas4                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_temp_meas4(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_TEMPS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_temps_batt12_v_temp_meas4_encode(data);
		 if(powertraincanv04_batt12_v_temps_batt12_v_temp_meas4_is_in_range(fl_encoded_data))
		 {
				 batt12_v_temps.batt12_v_temp_meas4 = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_temps_pack(fl_data,&batt12_v_temps,(size_t)BATT12_V_TEMPS_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_TEMPS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VTempMeas5                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_temp_meas5(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_TEMPS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_temps_batt12_v_temp_meas5_encode(data);
		 if(powertraincanv04_batt12_v_temps_batt12_v_temp_meas5_is_in_range(fl_encoded_data))
		 {
				 batt12_v_temps.batt12_v_temp_meas5 = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_temps_pack(fl_data,&batt12_v_temps,(size_t)BATT12_V_TEMPS_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_TEMPS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VTempMeas6                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_temp_meas6(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_TEMPS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_temps_batt12_v_temp_meas6_encode(data);
		 if(powertraincanv04_batt12_v_temps_batt12_v_temp_meas6_is_in_range(fl_encoded_data))
		 {
				 batt12_v_temps.batt12_v_temp_meas6 = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_temps_pack(fl_data,&batt12_v_temps,(size_t)BATT12_V_TEMPS_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_TEMPS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VTempMeas7                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_temp_meas7(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_TEMPS_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_temps_batt12_v_temp_meas7_encode(data);
		 if(powertraincanv04_batt12_v_temps_batt12_v_temp_meas7_is_in_range(fl_encoded_data))
		 {
				 batt12_v_temps.batt12_v_temp_meas7 = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_temps_pack(fl_data,&batt12_v_temps,(size_t)BATT12_V_TEMPS_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_TEMPS,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt12VTempMeas1                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_temp_meas1_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_TEMPS));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VTempMeas2                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_temp_meas2_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_TEMPS));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VTempMeas3                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_temp_meas3_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_TEMPS));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VTempMeas4                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_temp_meas4_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_TEMPS));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VTempMeas5                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_temp_meas5_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_TEMPS));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VTempMeas6                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_temp_meas6_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_TEMPS));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VTempMeas7                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_temp_meas7_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_TEMPS));
}

/* 
  * @Brief  : Updates signal Batt12VCell1SoC                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell1_so_c(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL1_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_so_c_encode(data);
		 if(powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_so_c_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell1_param.batt12_v_cell1_so_c = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell1_param_pack(fl_data,&batt12_v_cell1_param,(size_t)BATT12_V_CELL1_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL1_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell1DoD                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell1_do_d(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL1_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_do_d_encode(data);
		 if(powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_do_d_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell1_param.batt12_v_cell1_do_d = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell1_param_pack(fl_data,&batt12_v_cell1_param,(size_t)BATT12_V_CELL1_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL1_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell1BalStatus                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell1_bal_status(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL1_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_bal_status_encode(data);
		 if(powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_bal_status_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell1_param.batt12_v_cell1_bal_status = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell1_param_pack(fl_data,&batt12_v_cell1_param,(size_t)BATT12_V_CELL1_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL1_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell1SoHCap                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell1_so_h_cap(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL1_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_so_h_cap_encode(data);
		 if(powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_so_h_cap_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell1_param.batt12_v_cell1_so_h_cap = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell1_param_pack(fl_data,&batt12_v_cell1_param,(size_t)BATT12_V_CELL1_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL1_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell1SoHRes                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell1_so_h_res(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL1_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_so_h_res_encode(data);
		 if(powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_so_h_res_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell1_param.batt12_v_cell1_so_h_res = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell1_param_pack(fl_data,&batt12_v_cell1_param,(size_t)BATT12_V_CELL1_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL1_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell1Imbal                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell1_imbal(float64 data)
{
		 uint8_t ret;
		 uint8_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL1_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_imbal_encode(data);
		 if(powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_imbal_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell1_param.batt12_v_cell1_imbal = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell1_param_pack(fl_data,&batt12_v_cell1_param,(size_t)BATT12_V_CELL1_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL1_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}


/* 
  * @Brief  : Updates signal Batt12VCell1Volt                                                                               
  * @param  : data                                                                               
  * @return : E_OK/E_NOT_OK                                                                               
*/ 
uint8_t CanMgr_Write_batt12_v_cell1_volt(float64 data)
{
		 uint8_t ret;
		 uint16_t fl_encoded_data;
		 static uint8_t fl_data[BATT12_V_CELL1_PARAM_LENGTH]={0};
		 fl_encoded_data = powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_volt_encode(data);
		 if(powertraincanv04_batt12_v_cell1_param_batt12_v_cell1_volt_is_in_range(fl_encoded_data))
		 {
				 batt12_v_cell1_param.batt12_v_cell1_volt = fl_encoded_data;
				 (void)powertraincanv04_batt12_v_cell1_param_pack(fl_data,&batt12_v_cell1_param,(size_t)BATT12_V_CELL1_PARAM_LENGTH);
				 ret = CanMgr_SendSignal( BATT12_V_CELL1_PARAM,fl_data);
		 }
		 else
		 {
		 		 ret = E_NOT_OK;
		 }
		 return  ret;
}




/* 
  * @Brief  : Returns the transmission status of Batt12VCell1SoC                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell1_so_c_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL1_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell1DoD                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell1_do_d_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL1_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell1BalStatus                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell1_bal_status_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL1_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell1SoHCap                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell1_so_h_cap_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL1_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell1SoHRes                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell1_so_h_res_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL1_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell1Imbal                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell1_imbal_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL1_PARAM));
}

/* 
  * @Brief  : Returns the transmission status of Batt12VCell1Volt                                                                               
  * @param  : NONE                                                                               
  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                
*/ 
uint8_t CanMgr_batt12_v_cell1_volt_cbk(void)
{
  return (CanMgr_GetTransmissionStatus(BATT12_V_CELL1_PARAM));
}



/* 
  * @Brief  : Reads signal InertiaSwitchState                                                                               
  * @param  : pointer to store the data                                                                               
  * @return : Reception status                                                                               
*/ 
uint8_t CanMgr_Read_inertia_switch_state(float64* data)
{
    static uint8_t fl_data[VEHICLE_INFO_LENGTH];
    uint8_t ret;
    ret = CanMgr_ReceiveSignal(VEHICLE_INFO,fl_data);
    (void)powertraincanv04_vehicle_info_unpack(&vehicle_info,fl_data,(size_t)VEHICLE_INFO_LENGTH);
    *data =powertraincanv04_vehicle_info_inertia_switch_state_decode(vehicle_info.inertia_switch_state);
    return ret;
}
/* 
  * @Brief  : Reads signal AmbientTemp                                                                               
  * @param  : pointer to store the data                                                                               
  * @return : Reception status                                                                               
*/ 
uint8_t CanMgr_Read_ambient_temp(float64* data)
{
    static uint8_t fl_data[VEHICLE_INFO_LENGTH];
    uint8_t ret;
    ret = CanMgr_ReceiveSignal(VEHICLE_INFO,fl_data);
    (void)powertraincanv04_vehicle_info_unpack(&vehicle_info,fl_data,(size_t)VEHICLE_INFO_LENGTH);
    *data =powertraincanv04_vehicle_info_ambient_temp_decode(vehicle_info.ambient_temp);
    return ret;
}
/* 
  * @Brief  : Reads signal EmergencySwitchState                                                                               
  * @param  : pointer to store the data                                                                               
  * @return : Reception status                                                                               
*/ 
uint8_t CanMgr_Read_emergency_switch_state(float64* data)
{
    static uint8_t fl_data[VEHICLE_INFO_LENGTH];
    uint8_t ret;
    ret = CanMgr_ReceiveSignal(VEHICLE_INFO,fl_data);
    (void)powertraincanv04_vehicle_info_unpack(&vehicle_info,fl_data,(size_t)VEHICLE_INFO_LENGTH);
    *data =powertraincanv04_vehicle_info_emergency_switch_state_decode(vehicle_info.emergency_switch_state);
    return ret;
}
/* 
  * @Brief  : Reads signal BrakePedalPos                                                                               
  * @param  : pointer to store the data                                                                               
  * @return : Reception status                                                                               
*/ 
uint8_t CanMgr_Read_brake_pedal_pos(float64* data)
{
    static uint8_t fl_data[VEHICLE_INFO_LENGTH];
    uint8_t ret;
    ret = CanMgr_ReceiveSignal(VEHICLE_INFO,fl_data);
    (void)powertraincanv04_vehicle_info_unpack(&vehicle_info,fl_data,(size_t)VEHICLE_INFO_LENGTH);
    *data =powertraincanv04_vehicle_info_brake_pedal_pos_decode(vehicle_info.brake_pedal_pos);
    return ret;
}
/* 
  * @Brief  : Reads signal DriveMode                                                                               
  * @param  : pointer to store the data                                                                               
  * @return : Reception status                                                                               
*/ 
uint8_t CanMgr_Read_drive_mode(float64* data)
{
    static uint8_t fl_data[VEHICLE_INFO_LENGTH];
    uint8_t ret;
    ret = CanMgr_ReceiveSignal(VEHICLE_INFO,fl_data);
    (void)powertraincanv04_vehicle_info_unpack(&vehicle_info,fl_data,(size_t)VEHICLE_INFO_LENGTH);
    *data =powertraincanv04_vehicle_info_drive_mode_decode(vehicle_info.drive_mode);
    return ret;
}
/* 
  * @Brief  : Reads signal EngineStopRequested                                                                               
  * @param  : pointer to store the data                                                                               
  * @return : Reception status                                                                               
*/ 
uint8_t CanMgr_Read_engine_stop_requested(float64* data)
{
    static uint8_t fl_data[VEHICLE_INFO_LENGTH];
    uint8_t ret;
    ret = CanMgr_ReceiveSignal(VEHICLE_INFO,fl_data);
    (void)powertraincanv04_vehicle_info_unpack(&vehicle_info,fl_data,(size_t)VEHICLE_INFO_LENGTH);
    *data =powertraincanv04_vehicle_info_engine_stop_requested_decode(vehicle_info.engine_stop_requested);
    return ret;
}
/* 
  * @Brief  : Reads signal ParkBrakeState                                                                               
  * @param  : pointer to store the data                                                                               
  * @return : Reception status                                                                               
*/ 
uint8_t CanMgr_Read_park_brake_state(float64* data)
{
    static uint8_t fl_data[VEHICLE_INFO_LENGTH];
    uint8_t ret;
    ret = CanMgr_ReceiveSignal(VEHICLE_INFO,fl_data);
    (void)powertraincanv04_vehicle_info_unpack(&vehicle_info,fl_data,(size_t)VEHICLE_INFO_LENGTH);
    *data =powertraincanv04_vehicle_info_park_brake_state_decode(vehicle_info.park_brake_state);
    return ret;
}
/* 
  * @Brief  : Reads signal VehiclePowerState                                                                               
  * @param  : pointer to store the data                                                                               
  * @return : Reception status                                                                               
*/ 
uint8_t CanMgr_Read_vehicle_power_state(float64* data)
{
    static uint8_t fl_data[VEHICLE_INFO_LENGTH];
    uint8_t ret;
    ret = CanMgr_ReceiveSignal(VEHICLE_INFO,fl_data);
    (void)powertraincanv04_vehicle_info_unpack(&vehicle_info,fl_data,(size_t)VEHICLE_INFO_LENGTH);
    *data =powertraincanv04_vehicle_info_vehicle_power_state_decode(vehicle_info.vehicle_power_state);
    return ret;
}
/* 
  * @Brief  : Reads signal CoolantTemp                                                                               
  * @param  : pointer to store the data                                                                               
  * @return : Reception status                                                                               
*/ 
uint8_t CanMgr_Read_coolant_temp(float64* data)
{
    static uint8_t fl_data[VEHICLE_INFO_LENGTH];
    uint8_t ret;
    ret = CanMgr_ReceiveSignal(VEHICLE_INFO,fl_data);
    (void)powertraincanv04_vehicle_info_unpack(&vehicle_info,fl_data,(size_t)VEHICLE_INFO_LENGTH);
    *data =powertraincanv04_vehicle_info_coolant_temp_decode(vehicle_info.coolant_temp);
    return ret;
}
/* 
  * @Brief  : Reads signal ReverseSwitchState                                                                               
  * @param  : pointer to store the data                                                                               
  * @return : Reception status                                                                               
*/ 
uint8_t CanMgr_Read_reverse_switch_state(float64* data)
{
    static uint8_t fl_data[VEHICLE_INFO_LENGTH];
    uint8_t ret;
    ret = CanMgr_ReceiveSignal(VEHICLE_INFO,fl_data);
    (void)powertraincanv04_vehicle_info_unpack(&vehicle_info,fl_data,(size_t)VEHICLE_INFO_LENGTH);
    *data =powertraincanv04_vehicle_info_reverse_switch_state_decode(vehicle_info.reverse_switch_state);
    return ret;
}
/* 
  * @Brief  : Reads signal CrankRequested                                                                               
  * @param  : pointer to store the data                                                                               
  * @return : Reception status                                                                               
*/ 
uint8_t CanMgr_Read_crank_requested(float64* data)
{
    static uint8_t fl_data[VEHICLE_INFO_LENGTH];
    uint8_t ret;
    ret = CanMgr_ReceiveSignal(VEHICLE_INFO,fl_data);
    (void)powertraincanv04_vehicle_info_unpack(&vehicle_info,fl_data,(size_t)VEHICLE_INFO_LENGTH);
    *data =powertraincanv04_vehicle_info_crank_requested_decode(vehicle_info.crank_requested);
    return ret;
}
/* 
  * @Brief  : Reads signal VehicleShutdownReq                                                                               
  * @param  : pointer to store the data                                                                               
  * @return : Reception status                                                                               
*/ 
uint8_t CanMgr_Read_vehicle_shutdown_req(float64* data)
{
    static uint8_t fl_data[VEHICLE_INFO_LENGTH];
    uint8_t ret;
    ret = CanMgr_ReceiveSignal(VEHICLE_INFO,fl_data);
    (void)powertraincanv04_vehicle_info_unpack(&vehicle_info,fl_data,(size_t)VEHICLE_INFO_LENGTH);
    *data =powertraincanv04_vehicle_info_vehicle_shutdown_req_decode(vehicle_info.vehicle_shutdown_req);
    return ret;
}




/* 
  * @Brief  : Reads signal ISGTorqueEst                                                                               
  * @param  : pointer to store the data                                                                               
  * @return : Reception status                                                                               
*/ 
uint8_t CanMgr_Read_isg_torque_est(float64* data)
{
    static uint8_t fl_data[ISG_INFO_LENGTH];
    uint8_t ret;
    ret = CanMgr_ReceiveSignal(ISG_INFO,fl_data);
    (void)powertraincanv04_isg_info_unpack(&isg_info,fl_data,(size_t)ISG_INFO_LENGTH);
    *data =powertraincanv04_isg_info_isg_torque_est_decode(isg_info.isg_torque_est);
    return ret;
}
/* 
  * @Brief  : Reads signal ISGState                                                                               
  * @param  : pointer to store the data                                                                               
  * @return : Reception status                                                                               
*/ 
uint8_t CanMgr_Read_isg_state(float64* data)
{
    static uint8_t fl_data[ISG_INFO_LENGTH];
    uint8_t ret;
    ret = CanMgr_ReceiveSignal(ISG_INFO,fl_data);
    (void)powertraincanv04_isg_info_unpack(&isg_info,fl_data,(size_t)ISG_INFO_LENGTH);
    *data =powertraincanv04_isg_info_isg_state_decode(isg_info.isg_state);
    return ret;
}




/* 
  * @Brief  : Reads signal ISGTorqueMinSlewRate                                                                               
  * @param  : pointer to store the data                                                                               
  * @return : Reception status                                                                               
*/ 
uint8_t CanMgr_Read_isg_torque_min_slew_rate(float64* data)
{
    static uint8_t fl_data[EMS_INFO1_LENGTH];
    uint8_t ret;
    ret = CanMgr_ReceiveSignal(EMS_INFO1,fl_data);
    (void)powertraincanv04_ems_info1_unpack(&ems_info1,fl_data,(size_t)EMS_INFO1_LENGTH);
    *data =powertraincanv04_ems_info1_isg_torque_min_slew_rate_decode(ems_info1.isg_torque_min_slew_rate);
    return ret;
}
/* 
  * @Brief  : Reads signal ISGMinTorque                                                                               
  * @param  : pointer to store the data                                                                               
  * @return : Reception status                                                                               
*/ 
uint8_t CanMgr_Read_isg_min_torque(float64* data)
{
    static uint8_t fl_data[EMS_INFO1_LENGTH];
    uint8_t ret;
    ret = CanMgr_ReceiveSignal(EMS_INFO1,fl_data);
    (void)powertraincanv04_ems_info1_unpack(&ems_info1,fl_data,(size_t)EMS_INFO1_LENGTH);
    *data =powertraincanv04_ems_info1_isg_min_torque_decode(ems_info1.isg_min_torque);
    return ret;
}
/* 
  * @Brief  : Reads signal ISGSpeedSetpoint                                                                               
  * @param  : pointer to store the data                                                                               
  * @return : Reception status                                                                               
*/ 
uint8_t CanMgr_Read_isg_speed_setpoint(float64* data)
{
    static uint8_t fl_data[EMS_INFO1_LENGTH];
    uint8_t ret;
    ret = CanMgr_ReceiveSignal(EMS_INFO1,fl_data);
    (void)powertraincanv04_ems_info1_unpack(&ems_info1,fl_data,(size_t)EMS_INFO1_LENGTH);
    *data =powertraincanv04_ems_info1_isg_speed_setpoint_decode(ems_info1.isg_speed_setpoint);
    return ret;
}
/* 
  * @Brief  : Reads signal EngineState                                                                               
  * @param  : pointer to store the data                                                                               
  * @return : Reception status                                                                               
*/ 
uint8_t CanMgr_Read_engine_state(float64* data)
{
    static uint8_t fl_data[EMS_INFO1_LENGTH];
    uint8_t ret;
    ret = CanMgr_ReceiveSignal(EMS_INFO1,fl_data);
    (void)powertraincanv04_ems_info1_unpack(&ems_info1,fl_data,(size_t)EMS_INFO1_LENGTH);
    *data =powertraincanv04_ems_info1_engine_state_decode(ems_info1.engine_state);
    return ret;
}
/* 
  * @Brief  : Reads signal ISGTorqueAvailable                                                                               
  * @param  : pointer to store the data                                                                               
  * @return : Reception status                                                                               
*/ 
uint8_t CanMgr_Read_isg_torque_available(float64* data)
{
    static uint8_t fl_data[EMS_INFO1_LENGTH];
    uint8_t ret;
    ret = CanMgr_ReceiveSignal(EMS_INFO1,fl_data);
    (void)powertraincanv04_ems_info1_unpack(&ems_info1,fl_data,(size_t)EMS_INFO1_LENGTH);
    *data =powertraincanv04_ems_info1_isg_torque_available_decode(ems_info1.isg_torque_available);
    return ret;
}
/* 
  * @Brief  : Reads signal CrankCmd                                                                               
  * @param  : pointer to store the data                                                                               
  * @return : Reception status                                                                               
*/ 
uint8_t CanMgr_Read_crank_cmd(float64* data)
{
    static uint8_t fl_data[EMS_INFO1_LENGTH];
    uint8_t ret;
    ret = CanMgr_ReceiveSignal(EMS_INFO1,fl_data);
    (void)powertraincanv04_ems_info1_unpack(&ems_info1,fl_data,(size_t)EMS_INFO1_LENGTH);
    *data =powertraincanv04_ems_info1_crank_cmd_decode(ems_info1.crank_cmd);
    return ret;
}
/* 
  * @Brief  : Reads signal ISGTorqueMaxSlewRate                                                                               
  * @param  : pointer to store the data                                                                               
  * @return : Reception status                                                                               
*/ 
uint8_t CanMgr_Read_isg_torque_max_slew_rate(float64* data)
{
    static uint8_t fl_data[EMS_INFO1_LENGTH];
    uint8_t ret;
    ret = CanMgr_ReceiveSignal(EMS_INFO1,fl_data);
    (void)powertraincanv04_ems_info1_unpack(&ems_info1,fl_data,(size_t)EMS_INFO1_LENGTH);
    *data =powertraincanv04_ems_info1_isg_torque_max_slew_rate_decode(ems_info1.isg_torque_max_slew_rate);
    return ret;
}


/**
  * @Brief  : Initializes all the TX message with default value  
  * @param  : NONE                                                                               
  * @return : NONE                                                                               
*/ 

void CanMgr_cfgInit(void)
{
    (void)powertraincanv04_batt48_v_cell14_param_pack(&Init_data_value[BATT48_V_CELL14_PARAM][0], &default_batt48_v_cell14_param, (size_t)BATT48_V_CELL14_PARAM_LENGTH);
    (void)powertraincanv04_batt48_v_cell13_param_pack(&Init_data_value[BATT48_V_CELL13_PARAM][0], &default_batt48_v_cell13_param, (size_t)BATT48_V_CELL13_PARAM_LENGTH);
    (void)powertraincanv04_batt48_v_cell12_param_pack(&Init_data_value[BATT48_V_CELL12_PARAM][0], &default_batt48_v_cell12_param, (size_t)BATT48_V_CELL12_PARAM_LENGTH);
    (void)powertraincanv04_batt48_v_cell11_param_pack(&Init_data_value[BATT48_V_CELL11_PARAM][0], &default_batt48_v_cell11_param, (size_t)BATT48_V_CELL11_PARAM_LENGTH);
    (void)powertraincanv04_batt48_v_cell10_param_pack(&Init_data_value[BATT48_V_CELL10_PARAM][0], &default_batt48_v_cell10_param, (size_t)BATT48_V_CELL10_PARAM_LENGTH);
    (void)powertraincanv04_batt48_v_cell9_param_pack(&Init_data_value[BATT48_V_CELL9_PARAM][0], &default_batt48_v_cell9_param, (size_t)BATT48_V_CELL9_PARAM_LENGTH);
    (void)powertraincanv04_batt48_v_cell8_param_pack(&Init_data_value[BATT48_V_CELL8_PARAM][0], &default_batt48_v_cell8_param, (size_t)BATT48_V_CELL8_PARAM_LENGTH);
    (void)powertraincanv04_batt48_v_cell7_param_pack(&Init_data_value[BATT48_V_CELL7_PARAM][0], &default_batt48_v_cell7_param, (size_t)BATT48_V_CELL7_PARAM_LENGTH);
    (void)powertraincanv04_batt48_v_cell6_param_pack(&Init_data_value[BATT48_V_CELL6_PARAM][0], &default_batt48_v_cell6_param, (size_t)BATT48_V_CELL6_PARAM_LENGTH);
    (void)powertraincanv04_batt48_v_cell5_param_pack(&Init_data_value[BATT48_V_CELL5_PARAM][0], &default_batt48_v_cell5_param, (size_t)BATT48_V_CELL5_PARAM_LENGTH);
    (void)powertraincanv04_batt48_v_cell4_param_pack(&Init_data_value[BATT48_V_CELL4_PARAM][0], &default_batt48_v_cell4_param, (size_t)BATT48_V_CELL4_PARAM_LENGTH);
    (void)powertraincanv04_batt48_v_cell3_param_pack(&Init_data_value[BATT48_V_CELL3_PARAM][0], &default_batt48_v_cell3_param, (size_t)BATT48_V_CELL3_PARAM_LENGTH);
    (void)powertraincanv04_batt48_v_cell2_param_pack(&Init_data_value[BATT48_V_CELL2_PARAM][0], &default_batt48_v_cell2_param, (size_t)BATT48_V_CELL2_PARAM_LENGTH);
    (void)powertraincanv04_batt48_v_cell1_param_pack(&Init_data_value[BATT48_V_CELL1_PARAM][0], &default_batt48_v_cell1_param, (size_t)BATT48_V_CELL1_PARAM_LENGTH);
    (void)powertraincanv04_batt48_v_info_pack(&Init_data_value[BATT48_V_INFO][0], &default_batt48_v_info, (size_t)BATT48_V_INFO_LENGTH);
    (void)powertraincanv04_batt12_v_info_pack(&Init_data_value[BATT12_V_INFO][0], &default_batt12_v_info, (size_t)BATT12_V_INFO_LENGTH);
    (void)powertraincanv04_pmu_status_pack(&Init_data_value[PMU_STATUS][0], &default_pmu_status, (size_t)PMU_STATUS_LENGTH);
    (void)powertraincanv04_batt48_v_temps_pack(&Init_data_value[BATT48_V_TEMPS][0], &default_batt48_v_temps, (size_t)BATT48_V_TEMPS_LENGTH);
    (void)powertraincanv04_batt_limits_pack(&Init_data_value[BATT_LIMITS][0], &default_batt_limits, (size_t)BATT_LIMITS_LENGTH);
    (void)powertraincanv04_dcdc48_v_info_pack(&Init_data_value[DCDC48_V_INFO][0], &default_dcdc48_v_info, (size_t)DCDC48_V_INFO_LENGTH);
    (void)powertraincanv04_dcdc12_v_info_pack(&Init_data_value[DCDC12_V_INFO][0], &default_dcdc12_v_info, (size_t)DCDC12_V_INFO_LENGTH);
    (void)powertraincanv04_batt12_v_cell4_param_pack(&Init_data_value[BATT12_V_CELL4_PARAM][0], &default_batt12_v_cell4_param, (size_t)BATT12_V_CELL4_PARAM_LENGTH);
    (void)powertraincanv04_batt12_v_cell3_param_pack(&Init_data_value[BATT12_V_CELL3_PARAM][0], &default_batt12_v_cell3_param, (size_t)BATT12_V_CELL3_PARAM_LENGTH);
    (void)powertraincanv04_batt12_v_cell2_param_pack(&Init_data_value[BATT12_V_CELL2_PARAM][0], &default_batt12_v_cell2_param, (size_t)BATT12_V_CELL2_PARAM_LENGTH);
    (void)powertraincanv04_batt12_v_temps_pack(&Init_data_value[BATT12_V_TEMPS][0], &default_batt12_v_temps, (size_t)BATT12_V_TEMPS_LENGTH);
    (void)powertraincanv04_batt12_v_cell1_param_pack(&Init_data_value[BATT12_V_CELL1_PARAM][0], &default_batt12_v_cell1_param, (size_t)BATT12_V_CELL1_PARAM_LENGTH);
}


/**********************************************************************************************************************
  *                                                R E V I S I O N   H I S T O R Y             
* **********************************************************************************************************************/
/**********************************************************************************************************************
REVISION NUMBER      : V1.0.0                                                                                   
REVISION DATE        : 30/01/2020                                                                               
CREATED / REVISED BY : Mahendran L (mahendranl@niyatainfotech.com)                                        
DESCRIPTION          : Initial Version                                                                       
---------------------------------------------------------------------------------------------------------------------
***********************************************************************************************************************/
