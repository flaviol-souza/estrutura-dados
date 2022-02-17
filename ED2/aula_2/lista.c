#include <stdio.h>
#include <stdlib.h>

#define VALOR int

typedef struct no
{
    VALOR valor;
    struct no *proximo;
} NO;

typedef struct
{
    NO *inicio;
    NO *fim;
} LISTA;

LISTA f;

/*Cria uma lista vazia. Deve ser usado antes de qualquer outra operação*/
void criar(LISTA *lista)
{
    lista->inicio= NULL;
    lista->fim = NULL;
}

/*Retorna 1 se a lista estiver vazia*/
int esta_vazia(LISTA *lista)
{
    return (lista->inicio == NULL);
}

/*Reinicializa uma lista existente q como uma lista vazia removendo todos os seus elementos.*/
void limpa_lista(LISTA *lista)
{
    NO *ndel, *proximoNo;
    if (esta_vazia(lista) != 0)
    {
        proximoNo = lista->inicio;
        while (proximoNo != NULL)
        {
            ndel = proximoNo;
            proximoNo = proximoNo->proximo;
            free(ndel);
        }
    }
    criar(lista);
}

/*Adiciona um item no fim da lista. 
Retorna true se operação realizada com sucesso.*/
int inserir(LISTA *lista, VALOR valor)
{
    NO *n;
    n = malloc(sizeof(NO));
    if (n == NULL)
        return 0; /*False*/

    n->valor = valor;
    n->proximo = NULL;
    
    if (esta_vazia(lista) == 1){
        lista->inicio = n;
    } else {
        lista->fim->proximo = n;
    }
        
    lista->fim = n;

    return 1; /*True*/
}

/*Remove um item do início da lista q. Retorna true se operação realizada com sucesso, false caso contrário*/
int remover(LISTA *lista, NO *no_removido)
{
    NO *no, *no_anterior = NULL;
    if (esta_vazia(lista) == 1)
        return 0; /*False*/

    no = lista->inicio;
    while(no != NULL){
        if(no->valor == no_removido->valor && no->proximo == no_removido->proximo){
            if(no_anterior == NULL){
                lista->inicio = no->proximo;
            } else {
                no_anterior->proximo =  no->proximo;
            }
            printf("\n\nNo de valor %i e com o proximo %p removido da lista.", no->valor, no->proximo);
            free(no);
            break;            
        }
        no_anterior = no;
        no = no->proximo;
    }
    

    return 1; /*True*/
}

NO *localizar(LISTA *lista, int valor_procurado){
    NO *no;
    if (esta_vazia(lista) == 1)
        return NULL; /*False*/

    no = lista->inicio;
    while(no != NULL){
        if(no->valor == valor_procurado){
            printf("\n\n No de valor %i localizado.",valor_procurado);
            return no;
        } else {
            no = no->proximo;
        }            
    }
    
    printf("\n No de valor %i NAO localizado.",valor_procurado);
    return NULL;
}

LISTA *inverter(LISTA lista){
    /*Crie uma funcao capaz de inverter a ordem dos itens da lista*/
}

/*Retorna o tamanho da lista*/
int tamanho(LISTA *lista)
{
    NO *no;
    int cont = 0;
    no = lista->inicio;

    while (no != NULL)
    {
        cont++;
        no = no->proximo;
    }
    return cont;
}

void imprimir_no(NO *no)
{
    if(no != NULL)
        printf("\n|V.: %i|P.: %p|", no->valor, no->proximo);
}

void imprimir(LISTA *lista)
{
    /*Imprime os elementos na sua ordem de precedência*/
    if (esta_vazia(lista) == 1){
        printf("\n\nA lista esta vazia\n\n");
    } 
    else
    {
        NO *no = lista->inicio;
        int t = tamanho(lista);
        printf("\n\nA lista tem %i nos", t);      

        while (no != NULL)
        {
            imprimir_no(no);
            no = no->proximo;
        }
    }
    return;
}

int main()
{
    NO *no;
    LISTA minhaLista;
    
    criar(&minhaLista);
    printf("Fila criada");

    inserir(&minhaLista, 17);
    imprimir(&minhaLista);

    inserir(&minhaLista, 21);
    imprimir(&minhaLista);

    inserir(&minhaLista, 19);
    imprimir(&minhaLista);

    inserir(&minhaLista, 11);
    imprimir(&minhaLista);
    
    no = localizar(&minhaLista, 21);
    imprimir_no(no);
    no = localizar(&minhaLista, 19);
    imprimir_no(no);

    remover(&minhaLista, no);
    imprimir(&minhaLista);

    return 0;
}