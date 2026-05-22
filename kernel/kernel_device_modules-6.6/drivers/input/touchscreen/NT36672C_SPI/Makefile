# SPDX-License-Identifier: GPL-2.0
# NT36672C SPI touch driver for camellia (Xiaomi Redmi Note 10 5G)
#
# Lifted from MiCode/Xiaomi_Kernel_OpenSource camellia-r-oss; the SPI variant
# of the same NT36xxx driver core that OnePlus shipped as NT36672C_I2C.

ccflags-y += -I$(srctree)/drivers/misc/mediatek/include/mt-plat/
ccflags-y += -I$(srctree)/drivers/misc/mediatek/include/mt-plat/$(MTK_PLATFORM)/include/

obj-m += nt36672c_spi.o
nt36672c_spi-y += nt36xxx.o nt36xxx_fw_update.o nt36xxx_ext_proc.o nt36xxx_mp_ctrlram.o
