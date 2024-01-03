#include <iostream>
#include <thread>
#include <chrono>
#include <functional>

using namespace std;

// Ýþ zamanlamasý fonksiyonu
void isZamanlayici(function<void()> fonksiyon, int milisaniye) {
    // Belirtilen süre kadar beklemek için
    this_thread::sleep_for(std::chrono::milliseconds(milisaniye));
    // Bekleme süresi dolunca verilen fonksiyonu çaðýrmak
    fonksiyon();
}

int main() {
    // Örnek kullaným
    auto benimFonksiyonum = []() {
        cout << "Belirli bir süre sonra çalýþan iþlev!" << endl;
        };

    // Ýþ zamanlayýcýsýný bir fonksiyon ve 1000 milisaniye (1 saniye) bekleme süresi ile çaðýrma
    isZamanlayici(benimFonksiyonum, 1000);

    return 0;
}
