n,a,b = gets.chomp.split.map(&:to_i)

count = 0
for i in 1..n do
    s = i.to_s.split('').map(&:to_i).inject{|acc, x| acc + x}
    count += i if a <= s && s <= b
end

puts count

