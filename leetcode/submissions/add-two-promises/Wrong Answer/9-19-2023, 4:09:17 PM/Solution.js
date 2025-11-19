// https://leetcode.com/problems/add-two-promises

/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    var x = 0;
    promise1.then(
        (value) => {
            x += value;
        }
    )
    promise2.then(
        (value) => {
            x += value;
        }
    )
    return x;
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */