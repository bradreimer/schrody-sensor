# schrody-sensor

Low-power sensor firmware for **ESP32-C3** boards, built with PlatformIO and the Arduino framework.

---

## Hardware Summary

| Attribute     | Detail                                              |
|---------------|-----------------------------------------------------|
| SoC           | Espressif ESP32-C3 (32-bit RISC-V @ up to 160 MHz) |
| Flash         | 4 MB                                                |
| SRAM          | 400 KB                                              |
| Wireless      | Wi-Fi 4 (802.11 b/g/n), BLE 5.0                     |
| Form factor   | Depends on board variant (DevKit, SuperMini, etc.) |

---

## Repository Structure

```plain
schrody-sensor/
├── src/
│   └── main.cpp          # Firmware source (DHT22 monitor)
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
3. Select **Tools → Board → ESP32 Arduino → ESP32C3 Dev Module**.
4. Open `src/main.cpp`, compile, and upload.

---

## Useful Resources

| Resource                    | URL                                                                 |
|-----------------------------|---------------------------------------------------------------------|
| ESP32-C3 datasheet          | https://www.espressif.com/sites/default/files/documentation/esp32-c3_datasheet_en.pdf |
| ESP32-C3 product page       | https://www.espressif.com/en/products/socs/esp32-c3                |
| Arduino-ESP32 docs          | https://docs.espressif.com/projects/arduino-esp32/en/latest/       |
| PlatformIO board page       | https://registry.platformio.org/boards/platformio/espressif32/esp32-c3-devkitm-1 |
