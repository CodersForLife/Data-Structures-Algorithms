#include<stdio.h>
int main(){
	int n;
	printf("\nEnter the number pf elements:");
	scanf("%d",&n);
	printf("\nEnter the elements:");
	int ar[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&ar[i]);
	printf("\nEnter the element to be searched for:");
	int element;
	scanf("%d",element);
	int beg=0,mid,last=n-1;
	mid=(beg+last)/2;
	while(beg<=last){
		if(ar[mid]==element)
			printf("\nFound element");
		else if(ar[mid]>element)
			last=mid-1;
		else
			beg=mid+1;
	}
}