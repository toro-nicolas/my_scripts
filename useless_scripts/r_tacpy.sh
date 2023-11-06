#!/bin/bash

cut -d: -f 1 | #On garde que la 1ère colone
    rev | #On retourne chaque mot
    sed -n "n;p" | #On enlève 1 sur 2 mots
    sort -r | #On tri la la colone de mot dans l'ordre inverse
    sed -n "${MY_LINE1},${MY_LINE2}p" | #On séléctionne l'endroit qu'on a choisi d'étudier
    tr "\n" "," | #On remplace chaques saut de lines par des virugles
    sed "s/,$/./g" | #On modifie le point finale
    sed "s/,/, /g" #On met l'espace apès chaque virgules
