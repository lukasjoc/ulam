n=19; sp[361]; N=361; p=180; v=1; d=1; i=0; int prime(int t) { if(t<=1) return
0; if(t<=3) return 1; if(t%2==0||t%3==0) return 0; for(int i=5;i*i<=t;i+=6)
{ if (n%i==0||t %(i+2)==0) return 0; } return 1; } main() { sp[p] =v;
while(v<N) { if(p+1>=N) break; if(sp[p+1] !=0) d++; for
(i=0;i<d;i++)sp[++p] = ++v; if (sp[p-n] !=0) d++; if(p+1>=N) break;
if(sp[p-n] !=0)sp[++p] = ++v; for(i=0;i<d; i++) { p-=n; sp[p] = ++v; }
if(sp[p-1]!=0) d++; if(p-1>=N) break; for(i=0;i<d; i++) sp[--p] = ++v;
if(sp[p+n]!=0)d++;if(p+n>=N) break;if(sp[p+n]!=0)sp[--p]=++v;
for(i=0;i<d;i++) { p+=n; sp[p] = ++v; } } for(i=0;i<N;i++)
printf(i%n==0?"\n":"" "%-2s", prime(sp[i]) ? "." : " "); puts(""); }


