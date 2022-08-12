#include "bt.h"
using namespace std;

// int main() 
// {
    // string events = "!1 2 2 1 5 6 7 1 2 2 1 5 6 7 1 3 3 4 5 6 7 1 3 3 4 5 6 7 1 3 3 4 5 6 7 1 3 3 4 5 6 7 1 3 3 4 5 6 7!";
    // int index = 1;
    // int i = 1;
    // int m = (i % 7) > 2 ? (i % 7) : 2;
    // int min_matrix = 0;
    // int col = 1;
    // int row = 1;
    
    // int **arr = new int *[7];
    // for (int i = 0; i < 7; i++)
    // {
    //     arr[i] = new int [7];
    // }
    
    // for (int i = 0; i < 7; i++)
    // {
    //     for (int j = 0; j < 7; j++)
    //     {
    //         string number = "";
    //         while (events[index] != ' ' && events[index] != '#' && events[index] != '!')
    //         {
    //             number += events[index];
    //             index++;
    //         }

    //         arr[i][j] = atoi(number);

    //         index++;
    //     }
        
    // }

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         min_matrix += arr[i][j];
    //     }
        
    // }

    // for (int i = 0; i < 7 - m; i++)
    // {
    //     for (int j = 0; j < 7 - m; j++)
    //     {
    //         int min_temp = 0;
    //         for (int r = i; r < i + m; r++)
    //         {
    //             for (int k = j; k < j + m; k++)
    //             {
    //                 min_temp += arr[r][k];
    //             }
                
    //         }

    //         if (min_temp < min_matrix)
    //         {
    //             min_matrix = min_temp;
    //             col = j + 1;
    //             row = i + 1;
    //         }
            
            
    //     }
        
    // }

    // for (int i = 0; i < 7; i++)
    // {
    //     for (int j = 0; j < 7; j++)
    //     {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    // cout << min_matrix << endl;
    // cout << row << endl;
    // cout << col << endl;
    
    //1
    // int days;
    // cin >> days;
    // year_week_day(days);
    
    //2
    // float a1;
    // float b1;
    // float a2;
    // float b2;
    // cin >> a1  >> b1;
    // cin >> a2  >> b2;
    // tim_giao_diem(a1,b1,a2,b2);

    //3
    // int nam;
    // cin >> nam;
    // thien_can_dia_chi(nam);

    //4
//     int nam;
//    int thang;
//    int ngay;
//    cin >> ngay >> thang >> nam;
//    tim_thu(ngay, thang, nam, nam_nhuan(nam));

    // int *p = new int [10];
    // srand(time(0));
    // for (int i = 0; i < 10; i++)
    // {
    //     p[i] = rand() % 100;
    //     cout << p[i] << " ";
    // }

    // delete[] p;
    // p = nullptr;
int main() 
{
    cau6();
    return 0;
}   


