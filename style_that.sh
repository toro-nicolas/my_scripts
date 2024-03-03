#!/bin/bash

make fclean
coding-style . .
#cat coding-style-reports.log | grep -v ":C-O1" | grep -v ": illegal token"
grep -vE "(:C-O1|: illegal token)" coding-style-reports.log
rm -rf coding-style-reports.log
