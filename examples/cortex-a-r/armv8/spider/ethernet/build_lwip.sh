#!/usr/bin/env bash

#stop on errors
set -e

function remove_items() {
	ITEMS="$1"

	for ITEM in $ITEMS; do
		if [ $(ls $ITEM 2>/dev/null) ]; then
			echo "Removing $ITEM"
			rm $ITEM
		fi
	done
}

# Remove old libraries that will be replaced with the new build
remove_items "liblwipallapps.a liblwipcore.a liblwipmbedtls.a"

# Move to LwIP folder and create the build folder
cd lwip

if [[ -d "build" ]]; then
	echo "Removing LwIP build folder"
	rm -r build
fi

mkdir build
cd build

cmake -DCMAKE_TOOLCHAIN_FILE:PATH="../../lwip-port/toolchain.cmake" ..

# Build only required libraries (no example)
make -j lwipcore lwipallapps lwipmbedtls

echo "Copying LwIP static libraries to local folder"
cp liblwipcore.a ../..
cp liblwipallapps.a ../..
cp liblwipmbedtls.a ../..
