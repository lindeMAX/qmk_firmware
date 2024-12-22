/* Debugging */

#define OS_DETECTION_DEBUG_ENABLE

/********/
/* MISC */
/********/

// Timeouts used for OLED and LEDs (ms)
#define TIMEOUT_DIM 10000
#define TIMEOUT_OFF 100000

/********************/
/* Hardware Options */
/********************/

#define DEBOUNCE 5

#define USB_POLLING_INTERVAL_MS 10
#define USB_SUSPEND_WAKEUP_DELAY 0
#define USB_MAX_POWER_CONSUMPTION 500
#define USB_SUSPEND_WAKEUP_DELAY 0

#define F_SCL 400000L

/*********/
/* Split */
/*********/

// The device which has USB connected and active USB commmunication will be the master.
// Uncomment to check for for supply voltage on physical USB connection (VBUS)
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000
#define SPLIT_USB_TIMEOUT_POLL 10
// Reboot slave if no communication from master within timeout.
#define SPLIT_WATCHDOG_TIMEOUT 3000
#define SPLIT_WATCHDOG_ENABLE
// Left hand if if B7 is HIGH
#define SPLIT_HAND_PIN A0
// Sync OLED state with the slave side
#define SPLIT_OLED_ENABLE
// Sync activity timestamps with the slave
#define SPLIT_ACTIVITY_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
// Enable sync of RGB backlight
/*#define RGBLIGHT_SPLIT*/
// First number is the amount of LEDs connected to the left side
// The next version will not have to use jumpers :)
/*#define MATRIX_ROW_PINS_RIGHT { "B12", "B14", "A8", "A15", "A12", "A11" }*/
/*#define MATRIX_COL_PINS_RIGHT { "B13", "B15", "A9", "A10", "B3" }*/

/***************/
/* USART & I2C */
/***************/

#define SERIAL_DEBUG

#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_DRIVER SD1
#define SERIAL_USART_TX_PIN B6     // USART TX pin
#define SERIAL_USART_RX_PIN B7     // USART RX pin

#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN B8
#define I2C1_SDA_PIN B9

/********/
/* OLED */
/********/

#define OLED_DISPLAY_WIDTH 128
#define OLED_DISPLAY_HEIGHT 32
// The local buffer size to allocate.
#define OLED_MATRIX_SIZE (OLED_DISPLAY_HEIGHT / 8 * OLED_DISPLAY_WIDTH)
//
#define OLED_BRIGHTNESS 127
// Set the time interval for updating the OLED display in ms. This will improve the matrix scan rate.
#define OLED_UPDATE_INTERVAL 50
// Number of dirty block to render per loop. Increasing may degrade performance
#define OLED_UPDATE_PROCESS_LIMIT 1
// Shift output to the right this many pixels.
// Useful for 128x64 displays centered on a 132x64 SH1106 IC.
#define OLED_COLUMN_OFFSET 0
// Set the display clock divide ratio/oscillator frequency.
#define OLED_DISPLAY_CLOCK 0x80
// The font code file to use for custom fonts
#define OLED_FONT_H "font5x7.c"
// The starting character index for custom fonts
#define OLED_FONT_START 32
// The ending character index for custom fonts
#define OLED_FONT_END 127
// The font width
#define OLED_FONT_WIDTH 5
// The font height (untested)
#define OLED_FONT_HEIGHT 7
// Set to OLED_IC_SH1106 or OLED_IC_SH1107 if the corresponding controller chip is used.
#define OLED_IC OLED_IC_SSD1306
// Enables fade out animation. Use together with OLED_TIMEOUT.
#define OLED_FADE_OUT
// The speed of fade out animation, from 0 to 15. Larger values are slower.
#define OLED_FADE_OUT_INTERVAL 0
// Scrolls the OLED screen after 0ms of OLED inactivity. Helps reduce OLED Burn-in. Set to 0 to disable.
#define OLED_SCROLL_TIMEOUT TIMEOUT_DIM
// Scroll timeout direction is right when defined, left when undefined.
#define OLED_SCROLL_TIMEOUT_RIGHT
// Turn off if after a certain time of inactivity
#define OLED_TIMEOUT TIMEOUT_OFF

/*******/
/* RGB */
/*******/


#define RGB_MATRIX_LED_COUNT 58

#define IS31FL3743A_I2C_ADDRESS_1 IS31FL3743A_I2C_ADDRESS_GND_GND
