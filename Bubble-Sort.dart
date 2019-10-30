List<num> bubbleSort(List<num> list) {
  var retList = new List<num>.from(list);
  var tmp;
  var swapped = false;
  do {
    swapped = false;
    for(var i = 1; i < retList.length; i++) {
      if(retList[i - 1] > retList[i]) {
        tmp = retList[i - 1];
        retList[i - 1] = retList[i];
        retList[i] = tmp;
        swapped = true;
      }
    }
  } while(swapped);
  
  return retList;
}
