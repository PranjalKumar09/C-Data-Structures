class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> f(26,0);
        for (auto i: letters) f[i-'a']++;
        int maxi = 0;
        int n = words.size();
        for (int i = 1 ; i < (1<<n); i++){
            vector<int> F(26,0);
            for (int j = 0 ; j<words.size() ; j++){
                if ((1<<j)&i)
                    for(int k = 0 ; k < words[j].size();k++) F[words[j][k]-'a']++;
                }
            bool flag = True;
            for (int j = 0 ; j < 26 ; j++)
                if (F[j] > f[j]) flag = False;
            if (flag){
                int sum = 0;
                for (int j = 0 ; j < 26 ; j++) sum += F[j]*score[j];
                maxi = max(maxi,sum);
            }
        }  
        return maxi;
    }
};