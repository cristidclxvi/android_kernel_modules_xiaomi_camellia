/* SPDX-License-Identifier: GPL-2.0 */
/*
 * camellia LOS 23 OPLUS compatibility stubs.
 *
 * The OnePlus modules tree (used as our 6.6 modules base) was authored with
 * extensive OPLUS_* preprocessor gating. After unifdef-stripping those macros,
 * dangling references to oplus_* functions/structs remain in unguarded code paths.
 *
 * This header provides minimal stub implementations so the build proceeds.
 * Stubs return "feature unsupported" so surrounding code takes its non-OPLUS branch.
 *
 * Force-included via subdir-ccflags-y += -include <camellia/oplus_compat.h>.
 */
#ifndef __CAMELLIA_OPLUS_COMPAT_H__
#define __CAMELLIA_OPLUS_COMPAT_H__

#include <linux/types.h>

/* Backlight / display apollo path always unsupported on camellia */
static inline int oplus_apollo_unsupported(void) { return 1; }

/* MTK charger OPLUS interface  -  stub as NULL so guarded code blocks no-op.
 * Used in mt6360_pmu_chg.c and related charger files.
 */
struct mtk_oplus_chg_interface {
	void (*wake_update_work)(void);
	void (*set_charger_type_unknown)(void);
	void (*set_otg_online)(bool online);
	int  (*get_charger_type)(void);
};
#define g_oplus_chg_intf ((struct mtk_oplus_chg_interface *)NULL)


/* Display ADFR/MFR mode tags: hskew sentinel values, never match real modes. */
#ifndef OPLUS_ADFR
#define OPLUS_ADFR (-1)
#endif
#ifndef OPLUS_MFR
#define OPLUS_MFR (-2)
#endif


/* OPLUS display panel param field rename (camellia struct has versioned name) */
#define oplus_display_lcd_tp_aod oplus_display_lcd_6382_aod

/* DRM LCM command helpers - stubbed; real impl was inside stripped OPLUS block.
 * Real impl probably packs/flushes a cmdq. For camellia we no-op; panel works
 * via the standard mtk_dsi path. */
struct drm_crtc;
struct cmdq_pkt;
static inline void mtk_drm_send_lcm_cmd_prepare(struct drm_crtc *crtc, struct cmdq_pkt **handle) {}
static inline void mtk_drm_send_lcm_cmd_flush(struct drm_crtc *crtc, struct cmdq_pkt **handle, int sync) {}


/* mtk_dsi silence-mode and DSI/LCM control enums - OPLUS additions to standard MTK. */
#define silence_mode  (0L)        /* always off on camellia */
#define silence_flag  silence_flag_dummy_v
static long silence_flag_dummy_v;
#define DSI_SET_BL_RECOVERY  (0xFFFE1)   /* sentinel - no case body matches */
#define LCM_CABC             (0xFFFE2)


/* Camera image-sensor vendor IDs and manufacturer strings.
 * Defined in OPLUS subdir which we are not compiling; the MTK common code
 * references them so we provide the canonical values here. */
#define IMGSENSOR_MODULE_ID_SUNNY    0x01
#define IMGSENSOR_MODULE_ID_TRULY    0x02
#define IMGSENSOR_MODULE_ID_SEMCO    0x03
#define IMGSENSOR_MODULE_ID_LITEON   0x04
#define IMGSENSOR_MODULE_ID_QTECH    0x05
#define IMGSENSOR_MODULE_ID_OFILM    0x06
#define IMGSENSOR_MODULE_ID_SHINE    0x07
#define IMGSENSOR_MODULE_ID_HLT      0x08
#define DEVICE_MANUFACUTRE_SUNNY     "Sunny"
#define DEVICE_MANUFACUTRE_TRULY     "Truly"
#define DEVICE_MANUFACUTRE_SEMCO     "Semco"
#define DEVICE_MANUFACUTRE_LITEON    "LiteOn"
#define DEVICE_MANUFACUTRE_QTECH     "QTech"
#define DEVICE_MANUFACUTRE_OFILM     "OFilm"
#define DEVICE_MANUFACUTRE_SHINE     "Shine"
#define DEVICE_MANUFACUTRE_HLT       "HLT"
#define DEVICE_MANUFACUTRE_NA        "NA"



/* OPLUS scheduler / performance hooks - providers in kernel/oplus_cpu disabled. */
#define mtk_rearrange_pipeline_preferred_cpus(...)  do { } while (0)
#define cb_ceiling_free_enable(...)                 do { } while (0)
#define update_ux_sched_cputopo(...)                do { } while (0)
#define android_rvh_dequeue_task_handler(...)       do { } while (0)
#define cb_update(...)                              do { } while (0)
#define __oplus_tick_balance(...)                   (0)
#define test_task_overload(...)                     do { } while (0)
#define android_rvh_after_enqueue_task_handler(...) do { } while (0)
#define android_rvh_schedule_handler(...)           do { } while (0)
#define sa_skip_rt_sync(...)                        do { } while (0)


/* Remaining OPLUS hooks from final modpost batch. */
#define oplus_update_tg_map(css)            do { (void)(css); } while (0)
#define soc_codec_conf_sia91xx(pdev, card)  do { (void)(pdev); (void)(card); } while (0)

#endif /* __CAMELLIA_OPLUS_COMPAT_H__ */
