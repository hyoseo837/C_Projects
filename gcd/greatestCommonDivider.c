#include <stdio.h>
#include <time.h>

int gcd(int m, int n)
{
    int r;
    if(n>m){
        return gcd(n,m);
    }

    while (n>0)
    {
        r = m % n;
        m = n;
        n = r;
    }   
    return m;
}

int main(){
    double time_spent = 0.0;
    clock_t begin = clock();

    printf("%d\n\n",gcd(70020,1125));

    
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds\n", time_spent);
    return 0;
}