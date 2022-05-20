#include "labirinto.h"

void Inicia(Labirinto *labirinto, int l, int c){
    labirinto->map = malloc(l * sizeof(Posicao*));

    labirinto->coluna = c;
    labirinto->linha = l;
    
    for(int i = 0; i < l; i++) {
        labirinto->map[i] = malloc(c *sizeof(Posicao));
    }
}

bool AbrirArquivo(Labirinto *labirinto) 
{
    FILE *File;
    int i=0, j=0;
    char arquivo[MAXTAM];
    char Posicao;
    
    scanf("%c", (char *) stdin);
    printf("Digite o nome do arquivo:");
	fgets(arquivo, MAXTAM-4, stdin);
	strtok(arquivo, "\n");
    strcat(arquivo,".txt");

    File = fopen(arquivo, "r");
    if (File == NULL) {
        printf("Arquivo não Encontrado!\n");
        exit(1);
    } 
    else 
    {
        while((Posicao = (char)fgetc(File)) != EOF) {
            if(Posicao != '\n') {
                labirinto->map[i][j].valor = Posicao;
                labirinto->map[i][j].verificado = false;
                j++;
            }
            else {
                i++;
                j = 0;
            }
        }
    }
    fclose(File);
    return true;
}

bool VerificarUltimo(Labirinto *labirinto, Fila *f) {
    if(f->Ultimo->dado.lin == (labirinto->linha-1) && f->Ultimo->dado.col == (labirinto->coluna-1)){
        return true;
    }     
    return false;
}

int PercorreLabirinto(Labirinto *labirinto, Fila *f) {
    bool cont = true;
    int cont2 = 1, x=0, y=0;
    Item aux, aux2;

    while (cont){
        Desenfileira(f, &aux);
        x = aux.lin;
        y = aux.col;
        if((x+1) < labirinto->linha && labirinto->map[x+1][y].valor != '#' && !labirinto->map[x+1][y].verificado && cont) {
            aux2.lin = x+1;
            aux2.col = y;

            labirinto->map[aux2.lin][aux2.col].verificado = true;
            Enfileira(f, aux2);

            cont2++;

            if(VerificarUltimo(labirinto, f)){
                cont = false;
            }
                
        }
        if((y+1) < labirinto->coluna && labirinto->map[x][y+1].valor != '#' && !labirinto->map[x][y+1].verificado && cont) {
            aux2.col = y+1;
            aux2.lin = x;
            

            labirinto->map[aux2.lin][aux2.col].verificado = true;
            Enfileira(f, aux2);

            cont2++;

            if(VerificarUltimo(labirinto, f))
            {
                cont = false;
            }     
        }
        if((y-1) >= 0 && labirinto->map[x][y-1].valor != '#' && !labirinto->map[x][y-1].verificado && cont) 
        {
            aux2.col = y-1;
            aux2.lin = x;

            labirinto->map[aux2.lin][aux2.col].verificado = true;
            Enfileira(f, aux2);

            cont2++;

            if(VerificarUltimo(labirinto, f)){
                cont = false;
            }
                
        }
        if((x-1) >= 0 && labirinto->map[x-1][y].valor != '#' && !labirinto->map[x-1][y].verificado && cont) 
        {
            aux2.lin = x-1;
            aux2.col = y;
            
            labirinto->map[aux2.lin][aux2.col].verificado = true;
            Enfileira(f, aux2);

            cont2++;
            
            if(VerificarUltimo(labirinto, f))
            {
                cont = false;
            }
        }
    }
    return cont2;
    
}

void ImprimirLabirinto(Labirinto *labirinto) 
{   
    printf("!!!Imprimindo o labirinto!!!\n\n");

    for(int i=0; i<labirinto->linha; i++) 
    {
        printf("      ");

        for(int j=0; j<labirinto->coluna; j++) 
        {
            printf("%c ", labirinto->map[i][j].valor);
        }
        printf("\n");
    }
}




