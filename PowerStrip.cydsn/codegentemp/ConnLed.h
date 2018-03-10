/*******************************************************************************
* File Name: ConnLed.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ConnLed_H) /* Pins ConnLed_H */
#define CY_PINS_ConnLed_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ConnLed_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} ConnLed_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   ConnLed_Read(void);
void    ConnLed_Write(uint8 value);
uint8   ConnLed_ReadDataReg(void);
#if defined(ConnLed__PC) || (CY_PSOC4_4200L) 
    void    ConnLed_SetDriveMode(uint8 mode);
#endif
void    ConnLed_SetInterruptMode(uint16 position, uint16 mode);
uint8   ConnLed_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void ConnLed_Sleep(void); 
void ConnLed_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(ConnLed__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define ConnLed_DRIVE_MODE_BITS        (3)
    #define ConnLed_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ConnLed_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the ConnLed_SetDriveMode() function.
         *  @{
         */
        #define ConnLed_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define ConnLed_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define ConnLed_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define ConnLed_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define ConnLed_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define ConnLed_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define ConnLed_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define ConnLed_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define ConnLed_MASK               ConnLed__MASK
#define ConnLed_SHIFT              ConnLed__SHIFT
#define ConnLed_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ConnLed_SetInterruptMode() function.
     *  @{
     */
        #define ConnLed_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define ConnLed_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define ConnLed_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define ConnLed_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(ConnLed__SIO)
    #define ConnLed_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(ConnLed__PC) && (CY_PSOC4_4200L)
    #define ConnLed_USBIO_ENABLE               ((uint32)0x80000000u)
    #define ConnLed_USBIO_DISABLE              ((uint32)(~ConnLed_USBIO_ENABLE))
    #define ConnLed_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define ConnLed_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define ConnLed_USBIO_ENTER_SLEEP          ((uint32)((1u << ConnLed_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << ConnLed_USBIO_SUSPEND_DEL_SHIFT)))
    #define ConnLed_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << ConnLed_USBIO_SUSPEND_SHIFT)))
    #define ConnLed_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << ConnLed_USBIO_SUSPEND_DEL_SHIFT)))
    #define ConnLed_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(ConnLed__PC)
    /* Port Configuration */
    #define ConnLed_PC                 (* (reg32 *) ConnLed__PC)
#endif
/* Pin State */
#define ConnLed_PS                     (* (reg32 *) ConnLed__PS)
/* Data Register */
#define ConnLed_DR                     (* (reg32 *) ConnLed__DR)
/* Input Buffer Disable Override */
#define ConnLed_INP_DIS                (* (reg32 *) ConnLed__PC2)

/* Interrupt configuration Registers */
#define ConnLed_INTCFG                 (* (reg32 *) ConnLed__INTCFG)
#define ConnLed_INTSTAT                (* (reg32 *) ConnLed__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define ConnLed_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(ConnLed__SIO)
    #define ConnLed_SIO_REG            (* (reg32 *) ConnLed__SIO)
#endif /* (ConnLed__SIO_CFG) */

/* USBIO registers */
#if !defined(ConnLed__PC) && (CY_PSOC4_4200L)
    #define ConnLed_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define ConnLed_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define ConnLed_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define ConnLed_DRIVE_MODE_SHIFT       (0x00u)
#define ConnLed_DRIVE_MODE_MASK        (0x07u << ConnLed_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins ConnLed_H */


/* [] END OF FILE */
