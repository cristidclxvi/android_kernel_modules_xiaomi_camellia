// SPDX-License-Identifier: GPL-2.0
/*
 * Weak no-op stubs for camellia LOS 23 - replaces OPLUS device-info hooks
 * and disabled OplusImgsensor providers. Real implementations will land in
 * Phase 2 (camellia hardware grafting).
 */
#include <linux/module.h>
#include <linux/types.h>

#include "imgsensor_hw.h"

/* OPLUS device-info module hooks - return release-mode defaults. */
unsigned int get_eng_version(void) { return 0; }
EXPORT_SYMBOL_GPL(get_eng_version);

unsigned int is_project(int project) { return 0; }
EXPORT_SYMBOL_GPL(is_project);

void register_device_proc(char *name, char *version, char *manufacture)
{
	(void)name; (void)version; (void)manufacture;
}
EXPORT_SYMBOL_GPL(register_device_proc);

void register_device_proc_for_emmc(char *name, char *version, char *manufacture)
{
	(void)name; (void)version; (void)manufacture;
}
EXPORT_SYMBOL_GPL(register_device_proc_for_emmc);

/* OplusImgsensor hooks (disabled subdir) - no-op until Phase 2 grafts a real
 * camellia camera HAL. */
void Oplusimgsensor_powerstate_notify(bool val) { (void)val; }
EXPORT_SYMBOL_GPL(Oplusimgsensor_powerstate_notify);

void oplus_imgsensor_hwcfg(void) { }
EXPORT_SYMBOL_GPL(oplus_imgsensor_hwcfg);

/* Camera power-sequence tables - empty terminators. Phase 2 must replace
 * these with camellia-specific entries from the stock 4.19 source. */
struct IMGSENSOR_HW_POWER_SEQ platform_power_sequence_for_mipi_switch[] = {
	{ NULL, { {0, 0, 0} }, 0 }
};
EXPORT_SYMBOL_GPL(platform_power_sequence_for_mipi_switch);

struct IMGSENSOR_HW_POWER_SEQ platform_power_sequence_for_mt6833[] = {
	{ NULL, { {0, 0, 0} }, 0 }
};
EXPORT_SYMBOL_GPL(platform_power_sequence_for_mt6833);

MODULE_LICENSE("GPL v2");
