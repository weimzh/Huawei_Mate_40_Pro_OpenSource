
obj-$(CONFIG_USB_DWC3_NOV)		+= dwc3-nov.o hisi_usb2_bc.o
obj-$(CONFIG_USB_DWC3_OCT)		+= dwc3-oct.o hisi_usb2_bc.o
obj-$(CONFIG_USB_DWC3_SEP)		+= dwc3-sep.o hisi_usb2_bc.o
obj-$(CONFIG_USB_DWC3_AUG)		+= dwc3-aug.o hisi_usb2_bc.o
# hisi_usb3_31phy must before dwc3-plat(e.g mar,apr), module_init called base on the order in Makefile
obj-$(CONFIG_USB_DWC3_APR)		+= combophy_regcfg.o hisi_usb3_31phy_v2.o dwc3-apr.o hisi_usb3_bc.o hisi_usb3_misctrl.o
obj-$(CONFIG_USB_DWC3_MAR)		+= combophy_regcfg.o hisi_usb3_31phy.o dwc3-mar.o hisi_usb3_bc.o hisi_usb3_misctrl.o
obj-$(CONFIG_USB_DWC3_HISI)		+= dwc3-hisi.o hisi_usb_bc12.o hisi_usb_hw.o

obj-$(CONFIG_HISI_DEBUG_FS)		+= hisi_usb_debug.o

ifeq ($(CONFIG_HIFI_MAILBOX), y)
EXTRA_CFLAGS += -I$(srctree)/drivers/hisi/hifi_mailbox/mailbox
EXTRA_CFLAGS += -I$(srctree)/drivers/hisi/hifi_mailbox/ipcm
EXTRA_CFLAGS += -I$(srctree)/drivers/hisi/hifi_dsp
endif

ifneq ($(filter y,$(CONFIG_USB_DWC3_MAR) $(CONFIG_USB_DWC3_APR)),)
EXTRA_CFLAGS += -DCOMBOPHY_VERSION_1_1
EXTRA_CFLAGS += -DCOMBOPHY_FW_UPDATE
endif

hisi_combophy-y				+= combophy_common.o
hisi_combophy-$(CONFIG_HISI_COMBOPHY)	+= combophy_func.o combophy_core.o
hisi_combophy-$(CONFIG_USB_DWC3_MAR)	+= combophy.o
hisi_combophy-$(CONFIG_USB_DWC3_APR)	+= combophy.o
obj-$(CONFIG_CONTEXTHUB_PD)		+= hisi_combophy.o
