import random

tab1_10 = []
tab2_10 = []
tab3_10 = []
tab4_10 = []
tab5_10 = []
tab6_10 = []
tab7_10 = []
tab8_10 = []
tab9_10 = []
tab10_10 = []

tab1_500 = []
tab2_500 = []
tab3_500 = []
tab4_500 = []
tab5_500 = []
tab6_500 = []
tab7_500 = []
tab8_500 = []
tab9_500 = []
tab10_500 = []

tab1_5000 = []
tab2_5000 = []
tab3_5000 = []
tab4_5000 = []
tab5_5000 = []
tab6_5000 = []
tab7_5000 = []
tab8_5000 = []
tab9_5000 = []
tab10_5000 = []

tab_10 = [tab1_10, tab2_10, tab3_10, tab4_10, tab5_10, tab6_10, tab7_10, tab8_10, tab9_10, tab10_10]
tab_500 = [tab1_500, tab2_500, tab3_500, tab4_500, tab5_500, tab6_500, tab7_500, tab8_500, tab9_500, tab10_500]
tab_5000 = [tab1_5000, tab2_5000, tab3_5000, tab4_5000, tab5_5000, tab6_5000, tab7_5000, tab8_5000, tab9_5000, tab10_5000]

i = 0
while i < 10:
    j = 0
    while j < 10:
        tab_10[j].append(random.randint(0, 100))
        j = j + 1
    i = i + 1

i = 0
while i < 500:
    j = 0
    while j < 10:
        tab_500[j].append(random.randint(0, 100))
        j = j + 1
    i = i + 1

i = 0
while i < 5000:
    j = 0
    while j < 10:
        tab_5000[j].append(random.randint(0, 100))
        j = j + 1
    i = i + 1


def tri_selection(tab):
    compteur = 0
    i = 0
    j = 0
    compteur = compteur + 2
    while i < len(tab) - 1:
        min = i
        j = i + 1
        compteur = compteur + 5
        while j < len(tab):
            compteur = compteur + 1
            if tab[j] < tab[min]:
                min = j
                compteur = compteur + 2
            j = j + 1
            compteur = compteur + 2

        compteur = compteur + 1
        tmp = tab[i]
        tab[i] = tab[min]
        tab[min] = tmp
        i = i + 1
        compteur = compteur + 5

    compteur = compteur + 1
    print(f"Nombre d'operations elementaires du tri par selection : {compteur}")
    return compteur


def recherche_dicho(tab: [int], e: int):
    compteur = 0

    deb = 0
    fin = len(tab) - 1
    ind = -1

    compteur = compteur + 4

    while deb <= fin:
        millieu = (fin + deb) // 2

        compteur = compteur + 4

        if tab[millieu] < e:
            deb = millieu + 1
            compteur = compteur + 3
        elif tab[millieu] > e:
            fin = millieu - 1
            compteur = compteur + 4
        else:
            ind = millieu
            compteur = compteur + 3
            print(f"Nombre d'operations elementaires de la recherche dicho : {compteur}")
            return
    compteur = compteur + 1
    print(f"Nombre d'operations elementaires de la recherche dicho : {compteur}")
    return ind


print("tab_10 : ")
calcul = 0
i = 0
while i < 10:
    calcul = calcul + tri_selection(tab_10[i])
    i = i + 1
print(f"Moyenne = {calcul / 10}")

print("tab_500 : ")
calcul = 0
i = 0
while i < 10:
    calcul = calcul + tri_selection(tab_500[i])
    i = i + 1
print(f"Moyenne = {calcul / 10}")

print("tab_5000 : ")
calcul = 0
i = 0
while i < 10:
    calcul = calcul + tri_selection(tab_5000[i])
    i = i + 1
print(f"Moyenne = {calcul / 10}")
