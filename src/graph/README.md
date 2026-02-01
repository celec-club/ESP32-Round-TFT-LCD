# Graph Widget Demo

This example demonstrates real-time graph plotting on the GC9A01 TFT display using the TFT_eWidget library.

![ESP32 to GC9A01 TFT Wiring Diagram](/docs/images/graph.gif)

## Features

- Creates a 200x150 pixel graph with grid lines
- Plots data in real-time with automatic trace management
- X-axis range: 0 to 100
- Y-axis range: -512 to 512
- Multiple colored traces (red, white, green)
- Automatically resets and starts a new trace when reaching the end

## What It Does

1. Draws a graph with a dark grey background and blue grid lines
2. Plots a horizontal reference line in red at y=0
3. Continuously plots a sawtooth wave pattern in white/green
4. The wave oscillates between -500 and 500 on the y-axis
5. When the plot reaches x=100, it clears and starts a new trace

## Display Layout

The graph is positioned at coordinates (40, 10) on the 240x240 display, optimized for landscape orientation (rotation 3).

## Grid Configuration

- **X-axis:** Grid lines every 20 units (0, 20, 40, 60, 80, 100)
- **Y-axis:** Grid lines every 64 units (-512, -448, -384, ..., 448, 512)

## Usage

To compile and upload this example:

```bash
# Set this as the main source file in platformio.ini
src_dir = src/graph

# Then build and upload
platformio run --target upload
```

## Key Functions

- `gr.createGraph()` - Creates graph with specified dimensions
- `gr.setGraphScale()` - Sets the x and y axis ranges
- `gr.setGraphGrid()` - Configures grid spacing and color
- `gr.drawGraph()` - Draws/refreshes the graph area
- `tr.startTrace()` - Begins a new trace with a specified color
- `tr.addPoint()` - Adds a data point to the current trace
