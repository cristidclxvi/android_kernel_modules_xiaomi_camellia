#
# Copyright (C) 2018 MediaTek Inc.
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

include $(wildcard $(KERNEL_SRC)/$(DEVICE_MODULES_REL_DIR)/Makefile.include)

modules modules_install clean:
	$(MAKE) -C $(KERNEL_SRC) M=$(M) $(KBUILD_OPTIONS) EXTRA_CFLAGS="$(EXTRA_CFLAGS)" KBUILD_EXTRA_SYMBOLS="$(EXTRA_SYMBOLS)" $(@)
# camellia LOS 23: relax warnings inherited from older base (AFTER any -Werror)
ccflags-y += -Wno-error=macro-redefined -Wno-error=unused-label -Wno-error=unused-variable -Wno-error=unused-function -Wno-error=implicit-function-declaration -Wno-error=incompatible-pointer-types -Wno-error=undef -Wno-error=vla -Wno-error=int-conversion -Wno-error=pointer-integer-compare
