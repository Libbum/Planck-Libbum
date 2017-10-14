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
    _SHIFT,
    _LSHIFT,
    _RSHIFT,
    _MOUSE,
    _SYMBOL,
    _SYMREG
};

enum planck_keycodes {
    BASE = SAFE_RANGE,
    OS_ALT  = OSM(MOD_LALT),
    OS_CALT = OSM(MOD_LALT | MOD_LCTL),
    OS_CGUI = OSM(MOD_LGUI | MOD_LCTL),
    OS_CSFT = OSM(MOD_LSFT | MOD_LCTL),
    OS_CTL  = OSM(MOD_LCTL),
    OS_GUI  = OSM(MOD_LGUI),
    OS_SALT = OSM(MOD_LALT | MOD_LSFT),
    OS_SGUI = OSM(MOD_LGUI | MOD_LSFT),
    LT_LEFT = LT (_SYMBOL, KC_LEFT),
    LT_LFTX = LT (_SYMREG, KC_LEFT),
    PS_CIRC,   // pseudo GUI_T(S(KC_6))
    PS_DLR,    // pseudo SFT_T(S(KC_4))
    PS_PERC,   // pseudo ALT_T(S(KC_5))
    PS_LPRN,   // pseudo CTL_T(S(KC_9))
    PS_PIPE,   // pseudo LT (_MOUSE, S(KC_BSLS))
};


//Modifiers
#define S_DOWN  S(KC_DOWN)
#define S_RGHT  S(KC_RGHT)
#define S_UP    S(KC_UP)

// tap dance keys
enum tap_dance {
    _CAPS = 0,
    _ENT,
    _SPC,
    _DQOT,
    _QUOT,
    _LBRC,
    _LCBR,
    _LPRN,
    _RBRC,
    _RCBR,
    _RPRN,
    _RNGL
};

#define TD_CAPS TD(_CAPS)
#define TD_ENT  TD(_ENT) //process_record_user() extends handling
#define TD_SPC  TD(_SPC)
#define TD_QUOT  TD(_QUOT)
#define TD_DQOT TD(_DQOT)
#define TD_RBRC TD(_RBRC)
#define TD_RCBR TD(_RCBR)
#define TD_RPRN TD(_RPRN)
#define TD_LBRC TD(_LBRC)
#define TD_LCBR TD(_LCBR)
#define TD_LPRN TD(_LPRN)
#define TD_RNGL TD(_RNGL)

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
        {KC_Z,   KC_X,   KC_M,   KC_C,   KC_V,   TD_CAPS, OS_CSFT, KC_K,   KC_L,    KC_COMM, KC_DOT, TD_QUOT},
        {OS_CTL, OS_GUI, OS_ALT, KC_ESC, TD_ENT, KC_TAB,  KC_BSPC, TD_SPC, LT_LEFT, KC_DOWN, KC_UP,  KC_RGHT}
    },

    [_SHIFT] = {
        {S(KC_Q),   S(KC_D),   S(KC_R),   S(KC_W),   S(KC_B),   OS_CALT, OS_CGUI, S(KC_J),   S(KC_F),    S(KC_U),    S(KC_P),   KC_SCLN},
        {S(KC_A),   S(KC_S),   S(KC_H),   S(KC_T),   S(KC_G),   OS_SALT, OS_SGUI, S(KC_Y),   S(KC_N),    S(KC_E),    S(KC_O),   S(KC_I)},
        {S(KC_Z),   S(KC_X),   S(KC_M),   S(KC_C),   S(KC_V),   TD_CAPS, OS_CSFT, S(KC_K),   S(KC_L),    KC_COMM, KC_DOT, TD_QUOT},
        {OS_CTL, OS_GUI, OS_ALT, KC_ESC, TD_ENT, KC_TAB,  KC_BSPC, TD_SPC, LT_LEFT, KC_DOWN, KC_UP,  KC_RGHT}
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
        {S(KC_Z), S(KC_X), S(KC_M), S(KC_C), S(KC_V), TD_CAPS, OS_CSFT, S(KC_K), S(KC_L), KC_SLSH, KC_QUES, TD_DQOT},
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
        {S(KC_Z), S(KC_X), S(KC_M), S(KC_C), S(KC_V), TD_CAPS, OS_CSFT, S(KC_K), S(KC_L), KC_SLSH, KC_QUES, TD_DQOT},
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

    /* Symbol navigation
     * .-----------------------------------------------------------------------------------.
     * |   {  |   .  |   *  |   &  |   }  |      |      |      | Home |  Up  |  End | PgUp |
     * |-----------------------------------------------------------------------------------|
     * |   (  |   ^  |   %  |   $  |   )  |      |      |      | Left | Down | Right| PgDn |
     * |-----------------------------------------------------------------------------------|
     * |   [  |   #  |   @  |   !  |   ]  |      |      |      |      |      |      |      |
     * |-----------------------------------------------------------------------------------|
     * |      |      |      |   \  |   |  |      |      |      |  f() |      |      |      |
     * '-----------------------------------------------------------------------------------'
     */
    [_SYMBOL] = {
        {KC_LCBR, KC_DOT,  KC_ASTR, KC_AMPR, TD_RCBR, _______, _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP},
        {PS_LPRN, PS_CIRC, PS_PERC, PS_DLR,  TD_RPRN, _______, _______, _______, LT_LFTX, KC_DOWN, KC_RGHT, KC_PGDN},
        {KC_LBRC, KC_HASH, KC_AT,   KC_EXLM, TD_RBRC, _______, _______, _______, _______, _______, _______, _______},
        {___x___, ___x___, ___x___, KC_BSLS, PS_PIPE, ___x___, ___x___, ___fn__, ___x___, ___x___, ___x___, ___x___},
    },

    /*
     *  .-----------------------------------------------------------------------------------.
     *  |      |   ?  |   +  |   ~  |      |      |      |      |      |      |      |      |
     *  |-----------------------------------------------------------------------------------|
     *  |      |   <  |   =  |   >  |      |      |      |      |  f() |      |      |      |
     *  |-----------------------------------------------------------------------------------|
     *  |      |   3  |   2  |   1  |      |      |      |      |      |      |      |      |
     *  |-----------------------------------------------------------------------------------|
     *  |      |      |      |      |      |      |      |      |  f() |      |      |      |
     *  '-----------------------------------------------------------------------------------'
     */
    [_SYMREG] = {
        {___x___, KC_QUES, KC_PLUS, KC_TILD, ___x___, _______, _______, _______, ___x___, ___x___, ___x___, ___x___},
        {___x___, KC_LT,   KC_EQL,  TD_RNGL, ___x___, _______, _______, _______, ___fn__, ___x___, ___x___, ___x___},
        {___x___, KC_3,    KC_2,    KC_1,    ___x___, _______, _______, _______, _______, _______, _______, _______},
        {___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___fn__, ___x___, ___x___, ___x___},
    },
};

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

#define SHIFT   1
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

// ALT_T, CTL_T, GUI_T, SFT_T for shifted keycodes
void mt_shift(keyrecord_t *record, uint16_t modifier, uint16_t keycode)
{
  if (record->event.pressed) {
    register_code (modifier);
    key_timer = timer_read();
  }
  else {
    unregister_code (modifier);
    if (timer_elapsed(key_timer) < TAPPING_TERM) {
      shift_key(keycode);
    }
    key_timer = 0;
  }
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

// tap dance shift rules
#define S_NEVER  0
#define S_SINGLE 1
#define S_DOUBLE 2
#define S_ALWAYS S_SINGLE | S_DOUBLE

void symbol_pair(uint8_t shift, uint16_t left, uint16_t right)
{
    if (shift & S_DOUBLE) {
        shift_key(left);
        shift_key(right);
    }
    else {
        tap_key(left);
        tap_key(right);
    }
}

#define CLOSE 1

// tap dance symbol pairs
void tap_pair(qk_tap_dance_state_t *state, uint8_t shift, uint16_t left, uint16_t right, uint8_t modifier, uint8_t close)
{
    // triple tap: left right with cursor between symbol pair a la vim :-)
    if (state->count > 2) {
        symbol_pair(shift, left, right);
        tap_key(KC_LEFT);
    }
    // double tap: left right
    else if (state->count > 1) {
        symbol_pair(shift, left, right);
    }
    // down: modifier
    else if (state->pressed) {
        if (modifier) {
            register_code(modifier);
        }
    }
    // tap: left (close: right)
    else {
        if (shift & S_SINGLE) {
            shift_key(close ? right : left);
        }
        else {
            tap_key(close ? right : left);
        }
    }
    if (!modifier) {
        reset_tap_dance(state);
    }
}

void doublequote(qk_tap_dance_state_t *state, void *user_data)
{
    tap_pair(state, S_ALWAYS, KC_QUOT, KC_QUOT, 0, 0);
}

void grave(qk_tap_dance_state_t *state, void *user_data)
{
    tap_pair(state, S_NEVER, KC_GRV, KC_GRV, 0, 0);
}

void lbrace(qk_tap_dance_state_t *state, void *user_data)
{
    tap_pair(state, S_NEVER, KC_LBRC, KC_RBRC, 0, 0);
}

void lcurly(qk_tap_dance_state_t *state, void *user_data)
{
    tap_pair(state, S_ALWAYS, KC_LBRC, KC_RBRC, 0, 0);
}

void lparen(qk_tap_dance_state_t *state, void *user_data)
{
    tap_pair(state, S_ALWAYS, KC_9, KC_0, KC_LCTL, 0);
}

void lparen_reset(qk_tap_dance_state_t *state, void *user_data)
{
    unregister_code(KC_LCTL);
}

void quote(qk_tap_dance_state_t *state, void *user_data)
{
    tap_pair(state, S_NEVER, KC_QUOT, KC_QUOT, 0, 0);
}

void rangle(qk_tap_dance_state_t *state, void *user_data)
{
    tap_pair(state, S_ALWAYS, KC_COMM, KC_DOT, 0, CLOSE);
}

void rbrace(qk_tap_dance_state_t *state, void *user_data)
{
    tap_pair(state, S_NEVER, KC_LBRC, KC_RBRC, 0, CLOSE);
}

void rcurly(qk_tap_dance_state_t *state, void *user_data)
{
    tap_pair(state, S_ALWAYS, KC_LBRC, KC_RBRC, 0, CLOSE);
}

void rparen(qk_tap_dance_state_t *state, void *user_data)
{
    tap_pair(state, S_ALWAYS, KC_9, KC_0, KC_LCTL, CLOSE);
}

void rparen_reset(qk_tap_dance_state_t *state, void *user_data)
{
    unregister_code(KC_LCTL);
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
    [_CAPS] = ACTION_TAP_DANCE_FN         (caps),
    [_ENT]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, enter, enter_reset),
    [_SPC]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, space, space_reset),
    [_QUOT] = ACTION_TAP_DANCE_FN         (quote),
    [_LBRC] = ACTION_TAP_DANCE_FN         (lbrace),
    [_LCBR] = ACTION_TAP_DANCE_FN         (lcurly),
    [_LPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lparen, lparen_reset),
    [_RBRC] = ACTION_TAP_DANCE_FN         (rbrace),
    [_RCBR] = ACTION_TAP_DANCE_FN         (rcurly),
    [_RPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rparen, rparen_reset),
    [_RNGL] = ACTION_TAP_DANCE_FN         (rangle)
};



#define        LEFT    1
#define        RIGHT   2
static uint8_t thumb = 0;
// LEFT (KC_SPC, S(KC_BSLS)), RIGHT (KC_LEFT, S(KC_LEFT)) opposite thumb combinations, see process_record_user()
// up,   down -> _SYMBOL
// down, down -> _MOUSE
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
            com_layer(record, LEFT, 0, 0, _LSHIFT, _SYMBOL);
            break;
        case TD_SPC:
            tap_layer(record, _RSHIFT);
            // LT (_RSHIFT, KC_SPC) emulation, see tap dance space
            break;
        case LT_LEFT:
            tap_layer(record, _SYMBOL);
            // LT (_SYMBOL, KC_LEFT) left right combination layer
            com_layer(record, RIGHT, 0, 0, _SYMBOL, _LSHIFT);
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
        case PS_CIRC:
            // GUI_T(S(KC_6))
            mt_shift(record, KC_LGUI, KC_6);
            break;
        case PS_DLR:
            // SFT_T(S(KC_4))
            mt_shift(record, KC_LSFT, KC_4);
            break;
        case PS_LPRN:
            // CTL_T(S(KC_9))
            mt_shift(record, KC_LCTL, KC_9);
            break;
        case PS_PERC:
            // ALT_T(S(KC_5))
            mt_shift(record, KC_LALT, KC_5);
            break;
        case PS_PIPE:
            tap_layer(record, _MOUSE);
            // LT (_MOUSE, S(KC_BSLS)) left right combination layer
            com_layer(record, LEFT, KC_BSLS, SHIFT, _MOUSE, _SYMBOL);
            break;
    }
    return true;
}
