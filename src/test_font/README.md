# Color Test and Display Inversion Demo

This diagnostic example demonstrates text rendering in different colors and the display color inversion feature on the GC9A01 round TFT display.

![ESP32 to GC9A01 TFT Wiring Diagram](/docs/images/color_test.gif)

## Features

- Displays text in multiple colors (white, red, green, blue)
- Demonstrates color inversion functionality
- Tests correct color order configuration
- Draws a green circle border around the display

## What It Does

The demo cycles through two display modes:

### Mode 1: Normal Display (Invert OFF)
- Black background
- White, red, green, and blue text
- Green circle border

### Mode 2: Inverted Display (Invert ON)
- Inverted colors (black ↔ white swapped)
- All colors are inverted (red ↔ cyan, green ↔ magenta, blue ↔ yellow)
- Green circle becomes magenta

Each mode displays for 5 seconds before switching.

## Purpose

This example is useful for:
- Verifying correct RGB color order on your display
- Testing the color inversion feature
- Diagnosing color-related display issues
- Understanding MADCTL register configuration

## Display Configuration Notes

The code includes detailed comments about:
- MADCTL control register bits (rotation, mirroring, RGB order)
- Color inversion functionality
- Common display driver configurations

## Usage

To compile and upload this example:

```bash
# Set this as the main source file in platformio.ini
src_dir = src/test_font

# Then build and upload
platformio run --target upload
```

## Troubleshooting

If colors appear incorrect (e.g., red and blue swapped), you may need to adjust the RGB order bit in the MADCTL register. This can typically be done through the TFT_eSPI library configuration.

## Key Functions

- `tft.fillScreen()` - Fills the entire screen with a color
- `tft.drawCircle()` - Draws a circle border
- `tft.setCursor()` - Positions text cursor
- `tft.setTextColor()` - Sets text color
- `tft.println()` - Prints text to display
- `tft.invertDisplay()` - Toggles color inversion on/off
