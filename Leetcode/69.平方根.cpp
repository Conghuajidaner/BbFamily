// 这种办法返回必须是right,left会被截断导致结果变小
class Solution {
public:
    int mySqrt(int x) {
        double left = 0, right = INT_MAX;

        while (abs(left- right) > 1e-9)
        {
            double mid = (left + right)/2;
            if (mid * mid > x)
            {
                right = mid;
            } else {
                left = mid;
            }
        }
        return int(right);
    }
};
