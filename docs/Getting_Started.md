# Getting Started!

Welcome! This guide will help you get started with the Dimmer firmware. This firmware runs on the ESPF32-C3 DevKit C-02 microcontroller.

## VS Code Setup Procedure

**TLDR**: Watch this link and note these changes below: [ESP-IDF Setup Video](https://www.youtube.com/watch?v=XDDcS7HQNlI)
1. COM Port: Check the one that is available on your computer by checking the device manager.
2. Esspressif Device Target: Set it to esp32-c3. If you don't, it won't flash onto the microcontroller. Also, make sure you are using UART.

Steps:
1. On Windows, install the "ESP-IDF" extension in the extensions tab.
    1. In the Command Palette (Ctrl+Shift+P) search for "Configure ESP-IDF Extension."
    2. Click on the matching result and select express installation option.
    3. Select the latest version and click install.
3. Clone this repo.
4. Open this repo by clicking File>Open Folder.. and navigate to where you cloned the repo.
5. Open an ESP-IDF Terminal through one of the tabs at the bottom of the VS Code Screen (Left of ESP-IDF: Build, Flash and Monitor Tab)
6. Type `idf.py menuconfig` and press enter
7. Navigate to the Serial flasher config section using the K,J,H and L keys and press enter
8. Navigate to the Flash Size tab and press enter and change it to `4 MB` 

### Troubleshooting

1. Check that your MicroUSB cable supports data transfer. Many MicroUSB cables are power-only.
2. Disable your antivirus.
3. Ensure that you are using the correct COM Port. You can verify this by checking your Device Manager under `Ports`
4. Ensure that the Esspressif Device Target is set to `esp32c3`
