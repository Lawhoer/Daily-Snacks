#include <iostream>
#include <thread>
#include <chrono>
#include <functional>

using namespace std;

// �� zamanlamas� fonksiyonu
void isZamanlayici(function<void()> fonksiyon, int milisaniye) {
    // Belirtilen s�re kadar beklemek i�in
    this_thread::sleep_for(std::chrono::milliseconds(milisaniye));
    // Bekleme s�resi dolunca verilen fonksiyonu �a��rmak
    fonksiyon();
}

int main() {
    // �rnek kullan�m
    auto benimFonksiyonum = []() {
        cout << "Belirli bir s�re sonra �al��an i�lev!" << endl;
        };

    // �� zamanlay�c�s�n� bir fonksiyon ve 1000 milisaniye (1 saniye) bekleme s�resi ile �a��rma
    isZamanlayici(benimFonksiyonum, 1000);

    return 0;
}
