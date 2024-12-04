#!/bin/bash

echo -n "$(id -Gn $FT_USER | tr ' ' ',')"

