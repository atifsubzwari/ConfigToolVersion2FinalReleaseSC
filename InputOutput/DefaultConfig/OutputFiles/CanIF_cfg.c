#ifndef CANIF_CFG_C
#define CANIF_CFG_C
/*********************************************************************************************************************** 
 *    DISCLAIMER                                                                                                        
 *   Copyright (C) 2011, 2016 Niyata Infotech Ptv. Ltd. All rights reserved.                                              
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * @author              Author : Akshay Bavalatti (akshayb@niyatainfotech.com)                                                                         
 ***********************************************************************************************************************/
/***********************************************************************************************************************
 *                                                F I L E  D E S C R I P T I O N                                           
*---------------------------------------------------------------------------------------------------------------------
 *  @brief                                                                                                             
*                                                                                                                     
 *  File name                       : CanIF_cfg.c                                                                         
 *  Version                         : V1.0.0                                                                           
*  Micros supported                : Micro Agnostic (Independant)                                                            
*  Compilers supported             : XXXX                                                                           
*  Platforms supported             : XXXX                                                                            
*  Description                     : This file contains precompile configuration settings for CanIF                                
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
 *                          I N C L U D E   F I L E S
 ***********************************************************************************************************************/

# include "CanIF_cfg.h"
#include "CanMgr.h"

/***********************************************************************************************************************
 *                          C O N F I G U R A T I O N
***********************************************************************************************************************/

/**********************************************************************************************************************
  CanIf_BusOffNotificationFctPtr
**********************************************************************************************************************/
/**
 * 
 */ 
const CanIf_BusOffNotificationFctType CanIf_BusOffNotificationFctPtr = &CanMgr_BusoffIndication ;

#ifdef CANIF_BASIC_CAN
/**********************************************************************************************************************
 CanIf_CanIfCtrlId2MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
\var    CanIf_CanIfCtrlId2MappedTxBuffersConfig
\brief  CAN controller configuration - mapped Tx-buffer(s).
\details
 Element                          Description
 MappedTxBuffersConfigEndIdx      the end index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
 MappedTxBuffersConfigStartIdx    the start index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
*/ 
const CanIf_CanIfCtrlId2MappedTxBuffersConfigType CanIf_CanIfCtrlId2MappedTxBuffersConfig[CANIF_CFG_MAX_CONTROLLER] = {
  /* Index                               MappedTxBuffersConfigEndIdx              MappedTxBuffersConfigStartIdx */        
 { /*0*/                                           0U ,                                                0U  }                                                       
};

#endif
/**********************************************************************************************************************
 CanIf_CtrlModeIndicationFctPtr
**********************************************************************************************************************/
const CanIf_CtrlModeIndicationFctType CanIf_CtrlModeIndicationFctPtr = NULL;
/**********************************************************************************************************************
CanIf_MailBoxConfig
**********************************************************************************************************************/
/** 
\var    CanIf_MailBoxConfig
\brief  Mailbox table.
\details
 Element                 Description
 CtrlStatesIdx           the index of the 1:1 relation pointing to CanIf_CtrlStates
PduIdFirst              "First" PDU mapped to mailbox.
 PduIdLast               "Last" PDU mapped to mailbox.
TxBufferCfgIdx          the index of the 0:1 relation pointing to CanIf_TxBufferPrioByCanIdByteQueueConfig
TxBufferHandlingType
MailBoxType             Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused.
*/ 
const CanIf_MailBoxConfigType CanIf_MailBoxConfig[CANIF_TOTAL_NUM_OF_MAIL_BOX] = {
   /* Index			CtrlStatesIdx			PduIdLast							PduIdFirst									TxBufferCfgIdx																		TxBufferHandlingType												MailBoxType      */         
  {  /*0 */					0U ,						0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG, 		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*1 */					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*2 */					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*3 */					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*4 */					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*5 */					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*6 */					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*7 */					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*8 */					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*9 */					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*10*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*11*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*12*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*13*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*14*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*15*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*16*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*17*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*18*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*19*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*20*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*21*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*22*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*23*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*24*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*25*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*26*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*27*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*28*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*29*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*30*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*31*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*32*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*33*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*34*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*35*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*36*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*37*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*38*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*39*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*40*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*41*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*42*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*43*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*44*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*45*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*46*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*47*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*48*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*49*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*50*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*51*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*52*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*53*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*54*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*55*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*56*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*57*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*58*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*59*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*60*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*61*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*62*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  },
  {  /*63*/					0U,							0U  /*Unused*/ ,			0U  /*Unused */ ,			CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG,		CANIF_TXBUFFER_HANDLINGTYPE_NONE, 					CANIF_UnusedCANMailbox  }
};


#ifdef CANIF_BASIC_CAN
/**********************************************************************************************************************
CanIf_MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MappedTxBuffersConfig
  \brief  Mapped Tx-buffer(s)
  \details
  Element             Description
  MailBoxConfigIdx    the index of the 1:1 relation pointing to CanIf_MailBoxConfig
*/ 
const CanIf_MappedTxBuffersConfigType CanIf_MappedTxBuffersConfig[CANIF_TOTAL_NUM_OF_MAILBOX_CONIGURED_TO_STORE_TX_BUFFERS] = {
      /* Index    MailBoxConfigIdx */     

};
#endif
/**********************************************************************************************************************
  CanIf_RxIndicationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_RxIndicationFctList
  \brief  Rx indication functions table.
  \details
  Element               Description
  RxIndicationFct       Rx indication function.
  RxIndicationLayout    Layout of Rx indication function.
*/
const CanIf_RxIndicationFctListType CanIf_RxIndicationFctList[CANIF_TOTAL_RX_INIDICATION_FUNC] = {
  /* Index                RxIndicationFct                                                RxIndicationLayout   */       
{ /*   0 */       { (CanIf_AdvancedRxIndicationFctType)&CanMgr_RxIndication }  ,  CanIf_AdvancedRxIndicationLayout   },
{ /*   1 */       { NULL_PTR }                                                 ,  CanIf_NmRxIndicationLayout         },  
{ /*   2 */       { NULL_PTR }                                                 ,  CanIf_AdvancedRxIndicationLayout   },  
{ /*   3 */       { NULL_PTR }                                                 ,  CanIf_AdvancedRxIndicationLayout   },  
{ /*   4 */       { NULL_PTR }                                                 ,  CanIf_AdvancedRxIndicationLayout   }   
};
/**********************************************************************************************************************
  CanIf_RxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfig
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  Dlc                       Data length code.
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
*/
const CanIf_RxPduConfigType CanIf_RxPduConfig[CANIF_TOTAL_RX_PDU] = {
  /*		Index			RxPduCanId					RxPduMask					UpperPduId										Dlc					 RxIndicationFctListIdx     */           
};

#ifdef CANIF_BASIC_CAN
/**********************************************************************************************************************
   CanIf_TxBufferPrioByCanIdByteQueueConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueConfig
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE
  \details
  Element                                             Description
  TxBufferPrioByCanIdBaseIdx                          the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase
  TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx      the end index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusLength      the number of relations pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx    the start index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
*/

const CanIf_TxBufferPrioByCanIdByteQueueConfigType CanIf_TxBufferPrioByCanIdByteQueueConfig[CANIF_TOTAL_NUM_OF_MAILBOX_CONIGURED_TO_STORE_TX_BUFFERS] = {
  /* Index    TxBufferPrioByCanIdBaseIdx       TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx    TxBufferPrioByCanIdByteQueueMappedTxPdusLength    TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx  */ 

};

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE: Mapped Tx-PDUs
  \details
  Element           Description
  TxPduConfigIdx    the index of the 1:1 relation pointing to CanIf_TxPduConfig
*/ 

const CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus[CANIF_TOTAL_TX_BUFFER_MESSAGE] = {
  /* Index    TxPduConfigIdx */

};

#endif
/**********************************************************************************************************************
  CanIf_TxConfirmationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_TxConfirmationFctList
  \brief  Tx confirmation functions table.
*/ 
const CanIf_TxConfirmationFctType CanIf_TxConfirmationFctList[CANIF_TOTAL_TX_CONFIRMATION_FUNC_LIST] = {
  /* Index     TxConfirmationFctList    Referable Keys */ 
  /*     0 */ NULL_PTR ,
  /*     1 */ NULL_PTR,
  /*     2 */ NULL_PTR,
  /*     3 */ (CanIf_TxConfirmationFctType)&CanMgr_TxConfirmation,
  /*     4 */ NULL_PTR
};

/**********************************************************************************************************************
  CanIf_TxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfig
  \brief  Tx-PDUs - configuration.
   \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle ID (8bit / 16bit).
   CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  Dlc                         Data length code.
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
*/ 
const CanIf_TxPduConfigType CanIf_TxPduConfig[CANIF_TOTAL_TX_MESSAGES] = {
  /*		Index				CanId								TxPduMask								UpperLayerTxPduId								CtrlStatesIdx				Dlc		tMailBoxConfigIdx		TxConfirmationFctListIdx    */

};
#ifdef CANIF_BASIC_CAN
/**********************************************************************************************************************
  CanIf_TxPduQueueIndex
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduQueueIndex
  \brief  Indirection table: Tx-PDU handle ID to corresponding Tx buffer handle ID. NOTE: Only BasicCAN Tx-PDUs have a valid indirection into the Tx buffer.
  \details
  Element       Description
  TxQueueIdx    the index of the 0:1 relation pointing to CanIf_TxQueue
*/
const CanIf_TxPduQueueIndexType CanIf_TxPduQueueIndex[CANIF_TOTAL_TX_MESSAGES] = {
  /* Index    TxQueueIdx                              */      
};

#endif

/**********************************************************************************************************************
  CanIf_CtrlStates
**********************************************************************************************************************/
/** 
  \var    CanIf_CtrlStates
  \details
  Element     Description
  CtrlMode    Controller mode.
  PduMode     PDU mode state.
*/ 
CanIf_CtrlStatesUType CanIf_CtrlStates;  
#ifdef CANIF_BASIC_CAN
/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdBase
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdBase
  \brief  Variable declaration - Tx-buffer: PRIO_BY_CANID as byte/bit-queue. Stores at least the QueueCounter.
*/

CanIf_TxBufferPrioByCanIdBaseUType CanIf_TxBufferPrioByCanIdBase;  

/**********************************************************************************************************************
  CanIf_TxQueue
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueue
  \brief  Variable declaration - Tx byte queue.
*/
CanIf_TxQueueUType CanIf_TxQueue;  

#endif

#endif

/**********************************************************************************************************************
                                          R E V I S I O N   H I S T O R Y                                        
***********************************************************************************************************************
***********************************************************************************************************************




***********************************************************************************************************************/

