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
        cout << "1. Pridėti studentą\n";
        cout << "2. Rodyti visus studentus\n";
        cout << "3. Rodyti konkretaus studento pažymius\n";
        cout << "4. Atnaujinti studento pažymį\n";
        cout << "5. Pašalinti studentą\n";
        cout << "0. Išeiti\n";
        cout << "Pasirinkite veiksmą: ";
        cin >> pasirinkimas;
    
        switch (pasirinkimas){
            case 1:{
                if (studentuSk >= studentaimax) {
                    cout << "Pasiektas maksimalus studentų skaičius.\n";
                    break;
                }
                {
                 cout << "Įveskite studento vardą (be tarpų): ";
                 cin >> vardai[studentuSk];
                
                 cout << "Kiek pažymių norite įvesti (iki 10): ";
                 cin >> kiekPazymiu[studentuSk];
                 if (kiekPazymiu[studentuSk] > maxpazymiai)
                     kiekPazymiu[studentuSk] = maxpazymiai;
                for (int j = 0; j < kiekPazymiu[studentuSk]; j++) {
                    cout << "Pažymys " << j + 1 << ": ";
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
                cout << "Įveskite studento vardą: ";
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
                cout << "Įveskite studento vardą: ";
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
                cout << "Įveskite pažymio numerį, kurį norite pakeisti: ";
                cin >> nr;
                if (nr < 1 || nr > kiekPazymiu[rasvard]){
                    cout << "Neteisingas pažymio numeris.\n";
                }else {
                    cout << "Įveskite naują pažymį: ";
                    cin >> pazymiai[rasvard][nr - 1];
                    cout << "Pažymys atnaujintas.\n";
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
                cout << "Įveskite studento vardą, kurį norite pašalinti: ";
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
            cout << "Studentas pašalintas.\n";
        }
                break;
            }

            case 0:
                cout << "Išeinama iš programos.\n";
                break;
            default:
             cout << "Neteisingas pasirinkimas.\n";
                break;
    }
    } while (pasirinkimas != 0);
}