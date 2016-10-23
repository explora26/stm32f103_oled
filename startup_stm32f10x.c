/* Generated by startup_generator */

#include <stdint.h>
#include <stm32f10x.h>
#include <core_cm3.h>

/* start address for the initialization values of the .data section.
defined in linker script */
extern uint32_t _sidata;
/* start address for the .data section. defined in linker script */
extern uint32_t __data_start__;
/* end address for the .data section. defined in linker script */
extern uint32_t __data_end__;
/* start address for the .bss section. defined in linker script */
extern uint32_t __bss_start__;
/* end address for the .bss section. defined in linker script */
extern uint32_t __bss_end__;
/* end address for the stack. defined in linker script */
extern uint32_t _estack;

extern int main(void);

void Reset_Handler(void) {

	/* Copy the data segment initializers from flash to SRAM */
	uint32_t *idata_begin = &_sidata;
	uint32_t *data_begin = &__data_start__;
	uint32_t *data_end = &__data_end__;
	while (data_begin < data_end) *data_begin++ = *idata_begin++;

	/* Zero fill the bss segment. */
	uint32_t *bss_begin = &__bss_start__;
	uint32_t *bss_end = &__bss_end__;
	while (bss_begin < bss_end) *bss_begin++ = 0;

    SystemInit();
    main();
    while(1) {}
}

void default_handler (void) 
{
  while(1);
}

/* Vector Table */

void NMI_Handler (void) __attribute__ ((weak,  alias ("default_handler")));
void HardFault_Handler (void) __attribute__ ((weak,  alias ("default_handler")));
void MemMange_Handler (void) __attribute__ ((weak,  alias ("default_handler")));
void BusFault_Handler (void) __attribute__ ((weak,  alias ("default_handler")));
void UsageFault_Handler (void) __attribute__ ((weak,  alias ("default_handler")));
void SVC_Handler (void) __attribute__ ((weak,  alias ("default_handler")));
void DebugMon_Handler (void) __attribute__ ((weak,  alias ("default_handler")));
void PendSV_Handler (void) __attribute__ ((weak,  alias ("default_handler")));
void SysTick_Handler (void) __attribute__ ((weak,  alias ("default_handler")));
void WWDG_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void PVD_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void TAMPER_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void RTC_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void FLASH_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void RCC_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void EXTI0_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void EXTI1_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void EXTI2_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void EXTI3_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void EXTI4_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void DMA1_Channel1_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void DMA1_Channel2_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void DMA1_Channel3_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void DMA1_Channel4_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void DMA1_Channel5_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void DMA1_Channel6_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void DMA1_Channel7_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void ADC1_2_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void USB_HP_CAN1_TX_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void USB_LP_CAN1_RX0_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void CAN1_RX1_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void CAN1_SCE_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void EXTI9_5_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void TIM1_BRK_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void TIM1_UP_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void TIM1_TRG_COM_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void TIM1_CC_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void TIM2_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void TIM3_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void TIM4_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void I2C1_EV_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void I2C1_ER_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void I2C2_EV_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void I2C2_ER_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void SPI1_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void SPI2_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void USART1_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void USART2_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void USART3_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void EXTI15_10_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void RTCAlarm_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));
void USBWakeUp_IRQHandler (void) __attribute__ ((weak,  alias ("default_handler")));


__attribute__ ((section(".isr_vector")))
uint32_t *isr_vectors[] = {
	(uint32_t *) &_estack,
	(uint32_t *) Reset_Handler,
	(uint32_t *) NMI_Handler,
	(uint32_t *) HardFault_Handler,
	(uint32_t *) MemMange_Handler,
	(uint32_t *) BusFault_Handler,
	(uint32_t *) UsageFault_Handler,
	0,
	0,
	0,
	0,
	(uint32_t *) SVC_Handler,
	(uint32_t *) DebugMon_Handler,
	0,
	(uint32_t *) PendSV_Handler,
	(uint32_t *) SysTick_Handler,
	(uint32_t *) WWDG_IRQHandler,
	(uint32_t *) PVD_IRQHandler,
	(uint32_t *) TAMPER_IRQHandler,
	(uint32_t *) RTC_IRQHandler,
	(uint32_t *) FLASH_IRQHandler,
	(uint32_t *) RCC_IRQHandler,
	(uint32_t *) EXTI0_IRQHandler,
	(uint32_t *) EXTI1_IRQHandler,
	(uint32_t *) EXTI2_IRQHandler,
	(uint32_t *) EXTI3_IRQHandler,
	(uint32_t *) EXTI4_IRQHandler,
	(uint32_t *) DMA1_Channel1_IRQHandler,
	(uint32_t *) DMA1_Channel2_IRQHandler,
	(uint32_t *) DMA1_Channel3_IRQHandler,
	(uint32_t *) DMA1_Channel4_IRQHandler,
	(uint32_t *) DMA1_Channel5_IRQHandler,
	(uint32_t *) DMA1_Channel6_IRQHandler,
	(uint32_t *) DMA1_Channel7_IRQHandler,
	(uint32_t *) ADC1_2_IRQHandler,
	(uint32_t *) USB_HP_CAN1_TX_IRQHandler,
	(uint32_t *) USB_LP_CAN1_RX0_IRQHandler,
	(uint32_t *) CAN1_RX1_IRQHandler,
	(uint32_t *) CAN1_SCE_IRQHandler,
	(uint32_t *) EXTI9_5_IRQHandler,
	(uint32_t *) TIM1_BRK_IRQHandler,
	(uint32_t *) TIM1_UP_IRQHandler,
	(uint32_t *) TIM1_TRG_COM_IRQHandler,
	(uint32_t *) TIM1_CC_IRQHandler,
	(uint32_t *) TIM2_IRQHandler,
	(uint32_t *) TIM3_IRQHandler,
	(uint32_t *) TIM4_IRQHandler,
	(uint32_t *) I2C1_EV_IRQHandler,
	(uint32_t *) I2C1_ER_IRQHandler,
	(uint32_t *) I2C2_EV_IRQHandler,
	(uint32_t *) I2C2_ER_IRQHandler,
	(uint32_t *) SPI1_IRQHandler,
	(uint32_t *) SPI2_IRQHandler,
	(uint32_t *) USART1_IRQHandler,
	(uint32_t *) USART2_IRQHandler,
	(uint32_t *) USART3_IRQHandler,
	(uint32_t *) EXTI15_10_IRQHandler,
	(uint32_t *) RTCAlarm_IRQHandler,
	(uint32_t *) USBWakeUp_IRQHandler,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	(uint32_t *)0xF108F85F,          /* @0x108. This is for boot in RAM mode for */
};


