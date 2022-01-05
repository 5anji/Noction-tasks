#include "containers.h"

#include "tree.h"

const uint64_t limit = 100000;
RedBlackTree<int> mp;
// std::map<int, uint64_t> mp;
std::vector<uint64_t> vec;

void display_as_percent(uint64_t n, uint64_t i) {
    if (i / (limit / 10) > 0 && i % (limit / 10) == 0)
        std::cout << i / (limit / 100) << "%..." << std::flush;
}

void benchmark_map_alloc(double& a) {
    clock_t start = clock();

    std::cout << "\tEstimating for map..." << std::endl
              << "\t";

    for (size_t i = 0; i <= limit; i++) {
        display_as_percent(limit, i);
        mp.insert(i + 1);
        // mp.insert({i, i+1});
    }
    a = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
    std::cout << "Finished" << std::endl;
    std::cout << "\tTime taken: " << a << std::endl
              << std::endl;
}

void benchmark_vector_alloc(double& a) {
    clock_t start = clock();

    std::cout << "\tEstimating for vector..." << std::endl
              << "\t";

    for (size_t i = 0; i <= limit; i++) {
        display_as_percent(limit, i);

        vec.push_back(i);
    }
    a = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
    std::cout << "Finished" << std::endl;
    std::cout << "\tTime taken: " << a << std::endl
              << std::endl;
}

void benchmark_map_search(double& a) {
    clock_t start = clock();

    std::cout << "\tEstimating for map..." << std::endl
              << "\t";

    for (size_t i = 0; i <= limit; i++) {
        uint64_t temp = i;

        display_as_percent(limit, i);

        auto chk = mp.searchTree(temp);
        // auto chk = mp.find(temp);
    }
    a = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
    std::cout << "Finished" << std::endl;
    std::cout << "\tTime taken: " << a << std::endl
              << std::endl;
}

void benchmark_vector_search(double& a) {
    clock_t start = clock();

    std::cout << "\tEstimating for vector..." << std::endl
              << "\t";

    for (size_t i = 0; i <= limit; i++) {
        uint64_t temp = i;

        display_as_percent(limit, i);

        auto chk = std::find(vec.begin(), vec.end(), i);
    }
    a = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
    std::cout << "Finished" << std::endl;
    std::cout << "\tTime taken: " << a << std::endl
              << std::endl;
}
