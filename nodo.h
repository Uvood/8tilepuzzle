/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   nodo.h
 * Author: danilo
 *
 * Created on 4 de Abril de 2019, 15:26
 */

#ifndef NODO_H
#define NODO_H


typedef struct Nodo *nodo;
typedef struct Lista *lista;

struct Nodo
{
    int id;
    int estado[9];
    nodo pai;
    lista filhos;
};

struct Lista
{
    nodo n;
    lista prox; 
};


nodo CriaInicial(int id, int state[9]);
nodo CriaNodoFilho(nodo pai, int pos, int posAux);//p1 e p2 devem trocar de posição
int isGoal(nodo n);//Verifica se e o estado objetivo

#endif /* NODO_H */

