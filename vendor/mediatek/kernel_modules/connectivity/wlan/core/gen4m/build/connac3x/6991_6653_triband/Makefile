# SPDX-License-Identifier: BSD-2-Clause
KO_CODE_PATH := $(if $(filter /%,$(src)),,$(srctree)/)$(src)

_CONNAC_VER := 3_0
_CONNAC_DENPENDENCY_SYMBOLS := wlan/adaptor/build/connac3x/Module.symvers
_MODULE_NAME := wlan_drv_gen4m_6991_6653_triband

$(info M=$(M))
$(info Kernel src=$(KERNEL_SRC))

include $(KERNEL_SRC)/$(M)/../../../Makefile

# camellia LOS 23: relax warnings inherited from older base (AFTER any -Werror)
ccflags-y += -Wno-error=macro-redefined -Wno-error=unused-label -Wno-error=unused-variable -Wno-error=unused-function -Wno-error=implicit-function-declaration -Wno-error=incompatible-pointer-types -Wno-error=undef -Wno-error=vla -Wno-error=int-conversion -Wno-error=pointer-integer-compare
