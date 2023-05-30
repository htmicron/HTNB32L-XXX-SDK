#ifndef __PS_DIAL_PLMN_CFG_H__
#define __PS_DIAL_PLMN_CFG_H__
/******************************************************************************
 ******************************************************************************
 Copyright:      - 2017- Copyrights of Qualcomm Ltd.
 File name:      - psdial_plmn_cfg.h
 Description:    - PLMN static configuation functions
 History:        - 06/26/2018, Originated by jcweng
 ******************************************************************************
******************************************************************************/
#include "commontypedef.h"

/******************************************************************************
 *****************************************************************************
 * MARCO
 *****************************************************************************
******************************************************************************/

#define DIAL_CFG_IPV4       0
#define DIAL_CFG_IPV6       1
#define DIAL_CFG_IPV4V6     2
#define DIAL_CFG_NON_IP     3

#define DIAL_CFG_PRFER_BAND_NUM 8


/******************************************************************************
 *****************************************************************************
 * STRUCT
 *****************************************************************************
******************************************************************************/

typedef struct DialPlmnCfgInfoTag
{
    struct {
        UINT16 mcc;
        UINT16 mnc;
    } plmn;

    BOOL    eitf;   /*ESM information transfer flag*/
    UINT8   ipType;

    CHAR    *pApn;
    CHAR    *pShortName;
    CHAR    *pLongName;
    UINT8   preBand[DIAL_CFG_PRFER_BAND_NUM];   /*prefer band*/
    CHAR    *pDefIp4Dns1;
    CHAR    *pDefIp4Dns2;
    CHAR    *pDefIp6Dns1;
    CHAR    *pDefIp6Dns2;
    /* PSM Values */
    UINT8    t3412mode;
    UINT8    t3412unit;
    UINT8    t3412val;
    UINT8    t3324mode;
    UINT8    t3324unit;
    UINT8    t3324val;
    
    /* DRX Values */
    UINT8    drxmode;
    UINT8    drxvalue;
    UINT8    ptw;

}DialPlmnCfgInfo;



/******************************************************************************
 ******************************************************************************
 * External global variable
 ******************************************************************************
******************************************************************************/



/******************************************************************************
 *****************************************************************************
 * Functions
 *****************************************************************************
******************************************************************************/
const DialPlmnCfgInfo* psDialGetPlmnCfgByPlmn(UINT16 mcc, UINT16 mnc);


#endif

