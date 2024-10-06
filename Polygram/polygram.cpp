#include<bits/stdc++.h>
using namespace std;

map<string,string>cipher_mp,decipher_mp;

string encryption_decryption(string text,map<string,string>mp, int block)
{
    string res = "";
    int size = text.size();
    for(int i = 0; i < size; i += block)
    {
        string temp = text.substr(i, min(block,size - i));
        res = res + mp[temp];
    }
    return res;
}


int main()
{
    freopen("input", "r", stdin);  
    freopen("output", "w", stdout);
    string x, y, plain;
    cin>>plain;
    int block = 3;
    while(cin>>x>>y)
    {
        cipher_mp[x] = y;
        decipher_mp[y] = x;
    }

    string cipher_text = encryption_decryption(plain,cipher_mp,block);
    string decipher_text = encryption_decryption(cipher_text,decipher_mp,block);

    cout<<"Plain text : "<<plain<<endl;
    cout<<"Cipher text : "<<cipher_text<<endl;
    cout<<"Decipher text : "<<decipher_text<<endl;

}