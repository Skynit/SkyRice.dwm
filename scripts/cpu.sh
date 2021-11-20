#!/bin/bash

# load colors
. ~/.ui/dwm/scripts/themes/skynox.sh

get_cpu_info() {
	load_avg_15=$(cat /proc/loadavg | awk '{print $3}')
	core_count=$(nproc --all)
	
	echo "^c$black^^b$purple_light^ 󰍛 ^d^^c$grey_dark^^b$purple_dark^ $(echo "scale=1; ($load_avg_15*100)/$core_count" | bc)% ^d^"
}

echo $(get_cpu_info)
