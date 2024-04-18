#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <sstream>

enum State { q0, q1, q2, q3, q4, q5, q6 };
using namespace std;

int FSX(string file, string filename, int in)
{
  
    State currentState = q0;

    for (char c : file) {
        switch (currentState) {
            case q0:
                if (c == 'p'){ currentState = q1;}
                else if (c == 'q'){ currentState = q6;}
                  else if (c == ' '){ currentState = q0;}
                else {
                    cout << "\033[1;31m======Syntax Error======\033[m\n\n";
                  cout << "\033[1;31mFile:\033[m " << filename << endl;

                  cout << "\033[1;31mLine:\033[m " << file << endl;
                  cout <<" \033[1;31mError:\033[m Expected 'p' or 'q' but got '" << c << "'" << endl;
                    return 1;
                }
                break;
            case q1:
                if (c == 'r'){ currentState = q2;}
                else {
                    cout << "\033[1;31m======Syntax Error======\033[m\n\n";
                  cout << "\033[1;31mFile:\033[m " << filename << endl;

                  cout << "\033[1;31mLine:\033[m " << file << endl;
                  cout <<" \033[1;31mError:\033[m Expected 'r' but got '" << c << "'" << endl;
                    return 1;
                }
                break;
            case q2:
                if (c == 'i'){ currentState = q3;}
                else {
                    cout << "\033[1;31m======Syntax Error======\033[m\n\n";
                  cout << "\033[1;31mFile:\033[m " << filename << endl;

                  cout << "\033[1;31mLine:\033[m " << file << endl;
                  cout <<" \033[1;31mError:\033[m Expected 'i' but got '" << c << "'" << endl;
                    return 1;
                }
                break;
            case q3:
                if (c == 'n'){ currentState = q4;}
                else {
                    cout << "\033[1;31m======Syntax Error======\033[m\n\n";
                  cout << "\033[1;31mFile:\033[m " << filename << endl;

                  cout << "\033[1;31mLine:\033[m " << file << endl;
                  cout <<" \033[1;31mError:\033[m Expected 'n' but got '" << c << "'" << endl;
                    return 1;
                }
                break;
            case q4:
                if (c == 't'){ currentState = q5;}
                else {
                    cout << "\033[1;31m======Syntax Error======\033[m\n\n";
                  cout << "\033[1;31mFile:\033[m " << filename << endl;

                  cout << "\033[1;31mLine:\033[m " << file << endl;
                  cout <<" \033[1;31mError:\033[m Expected 't' but got '" << c << "'" << endl;
                    return 1;
                }
                break;
            case q6:
                cout << "quit" << endl;
                return 2;
            case q5:
          cout << "'print'" << endl; 
          break;
          return 0;
        }
    }
    return 1;
}


int main(int argc, char* argv[]) {
  if(argc < 2){
    cout << "引数が足りません" << endl;
    return 1;
  }
  string filepass = argv[1];
  ifstream file(filepass);  // 読み込むファイルのパスを指定
  if(!file)
  {
    cout << "ファイルが見つかりません" << endl;
    return 1;
  }
  string line;
  int in;
  while (getline(file, line)) {  // 1行ずつ読み込む
      FSX(line,filepass,in);
  }
}