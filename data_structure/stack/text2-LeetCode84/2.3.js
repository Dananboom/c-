/**
 * @param {number[]} heights
 * @return {number}
 */
function MAX (a,b) {
    return a > b ? a : b
}
var largestRectangleArea = function(heights) {
    const stack = [] 
    let max = 0;
    heights.forEach((arrayItem, arrayIndex) => {
        let stackIndex = stack.length - 1;//栈顶的索引
        let target = heights.length == arrayIndex ? 0 : arrayItem
        while (
            stack[stackIndex] !== undefined 
            && target < stack[stackIndex]
            ) {
                let temp = stack[stackIndex];
                stack.pop;
                stackIndex--;
                let width = arrayIndex - (stackIndex == 0 ? 0 : stackIndex + 1)
                max = MAX (width * temp, max);
            } 
            stack.push(arrayItem)
    })
    return max
}