package algorithm.LeetCode;

import java.util.HashMap;
import java.util.Map;

public class Integer_to_Roman {
    Map<Integer,String> map = new HashMap<Integer,String>();
    public void init(){
        map.put(1,"I");
        map.put(4,"VI");
        map.put(5,"V");
        map.put(9,"XI");
        map.put(10,"X");
        map.put(40,"LX");
        map.put(50,"L");
        map.put(90,"CX");
        map.put(100,"C");
        map.put(400,"DC");
        map.put(500,"D");
        map.put(900,"MC");
        map.put(1000,"M");
    }


    public String intToRoman(int num) {
        init();
        StringBuilder sb = new StringBuilder();
        int level = 1;
        while(num != 0){
            int temp = num % 10;
            if(temp == 1 || temp == 4 || temp == 9 || temp ==5){
                sb.append(map.get(temp*level));
            }
            else if (temp == 2 || temp == 3){
                for(int i =0;i<temp;i++) {
                    sb.append(map.get(level));
                }
            }
            else if(temp == 6 || temp == 7 || temp == 8){


                temp -= 5;
                for(int i =0;i<temp;i++) {
                    sb.append(map.get(level));
                }
                sb.append(map.get(5*level));
            }
            level *= 10;
            num /= 10;
        }
        return sb.reverse().toString();
    }
}
