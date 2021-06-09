#!/bin/bash
set -x

####
#
# WARNING - make sure ModeManager is not running:
#     systemctl stop ModemManager
#
###

BASE_DIR=/home/user/src/keyboard
BUILD_DIR=${BASE_DIR}/qmk_firmware/.build
#FILE=$BASE_DIR/Blink.cpp.hex
#FILE=${BUILD_DIR}/planck_rev6_default.hex
FILE=${BASE_DIR}/qmk_firmware/util/bootloader_atmega32u4_1.0.0.hex
#FILE=${BASE_DIR}/qmk_firmware/util/pro_micro_ISP_B6_10.hex
#FILE=${BUILD_DIR}/40percentclub_nori_default.hex

#PRGR=avr109
PRGR=usbasp

if [ "${PRGR}" = "avr109" ] ; then
  #DEV=/dev/ttyACM0
  DEV=$(ls /dev/ttyACM?)
  BAUD=57600
else
  DEV=/dev/ttyS0
  BAUD=19200
fi

AVRDUDE=/usr/share/arduino/hardware/tools/avrdude 
AVRDUDE_CONF=/usr/share/arduino/hardware/tools/avrdude.conf 
#AVRDUDE=avrdude
#AVRDUDE_CONF=/etc/avrdude.conf
PART=atmega32u4

ARGS="-n -p${PART} -C${AVRDUDE_CONF} -c${PRGR}  -P${DEV} -b${BAUD} -D -V"

if [[ ! -e "${DEV}" ]] ; then
  echo "DEV=$DEV does not exist"
  exit 1
fi

if [[ ! -e "${FILE}" ]] ; then
  echo "FILE=$FILE does not exist"
  exit 1
fi

stty -F "${DEV}" 1200

while true; do
  sleep 1
  [ -c "${DEV}" ] && break
done


#${AVRDUDE} ${ARGS} 

#${AVRDUDE} ${ARGS} -Uflash:w:${FILE}:i


# Caterina
#${AVRDUDE} ${ARGS} -U lfuse:w:0xFF:m -U hfuse:w:0xD8:m -U efuse:w:0xCB:m

#DFU no-JTAG 
#${AVRDUDE} ${ARGS} -U lfuse:w:0x5E:m -U hfuse:w:0xD9:m -U efuse:w:0xC3:m

#DFU JTAG
#${AVRDUDE} ${ARGS} -U lfuse:w:0x5E:m -U hfuse:w:0x99:m -U efuse:w:0xC3:m

${AVRDUDE} ${ARGS} 
