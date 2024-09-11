import random

"DataSet Creacion Arreglos tamaño 1000"

listaOrdenada = list(range(1000))
print(listaOrdenada)
print("----------------------------------------------------------------- ORDENADA")

listaSemiordenada = list(range(1000))
mitad = listaSemiordenada[:500]
random.shuffle(mitad)
listaSemiordenada[:500] = mitad 
print(listaSemiordenada)
print("----------------------------------------------------------------- SEMI")

listaParcial = list(range(1000))
cuarto = listaParcial[:250]
random.shuffle(cuarto)
listaParcial[:250] = cuarto
print(listaParcial)
print("----------------------------------------------------------------- PARCIAL")

listaDesordenada = list(range(1000))
random.shuffle(listaDesordenada)
print(listaDesordenada)
print("----------------------------------------------------------------- DESORDENADA")

listas = [listaOrdenada, listaSemiordenada, listaParcial, listaDesordenada]
with open('Arreglos1000.txt', 'w') as archivo:
    for lista in listas:
        linea = ' '.join(map(str, lista))  
        archivo.write(linea + '\n')




"-----------DataSet Creacion Arreglos tamaño 5000-----------"

listaOrdenada = list(range(5000))
print(listaOrdenada)
print("----------------------------------------------------------------- ORDENADA")

listaSemiordenada = list(range(5000))
mitad = listaSemiordenada[:2500]
random.shuffle(mitad)
listaSemiordenada[:2500] = mitad 
print(listaSemiordenada)
print("----------------------------------------------------------------- SEMI")

listaParcial = list(range(5000))
cuarto = listaParcial[:1250]
random.shuffle(cuarto)
listaParcial[:1250] = cuarto
print(listaParcial)
print("----------------------------------------------------------------- PARCIAL")

listaDesordenada = list(range(5000))
random.shuffle(listaDesordenada)
print(listaDesordenada)
print("----------------------------------------------------------------- DESORDENADA")

listas = [listaOrdenada, listaSemiordenada, listaParcial, listaDesordenada]
with open('Arreglos5000.txt', 'w') as archivo:
    for lista in listas:
        linea = ' '.join(map(str, lista))  
        archivo.write(linea + '\n')



"-----------DataSet Creacion Arreglos tamaño 10000-----------"

listaOrdenada = list(range(10000))
print(listaOrdenada)
print("----------------------------------------------------------------- ORDENADA")

listaSemiordenada = list(range(10000))
mitad = listaSemiordenada[:5000]
random.shuffle(mitad)
listaSemiordenada[:5000] = mitad 
print(listaSemiordenada)
print("----------------------------------------------------------------- SEMI")

listaParcial = list(range(10000))
cuarto = listaParcial[:2500]
random.shuffle(cuarto)
listaParcial[:2500] = cuarto
print(listaParcial)
print("----------------------------------------------------------------- PARCIAL")

listaDesordenada = list(range(10000))
random.shuffle(listaDesordenada)
print(listaDesordenada)
print("----------------------------------------------------------------- DESORDENADA")

listas = [listaOrdenada, listaSemiordenada, listaParcial, listaDesordenada]
with open('Arreglos10000.txt', 'w') as archivo:
    for lista in listas:
        linea = ' '.join(map(str, lista))  
        archivo.write(linea + '\n')



"-----------DataSet Creacion Arreglos tamaño 50000-----------"

listaOrdenada = list(range(50000))
print(listaOrdenada)
print("----------------------------------------------------------------- ORDENADA")

listaSemiordenada = list(range(50000))
mitad = listaSemiordenada[:25000]
random.shuffle(mitad)
listaSemiordenada[:25000] = mitad 
print(listaSemiordenada)
print("----------------------------------------------------------------- SEMI")

listaParcial = list(range(50000))
cuarto = listaParcial[:12500]
random.shuffle(cuarto)
listaParcial[:12500] = cuarto
print(listaParcial)
print("----------------------------------------------------------------- PARCIAL")

listaDesordenada = list(range(50000))
random.shuffle(listaDesordenada)
print(listaDesordenada)
print("----------------------------------------------------------------- DESORDENADA")

listas = [listaOrdenada, listaSemiordenada, listaParcial, listaDesordenada]
with open('Arreglos50000.txt', 'w') as archivo:
    for lista in listas:
        linea = ' '.join(map(str, lista))  
        archivo.write(linea + '\n')