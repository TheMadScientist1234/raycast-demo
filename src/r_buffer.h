#ifndef __R_BUFFER_H_
#define __R_BUFFER_H_

typedef struct {
    int col;
    int start_y;
    int end_y;
} line_t;

void R_AddLine(int col, int start_y, int end_y);
void R_DrawAll();

#endif /* __R_BUFFER_H_ */