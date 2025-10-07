#include <stdio.h>
#include <assert.h>

int gcd(int a, int b) {
    assert(b != 0);
    int q = a % b;
    if(q == 0) {
        return b;
    }
    return gcd(b, q);
}

typedef struct {
    int x;
    int y;
    int found;
} Solution;

Solution diofantine_equasion_base_solution(int a, int b, int c) {
    Solution solution;
    solution.found = 0;

    if(c % gcd(a,b) != 0) {
        return solution;
    }

    int x = 1;
    int y = 0;

    while (x*a+y*b<c)
    {
        if(c%(x*a+y*b) == 0) {
            int fraction = c/(x*a+y*b);
            solution.x = x*fraction;
            solution.y = y*fraction;
            solution.found = 1;
            break;
        }
    
        x = x - 1;
        y = y + 1;
        if(c%(x*a+y*b) == 0) {
            int fraction = c/(x*a+y*b);
            solution.x = x*fraction;
            solution.y = y*fraction;
            solution.found = 1;
            break;
        }

        x = x + 1;
        if(c%(x*a+y*b) == 0) {
            int fraction = c/(x*a+y*b);
            solution.x = x*fraction;
            solution.y = y*fraction;
            solution.found = 1;
            break;
        }
    }
    return solution;
}

int main() {
    Solution sol = diofantine_equasion_base_solution(1, -1, 1);
    if (sol.found) {
        printf("%d %d\n", sol.x, sol.y);
    } else {
        printf("NONE\n");
    }
    return 0;
}