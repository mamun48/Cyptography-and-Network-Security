#include<bits/stdc++.h>
using namespace std;

string encryption(string text, int width)
{
    string cipher = "";
    for(int i = 0; i < width; i++)
    {
        for(int j = i; j < text.size(); j += width)
        {
            cipher.push_back(text[j]);
        }
    }
    return cipher;
}

string decryption(string text, int width)
{
    string decipher(text.size(),'.');
    int idx = 0;
    for(int i = 0; i < width; i++)
    {
        for (int j = i; j < text.size(); j += width)
        {
            decipher[j] = text[idx++];
        }  
    }
    return decipher;
}

int main()
{
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    int width = 5;
    string plain;
    getline(cin,plain);

    cout<<plain<<endl;
    string cipher_text = encryption(plain,width);
    cout<<"Cipher text : "<<cipher_text<<endl;
    string double_cipher_text = encryption(cipher_text,width);
    cout<<"Double Cipher text : "<<double_cipher_text<<endl;


    string decipher_text1 = decryption(double_cipher_text,width);
    cout<<"Decipher text : "<<decipher_text1<<endl;

    string decipher_text2 = decryption(decipher_text1,width);
    cout<<"Decipher text : "<<decipher_text2<<endl;

}