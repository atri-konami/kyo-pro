n=gets.to_i
a=gets.chomp.split.map(&:to_i)

s=Array.new(a.size+10)
s[0]=0

for i in 1..a.size
    s[i] = 2*s[i-1]+a[i-1]
end

puts s[a.size]
