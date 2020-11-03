function isAnagram(str1, str2) {

    if (str1.length !== str2.length) {
        return false;
    }

    var frequencyCounter1 = {}
      , frequencyCounter2 = {};

    for (let val of str1.toLowerCase()) {
        frequencyCounter1[val] = (frequencyCounter1[val] || 0) + 1;
    }

    for (let val of str2.toLowerCase()) {
        frequencyCounter2[val] = (frequencyCounter2[val] || 0) + 1;
    }

    for (let key in frequencyCounter1) {
        if (!(key in frequencyCounter2)) {
            return false;
        }

        if (frequencyCounter2[key] !== frequencyCounter1[key]) {
            return false;
        }
    }
    return true;
}

isAnagram("Rachel Solando", "Dolores Chanal");
