# System-Stress-Dashboard
This repository contains screenshots and an overview of the System Stress Dashboard program.

## About the Program
This program calculates a systems stress level using CPU temperature, CPU load, battery level, and RAM load. A C++ backend collects the raw system metrics and calculates a stress score. A Python dashboard displays the stress core using a gauge and live line chart. MATLAB is used for further analysis, through FFT, raw vs. smoothing, and CPU load vs. stress score plots.

## Tech Stack
- **Backend Engine:** C++
- **Live Dashboard:** Python
- **Analysis Plots:** MATLAB

## Roadmap
- Convert dashboard to Plotly for modern UI
- Add auto-start background monitoring
