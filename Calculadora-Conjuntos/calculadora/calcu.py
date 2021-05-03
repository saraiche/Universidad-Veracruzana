import string
import math as mt
import numpy as np
from datetime import datetime
#from .operations.conjunto import *
import operations.conjunto as opers
diccionario = {}
data = []

def presentacion():
	presentacion = "Calculadora de Conjuntos"
	de = "Universidad Veracruzana"
	hora = "fecha y hora de inicio {}"
	print(presentacion.center(100))
	print(de.center(95))
	print(hora.format(str(datetime.now())[0:19]).center(100))

def validar( entrada ):
	invalidos = " @[]!~|&'¿¡?+-´^/*%<>;:"
	separado = [ ',' , '{' , '}' ]
	#print("Dentro de validar", *invalidos)
	for c in entrada:
	#	print(c)
		if (c in invalidos):#" or c in separado:
	#		print( c , "Esta aqui")
			return False
	if entrada.count("=") > 1:
		return False
	if entrada.count('(') != entrada.count(')'):
		return False
	if entrada.count('{') != entrada.count('}'):
		return False
	return True

def analizar(linea):
	mayusculas = string.ascii_uppercase
	temporal = []
	ok1 = False
	nuevas = {}
	for c in linea:
		if c in mayusculas:
			if c in diccionario:
				temporal.append(diccionario[c])
				ok = True
			else:
				break


	return  temporal

def construye_conjunto():
	return

def solucionar():
	return [1,2]

def main():
	presentacion()
	line = 0 
	try:
		while True:
			
			print("{}:]".format(line+1), end=" ")
			line += 1
			n = input()
			n = n.replace(' ','')

			if not validar(n):
				print("\nExpresion Invalida")
			else:
				#ans = solucionar()
				print("\n",n)
			print()

	except KeyboardInterrupt:
		print("\nSaliendo")


if __name__ == "__main__":
	main()

