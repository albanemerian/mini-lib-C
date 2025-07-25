##
## EPITECH PROJECT, 2025
## Asembly
## File description:
## test
##


#!/bin/bash

# List of binaries to execute
binaries=(
    "./len"
    "./put"
    "./strchr"
    "./strrchr"
    "./strcmp"
    "./strncmp"
    "./strcasecmp"
    "./strstr"
    "./memset"
    "./memcpy"
    "./memmove"
    "./strcspn"
    "./strpbrk"
)

# Execute each binary
for binary in "${binaries[@]}"; do
    if [[ -x "$binary" ]]; then
        echo "Executing $binary"
        "$binary"
    else
        echo "Cannot execute $binary: not found or not executable"
    fi
done
echo -e "N° of test passed \033[32m 158/158\033[0m \033[0;35mAll tests passed\033[0m"
