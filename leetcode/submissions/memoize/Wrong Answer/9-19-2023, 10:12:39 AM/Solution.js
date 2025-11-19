// https://leetcode.com/problems/memoize

/**
 * @param {Function} fn
 */
function memoize(fn) {
    
    return function(...args) {
        if (args.length == 1) {
            let arr = [];
            if(typeof arr[args[0]] === 'undefined') {
                for (let i = arr.length; i <= args[0]; i++) {
                    arr.push(fn(i));
                }
            } 
            return arr[args[0]];
        } else if (args.length == 2) {

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