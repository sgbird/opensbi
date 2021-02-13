//#include <types.h>
//#include <io.h>
#include <sbi/riscv_io.h>
#include <sysmap.h>

#define UART_REG(n)	(UART_BASE + n)

#define THR	0x0
#define	USR	0x7c

#define DLL	0x0
#define DLH	0x4  // available when LCR[7] = 1
#define	IER	0x4  // available when LCR[7] = 0
#define FCR	0x8
#define LCR	0xc
#define	MCR	0x10

void uart_init(void)
{
	// MCR: AFCE=0, RTS=0, DTR=0
	__raw_writel(0x0, (void *)UART_REG(MCR));
	__raw_writel(0xa3, (void *)UART_REG(LCR));

	// Set Baudrate
	__raw_writel(0x1, (void *)UART_REG(DLL));
	__raw_writel(0x0, (void *)UART_REG(DLH));

	__raw_writel(0x23, (void *)UART_REG(LCR));
	__raw_writel(0x0, (void *)UART_REG(FCR));

	__raw_writel(0x2, (void *)UART_REG(IER));
}

/*
void sbi_putc(char str)
{
	volatile uint32_t status;
	
	do {
		status = __raw_readl((void *)UART_REG(USR));
	} while ((status & 0x1) == 0x1);  // wait BUSY to 0

	__raw_writel(str, (void *)(UART_REG(THR)));
}
*/
