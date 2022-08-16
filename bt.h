#pragma once
#include<iostream>
#include<iomanip>
#include<bits/stdc++.h>
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

void cau1 ()
{
    int n;
    cout << "nhap n: ";
    cin >> n;

    cout << "pi tinh theo cach 1: " << cau1_pi_cach1(n) << endl;
    cout << "pi tinh theo cach 2: " << cau1_pi_cach2(n) * 2 << endl;
    cout << "pi tinh theo cach 3: " << cau1_pi_cach3(n) * 2 << endl;
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

// C++ program two find number of
// days between two given dates
// #include <iostream>
// using namespace std;

// A date has day 'd', month 'm' and year 'y'
struct Date {
	int d, m, y;
};

// To store number of days in
// all months from January to Dec.
const int monthDays[12]
	= { 31, 28, 31, 30, 31, 30,
	31, 31, 30, 31, 30, 31 };

// This function counts number of
// leap years before the given date
int countLeapYears(Date d)
{
	int years = d.y;

	// Check if the current year needs to be
	// considered for the count of leap years
	// or not
	if (d.m <= 2)
		years--;

	// An year is a leap year if it
	// is a multiple of 4,
	// multiple of 400 and not a
	// multiple of 100.
	return years / 4
		- years / 100
		+ years / 400;
}

// This function returns number of
// days between two given dates
int getDifference(Date dt1, Date dt2)
{
	// COUNT TOTAL NUMBER OF DAYS
	// BEFORE FIRST DATE 'dt1'

	// initialize count using years and day
	long int n1 = dt1.y * 365 + dt1.d;

	// Add days for months in given date
	for (int i = 0; i < dt1.m - 1; i++)
		n1 += monthDays[i];

	// Since every leap year is of 366 days,
	// Add a day for every leap year
	n1 += countLeapYears(dt1);

	// SIMILARLY, COUNT TOTAL NUMBER OF
	// DAYS BEFORE 'dt2'

	long int n2 = dt2.y * 365 + dt2.d;
	for (int i = 0; i < dt2.m - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(dt2);

	// return difference between two counts
	return (n2 - n1);
}

// Driver code
// int main()
// {
// 	Date dt1 = { 1, 2, 2000 };
// 	Date dt2 = { 1, 2, 2004 };

// 	// Function call
// 	cout << "Difference between two dates is "
// 		<< getDifference(dt1, dt2);

// 	return 0;
// }

// A C++ Program to Implement a Calendar
// of an year

// using namespace std;

/*A Function that returns the index of the day
of the date- day/month/year
For e.g-

Index	 Day
0		 Sunday
1		 Monday
2		 Tuesday
3		 Wednesday
4		 Thursday
5		 Friday
6		 Saturday*/
int dayNumber(int day, int month, int year)
{

	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,
					4, 6, 2, 4 };
	year -= month < 3;
	return ( year + year/4 - year/100 +
			year/400 + t[month-1] + day) % 7;
}

/*
A Function that returns the name of the month
with a given month number

Month Number	 Name
0			 January
1			 February
2			 March
3			 April
4			 May
5			 June
6			 July
7			 August
8			 September
9			 October
10			 November
11			 December */
string getMonthName(int monthNumber)
{
	string months[] = {"January", "February", "March",
					"April", "May", "June",
					"July", "August", "September",
					"October", "November", "December"
					};

	return (months[monthNumber]);
}

/* A Function to return the number of days in
a month

Month Number	 Name	 Number of Days
0			 January	 31
1			 February 28 (non-leap) / 29 (leap)
2			 March	 31
3			 April	 30
4			 May		 31
5			 June	 30
6			 July	 31
7			 August	 31
8			 September 30
9			 October	 31
10			 November 30
11			 December 31

*/
int numberOfDays (int monthNumber, int year)
{
	// January
	if (monthNumber == 0)
		return (31);

	// February
	if (monthNumber == 1)
	{
		// If the year is leap then February has
		// 29 days
		if (year % 400 == 0 ||
				(year % 4 == 0 && year % 100 != 0))
			return (29);
		else
			return (28);
	}

	// March
	if (monthNumber == 2)
		return (31);

	// April
	if (monthNumber == 3)
		return (30);

	// May
	if (monthNumber == 4)
		return (31);

	// June
	if (monthNumber == 5)
		return (30);

	// July
	if (monthNumber == 6)
		return (31);

	// August
	if (monthNumber == 7)
		return (31);

	// September
	if (monthNumber == 8)
		return (30);

	// October
	if (monthNumber == 9)
		return (31);

	// November
	if (monthNumber == 10)
		return (30);

	// December
	if (monthNumber == 11)
		return (31);
}

// Function to print the calendar of the given year
void printCalendar(int month, int year)
{
	printf ("		 Calendar - %d\n\n", year);
	int days;

	// Index of the day from 0 to 6
	int current = dayNumber (1, month, year);

	// i --> Iterate through all the months
	// j --> Iterate through all the days of the
	//	 month - i
	// for (int i = 0; i < 12; i++)
	// {
		days = numberOfDays (month, year);

		// Print the current month name
		printf("\n ------------%s-------------\n",
			getMonthName (month).c_str());

		// Print the columns
		printf(" Sun   Mon  Tue  Wed  Thu Fri    Sat\n");

		// Print appropriate spaces
		int k;
		for (k = 0; k < current; k++)
			printf("     ");

		for (int j = 1; j <= days; j++)
		{
			printf("%5d", j);

			if (++k > 6)
			{
				k = 0;
				printf("\n");
			}
		}

		if (k)
			printf("\n");

		current = k;
	// }

	return;
}

// Driver Program to check above functions
// int main()
// {
// 	int year = 2016;
// 	printCalendar(year);

// 	return (0);
// }


void cau3 ()
{
	cout << "1. Tinh so ngay" << endl;
	cout << "2. Tim thu" << endl;
	cout << "3. In lich thang" << endl;
	cout << "0. Thoat" << endl;
	cout << "Nhap lua chon: ";

	int n;
	cin >> n;

	while (n != 0)
	{
		if (n == 1)
		{
            int ngay_1;
            int thang_1;
            int nam_1;
            int ngay_2;
            int thang_2;
            int nam_2;
            cout << "nhap ngay (1): ";
            cin >> ngay_1;
            cout << "nhap thang (1): ";
            cin >> thang_1;
            cout << "nhap nam (1): ";
            cin >> nam_1;
            cout << "nhap ngay (2): ";
            cin >> ngay_2;
            cout << "nhap thang (2): ";
            cin >> thang_2;
            cout << "nhap nam (2): ";
            cin >> nam_2;
            Date dt1 = { ngay_1, thang_1, nam_1 };
            Date dt2 = { ngay_2, thang_2, nam_2};

            // Function call
            cout << "Difference between two dates is "
                << getDifference(dt1, dt2) << endl;

		}

        else if (n == 2)
        {
            int ngay;
            int thang;
            int nam;
            cout << "nhap ngay: ";
            cin >> ngay;
            cout << "nhap thang: ";
            cin >> thang;
            cout << "nhap nam: ";
            cin >> nam;

            tim_thu(ngay, thang, nam, nam_nhuan(nam));
            cout << endl;
        }
        

        else if (n == 3)
        {
            int year;
            int month;
            cout << "nhap vao thang: ";
            cin >> month;
            cout << "nhap vao nam: ";
            cin >> year;
	        printCalendar(month - 1, year);
            cout << endl;
        }
        

        cout << "Nhap lua chon: ";

	    cin >> n;
	}
	
	
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

char* process(char *str,char *result) {
  int pos = 0;
 
  const int len = strlen(str); /*Tìm độ dài chuỗi ban đầu*/
  for(int i = 0; i < len; i++) {
      char chr = str[i];

      /*Nếu ký tự lấy ra là ký tự trắng thì bỏ qua*/
      if (chr == ' ' && ((str[i + 1] >= 'a' && str[i + 1] <= 'z') || (str[i + 1] >= 'A' && str[i + 1] <= 'Z')))
			{
				result[pos++] = chr;
				continue;
			}
			
      if (chr == '\r' || chr == '\n' || chr == ' ') {
        continue;
      }

        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
      /*Thêm ký tự lấy ra vào kết quả*/
      result[pos++] = chr;
    }

	if (result[0] == ' ')
	{
		for (int i = 0; i < pos; i++)
		{
			result[i] = result[i+ 1];
		}
		result[pos - 1] = '\0';
	}
	
  return result;
}

void cau5 ()
{
    char str[] = "   *vo mai &^%$# phuon@#!g VIET   NAM   "; 
    cout << "before: ["<< str<<"]\n";
    char result[100];
    cout << "after : ["<< process(str,result)<<"]\n";
}


// cau 6
// void normalizeName(char* fullName)
// {
//     char *tmp = 0;
//     int i = 0, j = 0, length = strlen(fullName);
//     // Cấp phát bộ nhớ cho tmp
//     tmp = (char*)malloc((length+1)*sizeof(char));
//     // Thực hiện loại bỏ khoảng trắng
//     while (i < length){
//         // Nếu là chữ cái hoặc số
//         if (isalnum(fullName[i])){
//             tmp[j++] = fullName[i]; // đưa chữ cái hoặc số vào tmp
//         }
//         // nếu là dấu trắng và đằng sau phải là chữ cái hoặc số
//         else if (j && (fullName[i] == ' ') && isalnum(fullName[i+1]))
//         {
//             tmp[j++] = fullName[i]; // đưa khoảng trắng vào tmp
//         }
//         i++;
//     }
//     tmp[j] = 0; // thêm kí tự NULL vào cuỗi chuỗi tmp
 
//     // Thực hiện chuyển các kí tự đầu của từ thành IN HOA
//     for (i = 0; i < j; i++){
//         if (!i || ((tmp[i-1] == ' ') && isalpha(tmp[i]))){
//             tmp[i] = toupper(tmp[i]);
//         }
//     }
 
//     // Cóp ngược trở lại theo yêu cầu của đề bài
//     strcpy(fullName, tmp);
// }

char* normalizeName(string fullName)
{
    char *tmp = 0;
    int i = 0, j = 0, length = fullName.length();
    // Cấp phát bộ nhớ cho tmp
    tmp = (char*)malloc((length+1)*sizeof(char));
    // Thực hiện loại bỏ khoảng trắng
    while (i < length){
        // Nếu là chữ cái hoặc số
        if (isalnum(fullName[i])){
            tmp[j++] = fullName[i]; // đưa chữ cái hoặc số vào tmp
        }
        // nếu là dấu trắng và đằng sau phải là chữ cái hoặc số
        else if (j && (fullName[i] == ' ') && isalnum(fullName[i+1]))
        {
            tmp[j++] = fullName[i]; // đưa khoảng trắng vào tmp
        }
        i++;
    }
    tmp[j] = 0; // thêm kí tự NULL vào cuỗi chuỗi tmp
 
    // Thực hiện chuyển các kí tự đầu của từ thành IN HOA
    for (i = 0; i < j; i++){
        if (!i || ((tmp[i-1] == ' ') && isalpha(tmp[i]))){
            tmp[i] = toupper(tmp[i]);
        }
        else tmp[i] = tolower(tmp[i]);
    }
 
    // Cóp ngược trở lại theo yêu cầu của đề bài
    // strcpy(fullName, tmp);
    return tmp;
    
} 

// void normalizeName(string fullName)
// {
//     char *tmp = 0;
//     int i = 0, j = 0, length = fullName.length();
//     // Cấp phát bộ nhớ cho tmp
//     tmp = (char*)malloc((length+1)*sizeof(char));
//     // Thực hiện loại bỏ khoảng trắng
//     while (i < length){
//         // Nếu là chữ cái hoặc số
//         if (isalnum(fullName[i])){
//             tmp[j++] = fullName[i]; // đưa chữ cái hoặc số vào tmp
//         }
//         // nếu là dấu trắng và đằng sau phải là chữ cái hoặc số
//         else if (j && (fullName[i] == ' ') && isalnum(fullName[i+1]))
//         {
//             tmp[j++] = fullName[i]; // đưa khoảng trắng vào tmp
//         }
//         i++;
//     }
//     tmp[j] = 0; // thêm kí tự NULL vào cuỗi chuỗi tmp
 
//     // Thực hiện chuyển các kí tự đầu của từ thành IN HOA
//     for (i = 0; i < j; i++){
//         if (!i || ((tmp[i-1] == ' ') && isalpha(tmp[i]))){
//             tmp[i] = toupper(tmp[i]);
//         }
//     }
 
//     // Cóp ngược trở lại theo yêu cầu của đề bài
//     // strcpy(fullName, tmp);
//     for (int i = 0; i < length; i++)
//     {
//         fullName[i] = tmp[i];
//     }
    
// }
void cau6 ()
{
	string name = "   *vo mai &^%$# phuon@#!g VIET   NAM   ";
    cout << name << endl;
    char *name1 = normalizeName(name);
    for (int i = 0; i < name.length(); i++)
    {
        cout << name1[i];
    }
    // cout << name << endl;

}




// cau 7

const char CHAR_55 = 55;
const char CHAR_48 = 48;

void convertNumber(int n, int b) {
    if (n < 0 || b < 2 || b > 16 ) {
        printf("He co so hoac gia tri chuyen doi khong hop le!");
    }
    int i;
    char arr[20];
    int count = 0;
    int m;
    int remainder = n;
    while (remainder > 0) {
        if (b > 10) {
            m = remainder % b;
            if (m >= 10) {
                arr[count] = (char) (m + CHAR_55);
                count++;
            } else {
                arr[count] = (char) (m + CHAR_48);
                count++;
            }
        } else {
            arr[count] = (char) ((remainder % b) + CHAR_48);
            count++;
        }
        remainder = remainder / b;
    }

    for (i = count - 1; i >= 0; i--) {
        printf("%c", arr[i]);
    }
}
 

void cau7 ()
{
    int n;
    cout << "nhap so n trong he co so 10: ";
    cin >> n;
    cout << "so " << n << " trong he co so 2 la: ";
    convertNumber(n, 2); cout << endl;
    cout << "so " << n << " trong he co so 8 la: ";
    convertNumber(n, 8); cout << endl;
    cout << "so " << n << " trong he co so 16 la: " ;
    convertNumber(n, 16); cout << endl;
}
// int main() {
//     int n = 12;
//     printf("So %d trong he co so 2 = ", n);
//     convertNumber(n, 2);
//     printf("\nSo %d trong he co so 16 = ", n);
//  convertNumber(n, 16);
//     return 1;
// }

void cau769()
{
    int a;
    a = 9999;
    int *p = &a;
    cout << p << endl;
}
 
struct phan_so
{
    int tu_so;
    int mau_so;
    phan_so(int tu, int mau)
    {
        tu_so = tu;
        mau_so = mau;
    }

    double result ()
    {
        return tu_so * 1.0 / mau_so;
    } 
};


struct int_number {
    int x;
    int_number *next;
};

class number
{
private:
    int_number *pHead;
    int_number *pTail;

public:
    number();
    ~number();
    void insert_to_head(int x);
    void insert_to_tail(int x);
    void insert_after_qNode(int qNode, int x);
    void insert_befor_qNode(int qNode, int x);
    void output();
    long int sum();
    bool is_emty();
    int_number * pop();
};

int_number * number::pop()
{
    int_number *tmp =this->pHead;
    if (!tmp->next)
    {
        return nullptr;
    }
    else
    {
        tmp = tmp->next;
        this->pHead->next = tmp->next;
        tmp->next = nullptr;
    }
    return tmp;
}

number::number()
{
    this->pHead = new int_number;
    this->pTail = this->pHead;
    this->pHead->next = nullptr;
    this->pTail->next = nullptr;
    cout << "contrucstor" << endl;
}

number::~number()
{
    int_number *tmp;
    for (tmp = this->pHead; this->pHead; tmp = this->pHead)
    {
        this->pHead = this->pHead->next;
        delete tmp;
    }
    cout << "detructor" << endl;
}

void number::insert_to_head(int x)
{
    int_number *node = new int_number;
    node->x = x;
    node->next = nullptr;

    if (this->pHead->next == nullptr)
    {
        this->pHead->next = node;
        this->pTail = node;
    }
    else
    {
        node->next =this->pHead->next;
        this->pHead->next = node;
    }
    
}

void number::insert_to_tail(int x)
{
    int_number *node = new int_number;
    node->x = x;
    node->next = nullptr;

    if (this->pHead->next == this->pTail->next)
    {
        this->pHead->next = node;
        this->pTail = node;
    }
    else
    {
        this->pTail->next = node;
        this->pTail = node;
    }
    
}

void number::output()
{
    int_number *tmp = this->pHead->next;
    while (tmp)
    {
        cout << tmp->x << " ------> ";
        tmp = tmp->next;
    }
    cout << "nullptr" << endl;
}

long int number::sum()
{
    long int sum = 0;
    int_number *tmp =this->pHead->next;
    while (tmp)
    {
        sum += tmp->x;
        tmp = tmp->next;
    }
    return sum;
}


bool number::is_emty()
{
    if (this->pHead->next == nullptr)
    {
        return true;
    }
    
    return false;
   
}

void number::insert_after_qNode(int qNode, int x)
{
    int count = 0;
    int_number *tmp = this->pHead;
    if (!this->pHead->next)
    {
        cout << "can't completed method because this is an emty linked list" << endl;
    }
    else
    {
        tmp = tmp->next;
        while (tmp)
        {
            count++;
            if (count == qNode)
            {
                int_number *node = new int_number;
                node->x = x;      
                node->next =tmp->next;
                tmp->next = node;
                break;
            }
            tmp = tmp->next;
        }
        
    }   
}

void number::insert_befor_qNode(int qNode, int x)
{
    int count = 0;
    int_number *tmp = this->pHead;

    if (!tmp->next)
    {
        cout << "can't completed method because this is emty linked list.\n";
    }
    else
    {
        int_number *tmp0 = this->pHead;
        tmp = tmp->next;
        while (tmp)
        {
            count++;
            if (count == qNode)
            {
                int_number *newNode = new int_number;
                newNode->x = x;
                newNode->next = tmp;
                tmp0->next = newNode;
                break;
            }
            tmp0 = tmp0->next;
            tmp = tmp->next;
        }
        
    }   
}


struct coordinate {
    float x;
    float y;
    float z;
};

struct Point {
    coordinate infor;
    Point * nextPoint;
};

class mpOxy
{
private:
    Point *pHead;
    Point *pTail;
public:
    mpOxy();
    mpOxy(float x, float y, float z);
    ~mpOxy();
};

mpOxy::mpOxy()
{
    this->pHead = new Point;
    this->pHead->nextPoint = nullptr;
    this->pTail = this->pHead;
}

mpOxy::mpOxy(float x, float y, float z)
{
    this->pHead = new Point;
    this->pHead->nextPoint->infor.x = x;
    this->pHead->nextPoint->infor.y = y;
    this->pHead->nextPoint->infor.z = z;
    this->pHead->nextPoint->nextPoint = nullptr;

    this->pTail = this->pHead->nextPoint;

}
mpOxy::~mpOxy()
{
    Point *tmp;
    for (tmp = this->pHead; this->pHead; tmp = this->pHead)
    {
        this->pHead = this->pHead->nextPoint;
        delete tmp;
    }

    this->pTail = nullptr;
}


struct student_node
{
    char name[30];
    int Maths = 0;
    int Literture = 0;
    float average = 0.0f;

    student_node *next;
};

class LinkedListStudent
{
private:
    student_node *pHead;
    student_node *pTail;
public:
    LinkedListStudent();
    LinkedListStudent(char name[], int Maths, int Literture, float average);
    ~LinkedListStudent();
    void InsertLinkedList(char name[], int Maths, int Literture, float average);
    void outputLinkedList ();
};

LinkedListStudent::LinkedListStudent()
{
    this->pHead = new student_node;
    this->pHead->next = nullptr;
    this->pTail = this->pHead;    
}

LinkedListStudent::LinkedListStudent(char name[], int Maths, int Literture, float average)
{
    this->pHead = new student_node;
    for (int i = 0; i < 30; i++)
    {
        this->pHead->next->name[i] = name[i];
    }

    this->pHead->next->Maths = Maths;
    this->pHead->next->Literture = Literture;
    this->pHead->next->average = average;

    this->pHead->next->next = nullptr;
    this->pTail = this->pHead->next;
    

}

LinkedListStudent::~LinkedListStudent()
{
    student_node *ptr;
    for (ptr = this->pHead; this->pHead; ptr = this->pHead)
    {
        this->pHead = this->pHead->next;
        delete [] ptr->name;
        delete ptr;
    }
    
}

void LinkedListStudent::InsertLinkedList(char name[], int Maths, int Literture, float average)
{
    if (this->pHead->next == nullptr)
    {
        for (int i = 0; i < 30; i++)
        {
            this->pHead->next->name[i] = name[i];
        }
        
        this->pHead->next->Maths = Maths;
        this->pHead->next->Literture = Literture;
        this->pHead->next->average = average;

        this->pHead->next->next = nullptr;
        this->pTail = this->pHead->next;
    }
    else
    {
        student_node *insert = new student_node;
        insert->average = average;
        insert->Maths = Maths;
        insert->Literture = Literture;
        for (int i = 0; i < 30; i++)
        {
            insert->name[i] = name[i];
        }
        insert->next = nullptr;

        this->pTail->next = insert;
        this->pTail = insert;
    }
}
