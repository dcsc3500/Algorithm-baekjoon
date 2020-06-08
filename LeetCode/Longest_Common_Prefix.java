package algorithm.LeetCode;

public class Longest_Common_Prefix {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0 )return "";
        String ans = strs[0];
        for(int i =1;i<strs.length;i++){
            int j =0;
            for(;j<ans.length();j++){
                if(strs[i].length()<=j) break;
                if(ans.charAt(j) != strs[i].charAt(j))
                    break;
            }
            ans = ans.substring(0,j);
        }


        return ans;
    }
}
