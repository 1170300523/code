import java.util.HashMap;

public class Code013 {
    public static  int romanToInt(String s) {

        int ans =0;
        s = s.toUpperCase();
        HashMap<Character,Integer> map = new HashMap<>();
        map.put('I',1);
        map.put('V',5);
        map.put('X',10);
        map.put('L',50);
        map.put('C',100);
        map.put('D',500);
        map.put('M',1000);

        int len = s.length();
        int i=0;
        for (;i<len-1;i++){
            int val1= map.get(s.charAt(i));
            int val2 = map.get(s.charAt(i+1));
            if(val1*5 == val2||val1*10==val2){
                ans += val2 -val1;
                i++;
            }else {
                ans += val1;
            }
        }
        if(i==len-1)ans += map.get(s.charAt(len-1));

        return ans;
    }

    public static void main(String[] args) {
        romanToInt("lll");
    }
}
