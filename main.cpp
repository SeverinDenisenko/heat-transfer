#include "matplot/util/common.h"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>

#include <matplot/matplot.h>

using real_t = double;

template <typename T>
using vector_t = std::vector<T>;

using image_t = vector_t<vector_t<real_t>>;

image_t create_image(size_t size)
{
    image_t image(size);
    for (auto& row : image) {
        row = vector_t<real_t>(size);
    }
    return image;
}

void plot_image(const image_t& im)
{
    using namespace matplot;

    image(im);
    colorbar(on).limits({ min(im), max(im) });
    show();
}

int main()
{
    image_t image = create_image(128);

    for (auto& row : image) {
        for (auto& cell : row) {
            cell = rand() % 100;
        }
    }

    plot_image(image);
    return 0;
}
