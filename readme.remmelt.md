# Workflow

## Tokyo60
- Go to https://config.qmk.fm/#/tokyo60/LAYOUT_60_hhkb
- Upload latest json file
- Make any changes
- Download json file
- `python3 util/json_to_c.py tokyo60_keymap_remmelt.json >! keyboards/tokyo60/keymaps/remmelt/keymap.c`
- `make tokyo60:remmelt:dfu`

## Romac
open keyboards/kingly_keys/romac/keymaps/remmelt/keymap.c and edit there
make kingly_keys/romac:remmelt:dfu

## Preonic
open keyboards/preonic/keymaps/remmelt/keymap.c and edit there
make preonic/rev3:remmelt:flash
