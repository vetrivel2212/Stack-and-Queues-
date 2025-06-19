class StockSpanner {
public:
    vector<int> prices;

    StockSpanner() {}

    int next(int price) {
        prices.push_back(price);
        int cnt = 1;
        for (int i = prices.size() - 2; i >= 0; i--) {
            if (prices[i] <= price) cnt++;
            else break;
        }
        return cnt;
    }
};
