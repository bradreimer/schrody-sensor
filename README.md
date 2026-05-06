# schrody-sensor

Low-power sensor firmware for **ESP32-C6** boards using ESPHome with OpenThread.

---

## Hardware Summary

| Attribute     | Detail                                              |
|---------------|-----------------------------------------------------|
| SoC           | Espressif ESP32-C6 (32-bit RISC-V @ up to 160 MHz) |
| Flash         | 4 MB                                                |
| SRAM          | 400 KB                                              |
| Wireless      | Wi-Fi 4 (802.11 b/g/n), BLE 5.0                     |
| Thread        | IEEE 802.15.4 (OpenThread)                          |
| Form factor   | Depends on board variant (DevKit, SuperMini, etc.) |

---

## Repository Structure

```plain
schrody-sensor/
├── schrody-indoor-01.yaml # ESPHome config (indoor sensor)
├── schrody-outdoor-01.yaml # ESPHome config (outdoor sensor)
├── secrets.yaml           # Local secrets (not for commit)
├── docs/
│   ├── getting-started.md # Local setup and first build/flash workflow
│   ├── design.md         # Design decisions and architecture
│   └── pinout.md         # Complete GPIO reference
├── pyproject.toml        # Python tool dependencies (ESPHome tooling)
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
esphome config schrody-outdoor-01.yaml
esphome run schrody-outdoor-01.yaml
```

---

## Configuration Workflow

Edit the ESPHome YAML for your device and compile/upload with ESPHome tooling.

---

## Useful Resources

| Resource                    | URL                                                                 |
|-----------------------------|---------------------------------------------------------------------|
| ESP32-C6 datasheet          | https://www.espressif.com/sites/default/files/documentation/esp32-c6_datasheet_en.pdf |
| ESP32-C6 product page       | https://www.espressif.com/en/products/socs/esp32-c6                |
| OpenThread docs             | https://openthread.io                                               |
| ESPHome docs                | https://esphome.io                                                  |
