# Project Recreation Prompt

Use the following prompt to recreate this project from scratch with an AI coding assistant.

---

Initialize a new embedded firmware repository called `schrody-sensor` for an **ESP32-C6** board using **ESPHome** with **OpenThread** support for low-power Thread sensor nodes.

**Repository structure to create:**
```
schrody-sensor/
├── schrody-indoor-01.yaml
├── schrody-outdoor-01.yaml
├── secrets.yaml
├── docs/
│   ├── design.md
│   └── pinout.md
├── pyproject.toml
├── README.md
├── PROMPT.md
└── .gitignore
```

**Initialize a git repo** with an initial commit containing all files.

---

**`schrody-outdoor-01.yaml`** — ESPHome configuration that:
- Targets `seeed_xiao_esp32c6` with `framework: esp-idf`
- Enables `logger`, encrypted `api`, and `ota`
- Enables IPv6 networking
- Configures OpenThread with `device_type: MTD` and long `poll_period` for sleepy end-device behavior
- Reads DHT22 temperature/humidity from `GPIO7` every 5 minutes

---

**`schrody-indoor-01.yaml`** — Similar ESPHome configuration for indoor deployment, with board-specific naming and sensor entities.

---

**`README.md`** — A thorough getting-started guide covering:
- Project description and hardware summary table (SoC, flash, SRAM, wireless, form factor)
- Repository structure tree
- Prerequisites (Python + ESPHome CLI)
- Steps to clone, validate config (`esphome config ...`), and flash (`esphome run ...`)
- Bootloader mode instructions (hold BOOT, plug USB-C, release BOOT)
- A table of useful resource links: ESP32-C3/C6 datasheets, ESPHome docs, and OpenThread docs

---

**`docs/pinout.md`** — ESP32-C3 and ESP32-C6 pinout guidance that:
- Documents the current DHT22 wiring on GPIO7
- Notes board-to-board pin-label differences
- Includes safe GPIO usage guidance for both C3 and C6 boards

---

**`docs/design.md`** — A design document covering:
- Project overview and DHT22 telemetry behavior
- Target hardware table (SoC, CPU, flash, SRAM, wireless, form factor, USB)
- Rationale for ESP32-C6 Thread profile and ESP32-C3 Wi-Fi profile
- Toolchain table (Firmware stack: ESPHome; transport: ESPHome API; mesh protocol: OpenThread)
- Networking and power strategy for sleepy-end-device behavior
- Repository conventions (one YAML per node profile, secrets in secrets.yaml)
- Future work checklist (safe-mode diagnostics, battery telemetry, deep sleep vs SED tuning, OTA playbook)
- References section with links to ESP32-C3/C6 datasheets, ESPHome docs, and OpenThread docs

---

**`.gitignore`** — Ignore: `.esphome/`, `.vscode/`, `.DS_Store`, `build/`, `dist/`, `__pycache__/`, `*.pyc`, `.venv/`, `secrets.yaml`.
