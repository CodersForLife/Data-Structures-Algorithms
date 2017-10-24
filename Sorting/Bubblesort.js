// Swap function which can easily swap two indices of any array.

Array.prototype.swap = function (first,second) {
  var temp = this[first];
  this[first] = this[second];
  this[second] = temp;
  return this;
}

// Main bubble sort logic.

function bubbleSort(array) {
  for(let i = 1; i < array.length; ++i) {
    sorted = true;

    for(let j = 0 ; j < array.length - i ; ++j) {
      if(array[j] > array[j+1]) {
        array.swap(j, j+1);
        sorted = false;
      }
    }

    if(sorted) {
      break;
    }
  }
  return array;
}

// Sample array

let array = [-1, 0, -100, 11, 10, 19, 1 , 50, 11, 7];

// Calling bubble sort function 

console.log(bubbleSort(array));
