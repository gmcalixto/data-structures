//
//  Created by Gustavo Calixto on 02/05/17.
//  Copyright © 2017 Gustavo Calixto. All rights reserved.
//
//algoritmo de ordenação FT/UNICAMP
//http://www.ft.unicamp.br/liag/siteEd/
//todos os direitos reservados


#include <stdio.h>
#include <stdlib.h>


void bubleSort( int vetorDesordenado[], int tamanhoVetor );
void trocarPosicaoValores( int *posicaoA, int *posicaoB );
void selectionSort( int vetorDesordenado[], int tamanhoVetor );
void insertionSort(int vetorDesordenado[], int tamanhoVetor );
void mergeSort( int *vetorDesorndeado, int posicaoInicio, int posicaoFim );
void quickSort( int *vetorDesordenado, int posicaoInicio, int posicaoFim );
int partition( int *vetorDesordenado, int posicaoInicio, int posicaoFim );



int main(int argc, const char * argv[]) {

    int vetor[100];
    int i;
    
    //preenchendo o vetor para o pior caso
    for(i=100;i>0;i--){
        vetor[100-i]=i;
    }
    
    //bubleSort(vetor, 100);
    //selectionSort(vetor, 100);
    //insertionSort(vetor, 100);
    quickSort(vetor, 0, 99);
    
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

void mergeSort( int *vetorDesorndeado, int posicaoInicio, int posicaoFim )
{
    int i,j,k,metadeTamanho,*vetorTemp;
    if ( posicaoInicio == posicaoFim ) return;
    
    // ordenacao recursiva das duas metades
    metadeTamanho = ( posicaoInicio+posicaoFim )/2;
    mergeSort( vetorDesorndeado, posicaoInicio, metadeTamanho);
    mergeSort( vetorDesorndeado, metadeTamanho+1,posicaoFim );
    
    // intercalacao no vetor temporario t
    i = posicaoInicio;
    j = metadeTamanho+1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim-posicaoInicio+1));
    
    while( i < metadeTamanho+1 || j  < posicaoFim+1 )
    {
        if ( i == metadeTamanho+1 )
        { // i passou do final da primeira metade, pegar v[j]
            vetorTemp[k] = vetorDesorndeado[j];
            j++;
            k++;
        }
        else
        {
            if (j==posicaoFim+1)
            {
                // j passou do final da segunda metade, pegar v[i]
                vetorTemp[k] = vetorDesorndeado[i];
                i++;
                k++;
            }
            else
            {
                if (vetorDesorndeado[i] < vetorDesorndeado[j])
                {
                    vetorTemp[k] = vetorDesorndeado[i];
                    i++;
                    k++;
                }
                else
                {
                    vetorTemp[k] = vetorDesorndeado[j];
                    j++;
                    k++;
                }
            }
        }
        
    }
    // copia vetor intercalado para o vetor original
    for( i = posicaoInicio; i <= posicaoFim; i++ )
    {
        vetorDesorndeado[i] = vetorTemp[i-posicaoInicio];
    }
    free(vetorTemp);
}

void quickSort( int *vetorDesordenado, int posicaoInicio, int posicaoFim )
{
    int pivot;
    if (posicaoInicio < posicaoFim)
    {
        pivot = partition( vetorDesordenado, posicaoInicio, posicaoFim);
        quickSort( vetorDesordenado, posicaoInicio, pivot);
        quickSort(vetorDesordenado, pivot+1, posicaoFim);
    }
}

int partition( int *vetorDesordenado, int posicaoInicio, int posicaoFim )
{
    int x,i,j,auxiliar;
    x = vetorDesordenado[posicaoInicio];
    i = posicaoInicio - 1;
    j = posicaoFim + 1;
    
    for(;;)
    {
        do { j--; } while( vetorDesordenado[j] > x );
        do { i++; } while( vetorDesordenado[i] < x );
        
        if (i < j)
        {
            auxiliar = vetorDesordenado[i];
            vetorDesordenado[i] = vetorDesordenado[j];
            vetorDesordenado[j] = auxiliar;
        }
        else
        {
            return j;
        }
    }
}
