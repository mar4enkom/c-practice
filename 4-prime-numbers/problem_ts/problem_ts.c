#include<stdio.h>
#include "u_template.h"

int my_abs(int a) {
    return a >= 0 ? a : -a;
}

int double_area(struct triangle_t tr) {
    return my_abs(
        tr.pts[0].x * (tr.pts[1].y - tr.pts[2].y) +
        tr.pts[1].x * (tr.pts[2].y - tr.pts[0].y) +
        tr.pts[2].x * (tr.pts[0].y - tr.pts[1].y)
    );
}
