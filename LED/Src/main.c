#include <stdint.h>
void delay();
int main(void){
	uint32_t *pAHB1ENR=(uint32_t*)0x40023830;
	uint32_t *pMODER=(uint32_t*)0x40020c00;
	uint32_t *pODR=(uint32_t*)0x40020c14;

	*pAHB1ENR |=(1<<3); //Enabling GPIODEN in bit 3 for GPIOD
	*pMODER |=(1<<26); //For General o/p mode 26 and 27 are 10 for o/p mode
	*pMODER &= ~ (1<<27);

	while(1){
		*pODR |=(1<<13);
		delay(1000);
		*pODR &=~(1<<13);
		delay(1000);
	}

}
void delay(int ms){
	for(int i=0;i<ms;i++){}
}
