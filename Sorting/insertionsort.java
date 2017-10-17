/* Created by Jacob Rodgers
   10/11/17
 */

 public class insertionSort {

     public void iSort(int userArray[]){
         for (int i = 1; i < userArray.length; i++){
             //create an index variable for tracking current number
             int index = userArray[i];
             //and a second counting variable, j
             int j = i - 1;

             //Iterate through entire Array comparing each variable to the index assigned above
             while ((j >= 0) && (userArray[j] > index)) {
                 //If there is a number out of order then we will switch them
                 userArray[j+1] = userArray[j];
                 j = j - 1;
             }
             userArray[j+1] = index;
         }
     }
 }





