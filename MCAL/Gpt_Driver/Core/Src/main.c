/******************************************************************************
 *
 * Module: GPT
 *
 * File Name: Main.c
 *
 * Description: Source file for GPT Module Test.
 *
 * Author: Mohamed Taha
 ******************************************************************************/


#include "main.h"
#include "Gpt.h"
#include "DWT.h"

void SystemClock_Config(void);

int main(void)
{
	uint8 counter = 0;
	uint32 clockAtStart = 0;
	uint32 period = 0;
	uint32 Value = 2000;
	HAL_Init();
	/* Configure the system clock */
	SystemClock_Config();

	/* initialize the driver */
	/* GPT Module Test */
	DWT_Init();
	clockAtStart = DWT_currentClock();
	Gpt_Init(&Gpt_Configuration);
	period = DWT_currentClock()-clockAtStart;

	/* Start Timer */
	for(counter = 0; counter < NUMBER_OF_GPT_CHANNELS; counter++)
	{
		clockAtStart = DWT_currentClock();
		Gpt_StartTimer(counter, Value);
		period = DWT_currentClock()-clockAtStart;
	}

	/* get time elapsed*/
	for(counter = 0; counter < NUMBER_OF_GPT_CHANNELS; counter++)
	{
		clockAtStart = DWT_currentClock();
		Gpt_GetTimeElapsed(counter);
		period = DWT_currentClock()-clockAtStart;
	}

	/* get time remaining*/
	for(counter = 0; counter < NUMBER_OF_GPT_CHANNELS; counter++)
	{
		clockAtStart = DWT_currentClock();
		Gpt_GetTimeRemaining(counter);
		period = DWT_currentClock()-clockAtStart;
	}

	/* Stop Timer */
	for(counter = 0; counter < NUMBER_OF_GPT_CHANNELS; counter++)
	{
		clockAtStart = DWT_currentClock();
		Gpt_StopTimer(counter);
		period = DWT_currentClock()-clockAtStart;
	}


	/* Deinitialize the drive */
	clockAtStart = DWT_currentClock();
	Gpt_DeInit();
	period = DWT_currentClock()-clockAtStart;
  while (1)
  {

  }
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
