def maxSubarraySum(array):
  maxSum = array[0]

  sum = 0
  for i in range(1, len(array)):
    sum = sum + array[i]
    maxSum = max(maxSum, sum)

    if sum < 0:
      sum = 0

  return maxSum

if __name__ == '__main__':
  print(maxSubarraySum([1, 2, 3, 4]))
  print(maxSubarraySum([-1, 2, -1, 4]))
  print(maxSubarraySum([-1, 4, -3, 1]))
  print(maxSubarraySum([-11, -4, -3, -11]))
