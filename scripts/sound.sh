#!/bin/bash

# load colors
. ~/.ui/dwm/scripts/themes/skynox.sh

get_sound_info() {
    get_volume=$(pulsemixer --get-volume | awk '{ print $1 }')
    get_mute=$(pulsemixer --get-mute)

    if [[ $get_mute == "1" ]]; then
        echo "^c$black^^b$yellow_light^ 󰝟 ^d^"
    else
        case $get_volume in
            6[7-9]|7[0-9]|8[0-9]|9[0-9]|100|*)
                echo "^c$black^^b$yellow_light^ 󰕾 ^d^^c$black_dark^^b$yellow^ ${get_volume}% ^d^" ;;
            3[4-9]|4[0-9]|5[0-9]|6[0-6])
                echo "^c$black^^b$yellow_light^ 󰖀 ^d^^c$black_dark^^b$yellow^ ${get_volume}% ^d^" ;;
            [0-9]|1[0-9]|2[0-9]|3[0-3])
                echo "^c$black^^b$yellow_light^ 󰕿 ^d^^c$black_dark^^b$yellow^ ${get_volume}% ^d^" ;;
        esac
    fi
}

echo $(get_sound_info)