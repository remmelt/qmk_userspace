# Workflow

## Remmelt's notes
`qmk userspace-compile`

or

```bash
qmk lint -kb preonic/rev3_drop -km remmelt
qmk compile -kb preonic/rev3_drop -km remmelt
qmk flash -kb preonic/rev3_drop -km remmelt
```

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
open keyboards/preonic/rev3_drop/keymaps/remmelt/keymap.c and edit there
make preonic/rev3_drop:remmelt:flash
