import string
import math as mt
import numpy as np
from datetime import datetime
from operations import *

def presentacion():
	presentacion = "Calculadora de Conjuntos"
	de = "Universidad Veracruzana"
	hora = "fecha y hora de inicio {}"
	print(presentacion.center(100))
	print(de.center(95))
	print(hora.format(str(datetime.now())[0:19]).center(100))

def main():
	presentacion()
	while True:
		n = input()
		print(list(n.split(' ')))




if __name__ == "__main__":
	try:
		main()
	except KeyboardInterrupt:
		print("Saliendo")



