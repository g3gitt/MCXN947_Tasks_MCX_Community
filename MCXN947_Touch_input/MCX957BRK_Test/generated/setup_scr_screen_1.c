/*
 * Copyright 2024 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"
void chart_create(lv_ui *ui);

void setup_scr_screen_1(lv_ui *ui){

	//Write codes screen_1
	ui->screen_1 = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->screen_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_1_main_main_default
	static lv_style_t style_screen_1_main_main_default;
	if (style_screen_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_1_main_main_default);
	else
		lv_style_init(&style_screen_1_main_main_default);
	lv_style_set_bg_color(&style_screen_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_screen_1_main_main_default, 0);
	lv_obj_add_style(ui->screen_1, &style_screen_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_1
	ui->screen_cont_1 = lv_obj_create(ui->screen_1);
	lv_obj_set_pos(ui->screen_cont_1, 0, 0);
	lv_obj_set_size(ui->screen_cont_1, 480, 320);
	lv_obj_set_scrollbar_mode(ui->screen_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_cont_1_main_main_default
	static lv_style_t style_screen_cont_1_main_main_default;
	if (style_screen_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_cont_1_main_main_default);
	else
		lv_style_init(&style_screen_cont_1_main_main_default);
	lv_style_set_radius(&style_screen_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_screen_cont_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_cont_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_cont_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_screen_cont_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_screen_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_screen_cont_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_screen_cont_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_screen_cont_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_screen_cont_1_main_main_default, 0);
	lv_style_set_border_color(&style_screen_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_screen_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->screen_cont_1, &style_screen_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_lab_bpm_value
	ui->screen_lab_bpm_value = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_lab_bpm_value, 347, 64);
	lv_obj_set_size(ui->screen_lab_bpm_value, 104, 78);
	lv_obj_set_scrollbar_mode(ui->screen_lab_bpm_value, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_lab_bpm_value, "64");
	lv_label_set_long_mode(ui->screen_lab_bpm_value, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_lab_bpm_value_main_main_default
	static lv_style_t style_screen_lab_bpm_value_main_main_default;
	if (style_screen_lab_bpm_value_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_lab_bpm_value_main_main_default);
	else
		lv_style_init(&style_screen_lab_bpm_value_main_main_default);
	lv_style_set_radius(&style_screen_lab_bpm_value_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_lab_bpm_value_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_lab_bpm_value_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_lab_bpm_value_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_lab_bpm_value_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_lab_bpm_value_main_main_default, 0);
	lv_style_set_shadow_color(&style_screen_lab_bpm_value_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_screen_lab_bpm_value_main_main_default, 255);
	lv_style_set_shadow_spread(&style_screen_lab_bpm_value_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_screen_lab_bpm_value_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_screen_lab_bpm_value_main_main_default, 0);
	lv_style_set_text_color(&style_screen_lab_bpm_value_main_main_default, lv_color_make(0x00, 0xff, 0x5c));
	lv_style_set_text_font(&style_screen_lab_bpm_value_main_main_default, &lv_font_Amiko_Regular_50);
	lv_style_set_text_letter_space(&style_screen_lab_bpm_value_main_main_default, 2);
	lv_style_set_text_line_space(&style_screen_lab_bpm_value_main_main_default, 0);
	lv_style_set_text_align(&style_screen_lab_bpm_value_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_lab_bpm_value_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_lab_bpm_value_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_lab_bpm_value_main_main_default, 8);
	lv_style_set_pad_bottom(&style_screen_lab_bpm_value_main_main_default, 0);
	lv_obj_add_style(ui->screen_lab_bpm_value, &style_screen_lab_bpm_value_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_lab_bpm
	ui->screen_lab_bpm = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_lab_bpm, 374, 111);
	lv_obj_set_size(ui->screen_lab_bpm, 100, 32);
	lv_obj_set_scrollbar_mode(ui->screen_lab_bpm, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_lab_bpm, "BPM");
	lv_label_set_long_mode(ui->screen_lab_bpm, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_lab_bpm_main_main_default
	static lv_style_t style_screen_lab_bpm_main_main_default;
	if (style_screen_lab_bpm_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_lab_bpm_main_main_default);
	else
		lv_style_init(&style_screen_lab_bpm_main_main_default);
	lv_style_set_radius(&style_screen_lab_bpm_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_lab_bpm_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_lab_bpm_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_lab_bpm_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_lab_bpm_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_lab_bpm_main_main_default, 0);
	lv_style_set_shadow_color(&style_screen_lab_bpm_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_screen_lab_bpm_main_main_default, 255);
	lv_style_set_shadow_spread(&style_screen_lab_bpm_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_screen_lab_bpm_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_screen_lab_bpm_main_main_default, 0);
	lv_style_set_text_color(&style_screen_lab_bpm_main_main_default, lv_color_make(0x00, 0xFF, 0x5c));
	lv_style_set_text_font(&style_screen_lab_bpm_main_main_default, &lv_font_Amiko_Regular_16);
	lv_style_set_text_letter_space(&style_screen_lab_bpm_main_main_default, 2);
	lv_style_set_text_line_space(&style_screen_lab_bpm_main_main_default, 0);
	lv_style_set_text_align(&style_screen_lab_bpm_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_lab_bpm_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_lab_bpm_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_lab_bpm_main_main_default, 8);
	lv_style_set_pad_bottom(&style_screen_lab_bpm_main_main_default, 0);
	lv_obj_add_style(ui->screen_lab_bpm, &style_screen_lab_bpm_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);


	//Write codes screen_lab_spo2_value
	ui->screen_lab_spo2_value = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_lab_spo2_value, 347, 200);
	lv_obj_set_size(ui->screen_lab_spo2_value, 104, 78);
	lv_obj_set_scrollbar_mode(ui->screen_lab_spo2_value, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_lab_spo2_value, "98");
	lv_label_set_long_mode(ui->screen_lab_spo2_value, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_lab_spo2_value_main_main_default
	static lv_style_t style_screen_lab_spo2_value_main_main_default;
	if (style_screen_lab_spo2_value_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_lab_spo2_value_main_main_default);
	else
		lv_style_init(&style_screen_lab_spo2_value_main_main_default);
	lv_style_set_radius(&style_screen_lab_spo2_value_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_lab_spo2_value_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_lab_spo2_value_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_lab_spo2_value_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_lab_spo2_value_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_lab_spo2_value_main_main_default, 0);
	lv_style_set_shadow_color(&style_screen_lab_spo2_value_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_screen_lab_spo2_value_main_main_default, 255);
	lv_style_set_shadow_spread(&style_screen_lab_spo2_value_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_screen_lab_spo2_value_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_screen_lab_spo2_value_main_main_default, 0);
	lv_style_set_text_color(&style_screen_lab_spo2_value_main_main_default, lv_color_make(0x00, 0xd2, 0xff));
	lv_style_set_text_font(&style_screen_lab_spo2_value_main_main_default, &lv_font_Amiko_Regular_50);
	lv_style_set_text_letter_space(&style_screen_lab_spo2_value_main_main_default, 2);
	lv_style_set_text_line_space(&style_screen_lab_spo2_value_main_main_default, 0);
	lv_style_set_text_align(&style_screen_lab_spo2_value_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_lab_spo2_value_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_lab_spo2_value_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_lab_spo2_value_main_main_default, 8);
	lv_style_set_pad_bottom(&style_screen_lab_spo2_value_main_main_default, 0);
	lv_obj_add_style(ui->screen_lab_spo2_value, &style_screen_lab_spo2_value_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_lab_spo2
	ui->screen_lab_spo2 = lv_label_create(ui->screen_cont_1);
	lv_obj_set_pos(ui->screen_lab_spo2, 380, 248);
	lv_obj_set_size(ui->screen_lab_spo2, 100, 32);
	lv_obj_set_scrollbar_mode(ui->screen_lab_spo2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_lab_spo2, "Spo2");
	lv_label_set_long_mode(ui->screen_lab_spo2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_lab_spo2_main_main_default
	static lv_style_t style_screen_lab_spo2_main_main_default;
	if (style_screen_lab_spo2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_lab_spo2_main_main_default);
	else
		lv_style_init(&style_screen_lab_spo2_main_main_default);
	lv_style_set_radius(&style_screen_lab_spo2_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_lab_spo2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_lab_spo2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_lab_spo2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_lab_spo2_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_lab_spo2_main_main_default, 0);
	lv_style_set_shadow_color(&style_screen_lab_spo2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_screen_lab_spo2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_screen_lab_spo2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_screen_lab_spo2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_screen_lab_spo2_main_main_default, 0);
	lv_style_set_text_color(&style_screen_lab_spo2_main_main_default, lv_color_make(0x00, 0xD2, 0xFf));
	lv_style_set_text_font(&style_screen_lab_spo2_main_main_default, &lv_font_Amiko_Regular_16);
	lv_style_set_text_letter_space(&style_screen_lab_spo2_main_main_default, 2);
	lv_style_set_text_line_space(&style_screen_lab_spo2_main_main_default, 0);
	lv_style_set_text_align(&style_screen_lab_spo2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_lab_spo2_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_lab_spo2_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_lab_spo2_main_main_default, 8);
	lv_style_set_pad_bottom(&style_screen_lab_spo2_main_main_default, 0);
	lv_obj_add_style(ui->screen_lab_spo2, &style_screen_lab_spo2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	/*Create a chart one*/
	ui->chart_one = lv_chart_create(ui->screen_1);
	lv_obj_set_size(ui->chart_one, 330, 100);
	lv_obj_align(ui->chart_one, LV_ALIGN_TOP_LEFT, 0, 35);
	lv_chart_set_type(ui->chart_one, LV_CHART_TYPE_LINE);
	//lv_chart_set_series_opa(chart_one, LV_OPA_70);
	//lv_chart_set_series_width(chart_one, 4);
	lv_chart_set_range(ui->chart_one,LV_CHART_AXIS_PRIMARY_X, 0, 330);

	/*Create a series three*/
	ui->ser_one = lv_chart_add_series(ui->chart_one, lv_color_make(0x00, 0xFF, 0x5C),LV_CHART_AXIS_PRIMARY_Y);      /*Create a series one*/



	static lv_style_t style_screen_2_chart_1_main_main_default;
		if (style_screen_2_chart_1_main_main_default.prop_cnt > 1)
			lv_style_reset(&style_screen_2_chart_1_main_main_default);
		else
			lv_style_init(&style_screen_2_chart_1_main_main_default);
		lv_style_set_radius(&style_screen_2_chart_1_main_main_default, 0);
		lv_style_set_bg_color(&style_screen_2_chart_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
		lv_style_set_bg_grad_color(&style_screen_2_chart_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
		lv_style_set_bg_grad_dir(&style_screen_2_chart_1_main_main_default, LV_GRAD_DIR_NONE);
		lv_style_set_bg_opa(&style_screen_2_chart_1_main_main_default, 0);
		lv_style_set_line_opa(&style_screen_2_chart_1_main_main_default, 0);
		lv_style_set_border_opa(&style_screen_2_chart_1_main_main_default, 0);

	    //lv_style_set_pad_all(&style_screen_2_chart_1_main_main_default, 0);
		//lv_chart_set_point_count(chart_one, 0);
		lv_obj_add_style(ui->chart_one, &style_screen_2_chart_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

		static lv_style_t style_screen_2_arc_1_main_knob_default;
		lv_style_init(&style_screen_2_arc_1_main_knob_default);
		lv_style_set_pad_all(&style_screen_2_arc_1_main_knob_default, 0);
		lv_style_set_bg_opa(&style_screen_2_arc_1_main_knob_default, 0);
		lv_obj_add_style(ui->chart_one, &style_screen_2_arc_1_main_knob_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

		/*Create a chart two*/
		ui->chart_two = lv_chart_create(ui->screen_1);
		lv_obj_set_size(ui->chart_two, 330, 100);
		lv_obj_align(ui->chart_two, LV_ALIGN_TOP_LEFT, 0, 210);
		lv_chart_set_type(ui->chart_two, LV_CHART_TYPE_LINE);
		//lv_chart_set_series_opa(chart_one, LV_OPA_70);
		//lv_chart_set_series_width(chart_one, 4);
		lv_chart_set_range(ui->chart_two,LV_CHART_AXIS_PRIMARY_X, 0, 150);

		/*Create a series three*/
		ui->ser_two = lv_chart_add_series(ui->chart_two, lv_color_make(0x00, 0xD2, 0xFF),LV_CHART_AXIS_PRIMARY_Y);      /*Create a series one*/


		static lv_style_t style_screen_2_chart_2_main_main_default;
			if (style_screen_2_chart_2_main_main_default.prop_cnt > 1)
				lv_style_reset(&style_screen_2_chart_2_main_main_default);
			else
				lv_style_init(&style_screen_2_chart_2_main_main_default);
			lv_style_set_radius(&style_screen_2_chart_2_main_main_default, 0);
			lv_style_set_bg_color(&style_screen_2_chart_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
			lv_style_set_bg_grad_color(&style_screen_2_chart_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
			lv_style_set_bg_grad_dir(&style_screen_2_chart_2_main_main_default, LV_GRAD_DIR_NONE);
			lv_style_set_bg_opa(&style_screen_2_chart_2_main_main_default, 0);
			lv_style_set_line_opa(&style_screen_2_chart_2_main_main_default, 0);
			lv_style_set_border_opa(&style_screen_2_chart_2_main_main_default, 0);

			//lv_style_set_pad_all(&style_screen_2_chart_1_main_main_default, 0);
			//lv_chart_set_point_count(chart_one, 0);
			lv_obj_add_style(ui->chart_two, &style_screen_2_chart_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

			static lv_style_t style_screen_2_arc_2_main_knob_default;
			lv_style_init(&style_screen_2_arc_2_main_knob_default);
			lv_style_set_pad_all(&style_screen_2_arc_2_main_knob_default, 0);
			lv_style_set_bg_opa(&style_screen_2_arc_2_main_knob_default, 0);
			lv_obj_add_style(ui->chart_two, &style_screen_2_arc_2_main_knob_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);


			//Write codes screen_btn_On_OFF
			ui->screen_btn_On_OFF = lv_btn_create(ui->screen_cont_1);
			lv_obj_set_pos(ui->screen_btn_On_OFF, 435, 15);
			lv_obj_set_size(ui->screen_btn_On_OFF, 35, 35);
			lv_obj_set_scrollbar_mode(ui->screen_btn_On_OFF, LV_SCROLLBAR_MODE_OFF);

			//Write style state: LV_STATE_DEFAULT for style_screen_btn_on_off_main_main_default
			static lv_style_t style_screen_btn_on_off_main_main_default;
			if (style_screen_btn_on_off_main_main_default.prop_cnt > 1)
				lv_style_reset(&style_screen_btn_on_off_main_main_default);
			else
				lv_style_init(&style_screen_btn_on_off_main_main_default);
			lv_style_set_radius(&style_screen_btn_on_off_main_main_default, 20);
			lv_style_set_bg_color(&style_screen_btn_on_off_main_main_default, lv_color_make(0x00, 0xff, 0x16));
			lv_style_set_bg_grad_color(&style_screen_btn_on_off_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
			lv_style_set_bg_grad_dir(&style_screen_btn_on_off_main_main_default, LV_GRAD_DIR_NONE);
			lv_style_set_bg_opa(&style_screen_btn_on_off_main_main_default, 255);
			lv_style_set_shadow_width(&style_screen_btn_on_off_main_main_default, 0);
			lv_style_set_shadow_color(&style_screen_btn_on_off_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
			lv_style_set_shadow_opa(&style_screen_btn_on_off_main_main_default, 255);
			lv_style_set_shadow_spread(&style_screen_btn_on_off_main_main_default, 0);
			lv_style_set_shadow_ofs_x(&style_screen_btn_on_off_main_main_default, 0);
			lv_style_set_shadow_ofs_y(&style_screen_btn_on_off_main_main_default, 0);
			lv_style_set_border_color(&style_screen_btn_on_off_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
			lv_style_set_border_width(&style_screen_btn_on_off_main_main_default, 0);
			lv_style_set_border_opa(&style_screen_btn_on_off_main_main_default, 255);
			lv_style_set_text_color(&style_screen_btn_on_off_main_main_default, lv_color_make(0xff, 0xff, 0xff));
			lv_style_set_text_font(&style_screen_btn_on_off_main_main_default, &lv_font_montserratMedium_16);
			lv_style_set_text_align(&style_screen_btn_on_off_main_main_default, LV_TEXT_ALIGN_CENTER);
			lv_obj_add_style(ui->screen_btn_On_OFF, &style_screen_btn_on_off_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

			//Write style state: LV_STATE_PRESSED for style_screen_btn_on_off_main_main_pressed
			static lv_style_t style_screen_btn_on_off_main_main_pressed;
			if (style_screen_btn_on_off_main_main_pressed.prop_cnt > 1)
				lv_style_reset(&style_screen_btn_on_off_main_main_pressed);
			else
				lv_style_init(&style_screen_btn_on_off_main_main_pressed);
			lv_style_set_radius(&style_screen_btn_on_off_main_main_pressed, 20);
			lv_style_set_bg_color(&style_screen_btn_on_off_main_main_pressed, lv_color_make(0xFF, 0x00, 0x00));
			lv_style_set_bg_grad_color(&style_screen_btn_on_off_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
			lv_style_set_bg_grad_dir(&style_screen_btn_on_off_main_main_pressed, LV_GRAD_DIR_NONE);
			lv_style_set_bg_opa(&style_screen_btn_on_off_main_main_pressed, 255);
			lv_style_set_shadow_width(&style_screen_btn_on_off_main_main_pressed, 0);
			lv_style_set_shadow_color(&style_screen_btn_on_off_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
			lv_style_set_shadow_opa(&style_screen_btn_on_off_main_main_pressed, 255);
			lv_style_set_shadow_spread(&style_screen_btn_on_off_main_main_pressed, 0);
			lv_style_set_shadow_ofs_x(&style_screen_btn_on_off_main_main_pressed, 0);
			lv_style_set_shadow_ofs_y(&style_screen_btn_on_off_main_main_pressed, 0);
			lv_style_set_border_color(&style_screen_btn_on_off_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
			lv_style_set_border_width(&style_screen_btn_on_off_main_main_pressed, 0);
			lv_style_set_border_opa(&style_screen_btn_on_off_main_main_pressed, 255);
			lv_style_set_text_color(&style_screen_btn_on_off_main_main_pressed, lv_color_make(0xff, 0xff, 0xff));
			lv_style_set_text_font(&style_screen_btn_on_off_main_main_pressed, &lv_font_montserratMedium_16);
			lv_obj_add_style(ui->screen_btn_On_OFF, &style_screen_btn_on_off_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);
			lv_obj_add_flag(ui->screen_btn_On_OFF, LV_OBJ_FLAG_CHECKABLE);
			ui->screen_btn_On_OFF_label = lv_label_create(ui->screen_btn_On_OFF);
			lv_label_set_text(ui->screen_btn_On_OFF_label, "|");
			lv_obj_set_style_pad_all(ui->screen_btn_On_OFF, 0, LV_STATE_DEFAULT);
			lv_obj_align(ui->screen_btn_On_OFF_label, LV_ALIGN_CENTER, 0, 0);

			//Write codes screen_imgbtn_1
			ui->screen_imgbtn_1 = lv_imgbtn_create(ui->screen_cont_1);
			lv_obj_set_pos(ui->screen_imgbtn_1, 400, 15);
			lv_obj_set_size(ui->screen_imgbtn_1, 30, 30);
			lv_obj_set_scrollbar_mode(ui->screen_imgbtn_1, LV_SCROLLBAR_MODE_OFF);

			//Write style state: LV_STATE_DEFAULT for style_screen_imgbtn_1_main_main_default
			static lv_style_t style_screen_imgbtn_1_main_main_default;
			if (style_screen_imgbtn_1_main_main_default.prop_cnt > 1)
				lv_style_reset(&style_screen_imgbtn_1_main_main_default);
			else
				lv_style_init(&style_screen_imgbtn_1_main_main_default);
			lv_style_set_shadow_width(&style_screen_imgbtn_1_main_main_default, 0);
			lv_style_set_shadow_color(&style_screen_imgbtn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
			lv_style_set_shadow_opa(&style_screen_imgbtn_1_main_main_default, 255);
			lv_style_set_shadow_spread(&style_screen_imgbtn_1_main_main_default, 0);
			lv_style_set_shadow_ofs_x(&style_screen_imgbtn_1_main_main_default, 0);
			lv_style_set_shadow_ofs_y(&style_screen_imgbtn_1_main_main_default, 0);
			lv_style_set_text_color(&style_screen_imgbtn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
			lv_style_set_text_align(&style_screen_imgbtn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
			lv_style_set_img_recolor(&style_screen_imgbtn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
			lv_style_set_img_recolor_opa(&style_screen_imgbtn_1_main_main_default, 0);
			lv_style_set_img_opa(&style_screen_imgbtn_1_main_main_default, 255);
			lv_obj_add_style(ui->screen_imgbtn_1, &style_screen_imgbtn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

			//Write style state: LV_STATE_PRESSED for style_screen_imgbtn_1_main_main_pressed
			static lv_style_t style_screen_imgbtn_1_main_main_pressed;
			if (style_screen_imgbtn_1_main_main_pressed.prop_cnt > 1)
				lv_style_reset(&style_screen_imgbtn_1_main_main_pressed);
			else
				lv_style_init(&style_screen_imgbtn_1_main_main_pressed);
			lv_style_set_shadow_width(&style_screen_imgbtn_1_main_main_pressed, 0);
			lv_style_set_shadow_color(&style_screen_imgbtn_1_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
			lv_style_set_shadow_opa(&style_screen_imgbtn_1_main_main_pressed, 255);
			lv_style_set_shadow_spread(&style_screen_imgbtn_1_main_main_pressed, 0);
			lv_style_set_shadow_ofs_x(&style_screen_imgbtn_1_main_main_pressed, 0);
			lv_style_set_shadow_ofs_y(&style_screen_imgbtn_1_main_main_pressed, 0);
			lv_style_set_text_color(&style_screen_imgbtn_1_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
			lv_style_set_img_recolor(&style_screen_imgbtn_1_main_main_pressed, lv_color_make(0xf0, 0x00, 0x00));
			lv_style_set_img_recolor_opa(&style_screen_imgbtn_1_main_main_pressed, 0);
			lv_style_set_img_opa(&style_screen_imgbtn_1_main_main_pressed, 255);
			lv_obj_add_style(ui->screen_imgbtn_1, &style_screen_imgbtn_1_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

			//Write style state: LV_STATE_CHECKED for style_screen_imgbtn_1_main_main_checked
			static lv_style_t style_screen_imgbtn_1_main_main_checked;
			if (style_screen_imgbtn_1_main_main_checked.prop_cnt > 1)
				lv_style_reset(&style_screen_imgbtn_1_main_main_checked);
			else
				lv_style_init(&style_screen_imgbtn_1_main_main_checked);
			lv_style_set_shadow_width(&style_screen_imgbtn_1_main_main_checked, 0);
			lv_style_set_shadow_color(&style_screen_imgbtn_1_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
			lv_style_set_shadow_opa(&style_screen_imgbtn_1_main_main_checked, 255);
			lv_style_set_shadow_spread(&style_screen_imgbtn_1_main_main_checked, 0);
			lv_style_set_shadow_ofs_x(&style_screen_imgbtn_1_main_main_checked, 0);
			lv_style_set_shadow_ofs_y(&style_screen_imgbtn_1_main_main_checked, 0);
			lv_style_set_text_color(&style_screen_imgbtn_1_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
			lv_style_set_img_recolor(&style_screen_imgbtn_1_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
			lv_style_set_img_recolor_opa(&style_screen_imgbtn_1_main_main_checked, 0);
			lv_style_set_img_opa(&style_screen_imgbtn_1_main_main_checked, 255);
			lv_obj_add_style(ui->screen_imgbtn_1, &style_screen_imgbtn_1_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
			lv_imgbtn_set_src(ui->screen_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_Unmuted_alpha_30x30, NULL);
			lv_imgbtn_set_src(ui->screen_imgbtn_1, LV_IMGBTN_STATE_PRESSED, NULL, &_muted_alpha_30x30, NULL);
			lv_obj_add_flag(ui->screen_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);





			//Write codes screen_line_ver
			ui->screen_line_ver = lv_line_create(ui->screen_cont_1);
			static lv_point_t screen_line_ver[] ={{0, 0},{0, 320},};
			lv_line_set_points(ui->screen_line_ver, screen_line_ver, 2);
			lv_obj_set_pos(ui->screen_line_ver, 340, 2);
			lv_obj_set_size(ui->screen_line_ver, 60, 320);
			lv_obj_set_scrollbar_mode(ui->screen_line_ver, LV_SCROLLBAR_MODE_OFF);

			//Write style for screen_line_ver, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
			lv_obj_set_style_line_width(ui->screen_line_ver, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_line_color(ui->screen_line_ver, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_line_opa(ui->screen_line_ver, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_line_rounded(ui->screen_line_ver, true, LV_PART_MAIN|LV_STATE_DEFAULT);


			//Write codes screen_line_1
			ui->screen_line_1 = lv_line_create(ui->screen_cont_1);
			lv_obj_set_pos(ui->screen_line_1, 0, 160);
			lv_obj_set_size(ui->screen_line_1, 472, 26);
			lv_obj_set_scrollbar_mode(ui->screen_line_1, LV_SCROLLBAR_MODE_OFF);

			//Write style state: LV_STATE_DEFAULT for style_screen_line_1_main_main_default
			static lv_style_t style_screen_line_1_main_main_default;
			if (style_screen_line_1_main_main_default.prop_cnt > 1)
				lv_style_reset(&style_screen_line_1_main_main_default);
			else
				lv_style_init(&style_screen_line_1_main_main_default);
			lv_style_set_line_color(&style_screen_line_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
			lv_style_set_line_width(&style_screen_line_1_main_main_default, 2);
			lv_style_set_line_rounded(&style_screen_line_1_main_main_default, true);
			lv_obj_add_style(ui->screen_line_1, &style_screen_line_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
			static lv_point_t screen_line_1[] ={{0, 0},{480, 0},};
			lv_line_set_points(ui->screen_line_1,screen_line_1,2);



			//Write codes screen_warning_label
				ui->screen_warning_label = lv_label_create(ui->screen_cont_1);
				lv_label_set_text(ui->screen_warning_label, "Measuring ...");
				lv_label_set_long_mode(ui->screen_warning_label, LV_LABEL_LONG_WRAP);
				lv_obj_set_pos(ui->screen_warning_label, 28, 141);
				lv_obj_set_size(ui->screen_warning_label, 388, 61);
				lv_obj_set_scrollbar_mode(ui->screen_warning_label, LV_SCROLLBAR_MODE_OFF);

				//Write style for screen_warning_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
				lv_obj_set_style_border_width(ui->screen_warning_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_radius(ui->screen_warning_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_text_color(ui->screen_warning_label, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_text_font(ui->screen_warning_label, &lv_font_Amiko_Regular_50, LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_text_letter_space(ui->screen_warning_label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_text_line_space(ui->screen_warning_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_text_align(ui->screen_warning_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_bg_opa(ui->screen_warning_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_pad_top(ui->screen_warning_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_pad_right(ui->screen_warning_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_pad_bottom(ui->screen_warning_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_pad_left(ui->screen_warning_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_shadow_width(ui->screen_warning_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);




}

void changecolor(uint8_t color, lv_ui obj){


if(color==1){

	lv_chart_set_series_color(obj.chart_one, obj.ser_one, lv_color_make(0xFF, 0x00, 0x00));
}

if(color==2){

	lv_chart_set_series_color(obj.chart_one, obj.ser_one, lv_color_make(0xFF, 0xFF, 0x00));
}



if(color==3){
	lv_chart_set_series_color(obj.chart_one, obj.ser_one, lv_color_make(0x00, 0xFF, 0x00));
}

}


