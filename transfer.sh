#!/bin/sh
# Transfer a satisfactory build: bin/DOS.lib -> lib/, src/DOS/*.h -> include/DOS/
set -e
cd "$(dirname "$0")"

LIB=bin/DOS.lib

if [ ! -f "$LIB" ]; then
    echo "transfer: $LIB not found - build first (./cmk.sh && ./bld.sh in src)" >&2
    exit 1
fi

mkdir -p lib include/DOS

cp "$LIB" lib/

# clear old headers so ones deleted from src/DOS don't linger
rm -f include/DOS/*.h
cp src/DOS/*.h include/DOS/

echo "transferred: lib/DOS.lib + $(ls include/DOS/*.h | wc -l | tr -d ' ') headers -> include/DOS/"
