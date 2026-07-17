# Custom ESP32-S3 Spotify Controller Macro-Pad

A hardware macro-pad designed from scratch to provide physical control over Spotify and computer audio. This project features mechanical keyswitches, a rotary encoder for volume tracking, and an integrated display for media status.

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

## Project Gallery

<img width="1337" height="907" alt="Screenshot 2026-06-25 223707" src="https://github.com/user-attachments/assets/ee41c84d-de81-4c3b-bfb0-19ae9472c569" />

<img width="2072" height="1057" alt="Screenshot 2026-07-09 151816" src="https://github.com/user-attachments/assets/e6da686d-15a7-4376-bcf5-c311a795d767" />

<img width="1410" height="2000" alt="pulse_zine_page" src="https://github.com/user-attachments/assets/d301f5fb-bad1-42ee-87c2-a704628e2532" />

<img width="1670" height="1072" alt="image" src="https://github.com/user-attachments/assets/6fe44595-0165-44b9-a5de-25a982202b8e" />


---

## Mechanical & CAD Design

**[Click here to view the Onshape 3D CAD Assembly & Source Files](https://cad.onshape.com/documents/9e875fa0eb3d29beb0a7e423/w/634ce2adc409bcbb121e172c/e/cf97eb71c9d871e1e5143c14)**

The case is a two-part shell (top piece and bottom base) that is secured together using **M2/M3 mechanical screws through internal mounting standoffs** that align with the PCB's mounting holes (H1–H4). This ensures a rigid, durable enclosure that holds the electronics firmly in place without relying on friction, tape, or glue.

* **Material Clearances:** The switch holes are slightly larger than they need to be so that they don't get stuck if the 3D print shrinks or over-extrudes a bit.
* **Flush Screen Housing:** The angled part for the screen meets the flat top completely flush so there isn't a weird lip sticking out.
* **Vertical Component Stack:** The case is deep enough so the pins on the bottom of the PCB don't hit the bottom of the shell.

---

## Build Guide & Instructions

### 1. Bill of Materials (BOM)
All components required to build Pulse (including the ESP32-S3 Mini, Cherry MX2A switches, EC11 rotary encoder, TENSTAR SPI Display, and custom PCB) can be found in the `BOM.csv` file.

### 2. PCB & Wiring Layout
* The project utilizes a custom printed circuit board designed in KiCad (source files located in `/Electronics`). 
* **Switches:** Solder the Cherry MX2A Speed Silver switches into the footprint designated on the top side of the board.
* **Encoder:** Mount and solder the EC11 rotary encoder into position `SW1`.
* **Display:** Connect the 1x9 Pin SPI Display header directly to `J1`, which routes hardware SPI pins from the ESP32-S3 WROOM module.
* **Mounting:** Use M2/M3 mechanical screws through standoffs `H1`–`H4` to secure the soldered PCB firmly inside the 3D-printed bottom shell.

### 3. Firmware & Flashing Instructions
1. Download and install the Arduino IDE along with the ESP32 board definitions and required libraries (`TFT_eSPI`, `BleKeyboard`, `ESP32Encoder`, and `FastLED`).
2. Open `/Firmware/pulse.ino` in your IDE.
3. Connect the ESP32-S3 to your computer via USB-C.
4. Select **ESP32S3 Dev Module** as your target board and select the correct COM port.
5. Click **Upload** to compile and flash the firmware onto the microcontroller.

### 4. Usage Guide
Once flashed and powered via USB-C, Pulse will boot up and display *"Pulse is online."* on the screen while lighting up the green underglow.
* **Pairing:** Open your computer or phone's Bluetooth settings and pair with the device named **"Pulse Controller"**.
* **Volume Control:** Turn the rotary encoder knob clockwise to increase system volume, and counter-clockwise to decrease volume.
* **Play/Pause:** Press down on the rotary encoder knob (integrated click switch) to toggle media play/pause.
* **Track Navigation:** Press the left Cherry MX switch (`BTN_SKIP_BCK`) to jump to the previous track, or the right switch (`BTN_SKIP_FWD`) to skip to the next track on Spotify!
