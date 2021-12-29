#define INF 0x3f3f3f3f // for int
class Solution {
public:
    int digit[4], ans[4], diff = INF, h, m; string res;
    int getDiff(int hour, int minu) {
        int c2o = 60 * 60 - h * 60 - m;
        int n2o = 60 * 60 - hour * 60 - minu;
        return n2o < c2o ? c2o - n2o : c2o - n2o + 3600;
    }
    void dfs(int cnt) {
        if (cnt == 4) {
            int newh = 10 * ans[0] + ans[1], newm = 10 * ans[2] + ans[3];
            if (newh >= 0 && newh <= 23 && newm >= 0 && newm <= 59) {
                int x = getDiff(newh, newm);
                if (x < diff) {
                    diff = x; 
                    res = getTime(newh) + ":" + getTime(newm);
                }
            }
            return;
        }
        for (int i = 0; i < 4; i++) {
            ans[cnt] = digit[i];
            dfs(cnt + 1);
        }
    }
    string getTime(int val) {
        if (val >= 0 && val <= 9) return "0" + to_string(val);
        else return to_string(val);
    }
    string nextClosestTime(string time) {
        int tmp = 0; 
        for (int i = 0; i < time.size(); i++) {
            if (time[i] == ':') continue;
            digit[tmp++] = time[i] - '0';
        }
        h = digit[0] * 10 + digit[1]; m = digit[2] * 10 + digit[3];
        dfs(0);
        return res;
    }
};