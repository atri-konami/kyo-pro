n,k=gets.chomp.split.map(&:to_i)
a=gets.chomp.split.map(&:to_i)
s=a[0...k].inject{|s,x| s+x}
ss=s
(0...(n-k)).each do |i|
    ss = ss - a[i] + a[i+k]
    s += ss
end

puts s
