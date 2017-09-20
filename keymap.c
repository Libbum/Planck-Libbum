#include "config.h"
#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
#include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

enum planck_layers {
    _BASE = 0,
    _LSHIFT,
    _RSHIFT,
    _MOUSE,
    _COLEMAK,
    _DVORAK,
    _LOWER,
    _RAISE,
    _PLOVER,
    _ADJUST
};

enum planck_keycodes {
    BASE = SAFE_RANGE,
    COLEMAK,
    DVORAK,
    PLOVER,
    LOWER,
    RAISE,
    BACKLIT,
    EXT_PLV,
    OS_ALT  = OSM(MOD_LALT),
    OS_CALT = OSM(MOD_LALT | MOD_LCTL),
    OS_CGUI = OSM(MOD_LGUI | MOD_LCTL),
    OS_CSFT = OSM(MOD_LSFT | MOD_LCTL),
    OS_CTL  = OSM(MOD_LCTL),
    OS_GUI  = OSM(MOD_LGUI),
    OS_SALT = OSM(MOD_LALT | MOD_LSFT),
    OS_SGUI = OSM(MOD_LGUI | MOD_LSFT)
};


//Modifiers
#define S_DOWN  S(KC_DOWN)
#define S_RGHT  S(KC_RGHT)
#define S_UP    S(KC_UP)

// tap dance keys
enum tap_dance {
    _CAPS = 0,
    _ENT,
    _SPC
};

#define TD_CAPS TD(_CAPS)
#define TD_ENT  TD(_ENT) //process_record_user() extends handling
#define TD_SPC  TD(_SPC)

//Keycodes
#define ___x___ KC_TRNS
#define ___fn__ ___x___
#ifdef _______
#undef _______
#endif
#define _______ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base
     * ,-----------------------------------------------------------------------------------.
     * |   Q  |   D  |   R  |   W  |   B  | ^Alt | ^GUI |   J  |   F  |   U  |   P  |   :  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |   A  |   S  |   H  |   T  |   G  | ↑Alt | ↑GUI |   Y  |   N  |   E  |   O  |   I  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |   Z  |   X  |   M  |   C  |   V  | Shift|^Shift|   K  |   L  |   ,  |   .  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |  GUI |  Alt |  Esc | Enter|  Tab | BkSp | Space| Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_BASE] = {
        {KC_Q,   KC_D,   KC_R,   KC_W,   KC_B,   OS_CALT, OS_CGUI, KC_J,   KC_F,    KC_U,    KC_P,   KC_SCLN},
        {KC_A,   KC_S,   KC_H,   KC_T,   KC_G,   OS_SALT, OS_SGUI, KC_Y,   KC_N,    KC_E,    KC_O,   KC_I},
        {KC_Z,   KC_X,   KC_M,   KC_C,   KC_V,   TD_CAPS, OS_CSFT, KC_K,   KC_L,    KC_COMM, KC_DOT, KC_QUOTE},
        {OS_CTL, OS_GUI, OS_ALT, KC_ESC, TD_ENT, KC_TAB,  KC_BSPC, TD_SPC, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT}
    },

    /* Left shift
     * ,-----------------------------------------------------------------------------------.
     * |   Q  |   D  |   R  |   W  |   B  | ^Alt | ^GUI |   J  |   F  |   U  |   P  |   :  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |   A  |   S  |   H  |   T  |   G  | ↑Alt | ↑GUI |   Y  |   N  |   E  |   O  |   I  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |   Z  |   X  |   M  |   C  |   V  | Caps |^Shift|   K  |   L  |   /  |   ?  |   "  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |  GUI |  Alt |  Esc |  f() |  Tab |  Del |   -  | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_LSHIFT] = {
        {S(KC_Q), S(KC_D), S(KC_R), S(KC_W), S(KC_B), OS_CALT, OS_CGUI, S(KC_J), S(KC_F), S(KC_U), S(KC_P), KC_COLN},
        {S(KC_A), S(KC_S), S(KC_H), S(KC_T), S(KC_G), OS_SALT, OS_SGUI, S(KC_Y), S(KC_N), S(KC_E), S(KC_O), S(KC_I)},
        {S(KC_Z), S(KC_X), S(KC_M), S(KC_C), S(KC_V), TD_CAPS, OS_CSFT, S(KC_K), S(KC_L), KC_SLSH, KC_QUES, KC_QUOT},
        {OS_CTL,  OS_GUI,  OS_ALT,  KC_ESC,  ___fn__, KC_TAB,  KC_DEL,  KC_MINS, KC_LEFT, S_DOWN,  S_UP,    S_RGHT}
    },

    /* Right shift
     * ,-----------------------------------------------------------------------------------.
     * |   Q  |   D  |   R  |   W  |   B  | ^Alt | ^GUI |   J  |   F  |   U  |   P  |   :  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |   A  |   S  |   H  |   T  |   G  | ↑Alt | ↑GUI |   Y  |   N  |   E  |   O  |   I  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |   Z  |   X  |   M  |   C  |   V  | Caps |^Shift|   K  |   L  |   ~  |   `  |   "  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |  GUI |  Alt |  Esc |   _  |  Tab | BkSp |  f() | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_RSHIFT] = {
        {S(KC_Q), S(KC_D), S(KC_R), S(KC_W), S(KC_B), OS_CALT, OS_CGUI, S(KC_J), S(KC_F), S(KC_U), S(KC_P), KC_COLN},
        {S(KC_A), S(KC_S), S(KC_H), S(KC_T), S(KC_G), OS_SALT, OS_SGUI, S(KC_Y), S(KC_N), S(KC_E), S(KC_O), S(KC_I)},
        {S(KC_Z), S(KC_X), S(KC_M), S(KC_C), S(KC_V), TD_CAPS, OS_CSFT, S(KC_K), S(KC_L), KC_SLSH, KC_QUES, KC_QUOT},
        {OS_CTL,  OS_GUI,  OS_ALT,  KC_ESC,  KC_UNDS, KC_TAB,  KC_BSPC, ___fn__, KC_LEFT, S_DOWN,  S_UP,    S_RGHT}
    },

    /* Mouse control
     * .-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      | Left |  Up  | Right|  Up  |
     * |-----------------------------------------------------------------------------------|
     * |      | Btn3 | Btn2 | Btn1 |      |      |      |      | Left | Down | Right| Down |
     * |-----------------------------------------------------------------------------------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |-----------------------------------------------------------------------------------|
     * |      |      |      |      |  f() |      |      |      |  f() |      |      |      |
     * '-----------------------------------------------------------------------------------'
     */
    [_MOUSE] = {
        {_______, _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U},
        {_______, KC_BTN3, KC_BTN2, KC_BTN1, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, ___fn__, _______, _______, _______, ___fn__, _______, _______, _______},
    },

    /* Colemak
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK] = {
        {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
        {KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
        {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
        {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
    },

    /* Dvorak
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_DVORAK] = {
        {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
        {KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH},
        {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT },
        {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
    },

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = {
        {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC},
        {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE},
        {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______},
        {_______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY}
    },

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = {
        {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
        {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
        {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
    },

    /* Plover layer (http://opensteno.org)
     * ,-----------------------------------------------------------------------------------.
     * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */

    [_PLOVER] = {
        {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
        {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
        {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
        {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
    },

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------------------.
     * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |Aud on|Audoff|AGnorm|AGswap| Base |Colemk|Dvorak|Plover|      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = {
        {_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL },
        {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, BASE,  COLEMAK, DVORAK,  PLOVER,  _______},
        {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
    }


};

#ifdef AUDIO_ENABLE
float plover_song[][2]     = SONG(PLOVER_SOUND);
float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

// register simple key press
void tap_key(uint16_t keycode)
{
    register_code  (keycode);
    unregister_code(keycode);
}

void shift_key(uint16_t keycode)
{
    register_code  (KC_LSFT);
    tap_key        (keycode);
    unregister_code(KC_LSFT);
}

#define         SHIFT   1
#define NOSHIFT 0

static uint16_t key_timer = 0;

// key press for com_layer() and lt_shift() macros
bool key_press(uint16_t keycode, uint8_t shift)
{
    if (keycode) {
        if (timer_elapsed(key_timer) < TAPPING_TERM) {
            if (shift) {
                shift_key(keycode);
            }
            else {
                tap_key(keycode);
            }
            return true;
        }
    }
    return false;
}

// tap dance persistant mods, see process_record_user()
// keyboard_report->mods (?) appears to be cleared by tap dance
static uint8_t mods = 0;

void tap_mods(keyrecord_t *record, uint16_t keycode)
{
    if (record->event.pressed) {
        mods |= MOD_BIT(keycode);
    }
    else {
        mods &= ~(MOD_BIT(keycode));
    }
}

// (un)register modifiers
void modifier(void (*f)(uint8_t))
{
    if (mods & MOD_BIT(KC_LCTL)) {
        (*f)(KC_LCTL);
    }
    if (mods & MOD_BIT(KC_LGUI)) {
        (*f)(KC_LGUI);
    }
    if (mods & MOD_BIT(KC_LALT)) {
        (*f)(KC_LALT);
    }
}

static uint8_t dt_shift = 0;

// tap dance LT (LAYER, KEY) emulation with <KEY><DOWN> -> <KEY><SHIFT> and auto-repeat extensions!
void tap_shift(qk_tap_dance_state_t *state, uint16_t keycode, uint8_t layer)
{
    // double tap plus down: repeating keycode
    if (state->count > 2) {
        register_code(keycode);
    }
    // tap plus down (or double tap): keycode (one shot) shift
    else if (state->count > 1) {
        tap_key (keycode);
        if (DT_SHIFT) {
            // set_oneshot_mods(MOD_LSFT);
            layer_on(layer);
            set_oneshot_layer(layer, ONESHOT_START);
            dt_shift = 1;
        }
        else {
            layer_on(layer);
        }
    }
    // down: shift
    else if (state->pressed) {
        layer_on(layer);
    }
    // tap: keycode
    else {
        modifier(register_code);
        tap_key (keycode);
        modifier(unregister_code);
    }
}

void tap_reset(uint16_t keycode, uint8_t layer)
{
    unregister_code(keycode);
    if (DT_SHIFT && dt_shift) {
        clear_oneshot_layer_state(ONESHOT_PRESSED);
        dt_shift = 0;
    }
    else {
        layer_off(layer);
    }
}

// augment pseudo LT (_LSHIFT, KC_ENT) handling below for rapid <ENTER><SHIFT> sequences
void enter(qk_tap_dance_state_t *state, void *user_data)
{
    tap_shift(state, KC_ENT, _LSHIFT);
}

void enter_reset(qk_tap_dance_state_t *state, void *user_data)
{
    tap_reset(KC_ENT, _LSHIFT);
}

// augment pseudo LT (_RSHIFT, KC_SPC) handling below for rapid <SPACE><SHIFT> sequences
void space(qk_tap_dance_state_t *state, void *user_data)
{
    tap_shift(state, KC_SPC, _RSHIFT);
}

void space_reset(qk_tap_dance_state_t *state, void *user_data)
{
    tap_reset(KC_SPC, _RSHIFT);
}

void caps(qk_tap_dance_state_t *state, void *user_data)
{
    if (state->count > 1) {
        tap_key(KC_CAPS);
    }
    else {
        set_oneshot_mods(MOD_LSFT);
    }
    reset_tap_dance(state);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [_CAPS] = ACTION_TAP_DANCE_FN         (caps)
        ,[_ENT]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, enter, enter_reset)
            ,[_SPC]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, space, space_reset)
};



#define        LEFT    1
#define        RIGHT   2
static uint8_t thumb = 0;
#define THUMBS_DOWN _MOUSE

static uint8_t overlayer = THUMBS_DOWN;

// left right layer combinations
void com_layer(keyrecord_t *record, uint8_t side, uint16_t keycode, uint8_t shift, uint8_t layer, uint8_t default_layer)
{
    if (record->event.pressed) {
        // layer_on via tap_layer(), see process_record_user()
        key_timer = timer_read();
        thumb     = thumb | side;
    }
    else {
        layer_off(layer);
        // opposite com_layer() thumb may have switched effective layer!
        if (overlayer) {
            layer_off(overlayer);
            overlayer = THUMBS_DOWN;
        }
        if (!key_press(keycode, shift)) {
            // opposite thumb down? see left right combination layer table above
            if (thumb & (side == LEFT ? RIGHT : LEFT)) {
                layer_on(default_layer);
                overlayer = default_layer;
            }
        }
        clear_mods();
        thumb     = thumb & ~side;
        key_timer = 0;
    }
}



// set layer asap to overcome macro latency errors, notably tap dance and LT usage
// this routine inexplicably (?) sets layer_on() faster than can be done in com_layer()
void tap_layer(keyrecord_t *record, uint8_t layer)
{
    if (record->event.pressed) {
        layer_on(layer);
    }
    else {
        layer_off(layer);
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BASE:
            if (record->event.pressed) {
                print("mode just switched to Workman and this is a huge string\n");
                set_single_persistent_default_layer(_BASE);
            }
            return false;
            break;
        case TD_ENT:
            tap_layer(record, _LSHIFT);
            // LT (_LSHIFT, KC_ENT) left right combination layer, see tap dance enter
            com_layer(record, LEFT, 0, 0, _LSHIFT, _DVORAK);
            break;
        case TD_SPC:
            tap_layer(record, _RSHIFT);
            // LT (_RSHIFT, KC_SPC) emulation, see tap dance space
            break;
        case OS_ALT:
            tap_mods(record, KC_LALT);
            break;
        case OS_CTL:
            tap_mods(record, KC_LCTL);
            break;
        case OS_GUI:
            tap_mods(record, KC_LGUI);
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
                backlight_step();
#endif
            } else {
                unregister_code(KC_RSFT);
            }
            return false;
            break;
        case PLOVER:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                stop_all_notes();
                PLAY_SONG(plover_song);
#endif
                layer_off(_RAISE);
                layer_off(_LOWER);
                layer_off(_ADJUST);
                layer_on(_PLOVER);
                if (!eeconfig_is_enabled()) {
                    eeconfig_init();
                }
                keymap_config.raw = eeconfig_read_keymap();
                keymap_config.nkro = 1;
                eeconfig_update_keymap(keymap_config.raw);
            }
            return false;
            break;
        case EXT_PLV:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                PLAY_SONG(plover_gb_song);
#endif
                layer_off(_PLOVER);
            }
            return false;
            break;
    }
    return true;
}
