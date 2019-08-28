#include<iostream>
#include<string.h>
#include<stdio.h>
#include <string>
#include <cstdlib>
#include<stdlib.h>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
//From key generation program
    string keyval[]={
    "000110110000001011101111111111000111000001110010",
    "011110011010111011011001110110111100100111100101",
    "010101011111110010001010010000101100111110011001",
    "011100101010110111010110110110110011010100011101",
    "011111001110110000000111111010110101001110101000",
    "011000111010010100111110010100000111101100101111",
    "111011001000010010110111111101100001100010111100",
    "111101111000101000111010110000010011101111111011",
    "111000001101101111101011111011011110011110000001",
    "101100011111001101000111101110100100011001001111",
    "001000010101111111010011110111101101001110 000110",
    "011101010111000111110101100101000110011111101001",
    "100101111100010111010001111110101011101001000001",
    "010111110100001110110111111100101110011100111010",
    "101111111001000110001101001111010011111100001010",
    "110010110011110110001011000011100001011111110101"
   };

    int s[8][4][16]=
    {{
        14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
    },
    {
        15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
    },


    {
        10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
    },
    {
        7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
        10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
    },
    {
        2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
        11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
    },
    {
        12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
    },
    {
        4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
    },
    {
        13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
        1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
        7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
        2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
    }};

string bin2hex(string p){
string op="";
string bits_COL[]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
for(int i=0;i<64;i+=4)
{
        string a,b,c,d;
        int j;
        a=p[i];
        b=p[i+1];
        c=p[i+2];
        d=p[i+3];

        string text = a+b+c+d;
        //cout<<endl<<"TEXT "<<text<<endl;
        int lc;
        for(j=0; j<=15;j++)
        {
            if(text==bits_COL[j])
            {
                if(j<=9)
                {
                string out_string;
                stringstream ss;
                ss << j;
                out_string = ss.str();
                //cout<<"oustring"<<out_string;
                op+=out_string;
                }

                else if(j>9){
                    if(j==10)
                        op+="A";
                    if(j==11)
                        op+="B";
                    if(j==12)
                        op+="C";
                    if(j==13)
                        op+="D";
                    if(j==14)
                        op+="E";
                    if(j==15)
                        op+="F";
                }
        }
        }
}
return op;
}
string hex2bin(string p)//hexadecimal to binary
{
        string ap="";
        int l=p.length();
        for(int i=0;i<l;i++)
        {
            string st="";
            if(p[i]>='0'&&p[i]<='9')
            {
                int te=int(p[i])-48;
                while(te>0)
                {
                    st+=char(te%2+48);
                    te/=2;
                }
                while(st.length()!=4)
                    st+='0';
                for(int j=3;j>=0;j--)
                    ap+=st[j];
            }
            else
            {
                int te=p[i]-'A'+10;
                while(te>0)
                {
                    st+=char(te%2+48);
                    te/=2;
                }
                for(int j=3;j>=0;j--)
                    ap+=st[j];
            }
        }
        return ap;
}


string initial_permuation( string inputval){
            int p64[64]={
            58,    50,   42,    34,    26,   18,    10,    2,
            60,    52,   44,    36,    28,   20,    12,    4,
            62,    54,   46,    38,    30,   22,    14,    6,
            64,    56,   48,    40,    32,   24,    16,    8,
            57,    49,   41,    33,    25,   17,     9,    1,
            59,    51,   43,    35,    27,   19,    11,    3,
            61,    53,   45,    37,    29,   21,    13,    5,
            63,    55,   47,    39,    31,   23,    15,    7
            };
            string out_p="";
            for(int i=0; i<64;i++)
            {
            out_p+=inputval[p64[i]-1];
            }

            return out_p;
}

string inv_perm(string text)
{
    int p64[64]=      {
            40,     8,   48,    16,    56,   24,    64,   32,
            39,     7,   47,    15,    55,   23,    63,   31,
            38,     6,   46,    14,    54,   22,    62,   30,
            37,     5,   45,    13,    53,   21,    61,   29,
            36,     4,   44,    12,    52,   20,    60,   28,
            35,     3,   43,    11,    51,   19,    59,   27,
            34,     2,   42,    10,   50,   18,    58,   26,
            33,     1,   41,    9,    49,   17,    57,   25};
    string out_p="";
    for(int i=0; i<64;i++)
    {
    out_p+=text[p64[i]-1];
    }

    return out_p;
}

string expn(string key)
{
    int p48[48]=      {
                32,     1,    2,     3,     4,    5,
                  4,     5,    6,     7,     8,    9,
                  8,     9,   10,    11,    12,   13,
                 12,    13,   14,    15,    16,   17,
                 16,    17,   18,    19,    20,   21,
                 20,    21,   22,    23,    24,   25,
                 24,    25,   26,    27,    28,   29,
                 28,    29,   30,    31,    32,    1};
    string out_p="";
    for(int i=0; i<48;i++)
    {
    out_p+=key[p48[i]-1];
    }

    return out_p;

}
string after_sbox(string inp)
{
    int p32[32]=      {
                        16,   7,  20,  21,
                         29,  12,  28,  17,
                          1,  15,  23,  26,
                          5,  18,  31,  10,
                          2,   8,  24,  14,
                         32,  27,   3,   9,
                         19,  13,  30,   6,
                         22,  11,   4,  25};
    string out_p="";
    for(int i=0; i<32;i++)
    {
    out_p+=inp[p32[i]-1];
    }

    return out_p;

}
string s_box(string value)
{
    int n=0;


    int i,j, lr, lc;
    int conv;
    string op="";
    string bits_ROW[]={"00","01","10","11"};
    int k=0;
    string bits_COL[]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
    while(k<48)
    {


        string row="";
        string col="";
        string a,b,c,d,e,f;

        a=value[k];
        b=value[k+5];
        c=value[k+1];
        d=value[k+2];
        e=value[k+3];
        f=value[k+4];
        row= a+b;
        col= c+d+e+f;
        for(i=0;i<4;i++){
            if(row == bits_ROW[i])
                lr=i;
        }
        for(j=0; j<16;j++){
            if(col==bits_COL[j])
                lc=j;
        }

        int n=k/6;
        conv=s[n][lr][lc];
        op+=bits_COL[conv];
        k=k+6;
        }
        //cout<<value<<endl;




    op= after_sbox(op);

    return op;
}
string XOR(string a,string b)
{
    string output = "";
    for(int i=0;i<a.size();i++){
        if(a[i] == b[i])
            output += "0";
        else
            output += "1";
    }
    return output;
}

string function_encrypt(string left, string right, string key)
{
    string left_val= right;
    string right_val;
    string total_val;
    string exp_key= expn(right);
    string output;
    string res;
    output= XOR(exp_key, key);
    //cout<<"RIGHT VALUE  "<<output<<endl;
    output= s_box(output);

    right_val= XOR(output,left);
    total_val= left_val +right_val;

    return total_val;


}

string decrypt( string p)
{
p = initial_permuation(p);
cout<<endl<<"Initial Permutation:"<<endl<<p;
string left_tot, right_tot;
string total_text;

for(int i=1;i<=16;i++)
{

    left_tot= p.substr(0,32);
    right_tot= p.substr(32,64);
    total_text=left_tot+right_tot;

    p = function_encrypt(left_tot, right_tot, keyval[16-i]);
}
string left= p.substr(32,64);
string right= p.substr(0,32);
string decrypt= left+right;
decrypt = inv_perm(decrypt);

cout<<endl<<endl<<"Decrypted Data is:"<<endl<<decrypt;

string plain_text= bin2hex(decrypt);

cout<<endl<<endl<<"PLAIN TEXT IS:"<<endl<<plain_text;
}






string split_key(string text)
{

string left_tot, right_tot;
string total_text;

for(int i=1;i<=16;i++)
{

    left_tot= text.substr(0,32);
    right_tot= text.substr(32,64);
    text = function_encrypt(left_tot, right_tot, keyval[i-1]);

}
string left= text.substr(32,64);
string right= text.substr(0,32);

string encrypt= left+right;

encrypt = inv_perm(encrypt);


cout<<endl<<"Encrypted Data is:"<<endl<<encrypt;
string cipher= bin2hex(encrypt);

cout<<endl<<endl<<"CIPHER TEXT:"<<endl<<cipher;

//DES DECRYPTION
cout<<endl<<endl<<"------------DECRYPTION------------"<<endl;
decrypt(encrypt);

}

int main()
{
string key_value;
string plaintext;
cout<<"-------------DES ENCRYPTION AND DECRYPTION--------------------";
cout<<endl<<endl<<"Enter the plain text value: ";
cin>>plaintext;
string convtext = hex2bin(plaintext);
cout<<endl<<"Binary Format"<<endl<<convtext;

cout<<endl<<endl<<"------------ENCRYPTION------------";
string func_value = initial_permuation(convtext);
cout<<endl<<endl<<"Initial permutation:"<<endl<<func_value<<endl;
split_key(func_value);

}







