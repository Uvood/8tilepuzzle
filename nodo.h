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

struct Nodo
{
    int id;
    int estado[9];
    nodo pai;
    nodo filhos[4];
};


nodo CriaInicial(int id, int state[9]);
nodo CriaNodoFilho(nodo pai, int pos, int posAux);//p1 e p2 devem trocar de posição

#endif /* NODO_H */

