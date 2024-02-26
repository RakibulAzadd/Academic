class Solution {
public:
    static const int MAXN = 100001;
    bool prime[MAXN];
    int spf[MAXN];

    void SieveOfEratosthenes() {
        memset(prime, true, sizeof(prime));

        for (int p = 2; p * p < MAXN; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i < MAXN; i += p)
                    prime[i] = false;
            }
        }
    }

    void sieve() {
        spf[1] = 1;
        for (int i = 2; i < MAXN; i++)
            spf[i] = i;

        for (int i = 4; i < MAXN; i += 2)
            spf[i] = 2;

        for (int i = 3; i * i < MAXN; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j < MAXN; j += i)
                    if (spf[j] == j)
                        spf[j] = i;
            }
        }
    }

    int getFactorization(int x) {
        int ret=0;
        while (x != 1) {
            ret+=spf[x];
            x = x / spf[x];
        }
        return ret;
    }

    int smallestValue(int n) {
        sieve();
        SieveOfEratosthenes();
        if(n<=4) return n;
       // cout<< prime[n]<<endl;
         while (!prime[n]) {
           int  p = getFactorization(n);
            //   cout<<p<<endl;
               n = p;
          }

        // cout<< prime[n]<<endl;
        // vector<int> p = getFactorization(n);
            // for (int i = 0; i < p.size(); i++) cout<< p[i] << " ";



        return n;
    }

};
