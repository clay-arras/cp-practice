// https://leetcode.com/problems/minimum-penalty-for-a-shop

class Solution:
    def bestClosingTime(self, customers: str) -> int:
        num_customers = len(customers)
        prefix_sum_of_customers = [0 for i in range(num_customers+1)]

        for i in range(1, num_customers + 1):
            prefix_sum_of_customers[i] = prefix_sum_of_customers[i-1] + (customers[i-1] == "Y")
        
        ans = (math.inf, -1)
        for i in range(0, num_customers+1):
            customer_penalty = (i - prefix_sum_of_customers[i]) + (prefix_sum_of_customers[num_customers] - prefix_sum_of_customers[i])
            ans = min(ans, (customer_penalty, i))
        
        return ans[1]