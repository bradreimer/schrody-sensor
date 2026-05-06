# Design Document — schrody-sensor

## 1. Project Overview

`schrody-sensor` is an ESPHome-based firmware project targeting **ESP32-C6** hardware. The primary node configuration reads a DHT22 sensor on GPIO7 and publishes temperature/humidity over encrypted ESPHome API across Thread (OpenThread).

---

## 2. Target Hardware

| Attribute     | Detail                                      |
|---------------|---------------------------------------------|
| SoC           | Espressif ESP32-C6 (RISC-V)                 |
| CPU           | 32-bit RISC-V @ up to 160 MHz               |
| Flash         | Commonly 4 MB on dev boards                 |
| SRAM          | 400 KB                                      |
| Wireless      | Wi-Fi 6, BLE 5.0, IEEE 802.15.4             |
| USB           | Native USB Serial/JTAG on supported boards  |

---

## 3. Firmware Behavior

| Function       | Implementation                              |
|----------------|---------------------------------------------|
| Sensor type    | DHT22                                       |
| Sensor pin     | GPIO7                                       |
| Sample period  | 5 minutes (outdoor profile)                 |
| Output         | Temperature in Celsius + humidity in %RH    |
| Error handling | ESPHome component state/error reporting     |

---

## 4. Toolchain

| Component      | Choice                           |
|----------------|----------------------------------|
| Firmware stack | ESPHome                          |
| Transport      | ESPHome API over IPv6            |
| Mesh protocol  | OpenThread                       |
| Target board   | `seeed_xiao_esp32c6`             |
| IDE            | VS Code + ESPHome CLI            |

---

## 5. Networking and Power Strategy

The outdoor profile uses OpenThread MTD mode with a long poll period to behave as a sleepy end device:

| Setting              | Value  | Purpose                                                  |
|----------------------|--------|----------------------------------------------------------|
| `device_type`        | `MTD`  | Reduced Thread device profile for battery operation      |
| `poll_period`        | `5min` | Lets parent buffer traffic while radio sleeps            |
| `network.enable_ipv6`| `true` | Required for native ESPHome API operation over Thread    |

---

## 6. Repository Conventions

- One YAML file per physical node profile.
- Secrets and credentials are provided through `secrets.yaml`.
- Runtime logs are emitted by ESPHome logger over USB serial.

---

## 7. Future Work

- [ ] Add explicit safe-mode diagnostics for early boot crashes
- [ ] Add battery voltage sensing and low-battery reporting
- [ ] Evaluate deep-sleep wake cycles vs sleepy-end-device polling
- [ ] Add OTA maintenance playbook for Thread devices

---

## 8. References

| Resource               | URL                                                                                   |
|------------------------|---------------------------------------------------------------------------------------|
| ESP32-C6 datasheet     | https://www.espressif.com/sites/default/files/documentation/esp32-c6_datasheet_en.pdf |
| ESPHome docs           | https://esphome.io                                                                      |
| OpenThread docs        | https://openthread.io                                                                   |
