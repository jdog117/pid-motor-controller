<h1 align="center">PID Motor Controller</h1>

<!-- ![Banner](docs/img/pidsideview.png) -->
<p align="center">
<img src="docs/img/pidsideview.png" alt="Banner" height="400px">
</p>
<p align="center"><strong>
Custom motor control board for reaction based flywheel controlled by PID loop function.</br>
Useful in balance sensitive applications.
</p></strong>

# Overview
This small PCB runs a driver with PID loop controller function. The board interfaces with a brushless motor controller for balance control.

# Hardware
PCB uses the STM32's internal oscilator 2 layer board design to keep manufactoing costs low
- STM32 Microcontroller (STM32C011F6U6TR)
- Accelerometer (MC63630)
- JTAG for serial wire debug (TC2030-IDC)
- Designed in Altium


# Project Requirements
- FOC motor controller
- Brushless motor
- Flywheel

### Schematic
![](docs/img/SCH_PIC.png)

# Improvements
- Status LED
- Design board with score along JTAG connector for snapping off when finished programing
- USB
