//  ArvoreBinaria
//
//  Created by Gustavo Calixto on 04/04/17.
//  Copyright © 2017 Gustavo Calixto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//estrutura da célula
struct celula{
    int dado;
    struct celula *pe;
    struct celula *pd;
};

//assinatura das funções
void insere(struct celula **raiz,int d);
void busca(struct celula *raiz,int d);
void varredura_inorder(struct celula *raiz);
void varredura_preorder(struct celula *raiz);
void varredura_postorder(struct celula *raiz);
int altura(struct celula *raiz);
void remover(struct celula *raiz,int d,struct celula *anterior);
void remover_tudo(struct celula **raiz);

//teste de árvore
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Arvore Binaria\n");
    
    struct celula *raiz = NULL;
    
    insere(&raiz,11);
    insere(&raiz,22);
    insere(&raiz,9);
    insere(&raiz,10);
    insere(&raiz,2);


    
    busca(raiz,10);
    busca(raiz,2);
    
    remover(raiz, 11, NULL);
    
    varredura_inorder(raiz);
    
    printf("OK");
    
    remover_tudo(&raiz);
    
    varredura_preorder(raiz);
    
    printf("Altura: %d\n",altura(raiz));
    
    return 0;
}


//insere célula na árvore
void insere(struct celula **raiz,int d){
    if(*raiz == NULL){
        *raiz = malloc(sizeof(struct celula));
        
        (*raiz)->dado = d;
        (*raiz)->pe = NULL;
        (*raiz)->pd = NULL;
    }
    else{
        if(d < (*raiz)->dado){
            if((*raiz)->pe == NULL){
                (*raiz)->pe = malloc(sizeof(struct celula));
                (*raiz)->pe->dado = d;
                (*raiz)->pe->pe = NULL;
                (*raiz)->pe->pd = NULL;
            }
            else{
                insere(&((*raiz)->pe),d);
            }
        }
        else{
            if((*raiz)->pd == NULL){
                (*raiz)->pd = malloc(sizeof(struct celula));
                (*raiz)->pd->dado = d;
                (*raiz)->pd->pe = NULL;
                (*raiz)->pd->pd = NULL;
            }
            else{
                insere(&((*raiz)->pe),d);
            }
        }
    }
}

//busca célula na árvore
void busca(struct celula *raiz,int d){
    if(raiz == NULL){
        return;
    }
    else{
        if(raiz->dado == d){
            printf("Celula %d encontrada\n",d);
            return;
        }
        else{
            busca(raiz->pe,d);
            busca(raiz->pd,d);
        }
    }
}

//varredura inorder (e-r-d)
void varredura_inorder(struct celula *raiz){
    if(raiz != NULL){
        varredura_inorder(raiz->pe);
        printf("%d \n",raiz->dado);
        varredura_inorder(raiz->pd);
    }
    
}
//varredura preorder (r-e-d)
void varredura_preorder(struct celula *raiz){
    if(raiz != NULL){
        printf("%d \n",raiz->dado);
        varredura_preorder(raiz->pe);
        varredura_preorder(raiz->pd);
    }
    
}
//varredura postorder (e-d-r)
void varredura_postorder(struct celula *raiz){
    if(raiz != NULL){
        varredura_postorder(raiz->pe);
        varredura_preorder(raiz->pd);
        printf("%d \n",raiz->dado);
    }
    
}
//altura da arvore ou nó
int altura(struct celula *raiz){
    if(raiz ==  NULL){
        return -1;
    }
    else{
        int ae = altura(raiz->pe);
        int ad = altura(raiz->pd);
        if(ae<ad) return ae+1;
        else return ad+1;
    }
}

//remove uma célula na árvore
void remover(struct celula *raiz,int d,struct celula *anterior){
    if(raiz == NULL){
        return;
    }
    else{
        if(raiz->dado == d){
            //caso 1: folha da arvore
            if(raiz->pd == NULL && raiz->pe == NULL){
                if(anterior == NULL){
                    free(raiz);
                }
                else if(anterior->pd->dado == d){
                    free(anterior->pd);
                    anterior->pd = NULL;
                }
                else if(anterior->pe->dado == d){
                    free(anterior->pe);
                    anterior->pe = NULL;
                }
            }
            //caso 2: celula somente com adjacente à direita
            else if (raiz->pe == NULL){
                anterior->pd = raiz->pd;
                free(raiz);
            }
            //caso 2: celula somente com adjacente à esquerda
            else if(raiz->pd == NULL){
                anterior->pe = raiz->pe;
                free(raiz);
            }
            //caso 3: celula com ambos ponteiros preenchidos (inclusive a raiz)
            else{
                struct celula *temp = raiz->pe;
                while(temp->pd != NULL){
                    anterior = temp;
                    temp = temp->pd;
                }
                raiz->dado = temp->dado;
                anterior->pd = NULL;
                free(temp);
            }
        }
        else{
            remover(raiz->pe,d,raiz);
            remover(raiz->pd,d,raiz);
        }
    }
}
//remove todos os elementos da arvore recursivamente
void remover_tudo(struct celula **raiz){
    if(*raiz == NULL){
        return;
    }
    else{
        remover_tudo(&((*raiz)->pe));
        remover_tudo(&((*raiz)->pd));
        free(*raiz);
    }
    *raiz = NULL;
}