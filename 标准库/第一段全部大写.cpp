#include <iostream>
using namespace std;
#include <vector>

int main()
{
    vector<string> text;
    for (string line; getline(cin, line);){
    	 text.push_back(line);
    	 text.push_back("");
	}

    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
        for (auto& c : *it) c = toupper(c);
        cout << *it << endl;
    }

    return 0;
}
