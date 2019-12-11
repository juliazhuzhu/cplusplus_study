#include <limits>
#include <time.h>
#include <stdio.h>

void a_expanded(int j){
    printf("a_expended %d. \n",j);
}

#define a(y) a_expanded(y)


int main() {

    printf("%d \n",sizeof(long int));
    time_t maxTime = 0x7FFFFFFF;//std::numeric_limits<time_t>::max();//
    printf("time max is %ld \n", maxTime);

    printf("time end %s \n", ctime(&maxTime));

    a(2);
}
