import time
import os
from utils import *
import numpy as np


for i in range(1, 11):

    nume_in = os.path.dirname(os.path.dirname(os.path.abspath(__file__))) + "\Data\input{}.txt".format(i)
    nume_out = os.path.dirname(os.path.dirname(os.path.abspath(__file__))) + "\Data\output{}.txt".format(i)

    inn = open(nume_in, "r")
    out = open(nume_out, "w")

    generator(1000,nume_in)

    line = inn.readline().split(' ')
    nr_coordonate,distanta_minima = int(line[0]), int(line[1])  # citirea numarului de coordonate si a distantei minime

    lan = np.zeros(100000, dtype=int)  # initializarea vectorului lan cu 0
    start = time.time()

    for j in range(0, nr_coordonate):
        lan = np.insert(lan, j, 0)

    MAX = 0  # initializarea maximului coordonatelor cu 0

    tulpini_ramase = 0  # initializarea numarului de tulpini ramase cu 0

    line2 = inn.readline().split()  # citirea coordonatelor

    eliminari = 0  # initializarea numarului de eliminari cu 0

    for coord in line2:
        coord = int(coord)
        if coord >= MAX:
            MAX = coord  # determinarea maximului coordonatelor
        if lan[coord] == 1:
            eliminari = eliminari + 1  # cresterea numarului de eliminari datorita coordonatelor ce se repeta
        elif lan[coord] == 0:
            lan = np.delete(lan, coord)
            lan = np.insert(lan, coord, 1)  # marcarea cu 1 a cocenilor de porumb existenti in vectorul lan

    eliminari = tulpini_ramase = 0

    if distanta_minima <= MAX:
        lan, MAX, tulpini_ramase = eliminare_tulpini(lan, MAX, distanta_minima, eliminari, tulpini_ramase)
        out.write("Numarul minim de tulpini eliminate: {}\n".format(nr_coordonate - tulpini_ramase))
        afisare_coordonate(lan, MAX, out)
    else:
        out.write("IMPOSIBIL\n")


    finish = time.time()
    duration = finish - start
    duration = round(duration, 13)
    out.write("\nDurata testului {} : {}s".format(i, duration))

    inn.close()
    out.close()
