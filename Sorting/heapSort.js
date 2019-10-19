let array_length

const heap_root = (input, i) => {
  const left = 2 * i + 1
  const right = 2 * i + 2
  let max = i

  if (left < array_length && input[left] > input[max]) {
    max = left
  }

  if (right < array_length && input[right] > input[max]) {
    max = right
  }

  if (max != i) {
    swap(input, i, max)
    heap_root(input, max)
  }
}

const swap = (input, indexA, indexB) => {
  const temp = input[indexA]

  input[indexA] = input[indexB]
  input[indexB] = temp
}

const heapSort = input => {
  array_length = input.length

  for (let i = Math.floor(array_length / 2); i >= 0; i -= 1) {
    heap_root(input, i)
  }

  for (let i = input.length - 1; i > 0; i--) {
    swap(input, 0, i)
    array_length--

    heap_root(input, 0)
  }
}

export default heapSort
