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
        tab_10[j].append(random.randint(0, 5000))
        j = j + 1
    i = i + 1

i = 0
while i < 500:
    j = 0
    while j < 10:
        tab_500[j].append(random.randint(0, 5000))
        j = j + 1
    i = i + 1

i = 0
while i < 5000:
    j = 0
    while j < 10:
        tab_5000[j].append(random.randint(0, 5000))
        j = j + 1
    i = i + 1




"""
:entrée/sortie tab: int
:pré-cond: len(tab) >= 1
:sortie compteur: int
:post-cond: ajouter +1 pour chaque operateur utiliser durant la recherche et 
trier les éléments d'un tableau en sélectionnant un par un les éléments du tableau, du plus petit au plus grand.
"""
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
    compteur = compteur + 2
    return compteur




def copie(tab1, tab2):
    """
    :entrée/sortie tab2: int
    :entrée tab1: int 
    :pré-cond: len(tab1) = len(tab2)
    :sortie compteur: int
    :post-cond: ajoute +1 pour chaque operateur utiliser durant la copie et effectue une copie élément par élément de tab1 vers tab2.
    """
    compteur = 0
    n = len(tab1)
    i = 0
    compteur = compteur + 2
    while i < n:
        tab2[i] = tab1[i]
        i = i + 1
        compteur = compteur + 4
    compteur = compteur + 1
    return (compteur)
        





def interclassement(left, right, tab):
    """
    :entrée left
    :entrée right
    :entrée/sortie tab
    :pré-cond: len(tab) = len(right) + len(left) 
    right et left sont triés
    :sortie compteur
    :post-cond: ajouter +1 pour chaque operateur utiliser durant le tri et 
    tab contient tous les éléments de left et right, et est trié
    """
    compteur = 0
    i = j = k = 0
    compteur = compteur + 4
    while i < len(left) and j < len(right):
        compteur = compteur + 3
        if left[i] < right[j]:
            tab[k] = left[i]
            i = i + 1
            compteur = compteur + 4
        else:
            tab[k] = right[j]
            j += 1
            k += 1
            compteur = compteur + 5
    compteur = compteur + 3
    while i < len(left):
        tab[k] = left[i]
        i += 1
        k += 1
        compteur = compteur + 6
    compteur = compteur + 1

    while j < len(right):
        tab[k] = right[j]
        j += 1
        k += 1
        compteur = compteur + 6
    compteur = compteur + 1
    return compteur



def tri_fusion(tab):
    """
    :entrée/sortie tab: [ind]
    :pré-cond: len(tab) >= 1
    :sortie compteur: int
    :post-cond: ajouter +1 pour chaque operateur utiliser durant le tri Le principe est de partager le tableau en deux moitiés, de 
    les trier récursivement, puis de fusionner ces deux moitiés triées de façon à obtenir un tableau trié.  
    """
    compteur = 0
    n = len(tab)
    compteur = compteur + 1
    if n > 1:
        mid = n // 2
        compteur = compteur + 2
        left = tab[:mid]
        compteur = compteur + 1
        right = tab[mid:]
        compteur = compteur + 1

        tri_fusion(left)
        compteur = compteur + 1
        tri_fusion(right)
        compteur = compteur + 1

        tab3 = [0] * n
        compteur = compteur + 1
        interclassement(left, right, tab3)
        compteur1 = interclassement(left, right, tab)
        compteur = compteur + 1
        copie(tab3, tab)
        compteur = compteur + 1
        compteur = compteur + compteur1 
    return(compteur)





def trie_bulle(tab):
    """
    :entrée/sortie tab: [int]
    :pré-cond: len(tab) >= 1
    :sortie compteur: int
    :post-cond: ajouter +1 pour chaque operateur utiliser durant le tri et le tri compare les éléments consécutifs du tableau
    et les permutes s'ils ne sont pas dans le bonne ordre
    """
    compteur = 0
    n = len(tab)
    compteur = compteur + 1
    while n > 0:
        compteur = compteur + 1
        i = 0
        compteur = compteur + 1
        while i < n - 1:
            compteur = compteur + 2
            if tab[i] > tab[i + 1]:
                compteur = compteur + 2
                tmp = tab[i]
                compteur = compteur + 1
                tab[i] = tab[i + 1]
                compteur = compteur + 2
                tab[i + 1] = tmp
                compteur = compteur + 2
            i += 1
            compteur = compteur + 2
        n -= 1
        compteur = compteur + 4
    return compteur





def recherche_dicho(tab:[int], e:int):
    """
    :entrée tab: [int]
    :entrée e: int
    :pré-cond: ∀i ∈ [0..len(tab)-2], tab[i] <= tab[i+1] 
    :sortie compteur: int
    :post-cond: ajouter +1 pour chaque operateur utiliser durant la recherche et S'il existe i ∈ [0..len(tab)-1] tel que tab[i] = e
    alors ind ∈ [0..len(tab)-1] et tab[ind] = e, sinon ind = -1. 
    """
    tri_fusion(tab)
    compteur = 0
    deb = 0
    fin = len(tab) - 1
    ind = -1

    compteur = 5 + compteur

    while deb <= fin:
        millieu = (fin + deb) // 2

        compteur = 4 + compteur

        if tab[millieu] < e:
            deb = millieu + 1
            compteur = 3 + compteur

        elif tab[millieu] > e:
            fin = millieu - 1
            compteur = 3 + compteur
        else:
            break
    compteur = compteur + 1
    return compteur




"""
:entrée/sortie tab: [int]
:entrée valeur_recherchee: int
:pré-cond:
:sortie compteur: int 
:post-cond: ajouter +1 pour chaque operateur utiliser durant la recherche
"""
def recherche(tab, valeur_recherchee):
    tri_fusion(tab)
    compteur = 0
    i = 0
    n = len(tab)
    ind = -1

    compteur += 4  # Initialisation des variables

    while i < n:
        compteur += 1
        if tab[i] == valeur_recherchee:
            ind = i
            compteur += 2  # Assignation et break
            break
        else:
            i += 1
            compteur += 2  # Incrémentation de i et else

    compteur += 1  # Sortie de la boucle

#   if ind != -1:
#       print(valeur_recherchee, "se trouve en premier à l'indice:", ind)
#    
#   else:
#       print(valeur_recherchee, "n'est pas présent dans le tableau.")
#        
    return compteur





def recherche_dicho_recursive(tab, e):
    """
    :entrée tab: [int]
    :entrée e: int
    :pré-cond: ∀i ∈ [0..len(tab)-2], tab[i] <= tab[i+1] 
    :sortie compteur: int
    :post-cond: ajouter +1 pour chaque operateur utiliser durant la recherche et 
    s'il existe i ∈ [0..len(tab)-1] tel que tab[i] = e alors ind ∈ [0..len(tab)-1] et tab[ind] = e, sinon ind = -1. 
    """
    tri_fusion(tab)
    n = len(tab)
    compteur = 0  # Initialisation du compteur

    compteur += 1  # Opération de longueur du tableau
    if n == 0:
        return compteur  # Retourne le compteur si le tableau est vide

    compteur += 1

    mil = n // 2
    compteur += 2
    if tab[mil] == e:
        return compteur  # Retourne le compteur si l'élément est trouvé

    else:
        compteur += 1
        if tab[mil] > e:
            compteur += recherche_dicho_recursive(tab[:mil], e)  # Recherche dans la moitié gauche

        else:
            compteur_inf = recherche_dicho_recursive(tab[mil + 1:], e)  # Recherche dans la moitié droite
            compteur += compteur_inf
            compteur += 1
            if compteur_inf != 0:
                compteur += 1
            # Retourne le compteur seulement (pas de déballage du résultat)
            return compteur








print("TRI SELECTION :")
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



print("")



print("TRI FUSION :")
print("tab_10 : ")
calcul = 0
i = 0
while i < 10:
    calcul = calcul + tri_fusion(tab_10[i])
    i = i + 1
print(f"Moyenne = {calcul / 10}")

print("tab_500 : ")
calcul = 0
i = 0
while i < 10:
    calcul = calcul + tri_fusion(tab_500[i])
    i = i + 1
print(f"Moyenne = {calcul / 10}")

print("tab_5000 : ")
calcul = 0
i = 0
while i < 10:
    calcul = calcul + tri_fusion(tab_5000[i])
    i = i + 1
print(f"Moyenne = {calcul / 10}")




print("")




print("TRI BULLE :")
print("tab_10 : ")
calcul = 0
i = 0
while i < 10:
    calcul = calcul + trie_bulle(tab_10[i])
    i = i + 1
print(f"Moyenne = {calcul / 10}")

print("tab_500 : ")
calcul = 0
i = 0
while i < 10:
    calcul = calcul + trie_bulle(tab_500[i])
    i = i + 1
print(f"Moyenne = {calcul / 10}")

print("tab_5000 : ")
calcul = 0
i = 0
while i < 10:
    calcul = calcul + trie_bulle(tab_5000[i])
    i = i + 1
print(f"Moyenne = {calcul / 10}")




print("")



valeur_recherchee = (5000)
print("RECHERCHE :")
print("tab_10 : ")
calcul = 0
i = 0
while i < 10:
    calcul = calcul + recherche(tab_10[i], valeur_recherchee)
    i = i + 1
print(f"Moyenne = {calcul / 10}")

print("tab_500 : ")
calcul = 0
i = 0
while i < 10:
    calcul = calcul + recherche(tab_500[i], valeur_recherchee)
    i = i + 1
print(f"Moyenne = {calcul / 10}")

print("tab_5000 : ")
calcul = 0
i = 0
while i < 10:
    calcul = calcul + recherche(tab_5000[i], valeur_recherchee)
    i = i + 1
print(f"Moyenne = {calcul / 10}")



print("")



print("RECHERCHE DICHO :")
print("tab_10 : ")
calcul = 0
i = 0
while i < 10:
    calcul = calcul + recherche_dicho(tab_10[i], valeur_recherchee)
    i = i + 1
print(f"Moyenne = {calcul / 10}")

print("tab_500 : ")
calcul = 0
i = 0
while i < 10:
    calcul = calcul + recherche_dicho(tab_500[i], valeur_recherchee)
    i = i + 1
print(f"Moyenne = {calcul / 10}")

print("tab_5000 : ")
calcul = 0
i = 0
while i < 10:
    calcul = calcul + recherche_dicho(tab_5000[i], valeur_recherchee)
    i = i + 1
print(f"Moyenne = {calcul / 10}")




print("")



print("RECHERCHE DICHO REC :")
print("tab_10 : ")
calcul = 0
i = 0
while i < 10:
    calcul = calcul + recherche_dicho_recursive(tab_10[i], valeur_recherchee)
    i = i + 1
print(f"Moyenne = {calcul / 10}")

print("tab_500 : ")
calcul = 0
i = 0
while i < 10:
    calcul = calcul + recherche_dicho_recursive(tab_500[i], valeur_recherchee)
    i = i + 1
print(f"Moyenne = {calcul / 10}")

print("tab_5000 : ")
calcul = 0
i = 0
while i < 10:
    calcul = calcul + recherche_dicho_recursive(tab_5000[i], valeur_recherchee)
    i = i + 1
print(f"Moyenne = {calcul / 10}")




print("")
print("")
print("")
print("")




print("Donc pour les algos de tri il faudra utiliser le tri fusion qui est enormement plus efficace que le tri selection et le tri à bulle")
print("")
print("Pour les recherches il faudra utiliser la recherche dichotomique recursive qui est légerement plus efficace pour un faible nombre de valeur mais encore plus pour un grand nombre de valeur par rapport à la recherche classique")
