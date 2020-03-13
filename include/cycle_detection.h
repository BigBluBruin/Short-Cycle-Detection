#pragma once 
#include <vector>
#include <iostream>
#include <algorithm>


bool Cycle_Detection(std::vector<std::vector<int>>& input_matrix, int start_ind, int end_int, int max_cycle);
std::vector<std::vector<int>> find_cn_neighbors(std::vector<std::vector<int>> & input_matrix);
std::vector<std::vector<int>> find_vn_neighbers(std::vector<std::vector<int>> & input_matrix); 