# XIAO ESP32-C6 — GPIO Pinout Reference

Source: <https://wiki.seeedstudio.com/xiao_esp32c6_getting_started/>

---

## Board Diagram (Top View)

```
                  USB-C
                ┌───────┐
      5V ───── │ 5V    │
     GND ───── │ GND   │
      3V ───── │ 3V3   │
      D0 ───── │ GPIO2 │ ────  GPIO2  (A0)
      D1 ───── │ GPIO3 │ ────  GPIO3  (A1 / RF-SW power)
      D2 ───── │ GPIO4 │ ────  GPIO4  (A2 / JTAG TCK)
      D3 ───── │ GPIO5 │ ────  GPIO5  (A3 / JTAG TMS)
      D4 ───── │ GPIO6 │ ────  GPIO6  (SDA / JTAG TDI)
      D5 ───── │ GPIO7 │ ────  GPIO7  (SCL / JTAG TDO)
      D6 ───── │ GPIO21│ ────  GPIO21 (TX0)
      D7 ───── │ GPIO20│ ────  GPIO20 (RX0)
      D8 ───── │ GPIO19│ ────  GPIO19 (SCK)
      D9 ───── │ GPIO18│ ────  GPIO18 (MISO)
     D10 ───── │ GPIO17│ ────  GPIO17 (MOSI)
               │       │
               │ GPIO9 │ ────  BOOT button (internal pull-up)
               │GPIO15 │ ────  USER_LED (active HIGH, orange)
               │GPIO14 │ ────  Antenna select
               └───────┘
     [BAT+]   [BAT−]  ← solder pads on reverse side
```

---

## Full Pin Map

| Silk Label | Function      | GPIO | LP GPIO | Notes                                           |
|------------|---------------|------|---------|-------------------------------------------------|
| D0         | GPIO / ADC    | 2    | —       | ADC1_CH2                                        |
| D1         | GPIO / ADC    | 3    | LP_IO3  | ADC1_CH3; used internally for RF-switch power   |
| D2         | GPIO / ADC    | 4    | LP_IO4  | ADC1_CH4; JTAG TCK                              |
| D3         | GPIO / ADC    | 5    | LP_IO5  | ADC1_CH5; JTAG TMS                              |
| D4         | SDA / GPIO    | 6    | LP_IO6  | Default I²C SDA; JTAG TDI                       |
| D5         | SCL / GPIO    | 7    | LP_IO7  | Default I²C SCL; JTAG TDO                       |
| D6         | TX / GPIO     | 21   | —       | Default UART0 TX                                |
| D7         | RX / GPIO     | 20   | —       | Default UART0 RX                                |
| D8         | SCK / GPIO    | 19   | —       | Default SPI SCK                                 |
| D9         | MISO / GPIO   | 18   | —       | Default SPI MISO                                |
| D10        | MOSI / GPIO   | 17   | —       | Default SPI MOSI                                |
| —          | BOOT button   | 9    | LP_IO9  | Internal pull-up; hold on power-up for DFU mode |
| —          | USER_LED      | 15   | —       | Onboard orange LED; **active HIGH**              |
| —          | RF-SW power   | 3    | LP_IO3  | Shared with D1; controls RF switch VCC          |
| —          | Antenna select| 14   | —       | LOW = ceramic/PCB antenna (default); HIGH = UFL  |

---

## JTAG Debug Pads

| Signal | GPIO |
|--------|------|
| TCK    | 4    |
| TMS    | 5    |
| TDI    | 6    |
| TDO    | 7    |

These pads are accessible via the castellated / SMD holes; they overlap with D2–D5.

---

## ADC-Capable Pins

| Silk Label | GPIO | ADC Channel |
|------------|------|-------------|
| D0         | 2    | ADC1_CH2    |
| D1         | 3    | ADC1_CH3    |
| D2         | 4    | ADC1_CH4    |
| D3         | 5    | ADC1_CH5    |

> Note: ADC2 is not available on the ESP32-C6.  
> Do **not** use ADC while Wi-Fi is active — use ADC1 only and be aware of noise.

---

## Communication Interfaces

| Interface | Signal | Default GPIO | Silk Label |
|-----------|--------|--------------|------------|
| I²C       | SDA    | 6            | D4         |
| I²C       | SCL    | 7            | D5         |
| SPI       | SCK    | 19           | D8         |
| SPI       | MISO   | 18           | D9         |
| SPI       | MOSI   | 17           | D10        |
| SPI       | CS     | user-defined | —          |
| UART0     | TX     | 21           | D6         |
| UART0     | RX     | 20           | D7         |
| LP_UART   | TX     | LP_IO4 (GPIO4) | D2      |
| LP_UART   | RX     | LP_IO5 (GPIO5) | D3      |

---

## Power Notes

| Parameter               | Value                          |
|-------------------------|--------------------------------|
| Operating voltage       | 3.3 V (on-board LDO)           |
| USB-C input             | 5 V                            |
| Battery pad             | BAT+ / BAT− (solder pads, rear)|
| Battery polarity        | BAT+ = positive terminal       |
| Active current          | ~20–100 mA (varies with radio) |
| Modem-sleep current     | ~30 mA                         |
| Light-sleep current     | ~3.1 mA                        |
| Deep-sleep current      | ~15 µA                         |
| 5 V rail (battery-only) | **Not available** — 5 V pin is unpowered when running from battery only |
