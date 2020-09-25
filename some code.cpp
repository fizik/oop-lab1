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

int count=0, *pdata=NULL;
void push(int d) {
    int i, t, *tmp;
    tmp=new int[count+1];
    for(int i=0; i<count; i++) {
        t=pdata[i];
        tmp[i]=t;
    }
    tmp[count++]=d;
    delete [] pdata;
    pdata=tmp;
}


int somefunc(int **data, int cnt) {
    int i, sum;
    for( sum=0, i=0; i<cnt; i++ )
        for( int i=0; i<cnt; i++ )
            sum+=data[::i][i];
    return sum;
}


int i=1;
int whereisi() {
    int i=2, cnt=5;
    for(i; i<cnt; i++ )
        for( int i=3; i<cnt; i++ )
            cout<<"i = " << i <<
                " ::i = " << ::i
                << endl;
    return i;
}
