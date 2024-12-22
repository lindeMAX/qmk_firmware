DEFAULT_FOLDER = thumby/split29

SPLIT_KEYBOARD = yes
# Use full duplex USART for split KB connection
SERIAL_DRIVER = usart
# Disables usb suspend check after keyboard startup. Usually the keyboard waits for the host to wake it up before any tasks are performed. This is useful for split keyboards as one half will not get a wakeup call but must send commands to the master.
NO_USB_STARTUP_CHECK = yes

OLED_DRIVER = ssd1306
OLED_TRANSPORT = i2c

CONSOLE_ENABLE = yes
