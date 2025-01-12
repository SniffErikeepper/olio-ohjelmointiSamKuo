#include <iostream>

using namespace std;

//protoryyppi:
int game(int maxnum);

int main()
{
    int arvausten_lukumaara = 0;
    int maxnum = 40;    //maksimi numero jonka kone arpoo.
    arvausten_lukumaara = game(maxnum); //kattoo paljon on tehty arvauksia.
    cout << "Arvauksia: " << arvausten_lukumaara << endl;



    return 0;
}

int game(int maxnum) {  //game proto
    int arvausten_lukumaara = 0;

    int satunnaisluku = 0;
    int arvaus = 0;

    srand (time(NULL)); //arvonta
    satunnaisluku = rand() % maxnum;


    while(arvaus != satunnaisluku) {    //katotaa minkä kokone se on.
        arvausten_lukumaara++;

        cout << "Anna luku?" << endl;
        cin >> arvaus;

        if (arvaus < satunnaisluku) {
            cout << "Liian pieni, kokeile uudestaan." << endl;
        }
        if (arvaus > satunnaisluku) {
            cout << "Liian iso, kokeile uudestaan." << endl;
        }

    }

    return arvausten_lukumaara;
}
