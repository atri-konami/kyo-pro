h,w=gets.chomp.split.map(&:to_i)

puts '#'*(w+2)
1.upto(h) do
    print '#'
    print gets.chomp
    puts '#'
end
puts '#'*(w+2)

