#include <stdio.h>

int summation(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

int maximum(int arr[], int n){
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int main(){
    int n;
    printf("Enter the length of the array (n): \n");
    scanf("%d", &n);

    int arr[n];
    printf("Enter integers of the array: \n");

    for (int i = 0; i < n ; i++) {
        printf("Enter element: \n");
        scanf("%d", &arr[i]);

    }

    printf("SUM: %d\n", summation(arr, n));
    printf("MAXIMUM: %d\n", maximum(arr, n));

    return 0;
}