#!/bin/bash

# Vérifier s'il y a un argument
if [ $# -ne 1 ]; then
    echo "Usage: $0 <fichier>"
    exit 1
fi

fichier=$1

# Vérifier si le fichier existe
if [ ! -f "$fichier" ]; then
    echo "Le fichier $fichier n'existe pas."
    exit 1
fi

# Vérifier si le fichier est exécutable
if [ ! -x "$fichier" ]; then
    echo "Le fichier $fichier n'est pas exécutable."
    exit 1
fi

# Exécuter la commande valgrind
valgrind -s --leak-check=full --show-leak-kinds=all ./"$fichier"
