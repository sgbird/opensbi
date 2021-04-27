//#include <types.h>
//#include <io.h>
#include <sbi/sbi_console.h>

void clk_init(void);
void uart_init(void);
void tlmm_init(void);
void pci_platform_init(void);

void system_init(void)
{
	clk_init();
	//rst_init();
	tlmm_init();
	uart_init();	
	//printf("bird, uart base addr: 0x%llx\n", addr);
	sbi_printf("bird\n");
	//pci_platform_init();

}
