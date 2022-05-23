#include <iostream>
void bubbleSorting(int* arr, int size, int& compares, int& exchanges)
{
    int temp;
    for (int i = 1; i < size; i++)
    {
        for (int j = size - 1; j >= i; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                temp = arr[j-1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                exchanges++;
            }
            compares++;
        }
    }
}
void insertionSorting(int* arr, int size, int& compares, int& exchanges)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        while ((++compares) && j >= 0 && arr[i] < arr[j])
        {
            j -= 1;
        }
        if (j + 1 != i)
        {
            int temp = arr[i];
            int l = i - 1;
            exchanges++;
            while (l >= j + 1)
            {
                arr[l + 1] = arr[l]; l--;
                exchanges++;
            }
            arr[j + 1] = temp;
            exchanges++;
        }
    }
    exchanges = exchanges / 3;
}
void selectionSorting(int* arr, int size, int& compares, int& exchanges)
{
    int temp = 0;
    int k = 0;
    for (int i = 0; i < size - 1; i++)
    {
        k = i;
        for (int j = i + 1; j < size; j++)
        {
            compares++;
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }
            if (i != k)
            {
                temp = arr[i];
                arr[i] = arr[k];
                arr[k] = temp;
                exchanges++;
            }
    }
}
void duplicateArray(int* mainarr, int* duplarr, int size)
{
    for (int i = 0; i < size; i++)
    {
        duplarr[i] = mainarr[i];
    }
}
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    int size;
    std::cout << "Введите размер массива (не более 10.000): ";
    std::cin >> size;
    int* MainArray = new int[size];
    int* SortedArr = new int[size];
    for (int i = 0; i < size; i++)
    {
        MainArray[i] = 0 + rand() % size;
    }
    duplicateArray(MainArray, SortedArr, size);
    bool menu = true;
    int choicemenu, compares, exchanges;
    while (true)
    {
        compares = 0;
        exchanges = 0;
        std::cout << "1) Сортировка обменом(метод пузырька).\n"
            "2) Сортировка выбором.\n"
            "3) Сортировка вставками.\n"
            "4) Выход\nВвод: ";
        std::cin >> choicemenu;
        switch (choicemenu)
        {
        case 1:
            bubbleSorting(SortedArr, size, compares, exchanges);
            std::cout << "\nДо сортировки:\n";
            for (int i = 0; i < size; i++)
            {
                std::cout << MainArray[i] << " ";
            }
            std::cout << "\n\nПосле сортировки:\n";
            for (int i = 0; i < size; i++)
            {
                std::cout << SortedArr[i] << " ";
            }
            std::cout << "\n";
            std::cout << compares << " сравнений, " << exchanges << "перестановок.\n" << std::endl;
            break;
        case 2:
            selectionSorting(SortedArr, size, compares, exchanges);
            std::cout << "\nДо сортировки:\n";
            for (int i = 0; i < size; i++)
            {
                std::cout << MainArray[i] << " ";
            }
            std::cout << "\n\nПосле сортировки:\n";
            for (int i = 0; i < size; i++)
            {
                std::cout << SortedArr[i] << " ";
            }
            std::cout << "\n";
            std::cout << compares << " сравнений, " << exchanges << "перестановок.\n" << std::endl;
            break;
        case 3:
            insertionSorting(SortedArr, size, compares, exchanges);
            std::cout << "\nДо сортировки:\n";
            for (int i = 0; i < size; i++)
            {
                std::cout << MainArray[i] << " ";
            }
            std::cout << "\n\nПосле сортировки:\n";
            for (int i = 0; i < size; i++)
            {
                std::cout << SortedArr[i] << " ";
            }
            std::cout << "\n";
            std::cout << compares << " сравнений, " << exchanges << "перестановок.\n" << std::endl;
            break;
        default:
            menu = false;
            break;
        }
        duplicateArray(MainArray, SortedArr, size);
    }
}