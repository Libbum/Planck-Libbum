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
    _ALPHA,
    _SALPHA,
    _NUMBER,
    _NUMSYM,
    _SYMBOL,
    _SYMREG,
    _MOUSE,
    _FNCKEY,
    _EDIT
};

enum planck_keycodes {
    BASE = SAFE_RANGE,
    PS_CIRC,   /* pseudo GUI_T(S(KC_6)) */
    PS_DLR,    /* pseudo SFT_T(S(KC_4)) */
    PS_PERC,   /* pseudo ALT_T(S(KC_5)) */
    PS_LPRN,   /* pseudo CTL_T(S(KC_9)) */
    PS_LEFT,   /* pseudo LT(_MOUSE, S(KC_LEFT)) */
    PS_PIPE,   /* pseudo LT(_MOUSE, S(KC_BSLS)) */
    PS_TAB,    /* pseudo LT(_FNCKEY, S(KC_TAB)) */
    LT_A    = LT(_NUMSYM, KC_A),
    LT_BSPC = LT(_EDIT,   KC_BSPC),
    LT_ESC  = LT(_NUMBER, KC_ESC),
    LT_LEFT = LT(_SYMBOL, KC_LEFT),
    LT_LFTX = LT(_SYMREG, KC_LEFT),
    LT_TAB  = LT(_FNCKEY, KC_TAB),
    OS_ALT  = OSM(MOD_LALT),
    OS_CALT = OSM(MOD_LALT | MOD_LCTL),
    OS_CGUI = OSM(MOD_LGUI | MOD_LCTL),
   /* OS_CSFT = OSM(MOD_LSFT | MOD_LCTL), */
    OS_CTL  = OSM(MOD_LCTL),
    OS_GUI  = OSM(MOD_LGUI),
    OS_SALT = OSM(MOD_LALT | MOD_LSFT),
    OS_SFT  = OSM(MOD_LSFT),
    OS_SGUI = OSM(MOD_LGUI | MOD_LSFT)
};

/* modifier keys */
#define AT_B    ALT_T(KC_B)
#define AT_DOWN ALT_T(KC_DOWN)
#define CT_RGHT CTL_T(KC_RGHT)
#define GT_C    GUI_T(KC_C)
#define GT_UP   GUI_T(KC_UP)
#define MT_E    MT(MOD_LCTL | MOD_LALT, KC_E)
#define MT_X    MT(MOD_LALT | MOD_LSFT, KC_X)
#define S_DOWN  S(KC_DOWN)
#define S_RGHT  S(KC_RGHT)
#define S_UP    S(KC_UP)

/* tap dance keys */
enum tap_dance {
    _CAPS = 0,
    _COMM,
    _DQOT,
    _ENT,
    _GRV,
    _LBRC,
    _LCBR,
    _LPRN,
    _QUOT,
    _RBRC,
    _RCBR,
    _RNGL,
    _RPRN,
    _SPC,
    _TILD,
    _ALPH
};

#define TD_CAPS TD(_CAPS)
#define TD_COMM TD(_COMM)
#define TD_PERC TD(_PERC)
#define TD_DQOT TD(_DQOT)
#define TD_ENT  TD(_ENT)
#define TD_GRV  TD(_GRV)
#define TD_LBRC TD(_LBRC)
#define TD_LCBR TD(_LCBR)
#define TD_LPRN TD(_LPRN)
#define TD_QUOT TD(_QUOT)
#define TD_RBRC TD(_RBRC)
#define TD_RCBR TD(_RCBR)
#define TD_RNGL TD(_RNGL)
#define TD_RPRN TD(_RPRN)
#define TD_SPC  TD(_SPC)
#define TD_TILD TD(_TILD)
#define TD_ALPH TD(_ALPH)

/* keycodes */
#define ___x___ KC_TRNS
#define ___fn__ ___x___
#ifdef _______
#undef _______
#endif
#define _______ KC_NO
#define COPY    LCTL(KC_C)
#define CUT     LCTL(KC_X)
#define EOT     LCTL(KC_D)
#define NAK     LCTL(KC_U)
#define PASTE   LCTL(KC_V)
#define UNDO    LCTL(KC_Z)
#define TMCOPY  LALT(LCTL(KC_C))
#define TMPASTE LALT(LCTL(KC_V))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base
     * ,-----------------------------------------------------------------------------------.
     * |   Q  |   D  |   R  |   W  |   B  | ^Alt | ^GUI |   J  |   F  |   U  |   P  |   :  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |   A  |   S  |   H  |   T  |   G  | ↑Alt | ↑GUI |   Y  |   N  |   E  |   O  |   I  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |   Z  |   X  |   M  |   C  |   V  | Shift| Alpha|   K  |   L  |   ,  |   .  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |  GUI |  Alt |  Esc | Enter|  Tab | BkSp | Space| Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_BASE] = {
        {KC_Q,   KC_D,   KC_R,   KC_W,   KC_B,   OS_CALT, OS_CGUI, KC_J,   KC_F,    KC_U,    KC_P,   KC_SCLN},
        {KC_A,   KC_S,   KC_H,   KC_T,   KC_G,   OS_SALT, OS_SGUI, KC_Y,   KC_N,    KC_E,    KC_O,   KC_I},
        {KC_Z,   KC_X,   KC_M,   KC_C,   KC_V,   TD_CAPS, TD_ALPH, KC_K,   KC_L,    KC_COMM, KC_DOT, TD_QUOT},
        {OS_CTL, OS_GUI, OS_ALT, LT_ESC, TD_ENT, LT_TAB,  LT_BSPC, TD_SPC, LT_LEFT, AT_DOWN, GT_UP,  CT_RGHT}
    },

    [_SHIFT] = {
        {S(KC_Q), S(KC_D), S(KC_R), S(KC_W), S(KC_B), OS_CALT, OS_CGUI, S(KC_J), S(KC_F), S(KC_U), S(KC_P), KC_SCLN},
        {S(KC_A), S(KC_S), S(KC_H), S(KC_T), S(KC_G), OS_SALT, OS_SGUI, S(KC_Y), S(KC_N), S(KC_E), S(KC_O), S(KC_I)},
        {S(KC_Z), S(KC_X), S(KC_M), S(KC_C), S(KC_V), TD_CAPS, TD_ALPH, S(KC_K), S(KC_L), KC_COMM, KC_DOT,  TD_QUOT},
        {OS_CTL,  OS_GUI,  OS_ALT,  LT_ESC,  TD_ENT,  LT_TAB,  LT_BSPC, TD_SPC,  LT_LEFT, AT_DOWN, GT_UP,   CT_RGHT}
    },

    /* Left shift
     * ,-----------------------------------------------------------------------------------.
     * |   Q  |   D  |   R  |   W  |   B  | ^Alt | ^GUI |   J  |   F  |   U  |   P  |   :  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |   A  |   S  |   H  |   T  |   G  | ↑Alt | ↑GUI |   Y  |   N  |   E  |   O  |   I  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |   Z  |   X  |   M  |   C  |   V  | Caps | Alpha|   K  |   L  |   /  |   ?  |   "  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |  GUI |  Alt |  Esc |  f() |  Tab |  Del |   -  | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_LSHIFT] = {
        {S(KC_Q), S(KC_D), S(KC_R), S(KC_W), S(KC_B), OS_CALT, OS_CGUI, S(KC_J), S(KC_F), S(KC_U), S(KC_P), KC_COLN},
        {S(KC_A), S(KC_S), S(KC_H), S(KC_T), S(KC_G), OS_SALT, OS_SGUI, S(KC_Y), S(KC_N), S(KC_E), S(KC_O), S(KC_I)},
        {S(KC_Z), S(KC_X), S(KC_M), S(KC_C), S(KC_V), TD_CAPS, TD_ALPH, S(KC_K), S(KC_L), KC_SLSH, KC_QUES, TD_DQOT},
        {OS_CTL,  OS_GUI,  OS_ALT,  LT_ESC,  ___fn__, LT_TAB,  KC_DEL,  KC_MINS, PS_LEFT, S_DOWN,  S_UP,    S_RGHT}
    },

    /* Right shift
     * ,-----------------------------------------------------------------------------------.
     * |   Q  |   D  |   R  |   W  |   B  | ^Alt | ^GUI |   J  |   F  |   U  |   P  |   :  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |   A  |   S  |   H  |   T  |   G  | ↑Alt | ↑GUI |   Y  |   N  |   E  |   O  |   I  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |   Z  |   X  |   M  |   C  |   V  | Caps | Alpha|   K  |   L  |   ~  |   `  |   "  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |  GUI |  Alt |  Esc |   _  |  Tab | BkSp |  f() | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_RSHIFT] = {
        {S(KC_Q), S(KC_D), S(KC_R), S(KC_W), S(KC_B), OS_CALT, OS_CGUI, S(KC_J), S(KC_F), S(KC_U), S(KC_P), KC_COLN},
        {S(KC_A), S(KC_S), S(KC_H), S(KC_T), S(KC_G), OS_SALT, OS_SGUI, S(KC_Y), S(KC_N), S(KC_E), S(KC_O), S(KC_I)},
        {S(KC_Z), S(KC_X), S(KC_M), S(KC_C), S(KC_V), TD_CAPS, TD_ALPH, S(KC_K), S(KC_L), TD_TILD, TD_GRV, TD_DQOT},
        {OS_CTL,  OS_GUI,  OS_ALT,  LT_ESC,  KC_UNDS, PS_TAB,  LT_BSPC, ___fn__, PS_LEFT, S_DOWN,  S_UP,    S_RGHT}
    },

    /* Alpha
     * .-----------------------------------------------------------------------------------.
     * |   θ  |   δ  |   ρ  |   ω  |   β  |      |      |   ς  |   φ  |   υ  |   π  |      |
     * |-----------------------------------------------------------------------------------|
     * |   α  |   σ  |   η  |   τ  |   γ  |      |      |   ψ  |   ν  |   ε  |   ο  |   ι  |
     * |-----------------------------------------------------------------------------------|
     * |   ζ  |   χ  |   μ  |   ξ  |      |      |      |   κ  |   λ  |   å  |   ä  |   ö  |
     * |-----------------------------------------------------------------------------------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * '-----------------------------------------------------------------------------------'
     */
    [_ALPHA] = {
        {UC(0x03B8), UC(0x03B4), UC(0x03C1), UC(0x03C9), UC(0x03B2), _______, _______, UC(0x03C2), UC(0x03C6), UC(0x03C5), UC(0x03C0), _______},
        {UC(0x03B1), UC(0x03C3), UC(0x03B7), UC(0x03C4), UC(0x03B3), _______, _______, UC(0x03C8), UC(0x03BD), UC(0x03B5), UC(0x03Bf), UC(0x03B9)},
        {UC(0x03B6), UC(0x03C7), UC(0x03BC), UC(0x03BE), _______,    _______, _______, UC(0x03BA), UC(0x03BB), UC(0xE5),   UC(0xE4),   UC(0xF6)},
        {___x___,     ___x___,   ___x___,    ___x___,    ___x___,    ___x___, ___x___, ___x___,    ___x___,    ___x___,    ___x___,    ___x___},
    },

    /* Shifted Alpha
     * .-----------------------------------------------------------------------------------.
     * |   Θ  |   Δ  |   Ρ  |   Ω  |   Β  |      |      |   Σ  |   Φ  |   Υ  |   Π  |      |
     * |-----------------------------------------------------------------------------------|
     * |   Α  |   Σ  |   Η  |   Τ  |   Γ  |      |      |   Ψ  |   Ν  |   Ε  |   Ο  |   Ι  |
     * |-----------------------------------------------------------------------------------|
     * |   Ζ  |   Χ  |   Μ  |   Ξ  |      |      |      |   Κ  |   Λ  |   Å  |   Ä  |   Ö  |
     * |-----------------------------------------------------------------------------------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * '-----------------------------------------------------------------------------------'
     */
    [_SALPHA] = {
        {UC(0x0398), UC(0x0394), UC(0x03A1), UC(0x03A9), UC(0x0392), _______, _______, UC(0x03A3), UC(0x03A6), UC(0x03A5), UC(0x03A0), _______},
        {UC(0x0391), UC(0x03A3), UC(0x0397), UC(0x03A4), UC(0x0393), _______, _______, UC(0x03A8), UC(0x039D), UC(0x0395), UC(0x039F), UC(0x0399)},
        {UC(0x0396), UC(0x03A7), UC(0x039C), UC(0x039E), _______,    _______, _______, UC(0x039A), UC(0x039B), UC(0xC5),   UC(0xC4),   UC(0xD6)},
        {___x___,     ___x___,   ___x___,    ___x___,    ___x___,    ___x___, ___x___, ___x___,    ___x___,    ___x___,    ___x___,    ___x___},
    },

    /* Numpad
     * .-----------------------------------------------------------------------------------.
     * |      |   F  |   E  |   D  |      |      |      |   /  |   7  |   8  |   9  |   *  |
     * |-----------------------------------------------------------------------------------|
     * | Ctrl |   C  |   B  |   A  |      |      |      |   .  |   4  |   5  |   6  |   -  |
     * |-----------------------------------------------------------------------------------|
     * |      |   #  |   X  |   G  |      |      |      |   ,  |   1  |   2  |   3  |   +  |
     * |-----------------------------------------------------------------------------------|
     * |      |      |      |  f() |      |      |      |   0  |   =  |      |      |      |
     * '-----------------------------------------------------------------------------------'
     */
    [_NUMBER] = {
        {_______, KC_F,    MT_E,    KC_D,    _______, _______, _______, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_ASTR},
        {OS_CTL,  GT_C,    AT_B,    LT_A,    _______, _______, _______, KC_DOT,  KC_4,    KC_5,    KC_6,    KC_MINS},
        {_______, KC_HASH, MT_X,    KC_G,    _______, _______, _______, TD_COMM, KC_1,    KC_2,    KC_3,    KC_PLUS},
        {___x___, ___x___, ___x___, ___fn__, ___x___, ___x___, ___x___, KC_0,    KC_EQL,  ___x___, ___x___, ___x___},
    },

    /*
     * .-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |   {  |   &  |   ?  |   :  |   }  |
     * |-----------------------------------------------------------------------------------|
     * |      |      |      |  f() |      |      |      |   (  |   $  |   %  |   ^  |   )  |
     * |-----------------------------------------------------------------------------------|
     * |      |      |      |      |      |      |      |   [  |   <  |   ~  |   >  |   ]  |
     * |-----------------------------------------------------------------------------------|
     * |      |      |      |  f() |      |      |      |   |  |   \  |      |      |      |
     * '-----------------------------------------------------------------------------------'
     */
    [_NUMSYM] = {
        {_______, _______, _______, ___x___, _______, _______, _______, TD_LCBR, KC_AMPR, KC_QUES, KC_COLN, KC_RCBR},
        {___x___, ___x___, ___x___, ___fn__, _______, _______, _______, TD_LPRN, KC_DLR,  KC_PERC, KC_CIRC, KC_RPRN},
        {_______, _______, _______, ___x___, _______, _______, _______, TD_LBRC, KC_LT,   KC_TILD, KC_GT,   KC_RBRC},
        {___x___, ___x___, ___x___, ___fn__, ___x___, ___x___, ___x___, KC_PIPE, KC_BSLS, ___x___, ___x___, ___x___},
    },

    /* Symbols
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
     * .-----------------------------------------------------------------------------------.
     * |      |   ?  |   +  |   ~  |      |      |      |      |      |      |      |      |
     * |-----------------------------------------------------------------------------------|
     * |      |   <  |   =  |   >  |      |      |      |      |  f() |      |      |      |
     * |-----------------------------------------------------------------------------------|
     * |      |   3  |   2  |   1  |      |      |      |      |      |      |      |      |
     * |-----------------------------------------------------------------------------------|
     * |      |      |      |      |      |      |      |      |  f() |      |      |      |
     * '-----------------------------------------------------------------------------------'
     */
    [_SYMREG] = {
        {___x___, KC_QUES, KC_PLUS, KC_TILD, ___x___, _______, _______, _______, ___x___, ___x___, ___x___, ___x___},
        {___x___, KC_LT,   KC_EQL,  TD_RNGL, ___x___, _______, _______, _______, ___fn__, ___x___, ___x___, ___x___},
        {___x___, KC_3,    KC_2,    KC_1,    ___x___, _______, _______, _______, _______, _______, _______, _______},
        {___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___fn__, ___x___, ___x___, ___x___},
    },

    /*
     * .-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |ScLeft|  Up  |SRight| ScUp |
     * |-----------------------------------------------------------------------------------|
     * |      | Btn2 | Btn3 | Btn1 |      |      |      |      | Left | Down | Right|ScDown|
     * |-----------------------------------------------------------------------------------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |-----------------------------------------------------------------------------------|
     * |      |      |      |      |  f() |      |      |      |  f() |      |      |      |
     * '-----------------------------------------------------------------------------------'
     */
    [_MOUSE] = {
        {_______, _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U},
        {_______, KC_BTN2, KC_BTN3, KC_BTN1, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, ___fn__, _______, _______, _______, ___fn__, _______, _______, _______},
    },

    /* Functions
     * .-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |  F7  |  F8  |  F9  |  F12 |
     * |-----------------------------------------------------------------------------------|
     * | Ctrl |  GUI |  Alt | Shift|      |      |      |      |  F4  |  F5  |  F6  |  F11 |
     * |-----------------------------------------------------------------------------------|
     * |      |      |      |      |      |      |      |      |  F1  |  F2  |  F3  |  F10 |
     * |-----------------------------------------------------------------------------------|
     * |      |      |      |      |      |  f() |      |   +  |      |      |      |      |
     * '-----------------------------------------------------------------------------------'
     */
    [_FNCKEY] = {
        {_______, _______, _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F12 },
        {OS_CTL,  OS_GUI,  OS_ALT,  OS_SFT,  _______, _______, _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11 },
        {_______, _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F10 },
        {_______, _______, _______, _______, _______, ___fn__, _______, KC_PLUS, _______, _______, _______, _______},
    },

    /* Shortcuts
     * .-----------------------------------------------------------------------------------.
     * |      |      | Copy | Paste|      |      |      |      |      |      |      |      |
     * |--------------------------------------------------------------+------+------+------|
     * | Undo |  Cut | Copy | Paste|      |      |      |      |      |      |      |      |
     * |-----------------------------------------------------------------------------------|
     * |      |      |  Nak |  Eot |      |      |      |      |      |      |      |      |
     * |-----------------------------------------------------------------------------------|
     * |      |      |      |      |      |      |  f() |      |      |      |      |      |
     * '-----------------------------------------------------------------------------------'
     */
    [_EDIT] = {
        {_______, _______, TMCOPY,  TMPASTE, _______, _______, _______, _______, _______, _______, _______, _______},
        {UNDO,    CUT,     COPY,    PASTE,   _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, NAK,     EOT,     _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, ___fn__, _______, _______, _______, _______, _______},
    },

};

#ifdef AUDIO_ENABLE
float song_startup  [][2] = SONG(STARTUP_SOUND);
float music_scale   [][2] = SONG(MUSIC_SCALE_SOUND);
float song_goodbye  [][2] = SONG(GOODBYE_SOUND);
#endif

/* Keycode Primitives ------------------------------------------------------- */

/* register simple key press */
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
#define         NOSHIFT 0

static uint16_t key_timer = 0;

/* key press for com_layer() and lt_shift() macros */
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

/* ALT_T, CTL_T, GUI_T, SFT_T for shifted keycodes */
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

/* Mod Masks ---------------------------------------------------------------- */

/* tap dance persistant mods, see process_record_user()
   keyboard_report->mods (?) appears to be cleared by tap dance */
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

/* (un)register modifiers */
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

/* Triple Dance Insert ------------------------------------------------------ */

void tilde(qk_tap_dance_state_t *state, void *user_data)
{
    /* double tap plus down: repeating keycode */
    if (state->count > 2) {
        register_code(KC_LSFT);
        register_code(KC_GRV);
    }
    /* tap: keycode */
    else {
        shift_key(KC_GRV);
        /* double tap: unix home directory */
        if (state->count > 1) {
            tap_key(KC_SLSH);
        }
    }
}

void tilde_reset(qk_tap_dance_state_t *state, void *user_data)
{
    unregister_code(KC_GRV);
    unregister_code(KC_LSFT);
}

/* Triple Dance Shift/Layer ------------------------------------------------- */

static uint8_t dt_shift = 0;

void double_shift(uint16_t keycode, uint8_t layer)
{
    tap_key (keycode);
    if (DT_SHIFT) {
        /* set_oneshot_mods(MOD_LSFT);
           layer_on(layer); */
        layer_on(_SHIFT);
        set_oneshot_layer(_SHIFT, ONESHOT_START);
        dt_shift = 1;
    }
    else {
        layer_on(layer);
    }
}

/* tap dance LT (LAYER, KEY) emulation with <KEY><DOWN> -> <KEY><SHIFT> and auto-repeat extensions! */
void tap_shift(qk_tap_dance_state_t *state, uint16_t keycode, uint8_t layer)
{
    /* double tap plus down */
    if (state->count > 2) {
        /* double enter shift */
        if (keycode == KC_ENT) {
            tap_key     (keycode);
            double_shift(keycode, layer);
        }
        /* repeating keycode */
        else {
            register_code(keycode);
        }
    }
    /* tap plus down (or double tap): keycode (one shot) shift */
    else if (state->count > 1) {
        double_shift(keycode, layer);
    }
    /* down: shift */
    else if (state->pressed) {
        layer_on(layer);
    }
    /* tap: keycode */
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

/* augment pseudo LT (_RSHIFT, KC_ENT) handling below for rapid <ENTER><SHIFT> sequences */
void enter(qk_tap_dance_state_t *state, void *user_data)
{
    tap_shift(state, KC_ENT, _LSHIFT);
}

void enter_reset(qk_tap_dance_state_t *state, void *user_data)
{
    tap_reset(KC_ENT, _LSHIFT);
}

/* augment pseudo LT (_LSHIFT, KC_SPC) handling below for rapid <SPACE><SHIFT> sequences */
void space(qk_tap_dance_state_t *state, void *user_data)
{
    tap_shift(state, KC_SPC, _RSHIFT);
}

void space_reset(qk_tap_dance_state_t *state, void *user_data)
{
    tap_reset(KC_SPC, _RSHIFT);
}


/* Tap Dance Pairs ---------------------------------------------------------- */

/* tap dance shift rules */
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

/* tap dance symbol pairs */
void tap_pair(qk_tap_dance_state_t *state, uint8_t shift, uint16_t left, uint16_t right, uint8_t modifier, uint8_t close)
{
    /* triple tap: left right */
    if (state->count > 2) {
        symbol_pair(shift, left, right);
    }
    /* double tap: left right with cursor between symbol pair */
    else if (state->count > 1) {
        symbol_pair(shift, left, right);
        tap_key(KC_LEFT);
    }
    /* down: modifier */
    else if (state->pressed) {
        if (modifier) {
            register_code(modifier);
        }
    }
    /* tap: left (close: right) */
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

void alpha(qk_tap_dance_state_t *state, void *user_data)
{
    if (state->count > 1) {
        set_oneshot_layer(_SALPHA, ONESHOT_START);
    }
    else {
        set_oneshot_layer(_ALPHA, ONESHOT_START);
    }
}

void alpha_reset(qk_tap_dance_state_t *state, void *user_data)
{
    clear_oneshot_layer_state(ONESHOT_PRESSED);
}

/* Tap Dance Insert --------------------------------------------------------- */

void comma(qk_tap_dance_state_t *state, void *user_data)
{
    tap_key(KC_COMM);
    if (state->count > 1) {
        tap_key(KC_SPC);
    }
    reset_tap_dance(state);
}


/* Tap Dance Toggle --------------------------------------------------------- */

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
    [_CAPS] = ACTION_TAP_DANCE_FN(caps),
    [_COMM] = ACTION_TAP_DANCE_FN(comma),
    [_DQOT] = ACTION_TAP_DANCE_FN(doublequote),
    [_GRV]  = ACTION_TAP_DANCE_FN(grave),
    [_LBRC] = ACTION_TAP_DANCE_FN(lbrace),
    [_LCBR] = ACTION_TAP_DANCE_FN(lcurly),
    [_QUOT] = ACTION_TAP_DANCE_FN(quote),
    [_RBRC] = ACTION_TAP_DANCE_FN(rbrace),
    [_RCBR] = ACTION_TAP_DANCE_FN(rcurly),
    [_RNGL] = ACTION_TAP_DANCE_FN(rangle),
    [_ALPH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alpha, alpha_reset),
    [_LPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lparen, lparen_reset),
    [_ENT]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, enter, enter_reset),
    [_RPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rparen, rparen_reset),
    [_SPC]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, space, space_reset),
    [_TILD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tilde, tilde_reset)
};

/* Dynamic Layers ----------------------------------------------------------- */

#define        LEFT    1
#define        RIGHT   2
static uint8_t thumb = 0;

/* LEFT (KC_SPC, S(KC_BSLS)), RIGHT (KC_LEFT, S(KC_LEFT)) opposite thumb combinations, see process_record_user()
   up,   up   -> _BASE
   up,   down -> _SYMBOL
   down, up   -> _NUMBER
   down, down -> _MOUSE */
#define THUMBS_DOWN _MOUSE

static uint8_t overlayer = THUMBS_DOWN;

/* left right layer combinations */
void com_layer(keyrecord_t *record, uint8_t side, uint16_t keycode, uint8_t shift, uint8_t layer, uint8_t default_layer)
{
    if (record->event.pressed) {
        /* layer_on via tap_layer(), see process_record_user() */
        key_timer = timer_read();
        thumb     = thumb | side;
    }
    else {
        layer_off(layer);
        /* opposite com_layer() thumb may have switched effective layer */
        if (overlayer) {
            layer_off(overlayer);
            overlayer = THUMBS_DOWN;
        }
        if (!key_press(keycode, shift)) {
            /* opposite thumb down? see left right combination layer table above */
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

/* LT for S(keycode) */
void lt_shift(keyrecord_t *record, uint16_t keycode, uint8_t layer)
{
    if (record->event.pressed) {
        layer_on(layer);
        key_timer = timer_read();
    }
    else {
        layer_off(layer);
        /* for shifted keycodes, hence, LT_SHIFT */
        key_press(keycode, SHIFT);
        clear_mods();
        key_timer = 0;
    }
}

/* set layer asap to overcome macro latency errors, notably tap dance and LT usage
   this routine inexplicably (?) sets layer_on() faster than can be done in com_layer() */
void tap_layer(keyrecord_t *record, uint8_t layer)
{
    if (record->event.pressed) {
        layer_on(layer);
    }
    else {
        layer_off(layer);
    }
}

/* Keymaps ------------------------------------------------------------------ */

void persistant_default_layer_set(uint16_t default_layer)
{
    eeconfig_update_default_layer(default_layer);
    default_layer_set            (default_layer);
}

/* User Keycode Trap -------------------------------------------------------- */

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
        case AT_DOWN:
            tap_mods(record, KC_LALT);
            break;
        case CT_RGHT:
            tap_mods(record, KC_LCTL);
            break;
        case GT_UP:
            tap_mods(record, KC_LGUI);
            break;
        case LT_ESC:
            tap_layer(record, _NUMBER);
            break;
        case LT_LEFT:
            tap_layer(record, _SYMBOL);
            /* LT (_SYMBOL, KC_LEFT) left right combination layer */
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
            /* GUI_T(S(KC_6)) */
            mt_shift(record, KC_LGUI, KC_6);
            break;
        case PS_DLR:
            /* SFT_T(S(KC_4)) */
            mt_shift(record, KC_LSFT, KC_4);
            break;
        case PS_LPRN:
            /* CTL_T(S(KC_9)) */
            mt_shift(record, KC_LCTL, KC_9);
            break;
        case PS_PERC:
            /* ALT_T(S(KC_5)) */
            mt_shift(record, KC_LALT, KC_5);
            break;
        case PS_LEFT:
            tap_layer(record, _MOUSE);
            /* LT (_MOUSE, S(KC_LEFT)) left right combination layer */
            com_layer(record, RIGHT, KC_LEFT, SHIFT, _MOUSE, _LSHIFT);
            break;
        case PS_PIPE:
            tap_layer(record, _MOUSE);
            /* LT (_MOUSE, S(KC_BSLS)) left right combination layer */
            com_layer(record, LEFT, KC_BSLS, SHIFT, _MOUSE, _SYMBOL);
            break;
        case PS_TAB:
            /* LT (_FNCKEY, S(KC_TAB)) emulation */
            lt_shift(record, KC_TAB, _FNCKEY);
            break;
        case TD_ENT:
            tap_layer(record, _LSHIFT);
            /* LT (_LSHIFT, KC_ENT) emulation, see tap dance enter */
            com_layer(record, LEFT, 0, 0, _LSHIFT, _SYMBOL);
            break;
        case TD_SPC:
            tap_layer(record, _RSHIFT);
            /* LT (_RSHIFT, KC_SPC) left right combination layer, see tap dance space */
            break;
    }
    return true;
}

/* Audio ------------------------------------------------------------------ */

void matrix_init_user(void)
{
    set_unicode_input_mode(UC_LNX);
#ifdef AUDIO_ENABLE
    startup_user();
#endif
}

#ifdef AUDIO_ENABLE
void startup_user(void)
{
    _delay_ms(20);                            /* gets rid of tick */
    PLAY_SONG(song_startup);
}

void shutdown_user(void)
{
    PLAY_SONG(song_goodbye);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}
#endif
