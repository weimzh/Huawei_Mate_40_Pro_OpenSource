# SPDX-License-Identifier: GPL-2.0
#
# Generic framework for controlling remote processors
#

obj-$(CONFIG_REMOTEPROC)		+= remoteproc.o
remoteproc-y				:= remoteproc_core.o
remoteproc-y				+= remoteproc_debugfs.o
remoteproc-y				+= remoteproc_sysfs.o
remoteproc-y				+= remoteproc_virtio.o
remoteproc-y				+= remoteproc_elf_loader.o
obj-$(CONFIG_HISI_REMOTEPROC)		+= hisp_remoteproc.o bin_loader.o
obj-$(CONFIG_IMX_REMOTEPROC)		+= imx_rproc.o
obj-$(CONFIG_OMAP_REMOTEPROC)		+= omap_remoteproc.o
obj-$(CONFIG_WKUP_M3_RPROC)		+= wkup_m3_rproc.o
obj-$(CONFIG_DA8XX_REMOTEPROC)		+= da8xx_remoteproc.o
obj-$(CONFIG_KEYSTONE_REMOTEPROC)	+= keystone_remoteproc.o
obj-$(CONFIG_QCOM_ADSP_PIL)		+= qcom_adsp_pil.o
obj-$(CONFIG_QCOM_RPROC_COMMON)		+= qcom_common.o
obj-$(CONFIG_QCOM_Q6V5_PIL)		+= qcom_q6v5_pil.o
obj-$(CONFIG_QCOM_WCNSS_PIL)		+= qcom_wcnss_pil.o
qcom_wcnss_pil-y			+= qcom_wcnss.o
qcom_wcnss_pil-y			+= qcom_wcnss_iris.o
obj-$(CONFIG_ST_REMOTEPROC)		+= st_remoteproc.o
ifeq ($(CONFIG_HISI_ISP_DEBUG), y)
	subdir-ccflags-y += -DDEBUG_HISI_ISP
endif
ifeq ($(CONFIG_HISI_ISP_SMMU_BYPASS_DEBUG), y)
	subdir-ccflags-y += -DISP_DEBUG_MMU_BYPASS
endif
