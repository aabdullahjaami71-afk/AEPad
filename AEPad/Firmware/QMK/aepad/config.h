// Copyright 2025 Aabdullah
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X32
#    define OLED_ROTATION 0
#endif

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP6
#define I2C1_SCL_PIN GP7
