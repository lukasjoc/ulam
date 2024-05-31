                                                                n=19;sp                         [361];N         =361;p=                         180;v=1

        ;d=1;i=                                         0;main(                                                                         ){sp[p]

                =v;while                         (v<N){if         (p+1>=N

                                                                        )break;         if(sp[p                                         +1]!=0)

                d++;for         (i=0;i<                         d;i++)sp                                                         [++p]=++

                                                                        v;if(sp         [p-n]!=                         0)d++;if

(p+1>=N                         )break;         if(sp[p                                         -n]!=0)         sp[++p]         =++v;for

        (i=0;i<         d;i++){         p-=n;sp         [p]=++v                         ;}if(sp

                                                                [p-1]!=         0)d++;if         (p-1>=N

                        )break;                         for(i=0                 ;i<d;i++ )sp[--p         ]=++v;if         (sp[p+n         ]!=0)d++

                                ;if(p+n         >=N)break         ;if(sp[

                                        p+n]!=0                         )sp[--p

]=++v;for                         (i=0;i<         d;i++){                         p+=n;sp                         [p]=++v         ;}}for(

        i=0;i<N                         ;i++){int                                         P=1;int                                         N=sp[i

                                                ];if(N>                                                                                         1){for(

        int i=2         ;i<=N/2                                         ;i++){if                         (N%i==0                         ){P=0;break

                ;}else{                                                                                         P=1;}}}

                                        printf(                         i%n==0?         "\n":""

                                "%-2s",         P==1?"."                         :"");}puts                                         ("");}
