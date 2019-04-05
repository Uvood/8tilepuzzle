/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

nodo CriaInicial(int id, int state)
{
    nodo ini = (nodo) malloc(sizeof(struct Nodo));
    if(ini != NULL)
    {
        ini->id = id;
//        ini->estado[0] = 7;
//	ini->estado[1] = 2;
//	ini->estado[2] = 5;
//	ini->estado[3] = 4;
//	ini->estado[4] = 0;
//	ini->estado[5] = 6;
//	ini->estado[6] = 8;
//	ini->estado[7] = 3;
//	ini->estado[8] = 1;

        memcpy(ini->estado, state, sizeof(int) * 9);//copia pai pro filho
        
                
        return ini;
    }
    
    exit(EXIT_FAILURE);
}

//cria nodo do tipo filho, copia, e troca as posições
nodo CriaNodoFilho(nodo pai, int pos, int posAux)//p1 e p2 devem trocar de posição
{
	nodo novo;
	if (!(novo = (nodo) malloc(sizeof(struct Nodo)))) return NULL;

	novo->id = 5;//***********
	novo->pai = pai;
	
	//adiciona filho na lista do pai*********
	
	memcpy(pai->estado, novo->estado, sizeof(int) * 9);//copia pai pro filho

	//troca posições
	int aux = novo->estado[pos];
	novo->estado[pos] = novo->estado[posAux];
	novo->estado[posAux] = aux;

	return novo;
}