#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000


void ler(int arr[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		arr[i] = rand() % n; 
	}
}

void print(int arr[], int n, char mens[])
{
	int i;
	printf("%s\n",mens);
	for(i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
		if(i % 50 == 0 && i > 0) printf("\n");
	}
	printf("\n");
}
typedef struct no
{
	int valor;
	struct no* prox;
}No;

void inserir(No** r, int valor)
{
	No* p;
	No* aux = NULL;
	No* atual = (*r);
	int cond = 1;

	p = (No*)malloc(sizeof(No));

	p->valor = valor;
	p->prox = NULL;

 	while(atual != NULL	&& cond)
 	{
 		if(valor <  atual->valor) cond = 0;
 		else
 		{
 			aux = atual;
 			atual = atual->prox;
 		}
 	}
 	p->prox = atual;
 	if(aux == NULL) (*r) = p;
 	else aux->prox = p;
}

void bucketSort(int arr[], int n)
{
	No** bucket = (No**)malloc(n * sizeof(No*));
	printf("------------------BUCKETSORT------------------\n");
	int i,j;
	for(i = 0; i < n; i++)
	{
		bucket[i] = NULL;
	}
	for(i = 0; i < n; i++)
	{
		int indice = n * ((double) arr[i]/(n + 1));
		inserir(bucket+indice, arr[i]);

	}
	int ind = 0;
	No*  b;
	for(i = 0; i < n; i++)
	{
		b = bucket[i];
		while(b != NULL)
		{
			arr[ind++] = (b)->valor;
			bucket[i] = (b)->prox;
			free(b);
			b = bucket[i];
		}
		free(b);
	}
}
/*------------------------------------------*/
int main()
{
	srand(time(NULL));
	int n;
	printf("Input the array size\n");
	scanf("%d",&n);
	int *arr = malloc(sizeof(int)*n);
		


	ler(arr, n);
	print(arr, n, "Antes");
	printf("\n");
	bucketSort(arr, n);
	printf("\n");	
	print(arr, n, "Depois");
	printf("\n\n");
	
	return 0;
}
