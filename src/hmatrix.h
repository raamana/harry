/*
 * Harry - A Tool for Measuring String Similarity
 * Copyright (C) 2013 Konrad Rieck (konrad@mlsec.org)
 * --
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.  This program is distributed without any
 * warranty. See the GNU General Public License for more details. 
 */

#ifndef HMATRIX_H
#define HMATRIX_H

#include "hstring.h"

/** 
 * Range for matrix 
 */
typedef struct
{
    int i;    /**< Start of range */
    int n;    /**< End of range */
} range_t;

/**
 * Structure for a matrix
 */
typedef struct
{
    float *labels;      /**< Labels */
    char **srcs;        /**< Sources */
    int num;            /**< Number of strings */

    float *values;      /**< Similarity values */
    int size;           /**< Size of memory */
    range_t x;          /**< Range x */
    range_t y;          /**< Range y */
} hmatrix_t;

hmatrix_t *hmatrix_init(hstring_t *s, int n);
void hmatrix_range(hmatrix_t *m, char *x, char *y);
float *hmatrix_alloc(hmatrix_t *m);
float hmatrix_get(hmatrix_t *m, int x, int y);
void hmatrix_set(hmatrix_t *m, int x, int y, float f);
void hmatrix_compute(hmatrix_t *m, hstring_t *s,
                     double (*measure) (hstring_t x, hstring_t y));
void hmatrix_destroy(hmatrix_t *m);

#endif /* HMATRIX_H */
