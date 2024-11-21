#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int main() {
    ifstream fin;
    string fileName;
    cout << "Please enter the name of the file: " << endl;
    cin >> fileName;
    fin.open(fileName);
    if (!fin) {
        cerr << "Error opening File ";
        exit(EXIT_FAILURE);
    }
    vector<string> ourList;
    vector<double>newList;
    string newElement;
    while (!fin.eof()) {
        getline(fin, newElement, ',');
        ourList.push_back(newElement);
    }
    fin.close();
    for (const string numbers : ourList) {
        double tempNum = 0;
        tempNum = stod(numbers);
        newList.push_back(tempNum);
    }
    if (newList.size() % 2 == 0) {
        cout << "The median of the dataset is: " << (newList[(newList.size() / 2) - 1] + newList[newList.size() / 2]) / 2 << ".";
    }
    else {
        cout << "The median of the dataset is: " << newList[(newList.size() / 2)] << ".";
    }
    return 0;
}