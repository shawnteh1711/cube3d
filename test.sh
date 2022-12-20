#!/bin/bash

RED=$'\033[0;31m'
GREEN=$'\033[0;32m'
MAGENTA=$'\033[1;35m'
CYAN=$'\033[1;36m'
NC=$'\033[0m'

PROG="./cub3d"
INVALID_FILES=(\
	"no_content.cub" \
	"no_identifier_only.cub" \
	"no_color.cub" \
	"no_map.cub" \
	"invalid_texture_path.cub" \
	"invalid_color_format.cub" \
	"invalid_color_format2.cub" \
	".cub" \
	"test"
)

INVALID_MAPS=(
	"invalid_character.cub" \
	"multiple_player.cub" \
	"no_enclosed.cub" \
	"no_player.cub"
)

exe() {
	echo ${RED}"${PROG} $@"${NC} ${MAGENTA}; ${PROG} $@ ;
}

exe2() {
	echo ${RED}"${PROG} $@"${NC} ${CYAN}; ${PROG} $@ ;
}

if [ "$1" = "" ]; then
	echo ${GREEN}"============= Test Invalid File ==========="
	for str in ${INVALID_FILES[@]}; do
		exe ./maps/${str}
		# echo ${GREEN}$?
		if [ $? -ne 0 ]; then
			echo "${RED}Error\n Invalid file for $1" >&2
			exit 1
		fi
	done
	echo ${GREEN}"============= Test Map ===================="
	for map in ${INVALID_MAPS[@]}; do
		exe2 ./maps/${map}
		if [ $? -ne 0 ]; then
			echo "${RED}Error\n Invalid map for $1" >&2
			exit 1
		fi
	done
elif [ "$1" = "default" ]; then
	exe ./maps/default.cub
fi