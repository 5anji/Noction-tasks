#include "containers.h"

int main() {
    double mp, vec;
    std::cout << "Creating elements" << std::endl;

    benchmark_map_alloc(mp);
    benchmark_vector_alloc(vec);

    std::cout << std::endl
              << mp << " vs " << vec << std::endl;
    std::cout << "\n\n\n";

    std::cout << "Searching element" << std::endl;

    benchmark_map_search(mp);
    benchmark_vector_search(vec);

    std::cout << std::endl
              << mp << " vs " << vec << std::endl;
    return 0;
}
