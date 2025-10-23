#include <iostream>
using namespace std;

const int studentaimax = 100;
const int maxpazymiai = 10;
const int maxvardas = 51;

int main(){
    char vardai [studentaimax] [maxvardas];
    int pazymiai [studentaimax][maxpazymiai];
    int kiekPazymiu [studentaimax];
    int studentuSk = 0;

    int pasirinkimas;
    
    
    do {
        cout << "1. Prideti studenta"<<endl;
        cout << "2. Rodyti visus studentus"<<endl;
        cout << "3. Rodyti konkretaus studento pazymius"<<endl;
        cout << "4. Atnaujinti studento pazymi"<<endl;
        cout << "5. Pasalinti studenta"<<endl;
        cout << "0. Iseiti"<<endl;
        cout << "Pasirinkite veiksma:"<<endl;
        cin >> pasirinkimas;
    
        switch (pasirinkimas){
            case 1:{
                if (studentuSk >= studentaimax) {
                    cout << "Pasiektas maksimalus studentu skaicius.\n";
                    break;
                }
                {
                 cout << "Iveskite studento varda: ";
                 cin >> vardai[studentuSk];
                
                 cout << "Kiek pažymių norite ivesti (iki 10): ";
                 cin >> kiekPazymiu[studentuSk];
                 if (kiekPazymiu[studentuSk] > maxpazymiai)
                     kiekPazymiu[studentuSk] = maxpazymiai;
                for (int j = 0; j < kiekPazymiu[studentuSk]; j++) {
                    cout << "Pazymys " << j + 1 << ": ";
                    cin >> pazymiai[studentuSk][j];
                }
            }
                studentuSk++;

                break;
            }
            case 2:{
                if (studentuSk == 0){
                    cout << "studentu nerasta" <<endl;
                }else {
                    cout << "visi studentai: " <<endl;
                    for (int i = 0; i < studentuSk; i++){
                        cout << vardai[i] << " : ";
                        for (int j = 0; j < kiekPazymiu[i]; j++) {
                            cout << pazymiai[i][j] << " ";
                        }
                        cout << endl;
                    }
                }
                break;

            }
            case 3:{
                if (studentuSk == 0){
                    cout << "studentu nerasta" <<endl;
                    break;
                }
                char vardas[maxvardas];
                cout << "Iveskite studento varda: ";
                cin >> vardas;
                int rasvard = -1;
                for (int i = 0; i < studentuSk; i++){
                    int vienod = 1;
                    for (int k = 0; vardai[i][k] != '\0' || vardas[k] != '\0'; k++){
                        if (vardai[i][k] != vardas[k]){
                            vienod = 0;
                            break;
                        }
                    }
                    if (vienod == 1){
                        rasvard = i;
                        break;
                    }
            }
            if (rasvard == -1){
                cout<<"studentas nerastas" << endl;
            }else {
                cout<< vardai[rasvard] << " pazymiai: ";
                for (int j = 0; j < kiekPazymiu[rasvard]; j++){
                    cout << pazymiai[rasvard][j] << " ";
            }
                cout << endl;
            }
                break;
            }
            case 4:{
                if (studentuSk == 0){
                    cout << "studentu nerasta" <<endl;
                    break;
                }
                char vardas[maxvardas];
                cout << "Iveskite studento varda: ";
                cin >> vardas;
                int rasvard = -1;
                for (int i = 0; i < studentuSk; i++){
                    int vienod = 1;
                    for (int k = 0; vardai[i][k] != '\0' || vardas[k] != '\0'; k++){
                        if (vardai[i][k] != vardas[k]){
                            vienod = 0;
                            break;
                        }
                    }
                    if (vienod == 1){
                        rasvard = i;
                        break;
                    }
            }
            if (rasvard == -1){
                cout<<"studentas nerastas" << endl;
            }else {
                cout<< vardai[rasvard] << " pazymiai: " << endl;
                for (int j = 0; j < kiekPazymiu[rasvard]; j++){
                    cout << j + 1 << ". " << pazymiai[rasvard][j] <<endl;
            }
                int nr;
                cout << "Iveskite pazymio numeri, kuri norite pakeisti: ";
                cin >> nr;
                if (nr < 1 || nr > kiekPazymiu[rasvard]){
                    cout << "Neteisingas pazymio numeris.\n";
                }else {
                    cout << "Iveskite nauja pazymi: ";
                    cin >> pazymiai[rasvard][nr - 1];
                    cout << "Pazymys atnaujintas.\n";
                }
            }
                break;
            }
            case 5:{
                if (studentuSk == 0){
                    cout << "studentu nerasta" <<endl;
                    break;
                }
                char vardas[maxvardas];
                cout << "Iveskite studento varda, kuri norite pasalinti: ";
                cin >> vardas;
                int rasvard = -1;
                for (int i = 0; i < studentuSk; i++){
                    int vienod = 1;
                    for (int k = 0; vardai[i][k] != '\0' || vardas[k] != '\0'; k++){
                        if (vardai[i][k] != vardas[k]){
                            vienod = 0;
                            break;
                        }
            }
            if (vienod == 1){
                rasvard = i;
                break;
            }
        }
        if (rasvard == -1){
            cout<<"studentas nerastas" << endl;
        }else {
            for (int i = rasvard; i < studentuSk - 1; i++){
                for (int k = 0; vardai[i][k] != '\0'; k++){
                    vardai[i][k] = vardai[i + 1][k];
                }
                kiekPazymiu[i] = kiekPazymiu[i + 1];
                for (int j = 0; j < kiekPazymiu[i]; j++){
                    pazymiai[i][j] = pazymiai[i + 1][j];
                }
            }
            studentuSk--;
            cout << "Studentas pasalintas.\n";
        }
                break;
            }

            case 0:
                cout << "Iseinama is programos.\n";
                break;
            default:
             cout << "Neteisingas pasirinkimas.\n";
                break;
    }
    } while (pasirinkimas != 0);
    return 0;
}
