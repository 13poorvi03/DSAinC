#include<stdio.h>   // Standard input-output header file include kar rahe hain

// Do numbers ka minimum nikalne ke liye function
int min(int a, int b){
    if(a<b) return a;   // Agar a chhota hai to a return karo
    else return b;      // Warna b return karo
}

// ------------------- Pehla method (commented out) -------------------
// Ye method 1 se lekar min(a,b) tak loop chalata hai
// Aur jo sabse bada number dono ko divide kare usse hcf banata hai


// int gcd(int a, int b){
//     int hcf;                                  // Highest common factor store karne ke liye variable
//     for(int i=1; i<=min(a,b); i++){              // 1 se min(a,b) tak loop
//         if(a%i==0 && b%i==0){                 // Agar i dono numbers ko divide kare
//             hcf = i;                          // hcf ko update karo
//         }
//     }
//     return hcf;                   // Loop ke baad hcf return karo
// }



// ------------------- Dusra method (optimized) -------------------

// Ye method min(a,b) se neeche check karta hai
// Aur pehla common divisor milte hi break kar deta hai
int gcd(int a, int b){
    int hcf;   // Highest common factor store karne ke liye variable
    for(int i= min(a,b); i>=1; i--){   // min(a,b) se 1 tak loop chalana
       if(a%i==0 && b%i==0){           // Agar i dono ko divide kare
        hcf = i;                       // hcf ko i set karo
        break;                         // Break kar do kyunki pehla divisor hi sabse bada hoga
       }
    }
    return hcf;   // hcf return karo
}

int main(){
    int a;   // Pehla number store karne ke liye variable
    printf("enter 1st number : ");   // User se pehla number maango
    scanf("%d",&a);                  // Input lo aur a me store karo

    int b;   // Dusra number store karne ke liye variable
    printf("enter 2nd number : ");   // User se dusra number maango
    scanf("%d",&b);                  // Input lo aur b me store karo
     
    int hcf = gcd(a,b);   // gcd function call karke result hcf me store karo
    printf("the HCF/GCD of %d and %d is : %d",a,b,hcf );   // Result print karo
    return 0;   // Program end
}