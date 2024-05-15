
function processMultiTask()
	i = 0
	print(i)
	coroutine.yield()
	i = i + 1
	print(i)
	coroutine.yield()
	i = i + 1
	print(i)
end

co = coroutine.create(processMultiTask)

coroutine.resume(co)
coroutine.resume(co)
coroutine.resume(co)

