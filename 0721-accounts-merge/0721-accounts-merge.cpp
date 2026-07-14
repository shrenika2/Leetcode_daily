#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.assign(size, 1);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        // Path compression
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        
        if (root_i != root_j) {
            // Union by rank
            if (rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            } else if (rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } else {
                parent[root_j] = root_i;
                rank[root_i] += 1;
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf(n);
        unordered_map<string, int> emailToId;
        
        // Step 1 & 2: Map emails to account indices and union overlapping accounts
        for (int i = 0; i < n; ++i) {
            for (size_t j = 1; j < accounts[i].size(); ++j) {
                string email = accounts[i][j];
                if (emailToId.count(email)) {
                    uf.unite(i, emailToId[email]);
                } else {
                    emailToId[email] = i;
                }
            }
        }
        
        // Step 3: Group emails by their ultimate root representative ID
        unordered_map<int, vector<string>> groupedEmails;
        for (auto const& [email, accountId] : emailToId) {
            int rootId = uf.find(accountId);
            groupedEmails[rootId].push_back(email);
        }
        
        // Step 4: Sort emails and construct the final output structure
        vector<vector<string>> result;
        for (auto& [rootId, emails] : groupedEmails) {
            sort(emails.begin(), emails.end());
            
            vector<string> account;
            account.push_back(accounts[rootId][0]); // Get the owner's name
            account.insert(account.end(), emails.begin(), emails.end());
            
            result.push_back(account);
        }
        
        return result;
    }
};