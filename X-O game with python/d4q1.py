def exo1():
   # Cette fonction est la fonction mere qui prend une matrice de l<utilisateur et retourne d<autre matrice
   print("Entrer les éléments de la matrice avec espaces entre les colonnes.")
   print("Une rangée par ligne, et une ligne vide à la fin.")
   
   matrice=[]
   while True:
      ligne = input()
      if not ligne: break
      valeurs = ligne.split()
      rangee = [int(val) for val in valeurs]
      matrice.append(rangee)
      
   # cette partie AFFICHE LES MATRICES ET FAIT APPELLE A D<AUTRE FONCTIONS POUR MODIFIER LES MATRICES 
   print("la matrice est :")
   print(matrice)
   print("Apres exécution de la fonction ajoute, la matrice est:")
   print(ajout(matrice))
   print("Une nouvelle matrice créée avec ajoute_V2: ")
   print(ajoutV2(matrice))
   print("Apres exécution de la fonction ajoute_V2, la matrice initiale est:")
   print(matrice)
   
def ajout(mat):
   # CETTE fonction prend une matrice la modifie en ajoutant 1 et retournne la matrice modifier
   for i in range(len(mat)):
      
      for j in range(len(mat[i])):
         mat[i][j]=1+mat[i][j]
   return mat

def ajoutV2(mat):
   # cette  fonction prend une matrice et stock les valeurs de chaque element dans une autre matrice en ajoutant 1
   # et ne modifie pas la matrice initiale et retourne la nouvelle matrice creer
   newmat=[]
   for i in range(len(mat)):
      newmat.append([])
      for val in (mat[i]):
         
         v=val+1
         newmat[i].append(v)
   return newmat

exo1()
         
