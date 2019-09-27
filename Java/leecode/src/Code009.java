// 判断一个整数是否为回文数
public class Code009 {
    public static  boolean isPalindrome(int x) {
            if(x<0)return false;
            int s = 0,x0=x;
            do {
                s = s*10 + x%10;
                x /= 10;
            }while (x != 0);
            return s==x0;
    }

    public static void main(String[] args) {
        System.out.println(isPalindrome(12321));
    }
}
