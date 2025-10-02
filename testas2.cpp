#include <iostream>
using namespace std;


int main(){
    int eur = 1;
    double GBP_Bendras  = 0.8729;
    double GBP_Pirkti   = 0.8600;
    double GBP_Parduoti = 0.9220;
    double USD_Bendras  = 1.1793;
    double USD_Pirkti   = 1.1460;
    double USD_Parduoti = 1.2340;
    double INR_Bendras  = 104.6918;
    double INR_Pirkti   = 101.3862;
    double INR_Parduoti = 107.8546;
    string val = "laba";
    int kiek = 0;
    int a;
    
    double sum = 0.00;
    while (true)
    {
        cout<<"Ka noretumete veikti ?"<<endl<<"1. Valiutos kurso palyginimas su kita valiuta.\n2. Įsigyti valiutos.\n3.Pparduoti valiutą. \nJusu pasirinkimas: "; cin>>a;
        switch (a){
            case 1:
                cout<<"Iveskite kieki:\n"; cin>>kiek;
                cout<<"Su kuo noretumete palyginti ? (USD, GBP, INR):\n"; cin>>val;
                if (val == "USD" || val == "usd"){
                    sum = kiek*USD_Bendras;
                }else if (val == "GBP" || val == "gbp"){
                    sum = kiek*GBP_Bendras;
                }else if (val == "INR" || val == "inr"){
                    sum = kiek*INR_Bendras;
                }else{
                    cout<<"Ivedete neteisingus duomenis"<<endl;
                }
                printf("Palyginus bus %.2f", sum );cout<<val<<"\n";
                break;
            case 2:
                cout<<"Kokia suma nureetumete isisgyti:\n"; cin>>kiek;
                cout<<"Ka noretumete isigyti ? (USD, GBP, INR):\n"; cin>>val;
                if (val == "USD" || val == "usd"){
                    sum = kiek*USD_Pirkti;
                }else if (val == "GBP" || val == "gbp"){
                    sum = kiek*GBP_Pirkti;
                }else if (val == "INR" || val == "inr"){
                    sum = kiek*INR_Pirkti;
                }else{
                    cout<<"Ivedete neteisingus duomenis"<<endl;
                }
                printf("Jus gausite %.2f", sum );cout<< val<<"\n";
                break;
            case 3:
                cout<<"Kokia suma nuretumete parduoti:\n"; cin>>kiek;
                cout<<"Ka noretumete parduoti ? (USD, GBP, INR):\n"; cin>>val;
                if (val == "USD" || val == "usd"){
                    sum = kiek*USD_Parduoti;
                }else if (val == "GBP" || val == "gbp"){
                    sum = kiek*GBP_Parduoti;
                }else if (val == "INR" || val == "inr"){
                    sum = kiek*INR_Parduoti;
                }else{
                    cout<<"Ivedete neteisingus duomenis"<<endl;
                }
                cout<<"Pardavus "<<kiek<<" "<<val;
                printf(" jus gausite %.2f", sum);cout<<" EUR"<<endl;
                break;
            default:
                    cout<<"\nDuomenys netinkami bandykite dar karta\n"<<endl;
                    break;
                }

    }
}