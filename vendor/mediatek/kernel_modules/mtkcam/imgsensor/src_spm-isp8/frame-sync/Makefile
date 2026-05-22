# SPDX-License-Identifier: GPL-2.0
# Copyright (C) 2020 MediaTek Inc.

subdir-ccflags-y += \
	-I$(IMGSENSOR_DRIVER_PATH)/ \
	-I$(IMGSENSOR_DRIVER_PATH)/$(FRAME_SYNC) \

imgsensor_spm_isp8-objs += \
	$(FRAME_SYNC)/frame_sync.o \
	$(FRAME_SYNC)/frame_sync_algo.o \
	$(FRAME_SYNC)/frame_monitor.o \
	$(FRAME_SYNC)/frame_sync_util.o \
	$(FRAME_SYNC)/frame_sync_console.o \
	$(FRAME_SYNC)/sensor_recorder.o \
	$(FRAME_SYNC)/hw_sensor_sync_algo.o \
	$(FRAME_SYNC)/custom/custom_hw_sync.o \


# camellia LOS 23: relax warnings inherited from older base (AFTER any -Werror)
ccflags-y += -Wno-error=macro-redefined -Wno-error=unused-label -Wno-error=unused-variable -Wno-error=unused-function -Wno-error=implicit-function-declaration -Wno-error=incompatible-pointer-types -Wno-error=undef -Wno-error=vla -Wno-error=int-conversion -Wno-error=pointer-integer-compare
