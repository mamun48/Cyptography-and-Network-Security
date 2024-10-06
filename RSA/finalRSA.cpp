#include <bits/stdc++.h>
using namespace std;
vector<int> plain;
vector<int> cipher;

int exp_mod(int x, int y, int p)
{
    int res = 1;
    while (y--)
    {
        res = (res * x) % p;
    }
    return res;
}

vector<int> encryption_decryption(vector<int> plain, int e, int n)
{
    vector<int> result;
    for (int m : plain)
    {
        result.push_back(exp_mod(m, e, n));
    }
    return result;
}

int main()
{
    string input;
    int e, d, n;
    cin >> e >> d >> n;
    //freopen("inputRSA.txt", "r", stdin);
    cin >> input;

    cout<<e<<endl<<d<<endl<<n<<endl<<input<<endl;

    string temp = to_string(n);
    int size = temp.size() - 1;
    int len = input.size();

    string t;

    cout << input << endl;
    for (int i = 0; i < len; i += size)
    {
        t = input.substr(i, min(size, len - i));
        plain.push_back(stoi(t));
    }
    cipher = encryption_decryption(plain, e, n);
    vector<int> decipher = encryption_decryption(cipher, d, n);
    for (auto x : cipher)
    {
        cout << x;
    }
    cout << endl;
    for (auto x : decipher)
    {
        cout << x;
    }
}