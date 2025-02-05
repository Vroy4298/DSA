import java.util.HashMap;

class Solution {  // Ensure the class name is "Solution"
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[]{map.get(complement), i};
            }
            map.put(nums[i], i);
        }
        
        return new int[]{}; // This line won't be reached as per problem constraints
    }

    public static void main(String[] args) {
        int[] nums = {2, 7, 11, 15};
        int target = 9;
        Solution solution = new Solution(); // Create an instance of Solution
        int[] result = solution.twoSum(nums, target);

        System.out.println("[" + result[0] + ", " + result[1] + "]");
    }
}
