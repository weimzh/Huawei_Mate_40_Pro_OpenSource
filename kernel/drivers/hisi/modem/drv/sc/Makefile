ifeq ($(strip $(llt_gcov)),y)
GCOV_PROFILE := y
endif

KBUILD_CPPFLAGS += -Idrivers/hisi/modem/drv/nvim \
                   -Idrivers/hisi/modem/include/adrv
-include $(srctree)/drivers/hisi/modem/config/product/$(OBB_PRODUCT_NAME)/$(OBB_MODEM_CUST_CONFIG_DIR)/config/balong_product_config.mk

obj-y			+= sc_balong.o

subdir-ccflags-y := -Werror

