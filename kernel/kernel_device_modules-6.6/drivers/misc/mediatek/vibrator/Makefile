# SPDX-License-Identifier: GPL-2.0
# camellia LOS 23: vibrator built as one composed module mtk_vibrator.ko
obj-$(CONFIG_MTK_VIBRATOR) := mtk_vibrator.o
mtk_vibrator-y := vibrator_drv.o mt6853/vibrator.o

ccflags-y += -I$(srctree)/$(src)/mt6853
ccflags-y += -I$(DEVICE_MODULES_PATH)/drivers/misc/mediatek/include
ccflags-y += -I$(DEVICE_MODULES_PATH)/drivers/misc/mediatek/include/mt-plat
