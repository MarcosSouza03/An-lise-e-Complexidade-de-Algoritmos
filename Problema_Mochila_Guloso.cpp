//Marcos Martins De Souza

#include<stdio.h>
#include<time.h>
#include<conio.h>
void mochila(float capacidade, int n, float peso[], float valor[])
{
	float x[20], totalvalor,y;
	int i,j;
	y=capacidade;
	totalvalor=0;
	for(i=0;i < n;i++)
		x[i]=0.0;
	for(i=0;i < n;i++)
	{
		if(peso[i] > y)
			break;
		else
		{
			x[i]=1.0;
			totalvalor=totalvalor+valor[i];
			y=y-peso[i];
		}
	}
	if(i < n)	
		x[i]=y/peso[i];
	totalvalor=totalvalor+(x[i]*valor[i]);
	printf("Os itens inseridos sao:-\n ");
	for(i=0;i < n;i++)
		if(x[i]==1.0)
			printf("\nvalor e %f com o peso %f ", valor[i], peso[i]);
		else if(x[i] > 0.0)
			printf("\n%f parte do valor %f com o peso %f", x[i], valor[i], peso[i]);
	printf("\nValor total para  %d objetos com a capacidade %f = %f\n\n", n, capacidade,totalvalor);
}			
int main()
{
	float peso[20],valor[20],ratio[20], t1,t2,t3;
	int n;
	time_t start,stop;
	float capacidade;
	//clrscr();
	int i,j;
	printf("Insira o numero de objetos:  ");
	scanf("%d", &n);
	printf("\nInsira a capacidade da mochila: ");
	scanf("%f", &capacidade);
	for(i=0;i < n;i++)
	{
		printf("\nInsira %d(th)  valor: ", (i+1));
		scanf("%f", &valor[i]);
		printf("Insira %d(th)  peso: ", (i+1));
		scanf("%f", &peso[i]);
		ratio[i]=valor[i]/peso[i];
	}
	start=time(NULL);
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
		{
			if(ratio[i] > ratio[j])
			{
				t1=ratio[i];
				ratio[i]=ratio[j];
				ratio[j]=t1;
				t2=peso[i];
				peso[i]=peso[j];
				peso[j]=t2;
				t3=valor[i];
				valor[i]=valor[j];
				valor[j]=t3;
			}
		}
	mochila(capacidade,n,peso,valor);
	stop=time(NULL);
	printf("\nmochila = %f\n", difftime(stop,start));
	getch();
}
