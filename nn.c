#include <time.h>

#define NN_IMPLEMENTATION
#include "nn.h"

float td[] = {
    0, 0, 0,
    0, 1, 1,
    1, 0, 1,
    1, 1, 0
};

int main()
{
    srand(time(0));

    size_t stride = 3;
    size_t n = sizeof(td)/sizeof(td[0])/stride;
    Mat ti = {
        .rows = n,
        .cols = 2,
        .stride = stride,
        .es = td
    };

    Mat to = {
        .rows = n,
        .cols = 1,
        .stride = stride,
        .es = td + 2,
    };

    size_t arch[] = {2, 2, 1};
    NN nn = nn_alloc(arch, ARRAY_LEN(arch));
    NN g  = nn_alloc(arch, ARRAY_LEN(arch));
    nn_rand(nn, 0.0f, 1.0f);

    float eps = 1e-1;
    float rate = 1e-1;

    for (size_t i = 0; i < 20*1000; i++) {
        nn_finite_diff(nn, g, eps, ti, to);
        nn_learn(nn, g, rate);
        printf("cost = %f\n", nn_cost(nn, ti, to));
    }

    printf("------------------\n");

    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; j < 2; j++) {
            MAT_AT(NN_INPUT(nn), 0, 0) = i;
            MAT_AT(NN_INPUT(nn), 0, 1) = j;
            nn_forward(nn);
            float y = *NN_OUTPUT(nn).es;

            printf("%zu ^ %zu = %f\n", i, j, y);
        }
    }

    printf("------------------\n");

    NN_PRINT(nn);

    return 0;
}