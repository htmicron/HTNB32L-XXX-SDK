#ifndef PSIF_HDR_EVENT_H
#define PSIF_HDR_EVENT_H

/******************************************************************************
 ******************************************************************************
 Copyright:      - 2018- Copyrights of Qualcomm Ltd.
 File name:      - psifevent.h
 Description:    - ps if related event header file
 History:        - 11/01/2018, Originated by xwang
 ******************************************************************************
******************************************************************************/
#include "netmgr.h"
#include "netif.h"


/****************************************************************************** 
 *****************************************************************************
 * STRUCT
 *****************************************************************************
******************************************************************************/


/******************************************************************************
 *****************************************************************************
 * Functions
 *****************************************************************************
******************************************************************************/
void PsifSendNetifInfoInd(struct netif *pNetif, NmNetifStatus status, NmNetifStatusChangeCause cause);

#endif

