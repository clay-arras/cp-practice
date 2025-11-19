// https://leetcode.com/problems/array-reduce-transformation

/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    if (nums.length == 0) {
        return init;
    }

    let arr = [];
    arr.push(fn(init, nums[0]));
    for (let i = 1; i < nums.length; i++) {
        arr.push(fn(arr[arr.length - 1], nums[i]));
    }
    return arr[arr.length - 1];
};