from random import *
import numpy as np
def generator(n, nume):
    for i in range(1, 11):
        aux = open(nume, "w")

        nr = randrange(3, n-1)  # generarea numarului de coordonate
        distanta_minima = randrange(1, n)  # generarea distantei minime

        aux.write("{} {}\n".format(nr, distanta_minima))  # afisarea in fisier a numarului de coordonate si a distantei minime

        for j in range(1, nr+1):
            aux.write("{} ".format(randrange(0, n-1)))  # generarea si afisarea in fisier a coordonatelor

        aux.close()

def afisare_coordonate(vector, aux, out):
    out.write("\nCoordonatele cocenilor ramasi sunt\n")
    for i in range(0, aux):
        out.write("{} ".format(vector[i]))
    out.write("\n")

def eliminare_tulpini(vector, nr_coordonate, dimensiune, distanta, tulpini_ramase, aux):

    eliminari = 0  # variabila ce retine numarul de tulpini eliminate
    tulpini_ramase = 0  # variabila ce retine numarul de tulpini ramase
    i = 0
    while i < dimensiune:
        x = int(vector[i+1])
        y = int(vector[i])
        if x - y < distanta:
            for j in range(i+1, dimensiune-1):  # eliminarea tulpinilor,d eplasand spre stanga cu o pozitie vectorul coordonate
                val = vector[ j + 1 ]
                vector = np.delete(vector, j)
                vector = np.insert(vector , j, val)
            i = i - 1
            dimensiune = dimensiune - 1
            eliminari = eliminari +1
        i = i + 1
    aux = dimensiune

    while eliminari <= nr_coordonate:  # determinarea numarului de tulpini ramase
        tulpini_ramase = tulpini_ramase +1
        eliminari = eliminari +1

    return vector ,aux, tulpini_ramase





