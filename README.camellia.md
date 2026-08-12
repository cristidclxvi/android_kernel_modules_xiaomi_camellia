# camellia branch

Branch `lineage-23.2` builds the MediaTek connectivity kernel modules (WiFi,
Bluetooth, GPS, FM) from source for the Xiaomi Redmi Note 10 5G / POCO M3 Pro
5G (`camellia`, MT6833) on LineageOS 23.2.

It branches from `oneplus/mt6833_s_12.1_oneplus_n300` at
`bf43f506736c522fccde2e67a86bcb3a18056df9`. That branch targets the same SoC
and the same kernel sublevel (4.14.186) camellia runs, which is why it is the
base rather than any of the newer OnePlus drops. Only
`vendor/mediatek/kernel_modules/connectivity` is used; the rest of the tree is
OnePlus platform code camellia does not have hardware for.

Everything camellia-specific is a single commit on top of that base, kept as
one reviewable diff so it stays easy to rebase onto a newer upstream drop.

`android-16-camellia` is unrelated: it is an abandoned attempt to port a 6.6
kernel from a much newer OnePlus branch, and nothing here depends on it.

## Why build these from source

They used to be prebuilt `.ko` extracted from the stock ROM. Two problems with
that. Shipping GPL modules as binaries with no source is not something a
custom ROM should do. And the prebuilts pinned the kernel: each module carries
CRCs for every symbol it imports, so any kernel change that moved
`module_layout` stopped all of them loading at once. Measured against a
4.14.357 build, all seven prebuilts failed, gen4m with 129 symbol mismatches.
Built from source they all pass, which is what makes a kernel bump possible at
all.

## What the camellia commit changes

LineageOS builds these through `TARGET_KERNEL_EXT_MODULES`, which runs
`make -C <kernel> M=<dir> modules_install` per module and passes no
per-module flags. Anything a single driver needs has to live in its own
Makefile.

| Change | Why |
|---|---|
| Force `MODULE_NAME` | gen4m derives `wlan_6833_axi` from chip id and HIF, but `init.wlan_drv.rc` loads `wlan_drv_gen4m.ko`. The WiFi adaptor never sets it and emits a nameless `.ko`. |
| `BT_PLATFORM ?= connac1x` | CONSYS_6833 is CONNAC1 and never populates `_MTK_BT_CHIP`, so it built as `bt_drv_.ko`. |
| `CFG_FM_PLAT ?= mt6631_6635` | fmradio only receives this when its top-level wrapper recurses; a direct build produced `fmradio_drv_.ko`. |
| Per-module `KBUILD_EXTRA_SYMBOLS` | gen4m imports from `wmt_drv` and `wmt_chrdev_wifi`; bt, gps and fmradio from `wmt_drv`. Without it modpost fails on unresolved symbols. |
| `-I$(src)` to `-I$(srctree)/$(src)` | The kernel build passes `M=` relative to the kernel source while the compiler runs from the kernel output directory, so the bare form resolved against the wrong base and modules could not find their own headers. |
| Drop `soc/oplus/system/oplus_project.h` | Does not exist outside a OnePlus tree. See below. |

### The regulatory-domain change

`mgmt/rlm_domain.c` included a OnePlus header for `get_project()`. Every use
of it indexes a table keyed by OnePlus internal project IDs, purely to
*override* the MediaTek default TX power-limit table already assigned
immediately above. No camellia device can appear in those tables, so a stub
that never matches leaves the MediaTek defaults in force. That is the correct
behaviour here, and stubbing rather than deleting keeps the file close to
upstream.

## Build order

Order matters, because of the symbol dependencies:

```
common -> connfem -> wlan/adaptor -> wlan/core/gen4m
       -> bt/mt66xx/wmt -> gps -> fmradio/Build/mt6631_6635
```

`fmradio/Build/mt6631_6635` is a symlink to `..`, so relative paths inside it
resolve physically from `fmradio`.

## Verified

Built against kernel 4.14.186 and flashed to a Redmi Note 10 5G. All seven
modules load, WiFi associates on both 2.4 and 5 GHz with the country code
reaching the driver, and Bluetooth, GPS and FM work. Dropping the last
prebuilt also cleared `TAINT_PROPRIETARY_MODULE` from the running kernel.

## Licence

GPL-2.0, as the upstream MediaTek sources.
