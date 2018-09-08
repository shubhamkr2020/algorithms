// For any xor dp question - Finds number of numbers formed by the array of numbers..........

for(int i=1;i<=k;i++) {
    for(int j=0;j<8192;j++) {
        mem[flag][j] = (mem[flag^1][j]*(1+(a[v[i-1]])/2))%mod + (mem[flag^1][j^v[i-1]]*((a[v[i-1]]+1)/2))%mod;
        if(mem[flag][j]>=mod)
            mem[flag][j]%=mod;
    }
    flag = flag^1;

}


// explanation - https://stackoverflow.com/questions/44958697/understanding-the-editorial-for-prime-xor-hackerrank#
// question - https://www.hackerrank.com/challenges/prime-xor/editorial
// if count[i] is x then number of ways to form 0 from it 1+x/2 
// and number of ways to form i from it is (x-1)/2