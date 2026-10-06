class Solution {
public:

    struct Node {
        string val;
        unordered_set<Node*> neigh;

        Node(): val("") {};
        Node(string s): val(s) {};
    };

    bool stringDif(string a, string b) {
        bool found = false;

        for(int i = 0; i < a.size(); ++i)
            if(a[i] != b[i]) {
                if(!found)
                    found = true;
                else 
                    return false;
            }

        if(found)
            return true;
        
        return false;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        wordList.push_back(beginWord);

        unordered_map<string, Node*> graph;

        for(int i = 0; i < wordList.size(); ++i)
            for(int j = i+1; j < wordList.size(); ++j) {
                if(stringDif(wordList[i], wordList[j])) {
                    if(!graph.contains(wordList[i]))    
                        graph.insert({wordList[i], new Node(wordList[i])});
                    if(!graph.contains(wordList[j]))    
                        graph.insert({wordList[j], new Node(wordList[j])});

                    graph[wordList[i]]->neigh.insert(graph[wordList[j]]);
                    graph[wordList[j]]->neigh.insert(graph[wordList[i]]);
                }
            } 

        if(graph.empty() || !graph.contains(beginWord))
            return 0; 

        queue<pair<string, int>> q;
        unordered_set<string> vis;

        q.push({beginWord, 1});
        vis.insert(beginWord);

        while(!q.empty()) {
            string pString = q.front().first;
            int pVal = q.front().second;
            q.pop();

            for(auto x : graph[pString]->neigh) {
                if(x->val == endWord)
                    return pVal + 1;
                
                if(!vis.contains(x->val)) {
                    q.push({x->val, pVal+1});
                    vis.insert(x->val);
                }
            }
        }

        return 0;  
    }
};
