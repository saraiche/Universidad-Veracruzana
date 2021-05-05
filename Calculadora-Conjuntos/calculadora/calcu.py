import string
import math as mt
import numpy as np
from datetime import datetime
#from .operations.conjunto import *  # <- instalar
import operations.conjunto as opers  # <- esto es para testear 

#========================================

diccionario = {}
data = []
operadores = ["card", "uni", "int", "dif", "prod", "pot","="]

#========================================

def presentacion():
	presentacion = "Calculadora de Conjuntos"
	de = "Universidad Veracruzana"
	hora = "fecha y hora de inicio {}"
	print(presentacion.center(100))
	print(de.center(95))
	print(hora.format(str(datetime.now())[0:19]).center(100))

def isSet(var):
	if ' ' in var:
		return False
	if var.count('{') != 1 or  var.count('}') != 1:
		return False
	coso = var[1:len(var)-1]
	n = len(coso.split(','))
	comas = var.count(',')
	if comas > n or comas +1 != n:# comas + n  != len(var)-2:
		return False 
	if var == "{}":
		return False
	return True

def validar( entrada ):
	invalidos = " @[]!~|&'¿¡?+-´^/*%<>;:()"
	separado = [ ',' , '{' , '}' ]
	minusculas = string.ascii_lowercase
	if len(entrada) == 0:
		return False
	if len(entrada) == 1:
		return False
	if '' in entrada:
		if entrada[len(entrada)-1] != '':
			return False
	if ' ' in entrada:
		return False
	if not isSet(entrada[0]):
		if not entrada[0] in string.ascii_uppercase.strip():
			return False
	aux = entrada[0].lower()
	if aux in operadores:
		return False

	for c in entrada:
		if c == '' or c == ' ':
			#print("encontre un blanco")
			return False
		for d in c:
			if d in invalidos:
				#print("encontre un invalido", invalidos)
				return False

	ok = True
	for c in entrada:
		if c.count("=") > 1:
			#print("encontre un =")
			return False
		if c[0] == '{':
			if not isSet(c):
				#print("encontre fue el set")
				ok = False
				return False
	for c in entrada:
		if isSet(c):
			aux = c[1:len(c)-1]
			aux = aux.split(',')
			if '' in aux:
				return False

	if not isSet(entrada[0]):
		if entrada[0] in operadores:
			return False
		if not entrada[0] in string.ascii_uppercase.strip():
			return False

	if entrada.count(operadores) >= 3:
		#print( entrada.count(operadores) )
		return False

	for c in entrada:
		if not ( isSet(c) or c in operadores or c in string.ascii_uppercase.strip()):
				return False
	if entrada[len(entrada)-1] in operadores or entrada[len(entrada)-1] in string.ascii_uppercase.strip():
		return False

	for c in range(0,len(entrada)-1):
		letras = string.ascii_uppercase.strip()
		if isSet(entrada[c]) and isSet(entrada[c+1]):
			return False
		if entrada[c] in operadores and entrada[c+1] in operadores:
			return False
		if entrada[c] in letras and entrada[c+1] in letras:
			return False
		if (entrada[c] in letras  and isSet(entrada[c+1])) or ( isSet(entrada[c]) and entrada[c+1] in letras) or ( entrada[c] in letras and entrada[c+1] in letras):
			return False

	if ok:
		return True
	##print("Dentro de validar", *invalidos)

	



def construye(coso):
	ans = []
	for c in coso:
		if isSet(c):
			aux = c
			aux = aux[1:len(aux)-1]
			aux =  aux.split(',')
			temporal = string.ascii_letters.strip()
			#print(temporal, aux)
			segundo = []
			for i in aux:
				ok = False
				for j in i:
					if j in temporal:
						ok = True
						segundo.append(i)
						break
				if not ok:
					segundo.append(int(i))

			#print("no es oficial -> ", segundo)
			aux = set(segundo)
			ans.append(aux)
		else:
			ans.append(c)
	return ans


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
			array = list( n.split(' '))
			print("el arreglo quedo -> ", array)
			if len(array) > 5 or not validar(array):
				print("\nExpresion Invalida")
			else:
				array = construye(array)
				array = array[::-1]
				stack = []
				print("\n",*array)
			print()

	except KeyboardInterrupt:
		print("\nSaliendo")


if __name__ == "__main__":
	main()
