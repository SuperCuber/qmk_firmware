#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_us_international.h"

enum custom_keycodes {
  MOUSE_LAYER = EZ_SAFE_RANGE,
  REPEAT_MACRO,
  HOLD_BUTTONS,
};

enum tap_dance_codes {
  ALT_F4,
  NUM_DANCES,
};

#define MUTE     KC_AUDIO_MUTE
#define VOL_UP   KC_AUDIO_VOL_UP
#define VOL_DOWN KC_AUDIO_VOL_DOWN
#define PLAY     KC_MEDIA_PLAY_PAUSE
#define PREV     KC_MEDIA_PREV_TRACK
#define REWIND   KC_MEDIA_REWIND
#define FAST_FO  KC_MEDIA_FAST_FORWARD
#define NEXT     KC_MEDIA_NEXT_TRACK

enum layers {
  BASE = 0,
  GAMING,
  GAMING_S,
  SYMBOLS,
  EDITING,
  NUM,
  FUNCTION,
  MOUSE,
  SPECIAL,
  NUM_LAYERS
};

const uint16_t PROGMEM keymaps[NUM_LAYERS][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox_pretty(
    XXXXXXX,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           XXXXXXX,                                        XXXXXXX,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           XXXXXXX,
    XXXXXXX,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           LCTL(LALT(KC_DELETE)),                          HOLD_BUTTONS,   KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           XXXXXXX,
    XXXXXXX,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      XXXXXXX,
    XXXXXXX,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           TD(ALT_F4),                                     REPEAT_MACRO,   KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       XXXXXXX,
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        LT(NUM, KC_TAB),                                                                                                MO(SYMBOLS),    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                                                    TO(GAMING),     KC_PSCREEN,      XXXXXXX,       LSFT(KC_LALT),
                                                                                                                    XXXXXXX,         XXXXXXX,
                                                                                    KC_SPACE, LCTL_T(KC_ESCAPE),    DYN_MACRO_PLAY1, XXXXXXX,       LT(EDITING, KC_BSPACE), LSFT_T(KC_ENTER)
  ), [GAMING] = LAYOUT_ergodox_pretty(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           _______,                                        _______,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           XXXXXXX,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           _______,                                        _______,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    KC_ESCAPE,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_ENTER,
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           _______,                                        _______,        KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_UP,          KC_SLASH,
    KC_LCTRL,       XXXXXXX,        KC_LGUI,        KC_LALT,        KC_LCTRL,                                                                                                       MO(SYMBOLS),    XXXXXXX,        KC_LEFT,        KC_DOWN,        KC_RIGHT,
                                                                                                    TO(BASE),       _______,        _______,        _______,
                                                                                                                    _______,        _______,
                                                                                    KC_SPACE,       KC_LCTRL,       TG(GAMING_S),   _______,        _______,        _______
  ), [GAMING_S] = LAYOUT_ergodox_pretty(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        KC_T,           KC_Q,           KC_W,           KC_E,           KC_R,           _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        KC_G,           KC_A,           KC_S,           KC_D,           KC_F,                                                                           _______,        _______,        _______,        _______,        _______,        _______,
    _______,        KC_B,           KC_Z,           KC_X,           KC_C,           KC_V,           _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,                                                                                                        _______,        _______,        _______,        _______,        _______,
                                                                                                    _______,       _______,        _______,         _______,
                                                                                                                   _______,        _______,
                                                                                    _______,        _______,       _______,        _______,         _______,        _______
  ), [SYMBOLS] = LAYOUT_ergodox_pretty(
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
    XXXXXXX,        LSFT(KC_1),     LSFT(KC_2),     LSFT(KC_3),     LSFT(KC_4),     LSFT(KC_5),     XXXXXXX,                                        XXXXXXX,        LSFT(KC_6),     LSFT(KC_7),     LSFT(KC_8),     KC_BSLASH,      KC_SCOLON,      XXXXXXX,
    XXXXXXX,        KC_TILDE,       KC_LCBR,        KC_ENTER,       KC_RCBR,        KC_MINUS,                                                                       KC_EQUAL,       LSFT(KC_9),     KC_UNDS,        LSFT(KC_0),     KC_COLON,       XXXXXXX,
    XXXXXXX,        KC_PIPE,        KC_LABK,        KC_QUOTE,       KC_RABK,        KC_GRAVE,       XXXXXXX,                                        XXXXXXX,        KC_PLUS,        KC_LBRACKET,    LSFT(KC_QUOTE), KC_RBRACKET,    KC_QUESTION,    XXXXXXX,
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        MO(SPECIAL),                                                                                                    _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                                                    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                                                                    XXXXXXX,        XXXXXXX,
                                                                                    _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX
  ), [EDITING] = LAYOUT_ergodox_pretty(
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
    XXXXXXX,        KC_DELETE,      KC_HOME,        KC_UP,          KC_END,         XXXXXXX,        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
    XXXXXXX,        KC_BSPACE,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       XXXXXXX,                                                                        XXXXXXX,        KC_RCTRL,       KC_RSHIFT,      KC_LALT,        KC_RGUI,        XXXXXXX,
    XXXXXXX,        LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     XXXXXXX,        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                                                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                                                    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                                                                    XXXXXXX,        XXXXXXX,
                                                                                    KC_SPACE,       XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX
  ), [NUM] = LAYOUT_ergodox_pretty(
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
    XXXXXXX,        XXXXXXX,        KC_TAB,         XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                        XXXXXXX,        KC_DOT,         KC_7,           KC_8,           KC_9,           KC_COMMA,       XXXXXXX,
    XXXXXXX,        KC_LGUI,        KC_LALT,        KC_LSHIFT,      KC_LCTRL,       XXXXXXX,                                                                        KC_EQUAL,       KC_4,           KC_5,           KC_6,           KC_0,           XXXXXXX,
    XXXXXXX,        MO(FUNCTION),   KC_CAPSLOCK,    XXXXXXX,        KC_TAB,         XXXXXXX,        XXXXXXX,                                        XXXXXXX,        KC_PLUS,        KC_1,           KC_2,           KC_3,           KC_MINUS,       XXXXXXX,
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        _______,                                                                                                        MO(SPECIAL),    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                                                    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                                                                    XXXXXXX,        XXXXXXX,
                                                                                    XXXXXXX,        TO(MOUSE),      XXXXXXX,        XXXXXXX,        KC_BSPACE,      KC_ENTER
  ), [FUNCTION] = LAYOUT_ergodox_pretty(
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                        XXXXXXX,        KC_F12,         KC_F7,          KC_F8,          KC_F9,          XXXXXXX,        XXXXXXX,
    XXXXXXX,        KC_LGUI,        KC_LALT,        KC_LSHIFT,      KC_LCTRL,       XXXXXXX,                                                                        KC_F11,         KC_F4,          KC_F5,          KC_F6,          XXXXXXX,        XXXXXXX,
    XXXXXXX,        _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                        XXXXXXX,        KC_F10,         KC_F1,          KC_F2,          KC_F3,          XXXXXXX,        XXXXXXX,
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                                                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                                                    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                                                                    XXXXXXX,        XXXXXXX,
                                                                                    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX
  ), [MOUSE] = LAYOUT_ergodox_pretty(
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
    XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_MS_UP,       KC_MS_BTN2,     KC_MS_WH_UP,    XXXXXXX,                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
    XXXXXXX,        KC_MS_BTN1,     KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_DOWN,                                                                  XXXXXXX,        KC_RCTRL,       KC_RSHIFT,      KC_LALT,        KC_RGUI,        XXXXXXX,
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_MS_BTN3,     XXXXXXX,                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        TO(BASE),                                                                                                       XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                                                    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                                                                    XXXXXXX,        XXXXXXX,
                                                                                    KC_MS_ACCEL0,   TO(BASE),       XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX
  ), [SPECIAL] = LAYOUT_ergodox_pretty(
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
    XXXXXXX,        RESET,          DYN_REC_START1, DYN_REC_STOP,   DYN_MACRO_PLAY1,XXXXXXX,        XXXXXXX,                                        XXXXXXX,        MUTE,           KC_INSERT,      KC_SCROLLLOCK,  KC_PAUSE,       PLAY,           XXXXXXX,
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                                        VOL_UP,         KC_PGDOWN,      KC_PGUP,        XXXXXXX,        XXXXXXX,        XXXXXXX,
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                        XXXXXXX,        VOL_DOWN,       PREV,           REWIND,         FAST_FO,        NEXT,           XXXXXXX,
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        _______,                                                                                                        _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                                                    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                                                                    XXXXXXX,        XXXXXXX,
                                                                                    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX
  // ), [NEW_LAYER] = LAYOUT_ergodox_pretty(
  //   XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
  //   XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
  //   XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
  //   XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
  //   XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                                                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
  //                                                                                                   XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
  //                                                                                                                   XXXXXXX,        XXXXXXX,
  //                                                                                   XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX
  ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

#define LED_COLOR_PRETTY(                                \
    C29, C28, C27, C26, C25,   C1,  C2,  C3,  C4,  C5,   \
    C34, C33, C32, C31, C30,   C6,  C7,  C8,  C9,  C10,  \
    C39, C38, C37, C36, C35,   C11, C12, C13, C14, C15,  \
    C44, C43, C42, C41, C40,   C16, C17, C18, C19, C20,  \
    C48, C47, C46, C45,             C21, C22, C23, C24 ) \
{C1, C2, C3, C4, C5, C6, C7, C8, C9, C10, C11, C12, C13, C14, C15, C16, C17, C18, C19, C20, C21, C22, C23, C24, C25, C26, C27, C28, C29, C30, C31, C32, C33, C34, C35, C36, C37, C38, C39, C40, C41, C42, C43, C44, C45, C46, C47, C48}

#define RED    {255, 0,   0}
#define GREEN  {0,   255, 0}
#define BLUE   {0,   0,   255}
#define CYAN   {0,   255, 255}
#define YELLOW {255, 255, 0}
#define PURPLE {255, 0,   255}
#define BLACK  {0,   0,   0}
#define WHITE  {255, 255, 255}

const uint8_t PROGMEM ledmap[NUM_LAYERS][DRIVER_LED_TOTAL][3] = {
    [BASE] = LED_COLOR_PRETTY(
        BLUE,   BLUE,   BLUE,   BLUE,   BLUE,        BLUE,   BLUE,   BLUE,   BLUE,   BLUE,
        BLUE,   BLUE,   BLUE,   BLUE,   BLUE,        BLUE,   BLUE,   BLUE,   BLUE,   BLUE,
        BLUE,   BLUE,   BLUE,   BLUE,   BLUE,        BLUE,   BLUE,   BLUE,   BLUE,   BLUE,
        BLUE,   BLUE,   BLUE,   BLUE,   BLUE,        BLUE,   BLUE,   BLUE,   BLUE,   BLUE,
        BLACK,  BLACK,  BLACK,  RED,                         RED,    BLACK,  BLACK,  BLACK
    ), [GAMING] = LED_COLOR_PRETTY(
        RED,    RED,    RED,    RED,    RED,         RED,    RED,    RED,    RED,    RED,
        RED,    GREEN,  RED,    RED,    RED,         RED,    RED,    RED,    RED,    RED,
        GREEN,  GREEN,  GREEN,  RED,    RED,         RED,    RED,    RED,    RED,    RED,
        RED,    RED,    RED,    RED,    RED,         RED,    RED,    RED,    RED,    GREEN,
        BLACK,  GREEN,  GREEN,  GREEN,                       BLUE,   BLACK,  GREEN,  GREEN
    ), [GAMING_S] = LED_COLOR_PRETTY(
        RED,    RED,    RED,    RED,    RED,         RED,    RED,    RED,    RED,    RED,
        RED,    RED,    GREEN,  RED,    RED,         RED,    RED,    RED,    RED,    RED,
        RED,    GREEN,  GREEN,  GREEN,  RED,         RED,    RED,    RED,    RED,    RED,
        RED,    RED,    RED,    RED,    RED,         RED,    RED,    RED,    RED,    GREEN,
        BLACK,  GREEN,  GREEN,  GREEN,                       BLUE,   BLACK,  GREEN,  GREEN
    ), [SYMBOLS] = LED_COLOR_PRETTY(
        BLACK,  BLACK,  BLACK,  BLACK,  BLACK,       BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
        CYAN,   CYAN,   CYAN,   CYAN,   CYAN,        CYAN,   CYAN,   CYAN,   GREEN,  GREEN,
        GREEN,  PURPLE, WHITE,  PURPLE, GREEN,       GREEN,  PURPLE, WHITE,  PURPLE, GREEN,
        GREEN,  PURPLE, RED,    PURPLE, GREEN,       GREEN,  PURPLE, RED,    PURPLE, GREEN,
        BLACK,  BLACK,  BLACK,  RED,                         WHITE,  WHITE,  BLACK,  BLACK
    ), [EDITING] = LED_COLOR_PRETTY(
        BLACK,  BLACK,  BLACK,  BLACK,  BLACK,       BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
        RED,    CYAN,   BLUE,   CYAN,   BLACK,       BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
        RED,    BLUE,   BLUE,   BLUE,   BLACK,       BLACK,  GREEN,  GREEN,  GREEN,  GREEN,
        PURPLE, PURPLE, PURPLE, PURPLE, BLACK,       BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
        BLACK,  BLACK,  BLACK,  BLACK,                       BLACK,  BLACK,  BLACK,  BLACK
    ), [NUM] = LED_COLOR_PRETTY(
        BLACK,  BLACK,  BLACK,  BLACK,  BLACK,       BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
        BLACK,  BLUE,   BLACK,  BLACK,  BLACK,       GREEN,  BLUE,   BLUE,   BLUE,   GREEN,
        GREEN,  GREEN,  GREEN,  GREEN,  BLACK,       YELLOW, BLUE,   BLUE,   BLUE,   BLUE,
        RED,    CYAN,   BLACK,  BLUE,   BLACK,       YELLOW, BLUE,   BLUE,   BLUE,   YELLOW,
        BLACK,  BLACK,  BLACK,  WHITE,                       RED,    BLACK,  BLACK,  BLACK
    ), [FUNCTION] = LED_COLOR_PRETTY(
        BLACK,  BLACK,  BLACK,  BLACK,  BLACK,       BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
        BLACK,  BLACK,  BLACK,  BLACK,  BLACK,       PURPLE, PURPLE, PURPLE, PURPLE, BLACK,
        GREEN,  GREEN,  GREEN,  GREEN,  BLACK,       PURPLE, PURPLE, PURPLE, PURPLE, BLACK,
        WHITE,  BLACK,  BLACK,  BLACK,  BLACK,       PURPLE, PURPLE, PURPLE, PURPLE, BLACK,
        BLACK,  BLACK,  BLACK,  WHITE,                       BLACK,  BLACK,  BLACK,  BLACK
    ), [MOUSE] = LED_COLOR_PRETTY(
        BLACK,  BLACK,  BLACK,  BLACK,  BLACK,       BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
        BLACK,  BLACK,  RED,    GREEN,  BLUE,        BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
        GREEN,  RED,    RED,    RED,    BLUE,        BLACK,  GREEN,  GREEN,  GREEN,  GREEN,
        BLACK,  BLACK,  BLACK,  BLACK,  CYAN,        BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
        BLACK,  BLACK,  BLACK,  RED,                         BLACK,  BLACK,  BLACK,  BLACK
    ), [SPECIAL] = LED_COLOR_PRETTY(
        BLACK,  BLACK,  BLACK,  BLACK,  BLACK,       BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
        RED,    PURPLE, PURPLE, PURPLE, BLACK,       CYAN,   GREEN,  GREEN,  GREEN,  YELLOW,
        BLACK,  PURPLE, PURPLE, PURPLE, BLACK,       BLUE,   GREEN,  GREEN,  BLACK,  BLACK,
        BLACK,  BLACK,  BLACK,  BLACK,  BLACK,       BLUE,   YELLOW, YELLOW, YELLOW, YELLOW,
        BLACK,  BLACK,  BLACK,  WHITE,                       WHITE,  BLACK,  BLACK,  BLACK
    // ), [NEW_LAYER] = LED_COLOR_PRETTY(
    //     BLACK,  BLACK,  BLACK,  BLACK,  BLACK,       BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
    //     BLACK,  BLACK,  BLACK,  BLACK,  BLACK,       BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
    //     BLACK,  BLACK,  BLACK,  BLACK,  BLACK,       BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
    //     BLACK,  BLACK,  BLACK,  BLACK,  BLACK,       BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
    //     BLACK,  BLACK,  BLACK,  BLACK,                       BLACK,  BLACK,  BLACK,  BLACK
    ),

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    RGB rgb = {
      .r = pgm_read_byte(&ledmap[layer][i][0]),
      .g = pgm_read_byte(&ledmap[layer][i][1]),
      .b = pgm_read_byte(&ledmap[layer][i][2]),
    };
    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
  }
}

uint16_t presses[DRIVER_LED_TOTAL];
void set_heatmap_color(void) {
  uint16_t max_press = 0;
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    if (presses[i] > max_press) {
      max_press = presses[i];
    }
  }
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    const uint8_t v = (uint8_t) ((((double) presses[i]) / (double)max_press) * 255);
    rgb_matrix_set_color(i, v, 0, 255-v);
  }
}

uint8_t led_index_of(keypos_t pos) {
  return g_led_config.matrix_co[pos.row][pos.col];
}

void rgb_matrix_indicators_user(void) {
  if (rgb_matrix_get_suspend_state() || keyboard_config.disable_layer_led) { return; }
  int layer_num = biton32(layer_state);
  /* if(layer_num == BASE) { */
  /*   set_heatmap_color(); */
  /* } else */
  if(layer_num < NUM_LAYERS) {
    set_layer_color(layer_num);
  } else if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
    rgb_matrix_set_color_all(0, 0, 0);
  }
}

uint16_t mouse_layer_time_pressed;
bool mouse_layer_on_when_pressed;
bool mouse_layer_another_key_pressed;

uint16_t last_macro_repeat;
bool macro_repeat_on = false;

bool holding_buttons = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (holding_buttons && !record->event.pressed && keycode != HOLD_BUTTONS) {
    return false;
  } else if (record->event.pressed) {
    mouse_layer_another_key_pressed = true;
    /* const int8_t idx = led_index_of(record->event.key); */
    /* if(idx != NO_LED) { */
    /*   presses[idx]++; */
    /*   // Fix overflow */
    /*   if (presses[idx] == 0) { */
    /*     presses[idx] = -1; */
    /*   } */
    /* } */
  }

  switch (keycode) {
    case MOUSE_LAYER:
      if (record->event.pressed) {
        mouse_layer_on_when_pressed = IS_LAYER_ON(MOUSE);
        mouse_layer_time_pressed = record->event.time;
        mouse_layer_another_key_pressed = false;
        layer_on(MOUSE);
      } else {
        if (mouse_layer_on_when_pressed || mouse_layer_another_key_pressed || TIMER_DIFF_16(record->event.time, mouse_layer_time_pressed) > 200) {
          layer_off(MOUSE);
        }
      }
      return false;
    case KC_LSHIFT:
      if(host_keyboard_led_state().caps_lock) {
        if (record->event.pressed) {
          register_code16(KC_UNDS);
        } else {
          unregister_code16(KC_UNDS);
        }
        return false;
      } else {
        return true;
      }
    case REPEAT_MACRO:
      if (!record->event.pressed) {
        last_macro_repeat = timer_read();
        macro_repeat_on = !macro_repeat_on;
        // Force update leds
        layer_state_set_user(layer_state);
      }
      return false;
    case HOLD_BUTTONS:
      if (record->event.pressed) {
        if (holding_buttons) {
          clear_keyboard();
          holding_buttons = false;
        } else {
          holding_buttons = true;
        }
        layer_state_set_user(layer_state);
      }
      return false;
    default:
      return true;
  }
}

void dyn_macro_play1(void) {
  keyevent_t event = {
    .key = (keypos_t){.row=1, .col=1},
    .pressed = false,
    .time = timer_read() | 1,
  };
  keyrecord_t record = {
    .event = event
  };

  process_dynamic_macro(DYN_MACRO_PLAY1, &record);
}

void matrix_scan_user(void) {
  if(macro_repeat_on && timer_elapsed(last_macro_repeat) > 100) {
    last_macro_repeat = timer_read();
    dyn_macro_play1();
  }
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  if (macro_repeat_on) {
    ergodox_right_led_1_on();
  }
  if (holding_buttons) {
    ergodox_right_led_2_on();
  }
  if (host_keyboard_led_state().caps_lock) {
    ergodox_right_led_3_on();
  }
}

// // Ergodox dance code
// typedef struct {
//     bool is_press_action;
//     uint8_t step;
// } tap;
// enum {
//     SINGLE_TAP = 1,
//     SINGLE_HOLD,
//     DOUBLE_TAP,
//     DOUBLE_HOLD,
//     DOUBLE_SINGLE_TAP,
//     MORE_TAPS
// };
// static tap dance_state[NUM_DANCES];
// uint8_t dance_step(qk_tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->interrupted || !state->pressed) return SINGLE_TAP;
//         else return SINGLE_HOLD;
//     } else if (state->count == 2) {
//         if (state->interrupted) return DOUBLE_SINGLE_TAP;
//         else if (state->pressed) return DOUBLE_HOLD;
//         else return DOUBLE_TAP;
//     }
//     return MORE_TAPS;
// }


qk_tap_dance_action_t tap_dance_actions[] = {
        [ALT_F4] = ACTION_TAP_DANCE_DOUBLE(KC_NO, LALT(KC_F4)),
};
