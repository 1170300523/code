// 两个排序数组的中位数
public class Code004 {
    // 时间复杂第:m+n
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {

        int len1 = nums1.length;
        int len2 = nums2.length;
        int bias = (len1+len2+1)%2;
        int mid = (len1+len2)/2;
        int i=0,j = 0,k=0,s = 0;
        while (i + j < mid){
            if(j>=len2||(i<len1 && nums1[i]<nums2[j]))s = nums1[i++];
            else s = nums2[j++];
        }
        if(j>=len2||(i<len1 && nums1[i]<nums2[j]))k = nums1[i];
        else k = nums2[j];

        if(bias==0)return k;
        else return  (s+k)/2.0;

    }

    public static double findMedianSortedArrays1(int[] nums1, int[] nums2) {
        int len1 = nums1.length;
        int len2 = nums2.length;
        int mid = (len1+len2-1)/2;




        return 0;
    }

    public static void main(String[] args) {
        int[] a = new int[]{1,2,3,4,5};
        int[] b = new int[]{1,1,1,4,5};
        System.out.println(findMedianSortedArrays(a,b));

    }
}
