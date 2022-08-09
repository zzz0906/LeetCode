class Solution {
public:
    int checkRecord(int n) {
      int MOD = 1e9 + 7;
      if(n == 1) return 3;
      long long all = 0;
      long long al = 1;
      long long ap = 1;
      long long aa = 2;
      long long nall = 1;
      long long nal = 1;
      long long nap = 2;
      
      for(int i = 3; i <= n; i++) {
        long long ALL = 0, AL = 0, AP = 0, AA = 0, NALL = 0, NAL = 0, NAP = 0;
        AP += all;
        AP += aa;
        AL += aa;
        ALL += al;
        AP += al;
        AP += ap;
        AL += ap;
        
        NAP += nall;
        AA += nall;
        NAP += nal;
        AA += nal;
        NALL += nal;
        NAP += nap;
        AA += nap;
        NAL += nap;
        
        all = ALL;
        al = AL;
        ap = AP;
        aa = AA;
        nall = NALL;
        nal  = NAL;
        nap = NAP;
        
        all %= MOD;
        al %= MOD;
        ap %= MOD;
        aa %= MOD;
        nall %= MOD;
        nal  %= MOD;
        nap %= MOD;
      }
      
      return (all + al + ap + aa + nall + nal + nap) % MOD;
    }
};