#include <stdio.h>

// Função para realizar a pesquisa binária
int binarySearch(int arr[], int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // Se o elemento estiver no meio
        if (arr[mid] == target)
            return mid;

        // Se o elemento for maior, ignore a metade direita
        if (arr[mid] < target)
            left = mid + 1;

        // Se o elemento for menor, ignore a metade esquerda
        else
            right = mid - 1;
    }

    // Se o elemento não estiver presente no array
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = binarySearch(arr, 0, n - 1, target);
    if (result == -1)
        printf("Elemento não encontrado\n");
    else
        printf("Elemento encontrado na posicao %d\n", result);
    return 0;
}
