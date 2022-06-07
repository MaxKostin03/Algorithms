

#include<iostream>
#include<string>
using namespace std;




void inline Task1(){
int i = 0, k;
    char Alphabet[] = { 'a','b','c','d','e','f','g','h','i',
                        'j','k','l','m','n','o','p','q','r',
                        's','t','u','v','w','x','y','z',
                        '_','.',',',
                        '0', '1','2','3','4','5','6','7','8','9' };
    char message[30];
    cout << "Enter secret message: " << endl;
    cin.getline(message, 30);
    cout << "Enter shift:" << endl;
    cin >> k;
    char* begin = Alphabet;
    char* end = Alphabet + sizeof(Alphabet);
    for (size_t i = 0; message[i]; ++i) {
        char* ch = find(begin, end, message[i]);
        if (ch != end) message[i] = *(begin + (ch - begin + k) % sizeof(Alphabet));
    }
    cout << "Coded message: " << endl;
    cout << message << endl;
    for (size_t i = 0; message[i]; ++i) {
        char* ch = find(begin, end, message[i]);
        if (ch != end) message[i] = *(begin + (ch - begin - k) % sizeof(Alphabet));
    }
    cout << "Decoded message: " << endl;
    cout << message << endl;
}

char* shuffle(char* in, int key, int encrypt) {
    int l = strlen(in);
    if (l == 0) {
        return NULL;
    }
    const int len = key * (1 + ((l - 1) / key));
    char* out = (char*)malloc(sizeof(char) + len);
    if (encrypt == 0)  {
        key = len / key;
    }
    int idx = 0;
    for (int i = 0; i < key; i++) {
        for (int j = i; j < len; j += key) {
            out[idx++] = (*(in + j)) ? *(in + j) : (char) 'x';
        }
    }
    out[len] = 0;
    return out;
}

void inline Task2() {
    char message[30];
    cout << "Enter secret message: " << endl;
    cin.getline(message, 30);
    char* s_encrypt = shuffle(message, 6, 1);
    cout << "Coded message: " << endl;
    cout << s_encrypt << endl;
    char* s_decrypt = shuffle(s_encrypt, 6, 0);
    cout << "Decoded message: " << endl;
    cout << s_decrypt << endl;
}

int main()
{
    
    Task1();
    Task2();
    return 0;
}
