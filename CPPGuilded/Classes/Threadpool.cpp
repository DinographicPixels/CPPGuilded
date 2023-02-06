#include "Threadpool.hpp"

CPPGuilded::Threadpool::Threadpool(const unsigned int size) {
	static unsigned int thread_pool_index = 0;
	threadpool_id = thread_pool_index++;

	utils = Utils();
	log = Utils::Logger("CPPGuilded | Threadpool");

	for (unsigned int i = 0; i < size; i++) {
		start_thread();
	}
}

CPPGuilded::Threadpool::~Threadpool() {
	{
		std::lock_guard<std::mutex> lock(state_mutex);
		shutdown = true;
	}

	condition.notify_all();

	for (unsigned int i = 0; i < threads.size(); i++) {
		threads[i].join();
	}
}

void CPPGuilded::Threadpool::start_thread() {
	std::lock_guard<std::mutex> lock(state_mutex);

	std::thread thread = std::thread(
		[this]() {

			std::cout << "Thread started" << std::endl;

			while (true) {
				std::function<void()> task;

				{
					std::unique_lock<std::mutex> lock(queue_mutex);
					condition.wait(lock, [this]() {
						return shutdown || !task_queue.empty();
					});
					if (shutdown) {
						break;
					}

					task = std::move(task_queue.front());
					task_queue.pop();
				}

				task();
			}

			std::cout << "Thread closed" << std::endl;
			log.unregisterThread(std::this_thread::get_id());
		});

	log.registerThread(thread.get_id(), "Threadpool-" + std::to_string(threadpool_id) +
			"-Thread-" + std::to_string(thread_count));

	threads.push_back(std::move(thread));

	thread_count++;
}

void CPPGuilded::Threadpool::queue_task(const std::function<void()>& task) {
	std::lock_guard<std::mutex> lock(queue_mutex);
	if (shutdown) {
		throw std::runtime_error("Cannot execute task on stopped threadpool");
	}

	task_queue.emplace(task);
	condition.notify_one();
}
