char *s="+++++++++[>++++++++>+++++++++++>+++++<<<-]>.>++.+++++++..+++.>-.------------.<++++++++.--------.+++.------.--------.>+.",*a,m[99]={},p=0,k[99]={},c,b=0;f(int i){c=s[i];if(!c)return;c==43&&(*a)++;c==45&&(*a)--;c==62&&a++;c==60&&a--;c==46&&putchar(*a);c==44&&(*a=getchar());c==93&&(i=k[--p]);if(c==91){if(*a)k[p++]=i-1;else{while(1){c=s[i];c==91&&b++;c==93&&b--;if(!b)break;i++;}}}f(i+1);}int main(){a=m;f(0);}
/*
char *s="+++++++++[>++++++++>+++++++++++>+++++<<<-]>.>++.+++++++..+++.>-.------------.<++++++++.--------.+++.------.--------.>+.",*a,m[99]={},p=0,k[99]={},c,b=0;
f(int i){
    c=s[i];
    if(!c)return;
    c==43&&(*a)++;
    c==45&&(*a)--;
    c==62&&a++;
    c==60&&a--;
    c==46&&putchar(*a);
    c==44&&(*a=getchar());
    c==93&&(i=k[--p]);
    if(c==91){
        if(*a)
            k[p++]=i-1;
        else{
            while(1){
                c=s[i];
                //printf("i=%d,c=%c,b=%d\n",i,c,b);
                c==91&&b++;
                c==93&&b--;
                if(!b)break;
                i++;
            }
        }
    }
    f(i+1);
}

main(){
    a=m;
    f(0);
}*/