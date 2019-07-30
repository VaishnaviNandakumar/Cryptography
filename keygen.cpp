#include<iostream>
#include<string.h>
#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;
static int i;

//To perform left shift operation
string left_shift( string s, int d)
{
reverse(s.begin(), s.begin()+d);
reverse(s.begin()+d, s.end());
reverse(s.begin(), s.end());
return s;
}

//For permutation of string
string permute(string inputval)
{

    int p48[48] = {14,17,11,24,1,5,
                   3,28,15,6,21,10,
                   23,19,12,14,26,8,
                   16,7,27,20,13,2,
                   41,52,31,37,47,55,
                   30,40,51,45,33,48,
                   44,49,39,56,34,53,
                   46,42,50,36,29,32};

    string out_p=" ";
    for(int i=0; i<48;i++)
    {
    out_p+=inputval[p48[i]-1];
    }

    return out_p;
}



//To split key equally and perform left shift
string split_key(string key_value)
{
string left_ip, right_ip;


string total_ip;

for(i=1;i<=16;i++)
{
    string lip = key_value.substr(0,28);
    string rip = key_value.substr(28,56);
    if(i==1||i==2||i==9|i==16)
    {
        left_ip= left_shift(lip,1);
        right_ip= left_shift(rip,1);
    }
    else
    {
        left_ip= left_shift(lip,2);
        right_ip= left_shift(rip,2);
    }

    /*cout<<"L"<<i<<"\t"<<left_ip<<endl;
    cout<<"R"<<i<<"\t"<<right_ip<<endl;*/

    key_value= left_ip+right_ip;

    string final_key =permute(key_value);

    cout<<endl<<"Key "<<i<<"\t"<<final_key<<endl;
}

}


int main()
{
cout<<"56 bit key seed value is:  ";
string key_value= "11100001100110010101010111111010101011001100111100011110";
cout<<key_value<<endl;

split_key(key_value);
}





