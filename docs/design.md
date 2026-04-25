# Design Document — schrody-sensor

## 1. Project Overview

`schrody-sensor` is an embedded firmware project targeting the **Seeed Studio XIAO ESP32-C6**.
The initial milestone is a **blink example** whose sole purpose is end-to-end toolchain
validation: prove that the PlatformIO environment can compile, flash, and communicate
with the board over USB-CDC serial before adding any application logic.

---

## 2. Target Hardware

| Attribute    | Detail                                                       |
|--------------|--------------------------------------------------------------|
| SoC          | Espressif ESP32-C6 (QFN40)                                   |
| CPU          | 32-bit RISC-V (RV32IMAC), up to 160 MHz HP core + 20 MHz LP core |
| Flash        | 4 MB (on-board SPI NOR)                                      |
| SRAM         | 512 KB (HP) + 16 KB (LP)                                     |
| Wireless     | Wi-Fi 6 (802.11ax 2.4 GHz), BLE 5.0, Zigbee 3.0, Thread / Matter |
| Form factor  | XIAO (21 × 17.5 mm), castellated + SMD pads, breadboard-friendly |
| USB          | USB-C (USB 2.0 Full Speed), built-in USB-Serial/JTAG controller |

---

## 3. Hardware Choice Rationale

| Reason                  | Detail                                                         |
|-------------------------|----------------------------------------------------------------|
| XIAO footprint          | Tiny module fits prototype and final PCBs without re-spinning  |
| Matter / Thread support | Native IEEE 802.15.4 radio enables future smart-home protocols |
| Wi-Fi 6                 | Better coexistence and lower power vs. Wi-Fi 4                 |
| LP core                 | Allows sensor polling to continue during HP deep-sleep         |
| Integrated USB-CDC      | No external UART chip needed for flashing or debug logging     |

---

## 4. Toolchain

| Component      | Choice                          | Notes                                          |
|----------------|---------------------------------|------------------------------------------------|
| Framework      | Arduino                         | Rapid prototyping; large library ecosystem     |
| Build system   | PlatformIO                      | Reproducible builds, dependency pinning        |
| Board package  | espressif32 ≥ 3.0.0             | First release with stable C6 / Matter support  |
| Language       | C++17                           | PlatformIO default for espressif32             |
| IDE            | VS Code + PlatformIO extension  | IntelliSense, integrated upload/monitor        |

---

## 5. Build Flags

Two build flags are mandatory for USB-CDC serial to function without an external UART bridge:

| Flag                        | Purpose                                                                 |
|-----------------------------|-------------------------------------------------------------------------|
| `-DARDUINO_USB_MODE=1`      | Switches the USB peripheral to **TinyUSB** mode (native CDC)           |
| `-DARDUINO_USB_CDC_ON_BOOT=1` | Starts the CDC device at boot so `Serial` is available immediately   |

Without these flags, `Serial.println()` will produce no output and the monitor will be silent.

---

## 6. Repository Conventions

- **One `[env]` per board variant** in `platformio.ini` — avoids accidental cross-board flashing.
- **Named constants** (`static constexpr`) for all magic numbers (pin numbers, intervals, baud rates).
- Source lives in `src/`; documentation in `docs/`.

---

## 7. Blink Design Decisions

| Decision         | Choice                    | Rationale                                                    |
|------------------|---------------------------|--------------------------------------------------------------|
| LED pin          | GPIO15 (onboard USER_LED) | No external hardware required; validates GPIO output path    |
| LED polarity     | Active HIGH               | GPIO15 on the C6 is active HIGH — unlike some other XIAO variants which are active LOW |
| Blink rate       | 1 Hz (500 ms on/off)      | Clearly visible; easy to verify with a stopwatch            |
| Serial logging   | `Serial.println` each toggle | Confirms USB-CDC is working in parallel with GPIO          |
| Timing mechanism | `delay()`                 | Sufficient for a blink demo; future work will use non-blocking timers |

---

## 8. Control Flow

```
                      ┌──────────┐
                      │  setup() │
                      └────┬─────┘
                           │
              ┌────────────▼─────────────┐
              │  Serial.begin(115200)    │
              │  pinMode(LED, OUTPUT)    │
              │  digitalWrite(LED, LOW)  │
              │  Serial.println("ready") │
              └────────────┬─────────────┘
                           │
                      ┌────▼─────┐
               ┌──────│  loop()  │◄─────────────────┐
               │      └──────────┘                   │
               │                                     │
               │  digitalWrite(LED, HIGH)             │
               │  Serial.println("LED ON")            │
               │  delay(500)                          │
               │                                     │
               │  digitalWrite(LED, LOW)              │
               │  Serial.println("LED OFF")           │
               │  delay(500)                          │
               └─────────────────────────────────────┘
```

---

## 9. Power Modes

| Mode        | HP Core | LP Core | Wi-Fi / BLE | Typical Current |
|-------------|---------|---------|-------------|-----------------|
| Active      | On      | On      | On          | 20–100 mA       |
| Modem-sleep | On      | On      | Off         | ~30 mA          |
| Light-sleep | Paused  | On      | Off         | ~3.1 mA         |
| Deep-sleep  | Off     | On/Off  | Off         | ~15 µA          |

The blink example runs in **active** mode. Future power-optimised builds will use light-sleep
or deep-sleep with timer wakeup.

---

## 10. Future Work

- [ ] Wi-Fi provisioning (SoftAP / BLE provisioning)
- [ ] MQTT sensor data publishing
- [ ] Zigbee coordinator / end-device mode
- [ ] Thread / Matter commissioning
- [ ] Deep sleep + timer wakeup (RTC or LP core)
- [ ] OTA firmware updates (ESP-IDF OTA or Arduino `Update` library)
- [ ] Unit tests (PlatformIO test runner + Unity framework)
- [ ] Non-blocking blink using `millis()`

---

## 11. References

| Resource | URL |
|----------|-----|
| ESP32-C6 datasheet | https://www.espressif.com/sites/default/files/documentation/esp32-c6_datasheet_en.pdf |
| XIAO ESP32-C6 schematic | https://files.seeedstudio.com/wiki/SeeedStudio-XIAO-ESP32C6/XIAO_ESP32C6_SCH_v1.0.pdf |
| Seeed Getting Started wiki | https://wiki.seeedstudio.com/xiao_esp32c6_getting_started/ |
| Arduino ESP32 docs | https://docs.espressif.com/projects/arduino-esp32/en/latest/ |
| PlatformIO espressif32 platform | https://docs.platformio.org/en/latest/platforms/espressif32.html |
| PlatformIO board page | https://docs.platformio.org/en/latest/boards/espressif32/seeed_xiao_esp32c6.html |
