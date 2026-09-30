/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "guider_fonts.h"


typedef struct
{
	lv_obj_t *screen_1;
	bool screen_1_del;
	lv_obj_t *screen_cont_1;
	lv_obj_t *screen_2_chart_1;
	lv_obj_t *label_value_point;
	lv_obj_t *chart_one;
	lv_chart_series_t *ser_one;
	lv_obj_t *screen_lab_bpm_value;
	lv_obj_t *screen_lab_bpm;
	lv_obj_t *screen_line_1;
	lv_obj_t *screen_lab_spo2_value;
	lv_obj_t *screen_lab_spo2;
	lv_obj_t *chart_two;
	lv_chart_series_t *ser_two;
	lv_obj_t *screen_btn_On_OFF;
	lv_obj_t *screen_btn_On_OFF_label;
	lv_obj_t *screen_imgbtn_1;
	lv_obj_t *screen_imgbtn_1_label;
	lv_obj_t *screen_line_ver;
	lv_obj_t *screen_warning_label;
}lv_ui;

void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_screen_1(lv_ui *ui);
void setup_scr_cont_2(lv_ui *ui);
void setup_scr_screen(lv_ui *ui);
void setup_scr_screen_2(lv_ui *ui);

//LV_FONT_DECLARE(lv_font_Alatsi_Regular_23);
//LV_FONT_DECLARE(lv_font_Alatsi_Regular_25);

//LV_FONT_DECLARE(lv_font_simsun_28);
//LV_FONT_DECLARE(lv_font_simsun_11);
//LV_FONT_DECLARE(lv_font_simsun_30);

LV_IMG_DECLARE(_muted_alpha_30x30);
LV_IMG_DECLARE(_Unmuted_alpha_30x30);

LV_FONT_DECLARE(lv_font_Amiko_Regular_16);
LV_FONT_DECLARE(lv_font_Amiko_Regular_50);


#ifdef __cplusplus
}
#endif
#endif
