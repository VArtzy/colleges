function containsDuplicate(arr) {
    tmp = [];

    for (let i = 0; i < arr.length; i++) {
        if(tmp[arr[i]] == 1) return true;
        tmp[arr[i]] = 1;
    }

    return false;
}

console.log(containsDuplicate([3, 4, 2, 4, 5, 1, 2]));
console.log(containsDuplicate([3, 6, 2, 4, 5, 1, 2]));
console.log(containsDuplicate([3, 6, 2, 4, 5, 1, 7]));
