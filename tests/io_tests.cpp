#include "local_include.hpp"


void output_test() {
    std::cout << " -- Output test\n";
	sim::simstring ss("Hello ");
	std::cout << ss << sim::simstring("world") << '\n';
}

int main() {
	output_test();
}

