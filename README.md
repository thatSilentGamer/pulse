# Custom ESP32-S3 Spotify Controller Macro-Pad

An original hardware macro-pad designed from scratch to provide physical control over Spotify and computer audio. This project features mechanical keyswitches, a rotary encoder for volume tracking, and an integrated display for media status.

---

## Project Overview

### What It Is
This is a compact hardware macro-pad designed as a **Spotify Controller**. It features two **Cherry MX2A Speed Silver switches** for skipping tracks or pausing music, an **EC11 rotary encoder** for volume scrolling, and a **TENSTAR ROBOT 1x9 Pin SPI Display** tilted at an angle to show track info.

### Why I Made It
I engineered this controller to bridge digital media apps with hardware. The goal was to build a dedicated desktop tool that lets me control music instantly without switching windows.

### How It Works
* **Media Switches:** The Cherry MX2A Speed Silvers are soldered directly to a custom PCB, passing through a top case layer for stability.
* **Volume Encoder:** Provides a rotating dial interface to control system volume or track scrolling, and it has an integrated click-switch.
* **Display Output:** The sequential 1x9 pin header channels hardware SPI communication straight from the ESP32-S3 Mini, enabling graphics for media feedback.
* **Power & Control:** Fully powered and controlled via a USB-C connection driven by the ESP32-S3 Mini processor.

---

## Mechanical & CAD Design

The case is a two-part shell that puts the top piece and bottom base together so it fits without needing tape or glue.

* **Material Clearances:** The switch holes are slightly larger than they need to be so that they don't get stuck if the 3D print shrinks or over-extrudes a bit
* **Flush Screen Housing:** The angled part for the screen meets the flat top completely flush so there isn't a weird lip sticking out.
* **Vertical Component Stack:** The case is deep enough so the pins on the bottom of the PCB don't hit the bottom of the shell.
