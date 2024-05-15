#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <sys/types.h>

struct Context {
	std::string arg;
};

using Handler = std::function<void(Context&)>;

void step1(Context& contex);
void step2(Context& contex);
void step3(Context& contex);

std::queue<Handler> eventQueue {};
Context eventContext;

void registerEvent(Handler handler)
{
	eventQueue.push(handler);
}

size_t processEvent()
{
	auto handler = eventQueue.front();
	handler(eventContext);
	eventQueue.pop();

	return eventQueue.size();
}

void run()
{
	while (true) {
		auto rc = processEvent();
		if (rc == 0) {
			break;
		}
	}
}

void step1(Context& contex)
{
	std::cout << "step 1, arg from start: " << contex.arg << std::endl;
	contex.arg = "hello";
	registerEvent(step2);
}

void step2(Context& contex)
{
	std::cout << "step 2, arg from step 1: " << contex.arg << std::endl;
	contex.arg = "world";
	registerEvent(step3);
}

void step3(Context& contex)
{
	std::cout << "step 3, arg from step2: " << contex.arg << std::endl;
	std::cout << "end" << std::endl;
}

void post()
{
	eventContext.arg = "start";
	registerEvent(step1);
}

void post2()
{
	registerEvent([](Context&) {
		std::cout << "step 1" << std::endl;
		registerEvent([](Context&) {
			std::cout << "step 2" << std::endl;
			registerEvent([](Context&) {
				std::cout << "step 3" << std::endl;
			});
		});
	});
}

int main()
{
	post();
	run();
	post2();
	run();
}
