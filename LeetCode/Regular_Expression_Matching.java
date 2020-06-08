package algorithm.LeetCode;

public class Regular_Expression_Matching {
    public boolean isMatch(String s, String p) {
        if(p.isEmpty()) return s.isEmpty();


        char c1 = s.charAt(0);
        char c2 = p.charAt(0);

        if(p.length() > 1 && p.charAt(1) == '*'){
            return isMatch(s,p.substring(2)) || (c1 == c2 && isMatch(s.substring(1),p));
        }
        else{
            if(s.length() != 0 ) return false;
            return (c1 == c2||c2 == '.') && isMatch(s.substring(1),p.substring(1));
        }

    }

}
