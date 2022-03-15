//
// Created by yangf on 2022/3/16.
//

#include "FileSystem.hpp"

std::size_t EffectiveCpp::FileSystem::numDisks() const {
    return nums_;
}

EffectiveCpp::FileSystem &EffectiveCpp::FileSystem::instance() {
    static FileSystem fileSystem(2);
    return fileSystem;
}
