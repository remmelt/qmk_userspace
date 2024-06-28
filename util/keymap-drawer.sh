#! /usr/bin/env bash

set -Eeuo pipefail

keymap=remmelt
keyboard=preonic/rev3_drop
output=remmelt-preonic

docker build -t keymap util
rm -rf output
mkdir -p output
qmk c2json -km "${keymap}" -kb "${keyboard}" --output output/"${output}".json --no-cpp
docker run --volume "$(PWD)/output:/work" keymap keymap parse --qmk-keymap-json /work/"${output}".json --output /work/"${output}".yaml
docker run --volume "$(PWD)/output:/work" keymap keymap draw /work/"${output}".yaml --output /work/"${output}".svg
mv output/"${output}".svg .
