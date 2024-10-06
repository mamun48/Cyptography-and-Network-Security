#include<bits/stdc++.h>
using namespace std;

string encryption(string text, int slide)
{
    string res = "";
    for(int i = 0; i < text.size(); i++)
    {
        char temp = text[i] + slide;
        if(!isalpha(temp)) temp -= 26;
        res.push_back(temp);
    }
    return res;
}

string decryption(string text, int slide)
{
    string res = "";
    for(int i = 0; i < text.size(); i++)
    {
        char temp = text[i] - slide;
        if(!isalpha(temp)) temp += 26;
        res.push_back(temp);
    }
    return res;
}

int main()
{
    string plain;
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    getline(cin,plain);
    int slide = 3;
    string cipher_text = encryption(plain,slide);
    string decipher_text = decryption(cipher_text, slide);

    cout<<"Plain text :   "<<plain<<endl;
    cout<<"Cipher text :  "<< cipher_text<<endl;
    cout<<"Decipher text: "<<decipher_text<<endl;
}