#include<iostream>
#include<fstream>
#include <algorithm>
#include <cctype>   

int main() {
    std::ifstream fin("text.in");
    std::ofstream fout("text.out");
    std::string words[100], line, word;
    int lines = 0, y = 0, counter[100] = {0};

    while (std::getline(fin, line)) {
        if (line.empty()) continue;

        word = "";
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ' ' || line[i] == '!' || line[i] == '?' || line[i] == '.' || line[i] == ',') {
                if (!word.empty()) {
                    std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c){ return std::tolower(c); });
                    
                    bool found = false;
                    for (int j = 0; j < y; j++) {
                        if (words[j] == word) {
                            counter[j]++;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        words[y] = word;
                        counter[y]++;
                        y++;
                    }
                    word = "";
                }
            } else {
                word += line[i];
            }
        }
        if (!word.empty()) {
            std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c){ return std::tolower(c); });
            
            bool found = false;
            for (int j = 0; j < y; j++) {
                if (words[j] == word) {
                    counter[j]++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                words[y] = word;
                counter[y]++;
                y++;
            }
        }
        lines++;
    }

    for (int i = 0; i < y; i++) {
        fout << words[i] << " " << counter[i] << std::endl;
    }

    fin.close();
    fout.close();

    return 0;
}
