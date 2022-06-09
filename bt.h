#pragma once
#include<iostream>
#include<math.h>
#include<vector>
#include<cstring>

using namespace std;

long long int sum_n_number(long long int n)
{
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

// phuong dep traj