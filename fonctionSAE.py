tab = [2020,752,1713,816,1438,1503,737,1943,907,1527,2050,746,1345,627,829,1647,1655,1901,1040,1410,1548,2124,633,1016,1211,1702,916,1032,1912,2002,1204,1907,1302,2156,726,1319,1427,1510,1826,1924,]

def trie_bulle(tab):
    compt=0
    n = len(tab)-1
    compt=compt+1
    trie = False
    compt=compt+1


    while (n > 0) and not trie:
        trie = True
        compt=compt+1
        i = 0
        compt=compt+1

        while i < n:
            compt=compt+1

            if tab[i] > tab[i+1]:
                compt=compt+1

                tmp = tab[i]   
                compt=compt+1

                tab[i]=tab[i+1]
                compt=compt+1

                tab[i+1]=tmp
                compt=compt+1

                trie = False
                compt=compt+1

            i=i+1 
            compt=compt+1

        n=n-1
        compt=compt+1

    print(tab,compt)
    return(tab)

#trie_bulle(tab)

def trie_1(tab):
    compt=0
    n = len(tab)
    compt=compt+1
    i = 0
    compt=compt+1
    while i < n - 1:
        compt=compt+1
        min_index = i
        compt=compt+1
        j = i + 1
        compt=compt+1
        while j < n:
            compt=compt+1
            if tab[j] < tab[min_index]:
                compt=compt+1
                min_index = j
                compt=compt+1
            j = j + 1
            compt=compt+1

        
        tmp = tab[i]
        compt=compt+1
        tab[i] = tab[min_index]
        compt=compt+1
        tab[min_index] = tmp
        compt=compt+1

        i = i + 1
        compt=compt+1
        
    print(tab,compt)
    return tab

trie_1(tab)



def insere_trie(tab,i):
    compt1=0
    v = tab[i]
    compt1=compt1+1
    j = i-1
    compt1=compt1+1
    while j >= 0 and tab[j] > v :
        compt1=compt1+1
        tab[j+1] = tab[j]
        compt1=compt1+1
        j = j-1
        compt1=compt1+1
    tab[j+1]=v
    compt1=compt1+1

    return compt1
   
    
def trie_insertion(tab):
    compt=0
 
    n = len(tab)
    compt=compt+1
    i = 1 
    compt=compt+1
    while i < n:
        compt=compt+1
        compt1=insere_trie(tab, i)
        
        compt=compt1 +compt
        i = i + 1

       
    
    print(tab,compt)
    return tab
 
trie_insertion(tab)



def recherche_dicho(tab,ind):
    val = ind
    i = 2
    n = len(tab)//2
    t = True
    
    
    if ind == n and n != tab[0] :
        ind = n - 1
        t = False
        
    if ind == tab[0] :
        ind = 0
        t = False
        
    
        
    while t:
        if tab[n] == ind:
            ind = n
            t = False
            
        else:
            if tab[n] < ind:
                n = n + (n//i)
                i = i + 2
            else:
                n = n - (n//2)
                i = i + 2
    
            
    
    
    print(val,"se trouve à l'indice :",ind)
    return(ind)


recherche_dicho(tab,1702)