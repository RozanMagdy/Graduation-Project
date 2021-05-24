#ifndef __CANIF_CBK_H__
#define __CANIF_CBK_H__


#include "Can_GeneralTypes.h"
#include "ComStack_Types.h"


void CanIf_TxConfirmation(PduIdType CanTxPduId);


void CanIf_CancelTxConfirmation( PduIdType CanTxPduId , const PduInfoType* PduInfoPtr);


/**
 * \brief This callout function is called whenever a CAN message is
 *  received in CAN driver.
 */
void CanIf_RxIndication( const Can_HwType* Mailbox , const PduInfoType* PduInfoPtr);


void CanIf_ControllerModeIndication( uint8 ControllerId, Can_ControllerStateType ControllerMode );



void CanIf_ControllerBusOff(uint8 ControllerId);










#endif

