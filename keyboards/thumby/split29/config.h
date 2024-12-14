/* MISC */

// Timeouts used for OLED and LEDs (ms)
#define TIMEOUT_DIM 300000
#define TIMEOUT_OFF 600000

/* Split */

// The device which has USB connected and active USB commmunication will be the master.
// Uncomment to check for for supply voltage on physical USB connection (VBUS)
#define SPLIT_USB_DETECT
// Left hand if if B7 is HIGH
#define SPLIT_HAND_PIN B7
// Sync OLED state with the slave side
#define SPLIT_OLED_ENABLE
// Sync activity timestamps with the slave
#define SPLIT_ACTIVITY_ENABLE
// Enable sync of RGB backlight
#define RGBLIGHT_SPLIT
// First number is the amount of LEDs connected to the left side
#define RGBLED_SPLIT { 29, 29 }
// The next version will not have to use jumpers :)
#define MATRIX_ROW_PINS_RIGHT { "B12", "B14", "A8", "A15", "A12", "A11" }
#define MATRIX_COL_PINS_RIGHT { "B13", "B15", "A9", "A10", "B3" }

/* USART & I2C */

#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN B6     // USART TX pin
#define SERIAL_USART_RX_PIN B7     // USART RX pin
#define SERIAL_USART_DRIVER SD1

#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN B8
#define I2C1_SDA_PIN B9

/* OLED */

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
/*#define OLED_FONT_H "gldcfont.c"*/
// The starting character index for custom fonts
/*#define OLED_FONT_START 0*/
// The ending character index for custom fonts
/*#define OLED_FONT_END 223*/
// The font width
/*#define OLED_FONT_WIDTH 6*/
// The font height (untested)
/*#define OLED_FONT_HEIGHT 8*/
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

/* RGB */

/*#define LED_RGB_MATRIX*/

// Full gradient & value pulse away from a single key hit then fades value out
#define ENABLE_RGB_MATRIX_SPASH
// reactive effects respond to keyreleases (instead of keypresses)
/*#define RGB_MATRIX_KEYRELEASES */
// Triggers RGB keypress events on key down. This makes RGB control feel more responsive. This may cause RGB to not function properly on some boards
#define RGB_TRIGGER_ON_KEYDOWN
// number of milliseconds to wait until rgb automatically turns off
#define RGB_MATRIX_TIMEOUT 0
// turn off effects when suspended
#define RGB_MATRIX_SLEEP
// limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5
// limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 0xc8
// Sets the default enabled state, if none has been set
#define RGB_MATRIX_DEFAULT_ON true
// Sets the default mode, if none has been set
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT
// Sets the default hue value, if none has been set
#define RGB_MATRIX_DEFAULT_HUE 0
// Sets the default saturation value, if none has been set
#define RGB_MATRIX_DEFAULT_SAT 255
// Sets the default brightness value, if none has been set
#define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
// Sets the default animation speed, if none has been set
#define RGB_MATRIX_DEFAULT_SPD 127
// Sets the default LED flags, if none has been set
#define RGB_MATRIX_DEFAULT_FLAGS LED_FLAG_ALL
// (Optional) For split keyboards, the number of LEDs connected on each half. X = left, Y = Right.
/*#define RGB_MATRIX_SPLIT { X, Y }*/
// If reactive effects are enabled, you also will want to enable SPLIT_TRANSPORT_MIRROR
