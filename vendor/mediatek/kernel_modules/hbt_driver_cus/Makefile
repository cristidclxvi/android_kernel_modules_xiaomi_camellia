modules:
	$(MAKE) -C $(KERNEL_SRC) M=$(M) $(KBUILD_OPTIONS) KBUILD_EXTRA_SYMBOLS="$(EXTRA_SYMBOLS)" $(@)
ifneq (,$(wildcard hbt_driver/Makefile))
	$(MAKE) -C $(KERNEL_SRC) M=$(M)/hbt_driver $(KBUILD_OPTIONS) KBUILD_EXTRA_SYMBOLS="$(EXTRA_SYMBOLS)" $(@)
	cp -r $(O)/$(M)/hbt_driver/*.ko $(O)/$(M)/*.ko
endif

modules_install:
ifneq (,$(wildcard hbt_driver/Makefile))
	$(MAKE) -C $(KERNEL_SRC) M=$(M)/hbt_driver $(KBUILD_OPTIONS) KBUILD_EXTRA_SYMBOLS="$(EXTRA_SYMBOLS)" $(@)
else
	$(MAKE) -C $(KERNEL_SRC) M=$(M) $(KBUILD_OPTIONS) KBUILD_EXTRA_SYMBOLS="$(EXTRA_SYMBOLS)" $(@)
endif

clean:
	$(MAKE) -C $(KERNEL_SRC) M=$(M) $(KBUILD_OPTIONS) KBUILD_EXTRA_SYMBOLS="$(EXTRA_SYMBOLS)" $(@)
ifneq (,$(wildcard hbt_driver/Makefile))
	$(MAKE) -C $(KERNEL_SRC) M=$(M)/hbt_driver $(KBUILD_OPTIONS) KBUILD_EXTRA_SYMBOLS="$(EXTRA_SYMBOLS)" $(@)
endif

# camellia LOS 23: relax warnings inherited from older base (AFTER any -Werror)
ccflags-y += -Wno-error=macro-redefined -Wno-error=unused-label -Wno-error=unused-variable -Wno-error=unused-function -Wno-error=implicit-function-declaration -Wno-error=incompatible-pointer-types -Wno-error=undef -Wno-error=vla -Wno-error=int-conversion -Wno-error=pointer-integer-compare
