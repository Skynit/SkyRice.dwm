#!/bin/bash

# load colors
. ~/.ui/dwm/scripts/themes/skynox.sh

get_network_info() {
    wlan0=$(cat /sys/class/net/wlan0/operstate)
    wlan0_signal=$(cat /proc/net/wireless | awk '$1~/wlan0/ {print $3}' | cut -d. -f1)
    enp0s31f6=$(cat /sys/class/net/enp0s31f6/operstate)

    if [[ $enp0s31f6 == "up" ]]; then
        echo "^c$black^^b$blue_sec_light^ 󰲝 ^d^"
    else
        if [[ $wlan0 == "up" ]]; then
            case $wlan0_signal in
                7[5-9]|8[0-9]|9[0-9]|100)
                    echo "^c$blacl^^b$blue_sec_light^ 󰤨 ^d^" ;;
                5[0-9]|6[0-9]|7[0-4])
                    echo "^c$black^^b$blue_sec_light^ 󰤥 ^d^" ;;
                2[5-9]|3[0-9]|4[0-9])
                    echo "^c$black^^b$blue_sec_light^ 󰤢 ^d^" ;;
                [0-9]|1[0-9]|2[0-4])
                    echo "^c$black^^b$blue_sec_light^ 󰤟 ^d^" ;;
            esac
        else
            echo "^c$black^^b$blue_sec_light^ 󰖪 ^d^"
        fi
    fi
}

echo $(get_network_info)
