// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int x;
        do {
            int first = rand7();
            int second = rand7();
            x = (first - 1)*7 + second;
        } while (x > 40);
        return (x % 10) + 1;
    }
};
