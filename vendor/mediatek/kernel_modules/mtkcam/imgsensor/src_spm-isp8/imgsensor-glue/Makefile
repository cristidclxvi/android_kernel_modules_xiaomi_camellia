# SPDX-License-Identifier: GPL-2.0
# Copyright (C) 2021 MediaTek Inc.

obj-$(CONFIG_MTK_V4L2_IMGSENSOR) += imgsensor-glue_spm_isp8.o

imgsensor-glue_spm_isp8-objs :=
imgsensor-glue_spm_isp8-objs += \
	imgsensor-glue.o \

$(info imgsensor-virt-sensor-objs : $(obj-$(CONFIG_MTK_V4L2_IMGSENSOR)))

# camellia LOS 23: relax warnings inherited from older base (AFTER any -Werror)
ccflags-y += -Wno-error=macro-redefined -Wno-error=unused-label -Wno-error=unused-variable -Wno-error=unused-function -Wno-error=implicit-function-declaration -Wno-error=incompatible-pointer-types -Wno-error=undef -Wno-error=vla -Wno-error=int-conversion -Wno-error=pointer-integer-compare
