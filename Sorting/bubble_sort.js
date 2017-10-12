Array.prototype.swap = function (x,y) {
  var b = this[x];
  this[x] = this[y];
  this[y] = b;
  return this;
}

let array = [-1, 0, -100, 11, 10, 19, 1 , 50, 11, 7];

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

console.log(array);
