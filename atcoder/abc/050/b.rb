n = gets.to_i
t = gets.chomp.split.map(&:to_i)
m = gets.to_i
p = []
x = []
0.upto(m-1) do
    pp, xx = gets.chomp.split.map(&:to_i)
    p << pp
    x << xx
end

sum = t.inject{|s,n| s+n}

0.upto(m-1) do |i|
    pp = p[i] - 1
    xx = x[i]
    dif = t[pp] - xx
    puts sum - dif
end

