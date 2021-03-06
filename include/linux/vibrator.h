/*
 * vibrator.h
 *
 * header file describing vibrator platform data for Samsung device
 *
 * COPYRIGHT(C) Samsung Electronics Co., Ltd. 2006-2011 All Right Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef __VIBRATOR_H__
#define __VIBRATOR_H__

enum vibrator_model {
	NO_VIBRATOR,
	HAPTIC_PWM,
	HAPTIC_MOTOR,/* tspdrv flow will support this model as inbuilt */
};

struct vibrator_platform_data {
	struct device *dev;
	unsigned int vib_pwm_gpio;/* gpio number for vibrator pwm */
//	unsigned int haptic_pwr_en_gpio;/* gpio number of haptic power enable */
	unsigned int vib_en_gpio;/* gpio number of vibrator enable */
	unsigned int is_pmic_vib_pwm ;
	enum vibrator_model vib_model;
	struct pwm_device	*pwm_dev;
	unsigned int pwm_period_us;
	unsigned int duty_us;
	unsigned int gp_clk;
	void (*power_onoff)(int onoff);
};

struct vibrator_platform_data_motor {
	void (*power_onoff)(int onoff);
};
#endif
