#include <exception>
#include <exec/task.hpp>
#include <iostream>
#include <stdexec/execution.hpp>
#include <thread>

namespace stdex = stdexec;
using namespace std::literals;

int main()
{
	stdex::run_loop loop;
	std::jthread worker([&](std::stop_token st) {
		std::stop_callback cb { st, [&] { loop.finish(); } };
		loop.run();
	});
	stdex::sender auto hello = stdex::just("hello world"s);
	stdex::sender auto print = std::move(hello)
	    | stdex::then([](auto msg) {
		      std::puts(msg.c_str());
		      return 0; // This will be returned as the
				// result of the async op
	      });
	stdex::scheduler auto io_thread = loop.get_scheduler();
	stdex::sender auto work = stdex::on(io_thread, std::move(print));
	auto [result] = stdex::sync_wait(std::move(work)).value();
	return result; // return 0
}
