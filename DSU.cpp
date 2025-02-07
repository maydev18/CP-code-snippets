class Disjoint{
    public:
    vector<int> size , par;
    Disjoint(int n){
        size.resize(n+1);
        par.resize(n+1);
        for(int i = 0 ; i <= n ; i++){
            size[i] = 1;
            par[i] = i;
        }
    }
    int find_par(int u){
        if(u == par[u]){
            return u;
        }
        return par[u] = find_par(par[u]);
    }
    void Union(int u , int v){
        int pau = find_par(u);
        int pav = find_par(v);
        if(pau == pav) return;
        if(size[pau] > size[pav]){
            par[pav] = pau;
            size[pau] += size[pav];
        }
        else{
            par[pau] = pav;
            size[pav] += size[pau];
        }
    }
};