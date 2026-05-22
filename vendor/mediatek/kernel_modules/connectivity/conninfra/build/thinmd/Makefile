ccflags-y += -Wno-error=macro-redefined -Wno-error=unused-label -Wno-error=unused-variable -Wno-error=unused-function -Wno-error=implicit-function-declaration -Wno-error=incompatible-pointer-types -Wno-error=undef -Wno-error=vla -Wno-error=int-conversion -Wno-error=pointer-integer-compare

$(info M=$(M))
$(info Kernel src=$(KERNEL_SRC))

#EXTRA_SYMBOLS += $(OUT_DIR)/../vendor/mediatek/kernel_modules/wwan/tmi3/Module.symvers
$(info conninfra_thinmd_makefile $$EXTRA_SYMBOLS=[${EXTRA_SYMBOLS}])

_FSM_DENPENDENCY_SYMBOLS := $(OUT_DIR)/../vendor/mediatek/kernel_modules/wwan/tmi3/Module.symvers
$(info conninfra_thinmd_makefile $$_FSM_DENPENDENCY_SYMBOLS=[${_FSM_DENPENDENCY_SYMBOLS}])

include $(KERNEL_SRC)/$(M)/../../Makefile

