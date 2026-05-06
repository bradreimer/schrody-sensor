# Getting Started

This project uses a local Python virtual environment and installs ESPHome tooling from `pyproject.toml`.

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

This installs the pinned tooling versions defined in `pyproject.toml`.

## 4. Verify ESPHome

```sh
esphome version
```

## 5. Validate configuration

```sh
esphome config schrody-outdoor-01.yaml
```

## 6. Build and flash firmware

```sh
esphome run schrody-outdoor-01.yaml
```

For an indoor node, run:

```sh
esphome run schrody-indoor-01.yaml
```

## Bootloader mode (if upload fails)

Hold BOOT, connect USB-C, release BOOT, then retry `esphome run ...`.
