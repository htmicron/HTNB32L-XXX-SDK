#ifndef __CMI_DEV_H__
#define __CMI_DEV_H__
/******************************************************************************
Copyright:      - 2017- Copyrights of Qualcomm Ltd.
File name:      - cmidev.h
Description:    - CMI (CIoT modem interface) device handling interface definition
History:        - 08/09/2017, Originated by jcweng
******************************************************************************/
#include "cmimm.h"

#define CMI_DEV_NUESTATS_THP_PERIOD_SECOND      2
#define CMI_DEV_NCELL_INFO_CELL_NUM             4

typedef enum CMI_DEV_PRIM_ID_TAG
{
    CMI_DEV_PRIM_BASE = 0,
    CMI_DEV_SET_CFUN_REQ = 1, //AT+CFUN
    CMI_DEV_SET_CFUN_CNF,
    CMI_DEV_GET_CFUN_REQ,
    CMI_DEV_GET_CFUN_CNF,
    CMI_DEV_GET_CFUN_CAPA_REQ,
    CMI_DEV_GET_CFUN_CAPA_CNF,

    CMI_DEV_SET_CIOT_BAND_REQ, //AT$QCBAND
    CMI_DEV_SET_CIOT_BAND_CNF,
    CMI_DEV_GET_CIOT_BAND_REQ,
    CMI_DEV_GET_CIOT_BAND_CNF = 10,
    CMI_DEV_GET_CIOT_BAND_CAPA_REQ,
    CMI_DEV_GET_CIOT_BAND_CAPA_CNF,

    CMI_DEV_SET_CIOT_FREQ_REQ, //AT$QCFREQ
    CMI_DEV_SET_CIOT_FREQ_CNF,
    CMI_DEV_GET_CIOT_FREQ_REQ, //AT$QCFREQ?
    CMI_DEV_GET_CIOT_FREQ_CNF,

    CMI_DEV_SET_POWER_STATE_REQ,    //AT+CIOTPOWER
    CMI_DEV_SET_POWER_STATE_CNF,

    CMI_DEV_SET_EXT_CFG_REQ,   //AT$QCCFG
    CMI_DEV_SET_EXT_CFG_CNF = 20,

    CMI_DEV_GET_EXT_CFG_REQ,
    CMI_DEV_GET_EXT_CFG_CNF,

    CMI_DEV_REMOVE_FPLMN_REQ,  //AT$QCRMFPLMN[=<value>]
    CMI_DEV_REMOVE_FPLMN_CNF,

    /* LPP related */
    CMI_DEV_LPP_UL_DATA_REQ,    //CmiDevLppUlDataReq
    CMI_DEV_LPP_UL_DATA_CNF,    //CmiDevLppUlDataCnf
    CMI_DEV_LPP_DL_DATA_IND,    //CmiDevLppDlDataInd

    CMI_DEV_LPP_GET_LOC_INFO_REQ,   //CmiDevLppGetLocInfoReq
    CMI_DEV_LPP_GET_LOC_INFO_CNF,   //CmiDevLppGetLocInfoCnf
    CMI_DEV_LPP_GET_LOC_INFO_IND = 30,  //CmiDevLppGetLocInfoInd

    CMI_DEV_LPP_STOP_LOC_MEAS_REQ,  //CmiDevLppStopLocMeasReq
    CMI_DEV_LPP_STOP_LOC_MEAS_CNF,  //CmiDevLppStopLocMeasCnf

    CMI_DEV_LPP_GET_EARLY_LOC_REQ,  //CmiDevLppGetEarlyLocReq
    CMI_DEV_LPP_GET_EARLY_LOC_CNF,  //CmiDevLppGetEarlyLocCnf

    CMI_DEV_LPP_GET_CELL_INFO_REQ,  //CmiDevLppGetCellInfoReq
    CMI_DEV_LPP_GET_CELL_INFO_CNF,  //CmiDevLppGetCellInfoCnf
    CMI_DEV_LPP_RESET_POSITION_INFO_IND,

    CMI_DEV_SET_CMOLR_REQ, //AT+CMOLR
    CMI_DEV_SET_CMOLR_CNF,
    CMI_DEV_GET_CMOLR_REQ = 40,  //AT+CMOLR?
    CMI_DEV_GET_CMOLR_CNF,
    CMI_DEV_GET_CMOLR_CAPA_REQ, //AT+CMOLR=?
    CMI_DEV_GET_CMOLR_CAPA_CNF,

    CMI_DEV_SET_CMTLR_REQ, //AT+CMTLR
    CMI_DEV_SET_CMTLR_CNF,
    CMI_DEV_GET_CMTLR_REQ,  //AT+CMTLR?
    CMI_DEV_GET_CMTLR_CNF,
    CMI_DEV_GET_CMTLR_CAPA_REQ, //AT+CMTLR=?
    CMI_DEV_GET_CMTLR_CAPA_CNF,
    CMI_DEV_CMTLR_IND = 50,

    CMI_DEV_SET_CMTLRA_REQ, //AT+CMTLRA
    CMI_DEV_SET_CMTLRA_CNF,
    CMI_DEV_GET_CMTLRA_REQ,  //AT+CMTLRA?
    CMI_DEV_GET_CMTLRA_CNF,
    CMI_DEV_GET_CMTLRA_CAPA_REQ, //AT+CMTLRA=?
    CMI_DEV_GET_CMTLRA_CAPA_CNF,

    CMI_DEV_GET_EXT_STATUS_REQ,     //CmiDevGetExtStatusReq, AT$QCSTATUS / AT$QCSTATUS?
    CMI_DEV_GET_EXT_STATUS_CNF,     //CmiDevGetExtStatusCnf

    CMI_DEV_SET_EXT_STATIS_MODE_REQ,    //CmiDevSetExtStatisModeReq, AT$QCSTATIS=<n>
    CMI_DEV_SET_EXT_STATIS_MODE_CNF = 60,

    CMI_DEV_EXT_STATIS_IND,     //CmiDevExtStatisInd, $QCSTATIS:

    CMI_DEV_GET_BASIC_CELL_LIST_INFO_REQ,   //CmiDevGetBasicCellListInfoReq, AT+ECBCINFOREQ
    CMI_DEV_GET_BASIC_CELL_LIST_INFO_CNF,   //CmiDevGetBasicCellListInfoCnf

    CMI_DEV_BAND_APN_AUTO_CONFIG_REQ_IND,   //CmiDevBandApnAutoCfgReqInd, let PSDIAL to config the APN & BAND if needed

    CMI_DEV_POWER_ON_CFUN_IND,  //CmiDevPowerOnCfunInd, $QCPCFUN, when first power on, need to notify uplayer current cfun state
    CMI_DEV_SILENT_RESET_IND,

    CMI_DEV_SET_ECPSTEST_REQ, //AT$QCPSTEST
    CMI_DEV_SET_ECPSTEST_CNF,
    CMI_DEV_GET_ECPSTEST_REQ,  //AT$QCPSTEST?
    CMI_DEV_GET_ECPSTEST_CNF = 70,
    CMI_DEV_SET_ECPOWERCLASS_REQ, //AT$QCPOWERCLASS
    CMI_DEV_SET_ECPOWERCLASS_CNF,
    CMI_DEV_GET_ECPOWERCLASS_REQ,  //AT$QCPOWERCLASS?
    CMI_DEV_GET_ECPOWERCLASS_CNF,
    CMI_DEV_GET_ECPOWERCLASS_CAPA_REQ,  //AT$QCPOWERCLASS=?
    CMI_DEV_GET_ECPOWERCLASS_CAPA_CNF,
    CMI_DEV_GET_BASIC_CELL_LIST_INFO_IND,   /*AT+ECBCINFO, <report_mode>=1, report URC*/
    CMI_DEV_GET_NB_REL_FEATURE_REQ,         /*AT+ECNBR14, CmiDevGetNBRelFeatureReq*/
    CMI_DEV_GET_NB_REL_FEATURE_CNF,
    
    CMI_DEV_SET_CE_INFO_REQ = 80, //AT+CEINFO
    CMI_DEV_SET_CE_INFO_CNF,
    CMI_DEV_GET_CE_INFO_REQ, //AT+CEINFO?
    CMI_DEV_GET_CE_INFO_CNF,
    CMI_DEV_CE_INFO_IND,
    CMI_DEV_GET_RPM_PARAM_INFO_REQ, //AT+RPMPARAM?
    CMI_DEV_GET_RPM_PARAM_INFO_CNF,
    CMI_DEV_GET_RPM_VERSION_REQ, //AT+RPMVERSION?
    CMI_DEV_GET_RPM_VERSION_CNF,

    CMI_DEV_SET_VZW_THROTTLE_REQ, //AT+VZWTHROTTLE
    CMI_DEV_SET_VZW_THROTTLE_CNF = 90,
    CMI_DEV_GET_VZW_THROTTLE_REQ, //AT+VZWTHROTTLE?
    CMI_DEV_GET_VZW_THROTTLE_CNF,
    
    CMI_DEV_GET_ECEVENTSTATIS_STATUS_REQ,  //AT+ECEVENTSTATIS?
    CMI_DEV_GET_ECEVENTSTATIS_STATUS_CNF,
    
    
    CMI_DEV_SET_ECEVENTSTATIS_MODE_REQ,    //AT+ECEVENTSTATIS=<mode>
    CMI_DEV_SET_ECEVENTSTATIS_MODE_CNF,

    CMI_DEV_WAKEUP_IND,         // QC specific change, added to broadcast wakeup indication
    CMI_DEV_GET_PSSLP_CFG_REQ,   //AT$QCPSSLPCFG?
    CMI_DEV_GET_PSSLP_CFG_CNF,

    CMI_DEV_SET_PSSLP_CFG_REQ,   //AT$QCPSSLPCFG = "minT3324",<T1>,"minT3324",<T2>,"minEDRXPeriod",<T3>
    CMI_DEV_SET_PSSLP_CFG_CNF,

    CMI_DEV_GET_PLMN_LOCK_LIST_REQ =102, //AT$QCPLMNLOCK?
    CMI_DEV_GET_PLMN_LOCK_LIST_CNF =103,

    CMI_DEV_UPDATE_PLMN_LOCK_LIST_REQ =104, //AT$QCPLMNLOCK= <add>/<delete>, <mcc>, <mnc>
    CMI_DEV_UPDATE_PLMN_LOCK_LIST_CNF =105,

    CMI_DEV_GET_EMM_STATE_REQ, //ATQCSTATE?
    CMI_DEV_GET_EMM_STATE_CNF,

    CMI_DEV_GET_DRX_REQ, //AT$QCDRX?
    CMI_DEV_GET_DRX_CNF,

    CMI_DEV_SET_LAPI_REQ,
    CMI_DEV_SET_LAPI_CNF,

    CMI_DEV_GET_LAPI_REQ,
    CMI_DEV_GET_LAPI_CNF,

    CMI_DEV_SET_ROAMING_DATA_REQ, //AT$QCROAMINGDATA=
    CMI_DEV_SET_ROAMING_DATA_CNF,

    CMI_DEV_GET_ROAMING_DATA_REQ, //AT$QCROAMINGDATA?
    CMI_DEV_GET_ROAMING_DATA_CNF,

	CMI_DEV_SET_CIOT_MCC_BAND_REQ, //AT$QCMCCBAND
    CMI_DEV_SET_CIOT_MCC_BAND_CNF,
    CMI_DEV_GET_CIOT_MCC_BAND_REQ,
    CMI_DEV_GET_CIOT_MCC_BAND_CNF,
    CMI_DEV_GET_CIOT_MCC_BAND_CAPA_REQ,
    CMI_DEV_GET_CIOT_MCC_BAND_CAPA_CNF,
	
    CMI_DEV_SET_PLMN_LIST_REQ, //AT$QCDTRPM=
	CMI_DEV_SET_PLMN_LIST_CNF,

	CMI_DEV_GET_PLMN_LIST_REQ,//AT$QCDTRPM?
	CMI_DEV_GET_PLMN_LIST_CNF, 

	CMI_DEV_SET_RPM_PARAM_INFO_REQ,//AT+RPMPARAM=
	CMI_DEV_SET_RPM_PARAM_INFO_CNF,

    CMI_DEV_DETECT_EVENT_IND,     //CmiDevDetectEventInd

    CMI_DEV_PRIM_END = 0x0fff
}CMI_DEV_PRIM_ID;


/******************************************************************************
 *****************************************************************************
 * STRUCT
 *****************************************************************************
******************************************************************************/

/******************************************************************************
 * CMI_DEV_SET_CFUN_REQ
******************************************************************************/
typedef enum CmiFuncValueEnum_TAG
{
    CMI_DEV_MIN_FUNC = 0,
    CMI_DEV_FULL_FUNC = 1,
    CMI_DEV_TURN_OFF_RF_FUNC = 4,


    CMI_DEV_MAX = 0xFF
}CmiFuncValueEnum;

typedef enum CmiFuncResetValueEnum_TAG
{
    CMI_DEV_DO_NOT_RESET = 0,
    CMI_DEV_RESET = 1
}CmiFuncResetValueEnum;

typedef struct CmiDevSetCfunReq_Tag
{
    UINT8   func; //CmiFuncValueEnum
    UINT8   rst;  //CmiFuncResetValueEnum
    UINT16  reserved;
}CmiDevSetCfunReq;

typedef struct CmiDevSetCfunCnf_Tag
{
    UINT8   func; //CmiFuncValueEnum, current func state
    UINT8   reserved0;
    UINT16  reserved1;
}CmiDevSetCfunCnf;

/******************************************************************************
 * CMI_DEV_GET_CFUN_REQ
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetCfunReq;

typedef struct CmiDevGetCfunCnf_Tag
{
    UINT8   func; //CmiFuncValueEnum
    UINT8   reserved1;
    UINT16  reserved2;
}CmiDevGetCfunCnf;


/******************************************************************************
 * CMI_DEV_GET_CFUN_CAPA_REQ
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetCfunCapaReq;

typedef struct CmiDevGetCfunCapaCnf_Tag
{
    UINT32 funcBitmap; // if cfun 0 support, bit 0 set to 1;
    UINT32 rstBitmap;
}CmiDevGetCfunCapaCnf;


/******************************************************************************
 * CMI_DEV_SET_CIOT_BAND_REQ,
 * AT$QCBAND=<mode>,<band1>,<band2>,<band3>...
******************************************************************************/
typedef enum CMIDEVNWMODE_TAG
{
    CMI_DEV_NB_MODE = 0
}CMIDEVNWMODE;

typedef enum CMIDEVMCCFEATURE_TAG
{
    CMI_DEV_MCC_FEATURE_DISABLE= 0,
	CMI_DEV_MCC_FEATURE_ENABLE
}CMIDEVMCCFEATUREMODE;

#define CMI_DEV_SUPPORT_MAX_BAND_NUM 32
typedef struct CmiDevSetCiotBandReq_Tag
{
    UINT8   nwMode;     //current NB only
    /*
     * if "AUTOBAND" is set, and PS DIAL can't find any band config info, then just use the default BAND in NVM;
     *  in such case, "bandNum" could be set to zero
    */
    UINT8   bandNum;
    UINT16  reserved;
    UINT8   orderedBand[CMI_DEV_SUPPORT_MAX_BAND_NUM];
}CmiDevSetCiotBandReq;  //20 bytes

typedef struct CmiDevSetCiotMccBandReq_Tag
{
    UINT8   mccNum;
	UINT8   bandNum;
    UINT16   mcc[10];
    UINT8   orderedBand[CMI_DEV_SUPPORT_MAX_BAND_NUM];
	UINT16  reserved1;
}CmiDevSetCiotMccBandReq;

/******************************************************************************
 * CMI_DEV_GET_CIOT_BAND_REQ
 *  $QCBAND=<mode>,<band1>,<band2>,<band3>...
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetMccBandReq;

typedef struct CmiDevGetMccBandCnf_Tag
{
	UINT8 Mode; 
    UINT16 Mcc;
    UINT8   bandNum;
    UINT8   reserved[3];
    UINT8   orderedBand[CMI_DEV_SUPPORT_MAX_BAND_NUM];
}CmiDevGetMccBandCnf;


typedef CacCmiEmptySig CmiDevSetCiotBandCnf;
typedef CacCmiEmptySig CmiDevSetCiotMccBandCnf;

/******************************************************************************
 * CMI_DEV_GET_CIOT_BAND_REQ
 *  $QCBAND=<mode>,<band1>,<band2>,<band3>...
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetCiotBandReq;

typedef struct CmiDevGetCiotBandCnf_Tag
{
    UINT8   nwMode; // current NB only
    UINT8   bandNum;
    UINT16  reserved;
    UINT8   orderedBand[CMI_DEV_SUPPORT_MAX_BAND_NUM];
}CmiDevGetCiotBandCnf;

typedef struct CmiDevGetCiotMccBandCnf_Tag
{
	UINT16  Mcc[10];
	UINT8   mccNum;
    UINT8   bandNum[CMI_DEV_SUPPORT_MAX_BAND_NUM];
    UINT16  reserved;
    UINT8   orderedBand[CMI_DEV_SUPPORT_MAX_BAND_NUM][CMI_DEV_SUPPORT_MAX_BAND_NUM];
}CmiDevGetCiotMccBandCnf;



/******************************************************************************
 * CMI_DEV_GET_CIOT_BAND_CAPA_REQ
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetCiotBandCapaReq;


typedef struct CmiDevGetCiotBandCapaCnf_Tag
{
    UINT8   nwMode; // current NB only
    UINT8   bandNum;
    UINT16  reserved;
    UINT8   supportBand[CMI_DEV_SUPPORT_MAX_BAND_NUM];
}CmiDevGetCiotBandCapaCnf;

/******************************************************************************
 * SIG_CEMM_CCM_GET_EMM_STATUS_CNF
******************************************************************************/
typedef struct CmiDevGetEmmStatusCnf_Tag
{
    UINT8 substate;
}CmiDevGetEmmStatusCnf;


/******************************************************************************
 * CMI_DEV_SET_CIOT_FREQ_REQ
 * internal AT CMD:
 * AT$QCFREQ = mode, parm1, parm2, ...
 * 1> AT$QCFREQ = 0 // cancel cell lock, or remove prefer ARFCN
 * 2> AT$QCFREQ = 1, arfcn1, arfcn2, ... // set prefer ARFCN list
 * 3> AT$QCFREQ = 2, arfcn[, phyCellId]    // cell lock
 * 4> AT$QCFREQ = 3 // clear preferred ARFCN list
******************************************************************************/
#define CMI_DEV_SUPPORT_MAX_FREQ_NUM    8
#define CMI_DEV_MAX_PHY_CELL_ID         503 //MAX PHY CELLID is 503

typedef enum CmiDevSetFreqModeEnum_Tag
{
    CMI_DEV_UNLOCK_FREQ_INFO,
    CMI_DEV_SET_PREFER_FREQ,
    CMI_DEV_LOCK_CELL,
    CMI_DEV_CLEAR_PREFER_FREQ_LIST
}CmiDevSetFreqModeEnum;

typedef struct CmiDevSetCiotFreqReq_Tag
{
    UINT8   mode;       // CmiDevSetFreqModeEnum
    UINT8   cellPresent;// indicate whether phyCellId present
    UINT16  phyCellId; // phyCell ID, 0 - 503

    UINT8   arfcnNum;
    UINT8   reserved0;
    UINT16  reserved1;
    UINT32  arfcnList[CMI_DEV_SUPPORT_MAX_FREQ_NUM];
}CmiDevSetCiotFreqReq; // total 40 bytes

typedef CacCmiEmptySig CmiDevSetCiotFreqCnf;


/******************************************************************************
 * CMI_DEV_GET_CIOT_FREQ_REQ
 * internal AT CMD:
 * AT$QCFREQ?
 * 1> $QCFREQ = 0 // no cell lock, or prefer FREQ
 * 2> $QCFREQ = 1, arfcn1, arfcn2, ... // prefer ARFCN list
 * 3> $QCFREQ = 2, arfcn[, phyCellId]    // cell lock info
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetCiotFreqReq;


typedef enum CmiDevGetFreqModeEnum_Tag
{
    CMI_DEV_NO_FREQ_INFO,
    CMI_DEV_PREFER_FREQ_INFO,
    CMI_DEV_CELL_LOCK_INFO,
    CMI_DEV_PREFER_FREQ_CELL_LOCK
}CmiDevGetFreqModeEnum;

typedef struct CmiDevGetCiotFreqCnf_Tag
{
    UINT8   mode;       // CmiDevGetFreqModeEnum
    UINT8   cellPresent;// indicate whether phyCellId present
    UINT16  phyCellId;  // phyCell ID, 0 - 503

    UINT8   arfcnNum;
    UINT8   reserved0;
    UINT16  reserved1;
    UINT32  lockedArfcn;
    UINT32  arfcnList[CMI_DEV_SUPPORT_MAX_FREQ_NUM];
}CmiDevGetCiotFreqCnf;

/******************************************************************************
 * CMI_DEV_SET_POWER_STATE_REQ
 * internal AT CMD:
 * AT+CIOTPOWER = mode // 0 - power save / hibernate state, 1 - SLEEP2, 2 - power on/wake up
******************************************************************************/
typedef enum CmiPowerStateEnum_TAG
{
    //CMI_DEV_POWER_SAVE = 0,     //prepare to enter Hibernate/Sleep2 state
    //CMI_DEV_POWER_SAVE_HIB = 0,
    //CMI_DEV_POWER_SAVE_SLEEP2 = 1,
    CMI_DEV_POWER_WAKE_UP = 2,  //wake up from Hibernate state

    CMI_DEV_POWER_STATE_MAX = 0xFF
}CmiPowerStateEnum;

typedef struct CmiDevSetPowerStateReq_Tag
{
    UINT8   powerState; //CmiPowerStateEnum
    UINT8   reserved0;
    UINT16  reserved1;
}CmiDevSetPowerStateReq;

//typedef CacCmiEmptySig CmiDevSetPowerStateCnf;
typedef struct CmiDevSetPowerStateCnf_Tag
{
    UINT8   powerState; //CmiPowerStateEnum, which power state confirmed
    UINT8   func;       //CmiFuncValueEnum, current func state
    UINT16  reserved1;

    CmiSimImsiStr   imsiStr;    //also notify CMS task the IMSI
}CmiDevSetPowerStateCnf;


/******************************************************************************
 * CMI_DEV_SET_EXT_CFG_REQ
 * AT$QCCFG="GCFTEST", 0/1, "AUTOAPN", 0/1, "SUPPORTSMS", 0/1, "SIMTEST", 0/1..
******************************************************************************/
typedef struct CmiDevSetExtCfgReq_Tag
{
    /* CCM */
    BOOL    autoApnPresent;
    BOOL    bAutoApn;

    BOOL    psSoftResetPresent;
    BOOL    bEnablePsSoftReset;

    //BOOL    simTestPresent;
    //BOOL    bSimTest;

    BOOL    usimSimuPresent;
    BOOL    bUsimSimulator;

    BOOL    rohcPresent;
    BOOL    bRohc;      //whether ROHC enabled

    BOOL    ipv6RsForTestSimPresent;
    BOOL    bIpv6RsForTestSim;  //whether enable IPv6 RS procedure for TEST SIM card

    BOOL    powerCfunPresent;
    UINT8   powerCfun;

    BOOL    psPowerOnMaxDelayPresent;
    UINT16  psPowerOnMaxDelay;
    UINT8   rsvd0;

    BOOL    enableBipPresent;
    BOOL    enableBip;

    BOOL    enableSimPsmPresent;
    BOOL    enableSimPsm;

    BOOL    ipv6GetPrefixTimePresent;
    UINT8   rsvd1;
    UINT16  ipv6GetPrefixTime;          //the maximum time of getting IPv6 prefix
    #if (RTE_PPP_EN==1)
	BOOL    tcpTptOptPresent;
    UINT8   bTcpTptOpt;  //whether enable TCP throughput optimization
    #endif
    /* EMM */
    BOOL    supportSmsPresent;
    BOOL    supportSms;

    BOOL    tauForSmsPresent;
    BOOL    tauForSms;

    BOOL    powerLevelPresent;
    UINT8   plmnSearchPowerLevel;   /*range [0..3]*/

    BOOL    epcoPresent;
    BOOL    enableEpco;

    BOOL    dnsIpAddrReadCfgPresent;
    UINT8   dnsIpType;
    UINT8   enableDnsIpAddrRead;
    UINT8   t3324MaxValuePresent;

    UINT32  t3324MaxValueS;

    BOOL    overrideLrplmnsiPresent;
    BOOL    overrideLrplmnsi;
	BOOL    EnableHPPlmnSearchPresent;
    UINT8   EnableHPPlmnSearch;

    /* ERRC */
    BOOL    multiCarrierPresent;
    BOOL    multiCarrier;

    BOOL    multiTonePresent;
    BOOL    multiTone;

    BOOL    upRaiPresent;
    BOOL    supportUpRai;

    BOOL    dataInactTimerPresent;
    UINT8   dataInactTimerS;    /*DataInactivityTimer-r14, used in CERRC; should > 40s; 0 - just means not use DataInactivityTimer feature */

    BOOL    relaxMonitorPresent;
    UINT8   relaxMonitorDeltaP; /*range [0..15], value in dB, 0 means relaxed monitoring(36.304, 5.2.4.12) in is not used, used in CERRC*/

    BOOL    relVersionPresent;
    UINT8   relVersion;         //release version, 13-14

    BOOL    enableCellReselPresent;
    BOOL    enableCellResel;

    BOOL    enableConnReEstPresent;
    BOOL    enableConnReEst;

    BOOL    nbCategoryPresent;
    UINT8   nbCategory;         /* Configure the NB-IoT category. Only support 1 and 2 now */

    BOOL    disableNCellMeasPresent;
    BOOL    disableNCellMeas;
    
    //Guard timer for cell search in seconds
    BOOL    cellSearchGuardTimerPresent;
    UINT16  cellSearchGuardTimerS; //cellSearchGuardTimer

    UINT8    dataInactMon_r14Present;
    BOOL     dataInactMon_r14;

    UINT8    interferenceRandomisation_r14Present;
    BOOL     interferenceRandomisation_r14;

    BOOL    SupportTwoHarqPresent;
    BOOL    SupportTwoHarq;

    BOOL    SupportMultiCarrierNPRACHPresent;
    BOOL    SupportMultiCarrierNPRACH;

    BOOL    SupportMultiCarrierPagingPresent;
    BOOL    SupportMultiCarrierPaging;

	BOOL    bEnableHPPlmnSearchPresent;
    UINT8   bEnableHPPlmnSearch;
    BOOL    CpReestablishmentPresent;
    BOOL    CpReestablishment;
}CmiDevSetExtCfgReq;    // 32 bytes

typedef CacCmiEmptySig CmiDevSetExtCfgCnf;

/******************************************************************************
 * CMI_DEV_GET_EXT_CFG_REQ
 * AT$QCCFG=?
 *  $QCCFG="GCFTEST", 0, "AUTOAPN", 0, "SUPPORTSMS", 0, "SIMTEST", 0
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetExtCfgReq;

typedef struct CmiDevGetExtCfgCnf_Tag
{
    /* CCM */
    //BOOL    bGcfTest; //useless
    BOOL    bAutoApn;
    BOOL    bEnablePsSoftReset;
    //BOOL    bSimTest; //replaced by enableSimPsm
    BOOL    bRohc;
    BOOL    bIpv6RsForTestSim;

    BOOL    bUsimSimulator;
    UINT8   powerCfun;
    UINT16  powerOnMaxDelay;

    BOOL    enableBip;              //+NCONFIG:ENABLE_BIP, XX
    BOOL    enableSimPsm;           //$QCCFG:USIMPOWERSAVE, XX /+NCONFIG:NAS_SIM_POWER_SAVING_ENABLE, XX
    UINT16  ipv6GetPrefixTime;      //+NCONFIG:IPV6_GET_PREFIX_TIME, XX
    #if (RTE_PPP_EN==1)
    UINT8   bTcpTptOpt;
    #endif
    /* EMM */
    BOOL    supportSms;
    BOOL    tauForSms;
    UINT8   plmnSearchPowerLevel;   /*range [0..3]*/
    BOOL    enableEpco;

    UINT32  t3324MaxValue;

    UINT8   dnsIpv4AddrReadCfg;     //+NCPCDPR:0,XX
    UINT8   dnsIpv6AddrReadCfg;     //+NCPCDPR:1,XX
    BOOL    overrideLrplmnsi;
	UINT8   EnableHPPlmnSearch;
	UINT8   bEnableHPPlmnSearch;
	
    UINT16  rsvd0;

    /* ERRC */
    BOOL    multiCarrier;
    BOOL    multiTone;
    BOOL    supportUpRai;           /*whether ERRC support RAI*/
    UINT8   ueCfgDataInactTimer;    /*ERRC data inactivity timer, in seconds*/

    UINT8   ueCfgRelaxMonitorDeltaP; /*relaxed monitor parameter, in DB, 0 - 17*/
    UINT8   relVersion;              /*release version, 13 - 14*/

    BOOL    enableCellResel;        //+NCONFIG:CELL_RESELECTION, XX
    BOOL    enableConnReEst;        //+NCONFIG:CONNECTION_REESTABLISHMENT, XX

    UINT8   nbCategory;             // +NCONFIG:NB_CATEGORY, XX  Configure the NB-IoT category. Only support 1 and 2 now
    BOOL    disableNCellMeas;

    //Guard timer for cell search in seconds
    UINT16  ueCfgCellSearchTimer; //cellSearchGuardTimer

    BOOL    dataInactMon_r14;

    BOOL    interferenceRandomisation_r14;
    BOOL    SupportTwoHarq;

    BOOL    SupportMultiCarrierNPRACH;
    BOOL    SupportMultiCarrierPaging;

    BOOL    CpReestablishment;
    
    UINT8   rsvd1[2];
}CmiDevGetExtCfgCnf;

/******************************************************************************
 * CMI_DEV_REMOVE_FPLMN_REQ,  //AT$QCRMFPLMN[=<value>]
 *  AT$QCRMFPLMN[=<value>]
******************************************************************************/
typedef enum CmiRmFPlmnTypeEnum_TAG
{
    CMI_DEV_RM_ALL_FPLMN = 0,   //default value
    CMI_DEV_RM_NVM_FPLMN = 1,   //remove FPLMN in NVM
    CMI_DEV_RM_SIM_FPLMN = 2    //remove FPLMN in SIM
}CmiRmFPlmnTypeEnum;

typedef struct CmiDevRemoveFPlmnReq_Tag
{
    UINT8   rmFPlmnType;    //CmiRmFPlmnTypeEnum
    UINT8   reserved0;
    UINT16  reserved1;
}CmiDevRemoveFPlmnReq;

typedef CacCmiEmptySig CmiDevRemoveFPlmnCnf;

/******************************************************************************
 ******************************************************************************
    LPP/LCS related CMI interface
 ******************************************************************************
*****************************************************************************/
/******************************************************************************
 * CMI_DEV_LPP_UL_DATA_REQ
******************************************************************************/
typedef struct CmiDevLppUlDataReq_Tag
{
    UINT16       length;
    BOOL         nasRoutingIdPresent;
    UINT8        reserved;
    UINT32       nasRoutingId;   /*IE type octet string(size(4))*/
    UINT8        *pdata;
}CmiDevLppUlDataReq;

/******************************************************************************
 * CMI_DEV_LPP_UL_DATA_CNF
******************************************************************************/
typedef enum CmiDevLppRcCodeEnum_Tag
{
    CMI_DEV_LPP_FAILURE = 0,
    CMI_DEV_LPP_SUCC = 1
}CmiDevLppRcCodeEnum;

typedef struct CmiDevLppUlDataCnf_Tag
{
    UINT8        result;    //CmiDevLppRcCodeEnum
    UINT8        reserved0;
    UINT16       reserved1;
}CmiDevLppUlDataCnf;

/******************************************************************************
 * CMI_DEV_LPP_DL_DATA_IND
******************************************************************************/
typedef struct CmiDevLppDlDataInd_Tag
{
    UINT16       length;
    BOOL         nasRoutingIdPresent;
    UINT8        reserved;
    UINT32       nasRoutingId;  /* IE type octet string(size(4)), the IE is defined in TS24.301-CR0640-V9.1.0;
                                 * but the IE is not clear defined in lastet Spec TS24.301-V14.7.0 */
    UINT8        *pdata;
}CmiDevLppDlDataInd;

/******************************************************************************
 * CMI_DEV_LPP_RESET_POSITION_INFO_IND
******************************************************************************/
typedef enum CmiUePositioningTechnologyTag
{
    CMI_UE_POSITIONING_TECHNOLOGY_AGNSS     = 0,
    CMI_UE_POSITIONING_TECHNOLOGY_OTDOA     = 1,
    CMI_UE_POSITIONING_TECHNOLOGY_MBS       = 2,
    CMI_UE_POSITIONING_TECHNOLOGY_WLAN      = 3,
    CMI_UE_POSITIONING_TECHNOLOGY_BLUETOOTH = 4,
    CMI_UE_POSITIONING_TECHNOLOGY_SENSOR    = 5
}
CmiUePositioningTechnology;

typedef struct CmiDevLppResetPositionInfoInd_Tag
{
    UINT8                  positionTech;    //CmiUePositioningTechnology
}CmiDevLppResetPositionInfoInd;

/******************************************************************************
 * CMI_DEV_LPP_GET_LOC_INFO_REQ
******************************************************************************/
typedef struct CmiECGI_Tag
{
    CmiNumericPlmn      plmn;
    UINT32              cellId; /* 0 to 268435455 */
}CmiECGI;       //8 bytes


typedef enum CmiCarrierFreqOffsetNBRefR14_Tag
{
    DEV_LPP_CARRIER_FREQ_OFFSET_V_10,
    DEV_LPP_CARRIER_FREQ_OFFSET_V_9,
    DEV_LPP_CARRIER_FREQ_OFFSET_V_8,
    DEV_LPP_CARRIER_FREQ_OFFSET_V_7,
    DEV_LPP_CARRIER_FREQ_OFFSET_V_6,
    DEV_LPP_CARRIER_FREQ_OFFSET_V_5,
    DEV_LPP_CARRIER_FREQ_OFFSET_V_4,
    DEV_LPP_CARRIER_FREQ_OFFSET_V_3,
    DEV_LPP_CARRIER_FREQ_OFFSET_V_2,
    DEV_LPP_CARRIER_FREQ_OFFSET_V_1,
    DEV_LPP_CARRIER_FREQ_OFFSET_V_0DOT5,
    DEV_LPP_CARRIER_FREQ_OFFSET_V0,
    DEV_LPP_CARRIER_FREQ_OFFSET_V1,
    DEV_LPP_CARRIER_FREQ_OFFSET_V2,
    DEV_LPP_CARRIER_FREQ_OFFSET_V3,
    DEV_LPP_CARRIER_FREQ_OFFSET_V4,
    DEV_LPP_CARRIER_FREQ_OFFSET_V5,
    DEV_LPP_CARRIER_FREQ_OFFSET_V6,
    DEV_LPP_CARRIER_FREQ_OFFSET_V7,
    DEV_LPP_CARRIER_FREQ_OFFSET_V8,
    DEV_LPP_CARRIER_FREQ_OFFSET_V9
}CmiCarrierFreqOffsetNBRefR14;


typedef struct CmiCarrierFreqNBR14_Tag
{
    UINT32              carrierFreqR14;
    BOOL                carrierFreqOffsetR14Present;
    UINT8               carrierFreqOffsetR14;   //CmiCarrierFreqOffsetNBRefR14
    UINT16              reserved0;
}CmiCarrierFreqNBR14;

/*
 * eutra-NumCRS-Ports-r14 ENUMERATED {ports1-or-2, ports4}
*/
typedef enum CmiOtdoaEutraNumCRSPortsR14_Tag
{
    OTDOA_RCELLINFONB_R14_EUTRA_NUMCRS_PORTS_R14_PORTS1_OR_2,
    OTDOA_RCELLINFONB_R14_EUTRA_NUMCRS_PORTS_R14_PORTS4
}CmiOtdoaEutraNumCRSPortsR14;

/*
 * otdoa-SIB1-NB-repetitions-r14 ENUMERATED { r4, r8, r16 }
*/
typedef enum CmiOtdoaSIB1NBRepetitionsR14_Tag
{
    OTDOA_RCell_SIB1_NB_REPETITIONS_R14_R4,
    OTDOA_RCell_SIB1_NB_REPETITIONS_R14_R8,
    OTDOA_RCell_SIB1_NB_REPETITIONS_R14_R16,
}CmiOtdoaSIB1NBRepetitionsR14;

typedef enum CmiNPRSInfoR14OperationModeInfoNPRSR14_Tag
{
    NPRS_OPERATION_MODE_INFO_NPRS_R14_INBAND,
    NPRS_OPERATION_MODE_INFO_NPRS_R14_STANDALONE,
}CmiNPRSInfoR14OperationModeInfoNPRSR14;

typedef enum CmiTNPRSInfoR14NprsBitmapR14Type_Tag
{
    T_NPRS_INFO_R14_NPRSBITMAP_R14_SUBFRAMEPATTERN10_R14 = 0,
    T_NPRS_INFO_R14_NPRSBITMAP_R14_SUBFRAMEPATTERN40_R14 = 1
}CmiTNPRSInfoR14NprsBitmapR14Type;


typedef struct CmiNPRSInfoR14PartAR14_Tag
{
    UINT8           nprsBitmapR14Type : 1;      //CmiTNPRSInfoR14NprsBitmapR14Type
    UINT8           nprsMutingInfoAR14Present : 1;  /*whether "nprsMutingInfoAR14" configed*/
    UINT8           nprsMutingInfoAR14Type : 2; //CmiTNPRSInfoMutingInfoAR14Type
    UINT8           reserved0 : 4;

    /*
     * CmiTNPRSInfoR14NprsBitmapR14Type;
     * nprsBitmap-r14 CHOICE {
     *  subframePattern10-r14 BIT STRING (SIZE (10)),
     *  subframePattern40-r14 BIT STRING (SIZE (40))
     * },
    */
    UINT16          nprsBitmapR14BitStringHigh;
    UINT32          nprsBitmapR14BitStringLow;
    /*
     * nprs-MutingInfoA-r14 CHOICE {
     *  po2-r14 BIT STRING (SIZE(2)),
     *  po4-r14 BIT STRING (SIZE(4)),
     *  po8-r14 BIT STRING (SIZE(8)),
     *  po16-r14 BIT STRING (SIZE(16)),
     *  ...
     * }
    */
    UINT8           nprsMutingInfoAR14[2];
}CmiNPRSInfoR14PartAR14;    // 9 bytes


typedef struct CmiNPRSInfoR14PartBR14_Tag
{
    /*
     * nprs-Period-r14 ENUMERATED { ms160, ms320, ms640, ms1280, ... },
    */
    UINT32          nprsPeriodR14 : 2;
    /*
     * nprs-startSF-r14 ENUMERATED { zero, one-eighth, two-eighths, three-eighths,
     *  four-eighths, five-eighths, six-eighths, seven-eighths, ...},
    */
    UINT32          nprsStartSFR14 : 3;
    /*
     * nprs-NumSF-r14 ENUMERATED { sf10, sf20, sf40, sf80, sf160, sf320, sf640, sf1280, ...},
    */
    UINT32          nprsNumSFR14 : 3;

    /*
     * nprs-MutingInfoB-r14 CHOICE {
     *  po2-r14 BIT STRING (SIZE(2)),
     *  po4-r14 BIT STRING (SIZE(4)),
     *  po8-r14 BIT STRING (SIZE(8)),
     *  po16-r14 BIT STRING (SIZE(16)),
     *  ...
     * } OPTIONAL, -- Cond MutingB
    */
    UINT32          nprsMutingInfoBR14Present : 1;
    UINT32          nprsMutingInfoBR14Type : 2;
    UINT32          reserved0 : 5;
    UINT32          nprsMutingInfoBR14Bitmap : 16;
}CmiNPRSInfoR14PartBR14;    // 4 bytes


/*
 * NPRS-Info-r14
*/
typedef struct NBPRSInfoR14_Tag
{
    UINT32                  nprsCarrierR14Present : 1;
    UINT32                  nprsSequenceInfoR14Present : 1;
    UINT32                  nprsIDR14Present : 1;
    UINT32                  partAR14Present : 1;
    UINT32                  partBR14Present : 1;
    UINT32                  opModeInfoNPRSR14 : 1;   //CmiNPRSInfoR14OperationModeInfoNPRSR14
    UINT32                  reserved0 : 2;

    UINT32                  nprsSequenceInfoR14 : 8;   /* 0 to 174 */
    UINT32                  nprsIDR14 : 16;  /* 0 to 4095 */

    CmiCarrierFreqNBR14     nprsCarrierFreqNBR14; // 8 bytes

    CmiNPRSInfoR14PartAR14  partAR14;    //8 bytes
    CmiNPRSInfoR14PartBR14  partBR14;    //4 bytes
}CmiNBPRSInfoR14;    // 24 bytes

typedef struct CmiOtdoaRCellInfoNBR14_Tag
{
    /*
     * physCellIdNB-r14 INTEGER (0..503)        OPTIONAL, -- Cond NoPRS-AD1
    */
    UINT16                      physCellIdNBR14Present : 1;
    /*
     * cellGlobalIdNB-r14 ECGI                  OPTIONAL, -- Cond NoPRS-AD2
    */
    UINT16                      ecgiNBR14Present : 1;
    /*
     * carrierFreqRef-r14 CarrierFreq-NB-r14    OPTIONAL, -- Cond NotSameAsServ1
    */
    UINT16                      carrierFreqRefR14Present : 1;
    /*
     * earfcn-r14 ARFCN-ValueEUTRA-r14          OPTIONAL, -- Cond Inband
    */
    UINT16                      earfcnR14Present : 1;
    /*
     * eutra-NumCRS-Ports-r14 ENUMERATED {ports1-or-2, ports4}      OPTIONAL, -- Cond NoPRS-AD3
    */
    UINT16                      eutraNumCRSPortsR14Present : 1;
    /*
     * otdoa-SIB1-NB-repetitions-r14 ENUMERATED { r4, r8, r16 }     OPTIONAL, -- Cond NotSameAsServ2
    */
    UINT16                      otdoaSIB1NBRepetitionsR14Present : 1;
    /*
     * eutra-NumCRS-Ports-r14 ENUMERATED {ports1-or-2, ports4}
    */
    UINT16                      eutraNumCRSPortsR14 : 1;    //CmiOtdoaEutraNumCRSPortsR14
    UINT16                      reserved0 : 1;
    /* 8 bits*/

    /*
     * otdoa-SIB1-NB-repetitions-r14 ENUMERATED { r4, r8, r16 }
    */
    UINT16                      sIB1NBRepetitionsR14 : 2;   //CmiOtdoaSIB1NBRepetitionsR14

    /*
     * nprsInfo-r14 PRS-Info-NB-r14             OPTIONAL, -- Cond NPRS-Type1
     *  0 - 5, if not present, set "nprsInfoR14Num" to 0;
    */
    UINT16                      nprsInfoR14Num : 3;
    /*
     * nprsInfo-Type2-v1470 PRS-Info-NB-r14         OPTIONAL -- Cond NPRS-Type2
     *  0 - 5, if not present, set "nprsInfoType2V1470Num" to 0;
    */
    UINT16                      nprsInfoType2V1470Num : 3;

    UINT16                      physCellIdNB_r14;       /* 0 to 503 */

    CmiECGI                     ecgi;                   // 8 bytes
    CmiCarrierFreqNBR14         carrierFreqNBR14;       // 8 bytes;
    UINT32                      earfcnR14;              // 4 bytes

    /*
     * nprsInfo-r14   PRS-Info-NB-r14               OPTIONAL, -- Cond NPRS-Type1
     *  PRS-Info-NB-r14 ::= SEQUENCE (SIZE (1..maxCarrier-r14)) OF NPRS-Info-r14
     *   maxCarrier-r14 = 5
    */
    CmiNBPRSInfoR14             nprsInfoR14List[5]; /*24*5 = 120 bytes, acceptable*/

    //NBPRSInfoR14                *pNBPrsInfoType2V1470;  /*max num is 5*/
    /*
     * nprsInfo-Type2-v1470 PRS-Info-NB-r14         OPTIONAL -- Cond NPRS-Type2
    */
    CmiNBPRSInfoR14             nprsInfoType2V1470List[5];  /*24*5 = 120 bytes, acceptable*/
}CmiOtdoaRCellInfoNBR14;    // 264 bytes

typedef struct CmiOtdoaNCellInfoNBR14_Tag
{
    /*
     * UINT32 4 bytes
    */
    /*
     * physCellIdNB-r14 INTEGER (0..503)    OPTIONAL, -- Cond NoPRS-AD1
    */
    UINT32                      physCellIdNBR14Present : 1;
    /*
     * cellGlobalIdNB-r14 ECGI              OPTIONAL, -- Cond NoPRS-AD2
    */
    UINT32                      cellGlobalIdNBR14Present : 1;
    /*
     * carrierFreq-r14 CarrierFreq-NB-r14   OPTIONAL, -- Cond NotSameAsRef1
    */
    UINT32                      carrierFreqR14Present : 1;
    /*
     * earfcn-r14 ARFCN-ValueEUTRA-r14      OPTIONAL, -- Cond Inband
    */
    UINT32                      earfcnR14Present : 1;
    /*
     * eutra-NumCRS-Ports-r14 ENUMERATED {ports-1-or-2, ports-4, ...}       OPTIONAL, -- Cond NotsameAsRef2
    */
    UINT32                      eutraNumCRSPortsR14Present : 1;
    /*
     * otdoa-SIB1-NB-repetitions-r14 ENUMERATED { r4, r8, r16 }             OPTIONAL, -- Cond NotSameAsRef3
    */
    UINT32                      otdoaSIB1NBRepetitionsR14Present : 1;
    /*
     * nprs-slotNumberOffset-r14 INTEGER (0..19)                            OPTIONAL, -- Cond NotsameAsRef5
    */
    UINT32                      nprsSlotNumOffsetR14Present : 1;
    /*
     * nprs-SFN-Offset-r14 INTEGER (0..63)  OPTIONAL, -- Cond NotsameAsRef6
    */
    UINT32                      nprsSFNOffsetR14Present : 1;
    /*
     * nprs-SubframeOffset-r14 INTEGER (0..1279)                            OPTIONAL, -- Need OP
    */
    UINT32                      nprsSubframeOffsetR14Present : 1;
    /*
     * expectedRSTD-r14 INTEGER (0..16383)  OPTIONAL, -- Cond NoPRS-AD3
    */
    UINT32                      expectedRSTDR14Present : 1;
    /*
     * expectedRSTD-Uncertainty-r14 INTEGER (0..1023)                       OPTIONAL, -- Cond NoPRS-AD3
    */
    UINT32                      expectedRSTDUncertaintyR14Present : 1;
    /*
     * prsNeighbourCellIndex-r14 INTEGER (1..72)                            OPTIONAL, -- Cond PRS-AD
    */
    UINT32                      prsNeighbourCellIndexR14Present : 1;
    UINT32                      eutraNumCRSPortsR14 : 1;    /* CmiOtdoaEutraNumCRSPortsR14 eutra-NumCRS-Ports-r14 ENUMERATED {ports-1-or-2, ports-4, ...}*/
    /*
     * nprsInfo-r14 PRS-Info-NB-r14         OPTIONAL, -- Cond NotsameAsRef4
     *  0 - 5, if not present, set "nprsInfoR14Num" to 0;
    */
    UINT32                      nprsInfoR14Num : 3;
    /* 16 bits */

    UINT32                      nprsSubframeOffsetR14 : 11;    /* 0 to 1279 */ //11 bits
    UINT32                      nprsSlotNumOffsetR14 : 5;   /* 0 to 19 */

    /*
     * UINT32 4 bytes
    */
    UINT32                      expectedRSTDR14 : 14;   /* 0 to 16383 */     //14 bits
    /*
     * otdoa-SIB1-NB-repetitions-r14 ENUMERATED { r4, r8, r16 }             OPTIONAL, -- Cond NotSameAsRef3
    */
    UINT32                      sIB1NBRepetitionsR14 : 2;   //CmiOtdoaSIB1NBRepetitionsR14

    UINT32                      expectedRSTDUncertaintyR14 : 10;   /* 0 to 1023 */ // 10 bits
    UINT32                      nprsSFNOffsetR14 : 6;   /* 0 to 63 */

    /*
     * UINT32 4 bytes
    */
    UINT32                      physCellIdNBR14 : 9;    /* 0 to 503 */ // 9 bits
    UINT32                      prsNeighbourCellIndexR14 : 7;  /* 1 to 72 */

    /*
     * nprsInfo-Type2-v1470 PRS-Info-NB-r14
     *  0 - 5, if not present, set "nprsInfoType2V1470Num" to 0;
    */
    UINT32                      nprsInfoType2V1470Num : 3;
    UINT32                      reserved1 : 13;

    CmiECGI                     ecgi;   //8 bytes
    CmiCarrierFreqNBR14         carrierFreqNBR14;   //8 bytes
    UINT32                      earfcnR14;

    /*
     * nprsInfo-r14 PRS-Info-NB-r14         OPTIONAL, -- Cond NotsameAsRef4
    */
    CmiNBPRSInfoR14             nprsInfoR14List[5]; /*24*5 = 120 bytes, acceptable*/

    /*
     * nprsInfo-Type2-v1470 PRS-Info-NB-r14                                 OPTIONAL -- Cond NotSameAsRef4
    */
    CmiNBPRSInfoR14             nprsInfoType2V1470List[5];  /*24*5 = 120 bytes, acceptable*/

}CmiOtdoaNCellInfoNBR14; //272 bytes

typedef struct CmiOtdoaAssistantData_Tag
{
    /*For nb, only need otdoaRefCellInfoNBR14 and otdoaNeighCellInfoNBR14*/
    BOOL                        otdoaRefCellInfoNBR14Present;
    /*
     * OTDOA-NeighbourCellInfoListNB-r14 ::= SEQUENCE (SIZE (1..maxCells-r14)) OF OTDOA-NeighbourCellInfoNB-r14
      * maxCells-r14 INTEGER ::= 72,
    */
    UINT8                       otdoaNeighCellInfoNum;  /*0 - 72, if not exist (0), "pNCellInfoList" is set to NULL*/
    UINT16                      reserved;
    CmiOtdoaRCellInfoNBR14      otdoaRefCellInfoNBR14;  //264 bytes
    CmiOtdoaNCellInfoNBR14      *pNCellInfoList;        /*A array, and the size indicated by "otdoaNeighCellInfoNum", use dynamic memory*/
}CmiOtdoaAssistantData; // 272 bytes

typedef struct CmiEcidMeasReqData_Tag
{
    UINT32              bCellChangeEvent : 1;   /*whether ECID means info need to report when primary/serving cell changed*/
    UINT32              rsrpReq : 1;    /* not used for NB, set FALSE*/
    UINT32              rsrqReq : 1;    /* not used for NB, set FALSE*/
    UINT32              ueRxTxTimeDiffReq : 1;  /* not used for NB, set FALSE*/
    UINT32              nRsrpReqR14 : 1;    /*only used for NB*/
    UINT32              nRsrqReqR14 : 1;    /*only used for NB*/
    UINT32              reserved : 26;
}CmiEcidMeasReqData;

typedef struct CmiOtdoaMeasReqData_Tag
{
    BOOL                    multipathRSTDr14;
    BOOL                    maxNumOfRSTDmeasr14Present;
    UINT8                   maxNumOfRSTDmeasr14;
    BOOL                    assistDataPresent;  /* AssistData has received */
    CmiOtdoaAssistantData   assistData;    //272 bytes
}CmiOtdoaMeasReqData;

typedef struct CmiDevLppGetLocInfoReq_Tag
{
    BOOL                    otdoaMeasPresent;
    BOOL                    ecidMeasPresent;
    UINT16                  reserved;
    CmiOtdoaMeasReqData     otdoaReqData; //272 bytes
    CmiEcidMeasReqData      ecidReqData;  //4 bytes
}CmiDevLppGetLocInfoReq;    // 280 bytes, acceptable

/******************************************************************************
 * CMI_DEV_LPP_GET_LOC_INFO_CNF
******************************************************************************/
#define CMI_DEV_OTDOA_MAX_ADDITIONAL_PATH_R14   2

typedef struct CmiLppEcidCellMeasuredInfo_Tag
{
    UINT16                      cellGobalIdPresent : 1;
    UINT16                      sfnPresent : 1;
    UINT16                      rsrpResultPresent : 1;
    UINT16                      rsrqResultPresent : 1;
    UINT16                      ueRxTxTimeDiffPresent : 1;
    UINT16                      nrsrpResultR14Present : 1;
    UINT16                      nrsrqResultR14Present : 1;
    UINT16                      carrierFreqOffsetPresent : 1;
    UINT16                      hsfnPresent : 1;
    UINT16                      rsrpResultV1470Present : 1;
    UINT16                      rsrqResultV1470Present : 1;
    UINT16                      reserved0 : 5;
    UINT16                      phyCellId;

    CmiECGI                     cellGobalId;    // 8 bytes
    UINT32                      earfcn;
    UINT16                      sfn;
    UINT8                       rsrpResult;     /*not used for NB*/
    UINT8                       rsrqResult;     /*not used for NB*/

    UINT16                      ueRxTxTimeDiff; /*not used for NB*/
    UINT8                       nrsrpResultR14; /*Note, the value range: 0 - 113, ERRC need to do right mapping according 36.133 9.1.22.9*/
    UINT8                       nrsrqResultR14; /*Note, the value range: 0 - 74, ERRC need to do right mapping according 36.133 9.1.7*/

    UINT8                       carrierFreqOffsetNBRefR14;  //CmiCarrierFreqOffsetNBRefR14
    UINT8                       reserved1;
    UINT16                      hsfn;

    INT8                        rsrpResultV1470;    /*not used for NB*/
    INT8                        rsrqResultV1470;    /*not used for NB*/
    UINT16                      reserved2;
}CmiLppEcidCellMeasuredInfo;    // 32 bytes

typedef struct CmiEcidMeasuredInfo_Tag
{
    BOOL                        pCellMeasuredResultsPresent;    /*primary cell measured result*/
    BOOL                        allCellMeased;          //whether all NCELL measured
    UINT8                       nCellEcidMeasNum;
    UINT8                       reserved0;
    /* TS36.355 "pCellMeasuredResult" field contains measurements for the primary cell, when the target device
     * reports measurements for both primary cell and neighbour cells. This field shall be omitted when the
     * target device reports measurements for the primary cell only, in which case the measurements
     * the primary cell is reported in the measuredResultsList.
    */
    CmiLppEcidCellMeasuredInfo  pCellMeasuredResult;    //32 bytes primary cell measured result

    /*
     * MeasuredResultsList ::= SEQUENCE (SIZE(1..32)) OF MeasuredResultsElement,
     *  if no NCell meas info, "nCellEcidMeasNum" should set to 1 and "pCellMeasuredResult" should be stored to the list
    */
    CmiLppEcidCellMeasuredInfo  *pNCellEcidMeasInfoList;
}CmiEcidMeasuredInfo;           // 40 bytes

typedef struct CmiOtdoaMeasQuality_Tag
{
    /*
     * OTDOA-MeasQuality ::= SEQUENCE {
     *   error-Resolution BIT STRING (SIZE (2)),
     *   error-Value BIT STRING (SIZE (5)),
     *   error-NumSamples BIT STRING (SIZE (3)) OPTIONAL,
     *   ...
     *   }
    */
    UINT8                   errorResolution;    /* 0 to 3 */
    UINT8                   errorValue; /* 0 to 31 */
    BOOL                    errorNumSamplesPresent;
    UINT8                   errorNumSamples;    /* 0 to 7 */
}CmiOtdoaMeasQuality;

typedef struct CmiAdditionalPathR14_Tag
{
    INT16                   relativeTimeDiffR14;    /*relativeTimeDifference-r14 INTEGER (-256..255)*/
    UINT16                  reserved0;
    CmiOtdoaMeasQuality     pathQualityR14;
}CmiAdditionalPathR14;          // 8 bytes

typedef struct CmiNCellMeasurementElementNBR14_Tag
{
    UINT32                          ecgiNeighPresent : 1;
    UINT32                          earfcnNeighbourPresent : 1;
    UINT32                          carrierFreqOffsetNeighPresent : 1;
    UINT32                          tpidNeighR14Present : 1;
    UINT32                          prsIdNeighR14Present : 1;
    UINT32                          deltaRstdR14Present : 1;
    UINT32                          nprsIdNeighR14Present : 1;
    UINT32                          reserved0 : 1;
    UINT32                          deltaRstdR14 : 3;       /* 0 to 5 */
    UINT32                          carrierFreqOffsetNeigh : 5; //CmiCarrierFreqOffsetNBRefR14   : 5 bits
    UINT32                          physCellIdNeighbour : 9;    /* 0 to 503 */
    UINT32                          numAdditionalPathNeighR14 : 2; /* 0 - 2, indicate the valid number of "additionalPathNeighR14" */
    UINT32                          reserved1 : 5;

    CmiECGI                         ecgiNeigh;          //8 bytes
    UINT32                          earfcnNeighbour;

    CmiOtdoaMeasQuality             rstdQuality;        //4 bytes

    UINT16                          rstd;               /* 0 to 12711 */
    UINT16                          tpidNeighR14;   /* 0 to 4095, for NB, maybe not valid now */
    UINT16                          prsIdNeighR14;  /* 0 to 4095, for NB, maybe not valid now */
    UINT16                          nprsIdNeighR14; /* 0 to 4095 */


    CmiAdditionalPathR14            additionalPathNeighR14[CMI_DEV_OTDOA_MAX_ADDITIONAL_PATH_R14];
}CmiNCellMeasurementElementNBR14;   //44 bytes

typedef struct CmiOtdoaMeasuredInfoNB_Tag
{
    /*
     *  OTDOA-SignalMeasurementInformation-NB-r14 ::= SEQUENCE {
     *       systemFrameNumber-r14 BIT STRING (SIZE (10)),
     *       physCellIdRef-r14 INTEGER (0..503),
     *       cellGlobalIdRef-r14 ECGI OPTIONAL,
     *       earfcnRef-r14 ARFCN-ValueEUTRA-r14 OPTIONAL, -- Cond NotSameAsRef0
     *       referenceQuality-r14 OTDOA-MeasQuality OPTIONAL,
     *       neighbourMeasurementList-r14 NeighbourMeasurementList-NB-r14,
     *       tpIdRef-r14 INTEGER (0..4095) OPTIONAL, -- Cond ProvidedByServer0
     *       prsIdRef-r14 INTEGER (0..4095) OPTIONAL, -- Cond ProvidedByServer1
     *       additionalPathsRef-r14 AdditionalPathList-r14 OPTIONAL,
     *       nprsIdRef-r14 INTEGER (0..4095) OPTIONAL, -- Cond ProvidedByServer2
     *       carrierFreqOffsetNB-Ref-r14 CarrierFreqOffsetNB-r14 OPTIONAL, -- Cond NB-IoT
     *       hyperSFN-r14 BIT STRING (SIZE (10)) OPTIONAL, -- Cond H-SFN
     *       ...
     *   }
    */
    UINT32                      ecgiPresent : 1;
    UINT32                      earfcnRefR14Present : 1;
    UINT32                      referenceQualityR14Present : 1;
    UINT32                      carrierFreqOffsetPresent : 1;
    UINT32                      hsfnPresent : 1;
    UINT32                      tpidRefR14Present : 1;
    UINT32                      prsIdRefR14Present : 1;
    UINT32                      nprsIdRefR14Present : 1;
    UINT32                      numAdditionalPathNeighR14 : 2; /* 0 - 2, indicate the valid number of "additionalPathNeighR14" */
    UINT32                      numNeighbourMeasList : 5;   /*0 - 24*/
    UINT32                      reserved0 : 1;
    UINT32                      carrierFreqOffsetNBRefR14 : 5; //CmiCarrierFreqOffsetNBRefR14. 5 bits
    UINT32                      reserved1 : 11;

    UINT16                      sfn;                /* 0 to 1023 */ // 10 bits
    UINT16                      refPhysCellIdR14;   /* 0 to 503 */  // 9 bits

    CmiECGI                     ecgi;               // 8 bytes
    UINT32                      refEarfcnR14;
    CmiOtdoaMeasQuality         referenceQualityR14;    // 4 bytes

    UINT16                      tpidRefR14;     /* 0 to 4095 */ // 12 bits
    UINT16                      prsIdRefR14;    /* 0 to 4095 */ // 12 bits
    UINT16                      nprsIdRefR14;   /* 0 to 4095 */ // 12 bits
    UINT16                      hsfnR14;        //10 bits

    CmiAdditionalPathR14        additionalPathR14[CMI_DEV_OTDOA_MAX_ADDITIONAL_PATH_R14];

    /*
     * NeighbourMeasurementList-NB-r14 ::= SEQUENCE (SIZE(1..24)) OF NeighbourMeasurementElement-NB-r14
     *  Array pointer, array size is "numNeighbourMeasList"
     */
    CmiNCellMeasurementElementNBR14 *pNcellMeasureListR14;
}CmiOtdoaMeasuredInfoNB;    // 52 bytes


typedef enum CmiOtdoaMeasResult_TAG
{
    CMI_OTDOA_MEAS_RESULT_NOT_PRESENT = 0,      /*OTDOA meas is not configured by Nw*/
    CMI_OTDOA_MEAS_RESULT_SUCCEED = 1,          /*OTDOA meas result is returned normally*/
    /* TS36.355 OTDOA-TargetDeviceErrorCauses ::= SEQUENCE {
     *                                  cause ENUMERATED { undefined,
     *                                                     assistance-data-missing,
     *                                                     unableToMeasureReferenceCell,
     *                                                     unableToMeasureAnyNeighbourCell,
     *                                                     attemptedButUnableToMeasureSomeNeighbourCells,
     *                                                     ...
     *                                                    },
     *           ...
     *   }
     */
    CMI_OTDOA_MEAS_RESULT_FAIL_UNDEFINED = 2,
    CMI_OTDOA_MEAS_RESULT_UNABLE_TO_MEASURE_RCELL = 3,
    CMI_OTDOA_MEAS_RESULT_UNABLE_TO_MEASURE_ANY_NCELL = 4,
    CMI_OTDOA_MEAS_RESULT_UNABLE_TO_MEASURE_SOME_NCELL = 5,
    CMI_OTDOA_MEAS_RESULT_ASSIST_PARA_ERR = 6   /*OTDOA assist parameter data incorrect*/
}CmiOtdoaMeasResult;

typedef enum CmiEcidMeasCause_TAG
{
    CMI_ECID_MEAS_RESULT_NOT_PRESENT = 0,           /*ECID meas is not configured by Nw*/
    CMI_ECID_MEAS_RESULT_SUCCEED_WITH_INFO = 1,     /*ECID meas result is returned normally*/
    CMI_ECID_MEAS_RESULT_SUCCEED_WITHOUT_INFO = 2,  /*special for cell change loc meas*/
    /*ECID-TargetDeviceErrorCauses ::= SEQUENCE {
     *                cause ENUMERATED { undefined,
     *                                  requestedMeasurementNotAvailable,
     *                                  notAllrequestedMeasurementsPossible,
     *                                  ...
     *                                   },
     */
    CMI_ECID_MEAS_RESULT_FAIL_UNDEFINED = 3,
    CMI_ECID_MEAS_RESULT_REQUESTED_MEASUREMENT_NOT_AVAILABLE = 4,
    CMI_ECID_MEAS_RESULT_NOT_ALL_REQUESTED_MEASUREMENT_POSSIBLE = 5
}CmiEcidMeasCause;

typedef struct CmiEcidMeasResult_TAG
{
    UINT8                           ecidMeasCause;     //CmiEcidMeasCause
    /* TS36.355 If the cause value is 'notAllRequestedMeasurementsPossible', the
     * target device was not able to provide all requested ECID measurements (but may be able to provide some
     * measurements). In this case, the target device should include any of the rsrpMeasurementNotPossible,
     * rsrqMeasurementNotPossible, ueRxTxMeasurementNotPossible, nrsrpMeasurementNotPossible, or
     * nrsrqMeasurementNotPossible fields, as applicable.
     */
    UINT8                           rsrpMeasurementNotPossible : 1;
    UINT8                           rsrqMeasurementNotPossible : 1;
    UINT8                           ueRxTxMeasurementNotPossible : 1;
    UINT8                           nrsrpMeasurementNotPossibleR14 : 1;
    UINT8                           nrsrqMeasurementNotPossibleR14 : 1;
    UINT8                           reserved1 : 3;
    UINT16                          reserved2;
}CmiEcidMeasResult;

/*
 *  1> if request to use ECID, then check "ecidMeasResult" firstly,
 *     if "CMI_ECID_MEAS_RESULT_SUCCEED_WITH_INFO", then check "ecidMeasuredInfoPresent" value;
 *  2> if request to use OTDOA, also check "otdoaMeasResult" firstly
*/
typedef struct CmiDevLppGetLocInfoCnf_Tag
{
    UINT8                           otdoaMeasResult;    //CmiOtdoaMeasResult
    BOOL                            otdoaMeasuredInfoPresent;
    BOOL                            ecidMeasuredInfoPresent;
    UINT8                           reserved1;
    CmiEcidMeasResult               ecidMeasResult;
    CmiOtdoaMeasuredInfoNB          otdoaMeasuredInfo;  /*valid when "otdoaMeasuredInfoPresent" = TRUE*/
    CmiEcidMeasuredInfo             ecidMeasuredInfo;   /*valid when "ecidMeasuredInfoPresent" = TRUE*/
}CmiDevLppGetLocInfoCnf; //100 bytes

/******************************************************************************
 * CMI_DEV_LPP_GET_LOC_INFO_IND
******************************************************************************/
typedef struct CmiDevLppGetLocInfoInd_Tag
{
    CmiEcidMeasResult               ecidMeasResult;
    CmiEcidMeasuredInfo             ecidMeasuredInfo;
}CmiDevLppGetLocInfoInd; // 40 bytes


/******************************************************************************
 * CMI_DEV_LPP_STOP_LOC_MEAS_REQ
******************************************************************************/
typedef struct CmiDevLppStopLocMeasReq_Tag
{
    BOOL                           withTempResult;
    UINT8                          reserved0;
    UINT16                         reserved1;
}CmiDevLppStopLocMeasReq;

/******************************************************************************
 * CMI_DEV_LPP_STOP_LOC_MEAS_CNF
******************************************************************************/
typedef CacCmiEmptySig CmiDevLppStopLocMeasCnf;


/******************************************************************************
 * CMI_DEV_LPP_GET_EARLY_LOC_REQ
******************************************************************************/
typedef CacCmiEmptySig CmiDevLppGetEarlyLocReq;


/******************************************************************************
 * CMI_DEV_LPP_GET_EARLY_LOC_CNF
 *  1> if request to use ECID, then check "ecidMeasResult" firstly,
 *     if "CMI_ECID_MEAS_RESULT_SUCCEED_WITH_INFO", then check "ecidMeasuredInfoPresent" value;
 *  2> if request to use OTDOA, also check "otdoaMeasResult" firstly
******************************************************************************/
typedef struct CmiDevLppGetEarlyLocCnf_Tag
{
    UINT8                           otdoaMeasResult;    //CmiOtdoaMeasResult
    BOOL                            otdoaMeasuredInfoPresent;
    BOOL                            ecidMeasuredInfoPresent;
    UINT8                           reserved1;
    CmiEcidMeasResult               ecidMeasResult;
    CmiOtdoaMeasuredInfoNB          otdoaMeasuredInfo;  /*valid when "otdoaMeasuredInfoPresent" = TRUE*/
    CmiEcidMeasuredInfo             ecidMeasuredInfo;   /*valid when "ecidMeasuredInfoPresent" = TRUE*/
}CmiDevLppGetEarlyLocCnf;

/******************************************************************************
 * CMI_DEV_LPP_GET_CELL_INFO_REQ
******************************************************************************/
typedef CacCmiEmptySig CmiDevLppGetCellInfoReq;

/******************************************************************************
 * CMI_DEV_LPP_GET_CELL_INFO_CNF
******************************************************************************/
typedef struct CmiDevLppGetCellInfoCnf_Tag
{
    CmiECGI                         ecgi;
    UINT16                          phyCellId;
}CmiDevLppGetCellInfoCnf;

/******************************************************************************
 * CMI_DEV_SET_CMOLR_REQ
******************************************************************************/

typedef enum CmiDevMolrEnableModeEnum_Tag
{
    CMI_DEV_DISABLE_REPORTING_AND_POSITIONING    = 0,
    CMI_DEV_ENABLE_REPORTING_NMEA                = 1,
    CMI_DEV_ENABLE_REPORTING_GAD_SHAPES          = 2,
    CMI_DEV_ENABLE_REPORTING_NMEA_AND_GAD_SHAPES = 3
}
CmiDevMolrEnableModeEnum;

typedef enum CmiDevMolrMethodEnum_Tag
{
    CMI_DEV_UNASSISTED_GPS             = 0,
    CMI_DEV_ASSISTED_GPS               = 1,
    CMI_DEV_ASSISTED_GANSS             = 2,
    CMI_DEV_ASSISTED_GPS_AND_GANSS     = 3,
    CMI_DEV_BASIC_SELF_LOCATION        = 4,
    CMI_DEV_TRANSFER_TO_THIRD_PARTY    = 5,
    CMI_DEV_RETRIEVAL_FROM_THIRD_PARTY = 6
}
CmiDevMolrMethodEnum;

typedef enum CmiDevHorizontalAccuracySet_Tag
{
    CMI_DEV_HOR_ACC_NOT_SET = 0,
    CMI_DEV_HOR_ACC_SET     = 1
}
CmiDevHorizontalAccuracySet;

typedef enum CmiDevVerReq_Tag
{
    CMI_DEV_VER_REQ_NOT_REQUESTED = 0,
    CMI_DEV_VER_REQ_REQUESTED     = 1
}
CmiDevVerReq;

typedef enum CmiDevVerticalAccuracySet_Tag
{
    CMI_DEV_VER_ACC_NOT_SET = 0,
    CMI_DEV_VER_ACC_SET     = 1
}
CmiDevVerticalAccuracySet;

typedef enum CmiDevVelocityType_Tag
{
    CMI_DEV_VELOCITY_NOT_REQUESTED                                      = 0,
    CMI_DEV_HORIZONTAL_VELOCITY_REQUESTED                               = 1,
    CMI_DEV_HORIZONTAL_AND_VERTICAL_VELOCITY_REQUESTED                  = 2,
    CMI_DEV_HORIZONTAL_VELOCITY_WITH_UNCERTAINTY_REQUESTED              = 3,
    CMI_DEV_HORIZONTAL_AND_VERTICAL_VELOCITY_WITH_UNCERTAINTY_REQUESTED = 4
}
CmiDevVelocityType;

typedef enum CmiDevMolrReportingMode_Tag
{
    CMI_DEV_MOLR_SINGLE_REPORT      = 0,
    CMI_DEV_MOLR_PERIODIC_REPORTING = 1
}
CmiDevMolrReportingMode;

typedef enum CmiDevShapeRepresenting_Tag
{
    CMI_DEV_ELLIPSOID_POINT                                         = 0x01,
    CMI_DEV_ELLIPSOID_POINT_WITH_UNCERTAINTY_CIRCLE                 = 0x02,
    CMI_DEV_ELLIPSOID_POINT_WITH_UNCERTAINTY_ELLIPSE                = 0x04,
    CMI_DEV_POLYGON                                                 = 0x08,
    CMI_DEV_ELLIPSOID_POINT_WITH_ALTITUDE                           = 0x10,
    CMI_DEV_ELLIPSOID_POINT_WITH_ALTITUDE_AND_UNCERTAINTY_ELLIPSOID = 0x20,
    CMI_DEV_ELLIPSOID_ARC                                           = 0x40
}
CmiDevShapeRepresenting;

typedef enum CmiDevMolrPlane_Tag
{
    CMI_DEV_CONTROL_PLANE     = 0,
    CMI_DEV_SECURE_USER_PLANE = 1
}
CmiDevMolrPlane;

typedef enum CmiDevNmeaStringType_Tag
{
    CMI_DEV_NMEA_TYPE_GPRMC   = 0,
    CMI_DEV_NMEA_TYPE_GPGSA   = 1,
    CMI_DEV_NMEA_TYPE_GPGSV   = 2,
    CMI_DEV_NMEA_TYPE_DEFAULT = 3
}
CmiDevNmeaStringType;

typedef struct LppMessage_Tag
{
    UINT8   length;
    UINT8   *pMessage;
}
LppMessage;

typedef struct CmiDevSetCmolrReq_Tag
{
    BOOL        enablePresent;
    UINT8       enableMode;     //CmiDevMolrEnableModeEnum
    BOOL        methodPresent;
    UINT8       method;         //CmiDevMolrMethodEnum
    BOOL        horAccSetPresent;
    UINT8       horAccSet;      //CmiDevHorizontalAccuracySet
    UINT8       horAcc;         //The value range is 0-127
    BOOL        verReqPresent;
    UINT8       verReq;         //CmiDevVerReq
    BOOL        verAccSetPresent;
    UINT8       verAccSet;      //CmiDevVerticalAccuracySet
    UINT8       verAcc;         //The value range is 0-127
    BOOL        velReqPresent;
    UINT8       velReq;         //CmiDevVelocityType     refer to 'velocityEstimate' in MOLR,shall not be included for E-UTRAN access.
    BOOL        reportModePresent;
    UINT8       reportMode;     //CmiDevMolrReportingMode
    UINT16      timeout;        //The value range is in seconds from 1 to 65535
    UINT16      interval;       //The value range is in seconds from 1 to 65535,and must be greater than or equal to <timeout>
    BOOL        shapeRepPresent;
    UINT8       shapeRep;       //CmiDevShapeRepresenting
    BOOL        planePresent;
    UINT8       plane;          //CmiDevMolrPlane
    //UINT8       nmeaRep;        //CmiDevNmeaStringType       not use
    //third-party-address  TBD
    UINT8       numOfLppMsg;    //1~3
    LppMessage  lppMsg[3];
}
CmiDevSetCmolrReq;

typedef CacCmiEmptySig CmiDevSetCmolrCnf;

/******************************************************************************
 * CMI_DEV_GET_CMOLR_REQ
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetCfunReq;

typedef struct CmiDevGetCmolrCnf_Tag
{
    UINT8       enableMode;     //CmiDevMolrEnableModeEnum
    UINT8       method;         //CmiDevMolrMethodEnum
    UINT8       horAccSet;      //CmiDevHorizontalAccuracySet
    BOOL        horAccPresent;
    UINT8       horAcc;         //The value range is 0-127
    UINT8       verReq;         //CmiDevVerReq
    BOOL        verAccSetPresent;
    UINT8       verAccSet;      //CmiDevVerticalAccuracySet
    BOOL        verAccPresent;
    UINT8       verAcc;         //The value range is 0-127
    UINT8       velReq;         //CmiDevVelocityType     refer to 'velocityEstimate' in MOLR,shall not be included for E-UTRAN access.
    UINT8       reportMode;     //CmiDevMolrReportingMode
    UINT16      timeout;        //The value range is in seconds from 1 to 65535
    UINT16      interval;       //The value range is in seconds from 1 to 65535,and must be greater than or equal to <timeout>
    UINT8       shapeRep;       //CmiDevShapeRepresenting
    UINT8       plane;          //CmiDevMolrPlane
    UINT8       nmeaRep;        //CmiDevNmeaStringType
    //BOOL        thirdpartyAddressPresent;
    //third-party-address  TBD
}CmiDevGetCmolrCnf;

/******************************************************************************
 * CMI_DEV_GET_CMOLR_CAPA_REQ
******************************************************************************/
/*typedef CacCmiEmptySig CmiDevGetCfunCapaReq;

typedef struct CmiDevGetCmolrCapaCnf_Tag
{
}CmiDevGetCmolrCapaCnf;*/


/******************************************************************************
 * CMI_DEV_SET_CMTLR_REQ
******************************************************************************/

typedef enum CmiDevSubscriber_Tag
{
    DISABLE_REPORTING_AND_POSITIONING                 = 0,
    NOTIFICATION_OF_MTLR_OVER_CONTROL_PLANE           = 1,
    NOTIFICATION_OF_MTLR_OVER_SUPLE                   = 2,
    NOTIFICATION_OF_MTLR_OVER_CONTROL_PLANE_AND_SUPLE = 3
}
CmiDevSubscriber;

typedef struct CmiDevSetCmtlrReq_Tag
{
    UINT8   subscribe;  //CmiDevSubscriber
    UINT8   reserved0;
    UINT16  reserved1;
}
CmiDevSetCmtlrReq;

typedef CacCmiEmptySig CmiDevSetCmtlrCnf;

/******************************************************************************
 * CMI_DEV_GET_CMTLR_REQ
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetCmtlrReq;

typedef struct CmiDevGetCmtlrCnf_Tag
{
    UINT8   subscribe; //CmiDevSubscriber
    UINT8   reserved1;
    UINT16  reserved2;
}
CmiDevGetCmtlrCnf;

/******************************************************************************
 * CMI_DEV_GET_CMTLR_CAPA_REQ
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetCmtlrCapaReq;

typedef struct CmiDevGetCmtlrCapaCnf_Tag
{
    UINT8       bBitMap; // bit 0 set to 1, means <subscribe> = 0;
    UINT8       reserved1;
    UINT16      reserved2;
}
CmiDevGetCmtlrCapaCnf;

/******************************************************************************
 * CMI_DEV_CMTLR_IND
******************************************************************************/
#define     CMI_DEV_MAX_SIZE_EXTERNAL_ADDRESS           20
#define     CMI_DEV_MAX_SIZE_EXTENSION_TYPE             16
#define     CMI_DEV_MAX_SIZE_EXTENSION_ID               16
#define     CMI_DEV_MAX_NUM_OF_PRIVATE_EXTENSIONS       10
#define     CMI_DEV_MAX_LCS_NAME_STRING_LENGTH          63

typedef enum CmiDevNotificationType_Tag
{
    POSITIONING_USER_IS_ALLOWED                       = 0,
    LOCATING_USER_IS_PERMITTED_IF_IGNORE_NOTIFICATION = 1,
    LOCATING_USER_IS_FORBIDDEN_IF_IGNORE_NOTIFICATION = 2
}
CmiDevNotificationType;

typedef enum CmiDevLocationType_Tag
{
    THE_CURRENT_LOCATION               = 0,
    THE_CURRENT_OR_LAST_KNOWN_LOCATION = 1,
    THE_INITIAL_LOCATION               = 2,
    LOCATION_TYPE_NOT_USED
}
CmiDevLocationType;

typedef struct CmiDevExternalAddress_Tag
{
    BOOL        present;
    INT8        addressLength;
    INT8        externalAddress[CMI_DEV_MAX_SIZE_EXTERNAL_ADDRESS];
}
CmiDevExternalAddress;

typedef struct CmiDevSsLcsExtensionType_Tag
{
    INT8         n;
    INT8         data[CMI_DEV_MAX_SIZE_EXTENSION_TYPE];
}
CmiDevSsLcsExtensionType;

typedef struct CmiDevSsLcsExtensionId_Tag
{
    INT8         n;
    INT8         data[CMI_DEV_MAX_SIZE_EXTENSION_ID];
}
CmiDevSsLcsExtensionId;

typedef struct CmiDevSsLcsPrivateExtListData_Tag
{
    BOOL                        extTypePresent;
    CmiDevSsLcsExtensionType    extType;
    CmiDevSsLcsExtensionId      extId;
}
CmiDevSsLcsPrivateExtListData;

typedef struct CmiDevSsLcsPrivateExtensionList_Tag
{
    INT8                            n; /* 1 to maxNumOfPrivateExtensions */
    CmiDevSsLcsPrivateExtListData   data[CMI_DEV_MAX_NUM_OF_PRIVATE_EXTENSIONS];
}
CmiDevSsLcsPrivateExtensionList;

typedef struct CmiDevSsLcsPcsExtensions_Tag
{
    INT8    dummy;
}
CmiDevSsLcsPcsExtensions;

typedef struct CmiDevSsLcsExtensionContainer_Tag
{
    BOOL                                privateExtensionListPresent;
    CmiDevSsLcsPrivateExtensionList     privateExtensionList;
    BOOL                                pcs_ExtensionsPresent;
    CmiDevSsLcsPcsExtensions            pcs_Extensions;
}
CmiDevSsLcsExtensionContainer;

typedef struct CmiDevExtensionContainer_Tag
{
    BOOL                            present;
    CmiDevSsLcsExtensionContainer   data;
}
CmiDevExtensionContainer;

typedef struct CmiDevClientExternalId_Tag
{
    BOOL                        present;
    CmiDevExternalAddress       externalAddress;
    CmiDevExtensionContainer    extensionContainer;
}
CmiDevClientExternalId;

typedef struct CmiDevDataCodingScheme_Tag
{
    INT8        scheme;
}
CmiDevDataCodingScheme;

typedef struct CmiDevNameString_Tag
{
    INT8        length;
    INT8        name[CMI_DEV_MAX_LCS_NAME_STRING_LENGTH];
}
CmiDevNameString;

typedef enum CmiDevLcsFormatIndicator_Tag
{
    CMI_DEV_LOGICAL_NAME  = 0,
    CMI_DEV_EMAIL_ADDRESS = 1,
    CMI_DEV_MSISDN        = 2,
    CMI_DEV_URL           = 3,
    CMI_DEV_SIP_URL       = 4
}
CmiDevLcsFormatIndicator;

typedef struct CmiDevLcsFormatIndicatorItem_Tag
{
    BOOL                        present;
    CmiDevLcsFormatIndicator    formatIndicator;
}
CmiDevLcsFormatIndicatorItem;

typedef struct CmiDevClientName_Tag
{
    BOOL                            present;
    CmiDevDataCodingScheme          dataCodingScheme;
    CmiDevNameString                nameString;
    CmiDevLcsFormatIndicatorItem    optFormatIndicator;
}
CmiDevClientName;

typedef struct CmiDevCmtlrInd_Tag
{
    UINT8                       handleId;
    UINT8                       notificationType;   //CmiDevNotificationType
    BOOL                        locationTypePresent;
    UINT8                       locationType;       //CmiDevLocationType
    CmiDevClientExternalId      clientExternalId;
    CmiDevClientName            clientName;
    UINT8                       plane;              //CmiDevMolrPlane
}
CmiDevCmtlrInd;

/******************************************************************************
 * CMI_DEV_SET_CMTLRA_REQ
******************************************************************************/

typedef enum CmidevLocationDisclosureAllowance_Tag
{
    LOCATION_DISCLOSURE_ALLOWED     = 0,
    LOCATION_DISCLOSURE_NOT_ALLOWED = 1
}
CmiDevLocationDisclosureAllowance;

typedef struct CmiDevSetCmtlraReq_Tag
{
    UINT8   locationAllowance;  //CmiDevLocationDisclosureAllowance
    UINT8   handleId;
}
CmiDevSetCmtlraReq;

typedef CacCmiEmptySig CmiDevSetCmtlraCnf;

/******************************************************************************
 * CMI_DEV_GET_CMTLRA_REQ
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetCmtlraReq;

typedef struct CmiDevGetCmtlraCnf_Tag
{
    UINT8   allowance; //CmiDevLocationDisclosureAllowance
    UINT8   handleId;
    UINT16  reserved;
}
CmiDevGetCmtlraCnf;

/******************************************************************************
 * CMI_DEV_GET_CMTLRA_CAPA_REQ
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetCmtlraCapaReq;

typedef struct CmiDevGetCmtlraCapaCnf_Tag
{
    UINT8       bBitMap; // bit 0 set to 1, means <allow> = 0;
    UINT8       reserved1;
    UINT16      reserved2;
}
CmiDevGetCmtlraCapaCnf;


/******************************************************************************
 * CMI_DEV_GET_EXT_STATUS_REQ
******************************************************************************/
typedef enum CmiGetExtStatusEnum_TAG
{
    CMI_DEV_GET_ECSTATUS = 0,
    CMI_DEV_GET_ECSTATUS_PHY,
    CMI_DEV_GET_ECSTATUS_L2,
    CMI_DEV_GET_ECSTATUS_RRC,
    CMI_DEV_GET_ECSTATUS_EMM,
    CMI_DEV_GET_ECSTATUS_PLMN,
    CMI_DEV_GET_ECSTATUS_ESM,
    CMI_DEV_GET_ECSTATUS_CCM,
    CMI_DEV_GET_NUESTATS,
    CMI_DEV_GET_NUESTATS_RADIO,
    CMI_DEV_GET_NUESTATS_CELL,
    CMI_DEV_GET_NUESTATS_BLER,
    CMI_DEV_GET_NUESTATS_THP,
    CMI_DEV_GET_NUESTATS_APPSMEM,
    CMI_DEV_GET_NUESTATS_ALL
}CmiGetExtStatusEnum;


/******************************************************************************
 * CMI_DEV_GET_EXT_STATUS_REQ, //AT$QCSTATUS?
 * CMI_DEV_GET_EXT_STATUS_CNF,
******************************************************************************/
typedef struct CmiDevGetExtStatusReq_Tag
{
    UINT8       getStatusType;   //CmiGetExtStatusEnum
    UINT8       reserved1;
    UINT16      reserved2;
}
CmiDevGetExtStatusReq;

/*
 * PHY status info
*/
typedef enum CmiDevEMNBOperModeEnum_Tag
{
    CMI_DEV_EM_NB_INBAND_SAME_PCI_MODE = 0,
    CMI_DEV_EM_NB_INBAND_DIFF_PCI_MODE,
    CMI_DEV_EM_NB_GUARD_BAND_MODE,
    CMI_DEV_EM_NB_STAND_ALONE_MODE
}CmiDevEMNBOperModeEnum;

typedef struct CmiDevPhyStatusInfo_Tag
{
    //value range: 0 ~ 262143
    UINT32      dlEarfcn;
    //PCI: value range: 0 ~ 503, 255
    UINT16      phyCellId;
    //indicate if this is the primaryCell, for NB-IoT, TRUE means the serving cell
    BOOL        primaryCell;
    //value in dB, value range: -30 ~ 30
    INT8        snr;
    //value in dBm, real RSRP = this value / 100, example: -10.5 dbm, sRsrp = -10.5*100 = -1050
    //value range: -15600 ~ -4400
    INT16       sRsrp;
    //value in dB, real RSRQ = this value / 100, example: -10.5 db, sRsrq = -10.5*100 = -1050
    //value range: -3400 ~ 250
    INT16       sRsrq;
    UINT8       anchorFreqOffset;    //CarrierFreqOffset
    UINT8       nonAnchorFreqOffset;    //CarrierFreqOffset
    UINT16      rsvd0;

    //value range: 0 ~ 262143
    UINT32      ulEarfcn;

    //CmiDevEMNBOperModeEnum
    UINT8       nbOperMode;
    //The current selected band accoring to BandIndicator or mFBI, value range: 0 ~ 85
    UINT8       band;

    //0-CE Level 0; 1-CE Level 1; 2-CE Level 2
    UINT8       ceLevel;
    UINT8       rsvd1;

    // DL block error, real block error * 10000, so 21, just means 0.0021 = 0.21%
    //value range: 0 ~ 10000
    UINT16      dlBler;
    // UL block error, real block error * 10000, so 21, just means 0.0021 = 0.21%
    //value range: 0 ~ 10000
    UINT16      ulBler;

    //dataInactivityTimer value in second
    //value range: 0 ~ 180; DataInactivityTimer
    UINT16      dataInactTimerS;
    //retxBSR-Timer value in PP
    //value range: 0 ~ infinity; RetxBSRTimerNB
    UINT16      retxBSRTimerP;
    //TA value in RAR, idle state report -1
    INT16      taValue;

    //Signal power in centibels
    INT16       signalPower;
    //Total power in centibels
    INT16       totalPower;
    //Current TX power level in dbm, -128 is the invalid value
    INT8        txPower;
    UINT8       rsvd;
    //Total TX time since last reboot in millisecond
    UINT32      txTime;
    //Total RX time since last reboot in millisecond
    UINT32      rxTime;
    //Total bytes transmitted
    UINT32      totalTxBytes;
    //Total bytes received
    UINT32      totalRxBytes;
    //Transport blocks sent
    UINT32      totalTxBlocks;
    //Transport blocks received
    UINT32      totalRxBlocks;
    //Transport blocks retransmitted
    UINT32      retransTxBlocks;
    //Total ACK/NACK messages received
    UINT32      retransRxBlocks;
}CmiDevPhyStatusInfo;   //28 bytes

/*
 * L2 status info
*/
typedef struct CmiDevL2StatusInfo_Tag
{
    //UINT8       rsvd;
    UINT8       srbNum;
    UINT8       drbNum;

    //UINT16      rsvd;

#if 0
    UINT32      rlcUlThp;     //RLC layer throughput (uplink). Integer bps
    UINT32      rlcDlThp;     //RLC layer throughput (downlink). Integer bps
    UINT32      macUlThp;     //Physical layer throughput (uplink). Integer bps
    UINT32      macDlThp;     //Physical layer throughput (downlink). Integer bps
#endif

    UINT8       rlcUlBler;           //RLC layer block error rate (uplink). Integer % (real block error * 10000)
    UINT8       rlcDlBler;           //RLC layer block error rate (downlink). Integer % (real block error * 10000)

#if 0
    UINT8       macUlBler;           //Physical layer block error rate (uplink). Integer %
    UINT8       macDlBler;           //Physical layer block error rate (downlink). Integer %

    UINT32      totalTxBytes;     //Total bytes transmitted
    UINT32      totalRxBytes;     //Total bytes received

    UINT32      totalTxBlocks;     //Transport blocks sent
    UINT32      totalRxBlocks;      //Transport blocks received
    UINT32      totalRtxBlocks;    //Transport blocks retransmitted
    UINT32      totalRxAckNack;    //Total ACK/NACK messages received
#endif
}CmiDevL2StatusInfo;    //4 bytes

/*
 * ERRC status info
 * EM: Engineering Mode
*/
typedef enum CmiDevEMRrcStateEnum_Tag
{
    CMI_DEV_EM_RRC_DEACTIVE_STATE = 0,
    CMI_DEV_EM_RRC_CELL_SEARCH_STATE,
    CMI_DEV_EM_RRC_NORMAL_IDLE_STATE,
    CMI_DEV_EM_RRC_SUSPEND_IDLE_STATE,
    CMI_DEV_EM_RRC_CONNECTED_STATE
}CmiDevEMRrcStateEnum;

/* The different between CmiDevNcellMeasInfo  and CmiDevNCellBasicInfo is that:
   CmiDevNcellMeasInfo: If Rrc has no neighbor cell info currently, it will not
   trigger ncell measurement, and not fill any infomation in struct CmiDevNcellMeasInfo.
   Intended to reduce power consumption.

   CmiDevNCellBasicInfo: If Rrc has no neighbor cell info currently, it will
   trigger ncell measurement, and fill ncell info in struct CmiDevNcellMeasInfo.
   It maybe increase power consumption.
*/
typedef struct CmiDevNcellMeasInfo_Tag
{
    UINT32       earfcn;
    UINT16       phyCellId;
    UINT16       rsvd;
    //value in units of dBm, value range: -156 ~ -44
    INT16           rsrp;
    //value in units of dB, value range: -34 ~ 25
    INT16           rsrq;
}CmiDevNcellMeasInfo;

typedef struct CmiDevRrcStatusInfo_Tag
{
    UINT8                 rrcState;   // CmiDevEMRrcStateEnum
    UINT8                 ncellNum;
    UINT16                tac;
    UINT32                cellId;
    CmiDevNcellMeasInfo   ncellMeasInfo[CMI_DEV_NCELL_INFO_CELL_NUM];
}CmiDevRrcStatusInfo;

/*
 * NAS(EMM/PLMN/ESM/SMS)
 *  EM: Engineering Mode
*/
typedef enum CmiDevEMEmmStateEnum_Tag
{
    CMI_DEV_EM_EMM_NULL_STATE = 0,  //EPS services are disabled in the UE
    CMI_DEV_EM_EMM_DEREGISTERED,
    CMI_DEV_EM_EMM_REGISTERED_INITIATED,
    CMI_DEV_EM_EMM_REGISTERED,
    CMI_DEV_EM_EMM_DEREGISTERED_INITIATED,
    CMI_DEV_EM_EMM_TAU_INITIATED,
    CMI_DEV_EM_EMM_SR_INITIATED
}CmiDevEMEmmStateEnum;

typedef enum CmiDevEmmSubState_Tag
{
    CMI_DEV_EMM_NULL                                = 0,
    CMI_DEV_EMM_REGISTERED_INITIATED                = 1,
    CMI_DEV_EMM_DEREGISTERED_INITIATED              = 2,
    CMI_DEV_EMM_TRACKING_AREA_UPDATING_INITIATED    = 3,
    CMI_DEV_EMM_SERVICE_REQUEST_INITIATED           = 4,
    CMI_DEV_EMM_DEREGISTERED_NORMAL_SERVICE         = 5,
    CMI_DEV_EMM_DEREGISTERED_LIMITED_SERVICE        = 6,
    CMI_DEV_EMM_DEREGISTERED_ATTEMPTING_TO_ATTACH   = 7,
    CMI_DEV_EMM_DEREGISTERED_PLMN_SEARCH            = 8,
    CMI_DEV_EMM_DEREGISTERED_NO_IMSI                = 9,
    CMI_DEV_EMM_DEREGISTERED_ATTACH_NEEDED          = 10,
    CMI_DEV_EMM_DEREGISTERED_NO_CELL_AVAILABLE      = 11,
    CMI_DEV_EMM_DEREGISTERED_ECALL_INACTIVE         = 12,
    CMI_DEV_EMM_REGISTERED_NORMAL_SERVICE           = 13,
    CMI_DEV_EMM_REGISTERED_ATTEMPTING_TO_UPDATE     = 14,
    CMI_DEV_EMM_REGISTERED_LIMITED_SERVICE          = 15,
    CMI_DEV_EMM_REGISTERED_PLMN_SEARCH              = 16,
    CMI_DEV_EMM_REGISTERED_UPDATE_NEEDED            = 17,
    CMI_DEV_EMM_REGISTERED_NO_CELL_AVAILABLE        = 18,
    CMI_DEV_EMM_REGISTERED_ATTEMPTING_TO_UPDATE_MM  = 19,
    CMI_DEV_EMM_REGISTERED_IMSI_DETACH_INITIATED    = 20
}CmiDevEmmSubState;

typedef enum CmiDevEmmLapiInfo_Tag
{
    CMI_DEV_NAS_SIGNALLING_RESERVED1    = 0,    /* Reserved(0) */
    CMI_DEV_NAS_SIGNALLING_LOW_PRIORITY = 1,    /* NAS signalling low priority */
    CMI_DEV_NAS_SIGNALLING_RESERVED2    = 2     /* Reserved(2-255) */
}CmiDevEmmLapiInfo;

/*
 * IDLE/PSM/CONNECTED
*/
typedef enum CmiDevEMEmmModeEnum_Tag
{
    CMI_DEV_EM_EMM_IDLE_MODE = 0,
    CMI_DEV_EM_EMM_PSM_MODE,
    CMI_DEV_EM_EMM_CONNECTED_MODE
}CmiDevEMEmmModeEnum;

/*
 * PLMN state
*/
typedef enum CmiDevEMPlmnStateEnum_Tag
{
    CMI_DEV_EM_NO_PLMN_SELECTED = 0,
    CMI_DEV_EM_PLMN_SEARCHING,
    CMI_DEV_EM_PLMN_SELECTED
}CmiDevEMPlmnStateEnum;

/*
 * PLMN type
*/
typedef enum CmiDevEMPlmnTypeEnum_Tag
{
    CMI_DEV_EMM_HPLMN = 0, //home PLMN, derived from IMSI
    CMI_DEV_EMM_EHPLMN,    //equivalent home PLMN
    CMI_DEV_EMM_VPLMN,     //visited PLMN
    CMI_DEV_EMM_UPLMN,     //user controlled PLMN
    CMI_DEV_EMM_OPLMN,     //operator controlled PLMN
    CMI_DEV_EMM_FPLMN,     //forbidden PLMN
    CMI_DEV_EMM_APLMN,     //available PLMN
}CmiDevEMPlmnTypeEnum;

#define CMI_DEV_EM_APN_LEN  32
typedef struct CmiDevNasStatusInfo_Tag
{
    /*
     * EMM
    */
    UINT8       emmState;       //CmiDevEMEmmStateEnum
    UINT8       emmMode;        //CmiDevEMEmmModeEnum
    UINT16      ptwMs;          //eDRX PTW in milli-second
    UINT32      eDRXPeriodMs;   //eDRX period in MS

    UINT32      psmExT3412TimerS;   //Extended T3412 timer in second

    UINT16      T3324TimerS;        //T3324 timer in second
    UINT16      T3346RemainTimeS;   //If T3346 is runing, set the remaining time, or set 0;

    /*
     * PLMN
    */
    UINT8       plmnState;      //CmiDevEMPlmnStateEnum
    UINT8       plmnType;       //CmiDevEMPlmnTypeEnum
    UINT16      rsvd0;
    CmiNumericPlmn  selectPlmn; //selected PLMN

    /*
     * ESM
    */
    UINT8       actBearerNum;   //How many activated bearer number
    UINT8       rsvd1;
    UINT16      rsvd2;
    UINT8       apnStr[CMI_DEV_EM_APN_LEN];
    CmiIpAddr   ipv4Addr;       //only print one bearer address
    CmiIpAddr   ipv6Addr;

}CmiDevNasStatusInfo;   //100 bytes

typedef struct CmiDevNasEmmSubState_Tag
{
    UINT8 emmSubstate;
}CmiDevNasEmmSubState;

/*
 * CCM
 *  EM: Engineering Mode
*/
#define CMI_DEV_EM_IMSI_STR_LEN 16
typedef struct CmiDevCcmStatusInfo_Tag
{
    UINT8       cfunValue;  //CmiFuncValueEnum
    UINT8       rsvd0;
    UINT16      rsvd1;
    /*example: IMSI: "460002343454245" */
    CHAR        imsi[CMI_DEV_EM_IMSI_STR_LEN];
}CmiDevCcmStatusInfo;   //20 bytes


/*
 * CMI_DEV_GET_BASIC_CELL_LIST_INFO_REQ,   //AT$QCBCINFOREQ
 * CMI_DEV_GET_BASIC_CELL_LIST_INFO_CNF,
*/
//typedef CacCmiEmptySig CmiDevGetBasicCellListInfoReq;
typedef enum CmiDevGetBasicCellInfoMode_Enum
{
    CMI_DEV_GET_BASIC_CELL_MEAS = 0,    //measure neighber cell signal quality: RSRP and RSRQ, don't need to acquire neighber cell SIB-NB.
    CMI_DEV_GET_BASIC_CELL_ID,          //search cell, including measure cell and acquire cell SIB1-NB to get cellID, PLMN, and tac info
    CMI_DEV_GET_SAVED_BASIC_CELL_INFO
}CmiDevGetBasicCellInfoMode;

typedef enum CmiDevGetBasicCellInfoRptMode_Enum
{
    CMI_DEV_BCINFO_SYN_RPT  = 0,        //cell info report in CMI CNF
    CMI_DEV_BCINFO_ASYN_RPT            //cell info report in CMI IND (URC)
}CmiDevGetBasicCellInfoRptMode;


typedef struct CmiDevGetBasicCellListInfoReq_Tag
{
    UINT8       mode;
    BOOL        needSave;           /* whether need to save neighber cell info into tiny context */
    UINT16      maxTimeoutS;        /* MAX measurement/search timeout in second */

    UINT8       reqMaxCellNum;      /* MAX Cell number request, (1-5) */
    UINT8       rptMode;            /* Syn mode, or Asyn mode */
    UINT16      rsvd;
}CmiDevGetBasicCellListInfoReq; //8 bytes

typedef struct CmiDevSCellBasicInfo_Tag
{
    CmiNumericPlmn  plmn;

    //DL earfcn (anchor earfcn), range 0 - 262143
    UINT32          earfcn;
    //the 28 bits Cell-Identity in SIB1, range 0 - 268435455
    UINT32          cellId;
    UINT16          tac;
    UINT16          rsvd0;

    //Physical Cell ID, range 0 - 503
    UINT16          phyCellId;
    //value in dB, value range: -30 ~ 30
    BOOL            snrPresent;   /*serving cell SNR some case not present*/
    INT8            snr;

    //value in units of dBm, value range: -156 ~ -44
    INT16           rsrp;
    //value in units of dB, value range: -34 ~ 25
    INT16           rsrq;
}CmiDevSCellBasicInfo;  //24 bytes

typedef struct CmiDevNCellBasicInfo_Tag
{
    //DL earfcn (anchor earfcn), range 0 - 262143
    UINT32          earfcn;

    //Physical Cell ID, range 0 - 503
    UINT16          phyCellId;
    UINT16          revd0;
    //value in units of dBm, value range: -156 ~ -44
    INT16           rsrp;
    //value in units of dB, value range: -34 ~ 25
    INT16           rsrq;

    //value in dB, value range: -30 ~ 30
    INT8            snr;
    //UINT8           rsvd[3];
    //whether plmn/tac/cellId valid/present
    BOOL            cellInfoValid;
    UINT16          tac;

    CmiNumericPlmn  plmn;
    //the 28 bits Cell-Identity in SIB1, range 0 - 268435455
    UINT32          cellId;
}CmiDevNCellBasicInfo;  //24 bytes


typedef struct CmiDevGetBasicCellListInfoCnf_Tag
{
    BOOL            sCellPresent;
    UINT8           nCellNum;
    UINT16          rsvd0;

    CmiDevSCellBasicInfo    sCellInfo;  //24 bytes
    CmiDevNCellBasicInfo    nCellList[CMI_DEV_NCELL_INFO_CELL_NUM]; //96 bytes
}CmiDevGetBasicCellListInfoCnf; //124 bytes

/* CMI_DEV_GET_BASIC_CELL_LIST_INFO_IND */
typedef CmiDevGetBasicCellListInfoCnf   CmiDevGetBasicCellListInfoInd;


/******************************************************************************
 * CMI_DEV_SET_EXT_STATIS_MODE_REQ,     //AT+ESTATIS=<n>
 * CMI_DEV_SET_EXT_STATIS_MODE_CNF,
 * CMI_DEV_EXT_STATIS_IND,     //+ESTATIS:
******************************************************************************/
typedef struct CmiDevSetExtStatisModeReq_Tag
{
    UINT16      periodRptS; //"CMI_DEV_EXT_STATIS_IND" report period, if set to 0, stop statis report
    UINT16      rsvd0;
}CmiDevSetExtStatisModeReq;

typedef CacCmiEmptySig  CmiDevSetExtStatisModeCnf;


/*
 * CMI_DEV_EXT_STATIS_IND
 * CmiDevExtStatisInd
 * Period Engineering Mode statistic indication
*/
typedef struct CmiDevL2StatisInfo_Tag
{
    UINT32      macUlBytes;     //MAC UL sent total bytes, including padding & MAC CE
    UINT32      macUlPadBytes;  //MAC UL sent total padding bytes
    UINT32      macDlBytes;     //MAC DL recv total bytes, including padding & MAC CE
    UINT32      macDlPadBytes;  //MAC DL recv total padding bytes, including MAC discard bytes

    UINT32      rlcUlPduBytes;  //RLC UL sent PDU total bytes
    UINT32      rlcUlRetxBytes; //RLC UL sent Retx PDU bytes
    UINT32      rlcDlPduBytes;  //RLC DL recv PDU total bytes

    UINT32      pdcpUlPduBytes; //PDCP UL PDU total bytes, not means already sent
    UINT32      pdcpDlPduBytes; //PDCP DL recv PDU total bytes
    UINT32      pdcpULDiscardBytes; //PDCP UL discard PDU bytes
}CmiDevL2StatisInfo;    //40 bytes

/*
 * Same structure defination as: "CephyStatisInfoInd"
*/
typedef struct CmiDevPhyStatisInfo_Tag
{
    // value in dBm, real RSRP = this value / 100
    INT16                           avgRsrp;
    // value in dB, real SNR = this value / 100, value range: -3000 ~ 3000
    INT16                           avgSnr;

    // downlink I_TBS, refer to table 16.4.1.5.1-1 of TS36.213 for NB-IoT
    // real I_TBS = this value / 100
    UINT16                          dlAvgITBS;
    // uplink I_TBS, refer to table 16.5.1.2-1 & 16.5.1.2-2 of TS36.213 for NB-IoT
    // real I_TBS = this value / 100
    UINT16                          ulAvgITBS;

    // DL block error, real block error * 10000, so 21, just means 0.0021 = 0.21%
    UINT16                          dlBler;
    // UL block error, real block error * 10000, so 21, just means 0.0021 = 0.21%
    UINT16                          ulBler;

    // DCI N1 ratio of HARQ0 & 1, real ratio = this value / 100
    UINT8                           dlGrantRatio[2];
    // DCI N0 ratio of HARQ0 & 1, real ratio = this value / 100
    UINT8                           ulGrantRatio[2];

    // value in ms
    // downlink N_REP, refer to table 16.4.1.3-2 of TS36.213
    // real Nrep = this value / 10
    UINT16                          dlAvgNrep;
    // value in ms
    // uplink N_REP, refer to table 16.5.1.1-3 of TS36.213
    // real Nrep = this value / 10
    UINT16                          ulAvgNrep;

    // value in ms
    // downlink N_SF * N_REP, refer to table 16.4.1.3-1 & 16.4.1.3-2 of TS36.213
    // real value = this value / 10
    UINT32                          dlAvgSbfrmNum;
    // value in ms
    // uplink N_UL_SLOTS * N_RU * N_REP, refer to table 16.5.1.1-2 & 16.5.1.1-3 of TS36.213 and table 10.1.2.3-1 of TS36.211
    // real value = this value / 10
    UINT32                          ulAvgSbfrmNum;

    // uplink subcarrier number
    // real value = this value / 100
    UINT32                          ulAvgScNum;

    // downlink average TB size, value in byte
    // real value = this value / 100
    UINT16                          dlAvgTBSize;
    // uplink average TB size, value in byte
    // real value = this value / 100
    UINT16                          ulAvgTBSize;

    // downlink total TB size, value in byte
    UINT32                          dlAccTBSize;
    // uplink total TB size, value in byte
    UINT32                          ulAccTBSize;
}CmiDevPhyStatisInfo;


typedef struct CmiDevExtStatisInd_Tag
{
    UINT16      periodTimeS;    //statis period time in second, could used to calc TPT
    UINT16      rsvd0;

    CmiDevL2StatisInfo  l2StatisInfo;
    CmiDevPhyStatisInfo phyStatisInfo;
}CmiDevExtStatisInd;


typedef struct CmiDevGetExtStatusCnf_Tag
{
    UINT8                           getStatusType; /* CmiGetExtStatusEnum  */
    UINT8                           rsvd[3];
    CmiDevPhyStatusInfo             phyStatus;  //44 bytes
    CmiDevL2StatusInfo              l2Status;   //4 bytes
    CmiDevRrcStatusInfo             rrcStatus;  //8 bytes
    CmiDevNasStatusInfo             nasStatus;  //100 bytes
    CmiDevCcmStatusInfo             ccmStatus;  //20 bytes
    CmiDevGetBasicCellListInfoCnf   basicCellListInfo; //124 bytes
    CmiDevL2StatisInfo              l2Statis;   //40 bytes
}CmiDevGetExtStatusCnf; //344 bytes


/*
 * CMI_DEV_BAND_APN_AUTO_CONFIG_REQ_IND
*/
typedef struct CmiDevBandApnAutoCfgReqInd_Tag
{
    BOOL        bCfgApn;
    BOOL        bCfgBand;
    UINT16      rsvd0;

    /*
     * IMSI
    */
    CmiSimImsiStr   imsiStr;    //20 bytess
}CmiDevBandApnAutoCfgReqInd;    //24 bytes


/*
 * CMI_DEV_POWER_ON_CFUN_IND
*/
typedef struct CmiDevPowerOnCfunInd_Tag
{
    UINT8       func; //CmiFuncValueEnum
    UINT8       rsvd1;
    UINT16      rsvd2;
}CmiDevPowerOnCfunInd;

/*
 * CMI_DEV_SILENT_RESET_IND
*/
typedef CacCmiEmptySig CmiDevSilentResetInd;

/*
 * CMI_DEV_WAKEUP_IND
*/
typedef struct CmiDevWakeupInd_Tag
{
    BOOL    wakeUp;
    UINT8   currOperator;
    UINT16  reserved1;
}
CmiDevWakeupInd;


/******************************************************************************
 * CMI_DEV_SET_ECPSTEST_REQ
******************************************************************************/
typedef struct CmiDevSetPsTestReq_Tag
{
    BOOL    enablePsTest;
    UINT8   reserved0;
    UINT16  reserved1;
}
CmiDevSetPsTestReq;

typedef CacCmiEmptySig CmiDevSetPsTestCnf;

/******************************************************************************
 * CMI_DEV_GET_ECPSTEST_REQ
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetPsTestReq;

typedef struct CmiDevGetPsTestCnf_Tag
{
    BOOL    enablePsTest;
    UINT8   reserved1;
    UINT16  reserved2;
}
CmiDevGetPsTestCnf;

/******************************************************************************
 * CMI_DEV_SET_ECPOWERCLASS_REQ
******************************************************************************/
typedef struct CmiDevSetPowerClassReq_Tag
{
    UINT8   band;
    UINT8   powerClass;
    UINT16  reserved2;
}
CmiDevSetPowerClassReq;

typedef CacCmiEmptySig CmiDevSetPowerClassCnf;

/******************************************************************************
 * CMI_DEV_GET_ECPOWERCLASS_REQ
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetPowerClassReq;

typedef struct CmiDevGetPowerClassCnf_Tag
{
    UINT8   numOfBand;
    UINT8   rsv0;
    UINT16  rsv1;
    UINT8   band[CMI_DEV_SUPPORT_MAX_BAND_NUM];
    UINT8   powerClass[CMI_DEV_SUPPORT_MAX_BAND_NUM];
}
CmiDevGetPowerClassCnf;

/******************************************************************************
 * CMI_DEV_GET_ECPOWERCLASS_CAPA_REQ
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetPowerClassCapaReq;

typedef struct CmiDevGetPowerClassCapaCnf_Tag
{
    UINT8   numOfBand;
    UINT8   rsv0;
    UINT16  rsv1;
    UINT8   band[CMI_DEV_SUPPORT_MAX_BAND_NUM];
    UINT8   powerClass[CMI_DEV_SUPPORT_MAX_BAND_NUM];
}
CmiDevGetPowerClassCapaCnf;

typedef enum CmiDevErrcUEState_Tag
{
    CMI_DEV_ERRC_UE_RACH      = 0,
    CMI_DEV_ERRC_UE_IDLE      = 1,
    CMI_DEV_ERRC_UE_CONNECTED = 2,
}CmiDevErrcUEState;

typedef enum CmiDevErrcReportReason_Tag
{
    CMI_DEV_ERRC_REPORT_SET_CE_INFO = 0,
    CMI_DEV_ERRC_REPORT_GET_CE_INFO = 1,
    CMI_DEV_ERRC_UNSOLICITED_REPORT = 2,
}CmiDevErrcReportReason ;        

/******************************************************************************
 * CMI_DEV_SET_CE_INFO_REQ
******************************************************************************/
typedef struct CmiDevSetCeInfoReq_Tag
{
    UINT8                           ceInfoReporting;
}CmiDevSetCeInfoReq;

/******************************************************************************
 * CMI_DEV_GET_CE_INFO_REQ
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetCeInfoReq;

/******************************************************************************
 * CMI_DEV_CE_INFO_IND
******************************************************************************/
typedef struct CmiDevCeInfoInd_Tag
{
    BOOL                                    ceInfoReportingEnabled;  //Store CE reporting enable/disable info
    BOOL                                    ceEnabled;
    CmiDevErrcUEState                       ueState;    //Store the UE state  //
    UINT8                                   downlinkRepetition; //Store downlinkRepetition factor
    UINT8                                   uplinkRepetition; //Store uplinkRepetition factor
    //value in units of dBm, value range: -156 ~ -44
    INT16                                   rsrp;
    // value in dB, value range: -30 ~ 30
    INT8                                    cinr;
}CmiDevCeInfoInd;

/******************************************************************************
 * CMI_DEV_SET_CE_INFO_CNF
 * structure of CmiDevSetCeInfoCnf is same as CmiDevCeInfoInd
******************************************************************************/
typedef CmiDevCeInfoInd CmiDevSetCeInfoCnf;

/******************************************************************************
 * CMI_DEV_GET_CE_INFO_CNF
 * structure of CmiDevGetCeInfoCnf is same as CmiDevCeInfoInd
******************************************************************************/
typedef CmiDevCeInfoInd CmiDevGetCeInfoCnf;


/******************************************************************************
 * CMI_DEV_GET_RPM_PARAM_INFO_REQ
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetRpmParamInfoReq;

/******************************************************************************
 * CMI_DEV_GET_RPM_VERSION_REQ
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetRpmVersionReq;

/******************************************************************************
 * CMI_DEV_GET_RPM_PARAM_INFO_CNF
******************************************************************************/
typedef struct CmiDevGetRpmParamInfoCnf_Tag
{
    /* RPM functionality enabled or disabled at power up */
    BOOL                 rpmFlag;

    /* Max no of SW resets per Hour allowed by RPM following permanent EMM reject */
    UINT8                N1;

    /* Average time before RPM resets modem following permanent EMM reject */
    UINT8                T1;

    /* Average time before RPM resets modem following permanent EMM reject if T1 = 0xFF */
    UINT8                T1_ext;
    
    /* Max number of PDN Connectivity Requests per Hour allowed by RPM following PDP Activation Ignore Scenario */
    UINT8                F1;

    /* Max number of PDN Connectivity Requests per Hour allowed by RPM following Permanent PDP Activation Reject */
    UINT8                F2;

    /* Max number of PDN Connectivity Requests per Hour allowed by RPM following Temporary PDP Activation Reject */
    UINT8                F3;

    /* Max number of PDN Connectivity Activation/ Deactivation Requests per Hour allowed by RPM */
    UINT8                F4;
    
    /* If RPM params are present on SIM card, If not all RPM OM functionality shall be disabled */
    BOOL                 isOmParamsValid;
    
    /* Operational Management Counter related to N1 */
    UINT8                CBR1;

    /* Operational Management Counter related to T1 */
    UINT8                CR1;
    
    /* Operational Management Counters related to F1 */
    UINT8                CPDP1;

    /* Operational Management Counters related to F2 */
    UINT8                CPDP2;

    /* Operational Management Counters related to F3 */
    UINT8                CPDP3;

    /* Operational Management Counters related to F4 */
    UINT8                CPDP4;
    
    /* Leak rate(in Hours) for C-BR-1 */
    UINT8                LR1;

    /* Leak rate(in Hours) for C-R-1 */
    UINT8                LR2;

    /* Leak rate(in Hours) for CPDP-1 to C-PDP-4 */
    UINT8                LR3;
}CmiDevGetRpmParamInfoCnf;

/******************************************************************************
 * CMI_DEV_GET_RPM_VERSION_CNF
******************************************************************************/
typedef struct CmiDevGetRpmVersionCnf_Tag
{
    UINT8                rpmVersion;  //Store RPM Version implemented
}CmiDevGetRpmVersionCnf;


/******************************************************************************
 * CMI_DEV_SET_VZW_THROTTLE_REQ
******************************************************************************/
typedef struct CmiDevSetVzwThrottleReq_Tag
{
    UINT16               maxLogTime;
    UINT8                maxEventCounter;
    UINT8                reserved0;
}CmiDevSetVzwThrottleReq;

/******************************************************************************
 * CMI_DEV_SET_VZW_THROTTLE_CNF
******************************************************************************/
typedef CacCmiEmptySig CmiDevSetVzwThrottleCnf;

/******************************************************************************
 * CMI_DEV_GET_VZW_THROTTLE_REQ
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetVzwThrottleReq;

/******************************************************************************
 * CMI_DEV_GET_VZW_THROTTLE_CNF
******************************************************************************/
typedef struct CmiDevGetVzwThrottleCnf_Tag
{
    UINT16               maxLogTime;
    UINT8                maxEventCounter;
}CmiDevGetVzwThrottleCnf;
/******************************************************************************
 * CMI_DEV_GET_ECEVENTSTATIS_STATUS_REQ
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetEventStatisReq;

typedef struct CmiDevGetEventStatisCnf_Tag
{
    UINT16  curMode;            /* current AT+ECEVENTSTATIS=<mode>*/
    UINT16  numRrcEstSucc;      /* count of RrcConnection Success */
    UINT16  numRrcEstFail;
    UINT16  numAttachSucc;      /* count of Attach Success */
    UINT16  numAttachFail;
    UINT16  numTauSucc;         /* count of TAU Success */
    UINT16  numTauFail;
    UINT16  numSrSucc;          /* count of Service request Success */
    UINT16  numSrFail;
    UINT16  numAuthFail;        /* count of Authentication Success */
    UINT16  numDetach;          /* count of Detach */
    UINT16  numOOS;             /* count of PLMN, OOS */
}
CmiDevGetEventStatisCnf;

/******************************************************************************
 * CMI_DEV_SET_ECEVENTSTATIS_MODE_REQ
******************************************************************************/
typedef struct CmiDevSetEventStatisReq_Tag
{
    UINT8   mode;
    UINT8   reserved1;
    UINT16  reserved2;
}
CmiDevSetEventStatisReq;

typedef struct CmiDevSetEventStatisCnf_Tag
{
    UINT8   ret; //CmiFuncValueEnum
    UINT8   reserved0;
    UINT16  reserved1;
}CmiDevSetEventStatisCnf;

/******************************************************************************
 * CmiDevEmmEventStatisCnf
 * SIG_CCM_GET_EMM_EVENT_STATIS_CNF
******************************************************************************/
typedef struct CmiDevEmmEventStatisCnf_Tag
{
    BOOL    eventMode;
    UINT16  numAttachSucc;      /* count of Attach Success */
    UINT16  numAttachFail;
    UINT16  numTauSucc;         /* count of TAU Success */
    UINT16  numTauFail;
    UINT16  numSrSucc;          /* count of Service request Success */
    UINT16  numSrFail;
    UINT16  numAuthFail;        /* count of Authentication Success */
    UINT16  numDetach;          /* count of Detach */
    UINT16  numOOS;             /* count of PLMN, OOS */
    UINT8   reverse0;
}CmiDevEmmEventStatisCnf;


/******************************************************************************
 * CmiDevCrrcEventStatisCnf
 * SIG_CCM_GET_CERRC_EVENT_STATIS_CNF
******************************************************************************/
typedef struct CmiDevCrrcEventStatisCnf_Tag
{
    UINT16  numRrcConnEstSucc;      /* count of RRC Conn Est Success */
    UINT16  numRrcConnEstFail;      /* count of RRC Conn Est fail */
}CmiDevCrrcEventStatisCnf;

/******************************************************************************
 * CmiDevEmmRrcEventStatisCnf
******************************************************************************/
typedef struct CmiDevEmmRrcEventStatisCnf_Tag
{
    BOOL    rrcReceived;
    BOOL    emmReceived;
    UINT16  reversed;
    CmiDevCrrcEventStatisCnf    rrcEventStatisCnf;
    CmiDevEmmEventStatisCnf     emmEventStatisCnf;
}CmiDevEmmRrcEventStatisCnf;

/******************************************************************************
 * CMI_DEV_GET_NB_REL_FEATURE_REQ
 * CMI_DEV_GET_NB_REL_FEATURE_CNF
 * 1> AT+ECNBR14
 * 2> Currently, only support R14, so here default get R14 feature
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetNBRelFeatureReq;

typedef struct CmiDevGetNBRelFeatureCnf_Tag
{
    /* UE capability */
    UINT8   ueRelVer;           //13 or 14
    BOOL    ueR14UpRaiCap;      //0 or 1

    /* NW capability */
    BOOL    r14TwoHarqEnabled;  /* Two-Harq capability in current RRC connection, get from RrcConnectionSetup  */
    BOOL    r14UpRaiEnabled;    /* R14 RAI capability in current RRC connection, get from RrcConnectionSetup  */

    BOOL    r14NonAnchorNPrach; /* R14 non-anchor NPRACH capability, get from SIB-22-NB */
    BOOL    r14NonAnchorPaging; /* R14 non-anchor paging capability, get from SIB-22-NB */
    BOOL    r14CpReest;         /* R14 CP Reestablishmen capability, get from SIB-2-NB */
    UINT8   rsvd;
}CmiDevGetNBRelFeatureCnf;

/******************************************************************************
 * CMI_DEV_GET_PSSLP_CFG_REQ
 * AT$QCPSSLPCFG?
 *  $QCPSSLPCFG="minT3324", value, "minT3412", value, "minEDRXPeriod", value
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetPsSleepCfgReq;

typedef struct CmiDevGetPsSleepCfgCnf_Tag
{
    UINT16  minT3324;
    UINT16  minEdrxPeriod;
    UINT32  minT3412;
}CmiDevGetPsSleepCfgCnf;


/******************************************************************************
 * CMI_DEV_SET_PSSLP_CFG_REQ
 * AT$QCPSSLPCFG="minT3324",<T1>,"minT3412",<T2>,"minEDRXPeriod",<T3>
******************************************************************************/
typedef struct CmiDevSetPsSleepCfgReq_Tag
{
    BOOL    t3324Present;
    BOOL    edrxPresent;
    BOOL    t3412Present;
    UINT8   rsvd;
    UINT16  minT3324ValueS;
    UINT16  minEdrxPeriodS;
    UINT32  minT3412ValueS;
}CmiDevSetPsSleepCfgReq;

/******************************************************************************
 * CMI_DEV_GET_PLMN_LOCK_LIST_REQ
 * AT$QCPLMNLOCK
 * QCPLMNLOCK:<number of plmns>[PLMN list <PLMN1>,<PLMN2>]
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetPlmnLockListReq;

/******************************************************************************
 * CMI_DEV_GET_PLMN_LOCK_LIST_CNF
 * AT$QCPLMNLOCK
 * QCPLMNLOCK:<number of plmns>[PLMN list <PLMN1>,<PLMN2>]
******************************************************************************/
#define MAX_TABLE_LEN 30

typedef struct CmiDevGetPlmnLockListCnf_Tag
{
    UINT8 listLen;
    CmiNumericPlmn plmnList[MAX_TABLE_LEN];
}CmiDevGetPlmnLockListCnf;


/******************************************************************************
 * CMI_DEV_UPDATE_PLMN_LOCK_LIST_REQ
 * AT$QCPLMNLOCK=<add>, <mcc>, <mnc>
 * AT$QCPLMNLOCK=<delete>, <mcc>, <mnc>
******************************************************************************/
typedef struct CmiDevSetPlmnLockListCnf_Tag
{
    UINT8   ret; //CmiFuncValueEnum
    UINT8   reserved0;
    UINT16  reserved1;
}CmiDevSetPlmnLockListCnf;

/******************************************************************************
 * CMI_DEV_UPDATE_PLMN_LOCK_LIST_REQ
 * AT$QCPLMNLOCK=<add>, <mcc>, <mnc>
 * AT$QCPLMNLOCK=<delete>, <mcc>, <mnc>
******************************************************************************/
typedef struct CmiDevSetPlmnLockListReq_Tag
{
    UINT8 operation; // 0: Delete, 1: Add
    CmiNumericPlmn uPlmn; 
}CmiDevSetPlmnLockListReq;

typedef CacCmiEmptySig CmiDevUpdatePlmnLockListCnf;

typedef CacCmiEmptySig CmiDevSetPsSleepCfgCnf;

typedef CacCmiEmptySig CmiDevGetEmmStateReq;


typedef CacCmiEmptySig CmiDevGetDrxReq;

typedef struct CmiDevGetdrxParmCnf_Tag
{

    UINT32       drxcycle;

    UINT8        mode; // 0-RRC IDLE, 1- RRC CONNECTED

    UINT8        onDurationTimer; //DrxOnDurationTimerNB

//Timer for DRX in TS 36.321 [6]. Value in number of PDCCH periods.
//Value range:{0,1,2,3,4,8,16,32}
    UINT8       drxInactivityTimer; //DrxInactivityTimerNB
//Timer for DRX in TS 36.321 [6]. Value in number of PDCCH periods.
    UINT8       drxRetransmissionTimer; //DrxRetransmissionTimerNB
//longDRX-Cycle in TS 36.321 [6]. The value of longDRX-Cycle is in number of sub-frames.
    UINT8       longdrxCycle;   //DrxCycle
//drxStartOffset in TS 36.321 [6]. Value is in number of sub-frames by step of (drx-cycle / 256).
//Value range:{0~255}
    UINT8       drxStartOffset;
//Timer for DRX in TS 36.321 [6]. Value in number of PDCCH periods.
    UINT8       drxULRetransmissionTimer;   //DrxULRetransmissionTimerNB
}CmiDevGetdrxParmCnf;

typedef CacCmiEmptySig CmiDevSetLapiCnfSig;

typedef struct CmiDevSetLapiReq_Tag
{
    UINT8 LAPI;
}CmiDevSetLapiReq;


typedef CacCmiEmptySig CmiDevGetLapiReq;

typedef struct CmiDevGetLapiCnf_Tag
{
    UINT8 lapi;
}CmiDevGetLapiCnf;

typedef struct CmiDevSetRoamingDataReq_Tag
{
    BOOL RoamData;
}CmiDevSetRoamingDataReq;

typedef CacCmiEmptySig CmiDevSetRoamingDataCnf;

typedef CacCmiEmptySig CmiDevGetRoamingDataReq;

typedef struct CmiDevGetRoamingDataCnf_Tag
{
    BOOL RoamData;
}CmiDevGetRoamingDataCnf;

/******************************************************************************
 * CMI_DEV_GET_PLMN_LIST_REQ
******************************************************************************/
typedef CacCmiEmptySig CmiDevGetPlmnListReq;

/******************************************************************************
 * CMI_DEV_GET_PLMN_LIST_CNF
******************************************************************************/
#define MAX_TABLE_LEN 30

typedef struct CmiDevGetPlmnListCnf_Tag
{
	UINT8 listLen;
	CmiNumericPlmn plmnList[MAX_TABLE_LEN];
}CmiDevGetPlmnListCnf;


/******************************************************************************
 * CMI_DEV_SET_PLMN_LIST_REQ
******************************************************************************/
typedef struct CmiDevSetPlmnListCnf_Tag
{
    UINT8   ret; //CmiFuncValueEnum
    UINT8   reserved0;
    UINT16  reserved1;
}CmiDevSetPlmnListCnf;


typedef struct CmiDevSetPlmnListReq_Tag
{
	UINT8 operation; // 0: Delete, 1: Add
	CmiNumericPlmn uPlmn; 
}CmiDevSetPlmnListReq;

typedef CacCmiEmptySig CmiDevSetUpdatePlmnListCnf;

/******************************************************************************
 * CMI_DEV_SET_RPM_PARAM_INFO_REQ
******************************************************************************/
typedef struct CmiDevSetRpmParamReq_Tag
{
	/* RPM functionality enabled or disabled at power up */
    BOOL                 rpmFlagPresent;
    BOOL                 rpmFlag;

    /* Max no of SW resets per Hour allowed by RPM following permanent EMM reject */
	BOOL                 N1Present;
    UINT8                N1;

    /* Average time before RPM resets modem following permanent EMM reject */
	BOOL                 T1Present;
    UINT8                T1;

	/* Average time before RPM resets modem following permanent EMM reject if T1 = 0xFF */
	BOOL                 T1_extPresent;
    UINT8                T1_ext;
	
	/* Max number of PDN Connectivity Requests per Hour allowed by RPM following PDP Activation Ignore Scenario */
	BOOL                 F1Present;
    UINT8                F1;

    /* Max number of PDN Connectivity Requests per Hour allowed by RPM following Permanent PDP Activation Reject */
	BOOL                 F2Present;
    UINT8                F2;

	/* Max number of PDN Connectivity Requests per Hour allowed by RPM following Temporary PDP Activation Reject */
	BOOL                 F3Present;
    UINT8                F3;

    /* Max number of PDN Connectivity Activation/ Deactivation Requests per Hour allowed by RPM */
	BOOL                 F4Present;
    UINT8                F4;
	
	
}CmiDevSetRpmParamReq;

/******************************************************************************
 * CMI_DEV_SET_RPM_PARAM_INFO_CNF
******************************************************************************/
typedef CacCmiEmptySig CmiDevSetRpmParamCnf;

#define CMI_DEV_MAX_SACN_FREQ_RPT_NUM    24

typedef enum CmiDevDetectEventType_Enum
{
    CMI_DEV_DETECT_EVENT_TYPE_RSSI_SACN  = 0,
    CMI_DEV_DETECT_EVENT_TYPE_SYS_INFO_DEC_FAIL = 1
}CmiDevDetectEventType;

typedef struct CmiDevScanFreqList_Tag
{
    UINT32      carrierFreq;    // euArfcn is bit[23:0], [31:24] reprsents carrierFreqOffset
    UINT8       freqScore;      // range in 0 ~ 255
    UINT8       rsvd[3];
}CmiDevScanFreqList;

typedef struct CmiDevRssiScanInfo_Tag
{
    UINT8               freqNum;
    UINT8               rsvd[3];
    CmiDevScanFreqList  freqList[CMI_DEV_MAX_SACN_FREQ_RPT_NUM];
}CmiDevRssiScanInfo;

typedef enum CmiDevSysInfoType_Enum
{
    CMI_DEV_SYS_INFO_TYPE_MIB  = 0,
    CMI_DEV_SYS_INFO_TYPE_SIB  = 1,
}CmiDevSysInfoType;

typedef struct CmiDevSysInfoDecFailInfo_Tag
{
    UINT32      carrierFreq;    // euArfcn is bit[23:0], [31:24] reprsents carrierFreqOffset
    UINT8       sysInfoType;    // CmiDevSysInfoType
    UINT16      phyCellId;
    UINT8       rsvd;
}CmiDevSysInfoDecFailInfo;

typedef struct CmiDevDetectEventInd_Tag
{
    UINT8   detectEventType;   /* CmiDevDetectEventType */
    UINT8   rsvd1[3];

    union {
        CmiDevRssiScanInfo          rssiSacnInfo;
        CmiDevSysInfoDecFailInfo    sysInfoDecFail;
    }event;
}CmiDevDetectEventInd;


#endif


