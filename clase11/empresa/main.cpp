#include <iostream>
#include <map>
#include <numeric>

using namespace std;

int main()
{
    map<string, double> bienes;
    bienes.insert(make_pair("ERT", 2.52));
    bienes.insert(make_pair("ART", 1.90));
    bienes.insert(make_pair("JRT", 6.55));
    bienes.insert(make_pair("RRT", 8.45));

    string key = "ART";
    if (bienes.count(key) > 0) {
        cout << bienes[key] << endl;
    } else {
        cout << "no existe " << key << endl;
    }

    auto total = accumulate(bienes.begin(),
                            bienes.end(),
                            0.0,
     [] (double a, pair<string, double> elemento) -> double {
            return a + elemento.second;
});
    cout << total << endl;
    return 0;
}
