void get_next(char* P,int* next)
{
    int n=strlen(P);
    int i=1,j=0;
    next[0]=0;
    if (n > 0) next[1] = 0;
    while(i < n-1)
    {
        if(P[i]!=P[j])
        {
            j=next[j];
            if(j==0 && P[i]!= P[j])
            {
                i++;
                next[i]=j;
            }
        }
        else
        {
            i++,j++;
            next[i]=j;
        }
    }
}
#define MAXSIZE 10000
int strStr(char* haystack, char* needle) {
    int n=strlen(haystack);
    int m=strlen(needle);
    int*next=(int *)malloc(sizeof(int)*(MAXSIZE+1));
    get_next(needle,next);
    int i=0,j=0;
    while(i < n && j < m)
    {
        if(haystack[i]==needle[j])
        {
            i++,j++;
        }
        else if(j > 0)
            j=next[j];
        else
            i++;
    }   
    free(next);
    if(j >= m)
        return i-m;
    else
        return -1;
}