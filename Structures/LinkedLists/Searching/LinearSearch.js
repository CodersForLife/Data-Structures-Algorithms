function linearSearch(array, targetValue) {

    for (var i = 0; i < array.length; i++) {
        if (targetValue === array[i]) {
            return i;
        }
    }
    return "Not Found";
}

function main() {

    // Example
    var exampleArray = [1, 2, 3, 4, 5, 6, 7, 8, 9];
    var exampleTarget = 5
    result = linearSearch(exampleArray, exampleTarget)
    if (result === "Not Found") {
        console.log("Your value " + exampleTarget + " was " + result);
    } else {
        console.log("Your value " + exampleTarget + " was found at array index " + result)
    }
}

main();

