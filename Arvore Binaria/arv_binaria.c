#include<stdio.h>
#include<stdlib.h>

typedef struct arv{
int info;
struct arv* esq;
struct arv* dir;
}Arv;

void imprime(Arv* A){
if(A!=NULL){
printf("%d ",A->info);
imprime(A->esq);
imprime(A->dir);
	}
}

Arv* arv_criavazia (void){
return NULL;
}

Arv* arv_cria(int c, Arv* sae, Arv* sad){
Arv* p=(Arv*)malloc(sizeof(Arv));
p->info = c;
p->esq = sae;
p->dir = sad;
return p;
}

int contNos(Arv* a){
int cont=0;

if(a==NULL)
return 0;

cont+= contNos(a->esq);
cont+= contNos(a->dir);

return ++cont;
}

int maiorNo(Arv* a){
int esq =0;
int dir =0;

if(a==NULL)
return 0;

esq=maiorNo(a->esq);
dir=maiorNo(a->dir);

if(esq>dir && esq > a->info){
return esq;
}else if(dir> esq && dir > a->info){
return dir;
}else{
return a->info;
}

}

//Exemplo:
// 5
// / \
// 10 15
// \
// 12
main(){
Arv *a =arv_cria(5,
arv_cria(10,
arv_criavazia(),
arv_cria(12,arv_criavazia(),arv_criavazia())),
arv_cria(15, arv_criavazia(),arv_criavazia())
);

printf("%d %d %d %d\n", a->info,
a->esq->info, a->esq->dir->info,
a->dir->info);

imprime(a);

}