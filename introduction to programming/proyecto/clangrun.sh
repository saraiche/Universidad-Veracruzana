#!/bin/bash
#-*- ENCODING: UTF-8 -*-
echo "Joseph Hynimoto Aguilar Lopez"
echo "compilando las tres librerias.."
clang++ -Wall -std=c++11 main.cpp  mascotas.cpp -o ejecuta
echo "Ejecutando..."
./ejecuta
rm ejecuta	
