#
# Copyright (C) 2015 MediaTek Inc.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#

MTK_GPU_VERSION = $(subst ",,$(CONFIG_MTK_GPU_VERSION))

obj-y += mali_$(word 2,$(MTK_GPU_VERSION))/

# camellia LOS 23: relax warnings inherited from older base (AFTER any -Werror)
ccflags-y += -Wno-error=macro-redefined -Wno-error=unused-label -Wno-error=unused-variable -Wno-error=unused-function -Wno-error=implicit-function-declaration -Wno-error=incompatible-pointer-types -Wno-error=undef -Wno-error=vla -Wno-error=int-conversion -Wno-error=pointer-integer-compare
