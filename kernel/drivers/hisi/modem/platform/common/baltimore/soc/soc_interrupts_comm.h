#ifndef __SOC_INTERRUPTS_COMM_H
#define __SOC_INTERRUPTS_COMM_H 
#ifdef __cplusplus
extern "C" {
#endif
#define GIC_PPI_START 27
#define GIC_SPI_START 32
#define SGI_INT_MAX 16
#define INT_LVL_MAX 280
#define INT_LVL_RTC 36
#define INT_LVL_WDT 37
#define INT_LVL_UPACC_DSP 38
#define INT_LVL_UICC 39
#define INT_LVL_UPACC_BBP_I1_E 40
#define INT_LVL_UPACC_BBP_I2 41
#define INT_LVL_EDMAC2 42
#define INT_LVL_CIPHER 43
#define INT_LVL_IPF0 44
#define INT_LVL_IPF1 45
#define INT_LVL_SOCP0 46
#define INT_LVL_SOCP1 47
#define INT_LVL_LTESIO_RX 48
#define INT_LVL_LTESIO_SIO 49
#define INT_LVL_LTESIO_TX 50
#define INT_LVL_UART2 50
#define INT_LVL_CICOM0_UL 51
#define INT_LVL_CICOM0_DL 52
#define INT_LVL_CICOM1_UL 53
#define INT_LVL_CICOM1_DL 54
#define INT_LVL_UPACC_ARM 55
#define INT_LVL_HDLC_FRM 56
#define INT_LVL_HDLC_DEF 57
#define INT_LVL_CS_ETR_0_FULL 58
#define INT_LVL_TSENSOR 59
#define INT_LVL_TIMER0 77
#define INT_LVL_TIMER1 78
#define INT_LVL_TIMER2 79
#define INT_LVL_TIMER3 80
#define INT_LVL_TIMER4 81
#define INT_LVL_TIMER5 82
#define INT_LVL_TIMER6 83
#define INT_LVL_TIMER7 84
#define INT_LVL_TIMER8 85
#define INT_LVL_TIMER9 86
#define INT_LVL_TIMER10 87
#define INT_LVL_TIMER11 88
#define INT_LVL_TIMER12 89
#define INT_LVL_TIMER13 90
#define INT_LVL_TIMER14 91
#define INT_LVL_TIMER15 92
#define INT_LVL_SCI0 93
#define INT_LVL_SCI1 94
#define INT_LVL_SPI0 95
#define INT_LVL_SPI1 96
#define INT_LVL_TCSSI0 97
#define INT_LVL_TCSSI1 98
#define INT_LVL_USB3_PME 99
#define INT_LVL_MIPI 100
#define INT_LVL_HSUART 101
#define INT_LVL_UART0 106
#define INT_LVL_UART1 107
#define INT_LVL_NANDC 274
#define INT_LVL_MIPI1 109
#define INT_LVL_I2C0 111
#define INT_LVL_I2C1 116
#define INT_LVL_EDMAC0 119
#define INT_LVL_EDMAC1 120
#define INT_LVL_AMON 121
#define INT_LVL_HSIC 122
#define INT_LVL_APP_PMU 123
#define INT_LVL_MDM_PMU 124
#define INT_LVL_PMU 127
#define INT_LVL_USB3_OTG 128
#define INT_LVL_X2H_X2P_ERR 129
#define INT_LVL_AXI_ERR 130
#define INT_LVL_USBOTG_BC 131
#define INT_LVL_TIMER16 134
#define INT_LVL_TIMER17 135
#define INT_LVL_TIMER18 136
#define INT_LVL_TIMER19 137
#define INT_LVL_TIMER20 138
#define INT_LVL_TIMER21 139
#define INT_LVL_TIMER22 140
#define INT_LVL_TIMER23 141
#define INT_LVL_CPU_AXI_LOCK 143
#define INT_LVL_GLB_AXI_LOCK 144
#define INT_LVL_MST_AXI_LOCK 145
#define INT_LVL_AMON_AXI_LOCK 146
#define INT_LVL_BBPPHY_AXI_LOCK 147
#define INT_LVL_SDCC_HCLK_WKUP 148
#define INT_LVL_LTE_ARM_POSITION_INT 149
#define INT_LVL_LTE_ARM_DL_DMA_INT 150
#define INT_LVL_CBBP_INTR04_2 151
#define INT_LVL_APP_L2CC 155
#define INT_LVL_MDMA9_L2CC 156
#define INT_LVL_USB3 158
#define INT_LVL_APP_SRST_REQ 160
#define INT_LVL_MDM_SRST_REQ 161
#define INT_LVL_LDRX2ARM_TIMERS_INT 162
#define INT_LVL_LDRX2ARM_WAKEUP_INT 163
#define INT_LVL_LDRX2ARM_PUB_INT 164
#define INT_LVL_TDRX2ARM_TIMERS_INT 165
#define INT_LVL_TDRX2ARM_WAKEUP_INT 166
#define INT_LVL_TDS_STU_ARM_INT 167
#define INT_LVL_CBBP_INTR01_2 168
#define INT_LVL_CBBP_INTR02_2 169
#define INT_LVL_ARM_VIC0 170
#define INT_LVL_ARM_VIC1 171
#define INT_LVL_ARM_VIC2 172
#define INT_LVL_ARM_VIC3 173
#define INT_LVL_EDMAC_CH4_0 182
#define INT_LVL_EDMAC_CH4_1 183
#define INT_LVL_EDMAC_CH4_2 184
#define INT_LVL_MERGE0 186
#define INT_LVL_MERGE1 187
#define INT_LVL_MERGE2 188
#define INT_LVL_MERGE3 189
#define INT_LVL_PCIE0_LINK_DOWN 192
#define INT_LVL_PCIE0_EDMA 193
#define INT_LVL_PCIE0_PM 194
#define INT_LVL_PCIE0_RADM_A 195
#define INT_LVL_PCIE0_RADM_B 196
#define INT_LVL_PCIE0_RADM_C 197
#define INT_LVL_PCIE0_RADM_D 198
#define INT_LVL_PCIE1_LINK_DOWN 199
#define INT_LVL_PCIE1_EDMA 200
#define INT_LVL_PCIE1_PM 201
#define INT_LVL_PCIE1_RADM_A 202
#define INT_LVL_PCIE1_RADM_B 203
#define INT_LVL_PCIE1_RADM_C 204
#define INT_LVL_PCIE1_RADM_D 205
#define INT_LVL_VIC_LTE_ARM_POSITION_INT (INT_LVL_MAX+32*0+0)
#define INT_LVL_VIC_LTE_ARM_DL_DMA_INT (INT_LVL_MAX+32*0+1)
#define INT_LVL_VIC_LDRX2ARM_TIMERS_INT (INT_LVL_MAX+32*0+4)
#define INT_LVL_VIC_LDRX2ARM_WAKEUP_INT (INT_LVL_MAX+32*0+5)
#define INT_LVL_VIC_TDRX2ARM_TIMERS_INT (INT_LVL_MAX+32*0+6)
#define INT_LVL_VIC_TDRX2ARM_WAKEUP_INT (INT_LVL_MAX+32*0+7)
#define INT_LVL_VIC_TDS_STU_ARM_INT (INT_LVL_MAX+32*0+8)
#define INT_LVL_VIC_DBG_INT (INT_LVL_MAX+32*0+12)
#define INT_LVL_VIC_BBP_ERR_INT (INT_LVL_MAX+32*0+13)
#define INT_LVL_VIC_DBG_ANTEN_INT (INT_LVL_MAX+32*0+14)
#define INT_LVL_VIC_WDRX_DEEPSLEEP_FLAG (INT_LVL_MAX+32*0+20)
#define INT_LVL_VIC_G1_GDRX_DEEPSLEEP_FLAG (INT_LVL_MAX+32*0+21)
#define INT_LVL_VIC_CDRX_DEEPSLEEP_FLAG_1X (INT_LVL_MAX+32*0+22)
#define INT_LVL_VIC_CDRX_DEEPSLEEP_FLAG_EVDO (INT_LVL_MAX+32*0+23)
#define INT_LVL_VIC_CBBP_INTR01_2 (INT_LVL_MAX+32*0+28)
#define INT_LVL_VIC_CBBP_INTR02_2 (INT_LVL_MAX+32*0+29)
#define INT_LVL_VIC_CBBP_INTR04_2 (INT_LVL_MAX+32*0+30)
#define INT_LVL_VIC_PMU_IRQ_VIC0 (INT_LVL_MAX+32*0+31)
#define INT_LVL_VIC_G1_INT_BBP_TO_DSP (INT_LVL_MAX+32*1+0)
#define INT_LVL_VIC_G1_INT_BBP_TO_DSP_32K (INT_LVL_MAX+32*1+1)
#define INT_LVL_VIC_G1_INT_BBP_TO_CPU (INT_LVL_MAX+32*1+2)
#define INT_LVL_VIC_G1_INT_BBP_TO_CPU_32K (INT_LVL_MAX+32*1+3)
#define INT_LVL_VIC_G2_INT_BBP_TO_DSP (INT_LVL_MAX+32*1+4)
#define INT_LVL_VIC_G2_INT_BBP_TO_DSP_32K (INT_LVL_MAX+32*1+5)
#define INT_LVL_VIC_G2_INT_BBP_TO_CPU (INT_LVL_MAX+32*1+6)
#define INT_LVL_VIC_G2_INT_BBP_TO_CPU_32K (INT_LVL_MAX+32*1+7)
#define INT_LVL_VIC_ARM_INT01 (INT_LVL_MAX+32*1+8)
#define INT_LVL_VIC_ARM_INT02 (INT_LVL_MAX+32*1+9)
#define INT_LVL_VIC_ARM_INT03 (INT_LVL_MAX+32*1+10)
#define INT_LVL_VIC_ARM_INT04 (INT_LVL_MAX+32*1+11)
#define INT_LVL_VIC_ARM_INT05 (INT_LVL_MAX+32*1+12)
#define INT_LVL_VIC_ARM_INT06 (INT_LVL_MAX+32*1+13)
#define INT_LVL_VIC_ARM_INT07 (INT_LVL_MAX+32*1+14)
#define INT_LVL_VIC_ARM_INT08 (INT_LVL_MAX+32*1+15)
#define INT_LVL_VIC_ARM_INT09 (INT_LVL_MAX+32*1+16)
#define INT_LVL_VIC_ARM_INT10 (INT_LVL_MAX+32*1+17)
#define INT_LVL_VIC_ARM_INT11 (INT_LVL_MAX+32*1+18)
#define INT_LVL_VIC_CTU_INT_TDS_C (INT_LVL_MAX+32*1+19)
#define INT_LVL_VIC_CTU_INT_LTE (INT_LVL_MAX+32*1+20)
#define INT_LVL_VIC_CTU_INT_G1 (INT_LVL_MAX+32*1+21)
#define INT_LVL_VIC_CTU_INT_W (INT_LVL_MAX+32*1+22)
#define INT_LVL_VIC_CTU_INT_G2 (INT_LVL_MAX+32*1+23)
#define INT_LVL_VIC_UPACC_BBP_INT_I2 (INT_LVL_MAX+32*1+24)
#define INT_LVL_VIC_UPACC_BBP_INT_I1_E (INT_LVL_MAX+32*1+25)
#define INT_LVL_VIC_GUC_MST_INT_GRP (INT_LVL_MAX+32*1+26)
#define INT_LVL_VIC_COM_32K_INT (INT_LVL_MAX+32*1+27)
#define INT_LVL_VIC_CBBP_INT04 (INT_LVL_MAX+32*1+28)
#define INT_LVL_VIC_CBBP_INT02 (INT_LVL_MAX+32*1+29)
#define INT_LVL_VIC_CBBP_INT01 (INT_LVL_MAX+32*1+30)
#define INT_LVL_VIC_ARM_INT15 (INT_LVL_MAX+32*1+31)
#define INT_LVL_VIC_PCIE0_LINK_DOWN_INT (INT_LVL_MAX+32*2+0)
#define INT_LVL_VIC_PCIE0_EDMA_INT (INT_LVL_MAX+32*2+1)
#define INT_LVL_VIC_PCIE0_PM_INT (INT_LVL_MAX+32*2+2)
#define INT_LVL_VIC_PCIE0_RADM_INTA (INT_LVL_MAX+32*2+3)
#define INT_LVL_VIC_PCIE0_RADM_INTB (INT_LVL_MAX+32*2+4)
#define INT_LVL_VIC_PCIE0_RADM_INTC (INT_LVL_MAX+32*2+5)
#define INT_LVL_VIC_PCIE0_RADM_INTD (INT_LVL_MAX+32*2+6)
#define INT_LVL_VIC_EDMA_DMA_INTR0 (INT_LVL_MAX+32*2+10)
#define INT_LVL_VIC_EDMA_DMA_INTR1 (INT_LVL_MAX+32*2+11)
#define INT_LVL_VIC_EDMA_DMA_INTR2 (INT_LVL_MAX+32*2+12)
#define INT_LVL_VIC_EDMA_DMA_INTR3 (INT_LVL_MAX+32*2+13)
#define INT_LVL_VIC_EDMA_DMA_INTR4 (INT_LVL_MAX+32*2+14)
#define INT_LVL_VIC_EDMA_DMA_INTR5 (INT_LVL_MAX+32*2+15)
#define INT_LVL_VIC_HDLC_FRM_INT (INT_LVL_MAX+32*2+16)
#define INT_LVL_VIC_HDLC_DEF_INT (INT_LVL_MAX+32*2+17)
#define INT_LVL_VIC_CICOM_UL_INT (INT_LVL_MAX+32*2+18)
#define INT_LVL_VIC_CICOM_DL_INT (INT_LVL_MAX+32*2+19)
#define INT_LVL_VIC_EDMA_DMA_INTR_ns0 (INT_LVL_MAX+32*2+20)
#define INT_LVL_VIC_EDMA_DMA_INTR_ns1 (INT_LVL_MAX+32*2+21)
#define INT_LVL_VIC_EDMA_DMA_INTR_ns2 (INT_LVL_MAX+32*2+22)
#define INT_LVL_VIC_EDMA_DMA_INTR_ns3 (INT_LVL_MAX+32*2+23)
#define INT_LVL_VIC_EDMA_DMA_INTR_ns4 (INT_LVL_MAX+32*2+24)
#define INT_LVL_VIC_EDMA_DMA_INTR_ns5 (INT_LVL_MAX+32*2+25)
#define INT_LVL_VIC_PMU_IRQ_VIC2 (INT_LVL_MAX+32*2+31)
#define INT_LVL_VIC_PMU_IRQ_VIC3 (INT_LVL_MAX+32*3+31)
#define INT_LVL_GBBP_DSP INT_LVL_VIC_G1_INT_BBP_TO_DSP
#define INT_LVL_GBBP_GSML_NODRX_INTR 100000
#define INT_LVL_GBBP_AWAKE_DSP INT_LVL_VIC_G1_INT_BBP_TO_DSP_32K
#define INT_LVL_GBBP_GSML_RESERVED_INTR 100000
#define INT_LVL_GBBP INT_LVL_VIC_G1_INT_BBP_TO_CPU
#define INT_LVL_GBBP_AWAKE INT_LVL_VIC_G1_INT_BBP_TO_CPU_32K
#define INT_LVL_GBBP1_DSP INT_LVL_VIC_G2_INT_BBP_TO_DSP
#define INT_LVL_GBBP1_AWAKE_DSP INT_LVL_VIC_G2_INT_BBP_TO_DSP_32K
#define INT_LVL_GBBP1 INT_LVL_VIC_G2_INT_BBP_TO_CPU
#define INT_LVL_GBBP1_AWAKE INT_LVL_VIC_G2_INT_BBP_TO_CPU_32K
#define INT_LVL_WBBP_0MS INT_LVL_VIC_ARM_INT01
#define INT_LVL_WBBP_AWAKE INT_LVL_VIC_ARM_INT02
#define INT_LVL_WBBP_SWITCH INT_LVL_VIC_ARM_INT03
#define INT_LVL_WBBP1_0MS INT_LVL_VIC_ARM_INT04
#define INT_LVL_WBBP_CARD2_0MS_INTR INT_LVL_VIC_ARM_INT04
#define INT_LVL_WBBP_SEARCH INT_LVL_VIC_ARM_INT05
#define INT_LVL_WBBP_SEARCH_INTR INT_LVL_VIC_ARM_INT05
#define INT_LVL_WBBP_RAKE INT_LVL_VIC_ARM_INT06
#define INT_LVL_WBBP_RAKE_INTR INT_LVL_VIC_ARM_INT06
#define INT_LVL_WBBP_DECODE INT_LVL_VIC_ARM_INT07
#define INT_LVL_WBBP_DECODE_INTR INT_LVL_VIC_ARM_INT07
#define INT_LVL_WBBP_TIME INT_LVL_VIC_ARM_INT08
#define INT_LVL_WBBP_CARD1_TIME_INTR INT_LVL_VIC_ARM_INT08
#define INT_LVL_WBBP1_TIME INT_LVL_VIC_ARM_INT09
#define INT_LVL_WBBP_CARD2_TIME_INTR INT_LVL_VIC_ARM_INT09
#define INT_LVL_WBBP_MULTI_SEARCH INT_LVL_VIC_ARM_INT10
#define INT_LVL_WBBP_MULTI_SEARCH_INTR INT_LVL_VIC_ARM_INT10
#define INT_LVL_WBBP_BBPMST INT_LVL_VIC_ARM_INT11
#define INT_LVL_BBPMASTER INT_LVL_VIC_ARM_INT11
#define INT_LVL_CTU_INT_G INT_LVL_VIC_CTU_INT_G1
#define INT_LVL_CTU_INT_W INT_LVL_VIC_CTU_INT_W
#define INT_LVL_INT12_G2 100000
#define INT_LVL_GU_UPACC_DSP INT_LVL_VIC_UPACC_BBP_INT_I1_E
#define INT_LVL_UPACC_INTR INT_LVL_VIC_UPACC_BBP_INT_I1_E
#define INT_LVL_CICOM_DL INT_LVL_CICOM0_DL
#define INT_LVL_CICOM_UL INT_LVL_CICOM0_UL
#define INT_LVL_GU_CICOM1_DL INT_LVL_CICOM1_DL
#define INT_LVL_GU_CICOM1_UL INT_LVL_CICOM1_UL
#define INT_LVL_GU_HDLC_FRM INT_LVL_HDLC_FRM
#define INT_LVL_GU_HDLC_DEF INT_LVL_HDLC_DEF
#define INT_LVL_CBBP_INTR04 INT_LVL_CBBP_INTR04_2
#define INT_LVL_CBBP_INTR01 INT_LVL_CBBP_INTR01_2
#define INT_LVL_CBBP_INTR02 INT_LVL_CBBP_INTR02_2
#define INT_LVL_COMM_32K INT_LVL_VIC_COM_32K_INT
#define INT_LVL_LTE_ARM_WAKEUP_INT INT_LVL_LDRX2ARM_WAKEUP_INT
#define INT_LVL_TDS_DRX_ARM_WAKEUP_INT INT_LVL_TDRX2ARM_WAKEUP_INT
#define INT_LVL_BBPTIMER INT_LVL_VIC_LTE_ARM_POSITION_INT
#define INT_LVL_GUC_BBPMST_INT0 INT_LVL_VIC_GUC_MST_INT_GRP
#ifdef __cplusplus
}
#endif
#endif