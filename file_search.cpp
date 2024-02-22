#include "file_search.h"
#include <iostream>
#include <filesystem>

namespace file_search {
    bool search_file(const std::string& file_name, const std::filesystem::path& path) {
        try {
            for (const auto& p : std::filesystem::recursive_directory_iterator(path)) {
                if (!std::filesystem::is_directory(p) && p.path().filename() == file_name) {
                    std::cout << "File found at: " << p.path() << std::endl;
                    return true;
                }
            }
        } catch (const std::filesystem::filesystem_error& e) {
            std::cout << "Error while accessing : " << path << " :: " << e.what() << '\n';
        }
        return false;
    }

    std::filesystem::path search_file_in_root(const std::string& file_name, const std::filesystem::path& root) {
        for (const auto& entry : std::filesystem::directory_iterator(root)) {
            if (!std::filesystem::is_directory(entry) && entry.path().filename() == file_name) {
                std::cout << "File found at: " << entry.path() << std::endl;
                return entry.path();
            }
        }
        return {};
    }
}
