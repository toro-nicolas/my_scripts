#!/bin/bash

coding-style . .
cat coding-style-reports.log | grep -v ":C-O1" | grep -v ": illegal token"
