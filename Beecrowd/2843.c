//2843 - Fast Writing, the Competition
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);

    char phrase[100000];
    int c[n][4], size, i = 0, duels, phase = 1;
    int duelsList[n];
    //c[competitor][4] = Ri Ei TimeTotal Phase

    for(i = 0; i < n; i++){
        scanf("%d %d\n", &c[i][0], &c[i][1]);
    }

    fgets(phrase, 100000, stdin);
    size = strlen(phrase);

    for(i = 0; i < n; i++){
        c[i][2] = c[i][0] + c[i][1]*size;
        duelsList[i] = i;
    }
    
    duels = n;

    while(duels > 1){
        for(int i = 0; i < duels; i=i+2){
            if(c[duelsList[i]][2] <= c[duelsList[i+1]][2]){
                c[duelsList[i+1]][3] = phase;
                duelsList[i+1] = -1;
            }
            else{//(c[duelsList[i]][2] > c[duelsList[i+1]][2])
                c[duelsList[i]][3] = phase;
                duelsList[i] = -1;
            }
            
        }
        int z = duels;
        for(int i = 0; i < z; i++){
            if(duelsList[i] == - 1){
                for(int j = i; j < z; j++){
                    duelsList[j] = duelsList[j+1];
                }
                z--;
                i--;
            }
        }
        
        phase++;
        duels = duels/2;
    }

    c[duelsList[0]][3] = phase;

    for(int i = 0; i < n - 1; i++){
        printf("%d ", c[i][3]);
    }
    printf("%d\n", c[n-1][3]);

}