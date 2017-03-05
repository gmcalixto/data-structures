//
//  linked_list.cpp
//  Exemplo de Lista Encadeada
//
//  Created by Gustavo Calixto on 13/02/17.
//  Copyright © 2017 Gustavo Calixto. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

//estrutura da célula
struct Registro{
    int dado;
    struct Registro *proximo;
};

//tipo de dado struct Registro redefinido para Celula através do comando typedef
typedef struct Registro Celula;

Celula* insere(int _dado,Celula *inicio){
    
    Celula *temp;
    
    //se celula inicial for nula, cria a primeira celula
    if(inicio == NULL){
        inicio = new Celula();
        inicio->dado = _dado;
        inicio->proximo = NULL;
        cout << "No criado dado " << inicio->dado << " endereco " << inicio << endl;
        return inicio;
    }
    else{
        temp = inicio;
        
        while(temp->proximo != NULL){
            temp = temp->proximo;
        }
        
        temp->proximo = new Celula();
        temp->proximo->dado = _dado;
        temp->proximo->proximo = NULL;
        cout << "No criado dado " << temp->proximo->dado << " endereco " << temp->proximo << endl;
        return inicio;
    }
}

Celula* busca(int _dado,Celula *inicio){
    
    Celula *temp;
    
    if(inicio == NULL){
        return NULL;
    }
    else{
        temp = inicio;
        do{
            if(temp->dado == _dado){
                return temp;
            }
            temp = temp->proximo;
            
        }while(temp->proximo != NULL);
        
        //somente entra se for o caso da ultima celula
        if(temp->dado == _dado){
            return temp;
        }
    }
    
    return NULL;
}

void imprime_dados(Celula *inicio){
    
    Celula *temp;
    int cont = 1;
    
    if(inicio == NULL){
        cout << "Sem celulas" <<endl;
    }
    else if(inicio->proximo == NULL){
        cout << "Celula " << cont << "Valor " << temp->dado << endl;
    }
    else{
        temp = inicio;
        do{
            cout << "Celula " << cont << "Valor " << temp->dado << endl;
            temp = temp->proximo;
            cont++;
        }while(temp->proximo != NULL);
        
        //imprime ultima celula
        cout << "Celula " << cont+1 << "Valor " << temp->dado << endl;
    }
}

void limpa_celulas(Celula *inicio){
    
    Celula *temp,*anterior;
    
    if(inicio == NULL){
        cout << "Sem celulas" <<endl;
        return;
    }
    else if(inicio->proximo == NULL){
        delete inicio;
    }
    else{
        temp = inicio;
        while(temp->proximo != NULL){
            anterior = temp;
            temp = temp->proximo;
            cout << "No removido dado " << anterior->dado << " endereco " << anterior << endl;
            delete anterior;
        }
        
        cout << "No removido dado " << temp->dado << " endereco " << temp << endl;
        delete temp;
    }
}

int main(int argc, const char * argv[]) {
    
    Celula *minhaLista;
    
    minhaLista = insere(1, minhaLista);
    minhaLista = insere(4, minhaLista);
    minhaLista = insere(5, minhaLista);
    minhaLista = insere(10, minhaLista);
    minhaLista = insere(9, minhaLista);
    
    imprime_dados(minhaLista);
    
    Celula *resultado = busca(20, minhaLista);
    if(resultado != NULL){
        cout << "No encontrado " << resultado->dado << " endereco " << resultado << endl;
    }
    else{
        cout << "Nao encontrado" << endl;
    }
    
    
    limpa_celulas(minhaLista);
    
    
}
