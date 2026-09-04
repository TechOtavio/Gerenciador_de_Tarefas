#include <corecrt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Tarefa{

    int Id;
    char *Nome;
    char *Descricao;
    char *Status;

    struct Tarefa *prox;
}Tarefa;


Tarefa *inicio = NULL;
int tam = 0;

void add_Tarefa(int id , char *nome , char *descricao , char *status , int pos){
    Tarefa *novo = malloc(sizeof(Tarefa));

    novo->Id = id;
    novo->Nome = nome;
    novo->Descricao = descricao;
    novo->Status = status;
    novo->prox = NULL;

    //Conectar os Nós;

    if(inicio == NULL){
        inicio = novo;
        tam++;
    } else {
        if(pos == 0){
            novo->prox = inicio;
            inicio = novo;
            tam ++;
        } else if(pos == tam){
            Tarefa *aux = inicio;
            for(int i = 0; i < tam -1 ; i++){
                aux = aux->prox;
            }
            aux->prox = novo;
            tam++;
        } else {
            Tarefa *aux = inicio;
            for( int i = 0; i < pos - 1 ; i++){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
            tam++;
        }
    }
}


void ler_tarefas(){
}




void atualizar_tarefa(int id_procurado , char *nome_novo , char *descricao_novo , char *status_novo){
    if (inicio == NULL){
        printf("\n Lista Vazia\n");
        return;
    }

    Tarefa *aux = inicio;

    while (inicio != NULL){
        if (aux->Id == id_procurado){
            aux->Id = id_procurado;
            aux->Nome = nome_novo;
            aux->Descricao = descricao_novo;
            aux->Status = status_novo;

            return;
        }
    aux = aux->prox;
    }

    printf("\n ID nao encontrado\n");
}


int main(){
}
