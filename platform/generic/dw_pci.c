//#include <types.h>
//#include <io.h>
#include <sbi/riscv_io.h>
#include <bits.h>
#include <sysmap.h>

#define MODE	2

void pci_platform_init(void)
{
	uint32_t i, val = 0;
	uint8_t mode = MODE;

	__raw_writel(mode, (void *)0xff09000014);
	__raw_writel(0xff, (void *)0xff09000000);
	__raw_writel(0xff, (void *)0xff09000004);
	__raw_writel(0xff, (void *)0xff09000008);
	__raw_writel(0xff, (void *)0xff0900000c);
	__raw_writel(0xc810010, (void *)0xff09001000);
	__raw_writel(0x10, (void *)0xff09000010);
	__raw_writel(0x0, (void *)0xff0900001c);
	__raw_writel(0x2, (void *)0xff09000018);
	__raw_writel(0xf, (void *)0xff09000010);
	__raw_writel(0x55, (void *)0xff0900001c);
	__raw_writel(0xc018010, (void *)0xff09001000);
	
	/* for pcie smmu */
	__raw_writel(0x9f0001, (void *)0xff08400000);


	while (val != 0x911)
		val = __raw_readl((void *)0xff09001010);

	for (i=0; i<65535; i++)
		__asm__("nop");
}
