function fn(array, digit){//一个数组，一个深度
	const stack = []
	array.forEach((arrayItem, arrayIndex) => {//一个数数组的每一个元素，一个是当前的。
		let stackIndex = stack.length - 1 //栈顶的索引
		while(
			stack[stackIndex] !== undefined //栈里有东西时
			&& array.length - arrayIndex > digit - stack.length //数组里的剩下的比栈的深度大的时候（边界处理）
		){
			if(stack[stackIndex] < arrayItem){//如果栈顶比数组的数小，就pop
				stack.pop()
				stackIndex--
			} else { 不小就不pop
				break
			}
		}
		if(stack.length < digit){ //如果栈的长度比栈的深度少的时候才push。
			stack.push(arrayItem)
		}
	})
	return stack
}
