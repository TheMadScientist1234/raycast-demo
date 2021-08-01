#ifndef __R_BUFFER_H_
#define __R_BUFFER_H_

typedef enum {
    WHITE = 0,
    GRAY = 1
} lineColor_t;

typedef struct {
    int col;
    int start_y;
    int end_y;
    lineColor_t color;
} line_t;

void R_AddLine(int col, int start_y, int end_y, lineColor_t color);
void R_DrawAll();

#endif /* __R_BUFFER_H_ */