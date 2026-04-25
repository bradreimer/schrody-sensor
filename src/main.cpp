/**
 * @file    main.cpp
 * @brief   Blink example for Seeed Studio XIAO ESP32-C6
 *
 * Toggles the onboard orange user LED (GPIO15, active HIGH) at 1 Hz to
 * validate the end-to-end PlatformIO + Arduino toolchain.
 *
 * Hardware:
 *   Board : Seeed Studio XIAO ESP32-C6
 *   LED   : GPIO15 — onboard orange user LED, active HIGH
 *
 * Build & flash:
 *   pio run                       # compile
 *   pio run --target upload       # compile + flash
 *   pio device monitor            # open serial monitor (115200 baud)
 *
 * Bootloader mode (if auto-reset fails):
 *   Hold BOOT → plug USB-C → release BOOT → flash → press RESET
 */

#include <Arduino.h>

static constexpr uint8_t  USER_LED          = 15;  // onboard orange LED, active HIGH
static constexpr uint32_t BLINK_INTERVAL_MS = 500; // 500 ms on, 500 ms off → 1 Hz

void setup() {
    Serial.begin(115200);
    pinMode(USER_LED, OUTPUT);
    digitalWrite(USER_LED, LOW);
    Serial.println("XIAO ESP32-C6 Blink — ready");
}

void loop() {
    digitalWrite(USER_LED, HIGH);
    Serial.println("LED ON");
    delay(BLINK_INTERVAL_MS);

    digitalWrite(USER_LED, LOW);
    Serial.println("LED OFF");
    delay(BLINK_INTERVAL_MS);
}
