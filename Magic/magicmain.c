#include <stdio.h>
#include <stdlib.h>
#include <time.h>



const char YES = 'Y';
const char NO = 'N';

char is_Magic2D(int a[3][3], int n, int value){


    int row = 0; /// Initialized Default values
    int column = 0;
    int diagonal_1 = 0;
    int diagonal_2 = 0;
    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < n; j++){
            row += a[i][j];     /// Adds up all the addition of rows and columns
            column += a[j][i];
        }
        if(row != value || column != value) 
            return NO; /// Determine whether the matrix is a magic square if row or column /= value
        row = 0;
        column = 0;
        diagonal_1 += a[i][i];  /// adds up the diagonal value
        diagonal_2 += a[2-i][i];
    }
    if(diagonal_1 != value || diagonal_2 != value) 
        return NO; /// Returns NO if diagonal /= value;

    return YES;
}

void randomize_1D(int *num){
    srand(time(NULL));
    int size = sizeof(num) + 1;
    int rand_n;
    int temp;
    for(int i = 0; i < size; i++){ /// Scrambles the order of 1-9
        rand_n = rand() % size;
        temp = num[rand_n];
        num[rand_n] = num[i];
        num[i] = temp;
    }
}
char randomize_2D(int a[3][3], int *num, int value){
    randomize_1D(num);
    int index_num = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            a[i][j] = num[index_num]; /// The random ordered of 1-9 is placed in the 2D array
            index_num++;
        }
    }
    return is_Magic2D(a,3,value);

}

void print_Matrix(int a[3][3]){
    for(int i = 0; i < 3; i++){
        printf("[  ");
        for(int j = 0; j < 3; j++){
            printf("%d  ", a[i][j]);
        }
        printf("]\n");
    }
        
    
}


int main(){
    const int MAX_VALUE = 500000000;
    int n_size = 3;
    int value = 15;
    int arr_1[][3] = { {4,9,2}, {3,7,5}, {8,1,6} }; 
    print_Matrix(arr_1);      
    if(is_Magic2D(arr_1, n_size, value) == YES)
        printf("This matrix is a Lo Shu Magic Square\n\n");
    else
        printf("This matrix is not a Lo Shu Magic Square\n\n");

    int arr_2[][3] = { {4,9,2}, {3,5,7}, {8,1,6} }; 
    print_Matrix(arr_2);      
    if(is_Magic2D(arr_2, n_size, value) == YES)
        printf("This matrix is a Lo Shu Magic Square\n\n");
    else
        printf("This matrix is not a Lo Shu Magic Square\n\n");

    int arr_3[][3] = { {4,3,8}, {9,5,1}, {2,7,6} }; 
    print_Matrix(arr_3);      
    if(is_Magic2D(arr_3, n_size, value) == YES)
        printf("This matrix is a Lo Shu Magic Square\n\n");
    else
        printf("This matrix is not a Lo Shu Magic Square\n\n");

    int num[] = {1,2,3,4,5,6,7,8,9};
    int arr_random[3][3];
    char result;
    int counter = 0;
    do{
            result = randomize_2D(arr_random, num, value);
            counter++;
    }while(result != YES && counter <= MAX_VALUE); ///Keeping track of the counter helps us avoid infinite loop.
    print_Matrix(arr_random);
    if(result == YES)
        printf("This matrix is a Lo Shu Magic Square\n\n");
    else{
        printf("Last generated matrix\n");
        printf("This matrix is not a Lo Shu Magic Square\n");
        printf("The amount of squares generated meets the exceeded maximum = 500000000"); 
    }

    return 0;
}
