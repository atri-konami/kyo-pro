a = gets.chomp.split.map(&:to_i)
b = gets.chomp.split.map(&:to_i)

c = gets.to_i

d = []
a.each{|x| b.each{|y|
    if x == c
        d << y
    elsif y == c
        d << x
    end
}}

d.uniq!

puts d.size

d.sort.each{|x| puts x}

