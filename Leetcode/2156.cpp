typedef long long ll;
class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = (int)s.size(); s = " " + s;
        vector<ll> hsh(n+2), p(k+1); p[0] = 1;
        for (int i=1; i<=k; i++) p[i] = (p[i-1] * power) % modulo;
        for (int i=n; i>=1; i--) hsh[i] = (hsh[i+1] * power + (s[i]-'a'+1)) % modulo;
        for (int i=1; i<=n; i++) {
            ll sub = ((hsh[i] - hsh[i+k] * p[k]) % modulo + modulo) % modulo;
            if (sub == hashValue) return s.substr(i, k);
        }
        return "A";
    }
};