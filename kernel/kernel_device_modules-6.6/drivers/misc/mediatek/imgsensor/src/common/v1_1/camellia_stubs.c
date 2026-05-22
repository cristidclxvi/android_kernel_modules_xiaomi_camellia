// SPDX-License-Identifier: GPL-2.0
/*
 * Weak no-op stubs for camellia LOS 23 - replaces OPLUS device-info hooks
 * and disabled OplusImgsensor providers. Real implementations will land in
 * Phase 2 (camellia hardware grafting).
 */
#include <linux/module.h>
#include <linux/types.h>

#include "imgsensor_hw.h"

/* For oplus_update_tg_map */
struct cgroup_subsys_state;

/* For soc_codec_conf_sia91xx */
struct platform_device;
struct snd_soc_card;

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


/* Board / project ID hooks from include/soc/oplus/boot/oplus_project.h.
 * Provider was drivers/soc/oplus/boot which is disabled.
 * Return 0/empty defaults until Phase 2 wires the camellia board IDs. */
unsigned int get_PCB_Version(void) { return 0; }
EXPORT_SYMBOL_GPL(get_PCB_Version);

unsigned int get_project(void)         { return 0; }
EXPORT_SYMBOL_GPL(get_project);

unsigned int get_prj(void)             { return 0; }
EXPORT_SYMBOL_GPL(get_prj);

unsigned int get_Oplus_Boot_Mode(void) { return 0; }
EXPORT_SYMBOL_GPL(get_Oplus_Boot_Mode);

unsigned int get_audio(void)           { return 0; }
EXPORT_SYMBOL_GPL(get_audio);

unsigned int get_dtsiNo(void)          { return 0; }
EXPORT_SYMBOL_GPL(get_dtsiNo);


/* OPLUS scheduler task-group hook - provider kernel/oplus_cpu disabled. */
void oplus_update_tg_map(struct cgroup_subsys_state *css) { (void)css; }
EXPORT_SYMBOL_GPL(oplus_update_tg_map);

/* SI-PA audio smart-amp - not on camellia, return 0 (no codec added). */
int soc_codec_conf_sia91xx(struct platform_device *pdev, struct snd_soc_card *card)
{
	(void)pdev; (void)card; return 0;
}
EXPORT_SYMBOL_GPL(soc_codec_conf_sia91xx);

MODULE_LICENSE("GPL v2");
