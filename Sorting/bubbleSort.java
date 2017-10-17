public class bubbleSort{
    
    public void bubble(int vet[]){

        for(int i = 0; i < vet.length-1; i++){
            for(int j = 0; j < vet.length-1-i; j++){
                if(vet[j] > vet[j+1]){
                    int a = vet[j];
                    vet[j] = vet[j+1];
                    vet[j+1] = a;
                }
            }
        }

    }

}