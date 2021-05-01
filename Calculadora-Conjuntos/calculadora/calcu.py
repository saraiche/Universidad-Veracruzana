import string
import math as mt
import numpy as np
from datetime import datetime
#import operadorconjuntos

def presentacion():
	presentacion = "Calculadora de Conjuntos"
	de = "Universidad Veracruzana"
	hora = "fecha y hora de inicio {}"
	print(presentacion.center(100))
	print(de.center(95))
	print(hora.format(str(datetime.now())[0:19]).center(100))

def main():
	presentacion()
	line = 0 
	try:
		while True:
			print("{}:]".format(line+1), end=" ")
			line += 1
			n = input()
			ans = list( n.split(' '))
			print("\n",list(n.split(' ')))
			print()
	except KeyboardInterrupt:
		print("\nSaliendo")




