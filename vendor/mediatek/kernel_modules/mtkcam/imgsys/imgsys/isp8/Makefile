# SPDX-License-Identifier: GPL-2.0
#
# Copyright (C) 2018 MediaTek Inc.
#
include $(wildcard $(KERNEL_SRC)/$(DEVICE_MODULES_REL_DIR)/Makefile.include)

EXTRA_SYMBOLS += $(OUT_DIR)/../vendor/mediatek/kernel_modules/mtkcam/mtk-hcp/isp8/Module.symvers
EXTRA_SYMBOLS += $(OUT_DIR)/../vendor/mediatek/kernel_modules/mtkcam/imgsys/common/Module.symvers
EXTRA_SYMBOLS += $(OUT_DIR)/../vendor/mediatek/kernel_modules/mtkcam/imgsys/imgsys/cmdq/isp8/Module.symvers
EXTRA_SYMBOLS += $(OUT_DIR)/../vendor/mediatek/kernel_modules/mtkcam/mtk-ipesys-me/Module.symvers

modules modules_install clean:
	$(MAKE) -C $(KERNEL_SRC) M=$(M) $(KBUILD_OPTIONS) EXTRA_CFLAGS="$(EXTRA_CFLAGS)" KBUILD_EXTRA_SYMBOLS="$(EXTRA_SYMBOLS)" $(@)

# camellia LOS 23: relax warnings inherited from older base (AFTER any -Werror)
ccflags-y += -Wno-error=macro-redefined -Wno-error=unused-label -Wno-error=unused-variable -Wno-error=unused-function -Wno-error=implicit-function-declaration -Wno-error=incompatible-pointer-types -Wno-error=undef -Wno-error=vla -Wno-error=int-conversion -Wno-error=pointer-integer-compare
