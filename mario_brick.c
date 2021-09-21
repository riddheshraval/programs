#include <stdio.h>
#include <cs50.h>

int get_bricks(void);


int main(void)
{
int n = get_bricks();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("#");
            }
        printf("\n");
        }
    }

int get_bricks(void){
    int n;
    do{
        n = get_int("bricks:");
    }
    while(n < 1);
    return n;
}