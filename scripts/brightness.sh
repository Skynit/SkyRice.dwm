#!/bin/bash

# load colors
. ~/.ui/dwm/scripts/themes/skynox.sh

get_brightness_info() {
    max_brightness=$(cat /sys/class/backlight/intel_backlight/max_brightness)
    act_brightness=$(cat /sys/class/backlight/intel_backlight/brightness)
    # mdi-circle-slice

    case $(echo "scale=0; ($act_brightness*100)/$max_brightness" | bc) in 
        100)
            echo "^c$black^^b$orange^ 󰪥 ^d^" ;;
        8[6-9]|9[0-9])
            echo "^c$black^^b$orange^ 󰪤 ^d^" ;;
        7[4-9]|8[0-5])
            echo "^c$black^^b$orange^ 󰪣 ^d^" ;;
        6[1-9]|7[0-3])
            echo "^c$black^^b$orange^ 󰪢 ^d^" ;;
        5[0-9]|60)
            echo "^c$black^^b$orange^ 󰪡 ^d^" ;;
        3[7-9]|4[0-9])
            echo "^c$black^^b$orange^ 󰪠 ^d^" ;;
        2[4-9]|3[0-6])
            echo "^c$black^^b$orange^ 󰪟 ^d^" ;;
        1[2-9]|2[0-3])
            echo "^c$black^^b$orange^ 󰪞 ^d^" ;;
        *)
            echo "^c$black^^b$orange^ 󰝦 ^d^" ;;         
    esac
}

echo $(get_brightness_info)
