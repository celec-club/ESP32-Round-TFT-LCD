# Analog Meter Demo

This example demonstrates an animated analog meter (speedometer style) on the GC9A01 round TFT display using the TFT_eWidget library.

![ESP32 to GC9A01 TFT Wiring Diagram](/docs/images/analog_meter.gif)

## Features

- Displays an analog meter with a needle that animates smoothly
- Color zones (green, yellow, orange, red) indicate different value ranges
- Simulates a speed measurement from 0 to 2.0 m/s using a sine wave
- Updates every 35ms for smooth animation

## What It Does

The meter is divided into 4 color zones:
- **Green (0-25%):** 0.0 - 0.5 m/s
- **Yellow (25-50%):** 0.5 - 1.0 m/s
- **Orange (50-75%):** 1.0 - 1.5 m/s
- **Red (75-100%):** 1.5 - 2.0 m/s

The needle oscillates smoothly through these zones using a sine wave pattern, demonstrating the full range of the meter.

## Display Layout

The meter is 239 pixels wide and 126 pixels high, centered vertically on the 240x240 round display.

## Usage

To compile and upload this example:

```bash
# Set this as the main source file in platformio.ini
src_dir = src/analog_meter

# Then build and upload
platformio run --target upload
```

## Key Functions

- `speed.setZones()` - Defines color zones for the meter
- `speed.analogMeter()` - Draws the initial meter with scale and labels
- `speed.updateNeedle()` - Updates the needle position (value between 0 and 2.0)
