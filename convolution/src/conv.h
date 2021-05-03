#pragma once

#define conv(x, y, z)	__conv(x, sizeof(x)/sizeof(x[0]), y, sizeof(y)/sizeof(y[0]), z, sizeof(z)/sizeof(z[0]))

int __conv(int *a, int size_a, int *b, int size_b, int *c, int size_c);
