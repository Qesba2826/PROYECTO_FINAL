/*******************************************************************************
* File Name: SIN_3.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SIN_3_H) /* Pins SIN_3_H */
#define CY_PINS_SIN_3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SIN_3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SIN_3__PORT == 15 && ((SIN_3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SIN_3_Write(uint8 value);
void    SIN_3_SetDriveMode(uint8 mode);
uint8   SIN_3_ReadDataReg(void);
uint8   SIN_3_Read(void);
void    SIN_3_SetInterruptMode(uint16 position, uint16 mode);
uint8   SIN_3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SIN_3_SetDriveMode() function.
     *  @{
     */
        #define SIN_3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SIN_3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SIN_3_DM_RES_UP          PIN_DM_RES_UP
        #define SIN_3_DM_RES_DWN         PIN_DM_RES_DWN
        #define SIN_3_DM_OD_LO           PIN_DM_OD_LO
        #define SIN_3_DM_OD_HI           PIN_DM_OD_HI
        #define SIN_3_DM_STRONG          PIN_DM_STRONG
        #define SIN_3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SIN_3_MASK               SIN_3__MASK
#define SIN_3_SHIFT              SIN_3__SHIFT
#define SIN_3_WIDTH              1u

/* Interrupt constants */
#if defined(SIN_3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SIN_3_SetInterruptMode() function.
     *  @{
     */
        #define SIN_3_INTR_NONE      (uint16)(0x0000u)
        #define SIN_3_INTR_RISING    (uint16)(0x0001u)
        #define SIN_3_INTR_FALLING   (uint16)(0x0002u)
        #define SIN_3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SIN_3_INTR_MASK      (0x01u) 
#endif /* (SIN_3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SIN_3_PS                     (* (reg8 *) SIN_3__PS)
/* Data Register */
#define SIN_3_DR                     (* (reg8 *) SIN_3__DR)
/* Port Number */
#define SIN_3_PRT_NUM                (* (reg8 *) SIN_3__PRT) 
/* Connect to Analog Globals */                                                  
#define SIN_3_AG                     (* (reg8 *) SIN_3__AG)                       
/* Analog MUX bux enable */
#define SIN_3_AMUX                   (* (reg8 *) SIN_3__AMUX) 
/* Bidirectional Enable */                                                        
#define SIN_3_BIE                    (* (reg8 *) SIN_3__BIE)
/* Bit-mask for Aliased Register Access */
#define SIN_3_BIT_MASK               (* (reg8 *) SIN_3__BIT_MASK)
/* Bypass Enable */
#define SIN_3_BYP                    (* (reg8 *) SIN_3__BYP)
/* Port wide control signals */                                                   
#define SIN_3_CTL                    (* (reg8 *) SIN_3__CTL)
/* Drive Modes */
#define SIN_3_DM0                    (* (reg8 *) SIN_3__DM0) 
#define SIN_3_DM1                    (* (reg8 *) SIN_3__DM1)
#define SIN_3_DM2                    (* (reg8 *) SIN_3__DM2) 
/* Input Buffer Disable Override */
#define SIN_3_INP_DIS                (* (reg8 *) SIN_3__INP_DIS)
/* LCD Common or Segment Drive */
#define SIN_3_LCD_COM_SEG            (* (reg8 *) SIN_3__LCD_COM_SEG)
/* Enable Segment LCD */
#define SIN_3_LCD_EN                 (* (reg8 *) SIN_3__LCD_EN)
/* Slew Rate Control */
#define SIN_3_SLW                    (* (reg8 *) SIN_3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SIN_3_PRTDSI__CAPS_SEL       (* (reg8 *) SIN_3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SIN_3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SIN_3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SIN_3_PRTDSI__OE_SEL0        (* (reg8 *) SIN_3__PRTDSI__OE_SEL0) 
#define SIN_3_PRTDSI__OE_SEL1        (* (reg8 *) SIN_3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SIN_3_PRTDSI__OUT_SEL0       (* (reg8 *) SIN_3__PRTDSI__OUT_SEL0) 
#define SIN_3_PRTDSI__OUT_SEL1       (* (reg8 *) SIN_3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SIN_3_PRTDSI__SYNC_OUT       (* (reg8 *) SIN_3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SIN_3__SIO_CFG)
    #define SIN_3_SIO_HYST_EN        (* (reg8 *) SIN_3__SIO_HYST_EN)
    #define SIN_3_SIO_REG_HIFREQ     (* (reg8 *) SIN_3__SIO_REG_HIFREQ)
    #define SIN_3_SIO_CFG            (* (reg8 *) SIN_3__SIO_CFG)
    #define SIN_3_SIO_DIFF           (* (reg8 *) SIN_3__SIO_DIFF)
#endif /* (SIN_3__SIO_CFG) */

/* Interrupt Registers */
#if defined(SIN_3__INTSTAT)
    #define SIN_3_INTSTAT            (* (reg8 *) SIN_3__INTSTAT)
    #define SIN_3_SNAP               (* (reg8 *) SIN_3__SNAP)
    
	#define SIN_3_0_INTTYPE_REG 		(* (reg8 *) SIN_3__0__INTTYPE)
#endif /* (SIN_3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SIN_3_H */


/* [] END OF FILE */
