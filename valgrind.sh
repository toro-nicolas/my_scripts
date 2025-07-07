#!/bin/bash

# Vérifier s'il y a au moins un argument
if [ $# -lt 1 ]; then
    echo "Usage: $0 <fichier> [arguments...]"
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

# Exécuter la commande valgrind avec tous les arguments
valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./"$@"
