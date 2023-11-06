#!/bin/bash

cat Day02/passwd | sed -e "s/theo1/Wile E. Coyote/" | sed -e "s/steven1/Daffy Duck/" | sed -e "s/arnaud1/Porky Pig/" | sed -e "s/pierre-jean/Marvin the Martian/" | grep -E "Wile E. Coyote|Daffy Duck|Porky Pig|Marvin the Martian"


