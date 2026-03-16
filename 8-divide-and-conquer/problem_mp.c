#include<stdio.h>
#include<stdlib.h>

struct Poly { unsigned n; unsigned *p; };

void clean_polynom(struct Poly * p) {
    char postfix_zero_count = 0;
    for (int i=p->n-1; i>=0; --i) { 
        if (p->p[i] != 0) {
            break;
        }
        postfix_zero_count++;
    }

    p->n = p->n-postfix_zero_count;
}

struct Poly mult(struct Poly lhs, struct Poly rhs) {
    struct Poly res = { lhs.n + rhs.n - 1, NULL };
    res.p = calloc(res.n, sizeof(unsigned));

    for (int i=0; i<lhs.n; ++i) {
        for (int k=0; k<rhs.n; ++k) {
            res.p[i+k] = res.p[i+k] + lhs.p[i] * rhs.p[k]; 
        }
    }

    clean_polynom(&res);

    return res;
}

void fill_polynom(struct Poly p) {
    for (int i=0; i<p.n; ++i) {
        scanf("%u", p.p+i);
    }
}

int main() {
    unsigned a_length, b_length;
    scanf("%u", &a_length);
    scanf("%u", &b_length);
    
    struct Poly a = { a_length, NULL };
    a.p = calloc(a.n, sizeof(unsigned));
    fill_polynom(a);

    struct Poly b = { b_length, NULL };
    b.p = calloc(b.n, sizeof(unsigned));
    fill_polynom(b);

    struct Poly res = mult(a, b);

    for (int i=0; i<res.n; ++i) {
        printf("%u ", res.p[i]);
    }
}