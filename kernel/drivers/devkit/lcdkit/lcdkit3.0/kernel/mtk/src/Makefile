obj-$(CONFIG_LCD_KIT_MTK)	+= lcd_kit_disp.o
obj-$(CONFIG_LCD_KIT_MTK)	+= lcd_kit_power.o
obj-$(CONFIG_LCD_KIT_MTK) 	+= lcd_kit_utils.o
obj-$(CONFIG_LCD_KIT_MTK) 	+= lcd_kit_panel.o
obj-$(CONFIG_DRM_MEDIATEK) 	+= lcd_kit_drm_panel.o
obj-$(CONFIG_LCD_KIT_MTK) 	+= bias/
obj-$(CONFIG_LCD_KIT_MTK) 	+= backlight/

ifeq ($(TARGET_VERSION_MODE),factory)
EXTRA_CFLAGS += -DLCD_FACTORY_MODE
endif
EXTRA_CFLAGS +=-Idrivers/staging/android \
		-Idrivers/atfdriver \
		-Idrivers/devkit/lcdkit/lcdkit3.0 \
		-Idrivers/devkit/lcdkit/lcdkit3.0/kernel/common/include \
		-Idrivers/devkit/lcdkit/lcdkit3.0/kernel/mtk/include \
		-Idrivers/devkit/lcdkit/lcdkit3.0/kernel/mtk/adapt \
		-Idrivers/misc/mediatek/lcm/inc
ccflags-$(CONFIG_DRM_MEDIATEK) += -I$(srctree)/drivers/gpu/drm/ \
		-I$(srctree)/drivers/gpu/drm/mediatek/
