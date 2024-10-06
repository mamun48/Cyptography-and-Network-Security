#include <bits/stdc++.h>
using namespace std;

string encryption(string plain, string pad)
{
    string res = plain;
    int idx = 0;
    for (int i = 0; i < plain.size(); i++)
    {
        if (isalpha(plain[i]))
        {
            res[i] = (((plain[i] - 'a') + (pad[idx++] - 'a') + 1) % 26) + 'a';
        }
        else
        {
            res[i] = plain[i];
        }
    }
    return res;
}

string decryption(string text, string pad)
{
    string res = text;
    int idx = 0;
    for (int i = 0; i < text.size(); i++)
    {
        if (isalpha(text[i]))
        {
            res[i] = (((text[i] - 'a') - (pad[idx++] - 'a') + 25) % 26) + 'a';
        }else{
             res[i] = text[i];
    }
        }
       
    return res;
}

int main()
{
    string pad, plain;
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    getline(cin, pad);
    getline(cin, plain);

    string cipher_text = encryption(plain, pad);
    string decipher_text = decryption(cipher_text, pad);

    cout << cipher_text << endl;
    cout << decipher_text;
}