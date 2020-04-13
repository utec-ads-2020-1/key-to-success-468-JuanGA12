#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

bool compare(const pair<char,int> &a, const pair<char,int> &b) {
    return a.second > b.second;
}

int main(){

    int cases;

    string input, encoded, decoded;

    cin >> cases;

    // \n after cases
    getline(cin, input);

    for (int cc = 0; cc < cases; ++cc ) {
        // blank line
        getline(cin, input);

        getline(cin, decoded);
        getline(cin, encoded);

        input = encoded;

        sort(decoded.begin(), decoded.end());
        sort(encoded.begin(), encoded.end());

        vector<pair<char, int> > d_occurrences;
        vector<pair<char, int> > e_occurrences;

        int count = 1;
        for (int i = 1, sz = decoded.size(); i < sz; i++) {
            if (decoded[i] == decoded[i - 1]) {
                count++;
            } else {
                if ((decoded[i - 1] >= 'a' && decoded[i - 1] <= 'z') ||
                    (decoded[i - 1] >= 'A' && decoded[i - 1] <= 'Z')) {
                    d_occurrences.emplace_back(make_pair(decoded[i - 1], count));
                }
                count = 1;
            }
        }
        if ((decoded[decoded.size() - 1] >= 'a' && decoded[decoded.size() - 1] <= 'z') ||
            (decoded[decoded.size() - 1] >= 'A' && decoded[decoded.size() - 1] <= 'Z')) {
            d_occurrences.emplace_back(make_pair(decoded[decoded.size() - 1], count));
        }

        count = 1;
        for (int i = 0, sz = encoded.size(); i < sz; i++) {
            if (encoded[i] == encoded[i - 1]) {
                count++;
            } else {
                if ((encoded[i - 1] >= 'a' && encoded[i - 1] <= 'z') ||
                    (encoded[i - 1] >= 'A' && encoded[i - 1] <= 'Z')) {
                    e_occurrences.emplace_back(make_pair(encoded[i - 1], count));
                }
                count = 1;
            }
        }
        if ((encoded[encoded.size() - 1] >= 'a' && encoded[encoded.size() - 1] <= 'z') ||
            (encoded[encoded.size() - 1] >= 'A' && encoded[encoded.size() - 1] <= 'Z')) {
            e_occurrences.emplace_back(make_pair(encoded[encoded.size() - 1], count));
        }

        sort(d_occurrences.begin(), d_occurrences.end(), compare);
        sort(e_occurrences.begin(), e_occurrences.end(), compare);

        map<char, char> decoder;
        for (int i = 0, sz = e_occurrences.size(); i < sz; i++) {
            decoder[e_occurrences[i].first] = d_occurrences[i].first;
        }

        for (int i = 0, sz = input.size(); i < sz; i++) {
            cout << decoder[input[i]];
        }
        cout << endl;

        if (cases) {
            cout << endl;
        }
    }


    return 0;
}