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

```plain
schrody-sensor/
├── src/
│   └── main.cpp          # Firmware source (blink example)
├── docs/
│   ├── getting-started.md # Local setup and first build/flash workflow
│   ├── design.md         # Design decisions and architecture
│   └── pinout.md         # Complete GPIO reference
├── platformio.ini        # PlatformIO project configuration
├── pyproject.toml        # Python tool dependencies (PlatformIO)
├── README.md
├── PROMPT.md             # AI prompt used to scaffold the project
└── .gitignore
```

---

## Prerequisites

- Python 3.12.x
- Optional: [pyenv](https://github.com/pyenv/pyenv) for managing Python versions

---

## Getting Started

Use the full setup guide in [docs/getting-started.md](docs/getting-started.md).

Quick start:

```sh
python3 -m venv .venv
source .venv/bin/activate
python -m pip install --upgrade pip setuptools wheel
python -m pip install .
platformio run
```

---

## Arduino IDE (Alternative)

1. Open **File → Preferences** and add the Espressif board manager URL:
   ```plain
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
