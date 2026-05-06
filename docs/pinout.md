# ESP32-C3 and ESP32-C6 Pinout Notes

This workspace contains both ESP32-C3 and ESP32-C6 node configurations:

- Indoor node: seeed_xiao_esp32c3
- Outdoor node: seeed_xiao_esp32c6

Because board vendors may use different silk labels and header layouts,
always confirm your exact board pinout before wiring sensors.

---

## Project Wiring (Current)

| Node               | Board               | DHT22 Data GPIO | Notes                       |
|--------------------|---------------------|-----------------|-----------------------------|
| schrody-indoor-01  | seeed_xiao_esp32c3  | GPIO7           | Wi-Fi profile               |
| schrody-outdoor-01 | seeed_xiao_esp32c6  | GPIO7           | OpenThread sleepy end device|

Shared sensor wiring:

| Signal     | Connection |
|------------|------------|
| DHT22 Data | GPIO7      |
| DHT22 VCC  | 3V3        |
| DHT22 GND  | GND        |

---

## ESP32-C3 GPIO Guidance

| GPIO Range | Typical Use                                      |
|------------|--------------------------------------------------|
| 0-7        | General-purpose I/O and ADC-capable pins         |
| 8-9        | Commonly tied to internal flash on many boards   |
| 10-21      | General-purpose digital I/O (board-dependent)    |

## ESP32-C6 GPIO Guidance

| GPIO Range | Typical Use                                      |
|------------|--------------------------------------------------|
| 0-7        | General-purpose I/O, many ADC-capable            |
| 8-9        | Commonly connected to flash or board internals   |
| 10-23      | General-purpose digital I/O (board-dependent)    |

---

## Serial and Upload Notes

- ESPHome logs are available over serial and API once connected.
- If upload fails, hold BOOT, connect USB, release BOOT, and retry upload.
- Keep data pin choices consistent across board families when possible to simplify YAML reuse.

---

## References

| Resource           | URL                                                                                   |
|--------------------|---------------------------------------------------------------------------------------|
| ESP32-C3 datasheet | https://www.espressif.com/sites/default/files/documentation/esp32-c3_datasheet_en.pdf |
| ESP32-C6 datasheet | https://www.espressif.com/sites/default/files/documentation/esp32-c6_datasheet_en.pdf |
| ESPHome docs       | https://esphome.io                                                                    |
