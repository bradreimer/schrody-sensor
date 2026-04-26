# Project Recreation Prompt

Use the following prompt to recreate this project from scratch with an AI coding assistant.

---

Initialize a new embedded firmware repository called `schrody-sensor` for an **ESP32-C3** board. The project should use **PlatformIO** as the build system and the **Arduino framework** via the `espressif32` platform package.

**Repository structure to create:**
```
schrody-sensor/
├── src/
│   └── main.cpp
├── docs/
│   ├── design.md
│   └── pinout.md
├── platformio.ini
├── README.md
├── PROMPT.md
└── .gitignore
```

**Initialize a git repo** with an initial commit containing all files.

---

**`platformio.ini`** — Target `esp32-c3-devkitm-1`, Arduino framework, `espressif32` platform, upload speed 921600, monitor speed 115200, and build flags `-DARDUINO_USB_MODE=1` and `-DARDUINO_USB_CDC_ON_BOOT=1`.

---

**`src/main.cpp`** — A DHT22 monitor that:
- Uses `GPIO18` for DHT22 data as a `static constexpr uint8_t`
- Samples every 10 seconds using a `static constexpr uint32_t` interval
- In `setup()`: calls `Serial.begin(115200)`, initializes DHT, and prints a startup message
- In `loop()`: reads humidity and Celsius temperature, prints values, and handles read failures
- Includes comments documenting purpose and non-obvious logic

---

**`README.md`** — A thorough getting-started guide covering:
- Project description and hardware summary table (SoC, flash, SRAM, wireless, form factor)
- Repository structure tree
- Prerequisites (PlatformIO CLI or VS Code extension)
- Steps to clone, build (`pio run`), flash (`pio run --target upload`), and monitor serial (`pio device monitor`)
- Bootloader mode instructions (hold BOOT, plug USB-C, release BOOT)
- Arduino IDE alternative setup (Espressif board manager URL, board package ≥ 3.0.0, select `ESP32C3 Dev Module`)
- A table of useful resource links: ESP32-C3 datasheet, Arduino ESP32 docs, and PlatformIO board page

---

**`docs/pinout.md`** — ESP32-C3 pinout guidance that:
- Documents the current DHT22 wiring on GPIO18
- Notes board-to-board pin-label differences
- Includes safe GPIO usage guidance for ESP32-C3 boards

---

**`docs/design.md`** — A design document covering:
- Project overview and DHT22 telemetry behavior
- Target hardware table (SoC, CPU, flash, SRAM, wireless, form factor, USB)
- Rationale for ESP32-C3 target and USB serial workflow
- Toolchain table (Framework: Arduino; Build system: PlatformIO; Board package: espressif32 ≥ 3.0.0; Language: C++17; IDE: VS Code + PlatformIO)
- Explanation of the two build flags and why they are required
- Repository conventions (one env per board variant, named constants for magic numbers)
- DHT22 design decisions in a table: sensor pin, sample interval, serial logging, and error handling
- ASCII flow diagram of `setup()` and `loop()` for periodic sensing
- Power modes table (active, modem-sleep, light-sleep, deep-sleep) with current values
- Future work checklist (Wi-Fi provisioning, MQTT, Zigbee, Thread/Matter, deep sleep + timer wakeup, OTA, unit tests)
- References section with links to ESP32-C3 datasheet, Arduino ESP32 docs, and PlatformIO docs

---

**`.gitignore`** — Ignore: `.pio/`, `.pioenvs/`, `.piolibdeps/`, `.clang_format`, `.travis.yml`, `.ccls-cache/`, `.vscode/`, `.DS_Store`, `build/`, `dist/`, `__pycache__/`, `*.pyc`.
