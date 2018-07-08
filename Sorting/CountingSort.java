class CountingSort
{
    void sort(char arr[])
    {
        int len=rr.length;
        char output[] = new char[len];
        int count[] = new int[256];
        for (int i=0; i<256; ++i)
            count[i] = 0;
        for (int i=0; i<len;++i)
            ++count[arr[i]];
		for (int i=1; i<=255; ++i)
            count[i] += count[i-1];
         for (int i = 0; i<len;++i)
        {
            output[count[arr[i]]-1] = arr[i];
            --count[arr[i]];
        }
        for (int i = 0; i<len;++i)
            arr[i] = output[i];
    }
 
    public static void main(String args[])
    {
        CountingSort ob = new CountingSort();
        char arr[] = {'g', 'e', 'e', 'k', 's', 'f', 'o',
                      'r', 'g', 'e', 'e', 'k', 's'
                     };
 
        ob.sort(arr);
 
        System.out.print("Sorted character array is ");
        for (int i=0; i<arr.length; ++i)
            System.out.print(arr[i]);
    }
}
