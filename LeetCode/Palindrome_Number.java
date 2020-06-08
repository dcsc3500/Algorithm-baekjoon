package algorithm.LeetCode;

public class Palindrome_Number {
    public boolean isPalindrome(int x) {
        boolean ret = false;

        String num = Integer.toString(x);
        String cmp = (new StringBuilder(num)).reverse().toString();
        for(int i =0;i<num.length();i++){
            if(num.charAt(i) != cmp.charAt(i)) return false;
        }
        return true;


    }

}
