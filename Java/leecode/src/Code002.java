// 两个链表相加
public class Code002 {
    /*
     * Definition for singly-linked list.
     * public class ListNode {
     *     int val;
     *     ListNode next;
     *     ListNode(int x) { val = x; }
     * }
     */

     public class ListNode {
          int val;
          ListNode next;
          ListNode(int x) { val = x; }
      }
    class Solution {
        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            ListNode ans = new ListNode(0);
            ListNode cur = ans;
            int carry = 0;
            while (l1!=null ||l2 != null){
                int x = (l1==null)?0:l1.val;
                int y = (l2==null)?0:l2.val;
                int sum = x + y + carry;
                carry = sum/10;
                cur.next = new ListNode(sum%10);
                cur = cur.next;
                if(l1!= null)l1 = l1.next;
                if(l2!= null)l2 = l2.next;
            }
            if(carry==1)cur.next = new ListNode(1);
            return  ans.next;
        }

        public ListNode addTwoNumbers2(ListNode l1, ListNode l2) {
            ListNode ans = new ListNode(0);
            ListNode cur = ans;
            int carry = 0;
            while (l1!=null ||l2 != null){
                if(l1==null){
                    while (l2 != null){
                    int sum = l2.val + carry;
                    carry = sum/10;
                    cur.next = new ListNode(sum%10);
                    cur = cur.next;
                    l2 = l2.next;}
                    break;

                }
                if(l2==null){

                    while (l1 != null){
                        int sum = l1.val + carry;
                        carry = sum/10;
                        cur.next = new ListNode(sum%10);
                        cur = cur.next;
                        l1 = l1.next;}
                    break;
                }
                int x = l1.val;
                int y = l2.val;
                int sum = x + y + carry;
                carry = sum/10;
                cur.next = new ListNode(sum%10);
                cur = cur.next;
                if(l1!= null)l1 = l1.next;
                if(l2!= null)l2 = l2.next;
            }
            if(carry==1)cur.next = new ListNode(1);
            return  ans.next;
        }
    }

    public static void main(String[] args) {
        System.out.println(7/10);
    }
}
