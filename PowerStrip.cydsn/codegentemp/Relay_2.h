/*******************************************************************************
* File Name: Relay_2.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Relay_2_H) /* Pins Relay_2_H */
#define CY_PINS_Relay_2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Relay_2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Relay_2_Write(uint8 value) ;
void    Relay_2_SetDriveMode(uint8 mode) ;
uint8   Relay_2_ReadDataReg(void) ;
uint8   Relay_2_Read(void) ;
uint8   Relay_2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Relay_2_DRIVE_MODE_BITS        (3)
#define Relay_2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Relay_2_DRIVE_MODE_BITS))

#define Relay_2_DM_ALG_HIZ         (0x00u)
#define Relay_2_DM_DIG_HIZ         (0x01u)
#define Relay_2_DM_RES_UP          (0x02u)
#define Relay_2_DM_RES_DWN         (0x03u)
#define Relay_2_DM_OD_LO           (0x04u)
#define Relay_2_DM_OD_HI           (0x05u)
#define Relay_2_DM_STRONG          (0x06u)
#define Relay_2_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Relay_2_MASK               Relay_2__MASK
#define Relay_2_SHIFT              Relay_2__SHIFT
#define Relay_2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Relay_2_PS                     (* (reg32 *) Relay_2__PS)
/* Port Configuration */
#define Relay_2_PC                     (* (reg32 *) Relay_2__PC)
/* Data Register */
#define Relay_2_DR                     (* (reg32 *) Relay_2__DR)
/* Input Buffer Disable Override */
#define Relay_2_INP_DIS                (* (reg32 *) Relay_2__PC2)


#if defined(Relay_2__INTSTAT)  /* Interrupt Registers */

    #define Relay_2_INTSTAT                (* (reg32 *) Relay_2__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Relay_2_DRIVE_MODE_SHIFT       (0x00u)
#define Relay_2_DRIVE_MODE_MASK        (0x07u << Relay_2_DRIVE_MODE_SHIFT)


#endif /* End Pins Relay_2_H */


/* [] END OF FILE */
