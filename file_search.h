#ifndef FILE_SEARCH_H
#define FILE_SEARCH_H

#include <filesystem>
#include <string>

namespace file_search {
    bool search_file(const std::string& file_name, const std::filesystem::path& path);

    std::filesystem::path search_file_in_root(const std::string& file_name, const std::filesystem::path& root);
}

#endif // FILE_SEARCH_H