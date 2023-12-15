#!/bin/bash

# Vérification des paramètres
if [ "$#" -lt 5 ]; then
  echo "Usage: $0 <github-repo-link> <semester-number> <module-name> <project-folder-name> <executable-name> [<library1> <library2> ...]"
  exit 84
fi

# Vérification du numéro de semestre
semester_number=$2
if ! [[ "$semester_number" =~ ^[0-9]+$ ]] || [ "$semester_number" -lt 0 ] || [ "$semester_number" -gt 10 ]; then
  echo "Le numéro du semestre doit être un nombre entre 0 et 10."
  exit 84
fi

git_link=$1
module_name=$3
folder_name=$4
executable_name=$5

# Vérification des noms de librairies
lib_folder="/home/nicolastoro/my_scripts/template/lib"
shift 5
for lib in "$@"; do
  if [ ! -d "$lib_folder/$lib" ]; then
    echo "La librairie '$lib' n'existe pas dans le dossier de référence."
    exit 84
  fi
done

# Création du chemin du projet
project_path="/home/nicolastoro/Epitech/Tech1/Semester-$semester_number/$module_name/$folder_name"
template_path="/home/nicolastoro/my_scripts/template"

# Vérification si le dossier du projet existe déjà
if [ -d "$project_path" ]; then
  echo "Le dossier du projet '$project_path' existe déjà."
  read -p "Voulez-vous le supprimer et continuer? (y/n): " answer
  if [ "$answer" != "y" ]; then
    exit 1
  else
    # Suppression du dossier existant
    rm -rf "$project_path"
  fi
fi

# Création du dossier du projet
mkdir -p "$project_path"
echo "Dossier du projet créé : $project_path"
cd "$project_path" || exit 84

# Clone du dépôt GitHub
git clone "$git_link" "$project_path" > /dev/null 2>&1
echo "Repository cloné : $git_link"

# Copie des fichiers et dossiers de template, en excluant le dossier lib
find "$template_path" \
  -mindepth 1 \
  -maxdepth 1 \
  \( -name build -o -name lib -o -name include -o -name .idea -o -name .vscode \) -prune \
  -o -exec cp -r {} "$project_path" \;

# Ajout des dossiers de librairies
mkdir "$project_path/lib"
for lib in "$@"; do
  cp -r "$lib_folder/$lib" lib/
done

# Modification des fichiers du projet
sed -i "s/\[project-exec\]/$executable_name/g" Makefile
sed -i "s/\[project-name\]/$folder_name/g" Makefile src/main.c

# Création des includes
mkdir "$project_path/include"

echo "Projet créé avec succès !"
exit 0
