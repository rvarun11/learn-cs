    #include<iostream>
    #include<string>
    #include <bits/stdc++.h>
    using namespace std;
     
   string word_encrypt(string w);
     
    int main(){
     
       int n;
       string str;
       cin >> n;
       cin.ignore();
       string input{n};
     
       for (int i=0;i<n;i++){
          getline(cin, str, '\n');
          input{i} = str;
       }
     
       for (int i=0;i<n;i++){
          istringstream ss(input{i});
          string word, new_str, new_word;
          while (ss >> word){
             new_word = word_encrypt(word);
             new_str += new_word;
          }
          new_str{0} = toupper(new_str{0});
          cout << new_str << endl;
       }
       
    return 0;
    }

    string word_encrypt(string w){
       int l = w.size();
       char g = tolower(w{0});
       string e_word = w.substr(1,l) + g + "ay";
       return (e_word + " ");
    }