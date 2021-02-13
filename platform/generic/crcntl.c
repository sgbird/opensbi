//#include <types.h>
//#include <io.h>
#include <bits.h>
#include <sbi/riscv_io.h>
#include <sysmap.h>

#define CRCNTL_REG(reg)	(CRCNTL_BASE + reg)
#define COHFAB_CFG_REG(reg) (COHFAB_CFG_BASE + reg)
#define CLUSTER0_CFG_REG(reg) (CLUSTER0_CFG_BASE + reg)

#define SW_RST_CFG0	0x130
#define CFG_EN_CFG0	0x140
#define CLK_SEL_CFG	0x150

#define CLK_CFG		0x40
 
void clk_init(void) 
{
	uint32_t val;

	// switch to cohfab PLL clk
	val = __raw_readl((void *)COHFAB_CFG_REG(CLK_CFG));
	val &= 0xfffffffe;
	__raw_writel(val, (void *)COHFAB_CFG_REG(CLK_CFG));
	
	// switch to cluster0 PLL clk
	val = __raw_readl((void *)CLUSTER0_CFG_REG(CLK_CFG));
	val &= 0xfffffffe;
	__raw_writel(val, (void *)CLUSTER0_CFG_REG(CLK_CFG));
	
	// switch to UART PLL clk
	val = __raw_readl((void *)CRCNTL_REG(CLK_SEL_CFG));
	val &= 0xfffffffc;
	__raw_writel(val, (void *)CRCNTL_REG(CLK_SEL_CFG));

	// enable PCIE clk;
	val = __raw_readl((void *)CRCNTL_REG(CFG_EN_CFG0));
	val |= BIT(2);
	__raw_writel(val, (void *)CRCNTL_REG(CFG_EN_CFG0));

	// switch to PCIE PLL clk;
	val = __raw_readl((void *)CRCNTL_REG(CLK_SEL_CFG));
	val &= 0xffffffcf;	// clear bit4,5 
	__raw_writel(val, (void *)CRCNTL_REG(CLK_SEL_CFG));

	// release reset	
	val = __raw_readl((void *)CRCNTL_REG(SW_RST_CFG0));
	val &= 0xfffffff9;	// clear bit1,2
	__raw_writel(val, (void *)CRCNTL_REG(SW_RST_CFG0));

	// release reset for DDR model, since DDR model
	// consumes AXI clock only, so just release reset
	// to make it work in ZEBU	
	val = __raw_readl((void *)CRCNTL_REG(SW_RST_CFG0));
	val &= 0xffffff7f;	// clear bit7
	__raw_writel(val, (void *)CRCNTL_REG(SW_RST_CFG0));
}
