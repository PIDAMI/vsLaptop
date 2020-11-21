#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef enum {
    NEW_BUS,
    BUSES_FOR_STOP,
    STOPS_FOR_BUS,
    ALL_BUSES
} state;

state GetState(string s) {
    if (s == "NEW_BUS") return NEW_BUS;
    else if (s == "BUSES_FOR_STOP") return BUSES_FOR_STOP;
    else if (s == "STOPS_FOR_BUS") return STOPS_FOR_BUS;
    else return ALL_BUSES;
}


void NewBus(map <string, vector <string>>& m, int count, string bus, vector <string> stops) {
    for (int i = 0; i < count; i++) {
        m[stops[i]].push_back(bus);
    }
}

map <string, vector <string>>> BusesForStop(map <string, vector <string>>& m, string stop) {
    if (m.count(stop) == 0) {
        cout << "No stop" << endl;
    }
    else {
        for (auto& c : m[stop]) {
            cout << c << ' ';
        }
    }
}
// stop - buses
void StopsForBus (map <string, vector <string>>& m, string bus) {
    int k = 0;
    for (auto& vec : m) {
        for (auto & stops : vec.second) {
            if (stops == bus) k = 1;
        }
    }
    if (!k) cout << "No bus" << endl;
    else {
        for (auto& vec : m) {
            //if ( )
            for (auto& stops : vec.second) {
                if (stops == bus) k = 1;
            }
        }
    }

    return;
}


void About(map <string, string>& m, string country) {
    if (m.count(country) == 0) {
        cout << "Country " << country <<" doesn't exist" << endl;
    }
    else {
        cout << "Country " << country << " has capital " << m[country] << endl;
    }

}

void Dump(map <string, string>& m) {
    if (m.size() == 0) {
        cout << "There are no countries in the world" << endl;
     }
    else {
        for (const auto& item : m) {
            cout << item.first << '/' << item.second << endl;
        }
    }
}

int main()
{
    int n;

    map <string, string> m;

    string s;
    cin >> n;
    string country, newCap, newCountry;


    for (int i = 0; i < n; i++) {
        cin >> s;
        switch (GetState(s)) {
        case 0:
            cin >> country >> newCap;
            ChangeCap(m, newCap, country);
            break;
        case 1:
            cin >> country >> newCountry;
            Rename(m, country, newCountry);
            break;
        case 2:
            cin >> country;
            About(m, country);
            break;
        case 3:
            Dump(m);
            break;
        }
    }


    return 0;
}
