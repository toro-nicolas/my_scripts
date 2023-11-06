#!/bin/bash

find -name "*~" -delete         \
  -o -name "#*#" -delete        \
  -o -name "*.o" -delete        \
  -o -name "*.gcno" -delete     \
  -o -name "*.gcov" -delete     \
  -o -name "*.gcda" -delete     \
  -o -name "vgcore*" -delete    \
  -o -name "*.log" -delete      \
