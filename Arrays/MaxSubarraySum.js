function maxSubarraySum(array) {
  let maxSum = array[0];

  let sum = 0;
  for (let i = 0; i < array.length; ++i) {
    sum += array[i];
    maxSum = Math.max(maxSum, sum);

    if (sum < 0) {
      sum = 0;
    }
  }

  return maxSum;
}

console.log(maxSubarraySum([1, 2, 3, 4]));
console.log(maxSubarraySum([-1, 2, -1, 4]));
console.log(maxSubarraySum([-1, 4, -3, 1]));
