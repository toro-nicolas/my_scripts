#!/bin/bash

# Colors for the output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RESET='\033[0m'
BOLD='\033[1m'

# Function to ask a yes/no question
ask_yes_no() {
    while true; do
        read -p "$1 (yes/no): " yn
        case $yn in
            [Yy]* ) return 0;;
            [Nn]* ) return 1;;
            * ) echo -e "${RED}Answer with yes or no.${RESET}";;
        esac
    done
}

# Function to ask a number between 1 and 10
ask_number_between_1_and_10() {
    while true; do
        read -p "`echo -e "$1 (1-10): "`" number
        if [[ "$number" =~ ^[1-9]$|^10$ ]]; then
            return 0
        else
            echo -e "${RED}Please enter a number between 1 and 10.${RESET}"
        fi
    done
}

# Function to ask a question with a required answer
ask_with_required_answer() {
    while true; do
        read -p "`echo -e "$1"`" response
        if [ -n "$response" ]; then
            break
        else
            echo -e "${RED}Please enter a valid answer.${RESET}"
        fi
    done
}

# Function to list the libraries
list_dirs_with_selected() {
    local selected_libs=("$@")
    local output=""
    for entry in "$libs_path"/*; do
        if [ -d "$entry" ]; then
            local dir_name=$(basename "$entry")
            if [[ " ${selected_libs[@]} " =~ " $dir_name " ]]; then
                output+=" ${GREEN}$dir_name${RESET}"
            else
                output+=" $dir_name"
            fi
        fi
    done
    echo -e "$output"
}

# Init mkproject script
echo -e "${BOLD}${YELLOW}Init mkproject script...${RESET}"
if [ ! -d "my_libs" ];then
    git clone git@github.com:toro-nicolas/my_libs.git
else
    cd my_libs && git pull
    cd ..
fi
if [ ! -d "my_templates" ];then
    git clone git@github.com:toro-nicolas/my_templates.git
else
    cd my_templates && git pull
    cd ..
fi

# Create the project
echo -e "${BOLD}${GREEN}Welcome to mkproject !\nLet's create a new project !${RESET}"

# Get the project path
project_path="./"
if ask_yes_no "Do you want to link this project to Epitech"; then
    ask_number_between_1_and_10 "Please specify the ${BOLD}semester number${RESET}"
    semester=$number
    tech=$(( (note_programmation / 2 ) + 1 ))
    tmp_path="$HOME/Epitech/Tech$tech/Semester-$semester/"
    echo -e "Please specify the ${BOLD}module name${RESET} :"
    directories="Existing module: "
    for entry in "$tmp_path"/*; do
        if [ -d "$entry" ]; then
            directories+="$(basename "$entry") "
        fi
    done
    echo "$directories"
    read module
    tmp_path+="$module/"
    project_path="$tmp_path"
fi

# Get project information
ask_with_required_answer "Please specify the ${BOLD}project folder name${RESET}: "
folder_name=$response
project_path+="$folder_name"
ask_with_required_answer "Please specify the ${BOLD}executable name${RESET}: "
executable_name=$response

# Get project language
available_languages="available languages:"
for entry in my_templates/*; do
    if [ -d "$entry" ]; then
        available_languages+=" "
        available_languages+="$(basename "$entry")"
    fi
done
while true; do
    read -p "`echo -e "Please specify the ${BOLD}language${RESET} of the project ($available_languages): "`" language
    if [ -d "my_templates/$language" ]; then
        break
    else
        echo -e "${RED}Please enter a valid language.${RESET}"
    fi
done

# Get project libraries
selected_libs=()
if ask_yes_no "Do you want to add libraries to the project"; then
    libs_path="my_libs/$language/"
    available_version="available version:"
    for entry in my_libs/"$language"/*; do
        if [ -d "$entry" ]; then
            available_version+=" "
            available_version+="$(basename "$entry")"
        fi
    done
    while true; do
        read -p "`echo -e "Please specify the ${BOLD}version${RESET} of the libraries ($available_version): "`" version
        if [ -d "my_libs/$language/$version" ]; then
            break
        else
            echo -e "${RED}Please enter a valid version.${RESET}"
        fi
    done
    libs_path="my_libs/$language/$version"
    while true; do
        echo -ne "\rAvailable libraries:"
        list_dirs_with_selected "${selected_libs[@]}"
        echo -ne "Add a library (leave empty to finish): "
        read lib_name
        if [ -z "$lib_name" ]; then
            break
        fi
        if [ -d "$libs_path/$lib_name" ]; then
            if [[ ! " ${selected_libs[@]} " =~ " $lib_name " ]]; then
                selected_libs+=("$lib_name")
            else
                echo -e "${RED}The library '$lib_name' is already selected.${RESET}"
            fi
        else
            echo -e "${RED}The library '$lib_name' does not exist.${RESET}"
        fi
    done
fi

# Get the git link
read -p "`echo -e "If you wish to link this project to a ${BOLD}github repository${RESET}, please specify the ${BOLD}link${RESET}: "`" git_link

# Check the project path
if [ -d "$project_path" ]; then
    if ask_yes_no "The project folder already exists. Do you want to delete it and continue"; then
        rm -rf "$project_path"
    else
        exit 1
    fi
fi

# Create the project folder
mkdir -p "$project_path"
echo -e "Project folder created: $project_path"
if [[ $git_link ]]; then
    git clone "$git_link" "$project_path" > /dev/null 2>&1
    echo "Repository cloned: $git_link"
fi
rsync -a --quiet "my_templates/$language/" "$project_path/"
for lib in "${selected_libs[@]}"; do
    rsync -a --quiet "my_libs/$language/$version/$lib" "$project_path/lib/"
done
cd $project_path
./"$language" "$executable_name" "$folder_name" "${selected_libs[@]}"
rm -rf "$language"
echo -e "${BOLD}${GREEN}Project created successfully !${RESET}"
