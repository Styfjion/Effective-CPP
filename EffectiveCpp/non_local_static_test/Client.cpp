//
// Created by yangf on 2022/3/16.
//
#include <iostream>
#include "FileSystem.hpp"

namespace EffectiveCpp {
    class Directory {
    public:
        Directory() {
            disks_ = FileSystem::instance().numDisks();
        }
        [[nodiscard]] std::size_t getDisKNum() const {
            return disks_;
        }
        static Directory& instance() {
            static Directory directory;
            return directory;
        }
    private:
        std::size_t disks_;
    };
}

int main() {
    std::cout << EffectiveCpp::Directory::instance().getDisKNum() << std::endl;
}
