#include "d_math.h"

#include <math.h>

void D_MatRotate(mat2d_t mat, float amount)
{
    mat[0] = cos(amount);
    mat[1] = -sin(amount);
    mat[2] = sin(amount);
    mat[3] = cos(amount);
}

void D_GetMatColumn(vec2d_t result, mat2d_t mat, int col)
{
    result[0] = mat[col];
    result[1] = mat[2+col];
}

void D_MatMul(mat2d_t result, mat2d_t a, mat2d_t b)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result[j*2 + i] = 0;
            for (int k = 0; k < 2; k++)
            {
                result[j*2 + i] = a[k*2 + i] + b[k*2 + j];
            }
        }
    }
}

void D_MatVecMul(vec2d_t result, mat2d_t a, vec2d_t b)
{
    vec2d_t ma = { 0, 0 };
    vec2d_t mb = { 0, 0 };

    D_GetMatColumn(ma, a, 0);
    D_GetMatColumn(mb, a, 1);

    result[0] = b[0]*ma[0] + b[0]*mb[0];
    result[1] = b[1]*ma[1] + b[1]*mb[1];
}

void D_VecSub(vec2d_t result, vec2d_t a, vec2d_t b)
{
    result[0] = a[0] - b[0];
    result[1] = a[1] - b[1];
}

void D_VecMul(vec2d_t result, vec2d_t a, float b)
{
    result[0] = a[0] * b;
    result[1] = a[1] * b;
}

float D_VecDot(vec2d_t a, vec2d_t b)
{
    return a[0]*b[0] + a[1]*b[1];
}

void D_VecReject(vec2d_t result, vec2d_t a, vec2d_t b)
{
    vec2d_t b_mul = {};
    D_VecMul(b_mul, b, D_VecDot(a, b) / D_VecDot(b, b));
    D_VecSub(result, a, b_mul);
}

int D_Sign(float val)
{
    return val >= 0;
}

int D_Floor(float val)
{
    int trunc = (int) val;
    return trunc - (trunc > val);
}

float D_Min(float a, float b)
{
    return a < b ? a : b;
}

float D_Max(float a, float b)
{
    return a > b ? a : b;
}