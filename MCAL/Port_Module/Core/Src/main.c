/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Main.c
 *
 * Description: Source file for Port Module Test.
 *
 * Author: Mohamed Taha
 ******************************************************************************/

/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "Port.h"
#include "DWT.h"
void SystemClock_Config(void);

int main(void)
{
	uint8 counter = 0;
	uint8 mode_counter = 0;
	uint32 clockAtStart = 0;
	uint32 period = 0;
	HAL_Init();

  /* Configure the system clock */
	SystemClock_Config();




	/* initialize the driver */
	/* Port Module Test */

	DWT_InitCycleCounter(); /* enable DWT hardware */
	DWT_ResetCycleCounter(); /* reset cycle counter */

	DWT_EnableCycleCounter();
	Port_Init(&Port_Configuration);
	period = GetCycleCounter();
	DWT_ResetCycleCounter();
	/* Set pin direction */
	for(counter = 0; counter < PORT_NUMBER_OF_PINS; counter++)
	{
		DWT_EnableCycleCounter();
		Port_SetPinDirection(counter,PORT_PIN_OUT);
		period = GetCycleCounter();
		DWT_ResetCycleCounter();
		DWT_EnableCycleCounter();
		Port_SetPinDirection(counter,PORT_PIN_IN);
		period = GetCycleCounter();
		DWT_ResetCycleCounter();
	}

	/* Set pin mode */
	for(counter = 0; counter < PORT_NUMBER_OF_PINS; counter++)
	{
		for(mode_counter = 0; mode_counter <= PORT_AF_ANALOG_; mode_counter++)
		{
			DWT_EnableCycleCounter();
			Port_SetPinMode(counter,mode_counter);
			period = GetCycleCounter();
			DWT_ResetCycleCounter();
		}
	}

	/* Refresh port direction */
	DWT_EnableCycleCounter();
	Port_RefreshPortDirection();
	period = GetCycleCounter();
	DWT_ResetCycleCounter();
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
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 150;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
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
