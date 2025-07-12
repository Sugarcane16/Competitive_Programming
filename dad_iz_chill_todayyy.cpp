// Instead of integer, record the binary representation of a long long number.
//Ok. Continue, cindia i mean adele
/*
duz it making sense?
yeaa last 1 bit not the last bit the last ONE BIT.
AGAIN THIS IS THE BIT OPERATION
ITS 
VERY
VERY
VERY FOST
MAKIN SENSE??
1. SHOW THE BINARY REPRESENTATION OF A LONG LONG :P
2. TELL ME IF DA NUMBER IZ A 2^smth :D
MAKIN SWENCE!!!?
p.s. the long long iz the input, ok? its the input

haiku:
dear dad, you exist
dad iz vewy chill 2day
long live c++
*/
#include <iostream>
using namespace std;

int main(){
    cout << "pip iz da sparkly glitter noodl wif bad spelling :D" << endl;
    long long chaoticNumber;
    cout << "pip hath commandeth thee to inputteth the chaotic numberTM: " << endl;
    cin >> chaoticNumber;
    cout << "beholde!! pip haz come up wif da binury repwezentashun of da chaotic numberTM: " << endl;
    int chaoticSize = sizeof(chaoticNumber);
    cout << "just 4 debuggin perpose pip declare chaotic size of da chaotic numba to be da " << chaoticSize << endl;
    for (int i = (chaoticSize << 3) - 1; i >= 0; i--) {
        long long angryCarrots = 1;
        if (chaoticNumber&(angryCarrots<<i)) cout << "1";
        else cout << "0";
    }
    cout << endl;
    if ((chaoticNumber&(chaoticNumber-1))==0){
        cout << "ooki pip's holy virdect iz dat ur chaotic number iz da sparkly power of twooo!! :)" << endl;
        cout << "pip added glitter~" << endl;
    } else{
        cout << "pip sez dat ur chaotic number iz not powa of 2 :(" << endl;
        cout << "but pip added glitter anywayz!!" << endl;
        cout << "welp itz sentient pankayk noww" << endl;
    }
    cout << "yay! fank u 4 testing out pip's binary machine! u r glittery now :D" << endl;
    return 0;
}
