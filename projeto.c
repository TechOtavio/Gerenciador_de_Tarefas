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
        }
    }
}


void ler_tarefas(){
    
}

    
int main(){


}