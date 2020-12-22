string decodeAtIndex(string S, int K) {
        long i = 0, cnt = 0;
        for (; cnt < K; ++i) {
            cnt = isdigit(S[i]) ? cnt * (S[i] - '0') : (cnt + 1);
        }
        while (i--) {
            if (isdigit(S[i])) {
                cnt /= (S[i] - '0');
                K %= cnt;
            } else {
                if (K % cnt == 0) return string(1, S[i]);
                --cnt;
            }
        }
        return "nothing";
    }