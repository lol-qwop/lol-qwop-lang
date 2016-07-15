#!/usr/bin/env bash
# takes one arg, the file to operate on.

IFS='\n'
while read -r line; do
    lastChar="${line: -1}"
    firstChar="${line:0:1}"

    [[ "$lastChar" = "l" ]] && echo -n '>' && continue
    [[ "$lastChar" = "p" ]] && ([[ "$firstChar" = "l" ]] && echo -n $line || echo -n '.') && continue

    eval "echo $lastChar | tr '.!?' $([[ "$firstChar" = "l" ]] && echo "'<+-'" || echo "',[]'") | tr -d '\n'"
done <<< $(grep -oE '(lol(-qwop)?|qwop)[.!?]?' "$1")
