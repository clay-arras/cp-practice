// https://leetcode.com/problems/memoize

/**
 * @param {Function} fn
 */
function memoize(fn) {
    const myGrid = new Map();

    return function(...args) {
        if (args.length == 1) {
            let a = args[0];
        } else if (args.length == 2) {
            let a = String(args[0]) + "/" + String(args[1]);
        }
        if (!(myGrid.has(a))) {
            myGrid.set(a, fn(...args));
        } 
        
        return myGrid.get(a);
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