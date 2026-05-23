/* SPDX-License-Identifier: GPL-2.0 */
/*
 * camellia LOS 23: minimal hqsysfs shim - Xiaomi hardware-info reporting
 * stub. Real implementation tracks hardware IDs for /sys/devices/. We
 * provide an empty stub since no consumers actually need the registered
 * info on our build (no MIUI services).
 */
#ifndef __HQ_SYSFS_HEAD__
#define __HQ_SYSFS_HEAD__

enum hardware_id {
	HWID_NONE = 0x00,
	HWID_AUDIO = 0x30,
	HWID_GSENSOR = 0x40,
};

static inline int hq_regiser_hw_info(enum hardware_id id, char *name)
{
	(void)id; (void)name;
	return 0;
}

#endif
