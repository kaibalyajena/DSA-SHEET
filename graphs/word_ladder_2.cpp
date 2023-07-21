//gives tle
//watch striver video for explanation
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        vector<string> sequence;
        vector<string> usedAtLevel;
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        usedAtLevel.push_back(beginWord);
        int level=0;
        while(!q.empty()){
            vector<string> seq=q.front();
            q.pop();
            if(seq.size()>level){
                level++;
                for(auto word:usedAtLevel){
                    s.erase(word);
                }
                usedAtLevel.clear();
            }
            string latest_word=seq.back();
            if(latest_word==endWord){
                if(ans.size()==0){
                    ans.push_back(seq);
                }else if(ans[0].size()==seq.size()){
                    ans.push_back(seq);
                }
            }
            for(int i=0;i<latest_word.size();i++){
                char original_word=latest_word[i];
                for(char ch='a';ch<='z';ch++){
                    latest_word[i]=ch;
                    if(s.find(latest_word)!=s.end()){
                        seq.push_back(latest_word);
                        usedAtLevel.push_back(latest_word);
                        q.push(seq);
                        seq.pop_back();
                    }
                }
                latest_word[i]=original_word;
            }
        }
        return ans;
    }
};