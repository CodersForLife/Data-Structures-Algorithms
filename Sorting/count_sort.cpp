//Counting sort works when the input is known to be withing a range.
#include <iostream>

using namespace std;

const int INPUT_SIZE = 20;  //total count of input numbers
const int BUCKET_K = 10;   //range of numbers will be from 1 to 10

void print(int *input)
{
    for ( int i = 0; i < INPUT_SIZE; i++ )
        cout << input[i] << " ";
    cout << endl;
}

void countingsort(int* input)
{
    int CountArr[BUCKET_K] = { 0 };

    for (int i=0;i<INPUT_SIZE;i++)
    {
        CountArr[input[i]]++;
    }

    int outputindex=0;
    for (int j=0;j<BUCKET_K;j++)
    {
        while (CountArr[j]--)
            input[outputindex++] = j;
    }

}

int main()
{
    int input[INPUT_SIZE] = { 2, 4, 6, 4, 7, 1, 4, 9, 5, 3, 7, 2, 2, 6, 9, 3, 7, 3, 4, 4 };

    cout << "Input: ";
    print(input);
    countingsort(input);
    cout << "Output: ";
    print(input);
    return 0;
}