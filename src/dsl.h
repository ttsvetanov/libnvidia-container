/*
 * Copyright (c) 2017, NVIDIA CORPORATION. All rights reserved.
 */

#ifndef HEADER_DSL_H
#define HEADER_DSL_H

#include <stddef.h>

#include "error_generic.h"

enum dsl_comparator {
        EQUAL,
        NOT_EQUAL,
        LESS,
        LESS_EQUAL,
        GREATER,
        GREATER_EQUAL,
};

struct dsl_rule {
    const char *name;
    int (*func)(void *, enum dsl_comparator, const char *);
};

int dsl_compare_version(const char *, enum dsl_comparator, const char *);
int dsl_evaluate(struct error *, char *, void *, const struct dsl_rule [], size_t);

#endif /* HEADER_DSL_H */
