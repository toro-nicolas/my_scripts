#!/bin/bash

# Vérifier si au moins un argument est passé
if [ "$#" -eq 0 ]; then
    echo "Usage: $0 fichier1 fichier2 ..."
    exit 1
fi

# Boucle sur chaque argument
for file in "$@"; do
    # Rechercher le fichier depuis la racine
    results=$(find / -type f -name "$file" 2>/dev/null)
    
    if [ -n "$results" ]; then
        echo -e "\e[1m$file\e[0m:"  # Texte en gras
        echo "$results"
    else
        echo -e "\e[31m$file introuvable !\e[0m"  # Texte en rouge
    fi
    echo  # Ligne vide pour séparer les résultats
done

