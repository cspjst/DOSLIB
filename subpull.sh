#!/bin/bash
set -e
git submodule update --remote --recursive --merge
git add bioslib
git commit -m "Sync submodules to latest"
