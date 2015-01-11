#include "utils.h"

using namespace std;

/* time exceeds limit
  dfs template for permutations
  @param & results
  @param n
  @param sol
  @param used

  if sol.size == n
     results.add(sol)
     return

  if (results.size == k) return
  for each i =0 ...n-1
      if i is not used
         sol.push_back(char_i)
         used[i] = true
         dfs(results, n, sol, used)
         used[i] = false
         sol.pop_back
 */
/*
void dfs(vector<string> & results, vector<int> & sol, int n, int k, int & count, bool *used){
    if(count>k) return;
    if(sol.size()==n){
        count++;
        if(count==k){
            stringstream ss;
            for(int i : sol){
                ss<<i;
            }
            results.push_back(ss.str());
        }
        return;
    }
    for(int i=0; i<n; i++){
        if(!used[i]){
            sol.push_back(i+1);
            used[i] = true;
            dfs(results, sol, n, k, count, used);
            used[i] = false;
            sol.pop_back();
        }
    }
}

string getPermutation2(int n, int k) {
    if(n<=0 || k<1 ) return string(""); // k > n! overflow
    int count = 0;
    vector<string> results;
    vector<int> sol;
    bool * used = new bool[n];
    for(int i=0; i<n; i++){
        used[i] = false;
    }
    dfs(results, sol, n, k, count, used);
    delete [] used;
    used = NULL;
    return results[0];
}
*/

/*
  let the number sequence of k^th permutation be a1, a2, ... an 
  k1 = k
  a1 = k1 / (n-1)!
  k2 = k1 % (n-1)!
  a2 = k2 / (n-2)!
  .
  .
  .
  kn-1 = kn-2 % 2!
  an-1 = kn-1 / 1!
  an = 0
 */
// n is less than 10 so no overflow
int factorial(int n){
    if(n==1 || n==0) return 1;
    return factorial(n-1) * n;
}

string getPermutation(int n, int k) {
    string perm;
    if(n<1 || n>9 || k<1) return perm;
    string numbers("123456789");
    int a=0;
    int total = factorial(n);
    k--; //tricky: index is zero-based 
    for(int i=0; i<n; i++){
        total /= n-i;
        a =  k/ total;
        perm.push_back(numbers[a]);
        //tricky: DO NOT FORGET to Remove this character since  it has been used
        numbers.erase(numbers.begin()+a);
        k = k% total;
    }
    return perm;
}

int main(int argc, char *argv[])
{
    cout<<getPermutation(3, 4)<<endl;
    cout<<getPermutation(9, 155915)<<endl;
    return 0;
}
