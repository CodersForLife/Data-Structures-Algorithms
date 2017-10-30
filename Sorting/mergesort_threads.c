#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arr[111111];
int temp[111111];
pthread_mutex_t mutex;
typedef struct node NODE;
struct node {
	int l;
	int r;
};

void merge (int l,int m,int r)
{
	int mid = m+1;
	int k=1;
	int safe = l;
	while(l<=m && mid<=r)
	{
		if(arr[l] <= arr[mid])
			temp[k++] = arr[l++];
		else
			temp[k++] = arr[mid++];
	}
	while(l<=m)
		temp[k++] = arr[l++];
	while(mid <=r)
		temp[k++] = arr[mid++];
	for(int i=1;i<k;i++)
		arr[safe+i-1] = temp[i];
	return;
}

void * mergesort(void * temp)
{
	NODE * elem = (NODE *)temp;
	int l = elem->l;
	int r = elem->r;
	if( l < r)
	{
		int n = r-l+1;
		if(n <= 5)
		{
  			pthread_mutex_lock(&mutex);
			for(int i=0;i<n-1;i++)
			{
				int minind = i;
				for(int j=i+1;j<n;j++)
				{
					if(arr[j] < arr[minind])
						minind = j;
				}
				int temp = arr[minind];
				arr[minind] = arr[i];
				arr[i] = temp;
			}
  			pthread_mutex_unlock(&mutex);
			pthread_exit(0);
		}

		NODE lftarr,rgtarr;
		int m = (l+r) >> 1;
		pthread_t lftid,rgtid;
		lftarr.l = l;
		lftarr.r = m;
		rgtarr.l = m+1;
		rgtarr.r = r;
		if(pthread_create(&lftid,NULL,mergesort,&lftarr))
		{
			perror("pthread_create");
			exit(1);
		}
		if(pthread_create(&rgtid,NULL,mergesort,&rgtarr))
		{
			perror("pthread_create");
			exit(1);
		}
		pthread_join(lftid, NULL);
		pthread_join(rgtid, NULL);
  		pthread_mutex_lock(&mutex);
		merge(l,m,r);
  		pthread_mutex_unlock(&mutex);

		pthread_exit(0);
	}
	pthread_exit(0);
}

int main()
{
	int n;
	//printf("No of elements to be sorted:- \n");
	scanf("%d",&n);
//	printf("Enter the elements to be sorted:- \n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	NODE temp;
	temp.l = 0;
	temp.r = n-1;
	pthread_t mergesortid;
	if(pthread_create(&mergesortid, NULL, mergesort, &temp))
	{
		perror("pthread_create");
		exit(1);
	}

	pthread_join(mergesortid, NULL);

//	printf("Sorted array:- \n");
	for(int i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
		if(i == n-1)
			printf("\n");
	}
	return 0;
}
