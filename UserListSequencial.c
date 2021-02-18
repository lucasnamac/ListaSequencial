#include<stdio.h>
#include<stdlib.h>
#include"ListaSequencial.h"

int main(){
    int opcao, num, remove, qtd, menos, tam;
    Lista l1, l2, l3;
    l1=cria_lista();
    l2=cria_lista();
    l3=cria_lista();
    //system("color 6B");
    menu();
    scanf("%d", &opcao);

    while(opcao!= 9){

        switch(opcao){
            case(1):
                printf("Digite o numero que deseja inserir\n");
                scanf("%d", &num);
                insere_elem(l1, num);
            break;
            case(2):
                printf("Digite o numero que deseja remover\n");
                scanf("%d", &remove);
                remove_elem(l1, remove);

            break;

            case(3):
                imprimir(l1);
                break;
            case(4):
                printf("Digite o elemento para inserir no inicio\n");
                scanf("%d", &num);
                insere_inicio(l1, num);
                break;

            case(5):
                RemoveImpares(l1);
                break;
            case(6):
                menor(l1, &menos);
                printf("O menor elemento da lista e: %d", menos);
                break;

            case(7):
                tamanho(l1, &tam);
                printf("O tamanho da lista e: %d", tam);
                break;

            case(8):
                printf("Digite a quantidade de elementos da segunda lista\n");
                scanf("%d", &qtd);
                while(qtd--){
                    scanf("%d", &num);
                    insere_elem(l2, num);
                }
                l3=intercala(l1, l2);
                imprimir(l3);
                break;

        };

    menu();
    scanf("%d", &opcao);
    }


    return 0;
}
