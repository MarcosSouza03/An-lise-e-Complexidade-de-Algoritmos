//Marcos Martins De Souza
#include<stdio.h>
 
int max(int a, int b) { return (a > b)? a : b; }
 
int mochila(int capacidade, int peso[], int val[], int n)
{
   int i, w;
   int K[n+1][capacidade+1];
 
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= capacidade; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (peso[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-peso[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][capacidade];
}
 
int main()
{
    int i, n, val[20], peso[20], capacidade;
    
    printf("Insira o numero de itens:");
    scanf("%d", &n);
    
    printf("Insira o valor e o peso:\n");
    for(i = 0;i < n; ++i){
        scanf("%d%d", &val[i], &peso[i]);
    }
 
    printf("Enter capacidade da mochila:");
    scanf("%d", &capacidade);
    
    printf("%d", mochila(capacidade, peso, val, n));
    return 0;
}
