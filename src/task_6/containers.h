#ifndef CONTAINERS_H
#define CONTAINERS_H

#include <algorithm>
#include <ctime>
#include <map>
#include <iostream>
#include <vector>

void benchmark_map_alloc(double &a);
void benchmark_vector_alloc(double &a);

void benchmark_map_search(double &a);
void benchmark_vector_search(double &a);

#endif