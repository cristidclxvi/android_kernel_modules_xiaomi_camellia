ccflags-y += -Wno-error=macro-redefined -Wno-error=unused-label -Wno-error=unused-variable -Wno-error=unused-function -Wno-error=implicit-function-declaration -Wno-error=incompatible-pointer-types -Wno-error=undef -Wno-error=vla -Wno-error=int-conversion -Wno-error=pointer-integer-compare

THIS_COMPONENT = usb3

ifdef LINUX_DRV_ROOT
export DRV_ROOT = $(LINUX_DRV_ROOT)
else
export DRV_ROOT = $(TARGET_OPEN_ROOT)
endif


SRC = 

OBJ =

SUB_COMPONENTS = mt7668

OPTIONAL_SUB_COMPONENTS =

DEFINES +=

CC_INC += 


#############################################################################
#
# Include the makefile common to all components
#
#############################################################################

include $(DRV_ROOT)/driver.mak
