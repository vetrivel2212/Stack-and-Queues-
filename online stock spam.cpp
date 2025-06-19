// class StockSpanner {
// public:
//     vector<int> prices;

//     StockSpanner() {}

//     int next(int price) {
//         prices.push_back(price);
//         int cnt = 1;
//         for (int i = prices.size() - 2; i >= 0; i--) {
//             if (prices[i] <= price) cnt++;
//             else break;
//         }
//         return cnt;
//     }
// };
class StockSpanner {
public:
    stack<pair<int,int>> st;
    int ind = -1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        ind+=1;

        while(!st.empty() && st.top().first <= price) st.pop();
        int ans = ind - (st.empty()?-1:st.top().second);
        st.push({price,ind});

        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
