#include "containers.h"

int main() {
    Benchmark<char> benchmark;

    std::cout << "Creating elements" << std::endl;

    benchmark.map_alloc();
    benchmark.vector_alloc();

    std::cout << std::endl
              << benchmark.alloc_compare_results() << std::endl;

    std::cout << "\n\n\n";

    std::cout << "Searching element" << std::endl;

    benchmark.map_search();
    benchmark.vector_search();

    std::cout << std::endl
              << benchmark.search_compare_results() << std::endl;
    return 0;
}
