#pragma once

#include "tree.h"

#include <algorithm>
#include <ctime>
#include <iostream>
#include <map>
#include <vector>

template <typename T>
class Benchmark {
private:
    const size_t limit = 100000;

    double mp_time_all;
    double vec_time_all;
    double mp_time_srch;
    double vec_time_srch;

    RedBlackTree<T> mp;
    std::vector<T> vec;

    void display_as_percent(uint64_t n, uint64_t i) {
        if (i / (limit / 100) > 0 && i % (limit / 100) == 0)
            std::cout << "\033[47m \033[0m" << std::flush;
    }
public:
    void map_alloc() {
        clock_t start = clock();

        std::cout << "\tEstimating for map..." << std::endl
                  << "\t|";

        for (size_t i = 0; i <= limit; i++) {
            display_as_percent(limit, i);
            mp.insert(i + 1);
            // mp.insert({i, i+1});
        }
        mp_time_all = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
        std::cout << "|" << std::endl;
        std::cout << "\tTime taken: " << mp_time_all << std::endl
                  << std::endl;
    }
    void vector_alloc() {
        clock_t start = clock();

        std::cout << "\tEstimating for vector..." << std::endl
                  << "\t|";

        for (size_t i = 0; i <= limit; i++) {
            display_as_percent(limit, i);

            vec.push_back(i);
        }
        vec_time_all = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
        std::cout << "|" << std::endl;
        std::cout << "\tTime taken: " << vec_time_all << std::endl
                  << std::endl;
    }

    void map_search() {
        clock_t start = clock();

        std::cout << "\tEstimating for map..." << std::endl
                  << "\t|";

        for (size_t i = 0; i <= limit; i++) {
            uint64_t temp = i;

            display_as_percent(limit, i);

            auto chk = mp.searchTree(temp);
            // auto chk = mp.find(temp);
        }
        mp_time_srch = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
        std::cout << "|" << std::endl;
        std::cout << "\tTime taken: " << mp_time_srch << std::endl
                  << std::endl;
    }
    void vector_search() {
        clock_t start = clock();

        std::cout << "\tEstimating for vector..." << std::endl
                  << "\t|";

        for (size_t i = 0; i <= limit; i++) {
            uint64_t temp = i;

            display_as_percent(limit, i);

            auto chk = std::find(vec.begin(), vec.end(), i);
        }
        vec_time_srch = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
        std::cout << "|" << std::endl;
        std::cout << "\tTime taken: " << vec_time_srch << std::endl
                  << std::endl;
    }

    std::string alloc_compare_results() {
        return std::to_string(mp_time_all) + " vs " + std::to_string(vec_time_all);
    }
    std::string search_compare_results() {
        return std::to_string(mp_time_srch) + " vs " + std::to_string(vec_time_srch);
    }
};
