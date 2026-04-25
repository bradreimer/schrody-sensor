# Design Document — schrody-sensor

## 1. Project Overview

`schrody-sensor` is an embedded firmware project targeting the **Seeed Studio XIAO ESP32-C6** microcontroller. The initial blink example serves as an **end-to-end toolchain validation**: it proves that the PlatformIO build system, `espressif32` board package, Arduino framework, and USB-CDC serial bridge are all correctly configured before any application logic is added.

---

## 2. Target Hardware

| Attribute     | Detail                                    |
|---------------|-------------------------------------------|
| SoC           | Espressif ESP32-C6 (RISC-V)               |
| CPU           | 32-bit RISC-V @ up to 160 MHz            |
| Flash         | 4 MB                                      |
| SRAM          | 512 KB                                    |
| Wireless      | Wi-Fi 6 (802.11ax), BLE 5.0, Zigbee, Thread/Matter |
| Form factor   | XIAO (21 × 17.5 mm), castellated pads     |
| USB           | USB-C (USB Full-Speed 2.0, built-in CDC)  |

---

## 3. Hardware Rationale

| Reason                  | Detail                                                                |
|-------------------------|-----------------------------------------------------------------------|
| XIAO footprint          | Extremely compact; fits breadboards and custom PCBs easily            |
| Matter / Thread support | Native 802.15.4 radio enables Matter over Thread for smart-home integration |
| Wi-Fi 6                 | Higher throughput and better co-existence in dense RF environments    |
| Low-power (LP) core     | Dedicated LP core + LP peripherals enable deep-sleep sensor polling   |

---

## 4. Toolchain

| Component      | Choice                           |
|----------------|----------------------------------|
| Framework      | Arduino                          |
| Build system   | PlatformIO                       |
| Board package  | `espressif32` ≥ 3.0.0            |
| Language       | C++17                            |
| IDE            | VS Code + PlatformIO extension   |

---

## 5. Build Flags

Two build flags are set in `platformio.ini` and are **required** for USB-CDC serial to work without an external UART bridge:

| Flag                        | Purpose                                                        |
|-----------------------------|----------------------------------------------------------------|
| `-DARDUINO_USB_MODE=1`      | Selects USB-OTG mode (required for built-in CDC on ESP32-C6)   |
| `-DARDUINO_USB_CDC_ON_BOOT=1` | Enables the USB-CDC ACM device at boot so `Serial` routes over USB instead of the hardware UART pins |

Without these flags, `Serial.println()` output goes to the hardware UART pins (D6/D7) and is invisible when connected via USB-C alone.

---

## 6. Repository Conventions

- **One `[env]` per board variant** in `platformio.ini` — keeps multi-board projects unambiguous.
- **Named constants for magic numbers** — all GPIO numbers and timing values are `static constexpr` identifiers; no bare literals in logic code.

---

## 7. Blink Design Decisions

| Decision          | Choice                   | Rationale                                                        |
|-------------------|--------------------------|------------------------------------------------------------------|
| LED pin           | GPIO15 (onboard LED)     | No external wiring needed; validates GPIO output immediately     |
| Blink rate        | 1 Hz (500 ms on/off)     | Clearly visible; matches conventional "heartbeat" firmware test  |
| Serial logging    | `Serial.println()`       | Confirms USB-CDC path works end-to-end                           |
| Timing mechanism  | `delay()`                | Simplest approach; acceptable for a single-task blink example    |

### LED Polarity Note

The onboard user LED on the XIAO ESP32-C6 is **active HIGH** (drive GPIO15 HIGH to turn on). This differs from some other XIAO variants where the LED is active LOW.

---

## 8. Firmware Flow

```
┌──────────────────────────────┐
│           setup()            │
│  Serial.begin(115200)        │
│  pinMode(USER_LED, OUTPUT)   │
│  digitalWrite(USER_LED, LOW) │
│  Serial.println("... ready") │
└──────────────┬───────────────┘
               │
               ▼
┌──────────────────────────────┐
│           loop()             │◄─────────────┐
│  digitalWrite(HIGH)          │              │
│  Serial.println("LED ON")    │              │
│  delay(500)                  │              │
│  digitalWrite(LOW)           │              │
│  Serial.println("LED OFF")   │              │
│  delay(500)                  │──────────────┘
└──────────────────────────────┘
```

---

## 9. Power Modes

| Mode        | Typical Current | Notes                                          |
|-------------|-----------------|------------------------------------------------|
| Active      | ~22 mA          | Wi-Fi TX peak; CPU running at full speed       |
| Modem-sleep | ~30 mA          | CPU active, radio in low-power state           |
| Light-sleep | ~3.1 mA         | CPU paused, RAM retained, fast wake            |
| Deep-sleep  | ~15 µA          | CPU + most peripherals off; RTC & LP core active |

---

## 10. Future Work

- [ ] Wi-Fi station provisioning (SoftAP + web portal or BLE provisioning)
- [ ] MQTT telemetry over Wi-Fi
- [ ] Zigbee coordinator / end-device example
- [ ] Thread / Matter commissioning
- [ ] Deep sleep + timer wakeup for low-power sensor polling
- [ ] OTA firmware update via Arduino OTA or ESP-IDF OTA
- [ ] Unit tests with PlatformIO native environment

---

## 11. References

| Resource                     | URL                                                                 |
|------------------------------|---------------------------------------------------------------------|
| Seeed Getting Started wiki   | https://wiki.seeedstudio.com/xiao_esp32c6_getting_started/          |
| ESP32-C6 datasheet           | https://www.espressif.com/sites/default/files/documentation/esp32-c6_datasheet_en.pdf |
| XIAO ESP32-C6 schematic      | https://files.seeedstudio.com/wiki/SeeedStudio-XIAO-ESP32C6/XIAO_ESP32C6_SCH_v1.0_230912.pdf |
| Arduino ESP32 docs           | https://docs.espressif.com/projects/arduino-esp32/en/latest/        |
| PlatformIO espressif32       | https://registry.platformio.org/platforms/platformio/espressif32    |
