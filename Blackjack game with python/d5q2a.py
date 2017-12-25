def recursive(n,b):

   for i in range(n):
      print('*',end='')
      
   print()
      
   if n>1:
      recursive(n-1,b)
   else:recursive2(n,b)
   
     
      
def recursive2(n,b):
   for i in range(n):
      print('*',end='')
      
   print()
      
   if n<b:
     
      recursive2(n+1,b)
  
   


def etoiles(n):
   "C<est la fonction qui fait appelle aux fonctions recursives"
   recursive(n,n)
n=int(input("entrer valeur : "))
etoiles(n)


