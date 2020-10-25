#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "HLEDMAT_interface.h"
#include "HLEDMAT_private.h"
#include "HLEDMAT_config.h"

u8 *HLEDMAT_u8Frame;
u8 HLEDMAT_u8CurrentIdx;
void HLEDMAT_voidInit(void)
{
	   GPIOX_VidSetPinDirection(HLEDMAT_ROW_0,0b0010);
		GPIOX_VidSetPinDirection(HLEDMAT_ROW_1,0b0010);
		GPIOX_VidSetPinDirection(HLEDMAT_ROW_2,0b0010);
		GPIOX_VidSetPinDirection(HLEDMAT_ROW_3,0b0010);
		GPIOX_VidSetPinDirection(HLEDMAT_ROW_4,0b0010);
		GPIOX_VidSetPinDirection(HLEDMAT_ROW_5,0b0010);
		GPIOX_VidSetPinDirection(HLEDMAT_ROW_6,0b0010);
		GPIOX_VidSetPinDirection(HLEDMAT_ROW_7,0b0010);


		GPIOX_VidSetPinDirection(HLEDMAT_COL_0,0b0010);
		GPIOX_VidSetPinDirection(HLEDMAT_COL_1,0b0010);
		GPIOX_VidSetPinDirection(HLEDMAT_COL_2,0b0010);
		GPIOX_VidSetPinDirection(HLEDMAT_COL_3,0b0010);
		GPIOX_VidSetPinDirection(HLEDMAT_COL_4,0b0010);
		GPIOX_VidSetPinDirection(HLEDMAT_COL_5,0b0010);
		GPIOX_VidSetPinDirection(HLEDMAT_COL_6,0b0010);
		GPIOX_VidSetPinDirection(HLEDMAT_COL_7,0b0010);
}

void HLEDMAT_voidDisplayFrame(u8 *Copy_u8Frame)
{
	/* Save the desired Frame */
	HLEDMAT_u8Frame = Copy_u8Frame;
	
	/* Reset the frame Start */
	HLEDMAT_u8CurrentIdx = 0;
	
	/* Dislay The first Column */
	ActivateColumn(HLEDMAT_u8CurrentIdx);
	SetRowsValue  (Copy_u8Frame[HLEDMAT_u8CurrentIdx]);
	
	/* Start timer */
	MSTK_VidSetIntervalPeriodic(2000,DisplayNextColumn);
}


void DisplayNextColumn(void)
{
	HLEDMAT_u8CurrentIdx++;
	if (HLEDMAT_u8CurrentIdx == 8)
	{
		HLEDMAT_u8CurrentIdx = 0;
	}
	
	/* Dislay The first Column */
	ActivateColumn(HLEDMAT_u8CurrentIdx);
	SetRowsValue  (HLEDMAT_u8Frame[HLEDMAT_u8CurrentIdx]);
}

void SetRowsValue  (u8 Copy_u8Value)
{
	u8 Local_u8Idx;
	u8 Local_u8Bit[8];
	for (Local_u8Idx =0; Local_u8Idx<8;Local_u8Idx++)
	{
		Local_u8Bit[Local_u8Idx]=GET_BIT(Copy_u8Value,Local_u8Idx);
	}
	
	GPIOX_VidSetPinValue(HLEDMAT_ROW_0,Local_u8Bit[0]);
	GPIOX_VidSetPinValue(HLEDMAT_ROW_1,Local_u8Bit[1]);
	GPIOX_VidSetPinValue(HLEDMAT_ROW_2,Local_u8Bit[2]);
	GPIOX_VidSetPinValue(HLEDMAT_ROW_3,Local_u8Bit[3]);
	GPIOX_VidSetPinValue(HLEDMAT_ROW_4,Local_u8Bit[4]);
	GPIOX_VidSetPinValue(HLEDMAT_ROW_5,Local_u8Bit[5]);
	GPIOX_VidSetPinValue(HLEDMAT_ROW_6,Local_u8Bit[6]);
	GPIOX_VidSetPinValue(HLEDMAT_ROW_7,Local_u8Bit[7]);

}

void ActivateColumn(u8 Copy_u8Col)
{
	/* Disable All */
	GPIOX_VidSetPinValue(HLEDMAT_COL_0,HIGH);
	GPIOX_VidSetPinValue(HLEDMAT_COL_1,HIGH);
	GPIOX_VidSetPinValue(HLEDMAT_COL_2,HIGH);
	GPIOX_VidSetPinValue(HLEDMAT_COL_3,HIGH);
	GPIOX_VidSetPinValue(HLEDMAT_COL_4,HIGH);
	GPIOX_VidSetPinValue(HLEDMAT_COL_5,HIGH);
	GPIOX_VidSetPinValue(HLEDMAT_COL_6,HIGH);
	GPIOX_VidSetPinValue(HLEDMAT_COL_7,HIGH);
	
	/* Enable the desired pin only */
	switch (Copy_u8Col)
	{
		case 0: GPIOX_VidSetPinValue(HLEDMAT_COL_0,LOW); break;
		case 1: GPIOX_VidSetPinValue(HLEDMAT_COL_1,LOW); break;
		case 2: GPIOX_VidSetPinValue(HLEDMAT_COL_2,LOW); break;
		case 3: GPIOX_VidSetPinValue(HLEDMAT_COL_3,LOW); break;
		case 4: GPIOX_VidSetPinValue(HLEDMAT_COL_4,LOW); break;
		case 5: GPIOX_VidSetPinValue(HLEDMAT_COL_5,LOW); break;
		case 6: GPIOX_VidSetPinValue(HLEDMAT_COL_6,LOW); break;
		case 7: GPIOX_VidSetPinValue(HLEDMAT_COL_7,LOW); break;
	}
}
