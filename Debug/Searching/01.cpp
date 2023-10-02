// strings debug-01 : reverseWords
void reverseWords(string s)
{
    vector<string> tmp;
    string str = "";
    for (int i = 0; i < s.length(); i++) { // Strings doesn't have null characters as terminator by default
        if (s[i] == ' ') {
            tmp.push_back(str);
            str = "";
        }
        else
            str += s[i];
    }
    tmp.push_back(str);
    reverse(tmp.begin(), tmp.end()); // reversing words with the reverse function

    // added below code for checking console output
    for (auto it : tmp) {
        for (auto ch : it) {
            cout << ch;
        }cout << " ";
    }cout << endl;
    // No return statement as function is void
}

int main()
{
    string str = "ayush chaudhary is highly motivated person";
    reverseWords(str);
    return 0;
    
}
