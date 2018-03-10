/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

#define LED_ON   1
#define LED_OFF  0

void updateRelay()
{
    CYBLE_GATTS_HANDLE_VALUE_NTF_T tempHandle1, tempHandle2;
    int relay_1 = (Relay_1_Read());
    int relay_2 = (Relay_2_Read());
    
    if(CyBle_GetState() != CYBLE_STATE_CONNECTED)
        return;
    
    tempHandle1.attrHandle = CYBLE_POWERSTRIP_RELAY_1_CHAR_HANDLE;
    tempHandle1.value.val = (uint8 *)&relay_1;
    tempHandle1.value.len = 1;
    CyBle_GattsWriteAttributeValue(&tempHandle1,0,&cyBle_connHandle,0);
    
    tempHandle2.attrHandle = CYBLE_POWERSTRIP_RELAY_2_CHAR_HANDLE;
    tempHandle2.value.val = (uint8 *)&relay_2;
    tempHandle2.value.len = 1;
    CyBle_GattsWriteAttributeValue(&tempHandle2,0,&cyBle_connHandle,0);
}

void BleCallBack(uint32 event, void* eventParam)
{
    CYBLE_GATTS_WRITE_REQ_PARAM_T *wrReqParam;
    
    switch(event)
    {
        case CYBLE_EVT_STACK_ON:
        case CYBLE_EVT_GAP_DEVICE_DISCONNECTED:
            CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
            ConnLed_Write(LED_OFF);
            break;
        case CYBLE_EVT_GATT_CONNECT_IND:
            updateRelay();
            ConnLed_Write(LED_ON);
            break;
        case CYBLE_EVT_GATTS_WRITE_REQ:
            wrReqParam = (CYBLE_GATTS_WRITE_REQ_PARAM_T *) eventParam;
            /*Request to write LED Param*/
            if(wrReqParam->handleValPair.attrHandle == CYBLE_POWERSTRIP_RELAY_1_CHAR_HANDLE)
            {
                /*Only update the value and write the response if write is allowed */
                if(CYBLE_GATT_ERR_NONE == CyBle_GattsWriteAttributeValue(&wrReqParam->handleValPair,0,&cyBle_connHandle,CYBLE_GATT_DB_PEER_INITIATED))
                {
                    Relay_1_Write(wrReqParam->handleValPair.value.val[0]);
                    CyBle_GattsWriteRsp(cyBle_connHandle);
                }
            }
            else if(wrReqParam->handleValPair.attrHandle == CYBLE_POWERSTRIP_RELAY_2_CHAR_HANDLE)
            {
                /*Only update the value and write the response if write is allowed */
                if(CYBLE_GATT_ERR_NONE == CyBle_GattsWriteAttributeValue(&wrReqParam->handleValPair,0,&cyBle_connHandle,CYBLE_GATT_DB_PEER_INITIATED))
                {
                    Relay_2_Write(wrReqParam->handleValPair.value.val[0]);
                    CyBle_GattsWriteRsp(cyBle_connHandle);
                }
            }
            break;

        default:
            break;
    }
}

int main()
{
    CyGlobalIntEnable;
    
    CyBle_Start(BleCallBack);
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        CyBle_ProcessEvents();
        CyBle_EnterLPM(CYBLE_BLESS_DEEPSLEEP);
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
