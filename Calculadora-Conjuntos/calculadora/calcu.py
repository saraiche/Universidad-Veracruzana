import string
import math as mt
import numpy as np
from datetime import datetime
from .operations.conjunto import *  # <- instalar
#import operations.conjunto as opers  # <- esto es para testear 

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
		print("longitud")
		return False
	if '' in entrada:
		if entrada[len(entrada)-1] != '':
			return False
	if ' ' in entrada:
		return False
	if not isSet(entrada[0]):
		if not entrada[0] in string.ascii_uppercase.strip() and ( entrada[0] != 'pot' and entrada[0] != 'card' ):
			print("problema en el primer elemento")
			return False
	if len(entrada) == 2:
		if entrada[0] == 'pot' or entrada[0] == 'card':
			if isSet(entrada[1]) or entrada[1] in string.ascii_uppercase.strip():
				return True
			else:
				return False
		else: 
			return False
	aux = entrada[0].lower()
	if aux in operadores:
		if ( aux != 'pot' and aux != 'card'):
			print("evalua el primer elemento operador")
			return False

	for c in entrada:
		if c == '' or c == ' ':
			#print("encontre un blanco")
			return False
		for d in c:
			if d in invalidos:
				#print("encontre un invalido", invalidos)
				return False
	if len(entrada) == 1:
		if entrada[0] in string.ascii_uppercase.strip():
			return True
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
			print("checa si es una letra entra si no lo es ")
			return False

	if entrada.count(operadores) >= 3:
		#print( entrada.count(operadores) )
		return False

	for c in entrada:
		if not ( isSet(c) or c in operadores or c in string.ascii_uppercase.strip()):
				return False
	if entrada[len(entrada)-1] in operadores:# or entrada[len(entrada)-1] in string.ascii_uppercase.strip():
		return False

	for c in range(0,len(entrada)-1):
		letras = string.ascii_uppercase.strip()
		if isSet(entrada[c]) and isSet(entrada[c+1]):
			return False
		if entrada[c] in operadores and entrada[c+1] in operadores:
			#print("es mi culpa")
			if (entrada[c] == '=' and (entrada[c+1] != 'pot' and entrada[c+1] != 'card')):
			#	print( (entrada[c] == '=' and (entrada[c+1] != 'pot' and entrada[c+1] != 'card') ))
				return False
		if entrada[c] in letras and entrada[c+1] in letras:
			return False
		if (entrada[c] in letras  and isSet(entrada[c+1])) or ( isSet(entrada[c]) and entrada[c+1] in letras) or ( entrada[c] in letras and entrada[c+1] in letras):
			return False

	for c in range(1,len(entrada)-1):
		if entrada[c] == 'card' or entrada[c] == 'pot':
			if isSet(entrada[c-1]) and isSet(entrada[c+1]):
				return False
	if len(entrada) == 3:
		if 'card' in entrada or 'pot' in entrada:
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

def memoria(a):
	letras = string.ascii_uppercase.strip()
	aux = type(a)
	if aux == type(set()):
		return a
	if a in diccionario:
		return diccionario[a]
	else:
		return set()

def solucionar(contenedor):
	ans = []
	if len(contenedor) == 1:
		if contenedor[0] in diccionario:
			return [diccionario[contenedor[0]]]
		else:
			return [set()]
	if len(contenedor) == 2:
		if contenedor[1] == 'pot':
			aux = memoria(contenedor[0])
			return [potencia(aux)]
		elif contenedor[1] == 'card':
			aux = memoria(contenedor[0])
			return [cardinalidad(aux)]

	if len(contenedor) == 3:
		if contenedor[1] == 'uni':
			aux = memoria(contenedor[0])
			aux2 = memoria(contenedor[2])
			return [uniones(aux,aux2)]

		elif contenedor[1] == 'int':
			aux = memoria(contenedor[0])
			aux2 = memoria(contenedor[2])
			return [intersec(aux,aux2)]
		elif contenedor[1] == 'dif':
			aux = memoria(contenedor[0])
			aux2 = memoria(contenedor[2])
			return [diferencia(aux,aux2)]
		elif contenedor[1] == 'prod':
			aux = memoria(contenedor[0])
			aux2 = memoria(contenedor[2])
			return [cartecian(aux,aux2)]
		elif contenedor[1] == '=':
			diccionario[contenedor[2]] = memoria(contenedor[0])
			aux = diccionario[contenedor[2]]
			return [aux]
	if len(contenedor) == 4:
		if( contenedor[1] == 'pot'):
			aux = memoria(contenedor[0])
			diccionario[contenedor[3]] = potencia(aux)
			aux = diccionario[contenedor[3]]
			return [aux]
		if contenedor[1] == 'card':
			aux = memoria(contenedor[0])
			diccionario[contenedor[3]] = cardinalidad(aux)
			aux = diccionario[contenedor[3]]
			return [aux]

	if len(contenedor) == 5:
		temporal = memoria(contenedor[0])
		for c in range(1,len(contenedor)-1,2):
			if contenedor[c] == 'uni':
				aux = memoria(contenedor[c+1])
				temporal = uniones(temporal,aux)
			elif contenedor[c] == 'int':
				aux = memoria(contenedor[c+1])
				temporal = intersec(temporal,aux)

			elif contenedor[c] == 'dif':
				aux = memoria(contenedor[c+1])
				temporal = diferencia(temporal,aux)

			elif contenedor[c] == 'prod':
				aux = memoria(contenedor[c+1])
				temporal = cartecian(temporal,aux)

			elif contenedor[c] == '=':
				diccionario[contenedor[c+1]] = temporal
		return [temporal]

	return ["error interno"]




def main():
	presentacion()
	line = 0 
	try:
		while True:
			
			print("{}:]".format(line+1), end=" ")
			line += 1
			n = input()
			array = list( n.split(' '))
			if '' in array:
				array.remove('')
			#print("el arreglo quedo -> ", array)
			if len(array) > 5 or not validar(array):
				print("\nExpresion Invalida")
			else:
				array = construye(array)
				array = array[::-1]
				ans = solucionar(array)
				print("\n", *ans)
			print()

	except KeyboardInterrupt:
		print("\nSaliendo")


if __name__ == "__main__":
	main()
