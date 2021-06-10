#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <regex>

#define URL_PATTERN "(((http|https)://)?www\\.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)"

using namespace std;

void searchUrl(string line, vector<string> &url){
    stringstream ss(line);
    string word;

    while(ss >> word)
        if(regex_match(word, regex(URL_PATTERN))) url.push_back(word);
}


void deletingElements(string &line){            // removing elements
    set<char> simboliai { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '!', '?', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '{', '}', '[', ']', ':', ';', '"', '`', '\\', '|', '\'', '<', '>', ',', '.', '/'};
    // set<char> num {'1','2','3','4','5','6','7','8','9','0'};
    // set<char> letters {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','r','s','t','u','v','z','q','w','x','y'};

    for(char simbolis : simboliai){     // trinami simboliai
        line.erase(remove(line.begin(), line.end(), simbolis), line.end());
    }

    int i = 0;
    while(i != line.length()){          // mazosios raides
        line[i] = tolower(line[i]);
        i++;
    }
}

void mainWord(string line, map<string, set<int>> &words, int &linenum){         // adding words to map
    stringstream ss(line);
    string word;

    while(ss >> word){
        auto word_search = words.find(word);

        if(word_search == words.end()){
            set<int> tempSet;
            tempSet.insert(linenum);
            words.insert(pair<string, set<int>> (word, tempSet));
        }
        else word_search->second.insert(linenum);
    }
}

// void print_cr(map<string, set<int>> words, int linenum){
//     ofstream output("output_cr.txt");

//     output << "CROSS REFERENCE TABLE: " << endl;

//     output << left << setw(18) << "ZODIS";
//     for(int i = 1; i <= linenum; i++){
//         output << i << " ";
//     }
//     output << endl << "------------------------------------" << endl;
// }

void print(map<string, set<int>> words, vector<string> url){        // output
    ofstream output("output.txt");

    if(url.size() > 0){     // PRINTING URL
        output << "------------------- URL ADRESAI: ------------------------" << endl;
        for(int i = 0; i < url.size(); i++){
            output << url[i] << endl;
        }
    }

    output << endl << "---------------------------------------------------" << endl << endl
    // << left << setw(18) << "ZODIS" << setw(15) << "PASIKARTOJA" << setw(15) << "EILUTES" << endl << endl;
    << "ZODIS" << " ----------- " << "PASIKARTOJA" << " - " << "EILUTES" << " ---------" << endl;

    for(auto it = words.begin(); it != words.end(); it++){      // PRINTING WORDS
        if(it->second.size() > 1) {
            output << left << setw(18) << it -> first << setw(14) << it -> second.size();
            
            for(int i : it -> second)
                output << i << " ";

            output << endl;
        }
    }
    output.close();
}

int main(){
    string line;
    int linenum = 0;

    // ifstream input("text.txt");              // LT tekstas
    ifstream input("text_en.txt");              // EN tekstas

    map<string, set<int>> words;
    vector<string> url;

    // ------

    if(input.is_open()){
        while(getline(input, line)){

            linenum++;
            searchUrl(line, url);
            deletingElements(line);           // istrinami nereikalingi elementai
            mainWord(line, words, linenum);     // main zodziu skaiciavimo funkcija
        }
        print(words, url);
        // print_cr(words, linenum);
    }
    
    else {
        cout << "Failas nerastas. Uzdaroma programa. ";
    }

    input.close();
}