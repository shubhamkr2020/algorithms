// https://www.hackerrank.com/challenges/eulers-criterion/problem
// Edtorial - https://en.wikipedia.org/wiki/Euler%27s_criterion  ********** IMPORTANT ***********


int main(){
    
    int t=fin;
    while(t--) {
        int a=fin, p=fin;
        if((modexpo(a,(p-1)/2,p)%p-1) == 0 || p==2)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}