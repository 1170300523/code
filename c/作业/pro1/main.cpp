//先按照字典序排序,再处理数字;
#include <iostream>
#include<string>

using namespace std;

int main()
{
    int i,j,c;

    string a[9];
    a[0]= "PAB";
    a[1]= "5C";
    a[2]= "PABC";
    a[3]= "CXY";
    a[4]= "CRSI";
    a[5]= "7";
    a[6]="B899" ;
    a[7]= "B9";
    a[8]= "wrong";

    for(i =0; i<7; i++)
    {
        for(j = i+1; j<8; j++)
        {
            if(a[i].compare(a[j])> 0)
            {
                a[8] = a[i];
                a[i] = a[j];
                a[j] = a[8];
            }
        }
    }

    for(i =0; i<8; i++)if(a[i][0] <= '9')c = i;

    string b[8];
    for(i =0;i<=c;i++)b[7-c+i] = a[i];
    for(i =0;i<7-c;i++)b[i] = a[c+i+1];
    for(i =0; i<8; i++)
        cout << b[i]<< endl;
    return 0;
}
