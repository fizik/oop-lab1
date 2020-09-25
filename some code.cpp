int count=0, *pdata=NULL;
void push(int d) {
    int i, t, *tmp;
    tmp=new int[count+1];
    for(i=0; i<count; i++) {
        t=pdata[i];
        tmp[i]=t;
    }
    tmp[count++]=d;
    delete [] pdata;
    pdata=tmp;
}

