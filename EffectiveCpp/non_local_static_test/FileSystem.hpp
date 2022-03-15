//
// Created by yangf on 2022/3/16.
//

#ifndef ROOT_FILESYSTEM_HPP
#define ROOT_FILESYSTEM_HPP


#include <cstddef>

namespace EffectiveCpp {
    class FileSystem {
    public:
        explicit FileSystem(std::size_t nums) : nums_(nums) {};
        [[nodiscard]] std::size_t numDisks() const;
        static FileSystem& instance();
    private:
        std::size_t nums_;
    };
}


#endif //ROOT_FILESYSTEM_HPP
