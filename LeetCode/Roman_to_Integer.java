package algorithm.LeetCode;

import java.util.HashMap;
import java.util.Map;

public class Roman_to_Integer {

    Map<String, Integer> map = new HashMap<String,Integer>();
    public void init(){
        map.put("I",1);
        map.put("IV",4);
        map.put("V",5);
        map.put("IX",9);
        map.put("X",10);
        map.put("XL",40);
        map.put("L",50);
        map.put("XC",90);
        map.put("C",100);
        map.put("CD",400);
        map.put("D",500);
        map.put("CM",900);
        map.put("M",1000);
    }
    public int romanToInt(String s) {
        init();
        int ret = 0;

        int index = 0;
        while(index < s.length()){
            if(index+2<=s.length()){
                String temp = s.substring(index,index+2);
                if(map.containsKey(temp)){
                    ret += map.get(temp);
                    index +=2;
                    continue;
                }
            }
            String temp = s.substring(index,index+1);
            ret += map.get(temp);
            index++;

        }



        return ret;
    }
}
