#include <iostream>
#include <thread>
#include <vector>
#include <filesystem>
#include "file_search.h"

int main() {
    std::string file_name = "input.txt";
    std::filesystem::path root = "D:\\algos_labs";

    std::vector<std::thread> threads;
    for (const auto& entry : std::filesystem::directory_iterator(root)) {
        if (std::filesystem::is_directory(entry) && threads.size() < 8) {
            threads.emplace_back(file_search::search_file, file_name, entry.path());
        }
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
