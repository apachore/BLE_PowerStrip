/*******************************************************************************
* File Name: ConnLed.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ConnLed_ALIASES_H) /* Pins ConnLed_ALIASES_H */
#define CY_PINS_ConnLed_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ConnLed_0			(ConnLed__0__PC)
#define ConnLed_0_PS		(ConnLed__0__PS)
#define ConnLed_0_PC		(ConnLed__0__PC)
#define ConnLed_0_DR		(ConnLed__0__DR)
#define ConnLed_0_SHIFT	(ConnLed__0__SHIFT)
#define ConnLed_0_INTR	((uint16)((uint16)0x0003u << (ConnLed__0__SHIFT*2u)))

#define ConnLed_INTR_ALL	 ((uint16)(ConnLed_0_INTR))


#endif /* End Pins ConnLed_ALIASES_H */


/* [] END OF FILE */
