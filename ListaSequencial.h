typedef struct lista* Lista;

Lista cria_lista();

int lista_vazia(Lista lst);

int lista_cheia(Lista lst);

int insere_elem(Lista lst, int elem);

int remove_elem (Lista lst, int elem);

int insere_inicio(Lista lst, int elem);

int imprimir(Lista lst);

void menu();

int RemoveImpares(Lista lst);

int menor(Lista lst, int *tam);

int tamanho(Lista lst, int *tam);

Lista intercala(Lista l1, Lista l2);


