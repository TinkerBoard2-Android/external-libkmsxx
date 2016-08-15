/* From Linux kernel: drm_edid.c */
/*
 * Copyright (c) 2006 Luc Verhaegen (quirks list)
 * Copyright (c) 2007-2008 Intel Corporation
 *   Jesse Barnes <jesse.barnes@intel.com>
 * Copyright 2010 Red Hat, Inc.
 *
 * DDC probing routines (drm_ddc_read & drm_do_probe_ddc_edid) originally from
 * FB layer.
 *   Copyright (C) 2006 Dennis Munsie <dmunsie@cecropia.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sub license,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <kms++/modedb.h>

#include <xf86drm.h>

namespace kms
{

#define DIV_ROUND(n, d) (((n) + (d) / 2) / (d))

#define DRM_MODE(nm, c, hd, hss, hse, ht, hsk, vd, vss, vse, vt, vs, f) \
	.name = nm, .clock = (c), \
	.hdisplay = (hd), .hsync_start = (hss), .hsync_end = (hse), .htotal = (ht), .hskew = (hsk), \
	.vdisplay = (vd), .vsync_start = (vss), .vsync_end = (vse), .vtotal = (vt), .vscan = (vs), \
	.vrefresh = DIV_ROUND(c * 1000, ht * vt) * (((f) & DRM_MODE_FLAG_INTERLACE) ? 2 : 1), \
	.flags = (f), .type = 0

/*
 * Autogenerated from the DMT spec.
 * This table is copied from xfree86/modes/xf86EdidModes.c.
 */
const Videomode dmt_modes[] = {
	/* 0x01 - 640x350@85Hz */
	{ DRM_MODE("640x350", 31500, 640, 672,
	  736, 832, 0, 350, 382, 385, 445, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x02 - 640x400@85Hz */
	{ DRM_MODE("640x400", 31500, 640, 672,
	  736, 832, 0, 400, 401, 404, 445, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x03 - 720x400@85Hz */
	{ DRM_MODE("720x400", 35500, 720, 756,
	  828, 936, 0, 400, 401, 404, 446, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x04 - 640x480@60Hz */
	{ DRM_MODE("640x480", 25175, 640, 656,
	  752, 800, 0, 480, 490, 492, 525, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x05 - 640x480@72Hz */
	{ DRM_MODE("640x480", 31500, 640, 664,
	  704, 832, 0, 480, 489, 492, 520, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x06 - 640x480@75Hz */
	{ DRM_MODE("640x480", 31500, 640, 656,
	  720, 840, 0, 480, 481, 484, 500, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x07 - 640x480@85Hz */
	{ DRM_MODE("640x480", 36000, 640, 696,
	  752, 832, 0, 480, 481, 484, 509, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x08 - 800x600@56Hz */
	{ DRM_MODE("800x600", 36000, 800, 824,
	  896, 1024, 0, 600, 601, 603, 625, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x09 - 800x600@60Hz */
	{ DRM_MODE("800x600", 40000, 800, 840,
	  968, 1056, 0, 600, 601, 605, 628, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x0a - 800x600@72Hz */
	{ DRM_MODE("800x600", 50000, 800, 856,
	  976, 1040, 0, 600, 637, 643, 666, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x0b - 800x600@75Hz */
	{ DRM_MODE("800x600", 49500, 800, 816,
	  896, 1056, 0, 600, 601, 604, 625, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x0c - 800x600@85Hz */
	{ DRM_MODE("800x600", 56250, 800, 832,
	  896, 1048, 0, 600, 601, 604, 631, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x0d - 800x600@120Hz RB */
	{ DRM_MODE("800x600", 73250, 800, 848,
	  880, 960, 0, 600, 603, 607, 636, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x0e - 848x480@60Hz */
	{ DRM_MODE("848x480", 33750, 848, 864,
	  976, 1088, 0, 480, 486, 494, 517, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x0f - 1024x768@43Hz, interlace */
	{ DRM_MODE("1024x768i", 44900, 1024, 1032,
	  1208, 1264, 0, 768, 768, 772, 817, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC |
	  DRM_MODE_FLAG_INTERLACE) },
	/* 0x10 - 1024x768@60Hz */
	{ DRM_MODE("1024x768", 65000, 1024, 1048,
	  1184, 1344, 0, 768, 771, 777, 806, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x11 - 1024x768@70Hz */
	{ DRM_MODE("1024x768", 75000, 1024, 1048,
	  1184, 1328, 0, 768, 771, 777, 806, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x12 - 1024x768@75Hz */
	{ DRM_MODE("1024x768", 78750, 1024, 1040,
	  1136, 1312, 0, 768, 769, 772, 800, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x13 - 1024x768@85Hz */
	{ DRM_MODE("1024x768", 94500, 1024, 1072,
	  1168, 1376, 0, 768, 769, 772, 808, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x14 - 1024x768@120Hz RB */
	{ DRM_MODE("1024x768", 115500, 1024, 1072,
	  1104, 1184, 0, 768, 771, 775, 813, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x15 - 1152x864@75Hz */
	{ DRM_MODE("1152x864", 108000, 1152, 1216,
	  1344, 1600, 0, 864, 865, 868, 900, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x55 - 1280x720@60Hz */
	{ DRM_MODE("1280x720", 74250, 1280, 1390,
	  1430, 1650, 0, 720, 725, 730, 750, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x16 - 1280x768@60Hz RB */
	{ DRM_MODE("1280x768", 68250, 1280, 1328,
	  1360, 1440, 0, 768, 771, 778, 790, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x17 - 1280x768@60Hz */
	{ DRM_MODE("1280x768", 79500, 1280, 1344,
	  1472, 1664, 0, 768, 771, 778, 798, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x18 - 1280x768@75Hz */
	{ DRM_MODE("1280x768", 102250, 1280, 1360,
	  1488, 1696, 0, 768, 771, 778, 805, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x19 - 1280x768@85Hz */
	{ DRM_MODE("1280x768", 117500, 1280, 1360,
	  1496, 1712, 0, 768, 771, 778, 809, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x1a - 1280x768@120Hz RB */
	{ DRM_MODE("1280x768", 140250, 1280, 1328,
	  1360, 1440, 0, 768, 771, 778, 813, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x1b - 1280x800@60Hz RB */
	{ DRM_MODE("1280x800", 71000, 1280, 1328,
	  1360, 1440, 0, 800, 803, 809, 823, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x1c - 1280x800@60Hz */
	{ DRM_MODE("1280x800", 83500, 1280, 1352,
	  1480, 1680, 0, 800, 803, 809, 831, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x1d - 1280x800@75Hz */
	{ DRM_MODE("1280x800", 106500, 1280, 1360,
	  1488, 1696, 0, 800, 803, 809, 838, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x1e - 1280x800@85Hz */
	{ DRM_MODE("1280x800", 122500, 1280, 1360,
	  1496, 1712, 0, 800, 803, 809, 843, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x1f - 1280x800@120Hz RB */
	{ DRM_MODE("1280x800", 146250, 1280, 1328,
	  1360, 1440, 0, 800, 803, 809, 847, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x20 - 1280x960@60Hz */
	{ DRM_MODE("1280x960", 108000, 1280, 1376,
	  1488, 1800, 0, 960, 961, 964, 1000, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x21 - 1280x960@85Hz */
	{ DRM_MODE("1280x960", 148500, 1280, 1344,
	  1504, 1728, 0, 960, 961, 964, 1011, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x22 - 1280x960@120Hz RB */
	{ DRM_MODE("1280x960", 175500, 1280, 1328,
	  1360, 1440, 0, 960, 963, 967, 1017, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x23 - 1280x1024@60Hz */
	{ DRM_MODE("1280x1024", 108000, 1280, 1328,
	  1440, 1688, 0, 1024, 1025, 1028, 1066, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x24 - 1280x1024@75Hz */
	{ DRM_MODE("1280x1024", 135000, 1280, 1296,
	  1440, 1688, 0, 1024, 1025, 1028, 1066, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x25 - 1280x1024@85Hz */
	{ DRM_MODE("1280x1024", 157500, 1280, 1344,
	  1504, 1728, 0, 1024, 1025, 1028, 1072, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x26 - 1280x1024@120Hz RB */
	{ DRM_MODE("1280x1024", 187250, 1280, 1328,
	  1360, 1440, 0, 1024, 1027, 1034, 1084, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x27 - 1360x768@60Hz */
	{ DRM_MODE("1360x768", 85500, 1360, 1424,
	  1536, 1792, 0, 768, 771, 777, 795, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x28 - 1360x768@120Hz RB */
	{ DRM_MODE("1360x768", 148250, 1360, 1408,
	  1440, 1520, 0, 768, 771, 776, 813, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x51 - 1366x768@60Hz */
	{ DRM_MODE("1366x768", 85500, 1366, 1436,
	  1579, 1792, 0, 768, 771, 774, 798, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x56 - 1366x768@60Hz */
	{ DRM_MODE("1366x768", 72000, 1366, 1380,
	  1436, 1500, 0, 768, 769, 772, 800, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x29 - 1400x1050@60Hz RB */
	{ DRM_MODE("1400x1050", 101000, 1400, 1448,
	  1480, 1560, 0, 1050, 1053, 1057, 1080, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x2a - 1400x1050@60Hz */
	{ DRM_MODE("1400x1050", 121750, 1400, 1488,
	  1632, 1864, 0, 1050, 1053, 1057, 1089, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x2b - 1400x1050@75Hz */
	{ DRM_MODE("1400x1050", 156000, 1400, 1504,
	  1648, 1896, 0, 1050, 1053, 1057, 1099, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x2c - 1400x1050@85Hz */
	{ DRM_MODE("1400x1050", 179500, 1400, 1504,
	  1656, 1912, 0, 1050, 1053, 1057, 1105, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x2d - 1400x1050@120Hz RB */
	{ DRM_MODE("1400x1050", 208000, 1400, 1448,
	  1480, 1560, 0, 1050, 1053, 1057, 1112, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x2e - 1440x900@60Hz RB */
	{ DRM_MODE("1440x900", 88750, 1440, 1488,
	  1520, 1600, 0, 900, 903, 909, 926, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x2f - 1440x900@60Hz */
	{ DRM_MODE("1440x900", 106500, 1440, 1520,
	  1672, 1904, 0, 900, 903, 909, 934, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x30 - 1440x900@75Hz */
	{ DRM_MODE("1440x900", 136750, 1440, 1536,
	  1688, 1936, 0, 900, 903, 909, 942, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x31 - 1440x900@85Hz */
	{ DRM_MODE("1440x900", 157000, 1440, 1544,
	  1696, 1952, 0, 900, 903, 909, 948, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x32 - 1440x900@120Hz RB */
	{ DRM_MODE("1440x900", 182750, 1440, 1488,
	  1520, 1600, 0, 900, 903, 909, 953, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x53 - 1600x900@60Hz */
	{ DRM_MODE("1600x900", 108000, 1600, 1624,
	  1704, 1800, 0, 900, 901, 904, 1000, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x33 - 1600x1200@60Hz */
	{ DRM_MODE("1600x1200", 162000, 1600, 1664,
	  1856, 2160, 0, 1200, 1201, 1204, 1250, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x34 - 1600x1200@65Hz */
	{ DRM_MODE("1600x1200", 175500, 1600, 1664,
	  1856, 2160, 0, 1200, 1201, 1204, 1250, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x35 - 1600x1200@70Hz */
	{ DRM_MODE("1600x1200", 189000, 1600, 1664,
	  1856, 2160, 0, 1200, 1201, 1204, 1250, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x36 - 1600x1200@75Hz */
	{ DRM_MODE("1600x1200", 202500, 1600, 1664,
	  1856, 2160, 0, 1200, 1201, 1204, 1250, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x37 - 1600x1200@85Hz */
	{ DRM_MODE("1600x1200", 229500, 1600, 1664,
	  1856, 2160, 0, 1200, 1201, 1204, 1250, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x38 - 1600x1200@120Hz RB */
	{ DRM_MODE("1600x1200", 268250, 1600, 1648,
	  1680, 1760, 0, 1200, 1203, 1207, 1271, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x39 - 1680x1050@60Hz RB */
	{ DRM_MODE("1680x1050", 119000, 1680, 1728,
	  1760, 1840, 0, 1050, 1053, 1059, 1080, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x3a - 1680x1050@60Hz */
	{ DRM_MODE("1680x1050", 146250, 1680, 1784,
	  1960, 2240, 0, 1050, 1053, 1059, 1089, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x3b - 1680x1050@75Hz */
	{ DRM_MODE("1680x1050", 187000, 1680, 1800,
	  1976, 2272, 0, 1050, 1053, 1059, 1099, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x3c - 1680x1050@85Hz */
	{ DRM_MODE("1680x1050", 214750, 1680, 1808,
	  1984, 2288, 0, 1050, 1053, 1059, 1105, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x3d - 1680x1050@120Hz RB */
	{ DRM_MODE("1680x1050", 245500, 1680, 1728,
	  1760, 1840, 0, 1050, 1053, 1059, 1112, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x3e - 1792x1344@60Hz */
	{ DRM_MODE("1792x1344", 204750, 1792, 1920,
	  2120, 2448, 0, 1344, 1345, 1348, 1394, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x3f - 1792x1344@75Hz */
	{ DRM_MODE("1792x1344", 261000, 1792, 1888,
	  2104, 2456, 0, 1344, 1345, 1348, 1417, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x40 - 1792x1344@120Hz RB */
	{ DRM_MODE("1792x1344", 333250, 1792, 1840,
	  1872, 1952, 0, 1344, 1347, 1351, 1423, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x41 - 1856x1392@60Hz */
	{ DRM_MODE("1856x1392", 218250, 1856, 1952,
	  2176, 2528, 0, 1392, 1393, 1396, 1439, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x42 - 1856x1392@75Hz */
	{ DRM_MODE("1856x1392", 288000, 1856, 1984,
	  2208, 2560, 0, 1392, 1393, 1396, 1500, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x43 - 1856x1392@120Hz RB */
	{ DRM_MODE("1856x1392", 356500, 1856, 1904,
	  1936, 2016, 0, 1392, 1395, 1399, 1474, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x52 - 1920x1080@60Hz */
	{ DRM_MODE("1920x1080", 148500, 1920, 2008,
	  2052, 2200, 0, 1080, 1084, 1089, 1125, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x44 - 1920x1200@60Hz RB */
	{ DRM_MODE("1920x1200", 154000, 1920, 1968,
	  2000, 2080, 0, 1200, 1203, 1209, 1235, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x45 - 1920x1200@60Hz */
	{ DRM_MODE("1920x1200", 193250, 1920, 2056,
	  2256, 2592, 0, 1200, 1203, 1209, 1245, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x46 - 1920x1200@75Hz */
	{ DRM_MODE("1920x1200", 245250, 1920, 2056,
	  2264, 2608, 0, 1200, 1203, 1209, 1255, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x47 - 1920x1200@85Hz */
	{ DRM_MODE("1920x1200", 281250, 1920, 2064,
	  2272, 2624, 0, 1200, 1203, 1209, 1262, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x48 - 1920x1200@120Hz RB */
	{ DRM_MODE("1920x1200", 317000, 1920, 1968,
	  2000, 2080, 0, 1200, 1203, 1209, 1271, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x49 - 1920x1440@60Hz */
	{ DRM_MODE("1920x1440", 234000, 1920, 2048,
	  2256, 2600, 0, 1440, 1441, 1444, 1500, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x4a - 1920x1440@75Hz */
	{ DRM_MODE("1920x1440", 297000, 1920, 2064,
	  2288, 2640, 0, 1440, 1441, 1444, 1500, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x4b - 1920x1440@120Hz RB */
	{ DRM_MODE("1920x1440", 380500, 1920, 1968,
	  2000, 2080, 0, 1440, 1443, 1447, 1525, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x54 - 2048x1152@60Hz */
	{ DRM_MODE("2048x1152", 162000, 2048, 2074,
	  2154, 2250, 0, 1152, 1153, 1156, 1200, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x4c - 2560x1600@60Hz RB */
	{ DRM_MODE("2560x1600", 268500, 2560, 2608,
	  2640, 2720, 0, 1600, 1603, 1609, 1646, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x4d - 2560x1600@60Hz */
	{ DRM_MODE("2560x1600", 348500, 2560, 2752,
	  3032, 3504, 0, 1600, 1603, 1609, 1658, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x4e - 2560x1600@75Hz */
	{ DRM_MODE("2560x1600", 443250, 2560, 2768,
	  3048, 3536, 0, 1600, 1603, 1609, 1672, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x4f - 2560x1600@85Hz */
	{ DRM_MODE("2560x1600", 505250, 2560, 2768,
	  3048, 3536, 0, 1600, 1603, 1609, 1682, 0,
	  DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC) },
	/* 0x50 - 2560x1600@120Hz RB */
	{ DRM_MODE("2560x1600", 552750, 2560, 2608,
	  2640, 2720, 0, 1600, 1603, 1609, 1694, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x57 - 4096x2160@60Hz RB */
	{ DRM_MODE("4096x2160", 556744, 4096, 4104,
	  4136, 4176, 0, 2160, 2208, 2216, 2222, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* 0x58 - 4096x2160@59.94Hz RB */
	{ DRM_MODE("4096x2160", 556188, 4096, 4104,
	  4136, 4176, 0, 2160, 2208, 2216, 2222, 0,
	  DRM_MODE_FLAG_PHSYNC | DRM_MODE_FLAG_NVSYNC) },
	/* TERMINATOR */
	{ },
};

}
