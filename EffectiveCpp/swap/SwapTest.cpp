//
// Created by y00564656 on 2022/6/30.
//
#include <vector>

namespace WidgetStuff {
    class WidgetImpl {
    public:
    private:
        int a, b, c;
        std::vector<double> v;
    };

    class Widget {
    public:
        Widget() {
            pImpl = new WidgetImpl();
        };

        ~Widget() {
            delete pImpl;
        }

        Widget(const Widget& rhs) {
            *pImpl = *(rhs.pImpl);
        }
        Widget& operator=(const Widget& rhs) {
            if (this == &rhs) {
                return *this;
            }
            *pImpl = *(rhs.pImpl);
            return *this;
        }
        void swap(Widget& other) {
            std::swap(pImpl, other.pImpl);
        }
    private:
        WidgetImpl* pImpl;
    };

    void swap(Widget& a, Widget& b)
    {
        a.swap(b);
    }
}

namespace std {
    template<>
    void swap<WidgetStuff::Widget>(WidgetStuff::Widget& a, WidgetStuff::Widget& b)
    {
        a.swap(b);
    }
}

namespace WidgetStuff {
    void doSomething()
    {
        Widget a, b;
        using namespace std;
        swap(a, b);
    }
}
int main()
{
    WidgetStuff::doSomething();
    return 0;
}
