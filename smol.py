import sys;z=int(sys.argv[1]);m,v,d=z**2,1,1;sp,i=[0]*m,m//2;sp[i]=v
while v<m:
    if i+1>=m:continue
    if sp[i+1]!=0:d+=1
    for _ in range(d):v+=1;i+=1;sp[i]=v
    if sp[i-z]!=0:d+=1
    if i+1>=m:continue
    if sp[i-z] != 0:v+=1;i+=1;sp[i]=v
    for _ in range(d):v+=1;i-=z;sp[i]=v
    if sp[i-1]!=0:d+=1
    if i-1>=m:continue
    for _ in range(d):v+=1;i-=1;sp[i]=v
    if sp[i+z]!=0:d+=1
    if i+z>=m:continue
    if sp[i+z]!=0:v+=1;i-=1;sp[i]=v
    for _ in range(d):v+=1;i+=z;sp[i]=v
for c,sp in enumerate(sp):
    if c%z==0:print()
    print("."if sp>1 and all(sp%c for c in range(2,int(sp**.5)+1))else " ",end=" ")
print()
