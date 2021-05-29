#!/bin/sh

# Get script dir.
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd)"

# Build targets.
export PATH=~/.atom/packages/platformio-ide/penv/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:~/n/bin:$PATH

pio ci --lib="." --verbose --board=uno --board=micro --board=leonardo --board=megaatmega1280 --board=megaatmega2560 examples/BrightnessAndContrastExample/BrightnessAndContrastExample.ino
pio ci --lib="." --verbose --board=uno --board=micro --board=leonardo --board=megaatmega1280 --board=megaatmega2560 examples/CGROMExample/CGROMExample.ino
pio ci --lib="." --verbose --board=uno --board=micro --board=leonardo --board=megaatmega1280 --board=megaatmega2560 examples/CrystalFontz632BasicExample/CrystalFontz632BasicExample.ino
pio ci --lib="." --verbose --board=uno --board=micro --board=leonardo --board=megaatmega1280 --board=megaatmega2560 examples/CrystalFontz632BasicExampleWithInit/CrystalFontz632BasicExampleWithInit.ino
pio ci --lib="." --verbose --board=uno --board=micro --board=leonardo --board=megaatmega1280 --board=megaatmega2560 examples/GraphExample/GraphExample.ino

exit $?
