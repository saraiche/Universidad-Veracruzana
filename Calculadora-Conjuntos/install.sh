#!/usr/bin/env bash

# Pregunta por ~./bash_aliases
if [ ! -f ~/.bash_aliases ]; then
    touch ~/.bash_aliases
fi
#instala los requerimientos con pip
pip3 install -r requeriments.txt
# Instalacion de la calculadora, y creacion del alias.
pip3 install --user . && echo "alias conjuntos=/home/$USER/.local/bin/conjuntos" >> ~/.bash_aliases
#actualizando la terminal
source ~/.bash_aliases
#limpiando
#imprimiendo	
echo "Instalacion terminada, para usar escribe 'conjuntos' en tu terminal"
read -s -n 1 -p "Oprime enter"
clear

