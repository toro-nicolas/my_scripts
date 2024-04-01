#!/bin/bash

if [ $# -eq 0 ]; then
    ssh-add -l
elif [ $1 -eq 0 ]; then
    eval "$(ssh-agent -s)"
    ssh-add ~/.ssh/id_ed25519
    echo "Ajout de la clé du compte github EPITECH"
elif [ $1 -eq 1 ]; then
    eval "$(ssh-agent -s)"
    ssh-add ~/.ssh/id_rsa
    echo "Ajout de la clé du compte github perso (nt-games-ytb)"
elif [ $1 -eq 2 ]; then
    eval "$(ssh-agent -s)"
    ssh-add ~/.ssh/id_ed25519
    ssh-add ~/.ssh/id_rsa
    echo "Ajout des deux clés"
else
    echo "Aucune action définie pour l'argument fourni."
    echo "Utilisation : set_ssh.sh [0|1|2]"
fi
