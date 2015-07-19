#include<stdio.h>
#include<stdlib.h>
#define MAX_LIST_LEN 1024
int partition(int list[], int low, int high) {
    
    int x = list[high];
    int i = low - 1;

    int j = 0;
    int tmp = 0;

    for (j = low; j < high; j++) {
        if (list[j] <= x) {
            i++;
            tmp = list[i];
            list[i] = list[j];
            list[j] = tmp;
        }
    }
    tmp = list[i+1];
    list[i+1] = list[high];
    list[high] = tmp;
    return i+1;
}

void quick_sort(int list[], int low, int high) {
    if (low < high) {
        int q = partition(list, low, high);
        quick_sort(list, low, q - 1);
        quick_sort(list, q + 1, high);
    }
}

int main(int argc, char *argv[]) {
    int i,ni=0;
    int tmp[MAX_LIST_LEN];
    
    while((scanf("%d",&i))!=EOF)
    {   
        tmp[ni]=i;
        ni++;
    }
    int list[ni];
    for(int j = 0;j<ni;j++)
    {   
        list[j]=tmp[j];
    }
    // function pointer
    for(int j = 0;j<ni;j++)
    {
        printf("%d ",list[j]);
    }
    printf("\n");
    void (*sort)(int [], int, int) = quick_sort;


    // use index nubmer
    sort(list, 0, ni-1);

    for(int j = 0;j<ni;j++)
    {
        printf("%d ",list[j]);
    }
    printf("\n");

    return 0;
}
