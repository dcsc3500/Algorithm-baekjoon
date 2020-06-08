package algorithm.LeetCode;

public class Container_With_Most_Water {
    public int maxArea(int[] height) {
        int l = 0;
        int r = height.length-1;
        int maxv = -1;
        while(l<r){
            int len = r-l;
            int hei = Math.min(height[l],height[r]);
            maxv = Math.max(maxv, len * hei);

            if(height[l] > height[r]) r--;
            else l++;
        }
        return maxv;
    }
}
