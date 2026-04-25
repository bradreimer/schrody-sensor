# XIAO ESP32-C6 GPIO Pinout Reference

> **Source:** [Seeed Studio XIAO ESP32-C6 Getting Started](https://wiki.seeedstudio.com/xiao_esp32c6_getting_started/)

---

## Board Diagram (Top View)

```
                    USB-C
                   ┌─────┐
              3V3 ─┤ 1  18├─ 5V
              GND ─┤ 2  17├─ GND
     D0 / GPIO2  ─┤ 3  16├─ GPIO21 / D10
     D1 / GPIO3  ─┤ 4  15├─ GPIO20 / D9
     D2 / GPIO0  ─┤ 5  14├─ GPIO19 / D8
     D3 / GPIO1  ─┤ 6  13├─ GPIO16 / D7 / RX
    D4 / GPIO22  ─┤ 7  12├─ GPIO17 / D6 / TX
    D5 / GPIO23  ─┤ 8  11├─ 3V3
               5V ─┤ 9  10├─ GND
                   └─────┘

    BOOT (GPIO9) — button on bottom side
    USER_LED (GPIO15) — orange LED on bottom side
```

> **Note:** Pin numbers above refer to the silk-screen labels on the board edge.
> The actual GPIO numbers differ — see the pin map table below.

---

## Pin Map Table

| Silk Label | Function          | GPIO # | LP GPIO | Notes                                      |
|------------|-------------------|--------|---------|--------------------------------------------|
| D0         | General I/O / ADC | GPIO2  | —       | ADC1_CH2                                   |
| D1         | General I/O / ADC | GPIO3  | —       | ADC1_CH3; also RF switch power control     |
| D2         | General I/O / ADC | GPIO0  | LP0     | ADC1_CH0; LP GPIO capable                  |
| D3         | General I/O / ADC | GPIO1  | LP1     | ADC1_CH1; LP GPIO capable                  |
| D4         | I²C SDA           | GPIO22 | —       | Default I²C SDA                            |
| D5         | I²C SCL           | GPIO23 | —       | Default I²C SCL                            |
| D6         | UART TX           | GPIO17 | —       | UART0 TX (USB-CDC when build flags set)    |
| D7         | UART RX           | GPIO16 | —       | UART0 RX (USB-CDC when build flags set)    |
| D8         | SPI SCK           | GPIO19 | —       | Default SPI clock                          |
| D9         | SPI MISO          | GPIO20 | —       | Default SPI MISO                           |
| D10        | SPI MOSI          | GPIO21 | —       | Default SPI MOSI                           |
| —          | BOOT button       | GPIO9  | LP9     | Active LOW; pull-up on board               |
| —          | User LED          | GPIO15 | —       | Onboard orange LED, **active HIGH**         |
| —          | RF switch power   | GPIO3  | —       | Controls power to the RF antenna switch    |
| —          | Antenna select    | GPIO14 | —       | LOW = ceramic antenna (default); HIGH = external UFL |

---

## JTAG Debug Pads

The following GPIOs are exposed as test pads on the underside of the board for JTAG debugging:

| Signal  | GPIO # |
|---------|--------|
| TCK     | GPIO4  |
| TDI     | GPIO5  |
| TDO     | GPIO6  |
| TMS     | GPIO7  |

---

## ADC-Capable Pins

| Pin Label | GPIO # | ADC Channel |
|-----------|--------|-------------|
| D0        | GPIO2  | ADC1_CH2    |
| D1        | GPIO3  | ADC1_CH3    |
| D2        | GPIO0  | ADC1_CH0    |
| D3        | GPIO1  | ADC1_CH1    |

> ADC2 is not available when Wi-Fi is active. Use ADC1 channels for reliable readings.

---

## Communication Interfaces

| Interface | Signal | GPIO # | Notes                                  |
|-----------|--------|--------|----------------------------------------|
| I²C       | SDA    | GPIO22 | D4; 400 kHz Fast-mode supported        |
| I²C       | SCL    | GPIO23 | D5                                     |
| SPI       | SCK    | GPIO19 | D8                                     |
| SPI       | MISO   | GPIO20 | D9                                     |
| SPI       | MOSI   | GPIO21 | D10                                    |
| SPI       | CS     | any    | User-defined                           |
| UART0     | TX     | GPIO17 | D6; re-mapped to USB-CDC by build flags|
| UART0     | RX     | GPIO16 | D7; re-mapped to USB-CDC by build flags|
| LP_UART   | TX     | GPIO5  | Low-power UART (JTAG pad)              |
| LP_UART   | RX     | GPIO4  | Low-power UART (JTAG pad)              |

---

## Power Notes

| Parameter              | Value / Detail                                              |
|------------------------|-------------------------------------------------------------|
| Operating voltage      | 3.3 V                                                       |
| USB-C input            | 5 V (regulated down to 3.3 V on board)                      |
| Battery pad polarity   | BAT+ / BAT− clearly marked; 3.7 V Li-Po                     |
| 5 V in battery mode    | **Not available** — 5 V rail is USB-sourced only            |
| Active current         | ~22 mA (Wi-Fi TX peak)                                      |
| Modem-sleep current    | ~30 mA                                                      |
| Light-sleep current    | ~3.1 mA                                                     |
| Deep-sleep current     | ~15 µA                                                      |

> **Warning:** The 5 V pin is only powered when USB-C is connected. Do not rely on
> it for peripherals when running from battery.
