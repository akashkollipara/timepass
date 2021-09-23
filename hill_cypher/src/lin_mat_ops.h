#pragma once

int populate_sqmat(unsigned char *);
void print_sqmat(unsigned char *, int);
int conv_txt_mat(unsigned char *mat, int, int);
void conv_mat_txt(unsigned char *mat, int, int);
void mat_mul_mod(unsigned char *a, unsigned char *b, unsigned char *c, int ro, int co);
void print_mat(unsigned char *, int, int);
