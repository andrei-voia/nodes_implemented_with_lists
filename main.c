#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct elem{
     int info;
     struct elem *urm;
  }nod;


nod *caut(nod *radacina, int inf)
{
    nod *p;
    for (p=radacina; p!=NULL && p->info!=inf; p=p->urm);
        if (p!=NULL)
            return p;
    return NULL;
}


void listez(nod *radacina)
{
    nod *p;
    for (p=radacina; p!=NULL; p=p->urm)
       printf("Valoarea: %d la adresa %p\n",p->info,p);
}


nod *sterg_incep(nod *radacina)
{
    nod *aux;
    if (radacina==NULL)
    {
     printf("lista e vida\n");
     return NULL;
    }
       aux=radacina;
       radacina=radacina->urm;
       free(aux);
       return radacina;
}


nod *creaza_nod(int infonou)
{
    nod *p;
    if ((p=(nod *)malloc(sizeof(nod)))==NULL)
    {
       printf("Eroare: memorie insuficienta\n");
      return NULL;
    }
    else
    {
       p->info=infonou;
       p->urm=NULL;
       return p;
    }
}


nod * intro_incep(nod *radacina, nod *nou)
{
    nou->urm=radacina;
    radacina=nou;
    return radacina;
}


nod * intro_sfs(nod *ultim, nod *nou)
{
   if (ultim!=NULL)
   ultim->urm=nou;
   return nou;
}


int main()
{
    char o;
    int val;
    nod *radacina=NULL;
    nod *nou, *ultim=NULL;
    puts("");
    while(1)
    {
       puts("");
       puts("a : adauga un nod la inceput");
       puts("d : adauga un nod la sfarsit");
       puts("c : cauta un nod");
       puts("s : sterge primul nod");
       puts("l : listeaza tot");
       puts("t : termina programul");
       printf("\nOptiunea: ");
       while(isspace(o=getchar()) );
       printf("\n");
       if (!isspace(o))
          switch (tolower(o))
         {
          case 'a': {  printf("adauga inceput   nr=");
               scanf("%d", &val);
               nou=creaza_nod(val);
               if (radacina==NULL)  ultim=nou;
               radacina=intro_incep(radacina, nou);
              break;}
         case 'd': {  printf("adauga sfarsit   nr=");
             scanf("%d", &val);
             nou=creaza_nod(val);
             if (radacina==NULL)  radacina=nou;
             ultim=intro_sfs(ultim, nou);
             break;}
         case 'c': {  puts("cauta si tipareste un nod");
             printf("nr=");
             scanf("%d", &val);
             if ((nou=caut(radacina, val))!=NULL)
                printf(" Valoare:%d\n", nou->info);
             else
                  printf("Eroare: Identificator nedefinit\n");
             break;
         }
         case 's':{   printf("stergere primul nod\n");
             radacina=sterg_incep(radacina);
             if (radacina==NULL) ultim=NULL;
             break;}
         case 'l':{  puts("listare");
             listez(radacina);
             break;}
         case 't':
             return;
         default:
             printf("Eroare : Comanda inexistenta\n");
         }
   }
}
