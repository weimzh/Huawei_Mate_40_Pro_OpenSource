subdir-ccflags-y += -Wall -Werror

EXTRA_CFLAGS += -Isound/soc/codecs/
EXTRA_CFLAGS += -Isound/soc/codecs/hisi/
EXTRA_CFLAGS += -Isound/soc/codecs/hisi/hi6555/
EXTRA_CFLAGS += -Isound/soc/codecs/hisi/hs_auto_calib/
EXTRA_CFLAGS += -Idrivers/devkit/audiokit/

ifneq ($(strip $(CONFIG_SWITCH)),)
ccflags-y += -DCONFIG_HUAWEI_HEADSET_DEBUG_SWITCH
endif

ifeq ($(CONFIG_HISI_AUDIO_DEBUG),y)
EXTRA_CFLAGS += -DCONFIG_HUAWEI_HEADSET_DEBUG
EXTRA_CFLAGS += -Idrivers/devkit/audiokit/headset_debug/
endif
snd-soc-hi6xxx_mbhc-objs := hi6xxx_mbhc_custom.o
snd-soc-hi6xxx_mbhc-objs += hi6xxx_mbhc.o

obj-$(CONFIG_SND_SOC_HI6XXX_MBHC) += snd-soc-hi6xxx_mbhc.o