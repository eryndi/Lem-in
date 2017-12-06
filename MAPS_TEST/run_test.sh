#!/bin/bash

for map in `find map -mindepth 1 -name "*$1*"`
do
    echo "+-+-+ Map $map +-+-+"
    ./lem-in < $map
done
