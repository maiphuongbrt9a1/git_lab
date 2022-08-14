#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct Information
{
    string  strName;
    int     nPopulation;
    int     nLandArea;
};
struct Node
{
    Information info;
    Node        *nextName;
    Node        *nextPopulation;
    Node        *nextLandArea;
};

Node    *pHead;

void Insert(Node *&pHead, string strName, int nPopulation, int nLandArea)
{
    Node    *pNew = new Node();

    pNew->info.strName = strName;
    pNew->info.nPopulation = nPopulation;
    pNew->info.nLandArea = nLandArea;
    pNew->nextName = NULL;
    pNew->nextPopulation = NULL;
    pNew->nextLandArea = NULL;

    if(pHead->nextName == NULL)
    {
        pHead->nextName = pNew;
        pHead->nextPopulation = pNew;
        pHead->nextLandArea = pNew;
        return;
    }
    /////////////////////////////////////////////
    //Create Country Name List
    Node    *pTemp0 = NULL;
    Node    *pTemp = pHead->nextName;
    while(pTemp!=NULL &&
          strName.compare(pTemp->info.strName)>0)
    {
        pTemp0 = pTemp;
        pTemp = pTemp->nextName;
    }
    if(pTemp == pHead->nextName)
    {
        pNew->nextName = pHead->nextName;
        pHead->nextName = pNew;
    }
    else
    {
        pNew->nextName = pTemp;
        pTemp0->nextName = pNew;
    }

    /////////////////////////////////////////////
    //Create Population List
    pTemp0 = NULL;
    pTemp = pHead->nextPopulation;
    while(pTemp!=NULL &&
          nPopulation > pTemp->info.nPopulation)
    {
        pTemp0 = pTemp;
        pTemp = pTemp->nextPopulation;
    }
    if(pTemp == pHead->nextPopulation)
    {
        pNew->nextPopulation = pHead->nextPopulation;
        pHead->nextPopulation = pNew;
    }
    else
    {
        pNew->nextPopulation = pTemp;
        pTemp0->nextPopulation = pNew;
    }

    /////////////////////////////////////////////
    //Create Land Area List
    pTemp0 = NULL;
    pTemp = pHead->nextLandArea;
    while(pTemp!=NULL &&
          nLandArea > pTemp->info.nLandArea)
    {
        pTemp0 = pTemp;
        pTemp = pTemp->nextLandArea;
    }
    if(pTemp == pHead->nextLandArea)
    {
        pNew->nextLandArea = pHead->nextLandArea;
        pHead->nextLandArea = pNew;
    }
    else
    {
        pNew->nextLandArea = pTemp;
        pTemp0->nextLandArea = pNew;
    }
}
void createList()
{
    ifstream csvFile;
    string strPathCSVFile = "CountriesList.csv";
    csvFile.open(strPathCSVFile.c_str());

    if (!csvFile.is_open())
    {
        cout << "Path Wrong!!!!" << endl;
        return;
    }

    string line;
    getline(csvFile, line); // skip the 1st line

    while (getline(csvFile,line))
    {
        if (line.empty()) // skip empty lines:
        {
            continue;
        }
        std::istringstream s(line);
        std::string field;
        string  strName;
        int     nPopulation;
        int     nLandArea;
        for(int i = 0; i<3; i++)
        {
            getline(s, field, ',');
            if(i == 0)
                strName = field;
            else if(i == 1)
                nPopulation = atoi(field.c_str());
            else if(i == 2)
                 nLandArea = atoi(field.c_str());
        }
        Insert(pHead, strName, nPopulation, nLandArea);
    }
}
int countriesNum(Node *pHead)
{
    Node *temp = pHead->nextName;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->nextName;
    }
    
    return count;
}
void listbyNameAsc(Node *pHead)
{
    Node *temp = pHead->nextName;
    while (temp)
    {
        cout << setw(30) << left << temp->info.strName;
        cout << setw(30) << right << temp->info.nPopulation;
        cout << setw(30) << right << temp->info.nLandArea << endl;
        temp = temp->nextName;
    }
    
}
void listbyNameDes(Node *pHead)
{
    int sizeLinkedList = countriesNum(pHead);
    Node **arrNode = new Node *[sizeLinkedList];
    Node *temp = pHead->nextName;
    
    for (int i = 0; i < sizeLinkedList; i++)
    {
        arrNode[i] = temp;
        temp = temp->nextName;
    }
    
    for (int i = sizeLinkedList - 1; i >= 0; i--)
    {
        cout << setw(30) << left << arrNode[i]->info.strName;
        cout << setw(30) << right << arrNode[i]->info.nPopulation;
        cout << setw(30) << right << arrNode[i]->info.nLandArea << endl;
    }   
}
void listbyPopulationAsc(Node *pHead)
{
    Node *temp = pHead->nextPopulation;
    while (temp)
    {
        cout << setw(30) << left << temp->info.nPopulation;
        cout << setw(30) << right << temp->info.strName;
        cout << setw(30) << right << temp->info.nLandArea << endl;
        temp = temp->nextPopulation;
    }
}
void listbyPopulationDes(Node *pHead)
{
    int sizeLinkedList = countriesNum(pHead);
    Node **arrNode = new Node *[sizeLinkedList];
    Node *temp = pHead->nextPopulation;
    
    for (int i = 0; i < sizeLinkedList; i++)
    {
        arrNode[i] = temp;
        temp = temp->nextPopulation;
    }
    
    for (int i = sizeLinkedList - 1; i >= 0; i--)
    {
        cout << setw(30) << left << arrNode[i]->info.nPopulation;
        cout << setw(30) << left << arrNode[i]->info.strName;
        cout << setw(30) << right << arrNode[i]->info.nLandArea << endl;
    }
}
void listbyAreaAsc(Node *pHead)
{
    Node *temp = pHead->nextLandArea;
    while (temp)
    {
        cout << setw(20) << left << temp->info.nLandArea;
        cout << setw(20) << left << temp->info.strName;
        cout << setw(20) << right << temp->info.nPopulation << endl;
        temp = temp->nextLandArea;
    }
}
void listbyAreaDes(Node *pHead)
{
    int sizeLinkedList = countriesNum(pHead);
    Node **arrNode = new Node *[sizeLinkedList];
    Node *temp = pHead->nextLandArea;
    
    for (int i = 0; i < sizeLinkedList; i++)
    {
        arrNode[i] = temp;
        temp = temp->nextLandArea;
    }
    
    for (int i = sizeLinkedList - 1; i >= 0; i--)
    {
        cout << setw(20) << left << arrNode[i]->info.nLandArea;
        cout << setw(20) << left << arrNode[i]->info.strName;
        cout << setw(20) << right << arrNode[i]->info.nPopulation << endl;
    }
}





void normalizeName(string & fullName)
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
    fullName = "";
    for (int i = 0; i < length; i++)
    {
        fullName += tmp[i];
    }
}

Node* searchbyName(Node *pHead)
{
    string name;
    cout << "Nhap ten quoc gia muon tim: ";
    std::cin.ignore(32767, '\n');
    getline(cin, name);

    normalizeName(name);
    // cout << name << endl;
    Node *p = pHead->nextName;
    while (p)
    {
        if (p->info.strName == name) return p;
        else p = p->nextName;
    }
    
    return NULL;
}
void searchbyPopulation(Node *pHead)
{
    int nMin = 0;
    int nMax = 0;

    cout << "nhap vao khoang gia tri ma ban muon tim: " << endl;
    cin >> nMin;
    cin >> nMax;

    Node *temp = pHead->nextPopulation;
    while (temp)
    {
        if (nMin <= temp->info.nPopulation && temp->info.nPopulation <= nMax)
        {
            cout << setw(30) << left << temp->info.strName;
            cout << setw(30) << right << temp->info.nPopulation;
            cout << setw(30) << right << temp->info.nLandArea << endl;
            temp = temp->nextPopulation;
        }
        else temp = temp->nextPopulation;
    }
    
}
void searchbyArea(Node *pHead)
{
    int nMin = 0;
    int nMax = 0;

    cout << "nhap vao khoang gia tri ma ban muon tim: " << endl;
    cin >> nMin;
    cin >> nMax;

    Node *temp = pHead->nextLandArea;
    while (temp)
    {
        if (nMin <= temp->info.nLandArea && temp->info.nLandArea <= nMax)
        {
            cout << setw(30) << left << temp->info.strName;
            cout << setw(30) << right << temp->info.nPopulation;
            cout << setw(30) << right << temp->info.nLandArea << endl;
            temp = temp->nextLandArea;
        }
        else temp = temp->nextLandArea;
    }
}
void insertCountry(Node *&pHead)
{
    string name = "";
    int nPopulation = 0;
    int nLandArea = 0;
    cout << "Nhap ten quoc gia muon them: ";
    std::cin.ignore(32767, '\n');
    getline(cin, name);
    cout << "Nhap dan so quoc gia muon them: ";
    cin >> nPopulation;
    cout << "Nhap dien tich quoc gia muon them: ";
    cin >> nLandArea;

    normalizeName(name);
    // cout << name << endl;
    Node *p = pHead->nextName;
    bool country_flag = false;
    while (p)
    {
        if (p->info.strName == name) 
        {
            country_flag = true;
            break;
        }
        else p = p->nextName;
    }
    
    if (!country_flag)
    {
        Insert(pHead, name, nPopulation, nLandArea);
    }
    
}

void deleteCountry(Node *&pHead)
{
    string name;
    cout << "Nhap ten quoc gia muon xoa: ";
    std::cin.ignore(32767, '\n');
    getline(cin, name);

    normalizeName(name);
    // cout << name << endl;
    Node *p = pHead->nextName;
    Node *temp = pHead;
    // Node *temp = pHead->nextName;
    while (p)
    {
        if (p->info.strName == name)
        {
            temp->nextName = p->nextName;
            temp->nextLandArea = p->nextLandArea;
            temp->nextPopulation = p->nextPopulation;

            p->nextLandArea = nullptr;
            p->nextName = nullptr;
            p->nextPopulation = nullptr;
            break;
        }
        else 
        {
            temp = p;
            p = p->nextName;
        }
    }
}
int main()
{
    pHead = new Node();

    pHead->nextName = NULL;
    pHead->nextPopulation = NULL;
    pHead->nextLandArea = NULL;
    createList();

    int     nChoice = -1;

    do
    {
        ///////////////////////////////////////
        cout << "   CHON CHUC NANG" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "1. So luong quoc gia" << endl;
        cout << "2. Danh sach xep theo ten (A->Z)" << endl;
        cout << "3. Danh sach xep theo ten (Z->A)" << endl;
        cout << "4. Danh sach xep theo dan so (it->nhieu)" << endl;
        cout << "5. Danh sach xep theo dan so (nhieu->it)" << endl;
        cout << "6. Danh sach xep theo dien tich (nho->lon)" << endl;
        cout << "7. Danh sach xep theo dien tich (lon->nho)" << endl;
        cout << "8. Tim kiem theo ten" << endl;
        cout << "9. Tim kiem theo dan so" << endl;
        cout << "10.Tim kiem theo dien tich" << endl;
        cout << "11.Them quoc gia" << endl;
        cout << "12.Xoa quoc gia" << endl;

        cout << "Nhap lua chon: ";
        cin >> nChoice;

        Node* pTemp;
        switch(nChoice)
        {
        case 1:
            cout << "So luong quoc gia: " <<countriesNum(pHead)<<endl;
            break;
        case 2:
            listbyNameAsc(pHead);
            break;
        case 3:
            listbyNameDes(pHead);
            break;
        case 4:
            listbyPopulationAsc(pHead);
            break;
        case 5:
            listbyPopulationDes(pHead);
            break;
        case 6:
            listbyAreaAsc(pHead);
            break;
        case 7:
            listbyAreaDes(pHead);
            break;
        case 8:
            pTemp = searchbyName(pHead);
            if(pTemp!=NULL)
            {
                cout << "Thong tin quoc gia: " << endl;
                cout << setw(25)<<left<<pTemp->info.strName;
                cout << setw(12)<<right<<pTemp->info.nPopulation;
                cout << setw(12)<<right<<pTemp->info.nLandArea;
                cout << endl;
            }
            else
                cout << "Khong ton tai quoc gia nay trong danh sach" << endl;
            break;
        case 9:
            searchbyPopulation(pHead);
            break;
        case 10:
            searchbyArea(pHead);
            break;
        case 11:
            insertCountry(pHead);
            break;
        case 12:
            deleteCountry(pHead);
            break;
        }
    }while(nChoice != 0);

    return 0;
}
