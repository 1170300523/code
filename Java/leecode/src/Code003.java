// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

public class Code003 {
    public int lengthOfLongestSubstring(String s) {
        int  size,i=0,j,k,max=0;
        size = s.length();
        for(j = 0;j<size;j++){
            for(k = i;k<j;k++)
                if(s.charAt(k) == s.charAt(j)){
                    i = k+1;
                    break;
                }
            if(j-i+1 > max)
                max = j-i+1;
        }
        return max;
    }
}
