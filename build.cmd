@echo off
cls

:: Get script directory
set SCRIPT_DIR=%~dp0
set SCRIPT_DIR=%SCRIPT_DIR:~0,-1%

:: Build all examples for supported platforms. We can probably do this much more
:: elegantly using a loop.
platformio ci --lib="." --verbose --board=uno --board=micro --board=leonardo --board=megaatmega1280 --board=megaatmega2560 examples/BrightnessAndContrastExample/BrightnessAndContrastExample.ino
platformio ci --lib="." --verbose --board=uno --board=micro --board=leonardo --board=megaatmega1280 --board=megaatmega2560 examples/CrystalFontz632BasicExample/CrystalFontz632BasicExample.ino
platformio ci --lib="." --verbose --board=uno --board=micro --board=leonardo --board=megaatmega1280 --board=megaatmega2560 examples/CrystalFontz632BasicExampleWithInit/CrystalFontz632BasicExampleWithInit.ino
platformio ci --lib="." --verbose --board=uno --board=micro --board=leonardo --board=megaatmega1280 --board=megaatmega2560 examples/GraphExample/GraphExample.ino

exit %ERRORLEVEL%
