#include <iostream>
#include <algorithm>
using namespace std;


struct hero {
    string name;
    int HP;
    int points;
    int age;
    int level;
} number[20];

int amount;

void fill_info(int amount) {

    for (int i = 0; i < amount; i++) {
        cout << "Введите имя героя: ";
        cin >> number[i].name;

        cout << "Введите уровень здоровья героя: ";
        cin >> number[i].HP;

        cout << "Введите очки героя: ";
        cin >> number[i].points;

        cout << "Введите возраст героя: ";
        cin >> number[i].age;

        cout << "Введите уровень героя в игре: ";
        cin >> number[i].level;
    }

}

void bubbleSort() {

    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < amount - 1; i++) {
            if (number[i].HP > number[i + 1].HP) {
                swap(number[i].HP, number[i + 1].HP);
                swapped = true;
            }
        }
    } while (swapped);

    for (int i = 0; i < amount; i++) {
        cout << number[i].HP << " ";
    }
}

void selectionSort() {
    for (int i = 0; i < amount - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < amount; j++) {
            if (number[j].name < number[min_index].name) {
                min_index = j;
            }
        }

        swap(number[i].name, number[min_index].name);
    }

    for (int i = 0; i < amount; i++) {
        cout << number[i].name << " ";
    }
}

void insertionSort()
{
    for (int i = 1; i < amount; ++i)
    {
        int temp = number[i].points;
        int j = i - 1;
        while (j >= 0 && number[j].points > temp)
        {
            number[j + 1].points = number[j].points;
            j--;
        }
        number[j + 1].points = temp;
    }
    
    for (int i = 0; i < amount; i++) {
        cout << number[i].points << " ";
    }
}

void quickSort(int left, int right)
{
    int i = left, j = right;
    int middle = number[(left + right) / 2].age;

    /* partition */
    while (i <= j)
    {
        while (number[i].age < middle)
            i++;

        while (middle < number[j].age)
            j--;

        if (i <= j)
        {
            swap(number[i].age, number[j].age);
            i++;
            j--;
        }
    }

    /* recursion */
    if (left < j)
        quickSort(left, j);

    if (i < right)
        quickSort(i, right);

}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    const int ZERO = 0;
    cout << "Введите количество героев: ";
    cin >> amount;
    fill_info(amount);
    int choose;
    system("cls");
    
    bool reply;
    system("cls");
    do {
        cout << "Каким способом вы хотите воспользоваться?" << endl;
        cout << "1 - Пузырьковая сортировка\n2 - Сортировка выбором.\n3 - Сортировка вставками.\n4 - Быстрая сортировка. \n5 - Сортировка слиянием." << endl;
        cin >> choose;

        switch (choose) {
        case 1: system("cls"); cout << "Пузырьковая сортировка." << endl << endl;
            bubbleSort(); cout << endl;
            break;
        case 2: system("cls"); cout << "Сортировка выбором." << endl << endl;
            selectionSort(); cout << endl;
            break;
        case 3: system("cls"); cout << "Сортировка вставками." << endl << endl;
            insertionSort(); cout << endl;
            break;
        case 4: system("cls"); cout << "Быстрая сортировка." << endl << endl;
            quickSort(ZERO, amount - 1); cout << endl;
            break;
        case 5: system("cls"); cout << "Сортировка слиянием." << endl << endl;
            int* arr = new int[amount];

            for (int i = 0; i < amount; i++) {
                arr[i] = number[i].level;
            }
            mergeSort(arr, 0, amount - 1);

            for (int i = 0; i < amount; i++) {
                number[i].level = arr[i];

                cout << number[i].level << " ";
            }
            delete[] arr; cout << endl;
            break;

        }
        cout << endl << "Вы хотите попробовать другой метод? (1 - да, 0 - нет): ";
        cin >> reply;
    } while (reply);
    
}
