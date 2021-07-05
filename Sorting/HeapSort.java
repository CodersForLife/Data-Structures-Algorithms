public class HeapSort {

    static void Max_Heapify(long[] A,int heapsize,int i){       //O(logN)
        int leftchild=2*i+1;
        int rightchild=2*i+2;
        int largest=-1;
        if(leftchild<heapsize && A[leftchild]>A[i])
            largest=leftchild;
        else largest=i;
        if(rightchild<heapsize && A[rightchild]>A[largest])
            largest=rightchild;
        long temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;
        if(i!=largest)
            Max_Heapify(A,heapsize,largest);

    }


    static void buildMaxHeap(long[] A)          //O(N)
    {
        for(int i=A.length/2;i>=0;i--)
        {
            Max_Heapify(A,A.length,i);
        }

    }

    static void heapSort(long A[])              //O(NlogN)
    {   buildMaxHeap(A);
        for(int i=A.length-1;i>0;i--)
        {
            long max=A[0];
            A[0]=A[i];
            A[i]=max;
            Max_Heapify(A,i,0);
        }
    }


}