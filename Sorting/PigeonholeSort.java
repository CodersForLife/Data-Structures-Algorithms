/*#Pigeonhole sort
  #Time complexity: O(n+k)
        where n= array size and
              k= no of possible key values in the array
                 which basically means how many unique elements are there
                 Runs in O(n) if approximately all the elements are unique
   #Works only for Integers (doesn't works for Long,Float etc.)
   #Code by : Anand
              github.com/anandthegreat
*/

public class PigeonholeSort {

    public void pigeonSort(int arr[]){
        int smallest=Integer.MAX_VALUE;
        int largest=Integer.MIN_VALUE;
        for(int i=0;i<arr.length;i++){      //loop to find minimum and maximum value in the array

            if(arr[i]<smallest)
                smallest=arr[i];
            if(arr[i]>largest)
                largest=arr[i];
        }
        int pigeonHoles=largest-smallest+1;
        int HolesArray[]=new int[pigeonHoles];
        for(int i=0;i<arr.length;i++){
            HolesArray[arr[i]-smallest]+=1;

        }

        int j=0;

        for(int i=0;i<pigeonHoles;i++){
            while(HolesArray[i]>0){
                HolesArray[i]-=1;
                arr[j++]=i+smallest;

            }
        }


    }
    public static void main(String[] args){

        PigeonholeSort obj=new PigeonholeSort();
        int arr[]={-54,54,3,7,1,2,3,8,0,12,74,-9,-7};
        obj.pigeonSort(arr);
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
    }

}



