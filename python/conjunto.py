
#Funciones principales o madres 
#cardinalidad
def cardinalidad(a):
	return len(a)

#union  retorna un conjunto s tal que s es la union de a u b 
def uniones( a, b ):
	s = a
	return s.union(b)

#interseccion retorna un conjunto s tal que s es la interseccion de a ^ b
def intersec(a, b ):
	s = a 
	return s.intersection(b)

#diferencia retorna la diferencia de dos conjuntos 
def diferencia(a, b):
	return a - b

#producto carteciano  retorna el producto carteciano 
def cartecian(a,b):
	s = set()
	for c in a:
		for d in b:
			s.add((c,d))
	return s
#producto potencia retorna un conjunto potencia
def potencia(a):
	''' calcula, crea y retorna una lista s
	tal que s sea el conjunto potencia de A'''
	#ADVERTENCIA no te excedad, la complejidad de esto es O(2^n * len(subset(A)))

	longi = cardinalidad(a)
	l = [c for c in a]
	s = set()
	for c in range(2 ** longi):
		selector = f'{c:0{longi}b}'
		subconjunto =  {l[d] for d, bit in enumerate(selector) if bit == '1'}
		s.add(frozenset(subconjunto))
	s = [set(c) for c in s]
	s.sort()
	return s


print("Ojo los datos solo pueden ser enteros\n")

a = set(map(int, input("ingresa los datos del conjunto A separados por espacios: ").split()))
b = set(map(int, input("ingresa los datos del conjunto B separados por espacios: ").split()))

print("Cardinalidad A:", cardinalidad(a))
print("Cardinalidad B:", cardinalidad(b))
print("Union de A u B ", uniones(a,b))
print("Interseccion de A ^ B: ", intersec(a,b))
print("Diferencia de A / B: ", diferencia(a,b))
print("Producto carteciano de A, B: ", cartecian(a,b))
print("Cardinalidad de un conjunto Potencia: " ,cardinalidad(potencia(a)))
print("El conjunto potencia de un conjunto carteciano: ", potencia(cartecian(a,b)))
