#include <cstdlib>
#include <iostream>
#include <glog/logging.h>
#include "WindowManager.hpp"

int main(int argc, char **argv) {
	google::InitGoogleLogging(argv[0]);
	
	std::unique_ptr<WindowManager> window_manager = WindowManager::create();
	if (!window_manager) {
		LOG(ERROR) << "failed to initialitiate WindowManager";
		return EXIT_FAILURE;
	}
	
	window_manager->run();
	
	return EXIT_SUCCESS;	
}
