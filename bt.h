#pragma once
#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<cstring>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#define EPSILON 0.00001f
#define MAX_SIZE 50

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

// float tong_can_2_long_nhau(int n)
// {
//     static int i = 1;
//     if (i == n) return sqrt(2);
//     else 
//         {
//             i++;
//             return sqrt(2 + tong_can_2_long_nhau(n));
//         }
// }

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


// Hãy kiểm tra các chữ số của số nguyên dương n có tăng dần từ trái
// sang phải hay không?

void check_number (int n)
{
    string result = to_string(n);
    int i = 0;
    int length = result.length();
    bool flag = true;

    while (true)
    {
        if (result[i] > result[i + 1])
        {
            if (i + 1 == length)
            {
                break;
            }
            
            flag = false;
            break;
        }
        else i++;
    }
    
    
    if (flag) cout << "so n co cac chu so tang tu trai sang phai!\n";
    else cout << "so n co cac chu so khong tang tu trai sang phai!\n";
}


// Kiểm tra số nguyên 4 byte có dạng 2^𝑘 hay không?

void is_n_2k (int n)
{
    int temp = 1;
    while (temp < n)
    {
        temp *= 2;
    }
    
    if (temp == n)
    {
        cout << "n la so nguyen 4 byte co dang 2^K!\n";
    }
    else
    {
        cout << "n la so nguyen 4 byte ko co dang 2^K!\n";
    }
}

float s_n_cau_80 (int n, int x)
{
    float result = 0.0f;
    for (int i = 1; i <= n; i++)
    {
        result += power_x_n(x, i) * 1.0 / sum_n_number(i);
    }
    
    return result;
}


void selection_Sort (int arr[])
{
    int i, j, min;
    for (i = 0; i < 5; i++)
    {
        min = i;
        for (j = i + 1; j < 5; j++)
            if (arr[j] < arr[min]) min = j;
        swap(arr[i], arr[min]);
    }
    
}


float my_sqrt(int n)
{  
    
    float result = 1.0f;
    while (fabs(result * result - n) > EPSILON)
    {
        result = (n * 1.0 / result  - result) / 2 + result;
    }
    
    return result;
}


void sum_money()
{
    int count = 0;
    for (int m = 0; m <= 200; m++)
    {
        for (int n = 0; n <= 100; n++)
        {
            for (int p = 0; p <= 40; p++)
            {
                if (m * 1000 + n * 2000 + p * 5000 == 200000)
                {
                    cout << m << " " << n << " " << p << endl;
                    count++;
                }
                
            }
            
        }
        
    }
    
    cout << "số lượng cách thức là: " << count << endl;
}


void translate_string (string &s1, string s2)
{
    int ith = s2.length() % 10;
    int length_s1 = s1.length();
    for (int i = 0; i < length_s1; i++)
    {
        int position = ith;
        // while (true)
        // {
            if (s1[i] >= 'A' && s1[i] <= 'Z')
            {
                if (int(s1[i]) + position > 90)
                {
                    position = position - (90 - int(s1[i])) - 1; 
                    s1[i] = 'A';
                    while (int(s1[i]) + position > 90)
                    {
                        position = position - (90 - int(s1[i])) - 1; 
                    }
                    
                    s1[i] = char(int(s1[i]) + position);
                }
                else
                {
                    s1[i] = char(int(s1[i]) + position);
                }
            }
            else if (s1[i] >= 'a' && s1[i] <= 'z')
            {
                if (int(s1[i]) + position > 122)
                {
                    position = position - (122 - int(s1[i])) - 1;
                    s1[i] = 'a';
                    while (int(s1[i]) + position > 122)
                    {
                        position = position - (122 - int(s1[i])) - 1; 
                    }
                    
                    s1[i] = char(int(s1[i]) + position);
                }
                else
                {
                    s1[i] = char(int(s1[i]) + position);
                }
            }   
        // }
        
    }
    
}

int atoi(string s)
{
    int result = 0;
    if (s.length() == 1)
    {
        return result += int(s[0]) - 48;
    }
    else 
    {
        result += int(s[0]) - 48;
        int s_length = s.length();
        for (int i = 1; i < s_length; i++)
        {
            result = result * 10 + (int(s[i]) - 48); 
        }
    }   
    
    return result;
}


void year_week_day(int days)
{
    int year = days / 365;
    int week = (days - year * 365) / 7;
    int day = days - year * 365 - week * 7;
    // 1532 ngày = 4 năm + 10 tuần + 2 ngày 
    cout << days << " " << "ngay = " << year << " nam + "<< week << " tuan + " << day << " ngay";
}

void tim_giao_diem(float a1, float b1, float a2, float b2)
{
    float result_x = (b2 - b1) / (a1 - a2);
    float result_y = a1 * result_x + b1;

    cout << "Giao cua hai duong thang la (x,y) = (" << result_x << "," << result_y << ")"; 
}

void thien_can_dia_chi(int nam)
{
    int thien_can = nam % 10;
    int dia_chi = nam % 12;
    string result = "";
    switch (thien_can)
    {
    case 1:
        result += "Tân";
        break;

    case 2:
        result += "Nhâm";
        break;
    case 3:
        result += "Quý";
        break;
    case 4:
        result += "Giáp";
        break;
    case 5:
        result += "Ất";
        break;
    case 6:
        result += "Bính";
        break;
    case 7:
        result += "Đinh";
        break;
    case 8:
        result += "Mậu";
        break;
    case 9:
        result += "Kỷ";
        break;
    case 0:
        result += "Canh";
        break;

    }
    
    result += " ";
    switch (dia_chi)
    {
    case 1:
        result += "Dậu";
        break;

    case 2:
        result += "Tuất";
        break;
    case 3:
        result += "Hợi";
        break;
    case 4:
        result += "Tý";
        break;
    case 5:
        result += "Sửu";
        break;
    case 6:
        result += "Dần";
        break;
    case 7:
        result += "Mão";
        break;
    case 8:
        result += "Thìn";
        break;
    case 9:
        result += "Tỵ";
        break;
    case 10:
        result += "Ngọ";
        break;
    case 11:
        result += "Mùi";
        break;
    case 12:
        result += "Thân";
        break;

    }

cout << result ;
}

bool nam_nhuan(int year)
{
    bool is_nam_nhuan;
    if(year % 4 == 0)
    {
        if( year % 100 == 0)
        {
            if ( year % 400 == 0)
                is_nam_nhuan = true;
            else
                is_nam_nhuan = false;
        }
        else
            is_nam_nhuan = true;
    }
    else
        is_nam_nhuan = false;
    return is_nam_nhuan;
}

void tim_thu(int day, int month, int year, bool nam_nhuan)
{
    int tra_nam = 0;
    int tra_thang = 0;
    int tra_thu = 0;
    if (year >= 1700 && year <= 1799)
    {
        tra_nam = 4;
    }
    else if (year >= 1800 && year <= 1899)
    {
        tra_nam = 2;
    }
    else if (year >= 1900 && year <= 1999)
    {
        tra_nam = 0;
    }
    else if (year >= 2000 && year <= 2099)
    {
        tra_nam = 6;
    }
    if (year >= 2100 && year <= 2199)
    {
        tra_nam = 4;
    }
    else if (year >= 2200 && year <= 2299)
    {
        tra_nam = 2;
    }
    else if (year >= 2300 && year <= 2399)
    {
        tra_nam = 0;
    }
    else if (year >= 2400 && year <= 2499)
    {
        tra_nam = 6;
    }
    if (year >= 2500 && year <= 2599)
    {
        tra_nam = 4;
    }
    else if (year >= 2600 && year <= 2699)
    {
        tra_nam = 2;
    }
    


    if (month == 1 && nam_nhuan)
    {
        tra_thang = 6;
    }
    else if (month == 1 && !nam_nhuan)
    {
        tra_thang = 0;
    }
    else if (month == 2 && nam_nhuan)
    {
        tra_thang = 2;
    }
    else if (month == 2 && !nam_nhuan)
    {
        tra_thang = 3;
    }
    else if (month == 3)
    {
        tra_thang = 3;
    }
    else if (month == 4)
    {
        tra_thang = 6;
    }
    else if (month == 5)
    {
        tra_thang = 1;
    }
    else if (month == 6)
    {
        tra_thang = 4;
    }
    else if (month == 7)
    {
        tra_thang = 6;
    }
    else if (month == 8)
    {
        tra_thang = 2;
    }
    else if (month == 9)
    {
        tra_thang = 5;
    }
    else if (month == 10)
    {
        tra_thang = 0;
    }
    else if (month == 11)
    {
        tra_thang = 3;
    }
    else if (month == 12)
    {
        tra_thang = 5;
    }



    string year_temp = to_string(year);
    string hai_so_cuoi = "";
    hai_so_cuoi += year_temp[2];
    hai_so_cuoi += year_temp[3];
    int buoc_2 = stoi(hai_so_cuoi,0,10);

    int step_3 = buoc_2 / 4;

    tra_thu = (tra_nam + buoc_2 + step_3 + tra_thang + day) % 7;

    if (tra_thu == 0)
    {
        cout << "Chu nhat ";
    }
    else if (tra_thu == 1)
    {
        cout << "Thu Hai";
    }
    else if (tra_thu == 2)
    {
        cout << "Thu Ba";
    }
    else if (tra_thu == 3)
    {
        cout << "Thu Tu";
    }
    else if (tra_thu == 4)
    {
        cout << "Thu Nam";
    }
    else if (tra_thu == 5)
    {
        cout << "Thu Sau";
    }
    else if (tra_thu == 6)
    {
        cout << "Thu Bay";
    }

}

float tien_dntt (int dntt)
{
    float tien = 0.0f;
    float result = 0.0f;
    if (dntt <= 50)
    {
        tien = dntt * 1.0f * 1484;  
    }
    else if (dntt <= 100)
    {
        tien = 50 * 1.0f * 1484 + (dntt - 50) * 1.0f * 1533;
    }
    else if (dntt <= 200)
    {
        tien = 50 * 1.0f * 1484 + 50 * 1.0f * 1533 + (dntt - 100) * 1.0f * 1786;
    }
    else if (dntt <= 300)
    {
        tien = 50 * 1.0f * 1484 + 50 * 1.0f * 1533 + 100 * 1.0f * 1786 + (dntt - 200) * 1.0f * 2242;
    }
    else if (dntt <= 400)
    {
        tien = 50 * 1.0f * 1484 + 50 * 1.0f * 1533 + 100 * 1.0f * 1786 + 100 * 1.0f * 2242 + (dntt - 300) * 1.0f * 2503;
    }
    else if (dntt >= 401)
    {
        tien = 50 * 1.0f * 1484 + 50 * 1.0f * 1533 + 100 * 1.0f * 1786 + 100 * 1.0f * 2242 + 100 * 1.0f * 2503 + (dntt - 400) * 1.0f * 2587;
    }
    
    
    return result = tien + tien * 10 / 100;
    
}

float tong_can_2_long_nhau(int n)
{
    static int i = 1;
    if (i == n) 
    {
        i = 1;
        return sqrt(2);
    }
    else 
        {
            i++;
            return sqrt(2 + tong_can_2_long_nhau(n));
        }
}


float cau1_pi_cach1 (int n)
{
    if (n == 0) return 2;
    else
    {
        return (2 * 1.0f / tong_can_2_long_nhau(n)) * cau1_pi_cach1(n - 1);
    }
}

float cau1_pi_cach2 (int n)
{
    float result = 1.0f;
    for (int i = 1; i < n + 1; i++)
    {
        int first_number = 1;
        int second_number = 3;
        float multiply = 1.0f;
        for (int j = 0; j < i; j++)
        {
            multiply *= first_number * 1.0f / second_number;
            first_number += 1;
            second_number += 2;
        }
        
        result += multiply;
    }
    
    return result;
}

float cau1_pi_cach3 (int n)
{
    if (n == 0) return (1 * 1.0f);
    else return (2 * n * 1.0f / ((2 *  n) - 1)) * (2 * n * 1.0f / ((2 * n) + 1)) * cau1_pi_cach3(n - 1);
}

void cau2 ()
{
    float arr[MAX_SIZE];
    int number = 0;
    float sum = 0.0f;
    float s = 0.0f;
    float average = 0.0f;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        float n;
        cin >> n;
        if (n < 0)    break;
        else    
        {
            arr[i] = n;
            sum += n;
            number++;
        }
    }

    average = sum / number;
    cout << "Trung binh cong la: " << average << endl;

    sum = 0.0f;
    for (int i = 0; i < number; i++)
    {
        sum += (arr[i] - average) * (arr[i] - average);
    }

    s = sqrt((1.0f / (number - 1)) * sum);

    cout << "Do lech chuan la: "<< s << endl;
    cout << "Mang truoc luc dao: ";
    for (int i = 0; i < number; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int left = 0;
    int right = number - 1;

    for (int i = 0; i < number; i++)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;

        if (left > right)
        {
            break;
        }
        
    }
    
    cout << "Mang sau luc dao: ";
    for (int i = 0; i < number; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    
}


void cau3 ()
{

}


void cau4 ()
{
    int n;
    int arr[MAX_SIZE];
    int max;
    cout << "Nhap so phan tu cua mang so nguyen: n > 2: ";
    cin >> n;
    cout << endl;
    cout << "Nhap mang so nguyen: "<< endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    max = arr[0] + arr[1];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] > max)
            {
                max = arr[i] + arr[j];
            }
            
        }
        
    }
    
    cout << "sum_max la: " << max; 
}

