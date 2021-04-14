function fn(array, digit){//一个数组，一个深度
	const stack = []
	array.forEach((arrayItem, arrayIndex) => {//一个数数组的每一个元素，一个是当前的。
		let stackIndex = stack.length - 1 
		while(
			stack[stackIndex] !== undefined 
			&& array.length - arrayIndex > digit - stack.length
		){
			if(stack[stackIndex] < arrayItem){
				stack.pop()
				stackIndex--
			} else {
				break
			}
		}
		if(stack.length < digit){
			stack.push(arrayItem)
		}
	})
	return stack
}
