#include <iostream>
#include <vector>

using namespace std;


int main(){
    vector<int> test(10, 0);

    test.insert(test.begin() + 6, 4);

    for(int i = 0; i < test.size(); i++){
        cout << test.at(i) << " ";
    }
}
