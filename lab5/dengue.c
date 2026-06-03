#include <stdio.h>

int main()
{
  int i, n;
  scanf("%d",&n);

  int arr[n];
  int notSaved[n];
  int deadCount = 0;

  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
    if(arr[i] <= 20) {
        notSaved[deadCount] = arr[i];
        deadCount++;
    }
  }

    if(deadCount) {
        printf("Only few are saved and the following are dead: \n");
        for(int i = 0; i < deadCount; i++) {
            printf("%d\n", notSaved[i]);
        }
    }else{
        printf("Saved all\n");
    }


 return 0;
}