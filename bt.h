#pragma once
#include<iostream>
#include<math.h>
#include<vector>
#include<cstring>

using namespace std;

long long int sum_n_number(long long int n)
{
    // tong cac so tu 1 den n
    long long int result = 0;
    for (long long int i = 1; i <= n; i++)
    {
        result += i;
    }
    
    return result;
}

long long int sum_square_n_number(long long int n)
{
    long long int result = 0;
    for (long long int i = 1; i <= n; i++)
    {
        result += i*i;
    }
    
    return result;
}

float tong_phan_so_1_chia_n(int n)
{
    float result = 0.0f;
    for (int i = 1; i <= n; i++)
    {
        result += 1.0f / i;
    }
    
    return result;
}

float tong_phan_so_1_chia_2n(int n)
{
    float result = 0.0f;
    result = (1.0f / 2) * tong_phan_so_1_chia_n(n);
    return result;
}

long long int power_x_n(int x, int n)
{
    long long int result = 1;
    for (long long int i = 1; i <= n; i++)
    {
        result *= x;
    }
    
    return result;
}


long long int factorial_n(int n)
{
    if (n == 1 || n == 0) return 1;
    else return n * factorial_n(n - 1);
}

double sum_sn(int x, int n)
{
    double result = 1.0;
    for (int i = 0; i <= n; i++)
    {
        result += power_x_n(x, (2 * i + 1)) * 1.0 / factorial_n(2 * i + 1);
    }
    

    return result;
}


void uoc_so_cua_n(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
        
    }
    
    cout << endl;

}

float tong_can_2_long_nhau(int n)
{
    static int i = 1;
    if (i == n) return sqrt(2);
    else 
        {
            i++;
            return sqrt(2 + tong_can_2_long_nhau(n));
        }
}

float tong_can_long_nhau_34(int n)
{
    static int i = 1;
    static int j = n;
    if (i == j) 
    {
        return 1;
    }
    else 
        {
            i++;
            return sqrt(n + tong_can_long_nhau_34(n - 1));
        }
}


float tong_can_long_nhau_35(int n)
{
    static int i = 1;
    static int j = n;
    if (i == j) 
    {
        return sqrt(j);
    }
    else 
        {
            return sqrt(i + tong_can_long_nhau_35(i++));
        }
}

float tong_can_long_nhau_40(int x, int n)
{
    static int i = 1;
    static int j = n;
    if (i == j) return sqrt(x);
    else
    {
        i++;
        return sqrt(power_x_n(x, n) + tong_can_long_nhau_40(x, n - 1));
    }
}


double tong_cau_41(int n)
{
    // tinh tong cua 1/
    /*                1 + 1/
                           1 + 1/.....
    co n dau phan so */


    static int start = 1;
    static int end = n;

    if (start == end) return 1.0 / 2;
    else 
    {
        start ++;
        return 1.0 / (1 + tong_cau_41(n));
    }
}

void find_k_max(int n)
{
    int result = 0;
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += i;
        if (sum < n)
        {
            result++;
        }
        else
        {
            break;
        }
        
    }   
    cout << "cau 42 k max la: " << result << endl;
}


void number_of_digits(long long int n)
{
    string result = "";
    result = std::to_string(n);
    cout << "do dai cua so n la: " << result.length() << endl;
}

int sum_of_digits(int n)
{
    // tong cac chu so cua so n
    int result = 0;
    int length_number_str = 0;
    string number_string = "";
    number_string = std::to_string(n);
    length_number_str = number_string.length();

    for (int i = 0; i < length_number_str; i++)
    {
        result += (int(number_string[i]) - 48);
    }
     
    return result;
}


long long int reverse(long long int n)
{
    // dao nguoc so n (reverse of the n) 
    long long int result = 0;
    int remainder = 0;
    long long int x = n;

    while (x != 0)
    {
        remainder = x % 10;
        result = result * 10 + remainder;
        x /= 10;
    }
    

    return result;
}


