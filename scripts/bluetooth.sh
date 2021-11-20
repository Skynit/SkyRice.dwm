#!/bin/bash

# load colors
. ~/.ui/dwm/scripts/themes/skynox.sh

get_sound_info() {
    get_bluetooth_state=$(bluetooth | awk '{print $3}')

    if [[ $get_bluetooth_state == "off" ]]; then
        echo "^c$black^^b$grey_dark^ 󰂲 ^d^"
    else
        echo "^c$black^^b$grey_dark^ 󰂯 ^d^"
    fi
}

echo $(get_sound_info)