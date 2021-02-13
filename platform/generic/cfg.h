#ifndef __CFG_H__
#define __CFG_H__

#ifdef SOCKET1
  #define SOCKET_OFFSET	0x80000000000
#else
  #define SOCKET_OFFSET 0x0
#endif

#define PCIE_BIRD
#define LANES   16
#define CONFIG_PCIE_ROLE_RC
//#define CONFIG_CHIPLINK
//#define CONFIG_PCIE_SPPED_GEN1
#define DEFAULT_LINK_MODE           LINK_MODE_16_0_0_0
//#define DEFAULT_LINK_MODE           LINK_MODE_8_8_0_0
//#define CONFIG_DEFAULT_LINK_MODE           LINK_MODE_ZEBU

//#define STANDALONE

#endif
