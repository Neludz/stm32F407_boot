#include "main.h"

extern  uint32_t _user_app_addr;
uint32_t user_app_addr = (uint32_t) &_user_app_addr;
int main(void)
{



	uint32_t appJumpAddress;
	void (*GoToApp)(void);
	appJumpAddress = *((volatile uint32_t*)(user_app_addr + 4));
	GoToApp = (void (*)(void))appJumpAddress;
	SCB->VTOR = (uint32_t) user_app_addr;
	__set_MSP(*((volatile uint32_t*)  user_app_addr)); //stack pointer (to RAM) for USER app in this address
	GoToApp();



}

