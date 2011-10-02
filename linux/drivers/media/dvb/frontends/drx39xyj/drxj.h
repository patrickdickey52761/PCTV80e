/*
  Copyright (c), 2004-2005,2007-2010 Trident Microsystems, Inc.
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
	and/or other materials provided with the distribution.
  * Neither the name of Trident Microsystems nor Hauppauge Computer Works
    nor the names of its contributors may be used to endorse or promote
	products derived from this software without specific prior written
	permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.
*/  
    
/**
* \file $Id: drxj.h,v 1.132 2009/12/22 12:13:48 danielg Exp $
*
* \brief DRXJ specific header file
*
* \author Dragan Savic, Milos Nikolic, Mihajlo Katona, Tao Ding, Paul Janssen
*/ 
    
#ifndef __DRXJ_H__
#define __DRXJ_H__
/*-------------------------------------------------------------------------
INCLUDES
-------------------------------------------------------------------------*/ 
    
#include "drx_driver.h"
#include "drx_dap_fasi.h"
    
#ifdef __cplusplus
extern "C" {
	
#endif				/* 
	
/* Check DRX-J specific dap condition */ 
/* Multi master mode and short addr format only will not work.
   RMW, CRC reset, broadcast and switching back to single master mode
   cannot be done with short addr only in multi master mode. */ 
#if ((DRXDAP_SINGLE_MASTER==0)&&(DRXDAPFASI_LONG_ADDR_ALLOWED==0))
#error "Multi master mode and short addressing only is an illegal combination"
	*;			/* Generate a fatal compiler error to make sure it stops here,
				   this is necesarry because not all compilers stop after a #error. */
	
#endif				/* 
	
/*-------------------------------------------------------------------------
TYPEDEFS
-------------------------------------------------------------------------*/ 
/*============================================================================*/ 
/*============================================================================*/ 
/*== code support ============================================================*/ 
/*============================================================================*/ 
/*============================================================================*/ 
	
/*============================================================================*/ 
/*============================================================================*/ 
/*== SCU cmd if  =============================================================*/ 
/*============================================================================*/ 
/*============================================================================*/ 
	
		
			     /**< Command number */
		
			     /**< Data length in byte */
		
			     /**< result length in byte */
		
			     /**< General purpous param */
		
			     /**< General purpous param */
	
	
/*============================================================================*/ 
/*============================================================================*/ 
/*== CTRL CFG related data structures ========================================*/ 
/*============================================================================*/ 
/*============================================================================*/ 
	
/* extra intermediate lock state for VSB,QAM,NTSC */ 
#define DRXJ_DEMOD_LOCK       (DRX_LOCK_STATE_1)
	
/* OOB lock states */ 
#define DRXJ_OOB_AGC_LOCK     (DRX_LOCK_STATE_1)   /* analog gain control lock */
#define DRXJ_OOB_SYNC_LOCK    (DRX_LOCK_STATE_2)   /* digital gain control lock */
	
/* Intermediate powermodes for DRXJ */ 
#define DRXJ_POWER_DOWN_MAIN_PATH   DRX_POWER_MODE_8
#define DRXJ_POWER_DOWN_CORE        DRX_POWER_MODE_9
#define DRXJ_POWER_DOWN_PLL         DRX_POWER_MODE_10
	
/* supstition for GPIO FNC mux */ 
#define APP_O                 (0x0000)
	
/*#define DRX_CTRL_BASE         (0x0000)*/ 
	
#define DRXJ_CTRL_CFG_BASE    (0x1000)
	    typedef enum { 
		    DRXJ_CTRL_CFG_BASE, 
		
		
		
		
		
		
		    /* ATV (FM) */ 
		    DRXJ_CFG_ATV_OUTPUT, /* also for FM (SIF control) but not likely */ 
		    DRXJ_CFG_ATV_MISC, 
		
		/* also for FM (IF,RF, audioAGC) */ 
		    
		
		
		
	} DRXJCfgType_t, *pDRXJCfgType_t;
	
/**
* /struct DRXJCfgSmartAntIO_t
* smart antenna i/o.
*/ 
	typedef enum DRXJCfgSmartAntIO_t { 
		    0, 
	} DRXJCfgSmartAntIO_t, *pDRXJCfgSmartAntIO_t;
	
/**
* /struct DRXJCfgSmartAnt_t
* Set smart antenna.
*/ 
	    typedef struct {
		
		
	
	
/**
* /struct DRXJAGCSTATUS_t
* AGC status information from the DRXJ-IQM-AF.
*/ 
	    typedef struct {
		
		
		
	
	
/* DRXJ_CFG_AGC_RF, DRXJ_CFG_AGC_IF */ 
	
/**
* /struct DRXJAgcCtrlMode_t
* Available AGCs modes in the DRXJ.
*/ 
	typedef enum { 
		    0, 
	} DRXJAgcCtrlMode_t, *pDRXJAgcCtrlMode_t;
	
/**
* /struct DRXJCfgAgc_t
* Generic interface for all AGCs present on the DRXJ.
*/ 
	    typedef struct {
		
						   apply */
		
		
		
		
		
		
		
					   current
					   is below cut-off current                */
	
	
/* DRXJ_CFG_PRE_SAW */ 
	
/**
* /struct DRXJCfgPreSaw_t
* Interface to configure pre SAW sense.
*/ 
	    typedef struct {
		
						   these settings apply */
		
					   value, range 0 .. 31 */
		
					   pre SAW sense */
	
	
/* DRXJ_CFG_AFE_GAIN */ 
	
/**
* /struct DRXJCfgAfeGain_t
* Interface to configure gain of AFE (LNA + PGA).
*/ 
	    typedef struct {
		
						   settings apply */
		
				   DRXJ range 140 .. 335 */
	
	
/**
* /struct DRXJRSErrors_t
* Available failure information in DRXJ_FEC_RS.
*
* Container for errors that are received in the most recently finished
* measurment period
*
*/ 
	    typedef struct {
		
		
				     /**< no of pre RS symbol errors       */
		
				     /**< no of pre RS packet errors       */
		
		
				     /**< no of post RS bit erros          */
	
	
/**
* /struct DRXJCfgVSBMisc_t
* symbol error rate
*/ 
	    typedef struct {
		
	
	
/**
* /enum DRXJMpegOutputClockRate_t
* Mpeg output clock rate.
*
*/ 
	    typedef enum { 
		
	} DRXJMpegStartWidth_t, *pDRXJMpegStartWidth_t;
	
/**
* /enum DRXJMpegOutputClockRate_t
* Mpeg output clock rate.
*
*/ 
	    typedef enum { 
		
		
		
		
		
		
	} DRXJMpegOutputClockRate_t, *pDRXJMpegOutputClockRate_t;
	
/**
* /struct DRXJCfgMisc_t
* Change TEI bit of MPEG output
* reverse MPEG output bit order
* set MPEG output clock rate
*/ 
	    typedef struct {
		
							(not change) TEI bit */
		
							msb on MD0; serial:
								 lsb out first */
		
							   /**< set MPEG output
							 clock rate that
							 overwrites the
							 derived one from
							 symbol rate */
		
							 start width */
	
	
/**
* /enum DRXJXtalFreq_t
* Supported external crystal reference frequency.
*/ 
	    typedef enum { 
		
	} DRXJXtalFreq_t, *pDRXJXtalFreq_t;
	
/**
* /enum DRXJXtalFreq_t
* Supported external crystal reference frequency.
*/ 
	typedef enum { 
	} DRXJI2CSpeed_t, *pDRXJI2CSpeed_t;
	
/**
* /struct DRXJCfgHwCfg_t
* Get hw configuration, such as crystal reference frequency, I2C speed, etc...
*/ 
	    typedef struct {
		
					/**< crystal reference frequency */
		
					/**< 100 or 400 kbps */
	
	
/*
 *  DRXJ_CFG_ATV_MISC
 */ 
	    typedef struct {
		
		
	
	
/*
 *  DRXJCfgOOBMisc_t
 */ 
#define   DRXJ_OOB_STATE_RESET                                        0x0
#define   DRXJ_OOB_STATE_AGN_HUNT                                     0x1
#define   DRXJ_OOB_STATE_DGN_HUNT                                     0x2
#define   DRXJ_OOB_STATE_AGC_HUNT                                     0x3
#define   DRXJ_OOB_STATE_FRQ_HUNT                                     0x4
#define   DRXJ_OOB_STATE_PHA_HUNT                                     0x8
#define   DRXJ_OOB_STATE_TIM_HUNT                                     0x10
#define   DRXJ_OOB_STATE_EQU_HUNT                                     0x20
#define   DRXJ_OOB_STATE_EQT_HUNT                                     0x30
#define   DRXJ_OOB_STATE_SYNC                                         0x40
	
		
		
		
		
		
		
		
		
	
	
/*
 *  Index of in array of coef
 */ 
	    typedef enum { 
		    0, 
		
		
	} DRXJCfgOobLoPower_t, *pDRXJCfgOobLoPower_t;
	
/*
 *  DRXJ_CFG_ATV_EQU_COEF
 */ 
	    typedef struct {
		
		
		
		
	
	
/*
 *  Index of in array of coef
 */ 
	    typedef enum { 
		    0, 
		
		
	} DRXJCoefArrayIndex_t, *pDRXJCoefArrayIndex_t;
	
/*
 *  DRXJ_CFG_ATV_OUTPUT
 */ 
	
/**
* /enum DRXJAttenuation_t
* Attenuation setting for SIF AGC.
*
*/ 
	    typedef enum { 
		
	} DRXJSIFAttenuation_t, *pDRXJSIFAttenuation_t;
	
/**
* /struct DRXJCfgAtvOutput_t
* SIF attenuation setting.
*
*/ 
	    typedef struct {
		
		
		
	
	
/*
   DRXJ_CFG_ATV_AGC_STATUS (get only)
*/ 
/* TODO : AFE interface not yet finished, subject to change */ 
	    typedef struct {
		
		
		
		
		
		
		
	
	
/*============================================================================*/ 
/*============================================================================*/ 
/*== CTRL related data structures ============================================*/ 
/*============================================================================*/ 
/*============================================================================*/ 
	
/* NONE */ 
	
/*============================================================================*/ 
/*============================================================================*/ 
	
/*========================================*/ 
/**
* /struct DRXJData_t
* DRXJ specific attributes.
*
* Global data container for DRXJ specific data.
*
*/ 
	    typedef struct {
		
		    /* device capabilties (determined during DRX_Open()) */ 
		Bool_t hasLNA;		       /**< TRUE if LNA (aka PGA) present */
		
		
		
		
		
		
		
		
		    /* A1/A2/A... */ 
		u8_t mfx;		       /**< metal fix */
		
		    /* tuner settings */ 
		Bool_t mirrorFreqSpectOOB;     /**< tuner inversion (TRUE = tuner mirrors the signal */
		
		    /* standard/channel settings */ 
		DRXStandard_t standard;	       /**< current standard information                     */
		
					       /**< current constellation                            */
		
		
		
		
		    /* signal quality information */ 
		u32_t fecBitsDesired;	       /**< BER accounting period                            */
		
		
		
		
		
		
		
		
		
		    /* HI configuration */ 
		u16_t HICfgTimingDiv;	       /**< HI Configure() parameter 2                       */
		
		
		
		
		
		    /* UIO configuartion */ 
		DRXUIOMode_t uioSmaRxMode;     /**< current mode of SmaRx pin                        */
		
		
		
		
		    /* IQM fs frequecy shift and inversion */ 
		u32_t iqmFsRateOfs;		/**< frequency shifter setting after setchannel      */
		
		
		    /* IQM RC frequecy shift */ 
		u32_t iqmRcRateOfs;		/**< frequency shifter setting after setchannel      */
		
		    /* ATV configuartion */ 
		u32_t atvCfgChangedFlags;      /**< flag: flags cfg changes */
		
		
		
		
		
		
		
		
		
		
					    /**< current SIF att setting */
		
		    /* Agc configuration for QAM and VSB */ 
		DRXJCfgAgc_t qamRfAgcCfg;      /**< qam RF AGC config */
		
		
		
		
		    /* PGA gain configuration for QAM and VSB */ 
		u16_t qamPgaCfg;	       /**< qam PGA config */
		
		
		    /* Pre SAW configuration for QAM and VSB */ 
		DRXJCfgPreSaw_t qamPreSawCfg;  /**< qam pre SAW config */
		
		
		    /* Version information */ 
		char vText[2][12];	       /**< allocated text versions */
		
		
					       /**< allocated version list */
		
		    /* smart antenna configuration */ 
		 Bool_t smartAntInverted;
		
		    /* Tracking filter setting for OOB */ 
		 u16_t oobTrkFilterCfg[8];
		
		
		    /* MPEG static bitrate setting */ 
		 u32_t mpegTsStaticBitrate;	 /**< bitrate static MPEG output */
		
		
		
					      /**< MPEG output clock rate */
		
					      /**< MPEG Start width */
		
		    /* Pre SAW & Agc configuration for ATV */ 
		 DRXJCfgPreSaw_t atvPreSawCfg; /**< atv pre SAW config */
		
		
		
		
		
		    /* pin-safe mode */ 
		 Bool_t pdrSafeMode;		 /**< PDR safe mode activated      */
		
		
		
		
		
		    /* OOB pre-saw value */ 
		 u16_t oobPreSaw;
		
		
	
	
/*-------------------------------------------------------------------------
Access MACROS
-------------------------------------------------------------------------*/ 
/**
* \brief Compilable references to attributes
* \param d pointer to demod instance
*
* Used as main reference to an attribute field.
* Can be used by both macro implementation and function implementation.
* These macros are defined to avoid duplication of code in macro and function
* definitions that handle access of demod common or extended attributes.
*
*/ 
	
#define DRXJ_ATTR_BTSC_DETECT(d)                       \
	 (((pDRXJData_t) (d)->myExtAttr)->audData.btscDetect) 
/**
* \brief Actual access macros
* \param d pointer to demod instance
* \param x value to set or to get
*
* SET macros must be used to set the value of an attribute.
* GET macros must be used to retrieve the value of an attribute.
* Depending on the value of DRX_USE_ACCESS_FUNCTIONS the macro's will be
* substituted by "direct-access-inline-code" or a function call.
*
*/ 
#define DRXJ_GET_BTSC_DETECT(d, x)                     \
	    do {
	\
#define DRXJ_SET_BTSC_DETECT(d, x)                     \
				      do {
				      \
				      \
/*-------------------------------------------------------------------------
DEFINES
-------------------------------------------------------------------------*/ 
				      
/**
* \def DRXJ_NTSC_CARRIER_FREQ_OFFSET
* \brief Offset from picture carrier to centre frequency in kHz, in RF domain
*
* For NTSC standard.
* NTSC channels are listed by their picture carrier frequency (Fpc).
* The function DRX_CTRL_SET_CHANNEL requires the centre frequency as input.
* In case the tuner module is not used the DRX-J requires that the tuner is
* tuned to the centre frequency of the channel:
*
* Fcentre = Fpc + DRXJ_NTSC_CARRIER_FREQ_OFFSET
*
*/ 
#define DRXJ_NTSC_CARRIER_FREQ_OFFSET           ((DRXFrequency_t)(1750))
				      
/**
* \def DRXJ_PAL_SECAM_BG_CARRIER_FREQ_OFFSET
* \brief Offset from picture carrier to centre frequency in kHz, in RF domain
*
* For PAL/SECAM - BG standard. This define is needed in case the tuner module
* is NOT used. PAL/SECAM channels are listed by their picture carrier frequency
* (Fpc).
* The DRX-J requires that the tuner is tuned to:
* Fpc + DRXJ_PAL_SECAM_BG_CARRIER_FREQ_OFFSET
*
* In case the tuner module is used the drxdriver takes care of this.
* In case the tuner module is NOT used the application programmer must take
* care of this.
*
*/ 
#define DRXJ_PAL_SECAM_BG_CARRIER_FREQ_OFFSET   ((DRXFrequency_t)(2375))
				      
/**
* \def DRXJ_PAL_SECAM_DKIL_CARRIER_FREQ_OFFSET
* \brief Offset from picture carrier to centre frequency in kHz, in RF domain
*
* For PAL/SECAM - DK, I, L standards. This define is needed in case the tuner
* module
* is NOT used. PAL/SECAM channels are listed by their picture carrier frequency
* (Fpc).
* The DRX-J requires that the tuner is tuned to:
* Fpc + DRXJ_PAL_SECAM_DKIL_CARRIER_FREQ_OFFSET
*
* In case the tuner module is used the drxdriver takes care of this.
* In case the tuner module is NOT used the application programmer must take
* care of this.
*
*/ 
#define DRXJ_PAL_SECAM_DKIL_CARRIER_FREQ_OFFSET ((DRXFrequency_t)(2775))
				      
/**
* \def DRXJ_PAL_SECAM_LP_CARRIER_FREQ_OFFSET
* \brief Offset from picture carrier to centre frequency in kHz, in RF domain
*
* For PAL/SECAM - LP standard. This define is needed in case the tuner module
* is NOT used. PAL/SECAM channels are listed by their picture carrier frequency
* (Fpc).
* The DRX-J requires that the tuner is tuned to:
* Fpc + DRXJ_PAL_SECAM_LP_CARRIER_FREQ_OFFSET
*
* In case the tuner module is used the drxdriver takes care of this.
* In case the tuner module is NOT used the application programmer must take
* care of this.
*/ 
#define DRXJ_PAL_SECAM_LP_CARRIER_FREQ_OFFSET   ((DRXFrequency_t)(-3255))
				      
/**
* \def DRXJ_FM_CARRIER_FREQ_OFFSET
* \brief Offset from sound carrier to centre frequency in kHz, in RF domain
*
* For FM standard.
* FM channels are listed by their sound carrier frequency (Fsc).
* The function DRX_CTRL_SET_CHANNEL requires the Ffm frequency (see below) as
* input.
* In case the tuner module is not used the DRX-J requires that the tuner is
* tuned to the Ffm frequency of the channel.
*
* Ffm = Fsc + DRXJ_FM_CARRIER_FREQ_OFFSET
*
*/ 
#define DRXJ_FM_CARRIER_FREQ_OFFSET             ((DRXFrequency_t)(-3000))
				      
/* Revision types -------------------------------------------------------*/ 
				      
#define DRXJ_TYPE_ID (0x3946000DUL)
				      
/* Macros ---------------------------------------------------------------*/ 
				      
/* Convert OOB lock status to string */ 
#define DRXJ_STR_OOB_LOCKSTATUS(x) (\
				      (x ==
				       DRX_NEVER_LOCK) ? "Never" : \
								      ==
								      DRX_NOT_LOCKED)
				      ? "No" : \
						  DRX_LOCKED) ? "Locked"
				      : \
					   DRX_LOCK_STATE_1) ?
				      "AGC lock" : \
				      ? "sync lock" : \
	
/*-------------------------------------------------------------------------
ENUM
-------------------------------------------------------------------------*/ 
	    
/*-------------------------------------------------------------------------
STRUCTS
-------------------------------------------------------------------------*/ 
	    
/*-------------------------------------------------------------------------
Exported FUNCTIONS
-------------------------------------------------------------------------*/ 
	
	
	
				      
	
/*-------------------------------------------------------------------------
Exported GLOBAL VARIABLES
-------------------------------------------------------------------------*/ 
	extern DRXAccessFunc_t drxDapDRXJFunct_g;
	
	
	
	
	
	
/*-------------------------------------------------------------------------
THE END
-------------------------------------------------------------------------*/ 
#ifdef __cplusplus
	} 
#endif				/* 
#endif	/* __DRXJ_H__ */