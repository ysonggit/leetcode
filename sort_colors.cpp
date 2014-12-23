#include "utils.h"

using namespace std;

// red 0
// white 1
// blue 2
/*
  idea. One pass algorithm: two pointers
  the front one is the index of the last red
  the back one is the index of the first blue
  initialize red_idx = -1, blue_idx = n
  move i from 0 to blue_idx
      if A[i] is red
          red_idx++
          swap A[i] and A[red_idx]
      if A[i] is blue
          blue_idx--
          swap A[i] and A[blue_idx]
          i--
      i++
      
 */
void sortColors(int A[], int n) {
    if(n<=0) return;
    int red_idx = -1;
    int blue_idx = n;
    int i=0;
    while(i<blue_idx){
        if(A[i]==0){
            //swap A[red_idx] with A[i]
            red_idx++;
            A[i] = A[red_idx];
            A[red_idx] = 0;
        }
        if(A[i]==2){
            blue_idx--;
            A[i] = A[blue_idx];
            A[blue_idx] = 2;
            i--;  // tricky: if A[i] = 2, A[blue_idx] = 0; after swap, A[i]=0, so have to move index one step back.
        }
        i++;
    }
}
int main(int argc, char *argv[])
{
    int colors[10] = {1, 2, 1, 2, 2, 1, 0, 1 ,1, 0};
    sortColors(colors, 10);
    for(int i=0; i<10; i++){
        cout<<colors[i]<<" "<<endl;
    }
    cout<<endl;
    int colors2[10] = {0, 1, 1, 2, 2, 1, 0, 1 ,1, 0};
    sortColors(colors2, 10);
    for(int i=0; i<10; i++){
        cout<<colors2[i]<<" "<<endl;
    }
    return 0;
}