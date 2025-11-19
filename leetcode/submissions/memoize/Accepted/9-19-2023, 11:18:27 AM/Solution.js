// https://leetcode.com/problems/memoize

/**
 * @param {Function} fn
 */
function memoize(fn) {
    let myArr = new Array(11);
    const myGrid = new Map();
    let arr = [];

    return function(...args) {
        if (args.length == 1) {
            if (typeof myArr[args[0]] === 'undefined') {
                myArr[args[0]] = fn(...args);
            } 
            return myArr[args[0]];

        } else if (args.length == 2) {
            let a = String(args[0]) + "/" + String(args[1]);
            console.log(a);
            // console.log(...args);
            // let a;

            // try {
            //     // a = String(Math.max(...args)) + String("/") + String(Math.min(...args));
            //     a = String(args[0]) + "/" + String(args[1]);
            //     console.log(typeof a);
            //     console.log("/");
            //     console.log(String(args[0]) + "/")
            //     console.log(toString(Math.max(...args)));
            // }
            // catch {
            //     console.log(error);
            // }
            // finally {
            //     if (a) {
            //         console.log(a);
            //     }
            // }
            arr.push(a);
            console.log(a in myGrid)
            if (!(myGrid.has(a))) {
            
                console.log(myGrid[a]);
                myGrid.set(a, fn(...args));
            } 
            
            return myGrid.get(a);
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