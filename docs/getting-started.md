# Getting Started

This project uses a local Python virtual environment and installs PlatformIO from `pyproject.toml`.

## Prerequisites

- Python 3.12.x
- `pip` (bundled with Python)

Optional (recommended): `pyenv` to manage Python versions.

## 1. Clone the repository

```sh
git clone https://github.com/bradreimer/schrody-sensor.git
cd schrody-sensor
```

## 2. Create and activate a virtual environment

```sh
python3 -m venv .venv
source .venv/bin/activate
```

## 3. Install dependencies from pyproject

```sh
python -m pip install --upgrade pip setuptools wheel
python -m pip install .
```

This installs PlatformIO at the pinned version defined in `pyproject.toml`.

## 4. Verify PlatformIO

```sh
platformio --version
```

## 5. Build and flash firmware

```sh
platformio run
platformio run --target upload
platformio device monitor
```

## Bootloader mode (if upload fails)

Hold the BOOT button, connect USB-C, release BOOT, upload again, then press RESET.
