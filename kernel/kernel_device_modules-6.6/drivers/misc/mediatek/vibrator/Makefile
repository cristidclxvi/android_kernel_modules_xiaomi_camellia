# SPDX-License-Identifier: GPL-2.0
# camellia LOS 23: always use mt6853 subdir for MT6833 platform
obj-$(CONFIG_MTK_VIBRATOR) := vibrator_drv.o
obj-$(CONFIG_MTK_VIBRATOR) += mt6853/
ccflags-y += -I$(srctree)/$(src)/mt6853
