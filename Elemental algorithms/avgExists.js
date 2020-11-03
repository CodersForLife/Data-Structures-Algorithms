function averagePair(arr, num) {
    var start = 0;
    var last = arr.length - 1;

    while (start < last) {
        let avg = (arr[start] + arr[last]) / 2;

        if (avg === num)
            return true;
        else if (avg < num)
            start++;
        else
            last--;
    }
    return false;
}

averagePair([1, 2, 3], 2.5);
