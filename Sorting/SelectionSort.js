var selectionSort = function(arr) {
  for(var i = 0; i < arr.length; i++){
    //set low to the current value of i
    var low = i;
    for(var j = i+1; j < arr.length; j++){
      if(arr[j] < arr[low]){
       low = j;
      }
    }
    var temp = arr[i];
    arr[i] = arr[low];
    arr[low] = temp;
  }
  return arr;
};
