#ifndef CANDRIVER_CFG_H
#define CANDRIVER_CFG_H
/*********************************************************************************************************************** 
 *    DISCLAIMER                                                                                                        
 *   Copyright (C) 2011, 2016 Niyata Infotech Ptv. Ltd. All rights reserved.                                              
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * @author              Author :                                                                         
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                F I L E  D E S C R I P T I O N                                           
 *---------------------------------------------------------------------------------------------------------------------
 *  @brief                                                                                                             
 *                                                                                                                     
 *  File name                       : CAN_Driver_cfg.h                                                                         
 *  Version                         : V1.0.0                                                                           
 *  Micros supported                : TMS570LS1337                                                           
 *  Compilers supported             : ti-cgt-arm 18.12.4.LTS                                                                           
 *  Platforms supported             : TMS570                                                                            
 *  Description                     : This file contains configuration settings for CAN Driver                                 
 *                                                                                                                     
 *                                                                                                                     
 *  @bug                                                                                                               
 *---------------------------------------------------------------------------------------------------------------------*/

/**********************************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/**********************************************************************************************************************/



/***********************************************************************************************************************
 *                 C  A  N       D  R  I  V  E  R        C  O  N  F  I  G  U  R  A  T  I  O  N       M  A  C  R  O  S  *                                                           
 **********************************************************************************************************************/
 
/**********************************************************************************************************************
 *                                 B  A  U  D  R  A  T  E      C  O  N  F  I  G  U  R  A  T  I  O  N  S   			  *
 **********************************************************************************************************************/
 
/**********************************************************************************************************************
 * CAN BIT RATE CONFIGURATIONS                             
 **********************************************************************************************************************
 * @ Genreal description about CAN bit rate: CAN supports bit rates in the range of lower than 1 kBit/s up to 1000 kBit/s. 
											 Each member of the CAN network has its own clock generator, usually a quartz 
											 oscillator. The timing parameter of the bit time (i.e. the reciprocal of 
											 the bit rate) can be configured individually for each CAN node, creating a 
											 common bit rate even though the CAN nodes’oscillator periods (fosc) may be 
											 different.
											 
 */           
/**********************************************************************************************************************
 * CAN_DRIVER_BITRATE_INKBPS - Specify Can bit/baud rate in Kbit/s
 **********************************************************************************************************************
 * @brief           This value is used to caluculate the nominal bit rate based on the propagation delay and CAN input  
 *                  clock frequency.
 * @param      		User shall use one of the following baudrate value
 *             		CAN_1000KBPS
 *             		CAN_500KBPS
 *					CAN_250KBPS
 *             		CAN_125KBPS
 *                  
 * @ValidCheck      YES
 * @Required        YES
 */
#define CAN_DRIVER_BITRATE_INKBPS   CAN_500KBPS

/**********************************************************************************************************************
 * CAN_DRIVER_PERIPHERAL_CLOCK_VALUE_IN_MHZ - CAN input frequency in MHZ 
 **********************************************************************************************************************
 * @brief           Input frequecny of the CAN module  
 * @param      		User shall use one of the following options
 * 					CAN_INPUT_CLOCK_80_MHZ
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_PERIPHERAL_CLOCK_VALUE_IN_MHZ    CAN_INPUT_CLOCK_80_MHZ

/**********************************************************************************************************************
 * CAN_DRIVER_AUTOMATIC_RETRANSMISSION - Automatically Retransmit Frames
 ********************************************************************************************************************** 
 * @brief           CAN provides a mechanism to automatically retransmit frames that have lost arbitration or have been 
 *                  disturbed by errors during transmission. The frame transmission service will not be confirmed 
 *                  to the user before the transmission is successfully completed. 
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_DISABLE  - Automatic Retransmission is disabled.
 *             		CAN_DRIVER_ENABLE 	- Automatic Retransmission of not successful messages is enabled.
 * 
 * @ValidCheck      YES
 * @Required        YES
 */
 
#define CAN_DRIVER_AUTOMATIC_RETRANSMISSION    CAN_DRIVER_ENABLE

/**********************************************************************************************************************
 * CAN_DRIVER_BITRATE_INKBPS - Parity Check Mechanism
 **********************************************************************************************************************
 * @brief           CAN provides a parity check mechanism to ensure data integrity of Message RAM data. For each
					word (32 bits) in Message RAM, one parity bit will be calculated.Parity information is stored 
					in the Message RAM on write accesses and will be checked against the stored parity bit 
					from Message RAM on read accesses.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_DISABLE  - Parity Check is disabled.
 *             		CAN_DRIVER_ENABLE 	- Automatic Retransmission of not successful messages is enabled.
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_RAM_PARITY_SUPPORT    CAN_DRIVER_ENABLE



/**********************************************************************************************************************
 *              C  A  N  D  R  I  V  E   R          M  A  I  L  B  O  X       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   1       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX1_CTRL - Activate/Deactivate CAN Mailbox 1  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.All the other mailbox settings are valid only 
 *                  if the mailbox is activated.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX1_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX1_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX1_DATALENGTHCODE - Enter the data length code for CAN Mailbox 1  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX1_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX1_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX1_DIRECTION - Select the Message Direction for CAN Mailbox 1  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX1_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX1_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 1  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX1_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX1_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 1  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX1_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX1_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 1  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 1
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX1_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX1_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 1  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 1.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX1_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX1_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX1_INTERRUPT - Selects the interrupt level for CAN Mailbox 1  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 1.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX1_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX1_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX1_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   2       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX2_CTRL - Activate/Deactivate CAN Mailbox 2  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX2_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX2_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX2_DATALENGTHCODE - Enter the data length code for CAN Mailbox 2  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX2_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX2_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX2_DIRECTION - Select the Message Direction for CAN Mailbox 2  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX2_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX2_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 2  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX2_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX2_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 2  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX2_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX2_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 2  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 2
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX2_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX2_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 2  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 2.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX2_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX2_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX2_INTERRUPT - Selects the interrupt level for CAN Mailbox 2  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 2.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX2_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX2_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX2_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   3       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX3_CTRL - Activate/Deactivate CAN Mailbox 3  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX3_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX3_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX3_DATALENGTHCODE - Enter the data length code for CAN Mailbox 3  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX3_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX3_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX3_DIRECTION - Select the Message Direction for CAN Mailbox 3  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX3_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX3_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 3  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX3_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX3_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 3  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX3_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX3_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 3  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 3
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX3_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX3_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 3  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 3.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX3_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX3_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX3_INTERRUPT - Selects the interrupt level for CAN Mailbox 3  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 3.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX3_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX3_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX3_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   4       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX4_CTRL - Activate/Deactivate CAN Mailbox 4  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX4_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX4_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX4_DATALENGTHCODE - Enter the data length code for CAN Mailbox 4  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX4_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX4_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX4_DIRECTION - Select the Message Direction for CAN Mailbox 4  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX4_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX4_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 4  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX4_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX4_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 4  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX4_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX4_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 4  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 4
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX4_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX4_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 4  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 4.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX4_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX4_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX4_INTERRUPT - Selects the interrupt level for CAN Mailbox 4  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 4.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX4_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX4_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX4_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   5       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX5_CTRL - Activate/Deactivate CAN Mailbox 5  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX5_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX5_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX5_DATALENGTHCODE - Enter the data length code for CAN Mailbox 5  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX5_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX5_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX5_DIRECTION - Select the Message Direction for CAN Mailbox 5  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX5_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX5_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 5  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX5_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX5_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 5  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX5_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX5_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 5  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 5
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX5_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX5_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 5  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 5.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX5_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX5_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX5_INTERRUPT - Selects the interrupt level for CAN Mailbox 5  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 5.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX5_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX5_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX5_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   6       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX6_CTRL - Activate/Deactivate CAN Mailbox 6  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX6_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX6_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX6_DATALENGTHCODE - Enter the data length code for CAN Mailbox 6  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX6_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX6_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX6_DIRECTION - Select the Message Direction for CAN Mailbox 6  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX6_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX6_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 6  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX6_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX6_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 6  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX6_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX6_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 6  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 6
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX6_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX6_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 6  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 6.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX6_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX6_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX6_INTERRUPT - Selects the interrupt level for CAN Mailbox 6  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 6.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX6_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX6_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX6_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   7       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX7_CTRL - Activate/Deactivate CAN Mailbox 7  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX7_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX7_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX7_DATALENGTHCODE - Enter the data length code for CAN Mailbox 7  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX7_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX7_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX7_DIRECTION - Select the Message Direction for CAN Mailbox 7  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX7_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX7_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 7  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX7_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX7_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 7  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX7_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX7_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 7  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 7
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX7_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX7_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 7  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 7.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX7_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX7_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX7_INTERRUPT - Selects the interrupt level for CAN Mailbox 7  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 7.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX7_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX7_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX7_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   8       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX8_CTRL - Activate/Deactivate CAN Mailbox 8  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX8_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX8_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX8_DATALENGTHCODE - Enter the data length code for CAN Mailbox 8  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX8_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX8_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX8_DIRECTION - Select the Message Direction for CAN Mailbox 8  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX8_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX8_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 8  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX8_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX8_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 8  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX8_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX8_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 8  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 8
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX8_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX8_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 8  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 8.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX8_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX8_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX8_INTERRUPT - Selects the interrupt level for CAN Mailbox 8  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 8.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX8_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX8_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX8_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   9       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX9_CTRL - Activate/Deactivate CAN Mailbox 9  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX9_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX9_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX9_DATALENGTHCODE - Enter the data length code for CAN Mailbox 9  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX9_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX9_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX9_DIRECTION - Select the Message Direction for CAN Mailbox 9  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX9_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX9_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 9  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX9_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX9_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 9  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX9_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX9_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 9  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 9
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX9_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX9_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 9  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 9.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX9_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX9_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX9_INTERRUPT - Selects the interrupt level for CAN Mailbox 9  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 9.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX9_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX9_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX9_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   10       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX10_CTRL - Activate/Deactivate CAN Mailbox 10  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX10_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX10_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX10_DATALENGTHCODE - Enter the data length code for CAN Mailbox 10  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX10_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX10_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX10_DIRECTION - Select the Message Direction for CAN Mailbox 10  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX10_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX10_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 10  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX10_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX10_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 10  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX10_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX10_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 10  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 10
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX10_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX10_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 10  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 10.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX10_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX10_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX10_INTERRUPT - Selects the interrupt level for CAN Mailbox 10  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 10.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX10_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX10_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX10_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   11       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX11_CTRL - Activate/Deactivate CAN Mailbox 11  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX11_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX11_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX11_DATALENGTHCODE - Enter the data length code for CAN Mailbox 11  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX11_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX11_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX11_DIRECTION - Select the Message Direction for CAN Mailbox 11  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX11_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX11_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 11  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX11_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX11_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 11  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX11_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX11_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 11  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 11
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX11_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX11_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 11  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 11.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX11_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX11_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX11_INTERRUPT - Selects the interrupt level for CAN Mailbox 11  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 11.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX11_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX11_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX11_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   12       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX12_CTRL - Activate/Deactivate CAN Mailbox 12  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX12_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX12_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX12_DATALENGTHCODE - Enter the data length code for CAN Mailbox 12  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX12_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX12_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX12_DIRECTION - Select the Message Direction for CAN Mailbox 12  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX12_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX12_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 12  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX12_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX12_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 12  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX12_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX12_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 12  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 12
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX12_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX12_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 12  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 12.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX12_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX12_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX12_INTERRUPT - Selects the interrupt level for CAN Mailbox 12  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 12.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX12_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX12_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX12_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   13       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX13_CTRL - Activate/Deactivate CAN Mailbox 13  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX13_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX13_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX13_DATALENGTHCODE - Enter the data length code for CAN Mailbox 13  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX13_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX13_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX13_DIRECTION - Select the Message Direction for CAN Mailbox 13  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX13_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX13_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 13  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX13_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX13_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 13  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX13_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX13_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 13  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 13
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX13_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX13_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 13  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 13.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX13_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX13_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX13_INTERRUPT - Selects the interrupt level for CAN Mailbox 13  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 13.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX13_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX13_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX13_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   14       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX14_CTRL - Activate/Deactivate CAN Mailbox 14  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX14_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX14_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX14_DATALENGTHCODE - Enter the data length code for CAN Mailbox 14  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX14_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX14_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX14_DIRECTION - Select the Message Direction for CAN Mailbox 14  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX14_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX14_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 14  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX14_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX14_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 14  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX14_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX14_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 14  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 14
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX14_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX14_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 14  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 14.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX14_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX14_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX14_INTERRUPT - Selects the interrupt level for CAN Mailbox 14  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 14.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX14_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX14_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX14_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   15       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX15_CTRL - Activate/Deactivate CAN Mailbox 15  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX15_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX15_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX15_DATALENGTHCODE - Enter the data length code for CAN Mailbox 15  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX15_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX15_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX15_DIRECTION - Select the Message Direction for CAN Mailbox 15  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX15_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX15_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 15  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX15_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX15_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 15  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX15_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX15_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 15  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 15
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX15_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX15_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 15  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 15.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX15_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX15_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX15_INTERRUPT - Selects the interrupt level for CAN Mailbox 15  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 15.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX15_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX15_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX15_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   16       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX16_CTRL - Activate/Deactivate CAN Mailbox 31  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX16_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX16_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX16_DATALENGTHCODE - Enter the data length code for CAN Mailbox 16  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX16_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX16_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX16_DIRECTION - Select the Message Direction for CAN Mailbox 16  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX16_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX16_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 16  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX16_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX16_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 16  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX16_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX16_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 16  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 16
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX16_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX16_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 16  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 16.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX16_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX16_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX16_INTERRUPT - Selects the interrupt level for CAN Mailbox 16  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 16.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX16_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX16_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX16_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   17       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX17_CTRL - Activate/Deactivate CAN Mailbox 17  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX17_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX17_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX17_DATALENGTHCODE - Enter the data length code for CAN Mailbox 17  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX17_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX17_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX17_DIRECTION - Select the Message Direction for CAN Mailbox 17  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX17_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX17_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 17  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX17_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX17_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 17  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX17_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX17_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 17  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 17
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX17_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX17_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 17  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 17.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX17_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX17_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX17_INTERRUPT - Selects the interrupt level for CAN Mailbox 17  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 17.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX17_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX17_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX17_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   18       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX18_CTRL - Activate/Deactivate CAN Mailbox 18  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX18_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX18_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX18_DATALENGTHCODE - Enter the data length code for CAN Mailbox 18  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX18_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX18_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX18_DIRECTION - Select the Message Direction for CAN Mailbox 18  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX18_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX18_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 18  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX18_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX18_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 18  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX18_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX18_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 18  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 18
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX18_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX18_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 18  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 18.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX18_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX18_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX18_INTERRUPT - Selects the interrupt level for CAN Mailbox 18  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 18.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX18_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX18_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX18_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   19       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX19_CTRL - Activate/Deactivate CAN Mailbox 19  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX19_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX19_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX19_DATALENGTHCODE - Enter the data length code for CAN Mailbox 19  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX19_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX19_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX19_DIRECTION - Select the Message Direction for CAN Mailbox 19  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX19_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX19_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 19  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX19_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX19_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 19  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX19_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX19_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 19  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 19
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX19_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX19_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 19  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 19.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX19_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX19_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX19_INTERRUPT - Selects the interrupt level for CAN Mailbox 19  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 19.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX19_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX19_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX19_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   20       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX20_CTRL - Activate/Deactivate CAN Mailbox 20  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX20_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX20_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX20_DATALENGTHCODE - Enter the data length code for CAN Mailbox 20  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX20_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX20_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX20_DIRECTION - Select the Message Direction for CAN Mailbox 20  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX20_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX20_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 20  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX20_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX20_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 20  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX20_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX20_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 20  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 20
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX20_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX20_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 20  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 20.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX20_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX20_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX20_INTERRUPT - Selects the interrupt level for CAN Mailbox 20  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 20.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX20_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX20_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX20_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   21       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX21_CTRL - Activate/Deactivate CAN Mailbox 21  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX21_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX21_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX21_DATALENGTHCODE - Enter the data length code for CAN Mailbox 21  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX21_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX21_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX21_DIRECTION - Select the Message Direction for CAN Mailbox 21  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX21_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX21_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 21  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX21_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX21_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 21  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX21_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX21_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 21  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 21
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX21_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX21_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 21  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 21.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX21_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX21_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX21_INTERRUPT - Selects the interrupt level for CAN Mailbox 21  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 21.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX21_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX21_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX21_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   22       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX22_CTRL - Activate/Deactivate CAN Mailbox 22  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX22_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX22_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX22_DATALENGTHCODE - Enter the data length code for CAN Mailbox 22  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX22_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX22_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX22_DIRECTION - Select the Message Direction for CAN Mailbox 22  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX22_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX22_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 22  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX22_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX22_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 22  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX22_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX22_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 22  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 22
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX22_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX22_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 22  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 22.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX22_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX22_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX22_INTERRUPT - Selects the interrupt level for CAN Mailbox 22  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 22.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX22_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX22_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX22_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   23       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX23_CTRL - Activate/Deactivate CAN Mailbox 23  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX23_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX23_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX23_DATALENGTHCODE - Enter the data length code for CAN Mailbox 23  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX23_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX23_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX23_DIRECTION - Select the Message Direction for CAN Mailbox 23  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX23_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX23_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 23  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX23_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX23_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 23  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX23_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX23_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 23  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 23
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX23_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX23_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 23  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 23.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX23_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX23_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX23_INTERRUPT - Selects the interrupt level for CAN Mailbox 23  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 23.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX23_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX23_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX23_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   24       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX24_CTRL - Activate/Deactivate CAN Mailbox 24  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX24_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX24_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX24_DATALENGTHCODE - Enter the data length code for CAN Mailbox 24  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX24_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX24_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX24_DIRECTION - Select the Message Direction for CAN Mailbox 24  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX24_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX24_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 24  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX24_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX24_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 24  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX24_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX24_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 24  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 24
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX24_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX24_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 24  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 24.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX24_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX24_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX24_INTERRUPT - Selects the interrupt level for CAN Mailbox 24  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 24.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX24_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX24_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX24_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   25       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX25_CTRL - Activate/Deactivate CAN Mailbox 25  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX25_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX25_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX25_DATALENGTHCODE - Enter the data length code for CAN Mailbox 25  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX25_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX25_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX25_DIRECTION - Select the Message Direction for CAN Mailbox 25  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX25_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX25_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 25  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX25_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX25_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 25  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX25_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX25_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 25  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 25
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX25_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX25_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 25  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 25.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX25_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX25_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX25_INTERRUPT - Selects the interrupt level for CAN Mailbox 25  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 25.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX25_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX25_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX25_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   26       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX26_CTRL - Activate/Deactivate CAN Mailbox 26  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX26_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX26_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX26_DATALENGTHCODE - Enter the data length code for CAN Mailbox 26  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX26_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX26_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX26_DIRECTION - Select the Message Direction for CAN Mailbox 26  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX26_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX26_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 26  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX26_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX26_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 26  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX26_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX26_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 26  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 26
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX26_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX26_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 26  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 26.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX26_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX26_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX26_INTERRUPT - Selects the interrupt level for CAN Mailbox 26  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 26.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX26_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX26_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX26_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   27       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX27_CTRL - Activate/Deactivate CAN Mailbox 27  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX27_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX27_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX27_DATALENGTHCODE - Enter the data length code for CAN Mailbox 27  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX27_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX27_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX27_DIRECTION - Select the Message Direction for CAN Mailbox 27  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX27_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX27_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 27  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX27_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX27_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 27  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX27_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX27_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 27  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 27
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX27_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX27_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 27  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 27.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX27_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX27_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX27_INTERRUPT - Selects the interrupt level for CAN Mailbox 27  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 27.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX27_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX27_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX27_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   28       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX28_CTRL - Activate/Deactivate CAN Mailbox 28  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX28_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX28_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX28_DATALENGTHCODE - Enter the data length code for CAN Mailbox 28  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX28_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX28_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX28_DIRECTION - Select the Message Direction for CAN Mailbox 28  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX28_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX28_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 28  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX28_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX28_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 28  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX28_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX28_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 28  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 28
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX28_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX28_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 28  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 28.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX28_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX28_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX28_INTERRUPT - Selects the interrupt level for CAN Mailbox 28  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 28.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX28_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX28_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX28_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   29       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX29_CTRL - Activate/Deactivate CAN Mailbox 29  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX29_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX29_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX29_DATALENGTHCODE - Enter the data length code for CAN Mailbox 29  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX29_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX29_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX29_DIRECTION - Select the Message Direction for CAN Mailbox 29  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX29_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX29_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 29  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX29_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX29_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 29  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX29_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX29_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 29  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 29
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX29_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX29_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 29  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 29.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX29_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX29_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX29_INTERRUPT - Selects the interrupt level for CAN Mailbox 29  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 29.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX29_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX29_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX29_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   30       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX30_CTRL - Activate/Deactivate CAN Mailbox 30  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX30_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX30_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX30_DATALENGTHCODE - Enter the data length code for CAN Mailbox 30  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX30_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX30_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX30_DIRECTION - Select the Message Direction for CAN Mailbox 30  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX30_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX30_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 30  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX30_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX30_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 30  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX30_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX30_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 30  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 30
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX30_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX30_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 30  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 30.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX30_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX30_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX30_INTERRUPT - Selects the interrupt level for CAN Mailbox 30  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 30.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX30_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX30_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX30_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   31       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX31_CTRL - Activate/Deactivate CAN Mailbox 31  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX31_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX31_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX31_DATALENGTHCODE - Enter the data length code for CAN Mailbox 31  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX31_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX31_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX31_DIRECTION - Select the Message Direction for CAN Mailbox 31  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX31_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX31_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 31  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX31_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX31_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 31  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX31_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX31_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 31  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 31
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX31_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX31_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 31  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 31.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX31_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX31_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX31_INTERRUPT - Selects the interrupt level for CAN Mailbox 31  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 31.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX31_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX31_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX31_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   32       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX32_CTRL - Activate/Deactivate CAN Mailbox 32  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX32_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX32_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX32_DATALENGTHCODE - Enter the data length code for CAN Mailbox 32  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX32_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX32_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX32_DIRECTION - Select the Message Direction for CAN Mailbox 32  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX32_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX32_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 32  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX32_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX32_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 32  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX32_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX32_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 32  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 32
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX32_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX32_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 32  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 32.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX32_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX32_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX32_INTERRUPT - Selects the interrupt level for CAN Mailbox 32  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 32.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX32_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX32_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX32_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   33       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX33_CTRL - Activate/Deactivate CAN Mailbox 33  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX33_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX33_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX33_DATALENGTHCODE - Enter the data length code for CAN Mailbox 33  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX33_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX33_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX33_DIRECTION - Select the Message Direction for CAN Mailbox 33  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX33_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX33_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 33  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX33_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX33_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 33  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX33_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX33_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 33  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 33
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX33_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX33_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 33  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 33.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX33_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX33_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX33_INTERRUPT - Selects the interrupt level for CAN Mailbox 33  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 33.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX33_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX33_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX33_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   34       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX34_CTRL - Activate/Deactivate CAN Mailbox 34  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX34_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX34_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX34_DATALENGTHCODE - Enter the data length code for CAN Mailbox 34  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX34_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX34_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX34_DIRECTION - Select the Message Direction for CAN Mailbox 34  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX34_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX34_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 34  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX34_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX34_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 34  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX34_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX34_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 34  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 34
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX34_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX34_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 34  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 34.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX34_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX34_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX34_INTERRUPT - Selects the interrupt level for CAN Mailbox 34  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 34.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX34_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX34_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX34_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   35       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX35_CTRL - Activate/Deactivate CAN Mailbox 35  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX35_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX35_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX35_DATALENGTHCODE - Enter the data length code for CAN Mailbox 35  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX35_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX35_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX35_DIRECTION - Select the Message Direction for CAN Mailbox 35  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX35_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX35_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 35  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX35_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX35_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 35  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX35_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX35_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 35  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 35
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX35_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX35_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 35  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 35.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX35_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX35_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX35_INTERRUPT - Selects the interrupt level for CAN Mailbox 35  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 35.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX35_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX35_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX35_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   36       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX36_CTRL - Activate/Deactivate CAN Mailbox 36  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX36_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX36_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX36_DATALENGTHCODE - Enter the data length code for CAN Mailbox 36  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX36_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX36_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX36_DIRECTION - Select the Message Direction for CAN Mailbox 36  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX36_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX36_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 36  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX36_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX36_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 36  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX36_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX36_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 36  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 36
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX36_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX36_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 36  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 36.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX36_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX36_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX36_INTERRUPT - Selects the interrupt level for CAN Mailbox 36  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 36.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX36_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX36_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX36_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   37       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX37_CTRL - Activate/Deactivate CAN Mailbox 37  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX37_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX37_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX37_DATALENGTHCODE - Enter the data length code for CAN Mailbox 37  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX37_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX37_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX37_DIRECTION - Select the Message Direction for CAN Mailbox 37  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX37_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX37_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 37  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX37_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX37_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 37  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX37_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX37_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 37  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 37
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX37_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX37_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 37  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 37.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX37_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX37_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX37_INTERRUPT - Selects the interrupt level for CAN Mailbox 37  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 37.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX37_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX37_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX37_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   38       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX38_CTRL - Activate/Deactivate CAN Mailbox 38  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX38_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX38_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX38_DATALENGTHCODE - Enter the data length code for CAN Mailbox 38  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX38_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX38_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX38_DIRECTION - Select the Message Direction for CAN Mailbox 38  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX38_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX38_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 38  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX38_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX38_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 38  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX38_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX38_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 38  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 38
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX38_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX38_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 38  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 38.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX38_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX38_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX38_INTERRUPT - Selects the interrupt level for CAN Mailbox 38  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 38.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX38_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX38_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX38_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   39       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX39_CTRL - Activate/Deactivate CAN Mailbox 39  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX39_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX39_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX39_DATALENGTHCODE - Enter the data length code for CAN Mailbox 39  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX39_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX39_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX39_DIRECTION - Select the Message Direction for CAN Mailbox 39  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX39_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX39_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 39  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX39_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX39_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 39  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX39_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX39_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 39  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 39
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX39_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX39_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 39  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 39.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX39_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX39_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX39_INTERRUPT - Selects the interrupt level for CAN Mailbox 39  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 39.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX39_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX39_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX39_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   40       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX40_CTRL - Activate/Deactivate CAN Mailbox 40  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX40_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX40_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX40_DATALENGTHCODE - Enter the data length code for CAN Mailbox 40  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX40_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX40_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX40_DIRECTION - Select the Message Direction for CAN Mailbox 40  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX40_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX40_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 40  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX40_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX40_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 40  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX40_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX40_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 40  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 40
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX40_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX40_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 40  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 40.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX40_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX40_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX40_INTERRUPT - Selects the interrupt level for CAN Mailbox 40  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 40.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX40_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX40_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX40_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   41       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX41_CTRL - Activate/Deactivate CAN Mailbox 41  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX41_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX41_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX41_DATALENGTHCODE - Enter the data length code for CAN Mailbox 41  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX41_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX41_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX41_DIRECTION - Select the Message Direction for CAN Mailbox 41  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX41_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX41_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 41  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX41_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX41_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 41  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX41_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX41_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 41  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 41
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX41_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX41_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 41  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 41.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX41_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX41_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX41_INTERRUPT - Selects the interrupt level for CAN Mailbox 41  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 41.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX41_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX41_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX41_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   42       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX42_CTRL - Activate/Deactivate CAN Mailbox 42  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX42_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX42_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX42_DATALENGTHCODE - Enter the data length code for CAN Mailbox 42  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX42_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX42_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX42_DIRECTION - Select the Message Direction for CAN Mailbox 42  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX42_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX42_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 42  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX42_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX42_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 42  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX42_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX42_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 42  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 42
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX42_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX42_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 42  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 42.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX42_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX42_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX42_INTERRUPT - Selects the interrupt level for CAN Mailbox 42  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 42.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX42_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX42_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX42_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   43       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX43_CTRL - Activate/Deactivate CAN Mailbox 43  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX43_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX43_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX43_DATALENGTHCODE - Enter the data length code for CAN Mailbox 43  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX43_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX43_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX43_DIRECTION - Select the Message Direction for CAN Mailbox 43  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX43_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX43_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 43  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX43_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX43_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 43  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX43_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX43_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 43  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 43
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX43_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX43_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 43  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 43.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX43_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX43_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX43_INTERRUPT - Selects the interrupt level for CAN Mailbox 43  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 43.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX43_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX43_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX43_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   44       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX44_CTRL - Activate/Deactivate CAN Mailbox 44  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX44_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX44_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX44_DATALENGTHCODE - Enter the data length code for CAN Mailbox 44  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX44_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX44_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX44_DIRECTION - Select the Message Direction for CAN Mailbox 44  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX44_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX44_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 44  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX44_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX44_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 44  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX44_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX44_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 44  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 44
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX44_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX44_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 44  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 44.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX44_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX44_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX44_INTERRUPT - Selects the interrupt level for CAN Mailbox 44  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 44.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX44_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX44_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX44_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   45       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX45_CTRL - Activate/Deactivate CAN Mailbox 45  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX45_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX45_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX45_DATALENGTHCODE - Enter the data length code for CAN Mailbox 45  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX45_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX45_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX45_DIRECTION - Select the Message Direction for CAN Mailbox 45  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX45_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX45_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 45  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX45_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX45_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 45  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX45_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX45_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 45  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 45
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX45_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX45_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 45  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 45.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX45_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX45_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX45_INTERRUPT - Selects the interrupt level for CAN Mailbox 45  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 45.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX45_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX45_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX45_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   46       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX46_CTRL - Activate/Deactivate CAN Mailbox 46  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX46_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX46_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX46_DATALENGTHCODE - Enter the data length code for CAN Mailbox 46  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX46_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX46_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX46_DIRECTION - Select the Message Direction for CAN Mailbox 46  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX46_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX46_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 46  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX46_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX46_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 46  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX46_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX46_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 46  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 46
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX46_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX46_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 46  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 46.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX46_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX46_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX46_INTERRUPT - Selects the interrupt level for CAN Mailbox 46  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 46.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX46_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX46_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX46_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   47       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX47_CTRL - Activate/Deactivate CAN Mailbox 47  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX47_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX47_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX47_DATALENGTHCODE - Enter the data length code for CAN Mailbox 47  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX47_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX47_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX47_DIRECTION - Select the Message Direction for CAN Mailbox 47  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX47_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX47_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 47  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX47_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX47_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 47  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX47_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX47_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 47  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 47
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX47_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX47_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 47  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 47.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX47_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX47_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX47_INTERRUPT - Selects the interrupt level for CAN Mailbox 47  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 47.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX47_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX47_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX47_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   48       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX48_CTRL - Activate/Deactivate CAN Mailbox 48  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX48_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX48_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX48_DATALENGTHCODE - Enter the data length code for CAN Mailbox 48  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX48_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX48_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX48_DIRECTION - Select the Message Direction for CAN Mailbox 48  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX48_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX48_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 48  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX48_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX48_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 48  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX48_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX48_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 48  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 48
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX48_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX48_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 48  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 48.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX48_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX48_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX48_INTERRUPT - Selects the interrupt level for CAN Mailbox 48  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 48.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX48_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX48_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX48_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   49       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX49_CTRL - Activate/Deactivate CAN Mailbox 49  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX49_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX49_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX49_DATALENGTHCODE - Enter the data length code for CAN Mailbox 49  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX49_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX49_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX49_DIRECTION - Select the Message Direction for CAN Mailbox 49  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX49_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX49_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 49  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX49_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX49_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 49  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX49_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX49_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 49  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 49
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX49_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX49_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 49  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 49.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX49_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX49_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX49_INTERRUPT - Selects the interrupt level for CAN Mailbox 49  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 49.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX49_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX49_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX49_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   50       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX50_CTRL - Activate/Deactivate CAN Mailbox 50  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX50_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX50_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX50_DATALENGTHCODE - Enter the data length code for CAN Mailbox 50  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX50_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX50_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX50_DIRECTION - Select the Message Direction for CAN Mailbox 50  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX50_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX50_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 50  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX50_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX50_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 50  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX50_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX50_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 50  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 50
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX50_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX50_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 50  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 50.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX50_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX50_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX50_INTERRUPT - Selects the interrupt level for CAN Mailbox 50  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 50.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX50_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX50_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX50_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   51       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX51_CTRL - Activate/Deactivate CAN Mailbox 51  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX51_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX51_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX51_DATALENGTHCODE - Enter the data length code for CAN Mailbox 51  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX51_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX51_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX51_DIRECTION - Select the Message Direction for CAN Mailbox 51  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX51_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX51_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 51  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX51_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX51_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 51  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX51_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX51_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 51  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 51
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX51_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX51_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 51  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 51.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX51_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX51_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX51_INTERRUPT - Selects the interrupt level for CAN Mailbox 51  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 51.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX51_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX51_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX51_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   52       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX52_CTRL - Activate/Deactivate CAN Mailbox 52  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX52_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX52_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX52_DATALENGTHCODE - Enter the data length code for CAN Mailbox 52  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX52_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX52_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX52_DIRECTION - Select the Message Direction for CAN Mailbox 52  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX52_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX52_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 52  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX52_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX52_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 52  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX52_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX52_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 52  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 52
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX52_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX52_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 52  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 52.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX52_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX52_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX52_INTERRUPT - Selects the interrupt level for CAN Mailbox 52  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 52.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX52_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX52_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX52_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   53       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX53_CTRL - Activate/Deactivate CAN Mailbox 53  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX53_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX53_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX53_DATALENGTHCODE - Enter the data length code for CAN Mailbox 53  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX53_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX53_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX53_DIRECTION - Select the Message Direction for CAN Mailbox 53  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX53_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX53_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 53  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX53_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX53_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 53  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX53_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX53_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 53  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 53
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX53_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX53_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 53  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 53.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX53_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX53_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX53_INTERRUPT - Selects the interrupt level for CAN Mailbox 53  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 53.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX53_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX53_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX53_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   54       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX54_CTRL - Activate/Deactivate CAN Mailbox 54  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX54_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX54_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX54_DATALENGTHCODE - Enter the data length code for CAN Mailbox 54  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX54_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX54_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX54_DIRECTION - Select the Message Direction for CAN Mailbox 54  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX54_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX54_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 54  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX54_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX54_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 54  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX54_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX54_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 54  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 54
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX54_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX54_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 54  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 54.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX54_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX54_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX54_INTERRUPT - Selects the interrupt level for CAN Mailbox 54  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 54.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX54_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX54_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX54_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   55       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX55_CTRL - Activate/Deactivate CAN Mailbox 55  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX55_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX55_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX55_DATALENGTHCODE - Enter the data length code for CAN Mailbox 55  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX55_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX55_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX55_DIRECTION - Select the Message Direction for CAN Mailbox 55  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX55_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX55_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 55  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX55_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX55_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 55  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX55_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX55_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 55  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 55
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX55_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX55_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 55  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 55.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX55_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX55_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX55_INTERRUPT - Selects the interrupt level for CAN Mailbox 55  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 55.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX55_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX55_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX55_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   56       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX56_CTRL - Activate/Deactivate CAN Mailbox 56  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX56_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX56_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX56_DATALENGTHCODE - Enter the data length code for CAN Mailbox 56  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX56_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX56_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX56_DIRECTION - Select the Message Direction for CAN Mailbox 56  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX56_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX56_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 56  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX56_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX56_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 56  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX56_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX56_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 56  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 56
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX56_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX56_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 56  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 56.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX56_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX56_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX56_INTERRUPT - Selects the interrupt level for CAN Mailbox 56  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 56.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX56_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX56_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX56_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   57       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX57_CTRL - Activate/Deactivate CAN Mailbox 57  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX57_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX57_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX57_DATALENGTHCODE - Enter the data length code for CAN Mailbox 57  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX57_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX57_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX57_DIRECTION - Select the Message Direction for CAN Mailbox 57  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX57_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX57_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 57  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX57_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX57_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 57  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX57_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX57_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 57  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 57
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX57_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX57_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 57  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 57.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX57_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX57_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX57_INTERRUPT - Selects the interrupt level for CAN Mailbox 57  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 57.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX57_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX57_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX57_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   58       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX58_CTRL - Activate/Deactivate CAN Mailbox 58  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX58_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX58_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX58_DATALENGTHCODE - Enter the data length code for CAN Mailbox 58  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX58_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX58_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX58_DIRECTION - Select the Message Direction for CAN Mailbox 58  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX58_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX58_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 58  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX58_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX58_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 58  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX58_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX58_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 58  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 58
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX58_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX58_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 58  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 58.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX58_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX58_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX58_INTERRUPT - Selects the interrupt level for CAN Mailbox 58  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 58.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX58_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX58_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX58_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   59       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX59_CTRL - Activate/Deactivate CAN Mailbox 59  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX59_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX59_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX59_DATALENGTHCODE - Enter the data length code for CAN Mailbox 59  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX59_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX59_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX59_DIRECTION - Select the Message Direction for CAN Mailbox 59  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX59_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX59_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 59  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX59_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX59_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 59  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX59_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX59_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 59  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 59
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX59_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX59_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 59  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 59.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX59_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX59_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX59_INTERRUPT - Selects the interrupt level for CAN Mailbox 59  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 59.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX59_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX59_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX59_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   60       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX60_CTRL - Activate/Deactivate CAN Mailbox 60  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX60_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX60_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX60_DATALENGTHCODE - Enter the data length code for CAN Mailbox 60  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX60_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX60_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX60_DIRECTION - Select the Message Direction for CAN Mailbox 60  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX60_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX60_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 60  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX60_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX60_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 60  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX60_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX60_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 60  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 60
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX60_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX60_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 60  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 60.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX60_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX60_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX60_INTERRUPT - Selects the interrupt level for CAN Mailbox 60  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 60.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX60_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX60_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX60_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   61       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX61_CTRL - Activate/Deactivate CAN Mailbox 61  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX61_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX61_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX61_DATALENGTHCODE - Enter the data length code for CAN Mailbox 61  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX61_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX61_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX61_DIRECTION - Select the Message Direction for CAN Mailbox 61  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX61_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX61_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 61  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX61_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX61_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 61  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX61_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX61_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 61  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 61
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX61_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX61_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 61  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 61.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX61_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX61_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX61_INTERRUPT - Selects the interrupt level for CAN Mailbox 61  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 61.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX61_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX61_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX61_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   62       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX62_CTRL - Activate/Deactivate CAN Mailbox 62  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX62_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX62_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX62_DATALENGTHCODE - Enter the data length code for CAN Mailbox 62  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX62_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX62_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX62_DIRECTION - Select the Message Direction for CAN Mailbox 62  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX62_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX62_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 62  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX62_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX62_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 62  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX62_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX62_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 62  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 62
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX62_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX62_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 62  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 62.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX62_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX62_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX62_INTERRUPT - Selects the interrupt level for CAN Mailbox 62  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 62.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX62_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX62_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX62_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   63       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX63_CTRL - Activate/Deactivate CAN Mailbox 63  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX63_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX63_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX63_DATALENGTHCODE - Enter the data length code for CAN Mailbox 63  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX63_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX63_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX63_DIRECTION - Select the Message Direction for CAN Mailbox 63  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX63_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX63_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 63  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX63_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX63_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 63  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX63_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX63_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 63  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 63
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX63_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX63_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 63  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 63.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX63_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX63_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX63_INTERRUPT - Selects the interrupt level for CAN Mailbox 63  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 63.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX63_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX63_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX63_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                 M  A  I  L  B  O  X   64       C  O  N  F  I  G  U  R  A  T  I  O  N  S   
 **********************************************************************************************************************/  
/**********************************************************************************************************************
 * CAN_MAILBOX64_CTRL - Activate/Deactivate CAN Mailbox 64  
 **********************************************************************************************************************
 * @brief           This configuration activiates/deactivates the CAN mailbox.
 * @param      		User shall use one of the following defined macro
 *             		CAN_DRIVER_ENABLE  - Activiates the Mailbox and its configurations
 *             		CAN_DRIVER_DISABLE - Deactiviates the Mailbox and its configurations
 *  
 * @ValidCheck      NO
 * @Required        YES
 */
 
#define CAN_DRIVER_MAILBOX64_CTRL    CAN_DRIVER_ENABLE

#if(CAN_MAILBOX64_CTRL == CAN_DRIVER_ENABLE)
	
/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX64_DATALENGTHCODE - Enter the data length code for CAN Mailbox 64  
 **********************************************************************************************************************
 * @brief           Data Length code for mailbox.
 * @param      		1 to 8
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOX64_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX64_DATALENGTHCODE           0x08U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX64_DIRECTION - Select the Message Direction for CAN Mailbox 64  
 **********************************************************************************************************************
 * @brief           Message Direction for mailbox.
 * @param      		CAN_DRIVER_TRANSMIT,CAN_DRIVER_RECEIVE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX64_DIRECTION           CAN_DRIVER_TRANSMIT

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX64_IDENTIFIER - Enter Message identifier in Hex for CAN Mailbox 64  
 **********************************************************************************************************************
 * @brief           Message Identifier Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX64_IDENTIFIER           0x01U

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX64_MASKVALUE - Enter Mask value in Hex for CAN Mailbox 64  
 **********************************************************************************************************************
 * @brief           Message Mask Value Configuration for mailbox.
 * @param      		0x00 to 0x1FFFFFFF
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX64_MASKVALUE           0x000007FFU

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX64_EOBCTRL - Set/Clear End of Block Indication for CAN Mailbox 64  
 **********************************************************************************************************************
 * @brief           End of Block Indication for CAN Mailbox 64
 * @param      		CAN_DRIVER_NOTANEOB - The message object is part of a FIFO Buffer block and is not the last message 
					object of this FIFO Buffer block.
					
					CAN_DRIVER_EOB - The message object is a single message object or the last message object 
					in a FIFO Buffer Block.
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX64_EOBCTRL           CAN_DRIVER_NOTANEOB

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX64_INTERRUPT_CTRL - Enable/Disable Interrupt for CAN Mailbox 64  
 **********************************************************************************************************************
 * @brief           Interrupt Configurations for mailbox 64.
 * @param      		CAN_DRIVER_ENABLE,CAN_DRIVER_DISABLE
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE)
 */
 
#define CAN_DRIVER_MAILBOX64_INTERRUPT_CTRL      CAN_DRIVER_ENABLE

#if (CAN_DRIVER_MAILBOX64_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE)

/**********************************************************************************************************************
 * CAN_DRIVER_MAILBOX64_INTERRUPT - Selects the interrupt level for CAN Mailbox 64  
 **********************************************************************************************************************
 * @brief           Interrupt level Configurations for mailbox 64.
 * @param      		CAN_HIGHPRIORITY,CAN_LOWPRIORITY
 * @ValidCheck      YES
 * @Required        Only if Mailbox is activated (CAN_MAILBOXX_CTRL == CAN_DRIVER_ENABLE) and mailbox interrupt is enabled
 *                  (CAN_DRIVER_MAILBOX64_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE) 
 */
 
#define CAN_DRIVER_MAILBOX64_INTERRUPT_PRIORITY           CAN_HIGHPRIORITY

#endif /*CAN_DRIVER_MAILBOX64_INTERRUPT_CTRL   ==   CAN_DRIVER_ENABLE*/

/**********************************************************************************************************************
 *                                              E N D   O F   S O F T W A R E                                         
 **********************************************************************************************************************/
#ifdef __cplusplus
}
#endif

/**********************************************************************************************************************
                                                R E V I S I O N   H I S T O R Y                                        
***********************************************************************************************************************
**********************************************************************************************************************
     REVISION NUMBER      : V1.0.1                                                                                   
     REVISION DATE        : MM/DD/YYYY                                                                               
     CREATED / REVISED BY : Balaji Panneerselvam(Template Version)                                        
     DESCRIPTION          : Added Mailbox Configurtions                                                                          
---------------------------------------------------------------------------------------------------------------------
***********************************************************************************************************************
**********************************************************************************************************************
     REVISION NUMBER      : V1.0.0                                                                                   
     REVISION DATE        : MM/DD/YYYY                                                                               
     CREATED / REVISED BY : Balaji Panneerselvam(Template Version)                                        
     DESCRIPTION          : Initial version                                                                          
---------------------------------------------------------------------------------------------------------------------
***********************************************************************************************************************/
#endif /* CANDRIVER_CFG_H */
