import java.util.*;

public class Code015 {
    public static List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        int len =nums.length;
        List<List<Integer>> ans1 = new ArrayList<>();
        HashSet<List<Integer>> ans = new HashSet<>();
        if(len<3||nums[0]>0||nums[len-1]<0)return ans1;
//        if(nums[0]==0 && nums[len-1] == 0){
//            ans.add( Arrays.asList(0,0,0));
//            return ans1;
//        }

//        HashSet<Integer> set = new HashSet<>();
//        for(int i:nums)set.add(i);
//        if(set.contains(0)) { // 若果包含0
//            for(int i=0,j = len -1;i<j;){
//                if(nums[i]*nums[i]<nums[j]*nums[j])j--;
//                else if(nums[i]*nums[i]>nums[j]*nums[j])i++;
//                else {
//                    if(j-i>1)ans.add( Arrays.asList(nums[i++],0,nums[j--]));
//                    else {
//                        i++;
//                        j--;
//                    }
//                }
//            }
//        }

        int m1=0,k=0,m2=len-1;
        while (nums[m1]<0)m1++;
        while (nums[m2]>0)m2--;
        if(m2 - m1 >1)ans.add( Arrays.asList(0,0,0));
//        for(int i=0;i<m1;i++){
//            for(int j = len -1;j>m2;j-- ) {
//                int sum = nums[i] + nums[j];
//                if (sum > 0) {
//                    for (k = i + 1; k < m1; k++) {
//                        if (sum + nums[k] == 0) ans.add(Arrays.asList(nums[i], nums[k], nums[j]));
//                    }
//                } else  if(sum<=0){
//                    for (k = m2 ; k < j; k++) {
//                        if (sum + nums[k] == 0) ans.add(Arrays.asList(nums[i], nums[k], nums[j]));
//                    }
//                }
//            }
//        }
/*        for(int i=0,j=len -1;i<m1 && j>m2;){
            int sum = nums[i] + nums[j];

            if (sum > 0) {
                for (k = i + 1; k < m1; k++) {
                    if (sum + nums[k] <= 0) {
                        if(sum + nums[k] == 0){
                            ans.add(Arrays.asList(nums[i], nums[k], nums[j]));
                            i++;
                            break;
                        }
                    }else {
                        j--;
                        break;
                    }
                }
                if(k==m1)i++;

            } else  if(sum<=0){
                for (k = j-1 ; k >=m2; k--) {
                    if (sum + nums[k] >= 0) {
                        if(sum+nums[k]==0){
                            ans.add(Arrays.asList(nums[i], nums[k], nums[j]));
                            j--;
                            break;
                        }
                    }else {
                        i++;
                        break;
                    }
                }
                if(k==m2)j--;
            }
        }*/
        Set<Integer> set = new HashSet<>();
        for(int i=0;i<m1;i++)set.add(nums[i]);
        int flag=1;
        if(nums[m2]==0)flag=0;
        for(int i=len-1;i>=m2;i--) {
            if(i<len-1&&nums[i]==nums[i+1])i--;
            for (int j = i - 1; j >=m2+flag; j--) {
                if (set.contains(-nums[i] - nums[j])) {
                    ans.add(Arrays.asList(nums[i], nums[j], -nums[i] - nums[j]));
                }
                if (-nums[i] - nums[j] > nums[len - 1]) break;
            }
        }


        Set<Integer> set1 = new HashSet<>(); //正数集合
        for(int i=m2;i<len;i++)set1.add(nums[i]);
        for(int i=0;i<m1;i++) {
            if(i>0&&nums[i]==nums[i-1])i++;
            for (int j = i + 1; j < m1; j++) {
                if (set1.contains(-nums[i] - nums[j])) {
                    ans.add(Arrays.asList(nums[i], nums[j], -nums[i] - nums[j]));
                }
                if (-nums[i] - nums[j] < nums[0]) break;
            }
        }

        for(List<Integer> i:ans)ans1.add(i);
        return ans1;
    }

    public static void main(String[] args) {
        int[] a = new int[]{-1,0,1,2,-1,-4};
        System.out.println(threeSum(a));

    }
}
