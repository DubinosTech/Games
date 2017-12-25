
def sommeListePos_rec(l,n):
   '''C est la fonction recursive qui prend une liste et calcule
et retourne la somme des entiers positifs'''
   if l[n-1]>=0:
      s=l[n-1]
   else : s=0
   if n<1:
      s=0
   else:
      sp=sommeListePos_rec(l,n-1)
      s=s+sp
         

   return s      
      
ch = input('Veuillez entrer une liste des valeurs separees par virgules: ')
l = list(eval(ch))
print("La somme des entiers positifs est:",sommeListePos_rec(l,len(l)))
