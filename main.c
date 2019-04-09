#include<stdio.h>
#include<stdlib.h>
#include "nodo.h"


//mostra o menu e o puzzle
void MostraMenu(nodo atual)
{
    //system("clear");
    printf("\n\t%d %d %d\n", atual->estado[0], atual->estado[1], atual->estado[2]);
    printf("\t%d %d %d\n", atual->estado[3], atual->estado[4], atual->estado[5]);
    printf("\t%d %d %d\n\n", atual->estado[6], atual->estado[7], atual->estado[8]);
    printf("Digite uma tecla para mover o blank:\n");
    printf("w - cima\n");
    printf("a - esquerda\n");
    printf("d - direita\n");
    printf("s - baixo\n");
    printf("0 - Sair\n");
}

//faz um for até encontrar o blank
int VerificaPosicaoBlank(nodo atual)
{
    for (int i = 0; i < 9; i++)
    {
        if (atual->estado[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

//verificação posição do blank, depois verifica intenção de movimento, e se possivel cria uma copia do filho com o movimento
nodo Move(nodo atual, char opc)
{
    int pos = VerificaPosicaoBlank(atual);
    int posAux;
    if (opc == 'w')
    {
        if (pos >= 3)//se é maior que 2 pode mover para cima
        {
            posAux = pos - 3;
            atual = CriaNodoFilho(atual, pos, posAux);
        }
        else
            printf("movimento para cima não permitido.");
    }
    else if (opc == 'a')
    {
        if (pos % 3 != 0)//se o resto de divisão por 3 é zero então está na lateral esquerda
        {
            posAux = pos - 1;
            atual = CriaNodoFilho(atual, pos, posAux);
        }
        else
            printf("movimento para esquerda não permitido.");
    }
    else if (opc == 'd')
    {
        if (pos % 3 != 2)//se o resto de divisão por 3 é 2 então está na lateral direita
        {
            posAux = pos + 1;
            atual = CriaNodoFilho(atual, pos, posAux);
        }
        else
            printf("movimento para direita não permitido.");
    }
    else if (opc == 's')
    {
        if (pos <= 5)//se é menor que 6 pode mover pra baixo
        {
            posAux = pos + 3;
            atual = CriaNodoFilho(atual, pos, posAux);
        }
        else
            printf("movimento para baixo não permitido.");
    }
    return atual;
}

int main()
{
    int initialState[9] = {1,0,2,3,4,5,6,7,8}; //Estado inicial
    
    nodo atual = CriaInicial(initialState);//cria o inicial
    idCount++;

    char opc = '\0';//var q recebe a opção digitada no teclado
    while (opc != '0')
    {
        MostraMenu(atual);

        scanf("%c", &opc);
        atual = Move(atual, opc);

        getchar();
    }
}