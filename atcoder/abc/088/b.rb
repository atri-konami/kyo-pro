n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)

alice = 0
bob = 0
a.sort{|a,b| b <=> a}
 .each_with_index{|n, idx|
     if idx % 2 == 0
         alice += n
     else
         bob += n
     end
 }

puts alice - bob
