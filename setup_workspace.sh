#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
PROJECT_ROOT="${SCRIPT_DIR}"
export PROJECT_ROOT

export PATH="$PATH:$PROJECT_ROOT/scripts"

if [ -f "${SCRIPT_DIR}/Makefile" ]; then
    export MAKEFILE_DIR="${PROJECT_ROOT}"
else
    echo "Error: Makefile not found in ${SCRIPT_DIR}"
    exit 1
fi