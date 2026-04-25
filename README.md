# schrody-sensor

Low-power sensor firmware for the **Seeed Studio XIAO ESP32-C6** microcontroller, built with PlatformIO and the Arduino framework.

---

## Hardware Summary

| Attribute     | Detail                                              |
|---------------|-----------------------------------------------------|
| SoC           | Espressif ESP32-C6 (32-bit RISC-V @ up to 160 MHz) |
| Flash         | 4 MB                                                |
| SRAM          | 512 KB                                              |
| Wireless      | Wi-Fi 6 (802.11ax), BLE 5.0, Zigbee, Thread/Matter |
| Form factor   | XIAO (21 × 17.5 mm), castellated pads, USB-C       |

---

## Repository Structure

```
schrody-sensor/
├── src/
│   └── main.cpp          # Firmware source (blink example)
├── docs/
│   ├── design.md         # Design decisions and architecture
│   └── pinout.md         # Complete GPIO reference
├── platformio.ini        # PlatformIO project configuration
├── README.md
├── PROMPT.md             # AI prompt used to scaffold the project
└── .gitignore
```

---

## Prerequisites

Install **one** of the following:

- [PlatformIO CLI](https://docs.platformio.org/en/latest/core/installation/index.html) (`pip install platformio`)
- [PlatformIO IDE extension for VS Code](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)

---

## Getting Started

### 1 — Clone the repository

```sh
git clone https://github.com/bradreimer/schrody-sensor.git
cd schrody-sensor
```

### 2 — Build

```sh
pio run
```

### 3 — Flash

Connect the XIAO ESP32-C6 via USB-C, then:

```sh
pio run --target upload
```

> **Bootloader mode** (if auto-reset fails):
> Hold the **BOOT** button → plug in USB-C → release **BOOT** → run the upload command → press **RESET**.

### 4 — Monitor serial output

```sh
pio device monitor
```

Expected output:

```
XIAO ESP32-C6 Blink — ready
LED ON
LED OFF
LED ON
...
```

---

## Arduino IDE (Alternative)

1. Open **File → Preferences** and add the Espressif board manager URL:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
2. Install **esp32 by Espressif Systems** ≥ 3.0.0 via **Tools → Board → Boards Manager**.
3. Select **Tools → Board → ESP32 Arduino → XIAO_ESP32C6**.
4. Open `src/main.cpp`, compile, and upload.

---

## Useful Resources

| Resource                    | URL                                                                 |
|-----------------------------|---------------------------------------------------------------------|
| Seeed Getting Started wiki  | https://wiki.seeedstudio.com/xiao_esp32c6_getting_started/          |
| ESP32-C6 datasheet          | https://www.espressif.com/sites/default/files/documentation/esp32-c6_datasheet_en.pdf |
| XIAO ESP32-C6 schematic     | https://files.seeedstudio.com/wiki/SeeedStudio-XIAO-ESP32C6/XIAO_ESP32C6_SCH_v1.0_230912.pdf |
| Official pinout spreadsheet | https://wiki.seeedstudio.com/xiao_esp32c6_getting_started/#hardware-overview |
| PlatformIO board page       | https://registry.platformio.org/boards/seeed_xiao_esp32c6          |
