int M = 1e9+7;
int fact[100005];
void calculateFactorial(){
    fact[0] = 1;
    for(int i = 1 ; i < 100005 ; i++){
        fact[i] = (1ll * fact[i-1] * i) % M;
    }
}
int modDiv(int a , int b){
    int b_inv = fastExpo(b , M-2);
    return (1ll * a * b_inv) % M;
}
int fastExpo(int a , int b){
    int ans = 1;
    while(b){
        if(b&1){
            ans = (1ll * ans * a) % M;
        }
        a = (1ll * a * a) % M;
        b >>= 1;
    }
    return ans;
}
int ncr(int n , int r){
    if(r == 0 || n == 0) return 1;
    int den = (1ll * fact[r] * fact[n-r])%M;
    return modDiv(fact[n] , den);
}