# SPDX-License-Identifier: GPL-2.0
# camellia LOS 23: vibrator driver for MT6833 platform (uses mt6853 subdir).
obj-$(CONFIG_MTK_VIBRATOR) := vibrator_drv.o
obj-$(CONFIG_MTK_VIBRATOR) += mt6853/

ccflags-y += -I$(srctree)/$(src)/mt6853
ccflags-y += -I$(DEVICE_MODULES_PATH)/drivers/misc/mediatek/include
ccflags-y += -I$(DEVICE_MODULES_PATH)/drivers/misc/mediatek/include/mt-plat
