//
//  Created by Gustavo Calixto on 02/05/17.
//  Copyright © 2017 Gustavo Calixto. All rights reserved.
//
//algoritmo FT/UNICAMP
//http://www.ft.unicamp.br/liag/siteEd/implementacao/bubble-sort.php
//todos os direitos reservados


#include <stdio.h>


void bubleSort( int vetorDesordenado[], int tamanhoVetor );
void trocarPosicaoValores( int *posicaoA, int *posicaoB );
void selectionSort( int vetorDesordenado[], int tamanhoVetor );
void insertionSort(int vetorDesordenado[], int tamanhoVetor );


int main(int argc, const char * argv[]) {

    int vetor[100];
    int i;
    
    //preenchendo o vetor para o pior caso
    for(i=100;i>0;i--){
        vetor[100-i]=i;
    }
    
    //bubleSort(vetor, 100);
    //selectionSort(vetor, 100);
    insertionSort(vetor, 100);
    
    for(i=0;i<100;i++){
        printf("%d ",vetor[i]);
    }
    
    return 0;
    
}


//  Complexidade Pior Caso - O(nˆ2)
void bubleSort( int vetorDesordenado[], int tamanhoVetor )
{
    int i, j;
    
    for( i = 0; i < ( tamanhoVetor - 1 );  i++ )
    {
        for( j=0; j <( tamanhoVetor - ( i + 1 ) ); j++ )
        {
            if( vetorDesordenado[j] > vetorDesordenado[j+1] )
            {
                trocarPosicaoValores( &vetorDesordenado[j], &vetorDesordenado[j+1] );
            }
        }
    }
}

//  Complexidade Pior Caso - O(nˆ2)
void selectionSort( int vetorDesordenado[], int tamanhoVetor )
{
    int i, j, posicaoValorMinimo;
    
    for (i = 0; i < ( tamanhoVetor - 1 ); i++)
    {
        posicaoValorMinimo = i;
        for (j = ( i + 1 ); j < tamanhoVetor; j++)
        {
            if( vetorDesordenado[j] < vetorDesordenado[posicaoValorMinimo] )
            {
                posicaoValorMinimo = j;
            }
        }
        
        if ( i != posicaoValorMinimo )
        {
            trocarPosicaoValores( &vetorDesordenado[i], &vetorDesordenado[posicaoValorMinimo] );
        }
    }
}

//  Complexidade Pior Caso - O(nˆ2)
void insertionSort(int vetorDesordenado[], int tamanhoVetor )
{
    int i, j, valorAtual;
    
    for( j=1; j < tamanhoVetor; j++ )
    {
        valorAtual = vetorDesordenado[j];
        i = j-1;
        
        while(i >= 0 && vetorDesordenado[i] > valorAtual)
        {
            vetorDesordenado[i+1] = vetorDesordenado[i];
            i--;
        }
        
        vetorDesordenado[i+1] = valorAtual;
    }
}

void trocarPosicaoValores( int *posicaoA, int *posicaoB )
{
    int temporario;
    temporario = *posicaoA;
    *posicaoA = *posicaoB;
    *posicaoB = temporario;
}