//#include <types.h>
//#include <io.h>
#include <sbi/riscv_io.h>
#include <bits.h>
#include <sysmap.h>

#define GPIO(n)	(TLMM_BASE + 4*n)

void tlmm_init(void)
{
	uint32_t val;

	// config UART0 input
	val = __raw_readl((void *)GPIO(54));
	val |= 0x8;
	__raw_writel(val, (void *)GPIO(54));

	// config UART0 output
	val = __raw_readl((void *)GPIO(55));
	val |= 0x8;
	__raw_writel(val, (void *)GPIO(55));
}
