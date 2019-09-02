n,m=gets.chomp.split.map(&:to_i)
man=[0]

for i in 1..m do
    man << gets.to_i
end

dp=Array.new(m+1).map{|x| Array.new(n+1,10**10)}

dp[0][0]=0

for i in 1..m 
    for j in 0...man[i]
        for k in man[i]..n
            l=man[i]-j-1
            r=k-man[i]
            t=[l*2+r,r*2+l].min
            dp[i][k]=[dp[i][k],[dp[i-1][j],t].max].min
        end
    end
end

puts dp.transpose[n].min
