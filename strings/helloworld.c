
    #include<stdio.h>
    int main(){
        // char arr[11]={'H','e','l','l','o',' ','W','o','r','l','d'};
        // char ch='\0';
        // for(int i=0; i<11;i++){
            
        //     printf("%c",ch);
        // }

        // char arr[]="i don't know";
        // int i=0;
        // while(i<12){
        //     printf("%c",arr[i]);
        //     i++;
        // }

        char arr[]="i don't know";
        int i=0;
        while(arr[i]!='\0'){
            printf("%c",arr[i]);
            i++;
        }
        return 0;
    }