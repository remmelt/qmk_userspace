import json
import sys

DEFAULT_KEYMAP_C = """#include QMK_KEYBOARD_H
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
__KEYMAP_GOES_HERE__
};
"""

if (len(sys.argv) != 2):
    print('Not enough args')
    sys.exit(1)

jsonFile = sys.argv[1]

with open(jsonFile) as f:
    data = json.load(f)

keymap_c = DEFAULT_KEYMAP_C
layer_txt = []
for layer_num, layer in enumerate(data['layers']):
    keys = [x[4:-1] if x.startswith('ANY(') else x for x in layer] # Remove ANY() function
    if layer_num != 0:
        layer_txt[-1] = layer_txt[-1] + ','
    layer_keys = ', '.join(keys)
    layer_txt.append('\t[%s] = %s(%s)' % (layer_num, data['layout'], layer_keys))

keymap = '\n'.join(layer_txt)
print(keymap_c.replace('__KEYMAP_GOES_HERE__', keymap))
