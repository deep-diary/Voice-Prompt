/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : CAN.h
**     Project     : Voice Prompt
**     Processor   : SKEAZ64MLH4
**     Component   : CAN_LDD
**     Version     : Component 01.112, Driver 01.00, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-11-19, 16:28, # CodeGen: 82
**     Abstract    :
**         This component "CAN_LDD" implements a CAN serial channel.
**     Settings    :
**          Component name                                 : CAN
**          CAN channel                                    : MSCAN
**          Interrupt service                              : Enabled
**            Interrupt TxD                                : INT_MSCAN_TX
**            Interrupt TxD priority                       : medium priority
**            ISR Name                                     : CAN_TxInterrupt
**            Interrupt RxD                                : INT_MSCAN_RX
**            Interrupt RxD priority                       : medium priority
**            ISR Name                                     : CAN_RxInterrupt
**            Interrupt error                              : INT_MSCAN_TX
**            Interrupt error priority                     : medium priority
**            ISR Name                                     : CAN_TxInterrupt
**            Interrupt bus off                            : INT_MSCAN_TX
**            Interrupt bus off priority                   : medium priority
**            ISR Name                                     : CAN_TxInterrupt
**            Interrupt wake up                            : INT_MSCAN_TX
**            Interrupt wake up priority                   : medium priority
**            ISR Name                                     : CAN_TxInterrupt
**          Settings                                       : 
**            Pins                                         : 
**              Rx pin                                     : 
**                Rx pin                                   : PTC6/KBI0_P22/UART1_RX/CAN0_RX
**              Tx pin                                     : 
**                Tx pin                                   : <Automatic>
**            Global acceptance mask                       : no
**            Receiver FIFO                                : Enabled
**              ID filter acceptance mode                  : One 32-bit
**              Invidual acceptance mask table             : Enabled
**                Elements                                 : 2
**                  Element 0                              : 
**                    ID mask                              : 0xFFFFFFFF
**                  Element 1                              : 
**                    ID mask                              : 0xFFFFFFFF
**              ID filter table                            : 
**                Elements                                 : 2
**                  Element 0                              : 
**                    ID mask                              : 0xFFFFFFFF
**                  Element 1                              : 
**                    ID mask                              : 0xFFFFFFFF
**            Message buffers                              : 2
**              Buffer0                                    : 
**                Buffer type                              : Receive
**              Buffer1                                    : 
**                Buffer type                              : Transmit
**            Timer synchronization                        : Disabled
**            Loop mode                                    : no
**            Bus off recovery mode                        : Automatic
**            Listen only mode                             : no
**            Wake up                                      : Disabled
**          Timing                                         : 
**            CAN timing calculator                        : click to run ->
**            Time segment 1                               : 4
**            Time segment 2                               : 2
**            Resync jump width                            : 1
**            Time quanta per bit                          : 7
**            Samples per bit                              : One sample
**            Bit rate                                     : 500 kbit/s
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnFreeTxBuffer                             : Enabled
**              OnFullRxBuffer                             : Enabled
**              OnTransmitWarning                          : Disabled
**              OnReceiveWarning                           : Disabled
**              OnBusOff                                   : Disabled
**              OnWakeUp                                   : Disabled
**              OnError                                    : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init               - LDD_TDeviceData* CAN_Init(LDD_TUserData *UserDataPtr);
**         SetRxIDFilterTable - LDD_TError CAN_SetRxIDFilterTable(LDD_TDeviceData *DeviceDataPtr,...
**         SendFrame          - LDD_TError CAN_SendFrame(LDD_TDeviceData *DeviceDataPtr, LDD_CAN_TMBIndex...
**         ReadFrame          - LDD_TError CAN_ReadFrame(LDD_TDeviceData *DeviceDataPtr, LDD_CAN_TMBIndex...
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file CAN.h
** @version 01.00
** @brief
**         This component "CAN_LDD" implements a CAN serial channel.
*/         
/*!
**  @addtogroup CAN_module CAN module documentation
**  @{
*/         

#ifndef __CAN_H
#define __CAN_H

/* MODULE CAN. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "Cpu.h"


/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define CAN_PRPH_BASE_ADDRESS  0x40024000U
  
/*! Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define CAN_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_CAN_ID))

typedef struct {
  MSCAN_MemMapPtr BaseAddr;            /* Device register memory map base address */
  uint8_t MaxDataLen;                  /* Max number of data to be sent in one frame */
  LDD_CAN_TMBIndex MaxBufferIndex;     /* Number of message buffers */
  LDD_CAN_TMBIndex BuffersNumber;      /* Number of message buffers */
  LDD_CAN_TMBIndex *BuffersIdxToHwPtr; /* Pointer to remap buffers table */
  LDD_CAN_TBufferMask RxBufferMask;    /* Bit mask for message buffers configured as receive */
  LDD_CAN_TMBIndex *HwToRxBuffersIdxPtr; /* Pointer to remap Rx buffers table */
  LDD_CAN_TBufferMask TxBufferMask;    /* Bit mask for message buffers configured as transmit */
  LDD_CAN_TMBIndex *HwToTxBuffersIdxPtr; /* Pointer to remap Tx buffers table */
  LDD_CAN_TBufferMask TxBuffersPendingMask; /* Tx buffer pending mask variable */
  uint8_t Index;                       /* Component instance index (for Deinit method distinction) */
  LDD_TUserData *UserData;             /* RTOS device data structure */
} CAN_TDeviceData;

typedef CAN_TDeviceData *CAN_TDeviceDataPtr; /* Pointer to the device data structure. */

/*
** ===================================================================
**     Method      :  CAN_Init (component CAN_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the "Enable
**         in init. code" is set to "yes" value then the device is also
**         enabled(see the description of the Enable() method). In this
**         case the Enable() method is not necessary and needn't to be
**         generated.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* CAN_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  CAN_SetRxIDFilterTable (component CAN_LDD)
*/
/*!
**     @brief
**         Sets the receive ID filter table element specified by the
**         parameter ElementIdx. This method is available only if
**         receiver FIFO mode is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         ElementIdx      - Index of the ID filter table
**                           element.
**     @param
**         AccCode         - 11-bit Mask could be selected for
**                           a standard frame or 29-bit for an extended
**                           frame. 
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_PARAM_RANGE - Value of receive ID
**                           filter element index is out of range.
**                           ERR_NOTAVAIL - Receive ID filter table
**                           isn't possible change when CAN component is
**                           running, component must be disabled or
**                           switched to freeze mode.
*/
/* ===================================================================*/
LDD_TError CAN_SetRxIDFilterTable(LDD_TDeviceData *DeviceDataPtr, LDD_CAN_TElementIndex ElementIdx, LDD_CAN_TAccCode AccCode);

/*
** ===================================================================
**     Method      :  CAN_ReadFrame (component CAN_LDD)
*/
/*!
**     @brief
**         Reads a frame from the CAN device. The user is informed
**         about CAN reception through OnFullRxBuffer event or
**         GetStateRX method.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         BufferIdx       - Index of the Rx message buffer.
**     @param
**         Frame           - Pointer to the received CAN frame.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED - This component is disabled
**                           by user
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_PARAM_RANGE - Value of buffer index is
**                           out of range.
**                           ERR_PARAM_INDEX - Index of message buffer
**                           is not for receive.
**                           ERR_BUSY - CAN module is busy.
**                           ERR_RXEMPTY - The receive buffer is empty.
**                           ERR_OVERRUN - The receive buffer is overrun.
*/
/* ===================================================================*/
LDD_TError CAN_ReadFrame(LDD_TDeviceData *DeviceDataPtr, LDD_CAN_TMBIndex BufferIdx, LDD_CAN_TFrame *Frame);

/*
** ===================================================================
**     Method      :  CAN_SendFrame (component CAN_LDD)
*/
/*!
**     @brief
**         Sends a frame via the CAN device. This method allow to
**         specify CAN buffer number, message ID, data to be sent,
**         frame type and whether the message will be sent after the
**         request comes. 
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         BufferIdx       - Index of the Tx message buffer.
**     @param
**         Frame           - Pointer to the CAN frame to send.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED - This component is disabled
**                           by user
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_PARAM_RANGE - Value of buffer index is
**                           out of range.
**                           ERR_PARAM_INDEX - Index of message buffer
**                           is not for transmit.
**                           ERR_PARAM_LENGTH - Number of data in the
**                           frame is greater than MaxDataLength.
**                           ERR_PARAM_ATTRIBUTE_SET - Frame type isn't
**                           supported.
**                           ERR_PARAM_VALUE - Value of Tx priority is
**                           fail.
**                           ERR_BUSY - CAN module is busy.
*/
/* ===================================================================*/
LDD_TError CAN_SendFrame(LDD_TDeviceData *DeviceDataPtr, LDD_CAN_TMBIndex BufferIdx, LDD_CAN_TFrame *Frame);

/*
** ===================================================================
**     Method      :  CAN_TxInterrupt (component CAN_LDD)
**
**     Description :
**         Transmit Warning Interrupt
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(CAN_TxInterrupt);

/*
** ===================================================================
**     Method      :  CAN_RxInterrupt (component CAN_LDD)
**
**     Description :
**         Receive Warning Interrupt
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(CAN_RxInterrupt);


/*
** ===================================================================
**     Method      :  CAN_SetClockConfiguration (component CAN_LDD)
**
**     Description :
**         This method changes the clock configuration. During a clock 
**         configuration change the component changes it's setting 
**         immediately upon a request.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void CAN_SetClockConfiguration(LDD_TDeviceData *DeviceDataPtr, LDD_TClockConfiguration ClockConfiguration);


/* END CAN. */

#endif
/* ifndef __CAN_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
