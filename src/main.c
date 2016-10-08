/* Includes */
#include <stddef.h>
#include <stdio.h>
#include "stm32l1xx.h"

int main(void){

  int i = 0;
  int stav = 0;
  uint8_t button;
  uint8_t buttonNew;

  //cv3
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);

  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_40MHz;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_5;
  GPIO_Init(GPIOA, &GPIO_InitStruct);

  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_40MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_Init(GPIOC, & GPIO_InitStructure);

  /* Infinite loop */
  while (1) {
	  //cv3_uloha1
	  //GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_SET); // zasvietenie LED
	  //GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_RESET); // Vypnutie Led

	  //cv3_uloha3_1
	/*	for (i = 0; i < 5000; i++) {
			GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_SET); // zasvietenie LED
		}
		for (i = 0; i < 5000; i++) {
			GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_RESET); // Vypnutie Led
	*/

	  //cv3_uloha3_2
	/*	button = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);
		if (button == 1) {
			GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_SET); // zasvietenie LED
		} else {
			GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_RESET); // zasvietenie LED
		}*/

//		//cv3_uloha3_3 LMA
		button = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);
		if (!button) {
			for (i = 0; i < 300; i++) {}
			buttonNew = (button == GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13)) ? 0 : 1;
			stav = 1;
		}
		if (buttonNew && !button && stav) {
			GPIO_ToggleBits(GPIOA, GPIO_Pin_5);
			stav = 0;
		}

  }
  return 0;
}

  /* TODO - Add your application code here */


#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {

  }
}
#endif

/*
 * Minimal __assert_func used by the assert() macro
 * */
void __assert_func(const char *file, int line, const char *func, const char *failedexpr)
{
  while(1)
  {}
}

/*
 * Minimal __assert() uses __assert__func()
 * */
void __assert(const char *file, int line, const char *failedexpr)
{
   __assert_func (file, line, NULL, failedexpr);
}
