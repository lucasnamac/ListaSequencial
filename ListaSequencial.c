#include<stdio.h>
#include<stdlib.h>
#include"ListSequencial.h"
#define MAX 10

struct lista{
    int no[MAX];
    int Fim;
};

Lista cria_lista(){
    Lista lst = (Lista) malloc(sizeof(struct lista));
    if (lst != NULL)
    lst->Fim = 0;
    return lst;
}

int lista_vazia(Lista lst) {
    if (lst->Fim == 0) return 1;
    else
    return 0;
}

int lista_cheia(Lista lst) {
    if (lst->Fim == MAX) return 1;
    else
    return 0;
}
int insere_elem(Lista lst, int elem) {
    if (lst == NULL || lista_cheia(lst) == 1)
    return 0;
    lst->no[lst->Fim] = elem;
    lst->Fim++;
    return 1;
}

int remove_elem (Lista lst, int elem) {
    if (lst == NULL || lista_vazia(lst) == 1) return 0;
    int i, Aux = 0;

    while (Aux < lst->Fim && lst->no[Aux] != elem)
    Aux++;

    if (Aux == lst->Fim) return 0;

    for (i = Aux+1; i < lst->Fim; i++) lst->no[i-1] = lst->no[i];

    lst->Fim--;
    return 1;
}

int insere_inicio(Lista lst, int elem){
    int i=0;
    if(lst==NULL || lista_cheia(lst)==1) return 0; //ERRO

     if(lista_vazia(lst)==1){
        lst->no[lst->Fim]=elem;
        lst->Fim++;
        return 1;
     }

    for(i=lst->Fim; i>0; i--){
        lst->no[i]= lst->no[i-1];
    }
    lst->no[0]=elem;
    lst->Fim++;
    return 1;
}

int imprimir(Lista lst){
    int i;
    if(lst==NULL || lista_vazia(lst)==1) return 0;

    for(i=0; i<lst->Fim; i++){
        printf("%d  ", lst->no[i]);
    }
    return 1;

}

void menu(){
    printf("\n");
    printf("1- Inserir\n");
    printf("2- Remover\n");
    printf("3- Imprimir\n");
    printf("4- Inserir no inicio\n");
    printf("5- Remove Impares\n");
    printf("6- Menor elemento\n");
    printf("7- Tamanho\n");
    printf("8- Intercala\n");

}

int RemoveImpares(Lista lst){
    int i;
    if(lst==NULL || lista_vazia(lst)) return 0;

    for(i=lst->Fim-1; i>=0; i--){
        if(lst->no[i] % 2 !=0){
            lst->no[i]=lst->no[i+1];
            lst->Fim--;
        }
    }
    return 1; //Sucesso
}

int menor(Lista lst, int *tam){
    int i;

    if(lst== NULL || lista_vazia(lst)==1) return 0; //Sucesso

    *tam=lst->no[lst->Fim];

    for(i=lst->Fim-1; i>=0; i--){
        if(lst->no[i]<*tam);
        *tam=lst->no[i];
    }
    return 1;

}

int tamanho(Lista lst, int *tam){
 if(lst==NULL || lista_vazia(lst)==1) return 0;
 else
    *tam=lst->Fim;
    return 1;
}


Lista intercala(Lista l1, Lista l2){
    Lista l3;
    int i, soma=l1->Fim +l2->Fim;
    int mal;
    if(lista_vazia(l1)==1 && lista_vazia(l2) == 1){
        return NULL;
    }
    if(soma <20){
        mal = 1;
    }
    else {
        mal =2;
    }
    l3 = (Lista) malloc ( mal * sizeof (struct lista));
    if(l3 == NULL){
        return NULL;
    }

    l3->Fim = 0;
    if(lista_vazia(l1)==1){ //Verifica se a lista 1 esta vazia
        for(i = 0; i < l2->Fim;i++){
            l3->no[i] = l2->no[i];
            l3->Fim++;
        }

    }
    else if(lista_vazia(l2)==1){    //Verifica se a lista 2 esta vazia
        for(i = 0; i < l1->Fim;i++){
            l3->no[l3->Fim] = l1->no[i];
            l3->Fim++;
        }
    }
    else{
        while(l3->Fim<soma){    // Insere na l3 os elementos da l1 e depois da l2
            for(i=0; i<l1->Fim; i++){
                l3->no[l3->Fim]=l1->no[i];
                l3->Fim++;
            }
            for(i=0; i<l2->Fim; i++){
                l3->no[l3->Fim]=l2->no[i];
                l3->Fim++;
            }
        }
    }

    return l3;
}







