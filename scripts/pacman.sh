#!/bin/bash

# load colors
. ~/.ui/dwm/scripts/themes/skynox.sh

get_pacman_info() {
    update_count=$(checkupdates | wc -l)
    
    if [[ $update_count -ne 0 ]]; then
        echo "^c$green^ 󰳛 $update_count updates^d^"
    else
        echo "^c$green^ 󰗠 Fully updated^d^"
    fi
}

echo $(get_pacman_info)