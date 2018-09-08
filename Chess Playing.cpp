
// https://www.hackerrank.com/contests/w36/challenges/ways-to-give-a-check/problem
bool rook(int pi, int pj, int ki, int kj) {
    int i,j;
    if(pi == ki) {
        for(i=min(pj,kj)+1; i<max(pj,kj); i++) {
            if(b[pi][i] != '#')
                return false;
        }
        return true;
    }
    if(pj == kj) {
        for(i=min(pi,ki)+1; i<max(pi,ki); i++) {
            if(b[i][pj] != '#')
                return false;
        }
        return true;
    }
    return false;
}

bool bishop(int pi, int pj, int ki, int kj) {
    if(abs(pi-ki) == abs(pj-kj)) {
        int i,j;
        if(pi>ki && pj>kj) {
            j=pj-1;
            for(i=pi-1; i>ki; i--) {
                if(b[i][j] != '#')
                    return false;
                j--;
            }
            return true;
        }
        if(pi>ki && pj<kj) {
            j=pj+1;
            for(i=pi-1; i>ki; i--) {
                if(b[i][j] != '#')
                    return false;
                j++;
            }
            return true;
        }
        if(pi<ki && pj>kj) {
            j=pj-1;
            for(i=pi+1; i<ki; i++) {
                if(b[i][j] != '#') {
                    return false;
                }
                j--;
            }
            return true;
        }
        if(pi<ki && pj<kj) {
            j=pj+1;
            for(i=pi+1; i<ki; i++) {
                if(b[i][j] != '#')
                    return false;
                j++;
            }
            return true;
        }
    }
    return false;
}

bool queen(int pi, int pj, int ki, int kj) {
    if(rook(pi,pj,ki,kj) || bishop(pi,pj,ki,kj))
        return true;
    return false;
}

bool knight(int pi, int pj, int ki, int kj) {
    if(abs(pi-ki) == 1 && abs(pj-kj)==2)
        return true;
    if(abs(pi-ki)==2 && abs(pj-kj)==1)
        return true;
    return false;
}