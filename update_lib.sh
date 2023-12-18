#!/bin/bash

# Fonction pour afficher un message d'erreur et quitter avec le code de sortie 84
exit_with_error() {
    echo "Erreur: $1"
    exit 84
}

# Fonction pour afficher un message d'erreur et quitter avec le code de sortie 1
handle_error() {
    local error_message="$1"
    echo "Erreur: $error_message"
    exit 1
}

# Vérifier que le nombre d'arguments est au moins 1
if [ $# -lt 1 ]; then
    exit_with_error "Au moins un nom de lib doit être fourni en argument"
fi

# Suppresion des .o
rm -rf lib/*.o

# Parcourir tous les arguments
for lib_name in "$@"; do
    # Vérifier si le dossier de la lib existe dans le dossier template
    template_lib_path="/home/nicolastoro/my_scripts/template/lib/$lib_name"
    if [ ! -d "$template_lib_path" ]; then
        exit_with_error "La librairie '$lib_name' n'existe pas dans le dossier de template"
    fi

    # Vérifier si le dossier de la lib existe dans le dossier courant
    current_lib_path="./lib/$lib_name"
    if [ ! -d "$current_lib_path" ]; then
        # Si la librairie n'existe pas dans le dossier courant, la copier depuis le dossier de template
        cp -r "$template_lib_path" "./lib/"
        echo "Librairie '$lib_name' copiée depuis le dossier de template"
    else
        # Comparer les fichiers et mettre à jour si nécessaire
        diff -r --exclude='*.o' "$template_lib_path" "$current_lib_path" > /dev/null 2>&1
        if [ $? -eq 0 ]; then
            echo "Librairie '$lib_name' est déjà à jour"
        else
            # S'il y a des différences, remplacer les fichiers (en excluant les fichiers .o)
            rsync -r --exclude='*.o' "$template_lib_path"/* "$current_lib_path/" > /dev/null 2>&1
            echo "Librairie '$lib_name' mise à jour"
            #echo "Fichiers modifiés :"
            #echo "$diff_output"
        fi
    fi
done

# Mettre à jour les .a
make libs > /dev/null 2>&1 || handle_error "Impossible de mettre à jour les libs avec \"make libs\""
echo "Les librairies ont été mises à jour avec succès !"

# Sortie avec code 0 (pas d'erreur)
exit 0
