#!/bin/bash

if [[ -z "$PROJECT_ROOT" || -z "$MAKEFILE_DIR" ]]; then
    echo "Error: No workspace environment to clean up. Did you run 'setup_workspace.sh'?"
    exit 1
fi

export PATH=$(echo "$PATH" | sed "s|:$PROJECT_ROOT/scripts||g")

unset PROJECT_ROOT
unset MAKEFILE_DIR

echo "Workspace environment cleaned up."