public class code001 {
    public static  int[] twoSum(int[] nums, int target) {
        for(int i =0;i<nums.length;i++){
               int d = target - nums[i];
                for(int j=i+1;j<nums.length;j++){
                    if(nums[j]==d){
                        return new int[]{i,j};
                    }
            }
        }
        return null;
    }

    public static void main(String[] args) {
        int[] nums = new int[]{2,8,11,7};
        int[] a = twoSum(nums,9);
        System.out.println(a[0]+" "+a[1]);
    }
}
