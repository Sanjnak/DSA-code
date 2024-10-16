#include <iostream>
#include<string>
using namespace std;

string truncateSentence(string s, int k) {
        string array[s.length()];
        int len = s.length();
        int cnt = 0;
        string newString = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] != ' '){
                newString += s[i];
                if(i == (len-1)){
                    array[cnt] = newString;
                    break;
                }
            }else{
                array[cnt] = newString;
                newString = "";
                cnt++;
            }
        }
        string returnString = "";
        for(int i=0; i<k; i++){
            returnString += array[i];
            if(i <k-1){
                returnString += " ";
            }
            
        }

        return returnString;


    }

    int main(){
        string s = "";
        cout << "ENter a string: "<<endl;
        getline(cin, s);
        //cout << s.length();
        int k;
        cout << "Enter k: "<<endl;
        cin >> k;
        s = truncateSentence(s, k);
        cout << s;
        return 0;
    }