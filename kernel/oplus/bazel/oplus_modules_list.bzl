# SPDX-License-Identifier: GPL-2.0
# Copyright (C) 2022 The Android Open Source Project

"""
This module contains a full list of kernel modules
 compiled by GKI.
"""
"""
Format：[PATH:KO_NAME],
"""

load("@mgk_info//:dict.bzl","OPLUS_FEATURES")

load("@mgk_info//:dict.bzl",
    "DEFCONFIG_OVERLAYS",
)

COMMON_OPLUS_MODULES_LIST = []  # neutered 2026-05-22 for camellia (refs subdirs we don't have)

"""
将以 OPLUS_FEATURE_ 打头的环境变量转换为字典
"""
def oplus_ddk_get_oplus_features():
   oplus_feature_list = {}
   for o in OPLUS_FEATURES.split(" "):
       lst = o.split('=')
       if len(lst) != 2:
           # print('info: environment variable [%s]' % o)
           continue
       oplus_feature_list[lst[0]] = lst[1]

   print("oplus_feature_list:", oplus_feature_list)
   return oplus_feature_list

"""
这个函数用于处理条件编译能力
条件需要与 define_oplus_ddk_module 中的条件一致
"""
def oplus_ddk_get_oplus_modules_list(
   name = "ddk_remove_from_dist",
   mods = {
       "pseudo_sensor":
           {"OPLUS_FEATURE_BSP_DRV_INJECT_TEST": "1"},

       "//vendor/oplus/sensor/kernel/sensorhub:pseudo_sensor":
           {"OPLUS_FEATURE_BSP_DRV_INJECT_TEST": "1"},

       "oplus_inject":
           {"OPLUS_FEATURE_BSP_DRV_INJECT_TEST": "1"},

       "oplus_inject_aw8692x":
           {"OPLUS_FEATURE_BSP_DRV_INJECT_TEST": "1"},
   }
):
   # 对来自环境变量的 OPLUS_FEATURES 进行解码
   oplus_feature_list = oplus_ddk_get_oplus_features()

   lst = []
   for item in COMMON_OPLUS_MODULES_LIST:
       # 根据全名或模块名进行匹配
       key1 = item
       key2 = "foofppfqq"
       if ":" in item:
           key2 = item.split(':')[1]

       # 获取比较条件
       if key1 in mods:
           conditional_build = mods[key1]
       elif key2 in mods:
           conditional_build = mods[key2]
       else:
           conditional_build = None

       if conditional_build:
           # 对条件进行处理
           build_me = 1
           for k in conditional_build:
               v = conditional_build[k]
               sv1 = str(v).upper()
               sv2 = str(oplus_feature_list.get(k, 'foo')).upper()
               if sv1 != sv2:
                   build_me = 0

           if build_me == 0:
               print("Remove: %s" % item)
           else:
               print("Add: %s" % item)
               lst.append(item)
       else:
           # 无需处理
           lst.append(item)

   return lst

def get_overlay_modules_list():
    if "mt6768_overlay.config" in DEFCONFIG_OVERLAYS:
        COMMON_OPLUS_MODULES_LIST.remove("//vendor/oplus/sensor/kernel/sensorhub/oplus_sensor_devinfo:oplus_sensor_deviceinfo")
        COMMON_OPLUS_MODULES_LIST.remove("//vendor/oplus/sensor/kernel/sensorhub/oplus_sensor_feedback:oplus_sensor_feedback")

get_overlay_modules_list()

