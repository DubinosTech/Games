def effaceTableau (tab):
   '''
   (list) -> None
   Cette fonction prepare le tableau de jeu (la matrice) 
   en mettant '-' dans tous les elements.
   Elle ne crée pas une nouvelle matrice
   Preconditions: tab est une reference a une matrice n x n qui contient '-', 'X' ou 'O'
   '''
   for i in range(len(tab)):
      for j in range(len(tab[i])):
         tab[i][j]='-'
   
    # a completer
    
    # retourne rien

      
def verifieGagner(tab):  
    '''(list) ->  bool
    * Preconditions: tab est une reference a une matrice n x n qui contient '-', 'X' ou 'O'
    * Verifie s'il y a un gagnant.
    * Cherche pour 3 X's et O's dans une ligne, colonne, et diagonal.
    * Si on a trouvé, affiche le gagnant (le message "Joueur X a gagné!" 
    * ou "Joueur O a gagné!") et retourne True.
    * S'il y a un match nul (verifie ca avec la fonction testMatchNul),
    * affiche "Match nul" et retourne True.
    * Si le jeu n'est pas fini, retourne False.
    * La fonction appelle les fonctions testLignes, testCols, testDiags
    * pour verifier s'il y a un gagnant.
    * Ces fonctions retournent le gagnant 'X' ou 'O', ou '-' s'il n'y a pas de gagnant
    '''

    "La condition appelle les fonctions testLignes, testCols, testDiags"
    " pour verifier s'il y a un gagnant et retourne le gagnant"
    if testLignes(tab)=='X' or testDiags(tab)=='X' or testCols(tab) =='X':
       print("Le joueur X est gagnant")
       return True
    elif testLignes(tab)=='O' or testDiags(tab)=='O' or testCols(tab) =='O':
       print("Le joueur O est gagnant")
       return True
    else :
       if testMatchNul(tab)==False:
          return False
       elif  testMatchNul(tab)==True:
          print("Match Nul")
          return True
          
   
      
    
         
    

    # a completer
   
    return False  # a changer

 
def testLignes(tab):
   ''' (list) ->  str
   * verifie s’il y a une ligne gagnante.
   * cherche trois 'X' ou trois 'O' dans une ligne.  
   * Si on trouve, le caractere 'X' ou 'O' et retourné, sinon '-' est retourné.
   * Preconditions: tab est une reference a une matrice n x n qui contient '-', 'X' ou 'O'
   '''
   for i in range(len(tab)):#selon ligne
      for j in range(len(tab[i])):
         if tab[i][j]=='X':drap= True
         else :
            drap = False
            
            break
      if drap==True:return 'X'
                
   for i in range(len(tab)):#selon la colonne
      for j in range(len(tab[i])):
         if tab[i][j]=='O':val= True 
         else :
            val = False
            break
      if val==True:return 'O'
   
   
   return '-'

                   

  
  
def testCols(tab):
   ''' (list) ->  str
   * verifie s’il y a une colonne gagnante.
   * cherche trois 'X' ou trois 'O' dans une colonne.  
   * Si on trouve, le caractere 'X' ou 'O' et retourné, sinon '-' est retourné.
   * Preconditions: tab est une reference a une matrice n x n qui contient '-', 'X' ou 'O'
   '''
   drap=False
   for i in range(len(tab)):# selon la ligne
         for j in range(len(tab[i])):
             if tab[j][i]=='X':
                
                drap= True 
             else :
                drap = False
                
                break
         if drap==True:
            
            return 'X'
   for i in range(len(tab)):#selon colonne
      for j in range(len(tab[i])):
         if tab[j][i]=='O':
            val= True
         else :
            val = False
            break
      if val==True:return 'O'

   
   
   return '-'
   
  #a changer pour retourner le gagnant, ou '-' s'il n'y a pas de gagnant

   
def testDiags(tab):
   ''' (list) ->  str
   * cherche trois 'X' ou trois 'O' dans une diagonale.  
   * Si on trouve, le caractere 'X' ou 'O' et retourné
   * sinon '-' est retourné.
   * Preconditions: tab est une reference a une matrice n x n qui contient '-', 'X' ou 'O'
   '''
   for i in range(len(tab)):
      for j in range(len(tab[i])):#selon Diagonal
         if i==j:
            if tab[i][j]=='X':drap= True 
            else :
               drap =False
               return testO(tab)# retourne l<element trouver dans la diagonale 
               
               
               
   if drap==True:return 'X'

def testO(tab):
   "cette fonction verifie s<il y a les <O> dans la diagonale"
   for i in range(len(tab)):
      for j in range(len(tab[i])):#selon Diagonal
         if i==j:
            if tab[i][j]=='O':val= True 
            else :
               val = False
               return '-'
   
   if val==True:return 'O'
      

   # a completer
    
   # a changer pour retourner le gagnant, ou '-' s'il n'y a pas de gagnant

  
  
def testMatchNul(tab):
   ''' (list) ->  bool
   * verifie s’il y a un match nul
   * verifie si tous les elements de la matrice contiennent X ou O, pas '-'.  
   * Si on ne trouve pas de '-' dans la matrice, retourne True. 
   * S'il y a de '-', retourne false.
   * Preconditions: tab est une reference a une matrice n x n qui contient '-', 'X' ou 'O'
   '''
   
   for i in range(len(tab)):
      for j in range(len(tab[i])):
         if tab[i][j]=='-':
            return False
   
   return True
    
  

