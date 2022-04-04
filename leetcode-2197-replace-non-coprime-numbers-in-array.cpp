class Solution {
public:
  bool non_coprime(int n1, int n2) {
    return gcd(n1, n2) > 1;
  }
  
  vector<int> replaceNonCoprimes(vector<int>& nums) {
    list<int> my_list;
    for(int i = 0; i < nums.size(); i++) {
      my_list.push_back(nums[i]);
    }
    
    for(int i = 0; i < 2; i++) {
      //left to right
      auto it = my_list.begin();
      while(it != my_list.end() && next(it) != my_list.end()) {
        int curr = *it;
        int nxt = *next(it);
        if(non_coprime(curr, nxt)) {
          *it = lcm(curr, nxt);
          my_list.erase(next(it));
        }
        else {
          it++;
        }
      }
      //right to left
      auto itr = my_list.rbegin();
      while(itr != my_list.rend() && next(itr) != my_list.rend()) {
        if(non_coprime(*itr, *next(itr))) {
          *next(itr) = lcm(*itr, *next(itr));
          my_list.erase(next(itr).base());
        }
        else {
          itr++;
        }
      }
    }
    
    
    vector<int> resVec(my_list.size());
    int idx=0;
    for(auto itr = my_list.begin(); itr != my_list.end(); itr++, idx++) {
      resVec[idx] = *itr;
    }
   
    return resVec;
  }
}; 