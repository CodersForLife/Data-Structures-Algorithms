// Java Program

class CountingSort 
{ 
    void sort(int array[]) 
    { 
        int n = array.length; 
  
        int output[] = new int[n]; 
  
        int count[] = new int[256]; 
        for (int i=0; i<256; ++i) 
            count[i] = 0; 
  
        for (int i=0; i<n; ++i) 
            ++count[array[i]]; 
  
        for (int i=1; i<=255; ++i) 
            count[i] += count[i-1]; 

        //Reverse order to make it Stable 
        for (int i = n-1; i>=0; i--) 
        { 
            output[count[array[i]]-1] = array[i]; 
            --count[array[i]]; 
        } 
  
        System.out.print("Sorted array is "); 
        for (int i=0; i<array.length; ++i)
        {
        	System.out.print(output[i] + " ");
        }
            
    }
    
    public static void main(String args[]) 
    { 
        CountingSort cs = new CountingSort(); 
        int array[] = {3, 1, 2, 1, 3, 2, 1, 2}; 
  
        cs.sort(array); 
    } 
}
