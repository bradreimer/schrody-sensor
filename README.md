# schrody-sensor

Low-power sensor firmware for the **Seeed Studio XIAO ESP32-C6**.

## Hardware Summary

| Attribute    | Detail                                     |
|--------------|--------------------------------------------|
| SoC          | Espressif ESP32-C6 (RISC-V, single-core)   |
| Flash        | 4 MB                                       |
| SRAM         | 512 KB                                     |
| Wireless     | Wi-Fi 6 (802.11ax), BLE 5.0, Zigbee, Thread / Matter |
| Form factor  | XIAO (21 × 17.5 mm), castellated + SMD pads |
| USB          | USB-C (USB 2.0 Full Speed, built-in CDC)   |

## Repository Structure

```
schrody-sensor/
├── src/
│   └── main.cpp        # Firmware source
├── docs/
│   ├── design.md       # Architecture & design decisions
│   └── pinout.md       # Full GPIO reference
├── platformio.ini      # PlatformIO build configuration
├── README.md
├── PROMPT.md           # AI project-recreation prompt
└── .gitignore
```

## Prerequisites

- [PlatformIO CLI](https://docs.platformio.org/en/latest/core/installation/index.html) **or**
- [VS Code](https://code.visualstudio.com/) + [PlatformIO IDE extension](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)

## Getting Started

### 1 — Clone

```bash
git clone https://github.com/bradreimer/schrody-sensor.git
cd schrody-sensor
```

### 2 — Build

```bash
pio run
```

### 3 — Flash

```bash
pio run --target upload
```

> **Bootloader mode** — If the board does not reset into download mode automatically:
> hold the **BOOT** button, plug in the USB-C cable, then release **BOOT**.

### 4 — Monitor serial output

```bash
pio device monitor
```

Baud rate is set to **115200** in `platformio.ini`.

## Arduino IDE (alternative)

1. Open *File → Preferences* and add the Espressif board manager URL:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
2. Install the **esp32** board package **≥ 3.0.0** via *Tools → Board → Boards Manager*.
3. Select *Tools → Board → esp32 → **XIAO_ESP32C6***.
4. Set the upload port and click **Upload**.

## Useful Links

| Resource | URL |
|----------|-----|
| Seeed Getting Started wiki | https://wiki.seeedstudio.com/xiao_esp32c6_getting_started/ |
| ESP32-C6 datasheet | https://www.espressif.com/sites/default/files/documentation/esp32-c6_datasheet_en.pdf |
| XIAO ESP32-C6 schematic | https://files.seeedstudio.com/wiki/SeeedStudio-XIAO-ESP32C6/XIAO_ESP32C6_SCH_v1.0.pdf |
| Official pinout spreadsheet | https://files.seeedstudio.com/wiki/SeeedStudio-XIAO-ESP32C6/XIAO_ESP32C6_Pin_Multiplexing.pdf |
| PlatformIO board page | https://docs.platformio.org/en/latest/boards/espressif32/seeed_xiao_esp32c6.html |
