from random import *
import numpy as np


def generator(n, nume):
    aux = open(nume, "w")

    nr = randrange(0, n - 1)  # generarea numarului de coordonate
    distana_minima = randrange(1, n)  # generarea distantei minime

    aux.write("{} {}\n".format(nr, distana_minima))  # afisarea in fisier a numarului de coordonate si a distantei minime

    for j in range(1, nr + 1):
        aux.write("{} ".format(randrange(0, n - 1)))  # generarea si afisarea in fisier a coordonatelor

    aux.close()


def afisare_coordonate(vector, dimensiune, out):
    out.write("\nCoordonatele cocenilor ramasi sunt: \n")
    for i in range(0, dimensiune + 1):
        if vector[i] ==1:
            out.write("{} ".format(i))
    out.write("\n")


def eliminare_tulpini(vector, dimensiune, distanta, eliminari, tulpini_ramase):
    j = 0
    i = 0
    while i < dimensiune:
        if vector[i] == 1:
            tulpini_ramase = tulpini_ramase +1
            for j in range(i+1,i+distanta):
                if vector[j] ==1:
                    eliminari = eliminari +1
                vector = np.delete(vector, j)
                vector = np.insert(vector, j, 0)
            i = i+distanta-1
        i = i+1
    if vector[dimensiune] == 1:
        tulpini_ramase = tulpini_ramase + 1

    return vector, dimensiune, tulpini_ramase
