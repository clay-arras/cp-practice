// https://leetcode.com/problems/memoize

/**
 * @param {Function} fn
 */
function memoize(fn) {
    let myArr = [...Array(11)];
    const myGrid = new Map();

    return function(...args) {
        if (args.length == 1) {
            if (typeof myArr[args[0]] === 'undefined') {
                myArr[args[0]] = fn(...args);
            } 
            return myArr[args[0]];

        } else if (args.length == 2) {
            let arg = toString(Math.max(...args)) + "|" + toString(Math.min(...args));
            if (!(arg in myGrid)) {
                myGrid.set(arg, fn(...arg));
            } 
            return myGrid.get(arg);
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