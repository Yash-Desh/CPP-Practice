// Author : Yash Deshpande
// Date : 07-09-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     // // Q1
//     // int first = 8;
//     // int second = 18;
//     // int *ptr = &second;
//     // *ptr = 9;
//     // cout<<first<<" "<<second<<endl;

//     // // Q2
//     // int first = 6;
//     // int *p = &first;
//     // int *q = p;
//     // (*q)++;
//     // cout<<first<<endl;

//     // // Q3
//     // int first = 8;
//     // int *p = &first;
//     // cout<<(*p)++<<" ";
//     // cout<<first<<endl;

//     // // Q4
//     // int *p = 0;
//     // int first = 110;
//     // *p = first;
//     // cout<<*p <<endl;        // segmentation fault

//     // // Q4-modified
//     // int *p = 0;
//     // int first = 110;
//     // p = &first;
//     // cout<<*p <<endl;

//     // // Q5
//     // int first = 8;
//     // int second = 11;
//     // int *third = &second;
//     // first = *third;
//     // *third = *third +2;
//     // cout<<first<<" "<<second<<endl;

//     // // Q6
//     // float f = 12.5;
//     // float p = 21.5;
//     // float *ptr  = &f;
//     // (*ptr)++;
//     // *ptr = p;
//     // cout<<*ptr<<" "<<f<<" "<<p<<endl;

//     // // Q7
//     // int arr[5];
//     // int *ptr;
//     // cout<<sizeof(arr)<<" "<<sizeof(ptr)<<endl;

//     // // Q8
//     // int arr[] = {11,21,13,14};
//     // cout<<*(arr)<<" "<<*(arr+1)<<endl;

//     // // Q9
//     // int arr[6] = {11, 12, 31};
//     // cout << arr << " " << &arr << endl;

//     // // NOTE : arr <==> &arr <==> &arr[0]

//     // // Q10
//     // int arr[6] = {11, 21, 13};
//     // cout << (arr + 1) << endl;

//     // // Q11
//     // int arr[6] = {11, 21, 31};
//     // int *p = arr;
//     // cout << p[2] << endl;

//     // // Q12
//     // int arr[] = {11, 12, 13, 14, 15};
//     // cout << *(arr) << " " << *(arr + 3);

//     // // Q13
//     // int arr[] = {11, 21, 31, 41};
//     // int *ptr = arr++;
//     // cout << *ptr << endl;        // ERROR

//     // // Q14
//     // char ch = 'a';
//     // char* ptr = &ch;
//     // ch++;
//     // cout << *ptr << endl;

//     // // Q15
//     // char arr[] = "abcde";
//     // char *p = &arr[0];
//     // cout << p << endl;

//     // // Q16
//     // char arr[] = "abcde";
//     // char *p = &arr[0];
//     // p++;
//     // cout << p << endl;

//     // // Q17
//     // char str[]= "babbar";
//     // char *p = str;
//     // cout << str[0] << " " << p[0] << endl;

//     return 0;
// }

// // Q18
// void update(int *p)
// {
//     *p = (*p) * 2;
// }

// int main()
// {
//     int i = 10;
//     update(&i);
//     cout << i << endl;
//     return 0;
// }

// // Q19
// void fun(int arr[])
// {
//     cout << arr[0] << " ";
// }

// int main()
// {
//     int arr[] = {11, 12, 13, 14};
//     fun(arr + 1);
//     cout << arr[0] << endl;
//     return 0;
// }

// // Q20
// void update(int *p)
// {
//     int a = 70;
//     p = &a;
//     *p = (*p) * (*p);
// }

// int main()
// {
//     int a = 70;
//     update(&a);
//     cout << a << endl;
// }

// // Q21
// int main()
// {
//     int first = 10;
//     int *p = &first;
//     int **q = &p;
//     int second = 20;
//     *q = &second;
//     (*p)++;
//     cout << first << " " << second << endl;
//     return 0;
// }

// // Q22
// int main()
// {
//     int first = 110;
//     int *p = &first;
//     int **q = &p;
//     int second = (**q)++ + 9;
//     cout << first << " " << second << endl;
//     return 0;
// }

// // Q23
// int main()
// {
//     int first = 100;
//     int *p = &first;
//     int **q = &p;
//     int second = ++(**q);
//     int *r = *q;
//     ++(*r);
//     cout << first << " " << second << endl;
//     return 0;
// }

// // Q24
// void increment(int **p)
// {
//     ++(**p);
// }

// int main()
// {
//     int num = 110;
//     int *ptr = &num;
//     increment(&ptr);
//     cout << num << endl;
// }

// // Q25
// int main()
// {
//     int arr[] = {41, 52, 36, 74};
//     int *p = (arr + 1);
//     cout << *arr + 8;
//     return 0;
// }

// // Q26
// int main()
// {
//     char *p;
//     char str[] = "pqrstuv";
//     p = str;
//     p += 3;
//     cout << p;
//     return 0;
// }

// // Q27
// int main()
// {
//     char arr[20];
//     int i;
//     for (i = 0; i < 10; i++)
//     {
//         *(arr + i) = 65 + i;
//     }
//     *(arr + i) = '\0';
//     cout << arr;
//     return 0;
// }

// // Q28
// int main()
// {
//     float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
//     float *ptr1 = &arr[0];
//     float *ptr2 = ptr1 + 3;
//     cout << *ptr2 << " ";
//     cout << ptr2 - ptr1;
//     return 0;
// }

// // Q29
// int main()
// {
//     char st[] = "ABCD";
//     for (int i = 0; st[i] != '\0'; i++)
//     {
//         cout << st[i] << *(st) + i << *(i + st) << i[st];
//     }
//     return 0;
// }

// // Q30
// void Q(int z)
// {
//     z += z;
//     cout << z << " ";
// }

// void P(int *y)
// {
//     int x = *y + 2;
//     Q(x);
//     *y = x - 1;
//     cout << x << " ";
// }

// int main()
// {
//     int x = 5;
//     P(&x);
//     cout << x;
//     return 0;
// }

// // Q31
// int main()
// {
//     int ***r, **q, *p, i = 8;
//     p = &i;
//     (*p)++;
//     q = &p;
//     (**q)++;
//     r = &q;
//     cout << *p << " " << **q << " " << ***r;
//     return 0;
// }

// // Q32
// int f(int x, int *py, int **ppz)
// {
//     int y, z;
//     **ppz += 1;
//     z = **ppz;
//     *py += 2;
//     y = *py;
//     x += 3;
//     return x + y + z;
// }

// int main()
// {
//     int c, *b, **a;
//     c = 4;
//     b = &c;
//     a = &b;
//     cout << f(c, b, a);
//     return 0;
// }