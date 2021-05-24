#! /usr/bin/env python
# encoding: utf8

import pickle

def guardar_puntajes(nombre_archivo, puntajes):
    """ Guarda la lista de puntajes en el archivo.
    Pre: nombre_archivo corresponde a un archivo válido,
         puntajes corresponde a una lista de secuencias de elementos.
    Post: se guardaron los valores en el archivo en formato pickle.
    """

    archivo = open(nombre_archivo, "wb") # wb es para esctibir en arch bin
    pickle.dump(puntajes, archivo)
    archivo.close()

def recuperar_puntajes(nombre_archivo):
    """ Recupera los puntajes a partir del archivo provisto.
        Devuelve una lista con los valores de los puntajes.
    Pre: el archivo contiene los puntajes en el formato pickle
    Post: la lista devuelta contiene los puntajes en el formato:
          [(nombre1,puntaje1,tiempo1),(nombre2,puntaje2,tiempo2)].
"""

    puntajes = []
    archivo = open(nombre_archivo, "rb")
    puntajes = pickle.load(archivo)
    archivo.close()
    return puntajes

valores = [("Pepe", 108, "4:16"), ("Juana", 2315, "8:42")]
guardar_puntajes("puntajes_03.bin", valores)
p = recuperar_puntajes ("puntajes_03.bin")
print (p)