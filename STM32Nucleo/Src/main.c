/*********************************************************************************************************
 *                 STM32F103RB BLINK PROJECT WITH SWITCH USING BARE METAL CONCEPT
 *
 *
 *********************************************************************************************************/
/*..........Port_C 8 pin as OUTPUT(LED which connected to this pin)..................*/
/*..........Port_C 9 pin as INPUT (Button which is connected to this pin..............*/

#include <stdint.h>

/*......Step 1: Enable the PORT C Clock Base Address of PORT C is 0x4001 1000......*/
#define GPIOC_BASEADDR  (uint32_t)0x40011000
#define RCC_BASEADDR	(uint32_t)0x40021000

/*We have Port C located in APB2 Bus need to enable the clock via RCC*/

#define RCC_APB2ENR					(RCC_BASEADDR+0x18)   //Address of RCC APB2 Enable register
#define GPIOC_CRH					(GPIOC_BASEADDR+0x04) //Address of RCC Configuration High Register

#define GPIOC_ODR					(GPIOC_BASEADDR+0x0C)  // Address of Output data register
#define GPIOC_IDR					(GPIOC_BASEADDR+0x08)  // Address of Input date register
#define GPIOC_BSRR      			(GPIOC_BASEADDR+0x10)	//Address of Bit set/reset register

/*.........Defining the address to the pointer...............*/

volatile uint32_t *pRCC_APB2ENR = 	(uint32_t*)RCC_APB2ENR;
volatile uint32_t *pGPIOC_CRH   = 	(uint32_t*)GPIOC_CRH;
volatile uint32_t *pGPIOC_BSRR  = 	(uint32_t*)GPIOC_BSRR;
volatile uint32_t *pGPIOC_ODR   = 	(uint32_t*)GPIOC_ODR;
volatile uint32_t *pGPIOC_IDR   = 	(uint32_t*)GPIOC_IDR;

int bitstatus=0;

int main(void)
{
	*pRCC_APB2ENR |= (1<<4);  //To set the PORT C clock in the RCC register
	*pGPIOC_CRH	  = 0x44444485;


while(1){

bitstatus=(*pGPIOC_IDR>>9)&1;
for(int i=0;i<=500;i++);
if(bitstatus==1)
{
	*pGPIOC_BSRR |=(1<<8);
}
else
{
	*pGPIOC_BSRR |=(1<<24);
}

}


}
