# Analysis And Design of Algorithms LAB

## Contents
- Lab 1: Duplicate Elements, Horner’s Rule, Linear Search, Permutation Generator, Selection Sort, Tower of Hanoi, Velocity, Power (Iterative & Recursive) , sum of n numbers (iterative & recursive), truth table generation (iterative & recursive) , bubble sort , consecutive numbers
- Lab 2: Binary Search, Insertion Sort
- Lab 3: Partitioning concept in quick sort(findpos code), Quick Sort
- Lab 4: Binary Search (Modified--n/3 and 2n/3 division), Merge Sort
- Lab 5: Convex Hull, Knapsack, Kth Smallest, Max-Min
- Lab 6: Dijkistra Algorithm, Prim’s Algorithm, Kruskal's Algorithm
- Lab 7: Single Source Shortest Path (SSSP), Multistage Graph(stages calculation)
- Lab 8: Matrix Chain Multiplication, Multistage (Forward & Backward)
- Lab 9: Travelling Salesperson , 0/1 Knapsack
- Lab 10: N-Queens , Subset sum , Graph colouring

---
## LAB 1 :

## 1. Program: duplicate

### Problem Statement
Find duplicate elements in an array.

### Topic
Array 

### Naive Approach
Compare each element with every other element.

### Algorithm
1. Input array
2. Use nested loops
3. Compare elements
4. Print duplicates

### Time Complexity
O(n²)

### Implemented Code
```cpp
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                index = j;   
                break;
            }
        }
        if (index != -1)
            break;
    }

    if (index != -1)
        cout << "first duplicate found at index: " << index << endl;
    else
        cout << "no duplicate found" << endl;
    return 0;
}
```
### Output of the implemented code
```text
enter number of elements: 7
enter array elements:
2 3 5 3 8 7 5
first duplicate found at index: 3
```
---

## 2. Program: hornor

### Problem Statement
Evaluate polynomial using Horner’s Rule.

### Naive Approach
Compute each power separately.

### Algorithm
1. Input coefficients and value of x
2. Initialize result
3. Apply Horner’s formula iteratively

### Time Complexity
O(n)

### Implemented Code
```cpp
#include <iostream>
using namespace std;
int horner(int coeff[], int n, int x)
{
    if (n == 0)
        return coeff[0];
    return x * horner(coeff, n - 1, x) + coeff[n];
}
int main()
{
    int n, x;
    cout << "enter degree of polynomial: ";
    cin >> n;
    int coeff[n + 1];
    cout << "enter coefficients from a0 to an:\n";
    for (int i = 0; i <= n; i++)
        cin >> coeff[i];
    cout << "Enter value of x: ";
    cin >> x;
    int result = horner(coeff, n, x);
    cout << "value of polynomial: " << result << endl;
    return 0;
}

```
### Output of the implemented code
```text
enter degree of polynomial: 3
enter coefficients from a0 to an:
3
6
7
8
Enter value of x: 2
value of polynomial: 70
```
---

## 3. Program: linearsearch

### Problem Statement
Search an element in an array.

### Topic
Searching (Linear Search)

### Naive Approach
Traverse entire array.

### Algorithm
1. Input array and key
2. Traverse array
3. If found, return index

### Time Complexity
O(n)

### Edge Cases
- Element not present
- Multiple occurrences

### Implemented Code
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
int linearsearch(int arr[], int size, int index, int key)
{
    if (index == size)
        return -1;
    if (arr[index] == key)
        return index;
    return linearsearch(arr, size, index + 1, key);
}
int main()
{
    int size;
    cout << "enter size of array: ";
    cin >> size;
    int arr[size];
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }
    int key = arr[size-1] ;
    auto start = high_resolution_clock::now();
    int result = linearsearch(arr, size, 0, key);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
        ofstream file("output.txt", ios::app);
    file << "array size" << " " << "duration"<< endl;
    if (result != -1)
    file << size << " " << duration.count() << endl;
    else
    file << size << " " << duration.count() << endl;
    file.close();
    cout << "Output successfully written to output.txt" << endl;
    return 0;
}

```
### Output of the implemented code
```text
array size duration
50 2800
array size duration
100 3100
array size duration
200 7800
array size duration
500 53700
array size duration
1000 142100
array size duration
2000 226600
```

### Graph
![linear-search](image-1.png)
---

## 4. Program: permutation generator

### Problem Statement
Generate all permutations of a given set.

### Topic
Recursion

### Naive Approach
Try all possible arrangements.

### Algorithm
1. Fix one element
2. Recursively permute remaining
3. Swap elements

### Time Complexity
O(n!)

### Implemented Code
```cpp
#include <iostream>
#include <cstring>
using namespace std;
void permutation(char a[], int k, int n)
{
    if (k == n)
    {
        cout << a << " ";
        return;
    }
    for (int i = k; i <= n; i++)
    {
        swap(a[i], a[k]);
        permutation(a, k + 1, n);
        swap(a[i], a[k]); 
    }
}
int main()
{
    char a[100];
    cout << "Enter string: ";
    cin >> a;
    int n = strlen(a);
    permutation(a, 0, n - 1);
    return 0;
}

```
### Output of the implemented code
```text
Enter string: abc
abc acb bac bca cba cab 
```

---

## 5. Program: selection sort

### Problem Statement
Sort an array using Selection Sort.

### Topic
Sorting Algorithm

### Naive Approach
Repeatedly find minimum and swap.

### Algorithm
1. Find minimum element
2. Swap with first position
3. Repeat for remaining array

### Time Complexity
O(n²)

### Edge Cases
- Already sorted
- Reverse sorted

### Implemented Code
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minindex])
                minindex = j;
        }
        swap(arr[i], arr[minindex]);
    }
}
int main()
{
    int size;
    cout << "enter size of array: ";
    cin >> size;
    int arr[size];
    srand(time(0));
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100;
    auto start = high_resolution_clock::now();
    selectionsort(arr, size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
        ofstream file("selection_output.txt", ios::app);
    file << "array size" << " " << "duration"<< endl;
    file << size << " " << duration.count() << endl;
    cout << "Output successfully written to selection_output.txt" << endl;
    return 0;
}

```
### Output of the implemented code
```text
array size duration
50 12700
array size duration
100 58900
array size duration
200 115500
array size duration
500 495700
array size duration
1000 3017700
array size duration
5000 97092100
array size duration
10000 209923400
array size duration
100 57200
array size duration
200 171200
array size duration
400 795600
array size duration
800 2263000
array size duration
1600 8596700
```

### Graph
![selectionsort](image-2.png)
---

## 6. Program: towerofhanoi 

### Problem Statement
Solve Tower of Hanoi problem.

### Topic
Recursion

### Naive Approach
Move disks manually.

### Algorithm
1. Move n-1 disks to auxiliary
2. Move largest disk
3. Move n-1 disks to destination

### Time Complexity
O(2ⁿ)

### Implemented Code
```cpp
#include<iostream>
using namespace std;
void TOH(int n , char F ,  char U , char T){
    if(n == 1){
    cout << "move disk from " << F << " to " << T << endl;
    return ;
    }
    else
    TOH(n-1,F,T,U);
    cout << "move disk from " << F << " to " << T << endl;
    TOH(n-1,U,F,T);
}
int main(){
    cout << "enter number of disks : ";
    int n;
    cin >> n;
    TOH(n,'F', 'U', 'T');
    return 0;
}
```
### Output of the implemented code
```text
enter number of disks : 3
move disk from F to T
move disk from F to U
move disk from T to U
move disk from F to T
move disk from U to F
move disk from U to T
move disk from F to T
```

---

## 7. Program: velocity

### Problem Statement
Given an initial velocity, determine how many times the velocity reduces (tips/stoppages) until it becomes less than 1.0, where each reduction multiplies the velocity by a constant factor.

### Topic
Recursion

### Naive Approach
Use an iterative loop to repeatedly multiply velocity by the reduction factor until it becomes less than 1.

### Algorithm
1. Input initial velocity v
2. Define reduction factor (0.575)
3. If v < 1, stop recursion
4. Otherwise:
   - Increment count (tips)
   - Reduce velocity: v = v * reduction
   - Call function recursively
5. Print total number of tips

### Time Complexity
O(log v)  
(Since velocity decreases exponentially each step)

### Implemented Code
```cpp
#include <iostream>
using namespace std;
double reduction = 0.575; 
int tips = 0;
void no_of_stoppage(double v)
{
    if (v < 1.0)
    return;
    tips++;
    double newvelocity = v * reduction;
    no_of_stoppage(newvelocity);
}
int main()
{
    double v;
    cout << "enter initial velocity : ";
    cin >> v;
    no_of_stoppage(v);
    cout << "number of tips: " << tips << endl;
    return 0;
}

```
### Output of the implemented code
```text
enter initial velocity : 100
number of tips: 9
```

---

## 8. Program: x power n iterative

### Problem Statement
Compute x power n using iterative method.

### Naive Approach
Multiply x repeatedly n times.

### Algorithm
1. Initialize result = 1
2. Loop n times
3. Multiply result by x

### Time Complexity
O(n)

### Implemented Code
```cpp
#include<iostream>
using namespace std;
int main(){
    int x,n,result=1;
    cout<<"enter value of x : ";
    cin>>x;
    cout<<"enter value of n : ";
    cin>>n;
    for(int i = 1 ; i <= n ; i++){
        result *= x;
    }
    cout << "result = " << result;
}

```
### Output of the implemented code
```text
enter value of x : 2
enter value of n : 10
result = 1024
```

---

## 9. Program: x power n recursive

### Problem Statement
Compute x power n using recursion.

### Topic
Recursion

### Naive Approach
Repeated recursive multiplication.

### Algorithm
1. Base case: n = 0 return 1
2. Recursive call: x * power(x, n-1)

### Time Complexity
O(n)

### Edge Cases
- Negative powers 

### Implemented Code
```cpp
#include <iostream>
using namespace std;
int power(int x, int n) {
    if (n == 0)
    return 1;
    return x * power(x, n - 1);
}
int main() {
    int x,n,result=1;
    cout << "enter value of x : ";
    cin >> x;
    cout << "enter value of n : ";
    cin >> n;
    cout << "result = " << power(x,n);
    return 0;
}
```

### Output of the implemented code
```text
enter value of x : 2
enter value of n : 10
result = 1024
```
---
## 10. Program: sumofnnumberiterative

### Problem Statement
Find the sum of first n natural numbers using iterative approach.

### Topic
Iteration

### Naive Approach
Add numbers from 1 to n using a loop.

### Algorithm
1. Input value of n
2. Initialize sum = 0
3. Loop from 1 to n:
   - Add i to sum
4. Output sum

### Time Complexity
O(n)

### Implemented Code
```cpp
#include <iostream>
using namespace std;
int main() {
    int n, sum = 0;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    cout << "Sum = " << sum;
    return 0;
}

```
### Output of the implemented code
```text
Enter number of elements: 6
Enter elements:
1
4
5
9
7
56
Sum = 82
```
---
## 11. Program: sumofnnumbersrecursive

### Problem Statement
Find the sum of first n natural numbers using recursion.

### Topic
Recursion

### Naive Approach
Repeated recursive addition.

### Algorithm
1. Base case: if n = 0 return 0
2. Return n + sum(n-1)

### Time Complexity
O(n)

### Implemented Code
```cpp
#include <iostream>
using namespace std;

int sum(int a[], int n) {
    if (n == 0)
        return 0;
    return a[n - 1] + sum(a, n - 1);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Sum = " << sum(a, n);
    return 0;
}

```
### Output of the implemented code
```text
Enter number of elements: 6
Enter elements:
1 23 45 67 89 2
Sum = 227
```

---

## 12. Program: truthtableiterative

### Problem Statement
Generate truth table for logical expressions using iterative approach.

### Topic
Iteration

### Naive Approach
Manually write all combinations.

### Algorithm
1. Determine number of variables
2. Loop through all binary combinations
3. Evaluate logical expression
4. Print results

### Time Complexity
O(2ⁿ)

### Implemented Code
```cpp
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cout << "Enter number of variables: ";
    cin >> n;
    int rows = pow(2, n);
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if ((i >> j) & 1)
                cout << "true ";
            else
                cout << "false ";
        }
        cout << endl;
    }
    return 0;
}
```
### Output of the implemented code
```text
Enter number of variables: 3
true true true 
true true false 
true false true 
true false false 
false true true 
false true false 
false false true 
false false false 
```
---

## 13. Program: truthtablerecursive

### Problem Statement
Generate truth table using recursion.

### Topic
Recursion 

### Naive Approach
Use nested loops for combinations.

### Algorithm
1. Recursively generate binary combinations
2. At each level assign 0 or 1
3. When all variables assigned:
   - Evaluate expression
   - Print result

### Time Complexity
O(2ⁿ)

### Implemented Code
```cpp
#include <iostream>
using namespace std;
void truthTable(bool arr[], int n, int index) {
    if (index == n) {
        for (int i = 0; i < n; i++) {
            if (arr[i])
                cout << "true ";
            else
                cout << "false ";
        }
        cout << endl;
        return;
    }
    arr[index] = true;
    truthTable(arr, n, index + 1);
    arr[index] = false;
    truthTable(arr, n, index + 1);
}
int main() {
    int n;
    cout << "Enter number of variables: ";
    cin >> n;
    bool arr[n];
    truthTable(arr, n, 0);
    return 0;
}

```
### Output of the implemented code
```text
Enter number of variables: 3
true true true 
true true false 
true false true 
true false false 
false true true 
false true false 
false false true 
false false false 
```

---

## 14. Program: bubble sort

### Problem Statement
Sort an array using Bubble Sort.

### Topic
Sorting Algorithm

### Naive Approach
Repeatedly compare adjacent elements and swap if they are in wrong order.

### Algorithm
1. Input array
2. Traverse array multiple times
3. Compare adjacent elements
4. Swap if needed
5. Repeat until array is sorted

### Time Complexity
O(n²)

### Implemented Code
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}
int main()
{
    int size;
    cout << "enter size of array: ";
    cin >> size;
    int arr[size];
    srand(time(0));
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100;
    auto start = high_resolution_clock::now();
    bubblesort(arr, size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
        ofstream file("bubble_output.txt", ios::app);
    file << "array size" << " " << "duration"<< endl;
    file << size << " " << duration.count() << endl;
    cout << "Output successfully written to bubble_output.txt" << endl;
    return 0;
}
```
### Output of the implemented code
```text
array size duration
50 26900
array size duration
100 93600
array size duration
200 261200
array size duration
400 1099300
array size duration
600 2385600
```

### Graph
![bubblesort](image-8.png)

---

## 15. Program: consecutive

### Problem Statement
Given a sequence of consecutive numbers with one number missing, find the missing number.

### Topic
Array Processing

### Naive Approach
Check every possible number in the range and compare with array elements.

### Algorithm
1. Input number of elements and array
2. Traverse array from index 0 to n-2
3. For each element:
   - Increment current element by 1
   - Compare with next element
4. If mismatch found:
   - Missing number = current element + 1
5. If no mismatch, no number is missing

### Time Complexity
O(n)
### Implemented Code
```cpp
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "enter consecutive numbers:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int missing = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int ele= arr[i];
        ele++; 
        if (arr[i + 1] != ele)
        {
            missing = ele;
            break;
        }
    }
    if (missing != -1)
        cout << "missing number is: " << missing << endl;
    else
        cout << "no number is missing" << endl;
    return 0;
}

```
### Output of the implemented code
```text
enter number of elements: 5
enter consecutive numbers:
1 2 4 5 6 
missing number is: 3
```

---

## LAB 2 :

## 1. Program: binarysearch

### Problem Statement
Search an element in a sorted array using binary search.

### Topic
Divide and Conquer

### Naive Approach
Use linear search.

### Algorithm
1. Set low and high
2. Find mid
3. Compare with target
4. Adjust search range

### Time Complexity
O(log n)

### Edge Cases
- Element not present
- Single element

### Implemented Code
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
int binarysearch(int arr[], int key, int low, int high)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        return binarysearch(arr, key, low, mid - 1);
    else
        return binarysearch(arr, key, mid + 1, high);
}
void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}
int main()
{
    int size;
    cout << "enter size of array: ";
    cin >> size;
    int arr[size];
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }
    bubblesort(arr,size);
    int key = rand() ;
    auto start = high_resolution_clock::now();
    int result = binarysearch(arr,key,0,size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
        ofstream file("binarysearchoutput.txt", ios::app);
    file << "array size" << " " << "duration"<< endl;
    if (result != -1)
    file << size << " " << duration.count() << endl;
    else
    file << size << " " << duration.count() << endl;
    file.close();
    cout << "Output successfully written to binarysearchoutput.txt" << endl;
    return 0;
}

```
### Output of the implemented code
```text
array size duration
100 700
array size duration
200 500
array size duration
300 800
array size duration
400 700
```

### Graph

---

## 2. Program: insertionsort

### Problem Statement
Sort an array using Insertion Sort.

### Topic
Sorting Algorithm

### Naive Approach
Insert each element in sorted position.

### Algorithm
1. Take one element
2. Compare with previous elements
3. Shift and insert in correct position

### Time Complexity
O(n²)

### Edge Cases
- Already sorted (best case O(n))
- Reverse sorted
### Implemented Code
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
void insertionsort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int size;
    cout << "enter size of array: ";
    cin >> size;
    int arr[size];
    srand(time(0));
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100;
    auto start = high_resolution_clock::now();
    insertionsort(arr, size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
        ofstream file("insertion_output.txt", ios::app);
    file << "array size" << " " << "duration"<< endl;
    file << size << " " << duration.count() << endl;
    cout << "Output successfully written to insertion_output.txt" << endl;
    return 0;
}

```
### Output of the implemented code
```text
array size duration
50 10000
array size duration
100 42400
array size duration
200 80200
array size duration
500 510100
array size duration
1000 1797000
array size duration
2000 6578900
array size duration
5000 30034500
```

### Graph
![insertion sort](image-3.png)
---
## LAB 3 :

## Program: findpos

### Problem Statement
Determine the correct position of the first element in an array such that all smaller elements are placed before it and larger elements after it (partitioning around a pivot).

### Topic
Divide and Conquer / Partitioning (Quick Sort Concept)

### Naive Approach
Sort the entire array and then find the position of the first element.

### Algorithm
1. Take the first element as key (pivot)
2. Count number of elements smaller than key → gives correct position
3. Initialize two pointers:
   - i from start
   - j from end
4. Swap elements such that:
   - Smaller elements move left
   - Larger elements move right
5. Place pivot at correct position

### Time Complexity
O(n)
### Implemented Code
```cpp
#include <iostream>
#include <iostream>
using namespace std;
int findposition(int arr[], int n){
    int l=0,s=0;
    for (int i=1;i<n;i++){
    if(arr[i]>arr[0])
    l++;
    else
    s++;
    }
    return s;
}
void arrange (int arr[], int n){
    int key = arr[0];
    int pos=findposition(arr,n);
    int i=1,j=n;
    while(i<=pos&&j>=pos){
    while(i<j){
        if(arr[i]>key){
            swap(key,arr[i]);
            i++;
        }
        if(arr[j]<key){
            swap(key,arr[j]);
            j--;
        }
    }
    swap(arr[key],j);
    }
}
int main()
{
    int size;
    cout << "enter size of array: ";
    cin >> size;
    int arr[size];
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand()%100;
    }
    cout<<"your array = ";
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    arrange(arr,size);
    return 0;
}

```

### Problem Statement
Sort an array using Quick Sort.

### Topic
Divide and Conquer

### Naive Approach
Use simple sorting like Bubble Sort (O(n²)).

### Algorithm
1. Choose a pivot element
2. Partition array into elements < pivot and > pivot
3. Recursively apply quicksort on subarrays

### Time Complexity
Best: O(n log n)  
Worst: O(n²)

### Edge Cases
- Already sorted array
- Duplicate elements
- Single element
### Implemented Code
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

int findposition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int count = 0;

    for (int i = low + 1; i <= high; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }
    return low + count;
}

int partition(int arr[], int low, int high)
{
    int pos = findposition(arr, low, high);
    int pivot = arr[low];

    swap(arr[low], arr[pos]);

    int i = low, j = high;

    while (i < pos && j > pos)
    {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;

        if (i < pos && j > pos)
            swap(arr[i++], arr[j--]);
    }
    return pos;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int* arr = new int[size];
    srand(time(0));

    for (int i = 0; i < size; i++)
        arr[i] = rand() ;

    auto start = high_resolution_clock::now();
    quicksort(arr, 0, size - 1);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    ofstream file("quicksortoutput.txt", ios::app);
    file << size << " " << duration.count() << endl;
    file.close();

    cout << "\nOutput successfully written to quicksortoutput.txt" << endl;

    delete[] arr;
    return 0;
}

```
### Output of the implemented code
```text
100 33300
200 72600
400 148900
800 341500
1600 668400
```

### Graph
![quicksort](image-4.png)
---

## LAB 4 :

## 1. Program: binary_modified

### Problem Statement
Perform binary search on a sorted array to find a given element where array is partitioned as n/3 and 2n/3 instead of n/2 and n/2.

### Topic
Divide and Conquer (Binary Search)

### Naive Approach
Use linear search to check each element.

### Algorithm
1. Input sorted array
2. Set low = 0, high = n-1
3. While low ≤ high:
   - Find mid which will be high - low / 3 in this case
   - If element found, return index
   - Else adjust low/high
4. Return -1 if not found

### Time Complexity
O(log n) same as binary as we only changed partition 

### Edge Cases
- Element not present
- Duplicate elements
- Single element
### Implemented Code
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
int binarysearch(int arr[], int key, int low, int high)
{
    if (low > high)
    return -1;
    int mid = low + (high - low) / 3;
    if (arr[mid] == key)
    return mid;
    else if (arr[mid] > key)
    return binarysearch(arr, key, low, mid - 1);
    else
    return binarysearch(arr, key, mid + 1, high);
}
void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}
int main()
{
    int size;
    cout << "enter size of array: ";
    cin >> size;
    int arr[size];
    cout << "enter array elements";
    for (int i = 0; i < size; i++)
    {
       cin >> arr[i];
    }
    int key ;
    cout << "enter key";
    cin >> key ;
    bubblesort(arr,size);
    int result = binarysearch(arr,key,0,size);
    if ( result == -1)
    cout << "element not found";
    else
    cout << "element found";
    return 0;
}

```
### Output of the implemented code
```text
enter size of array: 10
enter array elements1 4 3 2 7 6 5 9 2 7
enter key8
element not found
```

## 2. Program: mergesort

### Problem Statement
Sort an array using Merge Sort.

### Topic
Divide and Conquer

### Naive Approach
Use simple sorting like Selection Sort.

### Algorithm
1. Divide array into two halves
2. Recursively sort both halves
3. Merge the sorted halves

### Time Complexity
O(n log n)

### Edge Cases
- Empty array
- Single element
- Large input size
### Implemented Code
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int *left = new int[n1];
    int *right = new int[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];
    int i = 0;
    int j = 0;
    int k = low;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
    delete[] left;
    delete[] right;
}
void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int main()
{
    int size;
    cout << "enter size of array: ";
    cin >> size;
    int *arr = new int[size];
    srand(time(0));
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 10000;
    auto start = high_resolution_clock::now();
    mergesort(arr, 0, size - 1);
    auto stop = high_resolution_clock::now();
    auto duration =
        duration_cast<nanoseconds>(stop - start);
    ofstream file("mergesortoutput.txt", ios::app);
    file << size << " "
         << duration.count()
         << endl;
    file.close();
    cout << "output saved in mergesortoutput.txt" << endl;
    cout << "time taken: "
         << duration.count()
         << " ns" << endl;
    delete[] arr;
    return 0;
}

```
### Output of the implemented code
```text
50 35600
100 97600
200 209100
500 404000
1000 814600
```

### Graph
![mergesort](image-5.png)
---

## LAB 5 :

## 1. Program: convexhull.cpp

### Problem Statement
Find the convex hull of a set of points.

### Naive Approach
Check all subsets of points to determine hull .

### Algorithm
1. Input set of points
2. Find leftmost point
3. Select next point using orientation
4. Repeat until returning to start point

### Time Complexity
O(n log n)

### Edge Cases
- Less than 3 points
- Collinear points
- Duplicate points
### Implemented Code
```cpp
#include <iostream>
#include <vector>
using namespace std;

struct point {
    int x, y;
};

int orientation(point a, point b, point c) {
    return (b.x - a.x)*(c.y - a.y) -
           (b.y - a.y)*(c.x - a.x);
}

bool insideTriangle(point a, point b, point c, point p) {
    int o1 = orientation(a, b, p);
    int o2 = orientation(b, c, p);
    int o3 = orientation(c, a, p);

    if ((o1 >= 0 && o2 >= 0 && o3 >= 0) ||
        (o1 <= 0 && o2 <= 0 && o3 <= 0))
        return true;

    return false;
}

int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    vector<point> points(n);
    cout << "Enter points (x y):\n";
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    vector<bool> ishull(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {

                bool valid = true;

                for (int m = 0; m < n; m++) {
                    if (m == i || m == j || m == k)
                        continue;

                    if (insideTriangle(points[i],
                                       points[j],
                                       points[k],
                                       points[m])) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    ishull[i] = true;
                    ishull[j] = true;
                    ishull[k] = true;
                }
            }
        }
    }

    cout << "\nConvex Hull Points:\n";
    for (int i = 0; i < n; i++) {
        if (ishull[i])
            cout << "(" << points[i].x
                 << ", " << points[i].y << ")\n";
    }

    return 0;
}
```
### Output of the implemented code
```text
Enter number of points: 5
Enter points (x y):
1 2
3 4
7 6
3 6
9 7

Convex Hull Points:
(1, 2)
(3, 4)
(7, 6)
(3, 6)
(9, 7)
```
---

## 2. Program: knapsack.cpp

### Problem Statement
Maximize profit in knapsack without exceeding capacity.

### Topic
Greedy 

### Naive Approach
Try all subsets of items.

### Algorithm
1. Input weights and profits
2. Compute profit/weight ratio
3. Sort items based on ratio
4. Select items within capacity

### Time Complexity
O(n log n)

### Edge Cases
- Capacity = 0
- Item weight greater than capacity
- All items fit within capacity

### Implemented Code
```cpp
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;
    double arr[n][3];  
    for (int i = 0; i < n; i++) {
        cout << "enter profit and weight for " << i+1 << " item : ";
        cin >> arr[i][0] >> arr[i][1];
        arr[i][2] = arr[i][0] / arr[i][1]; 
    }
    cout << "Enter capacity: ";
    cin >> capacity;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i][2] < arr[j][2]) {
                for (int k = 0; k < 3; k++) {
                    swap(arr[i][k], arr[j][k]);
                }
            }
        }
    }
    double totalProfit = 0;
    for (int i = 0; i < n; i++) {
        if (capacity >= arr[i][1]) {
            capacity -= arr[i][1];
            totalProfit += arr[i][0];
        }
        else {
            totalProfit += arr[i][0] * (capacity / arr[i][1]);
            break;
        }
    }
    cout << "Maximum Profit = " << totalProfit;
    return 0;
}

```
### Output of the implemented code
```text
Enter number of items: 5
enter profit and weight for 1 item : 5 20
enter profit and weight for 2 item : 5 30
enter profit and weight for 3 item : 2 10
enter profit and weight for 4 item : 7 4
enter profit and weight for 5 item : 10 4
Enter capacity: 20
Maximum Profit = 20
```

## 3. Program: Kth Smallest Element

### Problem Statement
Find the k-th smallest element in an array.

### Topic
Selection 

### Naive Approach
Sort the array and return k-1 index.

### Algorithm
1. Input array
2. Sort array
3. Return arr[k-1]

### Time Complexity
O(n log n)

### Edge Cases
- k > n
- Duplicate values
- Negative elements

### Implemented Code
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
int kthsmallest(int arr[], int low, int high, int k) {
    if (low <= high) {
        int p = partition(arr, low, high);
        if (p == k)
            return arr[p];
        else if (p > k)
            return kthsmallest(arr, low, p - 1, k);
        else
            return kthsmallest(arr, p + 1, high, k);
    }
    return -1; 
}
int main() {
    cout << "enter size of array : ";
    int n;
    cin >> n ;
    int arr [n];
    for (int i = 0 ; i < n ; i++)
    arr[i] = rand() ;
    int k = rand()%100 ; 
    auto start = high_resolution_clock::now();
    kthsmallest(arr, 0, n - 1, k - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    ofstream file("kthsmallest_output.txt", ios::app);
    file << n << " " << duration.count() << endl;
    file.close();

    cout << "\noutput successfully written" << endl;
    cout << "kth smallest element: "<< kthsmallest(arr, 0, n - 1, k - 1);
    return 0;
}

```
### Output of the implemented code
```text
10 900
100 9500
1000 30200
2000 141500
```

### Graph
![kth smalllest](image-6.png)
---

## 4. Program: Max-Min Element

### Problem Statement
Find the maximum and minimum element in an array.

### Topic
Divide & Conquer 

### Naive Approach
Traverse array twice to find max and min.

### Algorithm
1. Initialize min and max as first element
2. Traverse array
3. Update min and max accordingly

### Time Complexity
O(n)

### Edge Cases
- Single element array
- All elements equal
- Negative numbers

### Implemented Code
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
struct minmax {
    int min;
    int max;
};
minmax maxormin(int arr[], int low, int high) {
    minmax result, left, right;
    if (low == high) {
        result.min = result.max = arr[low];
        return result;
    }
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }
    int mid = (low + high) / 2;
    left = maxormin(arr, low, mid);
    right = maxormin(arr, mid + 1, high);
    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;
    return result;
}
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    arr[i] = rand() ;
    auto start = high_resolution_clock::now();
    maxormin(arr, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    ofstream file("maxormin_output.txt", ios::app);
    file << n << " " << duration.count() << endl;
    file.close();
    cout << "\noutput successfully written" << endl;
    return 0;
}

```
### Output of the implemented code
```text
10 1200
50 1800
100 5600
500 13900
1000 57000
2000 68200
5000 221900
10000 527900
```

### Graph
![minmax](image-7.png)
---
## LAB 6
## 1. Program: Prim’s Algorithm

### Problem Statement
Find the Minimum Spanning Tree (MST) of a graph.

### Topic
Greedy Algorithm

### Naive Approach
Generate all spanning trees and pick minimum which is discarded because it is inefficient.

### Algorithm
1. Start from any vertex
2. Select minimum weight edge connecting visited to unvisited node
3. Repeat until all vertices are included

### Time Complexity
O(V²)

### Edge Cases
- Disconnected graph
- Negative weights
- Single node graph
### Implemented Code
```cpp
#include <iostream>
using namespace std;
#define MAX 50
#define INTMAX 100000
void prims(int cost[MAX][MAX], int n) {
    int t[MAX][2];
    int near[MAX];
    int mincost = 0;
    int k = 0, l = 0;
    int min = INTMAX;
    // find minimum cost edge
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cost[i][j] < min) {
                min = cost[i][j];
                k = i;
                l = j;
            }
        }
    }
    t[0][0] = k;
    t[0][1] = l;
    mincost = cost[k][l];
    // initialize near array
    for (int i = 0; i < n; i++) {
        if (cost[i][k] < cost[i][l])
            near[i] = k;
        else
            near[i] = l;
    }
    // -1 means vertex already included in MST
    near[k] = near[l] = -1;
    for (int j = 1; j < n - 1; j++) {
        min = INTMAX;
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (near[i] != -1 && cost[i][near[i]] < min) {
                min = cost[i][near[i]];
                index = i;
            }
        }
        t[j][0] = index;
        t[j][1] = near[index];
        mincost += cost[index][near[index]];
        near[index] = -1;
        for (int i = 0; i < n; i++) {
            if (near[i] != -1 && cost[i][index] < cost[i][near[i]]) {
                near[i] = index;
            }
        }
    }
    cout << "\nEdges in MST:\n";
    for (int i = 0; i < n - 1; i++) {
        cout << t[i][0] << " - " << t[i][1] << endl;
    }
    cout << "Minimum Cost = " << mincost << endl;
}
int main() {
    int n;
    int cost[MAX][MAX];
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (i != j && cost[i][j] == 0)
                cost[i][j] = INTMAX;
        }
    }
    prims(cost, n);
    return 0;
}

```
### Output of the implemented code
```text
Enter number of vertices: 4
Enter cost matrix:
0 10 6 5
10 0 0 15
6 0 0 4
5 15 4 0
Edges in MST:
2 - 3
0 - 3
1 - 0
Minimum Cost = 19
```

## 2. Program: dijkstra

### Problem Statement
Find the shortest path from a source vertex to all other vertices in a weighted graph.

### Topic
Greedy 

### Naive Approach
Check all possible paths between nodes.

### Algorithm
1. Initialize all distances to infinity
2. Set source distance = 0
3. Repeat V-1 times:
   - Select unvisited vertex with minimum distance
   - Mark it visited
   - Relax all adjacent edges
4. Print shortest distances

### Time Complexity
O(V²)
### Implemented Code
```cpp
#include <iostream>
#include <climits>
using namespace std;
#define MAX 100
#define INF INT_MAX
int V;
int graph[MAX][MAX];
void dijkstra(int src) {
    int dist[MAX];
    bool visited[MAX];
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1, min = INF;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }
        visited[u] = true;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 && graph[u][v] != INF) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
    cout << "Vertex\tDistance\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}
int main() {
    cout << "enter number of vertices: ";
    cin >> V;
    cout << "enter adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }
    int src;
    cout << "enter source vertex: ";
    cin >> src;
    dijkstra(src);
    return 0;
}
```
### Output of the implemented code
```text
enter number of vertices: 4
enter adjacency matrix:
0 10 6 5
10 0 0 15
6 0 0 4 
5 15 4 0
enter source vertex: 1
Vertex  Distance
0       10
1       0
2       16
3       15
```

## 3. Program: kruskal.cpp

### Problem Statement
Find the Minimum Spanning Tree (MST) of a graph.

### Topic
Greedy 

### Naive Approach
Generate all spanning trees and select minimum.

### Algorithm
1. Sort all edges in increasing order of weight
2. Make each vertex its own set
3. For each edge:
   - If it connects different sets:
     - Add to MST
     - Union the sets
4. Stop when V-1 edges are selected

### Time Complexity
O(E log E)
### Implemented Code
```cpp
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100
struct Edge {
    int u, v, w;
};
int parent[MAX], rankArr[MAX];
int findSet(int i) {
    if (parent[i] != i)
        parent[i] = findSet(parent[i]);
    return parent[i];
}
void unionSet(int u, int v) {
    int uRoot = findSet(u);
    int vRoot = findSet(v);
    if (rankArr[uRoot] < rankArr[vRoot])
        parent[uRoot] = vRoot;
    else if (rankArr[uRoot] > rankArr[vRoot])
        parent[vRoot] = uRoot;
    else {
        parent[vRoot] = uRoot;
        rankArr[uRoot]++;
    }
}
int main() {
    int V, E;
    Edge edges[MAX];
    cout << "Enter vertices and edges: ";
    cin >> V >> E;
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges, edges + E, [](Edge a, Edge b) {
        return a.w < b.w;
    });
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }
    cout << "Edges in MST:\n";
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (findSet(u) != findSet(v)) {
            cout << u << " - " << v << " : " << edges[i].w << endl;
            unionSet(u, v);
        }
    }
    return 0;
}

```
### Output of the implemented code
```text
Enter vertices and edges: 5 7 
Enter edges (u v w):
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9
Edges in MST:
0 - 1 : 2
1 - 2 : 3
1 - 4 : 5
0 - 3 : 6
```

---
## LAB 7
## 1. Program: Single Source Shortest Path (SSSP)

### Problem Statement
Find shortest path from a source node to all other nodes.

## Topic
Graphs

### Naive Approach
Check all possible paths.

### Algorithm
1. Initialize all distances to infinity
2. Set source distance to 0
3. Pick node with minimum distance
4. Update adjacent nodes
5. Repeat

### Time Complexity
O(V²)

### Edge Cases
- Negative weights 
- Disconnected graph
- Cycles
### Implemented Code
```cpp
#include <iostream>
#include <climits>
using namespace std;
#define MAX 50
#define INTMAX 100000
void dijkstra(int cost[MAX][MAX], int n, int v) {
    int dist[MAX], visited[MAX];
    // we are intialising distance with the cost between the vertices 
    // also making all the nodes non visited initially
    for (int i = 0; i < n; i++) {
        dist[i] = cost[v][i];
        visited[i] = 0; // all nodes non visited initially 
    }
    // choosing aisa vertex such that its distance is less than minimum
    for (int j = 2; j < n - 1; j++) {
        int u;
        int min = INTMAX;
        // find such vertex that dis[that vertex] < min where min initially we assign intmax 
        // && that vertex is not visited yet
        for (int i = 0; i < n; i++) {
            if (dist[i] < min && visited[i] == 0) {
                u = i ;
            }
            visited[u] = 1;
        }  
        // ab jo vertex hmne include kri hai uske neighbours ka distances update krenge if distances changed
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0 && dist[i] > dist[u] + cost[u][i]) {
                dist[i] = dist[u] + cost[u][i];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << "vertex : " << i  << " dist : "<< dist[i] << endl;
    }

}
int main() {
    int n = 5;
    int cost[MAX][MAX] = {
        {0, 3, 1, INTMAX , INTMAX},
        {3, 0, INTMAX, 6, 7},
        {1,INTMAX, 0, 8, 2},
        {INTMAX, 6, 8, 0, 6},
        {INTMAX, 7, 2, 6, 0}
    };
    int source = 0;
    dijkstra(cost, n, source);
    return 0;
}

```
### Output of the implemented code
```text
vertex : 0 dist : 0
vertex : 1 dist : 3
vertex : 2 dist : 1
vertex : 3 dist : 9
vertex : 4 dist : 3
```
---

## 2. Program: Stages in Multistage Graph 

### Problem Statement
Given a directed graph, determine the number of stages in the graph starting from the source node. 

### Topic
Graph Traversal (BFS)

### Naive Approach
Manually trace all paths from source to destination and count levels

### Algorithm
1. Input number of vertices and edges
2. Initialize adjacency matrix with weights (INT_MAX for no edge)
3. Store indegree of each vertex
4. Find source node (node with indegree 0)
5. Mark source as visited and add to current stage
6. Repeat:
   - For each node in current stage:
     - Visit all unvisited adjacent nodes
     - Add them to next stage
   - Replace current stage with next stage
   - Increment stage count
7. Stop when no new nodes are found
8. Output total number of stages

### Time Complexity
O(V²)  
### Implemented Code
```cpp
#include <iostream>
#define INF 10000
using namespace std;
int main() {
    int v, e, v1, v2, w;
    int stages = 1;
    cout << "Enter number of vertices: ";
    cin >> v;
    int arr[50][50];
    int current[50], next[50];
    int visited[50] = {0};
    int indegree[50] = {0};
    cout << "Enter number of edges: ";
    cin >> e;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (i == j)
                arr[i][j] = 0;
            else
                arr[i][j] = INF;
        }
    }
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < e; i++) {
        cin >> v1 >> v2 >> w;
        // Use 0-based vertices only, like: 0 1 2
        arr[v1][v2] = w;
        indegree[v2]++;
    }
    int source = 0;
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) {
            source = i;
            break;
        }
    }
    int k = 1;
    current[0] = source;
    visited[source] = 1;
    while (true) {
        int p = 0;
        for (int i = 0; i < k; i++) {
            int node = current[i];
            for (int j = 0; j < v; j++) {
                if (arr[node][j] != 0 && arr[node][j] != INF && visited[j] == 0) {
                    next[p] = j;
                    p++;
                    visited[j] = 1;
                }
            }
        }
        if (p == 0)
            break;
        for (int i = 0; i < p; i++) {
            current[i] = next[i];
        }
        k = p;
        stages++;
    }
    cout << "Number of stages: " << stages;
    return 0;
}

```
### Output of the implemented code
```text
Enter number of edges: 7
Enter edges (u v w):
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9
Number of stages: 3
```

---
## LAB 8
## 1. Program: Matrix Chain Multiplication

### Problem Statement
Find minimum number of scalar multiplications required to multiply matrices.

### Topic
Dynamic Programming

### Naive Approach
Try all possible ways.

### Algorithm
1. Create DP table m[i][j]
2. Compute cost for chain lengths from 2 to n
3. Use recurrence relation to minimize cost

### Time Complexity
O(n³)

### Edge Cases
- Only one matrix
- Large dimensions
### Implemented Code
```cpp
#include<iostream>
#include<climits>
using namespace std;
#define MAX 100
int matrixChainMulti(int p[], int n) {
    int m[MAX][MAX]; 
    int s[MAX][MAX]; 
    for(int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }
    for(int l = 2; l <= n; l++) {
        for(int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for(int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k; 
                }
            }
        }
    }
    return m[1][n];
}
int main() {
    int p[] = {10, 20, 30, 40, 30}; 
    int n = 4; 
    cout << "minimum number of multiplications: "<< matrixChainMulti(p, n);
    return 0;
}

```
### Output of the implemented code
```text
minimum number of multiplications: 30000
```

---

## 2. Program: Multistage Graph (Backward Approach)

### Problem Statement
Find shortest path using backward approach.

### Topic
Dynamic Programming

### Approach
Start from destination and move backward computing minimum cost.

### Algorithm
1. Initialize cost of destination as 0
2. Move backward stage by stage
3. Compute minimum cost for each node

### Time Complexity
O(E)

### Edge Cases
- No valid path
- Graph with isolated nodes
### Implemented Code
```cpp
#include <iostream>
#define INT_MAX 10000
using namespace std;
int main() {
    int vertices, edges;
    cout << "enter number of vertices: ";
    cin >> vertices;
    cout << "enter number of edges: ";
    cin >> edges;
    int cost[vertices][vertices];
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = INT_MAX;
        }
    }
    cout << "enter edges -- source destination weight:\n";
    int source, destination, weight;
    for (int i = 0; i < edges; i++) {
        cin >> source >> destination >> weight;
        cost[source - 1][destination - 1] = weight;
    }

    int minCost[vertices];
    int path[vertices];

    minCost[vertices - 1] = 0;

    for (int i = vertices - 2; i >= 0; i--) {
        minCost[i] = INT_MAX;
        path[i] = -1;   
        for (int j = 0; j < vertices; j++) {
            if (cost[i][j] != INT_MAX && i != j) {
                if (minCost[i] > cost[i][j] + minCost[j]) {
                    minCost[i] = cost[i][j] + minCost[j];
                    path[i] = j;
                }
            }
        }
    }
    cout << "minimum cost: " << minCost[0] << endl;

    cout << "path: ";
    int current = 0;

    while (current != -1 && current != vertices - 1) {
        cout << current + 1 << " -> ";
        current = path[current];
    }
    cout << vertices;
    return 0;
}

```
### Output of the implemented code
```text
enter number of vertices: 5
enter number of edges: 6
enter edges -- source destination weight:
1 2 2
1 3 5
2 4 4
2 5 6
3 5 2
4 5 1
minimum cost: 6
path: 1 -> 2 -> 4 -> 5
```
---

## 3. Program: Multistage Graph (Forward Approach)

### Problem Statement
Find shortest path using forward approach.

### Topic
Dynamic Programming

### Approach
Start from source and move forward updating costs.

### Algorithm
1. Initialize source cost as 0
2. Traverse stage by stage
3. Update minimum cost for each node

### Time Complexity
O(E)

### Edge Cases
- No path exists
- Multiple optimal paths
### Implemented Code
```cpp
#include <iostream>
#define INT_MAX 10000
using namespace std;
int main() {
    int vertices, edges;
    cout << "enter number of vertices: ";
    cin >> vertices;
    cout << "enter number of edges: ";
    cin >> edges;
    int cost[vertices][vertices];
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = INT_MAX;
        }
    }
    cout << "enter edges -- source destination weight :\n";
    int source, destination, weight;
    for (int i = 0; i < edges; i++) {
        cin >> source >> destination >> weight;
        cost[source - 1][destination - 1] = weight;
    }
    int minCost[vertices];
    int path[vertices];
    minCost[vertices - 1] = 0;
    for (int i = vertices - 2; i >= 0; i--) {
        minCost[i] = INT_MAX;
        for (int j = 0; j < vertices; j++) {
            if (cost[i][j] != INT_MAX) {
                if (minCost[i] > cost[i][j] + minCost[j]) {
                    minCost[i] = cost[i][j] + minCost[j];
                    path[i] = j;
                }
            }
        }
    }
    cout << "minimum cost: " << minCost[0] << endl;
    cout << "path: ";
    int current = 0;
    while (current != vertices - 1) {
        cout << current + 1 << " -> ";
        current = path[current];
    }
    cout << vertices;
    return 0;
}

```
### Output of the implemented code
```text
enter number of vertices: 5
enter number of edges: 6
enter edges -- source destination weight:
1 2 2
1 3 5
2 4 4
2 5 6
3 5 2
4 5 1
minimum cost: 6
path: 1 -> 2 -> 4 -> 5
```
## LAB 9 :
## 1. Program: travelling salesperson problem

### Problem Statement
Find the minimum cost path that visits every city exactly once and returns to the starting city.

### Topic
Backtracking

### Naive Approach
Generate all possible tours and compute the cost of each tour.

### Algorithm
1. Start from first city
2. Mark city as visited
3. Visit every unvisited adjacent city recursively
4. Add travel cost
5. After visiting all cities, return to starting city
6. Store minimum cost among all paths

### Time Complexity
O(n!)

### Implemented Code
```cpp
#include <iostream>
#include <climits>
using namespace std;

int n;
int cost[20][20];
int visited[20];
int ans = INT_MAX;

void tsp(int city, int count, int sum) {
    if (count == n) {
        if (cost[city][0] != 0)
            ans = min(ans, sum + cost[city][0]);
        return;
    }

    for (int next = 0; next < n; next++) {
        if (visited[next] == 0 && cost[city][next] != 0) {
            visited[next] = 1;
            tsp(next, count + 1, sum + cost[city][next]);
            visited[next] = 0;
        }
    }
}

int main() {
    cout << "enter number of cities: ";
    cin >> n;

    cout << "enter cost matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;
    tsp(0, 1, 0);

    cout << "minimum cost: " << ans;
    return 0;
}
```

### Output of the implemented code
```text
enter number of cities: 4
enter cost matrix:
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
minimum cost: 80
```

---

## 2. Program: 0/1 knapsack

### Problem Statement
Find maximum profit by selecting items without exceeding knapsack capacity.

### Topic
Dynamic Programming

### Naive Approach
Try all subsets and choose subset with maximum profit.

### Algorithm
1. Create dp table
2. Initialize first row and first column as 0
3. If current weight <= capacity, choose maximum of include/exclude
4. Otherwise exclude item
5. Final cell gives maximum profit

### Time Complexity
O(n × w)

### Implemented Code
```cpp
#include <iostream>
using namespace std;

int main() {
    int n, capacity;

    cout << "enter number of items: ";
    cin >> n;

    int weight[n + 1], profit[n + 1];

    cout << "enter weights:\n";
    for (int i = 1; i <= n; i++)
        cin >> weight[i];

    cout << "enter profits:\n";
    for (int i = 1; i <= n; i++)
        cin >> profit[i];

    cout << "enter capacity: ";
    cin >> capacity;

    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i] <= w)
                dp[i][w] = max(profit[i] + dp[i - 1][w - weight[i]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << "maximum profit: " << dp[n][capacity];
    return 0;
}
```

### Output of the implemented code
```text
enter number of items: 3
enter weights:
10 20 30
enter profits:
60 100 120
enter capacity: 50
maximum profit: 220
```
---
## LAB 10 :
## 1. Program: n queens problem

### Problem Statement
Place n queens on chessboard so that no two queens attack each other.

### Topic
Backtracking

### Naive Approach
Try placing queen in every cell and check validity.

### Algorithm
1. Place queen row by row
2. Check column safety
3. Check left diagonal
4. Check right diagonal
5. If safe, place queen
6. Backtrack if no solution

### Time Complexity
O(n!)

### Implemented Code
```cpp
#include <iostream>
using namespace std;

int board[20][20];
int n;

bool issafe(int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

bool nqueen(int row) {
    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {
        if (issafe(row, col)) {
            board[row][col] = 1;
            if (nqueen(row + 1))
                return true;
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    cout << "enter number of queens: ";
    cin >> n;

    if (nqueen(0)) {
        cout << "solution:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    } else
        cout << "no solution exists";

    return 0;
}
```

### Output of the implemented code
```text
enter number of queens: 4
solution:
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0
```

---

## 2. Program: graph coloring

### Problem Statement
Assign colors to graph vertices so that adjacent vertices have different colors.

### Topic
Backtracking

### Naive Approach
Try all color combinations.

### Algorithm
1. Start with first vertex
2. Assign valid color
3. Check adjacent vertices
4. Recursively color next vertex
5. Backtrack if conflict occurs

### Time Complexity
O(m^n)

### Edge Cases
- Complete graph
- Insufficient colors

### Implemented Code
```cpp
#include <iostream>
using namespace std;

int graph[20][20];
int color[20];
int n, m;

bool issafe(int vertex, int c) {
    for (int i = 0; i < n; i++)
        if (graph[vertex][i] == 1 && color[i] == c)
            return false;
    return true;
}

bool graphcoloring(int vertex) {
    if (vertex == n)
        return true;

    for (int c = 1; c <= m; c++) {
        if (issafe(vertex, c)) {
            color[vertex] = c;
            if (graphcoloring(vertex + 1))
                return true;
            color[vertex] = 0;
        }
    }
    return false;
}

int main() {
    cout << "enter number of vertices: ";
    cin >> n;

    cout << "enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    cout << "enter number of colors: ";
    cin >> m;

    if (graphcoloring(0)) {
        for (int i = 0; i < n; i++)
            cout << "vertex " << i + 1 << " -> color " << color[i] << endl;
    } else
        cout << "no solution exists";

    return 0;
}
```

### Output of the implemented code
```text
enter number of vertices: 4
enter adjacency matrix:
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
enter number of colors: 3
vertex 1 -> color 1
vertex 2 -> color 2
vertex 3 -> color 3
vertex 4 -> color 2
```

---

## 3. Program: subset sum

### Problem Statement
Find subsets whose sum is equal to target sum.

### Topic
Backtracking

### Naive Approach
Generate all subsets and check sum.

### Algorithm
1. Include current element
2. Exclude current element
3. Recursively continue
4. If sum equals target, print subset
5. Stop when index reaches end

### Time Complexity
O(2^n)

### Implemented Code
```cpp
#include <iostream>
using namespace std;

int arr[20];
int x[20];
int n, target;

void subsetsum(int index, int sum) {
    if (sum == target) {
        cout << "subset: ";
        for (int i = 0; i < index; i++)
            if (x[i] == 1)
                cout << arr[i] << " ";
        cout << endl;
        return;
    }

    if (index == n || sum > target)
        return;

    x[index] = 1;
    subsetsum(index + 1, sum + arr[index]);

    x[index] = 0;
    subsetsum(index + 1, sum);
}

int main() {
    cout << "enter number of elements: ";
    cin >> n;

    cout << "enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "enter target sum: ";
    cin >> target;

    subsetsum(0, 0);

    return 0;
}
```

### Output of the implemented code
```text
enter number of elements: 6
enter elements:
5 10 12 13 15 18
enter target sum: 30
subset: 5 10 15
subset: 12 18
```

---
