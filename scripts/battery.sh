#!/bin/bash

# load colors
. ~/.ui/dwm/scripts/themes/skynox.sh

get_battery_info() {
	AC_online=$(cat /sys/class/power_supply/AC/online)
	battery_capacity=$(cat /sys/class/power_supply/BAT0/capacity)

	if [[ $AC_online -eq 1 ]]; then
		case $battery_capacity in
			100)
				echo "^c$black^^b$green^ 󰂄 ^d^^c$black_dark^^b$green_dark^ ${battery_capacity}% ^d^" ;;
			9[0-9])
				echo "^c$black^^b$green^ 󰂋 ^d^^c$black_dark^^b$green_dark^ ${battery_capacity}% ^d^" ;;
			8[0-9])
				echo "^c$black^^b$green^ 󰂊 ^d^^c$black_dark^^b$green_dark^ ${battery_capacity}% ^d^" ;;
			7[0-9])
				echo "^c$black^^b$green^ 󰢞 ^d^^c$black_dark^^b$green_dark^ ${battery_capacity}% ^d^" ;;
			6[0-9])
				echo "^c$black^^b$green^ 󰂉 ^d^^c$black_dark^^b$green_dark^ ${battery_capacity}% ^d^" ;;
			5[0-9])
				echo "^c$black^^b$green^ 󰢝 ^d^^c$black_dark^^b$green_dark^ ${battery_capacity}% ^d^" ;;
			4[0-9])
				echo "^c$black^^b$green^ 󰂈 ^d^^c$black_dark^^b$green_dark^ ${battery_capacity}% ^d^" ;;
			3[0-9])
				echo "^c$black^^b$green^ 󰂇 ^d^^c$black_dark^^b$green_dark^ ${battery_capacity}% ^d^" ;;
			2[0-9])
				echo "^c$black^^b$red_dark^ 󰂆 ^d^^c$black_dark^^b$red^ ${battery_capacity}% ^d^" ;;
			1[0-9])
				echo "^c$black^^b$red_dark^ 󰢜 ^d^^c$black_dark^^b$red^ ${battery_capacity}% ^d^" ;;
			*)
				echo "^c$black^^b$red_dark^ 󰢟 ^d^^c$black_dark^^b$red^ ${battery_capacity}% ^d^" ;;
		esac
	else
		case $battery_capacity in
			100)
				echo "^c$black^^b$green^ 󰁹 ^d^^c$black_dark^^b$green_dark^ ${battery_capacity}% ^d^" ;;
			9[0-9])
				echo "^c$black^^b$green^ 󰂂 ^d^^c$black_dark^^b$green_dark^ ${battery_capacity}% ^d^" ;;
			8[0-9])
				echo "^c$black^^b$green^ 󰂁 ^d^^c$black_dark^^b$green_dark^ ${battery_capacity}% ^d^" ;;
			7[0-9])
				echo "^c$black^^b$green^ 󰂀 ^d^^c$black_dark^^b$green_dark^ ${battery_capacity}% ^d^" ;;
			6[0-9])
				echo "^c$black^^b$green^ 󰁿 ^d^^c$black_dark^^b$green_dark^ ${battery_capacity}% ^d^" ;;
			5[0-9])
				echo "^c$black^^b$green^ 󰁾 ^d^^c$black_dark^^b$green_dark^ ${battery_capacity}% ^d^" ;;
			4[0-9])
				echo "^c$black^^b$green^ 󰁽 ^d^^c$black_dark^^b$green_dark^ ${battery_capacity}% ^d^" ;;
			3[0-9])
				echo "^c$black^^b$green^ 󰁼 ^d^^c$black_dark^^b$green_dark^ ${battery_capacity}% ^d^" ;;
			2[0-9])
				echo "^c$black^^b$red_dark^ 󰁻 ^d^^c$black_dark^^b$red^ ${battery_capacity}% ^d^" ;;
			1[0-9])
				echo "^c$black^^b$red_dark^ 󰁺 ^d^^c$black_dark^^b$red^ ${battery_capacity}% ^d^" ;;
			*)
				echo "^c$black^^b$red_dark^ 󱃍 ^d^^c$black_dark^^b$red^ ${battery_capacity}% ^d^" ;;
		esac
	fi
}

echo $(get_battery_info)
