// the basic idea is doing bfs
// instead of a visited array we maintaing an unordered set (removing the word from the unordered set whenever it is present inside the wordList and push into the queue)
// for every word starting from the beginWord we try each character at every position and whenever we find it in the wordlist we push into the queue and add one to the no of steps
// when we reach the end word we just return the steps

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        queue<pair<string,int>> q;
        unordered_set<string> s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        q.push({beginWord,1});
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==endWord){
                return steps;
            }
            for(int i=0;i<word.size();i++){
                char original_character=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(s.find(word)!=s.end()){
                        s.erase(word);
                        q.push({word,steps+1});
                    }
                }
                //after all the changing it must become what it originally was
                word[i]=original_character;
            }
        }
        return 0;
    }
};








//non tle code
//does dfs as well as bfs
class Solution {
    unordered_map<string,int> mp;
    vector<vector<string>> ans;
    string first_word;
public:
    void dfs(string word,vector<string>& seq){
        if(word==first_word){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int n=word.size();
        int steps=mp[word];
        for(int i=0;i<n;i++){
            char original_word=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(mp.find(word)!=mp.end() && mp[word]==steps-1){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i]=original_word;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<string> q;
        first_word=beginWord;
        q.push(beginWord);
        s.erase(beginWord);
        mp[beginWord]=1;
        while(!q.empty()){
            string word=q.front();
            q.pop();
            if(word==endWord){
                break;
            }
            int n=word.size();
            int steps=mp[word];
            for(int i=0;i<n;i++){
                char original_word=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(s.find(word)!=s.end()){
                        s.erase(word);
                        mp[word]=steps+1;
                        q.push(word);
                    }
                }
                word[i]=original_word;
            }    
        }
        if(mp.find(endWord)!=mp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
};