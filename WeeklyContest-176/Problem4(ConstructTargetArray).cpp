class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size() == 1) return target[0] == 1;
        priority_queue<long long> q;
        long long sum = 0;
        
        for(long long el : target) {
            sum+=el;
            q.push(el);
        }

        while(q.top() > 1) {
            long long max_val = q.top();
            q.pop();
            long long remaining_sum = sum - max_val;
            long long new_val = max_val - remaining_sum;
            if(new_val < 1) return false;
            q.push(new_val);
            sum = max_val;
        }
        return true;
    }
};