# Project Recreation Prompt

Use the following prompt to recreate this project from scratch with an AI coding assistant.

---

Initialize a new embedded firmware repository called `schrody-sensor` for the **Seeed Studio XIAO ESP32-C6** microcontroller. The project should use **PlatformIO** as the build system and the **Arduino framework** via the `espressif32` platform package.

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

**`platformio.ini`** — Target `seeed_xiao_esp32c6`, Arduino framework, `espressif32` platform, upload speed 921600, monitor speed 115200, and build flags `-DARDUINO_USB_MODE=1` and `-DARDUINO_USB_CDC_ON_BOOT=1` (required for USB-CDC serial to work without an external UART bridge).

---

**`src/main.cpp`** — A blink example that:
- Uses `GPIO15` (named `USER_LED`) as a `static constexpr uint8_t` — this is the onboard orange user LED on the XIAO ESP32-C6, **active HIGH**
- Uses `BLINK_INTERVAL_MS = 500` as a `static constexpr uint32_t`
- In `setup()`: calls `Serial.begin(115200)`, sets `USER_LED` as `OUTPUT`, drives it `LOW`, and prints `"XIAO ESP32-C6 Blink — ready"`
- In `loop()`: drives LED `HIGH`, prints `"LED ON"`, delays, drives `LOW`, prints `"LED OFF"`, delays
- Includes a full file header comment documenting the purpose, hardware, and PlatformIO build/monitor commands

---

**`README.md`** — A thorough getting-started guide covering:
- Project description and hardware summary table (SoC, flash, SRAM, wireless, form factor)
- Repository structure tree
- Prerequisites (PlatformIO CLI or VS Code extension)
- Steps to clone, build (`pio run`), flash (`pio run --target upload`), and monitor serial (`pio device monitor`)
- Bootloader mode instructions (hold BOOT, plug USB-C, release BOOT)
- Arduino IDE alternative setup (Espressif board manager URL, board package ≥ 3.0.0, select `XIAO_ESP32C6`)
- A table of useful resource links: Seeed Getting Started wiki, ESP32-C6 datasheet, schematic, official pinout spreadsheet, and PlatformIO board page

---

**`docs/pinout.md`** — A complete GPIO reference for the XIAO ESP32-C6 sourced from the Seeed Studio wiki (`https://wiki.seeedstudio.com/xiao_esp32c6_getting_started/`), including:
- An ASCII art board diagram (top view) showing all labeled pins on both sides
- A full pin map table with columns: Silk label, Function, GPIO number, LP GPIO, Notes
- All 11 user GPIOs (D0–D10) with their alternate functions (ADC, I²C, SPI, UART)
- JTAG debug pads (GPIO4–7)
- Special-purpose GPIOs: GPIO9 (BOOT button), GPIO15 (user LED, active HIGH), GPIO3 (RF switch power), GPIO14 (antenna select: LOW = ceramic/default, HIGH = external UFL)
- ADC-capable pin list
- Communication interfaces table (I²C, SPI, UART0, LP_UART) with default GPIO assignments
- Power notes: operating voltage, USB-C input, battery pad polarity, deep/light/modem-sleep current values (~15 µA / ~3.1 mA / ~30 mA), and the warning that 5 V is absent in battery-only mode

---

**`docs/design.md`** — A design document covering:
- Project overview and the purpose of the blink example (end-to-end toolchain validation)
- Target hardware table (SoC, CPU, flash, SRAM, wireless, form factor, USB)
- Rationale for hardware choice (XIAO footprint, Matter support, Wi-Fi 6, LP core)
- Toolchain table (Framework: Arduino; Build system: PlatformIO; Board package: espressif32 ≥ 3.0.0; Language: C++17; IDE: VS Code + PlatformIO)
- Explanation of the two build flags and why they are required
- Repository conventions (one env per board variant, named constants for magic numbers)
- Blink design decisions in a table: LED pin choice (GPIO15 onboard vs external), blink rate (1 Hz), serial logging, `delay()` vs non-blocking timers
- LED polarity note (active HIGH, unlike some other XIAO variants)
- ASCII flow diagram of `setup()` and `loop()`
- Power modes table (active, modem-sleep, light-sleep, deep-sleep) with current values
- Future work checklist (Wi-Fi provisioning, MQTT, Zigbee, Thread/Matter, deep sleep + timer wakeup, OTA, unit tests)
- References section with links to datasheet, schematic, Seeed wiki, Arduino ESP32 docs, PlatformIO platform docs

---

**`.gitignore`** — Ignore: `.pio/`, `.pioenvs/`, `.piolibdeps/`, `.clang_format`, `.travis.yml`, `.ccls-cache/`, `.vscode/`, `.DS_Store`, `build/`, `dist/`, `__pycache__/`, `*.pyc`.
