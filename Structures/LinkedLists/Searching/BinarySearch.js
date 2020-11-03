function binarySearch(array, targetValue) {
    var high = array.length - 1;
    var low = 0;
    var mid;

    while (low <= high) {
        // Getting the mid index of the array, using Math.floor to cancel out decimals
        mid = Math.floor((high + low) / 2);

        if (targetValue === array[mid]) {
            return mid;
        } else if (targetValue > array[mid]) {
            // Setting low as mid + 1 because target can only be above mid
            low = mid + 1;
        } else {
            // Setting high as mid - 1 because target can only be below mid
            high = mid - 1;
        }
    }

    return "Not Found";
}

function main() {

    // Example
    var exampleArray = [1, 2, 3, 4, 4, 7, 8, 11, 13, 20];
    var exampleTarget = 13;
    result = binarySearch(exampleArray, exampleTarget);
    if (result === "Not Found") {
        console.log("Your value " + exampleTarget + " was " + result);
    } else {
        console.log("Your value " + exampleTarget + " was found at array index " + result);
    }
}

main();