#!/bin/sh
curl -s $1 | cut -d' ' -f2 | cut -d'"' -f2 | grep http