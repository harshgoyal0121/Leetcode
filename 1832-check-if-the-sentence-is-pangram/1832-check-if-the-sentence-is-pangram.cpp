class Solution {
public:
    // optimal solution
    bool checkIfPangram(string sentence) {
        unordered_map<char, int>map;
        int n=sentence.size();
        int count=0;
        for(int i=0; i<n; i++){
            map[sentence[i]]=i;
        }
        for(auto it: map){
            count++;
            if(count==26)
                return true;
        }
        return false;
    }
    
};