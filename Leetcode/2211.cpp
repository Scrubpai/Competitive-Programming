class Solution {
public:
    int countCollisions(string directions) {
        int n = (int)directions.size(), l=-1, r=-1, s=0;
        for (int i=0; i<n; i++) {
            if (directions[i] != 'L') {
                l=i; break;
            }
        }
        for (int i=n-1; i>=0; i--) {
            if (directions[i] != 'R') {
                r=i; break;
            }
        }
        if (l>r || l==-1 || r==-1) return 0;
        for (int i=l; i<=r; i++) {
            if (directions[i] == 'S') s++;
        }
        return (r-l+1)-s;
    }
};