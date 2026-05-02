# Design Document — schrody-sensor

## 1. Project Overview

`schrody-sensor` is embedded firmware targeting **ESP32-C3** boards with PlatformIO and Arduino. The current application reads a DHT22 sensor on GPIO18 and publishes temperature/humidity every 10 seconds over USB serial.

---

## 2. Target Hardware

| Attribute     | Detail                                      |
|---------------|---------------------------------------------|
| SoC           | Espressif ESP32-C3 (RISC-V)                 |
| CPU           | 32-bit RISC-V @ up to 160 MHz               |
| Flash         | Commonly 4 MB on dev boards                 |
| SRAM          | 400 KB                                      |
| Wireless      | Wi-Fi 4 (802.11 b/g/n), BLE 5.0             |
| USB           | Native USB Serial/JTAG on supported boards  |

---

## 3. Firmware Behavior

| Function       | Implementation                              |
|----------------|---------------------------------------------|
| Sensor type    | DHT22                                       |
| Sensor pin     | GPIO18                                      |
| Sample period  | 10 seconds                                  |
| Output         | Temperature in Celsius + humidity in %RH    |
| Error handling | Prints `DHT22 read failed` on bad samples   |

---

## 4. Toolchain

| Component      | Choice                           |
|----------------|----------------------------------|
| Framework      | Arduino                          |
| Build system   | PlatformIO                       |
| Target board   | `esp32-c3-devkitm-1`             |
| Language       | C++17                            |
| IDE            | VS Code + PlatformIO extension   |

---

## 5. Build Flags

The project enables USB serial support through these `platformio.ini` flags:

| Flag                           | Purpose                                              |
|--------------------------------|------------------------------------------------------|
| `-DARDUINO_USB_MODE=1`         | Enables USB mode used by Arduino-ESP32               |
| `-DARDUINO_USB_CDC_ON_BOOT=1`  | Starts USB CDC on boot for `Serial` output           |

---

## 6. Repository Conventions

- One active PlatformIO environment per board target.
- GPIO and timing constants use `static constexpr` names.
- Runtime logs are emitted over `Serial` at 115200 baud.

---

## 7. Future Work

- [ ] Add non-blocking sensor scheduling with explicit startup warmup
- [ ] Persist calibration/configuration in NVS
- [ ] Add deep-sleep sampling mode for low-power operation
- [ ] Add telemetry transport (MQTT/HTTP)

---

## 8. References

| Resource               | URL                                                                                   |
|------------------------|---------------------------------------------------------------------------------------|
| ESP32-C3 datasheet     | https://www.espressif.com/sites/default/files/documentation/esp32-c3_datasheet_en.pdf |
| Arduino ESP32 docs     | https://docs.espressif.com/projects/arduino-esp32/en/latest/                          |
| PlatformIO espressif32 | https://registry.platformio.org/platforms/platformio/espressif32                      |
