ifdef CONFIG_HISI_UEFI_HHEE
obj-$(CONFIG_HISI_HHEE)         += hvc.o rodata.o
else
obj-$(CONFIG_HISI_HHEE)         += hvc.o rodata.o critdata.o xodata.o
endif

obj-$(CONFIG_HISI_UEFI_HHEE)    += vmmu_enable.o hkip_uefi.o
