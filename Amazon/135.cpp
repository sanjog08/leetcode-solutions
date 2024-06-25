// Amazon | Hard | 135. Candy

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if (size <= 1)
            return size;

        int ans = 0;
        vector<int> candies(size, 1); // Assign each child one candy to start with

        // Scan from left to right, assign more candies to the right neighbor if ratings increase
        for (int i = 1; i < size; ++i) {
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        }

        // Scan from right to left, assign more candies to the left neighbor if ratings increase
        for (int i = size - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i], candies[i + 1] + 1);
        }

        // Calculate total candies
        for (int i = 0; i < size; ++i) {
            ans += candies[i];
        }

        return ans;
    }
};