#!/bin/bash

# Commented commands are those that no longer work or do not work

dnf_commands=(
    "gcc"
    "code"
    "CSFML*"
    "terminus-fonts-console"
    "docker-ce docker-ce-cli containerd.io"
    "pacman"
    "thunar"
    "valgrind"
    "curl git cmake net-tools gcc g++ clang"
    "gdb"
    "perf"
    "libpng"
    "nodejs"
    "gcovr"
    "xbindkeys xvkbd"
    "apt"
    "xdotool"
    "xautomation"
    "git-lfs"
    "git-filter-repo"
    "akmod-VirtualBox kernel-devel-$(uname -r)"
    "make time perl gcc dkms kernel-devel kernel-headers"
    "unrar"
    "touchegg"
    "fedora-workstation-repositories"
    "rpmfusion-free-release-tainted"
    "rpmfusion-nonfree-release-tainted"
    "dnf-utils"
    "fedy -y"
    "redhat-lsb-core anydesk"
    "php"
    "phpmyadmin"
    "nodejs"
    "npm"
    "links"
    "vim"
    "nodejs npm"
    "SDL2 SDL2-devel SDL2_ttf SDL2_ttf-devel SFML SFML-devel ncurses ncurses-devel"
    "SDL2 SDL2-devel SDL2_ttf SDL2_ttf-devel SFML SFML-devel ncurses ncurses-devel"
    "snapd"
    "kernel-modules"
    "fuse squashfuse"
    "clang cmake cubeb-devel freeglut-devel git glm-devel gtk3-devel kernel-headers libgcrypt-devel libsecret-devel libtool libusb1-devel nasm ninja-build perl-core systemd-devel zlib-devel"
    "apt"
    "Cemu"
    "gnuplot"
    "https://download.postgresql.org/pub/repos/yum/reporpms/F-38-x86_64/pgdg-fedora-repo-latest.noarch.rpm"
    "postgresql16-server"
    "doxygen"
    "doxygen-doxywizard"
    "php"
    "phpmyadmin"
    "openvpn"
)

yum_commands=(
    "php-gd"
    "gd-devel"
    "ruby"
    "curl git cmake net-tools gcc g++ clang"
)

npm_commands=(
    "dotenv --save"
)

apt_commands=(
    "phpmyadmin"
    "xautomation"
    "--install-recommends winehq-stable"
    "kali-linux-everything"
    "curl"
)

snap_commands=(
    "install flutter --classic"
)

pip_commands=(
    "gcovr"
    "--user git-filter-repo"
    "scipy"
    "matplotlib"
    "scipy"
    "numpy"
)

pacman_commands=(
    "wii-dev"
    "dkp-libs"
    "wiiu-dev"
    "ppc-lgd"
    "ppc-zlib ppc-libmad ppc-libogg ppc-libgd ppc-freetype ppc-libjpeg-turbo ppc-libpng ppc-libvorbisidec ppc-glm ppc-bzip2"
)

hidden_commands=(
    "dnf install docker"
    "dnf install software-properties-common gdebi gdebi-kde gdeby-core aptitude build-essential bfg bfg-repo-cleaner brew xdg xbindkeys-config p10k rar winrar \*-firmware laravel snap flutter apt-add apt-add-repository lib32z1 lib32ncurses5 lib32bz2-1.0 nanolib yay wordlists kali-linux-everything metasploit"
    "yum install libsfml-dev"
)



# Fonction pour afficher l'usage
usage()
{
    echo "Usage: $0 [OPTIONS]"
    echo "Options:"
    echo "  -h, --help        Afficher l'usage"
    echo "  -y, --yes         Installer les packages sans confirmation"
    echo "  -n, --name        Vérifier l'existence d'un package et l'installer"
    echo "  -a, --all         Installer tous les packages, y compris les cachés"
    exit 1
}

# Fonction pour installer les packages
install_packages()
{
    echo -e "\e[32mInstallation des packages...\e[0m"
    if [ "$YES" = true ]; then
        for cmd in "${dnf_commands[@]}"; do
            sudo dnf install -y $cmd
        done
        for cmd in "${yum_commands[@]}"; do
            sudo yum install -y $cmd
        done
        for cmd in "${npm_commands[@]}"; do
            sudo npm install -g $cmd
        done
        #for cmd in "${apt_commands[@]}"; do
        #    sudo apt install -y $cmd
        #done
        for cmd in "${snap_commands[@]}"; do
            sudo snap install $cmd
        done
        for cmd in "${pip_commands[@]}"; do
            sudo pip install $cmd
        done
        for cmd in "${pacman_commands[@]}"; do
            sudo pacman -S $cmd --noconfirm
        done
    else
        for cmd in "${dnf_commands[@]}"; do
            sudo dnf install $cmd
        done
        for cmd in "${yum_commands[@]}"; do
            sudo yum install $cmd
        done
        for cmd in "${npm_commands[@]}"; do
            sudo npm install -g $cmd
        done
        #for cmd in "${apt_commands[@]}"; do
        #    sudo apt install $cmd
        #done
        for cmd in "${snap_commands[@]}"; do
            sudo snap install $cmd
        done
        for cmd in "${pip_commands[@]}"; do
            sudo pip install $cmd
        done
        for cmd in "${pacman_commands[@]}"; do
            sudo pacman -S $cmd
        done
    fi
    if [ "$ALL" = true ]; then
        for cmd in "${hidden_commands[@]}"; do
            sudo $cmd
        done
        for cmd in "${apt_commands[@]}"; do
            sudo apt install -y $cmd
        done
    fi
    sudo dnf update
}

# Fonction pour vérifier et installer un package
check_and_install_package() {
    local package="$1"
    local package_installers=()

    echo "Vérification de l'existence du package $package..."

    if sudo dnf info $package &> /dev/null; then
        package_installers+=("dnf")
    fi

    if sudo yum info $package &> /dev/null; then
        package_installers+=("yum")
    fi

    if npm list -g --depth=0 | grep -q "$package"; then
        package_installers+=("npm")
    fi

    if apt show $package &> /dev/null; then
        package_installers+=("apt")
    fi

    #if snap list | grep -q "$package"; then
    #    package_installers+=("snap")
    #fi

    pip_command="python -m pip_search $package"
    pip_output=$(eval $pip_command)
    pip_output_length=$(echo -n "$pip_output" | wc -m)
    if [ $pip_output_length -gt 327 ]; then
        package_installers+=("pip")
    fi

    if pacman -Ss $package &> /dev/null; then
        package_installers+=("pacman")
    fi

    if [ ${#package_installers[@]} -eq 0 ]; then
        echo -e "\e[31mLe package $package n'existe pas\e[0m"
    else
        echo -e "\e[32mLe package $package existe\e[0m"
        echo "Installateurs disponibles : ${package_installers[@]}"
        for installer in "${package_installers[@]}"; do
            echo "Installation avec $installer..."
            case $installer in
                "dnf")
                sudo dnf install $package
                ;;
                "yum")
                sudo yum install $package
                ;;
                "npm")
                sudo npm install -g $package
                ;;
                "apt")
                sudo apt install $package
                ;;
                "snap")
                sudo snap install $package
                ;;
                "pip")
                pip install $package
                ;;
                "pacman")
                sudo pacman -S $package --noconfirm
                ;;
                *)
                echo "Installer non supporté: $installer"
                ;;
            esac
        done
    fi
}



# Vérifier les arguments de ligne de commande
YES=false
ALL=false
NAME=false

# Vérifier si aucun argument n'est fourni ou seulement l'option -y
if [ $# -eq 0 ] || ([ $# -eq 1 ] && [ "$1" = "-y" ] || [ "$1" = "--yes" ]); then
    if [ "$1" = "-y" ] || [ "$1" = "--yes" ]; then
        YES=true
    fi
    install_packages "${base_commands[@]}"
    exit 0
fi

while [[ $# -gt 0 ]]; do
    key="$1"

    case $key in
        -h|--help)
        usage
        ;;
        -y|--yes)
        YES=true
        shift
        ;;
        -a|--all)
        ALL=true
        shift
        ;;
        -n|--name)
        NAME=true
        shift
        ;;
        *)
        echo "Option non reconnue: $key"
        usage
        ;;
    esac
done

# Vérifier les options et exécuter les commandes correspondantes
if [ "$ALL" = true ]; then
    install_packages "${all_commands[@]}"
elif [ "$NAME" = true ]; then
    echo "Entrez le nom du package à vérifier et installer :"
    read package_name
    check_and_install_package $package_name
else
    usage
fi
