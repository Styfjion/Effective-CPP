//
// Created by y00564656 on 2022/6/30.
//
#include <mutex>
#include <sstream>
#include <string>
#include <memory>

class Image {
public:
    Image(std::istream &imgSrc) {

    }
};

struct PMImpl {
    std::shared_ptr<Image> bgImage;
    int imageChanges;
};

class PrettyMenu {
public:
    void changeBackground(std::istream &imgSrc);
private:
    std::mutex lock;
    std::unique_ptr<PMImpl> pImpl;
};

void PrettyMenu::changeBackground(std::istream &imgSrc) {
    // copy and swap
    using std::swap;
    std::lock_guard<std::mutex> lockGuard(lock);
    std::unique_ptr<PMImpl> pNew(new PMImpl(*pImpl));
    pNew->bgImage.reset(new Image(imgSrc));
    ++pNew->imageChanges;
    swap(pImpl, pNew);
}
