def ok(t,n,m,x)
    d=Array.new(m+1,0)
    for i in 1..m
        l=x[i]-d[i-1]-1
        r=0
        while true
            if [l*2+r,r*2+l].min > t || (i!=m && x[i+1] <= x[i]+r)
                if r==0
                    return false
                else
                    r-=1
                    break
                end
            else
                r+=1
            end
        end
        d[i]=x[i]+r
    end
    d[m]>=n
end

n,m=gets.chomp.split.map(&:to_i)
x=Array.new(m+1)

for i in 1..m
    x[i] = gets.to_i
end

lb=0
ub=3*n.to_f

for i in 1..64
    mid = (lb+ub)/2
    if ok(mid,n,m,x)
        ub=mid
    else
        lb=mid
    end
end

puts lb.round
          
