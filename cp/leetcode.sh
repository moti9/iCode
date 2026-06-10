#!/bin/bash

input="$1"
ext="${2:-cpp}"

number=$(echo "$input" | sed -E 's/^([0-9]+).*/\1/')
title=$(echo "$input" | sed -E 's/^[0-9]+\.?[[:space:]]*//')

filename="${number}_$(echo "$title" \
    | tr '[:upper:]' '[:lower:]' \
    | sed 's/[^a-zA-Z0-9]/_/g' \
    | sed 's/_\+/_/g' \
    | sed 's/^_//;s/_$//').${ext}"

touch "$filename"

# Open in current VS Code window
code -r "$filename"

echo "Created: $filename"