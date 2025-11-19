// https://leetcode.com/problems/memoize

/**
 * @param {Function} fn
 */
function memoize(fn) {
    
    return function(...args) {
        let myGrid = [...Array(11)].map(e => Array(11));
        let arr = [];
        if (args.length == 1) {
            if (typeof arr[args[0]] === 'undefined') {
                for (let i = arr.length; i <= args[0]; i++) {
                    arr.push(fn(i));
                }
            } 
            return arr[args[0]];
        } else if (args.length == 2) {
            if (typeof myGrid[args[0]][args[1]] === 'undefined') {
                myGrid[args[0]][args[1]] = fn(...args);
            } 
            return myGrid[args[0]][args[1]];
        }
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */