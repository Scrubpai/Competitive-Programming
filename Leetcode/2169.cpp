class Solution {
public:
    int countOperations(int num1, int num2) {
        if (!num1 || !num2) return 0;
        for (int i=1; ; i++) {
            if (num1 >= num2) num1 -= num2;
            else num2 -= num1;
            if (!num1 || !num2) return i;
        }
    }
};