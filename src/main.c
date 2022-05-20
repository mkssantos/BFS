#include "labirinto.h"
#include "locale.h"

int main() {
    Labirinto L;
    Fila F;
    Item I;
    int it=0;
    int linhas=0, colunas=0;
   
    FVazia(&F);

    InicializaItem(&I);
    setlocale(LC_ALL,"Portuguese");

    printf("Numero de Linhas:");
    scanf("%d", &linhas);
    printf("Numero de Colunas:");
    scanf("%d", &colunas);
    
    Inicia(&L, linhas, colunas);

    AbrirArquivo(&L);

    Enfileira(&F, I);
    
    L.map[I.lin][I.col].verificado = true;

    printf("\n");
    ImprimirLabirinto(&L);

    it = PercorreLabirinto(&L, &F);

    printf("\nQuantidade de iterações: %d\n", it);
    return 0;
}