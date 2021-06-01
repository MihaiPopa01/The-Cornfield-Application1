from utils import *
from sort import *
import time
import os
import numpy as np

for i in range(1, 11):

    nume_in = os.path.dirname(os.path.dirname(os.path.abspath(__file__))) + "\Data\input{}.txt".format(i)
    nume_out = os.path.dirname(os.path.dirname(os.path.abspath(__file__))) + "\Data\output{}.txt".format(i)

    inn = open(nume_in, "r")
    out = open(nume_out, "w")

    generator(100,nume_in)

    line = [ ]
    line = inn.readline().split()

    nr_coordonate, distanta_minima = int(line[ 0 ]), int(line[ 1 ])  # citirea numarului de coordonate si a distantei minime

    coordonate = np.zeros(nr_coordonate, dtype=int)  # initializarea vectorului coordonate cu 0

    start = time.time()

    nr_copie = nr_coordonate  # variabila ce retine o copie a numarului de coordonate

    line2 = [ ]
    line2 = inn.readline().split()

    x = 0
    for k in line2:
        k = int(k)
        coordonate = np.delete(coordonate, x)
        coordonate = np.insert(coordonate, x, k)  # stocarea coordonatelor in vector
        x = x + 1

    quick_sort(coordonate, 0, nr_coordonate-1)  # sortarea strict crescatoare a coordonatelor

    if nr_coordonate == 2:
        if coordonate[1] - coordonate[0] < distanta_minima:
            out.write("IMPOSIBIL \n")
        elif coordonate[1] - coordonate[0] >= distanta_minima:
            out.write("Numarul minim de tulpini eliminate: {}\n".format(0))
            out.write("\nCoordonatele cocenilor ramasi sunt:\n{} {}".format(coordonate[0],coordonate[1]))
            continue

    tulpini_ramase = int()
    aux = int()
    dimensiune = nr_coordonate

    if distanta_minima <= coordonate[ nr_coordonate - 1 ]:
        coordonate, aux, tulpini_ramase = eliminare_tulpini (coordonate, nr_coordonate, dimensiune, distanta_minima, tulpini_ramase, aux)
        out.write("Numarul minim de tulpini eliminate: {} \n".format(nr_copie - tulpini_ramase))
        aux = aux +1
        afisare_coordonate(coordonate, aux, out)

    else:
        out.write("IMPOSIBIL\n")

    finish = time.time()
    duration = finish - start
    duration = round (duration, 13)
    out.write("\nDurata testului {} : {}s\n".format(i,duration))

    inn.close()
    out.close()
