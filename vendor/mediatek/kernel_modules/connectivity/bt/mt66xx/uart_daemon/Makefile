LAUNCHER_SDIO=uart_launcher
LAUNCHER_SDIO_SRC=uart_launcher.c

all: $(LAUNCHER_SDIO)

$(LAUNCHER_SDIO):
	$(CC) -o $(LAUNCHER_SDIO) $(LAUNCHER_SDIO_SRC)

clean:
	rm $(LAUNCHER_UART) ${LAUNCHER_SDIO}

# camellia LOS 23: relax warnings inherited from older base (AFTER any -Werror)
ccflags-y += -Wno-error=macro-redefined -Wno-error=unused-label -Wno-error=unused-variable -Wno-error=unused-function -Wno-error=implicit-function-declaration -Wno-error=incompatible-pointer-types -Wno-error=undef -Wno-error=vla -Wno-error=int-conversion -Wno-error=pointer-integer-compare
