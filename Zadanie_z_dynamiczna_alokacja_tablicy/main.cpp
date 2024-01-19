#include <iostream>
#include <fstream>
using namespace std;

int Menu()
{
    int x;
    cout<<endl;
    cout<<"1. Dodaj element tablicy"<<endl;
    cout<<"2. Wstaw element tablicy"<<endl;
    cout<<"3. Usun element tablicy"<<endl;
    cout<<"4. Wyœwietl elementy tablicy"<<endl;
    cout<<"5. Zapisz do pliku"<<endl;
    cout<<"6. Wczytaj z pliku"<<endl;
    cout<<"7. Wyjscie z programu"<<endl;
    cin>>x;
    cout<<endl;
    return x;
}

int main()
{
    int m;
    int *p = NULL;
    int n = 0;
    while(true)
    {
        m = Menu();
        switch(m)
        {
        case 7:
            {
                return 0;
            }
        case 1:
            {
                int * tmp = NULL;
                tmp = new int[n+1];
                if(p != NULL)
                {
                    for(int i=0;i<n;i++)
                    {
                        tmp[i] = p[i];
                    }
                    delete[] p;

                }
                cout<<"Podaj wartosc elementu tablicy: ";
                cin>>tmp[n];  //wstaw now¹ wartoœæ do tablicy (na koniec)
                p = tmp; //przekopiuj adres nowej tablicy do wskaŸnika p
                n++; //zwiêksz iloœæ elementów tablicy o 1
                break;
            }
        case 2:
            {
                //wstawienie elementu w dowolne miejsce
                int index;
                int a;
                cout <<"Podaj index w jaki chcesz wstawic element: ";
                cin>>index;
                cout<<"Podaj wartosc elementu tablicy: ";
                cin>> a;

                int * tmp = NULL;
                tmp = new int[n+1];
                if(p != NULL)
                {
                    for(int i=0;i<index;i++)
                    {
                        tmp[i] = p[i];
                    }
                    tmp[index] = a;
                    for(int i=index;i<n;i++)
                    {
                        tmp[i+1] = p[i];
                    }


                }

                    delete[] p;


                p = tmp; //przekopiuj adres nowej tablicy do wskaŸnika p
                n++; //zwiêksz iloœæ elementów tablicy o 1
                break;
            }
        case 3:
            {
                //usuwanie dowolnego elementu (po indeksie)
                cout <<"Podaj index elementu, ktory chcesz usunac (pierwszy element tablicy ma index 0): ";
                int index;
                cin>>index;
                int * tmp = NULL;
                tmp = new int[n-1];
                if(p != NULL) //je¿eli istnieje poprzednia tablica to:
                {
                    for(int i=0, j = 0; i<n;i++)
                    {
                        if (i != index)
                        {
                            tmp[j] = p[i];
                            j++;
                        }

                    }
                    //usuñ poprzedni¹ tablicê
                    delete[] p;

                }

                p = tmp; //przekopiuj adres nowej tablicy do wskaŸnika p
                n--;
                break;
            }
        case 4:
            {
                cout<<"Zawartosc tablicy:"<<endl;
                for(int i=0;i<n;i++)
                {
                    cout<<p[i]<<", ";
                }
                cout<<endl;
                break;
            }
        case 5:
            {
            ofstream plik("dane.txt");

            if (plik.is_open()) {
                cout << "Zawartosc tablicy zostala wpisana do pliku." << endl;

                plik << n << " ";

                for (int i = 0; i < n; i++) {
                    plik << p[i] << " ";
                }

                plik.close();
            } else {
                cout << "Blad otwarcia pliku do zapisu." << endl;
            }
            break;
                }

        case 6:
            {
             // Wczytaj z pliku
            ifstream plik("dane.txt");
            if (plik.is_open()) {
                cout << "Zawartosc tablicy zostala odczytana z pliku." << endl;

                if (!(plik >> n)) {
                    cout << "Blad odczytu rozmiaru tablicy z pliku." << endl;
                    plik.close();
                    return 1;
                }

                delete[] p;
                p = new int[n];

                for (int i = 0; i < n; i++) {
                    if (!(plik >> p[i])) {
                        cout << "Blad odczytu danych z pliku." << endl;
                        plik.close();
                        delete[] p;
                        return 1;
                    }
                }

                plik.close();

                cout << "Elementy w tablicy po odczycie z pliku:\n";
                for (int i = 0; i < n; i++) {
                    cout << p[i] << ", ";
                }
                cout << endl;
                } else {
                    cout << "Blad otwarcia pliku do odczytu." << endl;
                }
                break;
            }

        default:
            {
                cout<<"Nieprawidlowa opcja"<<endl;
            }

        }
    }

    return 0;
}
