#!/bin/bash

# Parcours récursif des fichiers .c dans le dossier actuel et ses sous-dossiers
find src -type f -name '*.c' | while read -r file; do
    # Récupère le nom du fichier sans le chemin
    filename=$(basename "$file")
     
    # Vérifie si le fichier est déjà présent dans la liste des SRCS
    grep -q "SRCS[[:space:]]\{1,\}+=[[:space:]]*$filename" Makefile
    
    # Si le fichier n'est pas présent, ajoute une ligne
    if [ $? -ne 0 ]; then
        sed -i '/^SRCS\t\t+=\tmain.c/a\SRCS||+=|.c\' Makefile
        echo "You need to add $filename"
    fi
done

# Remplace les occurrences de "\t" par des vraies tabulations
sed -i 's/|/\t/g' Makefile
