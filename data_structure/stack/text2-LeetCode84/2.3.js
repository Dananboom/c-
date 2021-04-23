/**
 * @param {number[]} heights
 * @return {number}
 */
var largestRectangleArea = function(heights) {
    const stack = [] 
    let max = 0;
    heights.push(0);
    heights.forEach((arrayItem, arrayIndex) => {
        let stackIndex = stack.length - 1;//栈顶的索引
        while (
            stack.length !== undefined 
            && heights < stack[stackIndex]
            ) {
                let temp = stack[stackIndex];
                stack.pop;
                stackIndex--;
                let width = arrayIndex - (stackIndex == 0 ? 0 : stackIndex + 1)
                max = Math.max (width * temp, max);
            } 
            stack.push(arrayItem)
    })
    return max
}