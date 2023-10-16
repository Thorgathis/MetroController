import pyautogui
import serial.tools.list_ports
from pyautogui import *

# Select arduino COM
print("Please Select arduinoCOM port for (ONLY NUMBER")
ports = list(serial.tools.list_ports.comports())
for p in ports:
    print(p)
com = "COM" + input("COM: ")
print()

# Try to begin serial
try:
    Serial = serial.Serial(port=com, baudrate=115200)
except ():
    print("This is not Arduino")
    exit(1)


time.sleep(2)
while True:
    try:
        incoming = str(Serial.readline())
    except ():
        break
    pyautogui.press(incoming[6:7])
    incoming = ""
