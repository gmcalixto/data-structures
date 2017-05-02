//
//  main.cpp
//  TesteCpp
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

//assinatura das funcoes
Celula* insere(int _dado,Celula *inicio);
Celula* busca(int _dado,Celula *inicio);
void imprime_dados(Celula *inicio);
void limpa_celulas(Celula *inicio);
void insere_celula(int apos_dado, Celula *inicio);
void insere_celula(int dado_busca,int novo_numero, Celula *inicio);
Celula* busca_anterior(Celula *inicio, Celula *frente);
Celula* remove_celula(int dado_busca, Celula *inicio);



int main(int argc, const char * argv[]) {
    
    Celula *minhaLista = NULL;
    
    minhaLista = insere(1, minhaLista);
    minhaLista = insere(4, minhaLista);
    minhaLista = insere(5, minhaLista);
    minhaLista = insere(10, minhaLista);
    minhaLista = insere(9, minhaLista);
    
    imprime_dados(minhaLista);
    insere_celula(4, 17, minhaLista);
    cout << "Lista com 17 adicionado" << endl;
    imprime_dados(minhaLista);
    
    minhaLista = remove_celula(5, minhaLista);
    cout << "Lista com 5 removido" << endl;
    imprime_dados(minhaLista);
    
    Celula *resultado = busca(4, minhaLista);
    if(resultado != NULL){
        cout << "No encontrado " << resultado->dado << " endereco " << resultado << endl;
    }
    else{
        cout << "Nao encontrado" << endl;
    }
    
    
    limpa_celulas(minhaLista);
    
    
}

//insere elemento na ponta da lista
Celula* insere(int _dado,Celula *inicio){
    
    Celula *temp;
    
    if(inicio == NULL){
        inicio = new Celula();
        inicio->dado = _dado;
        inicio->proximo = NULL;
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
        return inicio;
    }
}

//busca elemento e retorna referência
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

//retorna o elemento anterior ao indicado na variavel frente
Celula* busca_anterior(Celula *inicio, Celula *frente){
    
    Celula *temp;
    
    if(inicio == NULL){
        return NULL;
    }
    else{
        temp = inicio;
        do{
            if(temp->proximo == frente){
                return temp;
            }
            temp = temp->proximo;
            
        }while(temp->proximo != NULL);
        
        //somente entra se for o caso da ultima celula
        if(temp->proximo == frente){
            return temp;
        }
    }
    
    return NULL;
}

//imprime toda a lista
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
        
        cout << "Celula " << cont+1 << "Valor " << temp->dado << endl;
    }
}

//apaga todas as celulas
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

//insere uma celula apos um dado indicado
void insere_celula(int dado_busca,int novo_numero, Celula *inicio){
    
    Celula *temp = busca(dado_busca,inicio);
    
    Celula *nova = new Celula();
    nova->dado = novo_numero;
    
    nova->proximo = temp->proximo;
    temp->proximo = nova;
}

//remove uma celula indicada
Celula* remove_celula(int dado_busca, Celula *inicio){
    
    Celula *temp = busca(dado_busca,inicio);
    
    if(temp == inicio){
        temp = inicio->proximo;
        delete inicio;
        return temp;
    }
    else{
        Celula *anterior = busca_anterior(inicio, temp);
        anterior->proximo = temp->proximo;
        delete temp;
        return inicio;
    }
}

