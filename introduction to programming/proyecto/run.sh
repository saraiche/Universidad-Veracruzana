#!/bin/bash
#-*- ENCODING: UTF-8 -*-
echo "Joseph Hynimoto Aguilar Lopez"
echo "compilando las tres librerias.."
g++ -Wall -std=c++11 main.cpp interface.h mascotas.h mascotas.cpp -o ejecuta
echo "Ejecutando..."
./ejecuta
rm ejecuta	
