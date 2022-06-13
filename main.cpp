#include "bt.h"
using namespace std;

int main() 
{
    long long int n;
    long long int x;
    cout << "nhap n:\n";
    cin >> n;
    cout << "nhap x:\n";
    cin >> x;
    cout << sum_n_number(n) << endl;
    cout << sum_square_n_number(n) << endl;
    cout << tong_phan_so_1_chia_n(n) << endl;
    cout << tong_phan_so_1_chia_2n(n) << endl;
    cout << power_x_n(x, n) << endl;


    cout << "factorial of n:" << endl;
    cout << factorial_n(n) << endl;

    cout << "tong s_n: \n";
    cout << sum_sn(x,n) << endl;

    uoc_so_cua_n(n);
    cout << "tong cua s_n_33: " << tong_can_2_long_nhau(n) << endl;
    cout << "tong cua s_n_34: " << tong_can_long_nhau_34(n) << endl;
    cout << "tong cua s_n_35: " << tong_can_long_nhau_35(n) << endl;

    cout << "tong cua s_n_40: " << tong_can_long_nhau_40(x, n) << endl;


    cout << "tong cau 41: " << tong_cau_41(n) << endl;
    find_k_max(n);

    number_of_digits(n);
    cout << "tong cac chu so cua so n: " << sum_of_digits(n) << endl;
    
    cout << "reverse of n: " << reverse(n) << endl;
    return 0;
}