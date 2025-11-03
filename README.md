# TI AM57xx Linux Userspace Examples

This repository contains minimal C examples for controlling and reading
board peripherals directly from Linux user space on the TI AM572x EVM.

## Contents

| Example | Description |
|----------|--------------|
| **leds** | Blink user LEDs using `/sys/class/leds` |
| **gpio_keys** | Read button events from `/dev/input/eventX` |
| **gpio_led_interaction** | Toggle LEDs based on key presses |

## How to Build

```bash
cd src/leds && make
cd ../gpio_keys && make
cd ../gpio_led_interaction && make

## How to Run on Target
./led_blink
./read_gpio_keys
./gpios_leds
