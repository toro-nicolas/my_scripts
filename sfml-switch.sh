#!/bin/bash

# Install version exemple :
#git clone https://github.com/SFML/SFML.git
#cd SFML
#git checkout 3.0.0
#mkdir build && cd build
#cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/opt/sfml-3.0.0
#make -j$(nproc)
#sudo make install



# Vérifie si un argument a été passé (numéro de version SFML)
if [ -z "$1" ]; then
  echo "Erreur : aucun numéro de version SFML fourni."
  echo "Usage : $0 <version>"
  exit 1
fi

VERSION=$1
SFML_DIR="/opt/sfml-$VERSION"
INCLUDE_DIR="/usr/local/include"

# Vérifie si le répertoire /opt/sfml-[version] existe
if [ ! -d "$SFML_DIR" ]; then
  echo "Erreur : le répertoire $SFML_DIR n'existe pas. Assurez-vous que SFML $VERSION est installé dans /opt."
  exit 1
fi

# Vérifie si le répertoire de destination /usr/local/include/SFML existe
if [ -d "$INCLUDE_DIR/SFML" ]; then
  echo "Suppression de l'ancien dossier $INCLUDE_DIR..."
  sudo rm -rf "$INCLUDE_DIR/SFML"
fi

# Copie les fichiers de /opt/sfml-[version]/include dans /usr/local/include/SFML
echo "Copie des fichiers de $SFML_DIR/include vers $INCLUDE_DIR..."
sudo cp -r "$SFML_DIR/include/SFML" "$INCLUDE_DIR"

# Vérifie si la copie a réussi
if [ $? -eq 0 ]; then
  echo "SFML $VERSION a été installé avec succès dans $INCLUDE_DIR."
else
  echo "Erreur lors de la copie des fichiers."
  exit 1
fi
