
function eventHandle1()
	local i = 0
	print("eventHandle1", i)
	waitEvent()
	i = i + 1
	print("eventHandle1", i)
	waitEvent()
	i = i + 1
	print("eventHandle1", i)
end

function eventHandle2()
	local i = 0
	print("eventHandle2", i)
	waitEvent()
	i = i + 1
	print("eventHandle2", i)
	waitEvent()
	i = i + 1
	print("eventHandle2", i)
end

co1 = coroutine.create(eventHandle1)
co2 = coroutine.create(eventHandle2)

function waitEvent()
	coroutine.yield()
end

function processEvent(event)
	if event == "event1" then
		coroutine.resume(co1)
	elseif event == "event2" then
		coroutine.resume(co2)
	end
end

function loop()
	processEvent("event1")
	processEvent("event2")
	processEvent("event1")
	processEvent("event2")
	processEvent("event1")
	processEvent("event2")
end

function main()
	loop()
end

main()

