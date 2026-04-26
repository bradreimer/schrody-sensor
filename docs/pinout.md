# ESP32-C3 Pinout Notes

This project now targets the PlatformIO board profile `esp32-c3-devkitm-1`.

Because many ESP32-C3 boards exist with different silk labels and header layouts,
always confirm your board's vendor pinout diagram before wiring sensors.

---

## Project Wiring (Current)

| Signal     | GPIO | Notes                          |
|------------|------|--------------------------------|
| DHT22 Data | 18   | Requires pull-up (typ. 10k)    |
| 3V3        | —    | Sensor VCC                     |
| GND        | —    | Sensor ground                  |

---

## ESP32-C3 GPIO Guidance

| GPIO Range | Typical Use                                      |
|------------|--------------------------------------------------|
| 0-7        | General-purpose I/O, many ADC-capable            |
| 8-9        | Often connected to on-module flash; avoid for I/O|
| 10-21      | General-purpose digital I/O (board-dependent)    |

---

## Serial and Upload Notes

- USB CDC serial is enabled at boot via project build flags.
- If upload fails, hold BOOT, reset/connect USB, and retry upload.

---

## References

| Resource           | URL                                                                 |
|--------------------|---------------------------------------------------------------------|
| ESP32-C3 datasheet | https://www.espressif.com/sites/default/files/documentation/esp32-c3_datasheet_en.pdf |
| Arduino ESP32 docs | https://docs.espressif.com/projects/arduino-esp32/en/latest/       |
