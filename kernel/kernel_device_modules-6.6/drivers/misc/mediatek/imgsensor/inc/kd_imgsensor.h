/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019 MediaTek Inc.
 */

#ifndef _KD_IMGSENSOR_H
#define _KD_IMGSENSOR_H

#define OPLUS_FEATURE_CAMERA_COMMON

#include <linux/ioctl.h>
#include <linux/i3c/device.h>

#ifndef ASSERT
#define ASSERT(expr)        WARN_ON(!(expr))
#endif

#define IMGSENSORMAGIC 'i'
/* IOCTRL(inode * ,file * ,cmd ,arg ) */
/* S means "set through a ptr" */
/* T means "tell by a arg value" */
/* G means "get by a ptr" */
/* Q means "get by return a value" */
/* X means "switch G and S atomically" */
/* H means "switch T and Q atomically" */

/******************************************************************************
 *
 ******************************************************************************/

/* sensorOpen */
#define KDIMGSENSORIOC_T_OPEN \
	_IO(IMGSENSORMAGIC, 0)
/* sensorGetInfo */
#define KDIMGSENSORIOC_X_GET_CONFIG_INFO \
	_IOWR(IMGSENSORMAGIC, 5, struct IMGSENSOR_GET_CONFIG_INFO_STRUCT)

#define KDIMGSENSORIOC_X_GETINFO \
	_IOWR(IMGSENSORMAGIC, 5, struct ACDK_SENSOR_GETINFO_STRUCT)
/* sensorGetResolution */
#define KDIMGSENSORIOC_X_GETRESOLUTION \
	_IOWR(IMGSENSORMAGIC, 10, struct ACDK_SENSOR_RESOLUTION_INFO_STRUCT)
/* For kernel 64-bit */
#define KDIMGSENSORIOC_X_GETRESOLUTION2 \
	_IOWR(IMGSENSORMAGIC, 10, struct ACDK_SENSOR_PRESOLUTION_STRUCT)
/* sensorFeatureControl */
#define KDIMGSENSORIOC_X_FEATURECONCTROL \
	_IOWR(IMGSENSORMAGIC, 15, struct ACDK_SENSOR_FEATURECONTROL_STRUCT)
/* sensorControl */
#define KDIMGSENSORIOC_X_CONTROL \
	_IOWR(IMGSENSORMAGIC, 20, struct ACDK_SENSOR_CONTROL_STRUCT)
/* sensorClose */
#define KDIMGSENSORIOC_T_CLOSE \
	_IO(IMGSENSORMAGIC, 25)
/* sensorSearch */
#define KDIMGSENSORIOC_T_CHECK_IS_ALIVE \
	_IO(IMGSENSORMAGIC, 30)
/* set sensor driver */
#define KDIMGSENSORIOC_X_SET_DRIVER \
	_IOWR(IMGSENSORMAGIC, 35, struct SENSOR_DRIVER_INDEX_STRUCT)
/* get socket postion */
#define KDIMGSENSORIOC_X_GET_SOCKET_POS \
	_IOWR(IMGSENSORMAGIC, 40, u32)
/* set I2C bus */
#define KDIMGSENSORIOC_X_SET_I2CBUS \
	_IOWR(IMGSENSORMAGIC, 45, u32)
/* set I2C bus */
#define KDIMGSENSORIOC_X_RELEASE_I2C_TRIGGER_LOCK \
	_IO(IMGSENSORMAGIC, 50)
/* Set Shutter Gain Wait Done */
#define KDIMGSENSORIOC_X_SET_SHUTTER_GAIN_WAIT_DONE \
	_IOWR(IMGSENSORMAGIC, 55, u32)
/* set mclk */
#define KDIMGSENSORIOC_X_SET_MCLK_PLL \
	_IOWR(IMGSENSORMAGIC, 60, struct ACDK_SENSOR_MCLK_STRUCT)
#define KDIMGSENSORIOC_X_GETINFO2 \
	_IOWR(IMGSENSORMAGIC, 65, struct IMAGESENSOR_GETINFO_STRUCT)
/* set open/close sensor index */
#define KDIMGSENSORIOC_X_SET_CURRENT_SENSOR \
	_IOWR(IMGSENSORMAGIC, 70, u32)
/* set GPIO */
#define KDIMGSENSORIOC_X_SET_GPIO \
	_IOWR(IMGSENSORMAGIC, 75, struct IMGSENSOR_GPIO_STRUCT)
/* Get ISP CLK */
#define KDIMGSENSORIOC_X_GET_ISP_CLK \
	_IOWR(IMGSENSORMAGIC, 80, u32)
/* Get CSI CLK */
#define KDIMGSENSORIOC_X_GET_CSI_CLK \
	_IOWR(IMGSENSORMAGIC, 85, u32)

/* Get ISP CLK via MMDVFS*/
#define KDIMGSENSORIOC_DFS_UPDATE \
	_IOWR(IMGSENSORMAGIC, 90, unsigned int)
#define KDIMGSENSORIOC_GET_SUPPORTED_ISP_CLOCKS \
	_IOWR(IMGSENSORMAGIC, 95, struct IMAGESENSOR_GET_SUPPORTED_ISP_CLK)
#define KDIMGSENSORIOC_GET_CUR_ISP_CLOCK \
	_IOWR(IMGSENSORMAGIC, 100, unsigned int)

#ifdef CONFIG_COMPAT
#define COMPAT_KDIMGSENSORIOC_X_GET_CONFIG_INFO \
	_IOWR(IMGSENSORMAGIC, 5, struct COMPAT_IMGSENSOR_GET_CONFIG_INFO_STRUCT)

#define COMPAT_KDIMGSENSORIOC_X_GETINFO \
	_IOWR(IMGSENSORMAGIC, 5, struct COMPAT_ACDK_SENSOR_GETINFO_STRUCT)
#define COMPAT_KDIMGSENSORIOC_X_FEATURECONCTROL \
	_IOWR(IMGSENSORMAGIC, 15, \
		struct COMPAT_ACDK_SENSOR_FEATURECONTROL_STRUCT)
#define COMPAT_KDIMGSENSORIOC_X_CONTROL \
	_IOWR(IMGSENSORMAGIC, 20, struct COMPAT_ACDK_SENSOR_CONTROL_STRUCT)
#define COMPAT_KDIMGSENSORIOC_X_GETINFO2 \
	_IOWR(IMGSENSORMAGIC, 65, struct COMPAT_IMAGESENSOR_GETINFO_STRUCT)
#define COMPAT_KDIMGSENSORIOC_X_GETRESOLUTION2 \
	_IOWR(IMGSENSORMAGIC, 10, struct COMPAT_ACDK_SENSOR_PRESOLUTION_STRUCT)
#endif

/*****************************************
 * Transfer SENSOR PID to I3C DEVICE INFO
 * I3C_DEVICE:
 *	Para1: manuf_id = PID[47:33]
 *	Para2: part_id = PID[31:16]
 *	Para3: data = NULL
 *****************************************/
#define PID_TO_I3C_DEV(_pid)  I3C_DEVICE ((_pid>>33), ((_pid>>16)&0xFFFF), (void *)NULL)

/************************************************************************
 *
 ************************************************************************/
#define HI1339_SENSOR_ID                          0x1339
#define SENSOR_DRVNAME_HI1339_MIPI_RAW            "hi1339_mipi_raw"
#define SENSOR_DRVNAME_HI1339SUBTXD_MIPI_RAW      "hi1339subtxd_mipi_raw"
#define SENSOR_DRVNAME_HI1339SUBOFILM_MIPI_RAW    "hi1339subofilm_mipi_raw"
#define HI1339OFILM_SENSOR_ID                     0x133A
#define SENSOR_DRVNAME_HI1339OFILM_MIPI_RAW       "hi1339ofilm_mipi_raw"
/* Onyx */
#define OV13B10LN_SENSOR_ID                       0x0D42
#define SENSOR_DRVNAME_OV13B10LN_MIPI_RAW         "ov13b10ln_mipi_raw"
#define S5K4H7LN_SENSOR_ID                        0x487B
#define SENSOR_DRVNAME_S5K4H7LN_MIPI_RAW          "s5k4h7ln_mipi_raw"

#define GC08A3REAR_SENSOR_ID                          0x08a3
#define SENSOR_DRVNAME_GC08A3REAR_MIPI_RAW            "gc08a3rear_mipi_raw"

#define S5K4H7SUB_SENSOR_ID                     0x487C
#define SENSOR_DRVNAME_S5K4H7SUB_MIPI_RAW       "s5k4h7sub_mipi_raw"
/* SENSOR CHIP VERSION */
/*IMX*/
#define IMX06A_SENSOR_ID                        0xa18a
#define IMX858_SENSOR_ID                        0x0858
#define IMX858DUAL_SENSOR_ID                    0x0859
#define IMX499_SENSOR_ID                        0x0499
#define IMX481_SENSOR_ID                        0x0481
#define IMX486_SENSOR_ID                        0x0486
#define IMX586_SENSOR_ID                        0x0586
#define IMX758_SENSOR_ID                        0x0758
#define IMX758LITE_SENSOR_ID                    0x0759
#define IMX598_SENSOR_ID                        0x0598
#define IMX598LITE_SENSOR_ID                    0x0599
#define IMX766_SENSOR_ID                        0x0766
#define IMX766DUAL_SENSOR_ID                    0x0767
#define IMX766O_SENSOR_ID                       0x0768
#define IMX766DUALO_SENSOR_ID                   0x0769
#define IMX800_SENSOR_ID                        0x0800
#define IMX709_SENSOR_ID                        0x0709
#define IMX866_SENSOR_ID                        0x0866
#define IMX866RGB_SENSOR_ID                     0x0866
#define IMX989_SENSOR_ID                        0x0989
#define IMX989LITE_SENSOR_ID                    0x098A
#define IMX966_SENSOR_ID                        0x9186
#define IMX709O_SENSOR_ID                       0x0709
#define IMX519_SENSOR_ID                        0x0519
#define IMX576_SENSOR_ID                        0x0576
#define IMX350_SENSOR_ID                        0x0350
#define IMX398_SENSOR_ID                        0x0398
#define IMX268_SENSOR_ID                        0x0268
#define IMX386_SENSOR_ID                        0x0386
#define IMX300_SENSOR_ID                        0x0300
#define IMX386_MONO_SENSOR_ID                   0x0286
#define IMX362_SENSOR_ID                        0x0362
#define IMX338_SENSOR_ID                        0x0338
#define IMX334_SENSOR_ID                        0x0334
#define IMX334SUB_SENSOR_ID                     0x0335
#define IMX376_SENSOR_ID                        0x0376
#define IMX318_SENSOR_ID                        0x0318
#define IMX319_SENSOR_ID                        0x0319
#define IMX377_SENSOR_ID                        0x0377
#define IMX278_SENSOR_ID                        0x0278
#define IMX258_SENSOR_ID                        0x0258
#define IMX258_MONO_SENSOR_ID                   0x0259
#define IMX230_SENSOR_ID                        0x0230
#define IMX220_SENSOR_ID                        0x0220
#define IMX219_SENSOR_ID                        0x0219
#define IMX214_SENSOR_ID                        0x0214
#define IMX214_MONO_SENSOR_ID                   0x0215
#define IMX179_SENSOR_ID                        0x0179
#define IMX178_SENSOR_ID                        0x0178
#define IMX135_SENSOR_ID                        0x0135
#define IMX132MIPI_SENSOR_ID                    0x0132
#define IMX119_SENSOR_ID                        0x0119
#define IMX105_SENSOR_ID                        0x0105
#define IMX091_SENSOR_ID                        0x0091
#define IMX073_SENSOR_ID                        0x0046
#define IMX058_SENSOR_ID                        0x0058
#define IMX582_SENSOR_ID                        0x0582
#define IMX596_SENSOR_ID                        0x0596
#define IMX6632X_SENSOR_ID                      0x0663
#define IMX355_SENSOR_ID                        0x0355
#define IMX882_SENSOR_ID                        0x8206
#define IMX882_SENSOR_ID2                       0x8202
/*OV*/
#define OV23850_SENSOR_ID                       0x023850
#define OV16880_SENSOR_ID                       0x016880
#define OV16825MIPI_SENSOR_ID                   0x016820
#define OV13855_SENSOR_ID                       0xD855
#define OV13850_SENSOR_ID                       0xD850
#define OV12A10_SENSOR_ID                       0x1241
#define OV13870_SENSOR_ID                       0x013870
#define OV13850_SENSOR_ID                       0xD850
#define OV13855_SENSOR_ID                       0xD855
#define OV16885_SENSOR_ID                       0x16885
#define OV13855MAIN2_SENSOR_ID                  0xD856
#define OV12830_SENSOR_ID                       0xC830
#define OV9760MIPI_SENSOR_ID                    0x9760
#define OV9740MIPI_SENSOR_ID                    0x9740
#define OV9726_SENSOR_ID                        0x9726
#define OV9726MIPI_SENSOR_ID                    0x9726
#define OV8865_SENSOR_ID                        0x8865
#define OV8858_SENSOR_ID                        0x8858
#define OV8858S_SENSOR_ID                      (0x8858+1)
#define OV8856_SENSOR_ID                        0x885A
#define OV8830_SENSOR_ID                        0x8830
#define OV8825_SENSOR_ID                        0x8825
#define OV7675_SENSOR_ID                        0x7673
#define OV5693_SENSOR_ID                        0x5690
#define OV5670MIPI_SENSOR_ID                    0x5670
#define OV5670MIPI_SENSOR_ID_2                  (0x5670+010000)
#define OV2281MIPI_SENSOR_ID                    0x5670
#define OV5675MIPI_SENSOR_ID                    0x5675
#define OV5671MIPI_SENSOR_ID                    0x5671
#define OV5650_SENSOR_ID                        0x5651
#define OV5650MIPI_SENSOR_ID                    0x5651
#define OV5648MIPI_SENSOR_ID                    0x5648
#define OV5647_SENSOR_ID                        0x5647
#define OV5647MIPI_SENSOR_ID                    0x5647
#define OV5645MIPI_SENSOR_ID                    0x5645
#define OV5642_SENSOR_ID                        0x5642
#define OV4688MIPI_SENSOR_ID                    0x4688
#define OV3640_SENSOR_ID                        0x364C
#define OV2724MIPI_SENSOR_ID                    0x2724
#define OV2722MIPI_SENSOR_ID                    0x2722
#define OV2680MIPI_SENSOR_ID                    0x2680
#define OV2680_SENSOR_ID                        0x2680
#define OV2659_SENSOR_ID                        0x2656
#define OV2655_SENSOR_ID                        0x2656
#define OV2650_SENSOR_ID                        0x2652
#define OV2650_SENSOR_ID_1                      0x2651
#define OV2650_SENSOR_ID_2                      0x2652
#define OV2650_SENSOR_ID_3                      0x2655
#define OV20880MIPI_SENSOR_ID                   0x20880
#define OV05A20_SENSOR_ID                       0x5305
#define OX08B40_SENSOR_ID                       0x580841

/*S5K*/
#define S5KHP3SP_SENSOR_ID                      0x1b73
#define S5KJD1_SENSOR_ID                        0x3841
#define S5KJN1_SENSOR_ID                        0x38E1
#define S5K2LQSX_SENSOR_ID                      0x2c1a
#define S5K4H7_SENSOR_ID                        0x487B
#define S5K3P8SP_SENSOR_ID                      0x3108
#define S5K2T7SP_SENSOR_ID                      0x2147
#define S5K3P8SX_SENSOR_ID                      0x3108
#define S5K2L7_SENSOR_ID                        0x20C7
#define S5K3L6_SENSOR_ID                        0x30C6
#define S5K3L8_SENSOR_ID                        0x30C8
#define S5K3M3_SENSOR_ID                        0x30D3
#define S5K3M5SX_SENSOR_ID                      0x30D5
#define S5K3M5SXO_SENSOR_ID                     0x30D5
#define S5K2X8_SENSOR_ID                        0x2188
#define S5K2P7_SENSOR_ID                        0x2107
#define S5K2P8_SENSOR_ID                        0x2108
#define S5K3P3_SENSOR_ID                        0x3103
#define S5K3P3SX_SENSOR_ID                      0x3103
#define S5K3P8_SENSOR_ID                        0x3108
#define S5K3P8STECH_SENSOR_ID                   0xf3108
#define S5K3M2_SENSOR_ID                        0x30D2
#define S5K4E6_SENSOR_ID                        0x4e60
#define S5K3AAEA_SENSOR_ID                      0x07AC
#define S5K3BAFB_SENSOR_ID                      0x7070
#define S5K3H7Y_SENSOR_ID                       0x3087
#define S5K3H2YX_SENSOR_ID                      0x382b
#define S5KA3DFX_SENSOR_ID                      0x00AB
#define S5K3E2FX_SENSOR_ID                      0x3E2F
#define S5K4B2FX_SENSOR_ID                      0x5080
#define S5K4E1GA_SENSOR_ID                      0x4E10
#define S5K4ECGX_SENSOR_ID                      0x4EC0
#define S5K53BEX_SENSOR_ID                      0x45A8
#define S5K53BEB_SENSOR_ID                      0x87A8
#define S5K5BAFX_SENSOR_ID                      0x05BA
#define S5K5E2YA_SENSOR_ID                      0x5e20
#define S5K4H5YX_2LANE_SENSOR_ID                0x485B
#define S5K4H5YC_SENSOR_ID                      0x485B
#define S5K83AFX_SENSOR_ID                      0x01C4
#define S5K5CAGX_SENSOR_ID                      0x05ca
#define S5K8AAYX_MIPI_SENSOR_ID                 0x08aa
#define S5K8AAYX_SENSOR_ID                      0x08aa
#define S5K5E8YX_SENSOR_ID                      0x5e80
#define S5K5E8YXREAR2_SENSOR_ID                 0x5e81
#define S5K5E9_SENSOR_ID                        0x559b
#define S5KHM2SP_SENSOR_ID                      0x1AD2
#define S5K4H7ALPHA_SENSOR_ID                   0x487B
#define S5KGD2_SENSOR_ID                        0x0842

/*HI*/
#define HI841_SENSOR_ID                         0x0841
#define HI707_SENSOR_ID                         0x00b8
#define HI704_SENSOR_ID                         0x0096
#define HI556_SENSOR_ID                         0x0556
#define HI551_SENSOR_ID                         0x0551
#define HI553_SENSOR_ID                         0x0553
#define HI545MIPI_SENSOR_ID                     0x0545
#define HI544MIPI_SENSOR_ID                     0x0544
#define HI542_SENSOR_ID                         0x00B1
#define HI542MIPI_SENSOR_ID                     0x00B1
#define HI253_SENSOR_ID                         0x0092
#define HI251_SENSOR_ID                         0x0084
#define HI191MIPI_SENSOR_ID                     0x0191
#define HIVICF_SENSOR_ID                        0x0081
#define HI1339SUBTXD_SENSOR_ID                  0x133A
#define HI1339SUBOFILM_SENSOR_ID                0x133B
#define HI847_SENSOR_ID                         0x0847
/*MT*/
#define MT9D011_SENSOR_ID                       0x1511
#define MT9D111_SENSOR_ID                       0x1511
#define MT9D112_SENSOR_ID                       0x1580
#define MT9M011_SENSOR_ID                       0x1433
#define MT9M111_SENSOR_ID                       0x143A
#define MT9M112_SENSOR_ID                       0x148C
#define MT9M113_SENSOR_ID                       0x2480
#define MT9P012_SENSOR_ID                       0x2800
#define MT9P012_SENSOR_ID_REV7                  0x2801
#define MT9T012_SENSOR_ID                       0x1600
#define MT9T013_SENSOR_ID                       0x2600
#define MT9T113_SENSOR_ID                       0x4680
#define MT9V112_SENSOR_ID                       0x1229
#define MT9DX11_SENSOR_ID                       0x1519
#define MT9D113_SENSOR_ID                       0x2580
#define MT9D115_SENSOR_ID                       0x2580
#define MT9D115MIPI_SENSOR_ID                   0x2580
#define MT9V113_SENSOR_ID                       0x2280
#define MT9V114_SENSOR_ID                       0x2283
#define MT9V115_SENSOR_ID                       0x2284
#define MT9P015_SENSOR_ID                       0x2803
#define MT9P017_SENSOR_ID                       0x4800
#define MT9P017MIPI_SENSOR_ID                   0x4800
#define MT9T113MIPI_SENSOR_ID                   0x4680
/*GC*/
#define GC5035_SENSOR_ID                        0x5035
#define GC2375_SENSOR_ID                        0x2375
#define GC2375H_SENSOR_ID                       0x2375
#define GC2375SUB_SENSOR_ID                     0x2376
#define GC2365_SENSOR_ID                        0x2365
#define GC2366_SENSOR_ID                        0x2366
#define GC2355_SENSOR_ID                        0x2355
#define GC2235_SENSOR_ID                        0x2235
#define GC2035_SENSOR_ID                        0x2035
#define GC2145_SENSOR_ID                        0x2145
#define GC0330_SENSOR_ID                        0xC1
#define GC0329_SENSOR_ID                        0xC0
#define GC0310_SENSOR_ID                        0xa310
#define GC0313MIPI_YUV_SENSOR_ID                0xD0
#define GC0312_SENSOR_ID                        0xb310
#define GC08A3_SENSOR_ID						0x08a3
#define GC8034_SENSOR_ID                        0x8044
#define GC8C34_SENSOR_ID                        0x80C4
//#define GC02M1_SENSOR_ID                        0x2E0
/*SP*/
#define SP0A19_YUV_SENSOR_ID                    0xA6
#define SP2518_YUV_SENSOR_ID                    0x53
#define SP2509_SENSOR_ID                        0x2509
#define SP250A_SENSOR_ID                        0x250A
/*A*/
#define A5141MIPI_SENSOR_ID                     0x4800
#define A5142MIPI_SENSOR_ID                     0x4800
/*HM*/
#define HM3451_SENSOR_ID                        0x345
/*AR*/
#define AR0833_SENSOR_ID                        0x4B03
/*SIV*/
#define SID020A_SENSOR_ID                       0x12B4
#define SIV100B_SENSOR_ID                       0x0C11
#define SIV100A_SENSOR_ID                       0x0C10
#define SIV120A_SENSOR_ID                       0x1210
#define SIV120B_SENSOR_ID                       0x0012
#define SIV121D_SENSOR_ID                       0xDE
#define SIM101B_SENSOR_ID                       0x09A0
#define SIM120C_SENSOR_ID                       0x0012
#define SID130B_SENSOR_ID                       0x001b
#define SIC110A_SENSOR_ID                       0x000D
#define SIV120B_SENSOR_ID                       0x0012
/*PAS (PixArt Image)*/
#define PAS105_SENSOR_ID                        0x0065
#define PAS302_SENSOR_ID                        0x0064
#define PAS5101_SENSOR_ID                       0x0067
#define PAS6180_SENSOR_ID                       0x6179
/*Panasoic*/
#define MN34152_SENSOR_ID                       0x01
/*Toshiba*/
#define T4KA7_SENSOR_ID                         0x2c30
/*Others*/
#define SHARP3D_SENSOR_ID                       0x003d
#define T8EV5_SENSOR_ID                         0x1011

#define S5KGD1SP_SENSOR_ID                      0x0841
#define HI846_SENSOR_ID                         0x0846
#define OV02A10_MONO_SENSOR_ID                  0x2509
#define IMX686_SENSOR_ID                        0X0686
#define IMX616_SENSOR_ID                        0x0616
#define OV48C_SENSOR_ID                         0x564843
#define IMX355_SENSOR_ID                        0x0355
#define OV13B10LZ_SENSOR_ID                       0x0d42
#define OV13B10_SENSOR_ID                       0x560d42
#define OV02B10_SENSOR_ID                       0x002b


#define OV48B_SENSOR_ID                         0x564842
#define OV64B_SENSOR_ID                         0x5664
#define S5K3P9SP_SENSOR_ID                      0x3109
#define GC8054_SENSOR_ID                        0x8054
#define GC02M0_SENSOR_ID                        0x02d0
#define GC02M0_SENSOR_ID1                       0x02d1
#define GC02M0_SENSOR_ID2                       0x02d2
#define GC02K0_SENSOR_ID                        0x2385
#define OV16A10_SENSOR_ID                       0x561641
#define GC02M1B_SENSOR_ID                       0x02e0
#define GC08A3_SENSOR_ID                        0x08a3
#define MAX96712MIPI_SENSOR_ID  0x52
#define MAX96712ISXMIPI_SENSOR_ID  0x54
#define MAX96712AMIPI_SENSOR_ID   0xA4
#define MAX96712A0MIPI_SENSOR_ID  0xA0
#define MAX96712A1MIPI_SENSOR_ID  0xA1
#define MAX96712A2MIPI_SENSOR_ID  0xA2
#define MAX96712A3MIPI_SENSOR_ID  0xA3
#define LT7911_SENSOR_ID  0x1605
/* CAMERA DRIVER NAME */
#define CAMERA_HW_DEVNAME                       "kd_camera_hw"
/* SENSOR DEVICE DRIVER NAME */
/*IMX*/
#define SENSOR_DRVNAME_IMX06A_MIPI_RAW          "imx06a_mipi_raw"
#define SENSOR_DRVNAME_IMX858_MIPI_RAW          "imx858_mipi_raw"
#define SENSOR_DRVNAME_IMX858DUAL_MIPI_RAW      "imx858dual_mipi_raw"
#define SENSOR_DRVNAME_IMX499_MIPI_RAW          "imx499_mipi_raw"
#define SENSOR_DRVNAME_IMX499_MIPI_RAW_13M      "imx499_mipi_raw_13m"
#define SENSOR_DRVNAME_IMX481_MIPI_RAW          "imx481_mipi_raw"
#define SENSOR_DRVNAME_IMX486_MIPI_RAW          "imx486_mipi_raw"
#define SENSOR_DRVNAME_IMX586_MIPI_RAW          "imx586_mipi_raw"
#define SENSOR_DRVNAME_IMX598_MIPI_RAW          "imx598_mipi_raw"
#define SENSOR_DRVNAME_IMX598LITE_MIPI_RAW      "imx598lite_mipi_raw"
#define SENSOR_DRVNAME_IMX758_MIPI_RAW          "imx758_mipi_raw"
#define SENSOR_DRVNAME_IMX758LITE_MIPI_RAW      "imx758lite_mipi_raw"
#define SENSOR_DRVNAME_IMX766_MIPI_RAW          "imx766_mipi_raw"
#define SENSOR_DRVNAME_IMX766O_MIPI_RAW         "imx766o_mipi_raw"
#define SENSOR_DRVNAME_IMX709_MIPI_RAW          "imx709_mipi_raw"
#define SENSOR_DRVNAME_IMX709O_MIPI_RAW         "imx709o_mipi_raw"
#define SENSOR_DRVNAME_IMX766DUAL_MIPI_RAW      "imx766dual_mipi_raw"
#define SENSOR_DRVNAME_IMX766DUALO_MIPI_RAW     "imx766dualo_mipi_raw"
#define SENSOR_DRVNAME_IMX989_MIPI_RAW          "imx989_mipi_raw"
#define SENSOR_DRVNAME_IMX989LITE_MIPI_RAW      "imx989lite_mipi_raw"
#define SENSOR_DRVNAME_IMX966_MIPI_RAW          "imx966_mipi_raw"
#define SENSOR_DRVNAME_IMX866RGB_MIPI_RAW       "imx866rgb_mipi_raw"
#define SENSOR_DRVNAME_IMX800_MIPI_RAW          "imx800_mipi_raw"
#define SENSOR_DRVNAME_IMX6632X_MIPI_RAW        "imx6632x_mipi_raw"
#define SENSOR_DRVNAME_IMX519_MIPI_RAW          "imx519_mipi_raw"
#define SENSOR_DRVNAME_IMX519DUAL_MIPI_RAW      "imx519dual_mipi_raw"
#define SENSOR_DRVNAME_IMX576_MIPI_RAW          "imx576_mipi_raw"
#define SENSOR_DRVNAME_IMX350_MIPI_RAW          "imx350_mipi_raw"
#define SENSOR_DRVNAME_IMX398_MIPI_RAW          "imx398_mipi_raw"
#define SENSOR_DRVNAME_IMX268_MIPI_RAW          "imx268_mipi_raw"
#define SENSOR_DRVNAME_IMX386_MIPI_RAW          "imx386_mipi_raw"
#define SENSOR_DRVNAME_IMX300_MIPI_RAW          "imx300_mipi_raw"
#define SENSOR_DRVNAME_IMX386_MIPI_MONO         "imx386_mipi_mono"
#define SENSOR_DRVNAME_IMX362_MIPI_RAW          "imx362_mipi_raw"
#define SENSOR_DRVNAME_IMX338_MIPI_RAW          "imx338_mipi_raw"
#define SENSOR_DRVNAME_IMX334_MIPI_RAW          "imx334_mipi_raw"
#define SENSOR_DRVNAME_IMX334SUB_MIPI_RAW       "imx334sub_mipi_raw"
#define SENSOR_DRVNAME_IMX376_MIPI_RAW          "imx376_mipi_raw"
#define SENSOR_DRVNAME_IMX318_MIPI_RAW          "imx318_mipi_raw"
#define SENSOR_DRVNAME_IMX319_MIPI_RAW          "imx319_mipi_raw"
#define SENSOR_DRVNAME_IMX377_MIPI_RAW          "imx377_mipi_raw"
#define SENSOR_DRVNAME_IMX278_MIPI_RAW          "imx278_mipi_raw"
#define SENSOR_DRVNAME_IMX258_MIPI_RAW          "imx258_mipi_raw"
#define SENSOR_DRVNAME_IMX258_MIPI_MONO         "imx258_mipi_mono"
#define SENSOR_DRVNAME_IMX230_MIPI_RAW          "imx230_mipi_raw"
#define SENSOR_DRVNAME_IMX220_MIPI_RAW          "imx220_mipi_raw"
#define SENSOR_DRVNAME_IMX219_MIPI_RAW          "imx219_mipi_raw"
#define SENSOR_DRVNAME_IMX214_MIPI_MONO         "imx214_mipi_mono"
#define SENSOR_DRVNAME_IMX214_MIPI_RAW          "imx214_mipi_raw"
#define SENSOR_DRVNAME_IMX179_MIPI_RAW          "imx179_mipi_raw"
#define SENSOR_DRVNAME_IMX178_MIPI_RAW          "imx178_mipi_raw"
#define SENSOR_DRVNAME_IMX135_MIPI_RAW          "imx135_mipi_raw"
#define SENSOR_DRVNAME_IMX132_MIPI_RAW          "imx132_mipi_raw"
#define SENSOR_DRVNAME_IMX119_MIPI_RAW          "imx119_mipi_raw"
#define SENSOR_DRVNAME_IMX105_MIPI_RAW          "imx105_mipi_raw"
#define SENSOR_DRVNAME_IMX091_MIPI_RAW          "imx091_mipi_raw"
#define SENSOR_DRVNAME_IMX073_MIPI_RAW          "imx073_mipi_raw"
#define SENSOR_DRVNAME_IMX582_MIPI_RAW          "imx582_mipi_raw"
#define SENSOR_DRVNAME_IMX596_MIPI_RAW          "imx596_mipi_raw"
/*OV*/
#define SENSOR_DRVNAME_OV23850_MIPI_RAW         "ov23850_mipi_raw"
#define SENSOR_DRVNAME_OV16880_MIPI_RAW         "ov16880_mipi_raw"
#define SENSOR_DRVNAME_OV16885_MIPI_RAW         "ov16885_mipi_raw"
#define SENSOR_DRVNAME_OV16825_MIPI_RAW         "ov16825_mipi_raw"
#define SENSOR_DRVNAME_OV13855_MIPI_RAW         "ov13855_mipi_raw"
#define SENSOR_DRVNAME_OV13870_MIPI_RAW         "ov13870_mipi_raw"
#define SENSOR_DRVNAME_OV13855_MIPI_RAW         "ov13855_mipi_raw"
#define SENSOR_DRVNAME_OV13855MAIN2_MIPI_RAW    "ov13855main2_mipi_raw"
#define SENSOR_DRVNAME_OV13850_MIPI_RAW         "ov13850_mipi_raw"
#define SENSOR_DRVNAME_OV12A10_MIPI_RAW         "ov12a10_mipi_raw"
#define SENSOR_DRVNAME_OV12830_MIPI_RAW         "ov12830_mipi_raw"
#define SENSOR_DRVNAME_OV9760_MIPI_RAW          "ov9760_mipi_raw"
#define SENSOR_DRVNAME_OV9740_MIPI_YUV          "ov9740_mipi_yuv"
#define SENSOR_DRVNAME_0V9726_RAW               "ov9726_raw"
#define SENSOR_DRVNAME_OV9726_MIPI_RAW          "ov9726_mipi_raw"
#define SENSOR_DRVNAME_OV8865_MIPI_RAW          "ov8865_mipi_raw"
#define SENSOR_DRVNAME_OV8858_MIPI_RAW          "ov8858_mipi_raw"
#define SENSOR_DRVNAME_OV8858S_MIPI_RAW         "ov8858s_mipi_raw"
#define SENSOR_DRVNAME_OV8856_MIPI_RAW          "ov8856_mipi_raw"
#define SENSOR_DRVNAME_OV8830_RAW               "ov8830_raw"
#define SENSOR_DRVNAME_OV8825_MIPI_RAW          "ov8825_mipi_raw"
#define SENSOR_DRVNAME_OV7675_YUV               "ov7675_yuv"
#define SENSOR_DRVNAME_OV5693_MIPI_RAW          "ov5693_mipi_raw"
#define SENSOR_DRVNAME_OV5670_MIPI_RAW          "ov5670_mipi_raw"
#define SENSOR_DRVNAME_OV5670_MIPI_RAW_2        "ov5670_mipi_raw_2"
#define SENSOR_DRVNAME_OV2281_MIPI_RAW          "ov2281_mipi_raw"
#define SENSOR_DRVNAME_OV5675_MIPI_RAW          "ov5675mipiraw"
#define SENSOR_DRVNAME_OV5671_MIPI_RAW          "ov5671_mipi_raw"
#define SENSOR_DRVNAME_OV5647MIPI_RAW           "ov5647_mipi_raw"
#define SENSOR_DRVNAME_OV5645_MIPI_RAW          "ov5645_mipi_raw"
#define SENSOR_DRVNAME_OV5645_MIPI_YUV          "ov5645_mipi_yuv"
#define SENSOR_DRVNAME_OV5650MIPI_RAW           "ov5650_mipi_raw"
#define SENSOR_DRVNAME_OV5650_RAW               "ov5650_raw"
#define SENSOR_DRVNAME_OV5648_MIPI_RAW          "ov5648_mipi_raw"
#define SENSOR_DRVNAME_OV5647_RAW               "ov5647_raw"
#define SENSOR_DRVNAME_OV5642_RAW               "ov5642_raw"
#define SENSOR_DRVNAME_OV5642_MIPI_YUV          "ov5642_mipi_yuv"
#define SENSOR_DRVNAME_OV5642_MIPI_RGB          "ov5642_mipi_rgb"
#define SENSOR_DRVNAME_OV5642_MIPI_JPG          "ov5642_mipi_jpg"
#define SENSOR_DRVNAME_OV5642_YUV               "ov5642_yuv"
#define SENSOR_DRVNAME_OV5642_YUV_SWI2C         "ov5642_yuv_swi2c"
#define SENSOR_DRVNAME_OV4688_MIPI_RAW          "ov4688_mipi_raw"
#define SENSOR_DRVNAME_OV3640_RAW               "ov3640_raw"
#define SENSOR_DRVNAME_OV3640_YUV               "ov3640_yuv"
#define SENSOR_DRVNAME_OV2724_MIPI_RAW          "ov2724_mipi_raw"
#define SENSOR_DRVNAME_OV2722_MIPI_RAW          "ov2722_mipi_raw"
#define SENSOR_DRVNAME_OV2680_MIPI_RAW          "ov2680_mipi_raw"
#define SENSOR_DRVNAME_OV2659_YUV               "ov2659_yuv"
#define SENSOR_DRVNAME_OV2655_YUV               "ov2655_yuv"
#define SENSOR_DRVNAME_OV2650_RAW               "ov265x_raw"
#define SENSOR_DRVNAME_OV20880_MIPI_RAW         "ov20880_mipi_raw"
#define SENSOR_DRVNAME_OV05A20_MIPI_RAW         "ov05a20_mipi_raw"
#define SENSOR_DRVNAME_OX08B40_MIPI_RAW         "ox08b40_mipi_raw"

/*S5K*/
#define SENSOR_DRVNAME_S5KHP3SP_MIPI_RAW        "s5khp3sp_mipi_raw"
#define SENSOR_DRVNAME_S5KJD1_MIPI_RAW        "s5kjd1_mipi_raw"
#define SENSOR_DRVNAME_S5K2LQSX_MIPI_RAW        "s5k2lqsx_mipi_raw"
#define SENSOR_DRVNAME_S5K4H7_MIPI_RAW          "s5k4h7_mipi_raw"
#define SENSOR_DRVNAME_S5K3P8SP_MIPI_RAW        "s5k3p8sp_mipi_raw"
#define SENSOR_DRVNAME_S5K2T7SP_MIPI_RAW        "s5k2t7sp_mipi_raw"
#define SENSOR_DRVNAME_S5K2T7SP_MIPI_RAW_5M     "s5k2t7sp_mipi_raw_5m"
#define SENSOR_DRVNAME_S5K3P8SX_MIPI_RAW        "s5k3p8sx_mipi_raw"
#define SENSOR_DRVNAME_S5K2L7_MIPI_RAW          "s5k2l7_mipi_raw"
#define SENSOR_DRVNAME_S5K3L6_MIPI_RAW          "s5k3l6_mipi_raw"
#define SENSOR_DRVNAME_S5K3L8_MIPI_RAW          "s5k3l8_mipi_raw"
#define SENSOR_DRVNAME_S5K3M3_MIPI_RAW          "s5k3m3_mipi_raw"
#define SENSOR_DRVNAME_S5K3M5SX_MIPI_RAW        "s5k3m5sx_mipi_raw"
#define SENSOR_DRVNAME_S5K3M5SXO_MIPI_RAW       "s5k3m5sxo_mipi_raw"
#define SENSOR_DRVNAME_S5K2X8_MIPI_RAW          "s5k2x8_mipi_raw"
#define SENSOR_DRVNAME_S5K2P7_MIPI_RAW          "s5k2p7_mipi_raw"
#define SENSOR_DRVNAME_S5K2P8_MIPI_RAW          "s5k2p8_mipi_raw"
#define SENSOR_DRVNAME_S5K3P3SX_MIPI_RAW        "s5k3p3sx_mipi_raw"
#define SENSOR_DRVNAME_S5K3P3_MIPI_RAW          "s5k3p3_mipi_raw"
#define SENSOR_DRVNAME_S5K3P8_MIPI_RAW          "s5k3p8_mipi_raw"
#define SENSOR_DRVNAME_S5K3M2_MIPI_RAW          "s5k3m2_mipi_raw"
#define SENSOR_DRVNAME_S5K4E6_MIPI_RAW          "s5k4e6_mipi_raw"
#define SENSOR_DRVNAME_S5K3H2YX_MIPI_RAW        "s5k3h2yx_mipi_raw"
#define SENSOR_DRVNAME_S5K3H7Y_MIPI_RAW         "s5k3h7y_mipi_raw"
#define SENSOR_DRVNAME_S5K4H5YC_MIPI_RAW        "s5k4h5yc_mipi_raw"
#define SENSOR_DRVNAME_S5K4E1GA_MIPI_RAW        "s5k4e1ga_mipi_raw"
#define SENSOR_DRVNAME_S5K4ECGX_MIPI_YUV        "s5k4ecgx_mipi_yuv"
#define SENSOR_DRVNAME_S5K5CAGX_YUV             "s5k5cagx_yuv"
#define SENSOR_DRVNAME_S5K4H5YX_2LANE_MIPI_RAW  "s5k4h5yx_2lane_mipi_raw"
#define SENSOR_DRVNAME_S5K5E2YA_MIPI_RAW        "s5k5e2ya_mipi_raw"
#define SENSOR_DRVNAME_S5K8AAYX_MIPI_YUV        "s5k8aayx_mipi_yuv"
#define SENSOR_DRVNAME_S5K8AAYX_YUV             "s5k8aayx_yuv"
#define SENSOR_DRVNAME_S5K5E8YX_MIPI_RAW        "s5k5e8yx_mipi_raw"
#define SENSOR_DRVNAME_S5K5E8YXREAR2_MIPI_RAW   "s5k5e8yxrear2_mipi_raw"
#define SENSOR_DRVNAME_S5K5E9_MIPI_RAW          "s5k5e9_mipi_raw"
#define SENSOR_DRVNAME_S5KHM2SP_MIPI_RAW        "s5khm2sp_mipi_raw"
#define SENSOR_DRVNAME_S5KJN1_MIPI_RAW			"s5kjn1_mipi_raw"
#define SENSOR_DRVNAME_S5K4H7ALPHA_MIPI_RAW     "s5k4h7alpha_mipi_raw"
#define SENSOR_DRVNAME_S5KGD2_MIPI_RAW         "s5kgd2_mipi_raw"
/*HI*/
#define SENSOR_DRVNAME_HI841_MIPI_RAW           "hi841_mipi_raw"
#define SENSOR_DRVNAME_HI707_YUV                "hi707_yuv"
#define SENSOR_DRVNAME_HI704_YUV                "hi704_yuv"
#define SENSOR_DRVNAME_HI556_MIPI_RAW           "hi556_mipi_raw"
#define SENSOR_DRVNAME_HI551_MIPI_RAW           "hi551_mipi_raw"
#define SENSOR_DRVNAME_HI553_MIPI_RAW           "hi553_mipi_raw"
#define SENSOR_DRVNAME_HI545_MIPI_RAW           "hi545_mipi_raw"
#define SENSOR_DRVNAME_HI542_RAW                "hi542_raw"
#define SENSOR_DRVNAME_HI542MIPI_RAW            "hi542_mipi_raw"
#define SENSOR_DRVNAME_HI544_MIPI_RAW           "hi544_mipi_raw"
#define SENSOR_DRVNAME_HI253_YUV                "hi253_yuv"
#define SENSOR_DRVNAME_HI191_MIPI_RAW           "hi191_mipi_raw"
#define SENSOR_DRVNAME_HI847_MIPI_RAW           "hi847_mipi_raw"
/*MT*/
#define SENSOR_DRVNAME_MT9P012_RAW              "mt9p012_raw"
#define SENSOR_DRVNAME_MT9P015_RAW              "mt9p015_raw"
#define SENSOR_DRVNAME_MT9P017_RAW              "mt9p017_raw"
#define SENSOR_DRVNAME_MT9P017_MIPI_RAW         "mt9p017_mipi_raw"
#define SENSOR_DRVNAME_MT9D115_MIPI_RAW         "mt9d115_mipi_raw"
#define SENSOR_DRVNAME_MT9V114_YUV              "mt9v114_yuv"
#define SENSOR_DRVNAME_MT9V115_YUV              "mt9v115_yuv"
#define SENSOR_DRVNAME_MT9T113_YUV              "mt9t113_yuv"
#define SENSOR_DRVNAME_MT9V113_YUV              "mt9v113_yuv"
#define SENSOR_DRVNAME_MT9T113_MIPI_YUV         "mt9t113_mipi_yuv"
/*GC*/
#define SENSOR_DRVNAME_GC02M0_MIPI_RAW          "gc02m0_mipi_raw"
#define SENSOR_DRVNAME_GC5035MIPI_RAW           "gc5035_mipi_raw"
#define SENSOR_DRVNAME_GC2375_MIPI_RAW          "gc2375_mipi_raw"
#define SENSOR_DRVNAME_GC2375H_MIPI_RAW         "gc2375h_mipi_raw"
#define SENSOR_DRVNAME_GC2375SUB_MIPI_RAW       "gc2375sub_mipi_raw"
#define SENSOR_DRVNAME_GC2365_MIPI_RAW          "gc2365_mipi_raw"
#define SENSOR_DRVNAME_GC2366_MIPI_RAW          "gc2366_mipi_raw"
#define SENSOR_DRVNAME_GC08A3_MIPI_RAW          "gc08a3_mipi_raw"
#define SENSOR_DRVNAME_GC2035_YUV               "gc2035_yuv"
#define SENSOR_DRVNAME_GC2235_RAW               "gc2235_raw"
#define SENSOR_DRVNAME_GC2355_MIPI_RAW          "gc2355_mipi_raw"
#define SENSOR_DRVNAME_GC2355_RAW               "gc2355_raw"
#define SENSOR_DRVNAME_GC0330_YUV               "gc0330_yuv"
#define SENSOR_DRVNAME_GC0329_YUV               "gc0329_yuv"
#define SENSOR_DRVNAME_GC2145_MIPI_YUV          "gc2145_mipi_yuv"
#define SENSOR_DRVNAME_GC0310_MIPI_YUV          "gc0310_mipi_yuv"
#define SENSOR_DRVNAME_GC0310_YUV               "gc0310_yuv"
#define SENSOR_DRVNAME_GC0312_YUV               "gc0312_yuv"
#define SENSOR_DRVNAME_GC0313MIPI_YUV           "gc0313_mipi_yuv"
#define SENSOR_DRVNAME_GC8C34_MIPI_RAW          "gc8c34_mipi_raw"
#define SENSOR_DRVNAME_GC8034_MIPI_RAW          "gc8034_mipi_raw"
#define SENSOR_DRVNAME_GC02M1_MIPI_RAW          "gc02m1_mipi_raw"
/*SP*/
#define SENSOR_DRVNAME_SP0A19_YUV               "sp0a19_yuv"
#define SENSOR_DRVNAME_SP2518_YUV               "sp2518_yuv"
#define SENSOR_DRVNAME_SP2509_MIPI_RAW          "sp2509_mipi_raw"
#define SENSOR_DRVNAME_SP250A_MIPI_RAW          "sp250a_mipi_raw"
/*A*/
#define SENSOR_DRVNAME_A5141_MIPI_RAW           "a5141_mipi_raw"
#define SENSOR_DRVNAME_A5142_MIPI_RAW           "a5142_mipi_raw"
/*HM*/
#define SENSOR_DRVNAME_HM3451_RAW               "hm3451_raw"
/*AR*/
#define SENSOR_DRVNAME_AR0833_MIPI_RAW          "ar0833_mipi_raw"
/*SIV*/
#define SENSOR_DRVNAME_SIV121D_YUV              "siv121d_yuv"
#define SENSOR_DRVNAME_SIV120B_YUV              "siv120b_yuv"
/*PAS (PixArt Image)*/
#define SENSOR_DRVNAME_PAS6180_SERIAL_YUV       "pas6180_serial_yuv"
/*Panasoic*/
#define SENSOR_DRVNAME_MN34152_MIPI_RAW         "mn34152_mipi_raw"
/*Toshiba*/
#define SENSOR_DRVNAME_T4KA7_MIPI_RAW           "t4ka7_mipi_raw"
/*Others*/
#define SENSOR_DRVNAME_SHARP3D_MIPI_YUV         "sharp3d_mipi_yuv"
#define SENSOR_DRVNAME_T8EV5_YUV                "t8ev5_yuv"
/*Test*/
#define SENSOR_DRVNAME_IMX135_MIPI_RAW_5MP      "imx135_mipi_raw_5mp"
#define SENSOR_DRVNAME_IMX135_MIPI_RAW_8MP      "imx135_mipi_raw_8mp"
#define SENSOR_DRVNAME_OV13870_MIPI_RAW_5MP     "ov13870_mipi_raw_5mp"
#define SENSOR_DRVNAME_OV8856_MIPI_RAW_5MP      "ov8856_mipi_raw_5mp"

#define SENSOR_DRVNAME_S5KGD1SP_MIPI_RAW        "s5kgd1sp_mipi_raw"
#define SENSOR_DRVNAME_HI846_MIPI_RAW           "hi846_mipi_raw"
#define SENSOR_DRVNAME_GC02M0_MIPI_RAW          "gc02m0_mipi_raw"
#define SENSOR_DRVNAME_GC08A3_MIPI_RAW          "gc08a3_mipi_raw"
#define SENSOR_DRVNAME_OV02A10_MIPI_MONO        "ov02a10_mipi_mono"
#define SENSOR_DRVNAME_IMX686_MIPI_RAW          "imx686_mipi_raw"
#define SENSOR_DRVNAME_IMX616_MIPI_RAW          "imx616_mipi_raw"
#define SENSOR_DRVNAME_OV48B_MIPI_RAW           "ov48b_mipi_raw"
#define SENSOR_DRVNAME_OV64B_MIPI_RAW           "ov64b_mipi_raw"
#define SENSOR_DRVNAME_S5K3P9SP_MIPI_RAW        "s5k3p9sp_mipi_raw"
#define SENSOR_DRVNAME_GC8054_MIPI_RAW          "gc8054_mipi_raw"
#define SENSOR_DRVNAME_GC02M0B_MIPI_MONO        "gc02m0b_mipi_mono"
#define SENSOR_DRVNAME_GC02M0B_MIPI_MONO1       "gc02m0b_mipi_mono1"
#define SENSOR_DRVNAME_GC02M0B_MIPI_MONO2       "gc02m0b_mipi_mono2"
#define SENSOR_DRVNAME_GC02K0B_MIPI_MONO        "gc02k0b_mipi_mono"
#define SENSOR_DRVNAME_OV16A10_MIPI_RAW         "ov16a10_mipi_raw"
#define SENSOR_DRVNAME_GC02M1B_MIPI_MONO        "gc02m1b_mipi_mono"
#define SENSOR_DRVNAME_OV48C_MIPI_RAW           "ov48c_mipi_raw"
#define SENSOR_DRVNAME_IMX355_MIPI_RAW          "imx355_mipi_raw"
#define SENSOR_DRVNAME_OV13B10LZ_MIPI_RAW       "ov13b10lz_mipi_raw"
#define SENSOR_DRVNAME_OV13B10_MIPI_RAW         "ov13b10_mipi_raw"
#define SENSOR_DRVNAME_OV02B10_MIPI_RAW         "ov02b10_mipi_raw"
#define SENSOR_DRVNAME_MAX96712_MIPI_YUV        "max96712_mipi_yuv"
#define SENSOR_DRVNAME_MAX96712ISX_MIPI_YUV        "max96712isx_mipi_yuv"
#define SENSOR_DRVNAME_MAX96712A_MIPI_YUV        "max96712a_mipi_yuv"
#define SENSOR_DRVNAME_MAX96712A0_MIPI_YUV        "max96712a0_mipi_yuv"
#define SENSOR_DRVNAME_MAX96712A1_MIPI_YUV        "max96712a1_mipi_yuv"
#define SENSOR_DRVNAME_MAX96712A2_MIPI_YUV        "max96712a2_mipi_yuv"
#define SENSOR_DRVNAME_MAX96712A3_MIPI_YUV        "max96712a3_mipi_yuv"
#define SENSOR_DRVNAME_LT7911_MIPI_YUV        "lt7911_mipi_yuv"


#define SENSOR_DRVNAME_IMX355_MIPI_RAW_LAFITE    "imx355_mipi_raw_lafite"
#define SENSOR_DRVNAME_OV02B10_MIPI_RAW         "ov02b10_mipi_raw"

#define OV64B_SENSOR_ID_20645                         0x5665
#define SENSOR_DRVNAME_OV64B_MIPI_RAW_20645           "ov64b_mipi_raw_20645"
#define OV02B10_SENSOR_ID_20645                       0x0033
#define SENSOR_DRVNAME_OV02B10_MIPI_RAW_20645         "ov02b10_mipi_raw_20645"
#define HI846_SENSOR_ID_20645                         0x849
#define SENSOR_DRVNAME_HI846_MIPI_RAW_20645           "hi846_mipi_raw_20645"
#define OV32A1Q_SENSOR_ID_20645                       0x563244
#define SENSOR_DRVNAME_OV32A1Q_MIPI_RAW_20645         "ov32a1q_mipi_raw_20645"

#define SENSOR_DRVNAME_OV64B_MIPI_RAW                 "ov64b_mipi_raw"
#define OV48B_SENSOR_ID                         0x564842
#define SENSOR_DRVNAME_OV48B_MIPI_RAW           "ov48b_mipi_raw"
#define OV32A_SENSOR_ID                      0x563241
#define SENSOR_DRVNAME_OV32A_MIPI_RAW      "ov32a_mipi_raw"
#define HI846_SENSOR_ID                         0x0846
#define SENSOR_DRVNAME_HI846_MIPI_RAW           "hi846_mipi_raw"



#define OV02B1B_SENSOR_ID                       0x002c
#define ATHENSC_IMX471_SENSOR_ID                0x472
#define IMX471_SENSOR_ID                        0x20000
#define OV02A1B_SENSOR_ID                       0x250a
#define ATHENSB_GC02M1B_SENSOR_ID                       0x02E1
#define GC02M1B_SENSOR_ID_20630                       0x02e0
#define HI846_SENSOR_ID_ANNA                        0x084B
#define HI846_SENSOR_ID_20633                         0x0846
#define IMX471_SENSOR_ID_ANNA                       0x20002
#define ATHENSC_IMX471_SENSOR_ID                      0x472
#define IMX471_SENSOR_ID_20633                        0x471

#define GC02M1_SENSOR_ID_APOLLOT                      0x02ee
#define SENSOR_DRVNAME_GC02M1_MIPI_RAW_APOLLOT        "gc02m1_mipi_raw_apollot"

#define SENSOR_DRVNAME_IMX471_MIPI_RAW_ANNA         "imx471_mipi_raw_anna"
#define SENSOR_DRVNAME_HI846_MIPI_RAW_ANNA          "hi846_mipi_raw_anna"
#define SENSOR_DRVNAME_IMX471_MIPI_RAW1          "imx471_mipi_raw1"
#define SENSOR_DRVNAME_OV02A1B_MIPI_MONO         "ov02a1b_mipi_mono"
#define SENSOR_DRVNAME_OV02B1B_MIPI_MONO        "ov02b1b_mipi_mono"
#define SENSOR_DRVNAME_IMX471_MIPI_RAW          "imx471_mipi_raw"
#define SENSOR_DRVNAME_GC02K0_MIPI_RAW          "gc02k0_mipi_raw"
#define SENSOR_DRVNAME_OV32A_MIPI_RAW           "ov32a_mipi_raw"
#define SENSOR_DRVNAME_S5KGM1ST_MIPI_RAW        "s5kgm1st_mipi_raw"
#define S5KGW1_SENSOR_ID                        0x0971
#define OV32A1Q_SENSOR_ID_20630                       0x563241
#define ATHENSB_OV32A1Q_SENSOR_ID                       0x563243
#define HI846_SENSOR_ID_20630                       0x0846
#define ATHENSB_HI846_SENSOR_ID                       0x0847
#define GC02K_SENSOR_ID_20630                       0x2395
#define ATHENSB_GC02K_SENSOR_ID                       0x2396
#define GC02M1B_SENSOR_ID_20630                       0x02e0
#define ATHENSB_GC02M1B_SENSOR_ID                       0x02E1
#define ATHENSC_HI846_SENSOR_ID                       0x0848
#define OV02B1B_SENSOR_ID1                      0x002C
#define OV02B10_SENSOR_ID_ANNA                      0x0032
#if defined(MT6853)
#define S5KGM1ST_SENSOR_ID                      0xF8D1
#endif
#define S5KGM1ST_SENSOR_ID_20633                       0xF8D1
#define S5KGM1ST_SENSOR_ID_ANNA                     0xF8D4 // (0xF8D1 + 3)
#define S5KGW3_SENSOR_ID_ANNA                       0x730B
#define S5KGW3_SENSOR_ID_20630                        0x7309
#define ATHENSC_S5KGM1ST_SENSOR_ID                    0xF8D2
#define S5KGW3_SENSOR_ID                        0x0973
#define GC02M1B_SENSOR_ID1                      0x02e1
#define IMX766_SENSOR_ID_MOSS                        0x0766
#define SENSOR_DRVNAME_IMX766_MOSSMIPI_RAW          "imx766_mossmipi_raw"
#define IMX471_SENSOR_ID_MOSS                       0x20000
#define SENSOR_DRVNAME_IMX471_MOSSMIPI_RAW         "imx471_mossmipi_raw"
#define IMX355_SENSOR_ID_MOSS                        (0x0355 + 1)
#define SENSOR_DRVNAME_IMX355_MOSSMIPI_RAW          "imx355_mossmipi_raw"
#define GC02M1_SENSOR_ID_MOSS                         0x02e0
#define SENSOR_DRVNAME_GC02M1_MOSSMIPI_RAW           "gc02m1_mossmipi_raw"
#define S5KGM1ST_SENSOR_ID_MOSSA                         0xF8D1
#define SENSOR_DRVNAME_S5KGM1ST_MOSSAMIPI_RAW           "s5kgm1st_mossamipi_raw"
#define GC02M1_SENSOR_ID_MOSSA                         (0x02e0+0xa)
#define SENSOR_DRVNAME_GC02M1_MOSSAMIPI_RAW           "gc02m1_mossamipi_raw"

#define IMX766_SENSOR_ID22693                         (0x0766 + 0x3)//0x0769
#define SENSOR_DRVNAME_IMX766_MIPI_RAW22693           "imx766_mipi_raw22693"
#define S5KHM6SP_SENSOR_ID22693                       (0x1ad6)
#define SENSOR_DRVNAME_S5KHM6SP_MIPI_RAW22693         "s5khm6sp_mipi_raw22693"
#define S5K3P9SP_SENSOR_ID22693                       (0x3109 + 0x6)//0x310f
#define SENSOR_DRVNAME_S5K3P9SP_MIPI_RAW22693         "s5k3p9sp_mipi_raw22693"
#define IMX355_SENSOR_ID22693                         (0x0355 + 0x7)//0x035c
#define SENSOR_DRVNAME_IMX355_MIPI_RAW22693           "imx355_mipi_raw22693"
#define GC02M1_SENSOR_ID22693                         (0x02e0 + 0xd)//0x02ed
#define SENSOR_DRVNAME_GC02M1_MIPI_RAW22693           "gc02m1_mipi_raw22693"

/*Cam.Drv add for tacoo 20230922*/
#define IMX882_SENSOR_ID23687                       0x8202
#define SENSOR_DRVNAME_IMX882_MIPI_RAW23687         "imx882_mipi_raw23687"
#define IMX890_SENSOR_ID23689                       0x0890
#define SENSOR_DRVNAME_IMX890_MIPI_RAW23689         "imx890_mipi_raw23689"
#define HI1634Q_SENSOR_ID23687                      0x1634
#define SENSOR_DRVNAME_HI1634Q_MIPI_RAW23687       "hi1634q_mipi_raw23687"
#define HI846W_SENSOR_ID23687                       0x0856
#define SENSOR_DRVNAME_HI846W_MIPI_RAW23687         "hi846w_mipi_raw23687"
#define GC02M1_SENSOR_ID23687                       (0x02e0 + 0xf)//0x02ef
#define SENSOR_DRVNAME_GC02M1_MIPI_RAW23687         "gc02m1_mipi_raw23687"
#define IMX882PD_SENSOR_ID23687                     (0x8202 + 0x1) // 0x8203
#define SENSOR_DRVNAME_IMX882PD_MIPI_RAW23687       "imx882pd_mipi_raw23687"
/*Cam.Drv add for tacoo 20230922*/

/*Cam.Drv add for tacoo-b 20231129*/
#define S5KJN1_SENSOR_ID23707                         0x38E9 /*0x0x38E1 + 8*/
#define SENSOR_DRVNAME_S5KJN1_MIPI_RAW23707           "s5kjn1_mipi_raw23707"
#define GC02M1_SENSOR_ID23707                         (0x02e0 + 0x13)//0x02f3
#define SENSOR_DRVNAME_GC02M1_MIPI_RAW23707           "gc02m1_mipi_raw23707"
#define HI1634Q_SENSOR_ID23707                        0x1635
#define SENSOR_DRVNAME_HI1634Q_MIPI_RAW23707          "hi1634q_mipi_raw23707"
/*Cam.Drv add for tacoo-b 20231129*/

/*Cam.Drv add for chengdu 20221213*/
#define S5KHP3SP_SENSOR_ID22629                       (0x1b73)
#define SENSOR_DRVNAME_S5KHP3SP_MIPI_RAW22629         "s5khp3sp_mipi_raw22629"
#define IMX615_SENSOR_ID22629                         (0x0615 + 0xe)//0x0623
#define SENSOR_DRVNAME_IMX615_MIPI_RAW22629           "imx615_mipi_raw22629"
#define IMX355_SENSOR_ID22629                         (0x0355 + 0x8)//0x035d
#define SENSOR_DRVNAME_IMX355_MIPI_RAW22629           "imx355_mipi_raw22629"
#define GC02M1_SENSOR_ID22629                         (0x02e0 + 0xe)//0x02ee
#define SENSOR_DRVNAME_GC02M1_MIPI_RAW22629           "gc02m1_mipi_raw22629"
#define OVA0B4_SENSOR_ID22633                         (0xa042 + 0x1)//0xa043
#define SENSOR_DRVNAME_OVA0B4_MIPI_RAW22633           "ova0b4_mipi_raw22633"
#define S5K3P9SP_SENSOR_ID22633                       0x3121
#define SENSOR_DRVNAME_S5K3P9SP_MIPI_RAW22633         "s5k3p9sp_mipi_raw22633"
#define SC202CS_SENSOR_ID22633                        (0xeb52 + 0x1)//0xeb53
#define SENSOR_DRVNAME_SC202CS_MIPI_MONO22633         "sc202cs_mipi_mono22633"
#define OV02B1B_SENSOR_ID22633                        (0x002b + 0xc)//0X0037
#define SENSOR_DRVNAME_OV02B1B_MIPI_MONO22633         "ov02b1b_mipi_mono22633"
/*Cam.Drv add for chengdu 20221213*/

#define SENSOR_DRVNAME_GC02M1B_MIPI_MONO0       "gc02m1b_mipi_mono0"
#define SENSOR_DRVNAME_GC02M1B_MIPI_MONO1       "gc02m1b_mipi_mono1"
#define SENSOR_DRVNAME_GC02M1B_MIPI_MONO2       "gc02m1b_mipi_mono2"

#define IMX581_SENSOR_ID                          0x0581
#define GC02M1_SENSOR_ID_DUFU                    (0x02e0+4)
#define SENSOR_DRVNAME_IMX581_MIPI_RAW           "imx581_mipi_raw"
#define SENSOR_DRVNAME_GC02M1_MIPI_RAW           "gc02m1_mipi_raw"

#define CHOPIN_OFFSET                               0x5
#define OV64B_SENSOR_ID_212A1                      (0x5664 + CHOPIN_OFFSET)
#define SENSOR_DRVNAME_OV64B_MIPI_RAW212A1         "ov64b_mipi_raw212a1"
#define IMX615_SENSOR_ID_212A1                     (0x0615 + CHOPIN_OFFSET)
#define SENSOR_DRVNAME_IMX615_MIPI_RAW212A1        "imx615_mipi_raw212a1"
#define IMX355_SENSOR_ID_212A1                     (0x0355 + CHOPIN_OFFSET)
#define SENSOR_DRVNAME_IMX355_MIPI_RAW212A1         "imx355_mipi_raw212a1"
#define GC02M1_SENSOR_ID_212A1                     (0x02e0 + CHOPIN_OFFSET)
#define SENSOR_DRVNAME_GC02M1_MIPI_RAW212A1        "gc02m1_mipi_raw212a1"

#define IVAN_OFFSET                                 0xA
#define OV64B_SENSOR_ID_21851                      (0x5664 + IVAN_OFFSET)
#define SENSOR_DRVNAME_OV64B_MIPI_RAW21851         "ov64b_mipi_raw21851"
#define IMX471_SENSOR_ID_21851                     (0x20000 + IVAN_OFFSET)
#define SENSOR_DRVNAME_IMX471_MIPI_RAW21851        "imx471_mipi_raw21851"
#define IMX355_SENSOR_ID_21851                     (0x0355 + IVAN_OFFSET)
#define SENSOR_DRVNAME_IMX355_MIPI_RAW21851         "imx355_mipi_raw21851"
#define GC02M1_SENSOR_ID_21851                     (0x02e0 + IVAN_OFFSET)
#define SENSOR_DRVNAME_GC02M1_MIPI_RAW21851        "gc02m1_mipi_raw21851"

#define CARR_OV13B10_SENSOR_ID                         0x560D43 // (0x560D42 + 1)
#define CARR_S5K3L6_SENSOR_ID                          0x30C7 // (0x30C6 + 1)
#define CARR_IMX355_SENSOR_ID                          0x0359 //(0x355 + 4)
#define CARR_GC02M1B_SENSOR_ID                         0x02e3 // (0x02e0 + 3)
#define CARR_OV02B10_SENSOR_ID                         0x002C // (0x002B + 1)
#define CARR_GC02M1_SENSOR_ID                          0x02e4 // (0x02e0 + 4)
#define SENSOR_DRVNAME_OV13B10_MIPI_RAW_CARR           "ov13b10_mipi_raw_carr"
#define SENSOR_DRVNAME_S5K3L6_MIPI_RAW_CARR            "s5k3l6_mipi_raw_carr"
#define SENSOR_DRVNAME_IMX355_MIPI_RAW_CARR            "imx355_mipi_raw_carr"
#define SENSOR_DRVNAME_GC02M1B_MIPI_MONO_CARR          "gc02m1b_mipi_mono_carr"
#define SENSOR_DRVNAME_OV02B10_MIPI_RAW_CARR           "ov02b10_mipi_raw_carr"
#define SENSOR_DRVNAME_GC02M1_MIPI_RAW_CARR            "gc02m1_mipi_raw_carr"
#define S5KGM1ST_SENSOR_ID_ODINA                       0xF8D3 // (0xF8D1 + 1)
#define IMX355_SENSOR_ID_ODINA                         0x357  // (0x355 + 1)
#define GC02M1B_SENSOR_ID_ODINA                        0x02e6 // (0x02e0 + 5)
#define OV02B10_SENSOR_ID_ODINA                        0x002E // (0x002B + 2)
#define SENSOR_DRVNAME_S5KGM1ST_MIPI_RAW_ODINA      "s5kgm1st_mipi_raw_odina"
#define SENSOR_DRVNAME_IMX355_MIPI_RAW_ODINA         "imx355_mipi_raw_odina"
#define SENSOR_DRVNAME_GC02M1B_MIPI_MONO_ODINA       "gc02m1b_mipi_mono_odina"
#define SENSOR_DRVNAME_OV02B10_MIPI_RAW_ODINA       "ov02b10_mipi_raw_odina"

#define OV64B_SENSOR_ID_21651                         0x5668 /*0x5665+3*/
#define SENSOR_DRVNAME_OV64B_MIPI_RAW_21651           "ov64b_mipi_raw_21651"
#define IMX471_SENSOR_ID_21651                        0x20003 /*0x20000+3*/
#define SENSOR_DRVNAME_IMX471_MIPI_RAW_21651          "imx471_mipi_raw_21651"
#define IMX355_SENSOR_ID_21651                        0x357  // (0x355 + 2)
#define SENSOR_DRVNAME_IMX355_MIPI_RAW_21651          "imx355_mipi_raw_21651"
#define GC02M1_SENSOR_ID_21651                        0x02e6 /*0x02e0+6*/
#define SENSOR_DRVNAME_GC02M1_MIPI_RAW_21651          "gc02m1_mipi_raw_21651"

/*aladdin*/
#define ALADDIN_OV50D40_SENSOR_ID                  0x565044
#define SENSOR_DRVNAME_ALADDIN_OV50D40              "aladdin_ov50d40"
#define ALADDIN_OV08D10_SENSOR_ID                  0x5608470B /*0x5608470B+B*/
#define SENSOR_DRVNAME_ALADDIN_OV08D10              "aladdin_ov08d10"
#define ALADDIN_OV02B1B_SENSOR_ID                  0x003A/*0x2B + F*/
#define SENSOR_DRVNAME_ALADDIN_OV02B1B             "aladdin_ov02b1b"

/*atom*/
#define ATOM_OV50D40_SENSOR_ID                  0x565045/*0x565045 + 1*/
#define SENSOR_DRVNAME_ATOM_OV50D40              "atom_ov50d40"
#define ATOM_OV02B1B_SENSOR_ID                  0x003B/*0x2B + 0x10*/
#define SENSOR_DRVNAME_ATOM_OV02B1B              "atom_ov02b1b"
#define ATOM_IMX355_SENSOR_ID                   0x35A /*0x355 + 5*/
#define SENSOR_DRVNAME_ATOM_IMX355              "atom_imx355"
#define ATOM_S5K5E9YX04_SENSOR_ID               0x559D /*0x559b + 2*/
#define SENSOR_DRVNAME_ATOM_S5K5E9YX04          "atom_s5k5e9yx04"
#define ATOM_22365_OV02B1B_SENSOR_ID            0x003C/*0x2B + 0x11*/
#define SENSOR_DRVNAME_ATOM_22365_OV02B1B       "atom_22365_ov02b1b"

/*miami*/
#define MIAMI_OV64B_SENSOR_ID                   0x5664
#define SENSOR_DRVNAME_MIAMI_OV64B              "miami_ov64b"
#define MIAMI_AAC2_OV64B_SENSOR_ID              0x5665
#define SENSOR_DRVNAME_MIAMI_AAC2_OV64B         "miami_aac2_ov64b"
#define MIAMI_S5KJN1_SENSOR_ID                  0x38E1
#define SENSOR_DRVNAME_MIAMI_S5KJN1             "miami_s5kjn1"
#define MIAMI_SC800CS_SENSOR_ID                 0xD126
#define SENSOR_DRVNAME_SC800CS_MIPI_RAW_MIAMI   "miami_sc800cs"
#define MIAMI_OV8856_SENSOR_ID                  0x885A
#define SENSOR_DRVNAME_OV8856_MIPI_RAW_MIAMI    "miami_ov8856"
#define MIAMI_GC02M1_SENSOR_ID                  0x2E0
#define SENSOR_DRVNAME_MIAMI_GC02M1             "miami_gc02m1"
#define MIAMI_SP2507_SENSOR_ID                   0x002B
#define SENSOR_DRVNAME_MIAMI_SP2507             "miami_sp2507"

/*Ark_23618*/
#define HI5022Q_SENSOR_ID23618                 0x5023
#define SENSOR_DRVNAME_HI5022Q_MIPI_RAW23618   "hi5022q_mipi_raw23618"
#define SC820CS_SENSOR_ID23618                 0xD154
#define SENSOR_DRVNAME_SC820CS_MIPI_RAW23618   "sc820cs_mipi_raw23618"

#define ATHENSD_S5KGW3_SENSOR_ID                        0x730A
#define ATHENSD_S5KGW3P1_SENSOR_ID                      0x730C
#define ATHENSD_IMX471_SENSOR_ID                        0x473
#define ATHENSD_HI846_SENSOR_ID                         0x0842
#define ATHENSD_GC02K_SENSOR_ID                         0x2398

#define SENSOR_DRVNAME_S5KGW3_MIPI_RAW_ATHENSD          "s5kgw3_mipi_raw_athensd"
#define SENSOR_DRVNAME_S5KGW3P1_MIPI_RAW_ATHENSD        "s5kgw3p1_mipi_raw_athensd"
#define SENSOR_DRVNAME_IMX471_MIPI_RAW_ATHENSD          "imx471_mipi_raw_athensd"
#define SENSOR_DRVNAME_HI846_MIPI_RAW_ATHENSD           "hi846_mipi_raw_athensd"
#define SENSOR_DRVNAME_GC02K_MIPI_RAW_ATHENSD           "gc02k_mipi_raw_athensd"


#define SENSOR_ID_OFFSET_21015                  0xE000
#define IMX709_SENSOR_ID_21015                  (0x0709 + SENSOR_ID_OFFSET_21015)
#define SENSOR_DRVNAME_IMX709_MIPI_RAW_21015    "imx709_mipi_raw21015"
#define IMX766_SENSOR_ID_21015                  (0x0766 + SENSOR_ID_OFFSET_21015)
#define SENSOR_DRVNAME_IMX766_MIPI_RAW_21015    "imx766_mipi_raw21015"
#define IMX355_SENSOR_ID_21015                  (0x0355 + SENSOR_ID_OFFSET_21015)
#define SENSOR_DRVNAME_IMX355_MIPI_RAW_21015    "imx355_mipi_raw21015"
#define OV02B10_SENSOR_ID_21015                 (0x002B + SENSOR_ID_OFFSET_21015)
#define SENSOR_DRVNAME_OV02B10_MIPI_RAW_21015   "ov02b10_mipi_raw21015"
#define IMX709_MONO_SENSOR_ID_21015              0xF709
#define SENSOR_DRVNAME_IMX709_MIPI_MONO_21015    "imx709_mipi_mono21015"
#define OV50A_SENSOR_ID                               (0x5650)
#define SENSOR_ID_OFFSET_21127                        (0x10000)
#define OV50A_SENSOR_ID_21127                         (OV50A_SENSOR_ID + SENSOR_ID_OFFSET_21127)
#define SENSOR_DRVNAME_OV50A_MIPI_RAW_21127           "ov50a_mipi_raw_21127"
#define IMX471_SENSOR_ID_21127                        (IMX471_SENSOR_ID + SENSOR_ID_OFFSET_21127) /*0x20000*/
#define SENSOR_DRVNAME_IMX471_MIPI_RAW_21127          "imx471_mipi_raw_21127"
#define IMX709_SENSOR_ID_21127                        (IMX709_SENSOR_ID + SENSOR_ID_OFFSET_21127)
#define SENSOR_DRVNAME_IMX709_MIPI_RAW_21127          "imx709_mipi_raw_21127"
#define GC02M1B_SENSOR_ID_21127                       (GC02M1B_SENSOR_ID + SENSOR_ID_OFFSET_21127)
#define SENSOR_DRVNAME_GC02M1B_MIPI_MONO_21127        "gc02m1b_mipi_mono_21127"

#define SENSOR_ID_OFFSET_21305                      (0x10)
#define IMX766_SENSOR_ID_21305                      (IMX766_SENSOR_ID + SENSOR_ID_OFFSET_21305)
#define SENSOR_DRVNAME_IMX766_MIPI_RAW_21305        "imx766_mipi_raw_21305"
#define IMX615_SENSOR_ID_21305                      (IMX615_SENSOR_ID + SENSOR_ID_OFFSET_21305) /*0x20000*/
#define SENSOR_DRVNAME_IMX615_MIPI_RAW_21305        "imx615_mipi_raw_21305"
#define IMX709_SENSOR_ID_21305                      (IMX709_SENSOR_ID + SENSOR_ID_OFFSET_21305)
#define SENSOR_DRVNAME_IMX709_MIPI_RAW_21305        "imx709_mipi_raw_21305"
#define IMX355_SENSOR_ID_21305                      (IMX355_SENSOR_ID + SENSOR_ID_OFFSET_21305)
#define SENSOR_DRVNAME_IMX355_MIPI_RAW_21305        "imx355_mipi_raw_21305"
#define GC02M1_SENSOR_ID                            0x02e0
#define GC02M1_SENSOR_ID_21305                      (GC02M1_SENSOR_ID + SENSOR_ID_OFFSET_21305)
#define SENSOR_DRVNAME_GC02M1_MIPI_RAW_21305        "gc02m1_mipi_raw_21305"

#define IMX686Q2R_SENSOR_ID                        0X0686
#define SENSOR_DRVNAME_IMX686Q2R_MIPI_RAW          "imx686q2r_mipi_raw"
#define HI846Q2R_SENSOR_ID                         0x0846
#define SENSOR_DRVNAME_HI846Q2R_MIPI_RAW           "hi846q2r_mipi_raw"
#define S5KGD1SPQ2R_SENSOR_ID                      0x0841
#define SENSOR_DRVNAME_S5KGD1SPQ2R_MIPI_RAW        "s5kgd1spq2r_mipi_raw"
#define IMX616Q2R_SENSOR_ID                        0x0616
#define SENSOR_DRVNAME_IMX616Q2R_MIPI_RAW          "imx616q2r_mipi_raw"
#define GC02M0_SENSOR_ID                        0x02d0
#define GC02M0_SENSOR_ID1                       0x02d1
#define SENSOR_DRVNAME_GC02M0B_MIPI_MONO        "gc02m0b_mipi_mono"
#define SENSOR_DRVNAME_GC02M0B_MIPI_MONO1       "gc02m0b_mipi_mono1"

#define S5KGM1ST_SENSOR_ID_20611                0xF8D9
//#define OV16A10_SENSOR_ID_20611                 0x561642
#define S5K3P9SP_SENSOR_ID_20611                0x310B
#define HI846_SENSOR_ID_20611                   0x084A
#define GC02K_SENSOR_ID_20611                   0x2397
#define OV02B1B_SENSOR_ID_20611                 0x0031

#define SENSOR_DRVNAME_S5KGM1ST_MIPI_RAW_20611  "s5kgm1st_mipi_raw_20611"
//#define SENSOR_DRVNAME_OV16A10_MIPI_RAW_20611   "ov16a10_mipi_raw_20611"
#define SENSOR_DRVNAME_S5K3P9SP_MIPI_RAW_20611  "s5k3p9sp_mipi_raw_20611"
#define SENSOR_DRVNAME_HI846_MIPI_RAW_20611     "hi846_mipi_raw_20611"
#define SENSOR_DRVNAME_GC02K_MIPI_RAW_20611     "gc02k_mipi_raw_20611"
#define SENSOR_DRVNAME_OV02B1B_MIPI_RAW_20611   "ov02b1b_mipi_raw_20611"

#define OV02B10_SENSOR_ID_APOLLOW                      0x0032 // (0x002B + 7)
#define OV02B1B_SENSOR_ID_APOLLOW                      0x0033 // (0x002B + 8)
#define OV64B_SENSOR_ID_APOLLOW                        0x5666 // (0x5664 + 2)
#define S5K3P9SP_SENSOR_ID_APOLLOW                     0x310E //(0x310C + 2)
#define SENSOR_DRVNAME_OV02B10_MIPI_RAW_APOLLOW          "ov02b10_mipi_raw_apollow"
#define SENSOR_DRVNAME_OV02B1B_MIPI_MONO_APOLLOW         "ov02b1b_mipi_mono_apollow"
#define SENSOR_DRVNAME_OV64B_MIPI_RAW_APOLLOW            "ov64b_mipi_raw_apollow"
#define SENSOR_DRVNAME_S5K3P9SP_MIPI_RAW_APOLLOW         "s5k3p9sp_mipi_raw_apollow"

//chanel
#define SENSOR_ID_OFFSET_22277                         0x20

#define OV32C_SENSOR_ID22277                         (0x3243 + SENSOR_ID_OFFSET_22277)
#define SENSOR_DRVNAME_OV32C_MIPI_RAW22277           "ov32c_mipi_raw22277"
#define IMX355_SENSOR_ID22277                        (0x0355 + SENSOR_ID_OFFSET_22277)
#define SENSOR_DRVNAME_IMX355_MIPI_RAW22277          "imx355_mipi_raw22277"
#define OV64B_SENSOR_ID22277                        (0x5664 + SENSOR_ID_OFFSET_22277)
#define SENSOR_DRVNAME_OV64B_MIPI_RAW22277          "ov64b_mipi_raw22277"
#define IMX709_SENSOR_ID22277                        (0x0709 + SENSOR_ID_OFFSET_22277)
#define SENSOR_DRVNAME_IMX709_MIPI_RAW22277          "imx709_mipi_raw22277"

//Givenchy
#define SENSOR_ID_OFFSET_23031                       0x21
#define OV64B_SENSOR_ID23031                         (0x5664 + SENSOR_ID_OFFSET_23031)
#define SENSOR_DRVNAME_OV64B_MIPI_RAW23031           "ov64b_mipi_raw23031"
#define OV08D_SENSOR_ID23031                         (0x56084700 + SENSOR_ID_OFFSET_23031)
#define SENSOR_DRVNAME_OV08D_MIPI_RAW23031           "ov08d_mipi_raw23031"
#define GC02M1_SENSOR_ID23031                        (0x02e0 + SENSOR_ID_OFFSET_23031)
#define SENSOR_DRVNAME_GC02M1_MIPI_RAW23031          "gc02m1_mipi_raw23031"
//Oris-c
#define OV50D40_SENSOR_ID_ORISC                      (0x565044 + 0x4)//0x565048
#define SENSOR_DRVNAME_OV50D40_MIPI_RAW_ORISC        "ov50d40_mipi_raw_orisc"
//Oris-a
#define OV50D40_SENSOR_ID_ORIS                      (0x565044 + 0x3)//0x565047
#define SENSOR_DRVNAME_OV50D40_MIPI_RAW_ORIS        "ov50d40_mipi_raw_oris"
#define GC05A2_SENSOR_ID_ORIS                        0x05A2
#define SENSOR_DRVNAME_GC05A2_MIPI_RAW               "gc05a2_mipi_raw"
#define HI846_SENSOR_ID_ORIS                        (0x846 + 0x1)//0x847
#define SENSOR_DRVNAME_HI846_MIPI_RAW_ORIS          "hi846_mipi_raw_oris"

//Burberry
#define SENSOR_ID_OFFSET_23231                       0x22
#define OV32C_SENSOR_ID23231                         (0x3243 + SENSOR_ID_OFFSET_23231)
#define SENSOR_DRVNAME_OV32C_MIPI_RAW23231           "ov32c_mipi_raw23231"
#define IMX355_SENSOR_ID23231                        (0x0355 + SENSOR_ID_OFFSET_23231)
#define SENSOR_DRVNAME_IMX355_MIPI_RAW23231          "imx355_mipi_raw23231"
#define IMX709_SENSOR_ID23231                        (0x0709 + SENSOR_ID_OFFSET_23231)
#define SENSOR_DRVNAME_IMX709_MIPI_RAW23231          "imx709_mipi_raw23231"
#define IMX882_SENSOR_ID23231                        (0x0882 + SENSOR_ID_OFFSET_23231)
#define SENSOR_DRVNAME_IMX882_MIPI_RAW23231          "imx882_mipi_raw23231"
#define IMX882PD_SENSOR_ID23231                      (0x0882 + 0x23)
#define SENSOR_DRVNAME_IMX882PD_MIPI_RAW23231        "imx882pd_mipi_raw23231"

//Magellan
#define SENSOR_ID_OFFSET_23051                       0x23
#define OV64B_SENSOR_ID23051                         (0x5664 + SENSOR_ID_OFFSET_23051)
#define SENSOR_DRVNAME_OV64B_MIPI_RAW23051           "ov64b_mipi_raw23051"
#define IMX355_SENSOR_ID23051                        (0x0355 + SENSOR_ID_OFFSET_23051)
#define SENSOR_DRVNAME_IMX355_MIPI_RAW23051          "imx355_mipi_raw23051"
#define IMX615_SENSOR_ID23051                        (0x0615 + SENSOR_ID_OFFSET_23051)
#define SENSOR_DRVNAME_IMX615_MIPI_RAW23051          "imx615_mipi_raw23051"
#define OV02B10_SENSOR_ID23051                       (0x002B + SENSOR_ID_OFFSET_23051)
#define SENSOR_DRVNAME_OV02B10_MIPI_RAW23051         "ov02b10_mipi_raw23051"

//Avatar
#define SENSOR_ID_OFFSET_23035                       0x24
#define OV64B_SENSOR_ID23035                         (0x5664 + SENSOR_ID_OFFSET_23035)
#define SENSOR_DRVNAME_OV64B_MIPI_RAW23035           "ov64b_mipi_raw23035"
#define OV08D_SENSOR_ID23035                         (0x56084700 + SENSOR_ID_OFFSET_23035)
#define SENSOR_DRVNAME_OV08D_MIPI_RAW23035           "ov08d_mipi_raw23035"
#define OV02B1B_SENSOR_ID23035                       (0x2B + SENSOR_ID_OFFSET_23035)
#define SENSOR_DRVNAME_OV02B1B_MIPI_RAW23035         "ov02b1b_mipi_raw23035"


/************************************
 * I3C SENSOR PID (TOTAL 48-BITS)
 ************************************/
/* SONY */
#define IMX866RGB_I3C_PID							0x036008660000


/************************************
 * ADD I3C SENSOR To TABLE
 ************************************/
static const struct i3c_device_id mtk_i3c_id_table[] = {
	PID_TO_I3C_DEV(IMX866RGB_I3C_PID),
	{ /* Sentinel, Don't remove this. */ },
};


/******************************************************************************
 *
 ******************************************************************************/
void KD_IMGSENSOR_PROFILE_INIT(void);
void KD_IMGSENSOR_PROFILE(char *tag);
void KD_IMGSENSOR_PROFILE_INIT_I2C(void);
void KD_IMGSENSOR_PROFILE_I2C(char *tag, int trans_num);

#define mDELAY(ms)     mdelay(ms)
#define uDELAY(us)       udelay(us)
#endif              /* _KD_IMGSENSOR_H */
