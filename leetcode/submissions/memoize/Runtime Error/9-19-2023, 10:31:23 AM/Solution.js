// https://leetcode.com/problems/memoize

/**
 * @param {Function} fn
 */
function memoize(fn) {
    
    let myArr = [...Array(11)];
    let myGrid = new Map();
    return function(...args) {
        if (args.length == 1) {
            if (typeof myArr[args[0]] === 'undefined') {
                myArr[args[0]] = fn(...args);
            } 
            return myArr[args[0]];
        } else if (args.length == 2) {
            // let arg = ;
            console.log(arg);
            console.log(myGrid);
            console.log([Math.max(...args), Math.min(...args)] in myGrid);
            if (!(myGrid.has(arg))) {
                myGrid.set(arg, fn(...args));
            } 
            return myGrid[arg];
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