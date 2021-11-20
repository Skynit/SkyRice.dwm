#!/bin/bash

# load colors
. ~/.ui/dwm/scripts/themes/skynox.sh

get_date_info() {
    get_date_format=$(date +"%a %b %d %Y %I:%M %p")

    echo "^c$black^^b$blue_light^ 󱑆 ^d^^c$black_dark^^b$blue^ $get_date_format ^d^"
}

echo $(get_date_info)
