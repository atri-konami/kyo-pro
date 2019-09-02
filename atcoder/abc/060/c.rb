n,t = gets.chomp.split.map(&:to_i)
ts = gets.chomp.split.map(&:to_i)
s = t
e = 0
1.upto n-1 do |i|
    d = ts[i] - ts[i-1]
    if t >= d
        s = ts[i] + t - e
    else
        e += d - t
        s += t
    end
end

puts s
