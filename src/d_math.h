#ifndef __D_MATH_H_
#define __D_MATH_H_

#define PI 3.1415296

#define DEG2RAD(x) ((PI/180)*x)
#define RAD2DEG(x) ((180/PI)*x)

typedef struct {
    float x;
    float y;
} pos2d_t;

typedef float vec2d_t[2];
typedef float mat2d_t[2*2];

// Create a rotation matrix from an angle in radians
void D_MatRotate(mat2d_t mat, float amount);

void D_GetMatColumn(vec2d_t result, mat2d_t mat, int col);

// Multiply two matrices together storing the result in another matrix
void D_MatMul(mat2d_t result, mat2d_t a, mat2d_t b);
// Multiply a matrix and a vector storing the result in a vector
void D_MatVecMul(vec2d_t result, mat2d_t a, vec2d_t b);
// Multiply a vector by a scalar value
void D_VecMul(vec2d_t result, vec2d_t a, float b);

int D_Sign(float val);
int D_Floor(float val);

float D_Min(float a, float b);
float D_Max(float a, float b);

#endif /* __D_MATH_H_ */