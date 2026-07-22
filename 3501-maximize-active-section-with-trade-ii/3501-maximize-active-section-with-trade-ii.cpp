#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

// Represents a contiguous segment of '0's in the binary string.
struct Group {
  int start;   // The 0-based start index of the '0' block in the original string.
  int length;  // The number of consecutive '0's in this block.
};

// A Sparse Table class used to answer Range Maximum Queries (RMQ) in O(1) time.
// Since the string is static and we only run queries, a Sparse Table is much
// faster than a Segment Tree (which takes O(log N) per query).
class SparseTable {
 public:
  SparseTable(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return;
    
    // 1. Precompute log values to avoid calling log functions at runtime.
    // log_table[i] will store floor(log2(i)).
    log_table.resize(n + 1, 0);
    for (int i = 2; i <= n; i++) {
      log_table[i] = log_table[i / 2] + 1;
    }
    
    // 2. Initialize the Sparse Table st[i][j]
    // st[i][j] will store the maximum value in the range [j, j + 2^i - 1].
    int max_log = log_table[n] + 1;
    st.assign(max_log, vector<int>(n));
    
    // Base case: intervals of length 2^0 = 1
    for (int i = 0; i < n; ++i) {
      st[0][i] = nums[i];
    }
    
    // Dynamic Programming step to fill the table for intervals of size 2^i
    for (int i = 1; i < max_log; ++i) {
      for (int j = 0; j + (1 << i) <= n; ++j) {
        // The max over an interval of size 2^i starting at j is the max of:
        // - First half: length 2^(i-1) starting at j.
        // - Second half: length 2^(i-1) starting at j + 2^(i-1).
        st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  // Returns the maximum value in the index range [l, r] in O(1) time.
  int query(int l, int r) const {
    if (l > r) return 0;
    int len = r - l + 1;
    int i = log_table[len]; // The largest power of 2 that fits into len.
    
    // We cover the interval [l, r] using two overlapping power-of-2 intervals:
    // One starting at l, and one ending at r.
    return max(st[i][l], st[i][r - (1 << i) + 1]);
  }

 private:
  vector<vector<int>> st;
  vector<int> log_table;
};

class Solution {
 public:
  vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
    const int n = s.length();
    
    // Count the total number of '1's in the original string.
    // Since any trade only converts '0's to '1's (after briefly swapping a '1' block to '0'
    // and converting the merged block back to '1'), the final number of '1's will always
    // be: (original number of '1's) + (number of '0's converted to '1's).
    const int ones = count(s.begin(), s.end(), '1');
    
    // Group all '0's into contiguous zero-segments.
    // zeroGroupIndex[i] tells us which zero-group contains index i (or the closest one to its left).
    const auto [zeroGroups, zeroGroupIndex] = getZeroGroups(s);
    
    // Edge case: If there are no '0's in the string, no trade can ever be made.
    // The maximum possible '1's will just be the original '1' count.
    if (zeroGroups.empty())
      return vector<int>(queries.size(), ones);

    // Build a Sparse Table over the combined lengths of adjacent zero groups.
    // For any 1-segment between zeroGroup[i] and zeroGroup[i+1], if we perform the trade on it,
    // the gain in '1's is: length(zeroGroup[i]) + length(zeroGroup[i+1]).
    // Hence, getZeroMergeLengths(zeroGroups)[i] = zeroGroups[i].length + zeroGroups[i+1].length.
    const SparseTable st(getZeroMergeLengths(zeroGroups));
    vector<int> ans;
    ans.reserve(queries.size());

    // Process each query independently
    for (const vector<int>& query : queries) {
      const int l = query[0];
      const int r = query[1];
      
      // Calculate how many '0's of the zero-group containing index 'l' fall inside the query [l, r].
      // Since 'l' starts the query, we only care about the suffix of this zero-group from 'l' onwards.
      const int left = zeroGroupIndex[l] == -1
                           ? -1
                           : (zeroGroups[zeroGroupIndex[l]].length -
                              (l - zeroGroups[zeroGroupIndex[l]].start));
                              
      // Calculate how many '0's of the zero-group containing index 'r' fall inside the query [l, r].
      // Since 'r' ends the query, we only care about the prefix of this zero-group up to 'r'.
      const int right = zeroGroupIndex[r] == -1
                            ? -1
                            : (r - zeroGroups[zeroGroupIndex[r]].start + 1);
                            
      // Find the range of zero-groups that are fully contained inside the query [l, r].
      // Any internal 1-segment must lie between two zero-groups that are both fully within [l, r].
      const auto [startAdjacentGroupIndex, endAdjacentGroupIndex] =
          mapToAdjacentGroupIndices(
              zeroGroupIndex[l] + 1,
              s[r] == '1' ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1);
              
      int activeSections = ones;
      
      // CASE 1: The query range is small and only spans across a single '1' segment,
      // and both boundary indices l and r are '0'.
      // This means the zero-group of l is group g, and the zero-group of r is group g + 1.
      // The trade can convert the '0's from index l to the end of group g, and from the start of group g+1 to index r.
      if (s[l] == '0' && s[r] == '0' &&
          zeroGroupIndex[l] + 1 == zeroGroupIndex[r]) {
        activeSections = max(activeSections, ones + left + right);
      } 
      
      // CASE 2: There is at least one '1' segment whose adjacent zero-groups are BOTH
      // completely contained within the query interval [l, r].
      // We can query the Sparse Table to find the maximum possible combined length of such adjacent groups.
      else if (startAdjacentGroupIndex <= endAdjacentGroupIndex) {
        activeSections = max(
            activeSections,
            ones + st.query(startAdjacentGroupIndex, endAdjacentGroupIndex));
      }
      
      // CASE 3: We choose to trade the '1' segment immediately to the right of l's zero-group.
      // Its left zero-group (group containing l) is only partially matched (giving 'left' zeros),
      // but its right zero-group (group zeroGroupIndex[l] + 1) is fully matched.
      if (s[l] == '0' &&
          zeroGroupIndex[l] + 1 <=
              (s[r] == '1' ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1)) {
        activeSections =
            max(activeSections,
                ones + left + zeroGroups[zeroGroupIndex[l] + 1].length);
      }
      
      // CASE 4: We choose to trade the '1' segment immediately to the left of r's zero-group.
      // Its right zero-group (group containing r) is only partially matched (giving 'right' zeros),
      // but its left zero-group (group zeroGroupIndex[r] - 1) is fully matched.
      if (s[r] == '0' && zeroGroupIndex[l] < zeroGroupIndex[r] - 1) {
        activeSections =
            max(activeSections,
                ones + right + zeroGroups[zeroGroupIndex[r] - 1].length);
      }
      
      ans.push_back(activeSections);
    }

    return ans;
  }

 private:
  // Helper to parse the string, identify all contiguous groups of '0's,
  // and map every character index to the index of its corresponding zero group.
  pair<vector<Group>, vector<int>> getZeroGroups(const string& s) {
    vector<Group> zeroGroups;
    vector<int> zeroGroupIndex;
    zeroGroupIndex.reserve(s.length());
    
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '0') {
        // If the previous character is also '0', extend the current group length.
        if (i > 0 && s[i - 1] == '0')
          ++zeroGroups.back().length;
        else // Otherwise, start a new zero group.
          zeroGroups.push_back({i, 1});
      }
      // Store which group contains this index.
      // If we are currently on a '1', we assign it the index of the closest zero group to its left.
      zeroGroupIndex.push_back(zeroGroups.empty() ? -1 : (int)zeroGroups.size() - 1);
    }
    return {zeroGroups, zeroGroupIndex};
  }

  // Prepares the values to populate the Sparse Table.
  // For each adjacent pair of zero groups (group i and group i+1),
  // it computes: length(group i) + length(group i+1).
  vector<int> getZeroMergeLengths(const vector<Group>& zeroGroups) {
    vector<int> zeroMergeLengths;
    if (zeroGroups.size() < 2) return zeroMergeLengths;
    zeroMergeLengths.reserve(zeroGroups.size() - 1);
    
    for (size_t i = 0; i + 1 < zeroGroups.size(); ++i) {
      zeroMergeLengths.push_back(zeroGroups[i].length + zeroGroups[i + 1].length);
    }
    return zeroMergeLengths;
  }

  // Maps the range of fully contained zero-groups to the corresponding indices in zeroMergeLengths.
  // e.g., if zero groups [1, 2, 3] are fully contained, the adjacent pairs are:
  // - Pair (1, 2) at index 1 of zeroMergeLengths.
  // - Pair (2, 3) at index 2 of zeroMergeLengths.
  // So the map range is [1, 3 - 1] -> [1, 2].
  pair<int, int> mapToAdjacentGroupIndices(int startGroupIndex, int endGroupIndex) {
    return {startGroupIndex, endGroupIndex - 1};
  }
};