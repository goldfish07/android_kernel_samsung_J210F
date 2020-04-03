#ifndef _DOLPHIN_NAND_H_
#define _DOLPHIN_NAND_H_
#include <mach/hardware.h>

#define NFC_REG_BASE                (SPRD_NFC_BASE)
#define NFC_START_REG               (NFC_REG_BASE)
#define NFC_CFG0_REG                (NFC_REG_BASE + 0x04)
#define NFC_CFG1_REG                (NFC_REG_BASE + 0x08)
#define NFC_CFG2_REG                (NFC_REG_BASE + 0x0C)
#define NFC_INT_REG                 (NFC_REG_BASE + 0x10)
#define NFC_TIMING_REG              (NFC_REG_BASE + 0x14)
#define NFC_TIMEOUT_REG             (NFC_REG_BASE + 0x18)
#define NFC_MAIN_ADDR_REG           (NFC_REG_BASE + 0x20)
#define NFC_SPAR_ADDR_REG           (NFC_REG_BASE + 0x24)
#define NFC_STAT_ADDR_REG           (NFC_REG_BASE + 0x28)
#define NFC_STAT_STSMCH_REG         (NFC_REG_BASE + 0x30)
#define NFC_STATUS0_REG             (NFC_REG_BASE + 0x40)
#define NFC_STATUS1_REG             (NFC_REG_BASE + 0x44)
#define NFC_STATUS2_REG             (NFC_REG_BASE + 0x48)
#define NFC_STATUS3_REG             (NFC_REG_BASE + 0x4C)
#define NFC_INST0_REG               (NFC_REG_BASE + 0x60)
#define NFC_INST1_REG               (NFC_REG_BASE + 0x64)
#define NFC_INST2_REG               (NFC_REG_BASE + 0x68)
#define NFC_INST3_REG               (NFC_REG_BASE + 0x6C)
#define NFC_INST4_REG               (NFC_REG_BASE + 0x70)
#define NFC_INST5_REG               (NFC_REG_BASE + 0x74)
#define NFC_INST6_REG               (NFC_REG_BASE + 0x78)
#define NFC_INST7_REG               (NFC_REG_BASE + 0x7C)
#define NFC_INST8_REG               (NFC_REG_BASE + 0x80)
#define NFC_INST9_REG               (NFC_REG_BASE + 0x84)
#define NFC_INST10_REG              (NFC_REG_BASE + 0x88)
#define NFC_INST11_REG              (NFC_REG_BASE + 0x8C)

//NFC_START bit define
#define NFC_VALID                   (1 << 31)
#define NFC_RBN                     (1 << 30)
#define NFC_RBN_CNT_OFFSET          (28)
#define NFC_RBN_CNT_MASK            (0x3 << NFC_RBN_CNT_OFFSET)
#define NFC_CMD_CLR                 (1 << 1)
#define NFC_START                   (1 << 0)

//NFC_CFG0 bit define
#define MAST_ENDIAN_OFFSET          (30)
#define MAST_ENDIAN_MASK            (0x3 << MAST_ENDIAN_OFFSET)
#define CS_SEL                      (1 << 0)
#define SECTOR_NUM_OFFSET           (24)
#define SECTOR_NUM_MASK             (0x1f << SECTOR_NUM_OFFSET)
#define REPEAT_NUM_OFFSET           (16)
#define REPEAT_NUM_MASK             (0xff << REPEAT_NUM_OFFSET)
#define NFC_WPN                     (1 << 15)
#define BUS_WIDTH                   (1 << 14)
#define SPAR_DLEN_CFG               (1 << 13)
#define SECNUM_IN_INST              (1 << 12)
#define DETECT_ALL_FF               (1 << 11)
#define NFC_RW                      (1 << 8)
#define MAIN_SPAR_APT               (1 << 6)
#define SPAR_USE                    (1 << 5)
#define MAIN_USE                    (1 << 4)
#define ECC_EN                      (1 << 2)
#define NFC_MODE_MASK               (0x3)
#define NFC_AUTO_MODE               (0x0)
#define NFC_ONLY_MST_MODE           (0x1)
#define NFC_ONLY_NAND_MODE          (0x2)
#define NFC_ONLY_ECC_MODE           (0x3)
//NFC_CFG1 bit define
#define SPAR_INFO_SIZE_OFFSET       (24)
#define SPAR_INFO_SIZE_MASK         (0x3f << SPAR_INFO_SIZE_OFFSET)
#define SPAR_SIZE_OFFSET            (16)
#define SPAR_SIZE_MASK              (0x7F << SPAR_SIZE_OFFSET)
#define MAIN_SIZE_MASK              (0x3ff)
//NFC_CFG2 bit define
#define SPAR_SECTOR_NUM_OFFSET      (24)
#define SPAR_SECTOR_NUM_MASK        (0x1f << SPAR_SECTOR_NUM_OFFSET)
#define SPAR_INFO_POS_OFFSET        (16)
#define SPAR_INFO_POS_MASK          (0x7f << SPAR_INFO_POS_OFFSET)
#define ECC_MODE_OFFSET             (13)
#define ECC_MODE_MASK               (0x7 << ECC_MODE_OFFSET)
#define NFC_ECC_MODE_1BIT           (0 << ECC_MODE_OFFSET)
#define NFC_ECC_MODE_2BIT           (1 << ECC_MODE_OFFSET)
#define NFC_ECC_MODE_4BIT           (2 << ECC_MODE_OFFSET)
#define NFC_ECC_MODE_8BIT           (3 << ECC_MODE_OFFSET)
#define NFC_ECC_MODE_12BIT          (4 << ECC_MODE_OFFSET)
#define NFC_ECC_MODE_16BIT          (5 << ECC_MODE_OFFSET)
#define NFC_ECC_MODE_24BIT          (6 << ECC_MODE_OFFSET)

#define ECC_STR_SEC_IND_OFFSET      (8)
#define ECC_STR_SEC_IND_MASK        (0x1f << ECC_STR_SEC_IND_OFFSET)
#define ECC_POSITON_MASK            (0x7f)
//NFC_INT bit define
#define INT_STSMCH_RAW              (1 << 27)
#define INT_WP_RAW                  (1 << 26)
#define INT_TO_RAW                  (1 << 25)
#define INT_DONE_RAW                (1 << 24)
#define INT_STSMCH_STS              (1 << 19)
#define INT_WP_STS                  (1 << 18)
#define INT_TO_STS                  (1 << 17)
#define INT_DONE_STS                (1 << 16)

#define INT_STSMCH_CLR              (1 << 11)
#define INT_WP_CLR                  (1 << 10)
#define INT_TO_CLR                  (1 << 9)
#define INT_DONE_CLR                (1 << 8)

#define INT_STSMCH_EN               (1 << 3)
#define INT_WP_EN                   (1 << 2)
#define INT_TO_EN                   (1 << 1)
#define INT_DONE_EN                 (1 << 0)


//NFC_TIMING
#define NFC_ACS_OFFSET              (27)
#define NFC_ACS_MASK                (0x1f << NFC_ACS_OFFSET)
#define NFC_ACE_OFFSET              (22)
#define NFC_ACE_MASK                (0x1f << NFC_ACE_OFFSET)
#define NFC_RWS_OFFSET              (16)
#define NFC_RWS_MASK                (0x3f << NFC_RWS_OFFSET)
#define NFC_RWE_OFFSET              (11)
#define NFC_RWE_MASK                (0x3f << NFC_RWS_OFFSET)
#define NFC_RWH_OFFSET              (6)
#define NFC_RWH_MASK                (0x1f << NFC_RWH_OFFSET)
#define NFC_RWL_MASK                (0x3f)
//NFC_TIMEOUT bit define
#define REPT_CLR_EN                 (1 << 31)
#define TIMETOUT_MASK               (0x7fffffff)

//NFC_STAT_STSMCH bit define
#define NFC_STSMCH_SEL              (1 << 17)
#define NFC_STSMCH_STOP_EN          (1 << 16)
#define NFC_STSMCH_MASK_OFFSET      (8)
#define NFC_STSMCH_VALUE_MASK       (0xff)
#define ERR_ERR_NUM0_MASK           (0x1f)
//NFC_STATUS0_REG bit define
#define ECC_ERR_NUM_MASK            (0x1f)
#define ECC_ERR_STS_SHIFT           (5)
#define ECC_ERR_STS_MASK            (0x3 << ECC_ERR_STS_SHIFT)
#define ECC_ALL_FF                  (1 << 7)

#define NFC_MC_ICMD_ID              (0xCD)
#define NFC_MC_ADDR_ID              (0x0A)
#define NFC_MC_WRB0_ID              (0xB0)
#define NFC_MC_WRB1_ID              (0xB1)
#define NFC_MC_MRDT_ID              (0xD0)
#define NFC_MC_MWDT_ID              (0xD1)
#define NFC_MC_SRDT_ID              (0xD2)
#define NFC_MC_SWDT_ID              (0xD3)
#define NFC_MC_IDST_ID              (0xDD)
#define NFC_MC_CSEN_ID              (0xCE)
#define NFC_MC_NOP_ID               (0xF0)
#define NFC_MC_DONE_ID              (0xFF)
#define NFC_MAX_CHIP                1
#define NFC_TIMEOUT_VAL             3000000   //usecs

#define NAND_MC_CMD(x)              (u16)(((x & 0xff) << 8) | NFC_MC_ICMD_ID)
#define NAND_MC_ADDR(x)             (u16)(((x & 0xff) << 8) | (NFC_MC_ADDR_ID << 4))
#define NAND_MC_WRB0(x)             (u16)(NFC_MC_WRB0_ID)
#define NAND_MC_MRDT                (u16)(NFC_MC_MRDT_ID)
#define NAND_MC_MWDT                (u16)(NFC_MC_MWDT_ID)
#define NAND_MC_SRDT                (u16)(NFC_MC_SRDT_ID)
#define NAND_MC_SWDT                (u16)(NFC_MC_SWDT_ID)
#define NAND_MC_IDST(x)             (u16)((NFC_MC_IDST_ID) | ((x -1) << 8))
#define NAND_MC_NOP(x)			(u16)(((x & 0xff) << 8) | NFC_MC_NOP_ID)

#define NFC_DEFAULT_TIMING          ((7)  | (6 << NFC_RWH_OFFSET) | (7 << NFC_RWE_OFFSET) | (7 << NFC_RWS_OFFSET) | (7 << NFC_ACE_OFFSET) | (7 << NFC_ACS_OFFSET))
 /* TODO : use global interface */
#define AHB_SOFT_NFC_RST            (1 << 5)

#endif
