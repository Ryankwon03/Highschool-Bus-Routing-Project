//project FINAL
#include <stdio.h>
#include <algorithm>
int a[1009][1009], n, schoolcheck[1009], schoolarr[1009], schooldistance = 99999999, check[1009],homearr[1009], homedistance = 99999999;




//Home to School
void ToSchool(int depth, int point, int cost){
    if (depth >= n){
        if (a[0][point] != 0 && schooldistance > cost){
            schooldistance = cost;
            for (int j=0;j<n;j++){
                schoolarr[schoolcheck[j]] = j+1;
            }
        }
        return;
    }
 
    for (int i=1;i<n;i++){
        if ((schoolcheck[i] == 0 && a[i][point] != 0) && (cost + a[i][point] <= schooldistance)){
            schoolcheck[i] = depth;
            ToSchool (depth+1, i, cost + a[i][point]);
            schoolcheck[i] = 0;
        }
    }
}
 
//School to Home
void ToHome(int depth, int point, int cost){
    if (depth >= n){
        if (a[point][0] != 0 && homedistance > cost){
            homedistance = cost;
            for (int j=0;j<n;j++){
               homearr[check[j]] = j+1;
            }
        }
        return;
    }
 
    for (int i=1;i<n;i++){
        if ((check[i] == 0 && a[point][i] != 0) && (cost + a[point][i] <= homedistance)){
            check[i] = depth;
            ToHome (depth+1, i, cost + a[point][i]);
            check[i] = 0;
        }
    }
}


 
int main(){
    int i, j;
    scanf("%d", &n);
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            scanf ("%d", &a[i][j]);
        }
    }
    ToSchool(1, 0, 0);
 
    printf("\n\n");
    
    printf("Home -> School distance: ");
    printf ("%d ± %d m\n", schooldistance, n*50);
 
 
    printf("Home -> School order: ");
 
//    for (i=n-1;i>=0;i--){
//        printf ("%d ", schoolarr[i]);
//    }
    for (i=n-1;i>0;i--){
        printf ("%d->", schoolarr[i]);
    }
    printf ("%d", schoolarr[0]);
    printf ("\n");
 
    
    ToHome(1, 0, 0);
     
    printf("\n");
    printf("School -> Home distance: ");
    printf ("%d ± %d m\n", homedistance, n*50);
    
    printf("School -> Home order: ");
    for (i=0;i<n-1;i++){
        printf ("%d->", homearr[i]);
    }
    printf ("%d", homearr[n-1]);
    printf ("\n\n");
    
    return 0;
}
