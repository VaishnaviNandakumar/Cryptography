#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cstdlib>
#include<stdlib.h>
#include<sstream>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;
string  sbox[16][16]={      "63",	"7c",	"77",	"7b",	"f2",	"6b",	"6f",	"c5",   "30",	"01",	"67",	"2b",	"fe",	"d7",	"ab",	"76",
                            "ca",	"82",	"c9",	"7d",	"fa",	"59",   "47",	"f0",	"ad",	"d4",	"a2",	"af",	"9c",	"a4",	"72",	"c0",
                            "b7",	"fd",	"93",	"26",	"36",	"3f",	"f7",	"cc",	"34",	"a5",   "e5",	"f1",	"71",	"d8",	"31",	"15",
                            "04",	"c7",	"23",	"c3",	"18",	"96",	"05",	"9a",	"07",	"12",	"80",   "e2",	"eb",	"27",	"b2",	"75",
                            "09",	"83",	"2c",	"1a",	"1b",	"6e",	"5a",	"a0",	"52",	"3b",	"d6",	"b3",	"29",	"e3",	"2f",	"84",
                            "53",	"d1",	"00",	"ed",	"20",	"fc",	"b1",	"5b",	"6a",	"cb",	"be",	"39",	"4a",	"4c",	"58",	"cf",
                            "d0",	"ef",	"aa",	"fb",	"43",	"4d",	"33",	"85",	"45",	"f9",   "02",	"7f",	"50",	"3c",	"9f",	"a8",
                            "51",	"a3",	"40",	"8f",	"92",	"9d",	"38",	"f5",	"bc",	"b6",	"da",	"21",	"10",	"ff",	"f3",	"d2",
                            "cd",	"0c",	"13",	"ec",	"5f",	"97",	"44",	"17",	"c4",	"a7",	"7e",	"3d",	"64",	"5d",	"19",	"73",
                            "60",	"81",	"4f",	"dc",	"22",	"2a",	"90",	"88",	"46",	"ee",	"b8",	"14",	"de",	"5e",	"0b",	"db",
                            "e0",	"32",	"3a",	"0a",	"49",	"06",	"24",	"5c",	"c2",	"d3",	"ac",	"62",	"91",	"95",	"e4",	"79",
                            "e7",	"c8",	"37",	"6d",	"8d",	"d5",	"4e",	"a9",	"6c",	"56",	"f4",	"ea",	"65",	"7a",	"ae",	"08",
                            "ba",	"78",	"25",	"2e",	"1c",	"a6",	"b4",	"c6",	"e8",	"dd",	"74",	"1f",	"4b",	"bd",	"8b",	"8a",
                            "70",	"3e",	"b5",	"66",	"48",	"03",	"f6",	"0e",	"61",	"35",	"57",	"b9",	"86",	"c1",	"1d",	"9e",
                            "e1",	"f8",	"98",	"11",	"69",	"d9",	"8e",	"94",	"9b",	"1e",	"87",	"e9",	"ce",	"55",	"28",	"df",
                            "8c",	"a1",	"89",	"0d",	"bf",	"e6",	"42",	"68",	"41",	"99",	"2d",	"0f",	"b0",	"54",	"bb",	"16" };
string keys[11][16]=
{

 "54", "68", "61", "74", "73", "20", "6D", "79", "20", "4B", "75", "6E", "67", "20", "46", "75",
 "E2", "32", "FC", "F1", "91", "12", "91", "88", "B1", "59", "E4", "E6", "D6", "79", "A2", "93",
 "56", "08", "20", "07", "C7", "1A", "B1", "8F", "76", "43", "55", "69", "A0", "3A", "F7", "FA",
 "D2", "60", "0D", "E7", "15", "7A", "BC", "68", "63", "39", "E9", "01", "C3", "03", "1E", "FB",
 "A1", "12", "02", "C9", "B4", "68", "BE", "A1", "D7", "51", "57", "A0", "14", "52", "49", "5B",
 "B1", "29", "3B", "33", "05", "41", "85", "92", "D2", "10", "D2", "32", "C6", "42", "9B", "69",
 "BD", "3D", "C2", "B7", "B8", "7C", "47", "15", "6A", "6C", "95", "27", "AC", "2E", "0E", "4E",
 "CC", "96", "ED", "16", "74", "EA", "AA", "03", "1E", "86", "3F", "24", "B2", "A8", "31", "6A",
 "8E", "51", "EF", "21", "FA", "BB", "45", "22", "E4", "3D", "7A", "06", "56", "95", "4B", "6C",
 "BF", "E2", "BF", "90", "45", "59", "FA", "B2", "A1", "64", "80", "B4", "F7", "F1", "CB", "D8",
 "28", "FD", "DE", "F8", "6D", "A4", "24", "4A", "CC", "C0", "A4", "FE", "3B", "31", "6F", "26" };

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

string bin2hex(string p, int n){
string op="";
string bits_COL[]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
for(int i=0;i<n;i+=4)
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

int hex2dec( string val)
{
    char num[20];
    int i, r, len, hex = 0;

    len = val.size();
    for (i = 0; val[i] != '\0'; i++)
    {
        len--;
        if(val[i] >= '0' && val[i] <= '9')
            r = val[i] - 48;
        else if(val[i] >= 'a' && val[i] <= 'f')
                r = val[i] - 87;
             else if(val[i] >= 'A' && val[i] <= 'F')
                    r = val[i] - 55;
        hex += r * pow(16,len);
    }
    return hex;
}


string dec2hex(int decnum)
{
    long int rem, quot;
	char hexdecnum[100];
	int i=1, j, temp;
	string finalno="";
	quot=decnum;
	while(quot!=0)
	{
		temp=quot%16;
		// to convert integer into character
		if(temp<10)
		{
			temp=temp+48;
		}
		else
		{
			temp=temp+55;
		}
		hexdecnum[i++]=temp;
		quot=quot/16;
	}

	for(j=i-1; j>0; j--)
	{
		finalno+=hexdecnum[j];
	}
	return finalno;
}
string addroundkey(string text, int i)
{
    int j=i;
    int k=i+16;
    string rkey;
    string finalkey;
    for(i=0;i<k;i++)
    rkey+=keys[j][i];
    //cout<<endl<<rkey<<endl;
    string output="";
    int n=0;
    while(n<32)
    {
        string subkey="";
        string mainkey="";

        mainkey=text.substr(n,2);
        subkey= rkey.substr(n,2);
        //cout<<mainkey<<"+"<<subkey<<endl;
        string no1=hex2bin(mainkey);
        string no2=hex2bin(subkey);
        string roundsum=XOR(no1,no2);
        string round=bin2hex(roundsum,8);
        finalkey+=round;

        n=n+2;
    }
 return finalkey;


}
string subbyte(string text)
{
    int i;
    string ffkey;
    for(i=0;i<32;i+=2)
    {
        string op=text.substr(i,2);
        string r=op.substr(0,1);
        string c=op.substr(1,1);


        /*int row= atoi(r.c_str());
        int col= atoi(c.c_str());*/
        int row= hex2dec(r);
        int col= hex2dec(c);
        //cout<<"row col  "<<r<<"  "<<c<<" "<<row<<" "<<col<<endl;
        string ip= sbox[row][col];
        //cout<<ip<<endl;
        ffkey+=ip;
    }
    return ffkey;
}

string left_shift( string s, int d)
{
reverse(s.begin(), s.begin()+d);
reverse(s.begin()+d, s.end());
reverse(s.begin(), s.end());
return s;
}

string matrix[4][4]={ "02", "03", "01", "01",
                      "01", "02", "03", "01",
                      "01", "01", "02", "03",
                      "03", "01", "01", "02" };



string mixcol2(string a, string b, int flag, string d)
{
  string es;
    if(flag==0)
    {
        int p=hex2dec(a);
        int m=hex2dec(b);
        int ans=p*m;
        //cout<<p<<m;
        es=dec2hex(ans);
        es=hex2bin(es);

    }
    else
    {
        string h= left_shift(d,1);
        //cout<<h<<endl;
        h.replace(7,1,"0");
        //cout<<h<<endl;
        es = XOR(h,"00011011");
    }
    return es;
}



string mixcolumn(string text)
{
int i,j,k, y;
string matrixtext[4][4];
int t=0;
                    for(i=0;i<4;i++)
                    {
                            for(j=0;j<4;j++)
                            {
                               string input= text.substr(t,2);
                               matrixtext[j][i]=input;
                               t=t+2;
                            }
                    }

                    string temp;
                        temp = matrixtext[1][0];
                        matrixtext[1][0] = matrixtext[1][1];
                        matrixtext[1][1] = matrixtext[1][2];
                        matrixtext[1][2] = matrixtext[1][3];
                        matrixtext[1][3] = temp;

                        //Row 3
                        temp = matrixtext[2][0];
                        matrixtext[2][0] = matrixtext[2][2];
                        matrixtext[2][2] = temp;
                        temp = matrixtext[2][1];
                        matrixtext[2][1] = matrixtext[2][3];
                        matrixtext[2][3] = temp;

                        //Row 4
                        temp = matrixtext[3][0];
                        matrixtext[3][0] = matrixtext[3][3];
                        matrixtext[3][3] = matrixtext[3][2];
                        matrixtext[3][2] = matrixtext[3][1];
                        matrixtext[3][1] = temp;


                        cout<<endl<<"Shifted Row Output:"<<endl;
                        for(i=0;i<4;i++)
                        {

                            for(j=0;j<4;j++)
                        {
                            cout<<matrixtext[i][j]<<"\t";
                        }
                        cout<<endl;
                        }
                        cout<<endl;



string mul[4][4];
string a,b,c,d;

for(y=0;y<4;y++)
{
for(j=0;j<4;j++)
{
string fval[4];
for(k=0;k<4;k++)
{
int flag=0;
string r,s,t,q;


b=matrixtext[k][j];
a=matrix[y][k];
//c=hex2bin(a);
d=hex2bin(b);

string e= d.substr(0,1);
string f= "1";
int atp= e.compare(f);
//cout<<b<<" "<<a<<endl;

if(atp==0)
    flag=1;

if(a=="01")
{
   r=d;
   fval[k]=r;
}

else if(a=="02")
{
    s=mixcol2(a,b,flag, d);
    fval[k]=s;
}
else if(a=="03")
{
t=mixcol2("02",b,flag,d);
t=XOR(t,d);
fval[k]=t;
}


}//k

/*cout<<"FVAL";
for(i=0;i<4;i++)
{
    cout<<endl<<fval[i]<<endl;
}*/


string ans1=XOR(fval[0],fval[1]);
string ans2=XOR(fval[2], fval[3]);
string ans3= XOR(ans1,ans2);
string ans4=bin2hex(ans3,8);
mul[y][j]=ans4;
//cout<<endl<<"Mul"<<mul[j][y]<<endl;


}//j

}//i
cout<<endl<<"Mixed Column Output:"<<endl;

for(i=0;i<4;i++)
{

    for(j=0;j<4;j++)
{
    cout<<mul[i][j]<<"\t";
}
cout<<endl;
}

}


string encrypt( string plain, int i)
{

    string rrkey= addroundkey(plain,i);
    cout<<endl<<"Add round key output:"<<rrkey<<endl;
    string subbkey= subbyte(rrkey);
    cout<<endl<<"Sub byte output:"<<subbkey<<endl;
    string mixcol= mixcolumn(subbkey);
}

int main()
{
    string plain="54776F204F6E65204E696E652054776F";
    cout<<"The plain text in hex: \t"<<plain<<endl;
    encrypt(plain,0);
}
