// Hotellivaraus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstdio>
#include <conio.h>

int huoneet();   //nimet‰‰n alifunktiot
int tarkistus(int kh);
int syotto(int a);
int Vsyotto(int a);
int Ysyotto(int a);
float hinta(float a, float b, float c, float d);


int main()
{
    using std::cout;
    using std::cin;
    int kh = 1; //alustetaan muuttuja kahden hengen huoneille
    kh = tarkistus(kh); //suoritetaan tarkistus kahden hengen huoneille, jotta saadaan parillinen arvottu luku
    int yh = kh / 2; //saadaan yhdelle hengelle sopivien huoneiden lukum‰‰r‰
    int yhmax = 5; //alustetaan maksimi m‰‰r‰t varattavia huoneita
    int khmax = 3; 
    int yhkpl = 0; //alustetaan hinnan lasketaan varten muuttujat
    int khkpl = 0; 
    int yht[5]; //muodostetaan arrayt huoneiden numeroiden tallentamista varten
    int kht[3];
    int yo{ 0 }; //alustetaan ˆiden m‰‰r‰t
    int kyo{ 0 };

    bool varaus{ true };
    
    do
    {
       
        int komento{ 0 };
        cout << "Tervetuloa. Voit valita viel‰ " << khmax << " kahden hengen huonetta ja " << yhmax << " yhden hengen huonetta.\n";
        if (yhmax == 0 && khmax == 0) { //tarkastetaan onko varattavia huoneita j‰ljell‰
            cout << "Et voi varata enemp‰‰ huoneita, siirry kassalle. \n";//jos ei ole, kehotetaan siirtym‰‰n kassalle.
        }
        cout << "Valitse vaihtoehdoista: \n1. Yhden hengen huone \n2. Kahden hengen huone \n3. Lista varatuista huoneista \n4. Kassa\n";
        std::string temp; //pyydet‰‰n k‰ytt‰j‰n syˆttˆ string, jotta voidaan tehd‰ syˆtˆn tarkistus.
        getline(cin, temp);
        std::istringstream ss(temp); ss >> komento;//k‰‰nnet‰‰n string arvo integer arvoksi, koska komennot ovat kaikki numeroita.
        switch (syotto(komento)) {
        case 1:
        {int komento{ 0 }; }
        if (yhmax > 0) { //tarkastetaan voiko huone tyyppi‰ viel‰ varata
            cout << "Valitsit yhden hengen huoneen.\nHaluatko itse valita huoneen?\n1. Valitse itse\n2. Valitsemme puolestasi\n"; //jos voi kysyt‰‰n haluaako k‰ytt‰j‰ itse varata huoneen vai antaako koneen valita huoneen
            std::string temp; //pyydet‰‰n k‰ytt‰j‰n syˆttˆ string, jotta voidaan tehd‰ syˆtˆn tarkistus.
            getline(cin, temp);
            std::istringstream ss(temp); ss >> komento; //k‰‰nnet‰‰n string arvo integer arvoksi, koska komennot ovat kaikki numeroita.
            if (Vsyotto(komento) == 1) {
                int numero{ 0 };
                cout << "Voit valita huoneen v‰lilt‰ 1 - " << yh-1 << " \n";
                cout << "Anna haluamasi huoneen numero: \n";
                std::string temp; //pyydet‰‰n k‰ytt‰j‰n syˆttˆ string, jotta voidaan tehd‰ syˆtˆn tarkistus.
                getline(cin, temp);
                std::istringstream ss(temp); ss >> numero; //k‰‰nnet‰‰n string arvo integer arvoksi, koska komennot ovat kaikki numeroita.
                auto etsi = std::find(std::begin(yht), std::end(yht), numero); //k‰ytet‰‰n find komentoa, jotta voidaan tarkistaa onko huoneen numero jo varattu.
                if (numero > 1 && numero < yh && etsi != std::end(yht)) {
                    cout << "olet jo varannut t‰m‰n huoneen. \n";
                    cout << "Paina entteri‰ jatkaaksesi";
                    _getch();
                    system("cls");
                    break;
                }
                else if (numero > 1 && numero < yh) {
                    cout << "Varaamasi huone on " << numero << " \n";
                    yhmax -= 1;  //v‰hennet‰‰n yksi varattavien huoneiden m‰‰r‰st‰
                    yht[yhkpl] = numero; //tallennetaan annettu numero arrayhyn, jossa on tallessa varatut huoneet
                    yhkpl += 1; //lis‰t‰‰n yksi varattujen huoneiden m‰‰r‰‰n
                    cout << "Paina entteri‰ jatkaaksesi";
                    _getch();
                    system("cls");
                    break;
                }
                else
                cout << "Virheellinen syˆttˆ, varaa huone uudelleen. \n";
                cout << "Paina entteri‰ jatkaaksesi";
                _getch();
                system("cls");
                break;

            }
            if (Vsyotto(komento) == 2) {
            int a = rand() % yh + 1; //muodostetaan printattava arvo jossa on yl‰raja arvolle, jonka kone valitsee itse
            auto etsi = std::find(std::begin(yht), std::end(yht), a); //k‰ytet‰‰n find komentoa, jotta voidaan tarkistaa onko huoneen numero jo varattu.
            if (a > 1 && a < yh && etsi != std::end(yht)) {
                cout << "olet jo varannut t‰m‰n huoneen. \n";
                cout << "Paina entteri‰ jatkaaksesi";
                _getch();
                system("cls");
                break;
            }
            else
                cout << "varaamasi huone on " << a << "\n";
                yhmax -= 1; //v‰hennet‰‰n yksi varattavien huoneiden m‰‰r‰st‰
                yht[yhkpl] = a; //tallennetaan annettu numero arrayhyn, jossa on tallessa varatut huoneet
                yhkpl += 1; //lis‰t‰‰n yksi varattujen huoneiden m‰‰r‰‰n
                cout << "Paina entteri‰ jatkaaksesi.";
                _getch();
                system("cls");
                break;
            }
            if (Vsyotto(komento) > 2) {
                cout << "Virheellinen syˆttˆ, varaa huone uudelleen. \n";
                cout << "Paina entteri‰ jatkaaksesi";
                _getch();
                system("cls");
                break;
            }
        }
        else
        cout << "Et voi varata enemp‰‰ yhden hengen huoneita \n";
        cout << "Paina entteri‰ jatkaaksesi";
        _getch();
        system("cls");
        break;
        case 2:
        {int komento{ 0 }; }
        if (khmax > 0) {
            cout << "Valitsit kahden hengen huoneen.\nHaluatko itse valita huoneen?\n1. Valitse itse\n2. Valitsemme puolestasi \n";
            std::string temp; //pyydet‰‰n k‰ytt‰j‰n syˆttˆ string, jotta voidaan tehd‰ syˆtˆn tarkistus.
            getline(cin, temp);
            std::istringstream ss(temp); ss >> komento; //k‰‰nnet‰‰n string arvo integer arvoksi, koska komennot ovat kaikki numeroita.
            if (Vsyotto(komento) == 1) {
                int numero{ 0 };
                cout << "Voit valita huoneen v‰lilt‰ " << yh << " - "<< kh;
                cout << " Anna haluamasi huoneen numero: \n";
                std::string temp; //pyydet‰‰n k‰ytt‰j‰n syˆttˆ string, jotta voidaan tehd‰ syˆtˆn tarkistus.    
                getline(cin, temp);
                std::istringstream ss(temp); ss >> numero; //k‰‰nnet‰‰n string arvo integer arvoksi, koska komennot ovat kaikki numeroita.
                auto etsi = std::find(std::begin(kht), std::end(kht), numero); //k‰ytet‰‰n find komentoa, jotta voidaan tarkistaa onko huoneen numero jo varattu.
                if (numero > yh && numero < kh && etsi != std::end(kht)) {
                    cout << "olet jo varannut t‰m‰n huoneen. \n";
                    cout << "Paina entteri‰ jatkaaksesi";
                    _getch();
                    system("cls");
                    break;
                }
                else if (numero > yh && numero < kh) {
                    cout << "Varaamasi huone on " << numero << " \n";
                    khmax -= 1;  //v‰hennet‰‰n yksi varattavien huoneiden m‰‰r‰st‰
                    kht[khkpl] = numero; //tallennetaan annettu numero arrayhyn, jossa on tallessa varatut huoneet
                    khkpl += 1; //lis‰t‰‰n yksi varattujen huoneiden m‰‰r‰‰n
                    cout << "Paina entteri‰ jatkaaksesi";
                    _getch();
                    system("cls");
                    break;
                }
                else
                    cout << "Virheellinen syˆttˆ, varaa huone uudelleen. \n";
                cout << "Paina entteri‰ jatkaaksesi";
                _getch();
                system("cls");
                break;

            }
            if (Vsyotto(komento) == 2) {
                int b = (rand() % (kh - yh + 1)) + yh; //muodostetaan printattava arvo jossa on yl‰ ja alarajat arvolle, jonka kone valitsee itse
                auto etsi = std::find(std::begin(kht), std::end(kht), b); //k‰ytet‰‰n find komentoa, jotta voidaan tarkistaa onko huoneen numero jo varattu.
                if (b > yh && b < kh && etsi != std::end(kht)) {
                    cout << "olet jo varannut t‰m‰n huoneen. \n";
                    cout << "Paina entteri‰ jatkaaksesi";
                    _getch();
                    system("cls");
                    break;
                }
                else
                cout << "varaamasi huone on " << b << " \n";
                khmax -= 1; //v‰hennet‰‰n yksi varattavien huoneiden m‰‰r‰st‰
                kht[khkpl] = b; //tallennetaan annettu numero arrayhyn, jossa on tallessa varatut huoneet
                khkpl += 1; //lis‰t‰‰n yksi varattujen huoneiden m‰‰r‰‰n
                cout << "Paina entteri‰ jatkaaksesi";
                _getch();
                system("cls");
                break;
            }
            if (Vsyotto(komento) > 2) {
                cout << "Virheellinen syˆttˆ, varaa huone uudelleen. \n";
                cout << "Paina entteri‰ jatkaaksesi";
                _getch();
                system("cls");
                break;
            }
        }
        else
            cout << "Et voi varata enemp‰‰ kahden hengen huoneita \n";
        cout << "Paina entteri‰ jatkaaksesi";
        _getch();
        system("cls");
        break;
        case 3:
            cout << "Varaamasi yhden hengen huoneet ovat \n"; //printataan huoneiden lista
            for (int i : yht) {
                if (i <= yh && i >= 1)
                    cout << i << " \n";
            }
            cout << "Varaamasi kahden hengen huoneet ovat \n"; //printataan kahden hengen huoneiden lista
            for (int i : kht) {
                if (i <= kh && i >= 1)
                    cout << i << " \n";
            }
            cout << "Paina entteri‰ jatkaaksesi";
            _getch();
            system("cls");
            break;
        case 4: 
        {
           
            if (yhkpl > 0 && khkpl > 0) {
                cout << "Anna yhden hengen huoneiden ˆiden m‰‰r‰: ";
                std::string temp; //pyydet‰‰n k‰ytt‰j‰n syˆttˆ string, jotta voidaan tehd‰ syˆtˆn tarkistus.    
                getline(cin, temp);
                std::istringstream ss(temp); ss >> yo; //k‰‰nnet‰‰n string arvo integer arvoksi, koska komennot ovat kaikki numeroita.
                if (Ysyotto(yo) > 0) {
                    cout << "Anna kahden hengen huoneiden ˆiden m‰‰r‰: ";
                    std::string temp2; //pyydet‰‰n k‰ytt‰j‰n syˆttˆ string, jotta voidaan tehd‰ syˆtˆn tarkistus.    
                    getline(cin, temp2);
                    std::istringstream aa(temp2); aa >> kyo; //k‰‰nnet‰‰n string arvo integer arvoksi, koska komennot ovat kaikki numeroita.
                }
                if (Ysyotto(kyo) > 0) {
                    cout << "Paina entteri‰ jatkaaksesi";
                    _getch();
                    varaus = false;
                    system("cls");
                    break;
                }
            }
            else if (yhkpl > 0 && khkpl < 1) {
                cout << "Anna yhden hengen huoneiden ˆiden m‰‰r‰: ";
                std::string temp; //pyydet‰‰n k‰ytt‰j‰n syˆttˆ string, jotta voidaan tehd‰ syˆtˆn tarkistus.    
                getline(cin, temp);
                std::istringstream ss(temp); ss >> yo; //k‰‰nnet‰‰n string arvo integer arvoksi, koska komennot ovat kaikki numeroita.
                if (Ysyotto(yo) > 0) {
                    cout << "Paina entteri‰ jatkaaksesi";
                    _getch();
                    varaus = false;
                    system("cls");
                    break;
                }

            }
            else if (yhkpl < 1 && khkpl > 0) {
                cout << "Anna kahden hengen huoneiden ˆiden m‰‰r‰: ";
                std::string temp2; //pyydet‰‰n k‰ytt‰j‰n syˆttˆ string, jotta voidaan tehd‰ syˆtˆn tarkistus.    
                getline(cin, temp2);
                std::istringstream aa(temp2); aa >> kyo; //k‰‰nnet‰‰n string arvo integer arvoksi, koska komennot ovat kaikki numeroita.
                if (Ysyotto(kyo) > 0) {
                    cout << "Paina entteri‰ jatkaaksesi";
                    _getch();
                    varaus = false;
                    system("cls");
                    break;
                }
            }
            else if (yhkpl == 0 && khkpl == 0) { //tulostetaan virheellisiss‰ tapauksissa virhe teksti
                cout << "Et ole valinnut yht‰k‰‰n huonetta. Valitse v‰hint‰‰n yksi huone ennen siirtymist‰ kassalle.\n";
                cout << "Paina entteri‰ jatkaaksesi";
                _getch();
                system("cls");
                break;
            }

            else if (Ysyotto(kyo) == 0 || Ysyotto(yo) == 0) { //tulostetaan virheellisiss‰ tapauksissa virhe teksti
                cout << "Virheellinen syˆttˆ, muista antaa ˆiden m‰‰r‰ numerona. \n";
                cout << "Paina entteri‰ jatkaaksesi";
                _getch();
                system("cls");
                break;
            }
        }
        case 5: //t‰m‰ tapaus kutsutaan, jos syˆttˆ on virheellinen heti alussa
            cout << "Paina entteri‰ jatkaaksesi";
            _getch();
            system("cls");
            break;
        }
        
    } while (varaus);
    cout << "Varaamiesi huoneiden hinta on " << hinta(yo, kyo, yhkpl, khkpl) << " euroa.";
}
   

int huoneet() //aliohjelma luo satunnaisesti luvun 40-300
{
    std::random_device rd;
    std::default_random_engine moottori{ rd() };
    std::uniform_int_distribution aivo{ 40, 300 };
    return (aivo(moottori));
}
int tarkistus(int a) //aliohjelma kutsuu toista aliohjelmaa, kunnes luku on parillinen
{
    while (-1) {
        
        if (a % 2 == 0)
            break;
        else
            a = huoneet();
    }
    return (a);
}
int syotto(int a) //Aliohjelma tarkistaa syˆtˆn
{
    int b{ 0 };
    if (a == 1 || a == 2 || a == 3 || a == 4){
        return(a);
}
    else {
        std::cout << "Virheellinen syˆttˆ, anna valinta uudestaan v‰lilt‰ 1-4. \n";
        int b = 5;
        return (b);
    }
}
int Vsyotto(int a) //Aliohjelma tarkistaa syˆtˆn
{
    int b{ 0 };
    if (a == 1 || a == 2) {
        return(a);
    }
    else {
        int b = 3;
        return (b);
    }
}
int Ysyotto(int a) //Aliohjelma tarkistaa syˆtˆn
{
    int b{ 0 };
    if (a > 0) {
        return(a);
    }
    else {
        int b = 0;
        return (b);
    }
}
float hinta(float a, float b, float c, float d) //Aliohjelma arpoo satunnaisesti alennuksen 0%, 10%, 20% arvoista
{
    float alennukset[3] = { 0, 0.10, 0.20 };
    srand(time(NULL));
    int RandIndex = rand() % 3;
    float e = (100 * a)*c + (150 * b)*d;
    float alennus = e * alennukset[RandIndex];
    float yhteishinta = e - alennus;
    return (yhteishinta);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file