#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class file
{
    ifstream inFile;
    
    
    public:
        file();
        ~file();
        void wczytaj(string wers, string linijka, string licznik_jedynek, string licznik_zer);
        void reverse(string rev, string licznik_jedynek, string licznik_zer);
};


file::file()
{
    inFile.open("dane_obrazki.txt");
        if (!inFile.good())
    {
        cerr << "Blad - pliku nie da sie otworzyc!\n";
        exit(1);
    }
}
void file::wczytaj(string wers, string linijka, string licznik_jedynek, string licznik_zer) {
	for(int i=0; i<20; i++) {
		inFile >> wers;
	}  for (int i=0; i<20; i++) {
		getline(inFile, linijka);
	} for(int i=0; i<20; i++) {
		if(linijka[i]=='1') {
			licznik_jedynek++;
		}
			else
				if(linijka[i]=='0') {
				licznik_zer++;
			}
	}
}
void file::reverse(string rev, string licznik_jedynek, string licznik_zer) {
	if(licznik_jedynek > licznik_zer )
		rev++;
		cout << "rewersow w tym pliku jest: " << rev;
}

file::~file()
{
    inFile.close();
}

int main(int argc, char** argv) {
	file p;
	p.wczytaj();
	p.reverse();
	return 0;
}
