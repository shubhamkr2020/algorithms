// https://codeforces.com/blog/entry/9901
// https://codeforces.com/blog/entry/9901?#comment-153756


int BinarySearch(vector<int>& v, int target) {
  int n = v.size();
  int l=-1,r=n;
  
  while(r-l>1) {
    int m = (l+r)/2;
    if(v[m] < target) l=m;
    else r=m;
  }
  return r;
}

/*
Here, finall values for l and r:
l will give you the first number which is less than the target.
r will give you the first number which is grater than equal to target.
i.e. 
v[l] < target
v[r] >= target

So, to find first number which is greater than target use the opposite.
*/
