#!/bin/bash

# Vérifiez si le script est exécuté en tant que superutilisateur (root)
if [ "$EUID" -ne 0 ]; then
  echo "Ce script doit être exécuté en tant que superutilisateur (root)."
  exit 1
fi

echo "Date actuelle : $(date)"

# Synchroniser l'heure avec un serveur NTP
ntpdate pool.ntp.org > /dev/null 2>&1

echo "Nouvelle date : $(date)"
echo "L'heure du système a été synchronisée avec succès."
