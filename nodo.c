/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"

nodo CriaInicial(int id, int state[9])
{
    nodo ini = (nodo) malloc(sizeof(struct Nodo));
    if(ini != NULL)
    {
        ini->id = id;
        memcpy(ini->estado, state, sizeof(int) * 9);//copia pai pro filho
        
        ini->filhos = NULL;
                
        return ini;
    }
    //Se nao criar o nodo
    exit(EXIT_FAILURE);
}

//cria nodo do tipo filho, copia, e troca as posições
nodo CriaNodoFilho(nodo pai, int pos, int posAux)//p1 e p2 devem trocar de posição
{
	nodo novo = (nodo) malloc(sizeof(struct Nodo));
	//if (!(novo = (nodo) malloc(sizeof(struct Nodo)))) return NULL;
        
	novo->id = 5;//***********
	novo->pai = pai;    
 
	memcpy(novo->estado, pai->estado, sizeof(int) * 9);//copia pai pro filho

	//troca posições
	int aux = novo->estado[pos]; 
	novo->estado[pos] = novo->estado[posAux];
	novo->estado[posAux] = aux;
        
        lista filho = (lista) malloc(sizeof(struct Lista));
	filho->n = novo;
        filho->prox = NULL;
        
        if (pai->filhos == NULL) //Primeiro filho
        {
            pai->filhos = aux;
        }
        else
        {
            lista aux = pai->filhos;
            while(aux->prox != NULL)
            {
                aux = aux->prox;
            }
            aux->prox = filho;
        }
        

	return novo;
}