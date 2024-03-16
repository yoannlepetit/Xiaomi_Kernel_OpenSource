/*
 * Copyright (C) 2016 Xiaomi Inc.
 * Copyright (C) 2018 XiaoMi, Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <linux/device.h>

struct LCM_setting_table {
	unsigned cmd;
	unsigned char count;
	unsigned char para_list[64];
};

#define REGFLAG_DELAY           0xFE
#define REGFLAG_END_OF_TABLE    0xFF   /* END OF REGISTERS MARKER */


static struct LCM_setting_table lcm_dsi_dispparam_cabcon_command[] = {
	{0x55, 1, {0x01} },
};

static struct LCM_setting_table lcm_dsi_dispparam_cabcguion_command[] = {
	{0x55, 1, {0x01} },
};

static struct LCM_setting_table lcm_dsi_dispparam_cabcstillon_command[] = {
	{0x55, 1, {0x02} },
};

static struct LCM_setting_table lcm_dsi_dispparam_cabcmovieon_command[] = {
	{0x55, 1, {0x03} },
};

static struct LCM_setting_table lcm_dsi_dispparam_cabcoff_command[] = {
	{0x55, 1, {0x00} },
};

static struct LCM_setting_table lcm_dsi_dispparam_dimmingon_command[] = {
	{0x53, 1, {0x2C} },
};

static struct LCM_setting_table lcm_dsi_dispparam_idleon_command[] = {

};

static struct LCM_setting_table lcm_dsi_dispparam_idleoff_command[] = {

};

static struct LCM_setting_table lcm_dsi_dispparam_warm_command[] = {
	{0xF0, 0x05, {0x55, 0xAA, 0x52, 0x08, 0x02} },
	{REGFLAG_DELAY, 1, {} },
	{0xD1, 0x10, {0x00, 0x00, 0x00, 0x72, 0x00, 0x9D, 0x00, 0xBB, 0x00, 0xD2, 0x00, 0xF7, 0x01, 0x14, 0x01, 0x41} },
	{0xD2, 0x10, {0x01, 0x65, 0x01, 0x9E, 0x01, 0xCA, 0x02, 0x0E, 0x02, 0x44, 0x02, 0x46, 0x02, 0x76, 0x02, 0xAA} },
	{0xD3, 0x10, {0x02, 0xCB, 0x02, 0xF7, 0x03, 0x16, 0x03, 0x43, 0x03, 0x5F, 0x03, 0x82, 0x03, 0x98, 0x03, 0xB4} },
	{0xD4, 0x04, {0x03, 0xEE, 0x03, 0xFF} },
	{REGFLAG_DELAY, 1, {} },
	{0xD5, 0x10, {0x00, 0xD3, 0x00, 0xDD, 0x00, 0xEF, 0x01, 0x01, 0x01, 0x0D, 0x01, 0x29, 0x01, 0x3A, 0x01, 0x61} },
	{0xD6, 0x10, {0x01, 0x7C, 0x01, 0xAF, 0x01, 0xD8, 0x02, 0x15, 0x02, 0x4B, 0x02, 0x4C, 0x02, 0x7A, 0x02, 0xAD} },
	{0xD7, 0x10, {0x02, 0xCE, 0x02, 0xFB, 0x03, 0x1B, 0x03, 0x45, 0x03, 0x60, 0x03, 0x82, 0x03, 0x98, 0x03, 0xB2} },
	{0xD8, 0x04, {0x03, 0xD3, 0x03, 0xFF} },
	{REGFLAG_DELAY, 1, {} },
	{0xD9, 0x10, {0x00, 0xE2, 0x00, 0xE9, 0x00, 0xF7, 0x01, 0x06, 0x01, 0x10, 0x01, 0x29, 0x01, 0x39, 0x01, 0x5E} },
	{0xDD, 0x10, {0x01, 0x78, 0x01, 0xAA, 0x01, 0xD4, 0x02, 0x12, 0x02, 0x48, 0x02, 0x49, 0x02, 0x78, 0x02, 0xAC} },
	{0xDE, 0x10, {0x02, 0xCE, 0x02, 0xFD, 0x03, 0x21, 0x03, 0x5D, 0x03, 0x75, 0x03, 0x8A, 0x03, 0x98, 0x03, 0xAC} },
	{0xDF, 0x04, {0x03, 0xE9, 0x03, 0xFF} },
	{REGFLAG_DELAY, 1, {} },
	{0xE0, 0x10, {0x00, 0x00, 0x00, 0x72, 0x00, 0x9D, 0x00, 0xBB, 0x00, 0xD2, 0x00, 0xF7, 0x01, 0x14, 0x01, 0x41} },
	{0xE1, 0x10, {0x01, 0x65, 0x01, 0x9E, 0x01, 0xCA, 0x02, 0x0E, 0x02, 0x44, 0x02, 0x46, 0x02, 0x76, 0x02, 0xAA} },
	{0xE2, 0x10, {0x02, 0xCB, 0x02, 0xF7, 0x03, 0x16, 0x03, 0x43, 0x03, 0x5F, 0x03, 0x82, 0x03, 0x98, 0x03, 0xB4} },
	{0xE3, 0x04, {0x03, 0xEE, 0x03, 0xFF} },
	{REGFLAG_DELAY, 1, {} },
	{0xE4, 0x10, {0x00, 0xD3, 0x00, 0xDD, 0x00, 0xEF, 0x01, 0x01, 0x01, 0x0D, 0x01, 0x29, 0x01, 0x3A, 0x01, 0x61} },
	{0xE5, 0x10, {0x01, 0x7C, 0x01, 0xAF, 0x01, 0xD8, 0x02, 0x15, 0x02, 0x4B, 0x02, 0x4C, 0x02, 0x7A, 0x02, 0xAD} },
	{0xE6, 0x10, {0x02, 0xCE, 0x02, 0xFB, 0x03, 0x1B, 0x03, 0x45, 0x03, 0x60, 0x03, 0x82, 0x03, 0x98, 0x03, 0xB2} },
	{0xE7, 0x04, {0x03, 0xD3, 0x03, 0xFF} },
	{REGFLAG_DELAY, 1, {} },
	{0xE8, 0x10, {0x00, 0xE2, 0x00, 0xE9, 0x00, 0xF7, 0x01, 0x06, 0x01, 0x10, 0x01, 0x29, 0x01, 0x39, 0x01, 0x5E} },
	{0xE9, 0x10, {0x01, 0x78, 0x01, 0xAA, 0x01, 0xD4, 0x02, 0x12, 0x02, 0x48, 0x02, 0x49, 0x02, 0x78, 0x02, 0xAC} },
	{0xEA, 0x10, {0x02, 0xCE, 0x02, 0xFD, 0x03, 0x21, 0x03, 0x5D, 0x03, 0x75, 0x03, 0x8A, 0x03, 0x98, 0x03, 0xAC} },
	{0xEB, 0x04, {0x03, 0xE9, 0x03, 0xFF} },
	{REGFLAG_DELAY, 1, {} },
	{0xF0, 0x05, {0x55, 0xAA, 0x52, 0x00, 0x00} },
};

static struct LCM_setting_table lcm_dsi_dispparam_normal1_command[] = {

};

static struct LCM_setting_table lcm_dsi_dispparam_normal2_command[] = {

};

static struct LCM_setting_table lcm_dsi_dispparam_cold_command[] = {
	{0xF0, 0x05, {0x55, 0xAA, 0x52, 0x08, 0x02} },
	{REGFLAG_DELAY, 1, {} },
	{0xD1, 0x10, {0x01, 0x23, 0x01, 0x29, 0x01, 0x35, 0x01, 0x42, 0x01, 0x4A, 0x01, 0x5C, 0x01, 0x6E, 0x01, 0x8A} },
	{0xD2, 0x10, {0x01, 0xA7, 0x01, 0xCF, 0x01, 0xF3, 0x02, 0x2E, 0x02, 0x5E, 0x02, 0x5F, 0x02, 0x8C, 0x02, 0xC1} },
	{0xD3, 0x10, {0x02, 0xE5, 0x03, 0x16, 0x03, 0x36, 0x03, 0x60, 0x03, 0x7C, 0x03, 0x9C, 0x03, 0xAE, 0x03, 0xC6} },
	{0xD4, 0x04, {0x03, 0xFC, 0x03, 0xFF} },
	{REGFLAG_DELAY, 1, {} },
	{0xD5, 0x10, {0x01, 0x0D, 0x01, 0x14, 0x01, 0x21, 0x01, 0x2D, 0x01, 0x38, 0x01, 0x4C, 0x01, 0x5E, 0x01, 0x7E} },
	{0xD6, 0x10, {0x01, 0x99, 0x01, 0xC6, 0x01, 0xEB, 0x02, 0x27, 0x02, 0x59, 0x02, 0x5A, 0x02, 0x88, 0x02, 0xBE} },
	{0xD7, 0x10, {0x02, 0xE2, 0x03, 0x13, 0x03, 0x34, 0x03, 0x5F, 0x03, 0x79, 0x03, 0x99, 0x03, 0xAD, 0x03, 0xC8} },
	{0xD8, 0x04, {0x03, 0xEF, 0x03, 0xFF} },
	{REGFLAG_DELAY, 1, {} },
	{0xD9, 0x10, {0x00, 0x00, 0x00, 0x2D, 0x00, 0x63, 0x00, 0x8D, 0x00, 0xA3, 0x00, 0xCE, 0x00, 0xF2, 0x01, 0x26} },
	{0xDD, 0x10, {0x01, 0x55, 0x01, 0x91, 0x01, 0xC3, 0x02, 0x0F, 0x02, 0x48, 0x02, 0x4A, 0x02, 0x7C, 0x02, 0xB4} },
	{0xDE, 0x10, {0x02, 0xD9, 0x03, 0x0E, 0x03, 0x33, 0x03, 0x6F, 0x03, 0x93, 0x03, 0xD7, 0x03, 0xDE, 0x03, 0xE0} },
	{0xDF, 0x04, {0x03, 0xEC, 0x03, 0xFF} },
	{REGFLAG_DELAY, 1, {} },
	{0xE0, 0x10, {0x01, 0x23, 0x01, 0x29, 0x01, 0x35, 0x01, 0x42, 0x01, 0x4A, 0x01, 0x5C, 0x01, 0x6E, 0x01, 0x8A} },
	{0xE1, 0x10, {0x01, 0xA7, 0x01, 0xCF, 0x01, 0xF3, 0x02, 0x2E, 0x02, 0x5E, 0x02, 0x5F, 0x02, 0x8C, 0x02, 0xC1} },
	{0xE2, 0x10, {0x02, 0xE5, 0x03, 0x16, 0x03, 0x36, 0x03, 0x60, 0x03, 0x7C, 0x03, 0x9C, 0x03, 0xAE, 0x03, 0xC6} },
	{0xE3, 0x04, {0x03, 0xFC, 0x03, 0xFF} },
	{REGFLAG_DELAY, 1, {} },
	{0xE4, 0x10, {0x01, 0x0D, 0x01, 0x14, 0x01, 0x21, 0x01, 0x2D, 0x01, 0x38, 0x01, 0x4C, 0x01, 0x5E, 0x01, 0x7E} },
	{0xE5, 0x10, {0x01, 0x99, 0x01, 0xC6, 0x01, 0xEB, 0x02, 0x27, 0x02, 0x59, 0x02, 0x5A, 0x02, 0x88, 0x02, 0xBE} },
	{0xE6, 0x10, {0x02, 0xE2, 0x03, 0x13, 0x03, 0x34, 0x03, 0x5F, 0x03, 0x79, 0x03, 0x99, 0x03, 0xAD, 0x03, 0xC8} },
	{0xE7, 0x04, {0x03, 0xEF, 0x03, 0xFF} },
	{REGFLAG_DELAY, 1, {} },
	{0xE8, 0x10, {0x00, 0x00, 0x00, 0x2D, 0x00, 0x63, 0x00, 0x8D, 0x00, 0xA3, 0x00, 0xCE, 0x00, 0xF2, 0x01, 0x26} },
	{0xE9, 0x10, {0x01, 0x55, 0x01, 0x91, 0x01, 0xC3, 0x02, 0x0F, 0x02, 0x48, 0x02, 0x4A, 0x02, 0x7C, 0x02, 0xB4} },
	{0xEA, 0x10, {0x02, 0xD9, 0x03, 0x0E, 0x03, 0x33, 0x03, 0x6F, 0x03, 0x93, 0x03, 0xD7, 0x03, 0xDE, 0x03, 0xE0} },
	{0xEB, 0x04, {0x03, 0xEC, 0x03, 0xFF} },
	{REGFLAG_DELAY, 1, {} },
	{0xF0, 0x05, {0x55, 0xAA, 0x52, 0x00, 0x00} },

};

static struct LCM_setting_table lcm_dsi_dispparam_papermode_command[] = {

};

static struct LCM_setting_table lcm_dsi_dispparam_papermode1_command[] = {

};

static struct LCM_setting_table lcm_dsi_dispparam_papermode2_command[] = {

};

static struct LCM_setting_table lcm_dsi_dispparam_papermode3_command[] = {

};

static struct LCM_setting_table lcm_dsi_dispparam_papermode4_command[] = {

};

static struct LCM_setting_table lcm_dsi_dispparam_papermode5_command[] = {

};

static struct LCM_setting_table lcm_dsi_dispparam_papermode6_command[] = {

};

static struct LCM_setting_table lcm_dsi_dispparam_papermode7_command[] = {

};

static struct LCM_setting_table lcm_dsi_dispparam_srgb_command[] = {

};

static struct LCM_setting_table lcm_dsi_dispparam_default_command[] = {

};

static struct LCM_setting_table lcm_dsi_dispparam_smartcontrast_command[] = {

};

static struct LCM_setting_table lcm_dsi_dispparam_ceon_command[] = {
	{0xF0, 5, {0x55, 0xAA, 0x52, 0x08, 0x00} },
	{0xCE, 0x0C, {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20} },
	{0xF0, 5, {0x55, 0xAA, 0x52, 0x00, 0x00} },
	{0x55, 1, {0x80} },
};

static struct LCM_setting_table lcm_dsi_dispparam_cecabc_on_command[] = {
	{0xF0, 5, {0x55, 0xAA, 0x52, 0x08, 0x00} },
	{0xCE, 0x0C, {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20} },
	{0xF0, 5, {0x55, 0xAA, 0x52, 0x00, 0x00} },
	{0x55, 1, {0x81} },
};

static struct LCM_setting_table lcm_dsi_dispparam_ceoff_command[] = {
	{0x55, 1, {0x01} },
};


typedef void (*send_cmd)(struct LCM_setting_table *table, unsigned int count, unsigned char force_update);

int set_panel_disp_param(unsigned int param, send_cmd p_func)
{
	unsigned int tmp;
	send_cmd push_table;
	push_table = p_func;

	tmp = param & 0x0000000F;
	switch (tmp) {
	case 0x1:		/* warm */
		if (sizeof(lcm_dsi_dispparam_warm_command)) {
			pr_info("warm\n");
			push_table(lcm_dsi_dispparam_warm_command,
				sizeof(lcm_dsi_dispparam_warm_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	case 0x2:		/* normal */
		if (sizeof(lcm_dsi_dispparam_default_command)) {
			pr_info("default\n");
			push_table(lcm_dsi_dispparam_default_command,
				sizeof(lcm_dsi_dispparam_default_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	case 0x3:		/* cold */
		if (sizeof(lcm_dsi_dispparam_cold_command)) {
			pr_info("cold\n");
			push_table(lcm_dsi_dispparam_cold_command,
				sizeof(lcm_dsi_dispparam_cold_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	case 0x5:
		if (sizeof(lcm_dsi_dispparam_papermode_command)) {
			pr_info("paper mode\n");
			push_table(lcm_dsi_dispparam_papermode_command,
				sizeof(lcm_dsi_dispparam_papermode_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	case 0x6:
		if (sizeof(lcm_dsi_dispparam_papermode1_command)) {
			pr_info("paper mode1\n");
			push_table(lcm_dsi_dispparam_papermode1_command,
				sizeof(lcm_dsi_dispparam_papermode1_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	case 0x7:
		if (sizeof(lcm_dsi_dispparam_papermode2_command)) {
			pr_info("paper mode2\n");
			push_table(lcm_dsi_dispparam_papermode2_command,
				sizeof(lcm_dsi_dispparam_papermode2_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	case 0x8:
		if (sizeof(lcm_dsi_dispparam_papermode3_command)) {
			pr_info("paper mode3\n");
			push_table(lcm_dsi_dispparam_papermode3_command,
				sizeof(lcm_dsi_dispparam_papermode3_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	case 0x9:
		if (sizeof(lcm_dsi_dispparam_papermode4_command)) {
			pr_info("paper mode4\n");
			push_table(lcm_dsi_dispparam_papermode4_command,
				sizeof(lcm_dsi_dispparam_papermode4_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	case 0xa:
		if (sizeof(lcm_dsi_dispparam_papermode5_command)) {
			pr_info("paper mode5\n");
			push_table(lcm_dsi_dispparam_papermode5_command,
				sizeof(lcm_dsi_dispparam_papermode5_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	case 0xb:
		if (sizeof(lcm_dsi_dispparam_papermode6_command)) {
			pr_info("paper mode6\n");
			push_table(lcm_dsi_dispparam_papermode6_command,
				sizeof(lcm_dsi_dispparam_papermode6_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	case 0xc:
		if (sizeof(lcm_dsi_dispparam_papermode7_command)) {
			pr_info("paper mode7\n");
			push_table(lcm_dsi_dispparam_papermode7_command,
				sizeof(lcm_dsi_dispparam_papermode7_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	default:
		break;
	}

	tmp = param & 0x000F0000;
	switch (tmp) {
	case 0xA0000:
		if (sizeof(lcm_dsi_dispparam_idleon_command)) {
			pr_info("idle on\n");
			push_table(lcm_dsi_dispparam_idleon_command,
				sizeof(lcm_dsi_dispparam_idleon_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	case 0xF0000:
		if (sizeof(lcm_dsi_dispparam_idleoff_command)) {
			pr_info("idle off\n");
			push_table(lcm_dsi_dispparam_idleoff_command,
				sizeof(lcm_dsi_dispparam_idleoff_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	default:
		break;
	}

	tmp = param & 0x00F00000;
	switch (tmp) {
	case 0x100000:
		if (sizeof(lcm_dsi_dispparam_normal1_command)) {
			pr_info("normal1\n");
			push_table(lcm_dsi_dispparam_normal1_command,
				sizeof(lcm_dsi_dispparam_normal1_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	case 0x200000:
		if (sizeof(lcm_dsi_dispparam_normal2_command)) {
			pr_info("normal2\n");
			push_table(lcm_dsi_dispparam_normal2_command,
				sizeof(lcm_dsi_dispparam_normal2_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	case 0x300000:
		if (sizeof(lcm_dsi_dispparam_srgb_command)) {
			pr_info("sRGB\n");
			push_table(lcm_dsi_dispparam_srgb_command,
				sizeof(lcm_dsi_dispparam_srgb_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	default:
		break;
	}

	tmp = param & 0x000000F0;
	switch (tmp) {
	case 0x10:
		if (sizeof(lcm_dsi_dispparam_ceon_command)) {
			pr_info("ce on\n");
			push_table(lcm_dsi_dispparam_ceon_command,
				sizeof(lcm_dsi_dispparam_ceon_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	case 0x20:
		if (sizeof(lcm_dsi_dispparam_cecabc_on_command)) {
			pr_info("ce&cabc on\n");
			push_table(lcm_dsi_dispparam_cecabc_on_command,
				sizeof(lcm_dsi_dispparam_cecabc_on_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	case 0xF0:
		if (sizeof(lcm_dsi_dispparam_ceoff_command)) {
			pr_info("ce off\n");
			push_table(lcm_dsi_dispparam_ceoff_command,
				sizeof(lcm_dsi_dispparam_ceoff_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	default:
		break;
	}

	tmp = param & 0x00000F00;
	switch (tmp) {
	case 0x100:
		if (sizeof(lcm_dsi_dispparam_cabcon_command)) {
			pr_info("cabc on\n");
			push_table(lcm_dsi_dispparam_cabcon_command,
				sizeof(lcm_dsi_dispparam_cabcon_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	case 0x200:
		if (sizeof(lcm_dsi_dispparam_cabcguion_command)) {
			pr_info("cabc gui on\n");
			push_table(lcm_dsi_dispparam_cabcguion_command,
				sizeof(lcm_dsi_dispparam_cabcguion_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	case 0x300:
		if (sizeof(lcm_dsi_dispparam_cabcstillon_command)) {
			pr_info("cabc still on\n");
			push_table(lcm_dsi_dispparam_cabcstillon_command,
				sizeof(lcm_dsi_dispparam_cabcstillon_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	case 0x400:
		if (sizeof(lcm_dsi_dispparam_cabcmovieon_command)) {
			pr_info("cabc movie on\n");
			push_table(lcm_dsi_dispparam_cabcmovieon_command,
				sizeof(lcm_dsi_dispparam_cabcmovieon_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	case 0x500:
		if (sizeof(lcm_dsi_dispparam_dimmingon_command)) {
			pr_info("dimming on\n");
			push_table(lcm_dsi_dispparam_dimmingon_command,
				sizeof(lcm_dsi_dispparam_dimmingon_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	case 0xA00:
		if (sizeof(lcm_dsi_dispparam_smartcontrast_command)) {
			pr_info("smart contrast on\n");
			push_table(lcm_dsi_dispparam_smartcontrast_command,
				sizeof(lcm_dsi_dispparam_smartcontrast_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	case 0xF00:
		if (sizeof(lcm_dsi_dispparam_cabcoff_command)) {
			pr_info("cabc off\n");
			push_table(lcm_dsi_dispparam_cabcoff_command,
				sizeof(lcm_dsi_dispparam_cabcoff_command) / sizeof(struct LCM_setting_table), 1);
		}
		break;
	default:
		break;
	}

	return 0;
}
