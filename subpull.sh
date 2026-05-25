#!/bin/bash
set -e
git -C bioslib checkout main
git submodule update --remote --merge
git add bioslib
git commit -m "Sync BIOSLIB to latest" || echo "Already up to date"
