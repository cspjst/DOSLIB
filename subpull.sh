#!/bin/bash
set -e

echo "Updating all submodules recursively..."
git submodule update --remote --recursive --merge

echo "Staging changes..."
git add bioslib

echo "Committing..."
git commit -m "Sync submodules to latest"
