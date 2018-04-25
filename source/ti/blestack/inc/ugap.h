/******************************************************************************

 Group: CMCU, SCS
 Target Device: CC2640R2

 ******************************************************************************
 
 Copyright (c) 2009-2017, Texas Instruments Incorporated
 All rights reserved.

 IMPORTANT: Your use of this Software is limited to those specific rights
 granted under the terms of a software license agreement between the user
 who downloaded the software, his/her employer (which must be your employer)
 and Texas Instruments Incorporated (the "License"). You may not use this
 Software unless you agree to abide by the terms of the License. The License
 limits your use, and you acknowledge, that the Software may not be modified,
 copied or distributed unless embedded on a Texas Instruments microcontroller
 or used solely and exclusively in conjunction with a Texas Instruments radio
 frequency transceiver, which is integrated into your product. Other than for
 the foregoing purpose, you may not use, reproduce, copy, prepare derivative
 works of, modify, distribute, perform, display or sell this Software and/or
 its documentation for any purpose.

 YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
 PROVIDED “AS IS” WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE,
 NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
 TEXAS INSTRUMENTS OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT,
 NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER
 LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
 INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE
 OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT
 OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
 (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

 Should you have any questions regarding your right to use this Software,
 contact Texas Instruments Incorporated at www.TI.com.

 ******************************************************************************
 Release Name: simplelink_cc2640r2_sdk_01_50_00_58
 Release Date: 2017-10-17 18:09:51
 *****************************************************************************/

/**
 *  @addtogroup Micro_BLE_Stack
 *  @{
 *  @defgroup UGAP Micro Gap Layer
 *  @{
 *  @file       ugap.h
 *  @brief  Micro BLE GAP API
 *
 *  This file contains the interface to the Micro GAP Layer.
 */

#ifndef UGAP_H
#define UGAP_H

#ifdef __cplusplus
extern "C"
{
#endif

/*-------------------------------------------------------------------
 * INCLUDES
 */

/*-------------------------------------------------------------------
 * CONSTANTS
 */

/** @defgroup UGAP_Constants Micro GAP Constants
 * @{
 */

/// @brief Duty Control Time Unit
#define UGAP_DUTY_TIME_UNIT    100L  //!< 100 ms unit

#if defined(FEATURE_BROADCASTER)

/** @defgroup UGAP_States uGAP Broadcaster States
 * @{
 */
#define UGAP_BCAST_STATE_INVALID     0 //!< Invalid state. Not even initialized
#define UGAP_BCAST_STATE_INITIALIZED 1 //!< Initialized. Waiting for start request
#define UGAP_BCAST_STATE_IDLE        2 //!< Advertising or Waiting stopped
#define UGAP_BCAST_STATE_ADVERTISING 3 //!< Advertising
#define UGAP_BCAST_STATE_WAITING     4 //!< Advertising paused during duty off period
#define UGAP_BCAST_STATE_SUSPENDED   5 //!< Advertising or Waiting is suspended
/** @} End UGAP_States */

/** @defgroup UGAP_Events uGAP Broadcaster Events
 * @{
 */
#define UGB_EVT_STATE_CHANGE       1 //!< Broadcaster's state has changed
#define UGB_EVT_ADV_PREPARE        2 //!< About to issue the next adv. Prepare adv payload
#define UGB_EVT_ADV_POSTPROCESS    3 //!< Adv has just been done. Do post processing if necessary
/** @} End UGAP_Events */
#endif /* FEATURE_BROADCASTER */

#if defined(FEATURE_OBSERVER)

/** @defgroup UGAP_Scan_States uGAP Scanning States
 * @{
 */
#define UGAP_SCAN_STATE_INVALID     0 //!< Invalid state. Not even initialized
#define UGAP_SCAN_STATE_INITIALIZED 1 //!< Initialized. Waiting for start request
#define UGAP_SCAN_STATE_IDLE        2 //!< Scanning stopped or Waiting stopped
#define UGAP_SCAN_STATE_SCANNING    3 //!< Scanning
#define UGAP_SCAN_STATE_WAITING     4 //!< Scanning pulsed in Scan intervl
#define UGAP_SCAN_STATE_SUSPENDED   5 //!< Scanning or Waiting is suspended
/** @} End UGAP_Scan_States */

/** @defgroup UGAP_Observer_Events uGAP Observer Events
 * @{
 */
#define UGAP_OBSERVER_EVT_STATE_CHANGE         4 //!< Observer's state has changed
#define UGAP_OBSERVER_EVT_SCAN_INDICATION      5 //!< Scan indication
#define UGAP_OBSERVER_EVT_SCAN_WINDOW_COMPLETE 6 //!< Scan window completed
/** @} End UGAP_Observer_Events */
#endif /* FEATURE_OBSERVER */
  
#if defined(FEATURE_MONITOR)

/** @defgroup UGAP_Monitor_States uGAP Monitoring States
 * @{
 */
#define UGAP_MONITOR_STATE_INVALID     0 //!< Invalid state. Not even initialized
#define UGAP_MONITOR_STATE_INITIALIZED 1 //!< Initialized. Waiting for start request
#define UGAP_MONITOR_STATE_IDLE        2 //!< Monitoring stopped
#define UGAP_MONITOR_STATE_MONITORING  3 //!< Monitor scanning
/** @} End UGAP_Monitor_States */

/** @defgroup UGAP_Monitor_Events uGAP Monitoring Events
 * @{
 */
#define UGAP_MONITOR_EVT_STATE_CHANGE         7 //!< Monitor's state has changed
#define UGAP_MONITOR_EVT_MONITOR_INDICATION   8 //!< Monitor indication
#define UGAP_MONITOR_EVT_MONITOR_COMPLETE     9 //!< Monitor completed
/** @} End UGAP_Monitor_Events */
#endif /* FEATURE_MONITOR */  
  
/** @} End UGAP_Constants */

/*-------------------------------------------------------------------
 * TYPEDEFS
 */

#if defined(FEATURE_BROADCASTER)

/** @defgroup UGAP_Structures Micro GAP Broadcaster Structures
 * @{
 */
typedef uint8 ugapBcastState_t;      //!< Broadcaster state

/** @} End UGAP_Structures */

/** @defgroup UGAP_Callbacks Micro GAP Broadcaster Callbacks
 * @{
 */

/**
 * @brief Callback of when the Broadcaster's state changes.
 *
 * @param state @ref UGAP_States
 */
typedef void (*ugapBcastStateChangeCb_t)(ugapBcastState_t state);

/**
 * @brief Callback of when the next Advertising Event is about to start
 *
 * The application can use this to update the payload if necessary
 */
typedef void (*ugapBcastAdvPrepareCb_t)(void);

/**
 * @brief  Callback of when an Advertising Event has just been done.
 *
 * @param status status of advertising done event
 */
typedef void (*ugapBcastAdvDoneCb_t)(bStatus_t status);

/**
 * @brief  Set of Broadcaster callbacks - must be setup by the application.
 */
typedef struct
{
  ugapBcastStateChangeCb_t  pfnStateChangeCB; //!< State change notification
  ugapBcastAdvPrepareCb_t   pfnAdvPrepareCB;  //!< Notification for Adv preperation
  ugapBcastAdvDoneCb_t      pfnAdvDoneCB;     //!< Notification of Adv event done
} ugapBcastCBs_t;

PACKED_TYPEDEF_STRUCT {
  ugapBcastState_t state; //!< new state
} ugapBcastMsgStateChange_t; //!< Message payload for the event @ref UGB_EVT_STATE_CHANGE

PACKED_TYPEDEF_STRUCT {
  bStatus_t      status; //!< advertising post process status
} ugapBcastMsgAdvPostprocess_t; //!< Message payload for the event @ref UGB_EVT_ADV_POSTPROCESS

/** @} End UGAP_Callbacks */

#endif /* FEATURE_BROADCASTER */

#if defined(FEATURE_OBSERVER)

/** @defgroup UGAP_Observer_Structures Micro GAP Observer Structures
 * @{
 */
typedef uint8 ugapObserverScan_State_t;      //!< Observer state

/** @} End UGAP_Observer_Structures */

/** @defgroup UGAP_Observer_Callbacks Micro GAP Observer allbacks
 * @{
 */

/**
 * @brief Callback of when the Observer's state changes.
 *
 * @param state @ref UGAP_Observer_Structures
 */
typedef void (*ugapObserverStateChangeCb_t)(ugapObserverScan_State_t state);

/**
 * @brief  Callback of when a packet is received.
 *
 * @param status status of a scan
 * @param len length of the payload
 * @param pPayload pointer to payload
 */
typedef void (*ugapObserverScanIndicationCb_t)(bStatus_t status, uint8_t len, uint8_t *pPayload);

/**
 * @brief  Callback of when a scan has just been done.
 *
 * @param status status of a scan
 */
typedef void (*ugapObserverScanWindowCompleteCb_t)(bStatus_t status);

/**
 * @brief  Set of Observer callbacks - must be setup by the application.
 */
typedef struct
{
  ugapObserverStateChangeCb_t         pfnStateChangeCB; //!< State change notification
  ugapObserverScanIndicationCb_t      pfnScanIndicationCB; //!< Scan indication with payload
  ugapObserverScanWindowCompleteCb_t  pfnScanWindowCompleteCB; //!< Notification of scan window complete
} ugapObserverScanCBs_t;

PACKED_TYPEDEF_STRUCT {
  ugapObserverScan_State_t state; //!< new state
} ugapObserverMsgStateChange_t; //!< Message payload for the event @ref UGAP_OBSERVER_EVT_STATE_CHANGE

PACKED_TYPEDEF_STRUCT {
  bStatus_t status; //!< scan indication process status
  uint8_t len; //!< Rx payload length
  uint8_t *pPayload; //!< pointer to Rx payload
} ugapObserverMsgScanIndication_t; //!< Message payload for the event @ref UGAP_OBSERVER_EVT_SCAN_INDICATION

PACKED_TYPEDEF_STRUCT {
  bStatus_t status; //!< scan complete process status
} ugapObserverMsgScanWindowComplete_t; //!< Message payload for the event @ref UGAP_OBSERVER_EVT_SCAN_WINDOW_COMPLETE

/** @} End UGAP_Observer_Callbacks */

#endif /* FEATURE_OBSERVER */

#if defined(FEATURE_MONITOR)

/** @defgroup UGAP_Monitor_Structures Micro GAP Monitor Structures
 * @{
 */
typedef uint8 ugapMonitorState_t;      //!< Monitor state

/** @} End UGAP_Monitor_Structures */

/** @defgroup UGAP_Monitor_Callbacks Micro GAP Monitor Callbacks
 * @{
 */

/**
 * @brief Callback of when the Monitor's state changes.
 *
 * @param state @ref UGAP_Monitor_Structures
 */
typedef void (*ugapMonitorStateChangeCb_t)(ugapMonitorState_t state);

/**
 * @brief  Callback of when a packet is received.
 *
 * @param status status of a monitoring scan
 * @param sessionId session ID
 * @param len length of the payload
 * @param pPayload pointer to payload
 */
typedef void (*ugapMonitorIndicationCb_t)(bStatus_t status, uint8_t sessionId, uint8_t len, uint8_t *pPayload);

/**
 * @brief  Callback of when a scan monitoring has just been done.
 *
 * @param status status of a scan
 * @param sessionId session ID
 */
typedef void (*ugapMonitorCompleteCb_t)(bStatus_t status, uint8_t sessionId);

/**
 * @brief  Set of Observer callbacks - must be setup by the application.
 */
typedef struct
{
  ugapMonitorStateChangeCb_t  pfnStateChangeCB; //!< State change notification
  ugapMonitorIndicationCb_t   pfnMonitorIndicationCB; //!< Scan monitor indication with payload
  ugapMonitorCompleteCb_t     pfnMonitorCompleteCB; //!< Notification of monitoring scan complete
} ugapMonitorCBs_t;

PACKED_TYPEDEF_STRUCT {
  ugapMonitorState_t state; //!< new state
} ugapMsgStateChange_t; //!< Message payload for the event @ref UGAP_MONITOR_EVT_STATE_CHANGE

PACKED_TYPEDEF_STRUCT {
  bStatus_t status; //!< monitor indication process status
  uint8_t sessionId; //!< monitor session ID
  uint8_t len; //!< Rx payload length
  uint8_t *pPayload; //!< pointer to Rx payload
} ugapMsgMonitorIndication_t; //!< Message payload for the event @ref UGAP_MONITOR_EVT_MONITOR_INDICATION

PACKED_TYPEDEF_STRUCT {
  bStatus_t status; //!< monitoring scan complete process status
  uint8_t sessionId; //!< monitor session ID
} ugapMsgMonitorComplete_t; //!< Message payload for the event @ref UGAP_MONITOR_EVT_MONITOR_COMPLETE

/** @} End UGAP_Monitor_Callbacks */

#endif /* FEATURE_MONITOR */

/*-------------------------------------------------------------------
 * MACROS
 */

/*-------------------------------------------------------------------
 * API FUNCTIONS
 */

#if defined(FEATURE_BROADCASTER)
/**
 * @brief   Initialize Micro Broadcaster
 *
 * @param   pCBs - a set of application callbacks for Broadcaster
 *
 * @return  @ref SUCCESS
 * @return  @ref INVALIDPARAMETER
 * @return  @ref FAILURE
 */
bStatus_t ugap_bcastInit(ugapBcastCBs_t* pCBs);

/**
 * @brief   Set Broadcaster Duty On/Off time
 *
 * @param   dutyOnTime  - Time period during which the Broadcaster
 *                        is in Advertising state. 100 ms unit. This cannot be
 *                        0 unless dutyOffTime is also 0.
 * @param   dutyOffTime - Time period during which the Broadcaster
 *                        is in Waiting state. 100 ms unit. If this is 0,
 *                        Duty Control is disabled regardless of dutyOnTime.
 *
 * @return  @ref SUCCESS
 * @return  @ref INVALIDPARAMETER
 */
bStatus_t ugap_bcastSetDuty(uint16 dutyOnTime, uint16 dutyOffTime);

/**
 * @brief   Start Broadcaster. Proceed the state from either Initialized or IDLE
 *          to Advertising.
 *
 * @param   numAdvEvent - # of Advertising events to be performed before
 *                        the Broadcaster state goes to IDLE. If this is 0,
 *                        the Broadcaster will keep staying in Advertising or
 *                        Advertising and Waiting alternately unless an error
 *                        happens or the application requests to stop.
 *
 * @return  @ref SUCCESS
 * @return  @ref FAILURE
 * @return  @ref INVALIDPARAMETER
 */
bStatus_t ugap_bcastStart(uint16 numAdvEvent);

/**
 * @brief   Stop Broadcaster. Proceed the state from either Advertising or
 *          Waiting to IDLE.
 *
 * @return  @ref SUCCESS
 * @return  @ref INVALIDPARAMETER
 * @return  @ref FAILURE
 */
bStatus_t ugap_bcastStop(void);
#endif /* FEATURE_BROADCASTER */

#if defined(FEATURE_OBSERVER)
/**
 * @brief   Initialize Micro Observer
 *
 * @param   pCBs - a set of application callbacks for Ovserver
 *
 * @return  @ref SUCCESS
 * @return  @ref FAILURE
 * @return  @ref INVALIDPARAMETER
 */
bStatus_t ugap_scanInit(ugapObserverScanCBs_t* pCBs);

/**
 * @brief   Start Observer scanning. Proceed the state from either Initialized
 *          or IDLE to Scanning.
 *
 * @return  @ref SUCCESS
 * @return  @ref FAILURE
 */
bStatus_t ugap_scanStart(void);

/**
 * @brief   Stop Observer scanning. Proceed the state from Scanning to Idle.
 *
 * @return  @ref SUCCESS
 * @return  @ref FAILURE
 */
bStatus_t ugap_scanStop(void);

/**
 * @brief   Suspend Observer scanning. Proceed the state from either Waiting
 *          or Scanning to Suspended. Suspend the Obesrver to make room
 *          for the Advertiser to transmit.
 *
 * @return  @ref SUCCESS
 * @return  @ref FAILURE
 */
bStatus_t ugap_scanSuspend(void);

/**
 * @brief   Resume a suspended Observer. Proceed the state from Suspended 
 *          to Scanning to Waiting. 
 *
 * @return  @ref SUCCESS
 * @return  @ref FAILURE
 */
bStatus_t ugap_scanResume(void);

/**
 * @brief   uGAP scan request
 *
 * @param   scanChanMap - Channels to scan advertising PDUs. One of more
 *                        of channels 37, 38 & 39. 
 * @param   scanWindow - Scan window to listen on a primary advertising
 *                       channel index for the duration of the scan window.
 *                       Unit in 0.625 ms; range from 2.5 ms to 40.959375 s.
 * @param   scanInterval - Scan interval. This is defined as the start of
 *                         two consecutive scan windows. Unit in 0.625 ms; 
 *                         range from 2.5 ms to 40.959375 s. When scanInterval
 *                         is the same as sacnWindow, a continuous scan 
 *                         is requested.
 *
 * @return  @ref SUCCESS
 * @return  @ref INVALIDPARAMETER
 */
bStatus_t ugap_scanRequest(uint8_t scanChanMap, uint16_t scanWindow, uint16_t scanInterval);

#endif /* FEATURE_OBSERVER */

#if defined(FEATURE_MONITOR)
/**
 * @brief   Initialize Micro Monitor
 *
 * @param   pCBs - a set of application callbacks for Monitor
 *
 * @return  @ref SUCCESS
 * @return  @ref FAILURE
 * @return  @ref INVALIDPARAMETER
 */
bStatus_t ugap_monitorInit(ugapMonitorCBs_t* pCBs);

/**
 * @brief   Start Monitor scanning. Proceed the state from either 
 *          Initialized or Idle to Monitoring.
 *
 * @return  @ref SUCCESS
 * @return  @ref FAILURE
 */
bStatus_t ugap_monitorStart(void);

/**
 * @brief   Stop Monitor scanning. Proceed the state from Monitoring
 *          to Idle.
 *
 * @return  @ref SUCCESS
 * @return  @ref FAILURE
 */
bStatus_t ugap_monitorStop(void);

/**
 * @brief   uGAP monitor request
 *
 * @param   channel - Channels to monitor.
 * @param   accessAddr - Access address. 0xFFFFFFFF is used as a
 *                       wildcard access address. An error status will 
 *                       be returned if the channel is one of 37, 38, 
 *                       or 39 but the accessAddr is not 0x8E89BED6.
 * @param   startTime - Absolute start time in RAT ticks.
 * @param   duration - Scan window per scanChanIndexchanIndex. A monitor
 *                     complete time-out statuscallback will be sent to 
 *                     the application. A zero indicates a continuous 
 *                     scan. Unit in 0.625 ms; range from 2.5 ms to 
 *                     40.959375 s.
 *
 * @return  @ref SUCCESS
 * @return  @ref INVALIDPARAMETER
 */
bStatus_t ugap_monitorRequest(uint8_t channel, 
                              uint32_t accessAddr,
                              uint32_t startTime,
                              uint16_t duration);

#endif /* FEATURE_MONITOR */

/*-------------------------------------------------------------------
-------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* UGAP_H */

/** @} End UGAP */

/** @} */ // end of Micro_BLE_Stack
